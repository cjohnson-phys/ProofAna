///////////////////////////////////////////////////////////////////
// CalibrationDataContainer.h, (c) ATLAS Detector software
///////////////////////////////////////////////////////////////////

#ifndef ANALYSISCALIBRATIONDATACONTAINER_H
#define ANALYSISCALIBRATIONDATACONTAINER_H

#include <vector>
#include <map>
#include <string>

#include "TMap.h"
#include "THashList.h"

#include "CalibrationDataInterface/CalibrationDataVariables.h"

namespace Analysis {

  /** 
      The following typedef is for convenience: most uncertainties can be asymmetric.
      The pair holds the positive (first) and negative (second) uncertainties. Note that
      in the context of systematic uncertainties, "positive" and "negative" may reflect
      what happens if the uncertainty parameter is varied. This means that the "positive"
      uncertainty result may be negative etc.
   */

  typedef std::pair<double, double> UncertaintyResult;


  /** @class CalibrationDataContainer

      This is the interface for the objects to be stored in the calibration ROOT file.
      The base class inherits from a TMap, the idea bing that the map's keys are TObjString
      objects while the values are the objects of interest. The keys are meant to provide
      access in a flexible manner.
   */

  class CalibrationDataContainer: public TMap {
  public:
    CalibrationDataContainer(const char* name = "default"); // default ctor needed for persistence
    virtual ~CalibrationDataContainer(); // virtual dtor needed for persistence

    /** @enum CalibrationParametrization

	The following enums are intended to contain the list of (kinematic or other)
	variables in terms of which results (and the corresponding uncertainties) are given.
	They are useful mainly for internal purposes, but the user may access them nevertheless.
    */

    enum CalibrationParametrization {
      kPt = 0,       // calibrated jet pt
      kEta = 1,      // jet eta
      kAbsEta = 2    // jet |eta|
    };

    /** @enum CalibrationStatus

	The following enums are intended to provide meaningful status codes.
    */

    enum CalibrationStatus {
      kSuccess = 0, // all OK
      kRange = 1,   // given coordinates outside range of validity
      kError = 2    // "technical" error (typically: nonexistent object)
    };

    /** @brief retrieve the list of "uncertainties" accessible to this object.
	A few uncertainty names are predetermined: "result", "comment", "statistics", "systematics".
	Individual sources of systematic uncertainty can be added by the user.
     */
    std::vector<std::string> listUncertainties() const;

    /**
       retrieve the list of "uncertainties" accessible to this object.
       A few uncertainty names are predetermined: "result", "comment", "statistics", "systematics".
       Individual sources of systematic uncertainty can be added by the user.
     */
    CalibrationStatus getUncertainties(const CalibrationDataVariables& x,
				       std::map<std::string, Analysis::UncertaintyResult>& all) const;

    /** @brief retrieve the comments entered for this calibration, if any */
    std::string getComment() const;

    /**
       retrieve the calibration result.
       @param  x        user-supplied (kinematic or other) variables
       @param  result   requested result
       @param  obj    object holding the requested result (it will be computed if not provided)
       @return status code (see above)
    */
    virtual CalibrationStatus getResult(const CalibrationDataVariables& x,
					double& result,
					TObject* obj = 0) const = 0;

    /**
       retrieve the calibration statistical uncertainty.
       @param  x      user-supplied (kinematic or other) variables
       @param  result requested statistical uncertainty
       @return status code (see above)
       Note the changed signature compared to getUncertainty(), getResult() etc.:
       this is because the statistical uncertainty computation always needs the result
       object, and only in case of the function interface also the covariance matrix
    */
    virtual CalibrationStatus getStatUncertainty(const CalibrationDataVariables& x,
						 double& result) const = 0;

    /**
       retrieve the calibration total systematic uncertainty
       @see    getUncertainty()
    */
    CalibrationStatus         getSystUncertainty(const CalibrationDataVariables& x,
						 UncertaintyResult& result,
						 TObject* obj = 0) const;

    /**
       retrieve the calibration uncertainty due to the given source.
       @param  x      user-supplied (kinematic or other) variables
       @param  unc    uncertainty specification
       @param  result requested uncertainty (for both positive and negative variation, if available)
       @param  obj    object holding the requested uncertainty information (it will be computed if not provided)
       @return status code (see above)
    */
    virtual CalibrationStatus getUncertainty(const std::string& unc,
					     const CalibrationDataVariables& x,
					     UncertaintyResult& result, TObject* obj = 0) const = 0;
    
    /** @brief insert the main object for this calibration */
    void setResult(TObject* obj);

    /** @brief insert the given text as comment for this calibration */
    void setComment(const std::string& text);

    /** @brief insert the relevant object for the requested source of 'uncertainty' */
    void setUncertainty(const std::string& unc, TObject* obj);

    /**
       If true, this will restrict the variables used to be within the (specified) range of validity.
       Note that this is a policy decision and as such not intrinsic to the data; but it is
       cumbersome to carry this information around everywhere.
    */
    void restrictToRange(bool restrict) { m_restrict = restrict; }

    /** @brief allow the user to inspect the above information */
    bool isRangeRestricted() const { return m_restrict; }

    /** retrieve the lower bound of validity for the requested variable type
	@param vartype variable type 
     */
    double getLowerBound(unsigned int vartype) const;

    /** retrieve the upper bound of validity for the requested variable type
	@param vartype variable type 
     */
    double getUpperBound(unsigned int vartype) const;

    /** check the bounds of validity for this calibration object */
    virtual void checkBounds(const TObject* obj, const std::vector<unsigned int>& types) const = 0;

    /** @brief allow the user to inspect the bounds of validity */
    std::vector<std::pair<double, double> > getBounds() const;

    /** @brief utility to retrieve variable types for the specified uncertainty */
    static std::vector<unsigned int> getVariableTypes(const TObject* obj);

  protected:

    /** compute the variables to be used for the given 'uncertainty'
	@param  x user-supplied (kinematic or other) variables
	@param  restrict set to true if the evaluation is to be restricted to the range of validity
	@return false if the given variables are outside the parametrisation's validity range
    */
    bool computeVariables(const std::string& unc,
			  const CalibrationDataVariables& x) const;

    mutable std::vector<double> m_lowerBounds;   // lower validity bounds
    mutable std::vector<double> m_upperBounds;   // upper validity bounds

  private:

    /** @brief specification of variable type per object (result / uncertainty) */
    mutable std::map<std::string, std::vector<unsigned int> > m_variables; //! persistency not needed for this variable

    /** @brief specifies whether the performance evaluation is to be done strictly within the range of validity */
    bool m_restrict;

    /** @brief decode the 'uncertainty' objects' names to determine the relevant variable types */
    void computeVariableTypes() const;

    ClassDef(Analysis::CalibrationDataContainer, 1);  // base class for calibration data objects

  };




  /** @class CalibrationDataHistogramContainer

      This is the class holding information for histogram-based calibration results.
      
   */

  class CalibrationDataHistogramContainer: public CalibrationDataContainer {
  public:
    CalibrationDataHistogramContainer(const char* name = "default"); // default ctor needed for persistence
    virtual ~CalibrationDataHistogramContainer();    // virtual dtor needed for persistence
    virtual CalibrationStatus getResult(const CalibrationDataVariables& x, double& result,
					TObject* obj = 0) const;
    virtual CalibrationStatus getStatUncertainty(const CalibrationDataVariables& x, double& result) const;
    virtual CalibrationStatus getUncertainty(const std::string& unc, const CalibrationDataVariables& x,
					     UncertaintyResult& result, TObject* obj = 0) const;

    /** @brief check the bounds of validity for this calibration object */
    virtual void checkBounds(const TObject* obj, const std::vector<unsigned int>& types) const;

    /** @brief indicate whether the given uncertainty is correlated from bin to bin or not
	(note that this function is to be used only for _systematic_ uncertainties) */
    bool isBinCorrelated(const std::string& unc) const;

    /** @brief indicate that the given uncertainty is to be treated uncorrelated from bin to bin
	(note that the default is for all systematic uncertainties to be treated as correlated) */
    void setUncorrelated(const std::string& unc);

  private:

    /** @brief list here the _systematic_ uncertainties that are not correlated from bin to bin */
    THashList m_uncorrelatedSyst;
    
    ClassDef(Analysis::CalibrationDataHistogramContainer, 1);  // histogram based calibration data object
  };




  /** @class CalibrationDataFunctionContainer

      This is the class holding information for function-based calibration results.
   */

  class CalibrationDataFunctionContainer: public CalibrationDataContainer {
  public:
    CalibrationDataFunctionContainer(const char* name = "default"); // default ctor needed for persistence
    virtual ~CalibrationDataFunctionContainer();   // virtual dtor needed for persistence
    virtual CalibrationStatus getResult(const CalibrationDataVariables& x, double& result,
					TObject* obj = 0) const;
    virtual CalibrationStatus getStatUncertainty(const CalibrationDataVariables& x, double& result) const;
    virtual CalibrationStatus getUncertainty(const std::string& unc, const CalibrationDataVariables& x,
					     UncertaintyResult& result,  TObject* obj = 0) const;

    /** @brief set the lower bound of validity for the given variable */
    inline void setLowerBound(int vartype, double bound) {m_lowerBounds[vartype] = bound; }
    
    /** @brief set the lower bound of validity for the given variable */
    inline void setUpperBound(int vartype, double bound) {m_upperBounds[vartype] = bound; }
    
    /** @brief check the bounds of validity for this calibration object (dummy since bounds set by hand) */
    virtual void checkBounds(const TObject* /* obj */, const std::vector<unsigned int>& /* types */) const {;}

  private:

    ClassDef(Analysis::CalibrationDataFunctionContainer, 1); // function based calibration data object
  };

} // end of namespace

#endif 
