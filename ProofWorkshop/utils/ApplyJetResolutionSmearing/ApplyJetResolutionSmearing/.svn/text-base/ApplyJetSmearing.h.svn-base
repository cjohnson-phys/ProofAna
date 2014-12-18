/*
 *  Dag Gillberg, Dec 2011
 */

#ifndef _APPLYJETSMEARING_
#define _APPLYJETSMEARING_

#include <iostream>
#include <TString.h>
#include <TLorentzVector.h>
#include <cmath>
#include <vector>
#include <TRandom3.h>
#include "JetResolution/JERProvider.h"
using std::cout;
using std::cerr;

class JetSmearingTool : public TNamed {

 public:
  // Constructor
  JetSmearingTool() : m_JER(0), m_randNom(0), m_randSyst(0) { }
  JetSmearingTool(TString jetAlgo /*="AntiKt4TopoEM"*/, TString JERinputFile="JERProviderPlots_2012.root");
  void SetSeed(int seed);
  void init();
  ~JetSmearingTool();

  // Multiplicative smearing factors for MC-jets
  double GetRandomSmearingFactor(double pt, double eta);
  double GetRandomSmearingFactorSyst(double pt, double eta);
  double GetRandomSmearingFactorSyst_AFII(double pt, double eta);
  //double GetRandomSmearingFactorSystRel17(double pt, double eta);

  // Avoid JER warning by using the 3.6<|eta|<4.5 resolution also for jets with |eta|>4.5
  double LimitEta(double eta);
  void SupressWarning(bool supress=true) { m_supressWarnings=supress; }

  // Multiplicative smearing factors for MC-jets
  double GetRandomSmearingFactor(TLorentzVector jet) 
  { return GetRandomSmearingFactor(jet.Pt(),jet.Eta()); }
  double GetRandomSmearingFactorSyst(TLorentzVector jet) 
  { return GetRandomSmearingFactorSyst(jet.Pt(),jet.Eta()); }
  double GetRandomSmearingFactorSyst_AFII(TLorentzVector jet) 
  { return GetRandomSmearingFactorSyst_AFII(jet.Pt(),jet.Eta()); }
  //  double GetRandomSmearingFactorSystRel17(TLorentzVector jet) 
  //{ return GetRandomSmearingFactorSystRel17(jet.Pt(),jet.Eta()); }


  // Smear a (MC fullsim) jet for systmatics evaluation (note different from previous, old "Rel 16" implementation)
  void SmearJet_Syst(TLorentzVector &jet)
  { jet *= GetRandomSmearingFactorSyst(jet); }

  // Smear a jet in an AFII sample for systmatics evaluation 
  void SmearJet_Syst_AFII(TLorentzVector &jet)
  { jet *= GetRandomSmearingFactorSyst_AFII(jet); }

  // Smear a MC-jet to the energy resolution measured in data
  void SmearJet(TLorentzVector &jet)
  { jet *= GetRandomSmearingFactor(jet); }
  
  /*
    void SmearJet_SystRel17(TLorentzVector &jet)
    { jet *= GetRandomSmearingFactorSystRel17(jet); }
  */
  
  double GetJER_Data(double pt, double eta) { return m_JER->getRelResolutionData(pt/m_GeV,eta); }
  double GetJER_MC(double pt, double eta)   { return m_JER->getRelResolutionMC(pt/m_GeV,eta); }
  double GetJER_AFII(double pt, double eta)   { return m_JER->getRelResolutionMC_AFII(pt/m_GeV,eta); }
  double GetJER_Data(TLorentzVector jet)    { return GetJER_Data(jet.Pt(),jet.Eta()); }
  double GetJER_MC(TLorentzVector jet)      { return GetJER_MC(jet.Pt(),jet.Eta()); }
  double GetJER_AFII(TLorentzVector jet)      { return GetJER_AFII(jet.Pt(),jet.Eta()); }
  double GetJER_Uncert(double pt, double eta) { return m_JER->getResolutionUncert(pt/m_GeV,eta); }
  double GetJER_Uncert(TLorentzVector jet) { return GetJER_Uncert(jet.Pt(),jet.Eta()); }
  double GetJER_Uncert_AFII(double pt, double eta) { return m_JER->getResolutionUncert_AFII(pt/m_GeV,eta); }
  double GetJER_Uncert_AFII(TLorentzVector jet) { return GetJER_Uncert_AFII(jet.Pt(),jet.Eta()); }

  // Default is to use MeV
  void UseGeV(bool useGeV=true) { if (useGeV) m_GeV=1.0; else m_GeV=1000; }
  void Is7TeV(bool use7TeV=true){if(use7TeV) m_is7TeV = true; else m_is7TeV = false;}
  
  TString GetJetAlgoDescription();

#ifdef APPLYJETSMEAR_STANDALONE
  ClassDef(JetSmearingTool,1);
#endif
  
  
 private:
  void error(TString msg) 
  {
    //write error message both to the error and standard streams
    std::cerr << "\nERROR - JetSmearingTool:\n\n " << msg.Data() << std::endl;
    std::cout << "\nERROR - JetSmearingTool:\n\n " << msg.Data() << std::endl;
    abort(); 
  }

  //void init(TString jetAlog);
  TString FindFile(TString fn);
  
  double m_GeV;
  bool m_is7TeV;
  TString m_jetAlgo;
  TString m_JERinputFile;
  
  JERProvider *m_JER;
  TRandom3 *m_randNom, *m_randSyst;
  bool m_supressWarnings;
};

#endif
