/**************************************************************************
 **
 **   File:         EventBuilder_GRJETSv11.h
 **
 **   Description:  EventBuilder class for analyzing the v11 GRJETS D3PDs. Use
 **                 cases include but are not limited to the following:
 **
 **   Authors:      D. W. Miller and M. Swiatlowski
 **
 **   Created:      2012-12-02 - MS
 **   Modified:     
 **
 **************************************************************************/

#ifndef EventBuilder_GRJETSv11_h
#define EventBuilder_GRJETSv11_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
//include <TSelector.h>
#include "EventBuilderBase.h"
#include <TLorentzVector.h>
#include "AnalysisBase.h"
#include "TrigRootAnalysis/TrigDecisionToolD3PD.h"
//#include "utils/TriggerConfViewer/TrigDefsGJ.h"

namespace Root {class TPileupReweighting;}
using namespace D3PD;

class EventBuilder_GRJETSv11 : public EventBuilderBase {
public :
   Bool_t   CopyEvent(AnalysisBase* evt);
   void  WriteAuxTrees(TDirectory* outfile);

   virtual bool DoCustomSetup();

   void Initialize();
   Bool_t  Notify();
 
   Bool_t   CopyTruthFull();
   Bool_t   CopyPhotons();
   Bool_t   CopyElectrons();
   Bool_t   CopyMuons();
   Bool_t   CopyVertices();	
   Bool_t   CopyJets();
   Bool_t   CopyJet(TString jetType = "", TString jetClass = "");
   Bool_t   CopyTracks();
   Bool_t   CopyClusters();
   Bool_t   CopySubjets();


   Bool_t   AddTrackJetLink(TString recoType = "");
   Bool_t   AddParentLinks();
   Bool_t   AddParentLink(TString parentJetType = "");
   Bool_t   AddConstituents();
   Bool_t   AddTruthLinks();
   Bool_t   AddTruthJetLinks();
   Bool_t   AddTruthJetLink(TString recoType = "");
   Bool_t   AddTrackingInfo();
   Bool_t   AddTrackInJetInfo(TString recoType = "");
   Bool_t   AddTriggers();
   Bool_t   AddBadJetType();
   Bool_t   AddBtags();
   Bool_t   AddBtag(TString jetType = "", TString jetClass = "");
   
   float TrackJetSyst(Particle &trackJet);
   bool doTrackSyst;
   int  doJESSyst;

   bool doJetStructure;
   bool doParentChild;
   bool doConstituents;
   bool doTruthConstituents;
   bool doTrack;
   bool doPhotons;
   bool doElectrons;
   bool doMuons;
   bool doLCCluster;
   bool doEMCluster;
   bool doTruth;
   bool doVertex;
   bool doBasic;
   bool doTruthLinks;
   bool doTruthJetLinks;
   bool doTrackJetLinks;
   bool doTrigger;
   bool doSubjets;

   TString mTRIGVEC;
   TString mLUMIVEC;
   TString mJETTYPEVEC;
   TString mSUBJETTYPEVEC;
   TString mBTAGVEC;
   TString mTRIGLUMIVEC;
   TString mTRIGCUTVEC; 
   TString mTRIGPARVEC; 

   Root::TPileupReweighting* myPile;

    // trigger things
   Long64_t m_TrigEntry;
   Long64_t m_TMNEntry;
   TTree* m_trigConfTree;
   TrigDecisionToolD3PD* m_trigdefs;

   EventBuilder_GRJETSv11(TTree * /*tree*/ =0);
   virtual ~EventBuilder_GRJETSv11();

   AnalysisBase* fEvt;

   ClassDef(EventBuilder_GRJETSv11,0);

private:

   	bool		m_isNewInit;
};

#endif

#ifdef EventBuilder_GRJETSv11_cxx

Bool_t EventBuilder_GRJETSv11::Notify()
{
  // The Notify() function is called when a new file is opened. This
  // can be either for a new TTree in a TChain or when when a new TTree
  // is started when using PROOF. It is normally not necessary to make changes
  // to the generated code, but the routine can be extended by the
  // user if needed. The return value is currently not used.

  //flag for skimming, do not want to copy auxiliary tree if we already have
  //cout << "starting notify" << endl;

  //if(fEvt->Debug()) cout << "setting up trees for trig decisions, etc." << endl;
  m_isNewInit = true;
  
  //flags for trigger navigation and trigger decision readers, whether we have to load branches
  m_TrigEntry = -1;
  m_TMNEntry = -1;

  if(!Tree()->GetTree()) return kTRUE;

  TFile* file = 0;
  TChain* chain = dynamic_cast< TChain* >( Tree() );
  //cout << "casted" << endl;
  if( chain ) {
	  // We are running locally...
	  file = chain->GetFile();
  } else {
	  // We are running on PROOF:
	  file = Tree()->GetCurrentFile();
  }

  m_trigConfTree = (TTree*)( file->Get( "jetsMeta/TrigConfTree" ) );


  if(m_trigdefs) delete m_trigdefs;

  m_trigdefs = new TrigDecisionToolD3PD(Tree()->GetTree(), m_trigConfTree,"trig_");
  //m_trigdefs->initTrigMetaData(m_trigConfTree,Tree());

  //if(fEvt->Debug()) cout << " All good on NotifyOnDemand()" << endl;
  return kTRUE;
}


#endif // #ifdef EventBuilder_GRJETSv11_cxx
