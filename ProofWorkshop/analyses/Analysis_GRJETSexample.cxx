/**************************************************************************
 **
 **   File:         Analysis_GRJETSexample.h
 **
 **   Description:  See header
 **                 
 **   Authors:      D. W. Miller and M. Swiatlowski
 **
 **************************************************************************/

#define Analysis_GRJETSexample_cxx

#include "Analysis_GRJETSexample.h"
#include "AnaConfig.h"
#include <TROOT.h>
#include <TH1F.h>
#include <TH2F.h>
#include <iostream>
#include <cstdlib>
#include "TKey.h"
#include "TObjString.h"
#include "TObjArray.h"

///=========================================
/// WorkerBegin: setup binning, etc. All this is done once at the beginning of every worker.
///=========================================
void Analysis_GRJETSexample::WorkerBegin()
{
  if (Debug()) cout << "Analysis_GRJETSexample: DEBUG In WorkerBegin()" << endl;

  ///=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
  /// Get options: helps you determine what types of plots you want to make
  ///=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
  doTruthLinks   = false;
  ChainCfg()->Get("DOTRUTHLINKS"    , doTruthLinks   );
  doTruthJetLinks=false;
  ChainCfg()->Get("DOTRUTHJETLINKS" , doTruthJetLinks   );
  doTrackJetLinks= false;
  ChainCfg()->Get("DOTRACKJETLINKS" , doTrackJetLinks);
  doJetStructure = false;
  ChainCfg()->Get("DOJETSTRUCT"     , doJetStructure );
  doConstituents = false;
  ChainCfg()->Get("DOCONSTIT"       , doConstituents );
  doTruthConstituents = false;
  ChainCfg()->Get("DOTRUTHCONSTIT"  , doTruthConstituents );
  doParentChild  = false;
  ChainCfg()->Get("DOPARENTCHILD"   , doParentChild  );
  doTrack        = false;
  ChainCfg()->Get("DOTRACK"         , doTrack        );
  doLCCluster    = false;
  ChainCfg()->Get("DOLCCLUSTER"     , doLCCluster    );
  doEMCluster    = false;
  ChainCfg()->Get("DOEMCLUSTER"     , doEMCluster    );
  doTruth        = false;
  ChainCfg()->Get("DOTRUTH"         , doTruth        );
  doVertex       = false;
  ChainCfg()->Get("DOVTX"           , doVertex       );
  doPhotons      = false;
  ChainCfg()->Get("DOPHOTON"        , doPhotons      );
  

  ///=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
  /// Set Pt and eta bounds for plots: for binning plots in pt/eta bins, convenient
  /// to define a vector of bounds like this, and a function GetPtBin(jet) to which
  /// you pass a jet, and the appropriate string for the ptbin is returned, with which
  /// you can construct a string for the name of a histogram, binned in pt/eta
  ///=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
  ptBounds.push_back(0.);   ptBounds.push_back(100.); 
  ptBounds.push_back(150.); ptBounds.push_back(200.); 
  ptBounds.push_back(300.); ptBounds.push_back(400.); ptBounds.push_back(500.); 
  ptBounds.push_back(600.); ptBounds.push_back(800.); ptBounds.push_back(1000.); 
  ptBounds.push_back(2000.); 

  etaBounds.push_back(0.);  etaBounds.push_back(0.8); 
  etaBounds.push_back(1.2); etaBounds.push_back(2.1);
  etaBounds.push_back(2.8);
  etaBounds.push_back(3.2); 
  
  
  ///=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
  /// Jet types: creates a normal vector<TString> of the jetTypes you initialized
  /// Loop over this vector to make plots for many different types of jets, for example
  ///=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
  if (Debug()) cout << "Analysis_GRJETSexample::WorkerBegin(): DEBUG Adding jet types to list to analyze" << endl;	
  TObjArray* arrJets = ChainCfg()->String("FULLJETTYPES").Tokenize(",");
  for(int i = 0; i<arrJets->GetEntries(); ++i) {
    TObjString* jetTypeObj = (TObjString*)arrJets->At(i);
	TString jetType        = jetTypeObj->GetString();
    if (Debug()) cout << "Analysis_GRJETSexample::WorkerBegin(): DEBUG Adding jet type: " << jetType << endl;	
    jetVec.push_back(jetType);    
  }
  arrJets->SetOwner(kFALSE); delete arrJets;
 
  //cout << "FULLJETTYPES = " << ChainCfg()->String("FULLJETTYPES") << endl;
  
  ///=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
  /// Triggers: create a vector<TString> of the triggers you initialized. Useful for
  /// looping over to compare performance of different types of triggers
  ///=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
  if (Debug()) cout << "Analysis_GRJETSexample::WorkerBegin(): DEBUG Adding triggers to list to analyze" << endl;	
  TObjArray* arrTrig = ChainCfg()->String("TRIGTYPES").Tokenize(",");
  for(int i = 0; i<arrTrig->GetEntries(); ++i) {
    TObjString* triggerObj = (TObjString*)arrTrig->At(i);
	TString trigType       = triggerObj->GetString();
    if (Debug()) cout << "Analysis_GRJETSexample::WorkerBegin(): DEBUG Adding trigger: " << trigType << endl;	
    trigVec.push_back(trigType);    
  }
  arrTrig->SetOwner(kFALSE); delete arrTrig;
  
  
  ///=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
  /// Lumi for triggers: a vector<float> of luminosities for the different triggers
  /// created above, in case you need that as well.
  ///=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
  if (Debug()) cout << "Analysis_GRJETSexample::WorkerBegin(): DEBUG Adding lumi values to list" << endl;	
  TObjArray* arrLumi = ChainCfg()->String("TRIGLUMI").Tokenize(",");
  for(int i = 0; i<arrLumi->GetEntries(); ++i) {
    TObjString* triggerObj = (TObjString*)arrLumi->At(i);
	float lumiValue        = triggerObj->GetString().Atof();
    if (Debug()) cout << "Analysis_GRJETSexample::WorkerBegin(): DEBUG Adding lumi value: " << lumiValue << endl;	
    lumi.push_back(lumiValue);    
  }
  arrLumi->SetOwner(kFALSE); delete arrLumi;
  

}

///=========================================
/// ProcessEvent: run the analysis: this is run once per event
/// Flow is as follows:
/// 1) Setup a cutflow
/// 2) Loop over initialized jetTypes
/// 3) Run the plotting function over those jet types
///=========================================
bool Analysis_GRJETSexample::ProcessEvent()
{
  OutputDir()->cd();
  if (Debug()) cout << "Analysis_GRJETSexample: DEBUG In ProcessEvent(): RunNumber = " << RunNumber() << "; Channel = " << ChannelNumber() << "; EventNumber = " << EventNumber() << endl;

  ///---------------------
  // Show properties set 
  ///---------------------
  if (Debug()) Show();

  BookCutflow("All");  

  ///---------------------
  /// GRL
  ///---------------------
  if (!Bool("grl")) return false;
  BookCutflow("GRLPass");  
  
  ///---------------------
  /// LAR ERROR FLAG
  ///---------------------
  if (Int("larerror") == 2) { if (Debug()) cout << "Analysis_GRJETSexample::ProcessEvent(): DEBUG Event rejected by LAr Error" << endl; return false; }
  BookCutflow("LArErrorVeto");    
  
  ///---------------------
  /// VERTEX REQUIREMENT
  ///---------------------
  if (Int("NPV") < 1) { if (Debug()) cout << "Analysis_GRJETSexample::ProcessEvent(): DEBUG Event rejected by Nvtx cut" << endl; return false; }
  BookCutflow("GoodVertex");    
  
  ///---------------------
  /// NO BAD JET
  ///---------------------
  if (jets("badjets")) {
    if(Debug()) cout << "Bad jet event veto!" << endl;
    return false;
  }
  
  BookCutflow("BadJetVeto");

  ///-------------------------------------------------
  /// Run the analysis! check for triggers inside here
  ///-------------------------------------------------
  for (unsigned int j = 0; j < jetVec.size(); ++j) {
    
    /// Only run on reconstructed jets
    if (jetVec.at(j).Contains("LCTopo") || jetVec.at(j).Contains("TruthJS")) {
      Book(jetVec.at(j));
    }
  }

  return true;
}



///=========================================
/// SetTriggWeight: Set up the weights for MC associated with a given trig 
///=========================================
void Analysis_GRJETSexample::SetTriggerWeight(int i)
{
  
  if (Debug()) cout << "Analysis_GRJETSexample: DEBUG In SetTriggerWeight()" << endl;
  
  Weight(DefaultWeight());


  if (Debug()) cout << "Analysis_GRJETSexample::SetTriggerWeight(): DEBUG DefaultWeight() = " << DefaultWeight() << "; LUMI = " << Float("LUMI") << "; PUW = " << Float(trigVec[i]+"_weight") << endl;

  if(isMC()){
    float lumifrac = lumi[i] / Float("LUMI"); //what's the fraction of prescaled lumi we have to use

    float pileweight = Float(trigVec[i]+"_weight");// what's the actual pileupweight

    float mcweight = Float("mcweight");//weights from the mc gen level

    Weight(DefaultWeight() * pileweight * lumifrac * mcweight); // default * pileweight *lumifrac 

    if(Debug()) cout << "Analysis_GRJETSexample::SetTriggerWeight(): DEBUG Total weight = " << Weight() << endl;
  }
}



///=========================================
/// WorkerTerminate: clean up
///=========================================
void Analysis_GRJETSexample::WorkerTerminate()
{

  // Nothing

}

///=========================================
/// Book: call histogram setup for this set
///=========================================
void Analysis_GRJETSexample::Book(const TString& prefix)
{
  /// Here, "prefix" will typically refer to the jet type in consideration
  /// This also calls SetPrefix() so the other histograms get put in the proper place

  if (Debug()) cout << "Analysis_GRJETSexample: DEBUG In Book() prefix = " << prefix << endl;

  ///---------------------
  /// Loop on all triggers
  ///---------------------
  for (unsigned int i = 0; i < trigVec.size(); ++i) {
    
    TString thisTrigger = trigVec.at(i);
    
    if (Debug()) cout << "Analysis_GRJETSexample::Book(): DEBUG Booking for trigger = " << thisTrigger << endl;
    
    BookCutflow(prefix + "_" + thisTrigger + "_all"); 
    pre = prefix;
    
    /// Check if the event passed the trigger
    if(!Bool(thisTrigger)) {
      if (Debug()) cout << "Analysis_GRJETSexample::Book(): DEBUG This trigger did not fire, result = " << Bool(thisTrigger) << endl;
      continue;
    }
    
    BookCutflow(prefix + "_" + thisTrigger + "_pass"); 
    
    /// Sets up the plateau region selection
    if(!Bool(thisTrigger + "_cut")) {
      if (Debug()) cout << "Analysis_GRJETSexample::Book(): DEBUG Offline does not satisfy trigger cut, result = " << Bool(thisTrigger + "_cut") << endl;
      continue;
    }
    
    BookCutflow(prefix + "_" + thisTrigger + "_trigPlateau"); 
    
    /// If this is MC, set the trigger weight including the pile-up reweighting
    if(isMC()){
      if (Debug()) cout << "Analysis_GRJETSexample::Book(): DEBUG Setting the trigger weight including the pile-up reweighting" << endl;
      SetTriggerWeight(i);
    }

    BookCutflow(prefix + "_" + thisTrigger + "_weighted"); 

    BookBasic();	
  }
}

///=========================================
/// BookBasic: ACTUALLY do it
///=========================================
void Analysis_GRJETSexample::BookBasic()
{

  Int_t nPvBins         = 41;   Float_t pvMinBin        = -0.5;    Float_t pvMaxBin   = 40.5;
  Int_t nResBins        = 50;   Float_t resMinBin       = -1.000;  Float_t resMaxBin  = -2.000; 
  Int_t nPvTrkBins      = 101;  Float_t pvTrkMin        = -0.5;    Float_t pvTrkMax   = 200.5;
  Int_t nPvSumPtBins    = 50;   Float_t pvSumPtMin      = 0.0;     Float_t pvSumPtMax = 2000.;
  Int_t nPvZBins        = 50;   Float_t pvZMin          = -200.0;  Float_t pvZMax     = 200.;

  Int_t nJetEtBins      = 180;  Float_t jetEtMinBin     = 0.;      Float_t jetEtMaxBin     = 1800.; 
  Int_t nFinePtbins     = 180;  Float_t finePtMinBin    = 0.;      Float_t finePtMaxBin    = 1800.;
  Int_t nJetConstEBins  = 60;   Float_t jetConstEMinBin = 0.;      Float_t jetConstEMaxBin = 60.; 
  Int_t nJetSumEtBins   = 100;  Float_t jetSumEtMinBin  = 0.;      Float_t jetSumEtMaxBin  = 2000.; 
  Int_t nJetMassBins    = 80;   Float_t jetMassMinBin   = 0.;      Float_t jetMassMaxBin   = 400.;
  Int_t nJetMassPtBins  = 50;   Float_t jetMassPtMinBin = 0.;      Float_t jetMassPtMaxBin = 1.;
  Int_t nEtaBins        = 20;   Float_t etaMinBin       = -5.0;    Float_t etaMaxBin       = 5.0;
  Int_t nJVFBins        = 60;   Float_t jvfMinBin       = -1.5;    Float_t jvfMaxBin       = 1.5;
  Int_t nNtrkBins       = 70;   Float_t minNtrk         = 0.;      Float_t maxNtrk         = 70.;
  Int_t nPtTrkBins      = 80;   Float_t minPtTrk        = 0.;      Float_t maxPtTrk        = 800.;
  Int_t nNjetBins       = 20;   Float_t minNjet         = 0.;      Float_t maxNjet         = 20.;
  Int_t nJetTowerBins   = 90;   Float_t nJetTowersMin   = 0.;      Float_t nJetTowersMax   = 270.0;
  Int_t nDeltaRBins     = 70;   Float_t deltaRMin       = 0.;      Float_t deltaRMax       = 3.5;
  Int_t nPtDeltaBins    = 50;   Float_t minPtDelta      = 0.;      Float_t maxPtDelta      = 100.;

  Int_t nAreaBins       = 50;   Float_t minArea         = 0.;      Float_t maxArea         = 10.0;

  Int_t nResponseBins   = 300;  Float_t responseMin     = 0.;      Float_t responseMax     = 15.0;
  Int_t nMassRatioBins  = 300;  Float_t massRatioMin    = 0.;      Float_t massRatioMax    = 15.0;

  Int_t nQSqBins        = 100;  Float_t QSqMinBin       = 0.;      Float_t QSqMaxBin       = 5000000.; 

  Int_t nDipBins        = 70;   Float_t dipMinBin       = 0.;      Float_t dipMaxBin       = 1.4;
  Int_t nTauBins        = 70;   Float_t tauMinBin       = 0.;      Float_t tauMaxBin       = 1.4;

  Int_t NSubJetbins     = 15;

  if (Debug()) cout << "Analysis_GRJETSexample: DEBUG In BookBasic(): Pre() = " << Pre() << endl;


  
  /// Now, actually fill events. Use the Fill("histName", value, weight, binlimits); function
  /// Weight() gives the default weight calculated from the MC

  ///-----------------------------------------
  /// Event level quantities
  /// Note that to get a Float from the event, you just ask Float
  /// Likewise for Int, etc.
  ///-----------------------------------------
  Fill("vertex_mult", Int("NPV"), Weight(), nPvBins, pvMinBin, pvMaxBin);
  Fill("mu",          Float("averageIntPerXing"), Weight(), nPvBins, pvMinBin, pvMaxBin) ;
  //Fill("ht4",         Float("EventHT")/1000., Weight(), 100, 0, 5);

  ///-----------------------------------------
  /// Actually analyze the jets!
  ///-----------------------------------------
  if (Debug()) cout << "Analysis_GRJETSexample::BookBasic(): DEBUG starting to fill jets for: " << Pre() << endl;

  /// Fill jets
  bool leadJetPassed = false;

  /// Loop over the current set of jets!
  /// Note that Pre() stores the current jetType-- this is set earlier in the code
  /// To get the number of jets of jetType, just ask for jets(jetType)
  /// To get a specific jet, do jet(iJet,jetType)
  /// Jets have a four-vector: jet(iJet,jetType).p is a TLorentzVector
  /// Jets have moments: access them the same way as event moments, i.e jet(iJet,jetType).Float(momentType)
  for (int i = 0; i < jets(Pre()); i++) {

    /// Check for kinematic, topological, and quality selections. Print info if requested
    if(!PassesJetCuts(i)) {
      if (Debug()) {
        cout << "Analysis_GRJETSexample::BookBasic(): DEBUG Failed cuts: ";
        DumpJetInfo(i);
      }
      continue;
    }
    
    ///=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
    /// Print something about this jet
    ///=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
    if (Debug()) {
      cout << "Analysis_GRJETSexample::BookBasic(): DEBUG Passed cuts: ";
      DumpJetInfo(i);
      jet(i,Pre()).Show();
    }

    ///=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
    /// Jet kinematics: note use of GetPtBin and GetEtaBin to construct name of histogram
    /// This makes sure the jet enters the right pt/eta bin in a simple way
    ///=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
    if (Debug()) cout << "Analysis_GRJETSexample::BookBasic(): DEBUG Filling jet kinmematics" << endl;
    
    Fill("jet_pT"   , jet(i,Pre()).p.Pt(), Weight(), nJetEtBins, jetEtMinBin, jetEtMaxBin);
    Fill("jet_mass" , jet(i,Pre()).p.M(), Weight(), nJetMassBins, jetMassMinBin, jetMassMaxBin);
    Fill("jet_mass"  + GetPtBin(i) + GetEtaBin(i) , jet(i,Pre()).p.M(), Weight(), nJetMassBins, jetMassMinBin, jetMassMaxBin);
    Fill("jet_mass_vs_NPV"  + GetPtBin(i) + GetEtaBin(i) , Int("NPV") , jet(i,Pre()).p.M(), Weight(), nPvBins, pvMinBin, pvMaxBin, nJetMassBins, jetMassMinBin, jetMassMaxBin);

    if (i==0)      { 
      Fill("jet_pT1", jet(i,Pre()).p.Pt(), Weight(), nJetEtBins, jetEtMinBin, jetEtMaxBin); 
      Fill("jet_mass1", jet(i,Pre()).p.M(), Weight(), nJetMassBins, jetMassMinBin, jetMassMaxBin); 
      Fill("jet_mass1" + GetPtBin(i) + GetEtaBin(i) , jet(i,Pre()).p.M(), Weight(), nJetMassBins, jetMassMinBin, jetMassMaxBin);
      Fill("jet_mass1_vs_NPV"  + GetPtBin(i) + GetEtaBin(i) , Int("NPV") , jet(i,Pre()).p.M(), Weight(), nPvBins, pvMinBin, pvMaxBin, nJetMassBins, jetMassMinBin, jetMassMaxBin);
      leadJetPassed = true;
    }
    else if (i==1) { 
      Fill("jet_pT2", jet(i,Pre()).p.Pt(), Weight(), nJetEtBins, jetEtMinBin, jetEtMaxBin); 
      Fill("jet_mass2", jet(i,Pre()).p.M(), Weight(), nJetMassBins, jetMassMinBin, jetMassMaxBin); 
      Fill("jet_mass2" + GetPtBin(i) + GetEtaBin(i) , jet(i,Pre()).p.M(), Weight(), nJetMassBins, jetMassMinBin, jetMassMaxBin);
      Fill("jet_mass2_vs_NPV"  + GetPtBin(i) + GetEtaBin(i) , Int("NPV") , jet(i,Pre()).p.M(), Weight(), nPvBins, pvMinBin, pvMaxBin, nJetMassBins, jetMassMinBin, jetMassMaxBin);
    }
    else if (i==2) { 
      Fill("jet_pT3", jet(i,Pre()).p.Pt(), Weight(), nJetEtBins, jetEtMinBin, jetEtMaxBin); 
      Fill("jet_mass3", jet(i,Pre()).p.M(), Weight(), nJetMassBins, jetMassMinBin, jetMassMaxBin); 
      //Fill("jet_mass3" + GetEtaBin(i), jet(i,Pre()).p.M()); 
      Fill("jet_mass3" + GetPtBin(i) + GetEtaBin(i) , jet(i,Pre()).p.M(), Weight(), nJetMassBins, jetMassMinBin, jetMassMaxBin);
      Fill("jet_mass3_vs_NPV"  + GetPtBin(i) + GetEtaBin(i) , Int("NPV") , jet(i,Pre()).p.M(), Weight(), nPvBins, pvMinBin, pvMaxBin,  nJetMassBins, jetMassMinBin, jetMassMaxBin);
    }
    
    if (i==1 && leadJetPassed) Fill("jet_mass2_vs_mass1", jet(0,Pre()).p.M(), jet(i,Pre()).p.M(), Weight(), nJetMassBins, jetMassMinBin, jetMassMaxBin, nJetMassBins, jetMassMinBin, jetMassMaxBin);


    ///=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
    /// Jet properties versus Mass
    ///=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
    if (Debug()) cout << "Analysis_GRJETSexample::BookBasic(): DEBUG Filling jet properties vs. mass" << endl;
    if (i==0) {

      /// Inclusive
      Fill("jet_leading_tau21_vs_m", jet(i,Pre()).p.M(), jet(i,Pre()).Float("constittau21"), Weight(),  nJetMassBins, jetMassMinBin, jetMassMaxBin, nTauBins,     tauMinBin,     tauMaxBin);
      Fill("jet_leading_tau32_vs_m", jet(i,Pre()).p.M(), jet(i,Pre()).Float("constittau32"), Weight(),  nJetMassBins, jetMassMinBin, jetMassMaxBin, nTauBins,     tauMinBin,     tauMaxBin);

	    /// Exclusive pT binning 
      Fill("jet_leading_tau21_vs_m" + GetPtBin(i) , jet(i,Pre()).p.M(), jet(i,Pre()).Float("constittau21"), Weight(), nJetMassBins, jetMassMinBin, jetMassMaxBin, nTauBins,     tauMinBin,     tauMaxBin );
      Fill("jet_leading_tau32_vs_m" + GetPtBin(i) , jet(i,Pre()).p.M(), jet(i,Pre()).Float("constittau32"), Weight(), nJetMassBins, jetMassMinBin, jetMassMaxBin, nTauBins,     tauMinBin,     tauMaxBin );

      Fill("jet_leading_tau21Min_vs_m", jet(i,Pre()).p.M(), jet(i,Pre()).Float("constittau21Min"), Weight(), nJetMassBins, jetMassMinBin, jetMassMaxBin, nTauBins,     tauMinBin,     tauMaxBin );
      Fill("jet_leading_tau32Min_vs_m", jet(i,Pre()).p.M(), jet(i,Pre()).Float("constittau32Min"), Weight(), nJetMassBins, jetMassMinBin, jetMassMaxBin, nTauBins,     tauMinBin,     tauMaxBin );
      
      /// Exclusive pT binning 
      Fill("jet_leading_tau21Min_vs_m" + GetPtBin(i) , jet(i,Pre()).p.M(), jet(i,Pre()).Float("constittau21Min"), Weight(), nJetMassBins, jetMassMinBin, jetMassMaxBin, nTauBins,     tauMinBin,     tauMaxBin );
      Fill("jet_leading_tau32Min_vs_m" + GetPtBin(i) , jet(i,Pre()).p.M(), jet(i,Pre()).Float("constittau32Min"), Weight(), nJetMassBins, jetMassMinBin, jetMassMaxBin, nTauBins,     tauMinBin,     tauMaxBin );
    }
    Fill("jet_tau21_vs_m" , jet(i,Pre()).p.M(), jet(i,Pre()).Float("constittau21"), Weight(), nJetMassBins, jetMassMinBin, jetMassMaxBin, nTauBins,     tauMinBin,     tauMaxBin );
    Fill("jet_tau32_vs_m" , jet(i,Pre()).p.M(), jet(i,Pre()).Float("constittau32"), Weight(), nJetMassBins, jetMassMinBin, jetMassMaxBin, nTauBins,     tauMinBin,     tauMaxBin );

	  /// Exclusive pT binning
    Fill("jet_tau21"   + GetPtBin(i) , jet(i,Pre()).Float("constittau21"), Weight(),  nTauBins,     tauMinBin,     tauMaxBin  );       
    Fill("jet_tau32"   + GetPtBin(i) , jet(i,Pre()).Float("constittau32"), Weight(),  nTauBins,     tauMinBin,     tauMaxBin   ); 
    Fill("jet_tau21_vs_m"   + GetPtBin(i) , jet(i,Pre()).p.M()  , jet(i,Pre()).Float("constittau21"), Weight(), nJetMassBins, jetMassMinBin, jetMassMaxBin, nTauBins,     tauMinBin,     tauMaxBin   );       
    Fill("jet_tau32_vs_m"   + GetPtBin(i) , jet(i,Pre()).p.M()  , jet(i,Pre()).Float("constittau32"), Weight(), nJetMassBins, jetMassMinBin, jetMassMaxBin, nTauBins,     tauMinBin,     tauMaxBin   );         
    Fill("jet_tau21_vs_NPV" + GetPtBin(i) , Int("NPV")          , jet(i,Pre()).Float("constittau21"), Weight(), nJetMassBins, jetMassMinBin, jetMassMaxBin, nTauBins,     tauMinBin,     tauMaxBin   );    
    Fill("jet_tau32_vs_NPV" + GetPtBin(i) , Int("NPV")          , jet(i,Pre()).Float("constittau32"), Weight(), nJetMassBins, jetMassMinBin, jetMassMaxBin, nTauBins,     tauMinBin,     tauMaxBin   );   


    Fill("jet_tau21Min_vs_m" , jet(i,Pre()).p.M(), jet(i,Pre()).Float("constittau21"), Weight(), nJetMassBins, jetMassMinBin, jetMassMaxBin, nTauBins,     tauMinBin,     tauMaxBin );
    Fill("jet_tau32Min_vs_m" , jet(i,Pre()).p.M(), jet(i,Pre()).Float("constittau32"), Weight(), nJetMassBins, jetMassMinBin, jetMassMaxBin, nTauBins,     tauMinBin,     tauMaxBin );

    /// Exclusive pT binning
    Fill("jet_tau21Min"   + GetPtBin(i) , jet(i,Pre()).Float("constittau21Min"), Weight() ,  nTauBins,     tauMinBin,     tauMaxBin  );       
    Fill("jet_tau32Min"   + GetPtBin(i) , jet(i,Pre()).Float("constittau32Min"), Weight() ,  nTauBins,     tauMinBin,     tauMaxBin   ); 
    Fill("jet_tau21Min_vs_m"   + GetPtBin(i) , jet(i,Pre()).p.M()  , jet(i,Pre()).Float("constittau21Min"), Weight(), nJetMassBins, jetMassMinBin, jetMassMaxBin, nTauBins,     tauMinBin,     tauMaxBin   );       
    Fill("jet_tau32Min_vs_m"   + GetPtBin(i) , jet(i,Pre()).p.M()  , jet(i,Pre()).Float("constittau32Min"), Weight(), nJetMassBins, jetMassMinBin, jetMassMaxBin, nTauBins,     tauMinBin,     tauMaxBin   );         
    Fill("jet_tau21Min_vs_NPV" + GetPtBin(i) , Int("NPV")          , jet(i,Pre()).Float("constittau21Min"), Weight(), nJetMassBins, jetMassMinBin, jetMassMaxBin, nTauBins,     tauMinBin,     tauMaxBin   );    
    Fill("jet_tau32Min_vs_NPV" + GetPtBin(i) , Int("NPV")          , jet(i,Pre()).Float("constittau32Min"), Weight(), nJetMassBins, jetMassMinBin, jetMassMaxBin, nTauBins,     tauMinBin,     tauMaxBin   );  

  }
  if (Debug()) cout << "Analysis_GRJETSexample::BookBasic(): DEBUG End fill" << endl;
}

///=========================================
/// BookDetail: Not filled yet
///=========================================
void Analysis_GRJETSexample::BookDetail()
{
  //BookDetailKin();
  //BookTrig();
  //BookTagrate();
}

///=========================================
/// PassesJetCuts: Cut on jets
///=========================================
Bool_t Analysis_GRJETSexample::PassesJetCuts(int iJET)
{
  if (Debug()) cout << "Analysis_GRJETSexample: DEBUG In PassesJetCuts()" << endl;

  /// pT cut
  if(jet(iJET,Pre()).p.Pt() < Float("MINJETPT")) return false;
  
  /// Prevent ridiculous cases: negative energy or pT > beam energy
  if(jet(iJET,Pre()).p.E()  < 0.)    return false;
  if(jet(iJET,Pre()).p.Pt() > 1999.) return false;
  
  /// Eta cut
  if (fabs(jet(iJET,Pre()).p.Eta()) > Float("MAXJETETA")) return false;

  /// JVF cut
  if (jet(iJET,Pre()).Exists("JVF")) {
    if ( fabs(jet(iJET,Pre()).Float("JVF")) < Float("MINJETJVF") )
      return false;
  }

  // LAR veto:
  // -0.1<eta<1.5 -0.1 and -0.9<phi<-0.5
  if((isMC() && RunNumber()==183003) || (!isMC() &&  (180613 < RunNumber()) && (RunNumber() < 185353))){
    if(Debug()) cout << "Analysis_GRJETSexample::PassesJetCuts(): DEBUG testing for lar hole" << endl;
    if((jet(iJET,Pre()).p.Phi() > -0.9 && jet(iJET,Pre()).p.Phi() < -0.5) &&
        (jet(iJET,Pre()).p.Eta() > -0.1 && jet(iJET,Pre()).p.Eta() < 1.5)){
      if(Debug()) cout << "Analysis_GRJETSexample::PassesJetCuts(): DEBUG larhole fail!" << endl;
      return false;
    }
  }

  return true;
}

///=========================================
/// DumpJetInfo: Print info on jets
///=========================================
void Analysis_GRJETSexample::DumpJetInfo(int iJET)
{
  TString info = 
    TString::Format("Jet %d: (E, Et, m, eta, phi) = (%1.2f, %1.2f, %1.2f, %1.2f, %1.2f)",
					iJET, 
					jet(iJET,Pre()).p.E(),
					jet(iJET,Pre()).p.Et(),
					jet(iJET,Pre()).p.M(),
					jet(iJET,Pre()).p.Eta(),
					jet(iJET,Pre()).p.Phi()
				  );
 
  cout << info << endl; 
}

///=========================================
/// GetPtBin: Find the pT bin for a jet
///=========================================
TString Analysis_GRJETSexample::GetPtBin(int iJET)
{
  //if (Debug()) cout << "Analysis_GRJETSexample: DEBUG In GetPtBin()" << endl;

  float pt = jet(iJET,Pre()).p.Perp();

  for(unsigned int iPT = 0; iPT < ptBounds.size()-1; iPT++){
    if(pt >= ptBounds[iPT] && pt < ptBounds[iPT+1]){
      return TString::Format("_PT%i",(int)(ptBounds[iPT])); 
    } 
  }
  //if(Debug()) cout << "Analysis_GRJETSexample::GetPtBin(): DEBUG did not find pt bin! " << pt << endl;
  return "";
}

///=========================================
/// GetEtaBin: Find the eta bin for a jet
///=========================================
TString Analysis_GRJETSexample::GetEtaBin(int iJET)
{
  //if (Debug()) cout << "Analysis_GRJETSexample: DEBUG In GetEtaBin()" << endl;

  float eta = fabs(jet(iJET, Pre()).p.Eta());

  //if(Debug()) cout << "Analysis_GRJETSexample::GetEtaBin(): DEBUG etaBounds.size() = " << etaBounds.size() << " is size of etaBounds" << endl;
  for(unsigned int iETA = 0; iETA < etaBounds.size()-1; iETA++){
    if(eta >= etaBounds[iETA] && eta < etaBounds[iETA+1]){
      return TString::Format("_eta%i",(int)(10.*etaBounds[iETA])); 
    } 
  }
  //if(Debug()) cout << "Analysis_GRJETSexample::GetEtaBin(): DEBUG did not find eta bin! " << eta << endl;
  return "";
}
