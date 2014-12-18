#include "./METUtilityAthD3PDTool.h"

#include "SGTools/BuiltinsClids.h" 
#include "SGTools/StlVectorClids.h"

#include "AthenaKernel/errorcheck.h"

#include <math.h>


// Constructor
METUtilityAthD3PDTool::METUtilityAthD3PDTool(const string& type, const string& name,
					     const IInterface* pParent) :
  AthAlgTool(type, name, pParent),
  METUtility(),
  m_electronPTGiven(false),
  m_muonPTGiven(false),
  m_photonPTGiven(false),
  m_jetPTGiven(false)
{

  declareInterface< IMETUtilityAthD3PDTool >(this);

  // For MET configurations other than standard MET_RefFinal
  declareProperty("METSuffix",         m_metsuffix         =  ""                           );

  // If you know ahead of time whether your D3PD has MET store as x/y components
  // or et/phi, you can set 1 (x/y) or 2(et/phi). Setting 0 autoconfigures.
  declareProperty("METBranchType",     m_metbranchtype     =  0                            );

  // Whether to automatically set up this tool at the beginning of each event
  declareProperty("ResetEveryEvent",   m_resetEveryEvent   =  true                         );

  // Tool configuration
  declareProperty("DoSignif",          m_doSignif          =  false                        );
  declareProperty("Verbosity",         m_verbosity         =  false                        );

  // MET definition
  declareProperty("DoRefEle",          m_dorefele          =  true                         );
  declareProperty("DoRefGamma",        m_dorefgamma        =  true                         );
  declareProperty("DoRefTau",          m_doreftau          =  true                         );
  declareProperty("DoRefJet",          m_dorefjet          =  true                         );
  declareProperty("DoRefMuon",         m_dorefmuon         =  true                         );
  declareProperty("DoMuonTotal",       m_domuontotal       =  true                         );
  declareProperty("DoSoftTerms",         m_dosoftterms         =  true                         );
  declareProperty("IsMuid",            m_ismuid            =  false                        );
  declareProperty("SoftJetCut",        m_softjetcut        =  20000.0                      ); 

}

// Destructor
METUtilityAthD3PDTool::~METUtilityAthD3PDTool()
{

}

StatusCode METUtilityAthD3PDTool::queryInterface( const InterfaceID& riid, void** ppvIf )
{
  if ( riid == IMETUtilityAthD3PDTool::interfaceID() )  {
    *ppvIf = (IMETUtilityAthD3PDTool*)this;
    addRef();
    return StatusCode::SUCCESS;
  }

  return AthAlgTool::queryInterface( riid, ppvIf );
}


StatusCode METUtilityAthD3PDTool::initialize() {
  msg(MSG::INFO) << "Initialising MissingETUtility" << endreq;
  msg(MSG::INFO) << "Using " << (m_ismuid ? "MUID" : "non-MUID") << " muons"
		 << endreq;

  // Set up the MET details
  doSignificance(m_doSignif);
  setVerbosity(m_verbosity);

  defineMissingET(m_dorefele, m_dorefgamma, m_doreftau, m_dorefjet,
		  m_dorefmuon, m_domuontotal, m_dosoftterms);
  setIsMuid(m_ismuid);

  IIncidentSvc* incsvc;
  StatusCode sc = service("IncidentSvc", incsvc);
  int priority = 100;
  if( sc.isSuccess() ) {
    incsvc->addListener( this, "BeginEvent", priority);
  }

  return StatusCode::SUCCESS;
}

StatusCode METUtilityAthD3PDTool::finalize(){
  msg(MSG::INFO) << "Finalising MissingETUtility." << endreq;
  METUtility::reset();

  msg(MSG::DEBUG) << "Nice to have MET you." << endreq;

  return StatusCode::SUCCESS;
}


////////////////////////// * Set object collections * //////////////////////////////////

StatusCode METUtilityAthD3PDTool::setElectronPT(std::vector<float> pt, std::string collName) {
  const std::vector<float>* el_eta = 0; CHECK( evtStore()->retrieve(el_eta,collName+"_eta") );
  const std::vector<float>* el_phi = 0; CHECK( evtStore()->retrieve(el_phi,collName+"_phi") );

  const std::vector<std::vector<float> >* el_wet = 0; CHECK( evtStore()->retrieve(el_wet,collName+"_MET"+m_metsuffix+"_wet") );
  const std::vector<std::vector<float> >* el_wpx = 0; CHECK( evtStore()->retrieve(el_wpx,collName+"_MET"+m_metsuffix+"_wpx") );
  const std::vector<std::vector<float> >* el_wpy = 0; CHECK( evtStore()->retrieve(el_wpy,collName+"_MET"+m_metsuffix+"_wpy") );

  const std::vector<std::vector<unsigned int> >* stat = 0; CHECK( evtStore()->retrieve(stat,collName+"_MET"+m_metsuffix+"_statusWord") );

  setElectronParameters(&pt, el_eta, el_phi, el_wet, el_wpx, el_wpy, stat);

  m_electronPTGiven = true;

  return StatusCode::SUCCESS;
}

StatusCode METUtilityAthD3PDTool::setPhotonPT(std::vector<float> pt, std::string collName) {
  const std::vector<float>* ph_eta = 0; CHECK( evtStore()->retrieve(ph_eta,collName+"_eta") );
  const std::vector<float>* ph_phi = 0; CHECK( evtStore()->retrieve(ph_phi,collName+"_phi") );

  const std::vector<std::vector<float> >* ph_wet = 0; CHECK( evtStore()->retrieve(ph_wet,collName+"_MET"+m_metsuffix+"_wet") );
  const std::vector<std::vector<float> >* ph_wpx = 0; CHECK( evtStore()->retrieve(ph_wpx,collName+"_MET"+m_metsuffix+"_wpx") );
  const std::vector<std::vector<float> >* ph_wpy = 0; CHECK( evtStore()->retrieve(ph_wpy,collName+"_MET"+m_metsuffix+"_wpy") );

  const std::vector<std::vector<unsigned int> >* stat = 0; CHECK( evtStore()->retrieve(stat,collName+"_MET"+m_metsuffix+"_statusWord") );

  setPhotonParameters(&pt, ph_eta, ph_phi, ph_wet, ph_wpx, ph_wpy, stat);

  m_photonPTGiven = true;

  return StatusCode::SUCCESS;
}

StatusCode METUtilityAthD3PDTool::setMuonPT(std::vector<float> pt, std::vector<float> ms_pt,std::string collName) {
  const std::vector<float>* mu_eta = 0; CHECK( evtStore()->retrieve(mu_eta,collName+"_eta") );
  const std::vector<float>* mu_phi = 0; CHECK( evtStore()->retrieve(mu_phi,collName+"_phi") );

  const std::vector<std::vector<float> >* mu_wet = 0; CHECK( evtStore()->retrieve(mu_wet,collName+"_MET"+m_metsuffix+"_wet") );
  const std::vector<std::vector<float> >* mu_wpx = 0; CHECK( evtStore()->retrieve(mu_wpx,collName+"_MET"+m_metsuffix+"_wpx") );
  const std::vector<std::vector<float> >* mu_wpy = 0; CHECK( evtStore()->retrieve(mu_wpy,collName+"_MET"+m_metsuffix+"_wpy") );

  const std::vector<std::vector<unsigned int> >* stat = 0; CHECK( evtStore()->retrieve(stat,collName+"_MET"+m_metsuffix+"_statusWord") );

  setMuonParameters(&pt, mu_eta, mu_phi, mu_wet, mu_wpx, mu_wpy, stat);

  const std::vector<float>* ms_mu_theta = 0; CHECK( evtStore()->retrieve(ms_mu_theta,collName+"_ms_theta") );
  const std::vector<float>* ms_mu_phi = 0;   CHECK( evtStore()->retrieve(ms_mu_phi,collName+"_ms_phi") );

  setExtraMuonParameters(&ms_pt,ms_mu_theta,ms_mu_phi);

  m_muonPTGiven = true;

  return StatusCode::SUCCESS;
}

StatusCode METUtilityAthD3PDTool::setJetPT(std::vector<float> pt, std::vector<float> e, std::string collName) {
  const std::vector<float>* jet_pt = 0;  CHECK( evtStore()->retrieve(jet_pt,collName+"_pt") );
  const std::vector<float>* jet_eta = 0; CHECK( evtStore()->retrieve(jet_eta,collName+"_eta") );
  const std::vector<float>* jet_phi = 0; CHECK( evtStore()->retrieve(jet_phi,collName+"_phi") );

  const std::vector<std::vector<float> >* jet_wet = 0; CHECK( evtStore()->retrieve(jet_wet,collName+"_MET"+m_metsuffix+"_wet") );
  const std::vector<std::vector<float> >* jet_wpx = 0; CHECK( evtStore()->retrieve(jet_wpx,collName+"_MET"+m_metsuffix+"_wpx") );
  const std::vector<std::vector<float> >* jet_wpy = 0; CHECK( evtStore()->retrieve(jet_wpy,collName+"_MET"+m_metsuffix+"_wpy") );

  const std::vector<std::vector<unsigned int> >* stat = 0; CHECK( evtStore()->retrieve(stat,collName+"_MET"+m_metsuffix+"_statusWord") );

  setJetParameters(&pt,jet_eta,jet_phi,&e,jet_wet,jet_wpx,jet_wpy,stat);

  m_jetPTGiven = true;

  return StatusCode::SUCCESS;
}

////////////////////////// * Set MET terms directly * //////////////////////////////////

StatusCode METUtilityAthD3PDTool::setMET_xy() {

  if(!m_electronPTGiven) {
    const Float_t* MET_RefEle_etx = 0;   CHECK( evtStore()->retrieve(MET_RefEle_etx,"MET_RefEle"+m_metsuffix+"_etx") );
    const Float_t* MET_RefEle_ety = 0;   CHECK( evtStore()->retrieve(MET_RefEle_ety,"MET_RefEle"+m_metsuffix+"_ety") );
    const Float_t* MET_RefEle_sumet = 0; CHECK( evtStore()->retrieve(MET_RefEle_sumet,"MET_RefEle"+m_metsuffix+"_sumet") );
    METUtility::setMETTerm(METUtil::RefEle, *MET_RefEle_etx, *MET_RefEle_ety, *MET_RefEle_sumet);
  }

  if(!m_photonPTGiven) {
    const Float_t* MET_RefGamma_etx = 0;   CHECK( evtStore()->retrieve(MET_RefGamma_etx,"MET_RefGamma"+m_metsuffix+"_etx") );
    const Float_t* MET_RefGamma_ety = 0;   CHECK( evtStore()->retrieve(MET_RefGamma_ety,"MET_RefGamma"+m_metsuffix+"_ety") );
    const Float_t* MET_RefGamma_sumet = 0; CHECK( evtStore()->retrieve(MET_RefGamma_sumet,"MET_RefGamma"+m_metsuffix+"_sumet") );
    METUtility::setMETTerm(METUtil::RefGamma, *MET_RefGamma_etx, *MET_RefGamma_ety, *MET_RefGamma_sumet);
  }

  if(!m_jetPTGiven) {
    const Float_t* MET_RefJet_etx = 0;   CHECK( evtStore()->retrieve(MET_RefJet_etx,"MET_RefJet"+m_metsuffix+"_etx") );
    const Float_t* MET_RefJet_ety = 0;   CHECK( evtStore()->retrieve(MET_RefJet_ety,"MET_RefJet"+m_metsuffix+"_ety") );
    const Float_t* MET_RefJet_sumet = 0; CHECK( evtStore()->retrieve(MET_RefJet_sumet,"MET_RefJet"+m_metsuffix+"_sumet") );
    METUtility::setMETTerm(METUtil::RefJet, *MET_RefJet_etx, *MET_RefJet_ety, *MET_RefJet_sumet);  
  }

  const Float_t* MET_RefTau_etx = 0;   CHECK( evtStore()->retrieve(MET_RefTau_etx,"MET_RefTau"+m_metsuffix+"_etx") );
  const Float_t* MET_RefTau_ety = 0;   CHECK( evtStore()->retrieve(MET_RefTau_ety,"MET_RefTau"+m_metsuffix+"_ety") );
  const Float_t* MET_RefTau_sumet = 0; CHECK( evtStore()->retrieve(MET_RefTau_sumet,"MET_RefTau"+m_metsuffix+"_sumet") );
  METUtility::setMETTerm(METUtil::RefTau, *MET_RefTau_etx, *MET_RefTau_ety, *MET_RefTau_sumet);  

  if(!m_muonPTGiven) {
    const Float_t* MET_MuonBoy_etx = 0;   CHECK( evtStore()->retrieve(MET_MuonBoy_etx,"MET_MuonBoy"+m_metsuffix+"_etx") );
    const Float_t* MET_MuonBoy_ety = 0;   CHECK( evtStore()->retrieve(MET_MuonBoy_ety,"MET_MuonBoy"+m_metsuffix+"_ety") );
    const Float_t* MET_MuonBoy_sumet = 0; CHECK( evtStore()->retrieve(MET_MuonBoy_sumet,"MET_MuonBoy"+m_metsuffix+"_sumet") );
    METUtility::setMETTerm(METUtil::MuonTotal, *MET_MuonBoy_etx, *MET_MuonBoy_ety, *MET_MuonBoy_sumet);  
  }

  const Float_t* MET_RefMuon_etx = 0;   CHECK( evtStore()->retrieve(MET_RefMuon_etx,"MET_RefMuon"+m_metsuffix+"_etx") );
  const Float_t* MET_RefMuon_ety = 0;   CHECK( evtStore()->retrieve(MET_RefMuon_ety,"MET_RefMuon"+m_metsuffix+"_ety") );
  const Float_t* MET_RefMuon_sumet = 0; CHECK( evtStore()->retrieve(MET_RefMuon_sumet,"MET_RefMuon"+m_metsuffix+"_sumet") );
  METUtility::setMETTerm(METUtil::RefMuon, *MET_RefMuon_etx, *MET_RefMuon_ety, *MET_RefMuon_sumet);

  if(m_isEflow) {
    const Float_t* MET_SoftTerms_Eflow_etx = 0;   CHECK( evtStore()->retrieve(MET_SoftTerms_Eflow_etx,"MET_SoftTerms_Eflow"+m_metsuffix+"_etx") );
    const Float_t* MET_SoftTerms_Eflow_ety = 0;   CHECK( evtStore()->retrieve(MET_SoftTerms_Eflow_ety,"MET_SoftTerms_Eflow"+m_metsuffix+"_ety") );
    const Float_t* MET_SoftTerms_Eflow_sumet = 0; CHECK( evtStore()->retrieve(MET_SoftTerms_Eflow_sumet,"MET_SoftTerms_Eflow"+m_metsuffix+"_sumet") );
    METUtility::setMETTerm(METUtil::SoftTerms, *MET_SoftTerms_Eflow_etx, *MET_SoftTerms_Eflow_ety, *MET_SoftTerms_Eflow_sumet);
  } else {
    const Float_t* MET_SoftTerms_etx = 0;   CHECK( evtStore()->retrieve(MET_SoftTerms_etx,"MET_SoftTerms"+m_metsuffix+"_etx") );
    const Float_t* MET_SoftTerms_ety = 0;   CHECK( evtStore()->retrieve(MET_SoftTerms_ety,"MET_SoftTerms"+m_metsuffix+"_ety") );
    const Float_t* MET_SoftTerms_sumet = 0; CHECK( evtStore()->retrieve(MET_SoftTerms_sumet,"MET_SoftTerms"+m_metsuffix+"_sumet") );
    METUtility::setMETTerm(METUtil::SoftTerms, *MET_SoftTerms_etx, *MET_SoftTerms_ety, *MET_SoftTerms_sumet);
  }

  return StatusCode::SUCCESS;
}

StatusCode METUtilityAthD3PDTool::setMET_etphi() {

  if(!m_electronPTGiven) {
    const Float_t* MET_RefEle_phi = 0;   CHECK( evtStore()->retrieve(MET_RefEle_phi,"MET_RefEle"+m_metsuffix+"_phi") );
    const Float_t* MET_RefEle_et = 0;    CHECK( evtStore()->retrieve(MET_RefEle_et,"MET_RefEle"+m_metsuffix+"_et") );
    const Float_t* MET_RefEle_sumet = 0; CHECK( evtStore()->retrieve(MET_RefEle_sumet,"MET_RefEle"+m_metsuffix+"_sumet") );
    double MET_RefEle_etx = *MET_RefEle_et*cos(*MET_RefEle_phi);
    double MET_RefEle_ety = *MET_RefEle_et*sin(*MET_RefEle_phi);
    METUtility::setMETTerm(METUtil::RefEle, MET_RefEle_etx, MET_RefEle_ety, *MET_RefEle_sumet);  
  }

  if(!m_photonPTGiven) {
    const Float_t* MET_RefGamma_phi = 0;   CHECK( evtStore()->retrieve(MET_RefGamma_phi,"MET_RefGamma"+m_metsuffix+"_phi") );
    const Float_t* MET_RefGamma_et = 0;    CHECK( evtStore()->retrieve(MET_RefGamma_et,"MET_RefGamma"+m_metsuffix+"_et") );
    const Float_t* MET_RefGamma_sumet = 0; CHECK( evtStore()->retrieve(MET_RefGamma_sumet,"MET_RefGamma"+m_metsuffix+"_sumet") );
    double MET_RefGamma_etx = *MET_RefGamma_et*cos(*MET_RefGamma_phi);
    double MET_RefGamma_ety = *MET_RefGamma_et*sin(*MET_RefGamma_phi);
    METUtility::setMETTerm(METUtil::RefGamma, MET_RefGamma_etx, MET_RefGamma_ety, *MET_RefGamma_sumet);
  }

  if(!m_jetPTGiven) {
    const Float_t* MET_RefJet_phi = 0;   CHECK( evtStore()->retrieve(MET_RefJet_phi,"MET_RefJet"+m_metsuffix+"_phi") );
    const Float_t* MET_RefJet_et = 0;    CHECK( evtStore()->retrieve(MET_RefJet_et,"MET_RefJet"+m_metsuffix+"_et") );
    const Float_t* MET_RefJet_sumet = 0; CHECK( evtStore()->retrieve(MET_RefJet_sumet,"MET_RefJet"+m_metsuffix+"_sumet") );
    double MET_RefJet_etx = *MET_RefJet_et*cos(*MET_RefJet_phi);
    double MET_RefJet_ety = *MET_RefJet_et*sin(*MET_RefJet_phi);
    METUtility::setMETTerm(METUtil::RefJet, MET_RefJet_etx, MET_RefJet_ety, *MET_RefJet_sumet);  
  }

  const Float_t* MET_RefTau_phi = 0;   CHECK( evtStore()->retrieve(MET_RefTau_phi,"MET_RefTau"+m_metsuffix+"_phi") );
  const Float_t* MET_RefTau_et = 0;    CHECK( evtStore()->retrieve(MET_RefTau_et,"MET_RefTau"+m_metsuffix+"_et") );
  const Float_t* MET_RefTau_sumet = 0; CHECK( evtStore()->retrieve(MET_RefTau_sumet,"MET_RefTau"+m_metsuffix+"_sumet") );
  double MET_RefTau_etx = *MET_RefTau_et*cos(*MET_RefTau_phi);
  double MET_RefTau_ety = *MET_RefTau_et*sin(*MET_RefTau_phi);
  METUtility::setMETTerm(METUtil::RefTau, MET_RefTau_etx, MET_RefTau_ety, *MET_RefTau_sumet);  

  if(!m_muonPTGiven) {
    const Float_t* MET_MuonBoy_phi = 0;   CHECK( evtStore()->retrieve(MET_MuonBoy_phi,"MET_MuonBoy"+m_metsuffix+"_phi") );
    const Float_t* MET_MuonBoy_et = 0;    CHECK( evtStore()->retrieve(MET_MuonBoy_et,"MET_MuonBoy"+m_metsuffix+"_et") );
    const Float_t* MET_MuonBoy_sumet = 0; CHECK( evtStore()->retrieve(MET_MuonBoy_sumet,"MET_MuonBoy"+m_metsuffix+"_sumet") );
    double MET_MuonBoy_etx = *MET_MuonBoy_et*cos(*MET_MuonBoy_phi);
    double MET_MuonBoy_ety = *MET_MuonBoy_et*sin(*MET_MuonBoy_phi);
    METUtility::setMETTerm(METUtil::MuonTotal, MET_MuonBoy_etx, MET_MuonBoy_ety, *MET_MuonBoy_sumet);  
  }

  const Float_t* MET_RefMuon_phi = 0;   CHECK( evtStore()->retrieve(MET_RefMuon_phi,"MET_RefMuon"+m_metsuffix+"_phi") );
  const Float_t* MET_RefMuon_et = 0;    CHECK( evtStore()->retrieve(MET_RefMuon_et,"MET_RefMuon"+m_metsuffix+"_et") );
  const Float_t* MET_RefMuon_sumet = 0; CHECK( evtStore()->retrieve(MET_RefMuon_sumet,"MET_RefMuon"+m_metsuffix+"_sumet") );
  double MET_RefMuon_etx = *MET_RefMuon_et*cos(*MET_RefMuon_phi);
  double MET_RefMuon_ety = *MET_RefMuon_et*sin(*MET_RefMuon_phi);
  METUtility::setMETTerm(METUtil::RefMuon, MET_RefMuon_etx, MET_RefMuon_ety, *MET_RefMuon_sumet);

  if(m_isEflow) {
    const Float_t* MET_SoftTerms_Eflow_phi = 0;   CHECK( evtStore()->retrieve(MET_SoftTerms_Eflow_phi,"MET_SoftTerms_Eflow"+m_metsuffix+"_phi") );
    const Float_t* MET_SoftTerms_Eflow_et = 0;    CHECK( evtStore()->retrieve(MET_SoftTerms_Eflow_et,"MET_SoftTerms_Eflow"+m_metsuffix+"_et") );
    const Float_t* MET_SoftTerms_Eflow_sumet = 0; CHECK( evtStore()->retrieve(MET_SoftTerms_Eflow_sumet,"MET_SoftTerms_Eflow"+m_metsuffix+"_sumet") );
    double MET_SoftTerms_Eflow_etx = *MET_SoftTerms_Eflow_et*cos(*MET_SoftTerms_Eflow_phi);
    double MET_SoftTerms_Eflow_ety = *MET_SoftTerms_Eflow_et*sin(*MET_SoftTerms_Eflow_phi);
    METUtility::setMETTerm(METUtil::SoftTerms, MET_SoftTerms_Eflow_etx, MET_SoftTerms_Eflow_ety, *MET_SoftTerms_Eflow_sumet);
  } else {
    const Float_t* MET_SoftTerms_phi = 0;   CHECK( evtStore()->retrieve(MET_SoftTerms_phi,"MET_SoftTerms"+m_metsuffix+"_phi") );
    const Float_t* MET_SoftTerms_et = 0;    CHECK( evtStore()->retrieve(MET_SoftTerms_et,"MET_SoftTerms"+m_metsuffix+"_et") );
    const Float_t* MET_SoftTerms_sumet = 0; CHECK( evtStore()->retrieve(MET_SoftTerms_sumet,"MET_SoftTerms"+m_metsuffix+"_sumet") );
    double MET_SoftTerms_etx = *MET_SoftTerms_et*cos(*MET_SoftTerms_phi);
    double MET_SoftTerms_ety = *MET_SoftTerms_et*sin(*MET_SoftTerms_phi);
    METUtility::setMETTerm(METUtil::SoftTerms, MET_SoftTerms_etx, MET_SoftTerms_ety, *MET_SoftTerms_sumet);
  }
  return StatusCode::SUCCESS;
}

//////////////////// * Set things up at the start of each event * //////////////////////////

void METUtilityAthD3PDTool::handle(const Incident& inc) {
  // Get the messaging service, print where you are

  msg(MSG::DEBUG) << "entering handle(), incidence type " << inc.type()
		  << " from " << inc.source() << endreq;

  // Only call fillIOV for EndEvent incident
  if (inc.type() != "BeginEvent") return;
  
  m_electronPTGiven = false;
  m_photonPTGiven = false;
  m_jetPTGiven = false;
  m_muonPTGiven = false;
  METUtility::reset();

  if(m_metbranchtype<2) m_metbranchtype = (setMET_xy().isFailure()) ? 2 : 1;
  if(m_metbranchtype==2) {
     if(setMET_etphi().isFailure()) { ATH_MSG_ERROR("Cannot load necessary MET weights"); throw 1; }
  }

  msg(MSG::DEBUG) << "end event handle" << endreq;
}
