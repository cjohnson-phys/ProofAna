/**************************************************************************
 **
 **   File:         EventBuilder_example.cxx
 **
 **   Description:  EventBuilder example class
 **                 
 **
 **   Author:       B. Butler
 **
 **   Created:      2-23-11
 **   Modified:
 **
 **************************************************************************/
// Use this file as a template for your EventBuilder source file (delete the 
// one produced by TTree->MakeSelector("EventBuilder_myFile")). Only the
// CopyEvent function must be changed.

#define EventBuilder_Eflow_cxx
/// Type used for internal caching

#include "EventBuilder_Eflow.h"
#include "AnaConfig.h"
#include "AnalysisBase.h"
#include "TMath.h"
#include "TVector3.h"
#include "PileupReweighting/TPileupReweighting.h"
#include "GoodRunsLists/TGoodRunsList.h"
#include "TKey.h"
#include <iostream>

 //Overlap removal w/z samples
//#include "SUSYTools/HforToolD3PD.h"

// muon mc smearing
//#include "MuonMomentumCorrections/SmearingClass.h"

 //calibration tools
#include "ApplyJetCalibration/ApplyJetCalibration.h"
#include "JetUncertainties/MultijetJESUncertaintyProvider.h"
#include "JetResolution/JERProvider.h"
#include "ApplyJetResolutionSmearing/ApplyJetSmearing.h"



#include "MissingETUtility/METUtility.h" 


EventBuilder_Eflow::EventBuilder_Eflow(TTree * /*tree*/)
{

  m_trigdefs = 0;
  myGRL = 0;
  myPRW = 0;

  data4LCCalibrator = 0;
  data4EMCalibrator = 0;

  data6LCCalibrator = 0;
  data6EMCalibrator = 0;

  mc4LCCalibrator = 0;
  mc4EMCalibrator = 0;

  mc6LCCalibrator = 0;
  mc6EMCalibrator = 0;


  afiimc4LCCalibrator = 0;
  afiimc4EMCalibrator = 0;

  afiimc6LCCalibrator = 0;
  afiimc6EMCalibrator = 0;


  //myHforTool = new HforToolD3PD();
  //myHforTool->initialize("angularbased", 0.4);


  mJETTYPEVEC    = "JETTYPEVEC";
  mBTAGVEC       = "BTAGVEC";
  mPRWVEC        = "PRWVEC";
  // nothing to init yet
}

EventBuilder_Eflow::~EventBuilder_Eflow(){
  // nothing to delete
  //delete m_trigdefs;
  //if(m_trigdefs) delete m_trigdefs;
  //if(myHforTool) delete myHforTool;
  //if(myGRL) delete myGRL;
  //if(myPRW) delete myPRW;
}


void EventBuilder_Eflow::Initialize(){
  myGRL = (Root::TGoodRunsList*)fInput->FindObject("myGRL");  
  if(!myGRL) {
    cout << "EventBuilder_Eflow: ERROR cannot retrieve GRL object from input list!" << endl;
    exit(1);
  }
  GetJetCalibrationTools();

  //MCPSmear = (MuonSmear::SmearingClass*) fInput->FindObject("MCPSmear");

  std::string maindir(gSystem->Getenv("PROOFANADIR"));
  if(maindir==".") maindir+="/libProofAna";
  cout << maindir << " is the maindir we work from! " << endl;
  cout << gSystem->Exec(TString("ls "+maindir).Data()) << endl;
  //MCPSmear = new MuonSmear::SmearingClass("Data12","muid","q_pT","Rel17.2Repro", maindir+"/utils/MuonMomentumCorrections/share/");
  //MCPSmear->Initialize("Data12","muid","q_pT","Rel17.2Repro", "../utils/MuonMomentumCorrections/share/");

	m_util = new METUtility;
	 //vector<float> jet_AntiKt4LCTopo_recalibrated_pt ;
	
}

Bool_t EventBuilder_Eflow::CopyEvent(AnalysisBase* evt)
{

////////////////////////////////////////////////////////////
//// Initialize configurations for this event
////////////////////////////////////////////////////////////

  doPRW                     = false;
  doAFII                    = false;
  doJet4                    = false;
  doJet6                    = false;
  doTruthJets               = false;
  doOOTtruthJet4            = false;
  doInTimeTruthJet4         = false;
  doLCJets                  = false;
  doEMJets                  = false;
  doJetCalibrations         = false; 
  doSMWZ                    = false;
  doCOMMON                  = false;
  doTruth                   = false;
  doTruthParentChild        = false;
  doTrack                   = false;
  doLCCluster               = false;
  doEMCluster               = false;
  doVertex                  = false;
  doPhotons                 = false;
  doMuons                   = false;
  doMuonTriggers            = false;
  doElectronTriggers        = false;
  doMuonTriggersMatch       = true;
  doJetTriggers             = false;
  doHFOR                    = false;
  doVectorJVFLinks          = false;
  doTruthMFLinks            = false;
  doConstitLinks            = false;
  doMETRefFinal             = false;
  doBarcode                 = false;
  Rename                    = false;
  doTrkJetBTag              = false;
  doLeptonTruth             = false;
  doEflow                   = false;
  
  muRef                     = 0.;
  npvRef                    = 0.;
  whichsyste                = JetMETSyst::NONE;
  doMuSmear                 = true;
  doMCGRL                   = false;

  evt->Cfg()->Get("DOHFOR",               doHFOR);
  evt->Cfg()->Get("DOJET4",               doJet4); 
  evt->Cfg()->Get("DOJET6",               doJet6); 
  evt->Cfg()->Get("DOTRUTHJETS",          doTruthJets);
  evt->Cfg()->Get("DOOOTTRUTHJET4",       doOOTtruthJet4);
  evt->Cfg()->Get("DOINTIMETRUTHJET4",    doInTimeTruthJet4);
  evt->Cfg()->Get("DOLCJETS",             doLCJets);
  evt->Cfg()->Get("DOEMJETS",             doEMJets);
  evt->Cfg()->Get("PILE",                 doPRW);
  evt->Cfg()->Get("DOVECTORJVFLINKS",     doVectorJVFLinks);
  evt->Cfg()->Get("DOTRUTHMFLINKS",       doTruthMFLinks);
  evt->Cfg()->Get("DOCONSTITLINKS",       doConstitLinks);
  evt->Cfg()->Get("DOMETREFFINAL",        doMETRefFinal);
  evt->Cfg()->Get("DOSMWZ",               doSMWZ);
  evt->Cfg()->Get("DOCOMMON",             doCOMMON);
  evt->Cfg()->Get("DOAFII",               doAFII);;
  evt->Cfg()->Get("DOTRACK",              doTrack);
  evt->Cfg()->Get("DOPHOTON",             doPhotons);
  evt->Cfg()->Get("DOLCCLUSTER",          doLCCluster);
  evt->Cfg()->Get("DOEMCLUSTER",          doEMCluster);
  evt->Cfg()->Get("DOTRUTH",              doTruth);
  evt->Cfg()->Get("DOPARENTCHILD",        doTruthParentChild);
  evt->Cfg()->Get("DOVTX",                doVertex);
  evt->Cfg()->Get("DOJETCALIBRATIONS",    doJetCalibrations);
  evt->Cfg()->Get("DOMUONS",              doMuons);
  evt->Cfg()->Get("DOMUONTRIGGERS",       doMuonTriggers);
  evt->Cfg()->Get("DOELECTRONTRIGGERS",   doElectronTriggers);
  evt->Cfg()->Get("DOMUONTRIGGERSMATCH",  doMuonTriggersMatch);
  evt->Cfg()->Get("DOJETTRIGGERS",        doJetTriggers);
  evt->Cfg()->Get("DOELECTRONS",          doElectrons);
  evt->Cfg()->Get("SYSTTYPE",             whichsyste);
  evt->Cfg()->Get("DOBARCODE",            doBarcode);
  evt->Cfg()->Get("RENAME",               Rename   );
  evt->Cfg()->Get("DOTRKJETBTAG",         doTrkJetBTag);
  evt->Cfg()->Get("DOLEPTONTRUTH",        doLeptonTruth);
  evt->Cfg()->Get("DOMUSMEAR",            doMuSmear);
  evt->Cfg()->Get("DOMCGRL",              doMCGRL);
  evt->Cfg()->Get("DOEFLOW",              doEflow);

  //cout << "whichsyste is " << whichsyste << endl;

  evt->Cfg()->Get("MUREF",                muRef);
  evt->Cfg()->Get("NPVREF",               npvRef);
  
  fEvt = evt;

  if(evt->Debug()) cout << " set up configs " << endl;

////////////////////////////////////////////////////////////
//// Set some global variable
////////////////////////////////////////////////////////////
	
	jet_AntiKt4LCTopo_recalibrated_pt.clear();

	//cout << "init global vars" << endl;
	evt->Set("RunNumber", (int) Get<UInt_t>("RunNumber"));
	evt->Set("EventNumber", (int)Get<UInt_t>("EventNumber"));

	
	if(fEvt->Debug()) cout << fEvt->RunNumber() << " is run number  and " << fEvt->EventNumber() << "is enum" << endl;
	
	evt->Set("larerror", Get<unsigned int>("larError")); 
  evt->Set("tileerror", Get<unsigned int>("tileError")); 
  evt->Set("coreflags", Get<unsigned int>("coreFlags")); 
  //evt->Set("isMC",(bool)(Get<UInt_t>("RunNumber")<152166));
	evt->Set("averageIntPerXing", Get<float>("averageIntPerXing"));
	evt->Set("LBN", (int)Get<UInt_t>("lbn"));
	evt->Set("BunchCrossingID", (int)Get<UInt_t>("bcid"));

  static const BranchKey bmc_channel_number("mc_channel_number");
	static const MomKey misMC("isMC"), mChannelNumber("ChannelNumber");
	if(BranchNames().find(bmc_channel_number)!=BranchNames().end()) {
		evt->Set(mChannelNumber,(int)Get<UInt_t>(bmc_channel_number));
		evt->Set(misMC,true);	
	}
	else evt->Set(misMC,false);	


  static const MomKey mEventWeight("EventWeight");
  static const BranchKey bmcevt_weight("mcevt_weight");
  if(fEvt->isMC()){
    if(Get<vector<vector<double> > >(bmcevt_weight).size()) {
      if(Get<vector<vector<double> > >(bmcevt_weight).at(0).size()) { //This stuff necessary due to a bug it seems
        fEvt->Set(mEventWeight,(float)Get<vector<vector<double> > >(bmcevt_weight).at(0).at(0));
      }
    }
    else Abort("ERROR: mcevt_weight vector is empty!");
  }
  else{
    evt->Set("EventWeight", 1.0); // default value
  }

  if(evt->Debug()){
    cout << "showing at the event quantities" << endl;
    evt->Show();
  }


  if(fEvt->Debug()) cout << " basic event quantities done" << endl;
////////////////////////////////////////////////////////////
//// Do GRL Parsing, and HFOR/PU 
////////////////////////////////////////////////////////////

  if(evt->Debug()){
    cout << "showing at the setup prw" << endl;
    evt->Show();
  }

  static const MomKey mgrl("grl"), LBN("LBN"), RunNumber("RunNumber");

  if (!(fEvt->isMC())){
    if (evt->Debug()){
      cout << " checking GRL " << endl;
      cout << LBN << " " << RunNumber << endl;
      if (myGRL){
	cout << "yes " << endl;
      }
      else{
	cout << "no" << endl;
      }
    }
  }

  if(fEvt->isMC() && !doMCGRL){ 
    fEvt->Set(mgrl,true);
  } else if(myGRL){
    fEvt->Set(mgrl,myGRL->HasRunLumiBlock(fEvt->Int(RunNumber),fEvt->Int(LBN)));
  } 


  if(evt->Debug()) cout << "set grl" << endl;
   

  if(evt->Debug()){
    cout << "showing at the hfor" << endl;
    evt->Show();
  }

  if(fEvt->Debug()) cout << " hfor done " << endl;
////////////////////////////////////////////////////////////
//// Copy over all the objects
////////////////////////////////////////////////////////////


  bool fail = true;

  // NOTE: I put the truth copy in the head for track-truth association.
  fail = fail && CopyTruthFull();

  if(evt->Debug()){
    cout << "showing at the end of truthfull" << endl;
    evt->Show();
  }

  fail = fail && AddTruthParentChild();


  if(evt->Debug()) cout << __LINE__ <<  " CopyEvent " << endl;
  fail = fail && CopyTracks();
  if(evt->Debug()) cout << __LINE__ <<  " CopyEvent " << endl;
  fail = fail && CopyVertices();
  if(evt->Debug()) cout << __LINE__ <<  " CopyEvent " << endl;
  fail = fail && CopyClusters();
  if(evt->Debug()) cout << __LINE__ <<  " CopyEvent " << endl;
  fail = fail && CopyEflow();
  if(evt->Debug()) cout << __LINE__ <<  " CopyEvent " << endl;

  if(evt->Debug()){
    cout << "showing at the end of tracks" << endl;
    evt->Show();
    cout << "HaHaHa" << endl;
  }

  evt->SortPtAll();
  
  if(fEvt->Debug()) cout << "abandon all hope, ye who enter here" << endl; 
  fail = fail && DoCustomSetup();
  
  if(fEvt->Debug()) cout << "set up full event, status is " << fail << endl;
  
  if(evt->Debug()){
    cout << "showing at the end" << endl;
    evt->Show();
  }

	return fail;
}

///========================================
/// CopyEflow
///==========================================
Bool_t EventBuilder_Eflow::CopyEflow(){


  if (fEvt->Debug()) cout << "EventBuilder_Eflow: DEBUG CopyEflow()" << endl;  

  static const MomKey EflowObjects("recosEFO");
  static const BranchKey bEflow_n("eflow_n"), bEflow_pt("eflow_eflow_pt"), bEflow_e("eflow_eflow_e"),
                         bEflow_eta("eflow_eflow_eta"), bEflow_phi("eflow_eflow_phi"),
                         bEflow_charge("eflow_eflow_charge"), bEflow_z0("eflow_eflow_z0"),
                         bEflow_d0("eflow_eflow_d0");

  static const MomKey    eflow_charge("eflow_charge"), eflow_z0("eflow_z0"), eflow_d0("eflow_d0");

  if(doEflow){
    fEvt->AddVec(EflowObjects);
    for (int i = 0; i< Get<Int_t>("eflow_n"); i++) {

        Particle * EFO = new Particle();
        float pt  = Get<vector<float> >(bEflow_pt) .at(i);
        float eta = Get<vector<float> >(bEflow_eta).at(i);
        float phi = Get<vector<float> >(bEflow_phi).at(i);
        float e   = Get<vector<float> >(bEflow_e)  .at(i);
        if(pt < 1)  continue; // this is MeV

        EFO->Set("pt", pt/1000.);
        EFO->p.SetPtEtaPhiE(pt/1000., eta, phi, e/1000.);

        EFO->Set(eflow_charge,      Get<vector<int> >    (bEflow_charge)     .at(i)); 
        EFO->Set(eflow_z0,          Get<vector<float> >  (bEflow_z0)         .at(i)); 
        EFO->Set(eflow_d0,          Get<vector<float> >  (bEflow_d0)         .at(i)); 

        fEvt->Add(EflowObjects,EFO);
    }
  }

  if (fEvt->Debug()) cout << "EventBuilder_Eflow: DEBUG CopyEflow(): End" << endl;
  return kTRUE;

}

///=========================================
/// CopyTruthFull
///=========================================
Bool_t EventBuilder_Eflow::CopyTruthFull()
{
  
  static const MomKey mtruths("truths");


  static const BranchKey bmc_pt("mc_pt"), bmc_eta("mc_eta"), bmc_phi("mc_phi"), bmc_m("mc_m"),
    bmc_pdgId("mc_pdgId"), bmc_status("mc_status"), bmc_charge("mc_charge"), bmc_barcode("mc_barcode"), bmc_vx_barcode("mc_vx_barcode");

  static const MomKey index("index"), type("type"), pdgId("pdgId"), charge("charge"), barcode("barcode"), mpt("pt"), status("status"), vx_barcode("vx_barcode");


  barcode_link = 0;

  if (fEvt->Debug()) cout << "EventBuilder_Eflow: DEBUG CopyTruthFull()  and doTruth = " << doTruth << endl;  
  
  /// If scheduled, set the truth particles
  if(fEvt->isMC() && doTruth) {
    
    fEvt->AddVec(mtruths);
    
    if(doBarcode){
      fEvt->AddVec("barcode_database");
      barcode_link = new MomentObj();
      fEvt->Add("barcode_database", barcode_link);
    }
    
    for (int i = 0; i< Get<Int_t>("mc_n"); i++) {

      Particle * mc = new Particle();
      float pt  = Get<vector<float> >(bmc_pt) .at(i);
      float eta = Get<vector<float> >(bmc_eta).at(i);
      float phi = Get<vector<float> >(bmc_phi).at(i);
      float m   = Get<vector<float> >(bmc_m)  .at(i);
      mc->Set("pt", pt);
      mc->p.SetPtEtaPhiM(pt/1000., eta, phi, m/1000.);
      mc->Set(index, i );      
      //mc->Set(mpt  , pt);

      mc->Set(type,      Get<vector<int> >  (bmc_pdgId)     .at(i)); 
      mc->Set(pdgId,     Get<vector<int> >  (bmc_pdgId)     .at(i)); 
      mc->Set(status,    Get<vector<int> >  (bmc_status)    .at(i)); 
      mc->Set(charge,    Get<vector<float> >(bmc_charge)    .at(i));
      mc->Set(barcode,   Get<vector<int> >  (bmc_barcode)   .at(i));
      mc->Set(vx_barcode,Get<vector<int> >  (bmc_vx_barcode).at(i));

      if(Rename){
        mc->Set("mc_type",    Get<vector<int> >(bmc_pdgId)    .at(i));
      	mc->Set("mc_pdgId",   Get<vector<int> >(bmc_pdgId)    .at(i));
	      mc->Set("mc_status",  Get<vector<int> >(bmc_status)   .at(i));
	      mc->Set("mc_charge",  Get<vector<float> >(bmc_charge) .at(i));
	      mc->Set("mc_barcode", Get<vector<int> >(bmc_barcode)  .at(i));
      }

      if(doBarcode){
        //MomentObj* barcode_link = fEvt->Obj<MomentObj>("barcode_database");
	barcode_link->AddVec(TString::Itoa(mc->Int("mc_barcode"), 10));
	barcode_link->Add(TString::Itoa(mc->Int("mc_barcode"), 10), mc);
      }

      fEvt->Add(mtruths,mc);
      if(fEvt->Debug()){
        //cout << "Going to print particle " << i << endl;
        //mc->Show();
      }
    } // end for loop over particles
  }
  
  if (fEvt->Debug()) cout << "EventBuilder_Eflow::CopyTruthFull(): DEBUG Scheduled Truth Particles" << endl;
  return kTRUE;
}

///=========================================
/// AddTruthParentChild
///=========================================
Bool_t EventBuilder_Eflow::AddTruthParentChild()
{
  TString prefix;
  if(Rename) prefix = "mc_";
  else       prefix = "";

  static const MomKey children(prefix + "children"), parents(prefix + "parents");

  TString child_branch, parent_branch;
  if(!doCOMMON){
    child_branch  = "mc_children";
    parent_branch = "mc_parents";
  }
  else{
    child_branch  = "mc_child_index";
    parent_branch = "mc_parent_index";
  }

  static const BranchKey bmc_children(child_branch), bmc_parents(parent_branch);

  if (fEvt->Debug()) cout << "EventBuilder_Eflow::AddTruthParentChild(): DEBUG Starting" << endl;

  if(fEvt->isMC() && doTruthParentChild)
  {
    for(int iTr = 0; iTr < fEvt->truths(); iTr++)
    {
      if (fEvt->Debug()) cout << "EventBuilder_Eflow::AddTruthParentChild(): DEBUG On particle " << iTr << " of " << fEvt->truths() << endl;

      fEvt->truth(iTr).AddVec(children);
      fEvt->truth(iTr).AddVec(parents, true);
      if (fEvt->Debug()) cout << "EventBuilder_Eflow::AddTruthParentChild(): DEBUG Has children " << Get<vector<vector<int> > >(bmc_children).at(iTr).size()  << endl;

      int nChildren = Get<vector<vector<int> > >(bmc_children).at(iTr).size();
      for(int iChild = 0; iChild < nChildren; iChild++)
      {
        int index = Get<vector<vector<int> > >(bmc_children).at(iTr).at(iChild);
        if (fEvt->Debug()) cout << "EventBuilder_Eflow::AddTruthParentChild(): DEBUG Adding child " << index  << endl;
           
        if(!doCOMMON){     
          if((index > -1) && (index < fEvt->truths()) && (index != iTr))
            fEvt->truth(iTr).Add(children,&(fEvt->truth(index)));
          else{
            if(fEvt->Debug()) cout << "Ops ... illegal truth index" << endl;
          }
        }
        else{
          fEvt->truth(iTr).Add(children,&(fEvt->truth(index)));
        }
      }

      if (fEvt->Debug()) cout << "EventBuilder_Eflow::AddTruthParentChild(): DEBUG Has parents " << Get<vector<vector<int> > >(bmc_parents).at(iTr).size()  << endl;

      int nParents = Get<vector<vector<int> > >(bmc_parents).at(iTr).size();
      for(int iParent = 0; iParent < nParents; iParent++)
      {
        int index = Get<vector<vector<int> > >(bmc_parents).at(iTr).at(iParent);
        if (fEvt->Debug()) cout << "EventBuilder_Eflow::AddTruthParentChild(): DEBUG Adding parent " << index << endl;
        
        if(!doCOMMON){
          if((index > -1) && (index < fEvt->truths()) && (index != iTr))
            fEvt->truth(iTr).Add(parents,&(fEvt->truth(index)));
          else{
            if(fEvt->Debug()) cout << "Ops ... illegal truth index" << endl;
           }
        }
        else{
          fEvt->truth(iTr).Add(parents,&(fEvt->truth(index)));
        }
      }
      
      if(fEvt->Debug()){
        cout << parents.Data() << " Has member " << fEvt->truth(iTr).Objs(parents) << endl;
        cout << children.Data() << " Has memebr " << fEvt->truth(iTr).Objs(children) << endl;
      }
    }
  } 

  if (fEvt->Debug()) cout << "EventBuilder_Eflow::AddTruthParentChild(): DEBUG Ending" << endl;
  return kTRUE;

}


Bool_t EventBuilder_Eflow::CopyClusters(){
  if(doLCCluster){
    static const MomKey clustersKey("clustersLCTopo");
    fEvt->AddVec(clustersKey);
    BranchKey bn, bpt, beta, bphi;
    if(doSMWZ ){
      bn   = BranchKey("cl_n");
      bpt  = BranchKey("cl_pt");
      beta = BranchKey("cl_eta");
      bphi = BranchKey("cl_phi");
    } else if (doCOMMON){
      bn   = BranchKey("cl_lc_n");
      bpt  = BranchKey("cl_lc_pt");
      beta = BranchKey("cl_lc_eta");
      bphi = BranchKey("cl_lc_phi");
    } else  {
      bn   = BranchKey("cl_had_n");
      bpt  = BranchKey("cl_had_pt");
      beta = BranchKey("cl_had_eta");
      bphi = BranchKey("cl_had_phi");
    }
    for(int iCl = 0; iCl < Get<int>(bn); iCl++){
      Particle* cl = new Particle();
      float pt = Get<vector<float> >(bpt).at(iCl);
      float eta = Get<vector<float> >(beta).at(iCl);
      float phi = Get<vector<float> >(bphi).at(iCl);
      cl->p.SetPtEtaPhiE(pt/1000.,eta,phi,pt/1000.*cosh(eta));
      fEvt->Add(clustersKey,cl);
    }
  }
  if(fEvt->Debug()) cout << "set up clusters" << endl;
  return kTRUE;
}


Bool_t EventBuilder_Eflow::CopyTracks(){

  static const MomKey mtracks("tracks"),
    nPixHits("nPixHits"), nPixHoles("nPixHoles"), nPixelDeadSensors("nPixelDeadSensors"), nSCTHits("nSCTHits"),
    nSCTHoles("nSCTHoles"), nSCTDeadSensors("nSCTDeadSensors"), chi2("chi2"), ndof("ndof"), nTRTOutliers("nTRTOutliers"),
    nTRTHits("nTRTHits"), qoverp("qoverp"), theta("theta"), d0_wrtPV("d0_wrtPV"), z0_wrtPV("z0_wrtPV"), z0("z0"), d0_wrtBL("d0_wrtBL"), d0_wrtBS("d0_wrtBS"),
    eta_atCalo("eta_atCalo"), phi_atCalo("phi_atCalo"), mc_barcode("mc_barcode");



  static const BranchKey btrk_n("trk_n"), btrk_pt("trk_pt"), btrk_eta("trk_eta"), btrk_nPixHits("trk_nPixHits"),
    btrk_nPixHoles("trk_nPixHoles"), btrk_nPixelDeadSensors("trk_nPixelDeadSensors"), btrk_nSCTHits("trk_nSCTHits"), 
    btrk_nSCTHoles("trk_nSCTHoles"), btrk_nSCTDeadSensors("trk_nSCTDeadSensors"), btrk_d0_wrtPV("trk_d0_wrtPV"),
    btrk_z0_wrtPV("trk_z0_wrtPV"), btrk_z0("trk_z0"), btrk_d0_wrtBL("trk_d0_wrtBL"), btrk_d0_wrtBS("trk_d0_wrtBS"), btrk_chi2("trk_chi2"), btrk_ndof("trk_ndof"),
    btrk_nTRTOutliers("trk_nTRTOutliers"), btrk_nTRTHits("trk_nTRTHits"),
    btrk_eta_atCalo("trk_eta_atCalo"), btrk_phi_atCalo("trk_phi_atCalo"), btrk_mc_barcode("trk_mc_barcode");

  BranchKey fix;

  if(doSMWZ || doCOMMON){
    fix = BranchKey("_wrtPV");
  } else {
    fix = BranchKey("");
  }

  const BranchKey btrk_phi("trk_phi"+fix), btrk_qoverp("trk_qoverp"+fix), btrk_theta("trk_theta"+fix);

  if(doTrack){

    fEvt->AddVec(mtracks);
    
    if(doTrkJetBTag) fEvt->AddVec("tracks_trkZjet", true);
    
    for(int iTr = 0; iTr < Get<Int_t>(btrk_n); iTr++){
      Particle* tr = new Particle();
      
      if(!doTrkJetBTag){
        float pt =  Get<vector<float> >(btrk_pt) .at(iTr);
        float eta = Get<vector<float> >(btrk_eta).at(iTr);
        float phi = Get<vector<float> >(btrk_phi).at(iTr);
        tr->p.SetPtEtaPhiM(pt/1000.,eta,phi,0);

        tr->Set(qoverp,            Get<vector<float> >(btrk_qoverp)           .at(iTr));
        tr->Set(nPixHits,          Get<vector<int> >  (btrk_nPixHits)         .at(iTr));
        tr->Set(nPixHoles,         Get<vector<int> >  (btrk_nPixHoles)        .at(iTr));
        tr->Set(nPixelDeadSensors, Get<vector<int> >  (btrk_nPixelDeadSensors).at(iTr));
        tr->Set(nSCTHits,          Get<vector<int> >  (btrk_nSCTHits)         .at(iTr));
        tr->Set(nSCTHoles,         Get<vector<int> >  (btrk_nSCTHoles)        .at(iTr));
        tr->Set(nSCTDeadSensors,   Get<vector<int> >  (btrk_nSCTDeadSensors)  .at(iTr));
        tr->Set(d0_wrtPV,          Get<vector<Float_t> >(btrk_d0_wrtPV)         .at(iTr));
        tr->Set(d0_wrtBL,          Get<vector<float> >(btrk_d0_wrtBL)         .at(iTr));
        if(!doSMWZ && !doCOMMON)
          tr->Set(d0_wrtBS,          Get<vector<float> >(btrk_d0_wrtBS)         .at(iTr));
        tr->Set(z0_wrtPV,          Get<vector<float> >(btrk_z0_wrtPV)         .at(iTr));
        if(!doSMWZ && !doCOMMON)
          tr->Set(z0,                Get<vector<float> >(btrk_z0)               .at(iTr));
        tr->Set(chi2,              Get<vector<float> >(btrk_chi2)             .at(iTr));
        tr->Set(theta,             Get<vector<float> >(btrk_theta)            .at(iTr));
        tr->Set(ndof,              Get<vector<int> >  (btrk_ndof)             .at(iTr));
        //tr->Set(nTRTOutliers,      Get<vector<int> >  (btrk_nTRTOutliers)     .at(iTr));
        tr->Set(nTRTHits,          Get<vector<int> >  (btrk_nTRTHits)         .at(iTr));
        if(!doSMWZ)
        tr->Set(eta_atCalo,        Get<vector<float> > (btrk_eta_atCalo)      .at(iTr));
        if(!doSMWZ)
        tr->Set(phi_atCalo,        Get<vector<float> > (btrk_phi_atCalo)      .at(iTr));
        if(!doSMWZ && fEvt->isMC())
        tr->Set(mc_barcode,        Get<vector<int> > (btrk_mc_barcode)        .at(iTr));
      }
      else{
        float pt  = Get<vector<float> >("trk_pt") .at(iTr);
        float eta = Get<vector<float> >("trk_eta").at(iTr);
        //float qoverp = Get<vector<float> >("trk_qoverp_wrtPV").at(iTr);
        //float theta = Get<vector<float> >("trk_theta_wrtPV").at(iTr);

        //float pt = TMath::Sin( theta ) / fabs( qoverp );
        //float eta = -1.0 * log( TMath::Tan( theta / 2.0 )  );
        float phi = Get<vector<float> >("trk_phi_wrtPV").at(iTr);
        float Mpi = 139.57018; // MeV
        tr->p.SetPtEtaPhiM(pt/1000.,eta,phi,Mpi/1000.);
      
        tr->Set("d0",              Get<vector<float> >("trk_d0_wrtPV")    .at(iTr));
        if(!doCOMMON)
          tr->Set("d0_wrtBS",        Get<vector<float> >("trk_d0_wrtBS")    .at(iTr));
        else
          tr->Set("d0_wrtBS", tr->Float("d0"));  // Because I don't want to change all following labels ... 
        tr->Set("z0",              Get<vector<float> >("trk_z0_wrtPV")    .at(iTr));
        tr->Set("z0SinTheta",      tr->Float("z0")*TMath::Sin(tr->p.Theta()));
        tr->Set("err_d0",          TMath::Sqrt(Get<vector<float> > ("trk_cov_d0_wrtPV")    .at(iTr)));
        tr->Set("err_z0",          TMath::Sqrt(Get<vector<float> > ("trk_cov_z0_wrtPV")    .at(iTr)));
        tr->Set("err_phi",         TMath::Sqrt(Get<vector<float> > ("trk_cov_phi_wrtPV")   .at(iTr)));
        tr->Set("err_theta",       TMath::Sqrt(Get<vector<float> > ("trk_cov_theta_wrtPV") .at(iTr)));
        tr->Set("err_qoverp",      TMath::Sqrt(Get<vector<float> > ("trk_cov_qoverp_wrtPV").at(iTr)));
     
        //NOTE: ignoring COV(z0, theta) term... since we don't have it
        double err_z0SinTheta = TMath::Sqrt( pow(TMath::Sin(tr->p.Theta()) * tr->Float("err_z0"), 2) + pow(TMath::Cos(tr->p.Theta()) * tr->Float("z0") * tr->Float("err_theta") , 2) );
        tr->Set("err_z0SinTheta", err_z0SinTheta);
        
        tr->Set("IPtSig", (tr->Float("d0"))/(tr->Float("err_d0")));
        tr->Set("IPzSig", (tr->Float("z0SinTheta"))/(tr->Float("err_z0SinTheta")));
 
        tr->Set("nPixHits",          Get<vector<int> >  ("trk_nPixHits")             .at(iTr));
        tr->Set("nBLHits",           Get<vector<int> >  ("trk_nBLHits")              .at(iTr));
        tr->Set("nSCTHits",          Get<vector<int> >  ("trk_nSCTHits")             .at(iTr));
        tr->Set("nPixHoles",         Get<vector<int> >  ("trk_nPixHoles")            .at(iTr));
        tr->Set("nSCTHoles",         Get<vector<int> >  ("trk_nSCTHoles")            .at(iTr));
        tr->Set("nPixDeadSensors",   Get<vector<int> >  ("trk_nPixelDeadSensors")    .at(iTr));
        tr->Set("nSCTDeadSensors",   Get<vector<int> >  ("trk_nSCTDeadSensors")      .at(iTr));

        tr->Set("chi2",              Get<vector<float> >("trk_chi2")                 .at(iTr));
        tr->Set("ndof",              Get<vector<int> >  ("trk_ndof")                 .at(iTr));

        if(!doCOMMON){
          tr->Set("nBLSharedHits",     Get<vector<int> >  ("trk_nBLSharedHits")        .at(iTr));
          tr->Set("nPixSharedHits",    Get<vector<int> >  ("trk_nPixSharedHits")       .at(iTr));
          tr->Set("nSCTSharedHits",    Get<vector<int> >  ("trk_nSCTSharedHits")       .at(iTr));
        } 

        tr->Set("mc_barcode",        Get<vector<int> >  ("trk_mc_barcode")           .at(iTr));
        tr->Set("mc_probability",    Get<vector<float> >("trk_mc_probability")       .at(iTr));
        if(doCOMMON){
          tr->Set("mc_index",          Get<vector<int> >("trk_mc_index")               .at(iTr));
          int mcindex = tr->Int("mc_index");

          // track-truth association (before sorting so that mc_index is useful)
          if(fEvt->Debug()) cout << "In CopyTracks: track-truth association for track " << iTr << " and truth " << mcindex << endl;
          if(mcindex != -1){
            tr->AddVec("MatchedTruth_D3PD", true);
            tr->Add("MatchedTruth_D3PD", &fEvt->truth(mcindex));
          }
        }
      }

      fEvt->Add(mtracks,tr);
      
      // TrackZ collection
      if(doTrkJetBTag){
        if( tr->p.Pt() > 0.5                                &&
	          fabs(tr->p.Eta()) < 2.5                         &&
	          tr->Int("nPixHits") > 0                         &&
            (tr->Int("nPixHits") + tr->Int("nBLHits")) > 0  &&
	          tr->Int("nSCTHits") > 5                         &&
         	  (tr->Int("nPixHits") + tr->Int("nSCTHits")) > 6 &&
	          fabs(tr->Float("d0")) < 1                       &&
	          //fabs(tr->Float("z0")*sin(tr->Float("theta"))) < 1.5 &&
	          fabs(tr->Float("z0")) < 1.5                     &&
	          //fabs(tr->Float("z0_wrtBS")) < 200 &&
	          tr->Float("chi2") /  tr->Float("ndof") < 3
          )
          	fEvt->Add("tracks_trkZjet",tr);
      }
      
    }
  }
  if(fEvt->Debug()) cout << "set up tracks" << endl;
  return kTRUE;
}

Bool_t EventBuilder_Eflow::CopyVertices()
{

  static const MomKey mvtxs("vtxs"), ntrk("ntrk"), mNPV("NPV"), sumPt("sumPt"), chisq("chisq"), ndof("ndof");

  static const BranchKey bvxp_nTracks("vxp_nTracks"), bvxp_x("vxp_x"), bvxp_y("vxp_y"), 
                         bvxp_z("vxp_z"), bvxp_chisq("vxp_chi2"), bvxp_ndof("vxp_ndof"), bvxp_sumpt("vxp_sumPt"), bvxp_trk_index("vxp_trk_index");

  static const MomKey mvtxsTruth("vtxsTruth"), mNPVTruth("NPVTruth");
  static const BranchKey bmcVx_x("mcVx_x"), bmcVx_y("mcVx_y"), bmcVx_z("mcVx_z");
  static const BranchKey bmcVxSMWZ_x("mc_vx_x"), bmcVxSMWZ_y("mc_vx_y"), bmcVxSMWZ_z("mc_vx_z");

  if(doVertex){
    if(fEvt->isMC() ) {
      fEvt->AddVec(mvtxsTruth);

      unsigned int npvTruth = doSMWZ ?Get<vector<float> >(bmcVxSMWZ_z).size():Get<vector<float> >(bmcVx_z).size();
      fEvt->Set(mNPVTruth, npvTruth);
      
      for(unsigned int pvi = 0; pvi < npvTruth; pvi++) {
	    Point* vtx = new Point();
        if(!doSMWZ){
	        vtx->x.SetXYZ(Get<vector<float> >(bmcVx_x).at(pvi),Get<vector<float> >(bmcVx_y).at(pvi),Get<vector<float> >(bmcVx_z).at(pvi));
        }else{
	        vtx->x.SetXYZ(Get<vector<float> >(bmcVxSMWZ_x).at(pvi),Get<vector<float> >(bmcVxSMWZ_y).at(pvi),Get<vector<float> >(bmcVxSMWZ_z).at(pvi));
        }
	    fEvt->Add(mvtxsTruth, vtx);
      }
    }

    fEvt->AddVec(mvtxs);

    //Vertices
    int NPV=0;
    for(unsigned pvi=0;pvi<Get<vector<int> >(bvxp_nTracks).size();++pvi) {
      if(Get<vector<int> >(bvxp_nTracks).at(pvi) >= 2){
        ++NPV;
        Point* vtx = new Point();
        vtx->x.SetXYZ(Get<vector<float> >(bvxp_x).at(pvi),Get<vector<float> >(bvxp_y).at(pvi),Get<vector<float> >(bvxp_z).at(pvi));
        vtx->Set(ntrk,Get<vector<int> >(bvxp_nTracks).at(pvi));
        vtx->Set(sumPt, Get<vector<float> >(bvxp_sumpt).at(pvi)/1000.);
        vtx->Set(chisq, Get<vector<float> >(bvxp_chisq).at(pvi));
        vtx->Set(ndof, Get<vector<int> >(bvxp_ndof).at(pvi));
        vtx->AddVec("vtxTracks", true);
        vector<int> trk_index = Get<vector<vector<int> > >(bvxp_trk_index).at(pvi);
        for(int iTrk=0; iTrk<trk_index.size(); ++iTrk){
            vtx->Add("vtxTracks", &(fEvt->track(trk_index[iTrk])), true);
        }

        fEvt->Add(mvtxs,vtx);
      }
    }
    fEvt->Set(mNPV,NPV);

  }
  if(fEvt->Debug()) cout << "set up vtx" << endl;
  return kTRUE;
}


void EventBuilder_Eflow::WriteAuxTrees(TDirectory* outfile){
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
	
	TDirectory* origQCDMeta = (TDirectory*)file->Get("qcdMeta");
	TKey *key;
	TTree* confTree = 0;
   	TIter nextkey(origQCDMeta->GetListOfKeys());
   	while ((key = (TKey *) nextkey())) {
   		if (strcmp("TrigConfTree",key->GetName()) == 0) { //This should grab highest cycle, if there are more than one
			TDirectory::TContext ctxt(origQCDMeta);
			confTree = (TTree*)key->ReadObj();
			break;
		}
	}
	if(!confTree) Abort("EventBuilder_qcdMeta: ERROR cannot retrieve TrigConfTree from input file!");

	TDirectory* qcdMeta = (TDirectory*)outfile->Get("qcdMeta");
	if(!qcdMeta) {
		qcdMeta = outfile->mkdir("qcdMeta");
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



Bool_t EventBuilder_Eflow::GetJetCalibrationTools(){
  cout << "In EventBuilder_Eflow::GetJetCalibrationTools(), doJetCalibrations: " << doJetCalibrations << endl;


    data4EMCalibrator = (JetCalibrationTool*) fInput->FindObject("data4EMCalibrator");
    data6EMCalibrator = (JetCalibrationTool*) fInput->FindObject("data6EMCalibrator");

    data4LCCalibrator = (JetCalibrationTool*) fInput->FindObject("data4LCCalibrator");
    data6LCCalibrator = (JetCalibrationTool*) fInput->FindObject("data6LCCalibrator");

    mc4EMCalibrator = (JetCalibrationTool*) fInput->FindObject("mc4EMCalibrator");
    mc6EMCalibrator = (JetCalibrationTool*) fInput->FindObject("mc6EMCalibrator");
    
    mc4LCCalibrator = (JetCalibrationTool*) fInput->FindObject("mc4LCCalibrator");
    mc6LCCalibrator = (JetCalibrationTool*) fInput->FindObject("mc6LCCalibrator");

    afiimc4EMCalibrator = (JetCalibrationTool*) fInput->FindObject("afiimc4EMCalibrator");
    afiimc4EMCalibrator = (JetCalibrationTool*) fInput->FindObject("afiimc4EMCalibrator");
    afiimc6EMCalibrator = (JetCalibrationTool*) fInput->FindObject("afiimc6EMCalibrator");
    afiimc6EMCalibrator = (JetCalibrationTool*) fInput->FindObject("afiimc6EMCalibrator");
  
    m_myJesNorm = (MultijetJESUncertaintyProvider*) fInput->FindObject("JES");
    m_myJesAFII = (MultijetJESUncertaintyProvider*) fInput->FindObject("JESA");

    m_myJER = (JetSmearingTool*) fInput->FindObject("JER");

  return kTRUE;

}


