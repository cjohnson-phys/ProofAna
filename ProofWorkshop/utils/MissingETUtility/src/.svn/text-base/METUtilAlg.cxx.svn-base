#define METUTILITY_EXAMPLEALG_CXX

#include "./METUtilAlg.h"
#include "GaudiKernel/ITHistSvc.h"
#include "MissingETEvent/MissingET.h"
#include "EventInfo/EventInfo.h"
#include "EventInfo/EventID.h"
#include "TH1D.h"

namespace MissingETUtility {

  METUtilAlg::METUtilAlg(const std::string& name, ISvcLocator* pSvcLocator) :
    AthAlgorithm(name,pSvcLocator),
    m_METUtilHandle("METUtilityAthTool") 
  {

    declareProperty( "MetUtil", m_METUtilHandle, "public, shared IMETUtilityAthTool" );

    declareProperty( "DoSoftJets", m_doSoftJets = false );

  }

  METUtilAlg::~METUtilAlg() {}

  StatusCode METUtilAlg::initialize() {
    msg(MSG::INFO) << "Initialising!" << endreq;

    if(service("THistSvc", m_tHistSvc).isFailure()) {
      msg(MSG::WARNING) << "Failed to get histogram service!" << endreq;
      return StatusCode::FAILURE;
    }

    // Get the MET Utility AthAlgTool
    if(m_METUtilHandle.retrieve().isFailure()){
      msg(MSG::WARNING) << "Failed to get METUtilityAthTool." << endreq;
      return StatusCode::FAILURE;
    }

    // Define histograms
    TH1D* h_refFinal_AOD = new TH1D("h_refFinal_AOD","MET_RefFinal from AOD",50,0,500);
    if (m_tHistSvc->regHist("/outfile/metutil/h_refFinal_AOD",h_refFinal_AOD).isFailure()) {
      msg(MSG::ERROR) << "Couldn't register h_refFinal_AOD" << endmsg;
    }

    TH1D* h_refFinal_METUtil = new TH1D("h_refFinal_METUtil","MET_RefFinal from METUtility",50,0,500);
    if (m_tHistSvc->regHist("/outfile/metutil/h_refFinal_METUtil",h_refFinal_METUtil).isFailure()) {
      msg(MSG::ERROR) << "Couldn't register h_refFinal_METUtil" << endmsg;
    }

    TH1D* h_refFinal_diff = new TH1D("h_refFinal_diff","Difference between AOD and METUtility",50,-10,10);
    if (m_tHistSvc->regHist("/outfile/metutil/h_refFinal_diff",h_refFinal_diff).isFailure()) {
      msg(MSG::ERROR) << "Couldn't register h_refFinal_diff" << endmsg;
    }

    TH1D* h_refEle_diff = new TH1D("h_refEle_diff","Difference between AOD and METUtility",50,-10,10);
    if (m_tHistSvc->regHist("/outfile/metutil/h_refEle_diff",h_refEle_diff).isFailure()) {
      msg(MSG::ERROR) << "Couldn't register h_refEle_diff" << endmsg;
    }

    TH1D* h_refJet_diff = new TH1D("h_refJet_diff","Difference between AOD and METUtility",50,-10,10);
    if (m_tHistSvc->regHist("/outfile/metutil/h_refJet_diff",h_refJet_diff).isFailure()) {
      msg(MSG::ERROR) << "Couldn't register h_refJet_diff" << endmsg;
    }

    TH1D* h_refTau_diff = new TH1D("h_refTau_diff","Difference between AOD and METUtility",50,-10,10);
    if (m_tHistSvc->regHist("/outfile/metutil/h_refTau_diff",h_refTau_diff).isFailure()) {
      msg(MSG::ERROR) << "Couldn't register h_refTau_diff" << endmsg;
    }

    TH1D* h_refGamma_diff = new TH1D("h_refGamma_diff","Difference between AOD and METUtility",50,-10,10);
    if (m_tHistSvc->regHist("/outfile/metutil/h_refGamma_diff",h_refGamma_diff).isFailure()) {
      msg(MSG::ERROR) << "Couldn't register h_refGamma_diff" << endmsg;
    }

    TH1D* h_muonTotal_diff = new TH1D("h_muonTotal_diff","Difference between AOD and METUtility",50,-10,10);
    if (m_tHistSvc->regHist("/outfile/metutil/h_muonTotal_diff",h_muonTotal_diff).isFailure()) {
      msg(MSG::ERROR) << "Couldn't register h_muonTotal_diff" << endmsg;
    }

    TH1D* h_softTerms_diff = new TH1D("h_softTerms_diff","Difference between AOD and METUtility",50,-10,10);
    if (m_tHistSvc->regHist("/outfile/metutil/h_softTerms_diff",h_softTerms_diff).isFailure()) {
      msg(MSG::ERROR) << "Couldn't register h_softTerms_diff" << endmsg;
    }

    TH1D* h_refFinal_JESUP = new TH1D("h_refFinal_JESUP","MET_RefFinal with all systematics up",50,0,500);
    if (m_tHistSvc->regHist("/outfile/metutil/h_refFinal_JESUP",h_refFinal_JESUP).isFailure()) {
      msg(MSG::ERROR) << "Couldn't register h_refFinal_JESUP" << endmsg;
    }

    TH1D* h_refFinal_JESDOWN = new TH1D("h_refFinal_JESDOWN","MET_RefFinal with all systematics down",50,0,500);
    if (m_tHistSvc->regHist("/outfile/metutil/h_refFinal_JESDOWN",h_refFinal_JESDOWN).isFailure()) {
      msg(MSG::ERROR) << "Couldn't register h_refFinal_JESDOWN" << endmsg;
    }

    return StatusCode::SUCCESS;
  }

  StatusCode METUtilAlg::execute() {
    msg(MSG::DEBUG) << "In execute!" << endreq;

    // We grab the event info for the purposes of seeding random number generators
//     const EventInfo* myEventInfo = 0;
//     CHECK( evtStore()->retrieve(myEventInfo/*,"MyEvent"*/) );

    //   msg(MSG::DEBUG) << "Think I messed up the incident handling, so call process directly." << endreq;
    CHECK( m_METUtilHandle->process() );

    //   We check the x-component all the time so as to be able to use the sums to isolate problems.
    const MissingET refEle          = m_METUtilHandle->getMETTerm(METUtil::RefEle);
    const MissingET refGamma        = m_METUtilHandle->getMETTerm(METUtil::RefGamma);
    const MissingET refTau          = m_METUtilHandle->getMETTerm(METUtil::RefTau);
    const MissingET refMuon         = m_METUtilHandle->getMETTerm(METUtil::RefMuon);
    const MissingET refJet          = m_METUtilHandle->getMETTerm(METUtil::RefJet);
    const MissingET softTerms       = m_METUtilHandle->getMETTerm(METUtil::SoftTerms);
    const MissingET muonTotal       = m_METUtilHandle->getMETTerm(METUtil::MuonTotal);
    const MissingET refFinal        = m_METUtilHandle->getMETTerm(METUtil::RefFinal);

    const MissingET* MET_RefEle = 0;
    const MissingET* MET_RefGamma = 0;
    const MissingET* MET_RefTau = 0;
    const MissingET* MET_RefMuon = 0;
    const MissingET* MET_RefJet = 0;
    const MissingET* MET_MuonBoy = 0;
    const MissingET* MET_CellOut = 0;
    const MissingET* MET_RefFinal = 0;
    const MissingET* MET_SoftJets = 0;
    MissingET* MET_SoftTerms = new MissingET;

    if(evtStore()->retrieve(MET_RefEle, "MET_RefEle").isFailure()){
      msg(MSG::ERROR) << "Failed to get MET_RefEle from SG" << endreq;
      return StatusCode::FAILURE;
    }
    if(evtStore()->retrieve(MET_RefGamma, "MET_RefGamma").isFailure()){
      msg(MSG::ERROR) << "Failed to get MET_RefGamma from SG" << endreq;
      return StatusCode::FAILURE;
    }
    if(evtStore()->retrieve(MET_RefTau, "MET_RefTau").isFailure()){
      msg(MSG::ERROR) << "Failed to get MET_RefTau from SG" << endreq;
      return StatusCode::FAILURE;
    }
    if(evtStore()->retrieve(MET_RefMuon, "MET_RefMuon").isFailure()){
      msg(MSG::ERROR) << "Failed to get MET_RefMuon from SG" << endreq;
      return StatusCode::FAILURE;
    }
    if(evtStore()->retrieve(MET_RefJet, "MET_RefJet").isFailure()){
      msg(MSG::ERROR) << "Failed to get MET_RefJet from SG" << endreq;
      return StatusCode::FAILURE;
    }
    if(evtStore()->retrieve(MET_MuonBoy, "MET_MuonBoy").isFailure()){
      msg(MSG::ERROR) << "Failed to get MET_MuonBoy from SG" << endreq;
      return StatusCode::FAILURE;
    }
    if(evtStore()->retrieve(MET_CellOut, "MET_CellOut_Eflow").isFailure()){
      msg(MSG::ERROR) << "Failed to get MET_CellOut_Eflow from SG" << endreq;
      return StatusCode::FAILURE;
    } else {
      MET_SoftTerms->setEx(MET_CellOut->etx());
      MET_SoftTerms->setEy(MET_CellOut->ety());
      MET_SoftTerms->setEtSum(MET_CellOut->sumet());
    }
    if(m_doSoftJets && evtStore()->retrieve(MET_SoftJets, "MET_SoftJets").isSuccess()){
      msg(MSG::INFO) << "Adding SoftJets into SoftTerms" << endreq;

      msg(MSG::DEBUG) << "Compare CellOut : " << MET_CellOut->etx() << " (orig), "
		      << m_METUtilHandle->getMissingET(METUtil::SoftTerms).etx() << endreq;

      MET_SoftTerms->setEx(MET_CellOut->etx()+MET_SoftJets->etx());
      MET_SoftTerms->setEy(MET_CellOut->ety()+MET_SoftJets->ety());
      MET_SoftTerms->setEtSum(MET_CellOut->sumet()+MET_SoftJets->sumet());
    }
    if(evtStore()->retrieve(MET_RefFinal, "MET_RefFinal").isFailure()){
      msg(MSG::ERROR) << "Failed to get MET_RefFinal from SG" << endreq;
      return StatusCode::FAILURE;
    }

    msg(MSG::DEBUG) << "+++++++++++++++++++++++++++++" << endreq;
    msg(MSG::DEBUG) << "Term:               Original       Tool output" << endreq;
    msg(MSG::DEBUG) << "RefEle etx:        " << MET_RefEle->etx()        << " vs " << refEle.etx()    << endreq;
    msg(MSG::DEBUG) << "RefGamma etx:      " << MET_RefGamma->etx()      << " vs " << refGamma.etx()  << endreq;
    msg(MSG::DEBUG) << "RefTau etx:        " << MET_RefTau->etx()        << " vs " << refTau.etx()    << endreq;
    msg(MSG::DEBUG) << "RefMuon etx:       " << MET_RefMuon->etx()       << " vs " << refMuon.etx()   << endreq;
    msg(MSG::DEBUG) << "RefJet etx:        " << MET_RefJet->etx()        << " vs " << refJet.etx()    << endreq;
    msg(MSG::DEBUG) << "MuonBoy etx:       " << MET_MuonBoy->etx()       << " vs " << muonTotal.etx() << endreq;
    msg(MSG::DEBUG) << "SoftTerms etx:     " << MET_SoftTerms->etx()     << " vs " << softTerms.etx() << endreq;
    msg(MSG::DEBUG) << "RefFinal etx:      " << MET_RefFinal->etx()      << " vs " << refFinal.etx()  << endreq;

    msg(MSG::DEBUG) << "+++++++++++++++++++++++++++++" << endreq;
    msg(MSG::DEBUG) << "Systematics comparison (et) :" << endreq;
    msg(MSG::DEBUG) << "MET RefFinal           = " << m_METUtilHandle->getMETTerm(METUtil::RefFinal).et() << endreq;
    msg(MSG::DEBUG) << "MET RefFinal_JESUp     = " << m_METUtilHandle->getMETTerm(METUtil::RefFinal,METUtil::JESUp).et() << endreq;
    msg(MSG::DEBUG) << "MET RefFinal_JESDown   = " << m_METUtilHandle->getMETTerm(METUtil::RefFinal,METUtil::JESDown).et() << endreq;
    msg(MSG::DEBUG) << "MET RefFinal_EESUp     = " << m_METUtilHandle->getMETTerm(METUtil::RefFinal,METUtil::EESUp).et() << endreq;
    msg(MSG::DEBUG) << "MET RefFinal_EESDown   = " << m_METUtilHandle->getMETTerm(METUtil::RefFinal,METUtil::EESDown).et() << endreq;
    msg(MSG::DEBUG) << "MET RefFinal_MESUp     = " << m_METUtilHandle->getMETTerm(METUtil::RefFinal,METUtil::MESUp).et() << endreq;
    msg(MSG::DEBUG) << "MET RefFinal_MESDown   = " << m_METUtilHandle->getMETTerm(METUtil::RefFinal,METUtil::MESDown).et() << endreq;
    msg(MSG::DEBUG) << "MET RefFinal_JERUp     = " << m_METUtilHandle->getMETTerm(METUtil::RefFinal,METUtil::JERUp).et() << endreq;
    msg(MSG::DEBUG) << "MET RefFinal_JERDown   = " << m_METUtilHandle->getMETTerm(METUtil::RefFinal,METUtil::JERDown).et() << endreq;
    msg(MSG::DEBUG) << "MET RefFinal_EERUp     = " << m_METUtilHandle->getMETTerm(METUtil::RefFinal,METUtil::EERUp).et() << endreq;
    msg(MSG::DEBUG) << "MET RefFinal_EERDown   = " << m_METUtilHandle->getMETTerm(METUtil::RefFinal,METUtil::EERDown).et() << endreq;
    msg(MSG::DEBUG) << "MET RefFinal_MERIDUp     = " << m_METUtilHandle->getMETTerm(METUtil::RefFinal,METUtil::MERIDUp).et() << endreq;
    msg(MSG::DEBUG) << "MET RefFinal_MERIDDown   = " << m_METUtilHandle->getMETTerm(METUtil::RefFinal,METUtil::MERIDDown).et() << endreq;
    msg(MSG::DEBUG) << "MET RefFinal_MERMSUp     = " << m_METUtilHandle->getMETTerm(METUtil::RefFinal,METUtil::MERMSUp).et() << endreq;
    msg(MSG::DEBUG) << "MET RefFinal_MERMSDown   = " << m_METUtilHandle->getMETTerm(METUtil::RefFinal,METUtil::MERMSDown).et() << endreq;
    msg(MSG::DEBUG) << "MET RefFinal_ScaleSoftTermsUp     = " << m_METUtilHandle->getMETTerm(METUtil::RefFinal,METUtil::ScaleSoftTermsUp).et() << endreq;
    msg(MSG::DEBUG) << "MET RefFinal_ScaleSoftTermsDown   = " << m_METUtilHandle->getMETTerm(METUtil::RefFinal,METUtil::ScaleSoftTermsDown).et() << endreq;
    msg(MSG::DEBUG) << "MET RefFinal_ResoSoftTermsUp     = " << m_METUtilHandle->getMETTerm(METUtil::RefFinal,METUtil::ResoSoftTermsUp).et() << endreq;
    msg(MSG::DEBUG) << "MET RefFinal_ResoSoftTermsDown   = " << m_METUtilHandle->getMETTerm(METUtil::RefFinal,METUtil::ResoSoftTermsDown).et() << endreq;
    msg(MSG::DEBUG) << "Delta MET RefFinal_All = " << m_METUtilHandle->deltaMissingET(METUtil::RefFinal,METUtil::All).et() << endreq;


    // Retrieve and fill histograms

    // Define histograms
    TH1* h_refFinal_AOD = 0;
    if (m_tHistSvc->getHist("/outfile/metutil/h_refFinal_AOD",h_refFinal_AOD).isFailure()) {
      msg(MSG::ERROR) << "Couldn't retrieve h_refFinal_AOD" << endmsg;
    }
    h_refFinal_AOD->Fill(MET_RefFinal->et()/GeV);

    TH1* h_refFinal_METUtil = 0;
    if (m_tHistSvc->getHist("/outfile/metutil/h_refFinal_METUtil",h_refFinal_METUtil).isFailure()) {
      msg(MSG::ERROR) << "Couldn't retrieve h_refFinal_METUtil" << endmsg;
    }
    h_refFinal_METUtil->Fill(refFinal.et()/GeV);

    TH1* h_refFinal_diff = 0;
    if (m_tHistSvc->getHist("/outfile/metutil/h_refFinal_diff",h_refFinal_diff).isFailure()) {
      msg(MSG::ERROR) << "Couldn't retrieve h_refFinal_diff" << endmsg;
    }
    h_refFinal_diff->Fill((MET_RefFinal->et()-refFinal.et())/GeV);

    TH1* h_refEle_diff = 0;
    if (m_tHistSvc->getHist("/outfile/metutil/h_refEle_diff",h_refEle_diff).isFailure()) {
      msg(MSG::ERROR) << "Couldn't retrieve h_refEle_diff" << endmsg;
    }
    h_refEle_diff->Fill((MET_RefEle->et()-refEle.et())/GeV);

    TH1* h_refJet_diff = 0;
    if (m_tHistSvc->getHist("/outfile/metutil/h_refJet_diff",h_refJet_diff).isFailure()) {
      msg(MSG::ERROR) << "Couldn't retrieve h_refJet_diff" << endmsg;
    }
    h_refJet_diff->Fill((MET_RefJet->et()-refJet.et())/GeV);

    TH1* h_refGamma_diff = 0;
    if (m_tHistSvc->getHist("/outfile/metutil/h_refGamma_diff",h_refGamma_diff).isFailure()) {
      msg(MSG::ERROR) << "Couldn't retrieve h_refGamma_diff" << endmsg;
    }
    h_refGamma_diff->Fill((MET_RefGamma->et()-refGamma.et())/GeV);

    TH1* h_refTau_diff = 0;
    if (m_tHistSvc->getHist("/outfile/metutil/h_refTau_diff",h_refTau_diff).isFailure()) {
      msg(MSG::ERROR) << "Couldn't retrieve h_refTau_diff" << endmsg;
    }
    h_refTau_diff->Fill((MET_RefTau->et()-refTau.et())/GeV);

    TH1* h_muonTotal_diff = 0;
    if (m_tHistSvc->getHist("/outfile/metutil/h_muonTotal_diff",h_muonTotal_diff).isFailure()) {
      msg(MSG::ERROR) << "Couldn't retrieve h_muonTotal_diff" << endmsg;
    }
    h_muonTotal_diff->Fill((MET_MuonBoy->et()-muonTotal.et())/GeV);

    TH1* h_softTerms_diff = 0;
    if (m_tHistSvc->getHist("/outfile/metutil/h_softTerms_diff",h_softTerms_diff).isFailure()) {
      msg(MSG::ERROR) << "Couldn't retrieve h_softTerms_diff" << endmsg;
    }
    h_softTerms_diff->Fill((MET_SoftTerms->et()-softTerms.et())/GeV);

    TH1* h_refFinal_JESUP = 0;
    if (m_tHistSvc->getHist("/outfile/metutil/h_refFinal_JESUP",h_refFinal_JESUP).isFailure()) {
      msg(MSG::ERROR) << "Couldn't retrieve h_refFinal_JESUP" << endmsg;
    }
    h_refFinal_JESUP->Fill(m_METUtilHandle->getMETTerm(METUtil::RefFinal,METUtil::JESUp).et()/GeV);

    TH1* h_refFinal_JESDOWN = 0;
    if (m_tHistSvc->getHist("/outfile/metutil/h_refFinal_JESDOWN",h_refFinal_JESDOWN).isFailure()) {
      msg(MSG::ERROR) << "Couldn't retrieve h_refFinal_JESDOWN" << endmsg;
    }
    h_refFinal_JESDOWN->Fill(m_METUtilHandle->getMETTerm(METUtil::RefFinal,METUtil::JESDown).et()/GeV);

    delete MET_SoftTerms;
    return StatusCode::SUCCESS;
  }

  StatusCode METUtilAlg::finalize(){
    msg(MSG::INFO) << "Goodbye cruel world!" << endreq;

    return StatusCode::SUCCESS;
  }

}
