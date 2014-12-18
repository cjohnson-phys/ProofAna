#define Example_cxx
#include "Example.h"
#include "TMath.h"
#include "TH1D.h"
#include "TFile.h"
#include "../MissingETUtility/METUtility.h"
#include "JetUncertainties/MultijetJESUncertaintyProvider.h"
#include "ApplyJetCalibration/ApplyJetCalibration.h"
#include "ApplyJetResolutionSmearing/ApplyJetSmearing.h"
#include "egammaAnalysisUtils/EnergyRescalerUpgrade.h"
#include "MuonMomentumCorrections/SmearingClass.h"
#include "TesUncertaintyProvider/TESUncertaintyProvider.h"

void Example::Begin(TTree */*tree*/)
{
  m_verbose = false;
  m_isData = false;
  m_is2012 = false;

  // Initialise your METUtility object
  m_testUtil = new METUtility;

  // *** Demonstration of the configuration here  ***
  // *** All values that are set are the defaults ***

  // Turn on (off) the relevant MET terms
  // Standard MET_RefFinal has:
  // RefEle, RefGamma, RefTau, RefJet, RefMuon, MuonTotal, CellOut_Eflow
  m_testUtil->defineMissingET(true, true, true, true, false, true, true);

  // Choose the type of RefJet pileup suppression, if any
  // m_testUtil->setJetPUcode(MissingETTags::JPU_JET_JVFCUT);

  // Whether to use MUID muons (otherwise STACO).
  m_testUtil->setIsMuid(false);

  // Whether METUtility should scream at you over every little thing
  m_testUtil->setVerbosity(false);

  m_systUtil = new METUtility;

  // Some other options are available, but not recommended/deprecated

  // *** Set up the calibration/uncertainty tools ***
  // Tag assumed: ApplyJetCalibration-00-03-03
  m_jetCalibTool = new JetCalibrationTool("AntiKt4LCTopo", "JES_Full2012dataset_Preliminary_Jan13.config", m_isData);

  // Tag assumed: JetUncertainties-00-08-02
  m_jesTool = new MultijetJESUncertaintyProvider("JES_2012/Moriond2013/MultijetJES_2012.config",
						 "JES_2012/Moriond2013/InsituJES2012_14NP.config",
						 "AntiKt4LCTopo","MC12a");

  // Tag assumed: ApplyJetResolutionSmearing-00-01-02
  m_jerTool = new JetSmearingTool("AntiKt4LCTopo","JERProviderPlots_2012.root");
  m_jerTool->init();

  // Tag assumed: egammaAnalysisUtils-00-04-17
  m_egammaTool = new egRescaler::EnergyRescalerUpgrade;
  m_egammaTool->Init("../../../InstallArea/share/EnergyRescalerData.root","2012","es2012");

  // Tag assumed: MuonMomentumCorrections-00-08-05
  m_muonTool = new MuonSmear::SmearingClass("Data12","staco","q_pT","Rel17.2Repro");
  m_muonTool->UseScale(1);
  m_muonTool->UseImprovedCombine();

  // No tag yet, testing code
  m_tesTool = new TESUncertaintyProvider;

  // Prepare an output file
  m_outfile = new TFile("metutil_example.root","RECREATE");
  // Set up a bunch of histograms
  h_RefFinal = new TH1D("h_RefFinal","RefFinal",50,0,500);
  // Jet systematics
  h_RefFinal_JESUp = new TH1D("h_RefFinal_JESUp",
			      "RefFinal JESUp",50,0,500);
  h_RefFinal_JESDown = new TH1D("h_RefFinal_JESDown",
				"RefFinal JESDown",50,0,500);
  h_RefFinal_JERUp = new TH1D("h_RefFinal_JERUp",
			      "RefFinal JERUp",50,0,500);
  // Electron systematics
  h_RefFinal_EESUp = new TH1D("h_RefFinal_EESUp",
			      "RefFinal EESUp",50,0,500);
  h_RefFinal_EESDown = new TH1D("h_RefFinal_EESDown",
				"RefFinal EESDown",50,0,500);
  h_RefFinal_EERUp = new TH1D("h_RefFinal_EERUp",
			      "RefFinal EERUp",50,0,500);
  h_RefFinal_EERDown = new TH1D("h_RefFinal_EERDown",
				"RefFinal EERDown",50,0,500);
  // Photon systematics
  h_RefFinal_PESUp = new TH1D("h_RefFinal_PESUp",
			      "RefFinal PESUp",50,0,500);
  h_RefFinal_PESDown = new TH1D("h_RefFinal_PESDown",
				"RefFinal PESDown",50,0,500);
  h_RefFinal_PERUp = new TH1D("h_RefFinal_PERUp",
			      "RefFinal PERUp",50,0,500);
  h_RefFinal_PERDown = new TH1D("h_RefFinal_PERDown",
				"RefFinal PERDown",50,0,500);
  // Muon systematics
  h_RefFinal_MESUp = new TH1D("h_RefFinal_MESUp",
			      "RefFinal MESUp",50,0,500);
  h_RefFinal_MESDown = new TH1D("h_RefFinal_MESDown",
				"RefFinal MESDown",50,0,500);
  h_RefFinal_MERIDUp = new TH1D("h_RefFinal_MERIDUp",
				"RefFinal MERIDUp",50,0,500);
  h_RefFinal_MERIDDown = new TH1D("h_RefFinal_MERIDDown",
				  "RefFinal MERIDDown",50,0,500);
  h_RefFinal_MERMSUp = new TH1D("h_RefFinal_MERMSUp",
				"RefFinal MERMSUp",50,0,500);
  h_RefFinal_MERMSDown = new TH1D("h_RefFinal_MERMSDown",
				  "RefFinal MERMSDown",50,0,500);
  // Soft terms systematics
  h_RefFinal_ScaleSoftTermsUp = new TH1D("h_RefFinal_ScaleSoftTermsUp",
					 "RefFinal ScaleSoftTermsUp",50,0,500);
  h_RefFinal_ScaleSoftTermsDown = new TH1D("h_RefFinal_ScaleSoftTermsDown",
					   "RefFinal ScaleSoftTermsDown",50,0,500);
  h_RefFinal_ResoSoftTermsUp = new TH1D("h_RefFinal_ResoSoftTermsUp",
					"RefFinal ResoSoftTermsUp",50,0,500);
  h_RefFinal_ResoSoftTermsDown = new TH1D("h_RefFinal_ResoSoftTermsDown",
					  "RefFinal ResoSoftTermsDown",50,0,500);
  // Alternate soft terms systematics
  h_RefFinal_ScaleSoftTermsUp_ptHard = new TH1D("h_RefFinal_ScaleSoftTermsUp_ptHard",
						"RefFinal ScaleSoftTermsUp_ptHard",50,0,500);
  h_RefFinal_ScaleSoftTermsDown_ptHard = new TH1D("h_RefFinal_ScaleSoftTermsDown_ptHard",
						  "RefFinal ScaleSoftTermsDown_ptHard",50,0,500);
  h_RefFinal_ResoSoftTermsUp_ptHard = new TH1D("h_RefFinal_ResoSoftTermsUp_ptHard",
					       "RefFinal ResoSoftTermsUp_ptHard",50,0,500);
  h_RefFinal_ResoSoftTermsUpDown_ptHard = new TH1D("h_RefFinal_ResoSoftTermsUpDown_ptHard",
						   "RefFinal ResoSoftTermsUpDown_ptHard",50,0,500);
  h_RefFinal_ResoSoftTermsDownUp_ptHard = new TH1D("h_RefFinal_ResoSoftTermsDownUp_ptHard",
						   "RefFinal ResoSoftTermsDownUp_ptHard",50,0,500);
  h_RefFinal_ResoSoftTermsDown_ptHard = new TH1D("h_RefFinal_ResoSoftTermsDown_ptHard",
						 "RefFinal ResoSoftTermsDown_ptHard",50,0,500);

  // Test of correlations
  h_RefFinal_JESUp_ScaleSoftTermsUp = new TH1D("h_RefFinal_JESUp_ScaleSoftTermsUp",
					       "RefFinal JESUp_ScaleSoftTermsUp",50,0,500);
  h_RefFinal_JESUp_ScaleSoftTermsDown = new TH1D("h_RefFinal_JESUp_ScaleSoftTermsDown",
						 "RefFinal JESUp_ScaleSoftTermsDown",50,0,500);
  h_RefFinal_JESDown_ScaleSoftTermsUp = new TH1D("h_RefFinal_JESDown_ScaleSoftTermsUp",
						 "RefFinal JESDown_ScaleSoftTermsUp",50,0,500);
  h_RefFinal_JESDown_ScaleSoftTermsDown = new TH1D("h_RefFinal_JESDown_ScaleSoftTermsDown",
						   "RefFinal JESDown_ScaleSoftTermsDown",50,0,500);
}

Bool_t Example::Process(Long64_t entry)
{
  // This just makes sure aliases are set to some generic objects
  EventReader::Process(entry);

  // See this method for an example of setting up the METUtility
  // such that it can rebuild the D3PD nominal MET values.
  Example::CheckMetRebuilding(m_verbose);

  // See this method for an example of how to pass object systematics
  // to METUtility such that they can be propagated to the MET.
  Example::DemoMetSystematics(m_verbose,m_isData);

  return kTRUE;
}

void Example::CheckMetRebuilding(bool verbose)
{

  //////////////////////////////////////////////////////////////////////////////
  // Demonstrates how to set up the METUtility with object momenta such that
  // MET_RefFinal can be rebuilt matching the values in D3PD.

  // Start with a clean METUtility
  m_testUtil->reset();

  // Fix for messed up NTUP_JETMET
  vector<vector<float> > *ph_MET_wet_new = new vector<vector<float> >;
  vector<vector<float> > *ph_MET_wpx_new = new vector<vector<float> >;
  vector<vector<float> > *ph_MET_wpy_new = new vector<vector<float> >;
  vector<vector<unsigned int> > *ph_MET_statusWord_new = new vector<vector<unsigned int> >;
  for (int iph=0; iph<ph_n; iph++){
      ph_MET_wet_new->push_back(ph_MET_wet->at(iph));
      ph_MET_wpx_new->push_back(ph_MET_wpx->at(iph));
      ph_MET_wpy_new->push_back(ph_MET_wpy->at(iph));
      ph_MET_statusWord_new->push_back(ph_MET_statusWord->at(iph));
  }

  vector<vector<float> > *el_MET_wet_new = new vector<vector<float> >;
  vector<vector<float> > *el_MET_wpx_new = new vector<vector<float> >;
  vector<vector<float> > *el_MET_wpy_new = new vector<vector<float> >;
  vector<vector<unsigned int> > *el_MET_statusWord_new = new vector<vector<unsigned int> >;
  for (int iel=0; iel<el_n; iel++){
    el_MET_wet_new->push_back(el_MET_wet->at(iel));
    el_MET_wpx_new->push_back(el_MET_wpx->at(iel));
    el_MET_wpy_new->push_back(el_MET_wpy->at(iel));
    el_MET_statusWord_new->push_back(el_MET_statusWord->at(iel));
  }

  if(int(el_MET_wet->size())>el_n) {

    for(int iel=el_n; iel<int(el_MET_wet->size()); iel++) {
      if (el_MET_wet->at(iel).at(0)>1.e-9) cout << "This one!" << endl;
      break;
    }
  }

  // For these, just the kinematics need to be set
  m_testUtil->setElectronParameters(el_pt, el_eta, el_phi,
				    el_MET_wet_new, el_MET_wpx_new, el_MET_wpy_new,
				    el_MET_statusWord_new);

  m_testUtil->setPhotonParameters(ph_pt, ph_eta, ph_phi,
				  ph_MET_wet_new, ph_MET_wpx_new, ph_MET_wpy_new,
				  ph_MET_statusWord_new);

  //  Tau rebuilding should be checked -- tau reco may be rerun in D3PD-making,
  //  and it must be ensured that this is performed prior to MET recalculation
  m_testUtil->setTauParameters(tau_pt, tau_eta, tau_phi,
			     tau_MET_wet, tau_MET_wpx, tau_MET_wpy,
			     tau_MET_statusWord);

  //  Cluster rebuilding is just for specialist studies
  //  m_testUtil->setClusterParameters(cl_pt, cl_eta, cl_phi,
  //				 cl_MET_wet, cl_MET_wpx, cl_MET_wpy,
  //				 cl_MET_statusWord);

  //  Track rebuilding is just for specialist studies
  //  m_testUtil->setTrackParameters(trk_pt, trk_eta, trk_phi,
  //			       trk_MET_wet, trk_MET_wpx, trk_MET_wpy,
  //			       trk_MET_statusWord);

  // The SoftJets term is now to be taken from D3PD, and no "hard jets" are allowed
  // to enter it. Recalibration or smearing could cause jets that were above the
  // 20 GeV threshold to drop below it, so we supply the original pT's to prevent
  // them from being moved out of RefJet.
  //
  // In p1328/p1344 and later D3PD tags, SoftJets is combined with CellOut(_Eflow)
  // and soft jet weights are always 0, so setOriJetParameters is deprecated.

  vector<float> *jet_pt_new  = new vector<float>;
  vector<float> *jet_eta_new = new vector<float>;
  vector<float> *jet_phi_new = new vector<float>;
  vector<float> *jet_E_new   = new vector<float>;
  for (int ijet=0; ijet<int(jet_MET_statusWord->size()); ijet++){
      jet_pt_new->push_back(jet_pt->at(ijet));
      jet_eta_new->push_back(jet_eta->at(ijet));
      jet_phi_new->push_back(jet_phi->at(ijet));
      jet_E_new->push_back(jet_E->at(ijet));
  }

  m_testUtil->setJetParameters(jet_pt_new, jet_eta_new, jet_phi_new, jet_E_new,
			       jet_MET_wet, jet_MET_wpx, jet_MET_wpy,
			       jet_MET_statusWord);

  // Muons may be ID, combined, or standalone. For the latter especially,
  // we need to set the MS four-momenta because they are treated differently.
  m_testUtil->setMuonParameters(mu_pt, mu_eta, mu_phi,
			      mu_MET_wet, mu_MET_wpx, mu_MET_wpy,
			      mu_MET_statusWord);
  m_testUtil->setExtraMuonParameters(mu_ms_qoverp, mu_ms_theta, mu_ms_phi, mu_charge);
  // An alternative version of this method is demonstrated below, and takes pT, eta, phi instead.
  // This is more convenient when one needs to smear the pT, for example.

  // When the terms are not rebuilt from the objects, due to incomplete info,
  // then one needs to set the term directly from the stored value in the D3PD.
  // This might also be done if you aren't interested in the possible variations
  // of that term. E.g. if you only care about photons, no need to rebuild muons.

  // m_testUtil->setMETTerm(METUtil::RefJet, MET_RefJet_etx, MET_RefJet_ety, MET_RefJet_sumet);  
  // m_testUtil->setMETTerm(METUtil::SoftJets, MET_SoftJets_etx, MET_SoftJets_ety, MET_SoftJets_sumet);  
  // m_testUtil->setMETTerm(METUtil::RefEle, MET_RefEle_etx, MET_RefEle_ety, MET_RefEle_sumet);  
  // m_testUtil->setMETTerm(METUtil::RefGamma, MET_RefGamma_etx, MET_RefGamma_ety, MET_RefGamma_sumet);

  // *** Note the difference in naming -- there is normally no MET_MuonTotal term.
  //     It's usually Muon_Total, Muon_Total_Muid, something like that.
  //     MET_RefFinal in particular uses MET_MuonBoy.
  // m_testUtil->setMETTerm(METUtil::MuonTotal, MET_MuonBoy_etx, MET_MuonBoy_ety, MET_MuonBoy_sumet);

//   Needed for reading some d3pds such as SMWZ
//   double MET_RefFinal_etx = MET_RefFinal_et*cos(MET_RefFinal_phi);
//   double MET_RefFinal_ety = MET_RefFinal_et*sin(MET_RefFinal_phi);

//   double MET_RefEle_etx = MET_RefEle_et*cos(MET_RefEle_phi);
//   double MET_RefEle_ety = MET_RefEle_et*sin(MET_RefEle_phi);

//   double MET_RefGamma_etx = MET_RefGamma_et*cos(MET_RefGamma_phi);
//   double MET_RefGamma_ety = MET_RefGamma_et*sin(MET_RefGamma_phi);

//   double MET_RefJet_etx = MET_RefJet_et*cos(MET_RefJet_phi);
//   double MET_RefJet_ety = MET_RefJet_et*sin(MET_RefJet_phi);

//   double MET_MuonBoy_etx = MET_MuonBoy_et*cos(MET_MuonBoy_phi);
//   double MET_MuonBoy_ety = MET_MuonBoy_et*sin(MET_MuonBoy_phi);

//   double MET_RefTau_etx = MET_RefTau_et*cos(MET_RefTau_phi);
//   double MET_RefTau_ety = MET_RefTau_et*sin(MET_RefTau_phi);

//   double MET_CellOut_Eflow_etx = MET_CellOut_Eflow_et*cos(MET_CellOut_Eflow_phi);
//   double MET_CellOut_Eflow_ety = MET_CellOut_Eflow_et*sin(MET_CellOut_Eflow_phi);

  // *** Note that RefMuon is not rebuilt from muons -- it is a calorimeter term.
  //     Don't use if MET is rebuilt from AOD (RefMuon==0), as the D3PD branch is from ESD.
  // m_testUtil->setMETTerm(METUtil::RefMuon, MET_RefMuon_etx, MET_RefMuon_ety, MET_RefMuon_sumet);
  m_testUtil->setMETTerm(METUtil::RefTau, MET_RefTau_etx, MET_RefTau_ety, MET_RefTau_sumet);
  m_testUtil->setMETTerm(METUtil::SoftTerms, MET_CellOut_Eflow_etx, MET_CellOut_Eflow_ety, MET_CellOut_Eflow_sumet);

  // This is the simple check, where you compare the terms manually against what's in the D3PD.
  // Note: every call to getMissingET recomputes the terms, so if you need to get more than one
  // value, e.g. etx, ety, et, sumET, it's more efficient to get the METUtility::METObject.
  // Usually, comparing etx and/or ety is more informative, because et could be right if
  // etx and ety were flipped, for example. They also add linearly, which et doesn't.
  
  METUtility::METObject RefEle_util = m_testUtil->getMissingET(METUtil::RefEle);
  METUtility::METObject RefGamma_util = m_testUtil->getMissingET(METUtil::RefGamma);
  METUtility::METObject RefTau_util = m_testUtil->getMissingET(METUtil::RefTau);
  //   METUtility::METObject RefMuon_util = m_testUtil->getMissingET(METUtil::RefMuon);
  METUtility::METObject RefJet_util = m_testUtil->getMissingET(METUtil::RefJet);
  METUtility::METObject CellOut_util = m_testUtil->getMissingET(METUtil::SoftTerms);
  METUtility::METObject MuonTotal_util = m_testUtil->getMissingET(METUtil::MuonTotal);
  METUtility::METObject RefFinal_util = m_testUtil->getMissingET(METUtil::RefFinal);
  
  // If you don't want to test manually, there's a built-in consistency check.
  // To test just one term, fill a METUtility::METObject with the appropriate values,
  // then feed it to the checkConsistency() method.
  // The difference can be retrieved via a reference argument.

  METUtility::METObject refFinal_test(MET_RefFinal_etx,
			  MET_RefFinal_ety,
			  MET_RefFinal_sumet);
  bool check_refFinal = m_testUtil->checkConsistency(refFinal_test,METUtil::RefFinal);
  if(check_refFinal) {if(verbose) cout << "RefFinal checks out!" << endl;}
  else cout << "RefFinal doesn't check out!" << endl;

  // By filling a vector of terms, you can test all of them in one function call.
  // The sum (and sumET) will be tested as well. (Can't get the difference this way).
  METUtility::METObject refEle_test(MET_RefEle_etx,
			MET_RefEle_ety,
			MET_RefEle_sumet);
//   METUtility::METObject refGamma_test(MET_RefGamma_etx,
// 			MET_RefGamma_ety,
// 			MET_RefGamma_sumet);
  METUtility::METObject refJet_test(MET_RefJet_etx,
			MET_RefJet_ety,
			MET_RefJet_sumet);
  METUtility::METObject muonBoy_test(MET_MuonBoy_etx,
			 MET_MuonBoy_ety,
			 MET_MuonBoy_sumet);
  vector<pair<int,METUtility::METObject> > testvector;
  testvector.push_back(pair<int,METUtility::METObject>(METUtil::RefEle,refEle_test));
//   testvector.push_back(pair<int,METUtility::METObject>(METUtil::RefGamma,refGamma_test));
  testvector.push_back(pair<int,METUtility::METObject>(METUtil::RefJet,refJet_test));
  testvector.push_back(pair<int,METUtility::METObject>(METUtil::MuonTotal,muonBoy_test));

  bool check = m_testUtil->checkConsistency(testvector);
  if(check) {if(verbose) cout << "MET checks out!" << endl;}
  else cout << "MET doesn't check out!" << endl;

  if(verbose || !check_refFinal || !check)  {
    cout << "** Manual consistency check **" << endl << endl;
    cout << "Term:    Original   vs    Tool output" << endl;
    cout << "RefEle etx: "    << MET_RefEle_etx   << " vs " << RefEle_util.etx()    << endl;
    cout << "RefGamma etx: "  << MET_RefGamma_etx << " vs " << RefGamma_util.etx()  << endl;
    cout << "RefTau etx: "    << MET_RefTau_etx   << " vs " << RefTau_util.etx()    << endl;
    //    cout << "RefMuon etx: "   << MET_RefMuon_etx  << " vs " << RefMuon_util.etx()   << endl;
    cout << "RefJet etx: "    << MET_RefJet_etx   << " vs " << RefJet_util.etx()   << endl;
    cout << "MuonBoy etx: "   << MET_MuonBoy_etx  << " vs " << MuonTotal_util.etx() << endl;
    cout << "CellOut etx: " << MET_CellOut_Eflow_etx << " vs " << CellOut_util.etx() << endl;
    cout << "RefFinal etx: "  << MET_RefFinal_etx << " vs " << RefFinal_util.etx()  << endl << endl;
  }

  // In addition to the etx, ety, sumet retrieval, you can also get the MET significance.
  // By default, METUtility::METObject::sig() returns etx() / ( 0.5*sqrt(sumet()) )
  // 
  // There is also the possibility of returning a more sophisticated estimator for
  // the significance, activated by calling METUtility::doSignificance() in setup.
  // This is still under development, and requires all object resolutions to be set.

  delete jet_pt_new;
  delete jet_eta_new;
  delete jet_phi_new;
  delete jet_E_new;

  delete ph_MET_wet_new;
  delete ph_MET_wpx_new;
  delete ph_MET_wpy_new;
  delete ph_MET_statusWord_new;

  delete el_MET_wet_new;
  delete el_MET_wpx_new;
  delete el_MET_wpy_new;
  delete el_MET_statusWord_new;

}

void Example::DemoMetSystematics(bool verbose, bool isData)
{

  //////////////////////////////////////////////////////////////////////////////
  // Demonstrates how to set up the METUtility with object momenta
  // such that MET_RefFinal can be rebuilt matching the values in D3PD.
  //
  // *** *** *** *** *** DISCLAIMER *** *** *** *** ***
  //
  // These examples of uncertainty-setting are meant to
  // demonstrate how the uncertainties should be passed
  // to METUtility.  Recommendations on just which ones
  // you are meant to be using come from the CP groups.

  // Check for a good primary vertex
  // This is needed for jet and soft term systematics
  int nvtxsoftmet = 0;
  int nvtxjets = 0;
  if(vxp_n>0) {
    // Most D3PDs contain the vx_type branch, but some don't.
    // Those which don't are most likely skimmed, and require at least 1 primary vertex for all events.
    // If your D3PD is skimmed in this way, then the goodPV (nTracks and z) check should be applied
    // to the first vertex in the collection.
    // Otherwise, you should ensure that the vx_type branch is available.
    for(int i=0; i<vxp_n; i++) {
      if(vxp_nTracks->at(i)>2) nvtxsoftmet++;
      if(vxp_nTracks->at(i)>1) nvtxjets++;
    }
  }
  vector<float> jet_calibpT, jet_calibE;
  // First, we get the jet energy scale uncertainties and
  // systematic variation in the jet resolutions
  vector<float> jerUp;
  vector<float> jerDown;
  vector<vector<float> > jet_jesUp, jet_jesDown; // For multiple nuisance parameters

  for(unsigned int iJet = 0; iJet < jet_pt->size(); ++iJet){

    TLorentzVector jetlv = m_jetCalibTool->ApplyJetAreaOffsetEtaJES(jet_constscale_E->at(iJet),
								    jet_constscale_eta->at(iJet),
								    jet_constscale_phi->at(iJet),
								    jet_constscale_m->at(iJet),
								    jet_ActiveAreaPx->at(iJet),
								    jet_ActiveAreaPy->at(iJet),
								    jet_ActiveAreaPz->at(iJet),
								    jet_ActiveAreaE->at(iJet),
								    Eventshape_rhoKt4LC,
								    averageIntPerXing,
								    nvtxjets);

    jet_calibpT.push_back(jetlv.Pt());
    jet_calibE.push_back(jetlv.E());

    float jesShift = 0.0;
    float jerShift = 1.0;

    // Use ApplyJetResolutionSmearing package, recommended for Moriond 2013
    if(jetlv.Pt() > 20e3 && jetlv.Pt() < 5000e3) {
      TLorentzVector jetlv_smear(jetlv);
      m_jerTool->SmearJet_Syst(jetlv_smear);
      jerShift = jetlv_smear.Pt()/jetlv.Pt();
    }

    jerUp.push_back(jerShift-1.);
    jerDown.push_back(1.-jerShift);

    //////////////////////////////////////////////////////////////////////
    // Note: The JERDown shift is essentially meaningless.
    // If one is smearing central values, then there is an alternate
    // definition, i.e. from r16:
    //
    // S = m_jerTool.getRelResolutionData(pt/1e3,eta);
    // SMC = m_jerTool.getRelResolutionMC(pt/1e3,eta);
    // U = m_jerTool.getResolutionUncert(pt/1e3,eta);
    // smearingFactorMC = sqrt( S*S - SMC*SMC );
    // smearingFactorSystUp = sqrt( (S+U)*(S+U) - SMC*SMC );
    // smearingFactorSystDown = (S-U > SMC) ? sqrt( (S+U)*(S+U) - SMC*SMC ) : 0;
    // 
    // float jerShift = jetRandom->Gaus(1,smearingFactorMC);
    // float jerShiftUp = jetRandom->Gaus(1,smearingFactorSystUp)/jerShift;
    // float jerShiftDown = jetRandom->Gaus(1,smearingFactorSystDown)/jerShift;
    //
    // jet_smeared_pt = pt*jerShift;
    // jerUp.push_back(jerShiftUp-1);
    // jerDown.push_back(jerShiftDown-1);
    //
    // This means that we smear the MC jets to match the resolution in data
    // for central values, or the resolution +/- uncertainty.
    // The standard practice is only to use res + uncertainty.
    //
    //////////////////////////////////////////////////////////////////////

    bool goodjet = false;
    goodjet = (jet_calibpT.at(iJet) > 20e3 && fabs(jet_eta->at(iJet)) < 4.5);
    
    // JetUncertainties for Moriond 2013 (14 NP)
    double eta = jet_eta->at(iJet); // uncalibrated
    double pt = jetlv.Pt(); // recalibrated

    // Loop over baseline uncertainty components
    int Ncomp=m_jesTool->getNUncertaintyComponents();
    int icomp=0; // can use this for other components not in the loop
    vector<float> newvectup, newvectdown;
    for (;icomp<Ncomp;++icomp) {
      if(icomp>=int(jet_jesUp.size())) {
	jet_jesUp.push_back(newvectup);
	jet_jesDown.push_back(newvectdown);
      }

      jesShift = m_jesTool->getRelUncertComponent(icomp, pt, eta);
      // nuisance paramter amplitude (with sign) ("relative uncertainty" of component) 
      // can also use  j.getRelUncertComponent(compName, pt, eta);

      jet_jesUp[icomp].push_back(goodjet ? jesShift : 0.);
      jet_jesDown[icomp].push_back(goodjet ? -1.*jesShift : 0.);
    }

    // Pileup uncertainties
    // 1.
    jesShift = m_jesTool->getRelNPVOffsetTerm(pt,eta,nvtxjets);
    if(icomp>=int(jet_jesUp.size())) {
      jet_jesUp.push_back(newvectup);
      jet_jesDown.push_back(newvectdown);
    }
    jet_jesUp[icomp].push_back(goodjet ? jesShift : 0.);
    jet_jesDown[icomp].push_back(goodjet ? -1.*jesShift : 0.);
    icomp++;
    // 2.
    jesShift = m_jesTool->getRelMuOffsetTerm(pt,eta,averageIntPerXing);
    if(icomp>=int(jet_jesUp.size())) {
      jet_jesUp.push_back(newvectup);
      jet_jesDown.push_back(newvectdown);
    }
    jet_jesUp[icomp].push_back(goodjet ? jesShift : 0.);
    jet_jesDown[icomp].push_back(goodjet ? -1.*jesShift : 0.);
    icomp++;
    // Moriond 2013 only
    if(m_is2012) {
      // 3.
      jesShift = m_jesTool->getRelPileupPtTerm(pt,eta,nvtxjets,averageIntPerXing);
      if(icomp>=int(jet_jesUp.size())) {
	jet_jesUp.push_back(newvectup);
	jet_jesDown.push_back(newvectdown);
      }
      jet_jesUp[icomp].push_back(goodjet ? jesShift : 0.);
      jet_jesDown[icomp].push_back(goodjet ? -1.*jesShift : 0.);
      icomp++;
      // 4.
      m_jesTool->getRelPileupRhoTopology(pt,eta); 
      if(icomp>=int(jet_jesUp.size())) {
	jet_jesUp.push_back(newvectup);
	jet_jesDown.push_back(newvectdown);
      }
      jet_jesUp[icomp].push_back(goodjet ? jesShift : 0.);
      jet_jesDown[icomp].push_back(goodjet ? -1.*jesShift : 0.);
      icomp++;
    }

    // Multijet/Flavour components

    double jesMultiJet = 0.;
    double mindR = 99;
    for(int iJet2=0; iJet2<jet_n; ++iJet2) {
      TLorentzVector jetlv2;
      jetlv2.SetPtEtaPhiE(jet_pt->at(iJet2),
			  jet_eta->at(iJet2),
			  jet_phi->at(iJet2),
			  jet_E->at(iJet2));
      if(!m_is2012) { // 2011 uses minimum dR
	// Compute deltaR to closest jet with EM pT of at least 7 GeV
	if(iJet2==iJet) continue;
	double empt = jet_emscale_pt->at(iJet2);
	if(empt<7e3) continue;
	mindR = jetlv2.DeltaR(jetlv);
	jesMultiJet = m_jesTool->getRelClosebyUncert(pt, mindR);
      } else {
	double fCloseby=0;
	// Loop over other jets to find those within dR < 1.1
	// Only take other jets with pT of at least 12 GeV
	if(iJet2==iJet) continue;
	if(jet_pt->at(iJet2)<12e3) continue;
	if(jetlv2.DeltaR(jetlv)>1.1) continue;
	// "fractional projection" of momentum along jet axis: p_jet*p_closeby / |p_jet|^2
	fCloseby += jetlv.Vect().Dot(jetlv2.Vect()) / (jetlv2.P()*jetlv2.P()) ; // close-by fraction
	 
	jesMultiJet = m_jesTool->getRelClosebyUncert(pt, fCloseby);
      }
    }
    if(icomp>=int(jet_jesUp.size())) {
      jet_jesUp.push_back(newvectup);
      jet_jesDown.push_back(newvectdown);
    }
    jet_jesUp[icomp].push_back(goodjet ? jesMultiJet : 0.);
    jet_jesDown[icomp].push_back(goodjet ? -1.*jesMultiJet : 0.);
    icomp++;

    // Some uncertainties are applied only (not applied) to b-jets
    if(jet_flavor_truth_label->at(iJet)==5) {
      // Flavour composition
      if(icomp>=int(jet_jesUp.size())) {
	jet_jesUp.push_back(newvectup);
	jet_jesDown.push_back(newvectdown);
      }
      jet_jesUp[icomp].push_back(0.);
      jet_jesDown[icomp].push_back(0.);
      icomp++;
      // Flavour response
      if(icomp>=int(jet_jesUp.size())) {
	jet_jesUp.push_back(newvectup);
	jet_jesDown.push_back(newvectdown);
      }
      jet_jesUp[icomp].push_back(0.);
      jet_jesDown[icomp].push_back(0.);
      icomp++;
      // B-JES
      double jesBjet = m_jesTool->getRelBJESUncert(pt, eta);
      if(icomp>=int(jet_jesUp.size())) {
	jet_jesUp.push_back(newvectup);
	jet_jesDown.push_back(newvectdown);
      }
      jet_jesUp[icomp].push_back(goodjet ? jesBjet : 0.);
      jet_jesDown[icomp].push_back(goodjet ? -1*jesBjet : 0.);
      icomp++;
    } else {
      // Flavour composition
      double jesFlavourUp = m_jesTool->getRelFlavorCompUncert(pt, eta, true);
      double jesFlavourDown = m_jesTool->getRelFlavorCompUncert(pt, eta, false);
      if(icomp>=int(jet_jesUp.size())) {
	jet_jesUp.push_back(newvectup);
	jet_jesDown.push_back(newvectdown);
      }
      jet_jesUp[icomp].push_back(goodjet ? jesFlavourUp : 0.);
      jet_jesDown[icomp].push_back(goodjet ? jesFlavourDown : 0.);
      icomp++;
      // Flavour response
      double jesFlavourResponse = m_jesTool->getRelFlavorResponseUncert(pt, eta);
      if(icomp>=int(jet_jesUp.size())) {
	jet_jesUp.push_back(newvectup);
	jet_jesDown.push_back(newvectdown);
      }
      jet_jesUp[icomp].push_back(goodjet ? jesFlavourResponse : 0.);
      jet_jesDown[icomp].push_back(goodjet ? -1*jesFlavourResponse : 0.);
      icomp++;
      // B-JES
      if(icomp>=int(jet_jesUp.size())) {
	jet_jesUp.push_back(newvectup);
	jet_jesDown.push_back(newvectdown);
      }
      jet_jesUp[icomp].push_back(0.);
      jet_jesDown[icomp].push_back(0.);
      icomp++;
    }
  }

  // Here we get the electron energy scale and resolution systematics
  vector<float> *el_smeared_pt = new vector<float>;
  vector<float> eerUp;
  vector<float> eerDown;
  vector<float> el_eesUp_ZStat, el_eesDown_ZStat, el_eesUp_ZMeth, el_eesDown_ZMeth;
  vector<float> el_eesUp_ZGen, el_eesDown_ZGen, el_eesUp_Mat, el_eesDown_Mat;
  vector<float> el_eesUp_PS, el_eesDown_PS, el_eesUp_LowPt, el_eesDown_LowPt;

  for (unsigned int iEl = 0; iEl < el_pt->size(); ++iEl) {

    m_egammaTool->SetRandomSeed(int(1e5*fabs(el_phi->at(iEl))));

    // Smear to match the data resolution, or by systematic variations
    float smear = m_egammaTool->getSmearingCorrection(el_cl_eta->at(iEl), el_E->at(iEl), egRescaler::EnergyRescalerUpgrade::Nominal);
    float smearUp = m_egammaTool->getSmearingCorrection(el_cl_eta->at(iEl), el_E->at(iEl), egRescaler::EnergyRescalerUpgrade::ERR_UP);
    float smearDown = m_egammaTool->getSmearingCorrection(el_cl_eta->at(iEl), el_E->at(iEl), egRescaler::EnergyRescalerUpgrade::ERR_DOWN);

    el_smeared_pt->push_back(smear*el_pt->at(iEl));
    eerUp.push_back((smearUp - smear)/smear);
    eerDown.push_back((smearDown - smear)/smear);

    // Correct the measured energies in data, and scale by systematic variations
    float correction = 1.;
    if(isData)
      correction = m_egammaTool->applyEnergyCorrection(el_cl_eta->at(iEl),el_E->at(iEl),egRescaler::EnergyRescalerUpgrade::Electron, egRescaler::EnergyRescalerUpgrade::Nominal) / el_E->at(iEl);
    el_smeared_pt->at(iEl)*= correction;

    // There are multiple systematic variations that should be applied independently.
    // See https://twiki.cern.ch/twiki/bin/viewauth/AtlasProtected/EnergyScaleResolutionRecommendations#Scale_corrections
    //
    // Case 0
    double energyUp = m_egammaTool->applyEnergyCorrection(el_cl_eta->at(iEl),el_cl_E->at(iEl),
							  egRescaler::EnergyRescalerUpgrade::Electron, egRescaler::EnergyRescalerUpgrade::ZeeStatUp) / (correction*el_E->at(iEl)) - 1;
    double energyDown = m_egammaTool->applyEnergyCorrection(el_cl_eta->at(iEl),el_cl_E->at(iEl),
							    egRescaler::EnergyRescalerUpgrade::Electron, egRescaler::EnergyRescalerUpgrade::ZeeStatDown) / (correction*el_E->at(iEl)) - 1;
    el_eesUp_ZStat.push_back(energyUp);
    el_eesDown_ZStat.push_back(energyDown);
    //
    // Case 1
    energyUp = m_egammaTool->applyEnergyCorrection(el_cl_eta->at(iEl),el_cl_E->at(iEl),
						   egRescaler::EnergyRescalerUpgrade::Electron, egRescaler::EnergyRescalerUpgrade::ZeeMethodUp) / (correction*el_E->at(iEl)) - 1;
    energyDown = m_egammaTool->applyEnergyCorrection(el_cl_eta->at(iEl),el_cl_E->at(iEl),
						     egRescaler::EnergyRescalerUpgrade::Electron, egRescaler::EnergyRescalerUpgrade::ZeeMethodDown) / (correction*el_E->at(iEl)) - 1;
    el_eesUp_ZMeth.push_back(energyUp);
    el_eesDown_ZMeth.push_back(energyDown);
    //
    // Case 2
    energyUp = m_egammaTool->applyEnergyCorrection(el_cl_eta->at(iEl),el_cl_E->at(iEl),
						   egRescaler::EnergyRescalerUpgrade::Electron, egRescaler::EnergyRescalerUpgrade::ZeeGenUp) / (correction*el_E->at(iEl)) - 1;
    energyDown = m_egammaTool->applyEnergyCorrection(el_cl_eta->at(iEl),el_cl_E->at(iEl),
						     egRescaler::EnergyRescalerUpgrade::Electron, egRescaler::EnergyRescalerUpgrade::ZeeGenDown) / (correction*el_E->at(iEl)) - 1;
    el_eesUp_ZGen.push_back(energyUp);
    el_eesDown_ZGen.push_back(energyDown);
    //
    // Case 3
    energyUp = m_egammaTool->applyEnergyCorrection(el_cl_eta->at(iEl),el_cl_E->at(iEl),
						   egRescaler::EnergyRescalerUpgrade::Electron, egRescaler::EnergyRescalerUpgrade::R12StatUp) / (correction*el_E->at(iEl)) - 1;
    energyDown = m_egammaTool->applyEnergyCorrection(el_cl_eta->at(iEl),el_cl_E->at(iEl),
						     egRescaler::EnergyRescalerUpgrade::Electron, egRescaler::EnergyRescalerUpgrade::R12StatDown) / (correction*el_E->at(iEl)) - 1;
    el_eesUp_Mat.push_back(energyUp);
    el_eesDown_Mat.push_back(energyDown);
    //
    // Case 4
    energyUp = m_egammaTool->applyEnergyCorrection(el_cl_eta->at(iEl),el_cl_E->at(iEl),
						   egRescaler::EnergyRescalerUpgrade::Electron, egRescaler::EnergyRescalerUpgrade::PSStatUp) / (correction*el_E->at(iEl)) - 1;
    energyDown = m_egammaTool->applyEnergyCorrection(el_cl_eta->at(iEl),el_cl_E->at(iEl),
						     egRescaler::EnergyRescalerUpgrade::Electron, egRescaler::EnergyRescalerUpgrade::PSStatDown) / (correction*el_E->at(iEl)) - 1;
    el_eesUp_PS.push_back(energyUp);
    el_eesDown_PS.push_back(energyDown);
    //
    // Case 5
    energyUp = m_egammaTool->applyEnergyCorrection(el_cl_eta->at(iEl),el_cl_E->at(iEl),
    		egRescaler::EnergyRescalerUpgrade::Electron, egRescaler::EnergyRescalerUpgrade::LowPtUp) / (correction*el_E->at(iEl)) - 1;
    energyDown = m_egammaTool->applyEnergyCorrection(el_cl_eta->at(iEl),el_cl_E->at(iEl),
    		egRescaler::EnergyRescalerUpgrade::Electron, egRescaler::EnergyRescalerUpgrade::LowPtDown) / (correction*el_E->at(iEl)) - 1;
    el_eesUp_LowPt.push_back(energyUp);
    el_eesDown_LowPt.push_back(energyDown);
  } //end of electron loop

  // Now we get the same for photons
  vector<float> *ph_smeared_pt = new vector<float>;
  vector<float> perUp;
  vector<float> perDown;
  vector<float> ph_pesUp_ZStat, ph_pesDown_ZStat, ph_pesUp_ZMeth, ph_pesDown_ZMeth;
  vector<float> ph_pesUp_ZGen, ph_pesDown_ZGen, ph_pesUp_Mat, ph_pesDown_Mat;
  vector<float> ph_pesUp_PS, ph_pesDown_PS, ph_pesUp_LowPt, ph_pesDown_LowPt;

  for (unsigned int iPh = 0; iPh < ph_pt->size(); ++iPh) {

    m_egammaTool->SetRandomSeed(int(1.e+5*fabs(ph_phi->at(iPh))));

    // Smear to match the data resolution, or by systematic variations
    float smear = m_egammaTool->getSmearingCorrection(ph_cl_eta->at(iPh), ph_E->at(iPh), egRescaler::EnergyRescalerUpgrade::Nominal);
    float smearUp = m_egammaTool->getSmearingCorrection(ph_cl_eta->at(iPh), ph_E->at(iPh), egRescaler::EnergyRescalerUpgrade::ERR_UP);
    float smearDown = m_egammaTool->getSmearingCorrection(ph_cl_eta->at(iPh), ph_E->at(iPh), egRescaler::EnergyRescalerUpgrade::ERR_DOWN);

    ph_smeared_pt->push_back(smear*ph_pt->at(iPh));
    perUp.push_back((smearUp - smear)/smear);
    perDown.push_back((smearDown - smear)/smear);

    // Correct the measured energies in data, and scale by systematic variations
    // Conversions are treated differently.
    float correction = 1.;
    egRescaler::EnergyRescalerUpgrade::ParticleType photontype = ph_isConv->at(iPh) ? egRescaler::EnergyRescalerUpgrade::Converted : egRescaler::EnergyRescalerUpgrade::Unconverted;
    if(isData)
      correction = m_egammaTool->applyEnergyCorrection(ph_cl_eta->at(iPh),ph_E->at(iPh),photontype,egRescaler::EnergyRescalerUpgrade::Nominal) / ph_E->at(iPh);
    ph_smeared_pt->at(iPh)*= correction;
    // There are multiple systematic variations that should be applied independently.
    // See https://twiki.cern.ch/twiki/bin/viewauth/AtlasProtected/EnergyScaleResolutionRecommendations#Scale_corrections
    //
    // Case 0
    double energyUp = m_egammaTool->applyEnergyCorrection(ph_cl_eta->at(iPh),ph_E->at(iPh),
							  photontype, egRescaler::EnergyRescalerUpgrade::ZeeStatUp) / (correction*ph_E->at(iPh)) - 1;
    double energyDown = m_egammaTool->applyEnergyCorrection(ph_cl_eta->at(iPh),ph_E->at(iPh),
							    photontype, egRescaler::EnergyRescalerUpgrade::ZeeStatDown) / (correction*ph_E->at(iPh)) - 1;
    ph_pesUp_ZStat.push_back(energyUp);
    ph_pesDown_ZStat.push_back(energyDown);
    //
    // Case 1
    energyUp = m_egammaTool->applyEnergyCorrection(ph_cl_eta->at(iPh),ph_E->at(iPh),
						   photontype, egRescaler::EnergyRescalerUpgrade::ZeeMethodUp) / (correction*ph_E->at(iPh)) - 1;
    energyDown = m_egammaTool->applyEnergyCorrection(ph_cl_eta->at(iPh),ph_E->at(iPh),
						     photontype, egRescaler::EnergyRescalerUpgrade::ZeeMethodDown) / (correction*ph_E->at(iPh)) - 1;
    ph_pesUp_ZMeth.push_back(energyUp);
    ph_pesDown_ZMeth.push_back(energyDown);
    //
    // Case 2
    energyUp = m_egammaTool->applyEnergyCorrection(ph_cl_eta->at(iPh),ph_E->at(iPh),
						   photontype, egRescaler::EnergyRescalerUpgrade::ZeeGenUp) / (correction*ph_E->at(iPh)) - 1;
    energyDown = m_egammaTool->applyEnergyCorrection(ph_cl_eta->at(iPh),ph_E->at(iPh),
						     photontype, egRescaler::EnergyRescalerUpgrade::ZeeGenDown) / (correction*ph_E->at(iPh)) - 1;
    ph_pesUp_ZGen.push_back(energyUp);
    ph_pesDown_ZGen.push_back(energyDown);
    //
    // Case 3
    energyUp = m_egammaTool->applyEnergyCorrection(ph_cl_eta->at(iPh),ph_E->at(iPh),
						   photontype, egRescaler::EnergyRescalerUpgrade::R12StatUp) / (correction*ph_E->at(iPh)) - 1;
    energyDown = m_egammaTool->applyEnergyCorrection(ph_cl_eta->at(iPh),ph_E->at(iPh),
						     photontype, egRescaler::EnergyRescalerUpgrade::R12StatDown) / (correction*ph_E->at(iPh)) - 1;
    ph_pesUp_Mat.push_back(energyUp);
    ph_pesDown_Mat.push_back(energyDown);
    //
    // Case 4
    energyUp = m_egammaTool->applyEnergyCorrection(ph_cl_eta->at(iPh),ph_E->at(iPh),
						   photontype, egRescaler::EnergyRescalerUpgrade::PSStatUp) / (correction*ph_E->at(iPh)) - 1;
    energyDown = m_egammaTool->applyEnergyCorrection(ph_cl_eta->at(iPh),ph_E->at(iPh),
						     photontype, egRescaler::EnergyRescalerUpgrade::PSStatDown) / (correction*ph_E->at(iPh)) - 1;
    ph_pesUp_PS.push_back(energyUp);
    ph_pesDown_PS.push_back(energyDown);
    //
    // Case 5
    energyUp = m_egammaTool->applyEnergyCorrection(ph_cl_eta->at(iPh),ph_E->at(iPh),
						   photontype, egRescaler::EnergyRescalerUpgrade::LowPtUp) / (correction*ph_E->at(iPh)) - 1;
    energyDown = m_egammaTool->applyEnergyCorrection(ph_cl_eta->at(iPh),ph_E->at(iPh),
						     photontype, egRescaler::EnergyRescalerUpgrade::LowPtDown) / (correction*ph_E->at(iPh)) - 1;
    ph_pesUp_LowPt.push_back(energyUp);
    ph_pesDown_LowPt.push_back(energyDown);
  }//end of photon loop

  // And now the same for muons. We need resolution shifts for ID and MS,
  // and different treatment for the MS four-vector (for standalone muons).
  vector<float> *mu_smeared_pt = new vector<float>;
  vector<float> *mu_smeared_ms_pt = new vector<float>;
      
  vector<float> cb_meridUp;
  vector<float> cb_meridDown;
  vector<float> cb_mermsUp;
  vector<float> cb_mermsDown;
  vector<float> mermsUp;
  vector<float> mermsDown;

  vector<float> mesUp;
  vector<float> mesDown;

  for(unsigned int iMu = 0; iMu < mu_pt->size(); ++iMu){

    double ptcb = mu_pt->at(iMu);
    double ptid = (mu_id_qoverp_exPV->at(iMu) != 0.) ? fabs(sin(mu_id_theta_exPV->at(iMu))/mu_id_qoverp_exPV->at(iMu)) : 0.;
    double ptms = (mu_ms_qoverp->at(iMu) != 0.) ? fabs(sin(mu_ms_theta->at(iMu))/mu_ms_qoverp->at(iMu)) : 0.;
    m_muonTool->SetSeed(int(1.e+5*fabs(mu_phi->at(iMu))));
    double etaMu = mu_eta->at(iMu);
    double charge = mu_charge->at(iMu);

    double smearedCBPt(0.), smearedMSPt(0.);

    if(mu_isCombinedMuon->at(iMu)) {
      m_muonTool->Event(ptms, ptid, ptcb, etaMu, charge);
      smearedCBPt = m_muonTool->pTCB();
      smearedMSPt = m_muonTool->pTMS();
      mu_smeared_pt->push_back(smearedCBPt);
      mu_smeared_ms_pt->push_back(smearedMSPt);
    } else if(mu_isSegmentTaggedMuon->at(iMu)) {
      m_muonTool->Event(ptid, etaMu, "ID", charge);
      smearedCBPt = m_muonTool->pTID(); // use ID rather than combined
      smearedMSPt = m_muonTool->pTMS(); // is 0
      mu_smeared_pt->push_back(smearedCBPt);
      mu_smeared_ms_pt->push_back(smearedMSPt);
    } else if(mu_isStandAloneMuon->at(iMu)) {
      m_muonTool->Event(ptms, etaMu, "MS", charge);
      smearedCBPt = m_muonTool->pTID(); // is 0
      smearedMSPt = m_muonTool->pTMS();
      mu_smeared_pt->push_back(smearedCBPt);
      mu_smeared_ms_pt->push_back(smearedMSPt);
    } else {
      mu_smeared_pt->push_back(0.);
      mu_smeared_ms_pt->push_back(0.);
      cout << "What kind of muon is this?" << endl;
    }

    double ptMS_smeared, ptID_smeared, ptCB_smeared;
    float smearfactor_MS, smearfactor_ID, smearfactor_CB;
    smearfactor_MS = 0.; smearfactor_ID = 0.; smearfactor_CB = 0.;
    // MSreso
    m_muonTool->PTVar(ptMS_smeared, ptID_smeared, ptCB_smeared, "MSLOW");
    smearfactor_MS = smearedMSPt > 0. ? ptMS_smeared/smearedMSPt - 1.0 : 0.;
    smearfactor_CB = smearedCBPt > 0. ? ptCB_smeared/smearedCBPt - 1.0 : 0.;
    mermsDown.push_back(smearfactor_MS);
    cb_mermsDown.push_back(smearfactor_CB);
    m_muonTool->PTVar(ptMS_smeared, ptID_smeared, ptCB_smeared, "MSUP");
    smearfactor_MS = smearedMSPt > 0. ? ptMS_smeared/smearedMSPt - 1.0 : 0.;
    smearfactor_CB = smearedCBPt > 0. ? ptCB_smeared/smearedCBPt - 1.0 : 0.;
    mermsUp.push_back(smearfactor_MS);
    cb_mermsUp.push_back(smearfactor_CB);
    // ID reso
    m_muonTool->PTVar(ptMS_smeared, ptID_smeared, ptCB_smeared, "IDUP");
    smearfactor_CB = smearedCBPt > 0. ? ptCB_smeared/smearedCBPt - 1.0 : 0.;
    cb_meridUp.push_back(smearfactor_CB);
    m_muonTool->PTVar(ptMS_smeared, ptID_smeared, ptCB_smeared, "IDLOW");
    smearfactor_CB = smearedCBPt > 0. ? ptCB_smeared/smearedCBPt - 1.0 : 0.;
    cb_meridDown.push_back(smearfactor_CB);
    // Scale
    m_muonTool->PTVar(ptMS_smeared, ptID_smeared, ptCB_smeared, "SCALEUP");
    smearfactor_CB = smearedCBPt > 0. ? ptCB_smeared/smearedCBPt - 1.0 : 0.;
    mesUp.push_back(smearfactor_CB);
    m_muonTool->PTVar(ptMS_smeared, ptID_smeared, ptCB_smeared, "SCALELOW");
    smearfactor_CB = smearedCBPt > 0. ? ptCB_smeared/smearedCBPt - 1.0 : 0.;
    mesDown.push_back(smearfactor_CB);

  }//end of muon loop

  vector<float> tesUp;
  vector<float> tesDown;

  // This usage of TESUncertaintyProvider assumes the trunk of
  // PhysicsAnalysis/TauID/TesUncertaintyProvider.
  // New recommendations are in preparation, so please contact the tau CP group
  // if you actually want to use the TES uncertainties

  for(int iTau=0; iTau<tau_n; iTau++) {
    double pt = tau_pt->at(iTau);
    double eta = tau_eta->at(iTau);
    int nProng = tau_nProng->at(iTau);
    double uncert = m_tesTool->GetTESUncertainty(pt/1e3, eta, nProng);

    if(uncert < 0) uncert = 0;
    tesUp.push_back(uncert);
    tesDown.push_back(-1*uncert);
  }

  // This demonstration is for doing smearing and systematics
  m_systUtil->reset();

  vector<float> *jet_pt_new  = new vector<float>;
  vector<float> *jet_eta_new = new vector<float>;
  vector<float> *jet_phi_new = new vector<float>;
  vector<float> *jet_E_new   = new vector<float>;
  for (int ijet=0; ijet<int(jet_MET_statusWord->size()); ijet++){
    //    jet_pt_new->push_back(jet_calibpT.at(ijet));
    jet_pt_new->push_back(jet_calibpT.at(ijet));
    jet_eta_new->push_back(jet_eta->at(ijet));
    jet_phi_new->push_back(jet_phi->at(ijet));
    jet_E_new->push_back(jet_calibE.at(ijet));
  }

  m_systUtil->setJetParameters(jet_pt_new, jet_eta, jet_phi, jet_E,
			       jet_MET_wet, jet_MET_wpx, jet_MET_wpy,
			       jet_MET_statusWord);

  // Fix for messed up NTUP_JETMET
  vector<vector<float> > *ph_MET_wet_new = new vector<vector<float> >;
  vector<vector<float> > *ph_MET_wpx_new = new vector<vector<float> >;
  vector<vector<float> > *ph_MET_wpy_new = new vector<vector<float> >;
  vector<vector<unsigned int> > *ph_MET_statusWord_new = new vector<vector<unsigned int> >;
  for (int iph=0; iph<ph_n; iph++){
    ph_MET_wet_new->push_back(ph_MET_wet->at(iph));
    ph_MET_wpx_new->push_back(ph_MET_wpx->at(iph));
    ph_MET_wpy_new->push_back(ph_MET_wpy->at(iph));
    ph_MET_statusWord_new->push_back(ph_MET_statusWord->at(iph));
  }

  vector<vector<float> > *el_MET_wet_new = new vector<vector<float> >;
  vector<vector<float> > *el_MET_wpx_new = new vector<vector<float> >;
  vector<vector<float> > *el_MET_wpy_new = new vector<vector<float> >;
  vector<vector<unsigned int> > *el_MET_statusWord_new = new vector<vector<unsigned int> >;
  for (int iel=0; iel<el_n; iel++){
    el_MET_wet_new->push_back(el_MET_wet->at(iel));
    el_MET_wpx_new->push_back(el_MET_wpx->at(iel));
    el_MET_wpy_new->push_back(el_MET_wpy->at(iel));
    el_MET_statusWord_new->push_back(el_MET_statusWord->at(iel));
  }

  // Putting in smeared and/or scaled objects will cause that to be reflected in MET

  m_systUtil->setElectronParameters(el_smeared_pt, el_eta, el_phi,
				    el_MET_wet_new, el_MET_wpx_new, el_MET_wpy_new,
				    el_MET_statusWord_new);
  m_systUtil->setPhotonParameters(ph_smeared_pt, ph_eta, ph_phi,
				  ph_MET_wet_new, ph_MET_wpx_new, ph_MET_wpy_new,
				  ph_MET_statusWord_new);
  m_systUtil->setTauParameters(tau_pt, tau_eta, tau_phi,
			       tau_MET_wet, tau_MET_wpx, tau_MET_wpy,
			       tau_MET_statusWord);
  m_systUtil->setMuonParameters(mu_smeared_pt, mu_eta, mu_phi,
				mu_MET_wet, mu_MET_wpx, mu_MET_wpy,
				mu_MET_statusWord);
  // In this instance there is an overloaded version of setExtraMuonParameters that accepts smeared pTs for spectro
  m_systUtil->setExtraMuonParameters(mu_smeared_ms_pt, mu_ms_theta, mu_ms_phi);

//   Needed for reading some d3pds such as SMWZ
//   double MET_RefTau_etx = MET_RefTau_et*cos(MET_RefTau_phi);
//   double MET_RefTau_ety = MET_RefTau_et*sin(MET_RefTau_phi);

//   double MET_CellOut_Eflow_etx = MET_CellOut_Eflow_et*cos(MET_CellOut_Eflow_phi);
//   double MET_CellOut_Eflow_ety = MET_CellOut_Eflow_et*sin(MET_CellOut_Eflow_phi);

  m_systUtil->setMETTerm(METUtil::RefTau, MET_RefTau_etx, MET_RefTau_ety, MET_RefTau_sumet);
//   m_systUtil->setMETTerm(METUtil::RefMuon, MET_RefMuon_etx, MET_RefMuon_ety, MET_RefMuon_sumet);
  m_systUtil->setMETTerm(METUtil::SoftTerms, MET_CellOut_Eflow_etx, MET_CellOut_Eflow_ety, MET_CellOut_Eflow_sumet);

  // These set up the systematic "SoftTerms_ptHard"
  m_systUtil->setNvtx(nvtxsoftmet);
  //  if(!isData)
  m_systUtil->setMETTerm(METUtil::Truth, MET_Truth_NonInt_etx, MET_Truth_NonInt_ety, MET_Truth_NonInt_sumet);

  for(int icomp=0; icomp<int(jet_jesUp.size()); icomp++) {
    m_systUtil->setObjectEnergyUncertainties(METUtil::Jets, jet_jesUp[icomp], jet_jesDown[icomp], icomp);
  }
  m_systUtil->setObjectResolutionShift(METUtil::Jets, jerUp, jerDown);

  //  m_systUtil->setObjectEnergyUncertainties(METUtil::Electrons, eesUp, eesDown);
  m_systUtil->setObjectEnergyUncertainties(METUtil::Electrons, el_eesUp_ZStat, el_eesDown_ZStat,0);
  m_systUtil->setObjectEnergyUncertainties(METUtil::Electrons, el_eesUp_ZMeth, el_eesDown_ZMeth,1);
  m_systUtil->setObjectEnergyUncertainties(METUtil::Electrons, el_eesUp_ZGen,  el_eesDown_ZGen, 2);
  m_systUtil->setObjectEnergyUncertainties(METUtil::Electrons, el_eesUp_Mat,   el_eesDown_Mat,  3);
  m_systUtil->setObjectEnergyUncertainties(METUtil::Electrons, el_eesUp_PS,    el_eesDown_PS,   4);
  m_systUtil->setObjectEnergyUncertainties(METUtil::Electrons, el_eesUp_LowPt, el_eesDown_LowPt,5);
  m_systUtil->setObjectResolutionShift(METUtil::Electrons, eerUp, eerDown);

  //  m_systUtil->setObjectEnergyUncertainties(METUtil::Photons, pesUp, pesDown);
  m_systUtil->setObjectEnergyUncertainties(METUtil::Photons, ph_pesUp_ZStat, ph_pesDown_ZStat,0);
  m_systUtil->setObjectEnergyUncertainties(METUtil::Photons, ph_pesUp_ZMeth, ph_pesDown_ZMeth,1);
  m_systUtil->setObjectEnergyUncertainties(METUtil::Photons, ph_pesUp_ZGen,  ph_pesDown_ZGen, 2);
  m_systUtil->setObjectEnergyUncertainties(METUtil::Photons, ph_pesUp_Mat,   ph_pesDown_Mat,  3);
  m_systUtil->setObjectEnergyUncertainties(METUtil::Photons, ph_pesUp_PS,    ph_pesDown_PS,   4);
  m_systUtil->setObjectEnergyUncertainties(METUtil::Photons, ph_pesUp_LowPt, ph_pesDown_LowPt,5);
  m_systUtil->setObjectResolutionShift(METUtil::Photons, perUp, perDown);

  // Muons are complicated, and MET makes use of track, spectro, and combined quantities,
  // so we need all of their resolutions.
  // comboms reflects that it is the combined muon res affected by shifting ms res up and down.
  // comboid is for shifting the id res up and down
  m_systUtil->setObjectResolutionShift(METUtil::MuonsComboMS, cb_mermsUp, cb_mermsDown);
  m_systUtil->setObjectResolutionShift(METUtil::MuonsComboID, cb_meridUp, cb_meridDown);
  m_systUtil->setObjectResolutionShift(METUtil::SpectroMuons, mermsUp, mermsDown);

  // For now the mes only affects combined
  m_systUtil->setObjectEnergyUncertainties(METUtil::Muons, mesUp, mesDown);

  // Taus are just in as an example
  m_systUtil->setObjectEnergyUncertainties(METUtil::Taus, tesUp, tesDown);

  // Fill histograms
  METUtility::METObject met_RefFinal = m_systUtil->getMissingET(METUtil::RefFinal);
  h_RefFinal->Fill(met_RefFinal.et()/1000);
  // Jet systematics
  METUtility::METObject met_RefFinal_JESUp = m_systUtil->getMissingET(METUtil::RefFinal,METUtil::JESUp);
  h_RefFinal_JESUp->Fill(met_RefFinal_JESUp.et()/1000);
  METUtility::METObject met_RefFinal_JESDown = m_systUtil->getMissingET(METUtil::RefFinal,METUtil::JESDown);
  h_RefFinal_JESDown->Fill(met_RefFinal_JESDown.et()/1000);
  METUtility::METObject met_RefFinal_JERUp = m_systUtil->getMissingET(METUtil::RefFinal,METUtil::JERUp);
  h_RefFinal_JERUp->Fill(met_RefFinal_JERUp.et()/1000);
  // Electron systematics
  METUtility::METObject met_RefFinal_EESUp = m_systUtil->getMissingET(METUtil::RefFinal,METUtil::EESUp);
  h_RefFinal_EESUp->Fill(met_RefFinal_EESUp.et()/1000);
  METUtility::METObject met_RefFinal_EESDown = m_systUtil->getMissingET(METUtil::RefFinal,METUtil::EESDown);
  h_RefFinal_EESDown->Fill(met_RefFinal_EESDown.et()/1000);
  METUtility::METObject met_RefFinal_EERUp = m_systUtil->getMissingET(METUtil::RefFinal,METUtil::EERUp);
  h_RefFinal_EERUp->Fill(met_RefFinal_EERUp.et()/1000);
  METUtility::METObject met_RefFinal_EERDown = m_systUtil->getMissingET(METUtil::RefFinal,METUtil::EERDown);
  h_RefFinal_EERDown->Fill(met_RefFinal_EERDown.et()/1000);
  // Photon systematics
  METUtility::METObject met_RefFinal_PESUp = m_systUtil->getMissingET(METUtil::RefFinal,METUtil::PESUp);
  h_RefFinal_PESUp->Fill(met_RefFinal_PESUp.et()/1000);
  METUtility::METObject met_RefFinal_PESDown = m_systUtil->getMissingET(METUtil::RefFinal,METUtil::PESDown);
  h_RefFinal_PESDown->Fill(met_RefFinal_PESDown.et()/1000);
  METUtility::METObject met_RefFinal_PERUp = m_systUtil->getMissingET(METUtil::RefFinal,METUtil::PERUp);
  h_RefFinal_PERUp->Fill(met_RefFinal_PERUp.et()/1000);
  METUtility::METObject met_RefFinal_PERDown = m_systUtil->getMissingET(METUtil::RefFinal,METUtil::PERDown);
  h_RefFinal_PERDown->Fill(met_RefFinal_PERDown.et()/1000);
  // Muon systematics
  METUtility::METObject met_RefFinal_MESUp = m_systUtil->getMissingET(METUtil::RefFinal,METUtil::MESUp);
  h_RefFinal_MESUp->Fill(met_RefFinal_MESUp.et()/1000);
  METUtility::METObject met_RefFinal_MESDown = m_systUtil->getMissingET(METUtil::RefFinal,METUtil::MESDown);
  h_RefFinal_MESDown->Fill(met_RefFinal_MESDown.et()/1000);
  METUtility::METObject met_RefFinal_MERIDUp = m_systUtil->getMissingET(METUtil::RefFinal,METUtil::MERIDUp);
  h_RefFinal_MERIDUp->Fill(met_RefFinal_MERIDUp.et()/1000);
  METUtility::METObject met_RefFinal_MERIDDown = m_systUtil->getMissingET(METUtil::RefFinal,METUtil::MERIDDown);
  h_RefFinal_MERIDDown->Fill(met_RefFinal_MERIDDown.et()/1000);
  METUtility::METObject met_RefFinal_MERMSUp = m_systUtil->getMissingET(METUtil::RefFinal,METUtil::MERMSUp);
  h_RefFinal_MERMSUp->Fill(met_RefFinal_MERMSUp.et()/1000);
  METUtility::METObject met_RefFinal_MERMSDown = m_systUtil->getMissingET(METUtil::RefFinal,METUtil::MERMSDown);
  h_RefFinal_MERMSDown->Fill(met_RefFinal_MERMSDown.et()/1000);

  // ResoSoftTerms uses gRandom for smearing. Set the seed here however you like.
  if(isData) gRandom->SetSeed(UInt_t(RunNumber * EventNumber));
  else gRandom->SetSeed(UInt_t(mc_channel_number * EventNumber));
  // Soft terms systematics
  METUtility::METObject met_RefFinal_ScaleSoftTermsUp = m_systUtil->getMissingET(METUtil::RefFinal,METUtil::ScaleSoftTermsUp);
  h_RefFinal_ScaleSoftTermsUp->Fill(met_RefFinal_ScaleSoftTermsUp.et()/1000);
  METUtility::METObject met_RefFinal_ScaleSoftTermsDown = m_systUtil->getMissingET(METUtil::RefFinal,METUtil::ScaleSoftTermsDown);
  h_RefFinal_ScaleSoftTermsDown->Fill(met_RefFinal_ScaleSoftTermsDown.et()/1000);
  METUtility::METObject met_RefFinal_ResoSoftTermsUp = m_systUtil->getMissingET(METUtil::RefFinal,METUtil::ResoSoftTermsUp);
  h_RefFinal_ResoSoftTermsUp->Fill(met_RefFinal_ResoSoftTermsUp.et()/1000);
  METUtility::METObject met_RefFinal_ResoSoftTermsDown = m_systUtil->getMissingET(METUtil::RefFinal,METUtil::ResoSoftTermsDown);
  h_RefFinal_ResoSoftTermsDown->Fill(met_RefFinal_ResoSoftTermsDown.et()/1000);
  METUtility::METObject met_RefFinal_ScaleSoftTermsUp_ptHard = m_systUtil->getMissingET(METUtil::RefFinal,METUtil::ScaleSoftTermsUp_ptHard);
  // Alternate soft terms systematics
  h_RefFinal_ScaleSoftTermsUp_ptHard->Fill(met_RefFinal_ScaleSoftTermsUp_ptHard.et()/1000);
  METUtility::METObject met_RefFinal_ScaleSoftTermsDown_ptHard = m_systUtil->getMissingET(METUtil::RefFinal,METUtil::ScaleSoftTermsDown_ptHard);
  h_RefFinal_ScaleSoftTermsDown_ptHard->Fill(met_RefFinal_ScaleSoftTermsDown_ptHard.et()/1000);
  METUtility::METObject met_RefFinal_ResoSoftTermsUp_ptHard = m_systUtil->getMissingET(METUtil::RefFinal,METUtil::ResoSoftTermsUp_ptHard);
  h_RefFinal_ResoSoftTermsUp_ptHard->Fill(met_RefFinal_ResoSoftTermsUp_ptHard.et()/1000);
  METUtility::METObject met_RefFinal_ResoSoftTermsUpDown_ptHard = m_systUtil->getMissingET(METUtil::RefFinal,METUtil::ResoSoftTermsUpDown_ptHard);
  h_RefFinal_ResoSoftTermsUpDown_ptHard->Fill(met_RefFinal_ResoSoftTermsUpDown_ptHard.et()/1000);
  METUtility::METObject met_RefFinal_ResoSoftTermsDownUp_ptHard = m_systUtil->getMissingET(METUtil::RefFinal,METUtil::ResoSoftTermsDownUp_ptHard);
  h_RefFinal_ResoSoftTermsDownUp_ptHard->Fill(met_RefFinal_ResoSoftTermsDownUp_ptHard.et()/1000);
  METUtility::METObject met_RefFinal_ResoSoftTermsDown_ptHard = m_systUtil->getMissingET(METUtil::RefFinal,METUtil::ResoSoftTermsDown_ptHard);
  h_RefFinal_ResoSoftTermsDown_ptHard->Fill(met_RefFinal_ResoSoftTermsDown_ptHard.et()/1000);

  // Systematics can be combined by just adding the enum values
  METUtility::METObject met_RefFinal_JESUp_ScaleSoftTermsUp = m_systUtil->getMissingET(METUtil::RefFinal,METUtil::JESUp+METUtil::ScaleSoftTermsUp);
  h_RefFinal_JESUp_ScaleSoftTermsUp->Fill(met_RefFinal_JESUp_ScaleSoftTermsUp.et()/1000);
  METUtility::METObject met_RefFinal_JESUp_ScaleSoftTermsDown = m_systUtil->getMissingET(METUtil::RefFinal,METUtil::JESUp+METUtil::ScaleSoftTermsDown);
  h_RefFinal_JESUp_ScaleSoftTermsDown->Fill(met_RefFinal_JESUp_ScaleSoftTermsDown.et()/1000);
  METUtility::METObject met_RefFinal_JESDown_ScaleSoftTermsUp = m_systUtil->getMissingET(METUtil::RefFinal,METUtil::JESDown+METUtil::ScaleSoftTermsUp);
  h_RefFinal_JESDown_ScaleSoftTermsUp->Fill(met_RefFinal_JESDown_ScaleSoftTermsUp.et()/1000);
  METUtility::METObject met_RefFinal_JESDown_ScaleSoftTermsDown = m_systUtil->getMissingET(METUtil::RefFinal,METUtil::JESDown+METUtil::ScaleSoftTermsDown);
  h_RefFinal_JESDown_ScaleSoftTermsDown->Fill(met_RefFinal_JESDown_ScaleSoftTermsDown.et()/1000);

  // Print out some information on each event
  if(verbose) {
    cout << "Demonstration of smearing and systematics" << endl;
    cout << "+++++++++++++++++++++++++++++" << endl;
    cout << "All these are the scalar MET term" << endl;
    cout << "RefEle (smeared): " << m_systUtil->getMissingET(METUtil::RefEle).et() << endl;
    cout << "RefGamma: " << m_systUtil->getMissingET(METUtil::RefGamma).et() << endl;
    cout << "RefTau: " << m_systUtil->getMissingET(METUtil::RefTau).et() << endl;
    cout << "RefJet: " << m_systUtil->getMissingET(METUtil::RefJet).et() << endl;
    //  cout << "RefMuon: " << m_systUtil->getMissingET(METUtil::RefMuon).et() << endl;
    cout << "MuonBoy (smeared and scaled): " << m_systUtil->getMissingET(METUtil::MuonTotal).et() << endl;
    cout << "CellOut_Eflow: " << m_systUtil->getMissingET(METUtil::SoftTerms).et() << endl;
    cout << "RefFinal: " << m_systUtil->getMissingET(METUtil::RefFinal).et() << endl;
    cout << "Truth: " << m_systUtil->getMissingET(METUtil::Truth).et() << endl;
    cout << "+++++++++++++++++++++++++++++" << endl;
    cout << "HardTerms: " << m_systUtil->getMissingET(METUtil::HardTerms).et() << endl;
    cout << "HardTerms stands for the sum of Ref* and MuonBoy." << endl;
    cout << "+++++++++++++++++++++++++++++" << endl;
    cout << endl;

    cout << "+++++++++++++++++++++++++++++" << endl;
    cout << "RefJet JESUp: " << m_systUtil->getMissingET(METUtil::RefJet,METUtil::JESUp).et()
	 << ",  JESDown: " << m_systUtil->getMissingET(METUtil::RefJet,METUtil::JESDown).et() << endl;
    cout << "RefJet JES Diff (up - Down)/none : " << m_systUtil->getMissingETDiff(METUtil::RefJet,METUtil::JES).et() << endl;
    cout << "RefFinal JESUp: " << met_RefFinal_JESUp.et()
	 << ", JESDown: " << met_RefFinal_JESDown.et() << endl;
    cout << "RefFinal JES Diff (up - Down)/none : " << m_systUtil->getMissingETDiff(METUtil::RefFinal,METUtil::JES).et() << endl;
    cout << "RefJet JERUp: " << m_systUtil->getMissingET(METUtil::RefJet,METUtil::JERUp).et()
	 << ", JERDown: " << m_systUtil->getMissingET(METUtil::RefJet,METUtil::JERDown).et() << endl;
    cout << "RefJet JER Diff (up - Down)/none : " << m_systUtil->getMissingETDiff(METUtil::RefJet,METUtil::JER).et() << endl;
    cout << "RefFinal JERUp: " << met_RefFinal_JERUp.et()
	 << ", JERDown: " << m_systUtil->getMissingET(METUtil::RefFinal,METUtil::JERDown).et() << endl;
    cout << "RefFinal JER Diff (up - Down)/none : " << m_systUtil->getMissingETDiff(METUtil::RefFinal,METUtil::JER).et() << endl;
    cout << "+++++++++++++++++++++++++++++" << endl;
    cout << "RefEle EESUp: " << m_systUtil->getMissingET(METUtil::RefEle,METUtil::EESUp).et()
	 << ",  EESDown: " << m_systUtil->getMissingET(METUtil::RefEle,METUtil::EESDown).et() << endl;
    cout << "RefFinal EESUp: " << met_RefFinal_EESUp.et()
	 << ",  EESDown: " << met_RefFinal_EESDown.et() << endl;
    cout << "RefFinal EES Diff (up - Down)/none : " << m_systUtil->getMissingETDiff(METUtil::RefFinal,METUtil::EES).et() << endl;
    cout << "RefEle EERUp: " << m_systUtil->getMissingET(METUtil::RefEle,METUtil::EERUp).et()
	 << ",  EERDown: " << m_systUtil->getMissingET(METUtil::RefEle,METUtil::EERDown).et() << endl;
    cout << "RefFinal EERUp: " << met_RefFinal_EERUp.et()
	 << ",  EERDown: " << met_RefFinal_EERDown.et() << endl;
    cout << "RefFinal EER Diff (up - Down)/none : " << m_systUtil->getMissingETDiff(METUtil::RefFinal,METUtil::EER).et() << endl;
    cout << "+++++++++++++++++++++++++++++" << endl;
    cout << "MuonBoy MESUp: " << m_systUtil->getMissingET(METUtil::MuonTotal,METUtil::MESUp).et()
	 << ",  MESDown: " << m_systUtil->getMissingET(METUtil::MuonTotal,METUtil::MESDown).et() << endl;
    cout << "RefFinal MESUp: " << met_RefFinal_MESUp.et()
	 << ",  MESDown: " << met_RefFinal_MESDown.et() << endl;
    cout << "RefFinal MES Diff (up - Down)/none : " << m_systUtil->getMissingETDiff(METUtil::RefFinal,METUtil::MES).et() << endl;
    cout << "MuonBoy MERIDUp: " << m_systUtil->getMissingET(METUtil::MuonTotal,METUtil::MERIDUp).et()
	 << ",  MERIDDown: " << m_systUtil->getMissingET(METUtil::MuonTotal,METUtil::MERIDDown).et() << endl;
    cout << "RefFinal MERIDUp: " << met_RefFinal_MERIDUp.et()
	 << ",  MERIDDown: " << met_RefFinal_MERIDDown.et() << endl;
    cout << "RefFinal MERID Diff (up - Down)/none : " << m_systUtil->getMissingETDiff(METUtil::RefFinal,METUtil::MERID).et() << endl;
    cout << "MuonBoy MERMSUp: " << m_systUtil->getMissingET(METUtil::MuonTotal,METUtil::MERMSUp).et()
	 << ",  MERMSDown: " << m_systUtil->getMissingET(METUtil::MuonTotal,METUtil::MERMSDown).et() << endl;
    cout << "RefFinal MERMSUp: " << met_RefFinal_MERMSUp.et()
	 << ",  MERMSDown: " << met_RefFinal_MERMSDown.et() << endl;
    cout << "RefFinal MERMS Diff (up - Down)/none : " << m_systUtil->getMissingETDiff(METUtil::RefFinal,METUtil::MERMS).et() << endl;
    cout << "+++++++++++++++++++++++++++++" << endl;
//     cout << "RefTau TESUp: " << m_systUtil->getMissingET(METUtil::RefTau,METUtil::TESUp).et()
// 	 << ",  TESDown: " << m_systUtil->getMissingET(METUtil::RefTau,METUtil::TESDown).et() << endl;
//     cout << "RefFinal TESUp: " << m_systUtil->getMissingET(METUtil::RefFinal,METUtil::TESUp).et()
// 	 << ",  TESDown: " << m_systUtil->getMissingET(METUtil::RefFinal,METUtil::TESDown).et() << endl;
//     cout << "RefFinal TES Diff (up - Down)/none : " << m_systUtil->getMissingETDiff(METUtil::RefFinal,METUtil::TES).et() << endl;
//     cout << "+++++++++++++++++++++++++++++" << endl;

    cout << endl;
    cout << "These are the April 2012 systematics. For information, please see:" << endl;
    cout << "https://indico.cern.ch/getFile.py/access?contribId=1&resId=0&materialId=slides&confId=161247" << endl;
    cout << endl;

    cout << "ScaleSoftTerms is the systematic on the scale CellOut(_Eflow)." << endl;

    // ResoSoftTerms uses gRandom for smearing. Set the seed here however you like.
    if(isData) gRandom->SetSeed(UInt_t(RunNumber * EventNumber));
    else gRandom->SetSeed(UInt_t(mc_channel_number * EventNumber));

    cout << "RefFinal ScaleSoftTerms Up: " << met_RefFinal_ScaleSoftTermsUp.et()
	 << ", RefFinal ScaleSoftTerms Down: " << met_RefFinal_ScaleSoftTermsDown.et() << endl;
    cout << "ResoSoftTerms is the systematic on the scale CellOut(_Eflow)." << endl;
    cout << "RefFinal ResoSoftTerms Up: " << met_RefFinal_ResoSoftTermsUp.et()
	 << ", RefFinal ResoSoftTerms Down: " << met_RefFinal_ResoSoftTermsDown.et() << endl;

    cout << "ScaleSoftTerms_ptHard is the systematic on the scale CellOut(_Eflow)." << endl;
    cout << "RefFinal ScaleSoftTerms_ptHard Up: " << met_RefFinal_ScaleSoftTermsUp_ptHard.et()
	 << ", RefFinal ScaleSoftTerms_ptHard Down: " << met_RefFinal_ScaleSoftTermsDown_ptHard.et() << endl;
    cout << "ResoSoftTerms is the systematic on the scale CellOut(_Eflow)." << endl;
    cout << "This is parameterised in terms of longitudinal and transverse components, which can be varied coherently or anti-coherently." << endl;
    cout << "RefFinal ResoSoftTerms_ptHard Up: " << met_RefFinal_ResoSoftTermsUp_ptHard.et()
	 << ", RefFinal ResoSoftTerms_ptHard Down: " << met_RefFinal_ResoSoftTermsDown_ptHard.et() << endl;
    cout << "RefFinal ResoSoftTerms_ptHard UpDown: " << met_RefFinal_ResoSoftTermsUpDown_ptHard.et()
	 << ", RefFinal ResoSoftTerms_ptHard DownUp: " << met_RefFinal_ResoSoftTermsDownUp_ptHard.et() << endl;

    cout << "+++++++++++++++++++++++++++++" << endl;
    cout << "Combined errors, giving an uncertainty on MET" << endl;
    METUtility::METObject smearedMET = m_systUtil->getMissingET(METUtil::RefFinal);
    cout << "RefFinal MET = " << smearedMET.et() << " +- " << m_systUtil->absDeltaMissingET(METUtil::RefFinal).et()
	 << " (" << 100*m_systUtil->deltaMissingET(METUtil::RefFinal).et() << "%)" << endl;
    cout << "+++++++++++++++++++++++++++++" << endl;
    cout << "AbsDelta(RF) = " << m_systUtil->absDeltaMissingET(METUtil::RefFinal).etx() << endl;
    cout << "AbsDelta(RJ) = " << m_systUtil->absDeltaMissingET(METUtil::RefJet).etx() << endl;
    cout << "AbsDelta(MT) = " << m_systUtil->absDeltaMissingET(METUtil::MuonTotal).etx() << endl;
    cout << endl;
  }

  delete jet_pt_new;
  delete jet_eta_new;
  delete jet_phi_new;
  delete jet_E_new;

  delete ph_MET_wet_new;
  delete ph_MET_wpx_new;
  delete ph_MET_wpy_new;
  delete ph_MET_statusWord_new;

  delete el_MET_wet_new;
  delete el_MET_wpx_new;
  delete el_MET_wpy_new;
  delete el_MET_statusWord_new;

  delete el_smeared_pt;
  delete ph_smeared_pt;
  delete mu_smeared_pt;
  delete mu_smeared_ms_pt;
}

void Example::Terminate()
{
  delete m_testUtil;
  delete m_systUtil;
  delete m_jerTool;
  delete m_jetCalibTool;
  delete m_jesTool;
  delete m_egammaTool;
  delete m_muonTool;
  delete m_tesTool;

  m_outfile->Write();
  m_outfile->Close();
}
