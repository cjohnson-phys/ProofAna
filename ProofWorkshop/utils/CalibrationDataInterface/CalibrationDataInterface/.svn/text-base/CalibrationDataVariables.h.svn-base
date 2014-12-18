///////////////////////////////////////////////////////////////////
// CalibrationDataVariables.h, (c) ATLAS Detector software
///////////////////////////////////////////////////////////////////

#ifndef ANALYSISCALIBRATIONDATAVARIABLES_H
#define ANALYSISCALIBRATIONDATAVARIABLES_H

#include <string>
#include <utility>

namespace Analysis 
{

  /** @class CalibrationDataVariables

      This class (struct, actually) is nothing but a light-weight container of
      (kinematic or other) variables.

      @author  Frank Filthaut <F.Filthaut@science.ru.nl>
  */  

  struct CalibrationDataVariables {
    std::string jetAuthor;
    double jetPt;                    // in MeV
    double jetEta;
  };

  /** @enum CalibrationDataUncertainty

      These enums describe the possible sources of uncertainties that may be
      implemented for given calibration results. (Note that not all calibrations
      need to implement all of these.)

   */

  // enum CalibrationDataUncertainty {
  //   kResult = 0,            // the result itself (i.e., not really an uncertainty...)
  //   kStatistics = 1,        // the associated statistical uncertainty
  //   kComment = 2,           // entry for comments (again not really an uncertainty...)
  //   kSystematics = 3,       // total systematic uncertainty
  //   kMAX = 4                // for internal use, add new entries before this one!
  // };

}

#endif // ANALYSISCALIBRATIONDATAVARIABLES_H
