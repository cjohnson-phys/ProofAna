/**************************************************************************
 **
 **   File:         EventBuilder_GRJETSv11.cxx
 **
 **   Description:  EventBuilder class for analyzing the v7 GRJETS D3PDs. Use
 **                 cases include but are not limited to the following:
 **
 **   Authors:      D. W. Miller and M. Swiatlowski
 **
 **   Created:      2012-12-02 - MS
 **   Modified:     
 **
 **************************************************************************/

#define EventBuilder_GRJETSv11_cxx

#include "EventBuilder_GRJETSv11.h"
#include "AnaConfig.h"
//#include "AnalysisBase.h"
#include "TMath.h"
#include "TVector3.h"
#include "PileupReweighting/TPileupReweighting.h"
#include "TKey.h"
#include <iostream>
#include "TPRegexp.h"


TRandom r1;

///=========================================
/// Constructor
///=========================================
EventBuilder_GRJETSv11::EventBuilder_GRJETSv11(TTree * /*tree*/)
{
  m_trigdefs  = 0;
  mJETTYPEVEC    = "JETTYPEVEC";
  mBTAGVEC       = "BTAGVEC";
  mSUBJETTYPEVEC = "SUBJETTYPEVEC";
  mTRIGVEC       = "TRIGVEC";
  mTRIGLUMIVEC   = "TRIGLUMIVEC";
  mTRIGCUTVEC    = "TRIGCUTVEC";
  mTRIGPARVEC    = "TRIGPARVEC";
}

///=========================================
/// Destructor
///=========================================
EventBuilder_GRJETSv11::~EventBuilder_GRJETSv11(){
  if( m_trigdefs) delete m_trigdefs;
}

///=========================================
/// Initialize
///=========================================
void EventBuilder_GRJETSv11::Initialize() {}

///=========================================
/// CopyEvent
///=========================================
Bool_t EventBuilder_GRJETSv11::CopyEvent(AnalysisBase* evt)
{
  // Copy the event from the TTree to the event class. Return false if you want to reject
  // event at the EventBuilder level using D3PD snippets, etc. 	
	
  static const MomKey mChannelNumber("ChannelNumber");
  static const MomKey misMC("isMC");


  fEvt = evt;

  ///=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
  /// Get the overall configuration
  ///=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
  
  if (evt->Debug()) cout << "EventBuilder_GRJETSv11: DEBUG CopyEvent() " << endl;	
  
  /// Overall Options for Event
  
  doBasic        = true;
  evt->Cfg()->Get("DOBASIC"         , doBasic             );
  doTruthLinks   = false;
  evt->Cfg()->Get("DOTRUTHLINKS"    , doTruthLinks        );
  doTruthJetLinks=false;
  evt->Cfg()->Get("DOTRUTHJETLINKS" , doTruthJetLinks     );
  doTrackJetLinks= false;
  evt->Cfg()->Get("DOTRACKJETLINKS" , doTrackJetLinks     );
  doJetStructure = false;
  evt->Cfg()->Get("DOJETSTRUCT"     , doJetStructure      );
  doConstituents = false;
  evt->Cfg()->Get("DOCONSTIT"       , doConstituents      );
  doTruthConstituents = false;
  evt->Cfg()->Get("DOTRUTHCONSTIT"  , doTruthConstituents );
  doParentChild  = false;
  evt->Cfg()->Get("DOPARENTCHILD"   , doParentChild       );
  doTrack        = false;
  evt->Cfg()->Get("DOTRACK"         , doTrack             );
  doLCCluster    = false;
  evt->Cfg()->Get("DOLCCLUSTER"     , doLCCluster         );
  doEMCluster    = false;
  evt->Cfg()->Get("DOEMCLUSTER"     , doEMCluster         );
  doTruth        = false;
  evt->Cfg()->Get("DOTRUTH"         , doTruth             );
  doVertex       = false;
  evt->Cfg()->Get("DOVTX"           , doVertex            );
  doPhotons      = false; 
  evt->Cfg()->Get("DOPHOTON"        , doPhotons           );
  doSubjets      = false;
  evt->Cfg()->Get("DOSUBJETS"       , doSubjets           );
  doElectrons    = false;
  evt->Cfg()->Get("DOELECTRONS"     , doElectrons         );
  doMuons        = false;
  evt->Cfg()->Get("DOMUONS"         , doMuons             );
  
  /// Systematics variations
  doTrackSyst    = false;
  evt->Cfg()->Get("DOTRACKSYST"     , doTrackSyst         );
  doJESSyst      = false;
  evt->Cfg()->Get("DOJETSYS"        , doJESSyst           );

  ///=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
  /// Add jet type list to event config
  ///=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
  if(!evt->Cfg()->Exists(mJETTYPEVEC)) {
    evt->Cfg()->AddVec(mJETTYPEVEC);
    //evt->AddVec(mJETTYPEVEC);
    TObjArray* arr = evt->Cfg()->String("JETTYPES").Tokenize(",");
    for(Int_t i = 0; i<arr->GetEntries(); ++i) {
      if (evt->Debug()) {
        TObjString* jetTypeObj = (TObjString*)arr->At(i);
		TString jetType        = jetTypeObj->GetString();
        cout << "EventBuilder_GRJETSv11::CopyEvent(): DEBUG Adding jet type: " << jetType << endl;	
      }
      
      evt->Cfg()->Add(mJETTYPEVEC, (TObjString*)arr->At(i));
    }
    
    arr->SetOwner(kFALSE);  delete arr;
  }

  /// here we copy subjet types listed in the vector in the runscript to an internal vector
  if (!evt->Cfg()->Exists(mSUBJETTYPEVEC)) {
    evt->Cfg()->AddVec(mSUBJETTYPEVEC);
    //evt->AddVec(mJETTYPEVEC);
    if(evt->Cfg()->Exists("SUBJETTYPES")){
      TObjArray* arr = evt->Cfg()->String("SUBJETTYPES").Tokenize(",");
      for(Int_t i = 0; i<arr->GetEntries(); ++i) {
        if (evt->Debug()) {
          TObjString* jetTypeObj = (TObjString*)arr->At(i);
          TString jetType        = jetTypeObj->GetString();
          cout << "EventBuilder_GRJETSv11::CopyEvent(): DEBUG Adding subjet type: " << jetType << endl; 
        }

        evt->Cfg()->Add(mSUBJETTYPEVEC, (TObjString*)arr->At(i));
      }
        
    arr->SetOwner(kFALSE);  delete arr;
    }
  }
  
  // here we copy things we want to copy b-tagging info for to an internal vector
  if(!evt->Cfg()->Exists(mBTAGVEC)) {
    evt->Cfg()->AddVec(mBTAGVEC);
    //evt->AddVec(mJETTYPEVEC);
    if(evt->Cfg()->Exists("BTAGS")){
      TObjArray* arr = evt->Cfg()->String("BTAGS").Tokenize(",");
      for(Int_t i = 0; i<arr->GetEntries(); ++i) {
        if (evt->Debug()) {
          TObjString* jetTypeObj = (TObjString*)arr->At(i);
          TString jetType        = jetTypeObj->GetString();
          cout << "EventBuilder_GRJETSv11::CopyEvent(): DEBUG Adding btag type: " << jetType << endl; 
        }
      
        evt->Cfg()->Add(mBTAGVEC, (TObjString*)arr->At(i));
      }
    
      arr->SetOwner(kFALSE);  delete arr;
    }
  }

  ///=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
  /// If we haven't already created a config 
  /// property for the list of triggers, 
  /// cuts, params and cut values, do it now
  ///=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
  if (!evt->Cfg()->Exists(mTRIGVEC)) {
    
    if (evt->Debug()) cout << "EventBuilder_GRJETSv11::CopyEvent(): DEBUG Loading trigger information" << endl;	
    
    //---------------------------------------------------------------------------
    // We need to specify FOUR VECTORS:
    //
    // 		TRIGTYPES: which triggers you want to check
    // 		TRIGLUMI: the luminosity associated with this trigger for weighting
    // 		TRIGPARAM: which parameter defines the plateau region
    // 		TRIGCUT: what's the value on the plateau to cut on in MeV!!!
    // 
    // so for g80_loose_EFFS:
    // specify TRIGPARAM = ph_pt
    // and TRIGCUT = 85000.0  <--- MEV
    //
    // for EF_j240_a4tc_EFFS
    // specify TRIGPARAM = jet_AntiKt4LCTopo_pt
    // and TRIGCUT = 350000.0 <--- MEV
    //
    // note to turn this off you can put some random branch for param and "0"
    // note also to specify the TRIGLUMI fraction that corresponds to the trig
    //---------------------------------------------------------------------------
    
    evt->Cfg()->AddVec(mTRIGVEC);
    evt->Cfg()->AddVec(mTRIGLUMIVEC);
    evt->Cfg()->AddVec(mTRIGCUTVEC);
    evt->Cfg()->AddVec(mTRIGPARVEC);

    TObjArray* arr      = evt->Cfg()->String("TRIGTYPES") .Tokenize(",");
    TObjArray* arrLumi  = evt->Cfg()->String("TRIGLUMI")  .Tokenize(",");
    TObjArray* arrCut   = evt->Cfg()->String("TRIGCUT")   .Tokenize(",");
    TObjArray* arrPar   = evt->Cfg()->String("TRIGPARAM") .Tokenize(",");
    
    /// Loop over all the triggers
    for(Int_t i = 0; i<arr->GetEntries(); ++i){ 
      
      if (evt->Debug()) cout << "EventBuilder_GRJETSv11::CopyEvent(): DEBUG Adding trigger info to event: entry = " << i << endl;	
      
      evt->Cfg()->Add(mTRIGVEC,     (TObjString*)arr->At(i));
      evt->Cfg()->Add(mTRIGLUMIVEC, (TObjString*)arrLumi->At(i));
      evt->Cfg()->Add(mTRIGCUTVEC,  (TObjString*)arrCut->At(i));
      evt->Cfg()->Add(mTRIGPARVEC,  (TObjString*)arrPar->At(i));
      
    }
    
    arr->SetOwner(kFALSE);     delete arr;     
    arrPar->SetOwner(kFALSE);  delete arrPar;   
    arrCut->SetOwner(kFALSE);  delete arrCut;  
    arrLumi->SetOwner(kFALSE); delete arrLumi; 
  }
    
  
  if (evt->Debug()) cout << "EventBuilder_GRJETSv11::CopyEvent(): DEBUG Setting up configs" << endl;

  ///=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
  /// BASIC OPTIONS: Run, Event, etc
  ///=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
  if (doBasic) {
    
    if (evt->Debug()) cout << "EventBuilder_GRJETSv11::CopyEvent(): DEBUG Setting basic event level quantities" << endl;
  
    /// Overall event info
    evt->Set("RunNumber"         , (int)   Get<UInt_t>("RunNumber"));
    evt->Set("EventNumber"       , (int)   Get<UInt_t>("EventNumber"));
    evt->Set("EventWeight"       ,  1.0) ; // default value
    evt->Set("mcweight"          , Get<vector<vector<double > > >("mcevt_weight").at(0).at(0));
    evt->Set("grl"               ,  true); // default value
    evt->Set("larerror"          ,         Get<UInt_t>("larError")); 
    evt->Set("averageIntPerXing" ,         Get<Float_t>("averageIntPerXing"));
    evt->Set("LBN"               , (int)   Get<UInt_t>("lbn"));
    evt->Set("BunchCrossingID"   , (int)   Get<UInt_t>("bcid"));

    evt->Set("rhoKt4LC"          , Get<Float_t>("rhorhoKt4LC"));
    evt->Set("rhoKt4EM"          , Get<Float_t>("rhorhoKt4EM"));
    evt->Set("rhoKt3LC"          , Get<Float_t>("rhorhoKt3LC"));
    evt->Set("rhoKt3EM"          , Get<Float_t>("rhorhoKt3EM"));
    
    ///=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
	/// Event level options
	///=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
	
	/// Luminosity
	evt->Set("LUMI"            , (float) evt->Cfg()->Float("LUMI"));     
	
	/// Cuts
	evt->Set("MINJETPT"        , (float) evt->Cfg()->Float("MINJETPT"));
	evt->Set("MAXJETETA"       , (float) evt->Cfg()->Float("MAXJETETA"));
	evt->Set("MINFATJETPT"     , (float) evt->Cfg()->Float("MINFATJETPT"));
	evt->Set("MAXFATJETETA"    , (float) evt->Cfg()->Float("MAXFATJETETA"));
	evt->Set("MINJETJVF"       , (float) evt->Cfg()->Float("MINJETJVF"));
	evt->Set("MAXJETTRKJETDR"  , (float) evt->Cfg()->Float("MAXJETTRKJETDR"));
	evt->Set("MAXTRUTHJETDR"   , (float) evt->Cfg()->Float("MAXTRUTHJETDR"));
	
	evt->Set("NStdJetCut"      , (int)   evt->Cfg()->Float("NStdJetCut"));
	evt->Set("LowMassCRcut"    , (float) evt->Cfg()->Float("LowMassCRcut"));
	evt->Set("ThreeBodyCRcut"  , (float) evt->Cfg()->Float("ThreeBodyCRcut"));
	evt->Set("y12CRcut"        , (float) evt->Cfg()->Float("y12CRcut"));
	
	/// Bad jet definitions
	///   NOTE: we're using the SAME jet type as used to 
	///         reject anomalous JX events in EventBuilder
	TString badJetType = evt->Cfg()->String("BADJETTYPE");
	TString badJetDef  = evt->Cfg()->String("BADJETDEF");
	evt->Set("BadJetType" , badJetType);
	evt->Set("BadJetDef"  , badJetDef);

    /// Determine if this is Monte Carlo or not 
    /// by looking for the process ID = mc_channel_number
    static const BranchKey bmc_channel_number("mc_channel_number");
    if(BranchNames().find(bmc_channel_number)!=BranchNames().end()) {
      evt->Set(mChannelNumber,(int)Get<UInt_t>(bmc_channel_number));
      evt->Set(misMC,true);	
    }
    else {
      evt->Set(misMC,          false);	
      evt->Set(mChannelNumber, 0);
    }
    
    if (evt->Debug()) cout << "EventBuilder_GRJETSv11::CopyEvent(): DEBUG Set event level quantities" << endl;

    /// Get the highest pT Anti-kT R=0.4 jet to reject ridiculous events  
    ///   NOTE: we're using the SAME jet type as used to determine bad events.
    ///         this is set inside the analysis in WorkerBegin
    /// This is the 2011 recommendation; slightly below find the 2012 version
    float maxpt4 = 0.;
    int chan = evt->Int(mChannelNumber);

    if (Get<vector<float> >("jet_" + badJetType + "_pt").size() > 0) 
      maxpt4 = Get<vector<float> >("jet_" + badJetType + "_pt").at(0)/1000;   

    if( (chan == 105009 && maxpt4 > 0)    || 
        (chan == 105010 && maxpt4 > 120)  || 
        (chan == 105011 && maxpt4 > 140)  ||
        (chan == 105012 && maxpt4 > 240)  ||
        (chan == 105013 && maxpt4 > 440)  ||
        (chan == 105014 && maxpt4 > 800)  ||
        (chan == 105015 && maxpt4 > 1300) ||
        (chan == 105016 && maxpt4 > 2400) 
      ) {

      if(evt->Debug()) cout << "EventBuilder_GRJETSv11::CopyEvent(): DEBUG MC event with high-pt pileup jet! Killing event!" << endl;
      
      return kFALSE;
    }

    /// 2012 rejection of bad pileup events in JZXW
    /// Note that this always uses antikt4lctopo jets: this is probably fine however
    if(chan >= 147910 && chan <= 147917){
      bool status = true;
      if(Get<vector<float> >("jet_AntiKt4LCTopo_pt").size() == 0 || Get<vector<float> >("jet_AntiKt4LCTopo_pt").size() == 1 || Get<vector<float> >("jet_AntiKt4Truth_pt").size() == 0){
        status = true;
      }
      else{ // we use the average of the leading 2 jets; this is from jim lacey's 2012 jet studies twiki
        float ptave = (Get<vector<float> >("jet_AntiKt4LCTopo_pt").at(0)/1000. + Get<vector<float> >("jet_AntiKt4LCTopo_pt").at(1)/1000.)/2.;
        float pttrue = (Get<vector<float> >("jet_AntiKt4Truth_pt").at(0)/1000.);

        if(ptave/pttrue > 0.6 && ptave/pttrue < 1.4)
          status = true;
        else
          status = false;
      }
      if(!status){
        if(fEvt->Debug()) cout << "found and killed a bad jet!" << endl;
        return kFALSE;
      }
    }



    if (evt->Debug()) cout << "EventBuilder_GRJETSv11::CopyEvent(): DEBUG Killed high-pt pileup jets" << endl;
  }
  
  ///=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
  /// BASIC OPTIONS: DEFAULT
  ///=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
  else {
    
    if (evt->Debug()) cout << "EventBuilder_GRJETSv11::CopyEvent(): DEBUG doBasic = false. Setting event level quantities to 1" << endl;
    
    evt->Set(misMC            , true); //if basic is off, we're almost certainly in MC only mode
    evt->Set("RunNumber"      , 1);
    evt->Set("EventNumber"    , 1);
    evt->Set("ChannelNumber"  , (int) evt->Cfg()->Int("CHANNEL"));
    evt->Set("grl"            , 1);
    evt->Set("mcweight"       , Get<vector<vector<double > > >("mcevt_weight").at(0).at(0));
    
    if(evt->Debug()) cout << "EventBuilder_GRJETSv11::CopyEvent(): DEBUG doBasic = false. Parameters set" << endl;
  }
 

  ///=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
  /// BUILD EVENT
  ///=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
  bool fail = true;
  
  if(evt->Debug()) cout <<"About to build the full event" << endl;
  
  fail = fail && CopyClusters();
  fail = fail && CopyVertices();
  fail = fail && CopyTracks();
  fail = fail && CopyTruthFull();
  fail = fail && AddTruthLinks();
  fail = fail && CopyPhotons();
  fail = fail && CopyElectrons();
  fail = fail && CopyMuons();
  fail = fail && CopyJets();
  
  fail = fail && AddTrackingInfo();
  fail = fail && AddTruthJetLinks();
  fail = fail && AddParentLinks();
  fail = fail && AddConstituents();
  fail = fail && AddBadJetType();
  fail = fail && AddTriggers();

  fail = fail && CopySubjets();
  fail = fail && AddBtags();

  /// The above need to be sorted by pt, Truth done by E	
  evt->SortPtAll(); 

  // if (evt->Debug()) cout << "EventBuilder_GRJETSv11::CopyEvent(): DEBUG Careful with the CustomSetup" << endl;
  // fail = fail && DoCustomSetup();

  if (evt->Debug()) cout << "EventBuilder_GRJETSv11::CopyEvent(): DEBUG Done! Status = " << fail << endl;
  return kTRUE;
}

///=========================================
/// CopyTruthFull
///=========================================
Bool_t EventBuilder_GRJETSv11::CopyTruthFull()
{
  
  if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11: DEBUG CopyTruthFull()  " << endl;	
  
  /// If scheduled, set the truth particles
  if(fEvt->isMC() && doTruth) {
    
    fEvt->AddVec("truths");
    
    for (int i = 0; i< Get<Int_t>("mc_n"); i++) {

      Particle * mc = new Particle();
      float pt  = Get<vector<float> >("mc_pt") .at(i);
      float eta = Get<vector<float> >("mc_eta").at(i);
      float phi = Get<vector<float> >("mc_phi").at(i);
      float m   = Get<vector<float> >("mc_m")  .at(i);
      mc->p.SetPtEtaPhiM(pt/1000., eta, phi, m/1000.);
      mc->Set("index",i);      
      mc->Set("mc_pdgId",  Get<vector<int> >("mc_pdgId") .at(i)); 
      mc->Set("mc_status", Get<vector<int> >("mc_status").at(i)); 
      mc->Set("mc_charge", Get<vector<float> >("mc_charge").at(i));
      mc->Set("mc_barcode", Get<vector<int> >("mc_barcode").at(i));

      fEvt->Add("truths",mc);
    }
  }
  
  if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11::CopyTruthFull(): DEBUG Scheduled Truth Particles" << endl;
  return kTRUE;
}


///=========================================
/// AddTruthLinks
///=========================================
Bool_t EventBuilder_GRJETSv11::AddTruthLinks()
{

  if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11: DEBUG In AddTruthLinks() " << endl;	  
  if (doTruthLinks && fEvt->isMC()){
    
    if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11::AddTruthLinks(): DEBUG Adding parents and children for N = " << fEvt->truths() << endl;
    
    for(int iTr = 0; iTr < fEvt->truths(); iTr++){
      vector<int> mc_parents  = Get<vector<vector<int> > >("mc_parent_index").at(iTr);
      vector<int> mc_children = Get<vector<vector<int> > >("mc_child_index").at(iTr);
  
      fEvt->truth(iTr).AddVec("mc_parents");
      fEvt->truth(iTr).AddVec("mc_children", true);

      if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11::AddTruthLinks(): DEBUG Adding parents Nparents = " << mc_parents.size() << endl;

      for(unsigned int iP = 0; iP < mc_parents.size(); iP++){
        if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11::AddTruthLinks(): DEBUG Parent #" << iP << "; index = " << mc_parents.at(iP) << endl;
        fEvt->truth(iTr).Add("mc_parents", &fEvt->truth(mc_parents.at(iP))); 
      }    
      
      if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11::AddTruthLinks(): DEBUG Adding children Nchildren = " << mc_children.size() << endl;
      
      for(unsigned int iC = 0; iC < mc_children.size(); iC++){
        if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11::AddTruthLinks(): DEBUG Child #" << iC << "; index = " << mc_children.at(iC) << endl;
        fEvt->truth(iTr).Add("mc_children", &fEvt->truth(mc_children.at(iC))); 
      }    
      
      if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11::AddTruthLinks(): DEBUG Done with truth particle index = " << iTr << endl;
      
    }    

  }
  if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11::AddTruthLinks(): DEBUG Scheduled Truth Links" << endl;
  return kTRUE;
}

///=========================================
/// AddBtags
///=========================================
Bool_t EventBuilder_GRJETSv11::AddBtags() 
{

  if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11: DEBUG In AddBtags() " << endl;   
  bool fail = true;
  /// Copy all jet types
  for(Int_t i = 0; i<fEvt->Cfg()->Objs(mBTAGVEC); ++i) {
    TString type = ((TObjString*)fEvt->Cfg()->Obj(mBTAGVEC,i))->GetString();
    if (type.Contains("Truth")) continue; 
    if(fEvt->Debug()) cout << "EventBuilder_GRJETSv11::AddBtags(): DEBUG Copying btag type " << type << " which is the " << i << "th jet collection" << endl;
    if(fEvt->Debug()) cout << "EventBuilder_GRJETSv11::AddBtagss(): DEBUG type in vec is " << ((TObjString*) fEvt->Cfg()->Obj(mBTAGVEC,i))->GetString() << endl;
    fail = fail && AddBtag(type,"");
  }
  
  if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11::AddBtags(): DEBUG Scheduled All Jet B-tags" << endl;
  return fail;
}

///=========================================
/// AddBtag
///=========================================
Bool_t EventBuilder_GRJETSv11::AddBtag(TString jetType, TString jetClass) 
{

  if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11: DEBUG In AddBtag() for jetType = " << jetType << "; jetClass = " << jetClass << endl;  
  
  // Handle the case where this is called without an argument
  if (jetType == "") { 
    Abort("EventBuilder_GRJETSv11::AddBtag(): ERROR No jet type selected. Aborting!");
  }
  
  // Now try to figure out what type of jet this is
  if (jetClass == "") {
    if (fEvt->Debug()) {
      cout << "EventBuilder_GRJETSv11::AddBtag(): INFO The jetClass variable is empty. ";
      cout << "Assuming that the class (truth, track, topo, etc) can be determined from the name." << endl;
    } // END IF
    
    // Parse the jetType: truth, track, topo
    if (jetType.Contains("Truth")) {
     
      cout << "EventBuilder_GRJETSv11::AddBtag(): ERROR Cannot add B-tagging for Truth jet collections!" << endl;
      return kFALSE;
    
    }
    else if (jetType.Contains("Track"))  jetClass = "track";
    else if (jetType.Contains("LCTopo")) jetClass = "topo";
    else if (jetType.Contains("TopoEM")) jetClass = "topo";
    else if (jetType.Contains("Tower"))  {
      cout << "EventBuilder_GRJETSv11::AddBtag(): ERROR Tower jets are not currently supported." << endl;
      return kFALSE;
    } // END IF
    
  } // END IF JET CLASS 
  
  // Otherwise, try to figure out what class of jet this really is
  else if (jetClass != "topo" && jetClass != "track") {
    cout << "EventBuilder_GRJETSv11::AddBtag(): ERROR Currently, the only supported classes of jets are: truth, track, topo." << endl;
    return kFALSE;
  }
  
  // Collect jet flavor information
  for(unsigned int iJet = 0; iJet < Get<vector<float> >("jet_" + jetType + "_phi").size(); iJet++){
  
  // get the pointer to the jet already created
  Particle* jet = &fEvt->jet(iJet,jetType);  
  /// Spit out some useful information about this jet
  if (fEvt->Debug()) {
    cout << "EventBuilder_GRJETSv11::AddBtag(): DEBUG ";
    TString info = 
    TString::Format("Jet %d: (E, Et, m, eta, phi) = (%1.2f, %1.2f, %1.2f, %1.2f, %1.2f)",
            iJet, 
            jet->p.E(),jet->p.Et(),jet->p.M(),jet->p.Eta(),jet->p.Phi()
          );
   
    cout << info << endl;
  }
    
    jet->Set("flavor_weight_Comb",                   Get<vector<float> >("jet_" + jetType + "_flavor_weight_Comb")                  .at(iJet));
    jet->Set("flavor_weight_IP2D",                   Get<vector<float> >("jet_" + jetType + "_flavor_weight_IP2D")                  .at(iJet));
    jet->Set("flavor_weight_IP3D",                   Get<vector<float> >("jet_" + jetType + "_flavor_weight_IP3D")                  .at(iJet));
    jet->Set("flavor_weight_SV0",                    Get<vector<float> >("jet_" + jetType + "_flavor_weight_SV0")                   .at(iJet));
    jet->Set("flavor_weight_SV1",                    Get<vector<float> >("jet_" + jetType + "_flavor_weight_SV1")                   .at(iJet));
    jet->Set("flavor_weight_SV2",                    Get<vector<float> >("jet_" + jetType + "_flavor_weight_SV2")                   .at(iJet));
    jet->Set("flavor_weight_JetFitterTagNN",         Get<vector<float> >("jet_" + jetType + "_flavor_weight_JetFitterTagNN")        .at(iJet));
    jet->Set("flavor_weight_JetFitterCOMBNN",        Get<vector<float> >("jet_" + jetType + "_flavor_weight_JetFitterCOMBNN")       .at(iJet));
    jet->Set("flavor_weight_MV1",                    Get<vector<float> >("jet_" + jetType + "_flavor_weight_MV1")                   .at(iJet));
    jet->Set("flavor_weight_MV2",                    Get<vector<float> >("jet_" + jetType + "_flavor_weight_MV2")                   .at(iJet));


    if(fEvt->isMC()){
      jet->Set("flavor_truth_label",                 Get<vector<int> >  ("jet_" + jetType + "_flavor_truth_label")                  .at(iJet));
    }
  
  } // END FOR LOOP
  
  if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11::AddBtag(): DEBUG Scheduled b-tags for jet collection = " << jetType << " with " << fEvt->jets(jetType) << " jets" << endl;
  return kTRUE;  
  
} // END AddBtag


///=========================================
/// CopyJets
///=========================================
Bool_t EventBuilder_GRJETSv11::CopyJets() 
{

  if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11: DEBUG In CopyJets() " << endl;	  

  bool fail       = true;
  TString jetType = "";
  
  /// Copy all jet types
  for(Int_t i = 0; i<fEvt->Cfg()->Objs(mJETTYPEVEC); ++i) {
    TString type = ((TObjString*)fEvt->Cfg()->Obj(mJETTYPEVEC,i))->GetString();
    if (type.Contains("Truth") && !fEvt->isMC()) continue; 
    if(fEvt->Debug()) cout << "EventBuilder_GRJETSv11::CopyJets(): DEBUG Copying jet type " << type << " which is the " << i << "th jet collection" << endl;
    if(fEvt->Debug()) cout << "EventBuilder_GRJETSv11::CopyJets(): DEBUG type in vec is " << ((TObjString*) fEvt->Cfg()->Obj(mJETTYPEVEC,i))->GetString() << endl;
    fail = fail && CopyJet(type,"");
    //Float_t HT = fEvt->ht(type, fEvt->Int("NStdJetCut"));
    //fEvt->Set("EventHT", HT);
  }
  
  if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11::CopyJets(): DEBUG Scheduled All Jets" << endl;
  return fail;
}

///=========================================
/// CopySubjets
///=========================================
Bool_t EventBuilder_GRJETSv11::CopySubjets()
{
  if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11: DEBUG In CopySubjets(), mSUBJETTYPEVEC =  " << mSUBJETTYPEVEC << endl;   

  bool fail       = true;
  TString jetType = "";
  
  if(!doSubjets){
    if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11::CopySubjets(): DEBUG No subjets scheduled" << endl;
    return false;
  }
  /// Copy all subjet types
  for(Int_t i = 0; i<fEvt->Cfg()->Objs(mSUBJETTYPEVEC); ++i) {
    TString type = ((TObjString*)fEvt->Cfg()->Obj(mSUBJETTYPEVEC,i))->GetString();
    if (type.Contains("Truth") && !fEvt->isMC()) continue; 


    if(fEvt->Debug()) cout << "EventBuilder_GRJETSv11::CopySubjets(): DEBUG Copying jet type " << type << " which is the " << i << "th jet collection" << endl;
    if(fEvt->Debug()) cout << "EventBuilder_GRJETSv11::CopySubjets(): DEBUG type in vec is " << ((TObjString*) fEvt->Cfg()->Obj(mJETTYPEVEC,i))->GetString() << endl;
    fail = fail && CopyJet(type,"");

    // need to parse to get parents, links set up
    TString parentType = type;
    parentType.ReplaceAll("Subjets","");

    TString groomType;
    TObjArray* tempArr;
    if(parentType.Contains("Trimmed")){
      tempArr = TPRegexp(".*Trimmed(.*)$").MatchS(parentType);
    }


    groomType = ((TObjString *)tempArr->At(1))->GetString();
    delete tempArr;

    if(fEvt->Debug()) cout << "EventBuilder_GRJETSv11::CopySubjets(): DEBUG Setting up links between parent " << parentType << " with number " << fEvt->jets(parentType) << endl;
    for(int iJet = 0; iJet < fEvt->jets(parentType); iJet++){
      if(fEvt->Debug()) cout << "EventBuilder_GRJETSv11::CopySubjets(): DEBUG Setting up links for parent jet " << iJet << endl;
      vector<int> subjet_parent_index = Get<vector<vector<int> > >("jet_"+parentType+"_TrimmedSubjets"+groomType+"_index").at(iJet);

      if(fEvt->Debug()) cout << "EventBuilder_GRJETSv11::CopySubjets(): " << subjet_parent_index.size() << " from D3PD  and " << fEvt->jets(type) << " already loaded!" <<endl;
      fEvt->jet(iJet,parentType).AddVec("Subjets");
      for(int iSub = 0; iSub< subjet_parent_index.size(); iSub++){
        fEvt->jet(iJet,parentType).Add("Subjets",&fEvt->jet(subjet_parent_index.at(iSub),type));

        fEvt->jet(iSub,type).AddVec("Parent");
        fEvt->jet(iSub,type).Add("Parent",&fEvt->jet(iJet,parentType));
      }
    }
  }
  


  if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11::CopySubjets(): DEBUG Scheduled All Subjets" << endl;
  return fail;


}

///=========================================
/// CopyJet
///=========================================
Bool_t EventBuilder_GRJETSv11::CopyJet(TString jetType, TString jetClass) 
{

  ///-------------------
  /// PREAMBLE
  ///-------------------
  if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11: DEBUG In CopyJet() for jetType = " << jetType << "; jetClass = " << jetClass << endl;	
  
  // Handle the case where this is called without an argument
  if (jetType == "") { 
    Abort("EventBuilder_GRJETSv11::CopyJet(): ERROR No jet type selected. Aborting!");
  }
  
  ///-------------------
  /// JET TYPE
  ///-------------------
  // Now try to figure out what type of jet this is
  if (jetClass == "") {
    if (fEvt->Debug()) {
      cout << "EventBuilder_GRJETSv11::CopyJet(): INFO The jetClass variable is empty. ";
      cout << "Assuming that the class (truth, track, topo, etc) can be determined from the name." << endl;
    } // END IF
    
    // Parse the jetType: truth, track, topo
    if (jetType.Contains("Truth")) {
      if (fEvt->isMC()) jetClass = "truth";
      else { 
        cout << "EventBuilder_GRJETSv11::CopyJet(): ERROR This is not MC and you have requested truth jets. Reconfigure analysis and run again!." << endl;
        return kFALSE;
      }
    }
    else if (jetType.Contains("Track"))  jetClass = "track";
    else if (jetType.Contains("LCTopo")) jetClass = "topo";
    else if (jetType.Contains("TopoEM")) jetClass = "topo";
    else if (jetType.Contains("Tower"))  {
      cout << "EventBuilder_GRJETSv11::CopyJet(): ERROR Tower jets are not currently supported." << endl;
      return kFALSE;
    } // END IF
    
  } // END IF JET CLASS 
  
  // Otherwise, try to figure out what class of jet this really is
  else if (jetClass != "truth" && jetClass != "topo" && jetClass != "track") {
    cout << "EventBuilder_GRJETSv11::CopyJet(): ERROR Currently, the only supported classes of jets are: truth, track, topo." << endl;
    return kFALSE;
  }
 
  if(fEvt->Debug()) cout << "have jet class " << jetClass << endl;
   
  ///-------------------
  /// COPY JETS
  ///-------------------
  // Collect jet information
  fEvt->AddVec("jets" + jetType);
  for (unsigned int iJet = 0; iJet < Get<vector<float> >("jet_" + jetType + "_phi").size(); iJet++) {
	
	/// Get Basic kinematics

	float pt; 
	float eta; 
	float phi; 
	float m;  
	
  if(jetType.Contains("LCTopo") || jetType.Contains("EM")){
    pt = Get<vector<float> >("jet_" + jetType + "_constscale_pt")  .at(iJet);
    eta =Get<vector<float> >("jet_" + jetType + "_constscale_eta") .at(iJet);
    phi =Get<vector<float> >("jet_" + jetType + "_constscale_phi") .at(iJet);
    m  = Get<vector<float> >("jet_" + jetType + "_constscale_m")   .at(iJet);
  }
  else{
    pt = Get<vector<float> >("jet_" + jetType + "_pt")  .at(iJet);
    eta= Get<vector<float> >("jet_" + jetType + "_eta") .at(iJet);
    phi= Get<vector<float> >("jet_" + jetType + "_phi") .at(iJet);
    m  = Get<vector<float> >("jet_" + jetType + "_m")   .at(iJet);
  }

	/// Apply the basic kinematic selections
	//if ( (pt/1000. < fEvt->Float("MINFATJETPT")) || (fabs(eta) > fEvt->Float("MAXFATJETETA")) ) continue;
 
    /// Set Basic kinematics
	Particle* jet = new Particle();
	jet->p.SetPtEtaPhiM(pt/1000., eta, phi, m/1000.);
		
	/// Spit out some useful information about this jet
	if (fEvt->Debug()) {
	  cout << "EventBuilder_GRJETSv11::CopyJet(): DEBUG ";
	  TString info = 
	  TString::Format("Jet %d: (E, Et, m, eta, phi) = (%1.2f, %1.2f, %1.2f, %1.2f, %1.2f)",
					  iJet, jet->p.E(), jet->p.Et(), jet->p.M(), jet->p.Eta(), jet->p.Phi() );
   
	  cout << info << endl;
	}
	
	// Set substructure and shape observables for all jets
	if (doJetStructure) {
		
		Double_t tau1 = Get<vector<float> >("jet_" + jetType + "_Tau1").at(iJet);
		Double_t tau2 = Get<vector<float> >("jet_" + jetType + "_Tau2").at(iJet);
		Double_t tau3 = Get<vector<float> >("jet_" + jetType + "_Tau3").at(iJet);
		
		jet->Set("tau21",        tau1 > 0 ? tau2/tau1 : -1.);
		jet->Set("tau32",        tau2 > 0 ? tau3/tau2 : -1.);
		jet->Set("width",        Get<vector<float> >("jet_" + jetType + "_WIDTH")       .at(iJet));
		jet->Set("split12",      Get<vector<float> >("jet_" + jetType + "_SPLIT12")     .at(iJet)/1000.);
		jet->Set("split23",      Get<vector<float> >("jet_" + jetType + "_SPLIT23")     .at(iJet)/1000.);
		jet->Set("split34",      Get<vector<float> >("jet_" + jetType + "_SPLIT34")     .at(iJet)/1000.);
		jet->Set("zcut12",       Get<vector<float> >("jet_" + jetType + "_ZCUT12")      .at(iJet));
		jet->Set("zcut23",       Get<vector<float> >("jet_" + jetType + "_ZCUT23")      .at(iJet));
		jet->Set("zcut34",       Get<vector<float> >("jet_" + jetType + "_ZCUT34")      .at(iJet));
		jet->Set("dip12",        Get<vector<float> >("jet_" + jetType + "_Dip12")       .at(iJet));
		jet->Set("dip13",        Get<vector<float> >("jet_" + jetType + "_Dip13")       .at(iJet));
		jet->Set("dip23",        Get<vector<float> >("jet_" + jetType + "_Dip23")       .at(iJet));
		jet->Set("dipExcl12",    Get<vector<float> >("jet_" + jetType + "_DipExcl12")   .at(iJet));
		jet->Set("ActiveArea",   Get<vector<float> >("jet_" + jetType + "_ActiveArea")  .at(iJet));
    jet->Set("ActiveArea_px",Get<vector<float> >("jet_" + jetType + "_ActiveArea_px").at(iJet));
    jet->Set("ActiveArea_py",Get<vector<float> >("jet_" + jetType + "_ActiveArea_py").at(iJet));
    jet->Set("ActiveArea_pz",Get<vector<float> >("jet_" + jetType + "_ActiveArea_pz").at(iJet));
    jet->Set("ActiveArea_e", Get<vector<float> >("jet_" + jetType + "_ActiveArea_e") .at(iJet));
		jet->Set("VoronoiArea",  Get<vector<float> >("jet_" + jetType + "_VoronoiArea") .at(iJet));
		
    } // ENDIF doJetStructure    
    
	// Handle reconstructed jets
	if (jetClass == "topo" ) {
    if(fEvt->Debug()) cout << "set topo type!" << endl;
	  jet->Set("ptConstScale", Get<vector<float> >("jet_" + jetType + "_constscale_pt").at(iJet)/1000.);
	  jet->Set("mConstScale",  Get<vector<float> >("jet_" + jetType + "_constscale_m").at(iJet)/1000.);
	  
	  // Deal with groomed jets
	  if (!jetType.Contains("Trimmed") && !jetType.Contains("Pruned") && !jetType.Contains("Filtered")) {
	  	jet->Set("JVF",Get<vector<float> >("jet_" + jetType + "_jvtxf").at(iJet));	
	  }
	  
	  // Cleaning information is only present for AKT4 jets
	  if (jetType.Contains("AntiKt4") && jetType.Contains("AOD")) {
	    jet->Set("isUgly",          Get<vector<UInt_t> >("jet_" + jetType + "_isUgly")         .at(iJet));
		jet->Set("isBadLoose",      Get<vector<UInt_t> >("jet_" + jetType + "_isBadLoose")     .at(iJet));
		jet->Set("isBadLooseMinus", Get<vector<Int_t> >("jet_" + jetType + "_isBadLooseMinus").at(iJet));
	  } // ENDIF AntiKt4
	  
	} // ENDIF topo
	
	// Handle track jets
	else if ( (jetClass == "track") && !jetType.Contains("Trimmed") && !jetType.Contains("Pruned") && !jetType.Contains("Filtered") ) { 
	  jet->Set("ZOrigin",           Get<vector<float> >("jet_" + jetType + "_jvtx_z")          .at(iJet));
	}
	
    // Handle truth jets
	else if (jetClass == "truth" ) { /* Nothing to do */ }
	
	// Add the jet to the event
	fEvt->Add("jets" + jetType , jet);
  
  } // END FOR LOOP
  
  if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11::CopyJet(): DEBUG Scheduled jet collection = " << jetType << " with " << fEvt->jets(jetType) << " jets" << endl;
  return kTRUE;  
  
} // END CopyJet

///=========================================
/// AddTrackingInfo
///=========================================
Bool_t EventBuilder_GRJETSv11::AddTrackingInfo()
{

  if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11: DEBUG In AddTrackingInfo() " << endl;	

  if (!doTrackJetLinks && !doTrack) return kTRUE;

  /// Add tracking info and track-jet links to reconstructed jets
  for(Int_t i = 0; i<fEvt->Cfg()->Objs(mJETTYPEVEC); ++i) {
	  
    TString type(((TObjString*)fEvt->Cfg()->Obj(mJETTYPEVEC,i))->GetString()); 
    
    if (type.Contains("Truth") && !fEvt->isMC()) continue;   

    /// Track-jet links
    if (doTrackJetLinks && type.Contains("Topo")) AddTrackJetLink(type);
    
    /// Tracking information
    if (doTrack && type.Contains("Topo")) AddTrackInJetInfo(type);
	
  }
  
  if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11::AddTrackingInfo(): DEBUG Scheduled track-jet-to-jet links" << endl;
  return kTRUE;
}

///=========================================
/// AddTrackJetLink
///=========================================
Bool_t EventBuilder_GRJETSv11::AddTrackJetLink(TString recoType)
{

  if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11: DEBUG In AddTrackJetLink() for type = " << recoType << endl;	
 
  if (!recoType.Contains("Topo")) return kFALSE;   
 
  /// Convert the reco jet name to the track-jet name
  TString trackJetType = recoType;
  trackJetType.ReplaceAll("LCTopo","TrackZ");
  if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11::AddTrackJetLink(): DEBUG Matching with track jet type = " << trackJetType << endl;	
  
  /// Loop on reco jets, match to track jets, and save the match
  for(int jetItr = 0; jetItr < fEvt->jets(recoType); jetItr++) {
        
    Int_t trackMatchIndex = -1;
    Double_t minDeltaR = 100000.;
    for (int tjItr = 0; tjItr < fEvt->jets(trackJetType); tjItr++) {
      Double_t deltaR = fEvt->jet(jetItr, recoType).p.DeltaR( fEvt->jet(tjItr, trackJetType).p );
      if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11::AddTrackJetLink(): DEBUG DR to trackjet index = " << tjItr << " -> " << deltaR << endl;
      if (deltaR < minDeltaR) {
        minDeltaR = deltaR;
        trackMatchIndex = tjItr;
      }
    }
    
    /// Say hello
    if (fEvt->Debug()) {
      if (trackMatchIndex >= 0) cout << "EventBuilder_GRJETSv11::AddTrackJetLink(): DEBUG Found a matching track jet, index = " << trackMatchIndex 
                                     << "; DR = " << minDeltaR << "; pT = " << fEvt->jet(trackMatchIndex, trackJetType).p.Pt() << endl;	
      else cout << "EventBuilder_GRJETSv11::AddTrackJetLink(): DEBUG Didn't find any matching track jets" << endl;
    }
    
    /// Add this track jet match to the reco jet
    if (trackMatchIndex >= 0) { 
      fEvt->jet(jetItr, recoType).AddVec("trackJetMatch");
      fEvt->jet(jetItr, recoType).Add("trackJetMatch", &fEvt->jet(trackMatchIndex, trackJetType));
      fEvt->jet(jetItr, recoType).Set("trackJetDR", minDeltaR);
    }
  }
  
  if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11::AddTrackJetLink(): Scheduled track-jet-to-jet links" << endl;
  return kTRUE;
}

///=========================================
/// AddTrackInJetInfo
///=========================================
Bool_t EventBuilder_GRJETSv11::AddTrackInJetInfo(TString recoType)
{

  if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11: DEBUG In AddTrackInJetInfo() for type = " << recoType << endl;	
 
  if (recoType.Contains("Truth") && !fEvt->isMC()) return kFALSE;;   
 
  /// Loop on reco jets, match to track jets, and save the match
  for(int jetItr = 0; jetItr < fEvt->jets(recoType); jetItr++) {
    
    /// Set the matching radius
	float jetRad = 0.;
	if (recoType.Contains("10"))
	  jetRad=1.0;
	else if (recoType.Contains("12"))
	  jetRad=1.2;
	else if (recoType.Contains("4"))
	  jetRad=0.4; 
	else if (recoType.Contains("6"))
	  jetRad=0.6; 
    else if (recoType.Contains("8"))
      jetRad=0.8; 

	/// Initialize the variables:
	Int_t    nTrk     = 0;
	Double_t sumPtTrk = 0.0;
	Double_t trkDR12  = -1.;
	
	Particle* trk1 = new Particle(); trk1->p.SetPtEtaPhiE(0.000001,0.,0.,0.000001);
	Particle* trk2 = new Particle(); trk2->p.SetPtEtaPhiE(0.000001,0.,0.,0.000001);
    
    /// Loop over tracks
    if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11::AddTrackInJetInfo(): DEBUG About to loop over tracks" << endl;	
	for(int iTr = 0; iTr < fEvt->tracks(); iTr++) {
	  
	  /// Pass tracking selections
           if  (fEvt->track(iTr).p.Pt()          < 0.500) continue;
      else if  (fEvt->track(iTr).Int("nPixHits") < 1)     continue;
      else if  (fEvt->track(iTr).Int("nSCTHits") < 6)     continue;
      else if  (fEvt->track(iTr).Float("d0")     > 1.0)   continue;
      else if ((fEvt->track(iTr).Float("z0"))*(TMath::Sin(fEvt->track(iTr).Float("theta"))) > 1.0) continue;
	  
	  /// Test for a match
	  if (fEvt->jet(jetItr, recoType).p.DeltaR(fEvt->track(iTr).p) > jetRad) continue;
	  if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11::AddTrackInJetInfo(): DEBUG Track matched! DR = " << fEvt->jet(jetItr, recoType).p.DeltaR(fEvt->track(iTr).p) << endl;	
	  
	  /// Keep track of Number and Sum of PT
	  nTrk++;
	  sumPtTrk += fEvt->track(iTr).p.Pt();
	  
	  /// Find leading two tracks
	  if (fEvt->track(iTr).p.Pt() > trk2->p.Pt()) {
	    if (fEvt->track(iTr).p.Pt() > trk1->p.Pt()) {
	      trk2->p.SetPtEtaPhiE(trk1->p.Pt(), trk1->p.Eta(), trk1->p.Phi(), trk1->p.E());
	      trk1->p.SetPtEtaPhiE(fEvt->track(iTr).p.Pt(), fEvt->track(iTr).p.Eta(), fEvt->track(iTr).p.Phi(), fEvt->track(iTr).p.E());
	    }
	    else trk2->p.SetPtEtaPhiE(fEvt->track(iTr).p.Pt(), fEvt->track(iTr).p.Eta(), fEvt->track(iTr).p.Phi(), fEvt->track(iTr).p.E());
	  }
	}
	
	/// Calculate DR between leading two tracks
	if ( (trk2->p.Pt() > 0.4) && (trk1->p.Pt() > 0.4)) trkDR12 = trk1->p.DeltaR(trk2->p);
  
    if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11::AddTrackInJetInfo(): DEBUG Jet #" << jetItr
                            << "; nTrk = " << nTrk
                            << "; trkPt1 = " << trk1->p.Pt()
                            << "; sumPtTrk = " << sumPtTrk
                            << "; trkDR12 = " << trkDR12
                            << endl;	
  
    /// Set the track properties of this jet
    fEvt->jet(jetItr,recoType).Set("nTrk"     , nTrk);
    fEvt->jet(jetItr,recoType).Set("trkPt1"   , trk1->p.Pt());
    fEvt->jet(jetItr,recoType).Set("sumPtTrk" , sumPtTrk);
    fEvt->jet(jetItr,recoType).Set("trkDR12"  , trkDR12);

    delete trk1;
    delete trk2;

  }
  
  if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11::AddTrackInJetInfo(): Scheduled track-jet-to-jet links" << endl;
  return kTRUE;
}

///=========================================
/// AddTruthJetLinks
///=========================================
Bool_t EventBuilder_GRJETSv11::AddTruthJetLinks()
{

  if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11: DEBUG In AddTruthJetLinks() " << endl;	

  /// If scheduled, loop on jet types and configure parent-to-groomed jet link
  if (doTruthJetLinks)  {
	for(Int_t i = 0; i<fEvt->Cfg()->Objs(mJETTYPEVEC); ++i) {
	 
	  TString type(((TObjString*)fEvt->Cfg()->Obj(mJETTYPEVEC,i))->GetString());
	  
	  if (type.Contains("Topo") && fEvt->isMC()) AddTruthJetLink(type);    
	  
	}
  }
  
  if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11::AddTruthJetLinks(): Scheduled truth-jet-to-reco-jet links" << endl;
  return kTRUE;
}

///=========================================
/// AddTruthJetLink
///=========================================
Bool_t EventBuilder_GRJETSv11::AddTruthJetLink(TString recoType)
{

  if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11: DEBUG In AddTruthJetLink() for type = " << recoType << endl;	
 
  if (!recoType.Contains("Topo") || !fEvt->isMC()) return kFALSE;   
 
  /// Convert the reco jet name to the truth-jet name
  TString truthJetType = recoType;
  truthJetType.ReplaceAll("LCTopo","Truth");
  if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11::AddTruthJetLink(): DEBUG Matching with truth jet type = " << truthJetType << endl;	
  
  /// Loop on reco jets, match to truth jets, and save the match
  for(int jetItr = 0; jetItr < fEvt->jets(recoType); jetItr++) {
        
    Int_t truthMatchIndex = -1;
    Double_t minDeltaR = 100000.;
    for (int truthItr = 0; truthItr < fEvt->jets(truthJetType); truthItr++) {
      Double_t deltaR = fEvt->jet(jetItr, recoType).p.DeltaR( fEvt->jet(truthItr, truthJetType).p );
      if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11::AddTruthJetLink(): DEBUG DR to truth jet index = " << truthItr << " -> " << deltaR << endl;
      if (deltaR < minDeltaR) {
        minDeltaR = deltaR;
        truthMatchIndex = truthItr;
      }
    }
    
    /// Say hello
    if (fEvt->Debug()) {
      if (truthMatchIndex >= 0) cout << "EventBuilder_GRJETSv11::AddTruthJetLink(): DEBUG Found a matching truth jet, index = " << truthJetType 
                                     << "; DR = " << minDeltaR << "; pT = " << fEvt->jet(truthMatchIndex, truthJetType).p.Pt() << endl;	
      else cout << "EventBuilder_GRJETSv11::AddTruthJetLink(): DEBUG Didn't find a matching truth jet" << endl;
    }
    
    /// Add this truth jet match to the reco jet
    if (truthMatchIndex >= 0) { 
      fEvt->jet(jetItr, recoType).AddVec("truthJetMatch");
      fEvt->jet(jetItr, recoType).Add("truthJetMatch", &fEvt->jet(truthMatchIndex, truthJetType));
      fEvt->jet(jetItr, recoType).Set("truthJetDR", minDeltaR);

      fEvt->jet(jetItr, recoType).Set("truthJetPT", fEvt->jet(truthMatchIndex, truthJetType).p.Perp());
      fEvt->jet(jetItr, recoType).Set("truthJetMass", fEvt->jet(truthMatchIndex,truthJetType).p.M());
      fEvt->jet(jetItr, recoType).Set("truthJetEta", fEvt->jet(truthMatchIndex, truthJetType).p.Eta());

    }
  }
  
  if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11::AddTruthJetLink(): Scheduled truth-jet-to-jet links" << endl;
  return kTRUE;
}

///=========================================
/// AddParentLinks
///=========================================
Bool_t EventBuilder_GRJETSv11::AddParentLinks()
{

  if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11: DEBUG In AddParentLinks() " << endl;	

  /// If scheduled, loop on jet types and configure parent-to-groomed jet link
  if (doParentChild)  {
	for(Int_t i = 0; i<fEvt->Cfg()->Objs(mJETTYPEVEC); ++i) {
	 
	  TString type(((TObjString*)fEvt->Cfg()->Obj(mJETTYPEVEC,i))->GetString());
	  
	  if (type.Contains("Truth") && !fEvt->isMC()) continue; 
	  
	  AddParentLink(type);    
	}
  }
  
  if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11::AddParentLinks(): Scheduled parent-to-groomed jet links" << endl;
  return kTRUE;
}

///=========================================
/// AddParentLink
///=========================================
Bool_t EventBuilder_GRJETSv11::AddParentLink(TString parentJetType) 
{

  if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11: DEBUG In AddParentLink() for parentJetType = " << parentJetType << endl;	
  
  if (parentJetType.Contains("Truth") && !fEvt->isMC()) return kFALSE;; 
  
  if(!parentJetType.Contains("Trimmed") && !parentJetType.Contains("Pruned") && !parentJetType.Contains("Filtered")) {
    
    /// We have an ungroomed jet type. Now look through the full list again for groomed jet types
    for(int j = 0; j<fEvt->Cfg()->Objs(mJETTYPEVEC); ++j){
      
      /// Pick up the jet type
      TString groomedJetType(((TObjString*) fEvt->Cfg()->Obj(mJETTYPEVEC,j))->GetString());
      
      if (groomedJetType.Contains("Truth") && !fEvt->isMC()) continue; 

      /// Check to see if it's groomed and derives from the parent type, "jetType"
      if(groomedJetType.Contains(parentJetType) && (groomedJetType.Contains("Trimmed") || groomedJetType.Contains("Pruned") || groomedJetType.Contains("Filtered"))) {
        
        if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11::AddParentLink(): DEBUG Found groomedJetType = " << groomedJetType << " from parentJetType = " << parentJetType << endl;
        
        /// We've found a groomed jet configuration! Create a child (groomed) jet branch and setup links between parents and children (groomed jets)
        for(int iChild = 0; iChild < fEvt->jets(groomedJetType); iChild++) {
          
          if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11::AddParentLink(): DEBUG Looking at child #" << iChild << " for groomedJetType = " << groomedJetType << endl;
          
          /// Create a list of parents for this groomed jet, despite the fact that this will only be filled with a single index
          fEvt->jet(iChild, groomedJetType).AddVec("parent");
          int link = Get<vector<vector<int> > >(TString("jet_"+groomedJetType+"_Parent_index")).at(iChild).at(0);
          
          if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11::AddParentLink(): DEBUG Found the index corresponding to the ungroomed version of this jet: " << link << endl;
          
          fEvt->jet(iChild, groomedJetType).Add("parent", &fEvt->jet(link, parentJetType));
          
          /// Create a list of children (once) and then fill it with the indices of all of the groomed jets that derive from this parent jet type 
          fEvt->jet(link, parentJetType).AddVec("child_"+groomedJetType,true);
          
          if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11::AddParentLink(): DEBUG Now adding this groomed jet to the parent jet as a 'child'" << endl;
          
          fEvt->jet(link, parentJetType).Add(TString("child_"+groomedJetType), &fEvt->jet(iChild, groomedJetType));
        }
      }
    }
  }
  
  if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11::AddParentLink(): DEBUG Scheduled parent-to-groomed jet links" << endl;
  return kTRUE;
}

///=========================================
/// AddConstituents
///=========================================
Bool_t EventBuilder_GRJETSv11::AddConstituents() 
{

  if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11: DEBUG In AddConstituents() " << endl;	
  
  /// If schedule, loop on the jet types and setup the constituent links
  if (doConstituents) {
  
	for (Int_t i = 0; i<fEvt->Cfg()->Objs(mJETTYPEVEC); ++i) {
	  
	  /// Read the jet type
	  TString type(((TObjString*)fEvt->Cfg()->Obj(mJETTYPEVEC,i))->GetString());
	  TString cons = "";
	  
	  /// Parse the jetType: truth, track, topo
	  
	  /// TRUTH JETS
	  if (type.Contains("Truth")) {
		
		/// Make sure (a) this is Monte Carlo and (b) that the truth particles have actually been requested as well
		if (fEvt->isMC() && doTruth) cons = "truths";
		else if (!fEvt->isMC()) { 
		  cout << "EventBuilder_GRJETSv11::AddConstituents(): ERROR This is not MC and you have requested truth jet constituents. Reconfigure analysis and run again!." << endl;
		  return kFALSE;
		}
		else if (!doTruth && doTruthConstituents) {
		  cout << "EventBuilder_GRJETSv11::AddConstituents(): ERROR You have requested truth jet constituents yet not truth particles. Reconfigure analysis and run again!." << endl;
		  return kFALSE;
		}
		else if (!doTruth && !doTruthConstituents) {
		  continue;
		}
	  }
	  
	  /// TRACK JETS
	  else if (type.Contains("Track")) {
		
		/// Make sure that tracks have been requested
		if (doTrack) cons = "tracks";
		else {
		  cout << "EventBuilder_GRJETSv11::AddConstituents(): ERROR You have requested track jet constituents yet not tracks. Reconfigure analysis and run again!." << endl;
		  return kFALSE;
		}
	  }
	  
	  /// RECO (TOPO) JETS
	  else if (type.Contains("LCTopo")) {
		
		/// Make sure that clusters have been requested
		if (doLCCluster) cons = "clustersLCTopo";
		else continue;
	  }
  
	  /// Loop on the jets of this type and set the indices to the constituents
	  for(int iJet = 0; iJet < fEvt->jets(type); iJet++){
		fEvt->jet(iJet,type).AddVec("constit");
		for(int iC = 0; iC < Get<vector<int> >("jet_"+type+"_constit_n").at(iJet); iC++){
		  fEvt->jet(iJet,type).Add("constit", fEvt->Obj(cons, Get<vector<vector<int> > >("jet_"+type+"_constit_index").at(iJet).at(iC)));
		}
	  } 
	}
  }
  
  if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11::AddConstituents(): DEBUG Scheduled jet constituent links" << endl;
  return kTRUE; 
}

///=========================================
/// AddBadJetType
///=========================================
Bool_t EventBuilder_GRJETSv11::AddBadJetType() 
{
  if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11: DEBUG In AddBadJetType() " << endl;	
  
  if(doBasic){
    /// Copy just the info needed to reject jets with the BadJetDef
    TString badJetType = fEvt->String("BadJetType");
    if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11::AddBadJetType(): DEBUG Setting bad jet type: " << badJetType << endl;
    fEvt->AddVec("jets" + badJetType);
    fEvt->AddVec("jetsbadjets");

    for (unsigned int iJet = 0; iJet < Get<vector<float> >("jet_" + badJetType + "_phi").size(); iJet++) {
      
      float pt  = Get<vector<float> >("jet_" + badJetType + "_pt")  .at(iJet);
      float eta = Get<vector<float> >("jet_" + badJetType + "_eta") .at(iJet);
      float phi = Get<vector<float> >("jet_" + badJetType + "_phi") .at(iJet);
      float e   = Get<vector<float> >("jet_" + badJetType + "_E")   .at(iJet);
      
      //float jvf           = Get<vector<float> > ("jet_" + badJetType + "_jvtxf")          .at(iJet);	
      int isBadLooseMinus = Get<vector<Int_t> >("jet_" + badJetType + "_isBadLooseMinus").at(iJet);
      int isUgly          = Get<vector<Int_t> >("jet_" + badJetType + "_isUgly")         .at(iJet);
      
      TLorentzVector j;
      j.SetPtEtaPhiE(pt/1000., eta, phi, e/1000.);

      /// REJECT LOW PT JETS
      if ( (pt/1000. < fEvt->Float("MINJETPT")) || (fabs(eta) > fEvt->Float("MAXJETETA")) ) continue;
      
      /// REJECT LOW JVF JETS: OFF FOR 2012
      //if ( (jvf < fEvt->Float("MINJETJVF")) && (fabs(eta) < 2.0) ) continue;
      
      /// REJECT BAD JETS
      if (isBadLooseMinus || isUgly) {
        Particle* jet = new Particle(j); 		
        fEvt->Add("jetsbadjets", jet);
        continue;
      }

      // Set Basic kinematics
      Particle* jet = new Particle(j);

      jet->Set("isUgly",          isUgly);
      jet->Set("isBadLooseMinus", isBadLooseMinus);
      
      jet->Set("isBadLoose",      Get<vector<Int_t> >("jet_" + badJetType + "_isBadLoose")     .at(iJet));
      jet->Set("isBadMedium",     Get<vector<Int_t> >("jet_" + badJetType + "_isBadMedium")    .at(iJet));
      jet->Set("isBadTight",      Get<vector<Int_t> >("jet_" + badJetType + "_isBadTight")     .at(iJet));

      fEvt->Add("jets" + badJetType , jet);
    }
  }
  if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11::AddBadJetType(): DEBUG Added info for jet type used to define bad jets" << endl;
  return kTRUE; 

}

///=========================================
/// CopyClusters
///=========================================
Bool_t EventBuilder_GRJETSv11::CopyClusters() 
{

  if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11: DEBUG CopyClusters() " << endl;	

  if(doLCCluster){

    fEvt->AddVec("clustersLCTopo");
    
    for(int iCl = 0; iCl < Get<Int_t>("cl_n"); iCl++) {
      
      Particle* cl = new Particle();
      float pt  = Get<vector<float> >("cl_pt") .at(iCl);
      float eta = Get<vector<float> >("cl_eta").at(iCl);
      float phi = Get<vector<float> >("cl_phi").at(iCl);
      cl->p.SetPtEtaPhiM(pt/1000.,eta,phi,0);
      
      fEvt->Add("clustersLCTopo",cl);
    }
  }
  
  if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11::CopyClusters(): scheduled clusters" << endl;
  return kTRUE;
}

///=========================================
/// CopyTracks
///=========================================
Bool_t EventBuilder_GRJETSv11::CopyTracks()
{

  if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11: DEBUG CopyTracks() " << endl;	

  if(doTrack) {
    fEvt->AddVec("tracks");
    for(int iTr = 0; iTr < Get<Int_t>("trk_n"); iTr++) {
      
      Particle* tr = new Particle();
      float pt  = Get<vector<float> >("trk_pt") .at(iTr);
      float eta = Get<vector<float> >("trk_eta").at(iTr);
      float phi = Get<vector<float> >("trk_phi_wrtPV").at(iTr);
      float Mpi = 139.57018;
      tr->p.SetPtEtaPhiM(pt/1000.,eta,phi,Mpi/1000.);
      
      tr->Set("nPixHits", Get<vector<int> >  ("trk_nPixHits")    .at(iTr));
      tr->Set("nSCTHits", Get<vector<int> >  ("trk_nSCTHits")    .at(iTr));
      tr->Set("d0",       Get<vector<float> >("trk_d0_wrtPV")    .at(iTr));
      tr->Set("z0",       Get<vector<float> >("trk_z0_wrtPV")    .at(iTr));
      tr->Set("chi2",     Get<vector<float> >("trk_chi2")        .at(iTr));
      tr->Set("theta",    Get<vector<float> >("trk_theta_wrtPV") .at(iTr));
      tr->Set("ndof",     Get<vector<int> >  ("trk_ndof")        .at(iTr));

      fEvt->Add("tracks",tr);
    }
  }
  
  if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11::CopyTracks(): scheduled tracks" << endl;
  return kTRUE;
}

///=========================================
/// CopyVertices
///=========================================
Bool_t EventBuilder_GRJETSv11::CopyVertices()
{

  if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11: DEBUG CopyVertices() " << endl;	

  if(doVertex) {
    fEvt->AddVec("vtxs");

    //Vertices
    Int_t NPV=0;
    for(int pvi=0;pvi<Get<vector<int> >("vx_trk_n").size();++pvi) {
      
      /// Count the number of vertices with at least 2 tracks
      if (Get<vector<int> >("vx_trk_n").at(pvi) > 1) ++NPV;
      
      Point* vtx = new Point();
      vtx->x.SetXYZ(Get<vector<float> >("vx_x").at(pvi), Get<vector<float> >("vx_y").at(pvi), Get<vector<float> >("vx_z").at(pvi));
      vtx->Set("ntrk",Get<vector<int> >("vx_trk_n").at(pvi));

      fEvt->Add("vtxs",vtx);
    }
    fEvt->Set("NPV",NPV);
  }
  
  if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11::CopyVertices(): scheduled vertices" << endl;
  return kTRUE;
}

///=========================================
/// CopyPhotons
///=========================================
Bool_t EventBuilder_GRJETSv11::CopyPhotons() 
{
  if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11: DEBUG CopyPhotons() " << endl;	

  if(doPhotons) {
    fEvt->AddVec("photons");
    for(int iPh = 0; iPh < Get<Int_t>("ph_n"); iPh++) {
      
      Particle* ph = new Particle();
      float pt  = Get<vector<float> >("ph_pt") .at(iPh);
      float eta = Get<vector<float> >("ph_eta").at(iPh);
      float phi = Get<vector<float> >("ph_phi").at(iPh);
      float e   = Get<vector<float> >("ph_E")  .at(iPh);
      ph->p.SetPtEtaPhiE(pt/1000.,eta,phi,e/1000.);

      ph->Set("Etcone40_corrected",    Get<vector<float> >("ph_Etcone40_corrected")   .at(iPh));
      ph->Set("Etcone40_ED_corrected", Get<vector<float> >("ph_Etcone40_ED_corrected").at(iPh));
      //ph->Set("ptIsolationCone",       Get<vector<float> >("ph_ptIsolationCone")      .at(iPh));
      ph->Set("topoEtcone40",          Get<vector<float> >("ph_topoEtcone40")         .at(iPh));
      ph->Set("Etcone40_pt_corrected", Get<vector<float> >("ph_Etcone40_pt_corrected").at(iPh));
      
      ph->Set("tight",      Get<vector<int> >("ph_tight")        .at(iPh));
      ph->Set("tightIso",   Get<vector<int> >("ph_tightIso")     .at(iPh));
      ph->Set("loose",      Get<vector<int> >("ph_loose")        .at(iPh));
      ph->Set("looseIso",   Get<vector<int> >("ph_looseIso")     .at(iPh));

      ph->Set("isEM",       Get<vector<UInt_t> >("ph_isEM")      .at(iPh));
      ph->Set("isEMLoose",  Get<vector<UInt_t> >("ph_isEMLoose") .at(iPh));
      ph->Set("isEMMedium", Get<vector<UInt_t> >("ph_isEMMedium").at(iPh));
      ph->Set("isEMTight",  Get<vector<UInt_t> >("ph_isEMTight") .at(iPh));

      ph->Set("OQ",         Get<vector<UInt_t> >("ph_OQ")        .at(iPh));
      //ph->Set("OQRecalc",   Get<vector<UInt_t> >("ph_OQRecalc")  .at(iPh));

      fEvt->Add("photons",ph);
    }
  }
  
  if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11::CopyPhotons(): scheduled photons" << endl;
  return kTRUE;
}

///=========================================
/// CopyMuons
///=========================================
Bool_t EventBuilder_GRJETSv11::CopyMuons() 
{
  if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11: DEBUG CopyMuons() BEGIN " << endl; 

  if(doMuons) {
    fEvt->AddVec("muons");
    for(unsigned int iMu = 0; iMu < Get<vector<float> >("mu_pt").size(); iMu++) {
      
      if(fEvt->Debug()) cout << "EventBuilder_GRJETSv11: DEBUG CopyMuons(): copying muon number " << iMu << " out of " << Get<vector<float> >("mu_pt").size() << endl;

      Particle* mu = new Particle();
      float pt  = Get<vector<float> >("mu_pt") .at(iMu);
      float eta = Get<vector<float> >("mu_eta").at(iMu);
      float phi = Get<vector<float> >("mu_phi").at(iMu);
      float m   = Get<vector<float> >("mu_m")  .at(iMu);
      mu->p.SetPtEtaPhiM(pt/1000.,eta,phi,m/1000.);
//      mu->Set("allauthor",                  Get<vector<int> >("mu_allauthor")                .at(iMu));
      
      mu->Set("hastrack",                Get<vector<int> >("mu_hastrack")               .at(iMu));

      mu->Set("charge",                  Get<vector<float> >("mu_charge")               .at(iMu));
      mu->Set("loose",                    Get<vector<int> >("mu_loose")                 .at(iMu));
      mu->Set("medium",                   Get<vector<int> >("mu_medium")                .at(iMu));
      mu->Set("tight",                    Get<vector<int> >("mu_tight")                 .at(iMu));


      fEvt->Add("muons",mu);
    }
  }
  
  if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11::CopyPhotons(): scheduled photons" << endl;
  return kTRUE;
}

///=========================================
/// CopyElectrons
///=========================================
Bool_t EventBuilder_GRJETSv11::CopyElectrons() 
{
  if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11: DEBUG CopyElectrons() " << endl; 

  if(doElectrons) {
    fEvt->AddVec("electrons");
    for(int iEl = 0; iEl < Get<Int_t>("el_n"); iEl++) {
      
      Particle* el = new Particle();
      float pt  = Get<vector<float> >("el_pt") .at(iEl);
      float eta = Get<vector<float> >("el_eta").at(iEl);
      float phi = Get<vector<float> >("el_phi").at(iEl);
      float e   = Get<vector<float> >("el_E")  .at(iEl);
      el->p.SetPtEtaPhiE(pt/1000.,eta,phi,e/1000.);

      //ph->Set("Etcone40_corrected",    Get<vector<float> >("ph_Etcone40_corrected")   .at(iEl));
      //ph->Set("Etcone40_ED_corrected", Get<vector<float> >("ph_Etcone40_ED_corrected").at(iEl));
      el->Set("author",                Get<vector<int> >("el_author")                .at(iEl));
      el->Set("isEM",                  Get<vector<unsigned int> >("el_isEM")         .at(iEl));
      el->Set("isEMLoose",             Get<vector<unsigned int> >("el_isEMLoose")    .at(iEl));
      el->Set("isEMMedium",            Get<vector<unsigned int> >("el_isEMMedium")   .at(iEl));
      el->Set("isEMTight",             Get<vector<unsigned int> >("el_isEMTight")    .at(iEl));
      el->Set("charge",                Get<vector<float> >       ("el_charge")       .at(iEl));

      
      el->Set("OQ",                    Get<vector<unsigned int> >("el_OQ")           .at(iEl));
      el->Set("convFlag",              Get<vector<int> >("el_convFlag")              .at(iEl));
      el->Set("isConv",                Get<vector<int> >("el_isConv")                .at(iEl));

      el->Set("mediumWithoutTrack",    Get<vector<int> >("el_mediumWithoutTrack")    .at(iEl));
      el->Set("mediumIsoWithoutTrack", Get<vector<int> >("el_mediumIsoWithoutTrack") .at(iEl));
      el->Set("tightWithoutTrack",     Get<vector<int> >("el_tightWithoutTrack")     .at(iEl));
      el->Set("tightIsoWithoutTrack",  Get<vector<int> >("el_tightIsoWithoutTrack")  .at(iEl));
      el->Set("loose",                 Get<vector<int> >("el_loose")                 .at(iEl));
      el->Set("looseIso",              Get<vector<int> >("el_looseIso")              .at(iEl));
      el->Set("medium",                Get<vector<int> >("el_medium")                .at(iEl));
      el->Set("mediumIso",             Get<vector<int> >("el_mediumIso")             .at(iEl));
      el->Set("tight",                 Get<vector<int> >("el_tight")                 .at(iEl));
      el->Set("tightIso",              Get<vector<int> >("el_tightIso")              .at(iEl));
      el->Set("loosePP",               Get<vector<int> >("el_loosePP")               .at(iEl));
      el->Set("loosePPIso",            Get<vector<int> >("el_loosePPIso")            .at(iEl));
      el->Set("mediumPP",              Get<vector<int> >("el_mediumPP")              .at(iEl));
      el->Set("mediumPPIso",           Get<vector<int> >("el_mediumPPIso")           .at(iEl));
      el->Set("tightPP",               Get<vector<int> >("el_tightPP")               .at(iEl));
      el->Set("tightPPIso",            Get<vector<int> >("el_tightPPIso")            .at(iEl));

      el->Set("goodOQ",                Get<vector<int> >("el_goodOQ")                .at(iEl));
      el->Set("refittedTrack_n",       Get<vector<int> >("el_refittedTrack_n")       .at(iEl));
      el->Set("vertweight",            Get<vector<int> >("el_vertweight")            .at(iEl));
      el->Set("hastrack",              Get<vector<int> >("el_hastrack")              .at(iEl));

      fEvt->Add("electrons",el);
    }
  }
  
  if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11::CopyPhotons(): scheduled photons" << endl;
  return kTRUE;
}

///=========================================
/// WriteAuxTrees
///=========================================
void EventBuilder_GRJETSv11::WriteAuxTrees(TDirectory* outfile)
{

  if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11: DEBUG WriteAuxTrees() " << endl;

  if(!m_isNewInit) return;
  m_isNewInit = false;

  TFile* file = 0;
  TChain* chain = dynamic_cast< TChain* >( Tree() );
  if( chain ) {
	  // We are running locally...
	  file = chain->GetFile();
  } else {
	  // We are running on PROOF:
	  file = Tree()->GetCurrentFile();
  }
  
  //Thie following doesn't work, as TMNUtil modifies the tree in some way to make it unclonable.
  //Instead, we have to do some annoying stuff to get the unadulterated disk copy
  //TTree* confTree = dynamic_cast< TTree* >( file->Get( "susyMeta/TrigConfTree" ) ); 
  
  TDirectory* origMeta = (TDirectory*)file->Get("jetsMeta");
  TKey *key;
  TTree* confTree = 0;
  TIter nextkey(origMeta->GetListOfKeys());
  while ((key = (TKey *) nextkey())) {
	  if (strcmp("TrigConfTree",key->GetName()) == 0) { //This should grab highest cycle, if there are more than one
		  TDirectory::TContext ctxt(origMeta);
		  confTree = (TTree*)key->ReadObj();
		  break;
	  }
  }
  if(!confTree) Abort("EventBuilder_GRJETSv11: ERROR cannot retrieve TrigConfTree from input file!");

  TDirectory* qcdMeta = (TDirectory*)outfile->Get("jetsMeta");
  if(!qcdMeta) {
	  qcdMeta = outfile->mkdir("jetsMeta");
  }
  qcdMeta->cd();

  TTree* TrigConfTree = (TTree*)qcdMeta->Get("TrigConfTree"); 
  if(!TrigConfTree) {
	  TrigConfTree = confTree->CloneTree();
  }
  else { //Merge trees
	  TList *list = new TList;
	  list->Add(TrigConfTree);
	  list->Add(confTree);

	  TTree *newtree = TTree::MergeTrees(list);

	  TrigConfTree->SetDirectory(0);
	  delete TrigConfTree; //make sure we load the new one next time
	  
	  newtree->SetName("TrigConfTree");
	  
	  delete list;
  }
  delete confTree;
}

///=========================================
/// AddTriggers
///=========================================
Bool_t EventBuilder_GRJETSv11::AddTriggers() 
{
 
  if(fEvt->Cfg()->Objs(mTRIGVEC) == 0)
    return kTRUE; // no triggers, no pileupweights, no nothing
 
  if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11: DEBUG AddTriggers() " << endl;
  
  /// load branches that are necessary for trigger (if not already)
  Load("trig_DB_SMK");
  Load("trig_DB_L1PSK");
  Load("trig_DB_HLTPSK");
  Load("trig_L1_TAV");
  Load("trig_EF_passedPhysics");
  Load("trig_L2_passedPhysics");
  Load("trig_L1_TBP");
  Load("trig_L1_TAP");
  Load("trig_L2_passedRaw");
  Load("trig_EF_passedRaw");
  Load("trig_L2_resurrected");
  Load("trig_EF_resurrected");
  Load("trig_L2_passedThrough");
  Load("trig_EF_passedThrough");

  m_trigdefs->GetEntry(Entry());
  /// For each requested trigger:
  ///   (1) check the decision and store as a bool in the evt
  ///   (2) check that the offline object associated with that trigger is on the trigger plateau
  ///   (3) Apply the weight defined by the pile-up reweighting for this trigger
  
  for (Int_t i = 0; i<fEvt->Cfg()->Objs(mTRIGVEC); ++i) {
    TString trig(((TObjString*)fEvt->Cfg()->Obj(mTRIGVEC,i))->GetString());
    
    if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11::AddTriggers(): DEBUG Adding trigger: " << trig << "; passed = " << m_trigdefs->IsPassed(trig.Data(), TrigDefs::Physics) << endl;
    
    /// (1) check the decision and store as a bool in the evt
    fEvt->Set(trig, m_trigdefs->IsPassed(trig.Data(), TrigDefs::Physics));    
    
    
    /// (2) check that the offline object associated with that trigger is on the trigger plateau
	TString trigPar(((TObjString*)fEvt->Cfg()->Obj(mTRIGPARVEC,i))->GetString());
	float trigVal(((TObjString*)fEvt->Cfg()->Obj(mTRIGCUTVEC,i))->GetString().Atof()); 
	
	if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11::CopyEvent(): DEBUG TrigType = " << trig << " ; trigPar = " << trigPar << " ; trigVal = " << trigVal << endl;	
	
	/// Make sure that the variable (trigPar) exists in the tree first. If it doesn't the trigger is set to not pass
	if (fEvt->Exists(trigPar.Data())) {
	  bool passTrig = (fEvt->Float(trigPar.Data()) > trigVal);
	  if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11::CopyEvent(): DEBUG Pass event-level trigger selection --> " << trigPar.Data() << " = " << fEvt->Float(trigPar.Data()) << " > " << trigVal << " ? " << passTrig << endl;	
	  fEvt->Set(TString(trig + "_cut"), passTrig);  
	}
	else if (Get<vector<float> >(trigPar.Data()).size() == 0) {
	  if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11::CopyEvent(): DEBUG There are no jets of type = " << trigPar << endl;	
	  fEvt->Set(TString(trig + "_cut"), 0);
	}
	/// If the variable is in the tree, check whether or not the value of that parameter (trigPar) is above the cut (trigVal)
	else {
	  bool passTrig = ((Get<vector<float> >(trigPar.Data()).at(0)) > trigVal);
	  if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11::CopyEvent(): DEBUG Pass trigger --> " << trigPar.Data() << " = " << Get<vector<float> >(trigPar.Data()).at(0) << " > " << trigVal << " ? " << passTrig << endl;	
	  fEvt->Set(TString(trig + "_cut"), passTrig);  
	}


    /// (3) Apply the weight defined by the pile-up reweighting for this trigger
    if(fEvt->isMC() && fEvt->Cfg()->Bool("PILE")){
      myPile = (Root::TPileupReweighting*) fInput->FindObject(trig);
      if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11::AddTriggers(): DEBUG Pileup weight inputs: run = " << fEvt->RunNumber() << "; chan = " << fEvt->ChannelNumber() << "; mu = " << fEvt->Float("averageIntPerXing") << endl;
      Double_t pileUpWeight = myPile->GetCombinedWeight(fEvt->RunNumber(), fEvt->ChannelNumber(), fEvt->Float("averageIntPerXing"));
      if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11::AddTriggers(): DEBUG Pileup weight = " << pileUpWeight << endl;
      fEvt->Set(TString(trig + "_weight"), pileUpWeight);
    }
    else
      fEvt->Set(TString(trig + "_weight"), 1.);
  }
  
  if(fEvt->Debug()) cout << "EventBuilder_GRJETSv11::AddTriggers(): DEBUG Scheduled setup of triggers" << endl;
  return kTRUE; 
}


///=========================================
/// DoCustomSetup
///=========================================
Bool_t EventBuilder_GRJETSv11::DoCustomSetup() 
{
 
  if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11::DoCustomSetup(): DEBUG In DoCustomSetup() " << endl;
 
  ///=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
  /// Tracking systematics
  ///=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
  if (doTrackSyst) {
    
    if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11::DoCustomSetup(): DEBUG Looping over jet types looking for TrackZ" << endl;
    
    /// Loop over jet types looking for track jets
	for(Int_t i = 0; i<fEvt->Cfg()->Objs(mJETTYPEVEC); ++i) {
		
	  TString type(((TObjString*)fEvt->Cfg()->Obj(mJETTYPEVEC,i))->GetString()); 
	  
	  /// If it's not a track jet, skip it!
	  if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11::DoCustomSetup(): DEBUG Jet type = " << type << endl;
	  if (!type.Contains("TrackZ")) continue;   
    
      /// Look at all the track jets we have here
      if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11::DoCustomSetup(): DEBUG Starting loop over track jets" << endl;
	  for ( int jetItr = 0; jetItr < fEvt->jets(type); ++jetItr ) {
		
		// Pick up the kinematics
		float pt  = fEvt->jet(jetItr, type).p.Pt();
		float eta = fEvt->jet(jetItr, type).p.Eta();
		float phi = fEvt->jet(jetItr, type).p.Phi();
		float E   = fEvt->jet(jetItr, type).p.E();
		
		// Grab the scaling factor
		if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11::DoCustomSetup(): DEBUG Getting track jet systematics" << endl;
		float factor = this->TrackJetSyst( fEvt->jet(jetItr, type) );
		
		// Apply it!
		if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11::DoCustomSetup(): DEBUG Reset track jet kinematics" << endl;
		fEvt->jet(jetItr, type).p.SetPtEtaPhiE( pt*factor, eta, phi, E*factor);
	  }
	}
  }
  
  return kTRUE;
  
}

///=========================================
/// TrackJetSyst
///=========================================
float EventBuilder_GRJETSv11::TrackJetSyst(Particle &trackJet)
{
  if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11::TrackJetSyst(): DEBUG In TrackJetSystematics()" << endl;

  /// Sanity check: make sure it has at least one track and 2 GeV of pT
  if (trackJet.Objs("constit") < 1 || trackJet.p.Pt() < 2.0) return 1.0;
  
  /// Print some info
  if (fEvt->Debug()) {
	TString jetinfo = 
	TString::Format("Track Jet: (E, Pt, m, eta, phi, Ntrk) = (%1.2f, %1.2f, %1.2f, %1.2f, %1.2f, %d)",
					trackJet.p.E(),
					trackJet.p.Pt(),
					trackJet.p.M(),
					trackJet.p.Eta(),
					trackJet.p.Phi(),
					(int)trackJet.Objs("constit")
				  );
	cout << jetinfo << endl; 
  }
  
  //// TLV for the efficiency-altered pT
  TLorentzVector tracks(0.,0.,0.,0.);
  int nTrk = 0;
  
  if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11::TrackJetSyst(): DEBUG Random number is: " << r1.Uniform() << endl;
  
  /// Loop over the constituent tracks for this track jet
  for (Int_t iConstit = 0; iConstit < trackJet.Objs("constit"); iConstit++) {
  
    Particle *track = (Particle*)trackJet.Obj("constit" , iConstit);
  
    /// Print some info
    if (fEvt->Debug()) {
	  TString trkinfo = 
	  TString::Format("Track: (pt, eta, phi, z0) = (%1.2f, %1.2f, %1.2f, %1.2f)",
					  track->p.Pt(), track->p.Eta(), track->p.Phi(), track->Float("z0")
					 );
	  cout << trkinfo << endl; 
	}

    float eta = track->p.Eta();
  
    /// Make sure they are decent tracks in the first place. Basically just a sanity check
	if (fabs(track->p.Pt())      < 0.500) { continue; }
    if (fabs(eta)                > 2.700) { continue; }
    
    /// Throw a random number between 0 & 1
	float roll = r1.Uniform();  

    /// If the track is in a given eta region, 
    /// it has a 2%, 3%, 4%, or 7% chance of being missed, 
    /// so throw it away based on that probability
	if (fabs(eta) < 1.3) {
		if (roll < 0.02) { continue; }
	} else if (fabs(eta) < 1.9) {
		if (roll < 0.03) { continue; }
	} else if (fabs(eta) < 2.3) {
		if (roll < 0.04) { continue; }
	} else {
		if (roll < 0.07) { continue; }
	}
  
    /// Add this track to the TLV of all tracks
	TLorentzVector t(0.,0.,0.,0.);
    t.SetPtEtaPhiM(track->p.Pt(), track->p.Eta(), track->p.Phi(), track->p.M());
  
	tracks += t;
	nTrk++;

  }
  
  /// What did we do?
  if (fEvt->Debug()) cout << "EventBuilder_GRJETSv11::TrackJetSyst(): DEBUG Resulting pT = " << tracks.Pt() << "; Ntrk = " << nTrk << endl;

  if (fEvt->Debug() && (trackJet.Objs("constit")-nTrk) > 0)  cout << "EventBuilder_GRJETSv11::TrackJetSyst(): DEBUG Threw away NeffLost = " << (trackJet.Objs("constit")-nTrk) << " tracks" << endl;

  /// Calculate how different the track jet pT might be if we lost a few more tracks
  float ratio = tracks.Pt() / trackJet.p.Pt();
  
  /// Throw a warning if this difference is greater than 10%
  if ( fabs(1. - ratio) > 0.1) cout << "EventBuilder_GRJETSv11::TrackJetSyst(): ERROR ratio sys/nosys = " << ratio << endl;
  
  return ratio;
}
