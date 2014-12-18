/*
 *  Smear MC jets to match the jet energy resolution measured data.
 *  Wrapper around the JERProvider.
 *
 *  Author: Dag Gillberg, dag.gillberg @ cern.ch
 *
 */

#include "ApplyJetResolutionSmearing/ApplyJetSmearing.h"
#include <TMath.h>
#include <TSystem.h>

JetSmearingTool::JetSmearingTool(TString jetAlgo, TString JERinputFile ) 
  : m_GeV(1000), m_is7TeV(false), m_jetAlgo(jetAlgo), m_JERinputFile(JERinputFile), 
  m_JER(0), m_randNom(0), m_randSyst(0), m_supressWarnings(true) {
  // nothing to do here
  }

JetSmearingTool::~JetSmearingTool() {
	if(m_JER) delete m_JER;
	if(m_randNom) delete m_randNom;
	if(m_randSyst) delete m_randSyst;
}

void JetSmearingTool::init(){ 

  TString jerJetAlgo(m_jetAlgo);
  // The JERProvider use a slightly different naming convention
  jerJetAlgo.ReplaceAll("TopoEM","TopoJES"); jerJetAlgo.ReplaceAll("LCTopo","LCTopoJES");

  printf("===================================\n\n");
  printf("  Initializing the JetSmearingToool\n");
  printf("  for %s jets\n\n",m_jetAlgo.Data());
  if(m_is7TeV)printf(" 2011 Resolution has been called");
  
  // initiate the JER provider
  // First help it find the relevant 
  TString JERfile=FindFile(m_JERinputFile);
  printf("  Reading JER and uncert. for data and MC from:\n    %s\n\n",JERfile.Data());
  m_JER = new JERProvider(jerJetAlgo.Data(),"Truth",JERfile.Data());
  if(m_is7TeV) m_JER->is7TeV(true);
  m_JER->init();
  m_JER->useGeV(); // since earlier we convert all input to GeV
  
  // initiate the random generators with different seeds
  m_randNom = new TRandom3(1); m_randSyst = new TRandom3(2);
  
  printf("\n===================================\n\n");
}

// Avoids flooding screen with JER provider warnings
// from jets with |eta|>4.5
double JetSmearingTool::LimitEta(double eta) {
  if (eta>4.5) return 4.5;
  if (eta<-4.5) return -4.5;
  return eta;
}

void JetSmearingTool::SetSeed(int seed) {
  m_randNom->SetSeed(seed); 
  m_randSyst->SetSeed(7*seed+3); // Different from nominal seed
}

TString JetSmearingTool::FindFile(TString file_name) {
  if (gSystem->AccessPathName(file_name)==false) return file_name;

  TString fn=gSystem->BaseName(file_name); // Check in the ROOTcore directory
  TString path=TString(gSystem->Getenv("ROOTCOREDIR"))+"/data/JetResolution/"+fn;
  if (gSystem->AccessPathName(path)==false) return path;

  path="JetResolution/share/"+fn;
  if (gSystem->AccessPathName(path)==false) return path;

  path=TString(gSystem->Getenv("ROOTCOREDIR"))+"/../JetResolution/share/"+fn;
  if (gSystem->AccessPathName(path)==false) return path;
  
  error("Cannot find file: "+file_name);
  return "HejHopp";
}

// smear MC jet resolution S_MC to data resolution S, i.e.: S_MC -> S
double JetSmearingTool::GetRandomSmearingFactor(double pt, double eta) {
  //double myEta = ( m_supressWarnings ? LimitEta(eta) : eta ); // not needed anymore
  double S=GetJER_Data(pt,eta), S_MC=GetJER_MC(pt,eta);
  double sigma = S > S_MC ? sqrt(S*S-S_MC*S_MC) : 0.0;
  return m_randNom->Gaus(1.0,sigma);
}

// further smear the smeared MC to the resolution in data + uncertainty: S -> S+U
double JetSmearingTool::GetRandomSmearingFactorSyst(double pt, double eta) {
  //double myEta = ( m_supressWarnings ? LimitEta(eta) : eta );
  double S=GetJER_MC(pt,eta), S_syst=S+GetJER_Uncert(pt,eta), sigma = sqrt(S_syst*S_syst-S*S);
  double randSmear = m_randSyst->Gaus(1.0,sigma);
  // protection from negative jets (cut of the 3 sigma tail)
  if (randSmear<=0) return GetRandomSmearingFactorSyst(pt,eta);
  return randSmear;
}

// further smear the smeared MC to the resolution in data + uncertainty: S -> S+U
double JetSmearingTool::GetRandomSmearingFactorSyst_AFII(double pt, double eta) {
  if(m_is7TeV)error("AFII resolution not available in 2011");
  //double myEta = ( m_supressWarnings ? LimitEta(eta) : eta );
  double S=GetJER_AFII(pt,eta), S_syst=S+GetJER_Uncert_AFII(pt,eta), sigma = sqrt(S_syst*S_syst-S*S);
  double randSmear = m_randSyst->Gaus(1.0,sigma);
  // protection from negative jets (cut of the 3 sigma tail)
  if (randSmear<=0) return GetRandomSmearingFactorSyst_AFII(pt,eta);
  return randSmear;
}

/*
// Rel 17 smearing - OLD METHOD. THIS approach is now the default
double JetSmearingTool::GetRandomSmearingFactorSystRel17(double pt, double eta) {
  double myEta = ( m_supressWarnings ? LimitEta(eta) : eta );
  double S=GetJER_MC(pt,myEta), S_syst=S+GetJER_Uncert(pt,myEta);
  double sigma = sqrt(S_syst*S_syst-S*S);
  return m_randSyst->Gaus(1.0,sigma);
}
*/

TString JetSmearingTool::GetJetAlgoDescription() {
  if (m_jetAlgo(0,6)!="AntiKt") return "unknown jet algortihm";
  double jetR = 0.1*atol(m_jetAlgo(6,2).Data());
  TString preCalib = m_jetAlgo.Contains("TopoEM") ? "EM" : m_jetAlgo.Contains("LCTopo") ? "LC" : "??";
  return Form("anti-k_{t} #it{R} = %.1f, %s+JES",jetR,preCalib.Data());
}
