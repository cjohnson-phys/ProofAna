#include "./METUtilityAthTool.h"

#include "JetUncertainties/MultijetJESUncertaintyProvider.h"
#include "ApplyJetCalibration/ApplyJetCalibration.h"
#include "ApplyJetResolutionSmearing/ApplyJetSmearing.h"
#include "MuonMomentumCorrections/SmearingClass.h"
#include "egammaAnalysisUtils/EnergyRescalerUpgrade.h"
#include "TesUncertaintyProvider/TESUncertaintyProvider.h"
#include <TRandom2.h>
#include <TMath.h>
#include <TString.h>

#include "AthenaKernel/errorcheck.h"
#include "FourMomUtils/P4Helpers.h"
#include "EventInfo/EventID.h"
#include "EventInfo/EventType.h"
#include "EventInfo/EventInfo.h"
#include "MissingETEvent/MissingETComposition.h"
#include "JetEvent/JetCollection.h"
#include "CaloEvent/CaloClusterContainer.h"
#include "egammaEvent/ElectronContainer.h"
#include "egammaEvent/PhotonContainer.h"
#include "muonEvent/MuonContainer.h"
#include "tauEvent/TauJetContainer.h"
#include "VxVertex/VxContainer.h"
#include "EventKernel/SignalStateHelper.h"
#include "EventShapeInterface/IEventEtDensityProvider.h"
#include "JetTagInfo/TruthInfo.h"
#include "MissingETEvent/MissingEtTruth.h"

namespace MissingETUtility {

  //////////////////////////////////////////////////////////////////////////////////////////////////
  // Constructor
  //
  METUtilityAthTool::METUtilityAthTool(const string& type, const string& name,
				       const IInterface* pParent) :
    AthAlgTool(type, name, pParent),
    METUtility(), // defaults, will be overwritten by configuration anyway.
    m_jetCalibTool(0),
    m_JERTool(0),
    m_multiJES(0),
    m_egammaTool(0),
    m_muonTool(0),
    m_TESTool(0),
    m_isData(false),
    m_nvtxjet(0),
    m_metComp(0)
  {
    declareInterface< IMETUtilityAthTool >(this);

    declareProperty("DoEveryEvent",      m_doEveryEvent      =  false                        );

    declareProperty("IsData",            m_isData            =  false                        );
    declareProperty("Verbosity",         m_verbose           =  false                        );
    declareProperty("DoRefEle",          m_doTerm[METUtil::RefEle]    =  true                );
    declareProperty("DoRefGamma",        m_doTerm[METUtil::RefGamma]  =  true                );
    declareProperty("DoRefTau",          m_doTerm[METUtil::RefTau]    =  true                );
    declareProperty("DoRefJet",          m_doTerm[METUtil::RefJet]    =  true                );
    declareProperty("DoRefMuon",         m_doTerm[METUtil::RefMuon]   =  false               );
    declareProperty("DoMuonTotal",       m_doTerm[METUtil::MuonTotal] =  true                );
    declareProperty("DoSoftTerms",       m_doTerm[METUtil::SoftTerms]   =  true              );
    declareProperty("IsEflow",           m_isEflow    =  true                                );
    declareProperty("IsMuid",            m_isMuid            =  false                        );

    declareProperty("DoMuEloss",         m_doMuEloss         =  false                        );  
    declareProperty("DoJetJVF",          m_doJetJVF          =  false                        );  

    declareProperty("JetType",           m_jetType           =  "AntiKt4LCTopo"              );
    declareProperty("DoJetCalibration",  m_doJetCalib        =  false                        );
    declareProperty("JetCalibFile",      m_configfileJetCalib = "JES_Full2012dataset_Preliminary_Jan13.config"   );

    declareProperty("MCTypeJES",         m_mcTypeJES         =  "MC12a"                      );
    declareProperty("ConfigFileJES",     m_configfileJES     =  "JES_2012/Moriond2013/InsituJES2012_14NP.config" );
    declareProperty("ConfigMultijet",    m_configMultijet    =  "JES_2012/Moriond2013/MultijetJES_2012.config"   );
    declareProperty("ConfigDirJES",      m_configdirJES      =  ""                           );

    //  declareProperty("MethodJER",         m_methodJER         =  "Truth"                      );
    declareProperty("InputFileJER",      m_inputfileJER      =  "JERProviderPlots_2012.root" );

    declareProperty("MuSmearingData",    m_muData            =  "Data12"                     );
    declareProperty("MuSmearingAlgo",    m_muAlgo            =  "staco"                      );
    declareProperty("MuSmearingType",    m_muSmearType       =  "q_pT"                       );
    declareProperty("MuSmearingRelease", m_muRel             =  "Rel17.2Repro"               );
    declareProperty("MuSmearingDir",     m_muDir             =  ""                           );

    declareProperty("FilePathTES",       m_TESpath           =  "");
    declareProperty("IdTES",             m_TESid             =  ""                           );
    declareProperty("ProductionTES",     m_TESproduction     =  "mc12"                       );

    declareProperty("DoSignificance",    m_doSignificance    =  false                        );

    // Best if these don't get used.
    // Can't declareProperty the enum, so translate the int instead.
    declareProperty("MuonStatusWord",    m_muonStatusWord    =  0x0001                       );
    declareProperty("ClusterStatusWord", m_clusterStatusWord =  0x0001                       );

    declareProperty("JetPileupCode",     m_jet_pu_code       =  0x0001                       );
    declareProperty("SoftTermsPileupCode", m_st_pu_code      =  0x0001                       );

    declareProperty("UseSmearedEl",      m_useSmearedEl      =  false                        );
    declareProperty("UseSmearedPh",      m_useSmearedPh      =  false                        );
    declareProperty("UseSmearedMu",      m_useSmearedMu      =  false                        );

    declareProperty("Is2012",            m_flagis2012        =  true                         );
    declareProperty("IsSTVF",            m_flagisSTVF        =  false                        );

    //   declareProperty("UseMETComp",        m_useMetComp        =  true                         );
    declareProperty("METCompKey",        m_metCompKey        =  "MET_RefComposition"         );

    declareProperty("ClusterKey",        m_clusterKey        =  ""                           );
    /*"CaloCalTopoCluster"*/
    declareProperty("TrackKey",          m_trackKey          =  ""                           );
    /*"TrackParticleCandidate"*/
    declareProperty("ElectronKey",       m_electronKey       =  "METComposition"             );
    /*"ElectronAODCollection"*/
    declareProperty("JetKey",            m_jetKey            =  "METComposition"             );
    /*"AntiKt4LCTopoJets"*/
    declareProperty("MuonKey",           m_muonKey           =  "METComposition"             );
    /*"StacoMuonCollection"*/
    declareProperty("PhotonKey",         m_photonKey         =  "METComposition"             );
    /*"PhotonAODCollection"*/
    declareProperty("TaujetKey",         m_taujetKey         =  "METComposition"             );
    /*"TauRecContainer"*/
    declareProperty("VertexKey",         m_vertexKey         =  "VxPrimaryCandidate"         );
    /*"CaloCalTopoCluster"*/

    declareProperty("MuonMatchKey",      m_muonMatchKey      =  "StacoMuonCollection"        );
    /*"MuidMuonCollection"*/

    declareProperty("RefEleKey",         m_RefEleKey         =  ""                           );
    declareProperty("RefGammaKey",       m_RefGammaKey       =  ""                           );
    declareProperty("RefJetKey",         m_RefJetKey         =  ""                           );
    declareProperty("RefTauKey",         m_RefTauKey         =  ""                           );
    declareProperty("RefMuonKey",        m_RefMuonKey        =  "MET_RefMuon"                );
    declareProperty("SoftTermsKey",      m_SoftTermsKey      =  "MET_CellOut_Eflow"          );
    declareProperty("TruthKey",          m_TruthKey          =  "MET_Truth"                  );
    // for backwards compatibility
    declareProperty("SoftJetsKey",       m_SoftJetsKey       =  ""                           );

  }

  //////////////////////////////////////////////////////////////////////////////////////////////////
  // Destructor
  //
  METUtilityAthTool::~METUtilityAthTool()
  {

  }

  //////////////////////////////////////////////////////////////////////////////////////////////////

  StatusCode METUtilityAthTool::queryInterface( const InterfaceID& riid, void** ppvIf )
  {
    if ( riid == IMETUtilityAthTool::interfaceID() )  {
      *ppvIf = (IMETUtilityAthTool*)this;
      addRef();
      return StatusCode::SUCCESS;
    }

    return AthAlgTool::queryInterface( riid, ppvIf );
  }

  //////////////////////////////////////////////////////////////////////////////////////////////////

  StatusCode METUtilityAthTool::initialize() {
    msg(MSG::INFO) << "Initialising MissingETUtility" << endreq;

    // Set up the MET details
    configMissingET(m_flagis2012,m_flagisSTVF);
    setJetPUcode(m_jet_pu_code);
    setSoftTermsPUcode(m_st_pu_code);

    TString jetAlgo=TString(m_jetType);
    if(m_doJetCalib)
      m_jetCalibTool = new JetCalibrationTool(jetAlgo, m_configfileJetCalib, m_isData);

    m_multiJES = new MultijetJESUncertaintyProvider(m_configMultijet, m_configfileJES, m_jetType, m_mcTypeJES, m_configdirJES);

    m_JERTool = new JetSmearingTool(m_jetType, m_inputfileJER);
    m_JERTool->Is7TeV(!m_is2012);
    m_JERTool->init();

    m_egammaTool = new egRescaler::EnergyRescalerUpgrade;
    if(m_is2012) m_egammaTool->Init("../../../InstallArea/share/EnergyRescalerData.root","2012","es2012");
    else m_egammaTool->Init("../../../InstallArea/share/EnergyRescalerData.root","2011","es2011a");

    m_muonTool = new MuonSmear::SmearingClass(m_muData, m_muAlgo, m_muSmearType, m_muRel, m_muDir);
    m_muonTool->UseScale(true);

    m_TESTool = new TESUncertaintyProvider(m_TESpath,m_TESid,m_TESproduction);

    msg(MSG::INFO) << "Setting up MET systematics "
		   << endreq;
    msg(MSG::INFO) << "Using " << (m_isMuid ? "MUID" : "non-MUID") << " muons"
		   << endreq;

    IIncidentSvc* incsvc;
    StatusCode sc = service("IncidentSvc", incsvc);
    int priority = 100;
    if( sc.isSuccess() ) {
      incsvc->addListener( this, "BeginEvent", priority);
    }

    return StatusCode::SUCCESS;
  }

  //////////////////////////////////////////////////////////////////////////////////////////////////
  // not an algorithm, doesn't have an execute
  // but we may want to run process every event
  StatusCode METUtilityAthTool::process() {
    METUtility::reset();

    CHECK( evtStore()->retrieve(m_metComp, m_metCompKey) );

    // set the MET terms directly
    const MissingET* MET_RefEle = 0;
    if(m_RefEleKey != "") {
      CHECK( evtStore()->retrieve(MET_RefEle, m_RefEleKey) );
      setMETTerm(METUtil::RefEle, MET_RefEle);
    } else {
      msg(MSG::DEBUG) << "Skip RefEle" << endreq;
    }

    const MissingET* MET_RefGamma = 0;
    if(m_RefGammaKey != "") {
      CHECK( evtStore()->retrieve(MET_RefGamma, m_RefGammaKey) );
      setMETTerm(METUtil::RefGamma, MET_RefGamma);
    } else {
      msg(MSG::DEBUG) << "Skip RefGamma" << endreq;
    }

    const MissingET* MET_RefJet = 0;
    if(m_RefJetKey != "") {
      CHECK( evtStore()->retrieve(MET_RefJet, m_RefJetKey) );
      setMETTerm(METUtil::RefJet, MET_RefJet);
    } else {
      msg(MSG::DEBUG) << "Skip RefJet" << endreq;
    }

    const MissingET* MET_RefTau = 0;
    if(m_RefTauKey != "") {
      CHECK( evtStore()->retrieve(MET_RefTau, m_RefTauKey) );
      setMETTerm(METUtil::RefTau, MET_RefTau);
    } else {
      msg(MSG::DEBUG) << "Skip RefTau" << endreq;
    }

    const MissingET* MET_RefMuon = 0;
    if(m_RefMuonKey != "") {
      CHECK( evtStore()->retrieve(MET_RefMuon, m_RefMuonKey) );
      setMETTerm(METUtil::RefMuon, MET_RefMuon);
    } else {
      msg(MSG::DEBUG) << "Skip RefMuon" << endreq;
    }

    const MissingET* MET_SoftTerms = 0;
    if(m_SoftTermsKey != "") {
      CHECK( evtStore()->retrieve(MET_SoftTerms, m_SoftTermsKey) );
      setMETTerm(METUtil::SoftTerms, MET_SoftTerms);
    } else {
      msg(MSG::DEBUG) << "Skip SoftTerms" << endreq;
    }

    const MissingET* MET_SoftJets = 0;
    if(m_SoftJetsKey != "") {
      CHECK( evtStore()->retrieve(MET_SoftJets, m_SoftJetsKey) );
      MissingET* MET_SoftTerms = new MissingET;
      MET_SoftTerms->setEx(getMissingET(METUtil::SoftTerms).etx()+MET_SoftJets->etx());
      MET_SoftTerms->setEy(getMissingET(METUtil::SoftTerms).ety()+MET_SoftJets->ety());
      MET_SoftTerms->setEtSum(getMissingET(METUtil::SoftTerms).sumet()+MET_SoftJets->sumet());
      setMETTerm(METUtil::SoftTerms, MET_SoftTerms);
      delete MET_SoftTerms;
      msg(MSG::DEBUG) << "Include SoftJets in SoftTerms" << endreq;
    }

    if(!m_isData) {
      msg(MSG::DEBUG) << "Truth key set to " << m_TruthKey << endreq;
      const MissingEtTruth* MET_Truth = 0;
      if(m_TruthKey != "") {
	CHECK( evtStore()->retrieve(MET_Truth, m_TruthKey) );
	setMETTerm(METUtil::Truth, MET_Truth);
      } else {
	msg(MSG::DEBUG) << "Skip Truth" << endreq;
      }
    }

    // This is needed for jet pileup uncertainties
    // as well as for SoftTerms_ptHard uncertainties
    if(m_vertexKey != "") {
      CHECK( setNvtx(m_vertexKey) );
    } else {msg(MSG::DEBUG) << "Skip vertices" << endreq;}

    if(m_jetKey != "") {
      CHECK( setupJets(m_jetKey) );
    } else {msg(MSG::DEBUG) << "Skip jets" << endreq;}

    if(m_electronKey != "") {
      CHECK( setupElectrons(m_electronKey) );
    } else {msg(MSG::DEBUG) << "Skip electrons" << endreq;}

    if(m_photonKey != "") {
      CHECK( setupPhotons(m_photonKey) );
    } else {msg(MSG::DEBUG) << "Skip photons" << endreq;}

    if(m_taujetKey != "") {
      CHECK( setupTaus(m_taujetKey) );
    } else {msg(MSG::DEBUG) << "Skip taus" << endreq;}

    if(m_muonKey != "") {
      CHECK( setupMuons(m_muonKey, m_muonMatchKey, m_muonStatusWord) );
    } else {msg(MSG::DEBUG) << "Skip muons" << endreq;}

    if(m_clusterKey != "") {
      CHECK( setupClusters(m_clusterKey, m_clusterStatusWord) );
    } else {msg(MSG::DEBUG) << "Skip clusters" << endreq;}

    if(m_trackKey != "") {
      CHECK( setupTracks(m_trackKey) );
    } else {msg(MSG::DEBUG) << "Skip tracks" << endreq;}

    msg(MSG::DEBUG) << "End of process" << endreq;
    msg(MSG::DEBUG) << "  MET_RefFinal         = " << getMissingET(METUtil::RefFinal).et() << endreq;
    //  msg(MSG::DEBUG) << "  MET_RefFinal_JESUP   = " << getMissingET(METUtil::RefFinal,METUtil::JESUp).et() << endreq;
    //  msg(MSG::DEBUG) << "  MET_RefFinal_JESDOWN = " << getMissingET(METUtil::RefFinal,METUtil::JESDown).et() << endreq;

    return StatusCode::SUCCESS;
  }

  //////////////////////////////////////////////////////////////////////////////////////////////////

  StatusCode METUtilityAthTool::finalize(){
    msg(MSG::INFO) << "Finalising MissingETUtility." << endreq;
    METUtility::reset();

    delete m_jetCalibTool;
    delete m_multiJES;
    delete m_JERTool;
    delete m_egammaTool;
    delete m_muonTool;
    delete m_TESTool;

    msg(MSG::DEBUG) << "Nice to have MET you." << endreq;

    return StatusCode::SUCCESS;
  }



  //////////////////////////////////////////////////////////////////////////////////////////////////
  //  methods for setting up the physics objects from AOD containers
  //

  StatusCode METUtilityAthTool::setupJets(const string &collectionName) { 
    msg(MSG::DEBUG) << "Setting up jets" << endreq;

    // We grab the event info for the purposes of seeding random number generators
    const EventInfo* myEventInfo = 0;
    CHECK( evtStore()->retrieve(myEventInfo/*,"MyEvent"*/) );

    bool useMetComp = collectionName == "METComposition";

    const JetCollection *aod_jets = 0;
    vector<vector<float> > jet_wet, jet_wpx, jet_wpy;
    vector<vector<unsigned int> > jet_statusWord;
    int ijet = 0;
    if(useMetComp) {
      msg(MSG::DEBUG) << "Setting up jet collection from MET composition" << endreq;
      if(!m_metComp) {
	msg(MSG::WARNING) << "Invalid pointer to MET composition object!" << endreq;
	return StatusCode::FAILURE;
      }
      // Fill the jet collection from the MET composition
      JetCollection *temp_jets = new JetCollection;
      MissingETComposition::const_iterator<Jet> fJet(m_metComp->beginIterator<Jet>());
      MissingETComposition::const_iterator<Jet> lJet(m_metComp->endIterator<Jet>());
      for(;fJet!=lJet;++fJet) {
	msg(MSG::VERBOSE) << "Adding jet " << ijet << " to collection" << endreq;
	if(!(*fJet)) msg(MSG::FATAL) << "Oops, didn't get the point(er)" << endreq;
	temp_jets->push_back(new Jet(**fJet));

	vector<float> thewet, thewpx, thewpy;
	if((*fJet)->pt()>20e3) {
	  thewet.push_back(fJet.getParameter().wet());
	  thewpx.push_back(fJet.getParameter().wpx());
	  thewpy.push_back(fJet.getParameter().wpy());
	} else {
	  thewet.push_back(0.);
	  thewpx.push_back(0.);
	  thewpy.push_back(0.);
	}

	jet_wet.push_back(thewet);
	jet_wpx.push_back(thewpx);
	jet_wpy.push_back(thewpy);

	vector<unsigned int> statusvec;
	statusvec.push_back(fJet.getParameter().statusWord());
	jet_statusWord.push_back(statusvec);

	++ijet;
      }

      aod_jets = temp_jets;
    } else {
      // Grab the jet collection from StoreGate
      // Less advisable, since the weights will not be properly accounted for.
      msg(MSG::DEBUG) << "Retrieving jet collection " << collectionName << " from StoreGate." << endreq;
      CHECK( evtStore()->retrieve( aod_jets, collectionName ) );
    }
  
    msg(MSG::DEBUG) << "Jet collection contains " << aod_jets->size() << " jets." << endreq;

    // Get the relevant information for the METUtility
    JetCollection::const_iterator iJet = aod_jets->begin();
    JetCollection::const_iterator eJet = aod_jets->end();
    vector<float> jet_pT, jet_eta, jet_phi, jet_E;
    vector<float> jet_resUp, jet_resDown;
    vector<vector<float> > jet_jesUp, jet_jesDown; // For multiple nuisance parameters

    unsigned int EventNumber = myEventInfo->event_ID()->event_number();
    msg(MSG::DEBUG) << "Now on event " << EventNumber << endreq;

    // Quantities needed for ApplyJetCalibration
    double mu = myEventInfo->averageInteractionsPerCrossing();
    double rho = 0.;

    if(m_doJetCalib) {
      CHECK( userStore()->retrieve( "ClusterRhoKt4EM", rho) );
    }

    ijet = 0;
    m_JERTool->SetSeed(EventNumber);
    for(;iJet!=eJet;++iJet) {
      msg(MSG::VERBOSE) << ijet << endl;
      if(!(*iJet)) msg(MSG::FATAL) << "Oops, didn't get the point(er)" << endreq;

      TLorentzVector jetlv;
      if(m_doJetCalib) {
	// iterate over jets in the event
	double Ax = (*iJet)->getMoment("ActiveAreaPx");
	double Ay = (*iJet)->getMoment("ActiveAreaPy");
	double Az = (*iJet)->getMoment("ActiveAreaPz");
	double Ae = (*iJet)->getMoment("ActiveAreaE");

	jetlv = m_jetCalibTool->ApplyJetAreaOffsetEtaJES((*iJet)->e(P4SignalState::JETCONSTITUENTSCALE),
							 (*iJet)->eta(P4SignalState::JETCONSTITUENTSCALE),
							 (*iJet)->phi(P4SignalState::JETCONSTITUENTSCALE),
							 (*iJet)->m(P4SignalState::JETCONSTITUENTSCALE),
							 Ax,Ay,Az,Ae,rho,mu,m_nvtxjet);

      } else {
	jetlv.SetPtEtaPhiE((*iJet)->pt(),(*iJet)->eta(),(*iJet)->phi(),(*iJet)->e());
      }

      jet_pT.push_back(jetlv.Pt());
      jet_eta.push_back((*iJet)->eta());
      jet_phi.push_back((*iJet)->phi());
      jet_E.push_back(jetlv.E());
    
      // Didn't use MET Composition, so we have to make up some weights instead
      // Put in the default statusWord, which is not used for jets anyway
      if(!useMetComp) {
	vector<float> univec;
	univec.push_back(1.);
	jet_wet.push_back(univec);
	jet_wpx.push_back(univec);
	jet_wpy.push_back(univec);

	vector<unsigned int> statusvec;
	statusvec.push_back(MissingETTags::DEFAULT);
	jet_statusWord.push_back(statusvec);
      }

      // Now compute the uncertainties using the JES and JER providers
      float jesShift = 0.0;
      float jerShift = 1.0;
      bool goodjet = (jetlv.Pt() > 20e3 && fabs((*iJet)->eta()) < 4.5);
      double mindR = 99.;

      // Use ApplyJetResolutionSmearing package, recommended for Moriond 2013
      if(jetlv.Pt() > 20e3 && jetlv.Pt() < 5000e3) {
	msg(MSG::VERBOSE) << " Getting JER uncertainty...";
	TLorentzVector jetlv_smear(jetlv);
	m_JERTool->SmearJet_Syst(jetlv_smear);
	jerShift = jetlv_smear.Pt()/jetlv.Pt();
      }

      jet_resUp.push_back(jerShift=1.);
      jet_resDown.push_back(1.-jerShift);

      msg(MSG::VERBOSE) << " Getting JES uncertainty... ";
    
      // JetUncertainties for Moriond 2013 (14 NP)
      double eta = (*iJet)->eta(); // uncalibrated
      double pt = jetlv.Pt(); // recalibrated

      // Loop over baseline uncertainty components
      int Ncomp=m_multiJES->getNUncertaintyComponents();
      int icomp=0; // can use this for other components not in the loop
      vector<float> newvectup, newvectdown;
      for (;icomp<Ncomp;++icomp) {
	if(icomp>=int(jet_jesUp.size())) {
	  jet_jesUp.push_back(newvectup);
	  jet_jesDown.push_back(newvectdown);
	}

	jesShift = m_multiJES->getRelUncertComponent(icomp, pt, eta);
	// nuisance paramter amplitude (with sign) ("relative uncertainty" of component) 
	// can also use  j.getRelUncertComponent(compName, pt, eta);

	jet_jesUp[icomp].push_back(goodjet ? jesShift : 0.);
	jet_jesDown[icomp].push_back(goodjet ? -1.*jesShift : 0.);
      }
      msg(MSG::VERBOSE) << " baseline loop... ";

      // Pileup uncertainties
      // 1.
      jesShift = m_multiJES->getRelNPVOffsetTerm(pt,eta,m_nvtxjet);
      if(icomp>=int(jet_jesUp.size())) {
	jet_jesUp.push_back(newvectup);
	jet_jesDown.push_back(newvectdown);
      }
      jet_jesUp[icomp].push_back(goodjet ? jesShift : 0.);
      jet_jesDown[icomp].push_back(goodjet ? -1.*jesShift : 0.);
      ++icomp;
      // 2.
      jesShift = m_multiJES->getRelMuOffsetTerm(pt,eta,mu);
      if(icomp>=int(jet_jesUp.size())) {
	jet_jesUp.push_back(newvectup);
	jet_jesDown.push_back(newvectdown);
      }
      jet_jesUp[icomp].push_back(goodjet ? jesShift : 0.);
      jet_jesDown[icomp].push_back(goodjet ? -1.*jesShift : 0.);
      ++icomp;
      // Moriond 2013 only
      if(m_is2012) {
	// 3.
	jesShift = m_multiJES->getRelPileupPtTerm(pt,eta,m_nvtxjet,mu);
	if(icomp>=int(jet_jesUp.size())) {
	  jet_jesUp.push_back(newvectup);
	  jet_jesDown.push_back(newvectdown);
	}
	jet_jesUp[icomp].push_back(goodjet ? jesShift : 0.);
	jet_jesDown[icomp].push_back(goodjet ? -1.*jesShift : 0.);
	++icomp;
	// 4.
	m_multiJES->getRelPileupRhoTopology(pt,eta); 
	if(icomp>=int(jet_jesUp.size())) {
	  jet_jesUp.push_back(newvectup);
	  jet_jesDown.push_back(newvectdown);
	}
	jet_jesUp[icomp].push_back(goodjet ? jesShift : 0.);
	jet_jesDown[icomp].push_back(goodjet ? -1.*jesShift : 0.);
	++icomp;
      }

      msg(MSG::VERBOSE) << " pileup components... ";

      // Multijet/Flavour components

      double jesMultiJet = 0.;
      JetCollection::const_iterator iJet2 = aod_jets->begin();

      for(;iJet2!=eJet;++iJet2) {
	if(!m_is2012) { // 2011 uses minimum dR
	  // Compute deltaR to closest jet with EM pT of at least 7 GeV
	  if(iJet2==iJet) continue;
	  double empt = (*iJet2)->pt(P4SignalState::JETEMSCALE);
	  if(empt<7e3) continue;
	  mindR = TMath::Min(mindR,P4Helpers::deltaR(*iJet,*iJet2));
	  jesMultiJet = m_multiJES->getRelClosebyUncert(pt, mindR);
	} else { // 2012 uses fCloseby projection
	  double fCloseby=0;
	  // Loop over other jets to find those within dR < 1.1
	  // Only take other jets with pT of at least 12 GeV
	  if(iJet2==iJet) continue;
	  if((*iJet2)->pt()<12e3) continue;
	  if(P4Helpers::deltaR(*iJet,*iJet2)>1.1) continue;
	  // "fractional projection" of momentum along jet axis: p_jet*p_closeby / |p_jet|^2
	  fCloseby += (*iJet)->hlv().vect().dot((*iJet2)->hlv().vect()) / (*iJet)->p2() ; // close-by fraction
	  jesMultiJet = m_multiJES->getRelClosebyUncert(pt, fCloseby);
	}
      }

      if(icomp>=int(jet_jesUp.size())) {
	jet_jesUp.push_back(newvectup);
	jet_jesDown.push_back(newvectdown);
      }
      jet_jesUp[icomp].push_back(goodjet ? jesMultiJet : 0.);
      jet_jesDown[icomp].push_back(goodjet ? -1.*jesMultiJet : 0.);
      ++icomp;

      msg(MSG::VERBOSE) << " multijet components... ";

      // --- get the true label of the jet from MC Truth:
      std::string label("N/A");
      const Analysis::TruthInfo* mcinfo = (*iJet)->tagInfo<Analysis::TruthInfo>("TruthInfo");
      if(mcinfo) {
	label = mcinfo->jetTruthLabel();
      } else {
	msg(MSG::VERBOSE) << "could not find TruthInfo for matching jet" << endreq;
      }
      bool isBjet(label=="B");

      // Some uncertainties are applied only (not applied) to b-jets
      if(isBjet) {
	// Flavour composition
	if(icomp>=int(jet_jesUp.size())) {
	  jet_jesUp.push_back(newvectup);
	  jet_jesDown.push_back(newvectdown);
	}
	jet_jesUp[icomp].push_back(0.);
	jet_jesDown[icomp].push_back(0.);
	++icomp;
	// Flavour response
	if(icomp>=int(jet_jesUp.size())) {
	  jet_jesUp.push_back(newvectup);
	  jet_jesDown.push_back(newvectdown);
	}
	jet_jesUp[icomp].push_back(0.);
	jet_jesDown[icomp].push_back(0.);
	++icomp;
	// B-JES
	double jesBjet = m_multiJES->getRelBJESUncert(pt, eta);
	if(icomp>=int(jet_jesUp.size())) {
	  jet_jesUp.push_back(newvectup);
	  jet_jesDown.push_back(newvectdown);
	}
	jet_jesUp[icomp].push_back(goodjet ? jesBjet : 0.);
	jet_jesDown[icomp].push_back(goodjet ? -1*jesBjet : 0.);
	++icomp;
      } else {

	// Flavour composition
	double jesFlavourUp = m_multiJES->getRelFlavorCompUncert(pt, eta, true);
	double jesFlavourDown = m_multiJES->getRelFlavorCompUncert(pt, eta, false);
	if(icomp>=int(jet_jesUp.size())) {
	  jet_jesUp.push_back(newvectup);
	  jet_jesDown.push_back(newvectdown);
	}
	jet_jesUp[icomp].push_back(goodjet ? jesFlavourUp : 0.);
	jet_jesDown[icomp].push_back(goodjet ? jesFlavourDown : 0.);
	++icomp;
	// Flavour response
	double jesFlavourResponse = m_multiJES->getRelFlavorResponseUncert(pt, eta);
	if(icomp>=int(jet_jesUp.size())) {
	  jet_jesUp.push_back(newvectup);
	  jet_jesDown.push_back(newvectdown);
	}
	jet_jesUp[icomp].push_back(goodjet ? jesFlavourResponse : 0.);
	jet_jesDown[icomp].push_back(goodjet ? -1*jesFlavourResponse : 0.);
	++icomp;
	// B-JES
	if(icomp>=int(jet_jesUp.size())) {
	  jet_jesUp.push_back(newvectup);
	  jet_jesDown.push_back(newvectdown);
	}
	jet_jesUp[icomp].push_back(0.);
	jet_jesDown[icomp].push_back(0.);
	++icomp;
      }
      msg(MSG::VERBOSE) << " flavour components... DONE" << endreq;

      msg(MSG::VERBOSE) << "Total JES components:" << jet_jesUp.size() << endreq;
    }
    ++ijet;

    msg(MSG::DEBUG) << "Setting jet parameters" << endreq;
    msg(MSG::VERBOSE) << "Lengths of vectors: " << endl
		      << " pt: " << jet_pT.size() << ", "
		      << " eta: " << jet_eta.size() << ", "
		      << " phi: " << jet_phi.size() << ", "
		      << " E: " << jet_E.size() << ", "    
		      << " wet: " << jet_wet.size() 
		      << endreq;
    setJetParameters(&jet_pT, &jet_eta, &jet_phi, &jet_E,
		     &jet_wet, &jet_wpx, &jet_wpy, &jet_statusWord);

    msg(MSG::DEBUG) << "Setting jet uncertainties" << endreq;
    for(int icomp=0; icomp<int(jet_jesUp.size()); ++icomp) {
      msg(MSG::VERBOSE) << "Component " << icomp << ":" << jet_jesUp[icomp].size() << endreq;
      setObjectEnergyUncertainties(METUtil::Jets, jet_jesUp[icomp], jet_jesDown[icomp], icomp);
    }
    setObjectResolutionShift(METUtil::Jets, jet_resUp, jet_resDown);

    msg(MSG::DEBUG) << "Done setting up jets." << endreq;
    if(useMetComp) delete aod_jets;

    return StatusCode::SUCCESS;
  }

  //////////////////////////////////////////////////////////////////////////////////////////////////

  StatusCode METUtilityAthTool::setupElectrons(const string &collectionName) { 

    msg(MSG::DEBUG) << "Setting up electrons" << endreq;

    bool useMetComp = collectionName == "METComposition";

    int iel = 0;
    const ElectronContainer *aod_electrons = 0;
    vector<vector<float> > el_wet, el_wpx, el_wpy;
    vector<vector<unsigned int> > el_statusWord;
    if(useMetComp) {
      msg(MSG::DEBUG) << "Setting up electron collection from MET composition" << endreq;
      if(!m_metComp) {
	msg(MSG::WARNING) << "Invalid pointer to MET composition object!" << endreq;
	return StatusCode::FAILURE;
      }
      // Fill the electron collection from the MET composition
      ElectronContainer *temp_electrons = new ElectronContainer;
      msg(MSG::DEBUG) << "Getting electron iterators" << endreq;
      MissingETComposition::const_iterator<Analysis::Electron> fEl(m_metComp->beginIterator<Analysis::Electron>());
      MissingETComposition::const_iterator<Analysis::Electron> lEl(m_metComp->endIterator<Analysis::Electron>());
      for(;fEl!=lEl;++fEl) {
	msg(MSG::VERBOSE) << "Adding electron " << iel << " to collection" << endreq;
	if(!(*fEl)) msg(MSG::FATAL) << "Oops, didn't get the point(er)" << endreq;
	if(!(*fEl)->author(egammaParameters::AuthorElectron)) continue;
	temp_electrons->push_back(new Analysis::Electron(**fEl));

	vector<float> thewet, thewpx, thewpy;
	thewet.push_back(fEl.getParameter().wet());
	thewpx.push_back(fEl.getParameter().wpx());
	thewpy.push_back(fEl.getParameter().wpy());

	el_wet.push_back(thewet);
	el_wpx.push_back(thewpx);
	el_wpy.push_back(thewpy);

	vector<unsigned int> statusvec;
	statusvec.push_back(fEl.getParameter().statusWord());
	el_statusWord.push_back(statusvec);
	++iel;
      }

      aod_electrons = temp_electrons;
    } else {
      // Grab the electron collection from StoreGate
      msg(MSG::DEBUG) << "Retrieving electron collection " << collectionName << " from StoreGate." << endreq;
      CHECK( evtStore()->retrieve( aod_electrons, collectionName ) );
    }
  
    msg(MSG::DEBUG) << "Electron collection contains " << aod_electrons->size() << " electrons." << endreq;

    iel = 0;
    ElectronContainer::const_iterator iEl = aod_electrons->begin();
    ElectronContainer::const_iterator eEl = aod_electrons->end();
    vector<float> el_pT, el_eta, el_phi, el_E;
    vector<float> el_smeared_pT, el_resUp, el_resDown;
    vector<float> el_eesUp_ZStat, el_eesDown_ZStat, el_eesUp_ZMeth, el_eesDown_ZMeth;
    vector<float> el_eesUp_ZGen, el_eesDown_ZGen, el_eesUp_Mat, el_eesDown_Mat;
    vector<float> el_eesUp_PS, el_eesDown_PS, el_eesUp_LowPt, el_eesDown_LowPt;
    for(;iEl!=eEl;++iEl) {
      msg(MSG::VERBOSE) << iel << endl;
      if(!(*iEl)) msg(MSG::FATAL) << "Oops, didn't get the point(er)" << endreq;
      el_pT.push_back((*iEl)->pt());
      el_eta.push_back((*iEl)->eta());
      el_phi.push_back((*iEl)->phi());
      el_E.push_back((*iEl)->e());

      if(!useMetComp) {
	vector<float> univec;
	univec.push_back(1.);
	el_wet.push_back(univec);
	el_wpx.push_back(univec);
	el_wpy.push_back(univec);

	vector<unsigned int> statusvec;
	statusvec.push_back(MissingETTags::DEFAULT);
	el_statusWord.push_back(statusvec);
      }
      msg(MSG::VERBOSE) << " Applying electron smearing... ";
      // Apply smearing/scaling
      m_egammaTool->SetRandomSeed(int(1.e+5*fabs((*iEl)->phi()))); //set the seed however you like, I'm following the SUSYTools example

      float smear(1.), smearUp(1.), smearDown(1.);
      if(m_useSmearedEl) {
	smear = m_egammaTool->getSmearingCorrection(     (*iEl)->cluster()->eta(), (*iEl)->e(),
							 egRescaler::EnergyRescalerUpgrade::Nominal );
	smearUp = m_egammaTool->getSmearingCorrection(   (*iEl)->cluster()->eta(), (*iEl)->e(),
							 egRescaler::EnergyRescalerUpgrade::ERR_UP );
	smearDown = m_egammaTool->getSmearingCorrection( (*iEl)->cluster()->eta(), (*iEl)->e(),
							 egRescaler::EnergyRescalerUpgrade::ERR_DOWN );
      }
      // The resolution uncertainties are relative to the smeared resolution
      // So it doesn't make a lot of sense to take uncertainties on the unsmeared values
      el_smeared_pT.push_back(smear*(*iEl)->pt());
      el_resUp.push_back((smearUp - smear)/smear);
      el_resDown.push_back((smearDown - smear)/smear);

      msg(MSG::VERBOSE) << " Getting energy scale uncertainty" << endreq;

      float correction = 1.;
      if(m_isData)
	correction = m_egammaTool->applyEnergyCorrection(	(*iEl)->cluster()->eta(),(*iEl)->e(),
								egRescaler::EnergyRescalerUpgrade::Electron, egRescaler::EnergyRescalerUpgrade::Nominal) / (*iEl)->e();
      el_smeared_pT.at(iel) *= correction;
      // There are multiple systematic variations that should be applied independently.
      // See https://twiki.cern.ch/twiki/bin/viewauth/AtlasProtected/EnergyScaleResolutionRecommendations#Scale_corrections
      //
      // Case 0
      double energyUp = m_egammaTool->applyEnergyCorrection((*iEl)->cluster()->eta(),(*iEl)->e(),
							    egRescaler::EnergyRescalerUpgrade::Electron, egRescaler::EnergyRescalerUpgrade::ZeeStatUp) / (correction*(*iEl)->e()) - 1;
      double energyDown = m_egammaTool->applyEnergyCorrection((*iEl)->cluster()->eta(),(*iEl)->e(),
							      egRescaler::EnergyRescalerUpgrade::Electron, egRescaler::EnergyRescalerUpgrade::ZeeStatDown) / (correction*(*iEl)->e()) - 1;
      el_eesUp_ZStat.push_back(energyUp);
      el_eesDown_ZStat.push_back(energyDown);
      //
      // Case 1
      energyUp = m_egammaTool->applyEnergyCorrection((*iEl)->cluster()->eta(),(*iEl)->e(),
						     egRescaler::EnergyRescalerUpgrade::Electron, egRescaler::EnergyRescalerUpgrade::ZeeMethodUp) / (correction*(*iEl)->e()) - 1;
      energyDown = m_egammaTool->applyEnergyCorrection((*iEl)->cluster()->eta(),(*iEl)->e(),
						       egRescaler::EnergyRescalerUpgrade::Electron, egRescaler::EnergyRescalerUpgrade::ZeeMethodDown) / (correction*(*iEl)->e()) - 1;
      el_eesUp_ZMeth.push_back(energyUp);
      el_eesDown_ZMeth.push_back(energyDown);
      //
      // Case 2
      energyUp = m_egammaTool->applyEnergyCorrection((*iEl)->cluster()->eta(),(*iEl)->e(),
						     egRescaler::EnergyRescalerUpgrade::Electron, egRescaler::EnergyRescalerUpgrade::ZeeGenUp) / (correction*(*iEl)->e()) - 1;
      energyDown = m_egammaTool->applyEnergyCorrection((*iEl)->cluster()->eta(),(*iEl)->e(),
						       egRescaler::EnergyRescalerUpgrade::Electron, egRescaler::EnergyRescalerUpgrade::ZeeGenDown) / (correction*(*iEl)->e()) - 1;
      el_eesUp_ZGen.push_back(energyUp);
      el_eesDown_ZGen.push_back(energyDown);
      //
      // Case 3
      energyUp = m_egammaTool->applyEnergyCorrection((*iEl)->cluster()->eta(),(*iEl)->e(),
						     egRescaler::EnergyRescalerUpgrade::Electron, egRescaler::EnergyRescalerUpgrade::R12StatUp) / (correction*(*iEl)->e()) - 1;
      energyDown = m_egammaTool->applyEnergyCorrection((*iEl)->cluster()->eta(),(*iEl)->e(),
						       egRescaler::EnergyRescalerUpgrade::Electron, egRescaler::EnergyRescalerUpgrade::R12StatDown) / (correction*(*iEl)->e()) - 1;
      el_eesUp_Mat.push_back(energyUp);
      el_eesDown_Mat.push_back(energyDown);
      //
      // Case 4
      energyUp = m_egammaTool->applyEnergyCorrection((*iEl)->cluster()->eta(),(*iEl)->e(),
						     egRescaler::EnergyRescalerUpgrade::Electron, egRescaler::EnergyRescalerUpgrade::PSStatUp) / (correction*(*iEl)->e()) - 1;
      energyDown = m_egammaTool->applyEnergyCorrection((*iEl)->cluster()->eta(),(*iEl)->e(),
						       egRescaler::EnergyRescalerUpgrade::Electron, egRescaler::EnergyRescalerUpgrade::PSStatDown) / (correction*(*iEl)->e()) - 1;
      el_eesUp_PS.push_back(energyUp);
      el_eesDown_PS.push_back(energyDown);
      //
      // Case 5
      energyUp = m_egammaTool->applyEnergyCorrection((*iEl)->cluster()->eta(),(*iEl)->e(),
						     egRescaler::EnergyRescalerUpgrade::Electron, egRescaler::EnergyRescalerUpgrade::LowPtUp) / (correction*(*iEl)->e()) - 1;
      energyDown = m_egammaTool->applyEnergyCorrection((*iEl)->cluster()->eta(),(*iEl)->e(),
						       egRescaler::EnergyRescalerUpgrade::Electron, egRescaler::EnergyRescalerUpgrade::LowPtDown) / (correction*(*iEl)->e()) - 1;
      el_eesUp_LowPt.push_back(energyUp);
      el_eesDown_LowPt.push_back(energyDown);

      ++iel;
    }
  
    msg(MSG::DEBUG) << "Setting electron momenta...";
    setElectronParameters(&el_smeared_pT, &el_eta, &el_phi,
			  &el_wet, &el_wpx, &el_wpy, &el_statusWord);

    msg(MSG::DEBUG) << "Setting energy scale uncertainty" << endreq;
    setObjectEnergyUncertainties(METUtil::Electrons, el_eesUp_ZStat, el_eesDown_ZStat,0);
    setObjectEnergyUncertainties(METUtil::Electrons, el_eesUp_ZMeth, el_eesDown_ZMeth,1);
    setObjectEnergyUncertainties(METUtil::Electrons, el_eesUp_ZGen,  el_eesDown_ZGen, 2);
    setObjectEnergyUncertainties(METUtil::Electrons, el_eesUp_Mat,   el_eesDown_Mat,  3);
    setObjectEnergyUncertainties(METUtil::Electrons, el_eesUp_PS,    el_eesDown_PS,   4);
    setObjectEnergyUncertainties(METUtil::Electrons, el_eesUp_LowPt, el_eesDown_LowPt,5);

    msg(MSG::DEBUG) << "Setting resolution uncertainty" << endreq;
    setObjectResolutionShift(METUtil::Electrons, el_resUp, el_resDown);

    if(useMetComp) delete aod_electrons;

    return StatusCode::SUCCESS;
  }

  //////////////////////////////////////////////////////////////////////////////////////////////////

  StatusCode METUtilityAthTool::setupPhotons(const string &collectionName) {

    msg(MSG::DEBUG) << "Setting up photons" << endreq;

    bool useMetComp = collectionName == "METComposition";

    const PhotonContainer *aod_photons = 0;
    vector<vector<float> > ph_wet, ph_wpx, ph_wpy;
    vector<vector<unsigned int> > ph_statusWord;
    if(useMetComp) {
      msg(MSG::DEBUG) << "Setting up photon collection from MET composition" << endreq;
      if(!m_metComp) {
	msg(MSG::WARNING) << "Invalid pointer to MET composition object!" << endreq;
	return StatusCode::FAILURE;
      }
      // Fill the photon collection from the MET composition
      PhotonContainer *temp_photons = new PhotonContainer;
      MissingETComposition::const_iterator<Analysis::Photon> fPh(m_metComp->beginIterator<Analysis::Photon>());
      MissingETComposition::const_iterator<Analysis::Photon> lPh(m_metComp->endIterator<Analysis::Photon>());
      for(;fPh!=lPh;++fPh) {
	if(!(*fPh)) msg(MSG::FATAL) << "Oops, didn't get the point(er)" << endreq;
	temp_photons->push_back(new Analysis::Photon(**fPh));

	vector<float> thewet, thewpx, thewpy;
	thewet.push_back(fPh.getParameter().wet());
	thewpx.push_back(fPh.getParameter().wpx());
	thewpy.push_back(fPh.getParameter().wpy());

	ph_wet.push_back(thewet);
	ph_wpx.push_back(thewpx);
	ph_wpy.push_back(thewpy);

	vector<unsigned int> statusvec;
	statusvec.push_back(fPh.getParameter().statusWord());
	ph_statusWord.push_back(statusvec);
      }

      aod_photons = temp_photons;
    } else {
      // Grab the photon collection from StoreGate
      CHECK( evtStore()->retrieve( aod_photons, collectionName ) );
    }

    msg(MSG::DEBUG) << "Photon collection contains " << aod_photons->size() << " photons." << endreq;

    int iph = 0;
    PhotonContainer::const_iterator iPh = aod_photons->begin();
    PhotonContainer::const_iterator ePh = aod_photons->end();
    vector<float> ph_pT, ph_eta, ph_phi, ph_E;
    vector<float> ph_smeared_pT, ph_resUp, ph_resDown;
    vector<float> ph_pesUp_ZStat, ph_pesDown_ZStat, ph_pesUp_ZMeth, ph_pesDown_ZMeth;
    vector<float> ph_pesUp_ZGen, ph_pesDown_ZGen, ph_pesUp_Mat, ph_pesDown_Mat;
    vector<float> ph_pesUp_PS, ph_pesDown_PS, ph_pesUp_LowPt, ph_pesDown_LowPt;
    for(;iPh!=ePh;++iPh) {
      if(!(*iPh)) msg(MSG::FATAL) << "Oops, didn't get the point(er)" << endreq;
      ph_pT.push_back((*iPh)->pt());
      ph_eta.push_back((*iPh)->eta());
      ph_phi.push_back((*iPh)->phi());
      ph_E.push_back((*iPh)->e());

      if(!useMetComp) {
	vector<float> univec;
	univec.push_back(1.);
	ph_wet.push_back(univec);
	ph_wpx.push_back(univec);
	ph_wpy.push_back(univec);

	vector<unsigned int> statusvec;
	statusvec.push_back(MissingETTags::DEFAULT);
	ph_statusWord.push_back(statusvec);
      }
      msg(MSG::VERBOSE) << " Applying electron smearing... ";
      // Apply smearing/scaling
      m_egammaTool->SetRandomSeed(int(1.e+5*fabs((*iPh)->phi()))); //set the seed however you like, I'm following the SUSYTools example

      float smear(1.), smearUp(1.), smearDown(1.);
      smear = m_egammaTool->getSmearingCorrection(     (*iPh)->cluster()->eta(), (*iPh)->e(),
						       egRescaler::EnergyRescalerUpgrade::Nominal);
      smearUp = m_egammaTool->getSmearingCorrection(   (*iPh)->cluster()->eta(), (*iPh)->e(),
						       egRescaler::EnergyRescalerUpgrade::ERR_UP);
      smearDown = m_egammaTool->getSmearingCorrection( (*iPh)->cluster()->eta(), (*iPh)->e(),
						       egRescaler::EnergyRescalerUpgrade::ERR_DOWN);

      // The resolution uncertainties are relative to the smeared resolution
      // So it doesn't make a lot of sense to take uncertainties on the unsmeared values
      ph_smeared_pT.push_back(smear*(*iPh)->pt());
      ph_resUp.push_back((smearUp - smear)/smear);
      ph_resDown.push_back((smearDown - smear)/smear);

      msg(MSG::VERBOSE) << " Getting energy scale uncertainty" << endreq;

      egRescaler::EnergyRescalerUpgrade::ParticleType photontype = (*iPh)->nConversions()>0 ? egRescaler::EnergyRescalerUpgrade::Converted :
	egRescaler::EnergyRescalerUpgrade::Unconverted;
      float correction = 1.;
      if(m_isData)
	correction = m_egammaTool->applyEnergyCorrection((*iPh)->cluster()->eta(),(*iPh)->e(),
							 photontype, egRescaler::EnergyRescalerUpgrade::Nominal) / (*iPh)->e();
      ph_smeared_pT.at(iph)*= correction;
      // There are multiple systematic variations that should be applied independently.
      // See https://twiki.cern.ch/twiki/bin/viewauth/AtlasProtected/EnergyScaleResolutionRecommendations#Scale_corrections
      //
      // Case 0
      double energyUp = m_egammaTool->applyEnergyCorrection((*iPh)->cluster()->eta(),(*iPh)->e(),
							    photontype, egRescaler::EnergyRescalerUpgrade::ZeeStatUp) / (correction*(*iPh)->e()) - 1;
      double energyDown = m_egammaTool->applyEnergyCorrection((*iPh)->cluster()->eta(),(*iPh)->e(),
							      photontype, egRescaler::EnergyRescalerUpgrade::ZeeStatDown) / (correction*(*iPh)->e()) - 1;
      ph_pesUp_ZStat.push_back(energyUp);
      ph_pesDown_ZStat.push_back(energyDown);
      //
      // Case 1
      energyUp = m_egammaTool->applyEnergyCorrection((*iPh)->cluster()->eta(),(*iPh)->e(),
						     photontype, egRescaler::EnergyRescalerUpgrade::ZeeMethodUp) / (correction*(*iPh)->e()) - 1;
      energyDown = m_egammaTool->applyEnergyCorrection((*iPh)->cluster()->eta(),(*iPh)->e(),
						       photontype, egRescaler::EnergyRescalerUpgrade::ZeeMethodDown) / (correction*(*iPh)->e()) - 1;
      ph_pesUp_ZMeth.push_back(energyUp);
      ph_pesDown_ZMeth.push_back(energyDown);
      //
      // Case 2
      energyUp = m_egammaTool->applyEnergyCorrection((*iPh)->cluster()->eta(),(*iPh)->e(),
						     photontype, egRescaler::EnergyRescalerUpgrade::ZeeGenUp) / (correction*(*iPh)->e()) - 1;
      energyDown = m_egammaTool->applyEnergyCorrection((*iPh)->cluster()->eta(),(*iPh)->e(),
						       photontype, egRescaler::EnergyRescalerUpgrade::ZeeGenDown) / (correction*(*iPh)->e()) - 1;
      ph_pesUp_ZGen.push_back(energyUp);
      ph_pesDown_ZGen.push_back(energyDown);
      //
      // Case 3
      energyUp = m_egammaTool->applyEnergyCorrection((*iPh)->cluster()->eta(),(*iPh)->e(),
						     photontype, egRescaler::EnergyRescalerUpgrade::R12StatUp) / (correction*(*iPh)->e()) - 1;
      energyDown = m_egammaTool->applyEnergyCorrection((*iPh)->cluster()->eta(),(*iPh)->e(),
						       photontype, egRescaler::EnergyRescalerUpgrade::R12StatDown) / (correction*(*iPh)->e()) - 1;
      ph_pesUp_Mat.push_back(energyUp);
      ph_pesDown_Mat.push_back(energyDown);
      //
      // Case 4
      energyUp = m_egammaTool->applyEnergyCorrection((*iPh)->cluster()->eta(),(*iPh)->e(),
						     photontype, egRescaler::EnergyRescalerUpgrade::PSStatUp) / (correction*(*iPh)->e()) - 1;
      energyDown = m_egammaTool->applyEnergyCorrection((*iPh)->cluster()->eta(),(*iPh)->e(),
						       photontype, egRescaler::EnergyRescalerUpgrade::PSStatDown) / (correction*(*iPh)->e()) - 1;
      ph_pesUp_PS.push_back(energyUp);
      ph_pesDown_PS.push_back(energyDown);
      //
      // Case 5
      energyUp = m_egammaTool->applyEnergyCorrection((*iPh)->cluster()->eta(),(*iPh)->e(),
						     photontype, egRescaler::EnergyRescalerUpgrade::LowPtUp) / (correction*(*iPh)->e()) - 1;
      energyDown = m_egammaTool->applyEnergyCorrection((*iPh)->cluster()->eta(),(*iPh)->e(),
						       photontype, egRescaler::EnergyRescalerUpgrade::LowPtDown) / (correction*(*iPh)->e()) - 1;
      ph_pesUp_LowPt.push_back(energyUp);
      ph_pesDown_LowPt.push_back(energyDown);

      ++iph;
    }

    msg(MSG::DEBUG) << "Setting photon momenta...";
    setPhotonParameters(&ph_smeared_pT, &ph_eta, &ph_phi,
			&ph_wet, &ph_wpx, &ph_wpy, &ph_statusWord);

    msg(MSG::DEBUG) << "Setting energy scale uncertainty" << endreq;
    setObjectEnergyUncertainties(METUtil::Photons, ph_pesUp_ZStat, ph_pesDown_ZStat,0);
    setObjectEnergyUncertainties(METUtil::Photons, ph_pesUp_ZMeth, ph_pesDown_ZMeth,1);
    setObjectEnergyUncertainties(METUtil::Photons, ph_pesUp_ZGen,  ph_pesDown_ZGen, 2);
    setObjectEnergyUncertainties(METUtil::Photons, ph_pesUp_Mat,   ph_pesDown_Mat,  3);
    setObjectEnergyUncertainties(METUtil::Photons, ph_pesUp_PS,    ph_pesDown_PS,   4);
    setObjectEnergyUncertainties(METUtil::Photons, ph_pesUp_LowPt, ph_pesDown_LowPt,5);

    msg(MSG::DEBUG) << "Setting resolution uncertainty" << endreq;
    setObjectResolutionShift(METUtil::Photons, ph_resUp, ph_resDown);

    if(useMetComp) delete aod_photons;

    return StatusCode::SUCCESS;
  }

  //////////////////////////////////////////////////////////////////////////////////////////////////

  StatusCode METUtilityAthTool::setupTaus(const string &collectionName) {

    msg(MSG::DEBUG) << "Setting up taus" << endreq;

    bool useMetComp = collectionName == "METComposition";

    const Analysis::TauJetContainer *aod_taus = 0;
    vector<vector<float> > tau_wet, tau_wpx, tau_wpy;
    vector<vector<unsigned int> > tau_statusWord;
    if(useMetComp) {
      msg(MSG::DEBUG) << "Setting up tau collection from MET composition" << endreq;
      if(!m_metComp) {
	msg(MSG::WARNING) << "Invalid pointer to MET composition object!" << endreq;
	return StatusCode::FAILURE;
      }
      // Fill the tau collection from the MET composition
      Analysis::TauJetContainer *temp_taus = new Analysis::TauJetContainer;
      MissingETComposition::const_iterator<Analysis::TauJet> fTau(m_metComp->beginIterator<Analysis::TauJet>());
      MissingETComposition::const_iterator<Analysis::TauJet> lTau(m_metComp->endIterator<Analysis::TauJet>());
      for(;fTau!=lTau;++fTau) {
	if(!(*fTau)) msg(MSG::FATAL) << "Oops, didn't get the point(er)" << endreq;
	temp_taus->push_back(new Analysis::TauJet(**fTau));

	vector<float> thewet, thewpx, thewpy;
	thewet.push_back(fTau.getParameter().wet());
	thewpx.push_back(fTau.getParameter().wpx());
	thewpy.push_back(fTau.getParameter().wpy());

	tau_wet.push_back(thewet);
	tau_wpx.push_back(thewpx);
	tau_wpy.push_back(thewpy);

	vector<unsigned int> statusvec;
	statusvec.push_back(fTau.getParameter().statusWord());
	tau_statusWord.push_back(statusvec);
      }

      aod_taus = temp_taus;
    } else {
      // Grab the tau collection from StoreGate
      CHECK( evtStore()->retrieve( aod_taus, collectionName ) );
    }

    msg(MSG::DEBUG) << "Tau collection contains " << aod_taus->size() << " taus." << endreq;

    Analysis::TauJetContainer::const_iterator iTau = aod_taus->begin();
    Analysis::TauJetContainer::const_iterator eTau = aod_taus->end();
    vector<float> tau_pT, tau_eta, tau_phi, tau_E;
    vector<float> tesUp, tesDown;
    for(;iTau!=eTau;++iTau) {
      if(!(*iTau)) msg(MSG::FATAL) << "Oops, didn't get the point(er)" << endreq;
      tau_pT.push_back((*iTau)->pt());
      tau_eta.push_back((*iTau)->eta());
      tau_phi.push_back((*iTau)->phi());
      tau_E.push_back((*iTau)->e());

      // This usage of TESUncertaintyProvider assumes the trunk of
      // PhysicsAnalysis/TauID/TesUncertaintyProvider.
      // New recommendations are in preparation, so please contact the tau CP group
      // if you actually want to use the TES uncertainties

      double uncert = m_TESTool->GetTESUncertainty((*iTau)->pt()/1e3,
						   (*iTau)->eta(),
						   (*iTau)->nProng());

      if(uncert < 0) uncert = 0;
      tesUp.push_back(uncert);
      tesDown.push_back(-1*uncert);

      if(!useMetComp) {
	vector<float> univec;
	univec.push_back(1.);
	tau_wet.push_back(univec);
	tau_wpx.push_back(univec);
	tau_wpy.push_back(univec);

	vector<unsigned int> statusvec;
	statusvec.push_back(MissingETTags::DEFAULT);
	tau_statusWord.push_back(statusvec);
      }
    }

    setTauParameters(&tau_pT, &tau_eta, &tau_phi,
		     &tau_wet, &tau_wpx, &tau_wpy, &tau_statusWord);

    //   setObjectEnergyUncertainties(METUtil::Taus,tesUp,tesDown);

    if(useMetComp) delete aod_taus;

    return StatusCode::SUCCESS;
  }

  //////////////////////////////////////////////////////////////////////////////////////////////////

  StatusCode METUtilityAthTool::setupMuons(const string &collectionName,
					   const string &matchCollectionName,
					   const unsigned short userStatusWord) {

    msg(MSG::DEBUG) << "Setting up muons" << endreq;

    bool useMetComp = collectionName == "METComposition";
    bool doMuonMatch = matchCollectionName != "";

    const Analysis::MuonContainer *match_muons = 0;
    if(doMuonMatch && useMetComp) {
      CHECK( evtStore()->retrieve( match_muons, matchCollectionName ) );
    }

    const Analysis::MuonContainer *aod_muons = 0;
    vector<vector<float> > mu_wet, mu_wpx, mu_wpy;
    vector<vector<unsigned int> > mu_statusWord;
    if(useMetComp) {
      msg(MSG::DEBUG) << "Setting up muon collection from MET composition" << endreq;
      if(!m_metComp) {
	msg(MSG::WARNING) << "Invalid pointer to MET composition object!" << endreq;
	return StatusCode::FAILURE;
      }
      // Fill the muon collection from the MET composition
      Analysis::MuonContainer *temp_muons = new Analysis::MuonContainer;
      MissingETComposition::const_iterator<Analysis::Muon> fMu(m_metComp->beginIterator<Analysis::Muon>());
      MissingETComposition::const_iterator<Analysis::Muon> lMu(m_metComp->endIterator<Analysis::Muon>());
      for(;fMu!=lMu;++fMu) {
	if(!(*fMu)) msg(MSG::FATAL) << "Oops, didn't get the point(er)" << endreq;

	bool saveMuon = false;
	if(doMuonMatch) {
	  Analysis::MuonContainer::const_iterator fMatchMu(match_muons->begin());
	  Analysis::MuonContainer::const_iterator lMatchMu(match_muons->end());
	  for(;fMatchMu!=lMatchMu;++fMatchMu) {
	    if((*fMu)==(*fMatchMu)){saveMuon = true;}
	  }
	} else {saveMuon = true;}

	if(!saveMuon) continue;
	temp_muons->push_back(new Analysis::Muon(**fMu));

	vector<float> thewet, thewpx, thewpy;
	thewet.push_back(fMu.getParameter().wet());
	thewpx.push_back(fMu.getParameter().wpx());
	thewpy.push_back(fMu.getParameter().wpy());

	mu_wet.push_back(thewet);
	mu_wpx.push_back(thewpx);
	mu_wpy.push_back(thewpy);

	vector<unsigned int> statusvec;
	statusvec.push_back(fMu.getParameter().statusWord());
	mu_statusWord.push_back(statusvec);
      }

      aod_muons = temp_muons;
    } else {
      // Grab the muon collection from StoreGate
      CHECK( evtStore()->retrieve( aod_muons, collectionName ) );
    }

    msg(MSG::DEBUG) << "Muon collection contains " << aod_muons->size() << " muons." << endreq;

    int imu = 0;
    Analysis::MuonContainer::const_iterator iMu = aod_muons->begin();
    Analysis::MuonContainer::const_iterator eMu = aod_muons->end();
    vector<float> mu_pT, mu_eta, mu_phi, mu_E;
    vector<float> mu_MS_pT, mu_MS_theta, mu_MS_phi;
    vector<float> mu_smeared_pT, mu_smeared_MS_pT;
    vector<float> cb_meridUp, cb_meridDown;
    vector<float> cb_mermsUp, cb_mermsDown;
    vector<float> mermsUp,    mermsDown;
    vector<float> mesUp,      mesDown;
    for(;iMu!=eMu;iMu++) {
      if(!(*iMu)) msg(MSG::FATAL) << "Oops, didn't get the point(er)" << endreq;
      msg(MSG::VERBOSE) << imu << endl;

      mu_pT.push_back((*iMu)->pt());
      mu_eta.push_back((*iMu)->eta());
      mu_phi.push_back((*iMu)->phi());
      mu_E.push_back((*iMu)->e());

      if(!useMetComp) {
	vector<float> univec;
	univec.push_back(1.);
	mu_wet.push_back(univec);
	mu_wpx.push_back(univec);
	mu_wpy.push_back(univec);

	vector<unsigned int> statusvec;
	statusvec.push_back(userStatusWord);
	mu_statusWord.push_back(statusvec);
      }

      msg(MSG::VERBOSE) << " Getting track particle...";
      const Rec::TrackParticle *thisMSmuon = (*iMu)->muonSpectrometerTrackParticle();
      if(thisMSmuon) {
	mu_MS_pT.push_back(thisMSmuon->pt());
	mu_MS_theta.push_back(asin(thisMSmuon->sinTh()));
	mu_MS_phi.push_back(thisMSmuon->phi());
      } else {
	msg(MSG::VERBOSE) << " FAILED! " << endreq;
	mu_MS_pT.push_back(0.);
	mu_MS_theta.push_back(0.);
	mu_MS_phi.push_back(0.);
      }

      double ptcb = (*iMu)->pt();
      double ptid = (*iMu)->hasInDetTrackParticle() ?
	(*iMu)->inDetTrackParticle()->pt() : 0.;
      double ptms = (*iMu)->hasMuonExtrapolatedTrackParticle() ?
	(*iMu)->muonSpectrometerTrackParticle()->pt() : 0.;
      m_muonTool->SetSeed(int(1.e+5*fabs((*iMu)->phi())));
      double etaMu = (*iMu)->eta();
      double charge = (*iMu)->charge();
      m_muonTool->Event(ptms, ptid, ptcb, etaMu);
      msg(MSG::VERBOSE) << " Original muon pT = " << ptcb << " (cb), " << ptms << " (ms)";

      msg(MSG::VERBOSE) << " Doing muon smearing...";
      float smearedCBPt(0.), smearedMSPt(0.);

      if((*iMu)->isCombinedMuon()) {
	m_muonTool->Event(ptms, ptid, ptcb, etaMu, charge);
	smearedCBPt = m_muonTool->pTCB();
	smearedMSPt = m_muonTool->pTMS();
	mu_smeared_pT.push_back(smearedCBPt);
	mu_smeared_MS_pT.push_back(smearedMSPt);
      } else if((*iMu)->isSegmentTaggedMuon()) {
	m_muonTool->Event(ptid, etaMu, "ID", charge);
	smearedCBPt = m_muonTool->pTID(); // use ID rather than combined
	smearedMSPt = m_muonTool->pTMS(); // is 0
	mu_smeared_pT.push_back(smearedCBPt);
	mu_smeared_MS_pT.push_back(smearedMSPt);
      } else if((*iMu)->isStandAloneMuon()) {
	m_muonTool->Event(ptms, etaMu, "MS", charge);
	smearedCBPt = m_muonTool->pTID(); // is 0
	smearedMSPt = m_muonTool->pTMS();
	mu_smeared_pT.push_back(smearedCBPt);
	mu_smeared_MS_pT.push_back(smearedMSPt);
      } else {
	mu_smeared_pT.push_back(0.);
	mu_smeared_MS_pT.push_back(0.);
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

      msg(MSG::VERBOSE) << endreq;
      ++imu;
    }

    if(m_useSmearedMu) {
      msg(MSG::DEBUG) << "Setting muon parameters with smeared muons" << endreq;
      setMuonParameters(&mu_smeared_pT, &mu_eta, &mu_phi,
			&mu_wet, &mu_wpx, &mu_wpy, &mu_statusWord);
      msg(MSG::DEBUG) << "Setting extra muon parameters with smeared muons" << endreq;
      setExtraMuonParameters(&mu_smeared_MS_pT, &mu_MS_theta, &mu_MS_phi);
    } else {
      msg(MSG::DEBUG) << "Setting muon parameters with original muons" << endreq;
      setMuonParameters(&mu_pT, &mu_eta, &mu_phi,
			&mu_wet, &mu_wpx, &mu_wpy, &mu_statusWord);
      msg(MSG::DEBUG) << "Setting extra muon parameters with original muons" << endreq;
      setExtraMuonParameters(&mu_MS_pT, &mu_MS_theta, &mu_MS_phi);
    } 

    msg(MSG::DEBUG) << "Setting muon resolution" << endreq;
    // muons are complicated, and MET makes use of track, spectro, and combined quantites,
    // so we need all off their resolutions. comboms reflects that it is 
    // the combined muon res affected by shifting ms res up and down.
    // comboid is for shifting the id res up and down
    setObjectResolutionShift(METUtil::MuonsComboMS, cb_mermsUp, cb_mermsDown);
    setObjectResolutionShift(METUtil::MuonsComboID, cb_meridUp, cb_meridDown);
    setObjectResolutionShift(METUtil::SpectroMuons, mermsUp, mermsDown);

    msg(MSG::DEBUG) << "Setting muon energy scale uncertainties" << endreq;
    // for now the mes only affects combined
    setObjectEnergyUncertainties(METUtil::Muons, mesUp, mesDown);

    if(useMetComp) delete aod_muons;

    return StatusCode::SUCCESS;
  }

  //////////////////////////////////////////////////////////////////////////////////////////////////

  StatusCode METUtilityAthTool::setupClusters(const string &collectionName,
					      const unsigned short userStatusWord) {
    msg(MSG::DEBUG) << "Setting up clusters" << endreq;

    bool useMetComp = collectionName == "METComposition";

    const CaloClusterContainer *aod_clusters = 0;
    vector<vector<float> > cl_wet, cl_wpx, cl_wpy;
    vector<vector<unsigned int> > cl_statusWord;
    if(useMetComp) {
      msg(MSG::DEBUG) << "Setting up cluster collection from MET composition" << endreq;
      if(!m_metComp) {
	msg(MSG::WARNING) << "Invalid pointer to MET composition object!" << endreq;
	return StatusCode::FAILURE;
      }
      // Fill the cluster collection from the MET composition
      int iclus = 0;
      CaloClusterContainer *temp_clusters = new CaloClusterContainer;
      MissingETComposition::const_iterator<CaloCluster> fCl(m_metComp->beginIterator<CaloCluster>());
      MissingETComposition::const_iterator<CaloCluster> lCl(m_metComp->endIterator<CaloCluster>());
      for(;fCl!=lCl;fCl++) {
	if(!(*fCl)) msg(MSG::FATAL) << "Oops, didn't get the point(er)" << endreq;
	temp_clusters->push_back(new CaloCluster(**fCl));

	msg(MSG::VERBOSE) << "Cluster " << iclus << endl;

	vector<float> thewet, thewpx, thewpy;

	thewet.push_back(fCl.getParameter().wet());
	thewpx.push_back(fCl.getParameter().wpx());
	thewpy.push_back(fCl.getParameter().wpy());

	cl_wet.push_back(thewet);
	cl_wpx.push_back(thewpx);
	cl_wpy.push_back(thewpy);

	vector<unsigned int> statusvec;
	statusvec.push_back(fCl.getParameter().statusWord());
	cl_statusWord.push_back(statusvec);
	//       msg(MSG::VERBOSE) << "statusWord = " << fCl.getParameter().statusWord() << endreq;
	++iclus;
      }

      aod_clusters = temp_clusters;
    } else {
      // Grab the cluster collection from StoreGate
      CHECK( evtStore()->retrieve( aod_clusters, collectionName ) );
    }

    msg(MSG::DEBUG) << "Cluster collection contains " << aod_clusters->size() << " clusters." << endreq;

    CaloClusterContainer::const_iterator iCl = aod_clusters->begin();
    CaloClusterContainer::const_iterator eCl = aod_clusters->end();
    vector<float> cl_pT, cl_eta, cl_phi, cl_E;
    for(;iCl!=eCl;iCl++) {
      if(!(*iCl)) msg(MSG::FATAL) << "Oops, didn't get the point(er)" << endreq;
      cl_pT.push_back((*iCl)->pt());
      cl_eta.push_back((*iCl)->eta());
      cl_phi.push_back((*iCl)->phi());
      cl_E.push_back((*iCl)->e());

      if(!useMetComp) {
	vector<float> univec;
	univec.push_back(1.);
	cl_wet.push_back(univec);
	cl_wpx.push_back(univec);
	cl_wpy.push_back(univec);

	vector<unsigned int> statusvec;
	statusvec.push_back(userStatusWord);
	cl_statusWord.push_back(statusvec);
      }
    }

    setClusterParameters(&cl_pT, &cl_eta, &cl_phi, &cl_E,
			 &cl_wet, &cl_wpx, &cl_wpy, &cl_statusWord);

    if(useMetComp) delete aod_clusters;

    return StatusCode::SUCCESS;
  }

  //////////////////////////////////////////////////////////////////////////////////////////////////

  StatusCode METUtilityAthTool::setupTracks(const string &collectionName) {
    msg(MSG::DEBUG) << "Setting up tracks" << endreq;

    bool useMetComp = collectionName == "METComposition";

    const Rec::TrackParticleContainer *aod_tracks = 0;
    vector<vector<float> > tr_wet, tr_wpx, tr_wpy;
    vector<vector<unsigned int> > tr_statusWord;
    if(useMetComp) {
      msg(MSG::DEBUG) << "Setting up track collection from MET composition" << endreq;
      if(!m_metComp) {
	msg(MSG::WARNING) << "Invalid pointer to MET composition object!" << endreq;
	return StatusCode::FAILURE;
      }
      // Fill the track collection from the MET composition
      int itrk = 0;
      Rec::TrackParticleContainer *temp_tracks = new Rec::TrackParticleContainer;
      MissingETComposition::const_iterator<Rec::TrackParticle> fTr(m_metComp->beginIterator<Rec::TrackParticle>());
      MissingETComposition::const_iterator<Rec::TrackParticle> lTr(m_metComp->endIterator<Rec::TrackParticle>());
      for(;fTr!=lTr;fTr++) {
	if(!(*fTr)) msg(MSG::FATAL) << "Oops, didn't get the point(er)" << endreq;
	temp_tracks->push_back(new Rec::TrackParticle(**fTr));

	msg(MSG::VERBOSE) << "Track " << itrk << endl;

	vector<float> thewet, thewpx, thewpy;
	thewet.push_back(fTr.getParameter().wet());
	thewpx.push_back(fTr.getParameter().wpx());
	thewpy.push_back(fTr.getParameter().wpy());

	tr_wet.push_back(thewet);
	tr_wpx.push_back(thewpx);
	tr_wpy.push_back(thewpy);

	vector<unsigned int> statusvec;
	statusvec.push_back(fTr.getParameter().statusWord());
	tr_statusWord.push_back(statusvec);
	msg(MSG::VERBOSE) << "statusWord = " << fTr.getParameter().statusWord() << endreq;
	++itrk;
      }

      aod_tracks = temp_tracks;
    } else {
      // Grab the track collection from StoreGate
      CHECK( evtStore()->retrieve( aod_tracks, collectionName ) );
    }

    msg(MSG::DEBUG) << "Track collection contains " << aod_tracks->size() << " tracks." << endreq;

    Rec::TrackParticleContainer::const_iterator iTr = aod_tracks->begin();
    Rec::TrackParticleContainer::const_iterator eTr = aod_tracks->end();
    vector<float> tr_pT, tr_eta, tr_phi, tr_E;
    for(;iTr!=eTr;iTr++) {
      if(!(*iTr)) msg(MSG::FATAL) << "Oops, didn't get the point(er)" << endreq;
      tr_pT.push_back((*iTr)->pt());
      tr_eta.push_back((*iTr)->eta());
      tr_phi.push_back((*iTr)->phi());
      tr_E.push_back((*iTr)->e());

      if(!useMetComp) {
	vector<float> univec;
	univec.push_back(1.);
	tr_wet.push_back(univec);
	tr_wpx.push_back(univec);
	tr_wpy.push_back(univec);

	vector<unsigned int> statusvec;
	statusvec.push_back(MissingETTags::DEFAULT);
	tr_statusWord.push_back(statusvec);
      }
    }

    setTrackParameters(&tr_pT, &tr_eta, &tr_phi, &tr_E,
		       &tr_wet, &tr_wpx, &tr_wpy, &tr_statusWord);

    if(useMetComp) delete aod_tracks;

    return StatusCode::SUCCESS;
  }

  //////////////////////////////////////////////////////////////////////////////////////////////////

  StatusCode METUtilityAthTool::setNvtx(const std::string &collectionName)
  {
    const VxContainer* aod_vertices;
    CHECK( evtStore()->retrieve( aod_vertices, collectionName ) );

    m_nvtx = 0;
    m_nvtxjet = 0;
    VxContainer::const_iterator iVx;
    VxContainer::const_iterator eVx = aod_vertices->end();
    //     bool goodPV = false;
    //     for(iVx = aod_vertices->begin(); iVx != eVx; ++iVx) {
    //       if((*iVx)->vertexType() == Trk::PriVtx) {
    // 	if((*iVx)->vxTrackAtVertex()->size()>2 && fabs((*iVx)->recVertex().position().z()<200.)) {
    // 	  goodPV = true;
    // 	}
    //       }
    //     }
    //    if(goodPV) {
    for(iVx = aod_vertices->begin(); iVx != eVx; ++iVx) {
      if((*iVx)->vxTrackAtVertex()->size()>2) ++m_nvtx;
      if((*iVx)->vxTrackAtVertex()->size()>=2) ++m_nvtxjet;
    }
    //    }

    return StatusCode::SUCCESS;
  }

  //////////////////////////////////////////////////////////////////////////////////////////////////
  //  methods for getting and setting the desired MET terms
  //

  void METUtilityAthTool::setMETTerm(const METUtil::Terms term, const MissingET* thisMET)
  {
    msg(MSG::DEBUG) << "Set MET term " << METUtil::getTermName(term) << endreq;
    METUtility::setMETTerm(term,thisMET->etx(),thisMET->ety(),thisMET->sumet());
  }

  MissingET METUtilityAthTool::getMETTerm(const METUtil::Terms term, const METUtil::Systematics systematic)
  {
    MissingET thisMET;
    METObject myMET = getMissingET(term,systematic);
    thisMET.setEx(myMET.etx());
    thisMET.setEy(myMET.ety());
    thisMET.setEtSum(myMET.sumet());

    // In case clusters have been built and SoftJets set as well.
    // Can't really deal with a separate SoftJets term any more.
    // This doesn't handle SoftTerms systematics correctly.
    if( (term == METUtil::SoftTerms||term==METUtil::RefFinal)
	&& m_SoftJetsKey != "" && m_momentaSet[METUtil::Clusters]) {

      thisMET.setEx(myMET.etx() + m_terms[METUtil::SoftTerms].etx());
      thisMET.setEy(myMET.ety() + m_terms[METUtil::SoftTerms].ety());
      thisMET.setEtSum(myMET.etx() + m_terms[METUtil::SoftTerms].sumet());

    }

    return thisMET;
  }

  //////////////////////////////////////////////////////////////////////////////////////////////////
  //  trigger process on hitting a new event
  //

  void METUtilityAthTool::handle(const Incident& inc) {
    // Get the messaging service, print where you are

    msg(MSG::DEBUG) << "entering handle(), incidence type " << inc.type()
		    << " from " << inc.source() << endreq;

    // Only call fillIOV for EndEvent incident
    if (inc.type() != "BeginEvent") return;
    if(m_doEveryEvent) 
      if(process().isFailure()) msg(MSG::FATAL) << "Setup of METUtility failed" << endreq;

    msg(MSG::DEBUG) << "end event handle" << endreq;

  }

}
