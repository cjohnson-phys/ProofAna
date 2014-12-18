/// Dear emacs, this is -*-c++-*-
///***********************************************************************
///
/// METUtilityAthTool
/// Authors: J. Goodson, T.J. Khoo
///
/// METUtility class, for use in ATHENA
///
///#### Usage:
///
///
///***********************************************************************

#ifndef _METUTILITYATHTOOL_
#define _METUTILITYATHTOOL_

#include "MissingETUtility/IMETUtilityAthTool.h"
#include "AthenaBaseComps/AthAlgTool.h"
#include "GaudiKernel/IIncidentListener.h"
#include "GaudiKernel/IIncidentSvc.h"
#include "GaudiKernel/ToolHandle.h"

namespace egRescaler {
  class EnergyRescalerUpgrade;
}

namespace MuonSmear{
  class SmearingClass;
}

// Jet tools
class JetCalibrationTool;
class JetSmearingTool;
class MultijetJESUncertaintyProvider;

class TESUncertaintyProvider;

class MissingET;
class MissingETComposition;

namespace MissingETUtility {

  class METUtilityAthTool : virtual public AthAlgTool, 
			    virtual public IMETUtilityAthTool,
			    virtual public IIncidentListener {

  public:
  
    // Constructors, destructor
    METUtilityAthTool(const std::string& type, const std::string& name,
		      const IInterface* pParent);

    virtual ~METUtilityAthTool();

    StatusCode queryInterface( const InterfaceID& riid, void** ppvIf );

    virtual StatusCode initialize();
    virtual StatusCode process();
    virtual StatusCode finalize();

    virtual void handle(const Incident& inc);

    virtual StatusCode setupJets(const std::string &collectionName);
    virtual StatusCode setupElectrons(const std::string &collectionName);
    virtual StatusCode setupPhotons(const std::string &collectionName);
    virtual StatusCode setupTaus(const std::string &collectionName);
    virtual StatusCode setupMuons(const std::string &collectionName,
				  const std::string &matchCollectionName,
				  const unsigned short userStatusWord);
    virtual StatusCode setupClusters(const std::string &collectionName,
				     const unsigned short userStatusWord);
    virtual StatusCode setupTracks(const std::string &collectionName);

    virtual StatusCode setNvtx(const std::string &collectionName);

    virtual void       setMETTerm(const METUtil::Terms term, const MissingET* thisMET);
    virtual MissingET  getMETTerm(const METUtil::Terms term,
				  const METUtil::Systematics systematic = METUtil::None);

  private:  
    JetCalibrationTool* m_jetCalibTool;
    JetSmearingTool* m_JERTool;
    MultijetJESUncertaintyProvider* m_multiJES;
    egRescaler::EnergyRescalerUpgrade* m_egammaTool;
    MuonSmear::SmearingClass* m_muonTool;
    TESUncertaintyProvider* m_TESTool;

    bool   m_isData;
    bool   m_doEveryEvent;

    string m_jetType;

    bool   m_doJetCalib;
    string m_configfileJetCalib;

    int    m_nvtxjet;
    string m_mcTypeJES;
    string m_configfileJES;
    string m_configMultijet;
    string m_configdirJES;

    //    string m_methodJER;
    string m_inputfileJER;

    string m_muData;
    string m_muAlgo;
    string m_muSmearType;
    string m_muRel;
    string m_muDir;

    string m_TESpath;
    string m_TESid;
    string m_TESproduction;

    bool   m_useSmearedEl;
    bool   m_useSmearedPh;
    bool   m_useSmearedMu;

    bool m_flagis2012;
    bool m_flagisSTVF;

    unsigned short m_muonStatusWord;
    unsigned short m_clusterStatusWord;

    unsigned short m_jet_pu_code;
    unsigned short m_st_pu_code;

    string m_clusterKey;
    string m_trackKey;
    string m_electronKey;
    string m_jetKey;
    string m_muonKey;
    string m_photonKey;
    string m_taujetKey;
    string m_vertexKey;

    string m_muonMatchKey; // for ambiguity resolution between Muid and Muons

    string m_RefEleKey;
    string m_RefGammaKey;
    string m_RefJetKey;
    string m_RefTauKey;
    string m_RefMuonKey;
    string m_SoftJetsKey;
    string m_SoftTermsKey;
    string m_TruthKey;

    string m_metCompKey;
    const MissingETComposition *m_metComp;

  };
}

#endif
