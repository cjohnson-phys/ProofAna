///////////////////////////////////////////////////////////////////
// CalibrationDataInterfaceBase.cxx, (c) ATLAS Detector software
///////////////////////////////////////////////////////////////////

#include "CalibrationDataInterface/CalibrationDataInterfaceBase.h"

#include "TMath.h"

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

//================ Constructor =================================================

Analysis::CalibrationDataInterfaceBase::CalibrationDataInterfaceBase()
{}

//================ Destructor ==================================================

Analysis::CalibrationDataInterfaceBase::~CalibrationDataInterfaceBase()
{}

//================ calibration names =============================================

const std::string& Analysis::CalibrationDataInterfaceBase::EffCalibrationName(const std::string& flavour) const
{
  
  // future: use map<>::find
  return m_calibrationEffNames[flavour];
}

void Analysis::CalibrationDataInterfaceBase::setEffCalibrationNames(const std::map<std::string, std::string>& names)
{
  m_calibrationEffNames = names;
}
      
const std::string& Analysis::CalibrationDataInterfaceBase::SFCalibrationName(const std::string& flavour) const
{
  // future: use map<>::find
  return m_calibrationSFNames[flavour];
}

void Analysis::CalibrationDataInterfaceBase::setSFCalibrationNames(const std::map<std::string, std::string>& names)
{
  m_calibrationSFNames = names;
}
      

//============================================================================================

std::string Analysis::CalibrationDataInterfaceBase::getBasename (const std::string& OP,
								 const std::string& flavour,
								 const std::string& extra,
								 bool SF) const
{
  std::string basename(OP);
  basename += "/";
  basename += (flavour == "N/A") ? "Light" : flavour;
  basename += "/";
  // future: use map<>::find
  basename += SF ? m_calibrationSFNames[flavour] : m_calibrationEffNames[flavour];
  basename += extra;

  return basename;
}

double
Analysis::CalibrationDataInterfaceBase::combinedUncertainty (double stat,
							     const std::pair<double, double>& syst) const 
{
  // The systematic uncertainty is (a priori) asymmetric, but this interface doesn't
  // at present allow for asymmetric uncertainties.
  // Address this by taking the larger (absolute) value of the two.
  double largest = syst.first;
  if (TMath::Abs(syst.second) > TMath::Abs(largest)) largest = syst.second;

  return TMath::Sqrt(stat*stat + largest*largest);
}
