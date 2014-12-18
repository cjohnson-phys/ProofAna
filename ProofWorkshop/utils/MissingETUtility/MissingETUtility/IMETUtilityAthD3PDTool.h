// this is -*-c++-*-
#ifndef _IMETUTILITYATHD3PDTOOL_
#define _IMETUTILITYATHD3PDTOOL_

#include "GaudiKernel/IAlgTool.h"
#include "MissingETUtility/METUtility.h"


static const InterfaceID IID_IMETUtilityAthD3PDTool( "IMETUtilityAthD3PDTool", 1, 0 );



class IMETUtilityAthD3PDTool : virtual public METUtility, virtual public IAlgTool {

public:
 
  static const InterfaceID& interfaceID() { return IID_IMETUtilityAthD3PDTool; };
 

  virtual StatusCode setMET_xy() = 0;
  virtual StatusCode setMET_etphi() = 0;

  virtual StatusCode setElectronPT(std::vector<float>, std::string collName="el") = 0;
  virtual StatusCode setPhotonPT(std::vector<float>, std::string collName="ph") = 0;
  virtual StatusCode setMuonPT(std::vector<float> pt, std::vector<float> ms_pt, std::string collName="mu_staco") = 0;
  virtual StatusCode setJetPT(std::vector<float> pt, std::vector<float> e,std::string collName="jet_AntiKt4LCTopo") = 0;

};



#endif
