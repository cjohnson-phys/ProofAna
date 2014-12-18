
#define oldExample_cxx
#include "oldExample.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

#include "../MissingETUtility/METUtility.h"

#include "JetUncertainties/JetUncertainties/JESUncertaintyProvider.h"
#include "JetResolution/JERProvider/JERProvider.h"
#include "EnergyRescalerTool/EnergyRescaler.h"
#include "MuonMomentumCorrections/root/SmearingClass.h"




void oldExample::Loop()
{

 
 bool verbose = true;

 
 
  JESUncertaintyProvider _JES("AntiKt6LCTopoJets", "JetUncertainties/share/JESUncertainty.root");
  _JES.init();

  JERProvider _JER("AntiKt6TopoJES", "Truth", "JetResolution/share/JERProviderPlots.root");
  _JER.init();

  EnergyRescaler _egammaTool;
  _egammaTool.useDefaultCalibConstants("2011");

  SmearingClass _muonTool;
  _muonTool.UseScale(1);


  //start of loop/ntuple stuff
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   cout << "Entering loop" << endl;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;



      // if(jentry%1000==0) 
   if(verbose)    cout << "Event " << jentry << endl;


      ///note, these are just examples of how to get jet, electron, and muon uncertainties and resolutions. The MET tool won't do it for you, because how you calibrate the tools supplied by the performance group is analysis specific. So you have to get them and feed them to METUtlity, and it will make sure they are used in the correct manner for MET

      //you, the user, should get updated tools for yourself.

      //First, we get the jet energy scale uncertainties and the resolutions of the jets
     vector<float> jesUp;
      vector<float> jesDown;
      vector<float> jetResUp;
      vector<float> jetResDown;

      TRandom *jetRandom = new TRandom;
      jetRandom->SetSeed(EventNumber);

      for(unsigned int iJet = 0; iJet < jet_AntiKt6LCTopo_pt->size(); ++iJet){
	float jesShift = 0.14;
	float jerShift = 0.14;//this is just a default value for out of bound jets. Chosen from the value for eta > 2.1 to be conservative.
	float deltaJerShift = 0.0;
	if(jet_AntiKt6LCTopo_pt->at(iJet) > 15000.0 && jet_AntiKt6LCTopo_pt->at(iJet) < 7000000.0 && fabs(jet_AntiKt6LCTopo_eta->at(iJet)) < 4.5){
	  jesShift = _JES.getRelUncert(jet_AntiKt6LCTopo_pt->at(iJet), jet_AntiKt6LCTopo_eta->at(iJet));
	}
	jesUp.push_back(jesShift);
	jesDown.push_back(-1.0*jesShift);
	
	if(jet_AntiKt6LCTopo_pt->at(iJet) > 10000.0 && jet_AntiKt6LCTopo_pt->at(iJet) < 5000.0*1000.0){
	  jerShift = _JER.getSigma(jet_AntiKt6LCTopo_pt->at(iJet)/1000.0, jet_AntiKt6LCTopo_eta->at(iJet)); //dubious whether we should apply this to LC jets, derived for EMJES
	  deltaJerShift = _JER.getUncert(jet_AntiKt6LCTopo_pt->at(iJet)/1000.0, jet_AntiKt6LCTopo_eta->at(iJet));
	}

	float smearShiftUp = jetRandom->Gaus(0.0, jerShift+deltaJerShift);
	float smearShiftDown = jetRandom->Gaus(0.0, jerShift-deltaJerShift);


	jetResUp.push_back(smearShiftUp);
	jetResDown.push_back(smearShiftDown);
      }//end of jet loop
      
      //now we get the same for electrons. We also smear the electrons -- the method should be similar for photons
      vector<float> eesUp;
      vector<float> eesDown;
      vector<float> eerUp;
      vector<float> eerDown;
      vector<float> *el_smeared_pt = new vector<float>;
      
      for (unsigned int iEl = 0; iEl < el_pt->size(); ++iEl){

	_egammaTool.SetRandomSeed(int(1.e+5*fabs(el_phi))); //set the seed however you like, I'm following the SUSYTools example

	float smear = _egammaTool.getSmearingCorrection(el_cl_eta->at(iEl), el_E->at(iEl)/1000.0, 0, true);
	float smearUp = _egammaTool.getSmearingCorrection(el_cl_eta->at(iEl), el_E->at(iEl)/1000.0, 2, true);
	float smearDown = _egammaTool.getSmearingCorrection(el_cl_eta->at(iEl), el_E->at(iEl)/1000.0, 1, true);

	el_smeared_pt->push_back(smear*el_pt->at(iEl));
	eerUp.push_back((smearUp - smear)/smear);
	eerDown.push_back((smearDown - smear)/smear);
	double energyUp = 0.03; //EnergyRescaler does jack if you feed it a float
	double energyDown = -0.03;

	_egammaTool.getError(el_cl_eta->at(iEl), el_Et->at(iEl)/1000.0, energyUp, energyDown, "ELECTRON");

	eesUp.push_back(static_cast<float>(energyUp)); 
	eesDown.push_back(static_cast<float>(energyDown));
      }//end of electron loop
    

        //and now the same for muons
      vector<float> *mu_staco_smeared_pt = new vector<float>;
      // vector<float> *mu_staco_smeared_ms_qoverp = new vector<float>;
      // vector<float> *mu_staco_smeared_trackqoverp = new vector<float>; 
      vector<float> *mu_staco_smeared_ms_pt = new vector<float>;
      vector<float> *mu_staco_smeared_trackpt = new vector<float>; 

      vector<float> cb_meridUp;
      vector<float> cb_meridDown;
      vector<float> cb_mermsUp;
      vector<float> cb_mermsDown;
      vector<float> mermsUp;
      vector<float> mermsDown;

      vector<float> mesUp;
      vector<float> mesDown;

      
      for(unsigned int iMu = 0; iMu < mu_staco_pt->size(); ++iMu){


	double ptcb = mu_staco_pt->at(iMu);
	double combinedPt = ptcb;
	double ptid = (mu_staco_id_qoverp_exPV->at(iMu) != 0.) ? fabs(sin(mu_staco_id_theta_exPV->at(iMu))/mu_staco_id_qoverp_exPV->at(iMu)) : 0.;
	double ptms = (mu_staco_me_qoverp_exPV->at(iMu) != 0.) ? fabs(sin(mu_staco_me_theta_exPV->at(iMu))/mu_staco_me_qoverp_exPV->at(iMu)) : 0.;
	_muonTool.SetSeed(int(1.e+5*fabs(mu_staco_phi->at(iMu))));
	double etaMu = mu_staco_eta->at(iMu);
	_muonTool.Event(ptms, ptid, ptcb, etaMu);


	Float_t smearedCombinedPt = _muonTool.pTCB();
	if(!mu_staco_isCombinedMuon->at(iMu)) smearedCombinedPt = _muonTool.pTMS() + _muonTool.pTID();

	Float_t smearedMSPt = _muonTool.pTMS();


	mu_staco_smeared_ms_pt->push_back(ptms);
	mu_staco_smeared_pt->push_back(smearedCombinedPt);

	double ptMS_smeared, ptID_smeared, ptCB_smeared;
	float smearedpTMS, smearedpTID, smearedpTCB;
	smearedpTMS = 0.1; smearedpTID = 0.1; smearedpTCB = 0.1;
	_muonTool.PTVar(ptMS_smeared, ptID_smeared, ptCB_smeared, "MSLOW");
	smearedpTMS = ptMS_smeared/smearedMSPt - 1.0;
	smearedpTCB = ptCB_smeared/smearedCombinedPt - 1.0;
	mermsDown.push_back(smearedpTMS);
	cb_mermsDown.push_back(smearedpTCB);
	_muonTool.PTVar(ptMS_smeared, ptID_smeared, ptCB_smeared, "MSUP");
	smearedpTMS = ptMS_smeared/smearedMSPt - 1.0;
	smearedpTCB = ptCB_smeared/smearedCombinedPt - 1.0;
	mermsUp.push_back(smearedpTMS);
	cb_mermsUp.push_back(smearedpTCB);
	_muonTool.PTVar(ptMS_smeared, ptID_smeared, ptCB_smeared, "IDUP");
	smearedpTCB = ptCB_smeared/smearedCombinedPt - 1.0;
	cb_meridUp.push_back(smearedpTCB);
	_muonTool.PTVar(ptMS_smeared, ptID_smeared, ptCB_smeared, "IDDOWN");
	smearedpTCB = ptCB_smeared/smearedCombinedPt - 1.0;
	cb_meridDown.push_back(-1.0*smearedpTCB);//it always seems like ID up and down are the same. So I made down negative so that it's 1 - down. Note that the code assumes you've handled the sign. I don't know why it does this (or how I did it), all the others are of opposite sign
	
	//get energies uncertainty from smearing class itself, it's in there but without a function to retrieve them. And only for CB?
	if(fabs(mu_staco_eta->at(iMu)) < 1.05){
	  mesUp.push_back(0.0006);
	  mesDown.push_back(-0.0006);
	}
	else if (fabs(mu_staco_eta->at(iMu)) < 1.7){
	  mesUp.push_back(0.0013);
	  mesDown.push_back(-0.0013);
	}
	else if (fabs(mu_staco_eta->at(iMu)) < 2.0){
	  mesUp.push_back(0.0021);
	  mesDown.push_back(-0.0021);
	}
	else {
	  mesUp.push_back(0.0022);
	  mesDown.push_back(-0.0022);
	}

	
      }//end of muon loop
      
    

  if(verbose)     cout << "Checking Rebuilding from METComposition Map Works:" << endl;

      //this is an example of how to simply rebuild MET from available objects
      METUtility metCheck;
      metCheck.setCellFix(false);//there is a fix in the code that diverts objects with weight less than 0.5 to the CellOut term, for proper systematics handling. this shuts this off so we can check that the tool rebuilts the met to match the d3pd
      metCheck.setObjects("jets", jet_AntiKt6LCTopo_pt, jet_AntiKt6LCTopo_eta, jet_AntiKt6LCTopo_phi, jet_AntiKt6LCTopo_E, jet_AntiKt6LCTopo_MET_wet, jet_AntiKt6LCTopo_MET_wpx, jet_AntiKt6LCTopo_MET_wpy, jet_AntiKt6LCTopo_MET_statusWord); //there is also a setJetParameters function like electrons below. Or this function can be used with electrons as setObjects("electrons", ...)
     
      
          metCheck.setElectronParameters(el_pt, el_eta, el_phi, el_MET_wet, el_MET_wpx, el_MET_wpy, el_MET_statusWord);
      //metCheck.setPhotonParameters(ph_pt, ph_eta, ph_phi, ph_MET_wet, ph_MET_wpx, ph_MET_wpy, ph_MET_statusWord); //test sample for Silvia did not contain  photons/taus
      // metCheck.setTauParameters(tau_pt, tau_eta, tau_phi, tau_MET_wet, tau_MET_wpx, tau_MET_wpy, tau_MET_statusWord);
      

      metCheck.setMuonParameters(mu_staco_pt, mu_staco_eta, mu_staco_phi, mu_staco_MET_wet, mu_staco_MET_wpx, mu_staco_MET_wpy, mu_staco_MET_statusWord);
      metCheck.setExtraMuonParameters(mu_staco_ms_qoverp, mu_staco_ms_theta, mu_staco_ms_phi, mu_staco_charge); //muons require more info for track and spectro. There is also a setObjectMomenta(type, pt, eta, phi, E) that will fill these using the type argument as "spectromuons" or "trackmuons"
      //this accepts the qoverp variables to simplify things for the users. There is an overloaded function that takes pt instead (and leaves off charge), to simplify things when smearing. See below in smearing and scaling example


 

      //these objects are either not in the D3PD, or it isn't trustworthy to rebuild the term. Any term can be put in and used in place of being rebuilt, but only the SoftJets and CellOut_Eflow systematics can be returned in that form
      metCheck.setMETTerm("RefTau", MET_RefTau_etx, MET_RefTau_ety, MET_RefTau_sumet);  
      metCheck.setMETTerm("RefGamma", MET_RefGamma_etx, MET_RefGamma_ety, MET_RefGamma_sumet);
      metCheck.setMETTerm("RefMuon", MET_RefMuon_etx, MET_RefMuon_ety, MET_RefMuon_sumet); //I didn't feel it was a good idea to rebuilt RefMuon from smeared and scaled jets, since it is a calorimeter term and the smearings and scaling from MCP are spectrometer and tracker based.
      metCheck.setMETTerm("CellOut", MET_CellOut_etx, MET_CellOut_ety, MET_CellOut_sumet);
      metCheck.setMETTerm("CellOutEflow", MET_CellOut_Eflow_etx, MET_CellOut_Eflow_ety, MET_CellOut_Eflow_sumet);

      float refEle_et = metCheck.MissingET("RefEle").et();
      float refGamma_et = metCheck.MissingET("RefGamma").et();
      float refTau_et = metCheck.MissingET("RefTau").et();
      float refMuon_et = metCheck.MissingET("RefMuon").et();
      float refJet_et = metCheck.MissingET("RefJet").et();
      float refSoftJet_et = metCheck.MissingET("SoftJets").et();
      float refCellOut_et = metCheck.MissingET("CellOut").et();
      float refCellOutEflow_et = metCheck.MissingET("CellOutEflow").et();
      float muonTotal_et = metCheck.MissingET("MuonTotal").et();
      float refFinal_et = metCheck.MissingET("RefFinal").et();

      
      if(verbose) {
   cout << "+++++++++++++++++++++++++++++" << endl;
      cout << "Term:    Original       Tool output" << endl;
      cout << "Ref Ele et: " << MET_RefEle_et << " vs " << refEle_et << endl;
      cout << "Ref Gamma et: " << MET_RefGamma_et << " vs " << refGamma_et << endl;
      cout << "Ref Tau et: " << MET_RefTau_et << " vs " << refTau_et << endl;
      cout << "Ref Muon et: " << MET_RefMuon_et << " vs " << refMuon_et << endl;
      cout << "Ref Jet et: " << MET_RefJet_et << " vs " << refJet_et << endl;
      cout << "SoftJet et: " << MET_SoftJets_et << " vs " << refSoftJet_et << endl;
      cout << "MuonBoy et: " << MET_MuonBoy_et << " vs " << muonTotal_et << endl;
      cout << "CellOut_eflow et: " << MET_CellOut_Eflow_et << " vs " << refCellOutEflow_et << endl;
      cout << "Ref Final et: " << MET_RefFinal_et << " vs " << refFinal_et << endl;
      }      
      
      ////Note, everytime you call MissingET(term), that term or RefFinal gets reconstructed. I haven't added any logic against that or to make it intelligent, but you can simplify things by not doing it for different elements of MET, I.E., etx, ety, et, sumet, or phi 

      //Part of METUtility is an METObject that holds MET. 
      //Declare is like so:
      METObject myMET;
      //set it to the output of METUtility:
      myMET = metCheck.MissingET("RefFinal");
      if(verbose) {      cout << "RefFinal components, etx = " << myMET.etx() << ", ety = " << myMET.ety() << ", sumet = " << myMET.sumet() << ", phi = " << myMET.phi() << ", et = " << myMET.et() << endl;
      //and note, there is an additional helper function, sig(), that returns MET/.5*SQRT(SUMET)
       cout << "Significance of RefFinal is " << myMET.sig() << endl;
      cout << "+++++++++++++++++++++++++++++" << endl;
      cout << "RefFinal in D3PD components, etx = " << MET_RefFinal_etx << ", ety = " << MET_RefFinal_ety << ", sumet = " << MET_RefFinal_sumet << ", phi = " << MET_RefFinal_phi << ", et = " << MET_RefFinal_et << endl;

      cout << "+++++++++++++++++++++++++++++" << endl;
     


      cout << "Demonstration of smearing and systematics" << endl;
      }
      //this demonstration is for doing smearing and systematics

	METUtility metSys;
	metSys.setPileUpUncertainty(0.10);
	metSys.setCellFix(true);
	metSys.doForwardEtaCut(true);
	metSys.setObjects("jets", jet_AntiKt6LCTopo_pt, jet_AntiKt6LCTopo_eta, jet_AntiKt6LCTopo_phi, jet_AntiKt6LCTopo_E, jet_AntiKt6LCTopo_MET_wet, jet_AntiKt6LCTopo_MET_wpx, jet_AntiKt6LCTopo_MET_wpy, jet_AntiKt6LCTopo_MET_statusWord);
	metSys.setExtraJetParameters(jet_AntiKt6LCTopo_GCWJES, jet_AntiKt6LCTopo_m, jet_AntiKt6LCTopo_eta, jet_AntiKt6LCTopo_phi);	//	metSys.setScaleCorrections("jets", jet_AntiKt6LCTopo_EMJES);//this is necessary for systematics. When MET does overlap a cluster might be applied to an electron and a tau. If that cluster becomes an electron there may be some cells still associated with a tau and these get an MET weight for taus, but below .5. The same occurs for jets. The objects systematics should not be applied to the detritus, so these loose cells get shunted into CellOut/CellOut_Eflow. In the case of jets, these loose cells need the EMJES moment removed. So we divide by it when we shunt the cells.
	//note, the function metSys.setCellFix(bool) can override this. Set it to false and it will not happen at all

	//note that this is different in Example.C. The D3PDs that this was built off did not have the complete variables. Maybe it would be better to use emscale eta/phi. If you think so, do so. In the other file I used eta/phi origin.


	//putting in smeared and/or scaled objects will cause that to be reflected in MET
	metSys.setElectronParameters(el_smeared_pt, el_eta, el_phi, el_MET_wet, el_MET_wpx, el_MET_wpy, el_MET_statusWord);
	
	
	metSys.setMuonParameters(mu_staco_smeared_pt, mu_staco_eta, mu_staco_phi, mu_staco_MET_wet, mu_staco_MET_wpx, mu_staco_MET_wpy, mu_staco_MET_statusWord);
	//in this instance there is an overloaded version of setExtraMuonParameters that accepts smeared pTs for track and spectro
	metSys.setExtraMuonParameters(mu_staco_smeared_ms_pt, mu_staco_ms_theta, mu_staco_ms_phi);
	
	metSys.setMETTerm("RefTau", MET_RefTau_etx, MET_RefTau_ety, MET_RefTau_sumet);
	metSys.setMETTerm("RefGamma", MET_RefGamma_etx, MET_RefGamma_ety, MET_RefGamma_sumet);
	metSys.setMETTerm("RefMuon", MET_RefMuon_etx, MET_RefMuon_ety, MET_RefMuon_sumet);
	metSys.setMETTerm("CellOut", MET_CellOut_etx, MET_CellOut_ety, MET_CellOut_sumet);
	metSys.setMETTerm("CellOutEflow", MET_CellOut_Eflow_etx, MET_CellOut_Eflow_ety, MET_CellOut_Eflow_sumet);
	

	metSys.setObjectEnergyUncertainties("jets", jesUp, jesDown);
	metSys.setObjectResolutionShift("jets", jetResUp, jetResDown);

	metSys.setObjectEnergyUncertainties("electrons", eesUp, eesDown);
	metSys.setObjectResolutionShift("electrons", eerUp, eerDown);

	//the muons are nasty.
	metSys.setObjectResolutionShift("comboms", cb_mermsUp, cb_mermsDown); //muons are complicated, and MET makes use of track, spectro, and combined quantites, so we need all off their resolutions. comboms reflects that it is the combined muon res affected by shifting ms res up and down. comboid is for shifting the id res up and down
	metSys.setObjectResolutionShift("comboid", cb_meridUp, cb_meridDown);
	metSys.setObjectResolutionShift("spectromuons", mermsUp, mermsDown);
	//metSys.setObjectResolutionShift("trackmuons", meridUp, meridDown);

	metSys.setObjectEnergyUncertainties("muons", mesUp, mesDown); //for now the mes only affects combined

	if(verbose) {
	cout << "+++++++++++++++++++++++++++++" << endl;
	cout << "All these are the scalar MET term" << endl;
     	cout << "RefEle (smeared): " << metSys.MissingET("RefEle").et() << endl;
	cout << "RefGamma: " << metSys.MissingET("RefGamma").et() << endl;
	cout << "RefTau: " << metSys.MissingET("RefTau").et() << endl;
	cout << "SoftJets: " << metSys.MissingET("SoftJets").et() << endl;
	cout << "RefJet: " << metSys.MissingET("RefJet").et() << endl;
	cout << "RefMuon: " << metSys.MissingET("RefMuon").et() << endl;
	cout << "MuonBoy (smeared and scaled): " << metSys.MissingET("MuonTotal").et() << endl;
	cout << "CellOut_eflow: " << metSys.MissingET("CellOutEflow").et() << endl;
	cout << "RefFinal: " << metSys.MissingET("RefFinal").et() << endl;
	cout << "+++++++++++++++++++++++++++++" << endl;
	cout << endl;
     	cout << "+++++++++++++++++++++++++++++" << endl;
	cout << "RefJet JESUp: " << metSys.MissingET("RefJet", "JESUp").et() << ",  JESDown: " << metSys.MissingET("RefJet", "JESDown").et() << endl;
	cout << "RefJet JES Diff (up - down)/none : " << metSys.MissingET("RefJet", "JESDiff").et() << endl;
	cout << "RefFinal JESUp: " << metSys.MissingET("RefFinal", "JESUp").et() << ", JESDown: " << metSys.MissingET("RefFinal", "JESDown").et() << endl;
	cout << "RefFinal JES Diff (up - down)/none : " << metSys.MissingET("RefFinal", "JESDiff").et() << endl;
 	cout << "RefJet JERUp: " << metSys.MissingET("RefJet", "JERUp").et() << ", JERDown: " << metSys.MissingET("RefJet", "JERDown").et() << endl;
	cout << "RefJet JER Diff (up - down)/none : " << metSys.MissingET("RefJet", "JERDiff").et() << endl;
	cout << "RefFinal JERUp: " << metSys.MissingET("RefFinal", "JERUp").et() << ", JERDown: " << metSys.MissingET("RefFinal", "JERDown").et() << endl;
	cout << "RefFinal JER Diff (up - down)/none : " << metSys.MissingET("RefFinal", "JERDiff").et() << endl;
 	cout << "+++++++++++++++++++++++++++++" << endl;
	// Use SoftJetsUp and SoftJetsDown
	cout << "SoftJets Up: " << metSys.MissingET("SoftJets", "SoftJetsUp").et() << ", Down: " << metSys.MissingET("SoftJets", "SoftJetsDown").et() << endl;
  	cout << "SoftJets Diff (up - down)/none: " << metSys.MissingET("SoftJets", "SoftJetsDiff").et() << endl;
  	cout << "RefFinal SoftJets up: " << metSys.MissingET("RefFinal", "SoftJetsUp").et() << ", SoftJets down: " << metSys.MissingET("RefFinal", "SoftJetsDown").et()  << endl;
	cout << "RefFinal SoftJets Diff (up - down)/none: " << metSys.MissingET("RefFinal", "SoftJetsDiff").et() << endl;
  	cout << "+++++++++++++++++++++++++++++" << endl;
	cout << "RefEle EESUp: " << metSys.MissingET("RefEle", "EESUp").et() << ",  EESDown: " << metSys.MissingET("RefEle", "EESDown").et() << endl;
	cout << "RefFinal EESUp: " << metSys.MissingET("RefFinal", "EESUp").et() << ",  EESDown: " << metSys.MissingET("RefFinal", "EESDown").et() << endl;
	cout << "RefFinal EES Diff (up - down)/none : " << metSys.MissingET("RefFinal", "EESDiff").et() << endl;
 	cout << "RefEle EERUp: " << metSys.MissingET("RefEle", "EERUp").et() << ",  EERDown: " << metSys.MissingET("RefEle", "EERDown").et() << endl;
	cout << "RefFinal EERUp: " << metSys.MissingET("RefFinal", "EERUp").et() << ",  EERDown: " << metSys.MissingET("RefFinal", "EERDown").et() << endl;
	cout << "RefFinal EER Diff (up - down)/none : " << metSys.MissingET("RefFinal", "EERDiff").et() << endl;
 	cout << "+++++++++++++++++++++++++++++" << endl;
	cout << "MuonBoy MESUp: " << metSys.MissingET("MuonTotal", "MESUp").et() << ",  MESDown: " << metSys.MissingET("MuonTotal", "MESDown").et() << endl;
	cout << "RefFinal MESUp: " << metSys.MissingET("RefFinal", "MESUp").et() << ",  MESDown: " << metSys.MissingET("RefFinal", "MESDown").et() << endl;
	cout << "RefFinal MES Diff (up - down)/none : " << metSys.MissingET("RefFinal", "MESDiff").et() << endl;
 	cout << "MuonBoy MERIDUp: " << metSys.MissingET("MuonTotal", "MERIDUp").et() << ",  MERIDDown: " << metSys.MissingET("MuonTotal", "MERIDDown").et() << endl;
	cout << "RefFinal MERIDUp: " << metSys.MissingET("RefFinal", "MERIDUp").et() << ",  MERIDDown: " << metSys.MissingET("RefFinal", "MERIDDown").et() << endl;
	cout << "RefFinal MERID Diff (up - down)/none : " << metSys.MissingET("RefFinal", "MERIDDiff").et() << endl;
	cout << "MuonBoy MERMSUp: " << metSys.MissingET("MuonTotal", "MERMSUp").et() << ",  MERMSDown: " << metSys.MissingET("MuonTotal", "MERMSDown").et() << endl;
	cout << "RefFinal MERMSUp: " << metSys.MissingET("RefFinal", "MERMSUp").et() << ",  MERMSDown: " << metSys.MissingET("RefFinal", "MERMSDown").et() << endl;
	cout << "RefFinal MERMS Diff (up - down)/none : " << metSys.MissingET("RefFinal", "MERMSDiff").et() << endl;
	cout << "+++++++++++++++++++++++++++++" << endl;
	///the cellout systematic is based on sumet of cellout, so the objects aren't needed. the numbers are from the May 2011 MET PLHC paper and include the affects predicted by different MC (Professor vs Perugia, etc) and cluster energy scale uncertainty
	cout << "CellOut_Eflow Up: " << metSys.MissingET("CellOutEflow", "CellOutEflowUp").et() << " CellOutEflow Down: " << metSys.MissingET("CellOutEflow", "CellOutDown").et() << endl;
	cout << "RefFinal, CellOut_Eflow up: " << metSys.MissingET("RefFinal", "CellEflowOutUp").et() << " CellOut_Eflow down: " << metSys.MissingET("RefFinal", "CellOutDown").et() << endl;
	cout << "+++++++++++++++++++++++++++++" << endl;
	cout << "Pile Up, RefFinal Up: " << metSys.MissingET("RefFinal", "PileUpUp").et() << ", PileUpDown: " << metSys.MissingET("RefFinal", "PileUpDown").et() << endl;
	cout << "+++++++++++++++++++++++++++++" << endl;
	cout << "+++++++++++++++++++++++++++++" << endl;
	cout << "Combined errors, giving an uncertainty on MET" << endl;
	METObject smearedMET = metSys.MissingET("RefFinal");
	cout << "RefFinal MET = " << smearedMET.et() << " +- " << metSys.absDeltaMissingET("RefFinal").et() << " (" << 100*metSys.deltaMissingET("RefFinal").et() << "%)" << endl;
	cout << endl;

	}
     
   }//end of loop


}//end of macro

