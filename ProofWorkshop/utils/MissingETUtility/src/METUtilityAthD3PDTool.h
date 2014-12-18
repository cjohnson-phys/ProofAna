/// Dear emacs, this is -*-c++-*-
///***********************************************************************
///METUtilityAthD3PDTool
///AthAlgTool for people who like to read D3PD in Athena
///Author: Will Buttinger
///***********************************************************************

#ifndef _METUTILITYATHD3PDTOOL_
#define _METUTILITYATHD3PDTOOL_

#include "MissingETUtility/IMETUtilityAthD3PDTool.h"
#include "AthenaBaseComps/AthAlgTool.h"


class METUtilityAthD3PDTool : virtual public AthAlgTool, 
			      virtual public IMETUtilityAthD3PDTool,
			      virtual public IIncidentListener {

public:
  
  // Constructors, destructor
  METUtilityAthD3PDTool(const std::string& type, const std::string& name,
			const IInterface* pParent);

  virtual ~METUtilityAthD3PDTool();

  StatusCode queryInterface( const InterfaceID& riid, void** ppvIf );

  virtual StatusCode initialize();

  // To set up the individual objects
  virtual StatusCode setElectronPT(std::vector<float>, std::string collName="el");
  virtual StatusCode setPhotonPT(std::vector<float>, std::string collName="ph");
  virtual StatusCode setMuonPT(std::vector<float> pt, std::vector<float> ms_pt,std::string collName="mu_staco");
  virtual StatusCode setJetPT(std::vector<float> pt, std::vector<float> e,std::string collName="jet_AntiKt4LCTopo");

  // To set up any remaining terms
  virtual StatusCode setMET_xy();
  virtual StatusCode setMET_etphi();

  virtual StatusCode finalize();

  virtual void handle(const Incident& inc);
    

private:  

  bool m_electronPTGiven;
  bool m_muonPTGiven;
  bool m_photonPTGiven;
  bool m_jetPTGiven;

  string m_metsuffix;
  int    m_metbranchtype;

  bool m_resetEveryEvent;
  bool m_verbosity;
  bool m_doSignif;

  bool m_dorefele;
  bool m_dorefgamma;
  bool m_doreftau;
  bool m_dorefjet;
  bool m_dosoftjets;
  bool m_dorefmuon;
  bool m_domuontotal;
  bool m_dosoftterms;
  bool m_ismuid;
  double m_softjetcut; 
   
};


#endif
