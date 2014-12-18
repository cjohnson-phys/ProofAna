/**************************************************************************
 **
 **   File:         Analysis_SimpleExample.cxx
 **
 **   Description:  See header
 **                 
 **   Authors:      M. Swiatlowski, E Thompson
 **
 **************************************************************************/

#define Analysis_SimpleExample_cxx

#include "Analysis_SimpleExample.h"
#include "AnaConfig.h"
#include <TROOT.h>
#include <TH1F.h>
#include <TH2F.h>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include "TKey.h"
#include "TObjString.h"
#include "TObjArray.h"

///=========================================
/// WorkerBegin: setup binning, etc
///=========================================
 void Analysis_SimpleExample::WorkerBegin()
 {
  if (Debug()) cout << "Analysis_SimpleExample: DEBUG In WorkerBegin()" << endl;

  Analysis_JetMET_Base::WorkerBegin();

  ///=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
  /// Set Pt and eta bounds for plots
  ///=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
  ptBounds.push_back(0.);
  ptBounds.push_back(100.);
  ptBounds.push_back(150.);
  ptBounds.push_back(350.);
  ptBounds.push_back(1000.); 
  ptBounds.push_back(4000.);

  etaBounds.push_back(0.);  etaBounds.push_back(1.2); 
  etaBounds.push_back(2.0);


  if (Debug()) cout << "Analysis_SimpleExample: DEBUG Finish WorkerBegin()" << endl;  
} 

///=========================================
/// ProcessEvent: run the analysis
///=========================================  
bool Analysis_SimpleExample::ProcessEvent()
{

  if (Debug()) cout << "Analysis_SimpleExample: DEBUG In ProcessEvent(): RunNumber = " << RunNumber() << "; Channel = " << ChannelNumber() << "; EventNumber = " << EventNumber() << endl;

  OutputDir()->cd();

  if(Debug()) cout << "Making jets and jet Plots!" << endl;

  //MomKey myJets = MakeJets(fastjet::antikt_algorithm, 0.3, "clustersLCTopo","extra");
  //MomKey myJets = MakeJets(fastjet::antikt_algorithm, 0.4, "calotowers");     
  MomKey myJets = MakeSKJets(fastjet::antikt_algorithm, 0.4, "calotowers", 5.0, 0.4, true);


  if(jets(myJets)){
    Fill("lead_jet_pt", jet(0,myJets).p.Perp(), Weight(), 100, 0, 2000); 
  }
  else{
    cout << "There are no jets in event." << endl;
  }

  return true;
  AddGoodTracks();

  static const MomKey JetKey10LC("AntiKt10LCTopoTrimmedPtFrac5SmallR30");
  static const MomKey JetKeyKt3Trk("KtZ3Track");
  
  //  MakeJetPlots(JetKey10LC);

  //first make the truth bhadrons and match add them to track jet collection
  MakeTruthBHadronCollection();

  //make a vector that passes some track jet cuts
  AddVec("jetsKtZ3TrackPassCuts");
  for(int i=0; i<jets("KtZ3Track"); ++i){
    Particle* jetawesomeness = &jet(i, "KtZ3Track");
    if(jetawesomeness->p.Pt() < 7.) continue;
    Add("jetsKtZ3TrackPassCuts", jetawesomeness);
  }

  //ghost asso bhadrons to tracks
  AddGhostMatch("KtZ3Track","truthsBHadrons");

  //ghost asso track jets to large R jets
  AddGhostMatch("AntiKt10LCTopoTrimmedPtFrac5SmallR30","jetsKtZ3TrackPassCuts");



  if(jets("AntiKt10LCTopoTrimmedPtFrac5SmallR30") >1){
    Particle* LeadingJet = &jet(0, "AntiKt10LCTopoTrimmedPtFrac5SmallR30");
    Particle* SubLeadingJet = &jet(1, "AntiKt10LCTopoTrimmedPtFrac5SmallR30");

    //    Particle* SubLeadingJet = (Particle*)Obj("jetsAntiKt10LCTopoTrimmedPtFrac5SmallR30", 1);

    int nTrkJetsAsso0 = LeadingJet->Objs("jetsKtZ3TrackPassCutsGhost");
    int nTrkJetsAsso1 = SubLeadingJet->Objs("jetsKtZ3TrackPassCutsGhost");


    Fill("LeadingJet_numTrkJets",nTrkJetsAsso0, 1., 10, 0., 10.);
    Fill("SubLeadingJet_numTrkJets",nTrkJetsAsso1, 1., 10, 0., 10.);

    //    std::cout << "got here nTrkJetsAsso0: " << nTrkJetsAsso0 << std::endl;

    for(int j = 0; j < nTrkJetsAsso0; ++j){
      //std::cout << "leading jet" << std::endl;
      //((Particle*)LeadingJet->Obj("jetsKtZ3TrackPassCutsGhost", j))->Show();
      //should be 1 bhadron most of the time, but could have two in the same track jet
      int nBhadronsForJet = ((Particle*)LeadingJet->Obj("jetsKtZ3TrackPassCutsGhost", j))->Objs("truthsBHadronsGhost");
      if(nBhadronsForJet>0) Fill("LeadingJet_numTrkJetBHad",nBhadronsForJet, 1., 10, 0., 10.);
    }

    //    std::cout << "got here nTrkJetsAsso1: " << nTrkJetsAsso1 << std::endl;

    for(int j = 0; j < nTrkJetsAsso1; ++j){
      //std::cout << "subleading jet" << std::endl;
      //((Particle*)SubLeadingJet->Obj("jetsKtZ3TrackPassCutsGhost", j))->Show();
      //should be 1 bhadron most of the time, but could have two in the same track jet
      int nBhadronsForJet = ((Particle*)SubLeadingJet->Obj("jetsKtZ3TrackPassCutsGhost", j))->Objs("truthsBHadronsGhost");
      if(nBhadronsForJet>0) Fill("SubLeadingJet_numTrkJetBHad",nBhadronsForJet, 1., 10, 0., 10.);
    }


  }

  return true;
}

void Analysis_SimpleExample::MakeJetPlots(const MomKey JetKey){
  AnaKey JetKeyS(JetKey.Data());
  for(int iJet = 0; iJet < jets(JetKey); iJet++){

    Fill(JetKeyS+"_lj_pt", jet(iJet, JetKey).p.Perp(), Weight(), 300, 0., 3000.);
    Fill(JetKeyS+"_lj_m",  jet(iJet, JetKey).p.M()   , Weight(), 300, 0., 3000.);
    Fill(JetKeyS+"_lj_m" + GetPtBin(JetKey, iJet)+GetEtaBin(JetKey, iJet), jet(iJet, JetKey).p.M()   , Weight(), 300, 0., 3000.);


    if(iJet < 2){
      Fill(JetKeyS+"_dj_pt", jet(iJet, JetKey).p.Perp(), Weight(), 300, 0., 3000.);
      Fill(JetKeyS+"_dj_m",  jet(iJet, JetKey).p.M()   , Weight(), 300, 0., 3000.);
      Fill(JetKeyS+"_dj_m" + GetPtBin(JetKey, iJet)+GetEtaBin(JetKey, iJet), jet(iJet, JetKey).p.M()   , Weight(), 300, 0., 3000.);
    } 
    if (iJet < 1){
      Fill(JetKeyS+"_lj_pt", jet(iJet, JetKey).p.Perp(), Weight(), 300, 0., 3000.);
      Fill(JetKeyS+"_lj_m",  jet(iJet, JetKey).p.M()   , Weight(), 300, 0., 1000.);
      Fill(JetKeyS+"_lj_m" + GetPtBin(JetKey, iJet)+GetEtaBin(JetKey, iJet), jet(iJet, JetKey).p.M()   , Weight(), 300, 0., 1000.);
    }
  }
}


AnaKey Analysis_SimpleExample::GetPtBin(const MomKey JetKey, const int iJet){
  float pt = jet(iJet,JetKey).p.Perp();

  for(unsigned int iPT = 0; iPT < ptBounds.size()-1; iPT++){
    if(pt >= ptBounds[iPT] && pt < ptBounds[iPT+1]){
      if(Debug()) cout << "jet has pt " << pt << " and is in pt bin " << ptBounds[iPT] << endl;
      return TString::Format("_PT%i",(int)(ptBounds[iPT])); 
    } 
  }
  if(Debug()) cout << " did not find pt bin! " << pt << endl;
  return "";  
}

AnaKey Analysis_SimpleExample::GetEtaBin(const MomKey JetKey, const int iJet){
  float eta = fabs(jet(iJet, JetKey).p.Eta());

  //if(Debug()) cout << etaBounds.size() << " is size of etaBounds" << endl;
  for(unsigned int iETA = 0; iETA < etaBounds.size()-1; iETA++){
    if(eta >= etaBounds[iETA] && eta < etaBounds[iETA+1]){
      if(Debug()) cout << "jet has eta " << eta << " and is in eta bin " << etaBounds[iETA] << endl;
      return TString::Format("_eta%i",(int)(10.*etaBounds[iETA])); 
    } 
  }
  if(Debug()) cout << " did not find eta bin! " << eta << endl;
  return "";
}

///=========================================
/// WorkerTerminate: clean up
///=========================================
void Analysis_SimpleExample::WorkerTerminate()
{

  // Nothing

}

///==========================================
/// MakeJetMassCut: return true if lead jet of type specified is outside of mass window
///==========================================
bool Analysis_SimpleExample::MakeJetMassCut(MomKey JetKey){
  if(jets(JetKey) < 1)
    return false;
  float m = jet(0,JetKey).p.M();
  if(m < 50. || m > 110.)
    return false; 
  return true;
}

///==========================================
/// MakeJetPtCut: return true if lead jet of type specified is outside of pT window
///==========================================
bool Analysis_SimpleExample::MakeJetPtCut(MomKey JetKey){
  if(jets(JetKey) < 1)
    return false;
  float pt = jet(0,JetKey).p.Perp();
  if(pt <= 200. || pt > 350.)
    return false; 
  return true;
}
