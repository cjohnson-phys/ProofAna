/**************************************************************************
 **
 **   File:         Analysis_GRJETSexample_setup.h
 **
 **   Description:  See header
 **                 
 **   Authors:      M. Kagan
 **
 **************************************************************************/

#define Analysis_GRJETSexample_setup_cxx

#include "Analysis_GRJETSexample_setup.h"
#include "AnaConfig.h"
#include <TROOT.h>
#include <TH1F.h>
#include <TH2F.h>
#include <iostream>
#include <cstdlib>
#include "TKey.h"
#include "TObjString.h"
#include "TObjArray.h"
#include "Nsubjettiness.h"


///=========================================
/// WorkerBegin: setup binning, etc
///=========================================
void Analysis_GRJETSexample_setup::WorkerBegin()
{
  if (Debug()) cout << "Analysis_GRJETSexample_setup: DEBUG In WorkerBegin()" << endl;
  
  ChainCfg()->Set("NEWJETTYPES", "AntiKtLCTopo15,AntiKtLCTopo15TrimmedPtFrac5SmallR30"); // add to list of jets


  if (Debug()) cout << "Analysis_GRJETSexample_setup: DEBUG Finish WorkerBegin()" << endl;



 

  // GET THE LIST OF CUSTOM TRIMMED JETS WE WANT TO CREATE
  // This is three separate things: the base type, and two trimming parameters
  TObjArray* arrJets = ChainCfg()->String("BASECUSTOMTRIMMING").Tokenize(",");
  for(int i = 0; i<arrJets->GetEntries(); ++i) {
    TObjString* jetTypeObj = (TObjString*)arrJets->At(i);
  TString jetType        = jetTypeObj->GetString();
    if (Debug()) cout << "Analysis_GRJETSexample::WorkerBegin(): DEBUG Adding jet type: " << jetType << endl; 
    baseCustomTrimming.push_back(jetType);    
  }
  arrJets->SetOwner(kFALSE); delete arrJets;

  arrJets = ChainCfg()->String("PTFRACCUSTOMTRIMMING").Tokenize(",");
  for(int i = 0; i<arrJets->GetEntries(); ++i) {
    TObjString* jetTypeObj = (TObjString*)arrJets->At(i);
  TString jetType        = jetTypeObj->GetString();
    if (Debug()) cout << "Analysis_GRJETSexample::WorkerBegin(): DEBUG Adding jet type: " << jetType << endl; 
    ptFracCustomTrimming.push_back(jetType.Atof());    
  }
  arrJets->SetOwner(kFALSE); delete arrJets;

  arrJets = ChainCfg()->String("SMALLRCUSTOMTRIMMING").Tokenize(",");
  for(int i = 0; i<arrJets->GetEntries(); ++i) {
    TObjString* jetTypeObj = (TObjString*)arrJets->At(i);
  TString jetType        = jetTypeObj->GetString();
    if (Debug()) cout << "Analysis_GRJETSexample::WorkerBegin(): DEBUG Adding jet type: " << jetType << endl; 
    smallRCustomTrimming.push_back(jetType.Atof());    
  }
  arrJets->SetOwner(kFALSE); delete arrJets;

  //copy over the listed jets, to the full jets list, which combines custom and new jets
  ChainCfg()->Set("FULLJETTYPES",ChainCfg()->String("JETTYPES"));

  // now check that we don't already have it in our list, and add it to the list
  for(unsigned int iJetType = 0; iJetType < baseCustomTrimming.size(); iJetType++){
    if(!ChainCfg()->String("FULLJETTYPES").Contains(baseCustomTrimming[iJetType]))
      ChainCfg()->Set("FULLJETTYPES",ChainCfg()->String("FULLJETTYPES")+","+baseCustomTrimming[iJetType]);
    TString trimmedString = baseCustomTrimming[iJetType]+TString::Format("TrimmedPtFrac%0.fSmallR%0.f",100.*ptFracCustomTrimming[iJetType],100.*smallRCustomTrimming[iJetType]);
    ChainCfg()->Set("FULLJETTYPES",ChainCfg()->String("FULLJETTYPES")+","+trimmedString);
    newJetType.push_back(baseCustomTrimming[iJetType]);
    newJetType.push_back(trimmedString);
  }


    ///=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
  /// Jet types: creates a normal vector<TString> of the jetTypes you initialized
  /// Loop over this vector to make plots for many different types of jets, for example
  ///=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
  if (Debug()) cout << "Analysis_GRJETSexample::WorkerBegin(): DEBUG Adding jet types to list to analyze" << endl;  
  arrJets = ChainCfg()->String("FULLJETTYPES").Tokenize(",");
  for(int i = 0; i<arrJets->GetEntries(); ++i) {
    TObjString* jetTypeObj = (TObjString*)arrJets->At(i);
  TString jetType        = jetTypeObj->GetString();
    if (Debug()) cout << "Analysis_GRJETSexample::WorkerBegin(): DEBUG Adding jet type: " << jetType << endl; 
    jetVec.push_back(jetType);    
  }
  arrJets->SetOwner(kFALSE); delete arrJets;



}

///=========================================
/// WorkerTerminate
///=========================================
void Analysis_GRJETSexample_setup::WorkerTerminate()
{
  if (Debug()) cout << "Analysis_GRJETSexample_setup: DEBUG In WorkerTerminate()" << endl;
  


  if (Debug()) cout << "Analysis_GRJETSexample_setup: DEBUG Finish WorkerTerminate()" << endl;



}

///=========================================
/// ProcessEvent: do stuff for the event
/// As an example here, set up new jets, and then add to them  n-subjettiness
/// Then calculate minimized n-subjettiness for all jets 
///=========================================
bool Analysis_GRJETSexample_setup::ProcessEvent()
{
  if (Debug()) cout << "Analysis_GRJETSexample_setup: DEBUG In ProcessEvent()" << endl;
  



  // for every new algorithm scheduled for trimming, add on the trimmed jets!
  for(unsigned int iNew = 0; iNew < baseCustomTrimming.size(); iNew++){
    AddTrimmedJets(baseCustomTrimming[iNew], ptFracCustomTrimming[iNew], smallRCustomTrimming[iNew]);
  }



  // for *all* jet types, add the new nsub, and the old nsub
  for(unsigned int iJet = 0; iJet < jetVec.size(); iJet++){
    AddNsub("constit", jetVec[iJet], false,1.);
    AddNsub("constit", jetVec[iJet], true, 1.);
    AddNsub("constit", jetVec[iJet], true, 2.);
  }


  //Show();
  //cout << endl << ChainCfg()->String("JETTYPES") << endl;


  if (Debug()) cout << "Analysis_GRJETSexample_setup: DEBUG Finish ProcessEvent()" << endl;


  return true;

}


///=========================================
/// Add tracking associations to a given jet, for all tracks within some DR of jet
/// Assumes that "tracksgood" is set up
///=========================================
bool Analysis_GRJETSexample_setup::AddTrackingDR(Particle* jet, float dr){
  jet->AddVec("tracksgoodDR");
  for(int iTr = 0; iTr < tracks("good"); iTr++){
    if(track(iTr,"good").p.DeltaR(jet->p) < dr){
      jet->Add("tracksgoodDR",&track(iTr,"good"));
    }
  }
  return true;
}

///=========================================
/// Defines good tracks. 2011 selection by default, should probably update for 2012.
///=========================================
bool Analysis_GRJETSexample_setup::AddGoodTracks(){
  AddVec("tracksgood");
  if(Debug()) cout << "starting with " << tracks() << " tracks!" << endl;
  for(int i = 0; i < tracks(); i++){

    if(track(i).p.Perp() < 1.0 || // if we fail one of these...
        track(i).Int("nPixHits") < 1 ||
        track(i).Int("nSCTHits") < 6 ||

        fabs(track(i).Float("d0")) > 1.0 ||
        fabs(track(i).Float("z0")*TMath::Sin(track(i).Float("theta"))) > 1.0 ||
        track(i).Float("chi2")/track(i).Float("ndof") > 3.){

      track(i).Set("bad",true);

    }
    // we've passed! add to the list of good tracks
    else{
      track(i).Set("bad",false);
      Add("tracksgood",&track(i));
    }
  }
  if(Debug()) cout << "we have " << tracks("good") << " left!" << endl;
  return true;
}



///=========================================
/// Say you are a groomed jet and you want to calculate color flow
/// but your constituents are trimmed! that sucks for color flow
/// So let's do something else: copy the collection of your parent's (i.e.
/// the ungroomed version of this jet) constituents
///=========================================
bool Analysis_GRJETSexample_setup::CopyParentConstituents(Particle* jet){
  if(Debug()) cout << "In CopyParentConstituents for jet " << jet << endl;
  Particle* parent = (Particle*) jet->Obj("parent",0);
  if(Debug()) cout << "In CopyParentConstituents, have parent " << parent << endl;


  jet->AddVec("constitParent");
  for(int iC = 0; iC < parent->Objs("constit"); iC++){
    jet->Add("constitParent", parent->Obj("constit",iC));
  }
  if(Debug()) cout << "Finished CopyParentConstituents for jet " << jet << endl;
  return true;
}

///=========================================
/// Cluster new fat, trimmed jets, but also parent jets
/// Create links between parent and child
/// TODO: if existingParent is set, use that as the parent for link purposes
/// Create links between constituents and jets
/// TODO: generalize to not just LCTopo?
///=========================================
bool Analysis_GRJETSexample_setup::AddTrimmedJets(TString jetCollection, float ptFrac, float R){
  vector<fastjet::PseudoJet> particles = ObjsToPJ("clustersLCTopo");

  double jetRad = 1.0;

  if(jetCollection.Contains("10"))
    jetRad=1.0;
  else if(jetCollection.Contains("12"))
    jetRad=1.2;
  else if(jetCollection.Contains("4"))
    jetRad=0.4; 
  else if(jetCollection.Contains("6"))
    jetRad=0.6; 
  else if(jetCollection.Contains("15"))
    jetRad=1.5;

  fastjet::JetDefinition* fJetDef = 0;

  if(jetCollection.Contains("AntiKt")){
    fJetDef = new fastjet::JetDefinition(fastjet::antikt_algorithm,
        jetRad,
        fastjet::Best); 
  }
  if(jetCollection.Contains("CamKt")){
    fJetDef = new fastjet::JetDefinition(fastjet::cambridge_algorithm,
        jetRad,
        fastjet::Best); 
  }

  fastjet::GhostedAreaSpec areaSpec(5.0);

  //------ cluster and calculate hard scattering jet areas
  fastjet::ClusterSequenceArea hardClustSeq(particles,
      *fJetDef, areaSpec);

  //matching to existing jets: assuming they are also sorted by pt
  vector<fastjet::PseudoJet> UnGroomedJets = 
    fastjet::sorted_by_pt(hardClustSeq.inclusive_jets(10.));

  fastjet::Filter trimmer(R, fastjet::SelectorPtFractionMin(ptFrac));  

  bool existingParent = Exists("jets"+jetCollection);

  if(Debug()) cout << "existingParent = " << existingParent << endl;

  if(!existingParent)
    AddVec("jets"+jetCollection);
  TString trimJetCollection = jetCollection+TString::Format("TrimmedPtFrac%0.fSmallR%0.f",100.*ptFrac,100.*R);
  if(Debug()) cout << trimJetCollection << " is the new trimmed collection" << endl;
  AddVec("jets"+trimJetCollection);
  for(unsigned int iJet = 0; iJet < UnGroomedJets.size(); iJet++){
    if(existingParent){
      if(iJet > jets(jetCollection)-1){
        continue;
      }
    }
    Particle* UnGroomed;
    if(!existingParent){
      UnGroomed = new Particle();
      UnGroomed->p.SetPtEtaPhiE(UnGroomedJets[iJet].pt(), UnGroomedJets[iJet].eta(),
        UnGroomedJets[iJet].phi(), UnGroomedJets[iJet].e());
      UnGroomed->Set("ptConstScale", UnGroomedJets[iJet].pt());
      UnGroomed->Set("mConstScale",  UnGroomedJets[iJet].m());
      UnGroomed->Set("etaConstScale", UnGroomedJets[iJet].eta());

      UnGroomed->Set("ActiveArea",   UnGroomedJets[iJet].area());

      fastjet::PseudoJet area = UnGroomedJets[iJet].area_4vector();
      UnGroomed->Set("ActiveArea_px", area.px());
      UnGroomed->Set("ActiveArea_py", area.py());
      UnGroomed->Set("ActiveArea_pz", area.pz());
      UnGroomed->Set("ActiveArea_e" , area.e());

      Add("jets"+jetCollection, UnGroomed);
    }
    else{
      UnGroomed = &jet(iJet,jetCollection);
    }
    if(Debug()) cout << "set up the ungroomed " << endl;


    Particle* Groomed = new Particle();
    fastjet::PseudoJet GroomedPJ = trimmer(UnGroomedJets[iJet]);
    Groomed->p.SetPtEtaPhiE(GroomedPJ.pt(), GroomedPJ.eta(),
      GroomedPJ.phi(), GroomedPJ.e());
    Groomed->Set("ptConstScale", GroomedPJ.pt());
    Groomed->Set("mConstScale", GroomedPJ.m());
    Groomed->Set("etaConstScale", GroomedPJ.eta());

    if(Debug()) cout << "set up the groomed " << endl;
    // Apparently groomed jets in FastJet don't support area directly???
    // Groomed->Set("ActiveArea",   GroomedPJ.area());

    // fastjet::PseudoJet area = GroomedPJ.area_4vector();
    // Groomed->Set("ActiveArea_px", area.px());
    // Groomed->Set("ActiveArea_py", area.py());
    // Groomed->Set("ActiveArea_pz", area.pz());
    // Groomed->Set("ActiveArea_e" , area.e());


    Add("jets"+trimJetCollection, Groomed);

    if(!existingParent){
      UnGroomed->AddVec("constit");
      Groomed->AddVec("constitParent");
      vector<fastjet::PseudoJet> UnGroomedCons = UnGroomedJets[iJet].constituents();
      for(unsigned int iCons = 0; iCons < UnGroomedCons.size(); iCons++){
        UnGroomed->Add("constit", UnGroomedCons[iCons].user_info<PJ_Info>().Pointer);
        Groomed->Add("constitParent", UnGroomedCons[iCons].user_info<PJ_Info>().Pointer);
      }
    }


    if(Debug()) cout << "intermediate constituent point" << endl;

    Groomed->AddVec("constit");
    vector<fastjet::PseudoJet> GroomedCons = GroomedPJ.constituents();
    for(unsigned int iCons = 0; iCons < GroomedCons.size(); iCons++){
      Groomed->Add("constit", GroomedCons[iCons].user_info<PJ_Info>().Pointer);
    }

    if(Debug()) cout << " set up constituents " << endl;

    Groomed->AddVec("parent");
    UnGroomed->AddVec("child_"+trimJetCollection,true);
    Groomed->Add("parent",UnGroomed);
    UnGroomed->Add("child_"+trimJetCollection, Groomed);

    if(Debug()) cout << " set up parent/child " << endl;

    if(Debug()){
      Groomed->Show();
      UnGroomed->Show();
    }

  }


  delete fJetDef;  


  return true;
}





