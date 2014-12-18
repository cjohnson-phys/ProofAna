///////////////////////////////////////////////////////////////////////
// CalibrationDataEigenVariations.cxx, (c) ATLAS Detector software
///////////////////////////////////////////////////////////////////////

#include "CalibrationDataInterface/CalibrationDataContainer.h"
#include "CalibrationDataInterface/CalibrationDataEigenVariations.h"

#include <iostream>
#include <cmath>
#include "TH1.h"
#include "TVectorT.h"
#include "TDecompBK.h"
#include "TMatrixDSymEigen.h"
#include "TROOT.h"

using Analysis::CalibrationDataEigenVariations;
using std::string;
using std::map;
using std::vector;
using std::pair;

namespace {
  // The covariance matrices constructed by the following two functions adhere to the TH1 binning conventions.
  // But in order to avoid unnecessary overhead, the actual dimensionality of the histograms is accounted for.

  // Construct the (diagonal) covariance matrix for the statistical uncertainties on the "ref" results
  TMatrixDSym getStatCovarianceMatrix(const TH1* hist) {
    Int_t nbinx = hist->GetNbinsX()+2, nbiny = hist->GetNbinsY()+2, nbinz = hist->GetNbinsZ()+2;
    Int_t rows = nbinx;
    if (hist->GetDimension() > 1) rows *= nbiny;
    if (hist->GetDimension() > 2) rows *= nbinz;

    // // the "2" below doesn't actually imply that two bins are used...
    // // this is just to make the loops below work
    // if (ref->GetDimension() <= 1) nbiny = 2;
    // if (ref->GetDimension() <= 2) nbinz = 2;

    TMatrixDSym stat(rows);
    for (Int_t binx = 1; binx < nbinx-1; ++binx)
      for (Int_t biny = 1; biny < nbiny-1; ++biny)
	for (Int_t binz = 1; binz < nbinz-1; ++binz) {
	  Int_t bin = hist->GetBin(binx, biny, binz);
	  double err = hist->GetBinError(bin);
	  stat(bin, bin) = err*err;
	}
    return stat;
  }

  // Construct the covariance matrix assuming that histogram "unc" contains systematic uncertainties
  // pertaining to the "ref" results, and that the uncertainties are fully correlated from bin to bin
  // (unless option "doCorrelated" is false, in which bins are assumed uncorrelated)
  TMatrixDSym getSystCovarianceMatrix(const TH1* ref, const TH1* unc, bool doCorrelated) {
    Int_t nbinx = ref->GetNbinsX()+2, nbiny = ref->GetNbinsY()+2, nbinz = ref->GetNbinsZ()+2;
    Int_t rows = nbinx;
    if (ref->GetDimension() > 1) rows *= nbiny;
    if (ref->GetDimension() > 2) rows *= nbinz;
    
    TMatrixDSym cov(rows);

    // Carry out a minimal consistency check
    if (unc->GetNbinsX()+2 != nbinx || unc->GetNbinsY()+2 != nbiny || unc->GetNbinsZ()+2 != nbinz
	|| unc->GetDimension() != ref->GetDimension()) {
      std::cout << "getSystCovarianceMatrix: inconsistency found in histograms "
		<< ref->GetName() << " and " << unc->GetName() << std::endl;
      return cov;
    }

    // // the "2" below doesn't actually imply that two bins are used...
    // // this is just to make the loops below work
    // if (ref->GetDimension() <= 1) nbiny = 2;
    // if (ref->GetDimension() <= 2) nbinz = 2;
    
    // Special case: uncertainties not correlated from bin to bin
    if (! doCorrelated) {
      for (Int_t binx = 1; binx < nbinx-1; ++binx)
	for (Int_t biny = 1; biny < nbiny-1; ++biny)
	  for (Int_t binz = 1; binz < nbinz-1; ++binz) {
	    Int_t bin = ref->GetBin(binx, biny, binz);
	    double err = unc->GetBinContent(bin);
	    cov(bin,bin) = err*err;
	  }
      return cov;
    }

    for (Int_t binx = 1; binx < nbinx-1; ++binx)
      for (Int_t biny = 1; biny < nbiny-1; ++biny)
	for (Int_t binz = 1; binz < nbinz-1; ++binz) {
	  Int_t bin = ref->GetBin(binx, biny, binz);
	  double err = unc->GetBinContent(bin);
	  for (Int_t binx2 = 1; binx2 < nbinx-1; ++binx2)
	    for (Int_t biny2 = 1; biny2 < nbiny-1; ++biny2)
	      for (Int_t binz2 = 1; binz2 < nbinz-1; ++binz2) {
		Int_t bin2 = ref->GetBin(binx2, biny2, binz2);
		double err2 = unc->GetBinContent(bin2);
		cov(bin, bin2) = err*err2;
	      }
	}
    return cov;
  }

}

CalibrationDataEigenVariations::CalibrationDataEigenVariations(const CalibrationDataHistogramContainer* cnt) :
  m_cnt(cnt), m_initialized(false)
{
}

CalibrationDataEigenVariations::~CalibrationDataEigenVariations()
{
  // delete all variation histograms owned by us
  for (vector<pair<TH1*, TH1*> >::iterator it = m_named.begin();
       it != m_named.end(); ++it) {
    delete it->first;
    delete it->second;
  }
  for (vector<pair<TH1*, TH1*> >::iterator it = m_eigen.begin();
       it != m_eigen.end(); ++it) {
    delete it->first;
    delete it->second;
  }
}

void
CalibrationDataEigenVariations::excludeNamedUncertainty(const std::string& name)
{
  if (m_initialized)
    std::cerr << "CalibrationDataEigenVariations::excludeNamedUncertainty error:"
	      << " initialization already done" << std::endl;
  else if (name == "comment" || name == "result" || name == "systematics" || name == "statistics" || name == "combined")
    std::cerr << "CalibrationDataEigenVariations::excludeNamedUncertainty error:"
	      << " name " << name << " not allowed" << std::endl;
  else if (! m_cnt->GetValue(name.c_str()))
    std::cerr << "CalibrationDataEigenVariations::excludeNamedUncertainty error:"
	      << " uncertainty named " << name << " not found" << std::endl;
  else {
    m_named.push_back(std::make_pair<TH1*, TH1*>(0, 0));
    m_namedIndices[name] = m_named.size()-1;
  }
}

void
CalibrationDataEigenVariations::initialize()
{

  // retrieve the central calibration
  TH1* result = dynamic_cast<TH1*>(m_cnt->GetValue("result"));

  gROOT->cd();

  // loop over the uncertainties to construct the covariance matrix for all uncertainties
  // to be addressed using the eigenvector method.

  // First, treat the statistics separately
  TMatrixDSym cov = getStatCovarianceMatrix(result);

  // Then loop through the list of (other) uncertainties
  std::vector<string> uncs = m_cnt->listUncertainties();
  for (unsigned int t = 0; t < uncs.size(); ++t) {
    // entries that should never be included
    if (uncs[t] == "comment" || uncs[t] == "result" ||
	uncs[t] == "combined" || uncs[t] == "statistics" ||
        uncs[t] == "systematics") continue;
    // entries that can be excluded if desired
    if (m_namedIndices.find(uncs[t]) != m_namedIndices.end()) continue;

    TH1* hunc = dynamic_cast<TH1*>(m_cnt->GetValue(uncs[t].c_str()));
    cov += getSystCovarianceMatrix(result, hunc, m_cnt->isBinCorrelated(uncs[t]));
  }

  // Second step: create the variations for the named sources of uncertainty (easy...)
  for (map<string, unsigned int>::iterator it = m_namedIndices.begin();
       it != m_namedIndices.end(); ++it) {
    pair<TH1*, TH1*>& p = m_named[it->second];
    TH1* hunc = (TH1*) m_cnt->GetValue(it->first.c_str());
    TString namedvar("namedVar");
    namedvar += it->first.c_str();
    TString namedvarUp(namedvar);   namedvarUp   += "_up";
    TString namedvarDown(namedvar); namedvarDown += "_down";
    TH1* resultVariedUp   = (TH1*)result->Clone(namedvarUp);   resultVariedUp->Add(hunc, 1.0);
    TH1* resultVariedDown = (TH1*)result->Clone(namedvarDown); resultVariedDown->Add(hunc, -1.0);
    p.first  = resultVariedUp;
    p.second = resultVariedDown;
  }

  // Third step: compute the eigenvector variations corresponding to the remaining sources of uncertainty
  int nbins = result->GetNbinsX()+2;
  if (result->GetDimension()>1) nbins*= (result->GetNbinsY()+2);
  if (result->GetDimension()>2) nbins*= (result->GetNbinsZ()+2);
  
  // Start by "compressing" the covariance matrix (removing columns/rows containing zeros only)
  int nZeros=0;
  std::vector<int> zeroComponents;
  int size2 = cov.GetNrows();

  // First flag all the zeros
  for (int i = 0; i < size2; ++i) {
    // Try a first (quick) identification of rows/columns of zeros by the first element in each row
    // If "successful", check the whole row in more detail
    if (fabs(cov(i,0)) < 1e-10) {
      bool isThereANonZero(false);
      for (int j = 0; j < size2; ++j) {
        if (fabs(cov(i,j)) > 1e-10) {
          isThereANonZero=true; break;
        }
      }
      if (! isThereANonZero) {
        ++nZeros;
        zeroComponents.push_back(i);
      }
    }
  }

  if (nZeros >= size2) {
    std::cerr << " Problem. Found n. " << nZeros << " while size of matrix is " << size2 << std::endl;
    return;
  }

  int size = size2 - nZeros;

  TMatrixT<double> matrixVariationJacobian(size,size2);
  int nMissed=0;
  for (int i = 0; i < size2; ++i) { //full size
    bool missed=false;
    for (unsigned int s = 0; s < zeroComponents.size(); ++s) {
      if (zeroComponents.at(s) == i) {
        missed = true;
        break;
      }
    }
    if (missed) {
      ++nMissed;
      continue;
    }
    matrixVariationJacobian(i-nMissed,i)=1;
  }

  // reduce the matrix to one without the zeros, using a "similarity" transformation
  TMatrixDSym redSystematicCovMatrix = cov.Similarity(matrixVariationJacobian);

  // GP uncomment to debug covariance matrix
  //  std::cout << " resulting size of cov matrix " <<  redSystematicCovMatrix.GetNrows()<< std::endl;
  //  std::cout << " determinant " << redSystematicCovMatrix.Determinant() << std::endl;
  //  for (int i=0;i<size;i++)
  //  {
  //    for (int j=0;j<size;j++)
  //    {
  //      std::cout << " ["<<i<<","<<j<<"]: " << redSystematicCovMatrix(i,j) << std::endl;
  //    }
  //  }

  const TMatrixDSym matrixCovariance = redSystematicCovMatrix;

  TVectorT<double> vectorConstants(redSystematicCovMatrix.GetNrows());
  for (int i = 0; i < redSystematicCovMatrix.GetNrows(); ++i) vectorConstants(i) = 0;
  
  TDecompBK myDecomposition(matrixCovariance);
  TMatrixDSym matrixWeight2=myDecomposition.Invert();
  
  //now you have the weight matrix
  TMatrixDSymEigen eigenValueMaker(matrixWeight2);
  TVectorT<double> eigenValues   = eigenValueMaker.GetEigenValues();
  TMatrixT<double> eigenVectors  = eigenValueMaker.GetEigenVectors();
  TMatrixT<double> eigenVectorsOriginal = eigenVectors;
  TMatrixT<double> eigenVectorsT = eigenVectors.T();

  TVectorT<double> constValues(size);
  for (int i = 0; i < size; ++i) {
    double constValue = 0;
    for (int j = 0; j < size; ++j) {
      double comb = eigenVectorsT[i][j];
      constValue += comb*vectorConstants[j];
    }
    constValues[i]=constValue;
  }

  TVectorT<double> randomEigenValues(size);
  TMatrixT<double> matrixVariations(size,size);
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) randomEigenValues(j)=0;
    randomEigenValues[i]=sqrt(1./eigenValues[i]);//here you can replace with a random gaussian sigma
  
    //now go back
    TVectorT<double> randomValues(size);
    for (int r = 0; r < size; ++r) {
      //first row of eigenVectors (without T) gives needed combinations
      double constValue = 0;
      for (int j = 0; j < size; ++j) {
        double comb = eigenVectorsOriginal[r][j];
        constValue += comb*randomEigenValues[j];
      }
      randomValues[r] = constValue;
      matrixVariations(i,r) = randomValues[r];//first index is the variation number, second corresponds to the pT bin
    }
  }

  TMatrixT<double> matrixVariationsWithZeros = matrixVariations * matrixVariationJacobian;

  // //now setup the real ucertainties
  // std::vector<TObject*> eigenvectorsUncUpProvider;
  // std::vector<TObject*> eigenvectorsUncDownProvider; 
  // std::vector<TObject*> eigenvectorsUncProvider;

  for (int i = 0; i < size; ++i) {
    // TString superstring(result->GetName());
    // superstring += "_eigenVar";
    TString superstring("eigenVar");
    superstring+=i;

    TString nameUp(superstring);   nameUp   += "_up";
    TString nameDown(superstring); nameDown += "_down";
    // TString nameUnc(superstring);  nameUnc+= "_unc";

    TH1* resultVariedUp   = (TH1*)result->Clone(nameUp);
    TH1* resultVariedDown = (TH1*)result->Clone(nameDown);
    // TH1* resultOnlyUnc    = (TH1*)result->Clone(nameUnc);

    for (int u = 0; u < nbins; ++u) {
      resultVariedUp->SetBinContent(u,result->GetBinContent(u)+
				    matrixVariationsWithZeros(i,u));
      resultVariedDown->SetBinContent(u,result->GetBinContent(u)-
				      matrixVariationsWithZeros(i,u));
      // resultOnlyUnc->SetBinContent(u,matrixVariationsWithZeros(i,u));
    }

    m_eigen.push_back(std::make_pair<TH1*, TH1*>(resultVariedUp, resultVariedDown));

    // eigenvectorsUncUpProvider.push_back(resultVariedUp);
    // eigenvectorsUncDownProvider.push_back(resultVariedDown);
    // eigenvectorsUncProvider.push_back(resultOnlyUnc);
  }//end eigenvector size

  // last step: order the named uncertainties (so that the user will not have to deal with this)
  
  m_initialized = true;
}

unsigned int
CalibrationDataEigenVariations::getNumberOfNamedVariations() const
{
  return m_namedIndices.size();
}

vector<string>
CalibrationDataEigenVariations::listNamedVariations() const
{
  vector<string> names;
  for (map<string, unsigned int>::const_iterator it = m_namedIndices.begin();
       it != m_namedIndices.end(); ++it)
    names.push_back(it->first);
  return names;
}

unsigned int
CalibrationDataEigenVariations::getNumberOfEigenVariations() const
{
  if (! m_initialized) const_cast<CalibrationDataEigenVariations*>(this)->initialize();
  return m_eigen.size();
}

bool
CalibrationDataEigenVariations::getEigenvectorVariation(unsigned int variation,
							TH1*& up, TH1*& down) const
{
  if (! m_initialized) const_cast<CalibrationDataEigenVariations*>(this)->initialize();
  if (variation < m_eigen.size()) {
    up   = m_eigen[variation].first;
    down = m_eigen[variation].second;
    return true;
  }

  up = down = 0;
  return false;
}

bool
CalibrationDataEigenVariations::getNamedVariation(const string& name,
						  TH1*& up, TH1*& down) const
{
  map<string, unsigned int>::const_iterator it = m_namedIndices.find(name);
  if (it != m_namedIndices.end()) return getNamedVariation(it->second, up, down);

  up = down = 0;
  return false;
}

bool
CalibrationDataEigenVariations::getNamedVariation(unsigned int nameIndex,
						  TH1*& up, TH1*& down) const
{
  if (! m_initialized) const_cast<CalibrationDataEigenVariations*>(this)->initialize();

  if (nameIndex < m_named.size()) {
    up   = m_named[nameIndex].first;
    down = m_named[nameIndex].second;
    return true;
  }

  up = down = 0;
  return false;
}

unsigned int
CalibrationDataEigenVariations::getNamedVariationIndex(const std::string& name) const
{
  map<string, unsigned int>::const_iterator it = m_namedIndices.find(name);
  return it->second;
}
