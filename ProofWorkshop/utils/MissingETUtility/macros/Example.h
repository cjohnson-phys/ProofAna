////////////////////-*-c++-*-///////////////////////////////////////
// A new example macro for the use of METUtility-01-00-00 onwards
// Author: TJ Khoo
// Date: 27 April 2012
//
// This inherits from EventReader, which is a marginally-modified
// TSelector. Fresh EventReader source files can be generated using
// MissingETUtility/scripts/genReader.py
// from your favourite D3PD.
//
////////////////////////////////////////////////////////////////////

#ifndef Example_h
#define Example_h

#include "EventReader.h"

class TH1D;
class METUtility;
class JetCalibrationTool;
class JetSmearingTool;
class MultijetJESUncertaintyProvider;
class TESUncertaintyProvider;

namespace egRescaler {
  class EnergyRescalerUpgrade;
}

namespace MuonSmear {
  class SmearingClass;
}

class Example : public EventReader {

public :

  Example(TTree * /*tree*/ =0) { }
  virtual ~Example() { }

  virtual void    Begin(TTree *tree);
  virtual Bool_t  Process(Long64_t entry);
  virtual void    Terminate();

private :

  virtual void    CheckMetRebuilding(bool verbose);
  virtual void    DemoMetSystematics(bool verbose, bool isData);

  bool m_verbose;
  bool m_isData;
  bool m_is2012;

  METUtility* m_testUtil;
  METUtility* m_systUtil;

  JetCalibrationTool* m_jetCalibTool;
  MultijetJESUncertaintyProvider* m_jesTool;
  JetSmearingTool* m_jerTool;
  egRescaler::EnergyRescalerUpgrade* m_egammaTool;
  MuonSmear::SmearingClass* m_muonTool;
  TESUncertaintyProvider* m_tesTool;

  TFile* m_outfile;

  TH1D* h_RefFinal;
  TH1D* h_RefFinal_JESUp;
  TH1D* h_RefFinal_JESDown;
  TH1D* h_RefFinal_JERUp;
  TH1D* h_RefFinal_EESUp;
  TH1D* h_RefFinal_EESDown;
  TH1D* h_RefFinal_EERUp;
  TH1D* h_RefFinal_EERDown;
  TH1D* h_RefFinal_PESUp;
  TH1D* h_RefFinal_PESDown;
  TH1D* h_RefFinal_PERUp;
  TH1D* h_RefFinal_PERDown;
  TH1D* h_RefFinal_MESUp;
  TH1D* h_RefFinal_MESDown;
  TH1D* h_RefFinal_MERIDUp;
  TH1D* h_RefFinal_MERIDDown;
  TH1D* h_RefFinal_MERMSUp;
  TH1D* h_RefFinal_MERMSDown;
  TH1D* h_RefFinal_ScaleSoftTermsUp;
  TH1D* h_RefFinal_ScaleSoftTermsDown;
  TH1D* h_RefFinal_ResoSoftTermsUp;
  TH1D* h_RefFinal_ResoSoftTermsDown;
  TH1D* h_RefFinal_ScaleSoftTermsUp_ptHard;
  TH1D* h_RefFinal_ScaleSoftTermsDown_ptHard;
  TH1D* h_RefFinal_ResoSoftTermsUp_ptHard;
  TH1D* h_RefFinal_ResoSoftTermsUpDown_ptHard;
  TH1D* h_RefFinal_ResoSoftTermsDownUp_ptHard;
  TH1D* h_RefFinal_ResoSoftTermsDown_ptHard;

  TH1D* h_RefFinal_JESUp_ScaleSoftTermsUp;
  TH1D* h_RefFinal_JESUp_ScaleSoftTermsDown;
  TH1D* h_RefFinal_JESDown_ScaleSoftTermsUp;
  TH1D* h_RefFinal_JESDown_ScaleSoftTermsDown;

  ClassDef(Example,0);
};

#endif // ifndef Example_h
