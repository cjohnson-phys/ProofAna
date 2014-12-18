///////////////////////////////////////////////////////////////////
// CalibrationDataInterfaceROOT.cxx, (c) ATLAS Detector software
///////////////////////////////////////////////////////////////////

#include "CalibrationDataInterface/CalibrationDataInterfaceROOT.h"
#include "CalibrationDataInterface/CalibrationDataContainer.h"

#include "CalibrationDataInterface/CalibrationDataEigenVariations.h"

#include "TMath.h"
#include "TEnv.h"
#include "TFile.h"
#include <iostream>

using std::string;
using std::cout;
using std::cerr;
using std::endl;

using Analysis::CalibrationDataContainer;
using Analysis::UncertaintyResult;
using Analysis::CalibrationDataEigenVariations;


//================ Constructor =================================================

Analysis::CalibrationDataInterfaceROOT::CalibrationDataInterfaceROOT(const string& taggerName, string configname, string pathname)
        :     m_runEigenVectorMethod(false)
{
  m_taggerName = taggerName;

  TEnv env(configname.c_str());

  // ROOT file containing the calibrations
  TString filename = env.GetValue("File", "BTaggingPerformanceCalibrations.root");
  TString filenameEff = env.GetValue("FileEff", "");
  TString filenameSF = env.GetValue("FileSF", "");
  if (filenameEff == "") {
    filenameEff = pathname + filename;
  }
  if (filenameSF == "") {
    filenameSF = pathname + filename;
  }

  cout << "=== CalibrationDataInterfaceROOT::CalibrationDataInterfaceROOT ===" << endl;
  cout << " Config name          : " << configname.c_str() << endl;
  cout << " taggerName           : " << taggerName.c_str() << endl;
  cout << " Efficiency file name : " << filenameEff.Data() << endl 
       << " SF         file name : " << filenameSF.Data() << endl
       << endl;
  // cout << "     : " << << endl;

  m_fileEff = new TFile(filenameEff.Data(), "READ");
  if (filenameEff == filenameSF)
    m_fileSF = m_fileEff;
  else
    m_fileSF = new TFile(filenameSF.Data(), "READ");
  
  // Calibration names for the efficiencies
  string testPrefix(taggerName); testPrefix += ".";
  string test(testPrefix); test += "EfficiencyCalibrationBName";
  string calibrationBName(env.GetValue(test.c_str(), "default"));
  test = testPrefix; test += "EfficiencyCalibrationCName";
  string calibrationCName(env.GetValue(test.c_str(), "default"));
  test = testPrefix; test += "EfficiencyCalibrationTName";
  string calibrationTName(env.GetValue(test.c_str(), "default"));
  test = testPrefix; test += "EfficiencyCalibrationLightName";
  string calibrationLightName(env.GetValue(test.c_str(), "default"));

  // insert the calibration names into a common object
  std::map<string, string> names;
  names["B"] = calibrationBName;
  names["C"] = calibrationCName;
  names["T"] = calibrationTName;
  names["Light"] = calibrationLightName;
  setEffCalibrationNames(names);

  // Calibration names for the efficiency scale factors
  test = testPrefix; test += "ScaleFactorCalibrationBName";
  calibrationBName = env.GetValue(test.c_str(), "default");
  test = testPrefix; test += "ScaleFactorCalibrationCName";
  calibrationCName = env.GetValue(test.c_str(), "default");
  test = testPrefix; test += "ScaleFactorCalibrationTName";
  calibrationTName = env.GetValue(test.c_str(), "default");
  test = testPrefix; test += "ScaleFactorCalibrationLightName";
  calibrationLightName = env.GetValue(test.c_str(), "default");

  // insert the calibration names into a common object
  names["B"] = calibrationBName;
  names["C"] = calibrationCName;
  names["T"] = calibrationTName;
  names["Light"] = calibrationLightName;
  setSFCalibrationNames(names);

  // Since TEnv doesn't allow for straight retrieval of vectors of strings, expect
  // semicolon-separated entries (semicolon because ROOT considers this as a "special"
  // token anyway in object names).
  test = testPrefix; test += "operatingPoints";
  string OP(env.GetValue(test.c_str(), ""));
  string::size_type end;
  if (OP.size() > 0) {
    do {
      end = OP.find(";");
      m_operatingPoints.push_back(OP.substr(0,end));
      if (end != string::npos) OP = OP.substr(end+1);
    } while (end != string::npos);
  }

  // Do the same thing for the aliases. Don't prefix this since the aliases are
  // common to all taggers (even if they are read again for each tagger).
  string AL(env.GetValue("aliases", ""));
  if (AL.size() > 0) {
    do {
      end = AL.find(";");
      string alias = AL.substr(0, end);
      // Each alias specification uses an arrow ("->"). Forget about entries
      // not properly following this specification.
      // NB: TEnv imposes a maximum string length of 1024 characters -- is this a problem?
      string::size_type arrow = alias.find("->");
      if (arrow == string::npos) continue;
      m_aliases[alias.substr(0,arrow)] = alias.substr(arrow+2);
      if (end != string::npos) AL = AL.substr(end+1);
    } while (end != string::npos);
  }

  //run egenvector method or not?
  test="runEigenVectorMethod";
  m_runEigenVectorMethod=(bool)env.GetValue(test.c_str(),0);

  if (m_runEigenVectorMethod)
  {
    // Retrieve the list of systematic uncertainties not to be considered when building up 
    // the full covariance matrix used for the eigenvector method
    test = "excludeFromCovMatrix";
    string uncList(env.GetValue(test.c_str(), ""));
    string::size_type end2;
    if (uncList.size() > 0) {
      do {
        end2 = uncList.find(";");
        m_excludeFromCovMatrix.push_back(uncList.substr(0,end2));
        if (end2 != string::npos) uncList = uncList.substr(end2+1);
      } while (end2 != string::npos);
    }
  }

  cout << " List of uncertainties to exclude: " << endl;
  for (unsigned int i = 0; i < m_excludeFromCovMatrix.size(); ++i) {
    cout << "\t"<< m_excludeFromCovMatrix[i] << endl;
  }
  

}

//================ Default constructor for PROOF purposes ===================== 
Analysis::CalibrationDataInterfaceROOT::CalibrationDataInterfaceROOT() 
{ 
  m_fileEff=0; 
  m_fileSF=0; 
} 

//================ Destructor =================================================

Analysis::CalibrationDataInterfaceROOT::~CalibrationDataInterfaceROOT()
{
  if ((m_fileEff!=0) && (m_fileSF!=0)) { 
    if (m_fileEff == m_fileSF) { 
      m_fileEff->Close(); 
      delete m_fileEff; m_fileEff = 0; 
    } else { 
      m_fileEff->Close(); 
      m_fileSF->Close(); 
      delete m_fileEff; m_fileEff = 0; 
      delete m_fileSF;  m_fileSF = 0; 
    } 
  }

  // delete also the stored objects (these are owned by us)
  for (std::vector<CalibrationDataContainer*>::iterator it = m_objects.begin();
       it != m_objects.end(); ++it) {
    if (*it) delete *it;
  }
}

bool
Analysis::CalibrationDataInterfaceROOT::retrieveCalibrationIndex (const std::string& label,
								  const std::string& OP,
								  const std::string& author,
								  bool isSF,
								  unsigned int& index) const
{
  index = 0;

  // construct the full name from the label, operating point, SF/Eff choice;
  // then look up this full name

  std::string name = fullName(author, OP, label, isSF);
  std::map<string, unsigned int>::const_iterator it = m_objectIndices.find(name);
  if (it == m_objectIndices.end()) {
    // if no container is found, attempt to retrieve it here (this is so that users won't
    // have to call the named scale factor etc. methods once just to retrieve the container)
    const_cast<Analysis::CalibrationDataInterfaceROOT*>(this)->retrieveContainer(name, (! isSF));
    it = m_objectIndices.find(name);
    if (it == m_objectIndices.end()) return false;
  }

  index = it->second;
  return true;
}

//====================== efficiency scale factor retrieval =============================

Analysis::CalibResult
Analysis::CalibrationDataInterfaceROOT::getScaleFactor (const CalibrationDataVariables& variables,
							const string& label, const string& OP,
							Uncertainty unc, unsigned int numVariation) const
{

  unsigned int index;
  if (! retrieveCalibrationIndex (label, OP, variables.jetAuthor, true, index)) {
    cerr << "getScaleFactor: unable to find SF calibration for object "
	 << fullName(variables.jetAuthor, OP, label, true) << endl;
    // Return a dummy result if the object is not found
    return Analysis::dummyResult;
  }
  
  return getScaleFactor(variables, index, unc, numVariation);
}

Analysis::CalibResult
Analysis::CalibrationDataInterfaceROOT::getScaleFactor (const CalibrationDataVariables& variables,
							unsigned int index, Uncertainty unc,
							unsigned int numVariation) const
{
  CalibrationDataContainer* container = m_objects[index];
  if (! container) return Analysis::dummyResult;

  // always retrieve the result itself
  double value;
  if (container->getResult(variables, value) == CalibrationDataContainer::kError)
    return Analysis::dummyResult;

  if (!m_runEigenVectorMethod && (unc == SFEigen || unc == SFNamed))
  {
     cerr << " ERROR. Trying to call eigenvector method but initialization not switched on in b-tagging .env config file." << endl;
     cerr << " Please correct your .env config file first. Nominal uncertainties used. " << endl;
  }
  if (unc == SFEigen || unc == SFNamed) {
    const CalibrationDataEigenVariations* eigenVariation=m_eigenVariationsMap[container];
    //eigenVariation=retrieveCalibrationDataEV(container);
    if (! eigenVariation) {
      cerr << " Could not retrieve eigenvector variation, while it should have been there." << endl;
      return Analysis::dummyResult;
    }
    unsigned int maxVariations = (unc == SFEigen) ? eigenVariation->getNumberOfEigenVariations() : eigenVariation->getNumberOfNamedVariations();
    if (numVariation > maxVariations-1) {
      cerr << "Asked for " << ((unc == SFEigen) ? "eigenvariation" : "named variation") << " number: " << numVariation << 
	" but overall number of available variations is: " << maxVariations << endl;
      return Analysis::dummyResult;
    }
    TH1* up=0;
    TH1* down=0;
    bool isOK = (unc == SFEigen) ?
      eigenVariation->getEigenvectorVariation(numVariation,up,down) :
      eigenVariation->getNamedVariation(numVariation,up,down);
    if (!isOK) {
      cerr << "Eigenvector object is there but cannot retrieve up and down uncertainty histograms." << endl;
      return Analysis::dummyResult;
    }
    
    double valueUp;
    double valueDown;
    if ((container->getResult(variables, valueUp,up) == CalibrationDataContainer::kError) ||
	(container->getResult(variables, valueDown,down) == CalibrationDataContainer::kError))
      return Analysis::dummyResult;

    return std::make_pair<double, double>(valueUp, valueDown);
  }//end eigenvector method

  //Proceed with no-eigenvector result
    
  // retrieve the statistical uncertainty if desired
  double stat(0);
  if (unc == Total || unc == Statistical) {
    if (container->getStatUncertainty(variables, stat) == CalibrationDataContainer::kError)
      cerr << "getScaleFactor: error retrieving Scale factor parameter covariance matrix!"
	   << endl;
  }
  Analysis::UncertaintyResult resSyst(0,0);
  if (unc == Total || unc == Systematic) {
    if (container->getSystUncertainty(variables, resSyst) == CalibrationDataContainer::kError)
      cerr << "getScaleFactor: error retrieving Scale factor parameter systematic uncertainty!"
	   << endl;
  }

  double uncertainty = combinedUncertainty(stat, resSyst);
  Analysis::CalibResult result = std::make_pair<double, double>(value, uncertainty);

  result.first = std::max(0., result.first);
  if (TMath::Abs(result.first) < Analysis::CalibZERO)
    result.first = 1.;
  return result;

}

//====================== "MC" efficiency retrieval ======================================

Analysis::CalibResult
Analysis::CalibrationDataInterfaceROOT::getMCEfficiency (const CalibrationDataVariables& variables,
							 const string& label, const string& OP,
							 Uncertainty unc) const
{
  unsigned int index;
  if (! retrieveCalibrationIndex (label, OP, variables.jetAuthor, false, index)) {
    cerr << "getMCEfficiency: unable to find Eff calibration for object "
	 << fullName(variables.jetAuthor, OP, label, false) << endl;
    // Return a dummy result if the object is not found
    return Analysis::dummyResult;
  }
  
  return getMCEfficiency(variables, index, unc);
}

Analysis::CalibResult
Analysis::CalibrationDataInterfaceROOT::getMCEfficiency (const CalibrationDataVariables& variables,
							 unsigned int index, Uncertainty unc) const
{
  CalibrationDataContainer* container = m_objects[index];
  if (! container) return Analysis::dummyResult;
  
  // always retrieve the result itself
  double value;
  if (container->getResult(variables, value) == CalibrationDataContainer::kError)
    return Analysis::dummyResult;

  // retrieve the statistical uncertainty if desired
  double stat(0);
  if (unc == Total || unc == Statistical) {
    if (container->getStatUncertainty(variables, stat) == CalibrationDataContainer::kError)
      cerr << "getScaleFactor: error retrieving Scale factor parameter covariance matrix!"
	   << endl;
  }
  // Temporary(?) hack: comment this out since the present MC results don't have "systematics" contributions
  // Analysis::UncertaintyResult resSyst(0,0);
  // if (unc == Total || unc == Systematic) {
  //   if (container->getSystUncertainty(variables, resSyst) == CalibrationDataContainer::kError)
  //     cerr << "getScaleFactor: error retrieving Scale factor parameter covariance matrix!"
  // 	   << endl;
  // }

  // since there is no combination of stat/syst uncertainties to be made, comment this out too
  double uncertainty = stat; // combinedUncertainty(stat, resSyst);
  Analysis::CalibResult result = std::make_pair<double, double>(value, uncertainty);

  result.first = std::max(0., std::min(1., result.first));
  return result;
}

//====================== efficiency retrieval ==========================================

Analysis::CalibResult
Analysis::CalibrationDataInterfaceROOT::getEfficiency (const CalibrationDataVariables& variables,
						       const string& label,
						       const string& OP, Uncertainty unc,
                                                       unsigned int numVariation) const
{

  unsigned int indexSF, indexEff;
  if (! (retrieveCalibrationIndex (label, OP, variables.jetAuthor, false, indexEff) &&
	 retrieveCalibrationIndex (label, OP, variables.jetAuthor, true, indexSF))) {
    cerr << "getEfficiency: unable to find SF/Eff calibration for object "
	 << fullName(variables.jetAuthor, OP, label, false) << endl;
    // Return a dummy result if the object is not found
    return Analysis::dummyResult;
  }
  
  return getEfficiency(variables, indexSF, indexEff, unc, numVariation);
}

Analysis::CalibResult
Analysis::CalibrationDataInterfaceROOT::getEfficiency (const CalibrationDataVariables& variables,
						       unsigned int indexSF, unsigned int indexEff,
						       Uncertainty unc, unsigned int numVariation) const
{
  Analysis::CalibResult sfResult = getScaleFactor(variables, indexSF, unc, numVariation);
  Analysis::CalibResult effResult = getMCEfficiency(variables, indexEff, unc);

  double relative = 0;
  double value = effResult.first;
  if (TMath::Abs(sfResult.first) > Analysis::CalibZERO) {
    value = std::min(effResult.first*sfResult.first, 1.);

    // Treat the scale factor variation cases separately since the contents of the CalibResult are different
    // (e.g. 'value' above contains the upward variation)
    if (unc == SFEigen || unc == SFNamed) {
      double valueDown = effResult.first*sfResult.second;
      return std::make_pair(value, valueDown);
    }
    if (value > 0.) {
      relative = effResult.second/effResult.first;
      double sfRelative = sfResult.second/sfResult.first;
      /*
	cout << "sferr=" << sfResult.second
	<< "btag Calib relative=" << relative << " sfRelative=" << sfRelative << endl;
      */
      relative = TMath::Sqrt(sfRelative*sfRelative + relative*relative);
    }
  } else {
    // now never happens due to protection of SF return value:
    cerr << "ERROR: CalibrationDataInterfaceROOT::getEfficiency: SF null result, SF=" << sfResult.first
	 << " MC eff=" << effResult.first 
	 << "; setting SF=1."
	 << endl;
    relative = Analysis::dummyValue;
  }

  return std::make_pair(value,value*relative);
}


//====================== "MC" inefficiency scale factor retrieval ======================================

Analysis::CalibResult
Analysis::CalibrationDataInterfaceROOT::getInefficiencyScaleFactor (const CalibrationDataVariables& variables,
								    const string& label,
								    const string& OP, Uncertainty unc,
								    unsigned int numVariation) const
{

  unsigned int indexSF, indexEff;
  if (! (retrieveCalibrationIndex (label, OP, variables.jetAuthor, false, indexEff) &&
	 retrieveCalibrationIndex (label, OP, variables.jetAuthor, true, indexSF))) {
    cerr << "getInefficiencyScaleFactor: unable to find SF/Eff calibration for object "
	 << fullName(variables.jetAuthor, OP, label, false) << endl;
    // Return a dummy result if the object is not found
    return Analysis::dummyResult;
  }
  
  return getInefficiencyScaleFactor(variables, indexSF, indexEff, unc, numVariation);
}

Analysis::CalibResult
Analysis::CalibrationDataInterfaceROOT::getInefficiencyScaleFactor(const CalibrationDataVariables& variables,
								   unsigned int indexSF, unsigned int indexEff,
								   Uncertainty unc, unsigned int numVariation) const
{

  Analysis::CalibResult effResult = getMCEfficiency(variables, indexEff, unc);
  Analysis::CalibResult sfResult = getScaleFactor(variables, indexSF, unc, numVariation);

  double eff = std::min(effResult.first, 1.);
  double efferr = effResult.second;
  double sf = sfResult.first; 
  double sferr = sfResult.second; 

  double val = 0.; // Analysis::dummyValue;
  double err = 0.; // Analysis::dummyValue;
  if (1. - eff > CalibZERO) {
    val = (1. - eff*sf) / (1. - eff);
    // Treat the scale factor variation cases separately since the contents of the CalibResult are different
    // ('sf' and 'sferr' above contain the upward and downward variations, respectively)
    if (unc == SFEigen || unc == SFNamed) {
      double valDown = (1. - eff*sferr) / (1. - eff);
      return std::make_pair(val, valDown);
    }
    err = pow((1. - sf) / (1. - eff) * efferr, 2) + pow(eff*sferr, 2);
    if (err > 0.)
      err = 1./(1. - eff) * TMath::Sqrt(err);
    // cout << "btag Calib Ineff err=" << err << endl;
  }

  return std::make_pair(std::max(0., val), err);

}

//====================== inefficiency retrieval ======================================

Analysis::CalibResult
Analysis::CalibrationDataInterfaceROOT::getInefficiency (const CalibrationDataVariables& variables,
							 const string& label,
							 const string& OP, Uncertainty unc,
							 unsigned int numVariation) const
{

  unsigned int indexSF, indexEff;
  if (! (retrieveCalibrationIndex (label, OP, variables.jetAuthor, false, indexEff) &&
	 retrieveCalibrationIndex (label, OP, variables.jetAuthor, true, indexSF))) {
    cerr << "getInefficiencyScaleFactor: unable to find SF/Eff calibration for object "
	 << fullName(variables.jetAuthor, OP, label, false) << endl;
    // Return a dummy result if the object is not found
    return Analysis::dummyResult;
  }
  
  return getInefficiency(variables, indexSF, indexEff, unc, numVariation);
}

Analysis::CalibResult
Analysis::CalibrationDataInterfaceROOT::getInefficiency (const CalibrationDataVariables& variables,
							 unsigned int indexSF, unsigned int indexEff,
							 Uncertainty unc, unsigned int numVariation) const
{
  Analysis::CalibResult effResult = getMCEfficiency(variables, indexEff, unc);
  Analysis::CalibResult sfResult = getScaleFactor(variables, indexSF, unc, numVariation);
  
  double val = std::max(0., 1. - effResult.first * sfResult.first);
  double err = 0.; // Analysis::dummyValue;
  if (effResult.first > 0. && sfResult.first > 0.) 
    // Treat the scale factor variation cases separately since the contents of the CalibResult are different
    // (e.g. 'val' above contains the upward variation)
    if (unc == SFEigen || unc == SFNamed) {
      double valDown = std::max(0., 1. - effResult.first*sfResult.second);
      return std::make_pair(val, valDown);
    }
    // safer than pow(x, 2):
    err = effResult.second/effResult.first*effResult.second/effResult.first + sfResult.second/sfResult.first*sfResult.second/sfResult.first;
  //  cout << "btag Calib Ineff err*err=" << err << endl;
  if (err > 0.)
    err = val*TMath::Sqrt(err);
  //  else err = Analysis::dummyValue;
  return std::make_pair(std::max(0., std::min(1., val)), err);

}

//====================== "MC" inefficiency retrieval ======================================

Analysis::CalibResult
Analysis::CalibrationDataInterfaceROOT::getMCInefficiency (const CalibrationDataVariables& variables,
							   const string& label,
							   const string& OP, Uncertainty unc) const
{
  Analysis::CalibResult effResult = getMCEfficiency(variables, label, OP, unc);
  return std::make_pair(std::max(0., 1. - effResult.first), effResult.second);
}

Analysis::CalibResult
Analysis::CalibrationDataInterfaceROOT::getMCInefficiency (const CalibrationDataVariables& variables,
							   unsigned int index, Uncertainty unc) const
{
  Analysis::CalibResult effResult = getMCEfficiency(variables, index, unc);
  return std::make_pair(std::max(0., 1. - effResult.first), effResult.second);
}

//====================== retrieval of sources of uncertainty ==============================

std::vector<string>
Analysis::CalibrationDataInterfaceROOT::listScaleFactorUncertainties(const string& author,
								     const string& label,
								     const string& OP,
								     bool named) const
{
  unsigned int index;
  if (! retrieveCalibrationIndex (label, OP, author, true, index)) {
    // Return a dummy result if the object is not found
    cerr << "listScaleFactorUncertainties: unable to find SF calibration for object "
	 << fullName(author, OP, label, true) << endl;
    std::vector<string> dummy;
    return dummy;
  }
  return listScaleFactorUncertainties(index, named);
}

std::vector<string>
Analysis::CalibrationDataInterfaceROOT::listScaleFactorUncertainties(unsigned int index,
								     bool named) const
{
  std::vector<string> dummy;
  CalibrationDataContainer* container = m_objects[index];
  if (container) {
    if (named) {
      // Find out which uncertainties are excluded from eigenvector construction
      if (! m_runEigenVectorMethod) return dummy;
      const CalibrationDataEigenVariations* eigenVariation=m_eigenVariationsMap[container];
      std::vector<string> unordered = eigenVariation->listNamedVariations();
      std::vector<string> ordered(unordered.size());
      for (unsigned int i = 0; i < unordered.size(); ++i)
	ordered[eigenVariation->getNamedVariationIndex(unordered[i])] = unordered[i];
      return ordered;
    }
    return container->listUncertainties();
  }

  return dummy;
}

unsigned int
Analysis::CalibrationDataInterfaceROOT::getNumVariations(const std::string& author,
							 const std::string& label,
							 const std::string& OP,
							 Uncertainty unc) const
{
  unsigned int index;
  if (! retrieveCalibrationIndex (label, OP, author, true, index)) return 0;
  return getNumVariations(index, unc);
}

unsigned int
Analysis::CalibrationDataInterfaceROOT::getNumVariations(unsigned int index,
							 Uncertainty unc) const
{
  if (! (unc == SFEigen || unc == SFNamed)) return 0;
  CalibrationDataContainer* container = m_objects[index];
  if (! container) return 0;
  const CalibrationDataEigenVariations* eigenVariation=m_eigenVariationsMap[container];
  return (unc == SFEigen) ?
    eigenVariation->getNumberOfEigenVariations() :
    eigenVariation->getNumberOfNamedVariations();
}

//====================== retrieval of central calibration object ===========================

const TH1*
Analysis::CalibrationDataInterfaceROOT::getBinnedScaleFactors (const std::string& author,
							       const std::string& label,
							       const std::string& OP) const
{
  unsigned int index;
  if (! retrieveCalibrationIndex (label, OP, author, true, index)) {
    // Return a dummy result if the object is not found
    cerr << "getBinnedScaleFactors: unable to find SF calibration for object "
	 << fullName(author, OP, label, true) << endl;
    return 0;
  }
  CalibrationDataHistogramContainer* container = dynamic_cast<CalibrationDataHistogramContainer*>(m_objects[index]);
  return (container) ? dynamic_cast<TH1*>(container->GetValue("result")) : 0;
}

//====================== retrieval of shifted calibration object ===========================

const TH1*
Analysis::CalibrationDataInterfaceROOT::getShiftedScaleFactors (const std::string& author,
								const std::string& label,
								const std::string& OP,
								const std::string& unc,
								double sigmas) const
{
  // quick sanity check
  if (unc == "comment" || unc == "result" || unc == "combined" || unc == "statistics") return 0;

  unsigned int index;
  if (! retrieveCalibrationIndex (label, OP, author, true, index)) {
    // Return a null result if the object is not found
    cerr << "getShiftedScaleFactors: unable to find SF calibration for object "
	 << fullName(author, OP, label, true) << endl;
    return 0;
  }
  CalibrationDataHistogramContainer* container = dynamic_cast<CalibrationDataHistogramContainer*>(m_objects[index]);
  if (! container) return 0;

  TH1* result = dynamic_cast<TH1*>(container->GetValue("result"));
  TH1* hunc = dynamic_cast<TH1*>(container->GetValue(unc.c_str()));
  // another sanity check...
  if ((! hunc) || (! result)) return 0;
  if (hunc->GetDimension() != result->GetDimension() || hunc->GetNbinsX() != result->GetNbinsX() ||
      hunc->GetNbinsX() != result->GetNbinsX() || hunc->GetNbinsX() != result->GetNbinsX())
    return 0;
  // also check that the uncertainty is to be treated as correlated from bin to bin
  // (for the variation is applied coherently, which isn't appropriate for uncertainties
  // that aren't correlated from bin to bin)
  if (! container->isBinCorrelated(unc)) return 0;

  // if everything is consistent, the actual operation simply consists of adding histograms...
  std::string name(container->GetName()); name += "_"; name += unc; name += "_";
  TH1* shifted = dynamic_cast<TH1*>(result->Clone(name.c_str()));
  shifted->Add(hunc, sigmas);
  return shifted;
}

//====================== put some utility functions here ===================================

namespace {
  // Construct the (diagonal) covariance matrix for the statistical uncertainties on the "ref" results
  TMatrixDSym getStatCovarianceMatrix(const TH1* hist) {
    Int_t nbinx = hist->GetNbinsX()+2, nbiny = hist->GetNbinsY()+2, nbinz = hist->GetNbinsZ()+2;
    Int_t rows = nbinx;
    if (hist->GetDimension() > 1) rows *= nbiny;
    if (hist->GetDimension() > 2) rows *= nbinz;
    TMatrixDSym stat(rows);
    for (Int_t binx = 1; binx < nbinx; ++binx)
      for (Int_t biny = 1; biny < nbiny; ++biny)
	for (Int_t binz = 1; binz < nbinz; ++binz) {
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
      cout << "getSystCovarianceMatrix: inconsistency found in histograms "
	   << ref->GetName() << " and " << unc->GetName() << endl;
      return cov;
    }

    // Special case: uncertainties not correlated from bin to bin
    if (! doCorrelated) {
      for (Int_t binx = 1; binx < nbinx; ++binx)
	for (Int_t biny = 1; biny < nbiny; ++biny)
	  for (Int_t binz = 1; binz < nbinz; ++binz) {
	    Int_t bin = ref->GetBin(binx, biny, binz);
	    double err = ref->GetBinError(bin);
	    cov(bin,bin) = err*err;
	  }
      return cov;
    }

    for (Int_t binx = 1; binx < nbinx; ++binx)
      for (Int_t biny = 1; biny < nbiny; ++biny)
	for (Int_t binz = 1; binz < nbinz; ++binz) {
	  Int_t bin = ref->GetBin(binx, biny, binz);
	  double err = ref->GetBinError(bin);
	  for (Int_t binx2 = 1; binx2 < nbinx; ++binx2)
	    for (Int_t biny2 = 1; biny2 < nbiny; ++biny2)
	      for (Int_t binz2 = 1; binz2 < nbinz; ++binz2) {
		Int_t bin2 = ref->GetBin(binx2, biny2, binz2);
		double err2 = ref->GetBinError(bin2);
		cov(bin, bin2) = err*err2;
	      }
	}
    return cov;
  }

}

//====================== retrieval of calibration covariance matrix ========================

TMatrixDSym 
Analysis::CalibrationDataInterfaceROOT::getScaleFactorCovarianceMatrix (const std::string& author,
									const std::string& label,
									const std::string& OP,
									const std::string& unc) const
{
  // Catch issues with the specified input as early as possible
  TMatrixDSym dummy;
  if (unc == "comment" || unc == "result" || unc == "combined") return dummy;

  unsigned int index;
  if (! retrieveCalibrationIndex (label, OP, author, true, index)) {
  // Return a dummy result if the object is not found
    cerr << "getScaleFactorCovarianceMatrix: unable to find SF calibration for object "
	 << fullName(author, OP, label, true) << endl;
    return dummy;
  }
  CalibrationDataHistogramContainer* container = dynamic_cast<CalibrationDataHistogramContainer*>(m_objects[index]);
  if (!container) return dummy;

  // retrieve the central calibration and its axes
  TH1* result = dynamic_cast<TH1*>(container->GetValue("result"));
  if (! result) return dummy;
  std::vector<unsigned int> varResult = CalibrationDataContainer::getVariableTypes(result);

  // "normal" case: single source of uncertainty
  if (unc != "all") {
    if (unc == "statistics") {
      return getStatCovarianceMatrix(result);
    } else {
      TH1* hunc = dynamic_cast<TH1*>(container->GetValue(unc.c_str()));
      if (! hunc) {
	cout << "getScaleFactorCovarianceMatrix: no uncertainty object found "
	     << "corresponding to name " << unc << endl;
	return dummy;
      }
      return getSystCovarianceMatrix(result, hunc, container->isBinCorrelated(unc));
    }
  }

  // special case: complete covariance matrix. This is to be constructed
  // as the sum over all individual contributions.
  // First, treat the statistics separately (as above)
  TMatrixDSym cov = getStatCovarianceMatrix(result);

  // Then loop through the list of (other) uncertainties
  std::vector<string> uncs = container->listUncertainties();
  for (unsigned int t = 0; t < uncs.size(); ++t) {
    if (uncs[t] == "comment" || uncs[t] == "result" ||
	uncs[t] == "combined" || uncs[t] == "statistics") continue;
    TH1* hunc = dynamic_cast<TH1*>(container->GetValue(uncs[t].c_str()));
    cov += getSystCovarianceMatrix(result, hunc, container->isBinCorrelated(uncs[t]));
  }

  return cov;
}

// Preload objects necessary so that input calibration file can be closed. 
// This is only needed when using PROOF. 
void 
Analysis::CalibrationDataInterfaceROOT::initialize(const string& jetauthor, const string& OP, Uncertainty unc) 
{ 
  if((!m_fileEff)||(!m_fileSF)) { 
    cerr << "initialize can only be called once per CalibrationDataInterfaceROOT object" << endl; 
    return; 
  } else { 
    cout << "initializing BTagCalibrationDataInterfaceROOT for PROOF with jetAuthor = " << jetauthor  
	 << ", tagger = " << m_taggerName << ", operating point = " << OP << ", uncertainty = " << unc << endl; 
  } 
 		 
  // quark flavours 
  std::vector<string> label; 
  label.push_back("C"); 
  label.push_back("B"); 
  label.push_back("T"); 
  label.push_back("Light"); 
 		 
  CalibrationDataVariables BTagVars; 
  BTagVars.jetAuthor = jetauthor; 
  BTagVars.jetPt  = 100000.; //Irrelevant, just has to be valid to retrieve objects 
  BTagVars.jetEta = 1.5; //Irrelevant, just has to be valid to retrieve objects 
 		 
  std::vector<string>::iterator flav = label.begin(); 
  for(; flav!=label.end(); flav++) { 
    std::pair<double, double> BTagCalibResult; 
    BTagCalibResult = getScaleFactor(BTagVars,(*flav), OP, unc); 
 		 
    std::pair<double, double> BTagCalibMCEff; 
    BTagCalibMCEff = getMCEfficiency(BTagVars,(*flav), OP, unc); 
  }      
 		 
  if (m_fileEff != m_fileSF) { 
    m_fileEff->Close(); 
    delete m_fileEff; 
  } 
  m_fileSF->Close(); 
  delete m_fileSF; 
  m_fileEff = 0; //prevents repeat deletion in destructor 
  m_fileSF = 0; //prevents repeat deletion in destructor 
} 

CalibrationDataContainer*
Analysis::CalibrationDataInterfaceROOT::retrieveContainer(const string& name, bool eff)
{
  // The test below can be commented out since it's already carried out in retrieveCalibrationIndex()
  // std::map<string, CalibrationDataContainer*>::iterator it = m_objectIndices.find(name);
  // if (it != m_objectIndices.end()) return m_objects[it->second];

  // If the object cannot be found, then each call will result in a new attempt to
  // retrieve the object from the ROOT file. Hopefully this will not happen too often...
  m_objectIndices[name] = m_objects.size();
  CalibrationDataContainer* cnt =
    dynamic_cast<CalibrationDataContainer*>((eff ? m_fileEff : m_fileSF) ->Get(name.c_str()));
  m_objects.push_back(cnt);
  if (!cnt)
    cout << "btag Calib: retrieveContainer: failed 2nd attempt to get " << name.c_str() << endl;

  if (m_runEigenVectorMethod && !TString(name).Contains("_Eff"))
  {
    const CalibrationDataHistogramContainer* histoContainer=dynamic_cast<const CalibrationDataHistogramContainer*>(cnt);
    if (histoContainer==0)
    {
      cerr << "Could not cast Container to a HistogramContainer. " << endl;
      return 0;
    }
    CalibrationDataEigenVariations* newEigenVariation=new CalibrationDataEigenVariations(histoContainer);

    std::vector<std::string>::const_iterator listBegin=m_excludeFromCovMatrix.begin();
    std::vector<std::string>::const_iterator listEnd=m_excludeFromCovMatrix.end();
    
    for (std::vector<std::string>::const_iterator listIter=listBegin;listIter!=listEnd;++listIter)
    {
      newEigenVariation->excludeNamedUncertainty(*listIter);
    }

    newEigenVariation->initialize();

    if (newEigenVariation==0)
    {
      cerr << " Could not create eigenvector variations. " << endl;
      return 0;
    }
    m_eigenVariationsMap[cnt]=newEigenVariation;
  }

  return cnt;
}

string
Analysis::CalibrationDataInterfaceROOT::getAlias(const string& author) const
{
  std::map<string,string>::const_iterator it = m_aliases.find(author);
  return (it == m_aliases.end()) ? author : it->second;
}

string
Analysis::CalibrationDataInterfaceROOT::fullName(const string& author, const string& OP,
						 const string& label, bool isSF) const
{
  string full(m_taggerName); full += "/";
  full += getAlias(author); full += "/";
  string name = (isSF) ?
    getBasename(OP, label, "_SF", true) :
    getBasename(OP, label, "_Eff", false);
  full += name;
  return full;
}
