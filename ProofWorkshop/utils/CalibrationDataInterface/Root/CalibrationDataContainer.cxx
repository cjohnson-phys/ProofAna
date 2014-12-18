///////////////////////////////////////////////////////////////////
// CalibrationDataContainer.cxx, (c) ATLAS Detector software
///////////////////////////////////////////////////////////////////

#include "CalibrationDataInterface/CalibrationDataContainer.h"

#include <iostream>
#include <cassert>
#include <limits>

#include "TH1.h"
#include "TF1.h"
#include "TMatrixT.h"
#include "TMatrixDSym.h"
#include "TMath.h"
#include "TString.h"
#include "TObjString.h"

using Analysis::UncertaintyResult;
using Analysis::CalibrationDataContainer;
using Analysis::CalibrationDataHistogramContainer;
using Analysis::CalibrationDataFunctionContainer;

// Things that are best hidden from the outside world...
namespace {

  // The value below is added to (subtracted from) the lower (upper) bound of validity
  // when a variable is restricted to be within its validity range.
  const double rangeEpsilon = 1.e-5;

  // array size for boundary specifications
  const int maxParameters = 10;

  // Since the actual variables used for the computation can remain completely internal,
  // we can simply reserve some fixed memory for them here.

  const int MAXVARS = 3;
  Double_t vars[MAXVARS];
}




// ---------------------- CalibrationDataContainer base class ----------------------------

CalibrationDataContainer::CalibrationDataContainer(const char* name) :
  TMap(), m_restrict(false)
{
  SetName(name);
}

CalibrationDataContainer::~CalibrationDataContainer()
{
}

// short-hand for the total systematic uncertainty retrieval

CalibrationDataContainer::CalibrationStatus
CalibrationDataContainer::getSystUncertainty(const CalibrationDataVariables& x,
					     UncertaintyResult& result, TObject* obj) const
{
  return getUncertainty("systematics", x, result, obj);
}

// retrieve the list of uncertainties for this calibration

std::vector<std::string>
CalibrationDataContainer::listUncertainties() const
{
  std::vector<std::string> uncertainties;
  TIter it(GetTable());
  while (TPair* pair = (TPair*) it()) {
    std::string spec(pair->Key()->GetName());
    uncertainties.push_back(spec);
  }
  return uncertainties;
}

// retrieve all uncertainties for this calibration

CalibrationDataContainer::CalibrationStatus
CalibrationDataContainer::getUncertainties(const CalibrationDataVariables& x,
					   std::map<std::string, UncertaintyResult>& all) const
{
  CalibrationStatus mycode(kSuccess);
  UncertaintyResult result;

  // first treat the "result" entry separately
  double single_result;
  CalibrationStatus code = getResult(x, single_result);
  if (code == kError) {
    std::cerr << "in CalibrationDataContainer::getUncertainties(): error retrieving result!" << std::endl;
    return code;
  }
  else if (code != kSuccess) mycode = code;
  result.first = single_result;
  result.second = 0;
  all[std::string("result")] = result;

  // similar for the "statistics" entry
  code = getStatUncertainty(x, single_result);
  if (code == kError) {
    std::cerr << "in CalibrationDataContainer::getUncertainties(): error retrieving stat. uncertainty!" << std::endl;
    return code;
  }
  else if (code != kSuccess) mycode = code;
  result.first  =  single_result;
  result.second = -single_result;
  all[std::string("statistics")] = result;

  // then cycle through the other (systematic) uncertainties
  TIter it(GetTable());
  while (TPair* pair = (TPair*) it()) {
    std::string spec(pair->Key()->GetName());
    // ignore these specific entries
    if (spec == "comment" || spec == "result" || spec == "statistics") continue;
    code = getUncertainty(spec, x, result, pair->Value());
    // we should never be finding any errors
    if (code == kError) {
      std::cerr << "in CalibrationDataContainer::getUncertainties(): error retrieving named uncertainty "
		<< spec << "!" << std::endl;
      return code;
    }
    // this assumes that non-success codes are likely to be correlated between uncertainty sources
    else if (code != kSuccess) mycode = code;
    all[spec] = result;
  }
  return mycode;
}

// retrieve the comments for this calibration (if any)

std::string
CalibrationDataContainer::getComment() const
{
  TObject* obj = GetValue("comment");
  if (! obj) return std::string("");
  TObjString* s = dynamic_cast<TObjString*>(obj);
  if (! s ) return std::string("");
  return std::string(s->GetName());
}

// insert the given object at the position indicated by the given 'uncertainty' index

void
CalibrationDataContainer::setUncertainty(const std::string& unc, TObject* obj)
{
  if (TPair* p = (TPair*) FindObject(unc.c_str())) DeleteEntry(p->Key());
  Add(new TObjString(unc.c_str()), obj);
}

// specialization of the above: insert the calibration result

void
CalibrationDataContainer::setResult(TObject* obj)
{
  setUncertainty(std::string("result"), obj);
}

// special case: TString itself doesn't inherit from TObject

void
CalibrationDataContainer::setComment(const std::string& text)
{
  if (TPair* p = (TPair*) FindObject("comment")) DeleteEntry(p->Key());
  Add(new TObjString("comment"), new TObjString(text.c_str()));
}

// Determine which variable types are to be used for all objects (results + uncertainties).
// This needs to be done only once per calibration object, as the results will be cached
// (even if not persistified).

void
CalibrationDataContainer::computeVariableTypes() const
{
  TIter it(GetTable());
  while (TPair* pair = dynamic_cast<TPair*>(it())) {
    std::vector<unsigned int> vartypes;
    TObject* obj = pair->Value();
    TObject* key = pair->Key();
    if (!key) {
      std::cerr << "in CalibrationDataContainer::computeVariableTypes(): key = 0!" << std::endl;
      return;
    } else if (!obj) {
      std::cerr << "in CalibrationDataContainer::computeVariableTypes(): value = 0!" << std::endl;
      return;
    }
    std::string spec(key->GetName());
    if (obj && spec != "comment" && spec != "statistics") {

      vartypes = getVariableTypes(obj);
      // std::cout << " checking bounds for object #" << uncert << ", title = " << obj->GetTitle()
      // 		<< ", variable types:";
      // for (int t = 0; t < vartypes.size(); ++t) std::cout << " " << vartypes[t];
      // std::cout << std::endl;
      checkBounds(obj, vartypes);
    }
    m_variables[spec] = vartypes;
  }

  // After doing this, we should always have a non-null vector!
  assert(m_variables.size() > 0);
}

std::vector<unsigned int>
CalibrationDataContainer::getVariableTypes(const TObject* obj)
{
  std::vector<unsigned int> vartypes;

  // histograms need a special treatment, as the coordinate titles are not actually stored
  // with the title itself, but instead moved off to the axis titles...
  if (const TH1* hobj = dynamic_cast<const TH1*>(obj)) {
    int dims = hobj->GetDimension();
    for (int dim = 0; dim < dims; ++dim) {
      TAxis* axis;
      switch (dim) {
      case 0: axis = hobj->GetXaxis(); break;
      case 1: axis = hobj->GetYaxis(); break;
      default: axis = hobj->GetZaxis();
      }
      std::string var(axis->GetTitle());
      unsigned int vartype;
      if (var == "eta") {
	vartype = kEta;
      } else if (var == "abseta") {
	vartype = kAbsEta;
      } else if (var == "pt") {
	vartype = kPt;
      } else {
	// Only flag the issue but otherwise take no action (assume non-argument use of a semicolon)
	std::cerr << "in CalibrationDataContainer::getVariableTypes(): cannot construct variable type from name "
		  << var << std::endl;
      }
      vartypes.push_back(vartype);
    }
  } else {
    std::string title(obj->GetTitle());
    std::string::size_type pos = title.find(";");
    while (pos != std::string::npos && pos != title.size()) {
      title = title.substr(pos+1);
      pos = title.find(";");
      std::string var = title.substr(0, pos);
      unsigned int vartype;
      if (var == "eta") {
	vartype = kEta;
      } else if (var == "abseta") {
	vartype = kAbsEta;
      } else if (var == "pt") {
	vartype = kPt;
      } else {
	// Only flag the issue but otherwise take no action (assume non-argument use of a semicolon)
	std::cerr << "in CalibrationDataContainer::getVariableTypes(): cannot construct variable type from name "
		  << var << std::endl;
      }
      vartypes.push_back(vartype);
    }
  }
  return vartypes;
}

// Determine which variables are to be used, and insert them in a separate array.
// So this is where the translation between the input variables and the histogram/function
// variables is made.
// The return value is used to indicate whether any input co-ordinate was out of bounds

bool
CalibrationDataContainer::computeVariables(const std::string& unc,
					   const CalibrationDataVariables& x) const
{
  // ensure that the variable types have been computed properly
  if (m_variables.size() == 0) computeVariableTypes();

  // also keep track of whether the variables are within bounds
  bool OK(true);

  // it should not be possible to fail to find the uncertainty specification
  std::map<std::string, std::vector<unsigned int> >::iterator it = m_variables.find(unc);
  assert (it != m_variables.end());

  std::vector<unsigned int> vartypes = it->second;
  for (unsigned int var = 0; var < vartypes.size(); ++var) {
    switch (vartypes[var]) {
    case kPt:
      // assume that the input values are given in MeV but the performance calibration in GeV!
      vars[var] = x.jetPt * 0.001;
      break;
    case kEta:
      vars[var] = x.jetEta;
      break;
    case kAbsEta:
      vars[var] = x.jetEta;
      if (vars[var] < 0) vars[var] *= -1.0;
    }
    if (vars[var] < getLowerBound(vartypes[var])) {
      OK = false;
      if (m_restrict) vars[var] = getLowerBound(vartypes[var]) + rangeEpsilon;
    } else if (vars[var] > getUpperBound(vartypes[var])) {
      OK = false;
      if (m_restrict) vars[var] = getUpperBound(vartypes[var]) - rangeEpsilon;
    }
  }

  return OK;
}

double
CalibrationDataContainer::getLowerBound(unsigned int vartype) const
{
  double minDefault = (vartype == kAbsEta || vartype == kPt) ? 0 : -std::numeric_limits<double>::max();
  return (vartype < m_lowerBounds.size()) ? m_lowerBounds[vartype] : minDefault;
}

double
CalibrationDataContainer::getUpperBound(unsigned int vartype) const
{
  return (vartype <  m_lowerBounds.size()) ? m_upperBounds[vartype] : std::numeric_limits<double>::max();
}

std::vector<std::pair<double, double> >
CalibrationDataContainer::getBounds() const
{
  // ensure that the variable types have been computed properly
  if (m_variables.size() == 0) computeVariableTypes();

  std::vector<std::pair<double, double> > bounds;
  for (unsigned int t = 0; t < m_lowerBounds.size() && t <= kAbsEta; ++t) {
    bounds.push_back(std::make_pair<double, double>(m_lowerBounds[t], m_upperBounds[t]));
  }
  return bounds;
}

// ---------------------- CalibrationDataHistogramContainer class ----------------------

CalibrationDataHistogramContainer::CalibrationDataHistogramContainer(const char* name) :
  CalibrationDataContainer(name)
{
  // Reset the validity bounds to reflect 'no bounds'.
  // They will be re-determined upon the first computation.

  m_lowerBounds.clear();
  m_lowerBounds.resize(maxParameters, -std::numeric_limits<double>::max());
  m_lowerBounds[kPt] = m_lowerBounds[kAbsEta] = 0;
  m_upperBounds.clear();
  m_upperBounds.resize(maxParameters, std::numeric_limits<double>::max());

  // But by default, switch on the range checking
  restrictToRange(true);
}

CalibrationDataHistogramContainer::~CalibrationDataHistogramContainer()
{
}

// result retrieval

CalibrationDataContainer::CalibrationStatus
CalibrationDataHistogramContainer::getResult(const CalibrationDataVariables& x,
					     double& result, TObject* obj) const
{
  if (!obj) obj = GetValue("result");
  TH1* hist = dynamic_cast<TH1*>(obj);
  if (! hist) return kError;

  // select the relevant kinematic variables
  bool inRange = computeVariables("result", x);
  // find the relevant "global" bin.
  // Note the limitation: at most three dimensions are supported.
  // TH1::FindBin() will ignore the variables not needed.
  // Note: it is assumed that these histograms are protected against rebinning
  // using the ResetBit(TH1::kCanRebin) method
  int bin = hist->FindBin(vars[0], vars[1], vars[2]);
  result = hist->GetBinContent(bin);

  return inRange ? kSuccess : kRange;
}

// statistical uncertainty retrieval (special since it is stored with the result itself)

CalibrationDataContainer::CalibrationStatus
CalibrationDataHistogramContainer::getStatUncertainty(const CalibrationDataVariables& x,
						      double& result) const
{
  TH1* hist = dynamic_cast<TH1*>(GetValue("result"));
  if (! hist) return kError;

  // select the relevant kinematic variables
  bool inRange = computeVariables("result", x);
  // find the relevant "global" bin.
  // Note the limitation: at most three dimensions are supported.
  // TH1::FindBin() will ignore the variables not needed.
  // Note: it is assumed that these histograms are protected against rebinning
  // using the ResetBit(TH1::kCanRebin) method
  int bin = hist->FindBin(vars[0], vars[1], vars[2]);
  result = hist->GetBinError(bin);

  return inRange ? kSuccess : kRange;
}

// general uncertainty retrieval

CalibrationDataContainer::CalibrationStatus
CalibrationDataHistogramContainer::getUncertainty(const std::string& unc,
						  const CalibrationDataVariables& x,
						  UncertaintyResult& result, TObject* obj) const
{
  // treat statistical uncertainties separately (they are stored with the actual result)
  if (unc == "statistics") {
    double res;
    CalibrationStatus code = getStatUncertainty(x, res);
    if (code == kError) return code;
    result.first =   res;
    result.second = -res;
    return code;
  }

  if (!obj) obj = GetValue(unc.c_str());
  TH1* hist = dynamic_cast<TH1*>(obj);
  if (! hist) return kError;

  // select the relevant kinematic variables
  bool inRange = computeVariables(unc, x);
  // TH1::FindBin() will ignore the variables not needed.
  // Note: it is assumed that these histograms are protected against rebinning
  // using the ResetBit(TH1::kCanRebin) method
  int bin = hist->FindBin(vars[0], vars[1], vars[2]);

  // the "first" and "second" entries are filled with the
  // "positive" and "negative" uncertainties, respectively.
  result.first = hist->GetBinContent(bin);
  result.second = hist->GetBinError(bin);

  return inRange ? kSuccess : kRange;
}

/** check the bounds of validity for this calibration object */
void
CalibrationDataHistogramContainer::checkBounds(const TObject* obj,
					       const std::vector<unsigned int>& vartypes) const
{
  const TH1* hist = dynamic_cast<const TH1*>(obj);
  if ((!hist) || hist->GetDimension() != int(vartypes.size())) {
    std::cerr << "in CalibrationDataHistogramContainer::checkBounds(): given number of variable types ("
	      << vartypes.size() << ") doesn't match histogram dimension (" << hist->GetDimension() << ")!"
	      << std::endl;
    return;
  }
  for (unsigned int t = 0; t < vartypes.size(); ++t) {
    if (vartypes[t] > m_upperBounds.size()) {
      std::cerr << "in CalibrationDataHistogramContainer::checkBounds(): variable " << t << "type ("
		<< vartypes[t] << "exceeds maximum type number (" << m_upperBounds.size() << ")!"
		<< std::endl;
      return;
    }
    TAxis* axis;
    switch (t) {
    case 0: axis = hist->GetXaxis(); break;
    case 1: axis = hist->GetYaxis(); break;
    default: axis = hist->GetZaxis();
    }
    double amax = axis->GetXmax(), amin = axis->GetXmin();
    if (amax < m_upperBounds[vartypes[t]]) m_upperBounds[vartypes[t]] = amax;
    if (amin > m_lowerBounds[vartypes[t]]) m_lowerBounds[vartypes[t]] = amin;
  }
}

/** indicate whether the given uncertainty is correlated from bin to bin or not
    (note that this function is to be used only for _systematic_ uncertainties) */
bool
CalibrationDataHistogramContainer::isBinCorrelated(const std::string& unc) const
{
  return (m_uncorrelatedSyst.FindObject(unc.c_str()) == 0);
}

/** indicate that the given uncertainty is to be treated uncorrelated from bin to bin
    (note that the default is for all systematic uncertainties to be treated as correlated) */
void
CalibrationDataHistogramContainer::setUncorrelated(const std::string& unc)
{
  m_uncorrelatedSyst.Add(new TObjString(unc.c_str()));
}


// ---------------------- CalibrationDataFunctionContainer class ----------------------

CalibrationDataFunctionContainer::CalibrationDataFunctionContainer(const char* name) :
  CalibrationDataContainer(name)
{
  // Reset the validity bounds to reflect 'no bounds'.

  m_lowerBounds.clear();
  m_lowerBounds.resize(maxParameters, -std::numeric_limits<double>::max());
  m_lowerBounds[kPt] = m_lowerBounds[kAbsEta] = 0;
  m_upperBounds.clear();
  m_upperBounds.resize(maxParameters, std::numeric_limits<double>::max());
}

CalibrationDataFunctionContainer::~CalibrationDataFunctionContainer()
{
}

// result retrieval

CalibrationDataContainer::CalibrationStatus
CalibrationDataFunctionContainer::getResult(const CalibrationDataVariables& x,
					    double& result, TObject* obj) const
{
  if (!obj) obj = GetValue("result");
  TF1* func = dynamic_cast<TF1*>(obj);
  if (! func) return kError;

  // select the relevant kinematic variables
  bool inRange = computeVariables("result", x);
  result = func->EvalPar(vars);

  return inRange ? kSuccess : kRange;
}

// general uncertainty retrieval

CalibrationDataContainer::CalibrationStatus
CalibrationDataFunctionContainer::getUncertainty(const std::string& unc,
						 const CalibrationDataVariables& x,
						 UncertaintyResult& result, TObject* obj) const
{
  // treat statistical uncertainties separately (they are stored with the actual result)
  if (unc == "statistics") {
    double res;
    CalibrationStatus code = getStatUncertainty(x, res);
    if (code == kError) return code;
    result.first =   res;
    result.second = -res;
    return code;
  }

  if (!obj) obj = GetValue(unc.c_str());
  TF1* func = dynamic_cast<TF1*>(obj);
  if (! func) return kError;

  // select the relevant kinematic variables
  bool inRange = computeVariables(unc, x);

  // the "first" and "second" entries are filled with the
  // "positive" and "negative" uncertainties, respectively.
  // Note: no "negative" uncertainties implemented as yet!
  result.first = func->EvalPar(vars);
  result.second = -result.first;

  return inRange ? kSuccess : kRange;
}

// statistical uncertainty retrieval (special since the uncertainty is not parametrized)

CalibrationDataContainer::CalibrationStatus
CalibrationDataFunctionContainer::getStatUncertainty(const CalibrationDataVariables& x,
						     double& result) const
{
  // ensure that the requested objects exist
  TF1* func = dynamic_cast<TF1*>(GetValue("result"));
  if (! func) return kError;

  TMatrixDSym* cov = dynamic_cast<TMatrixDSym*>(GetValue("statistics"));
  if (! cov) return kError;

  // select the relevant kinematic variables
  bool inRange = computeVariables("result", x);

  // use a large value for "eps": this multiplies the uncertainties that
  // are expected to be associated with the parameters. Choosing a large
  // value expresses the fact that we are not primarily interested in the
  // parabolic behaviour at the minimum
  // const Double_t eps = 1.0;
  // test: set to 0.5
  const Double_t eps = 0.5;

  int npar = func->GetNpar();
  if (npar == 0) {
    result = 0.;
    return kSuccess;
  }

  TMatrixT<double> gradients(npar,1);
  //  std::cout << "parametricVariance: gradients:";
  for (int ipar = 0; ipar < npar; ++ipar) {
    gradients(ipar,0) = func->GradientPar(ipar, vars, eps);
    // std::cout << " " << gradients(ipar,0);
  }
  //  std::cout << std::endl;

  // carry out the matrix multiplication
  TMatrixT<double> gradientsTransposed(TMatrixT<double>::kTransposed, gradients);
  //  std::cout << "parametricVariance: transposed gradients:";
  //  for (int ipar = 0; ipar < npar; ++ipar)
  //    std::cout << " " << gradients(0,ipar);
  //  std::cout << std::endl;
  TMatrixT<double> tmp1(*cov, TMatrixT<double>::kMult, gradients);
  //  std::cout << "parametricVariance: cov * gradients:";
  //  for (int ipar = 0; ipar < npar; ++ipar)
  //    std::cout << " " << tmp1(ipar,0);
  TMatrixT<double> tmp2(gradientsTransposed, TMatrixT<double>::kMult, tmp1);

  result = TMath::Sqrt(tmp2(0,0));

  return inRange ? kSuccess : kRange;
}
