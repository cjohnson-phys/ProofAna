//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu May 19 11:45:54 2011 by ROOT version 5.27/02
// from TChain qcd/
//////////////////////////////////////////////////////////

#ifndef oldExample_h
#define oldExample_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

class oldExample {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   UInt_t          RunNumber;
   UInt_t          EventNumber;
   UInt_t          lbn;
   UInt_t          bcid;
   Bool_t          collcand_passCaloTime;
   Bool_t          collcand_passMBTSTime;
   Bool_t          collcand_passTrigger;
   Bool_t          collcand_pass;
   vector<float>   *beamSpot_x;
   vector<float>   *beamSpot_y;
   vector<float>   *beamSpot_z;
   Int_t           vxp_n;
   vector<float>   *vxp_x;
   vector<float>   *vxp_y;
   vector<float>   *vxp_z;
   vector<float>   *vxp_cov_x;
   vector<float>   *vxp_cov_y;
   vector<float>   *vxp_cov_z;
   vector<float>   *vxp_cov_xy;
   vector<float>   *vxp_cov_xz;
   vector<float>   *vxp_cov_yz;
   vector<float>   *vxp_chi2;
   vector<int>     *vxp_ndof;
   vector<float>   *vxp_px;
   vector<float>   *vxp_py;
   vector<float>   *vxp_pz;
   vector<float>   *vxp_E;
   vector<float>   *vxp_m;
   vector<int>     *vxp_nTracks;
   vector<float>   *vxp_sumPt;
   vector<int>     *vxp_type;
   vector<int>     *vxp_trk_n;
   vector<vector<int> > *vxp_trk_index;
   Int_t           el_n;
   vector<float>   *el_E;
   vector<float>   *el_Et;
   vector<float>   *el_pt;
   vector<float>   *el_m;
   vector<float>   *el_eta;
   vector<float>   *el_phi;
   vector<float>   *el_px;
   vector<float>   *el_py;
   vector<float>   *el_pz;
   vector<float>   *el_charge;
   vector<int>     *el_author;
   vector<unsigned int> *el_isEM;
   vector<int>     *el_loose;
   vector<int>     *el_medium;
   vector<int>     *el_mediumIso;
   vector<int>     *el_tight;
   vector<int>     *el_tightIso;
   vector<float>   *el_Etcone45;
   vector<float>   *el_Etcone20;
   vector<float>   *el_Etcone30;
   vector<float>   *el_Etcone40;
   vector<float>   *el_Es2;
   vector<float>   *el_etas2;
   vector<float>   *el_phis2;
   vector<float>   *el_cl_E;
   vector<float>   *el_cl_pt;
   vector<float>   *el_cl_eta;
   vector<float>   *el_cl_phi;
   vector<float>   *el_trackd0;
   vector<float>   *el_trackz0;
   vector<float>   *el_trackphi;
   vector<float>   *el_tracktheta;
   vector<float>   *el_trackqoverp;
   vector<float>   *el_trackpt;
   vector<float>   *el_tracketa;
   vector<float>   *el_vertx;
   vector<float>   *el_verty;
   vector<float>   *el_vertz;
   Bool_t          EF_e10_NoCut;
   Bool_t          EF_e10_loose;
   Bool_t          EF_e10_loose_mu10;
   Bool_t          EF_e10_loose_mu6;
   Bool_t          EF_e10_medium;
   Bool_t          EF_e10_medium_IDTrkNoCut;
   Bool_t          EF_e10_medium_SiTrk;
   Bool_t          EF_e10_medium_TRT;
   Bool_t          EF_e10_tight;
   Bool_t          EF_e10_tight_TRT;
   Bool_t          EF_e15_loose;
   Bool_t          EF_e15_loose_IDTrkNoCut;
   Bool_t          EF_e15_medium;
   Bool_t          EF_e15_medium_SiTrk;
   Bool_t          EF_e15_medium_TRT;
   Bool_t          EF_e15_tight;
   Bool_t          EF_e15_tight_TRT;
   Bool_t          EF_e20_loose;
   Bool_t          EF_e20_loose_IDTrkNoCut;
   Bool_t          EF_e20_loose_TRT;
   Bool_t          EF_e20_loose_passEF;
   Bool_t          EF_e20_loose_passL2;
   Bool_t          EF_e20_loose_xe20;
   Bool_t          EF_e20_loose_xe20_noMu;
   Bool_t          EF_e20_loose_xe30;
   Bool_t          EF_e20_loose_xe30_noMu;
   Bool_t          EF_e20_medium;
   Bool_t          EF_mu10;
   Bool_t          EF_mu10_Ecut12;
   Bool_t          EF_mu10_Ecut123;
   Bool_t          EF_mu10_Ecut13;
   Bool_t          EF_mu10_IDTrkNoCut;
   Bool_t          EF_mu10_MG;
   Bool_t          EF_mu10_MSonly;
   Bool_t          EF_mu10_MSonly_Ecut12;
   Bool_t          EF_mu10_MSonly_Ecut123;
   Bool_t          EF_mu10_MSonly_Ecut13;
   Bool_t          EF_mu10_MSonly_tight;
   Bool_t          EF_mu10_NoAlg;
   Bool_t          EF_mu10_SiTrk;
   Bool_t          EF_mu10_j30;
   Bool_t          EF_mu10_tight;
   Bool_t          EF_mu10i_loose;
   Bool_t          EF_mu13;
   Bool_t          EF_mu13_MG;
   Bool_t          EF_mu13_MG_tight;
   Bool_t          EF_mu13_tight;
   Bool_t          EF_mu15;
   Bool_t          EF_mu15_MG;
   Bool_t          EF_mu15_NoAlg;
   Bool_t          L1_2J15_XE10;
   Bool_t          L1_2J15_XE15;
   Bool_t          L1_2J15_XE25;
   Bool_t          L1_EM10;
   Bool_t          L1_EM10I;
   Bool_t          L1_EM14;
   Bool_t          L1_EM14I;
   Bool_t          L1_EM14_XE10;
   Bool_t          L1_EM14_XE15;
   Bool_t          L1_J15_XE15_EM10;
   Bool_t          L1_J15_XE15_MU15;
   Bool_t          L1_J30_XE10;
   Bool_t          L1_J30_XE15;
   Bool_t          L1_J30_XE25;
   Bool_t          L1_MU10;
   Bool_t          L1_MU15;
   Bool_t          L1_MU20;
   Bool_t          L1_MU6;
   Bool_t          L1_XE10;
   Bool_t          L1_XE15;
   Bool_t          L1_XE20;
   Bool_t          L1_XE25;
   Bool_t          L1_XE30;
   Bool_t          L1_XE35;
   Bool_t          L1_XE40;
   Bool_t          L1_XE50;
   Int_t           mu_staco_n;
   vector<float>   *mu_staco_E;
   vector<float>   *mu_staco_pt;
   vector<float>   *mu_staco_m;
   vector<float>   *mu_staco_eta;
   vector<float>   *mu_staco_phi;
   vector<float>   *mu_staco_px;
   vector<float>   *mu_staco_py;
   vector<float>   *mu_staco_pz;
   vector<float>   *mu_staco_charge;
   vector<unsigned short> *mu_staco_allauthor;
   vector<int>     *mu_staco_author;
   vector<float>   *mu_staco_beta;
   vector<float>   *mu_staco_isMuonLikelihood;
   vector<float>   *mu_staco_matchchi2;
   vector<int>     *mu_staco_matchndof;
   vector<float>   *mu_staco_etcone20;
   vector<float>   *mu_staco_etcone30;
   vector<float>   *mu_staco_etcone40;
   vector<float>   *mu_staco_nucone20;
   vector<float>   *mu_staco_nucone30;
   vector<float>   *mu_staco_nucone40;
   vector<float>   *mu_staco_ptcone20;
   vector<float>   *mu_staco_ptcone30;
   vector<float>   *mu_staco_ptcone40;
   vector<float>   *mu_staco_energyLossPar;
   vector<float>   *mu_staco_energyLossErr;
   vector<float>   *mu_staco_etCore;
   vector<float>   *mu_staco_energyLossType;
   vector<unsigned short> *mu_staco_caloMuonIdTag;
   vector<double>  *mu_staco_caloLRLikelihood;
   vector<int>     *mu_staco_bestMatch;
   vector<int>     *mu_staco_isStandAloneMuon;
   vector<int>     *mu_staco_isCombinedMuon;
   vector<int>     *mu_staco_isLowPtReconstructedMuon;
   vector<int>     *mu_staco_loose;
   vector<int>     *mu_staco_medium;
   vector<int>     *mu_staco_tight;
   vector<float>   *mu_staco_d0_exPV;
   vector<float>   *mu_staco_z0_exPV;
   vector<float>   *mu_staco_phi_exPV;
   vector<float>   *mu_staco_theta_exPV;
   vector<float>   *mu_staco_qoverp_exPV;
   vector<float>   *mu_staco_cb_d0_exPV;
   vector<float>   *mu_staco_cb_z0_exPV;
   vector<float>   *mu_staco_cb_phi_exPV;
   vector<float>   *mu_staco_cb_theta_exPV;
   vector<float>   *mu_staco_cb_qoverp_exPV;
   vector<float>   *mu_staco_id_d0_exPV;
   vector<float>   *mu_staco_id_z0_exPV;
   vector<float>   *mu_staco_id_phi_exPV;
   vector<float>   *mu_staco_id_theta_exPV;
   vector<float>   *mu_staco_id_qoverp_exPV;
   vector<float>   *mu_staco_me_d0_exPV;
   vector<float>   *mu_staco_me_z0_exPV;
   vector<float>   *mu_staco_me_phi_exPV;
   vector<float>   *mu_staco_me_theta_exPV;
   vector<float>   *mu_staco_me_qoverp_exPV;
   vector<float>   *mu_staco_ie_d0_exPV;
   vector<float>   *mu_staco_ie_z0_exPV;
   vector<float>   *mu_staco_ie_phi_exPV;
   vector<float>   *mu_staco_ie_theta_exPV;
   vector<float>   *mu_staco_ie_qoverp_exPV;
   vector<vector<int> > *mu_staco_SpaceTime_detID;
   vector<vector<float> > *mu_staco_SpaceTime_t;
   vector<vector<float> > *mu_staco_SpaceTime_tError;
   vector<vector<float> > *mu_staco_SpaceTime_weight;
   vector<vector<float> > *mu_staco_SpaceTime_x;
   vector<vector<float> > *mu_staco_SpaceTime_y;
   vector<vector<float> > *mu_staco_SpaceTime_z;
   vector<vector<float> > *mu_staco_SpaceTime_t_Tile;
   vector<vector<float> > *mu_staco_SpaceTime_tError_Tile;
   vector<vector<float> > *mu_staco_SpaceTime_weight_Tile;
   vector<vector<float> > *mu_staco_SpaceTime_x_Tile;
   vector<vector<float> > *mu_staco_SpaceTime_y_Tile;
   vector<vector<float> > *mu_staco_SpaceTime_z_Tile;
   vector<vector<float> > *mu_staco_SpaceTime_t_TRT;
   vector<vector<float> > *mu_staco_SpaceTime_tError_TRT;
   vector<vector<float> > *mu_staco_SpaceTime_weight_TRT;
   vector<vector<float> > *mu_staco_SpaceTime_x_TRT;
   vector<vector<float> > *mu_staco_SpaceTime_y_TRT;
   vector<vector<float> > *mu_staco_SpaceTime_z_TRT;
   vector<vector<float> > *mu_staco_SpaceTime_t_MDT;
   vector<vector<float> > *mu_staco_SpaceTime_tError_MDT;
   vector<vector<float> > *mu_staco_SpaceTime_weight_MDT;
   vector<vector<float> > *mu_staco_SpaceTime_x_MDT;
   vector<vector<float> > *mu_staco_SpaceTime_y_MDT;
   vector<vector<float> > *mu_staco_SpaceTime_z_MDT;
   vector<float>   *mu_staco_TileCellEnergyLayer1;
   vector<float>   *mu_staco_TileTimeLayer1;
   vector<float>   *mu_staco_TileCellRmsNoiseLayer1;
   vector<float>   *mu_staco_TileCellSignLayer1;
   vector<float>   *mu_staco_TileCellEnergyLayer2;
   vector<float>   *mu_staco_TileTimeLayer2;
   vector<float>   *mu_staco_TileCellRmsNoiseLayer2;
   vector<float>   *mu_staco_TileCellSignLayer2;
   vector<float>   *mu_staco_TileCellEnergyLayer3;
   vector<float>   *mu_staco_TileTimeLayer3;
   vector<float>   *mu_staco_TileCellRmsNoiseLayer3;
   vector<float>   *mu_staco_TileCellSignLayer3;
   vector<float>   *mu_staco_MSTrkT0_1;
   vector<float>   *mu_staco_MSTrkT0_2;
   vector<float>   *mu_staco_MSTrkT0_3;
   vector<float>   *mu_staco_cov_d0_exPV;
   vector<float>   *mu_staco_cov_z0_exPV;
   vector<float>   *mu_staco_cov_phi_exPV;
   vector<float>   *mu_staco_cov_theta_exPV;
   vector<float>   *mu_staco_cov_qoverp_exPV;
   vector<float>   *mu_staco_cov_d0_z0_exPV;
   vector<float>   *mu_staco_cov_d0_phi_exPV;
   vector<float>   *mu_staco_cov_d0_theta_exPV;
   vector<float>   *mu_staco_cov_d0_qoverp_exPV;
   vector<float>   *mu_staco_cov_z0_phi_exPV;
   vector<float>   *mu_staco_cov_z0_theta_exPV;
   vector<float>   *mu_staco_cov_z0_qoverp_exPV;
   vector<float>   *mu_staco_cov_phi_theta_exPV;
   vector<float>   *mu_staco_cov_phi_qoverp_exPV;
   vector<float>   *mu_staco_cov_theta_qoverp_exPV;
   vector<float>   *mu_staco_id_cov_d0_exPV;
   vector<float>   *mu_staco_id_cov_z0_exPV;
   vector<float>   *mu_staco_id_cov_phi_exPV;
   vector<float>   *mu_staco_id_cov_theta_exPV;
   vector<float>   *mu_staco_id_cov_qoverp_exPV;
   vector<float>   *mu_staco_me_cov_d0_exPV;
   vector<float>   *mu_staco_me_cov_z0_exPV;
   vector<float>   *mu_staco_me_cov_phi_exPV;
   vector<float>   *mu_staco_me_cov_theta_exPV;
   vector<float>   *mu_staco_me_cov_qoverp_exPV;
   vector<float>   *mu_staco_ms_d0;
   vector<float>   *mu_staco_ms_z0;
   vector<float>   *mu_staco_ms_phi;
   vector<float>   *mu_staco_ms_theta;
   vector<float>   *mu_staco_ms_qoverp;
   vector<float>   *mu_staco_id_d0;
   vector<float>   *mu_staco_id_z0;
   vector<float>   *mu_staco_id_phi;
   vector<float>   *mu_staco_id_theta;
   vector<float>   *mu_staco_id_qoverp;
   vector<float>   *mu_staco_me_d0;
   vector<float>   *mu_staco_me_z0;
   vector<float>   *mu_staco_me_phi;
   vector<float>   *mu_staco_me_theta;
   vector<float>   *mu_staco_me_qoverp;
   vector<float>   *mu_staco_ie_d0;
   vector<float>   *mu_staco_ie_z0;
   vector<float>   *mu_staco_ie_phi;
   vector<float>   *mu_staco_ie_theta;
   vector<float>   *mu_staco_ie_qoverp;
   vector<int>     *mu_staco_nOutliersOnTrack;
   vector<int>     *mu_staco_nBLHits;
   vector<int>     *mu_staco_nPixHits;
   vector<int>     *mu_staco_nSCTHits;
   vector<int>     *mu_staco_nTRTHits;
   vector<int>     *mu_staco_nTRTHighTHits;
   vector<int>     *mu_staco_nBLSharedHits;
   vector<int>     *mu_staco_nPixSharedHits;
   vector<int>     *mu_staco_nPixHoles;
   vector<int>     *mu_staco_nSCTSharedHits;
   vector<int>     *mu_staco_nSCTHoles;
   vector<int>     *mu_staco_nTRTOutliers;
   vector<int>     *mu_staco_nTRTHighTOutliers;
   vector<int>     *mu_staco_nGangedPixels;
   vector<int>     *mu_staco_nPixelDeadSensors;
   vector<int>     *mu_staco_nSCTDeadSensors;
   vector<int>     *mu_staco_nTRTDeadStraws;
   vector<int>     *mu_staco_expectBLayerHit;
   vector<int>     *mu_staco_nMDTHits;
   vector<int>     *mu_staco_nMDTHoles;
   vector<int>     *mu_staco_nCSCEtaHits;
   vector<int>     *mu_staco_nCSCEtaHoles;
   vector<int>     *mu_staco_nCSCPhiHits;
   vector<int>     *mu_staco_nCSCPhiHoles;
   vector<int>     *mu_staco_nRPCEtaHits;
   vector<int>     *mu_staco_nRPCEtaHoles;
   vector<int>     *mu_staco_nRPCPhiHits;
   vector<int>     *mu_staco_nRPCPhiHoles;
   vector<int>     *mu_staco_nTGCEtaHits;
   vector<int>     *mu_staco_nTGCEtaHoles;
   vector<int>     *mu_staco_nTGCPhiHits;
   vector<int>     *mu_staco_nTGCPhiHoles;
   vector<int>     *mu_staco_nMDTBIHits;
   vector<int>     *mu_staco_nMDTBMHits;
   vector<int>     *mu_staco_nMDTBOHits;
   vector<int>     *mu_staco_nMDTBEEHits;
   vector<int>     *mu_staco_nMDTBIS78Hits;
   vector<int>     *mu_staco_nMDTEIHits;
   vector<int>     *mu_staco_nMDTEMHits;
   vector<int>     *mu_staco_nMDTEOHits;
   vector<int>     *mu_staco_nMDTEEHits;
   vector<int>     *mu_staco_nRPCLayer1EtaHits;
   vector<int>     *mu_staco_nRPCLayer2EtaHits;
   vector<int>     *mu_staco_nRPCLayer3EtaHits;
   vector<int>     *mu_staco_nRPCLayer1PhiHits;
   vector<int>     *mu_staco_nRPCLayer2PhiHits;
   vector<int>     *mu_staco_nRPCLayer3PhiHits;
   vector<int>     *mu_staco_nTGCLayer1EtaHits;
   vector<int>     *mu_staco_nTGCLayer2EtaHits;
   vector<int>     *mu_staco_nTGCLayer3EtaHits;
   vector<int>     *mu_staco_nTGCLayer4EtaHits;
   vector<int>     *mu_staco_nTGCLayer1PhiHits;
   vector<int>     *mu_staco_nTGCLayer2PhiHits;
   vector<int>     *mu_staco_nTGCLayer3PhiHits;
   vector<int>     *mu_staco_nTGCLayer4PhiHits;
   vector<int>     *mu_staco_barrelSectors;
   vector<int>     *mu_staco_endcapSectors;
   vector<float>   *mu_staco_trackd0;
   vector<float>   *mu_staco_trackz0;
   vector<float>   *mu_staco_trackphi;
   vector<float>   *mu_staco_tracktheta;
   vector<float>   *mu_staco_trackqoverp;
   vector<float>   *mu_staco_trackcov_d0;
   vector<float>   *mu_staco_trackcov_z0;
   vector<float>   *mu_staco_trackcov_phi;
   vector<float>   *mu_staco_trackcov_theta;
   vector<float>   *mu_staco_trackcov_qoverp;
   vector<float>   *mu_staco_trackcov_d0_z0;
   vector<float>   *mu_staco_trackcov_d0_phi;
   vector<float>   *mu_staco_trackcov_d0_theta;
   vector<float>   *mu_staco_trackcov_d0_qoverp;
   vector<float>   *mu_staco_trackcov_z0_phi;
   vector<float>   *mu_staco_trackcov_z0_theta;
   vector<float>   *mu_staco_trackcov_z0_qoverp;
   vector<float>   *mu_staco_trackcov_phi_theta;
   vector<float>   *mu_staco_trackcov_phi_qoverp;
   vector<float>   *mu_staco_trackcov_theta_qoverp;
   vector<float>   *mu_staco_trackfitchi2;
   vector<int>     *mu_staco_trackfitndof;
   vector<int>     *mu_staco_hastrack;
   vector<float>   *mu_staco_truth_dr;
   vector<int>     *mu_staco_truth_matched;
   vector<float>   *mu_staco_EFCB_dr;
   vector<int>     *mu_staco_EFCB_n;
   vector<vector<int> > *mu_staco_EFCB_MuonType;
   vector<vector<float> > *mu_staco_EFCB_pt;
   vector<vector<float> > *mu_staco_EFCB_eta;
   vector<vector<float> > *mu_staco_EFCB_phi;
   vector<vector<int> > *mu_staco_EFCB_hasCB;
   vector<int>     *mu_staco_EFCB_matched;
   vector<float>   *mu_staco_EFMG_dr;
   vector<int>     *mu_staco_EFMG_n;
   vector<vector<int> > *mu_staco_EFMG_MuonType;
   vector<vector<float> > *mu_staco_EFMG_pt;
   vector<vector<float> > *mu_staco_EFMG_eta;
   vector<vector<float> > *mu_staco_EFMG_phi;
   vector<vector<int> > *mu_staco_EFMG_hasMG;
   vector<int>     *mu_staco_EFMG_matched;
   vector<float>   *mu_staco_EFME_dr;
   vector<int>     *mu_staco_EFME_n;
   vector<vector<int> > *mu_staco_EFME_MuonType;
   vector<vector<float> > *mu_staco_EFME_pt;
   vector<vector<float> > *mu_staco_EFME_eta;
   vector<vector<float> > *mu_staco_EFME_phi;
   vector<vector<int> > *mu_staco_EFME_hasME;
   vector<int>     *mu_staco_EFME_matched;
   vector<float>   *mu_staco_L2CB_dr;
   vector<float>   *mu_staco_L2CB_pt;
   vector<float>   *mu_staco_L2CB_eta;
   vector<float>   *mu_staco_L2CB_phi;
   vector<float>   *mu_staco_L2CB_id_pt;
   vector<float>   *mu_staco_L2CB_ms_pt;
   vector<int>     *mu_staco_L2CB_nPixHits;
   vector<int>     *mu_staco_L2CB_nSCTHits;
   vector<int>     *mu_staco_L2CB_nTRTHits;
   vector<int>     *mu_staco_L2CB_nTRTHighTHits;
   vector<int>     *mu_staco_L2CB_matched;
   vector<float>   *mu_staco_L1_dr;
   vector<float>   *mu_staco_L1_pt;
   vector<float>   *mu_staco_L1_eta;
   vector<float>   *mu_staco_L1_phi;
   vector<short>   *mu_staco_L1_thrNumber;
   vector<short>   *mu_staco_L1_RoINumber;
   vector<short>   *mu_staco_L1_sectorAddress;
   vector<int>     *mu_staco_L1_firstCandidate;
   vector<int>     *mu_staco_L1_moreCandInRoI;
   vector<int>     *mu_staco_L1_moreCandInSector;
   vector<short>   *mu_staco_L1_source;
   vector<short>   *mu_staco_L1_hemisphere;
   vector<int>     *mu_staco_L1_matched;
   Int_t           el_HR_n;
   vector<float>   *el_HR_E;
   vector<float>   *el_HR_Et;
   vector<float>   *el_HR_pt;
   vector<float>   *el_HR_m;
   vector<float>   *el_HR_eta;
   vector<float>   *el_HR_phi;
   vector<float>   *el_HR_px;
   vector<float>   *el_HR_py;
   vector<float>   *el_HR_pz;
   vector<float>   *el_HR_charge;
   vector<int>     *el_HR_author;
   vector<unsigned int> *el_HR_isEM;
   vector<unsigned int> *el_HR_OQ;
   vector<int>     *el_HR_convFlag;
   vector<int>     *el_HR_isConv;
   vector<int>     *el_HR_nConv;
   vector<int>     *el_HR_nSingleTrackConv;
   vector<int>     *el_HR_nDoubleTrackConv;
   vector<unsigned int> *el_HR_OQRecalc;
   vector<int>     *el_HR_type;
   vector<int>     *el_HR_origin;
   vector<int>     *el_HR_typebkg;
   vector<int>     *el_HR_originbkg;
   vector<float>   *el_HR_truth_E;
   vector<float>   *el_HR_truth_pt;
   vector<float>   *el_HR_truth_eta;
   vector<float>   *el_HR_truth_phi;
   vector<int>     *el_HR_truth_type;
   vector<int>     *el_HR_truth_status;
   vector<int>     *el_HR_truth_barcode;
   vector<int>     *el_HR_truth_mothertype;
   vector<int>     *el_HR_truth_motherbarcode;
   vector<int>     *el_HR_truth_hasHardBrem;
   vector<int>     *el_HR_truth_index;
   vector<int>     *el_HR_truth_matched;
   vector<int>     *el_HR_loose;
   vector<int>     *el_HR_medium;
   vector<int>     *el_HR_mediumIso;
   vector<int>     *el_HR_tight;
   vector<int>     *el_HR_tightIso;
   vector<int>     *el_HR_goodOQ;
   vector<float>   *el_HR_Ethad;
   vector<float>   *el_HR_Ethad1;
   vector<float>   *el_HR_f1;
   vector<float>   *el_HR_f1core;
   vector<float>   *el_HR_Emins1;
   vector<float>   *el_HR_fside;
   vector<float>   *el_HR_Emax2;
   vector<float>   *el_HR_ws3;
   vector<float>   *el_HR_wstot;
   vector<float>   *el_HR_emaxs1;
   vector<float>   *el_HR_deltaEs;
   vector<float>   *el_HR_E233;
   vector<float>   *el_HR_E237;
   vector<float>   *el_HR_E277;
   vector<float>   *el_HR_weta2;
   vector<float>   *el_HR_f3;
   vector<float>   *el_HR_f3core;
   vector<float>   *el_HR_rphiallcalo;
   vector<float>   *el_HR_Etcone45;
   vector<float>   *el_HR_Etcone15;
   vector<float>   *el_HR_Etcone20;
   vector<float>   *el_HR_Etcone25;
   vector<float>   *el_HR_Etcone30;
   vector<float>   *el_HR_Etcone35;
   vector<float>   *el_HR_Etcone40;
   vector<float>   *el_HR_ptcone20;
   vector<float>   *el_HR_ptcone30;
   vector<float>   *el_HR_ptcone40;
   vector<float>   *el_HR_nucone20;
   vector<float>   *el_HR_nucone30;
   vector<float>   *el_HR_nucone40;
   vector<float>   *el_HR_convanglematch;
   vector<float>   *el_HR_convtrackmatch;
   vector<int>     *el_HR_hasconv;
   vector<float>   *el_HR_convvtxx;
   vector<float>   *el_HR_convvtxy;
   vector<float>   *el_HR_convvtxz;
   vector<float>   *el_HR_Rconv;
   vector<float>   *el_HR_zconv;
   vector<float>   *el_HR_convvtxchi2;
   vector<float>   *el_HR_pt1conv;
   vector<int>     *el_HR_convtrk1nBLHits;
   vector<int>     *el_HR_convtrk1nPixHits;
   vector<int>     *el_HR_convtrk1nSCTHits;
   vector<int>     *el_HR_convtrk1nTRTHits;
   vector<float>   *el_HR_pt2conv;
   vector<int>     *el_HR_convtrk2nBLHits;
   vector<int>     *el_HR_convtrk2nPixHits;
   vector<int>     *el_HR_convtrk2nSCTHits;
   vector<int>     *el_HR_convtrk2nTRTHits;
   vector<float>   *el_HR_ptconv;
   vector<float>   *el_HR_pzconv;
   vector<float>   *el_HR_pos7;
   vector<float>   *el_HR_etacorrmag;
   vector<float>   *el_HR_deltaeta1;
   vector<float>   *el_HR_deltaeta2;
   vector<float>   *el_HR_deltaphi2;
   vector<float>   *el_HR_deltaphiRescaled;
   vector<float>   *el_HR_deltaPhiRot;
   vector<float>   *el_HR_expectHitInBLayer;
   vector<float>   *el_HR_trackd0_physics;
   vector<float>   *el_HR_reta;
   vector<float>   *el_HR_rphi;
   vector<int>     *el_HR_refittedTrack_n;
   vector<float>   *el_HR_firstEdens;
   vector<float>   *el_HR_cellmaxfrac;
   vector<float>   *el_HR_longitudinal;
   vector<float>   *el_HR_secondlambda;
   vector<float>   *el_HR_lateral;
   vector<float>   *el_HR_secondR;
   vector<float>   *el_HR_centerlambda;
   vector<float>   *el_HR_trackd0;
   vector<float>   *el_HR_trackz0;
   vector<float>   *el_HR_trackphi;
   vector<float>   *el_HR_tracktheta;
   vector<float>   *el_HR_trackqoverp;
   vector<float>   *el_HR_trackpt;
   vector<float>   *el_HR_tracketa;
   vector<int>     *el_HR_nBLHits;
   vector<int>     *el_HR_nPixHits;
   vector<int>     *el_HR_nSCTHits;
   vector<int>     *el_HR_nTRTHits;
   vector<int>     *el_HR_nPixHoles;
   vector<int>     *el_HR_nSCTHoles;
   vector<int>     *el_HR_nBLSharedHits;
   vector<int>     *el_HR_nPixSharedHits;
   vector<int>     *el_HR_nSCTSharedHits;
   vector<int>     *el_HR_nTRTHighTHits;
   vector<int>     *el_HR_nTRTOutliers;
   vector<int>     *el_HR_nTRTHighTOutliers;
   vector<int>     *el_HR_nSiHits;
   vector<float>   *el_HR_TRTHighTHitsRatio;
   vector<float>   *el_HR_TRTHighTHitsRatioOutliers;
   vector<float>   *el_HR_pixeldEdx;
   vector<float>   *el_HR_eProbabilityComb;
   vector<float>   *el_HR_eProbabilityHT;
   vector<float>   *el_HR_eProbabilityToT;
   vector<float>   *el_HR_eProbabilityBrem;
   vector<int>     *el_HR_hastrack;
   vector<float>   *el_HR_deltaEmax2;
   vector<float>   *el_HR_calibHitsShowerDepth;
   vector<float>   *el_HR_trackd0beam;
   vector<float>   *el_HR_tracksigd0beam;
   vector<float>   *el_HR_trackd0pv;
   vector<float>   *el_HR_tracksigd0pv;
   vector<float>   *el_HR_trackz0pv;
   vector<float>   *el_HR_tracksigz0pv;
   vector<float>   *el_HR_trackd0pvunbiased;
   vector<float>   *el_HR_tracksigd0pvunbiased;
   vector<float>   *el_HR_trackz0pvunbiased;
   vector<float>   *el_HR_tracksigz0pvunbiased;
   vector<unsigned int> *el_HR_isIso;
   vector<float>   *el_HR_mvaptcone20;
   vector<float>   *el_HR_mvaptcone30;
   vector<float>   *el_HR_mvaptcone40;
   vector<float>   *el_HR_EF_dr;
   vector<float>   *el_HR_L2_dr;
   vector<float>   *el_HR_L1_dr;
   Int_t           mu_HR_n;
   vector<float>   *mu_HR_E;
   vector<float>   *mu_HR_pt;
   vector<float>   *mu_HR_m;
   vector<float>   *mu_HR_eta;
   vector<float>   *mu_HR_phi;
   vector<float>   *mu_HR_px;
   vector<float>   *mu_HR_py;
   vector<float>   *mu_HR_pz;
   vector<float>   *mu_HR_charge;
   vector<unsigned short> *mu_HR_allauthor;
   vector<int>     *mu_HR_author;
   vector<float>   *mu_HR_beta;
   vector<float>   *mu_HR_isMuonLikelihood;
   vector<float>   *mu_HR_matchchi2;
   vector<int>     *mu_HR_matchndof;
   vector<float>   *mu_HR_etcone20;
   vector<float>   *mu_HR_etcone30;
   vector<float>   *mu_HR_etcone40;
   vector<float>   *mu_HR_nucone20;
   vector<float>   *mu_HR_nucone30;
   vector<float>   *mu_HR_nucone40;
   vector<float>   *mu_HR_ptcone20;
   vector<float>   *mu_HR_ptcone30;
   vector<float>   *mu_HR_ptcone40;
   vector<float>   *mu_HR_energyLossPar;
   vector<float>   *mu_HR_energyLossErr;
   vector<float>   *mu_HR_etCore;
   vector<float>   *mu_HR_energyLossType;
   vector<unsigned short> *mu_HR_caloMuonIdTag;
   vector<double>  *mu_HR_caloLRLikelihood;
   vector<int>     *mu_HR_bestMatch;
   vector<int>     *mu_HR_isStandAloneMuon;
   vector<int>     *mu_HR_isCombinedMuon;
   vector<int>     *mu_HR_isLowPtReconstructedMuon;
   vector<int>     *mu_HR_loose;
   vector<int>     *mu_HR_medium;
   vector<int>     *mu_HR_tight;
   vector<float>   *mu_HR_d0_exPV;
   vector<float>   *mu_HR_z0_exPV;
   vector<float>   *mu_HR_phi_exPV;
   vector<float>   *mu_HR_theta_exPV;
   vector<float>   *mu_HR_qoverp_exPV;
   vector<float>   *mu_HR_cb_d0_exPV;
   vector<float>   *mu_HR_cb_z0_exPV;
   vector<float>   *mu_HR_cb_phi_exPV;
   vector<float>   *mu_HR_cb_theta_exPV;
   vector<float>   *mu_HR_cb_qoverp_exPV;
   vector<float>   *mu_HR_id_d0_exPV;
   vector<float>   *mu_HR_id_z0_exPV;
   vector<float>   *mu_HR_id_phi_exPV;
   vector<float>   *mu_HR_id_theta_exPV;
   vector<float>   *mu_HR_id_qoverp_exPV;
   vector<float>   *mu_HR_me_d0_exPV;
   vector<float>   *mu_HR_me_z0_exPV;
   vector<float>   *mu_HR_me_phi_exPV;
   vector<float>   *mu_HR_me_theta_exPV;
   vector<float>   *mu_HR_me_qoverp_exPV;
   vector<float>   *mu_HR_ie_d0_exPV;
   vector<float>   *mu_HR_ie_z0_exPV;
   vector<float>   *mu_HR_ie_phi_exPV;
   vector<float>   *mu_HR_ie_theta_exPV;
   vector<float>   *mu_HR_ie_qoverp_exPV;
   vector<vector<int> > *mu_HR_SpaceTime_detID;
   vector<vector<float> > *mu_HR_SpaceTime_t;
   vector<vector<float> > *mu_HR_SpaceTime_tError;
   vector<vector<float> > *mu_HR_SpaceTime_weight;
   vector<vector<float> > *mu_HR_SpaceTime_x;
   vector<vector<float> > *mu_HR_SpaceTime_y;
   vector<vector<float> > *mu_HR_SpaceTime_z;
   vector<vector<float> > *mu_HR_SpaceTime_t_Tile;
   vector<vector<float> > *mu_HR_SpaceTime_tError_Tile;
   vector<vector<float> > *mu_HR_SpaceTime_weight_Tile;
   vector<vector<float> > *mu_HR_SpaceTime_x_Tile;
   vector<vector<float> > *mu_HR_SpaceTime_y_Tile;
   vector<vector<float> > *mu_HR_SpaceTime_z_Tile;
   vector<vector<float> > *mu_HR_SpaceTime_t_TRT;
   vector<vector<float> > *mu_HR_SpaceTime_tError_TRT;
   vector<vector<float> > *mu_HR_SpaceTime_weight_TRT;
   vector<vector<float> > *mu_HR_SpaceTime_x_TRT;
   vector<vector<float> > *mu_HR_SpaceTime_y_TRT;
   vector<vector<float> > *mu_HR_SpaceTime_z_TRT;
   vector<vector<float> > *mu_HR_SpaceTime_t_MDT;
   vector<vector<float> > *mu_HR_SpaceTime_tError_MDT;
   vector<vector<float> > *mu_HR_SpaceTime_weight_MDT;
   vector<vector<float> > *mu_HR_SpaceTime_x_MDT;
   vector<vector<float> > *mu_HR_SpaceTime_y_MDT;
   vector<vector<float> > *mu_HR_SpaceTime_z_MDT;
   vector<float>   *mu_HR_TileCellEnergyLayer1;
   vector<float>   *mu_HR_TileTimeLayer1;
   vector<float>   *mu_HR_TileCellRmsNoiseLayer1;
   vector<float>   *mu_HR_TileCellSignLayer1;
   vector<float>   *mu_HR_TileCellEnergyLayer2;
   vector<float>   *mu_HR_TileTimeLayer2;
   vector<float>   *mu_HR_TileCellRmsNoiseLayer2;
   vector<float>   *mu_HR_TileCellSignLayer2;
   vector<float>   *mu_HR_TileCellEnergyLayer3;
   vector<float>   *mu_HR_TileTimeLayer3;
   vector<float>   *mu_HR_TileCellRmsNoiseLayer3;
   vector<float>   *mu_HR_TileCellSignLayer3;
   vector<float>   *mu_HR_MSTrkT0_1;
   vector<float>   *mu_HR_MSTrkT0_2;
   vector<float>   *mu_HR_MSTrkT0_3;
   vector<float>   *mu_HR_cov_d0_exPV;
   vector<float>   *mu_HR_cov_z0_exPV;
   vector<float>   *mu_HR_cov_phi_exPV;
   vector<float>   *mu_HR_cov_theta_exPV;
   vector<float>   *mu_HR_cov_qoverp_exPV;
   vector<float>   *mu_HR_cov_d0_z0_exPV;
   vector<float>   *mu_HR_cov_d0_phi_exPV;
   vector<float>   *mu_HR_cov_d0_theta_exPV;
   vector<float>   *mu_HR_cov_d0_qoverp_exPV;
   vector<float>   *mu_HR_cov_z0_phi_exPV;
   vector<float>   *mu_HR_cov_z0_theta_exPV;
   vector<float>   *mu_HR_cov_z0_qoverp_exPV;
   vector<float>   *mu_HR_cov_phi_theta_exPV;
   vector<float>   *mu_HR_cov_phi_qoverp_exPV;
   vector<float>   *mu_HR_cov_theta_qoverp_exPV;
   vector<float>   *mu_HR_ms_d0;
   vector<float>   *mu_HR_ms_z0;
   vector<float>   *mu_HR_ms_phi;
   vector<float>   *mu_HR_ms_theta;
   vector<float>   *mu_HR_ms_qoverp;
   vector<float>   *mu_HR_id_d0;
   vector<float>   *mu_HR_id_z0;
   vector<float>   *mu_HR_id_phi;
   vector<float>   *mu_HR_id_theta;
   vector<float>   *mu_HR_id_qoverp;
   vector<float>   *mu_HR_me_d0;
   vector<float>   *mu_HR_me_z0;
   vector<float>   *mu_HR_me_phi;
   vector<float>   *mu_HR_me_theta;
   vector<float>   *mu_HR_me_qoverp;
   vector<float>   *mu_HR_ie_d0;
   vector<float>   *mu_HR_ie_z0;
   vector<float>   *mu_HR_ie_phi;
   vector<float>   *mu_HR_ie_theta;
   vector<float>   *mu_HR_ie_qoverp;
   vector<float>   *mu_HR_trackd0;
   vector<float>   *mu_HR_trackz0;
   vector<float>   *mu_HR_trackphi;
   vector<float>   *mu_HR_tracktheta;
   vector<float>   *mu_HR_trackqoverp;
   vector<float>   *mu_HR_trackcov_d0;
   vector<float>   *mu_HR_trackcov_z0;
   vector<float>   *mu_HR_trackcov_phi;
   vector<float>   *mu_HR_trackcov_theta;
   vector<float>   *mu_HR_trackcov_qoverp;
   vector<int>     *mu_HR_hastrack;
   vector<float>   *mu_HR_truth_dr;
   vector<float>   *mu_HR_truth_E;
   vector<float>   *mu_HR_truth_pt;
   vector<float>   *mu_HR_truth_eta;
   vector<float>   *mu_HR_truth_phi;
   vector<int>     *mu_HR_truth_type;
   vector<int>     *mu_HR_truth_status;
   vector<int>     *mu_HR_truth_barcode;
   vector<int>     *mu_HR_truth_mothertype;
   vector<int>     *mu_HR_truth_motherbarcode;
   vector<int>     *mu_HR_truth_matched;
   vector<float>   *mu_HR_EFCB_dr;
   vector<int>     *mu_HR_EFCB_n;
   vector<vector<int> > *mu_HR_EFCB_MuonType;
   vector<vector<float> > *mu_HR_EFCB_pt;
   vector<vector<float> > *mu_HR_EFCB_eta;
   vector<vector<float> > *mu_HR_EFCB_phi;
   vector<vector<int> > *mu_HR_EFCB_hasCB;
   vector<int>     *mu_HR_EFCB_matched;
   vector<float>   *mu_HR_EFMG_dr;
   vector<int>     *mu_HR_EFMG_n;
   vector<vector<int> > *mu_HR_EFMG_MuonType;
   vector<vector<float> > *mu_HR_EFMG_pt;
   vector<vector<float> > *mu_HR_EFMG_eta;
   vector<vector<float> > *mu_HR_EFMG_phi;
   vector<vector<int> > *mu_HR_EFMG_hasMG;
   vector<int>     *mu_HR_EFMG_matched;
   vector<float>   *mu_HR_EFME_dr;
   vector<int>     *mu_HR_EFME_n;
   vector<vector<int> > *mu_HR_EFME_MuonType;
   vector<vector<float> > *mu_HR_EFME_pt;
   vector<vector<float> > *mu_HR_EFME_eta;
   vector<vector<float> > *mu_HR_EFME_phi;
   vector<vector<int> > *mu_HR_EFME_hasME;
   vector<int>     *mu_HR_EFME_matched;
   vector<float>   *mu_HR_L2CB_dr;
   vector<float>   *mu_HR_L2CB_pt;
   vector<float>   *mu_HR_L2CB_eta;
   vector<float>   *mu_HR_L2CB_phi;
   vector<float>   *mu_HR_L2CB_id_pt;
   vector<float>   *mu_HR_L2CB_ms_pt;
   vector<int>     *mu_HR_L2CB_matched;
   vector<float>   *mu_HR_L1_dr;
   vector<float>   *mu_HR_L1_pt;
   vector<float>   *mu_HR_L1_eta;
   vector<float>   *mu_HR_L1_phi;
   vector<int>     *mu_HR_L1_matched;
   Float_t         RoughRecoil_etx;
   Float_t         RoughRecoil_ety;
   Float_t         RoughRecoil_phi;
   Float_t         RoughRecoil_et;
   Float_t         RoughRecoil_sumet;
   Float_t         ueCorrection_etx;
   Float_t         ueCorrection_ety;
   Float_t         ueCorrection_phi;
   Float_t         ueCorrection_et;
   Float_t         ueCorrection_sumet;
   Int_t           jet_AntiKt4TopoEM_n;
   vector<float>   *jet_AntiKt4TopoEM_E;
   vector<float>   *jet_AntiKt4TopoEM_pt;
   vector<float>   *jet_AntiKt4TopoEM_m;
   vector<float>   *jet_AntiKt4TopoEM_eta;
   vector<float>   *jet_AntiKt4TopoEM_phi;
   vector<float>   *jet_AntiKt4TopoEM_n90;
   vector<float>   *jet_AntiKt4TopoEM_Timing;
   vector<float>   *jet_AntiKt4TopoEM_LArQuality;
   vector<float>   *jet_AntiKt4TopoEM_sumPtTrk;
   vector<float>   *jet_AntiKt4TopoEM_HECQuality;
   vector<float>   *jet_AntiKt4TopoEM_BCH_CORR_CELL;
   vector<float>   *jet_AntiKt4TopoEM_BCH_CORR_DOTX;
   vector<int>     *jet_AntiKt4TopoEM_SamplingMax;
   vector<double>  *jet_AntiKt4TopoEM_fracSamplingMax;
   vector<float>   *jet_AntiKt4TopoEM_hecf;
   vector<float>   *jet_AntiKt4TopoEM_tgap3f;
   vector<int>     *jet_AntiKt4TopoEM_isBadLoose;
   vector<int>     *jet_AntiKt4TopoEM_isBadMedium;
   vector<int>     *jet_AntiKt4TopoEM_isBadTight;
   vector<float>   *jet_AntiKt4TopoEM_emfrac;
   vector<float>   *jet_AntiKt4TopoEM_EMJES;
   vector<float>   *jet_AntiKt4TopoEM_GCWJES;
   vector<float>   *jet_AntiKt4TopoEM_emscale_E;
   vector<float>   *jet_AntiKt4TopoEM_emscale_pt;
   vector<float>   *jet_AntiKt4TopoEM_emscale_m;
   vector<float>   *jet_AntiKt4TopoEM_emscale_eta;
   vector<float>   *jet_AntiKt4TopoEM_emscale_phi;
   Int_t           jet_AntiKt6TopoEM_n;
   vector<float>   *jet_AntiKt6TopoEM_E;
   vector<float>   *jet_AntiKt6TopoEM_pt;
   vector<float>   *jet_AntiKt6TopoEM_m;
   vector<float>   *jet_AntiKt6TopoEM_eta;
   vector<float>   *jet_AntiKt6TopoEM_phi;
   vector<float>   *jet_AntiKt6TopoEM_n90;
   vector<float>   *jet_AntiKt6TopoEM_Timing;
   vector<float>   *jet_AntiKt6TopoEM_LArQuality;
   vector<float>   *jet_AntiKt6TopoEM_sumPtTrk;
   vector<float>   *jet_AntiKt6TopoEM_HECQuality;
   vector<float>   *jet_AntiKt6TopoEM_BCH_CORR_CELL;
   vector<float>   *jet_AntiKt6TopoEM_BCH_CORR_DOTX;
   vector<int>     *jet_AntiKt6TopoEM_SamplingMax;
   vector<double>  *jet_AntiKt6TopoEM_fracSamplingMax;
   vector<float>   *jet_AntiKt6TopoEM_hecf;
   vector<float>   *jet_AntiKt6TopoEM_tgap3f;
   vector<int>     *jet_AntiKt6TopoEM_isBadLoose;
   vector<int>     *jet_AntiKt6TopoEM_isBadMedium;
   vector<int>     *jet_AntiKt6TopoEM_isBadTight;
   vector<float>   *jet_AntiKt6TopoEM_emfrac;
   vector<float>   *jet_AntiKt6TopoEM_EMJES;
   vector<float>   *jet_AntiKt6TopoEM_GCWJES;
   vector<float>   *jet_AntiKt6TopoEM_emscale_E;
   vector<float>   *jet_AntiKt6TopoEM_emscale_pt;
   vector<float>   *jet_AntiKt6TopoEM_emscale_m;
   vector<float>   *jet_AntiKt6TopoEM_emscale_eta;
   vector<float>   *jet_AntiKt6TopoEM_emscale_phi;
   Int_t           jet_AntiKt6LCTopo_n;
   vector<float>   *jet_AntiKt6LCTopo_E;
   vector<float>   *jet_AntiKt6LCTopo_pt;
   vector<float>   *jet_AntiKt6LCTopo_m;
   vector<float>   *jet_AntiKt6LCTopo_eta;
   vector<float>   *jet_AntiKt6LCTopo_phi;
   vector<float>   *jet_AntiKt6LCTopo_n90;
   vector<float>   *jet_AntiKt6LCTopo_Timing;
   vector<float>   *jet_AntiKt6LCTopo_LArQuality;
   vector<float>   *jet_AntiKt6LCTopo_sumPtTrk;
   vector<float>   *jet_AntiKt6LCTopo_HECQuality;
   vector<float>   *jet_AntiKt6LCTopo_BCH_CORR_CELL;
   vector<float>   *jet_AntiKt6LCTopo_BCH_CORR_DOTX;
   vector<int>     *jet_AntiKt6LCTopo_SamplingMax;
   vector<double>  *jet_AntiKt6LCTopo_fracSamplingMax;
   vector<float>   *jet_AntiKt6LCTopo_hecf;
   vector<float>   *jet_AntiKt6LCTopo_tgap3f;
   vector<int>     *jet_AntiKt6LCTopo_isBadLoose;
   vector<int>     *jet_AntiKt6LCTopo_isBadMedium;
   vector<int>     *jet_AntiKt6LCTopo_isBadTight;
   vector<float>   *jet_AntiKt6LCTopo_emfrac;
   vector<float>   *jet_AntiKt6LCTopo_EMJES;
   vector<float>   *jet_AntiKt6LCTopo_GCWJES;
   vector<float>   *jet_AntiKt6LCTopo_emscale_E;
   vector<float>   *jet_AntiKt6LCTopo_emscale_pt;
   vector<float>   *jet_AntiKt6LCTopo_emscale_m;
   vector<float>   *jet_AntiKt6LCTopo_emscale_eta;
   vector<float>   *jet_AntiKt6LCTopo_emscale_phi;
   Float_t         MET_RefFinal_etx;
   Float_t         MET_RefFinal_ety;
   Float_t         MET_RefFinal_phi;
   Float_t         MET_RefFinal_et;
   Float_t         MET_RefFinal_sumet;
   Float_t         MET_RefFinal_etx_CentralReg;
   Float_t         MET_RefFinal_ety_CentralReg;
   Float_t         MET_RefFinal_sumet_CentralReg;
   Float_t         MET_RefFinal_phi_CentralReg;
   Float_t         MET_RefFinal_etx_EndcapRegion;
   Float_t         MET_RefFinal_ety_EndcapRegion;
   Float_t         MET_RefFinal_sumet_EndcapRegion;
   Float_t         MET_RefFinal_phi_EndcapRegion;
   Float_t         MET_RefFinal_etx_ForwardReg;
   Float_t         MET_RefFinal_ety_ForwardReg;
   Float_t         MET_RefFinal_sumet_ForwardReg;
   Float_t         MET_RefFinal_phi_ForwardReg;
   Float_t         MET_Cryo_etx;
   Float_t         MET_Cryo_ety;
   Float_t         MET_Cryo_phi;
   Float_t         MET_Cryo_et;
   Float_t         MET_Cryo_sumet;
   Float_t         MET_Cryo_etx_CentralReg;
   Float_t         MET_Cryo_ety_CentralReg;
   Float_t         MET_Cryo_sumet_CentralReg;
   Float_t         MET_Cryo_phi_CentralReg;
   Float_t         MET_Cryo_etx_EndcapRegion;
   Float_t         MET_Cryo_ety_EndcapRegion;
   Float_t         MET_Cryo_sumet_EndcapRegion;
   Float_t         MET_Cryo_phi_EndcapRegion;
   Float_t         MET_Cryo_etx_ForwardReg;
   Float_t         MET_Cryo_ety_ForwardReg;
   Float_t         MET_Cryo_sumet_ForwardReg;
   Float_t         MET_Cryo_phi_ForwardReg;
   Float_t         MET_RefEle_etx;
   Float_t         MET_RefEle_ety;
   Float_t         MET_RefEle_phi;
   Float_t         MET_RefEle_et;
   Float_t         MET_RefEle_sumet;
   Float_t         MET_RefEle_etx_CentralReg;
   Float_t         MET_RefEle_ety_CentralReg;
   Float_t         MET_RefEle_sumet_CentralReg;
   Float_t         MET_RefEle_phi_CentralReg;
   Float_t         MET_RefEle_etx_EndcapRegion;
   Float_t         MET_RefEle_ety_EndcapRegion;
   Float_t         MET_RefEle_sumet_EndcapRegion;
   Float_t         MET_RefEle_phi_EndcapRegion;
   Float_t         MET_RefEle_etx_ForwardReg;
   Float_t         MET_RefEle_ety_ForwardReg;
   Float_t         MET_RefEle_sumet_ForwardReg;
   Float_t         MET_RefEle_phi_ForwardReg;
   Float_t         MET_RefJet_etx;
   Float_t         MET_RefJet_ety;
   Float_t         MET_RefJet_phi;
   Float_t         MET_RefJet_et;
   Float_t         MET_RefJet_sumet;
   Float_t         MET_RefJet_etx_CentralReg;
   Float_t         MET_RefJet_ety_CentralReg;
   Float_t         MET_RefJet_sumet_CentralReg;
   Float_t         MET_RefJet_phi_CentralReg;
   Float_t         MET_RefJet_etx_EndcapRegion;
   Float_t         MET_RefJet_ety_EndcapRegion;
   Float_t         MET_RefJet_sumet_EndcapRegion;
   Float_t         MET_RefJet_phi_EndcapRegion;
   Float_t         MET_RefJet_etx_ForwardReg;
   Float_t         MET_RefJet_ety_ForwardReg;
   Float_t         MET_RefJet_sumet_ForwardReg;
   Float_t         MET_RefJet_phi_ForwardReg;
   Float_t         MET_SoftJets_etx;
   Float_t         MET_SoftJets_ety;
   Float_t         MET_SoftJets_phi;
   Float_t         MET_SoftJets_et;
   Float_t         MET_SoftJets_sumet;
   Float_t         MET_SoftJets_etx_CentralReg;
   Float_t         MET_SoftJets_ety_CentralReg;
   Float_t         MET_SoftJets_sumet_CentralReg;
   Float_t         MET_SoftJets_phi_CentralReg;
   Float_t         MET_SoftJets_etx_EndcapRegion;
   Float_t         MET_SoftJets_ety_EndcapRegion;
   Float_t         MET_SoftJets_sumet_EndcapRegion;
   Float_t         MET_SoftJets_phi_EndcapRegion;
   Float_t         MET_SoftJets_etx_ForwardReg;
   Float_t         MET_SoftJets_ety_ForwardReg;
   Float_t         MET_SoftJets_sumet_ForwardReg;
   Float_t         MET_SoftJets_phi_ForwardReg;
   Float_t         MET_RefMuon_etx;
   Float_t         MET_RefMuon_ety;
   Float_t         MET_RefMuon_phi;
   Float_t         MET_RefMuon_et;
   Float_t         MET_RefMuon_sumet;
   Float_t         MET_RefMuon_etx_CentralReg;
   Float_t         MET_RefMuon_ety_CentralReg;
   Float_t         MET_RefMuon_sumet_CentralReg;
   Float_t         MET_RefMuon_phi_CentralReg;
   Float_t         MET_RefMuon_etx_EndcapRegion;
   Float_t         MET_RefMuon_ety_EndcapRegion;
   Float_t         MET_RefMuon_sumet_EndcapRegion;
   Float_t         MET_RefMuon_phi_EndcapRegion;
   Float_t         MET_RefMuon_etx_ForwardReg;
   Float_t         MET_RefMuon_ety_ForwardReg;
   Float_t         MET_RefMuon_sumet_ForwardReg;
   Float_t         MET_RefMuon_phi_ForwardReg;
   Float_t         MET_RefMuon_Staco_etx;
   Float_t         MET_RefMuon_Staco_ety;
   Float_t         MET_RefMuon_Staco_phi;
   Float_t         MET_RefMuon_Staco_et;
   Float_t         MET_RefMuon_Staco_sumet;
   Float_t         MET_RefMuon_Staco_etx_CentralReg;
   Float_t         MET_RefMuon_Staco_ety_CentralReg;
   Float_t         MET_RefMuon_Staco_sumet_CentralReg;
   Float_t         MET_RefMuon_Staco_phi_CentralReg;
   Float_t         MET_RefMuon_Staco_etx_EndcapRegion;
   Float_t         MET_RefMuon_Staco_ety_EndcapRegion;
   Float_t         MET_RefMuon_Staco_sumet_EndcapRegion;
   Float_t         MET_RefMuon_Staco_phi_EndcapRegion;
   Float_t         MET_RefMuon_Staco_etx_ForwardReg;
   Float_t         MET_RefMuon_Staco_ety_ForwardReg;
   Float_t         MET_RefMuon_Staco_sumet_ForwardReg;
   Float_t         MET_RefMuon_Staco_phi_ForwardReg;
   Float_t         MET_RefMuon_Muid_etx;
   Float_t         MET_RefMuon_Muid_ety;
   Float_t         MET_RefMuon_Muid_phi;
   Float_t         MET_RefMuon_Muid_et;
   Float_t         MET_RefMuon_Muid_sumet;
   Float_t         MET_RefMuon_Muid_etx_CentralReg;
   Float_t         MET_RefMuon_Muid_ety_CentralReg;
   Float_t         MET_RefMuon_Muid_sumet_CentralReg;
   Float_t         MET_RefMuon_Muid_phi_CentralReg;
   Float_t         MET_RefMuon_Muid_etx_EndcapRegion;
   Float_t         MET_RefMuon_Muid_ety_EndcapRegion;
   Float_t         MET_RefMuon_Muid_sumet_EndcapRegion;
   Float_t         MET_RefMuon_Muid_phi_EndcapRegion;
   Float_t         MET_RefMuon_Muid_etx_ForwardReg;
   Float_t         MET_RefMuon_Muid_ety_ForwardReg;
   Float_t         MET_RefMuon_Muid_sumet_ForwardReg;
   Float_t         MET_RefMuon_Muid_phi_ForwardReg;
   Float_t         MET_RefGamma_etx;
   Float_t         MET_RefGamma_ety;
   Float_t         MET_RefGamma_phi;
   Float_t         MET_RefGamma_et;
   Float_t         MET_RefGamma_sumet;
   Float_t         MET_RefGamma_etx_CentralReg;
   Float_t         MET_RefGamma_ety_CentralReg;
   Float_t         MET_RefGamma_sumet_CentralReg;
   Float_t         MET_RefGamma_phi_CentralReg;
   Float_t         MET_RefGamma_etx_EndcapRegion;
   Float_t         MET_RefGamma_ety_EndcapRegion;
   Float_t         MET_RefGamma_sumet_EndcapRegion;
   Float_t         MET_RefGamma_phi_EndcapRegion;
   Float_t         MET_RefGamma_etx_ForwardReg;
   Float_t         MET_RefGamma_ety_ForwardReg;
   Float_t         MET_RefGamma_sumet_ForwardReg;
   Float_t         MET_RefGamma_phi_ForwardReg;
   Float_t         MET_RefTau_etx;
   Float_t         MET_RefTau_ety;
   Float_t         MET_RefTau_phi;
   Float_t         MET_RefTau_et;
   Float_t         MET_RefTau_sumet;
   Float_t         MET_RefTau_etx_CentralReg;
   Float_t         MET_RefTau_ety_CentralReg;
   Float_t         MET_RefTau_sumet_CentralReg;
   Float_t         MET_RefTau_phi_CentralReg;
   Float_t         MET_RefTau_etx_EndcapRegion;
   Float_t         MET_RefTau_ety_EndcapRegion;
   Float_t         MET_RefTau_sumet_EndcapRegion;
   Float_t         MET_RefTau_phi_EndcapRegion;
   Float_t         MET_RefTau_etx_ForwardReg;
   Float_t         MET_RefTau_ety_ForwardReg;
   Float_t         MET_RefTau_sumet_ForwardReg;
   Float_t         MET_RefTau_phi_ForwardReg;
   Float_t         MET_CellOut_etx;
   Float_t         MET_CellOut_ety;
   Float_t         MET_CellOut_phi;
   Float_t         MET_CellOut_et;
   Float_t         MET_CellOut_sumet;
   Float_t         MET_CellOut_etx_CentralReg;
   Float_t         MET_CellOut_ety_CentralReg;
   Float_t         MET_CellOut_sumet_CentralReg;
   Float_t         MET_CellOut_phi_CentralReg;
   Float_t         MET_CellOut_etx_EndcapRegion;
   Float_t         MET_CellOut_ety_EndcapRegion;
   Float_t         MET_CellOut_sumet_EndcapRegion;
   Float_t         MET_CellOut_phi_EndcapRegion;
   Float_t         MET_CellOut_etx_ForwardReg;
   Float_t         MET_CellOut_ety_ForwardReg;
   Float_t         MET_CellOut_sumet_ForwardReg;
   Float_t         MET_CellOut_phi_ForwardReg;
   Float_t         MET_Track_etx;
   Float_t         MET_Track_ety;
   Float_t         MET_Track_phi;
   Float_t         MET_Track_et;
   Float_t         MET_Track_sumet;
   Float_t         MET_Track_etx_CentralReg;
   Float_t         MET_Track_ety_CentralReg;
   Float_t         MET_Track_sumet_CentralReg;
   Float_t         MET_Track_phi_CentralReg;
   Float_t         MET_Track_etx_EndcapRegion;
   Float_t         MET_Track_ety_EndcapRegion;
   Float_t         MET_Track_sumet_EndcapRegion;
   Float_t         MET_Track_phi_EndcapRegion;
   Float_t         MET_Track_etx_ForwardReg;
   Float_t         MET_Track_ety_ForwardReg;
   Float_t         MET_Track_sumet_ForwardReg;
   Float_t         MET_Track_phi_ForwardReg;
   Float_t         MET_RefFinal_em_etx;
   Float_t         MET_RefFinal_em_ety;
   Float_t         MET_RefFinal_em_phi;
   Float_t         MET_RefFinal_em_et;
   Float_t         MET_RefFinal_em_sumet;
   Float_t         MET_RefFinal_em_etx_CentralReg;
   Float_t         MET_RefFinal_em_ety_CentralReg;
   Float_t         MET_RefFinal_em_sumet_CentralReg;
   Float_t         MET_RefFinal_em_phi_CentralReg;
   Float_t         MET_RefFinal_em_etx_EndcapRegion;
   Float_t         MET_RefFinal_em_ety_EndcapRegion;
   Float_t         MET_RefFinal_em_sumet_EndcapRegion;
   Float_t         MET_RefFinal_em_phi_EndcapRegion;
   Float_t         MET_RefFinal_em_etx_ForwardReg;
   Float_t         MET_RefFinal_em_ety_ForwardReg;
   Float_t         MET_RefFinal_em_sumet_ForwardReg;
   Float_t         MET_RefFinal_em_phi_ForwardReg;
   Float_t         MET_RefEle_em_etx;
   Float_t         MET_RefEle_em_ety;
   Float_t         MET_RefEle_em_phi;
   Float_t         MET_RefEle_em_et;
   Float_t         MET_RefEle_em_sumet;
   Float_t         MET_RefEle_em_etx_CentralReg;
   Float_t         MET_RefEle_em_ety_CentralReg;
   Float_t         MET_RefEle_em_sumet_CentralReg;
   Float_t         MET_RefEle_em_phi_CentralReg;
   Float_t         MET_RefEle_em_etx_EndcapRegion;
   Float_t         MET_RefEle_em_ety_EndcapRegion;
   Float_t         MET_RefEle_em_sumet_EndcapRegion;
   Float_t         MET_RefEle_em_phi_EndcapRegion;
   Float_t         MET_RefEle_em_etx_ForwardReg;
   Float_t         MET_RefEle_em_ety_ForwardReg;
   Float_t         MET_RefEle_em_sumet_ForwardReg;
   Float_t         MET_RefEle_em_phi_ForwardReg;
   Float_t         MET_RefJet_em_etx;
   Float_t         MET_RefJet_em_ety;
   Float_t         MET_RefJet_em_phi;
   Float_t         MET_RefJet_em_et;
   Float_t         MET_RefJet_em_sumet;
   Float_t         MET_RefJet_em_etx_CentralReg;
   Float_t         MET_RefJet_em_ety_CentralReg;
   Float_t         MET_RefJet_em_sumet_CentralReg;
   Float_t         MET_RefJet_em_phi_CentralReg;
   Float_t         MET_RefJet_em_etx_EndcapRegion;
   Float_t         MET_RefJet_em_ety_EndcapRegion;
   Float_t         MET_RefJet_em_sumet_EndcapRegion;
   Float_t         MET_RefJet_em_phi_EndcapRegion;
   Float_t         MET_RefJet_em_etx_ForwardReg;
   Float_t         MET_RefJet_em_ety_ForwardReg;
   Float_t         MET_RefJet_em_sumet_ForwardReg;
   Float_t         MET_RefJet_em_phi_ForwardReg;
   Float_t         MET_SoftJets_em_etx;
   Float_t         MET_SoftJets_em_ety;
   Float_t         MET_SoftJets_em_phi;
   Float_t         MET_SoftJets_em_et;
   Float_t         MET_SoftJets_em_sumet;
   Float_t         MET_SoftJets_em_etx_CentralReg;
   Float_t         MET_SoftJets_em_ety_CentralReg;
   Float_t         MET_SoftJets_em_sumet_CentralReg;
   Float_t         MET_SoftJets_em_phi_CentralReg;
   Float_t         MET_SoftJets_em_etx_EndcapRegion;
   Float_t         MET_SoftJets_em_ety_EndcapRegion;
   Float_t         MET_SoftJets_em_sumet_EndcapRegion;
   Float_t         MET_SoftJets_em_phi_EndcapRegion;
   Float_t         MET_SoftJets_em_etx_ForwardReg;
   Float_t         MET_SoftJets_em_ety_ForwardReg;
   Float_t         MET_SoftJets_em_sumet_ForwardReg;
   Float_t         MET_SoftJets_em_phi_ForwardReg;
   Float_t         MET_RefMuon_em_etx;
   Float_t         MET_RefMuon_em_ety;
   Float_t         MET_RefMuon_em_phi;
   Float_t         MET_RefMuon_em_et;
   Float_t         MET_RefMuon_em_sumet;
   Float_t         MET_RefMuon_em_etx_CentralReg;
   Float_t         MET_RefMuon_em_ety_CentralReg;
   Float_t         MET_RefMuon_em_sumet_CentralReg;
   Float_t         MET_RefMuon_em_phi_CentralReg;
   Float_t         MET_RefMuon_em_etx_EndcapRegion;
   Float_t         MET_RefMuon_em_ety_EndcapRegion;
   Float_t         MET_RefMuon_em_sumet_EndcapRegion;
   Float_t         MET_RefMuon_em_phi_EndcapRegion;
   Float_t         MET_RefMuon_em_etx_ForwardReg;
   Float_t         MET_RefMuon_em_ety_ForwardReg;
   Float_t         MET_RefMuon_em_sumet_ForwardReg;
   Float_t         MET_RefMuon_em_phi_ForwardReg;
   Float_t         MET_RefMuon_Track_em_etx;
   Float_t         MET_RefMuon_Track_em_ety;
   Float_t         MET_RefMuon_Track_em_phi;
   Float_t         MET_RefMuon_Track_em_et;
   Float_t         MET_RefMuon_Track_em_sumet;
   Float_t         MET_RefMuon_Track_em_etx_CentralReg;
   Float_t         MET_RefMuon_Track_em_ety_CentralReg;
   Float_t         MET_RefMuon_Track_em_sumet_CentralReg;
   Float_t         MET_RefMuon_Track_em_phi_CentralReg;
   Float_t         MET_RefMuon_Track_em_etx_EndcapRegion;
   Float_t         MET_RefMuon_Track_em_ety_EndcapRegion;
   Float_t         MET_RefMuon_Track_em_sumet_EndcapRegion;
   Float_t         MET_RefMuon_Track_em_phi_EndcapRegion;
   Float_t         MET_RefMuon_Track_em_etx_ForwardReg;
   Float_t         MET_RefMuon_Track_em_ety_ForwardReg;
   Float_t         MET_RefMuon_Track_em_sumet_ForwardReg;
   Float_t         MET_RefMuon_Track_em_phi_ForwardReg;
   Float_t         MET_RefGamma_em_etx;
   Float_t         MET_RefGamma_em_ety;
   Float_t         MET_RefGamma_em_phi;
   Float_t         MET_RefGamma_em_et;
   Float_t         MET_RefGamma_em_sumet;
   Float_t         MET_RefGamma_em_etx_CentralReg;
   Float_t         MET_RefGamma_em_ety_CentralReg;
   Float_t         MET_RefGamma_em_sumet_CentralReg;
   Float_t         MET_RefGamma_em_phi_CentralReg;
   Float_t         MET_RefGamma_em_etx_EndcapRegion;
   Float_t         MET_RefGamma_em_ety_EndcapRegion;
   Float_t         MET_RefGamma_em_sumet_EndcapRegion;
   Float_t         MET_RefGamma_em_phi_EndcapRegion;
   Float_t         MET_RefGamma_em_etx_ForwardReg;
   Float_t         MET_RefGamma_em_ety_ForwardReg;
   Float_t         MET_RefGamma_em_sumet_ForwardReg;
   Float_t         MET_RefGamma_em_phi_ForwardReg;
   Float_t         MET_RefTau_em_etx;
   Float_t         MET_RefTau_em_ety;
   Float_t         MET_RefTau_em_phi;
   Float_t         MET_RefTau_em_et;
   Float_t         MET_RefTau_em_sumet;
   Float_t         MET_RefTau_em_etx_CentralReg;
   Float_t         MET_RefTau_em_ety_CentralReg;
   Float_t         MET_RefTau_em_sumet_CentralReg;
   Float_t         MET_RefTau_em_phi_CentralReg;
   Float_t         MET_RefTau_em_etx_EndcapRegion;
   Float_t         MET_RefTau_em_ety_EndcapRegion;
   Float_t         MET_RefTau_em_sumet_EndcapRegion;
   Float_t         MET_RefTau_em_phi_EndcapRegion;
   Float_t         MET_RefTau_em_etx_ForwardReg;
   Float_t         MET_RefTau_em_ety_ForwardReg;
   Float_t         MET_RefTau_em_sumet_ForwardReg;
   Float_t         MET_RefTau_em_phi_ForwardReg;
   Float_t         MET_CellOut_em_etx;
   Float_t         MET_CellOut_em_ety;
   Float_t         MET_CellOut_em_phi;
   Float_t         MET_CellOut_em_et;
   Float_t         MET_CellOut_em_sumet;
   Float_t         MET_CellOut_em_etx_CentralReg;
   Float_t         MET_CellOut_em_ety_CentralReg;
   Float_t         MET_CellOut_em_sumet_CentralReg;
   Float_t         MET_CellOut_em_phi_CentralReg;
   Float_t         MET_CellOut_em_etx_EndcapRegion;
   Float_t         MET_CellOut_em_ety_EndcapRegion;
   Float_t         MET_CellOut_em_sumet_EndcapRegion;
   Float_t         MET_CellOut_em_phi_EndcapRegion;
   Float_t         MET_CellOut_em_etx_ForwardReg;
   Float_t         MET_CellOut_em_ety_ForwardReg;
   Float_t         MET_CellOut_em_sumet_ForwardReg;
   Float_t         MET_CellOut_em_phi_ForwardReg;
   Float_t         MET_Muon_Isol_Staco_etx;
   Float_t         MET_Muon_Isol_Staco_ety;
   Float_t         MET_Muon_Isol_Staco_phi;
   Float_t         MET_Muon_Isol_Staco_et;
   Float_t         MET_Muon_Isol_Staco_sumet;
   Float_t         MET_Muon_Isol_Staco_etx_CentralReg;
   Float_t         MET_Muon_Isol_Staco_ety_CentralReg;
   Float_t         MET_Muon_Isol_Staco_sumet_CentralReg;
   Float_t         MET_Muon_Isol_Staco_phi_CentralReg;
   Float_t         MET_Muon_Isol_Staco_etx_EndcapRegion;
   Float_t         MET_Muon_Isol_Staco_ety_EndcapRegion;
   Float_t         MET_Muon_Isol_Staco_sumet_EndcapRegion;
   Float_t         MET_Muon_Isol_Staco_phi_EndcapRegion;
   Float_t         MET_Muon_Isol_Staco_etx_ForwardReg;
   Float_t         MET_Muon_Isol_Staco_ety_ForwardReg;
   Float_t         MET_Muon_Isol_Staco_sumet_ForwardReg;
   Float_t         MET_Muon_Isol_Staco_phi_ForwardReg;
   Float_t         MET_Muon_NonIsol_Staco_etx;
   Float_t         MET_Muon_NonIsol_Staco_ety;
   Float_t         MET_Muon_NonIsol_Staco_phi;
   Float_t         MET_Muon_NonIsol_Staco_et;
   Float_t         MET_Muon_NonIsol_Staco_sumet;
   Float_t         MET_Muon_NonIsol_Staco_etx_CentralReg;
   Float_t         MET_Muon_NonIsol_Staco_ety_CentralReg;
   Float_t         MET_Muon_NonIsol_Staco_sumet_CentralReg;
   Float_t         MET_Muon_NonIsol_Staco_phi_CentralReg;
   Float_t         MET_Muon_NonIsol_Staco_etx_EndcapRegion;
   Float_t         MET_Muon_NonIsol_Staco_ety_EndcapRegion;
   Float_t         MET_Muon_NonIsol_Staco_sumet_EndcapRegion;
   Float_t         MET_Muon_NonIsol_Staco_phi_EndcapRegion;
   Float_t         MET_Muon_NonIsol_Staco_etx_ForwardReg;
   Float_t         MET_Muon_NonIsol_Staco_ety_ForwardReg;
   Float_t         MET_Muon_NonIsol_Staco_sumet_ForwardReg;
   Float_t         MET_Muon_NonIsol_Staco_phi_ForwardReg;
   Float_t         MET_Muon_Total_Staco_etx;
   Float_t         MET_Muon_Total_Staco_ety;
   Float_t         MET_Muon_Total_Staco_phi;
   Float_t         MET_Muon_Total_Staco_et;
   Float_t         MET_Muon_Total_Staco_sumet;
   Float_t         MET_Muon_Total_Staco_etx_CentralReg;
   Float_t         MET_Muon_Total_Staco_ety_CentralReg;
   Float_t         MET_Muon_Total_Staco_sumet_CentralReg;
   Float_t         MET_Muon_Total_Staco_phi_CentralReg;
   Float_t         MET_Muon_Total_Staco_etx_EndcapRegion;
   Float_t         MET_Muon_Total_Staco_ety_EndcapRegion;
   Float_t         MET_Muon_Total_Staco_sumet_EndcapRegion;
   Float_t         MET_Muon_Total_Staco_phi_EndcapRegion;
   Float_t         MET_Muon_Total_Staco_etx_ForwardReg;
   Float_t         MET_Muon_Total_Staco_ety_ForwardReg;
   Float_t         MET_Muon_Total_Staco_sumet_ForwardReg;
   Float_t         MET_Muon_Total_Staco_phi_ForwardReg;
   Float_t         MET_Muon_Isol_Muid_etx;
   Float_t         MET_Muon_Isol_Muid_ety;
   Float_t         MET_Muon_Isol_Muid_phi;
   Float_t         MET_Muon_Isol_Muid_et;
   Float_t         MET_Muon_Isol_Muid_sumet;
   Float_t         MET_Muon_Isol_Muid_etx_CentralReg;
   Float_t         MET_Muon_Isol_Muid_ety_CentralReg;
   Float_t         MET_Muon_Isol_Muid_sumet_CentralReg;
   Float_t         MET_Muon_Isol_Muid_phi_CentralReg;
   Float_t         MET_Muon_Isol_Muid_etx_EndcapRegion;
   Float_t         MET_Muon_Isol_Muid_ety_EndcapRegion;
   Float_t         MET_Muon_Isol_Muid_sumet_EndcapRegion;
   Float_t         MET_Muon_Isol_Muid_phi_EndcapRegion;
   Float_t         MET_Muon_Isol_Muid_etx_ForwardReg;
   Float_t         MET_Muon_Isol_Muid_ety_ForwardReg;
   Float_t         MET_Muon_Isol_Muid_sumet_ForwardReg;
   Float_t         MET_Muon_Isol_Muid_phi_ForwardReg;
   Float_t         MET_Muon_NonIsol_Muid_etx;
   Float_t         MET_Muon_NonIsol_Muid_ety;
   Float_t         MET_Muon_NonIsol_Muid_phi;
   Float_t         MET_Muon_NonIsol_Muid_et;
   Float_t         MET_Muon_NonIsol_Muid_sumet;
   Float_t         MET_Muon_NonIsol_Muid_etx_CentralReg;
   Float_t         MET_Muon_NonIsol_Muid_ety_CentralReg;
   Float_t         MET_Muon_NonIsol_Muid_sumet_CentralReg;
   Float_t         MET_Muon_NonIsol_Muid_phi_CentralReg;
   Float_t         MET_Muon_NonIsol_Muid_etx_EndcapRegion;
   Float_t         MET_Muon_NonIsol_Muid_ety_EndcapRegion;
   Float_t         MET_Muon_NonIsol_Muid_sumet_EndcapRegion;
   Float_t         MET_Muon_NonIsol_Muid_phi_EndcapRegion;
   Float_t         MET_Muon_NonIsol_Muid_etx_ForwardReg;
   Float_t         MET_Muon_NonIsol_Muid_ety_ForwardReg;
   Float_t         MET_Muon_NonIsol_Muid_sumet_ForwardReg;
   Float_t         MET_Muon_NonIsol_Muid_phi_ForwardReg;
   Float_t         MET_Muon_Total_Muid_etx;
   Float_t         MET_Muon_Total_Muid_ety;
   Float_t         MET_Muon_Total_Muid_phi;
   Float_t         MET_Muon_Total_Muid_et;
   Float_t         MET_Muon_Total_Muid_sumet;
   Float_t         MET_Muon_Total_Muid_etx_CentralReg;
   Float_t         MET_Muon_Total_Muid_ety_CentralReg;
   Float_t         MET_Muon_Total_Muid_sumet_CentralReg;
   Float_t         MET_Muon_Total_Muid_phi_CentralReg;
   Float_t         MET_Muon_Total_Muid_etx_EndcapRegion;
   Float_t         MET_Muon_Total_Muid_ety_EndcapRegion;
   Float_t         MET_Muon_Total_Muid_sumet_EndcapRegion;
   Float_t         MET_Muon_Total_Muid_phi_EndcapRegion;
   Float_t         MET_Muon_Total_Muid_etx_ForwardReg;
   Float_t         MET_Muon_Total_Muid_ety_ForwardReg;
   Float_t         MET_Muon_Total_Muid_sumet_ForwardReg;
   Float_t         MET_Muon_Total_Muid_phi_ForwardReg;
   Float_t         MET_MuonBoy_etx;
   Float_t         MET_MuonBoy_ety;
   Float_t         MET_MuonBoy_phi;
   Float_t         MET_MuonBoy_et;
   Float_t         MET_MuonBoy_sumet;
   Float_t         MET_MuonBoy_etx_CentralReg;
   Float_t         MET_MuonBoy_ety_CentralReg;
   Float_t         MET_MuonBoy_sumet_CentralReg;
   Float_t         MET_MuonBoy_phi_CentralReg;
   Float_t         MET_MuonBoy_etx_EndcapRegion;
   Float_t         MET_MuonBoy_ety_EndcapRegion;
   Float_t         MET_MuonBoy_sumet_EndcapRegion;
   Float_t         MET_MuonBoy_phi_EndcapRegion;
   Float_t         MET_MuonBoy_etx_ForwardReg;
   Float_t         MET_MuonBoy_ety_ForwardReg;
   Float_t         MET_MuonBoy_sumet_ForwardReg;
   Float_t         MET_MuonBoy_phi_ForwardReg;
   Float_t         MET_CellOut_Eflow_etx;
   Float_t         MET_CellOut_Eflow_ety;
   Float_t         MET_CellOut_Eflow_phi;
   Float_t         MET_CellOut_Eflow_et;
   Float_t         MET_CellOut_Eflow_sumet;
   Float_t         MET_CellOut_Eflow_etx_CentralReg;
   Float_t         MET_CellOut_Eflow_ety_CentralReg;
   Float_t         MET_CellOut_Eflow_sumet_CentralReg;
   Float_t         MET_CellOut_Eflow_phi_CentralReg;
   Float_t         MET_CellOut_Eflow_etx_EndcapRegion;
   Float_t         MET_CellOut_Eflow_ety_EndcapRegion;
   Float_t         MET_CellOut_Eflow_sumet_EndcapRegion;
   Float_t         MET_CellOut_Eflow_phi_EndcapRegion;
   Float_t         MET_CellOut_Eflow_etx_ForwardReg;
   Float_t         MET_CellOut_Eflow_ety_ForwardReg;
   Float_t         MET_CellOut_Eflow_sumet_ForwardReg;
   Float_t         MET_CellOut_Eflow_phi_ForwardReg;
   Float_t         MET_CellOut_MiniJet_etx;
   Float_t         MET_CellOut_MiniJet_ety;
   Float_t         MET_CellOut_MiniJet_phi;
   Float_t         MET_CellOut_MiniJet_et;
   Float_t         MET_CellOut_MiniJet_sumet;
   Float_t         MET_CellOut_MiniJet_etx_CentralReg;
   Float_t         MET_CellOut_MiniJet_ety_CentralReg;
   Float_t         MET_CellOut_MiniJet_sumet_CentralReg;
   Float_t         MET_CellOut_MiniJet_phi_CentralReg;
   Float_t         MET_CellOut_MiniJet_etx_EndcapRegion;
   Float_t         MET_CellOut_MiniJet_ety_EndcapRegion;
   Float_t         MET_CellOut_MiniJet_sumet_EndcapRegion;
   Float_t         MET_CellOut_MiniJet_phi_EndcapRegion;
   Float_t         MET_CellOut_MiniJet_etx_ForwardReg;
   Float_t         MET_CellOut_MiniJet_ety_ForwardReg;
   Float_t         MET_CellOut_MiniJet_sumet_ForwardReg;
   Float_t         MET_CellOut_MiniJet_phi_ForwardReg;
   Float_t         MET_RefMuon_Track_etx;
   Float_t         MET_RefMuon_Track_ety;
   Float_t         MET_RefMuon_Track_phi;
   Float_t         MET_RefMuon_Track_et;
   Float_t         MET_RefMuon_Track_sumet;
   Float_t         MET_RefMuon_Track_etx_CentralReg;
   Float_t         MET_RefMuon_Track_ety_CentralReg;
   Float_t         MET_RefMuon_Track_sumet_CentralReg;
   Float_t         MET_RefMuon_Track_phi_CentralReg;
   Float_t         MET_RefMuon_Track_etx_EndcapRegion;
   Float_t         MET_RefMuon_Track_ety_EndcapRegion;
   Float_t         MET_RefMuon_Track_sumet_EndcapRegion;
   Float_t         MET_RefMuon_Track_phi_EndcapRegion;
   Float_t         MET_RefMuon_Track_etx_ForwardReg;
   Float_t         MET_RefMuon_Track_ety_ForwardReg;
   Float_t         MET_RefMuon_Track_sumet_ForwardReg;
   Float_t         MET_RefMuon_Track_phi_ForwardReg;
   Float_t         MET_RefMuon_Track_Staco_etx;
   Float_t         MET_RefMuon_Track_Staco_ety;
   Float_t         MET_RefMuon_Track_Staco_phi;
   Float_t         MET_RefMuon_Track_Staco_et;
   Float_t         MET_RefMuon_Track_Staco_sumet;
   Float_t         MET_RefMuon_Track_Staco_etx_CentralReg;
   Float_t         MET_RefMuon_Track_Staco_ety_CentralReg;
   Float_t         MET_RefMuon_Track_Staco_sumet_CentralReg;
   Float_t         MET_RefMuon_Track_Staco_phi_CentralReg;
   Float_t         MET_RefMuon_Track_Staco_etx_EndcapRegion;
   Float_t         MET_RefMuon_Track_Staco_ety_EndcapRegion;
   Float_t         MET_RefMuon_Track_Staco_sumet_EndcapRegion;
   Float_t         MET_RefMuon_Track_Staco_phi_EndcapRegion;
   Float_t         MET_RefMuon_Track_Staco_etx_ForwardReg;
   Float_t         MET_RefMuon_Track_Staco_ety_ForwardReg;
   Float_t         MET_RefMuon_Track_Staco_sumet_ForwardReg;
   Float_t         MET_RefMuon_Track_Staco_phi_ForwardReg;
   Float_t         MET_RefMuon_Track_Muid_etx;
   Float_t         MET_RefMuon_Track_Muid_ety;
   Float_t         MET_RefMuon_Track_Muid_phi;
   Float_t         MET_RefMuon_Track_Muid_et;
   Float_t         MET_RefMuon_Track_Muid_sumet;
   Float_t         MET_RefMuon_Track_Muid_etx_CentralReg;
   Float_t         MET_RefMuon_Track_Muid_ety_CentralReg;
   Float_t         MET_RefMuon_Track_Muid_sumet_CentralReg;
   Float_t         MET_RefMuon_Track_Muid_phi_CentralReg;
   Float_t         MET_RefMuon_Track_Muid_etx_EndcapRegion;
   Float_t         MET_RefMuon_Track_Muid_ety_EndcapRegion;
   Float_t         MET_RefMuon_Track_Muid_sumet_EndcapRegion;
   Float_t         MET_RefMuon_Track_Muid_phi_EndcapRegion;
   Float_t         MET_RefMuon_Track_Muid_etx_ForwardReg;
   Float_t         MET_RefMuon_Track_Muid_ety_ForwardReg;
   Float_t         MET_RefMuon_Track_Muid_sumet_ForwardReg;
   Float_t         MET_RefMuon_Track_Muid_phi_ForwardReg;
   Float_t         MET_CryoCone_etx;
   Float_t         MET_CryoCone_ety;
   Float_t         MET_CryoCone_phi;
   Float_t         MET_CryoCone_et;
   Float_t         MET_CryoCone_sumet;
   Float_t         MET_CryoCone_etx_CentralReg;
   Float_t         MET_CryoCone_ety_CentralReg;
   Float_t         MET_CryoCone_sumet_CentralReg;
   Float_t         MET_CryoCone_phi_CentralReg;
   Float_t         MET_CryoCone_etx_EndcapRegion;
   Float_t         MET_CryoCone_ety_EndcapRegion;
   Float_t         MET_CryoCone_sumet_EndcapRegion;
   Float_t         MET_CryoCone_phi_EndcapRegion;
   Float_t         MET_CryoCone_etx_ForwardReg;
   Float_t         MET_CryoCone_ety_ForwardReg;
   Float_t         MET_CryoCone_sumet_ForwardReg;
   Float_t         MET_CryoCone_phi_ForwardReg;
   Float_t         MET_Final_etx;
   Float_t         MET_Final_ety;
   Float_t         MET_Final_phi;
   Float_t         MET_Final_et;
   Float_t         MET_Final_sumet;
   Float_t         MET_Final_etx_CentralReg;
   Float_t         MET_Final_ety_CentralReg;
   Float_t         MET_Final_sumet_CentralReg;
   Float_t         MET_Final_phi_CentralReg;
   Float_t         MET_Final_etx_EndcapRegion;
   Float_t         MET_Final_ety_EndcapRegion;
   Float_t         MET_Final_sumet_EndcapRegion;
   Float_t         MET_Final_phi_EndcapRegion;
   Float_t         MET_Final_etx_ForwardReg;
   Float_t         MET_Final_ety_ForwardReg;
   Float_t         MET_Final_sumet_ForwardReg;
   Float_t         MET_Final_phi_ForwardReg;
   Float_t         MET_MuonBoy_Spectro_etx;
   Float_t         MET_MuonBoy_Spectro_ety;
   Float_t         MET_MuonBoy_Spectro_phi;
   Float_t         MET_MuonBoy_Spectro_et;
   Float_t         MET_MuonBoy_Spectro_sumet;
   Float_t         MET_MuonBoy_Spectro_etx_CentralReg;
   Float_t         MET_MuonBoy_Spectro_ety_CentralReg;
   Float_t         MET_MuonBoy_Spectro_sumet_CentralReg;
   Float_t         MET_MuonBoy_Spectro_phi_CentralReg;
   Float_t         MET_MuonBoy_Spectro_etx_EndcapRegion;
   Float_t         MET_MuonBoy_Spectro_ety_EndcapRegion;
   Float_t         MET_MuonBoy_Spectro_sumet_EndcapRegion;
   Float_t         MET_MuonBoy_Spectro_phi_EndcapRegion;
   Float_t         MET_MuonBoy_Spectro_etx_ForwardReg;
   Float_t         MET_MuonBoy_Spectro_ety_ForwardReg;
   Float_t         MET_MuonBoy_Spectro_sumet_ForwardReg;
   Float_t         MET_MuonBoy_Spectro_phi_ForwardReg;
   Float_t         MET_MuonBoy_Track_etx;
   Float_t         MET_MuonBoy_Track_ety;
   Float_t         MET_MuonBoy_Track_phi;
   Float_t         MET_MuonBoy_Track_et;
   Float_t         MET_MuonBoy_Track_sumet;
   Float_t         MET_MuonBoy_Track_etx_CentralReg;
   Float_t         MET_MuonBoy_Track_ety_CentralReg;
   Float_t         MET_MuonBoy_Track_sumet_CentralReg;
   Float_t         MET_MuonBoy_Track_phi_CentralReg;
   Float_t         MET_MuonBoy_Track_etx_EndcapRegion;
   Float_t         MET_MuonBoy_Track_ety_EndcapRegion;
   Float_t         MET_MuonBoy_Track_sumet_EndcapRegion;
   Float_t         MET_MuonBoy_Track_phi_EndcapRegion;
   Float_t         MET_MuonBoy_Track_etx_ForwardReg;
   Float_t         MET_MuonBoy_Track_ety_ForwardReg;
   Float_t         MET_MuonBoy_Track_sumet_ForwardReg;
   Float_t         MET_MuonBoy_Track_phi_ForwardReg;
   Float_t         MET_MuonMuid_etx;
   Float_t         MET_MuonMuid_ety;
   Float_t         MET_MuonMuid_phi;
   Float_t         MET_MuonMuid_et;
   Float_t         MET_MuonMuid_sumet;
   Float_t         MET_MuonMuid_etx_CentralReg;
   Float_t         MET_MuonMuid_ety_CentralReg;
   Float_t         MET_MuonMuid_sumet_CentralReg;
   Float_t         MET_MuonMuid_phi_CentralReg;
   Float_t         MET_MuonMuid_etx_EndcapRegion;
   Float_t         MET_MuonMuid_ety_EndcapRegion;
   Float_t         MET_MuonMuid_sumet_EndcapRegion;
   Float_t         MET_MuonMuid_phi_EndcapRegion;
   Float_t         MET_MuonMuid_etx_ForwardReg;
   Float_t         MET_MuonMuid_ety_ForwardReg;
   Float_t         MET_MuonMuid_sumet_ForwardReg;
   Float_t         MET_MuonMuid_phi_ForwardReg;
   Float_t         MET_Muid_etx;
   Float_t         MET_Muid_ety;
   Float_t         MET_Muid_phi;
   Float_t         MET_Muid_et;
   Float_t         MET_Muid_sumet;
   Float_t         MET_Muid_etx_CentralReg;
   Float_t         MET_Muid_ety_CentralReg;
   Float_t         MET_Muid_sumet_CentralReg;
   Float_t         MET_Muid_phi_CentralReg;
   Float_t         MET_Muid_etx_EndcapRegion;
   Float_t         MET_Muid_ety_EndcapRegion;
   Float_t         MET_Muid_sumet_EndcapRegion;
   Float_t         MET_Muid_phi_EndcapRegion;
   Float_t         MET_Muid_etx_ForwardReg;
   Float_t         MET_Muid_ety_ForwardReg;
   Float_t         MET_Muid_sumet_ForwardReg;
   Float_t         MET_Muid_phi_ForwardReg;
   Float_t         MET_Muid_Spectro_etx;
   Float_t         MET_Muid_Spectro_ety;
   Float_t         MET_Muid_Spectro_phi;
   Float_t         MET_Muid_Spectro_et;
   Float_t         MET_Muid_Spectro_sumet;
   Float_t         MET_Muid_Spectro_etx_CentralReg;
   Float_t         MET_Muid_Spectro_ety_CentralReg;
   Float_t         MET_Muid_Spectro_sumet_CentralReg;
   Float_t         MET_Muid_Spectro_phi_CentralReg;
   Float_t         MET_Muid_Spectro_etx_EndcapRegion;
   Float_t         MET_Muid_Spectro_ety_EndcapRegion;
   Float_t         MET_Muid_Spectro_sumet_EndcapRegion;
   Float_t         MET_Muid_Spectro_phi_EndcapRegion;
   Float_t         MET_Muid_Spectro_etx_ForwardReg;
   Float_t         MET_Muid_Spectro_ety_ForwardReg;
   Float_t         MET_Muid_Spectro_sumet_ForwardReg;
   Float_t         MET_Muid_Spectro_phi_ForwardReg;
   Float_t         MET_Muid_Track_etx;
   Float_t         MET_Muid_Track_ety;
   Float_t         MET_Muid_Track_phi;
   Float_t         MET_Muid_Track_et;
   Float_t         MET_Muid_Track_sumet;
   Float_t         MET_Muid_Track_etx_CentralReg;
   Float_t         MET_Muid_Track_ety_CentralReg;
   Float_t         MET_Muid_Track_sumet_CentralReg;
   Float_t         MET_Muid_Track_phi_CentralReg;
   Float_t         MET_Muid_Track_etx_EndcapRegion;
   Float_t         MET_Muid_Track_ety_EndcapRegion;
   Float_t         MET_Muid_Track_sumet_EndcapRegion;
   Float_t         MET_Muid_Track_phi_EndcapRegion;
   Float_t         MET_Muid_Track_etx_ForwardReg;
   Float_t         MET_Muid_Track_ety_ForwardReg;
   Float_t         MET_Muid_Track_sumet_ForwardReg;
   Float_t         MET_Muid_Track_phi_ForwardReg;
   Float_t         MET_Muon_etx;
   Float_t         MET_Muon_ety;
   Float_t         MET_Muon_phi;
   Float_t         MET_Muon_et;
   Float_t         MET_Muon_sumet;
   Float_t         MET_Muon_etx_CentralReg;
   Float_t         MET_Muon_ety_CentralReg;
   Float_t         MET_Muon_sumet_CentralReg;
   Float_t         MET_Muon_phi_CentralReg;
   Float_t         MET_Muon_etx_EndcapRegion;
   Float_t         MET_Muon_ety_EndcapRegion;
   Float_t         MET_Muon_sumet_EndcapRegion;
   Float_t         MET_Muon_phi_EndcapRegion;
   Float_t         MET_Muon_etx_ForwardReg;
   Float_t         MET_Muon_ety_ForwardReg;
   Float_t         MET_Muon_sumet_ForwardReg;
   Float_t         MET_Muon_phi_ForwardReg;
   Float_t         MET_TopoObj_etx;
   Float_t         MET_TopoObj_ety;
   Float_t         MET_TopoObj_phi;
   Float_t         MET_TopoObj_et;
   Float_t         MET_TopoObj_sumet;
   Float_t         MET_TopoObj_etx_CentralReg;
   Float_t         MET_TopoObj_ety_CentralReg;
   Float_t         MET_TopoObj_sumet_CentralReg;
   Float_t         MET_TopoObj_phi_CentralReg;
   Float_t         MET_TopoObj_etx_EndcapRegion;
   Float_t         MET_TopoObj_ety_EndcapRegion;
   Float_t         MET_TopoObj_sumet_EndcapRegion;
   Float_t         MET_TopoObj_phi_EndcapRegion;
   Float_t         MET_TopoObj_etx_ForwardReg;
   Float_t         MET_TopoObj_ety_ForwardReg;
   Float_t         MET_TopoObj_sumet_ForwardReg;
   Float_t         MET_TopoObj_phi_ForwardReg;
   Float_t         MET_LocHadTopoObj_etx;
   Float_t         MET_LocHadTopoObj_ety;
   Float_t         MET_LocHadTopoObj_phi;
   Float_t         MET_LocHadTopoObj_et;
   Float_t         MET_LocHadTopoObj_sumet;
   Float_t         MET_LocHadTopoObj_etx_CentralReg;
   Float_t         MET_LocHadTopoObj_ety_CentralReg;
   Float_t         MET_LocHadTopoObj_sumet_CentralReg;
   Float_t         MET_LocHadTopoObj_phi_CentralReg;
   Float_t         MET_LocHadTopoObj_etx_EndcapRegion;
   Float_t         MET_LocHadTopoObj_ety_EndcapRegion;
   Float_t         MET_LocHadTopoObj_sumet_EndcapRegion;
   Float_t         MET_LocHadTopoObj_phi_EndcapRegion;
   Float_t         MET_LocHadTopoObj_etx_ForwardReg;
   Float_t         MET_LocHadTopoObj_ety_ForwardReg;
   Float_t         MET_LocHadTopoObj_sumet_ForwardReg;
   Float_t         MET_LocHadTopoObj_phi_ForwardReg;
   Float_t         MET_Topo_etx;
   Float_t         MET_Topo_ety;
   Float_t         MET_Topo_phi;
   Float_t         MET_Topo_et;
   Float_t         MET_Topo_sumet;
   Float_t         MET_Topo_SUMET_EMFrac;
   Float_t         MET_Topo_etx_PEMB;
   Float_t         MET_Topo_ety_PEMB;
   Float_t         MET_Topo_sumet_PEMB;
   Float_t         MET_Topo_phi_PEMB;
   Float_t         MET_Topo_etx_EMB;
   Float_t         MET_Topo_ety_EMB;
   Float_t         MET_Topo_sumet_EMB;
   Float_t         MET_Topo_phi_EMB;
   Float_t         MET_Topo_etx_PEMEC;
   Float_t         MET_Topo_ety_PEMEC;
   Float_t         MET_Topo_sumet_PEMEC;
   Float_t         MET_Topo_phi_PEMEC;
   Float_t         MET_Topo_etx_EME;
   Float_t         MET_Topo_ety_EME;
   Float_t         MET_Topo_sumet_EME;
   Float_t         MET_Topo_phi_EME;
   Float_t         MET_Topo_etx_TILE;
   Float_t         MET_Topo_ety_TILE;
   Float_t         MET_Topo_sumet_TILE;
   Float_t         MET_Topo_phi_TILE;
   Float_t         MET_Topo_etx_HEC;
   Float_t         MET_Topo_ety_HEC;
   Float_t         MET_Topo_sumet_HEC;
   Float_t         MET_Topo_phi_HEC;
   Float_t         MET_Topo_etx_FCAL;
   Float_t         MET_Topo_ety_FCAL;
   Float_t         MET_Topo_sumet_FCAL;
   Float_t         MET_Topo_phi_FCAL;
   Float_t         MET_Topo_nCell_PEMB;
   Float_t         MET_Topo_nCell_EMB;
   Float_t         MET_Topo_nCell_PEMEC;
   Float_t         MET_Topo_nCell_EME;
   Float_t         MET_Topo_nCell_TILE;
   Float_t         MET_Topo_nCell_HEC;
   Float_t         MET_Topo_nCell_FCAL;
   Float_t         MET_Topo_etx_CentralReg;
   Float_t         MET_Topo_ety_CentralReg;
   Float_t         MET_Topo_sumet_CentralReg;
   Float_t         MET_Topo_phi_CentralReg;
   Float_t         MET_Topo_etx_EndcapRegion;
   Float_t         MET_Topo_ety_EndcapRegion;
   Float_t         MET_Topo_sumet_EndcapRegion;
   Float_t         MET_Topo_phi_EndcapRegion;
   Float_t         MET_Topo_etx_ForwardReg;
   Float_t         MET_Topo_ety_ForwardReg;
   Float_t         MET_Topo_sumet_ForwardReg;
   Float_t         MET_Topo_phi_ForwardReg;
   Float_t         MET_CorrTopo_etx;
   Float_t         MET_CorrTopo_ety;
   Float_t         MET_CorrTopo_phi;
   Float_t         MET_CorrTopo_et;
   Float_t         MET_CorrTopo_sumet;
   Float_t         MET_CorrTopo_SUMET_EMFrac;
   Float_t         MET_CorrTopo_etx_PEMB;
   Float_t         MET_CorrTopo_ety_PEMB;
   Float_t         MET_CorrTopo_sumet_PEMB;
   Float_t         MET_CorrTopo_phi_PEMB;
   Float_t         MET_CorrTopo_etx_EMB;
   Float_t         MET_CorrTopo_ety_EMB;
   Float_t         MET_CorrTopo_sumet_EMB;
   Float_t         MET_CorrTopo_phi_EMB;
   Float_t         MET_CorrTopo_etx_PEMEC;
   Float_t         MET_CorrTopo_ety_PEMEC;
   Float_t         MET_CorrTopo_sumet_PEMEC;
   Float_t         MET_CorrTopo_phi_PEMEC;
   Float_t         MET_CorrTopo_etx_EME;
   Float_t         MET_CorrTopo_ety_EME;
   Float_t         MET_CorrTopo_sumet_EME;
   Float_t         MET_CorrTopo_phi_EME;
   Float_t         MET_CorrTopo_etx_TILE;
   Float_t         MET_CorrTopo_ety_TILE;
   Float_t         MET_CorrTopo_sumet_TILE;
   Float_t         MET_CorrTopo_phi_TILE;
   Float_t         MET_CorrTopo_etx_HEC;
   Float_t         MET_CorrTopo_ety_HEC;
   Float_t         MET_CorrTopo_sumet_HEC;
   Float_t         MET_CorrTopo_phi_HEC;
   Float_t         MET_CorrTopo_etx_FCAL;
   Float_t         MET_CorrTopo_ety_FCAL;
   Float_t         MET_CorrTopo_sumet_FCAL;
   Float_t         MET_CorrTopo_phi_FCAL;
   Float_t         MET_CorrTopo_nCell_PEMB;
   Float_t         MET_CorrTopo_nCell_EMB;
   Float_t         MET_CorrTopo_nCell_PEMEC;
   Float_t         MET_CorrTopo_nCell_EME;
   Float_t         MET_CorrTopo_nCell_TILE;
   Float_t         MET_CorrTopo_nCell_HEC;
   Float_t         MET_CorrTopo_nCell_FCAL;
   Float_t         MET_CorrTopo_etx_CentralReg;
   Float_t         MET_CorrTopo_ety_CentralReg;
   Float_t         MET_CorrTopo_sumet_CentralReg;
   Float_t         MET_CorrTopo_phi_CentralReg;
   Float_t         MET_CorrTopo_etx_EndcapRegion;
   Float_t         MET_CorrTopo_ety_EndcapRegion;
   Float_t         MET_CorrTopo_sumet_EndcapRegion;
   Float_t         MET_CorrTopo_phi_EndcapRegion;
   Float_t         MET_CorrTopo_etx_ForwardReg;
   Float_t         MET_CorrTopo_ety_ForwardReg;
   Float_t         MET_CorrTopo_sumet_ForwardReg;
   Float_t         MET_CorrTopo_phi_ForwardReg;
   Float_t         MET_LocHadTopo_etx;
   Float_t         MET_LocHadTopo_ety;
   Float_t         MET_LocHadTopo_phi;
   Float_t         MET_LocHadTopo_et;
   Float_t         MET_LocHadTopo_sumet;
   Float_t         MET_LocHadTopo_SUMET_EMFrac;
   Float_t         MET_LocHadTopo_etx_PEMB;
   Float_t         MET_LocHadTopo_ety_PEMB;
   Float_t         MET_LocHadTopo_sumet_PEMB;
   Float_t         MET_LocHadTopo_phi_PEMB;
   Float_t         MET_LocHadTopo_etx_EMB;
   Float_t         MET_LocHadTopo_ety_EMB;
   Float_t         MET_LocHadTopo_sumet_EMB;
   Float_t         MET_LocHadTopo_phi_EMB;
   Float_t         MET_LocHadTopo_etx_PEMEC;
   Float_t         MET_LocHadTopo_ety_PEMEC;
   Float_t         MET_LocHadTopo_sumet_PEMEC;
   Float_t         MET_LocHadTopo_phi_PEMEC;
   Float_t         MET_LocHadTopo_etx_EME;
   Float_t         MET_LocHadTopo_ety_EME;
   Float_t         MET_LocHadTopo_sumet_EME;
   Float_t         MET_LocHadTopo_phi_EME;
   Float_t         MET_LocHadTopo_etx_TILE;
   Float_t         MET_LocHadTopo_ety_TILE;
   Float_t         MET_LocHadTopo_sumet_TILE;
   Float_t         MET_LocHadTopo_phi_TILE;
   Float_t         MET_LocHadTopo_etx_HEC;
   Float_t         MET_LocHadTopo_ety_HEC;
   Float_t         MET_LocHadTopo_sumet_HEC;
   Float_t         MET_LocHadTopo_phi_HEC;
   Float_t         MET_LocHadTopo_etx_FCAL;
   Float_t         MET_LocHadTopo_ety_FCAL;
   Float_t         MET_LocHadTopo_sumet_FCAL;
   Float_t         MET_LocHadTopo_phi_FCAL;
   Float_t         MET_LocHadTopo_nCell_PEMB;
   Float_t         MET_LocHadTopo_nCell_EMB;
   Float_t         MET_LocHadTopo_nCell_PEMEC;
   Float_t         MET_LocHadTopo_nCell_EME;
   Float_t         MET_LocHadTopo_nCell_TILE;
   Float_t         MET_LocHadTopo_nCell_HEC;
   Float_t         MET_LocHadTopo_nCell_FCAL;
   Float_t         MET_LocHadTopo_etx_CentralReg;
   Float_t         MET_LocHadTopo_ety_CentralReg;
   Float_t         MET_LocHadTopo_sumet_CentralReg;
   Float_t         MET_LocHadTopo_phi_CentralReg;
   Float_t         MET_LocHadTopo_etx_EndcapRegion;
   Float_t         MET_LocHadTopo_ety_EndcapRegion;
   Float_t         MET_LocHadTopo_sumet_EndcapRegion;
   Float_t         MET_LocHadTopo_phi_EndcapRegion;
   Float_t         MET_LocHadTopo_etx_ForwardReg;
   Float_t         MET_LocHadTopo_ety_ForwardReg;
   Float_t         MET_LocHadTopo_sumet_ForwardReg;
   Float_t         MET_LocHadTopo_phi_ForwardReg;
   Float_t         MET_Truth_NonInt_etx;
   Float_t         MET_Truth_NonInt_ety;
   Float_t         MET_Truth_NonInt_phi;
   Float_t         MET_Truth_NonInt_et;
   Float_t         MET_Truth_NonInt_sumet;
   Float_t         MET_Truth_Int_etx;
   Float_t         MET_Truth_Int_ety;
   Float_t         MET_Truth_IntCentral_etx;
   Float_t         MET_Truth_IntCentral_ety;
   Float_t         MET_Truth_IntFwd_etx;
   Float_t         MET_Truth_IntFwd_ety;
   Float_t         MET_Truth_IntOutCover_etx;
   Float_t         MET_Truth_IntOutCover_ety;
   Float_t         MET_Truth_IntMuons_etx;
   Float_t         MET_Truth_IntMuons_ety;
   Float_t         MET_Truth_Int_phi;
   Float_t         MET_Truth_IntCentral_phi;
   Float_t         MET_Truth_IntFwd_phi;
   Float_t         MET_Truth_IntOutCover_phi;
   Float_t         MET_Truth_IntMuons_phi;
   Float_t         MET_Truth_Int_et;
   Float_t         MET_Truth_IntCentral_et;
   Float_t         MET_Truth_IntFwd_et;
   Float_t         MET_Truth_IntOutCover_et;
   Float_t         MET_Truth_IntMuons_et;
   Float_t         MET_Truth_Int_sumet;
   Float_t         MET_Truth_IntCentral_sumet;
   Float_t         MET_Truth_IntFwd_sumet;
   Float_t         MET_Truth_IntOutCover_sumet;
   Float_t         MET_Truth_IntMuons_sumet;
   Float_t         MET_Truth_PileUp_NonInt_etx;
   Float_t         MET_Truth_PileUp_NonInt_ety;
   Float_t         MET_Truth_PileUp_NonInt_phi;
   Float_t         MET_Truth_PileUp_NonInt_et;
   Float_t         MET_Truth_PileUp_NonInt_sumet;
   Float_t         MET_Truth_PileUp_Int_etx;
   Float_t         MET_Truth_PileUp_Int_ety;
   Float_t         MET_Truth_PileUp_IntCentral_etx;
   Float_t         MET_Truth_PileUp_IntCentral_ety;
   Float_t         MET_Truth_PileUp_IntFwd_etx;
   Float_t         MET_Truth_PileUp_IntFwd_ety;
   Float_t         MET_Truth_PileUp_IntOutCover_etx;
   Float_t         MET_Truth_PileUp_IntOutCover_ety;
   Float_t         MET_Truth_PileUp_IntMuons_etx;
   Float_t         MET_Truth_PileUp_IntMuons_ety;
   Float_t         MET_Truth_PileUp_Int_phi;
   Float_t         MET_Truth_PileUp_IntCentral_phi;
   Float_t         MET_Truth_PileUp_IntFwd_phi;
   Float_t         MET_Truth_PileUp_IntOutCover_phi;
   Float_t         MET_Truth_PileUp_IntMuons_phi;
   Float_t         MET_Truth_PileUp_Int_et;
   Float_t         MET_Truth_PileUp_IntCentral_et;
   Float_t         MET_Truth_PileUp_IntFwd_et;
   Float_t         MET_Truth_PileUp_IntOutCover_et;
   Float_t         MET_Truth_PileUp_IntMuons_et;
   Float_t         MET_Truth_PileUp_Int_sumet;
   Float_t         MET_Truth_PileUp_IntCentral_sumet;
   Float_t         MET_Truth_PileUp_IntFwd_sumet;
   Float_t         MET_Truth_PileUp_IntOutCover_sumet;
   Float_t         MET_Truth_PileUp_IntMuons_sumet;
   Float_t         MET_DM_Crack1_etx;
   Float_t         MET_DM_Crack1_ety;
   Float_t         MET_DM_Crack1_phi;
   Float_t         MET_DM_Crack1_et;
   Float_t         MET_DM_Crack1_sumet;
   Float_t         MET_DM_Crack2_etx;
   Float_t         MET_DM_Crack2_ety;
   Float_t         MET_DM_Crack2_phi;
   Float_t         MET_DM_Crack2_et;
   Float_t         MET_DM_Crack2_sumet;
   Float_t         MET_DM_All_etx;
   Float_t         MET_DM_All_ety;
   Float_t         MET_DM_All_phi;
   Float_t         MET_DM_All_et;
   Float_t         MET_DM_All_sumet;
   Float_t         MET_DM_Cryo_etx;
   Float_t         MET_DM_Cryo_ety;
   Float_t         MET_DM_Cryo_phi;
   Float_t         MET_DM_Cryo_et;
   Float_t         MET_DM_Cryo_sumet;
   Int_t           el_MET_n;
   vector<float>   *el_MET_wpx;
   vector<float>   *el_MET_wpy;
   vector<float>   *el_MET_wet;
   vector<unsigned short> *el_MET_statusWord;
   Int_t           ph_MET_n;
   vector<float>   *ph_MET_wpx;
   vector<float>   *ph_MET_wpy;
   vector<float>   *ph_MET_wet;
   vector<unsigned short> *ph_MET_statusWord;
   Int_t           mu_staco_MET_n;
   vector<float>   *mu_staco_MET_wpx;
   vector<float>   *mu_staco_MET_wpy;
   vector<float>   *mu_staco_MET_wet;
   vector<unsigned short> *mu_staco_MET_statusWord;
   Int_t           mu_muid_MET_n;
   vector<float>   *mu_muid_MET_wpx;
   vector<float>   *mu_muid_MET_wpy;
   vector<float>   *mu_muid_MET_wet;
   vector<unsigned short> *mu_muid_MET_statusWord;
   Int_t           tau_MET_n;
   vector<float>   *tau_MET_wpx;
   vector<float>   *tau_MET_wpy;
   vector<float>   *tau_MET_wet;
   vector<unsigned short> *tau_MET_statusWord;
   Int_t           jet_AntiKt6LCTopo_MET_n;
   vector<float>   *jet_AntiKt6LCTopo_MET_wpx;
   vector<float>   *jet_AntiKt6LCTopo_MET_wpy;
   vector<float>   *jet_AntiKt6LCTopo_MET_wet;
   vector<unsigned short> *jet_AntiKt6LCTopo_MET_statusWord;
   Int_t           cl_MET_n;
   vector<float>   *cl_MET_wpx;
   vector<float>   *cl_MET_wpy;
   vector<float>   *cl_MET_wet;
   vector<unsigned short> *cl_MET_statusWord;
   Int_t           trk_MET_n;
   vector<float>   *trk_MET_wpx;
   vector<float>   *trk_MET_wpy;
   vector<float>   *trk_MET_wet;
   vector<unsigned short> *trk_MET_statusWord;
   Float_t         MET_RefFinal_GCW_pt20_etx;
   Float_t         MET_RefFinal_GCW_pt20_ety;
   Float_t         MET_RefFinal_GCW_pt20_phi;
   Float_t         MET_RefFinal_GCW_pt20_et;
   Float_t         MET_RefFinal_GCW_pt20_sumet;
   Float_t         MET_RefFinal_GCW_pt20_etx_CentralReg;
   Float_t         MET_RefFinal_GCW_pt20_ety_CentralReg;
   Float_t         MET_RefFinal_GCW_pt20_sumet_CentralReg;
   Float_t         MET_RefFinal_GCW_pt20_phi_CentralReg;
   Float_t         MET_RefFinal_GCW_pt20_etx_EndcapRegion;
   Float_t         MET_RefFinal_GCW_pt20_ety_EndcapRegion;
   Float_t         MET_RefFinal_GCW_pt20_sumet_EndcapRegion;
   Float_t         MET_RefFinal_GCW_pt20_phi_EndcapRegion;
   Float_t         MET_RefFinal_GCW_pt20_etx_ForwardReg;
   Float_t         MET_RefFinal_GCW_pt20_ety_ForwardReg;
   Float_t         MET_RefFinal_GCW_pt20_sumet_ForwardReg;
   Float_t         MET_RefFinal_GCW_pt20_phi_ForwardReg;
   Float_t         MET_RefGamma_GCW_pt20_etx;
   Float_t         MET_RefGamma_GCW_pt20_ety;
   Float_t         MET_RefGamma_GCW_pt20_phi;
   Float_t         MET_RefGamma_GCW_pt20_et;
   Float_t         MET_RefGamma_GCW_pt20_sumet;
   Float_t         MET_RefGamma_GCW_pt20_etx_CentralReg;
   Float_t         MET_RefGamma_GCW_pt20_ety_CentralReg;
   Float_t         MET_RefGamma_GCW_pt20_sumet_CentralReg;
   Float_t         MET_RefGamma_GCW_pt20_phi_CentralReg;
   Float_t         MET_RefGamma_GCW_pt20_etx_EndcapRegion;
   Float_t         MET_RefGamma_GCW_pt20_ety_EndcapRegion;
   Float_t         MET_RefGamma_GCW_pt20_sumet_EndcapRegion;
   Float_t         MET_RefGamma_GCW_pt20_phi_EndcapRegion;
   Float_t         MET_RefGamma_GCW_pt20_etx_ForwardReg;
   Float_t         MET_RefGamma_GCW_pt20_ety_ForwardReg;
   Float_t         MET_RefGamma_GCW_pt20_sumet_ForwardReg;
   Float_t         MET_RefGamma_GCW_pt20_phi_ForwardReg;
   Float_t         MET_RefEle_GCW_pt20_etx;
   Float_t         MET_RefEle_GCW_pt20_ety;
   Float_t         MET_RefEle_GCW_pt20_phi;
   Float_t         MET_RefEle_GCW_pt20_et;
   Float_t         MET_RefEle_GCW_pt20_sumet;
   Float_t         MET_RefEle_GCW_pt20_etx_CentralReg;
   Float_t         MET_RefEle_GCW_pt20_ety_CentralReg;
   Float_t         MET_RefEle_GCW_pt20_sumet_CentralReg;
   Float_t         MET_RefEle_GCW_pt20_phi_CentralReg;
   Float_t         MET_RefEle_GCW_pt20_etx_EndcapRegion;
   Float_t         MET_RefEle_GCW_pt20_ety_EndcapRegion;
   Float_t         MET_RefEle_GCW_pt20_sumet_EndcapRegion;
   Float_t         MET_RefEle_GCW_pt20_phi_EndcapRegion;
   Float_t         MET_RefEle_GCW_pt20_etx_ForwardReg;
   Float_t         MET_RefEle_GCW_pt20_ety_ForwardReg;
   Float_t         MET_RefEle_GCW_pt20_sumet_ForwardReg;
   Float_t         MET_RefEle_GCW_pt20_phi_ForwardReg;
   Float_t         MET_RefTau_GCW_pt20_etx;
   Float_t         MET_RefTau_GCW_pt20_ety;
   Float_t         MET_RefTau_GCW_pt20_phi;
   Float_t         MET_RefTau_GCW_pt20_et;
   Float_t         MET_RefTau_GCW_pt20_sumet;
   Float_t         MET_RefTau_GCW_pt20_etx_CentralReg;
   Float_t         MET_RefTau_GCW_pt20_ety_CentralReg;
   Float_t         MET_RefTau_GCW_pt20_sumet_CentralReg;
   Float_t         MET_RefTau_GCW_pt20_phi_CentralReg;
   Float_t         MET_RefTau_GCW_pt20_etx_EndcapRegion;
   Float_t         MET_RefTau_GCW_pt20_ety_EndcapRegion;
   Float_t         MET_RefTau_GCW_pt20_sumet_EndcapRegion;
   Float_t         MET_RefTau_GCW_pt20_phi_EndcapRegion;
   Float_t         MET_RefTau_GCW_pt20_etx_ForwardReg;
   Float_t         MET_RefTau_GCW_pt20_ety_ForwardReg;
   Float_t         MET_RefTau_GCW_pt20_sumet_ForwardReg;
   Float_t         MET_RefTau_GCW_pt20_phi_ForwardReg;
   Float_t         MET_RefJet_GCW_pt20_etx;
   Float_t         MET_RefJet_GCW_pt20_ety;
   Float_t         MET_RefJet_GCW_pt20_phi;
   Float_t         MET_RefJet_GCW_pt20_et;
   Float_t         MET_RefJet_GCW_pt20_sumet;
   Float_t         MET_RefJet_GCW_pt20_etx_CentralReg;
   Float_t         MET_RefJet_GCW_pt20_ety_CentralReg;
   Float_t         MET_RefJet_GCW_pt20_sumet_CentralReg;
   Float_t         MET_RefJet_GCW_pt20_phi_CentralReg;
   Float_t         MET_RefJet_GCW_pt20_etx_EndcapRegion;
   Float_t         MET_RefJet_GCW_pt20_ety_EndcapRegion;
   Float_t         MET_RefJet_GCW_pt20_sumet_EndcapRegion;
   Float_t         MET_RefJet_GCW_pt20_phi_EndcapRegion;
   Float_t         MET_RefJet_GCW_pt20_etx_ForwardReg;
   Float_t         MET_RefJet_GCW_pt20_ety_ForwardReg;
   Float_t         MET_RefJet_GCW_pt20_sumet_ForwardReg;
   Float_t         MET_RefJet_GCW_pt20_phi_ForwardReg;
   Float_t         MET_CellOut_GCW_pt20_etx;
   Float_t         MET_CellOut_GCW_pt20_ety;
   Float_t         MET_CellOut_GCW_pt20_phi;
   Float_t         MET_CellOut_GCW_pt20_et;
   Float_t         MET_CellOut_GCW_pt20_sumet;
   Float_t         MET_CellOut_GCW_pt20_etx_CentralReg;
   Float_t         MET_CellOut_GCW_pt20_ety_CentralReg;
   Float_t         MET_CellOut_GCW_pt20_sumet_CentralReg;
   Float_t         MET_CellOut_GCW_pt20_phi_CentralReg;
   Float_t         MET_CellOut_GCW_pt20_etx_EndcapRegion;
   Float_t         MET_CellOut_GCW_pt20_ety_EndcapRegion;
   Float_t         MET_CellOut_GCW_pt20_sumet_EndcapRegion;
   Float_t         MET_CellOut_GCW_pt20_phi_EndcapRegion;
   Float_t         MET_CellOut_GCW_pt20_etx_ForwardReg;
   Float_t         MET_CellOut_GCW_pt20_ety_ForwardReg;
   Float_t         MET_CellOut_GCW_pt20_sumet_ForwardReg;
   Float_t         MET_CellOut_GCW_pt20_phi_ForwardReg;
   Float_t         MET_Cryo_GCW_pt20_etx;
   Float_t         MET_Cryo_GCW_pt20_ety;
   Float_t         MET_Cryo_GCW_pt20_phi;
   Float_t         MET_Cryo_GCW_pt20_et;
   Float_t         MET_Cryo_GCW_pt20_sumet;
   Float_t         MET_Cryo_GCW_pt20_etx_CentralReg;
   Float_t         MET_Cryo_GCW_pt20_ety_CentralReg;
   Float_t         MET_Cryo_GCW_pt20_sumet_CentralReg;
   Float_t         MET_Cryo_GCW_pt20_phi_CentralReg;
   Float_t         MET_Cryo_GCW_pt20_etx_EndcapRegion;
   Float_t         MET_Cryo_GCW_pt20_ety_EndcapRegion;
   Float_t         MET_Cryo_GCW_pt20_sumet_EndcapRegion;
   Float_t         MET_Cryo_GCW_pt20_phi_EndcapRegion;
   Float_t         MET_Cryo_GCW_pt20_etx_ForwardReg;
   Float_t         MET_Cryo_GCW_pt20_ety_ForwardReg;
   Float_t         MET_Cryo_GCW_pt20_sumet_ForwardReg;
   Float_t         MET_Cryo_GCW_pt20_phi_ForwardReg;
   Float_t         MET_RefMuon_GCW_pt20_etx;
   Float_t         MET_RefMuon_GCW_pt20_ety;
   Float_t         MET_RefMuon_GCW_pt20_phi;
   Float_t         MET_RefMuon_GCW_pt20_et;
   Float_t         MET_RefMuon_GCW_pt20_sumet;
   Float_t         MET_RefMuon_Staco_GCW_pt20_etx;
   Float_t         MET_RefMuon_Staco_GCW_pt20_ety;
   Float_t         MET_RefMuon_Staco_GCW_pt20_phi;
   Float_t         MET_RefMuon_Staco_GCW_pt20_et;
   Float_t         MET_RefMuon_Staco_GCW_pt20_sumet;
   Float_t         MET_Muon_Isol_Staco_GCW_pt20_etx;
   Float_t         MET_Muon_Isol_Staco_GCW_pt20_ety;
   Float_t         MET_Muon_Isol_Staco_GCW_pt20_phi;
   Float_t         MET_Muon_Isol_Staco_GCW_pt20_et;
   Float_t         MET_Muon_Isol_Staco_GCW_pt20_sumet;
   Float_t         MET_Muon_NonIsol_Staco_GCW_pt20_etx;
   Float_t         MET_Muon_NonIsol_Staco_GCW_pt20_ety;
   Float_t         MET_Muon_NonIsol_Staco_GCW_pt20_phi;
   Float_t         MET_Muon_NonIsol_Staco_GCW_pt20_et;
   Float_t         MET_Muon_NonIsol_Staco_GCW_pt20_sumet;
   Float_t         MET_Muon_Total_Staco_GCW_pt20_etx;
   Float_t         MET_Muon_Total_Staco_GCW_pt20_ety;
   Float_t         MET_Muon_Total_Staco_GCW_pt20_phi;
   Float_t         MET_Muon_Total_Staco_GCW_pt20_et;
   Float_t         MET_Muon_Total_Staco_GCW_pt20_sumet;
   Float_t         MET_RefMuon_Track_GCW_pt20_etx;
   Float_t         MET_RefMuon_Track_GCW_pt20_ety;
   Float_t         MET_RefMuon_Track_GCW_pt20_phi;
   Float_t         MET_RefMuon_Track_GCW_pt20_et;
   Float_t         MET_RefMuon_Track_GCW_pt20_sumet;
   Float_t         MET_RefMuon_Track_Staco_GCW_pt20_etx;
   Float_t         MET_RefMuon_Track_Staco_GCW_pt20_ety;
   Float_t         MET_RefMuon_Track_Staco_GCW_pt20_phi;
   Float_t         MET_RefMuon_Track_Staco_GCW_pt20_et;
   Float_t         MET_RefMuon_Track_Staco_GCW_pt20_sumet;
   Float_t         MET_RefFinal_LCW_NI_eflow4_etx;
   Float_t         MET_RefFinal_LCW_NI_eflow4_ety;
   Float_t         MET_RefFinal_LCW_NI_eflow4_phi;
   Float_t         MET_RefFinal_LCW_NI_eflow4_et;
   Float_t         MET_RefFinal_LCW_NI_eflow4_sumet;
   Float_t         MET_RefFinal_LCW_NI_eflow4_etx_CentralReg;
   Float_t         MET_RefFinal_LCW_NI_eflow4_ety_CentralReg;
   Float_t         MET_RefFinal_LCW_NI_eflow4_sumet_CentralReg;
   Float_t         MET_RefFinal_LCW_NI_eflow4_phi_CentralReg;
   Float_t         MET_RefFinal_LCW_NI_eflow4_etx_EndcapRegion;
   Float_t         MET_RefFinal_LCW_NI_eflow4_ety_EndcapRegion;
   Float_t         MET_RefFinal_LCW_NI_eflow4_sumet_EndcapRegion;
   Float_t         MET_RefFinal_LCW_NI_eflow4_phi_EndcapRegion;
   Float_t         MET_RefFinal_LCW_NI_eflow4_etx_ForwardReg;
   Float_t         MET_RefFinal_LCW_NI_eflow4_ety_ForwardReg;
   Float_t         MET_RefFinal_LCW_NI_eflow4_sumet_ForwardReg;
   Float_t         MET_RefFinal_LCW_NI_eflow4_phi_ForwardReg;
   Float_t         MET_RefGamma_LCW_NI_eflow4_etx;
   Float_t         MET_RefGamma_LCW_NI_eflow4_ety;
   Float_t         MET_RefGamma_LCW_NI_eflow4_phi;
   Float_t         MET_RefGamma_LCW_NI_eflow4_et;
   Float_t         MET_RefGamma_LCW_NI_eflow4_sumet;
   Float_t         MET_RefGamma_LCW_NI_eflow4_etx_CentralReg;
   Float_t         MET_RefGamma_LCW_NI_eflow4_ety_CentralReg;
   Float_t         MET_RefGamma_LCW_NI_eflow4_sumet_CentralReg;
   Float_t         MET_RefGamma_LCW_NI_eflow4_phi_CentralReg;
   Float_t         MET_RefGamma_LCW_NI_eflow4_etx_EndcapRegion;
   Float_t         MET_RefGamma_LCW_NI_eflow4_ety_EndcapRegion;
   Float_t         MET_RefGamma_LCW_NI_eflow4_sumet_EndcapRegion;
   Float_t         MET_RefGamma_LCW_NI_eflow4_phi_EndcapRegion;
   Float_t         MET_RefGamma_LCW_NI_eflow4_etx_ForwardReg;
   Float_t         MET_RefGamma_LCW_NI_eflow4_ety_ForwardReg;
   Float_t         MET_RefGamma_LCW_NI_eflow4_sumet_ForwardReg;
   Float_t         MET_RefGamma_LCW_NI_eflow4_phi_ForwardReg;
   Float_t         MET_RefEle_LCW_NI_eflow4_etx;
   Float_t         MET_RefEle_LCW_NI_eflow4_ety;
   Float_t         MET_RefEle_LCW_NI_eflow4_phi;
   Float_t         MET_RefEle_LCW_NI_eflow4_et;
   Float_t         MET_RefEle_LCW_NI_eflow4_sumet;
   Float_t         MET_RefEle_LCW_NI_eflow4_etx_CentralReg;
   Float_t         MET_RefEle_LCW_NI_eflow4_ety_CentralReg;
   Float_t         MET_RefEle_LCW_NI_eflow4_sumet_CentralReg;
   Float_t         MET_RefEle_LCW_NI_eflow4_phi_CentralReg;
   Float_t         MET_RefEle_LCW_NI_eflow4_etx_EndcapRegion;
   Float_t         MET_RefEle_LCW_NI_eflow4_ety_EndcapRegion;
   Float_t         MET_RefEle_LCW_NI_eflow4_sumet_EndcapRegion;
   Float_t         MET_RefEle_LCW_NI_eflow4_phi_EndcapRegion;
   Float_t         MET_RefEle_LCW_NI_eflow4_etx_ForwardReg;
   Float_t         MET_RefEle_LCW_NI_eflow4_ety_ForwardReg;
   Float_t         MET_RefEle_LCW_NI_eflow4_sumet_ForwardReg;
   Float_t         MET_RefEle_LCW_NI_eflow4_phi_ForwardReg;
   Float_t         MET_RefTau_LCW_NI_eflow4_etx;
   Float_t         MET_RefTau_LCW_NI_eflow4_ety;
   Float_t         MET_RefTau_LCW_NI_eflow4_phi;
   Float_t         MET_RefTau_LCW_NI_eflow4_et;
   Float_t         MET_RefTau_LCW_NI_eflow4_sumet;
   Float_t         MET_RefTau_LCW_NI_eflow4_etx_CentralReg;
   Float_t         MET_RefTau_LCW_NI_eflow4_ety_CentralReg;
   Float_t         MET_RefTau_LCW_NI_eflow4_sumet_CentralReg;
   Float_t         MET_RefTau_LCW_NI_eflow4_phi_CentralReg;
   Float_t         MET_RefTau_LCW_NI_eflow4_etx_EndcapRegion;
   Float_t         MET_RefTau_LCW_NI_eflow4_ety_EndcapRegion;
   Float_t         MET_RefTau_LCW_NI_eflow4_sumet_EndcapRegion;
   Float_t         MET_RefTau_LCW_NI_eflow4_phi_EndcapRegion;
   Float_t         MET_RefTau_LCW_NI_eflow4_etx_ForwardReg;
   Float_t         MET_RefTau_LCW_NI_eflow4_ety_ForwardReg;
   Float_t         MET_RefTau_LCW_NI_eflow4_sumet_ForwardReg;
   Float_t         MET_RefTau_LCW_NI_eflow4_phi_ForwardReg;
   Float_t         MET_RefJet_LCW_NI_eflow4_etx;
   Float_t         MET_RefJet_LCW_NI_eflow4_ety;
   Float_t         MET_RefJet_LCW_NI_eflow4_phi;
   Float_t         MET_RefJet_LCW_NI_eflow4_et;
   Float_t         MET_RefJet_LCW_NI_eflow4_sumet;
   Float_t         MET_RefJet_LCW_NI_eflow4_etx_CentralReg;
   Float_t         MET_RefJet_LCW_NI_eflow4_ety_CentralReg;
   Float_t         MET_RefJet_LCW_NI_eflow4_sumet_CentralReg;
   Float_t         MET_RefJet_LCW_NI_eflow4_phi_CentralReg;
   Float_t         MET_RefJet_LCW_NI_eflow4_etx_EndcapRegion;
   Float_t         MET_RefJet_LCW_NI_eflow4_ety_EndcapRegion;
   Float_t         MET_RefJet_LCW_NI_eflow4_sumet_EndcapRegion;
   Float_t         MET_RefJet_LCW_NI_eflow4_phi_EndcapRegion;
   Float_t         MET_RefJet_LCW_NI_eflow4_etx_ForwardReg;
   Float_t         MET_RefJet_LCW_NI_eflow4_ety_ForwardReg;
   Float_t         MET_RefJet_LCW_NI_eflow4_sumet_ForwardReg;
   Float_t         MET_RefJet_LCW_NI_eflow4_phi_ForwardReg;
   Float_t         MET_CellOut_LCW_NI_eflow4_etx;
   Float_t         MET_CellOut_LCW_NI_eflow4_ety;
   Float_t         MET_CellOut_LCW_NI_eflow4_phi;
   Float_t         MET_CellOut_LCW_NI_eflow4_et;
   Float_t         MET_CellOut_LCW_NI_eflow4_sumet;
   Float_t         MET_CellOut_LCW_NI_eflow4_etx_CentralReg;
   Float_t         MET_CellOut_LCW_NI_eflow4_ety_CentralReg;
   Float_t         MET_CellOut_LCW_NI_eflow4_sumet_CentralReg;
   Float_t         MET_CellOut_LCW_NI_eflow4_phi_CentralReg;
   Float_t         MET_CellOut_LCW_NI_eflow4_etx_EndcapRegion;
   Float_t         MET_CellOut_LCW_NI_eflow4_ety_EndcapRegion;
   Float_t         MET_CellOut_LCW_NI_eflow4_sumet_EndcapRegion;
   Float_t         MET_CellOut_LCW_NI_eflow4_phi_EndcapRegion;
   Float_t         MET_CellOut_LCW_NI_eflow4_etx_ForwardReg;
   Float_t         MET_CellOut_LCW_NI_eflow4_ety_ForwardReg;
   Float_t         MET_CellOut_LCW_NI_eflow4_sumet_ForwardReg;
   Float_t         MET_CellOut_LCW_NI_eflow4_phi_ForwardReg;
   Float_t         MET_Cryo_LCW_NI_eflow4_etx;
   Float_t         MET_Cryo_LCW_NI_eflow4_ety;
   Float_t         MET_Cryo_LCW_NI_eflow4_phi;
   Float_t         MET_Cryo_LCW_NI_eflow4_et;
   Float_t         MET_Cryo_LCW_NI_eflow4_sumet;
   Float_t         MET_Cryo_LCW_NI_eflow4_etx_CentralReg;
   Float_t         MET_Cryo_LCW_NI_eflow4_ety_CentralReg;
   Float_t         MET_Cryo_LCW_NI_eflow4_sumet_CentralReg;
   Float_t         MET_Cryo_LCW_NI_eflow4_phi_CentralReg;
   Float_t         MET_Cryo_LCW_NI_eflow4_etx_EndcapRegion;
   Float_t         MET_Cryo_LCW_NI_eflow4_ety_EndcapRegion;
   Float_t         MET_Cryo_LCW_NI_eflow4_sumet_EndcapRegion;
   Float_t         MET_Cryo_LCW_NI_eflow4_phi_EndcapRegion;
   Float_t         MET_Cryo_LCW_NI_eflow4_etx_ForwardReg;
   Float_t         MET_Cryo_LCW_NI_eflow4_ety_ForwardReg;
   Float_t         MET_Cryo_LCW_NI_eflow4_sumet_ForwardReg;
   Float_t         MET_Cryo_LCW_NI_eflow4_phi_ForwardReg;
   Float_t         MET_RefMuon_LCW_NI_eflow4_etx;
   Float_t         MET_RefMuon_LCW_NI_eflow4_ety;
   Float_t         MET_RefMuon_LCW_NI_eflow4_phi;
   Float_t         MET_RefMuon_LCW_NI_eflow4_et;
   Float_t         MET_RefMuon_LCW_NI_eflow4_sumet;
   Float_t         MET_RefMuon_Staco_LCW_NI_eflow4_etx;
   Float_t         MET_RefMuon_Staco_LCW_NI_eflow4_ety;
   Float_t         MET_RefMuon_Staco_LCW_NI_eflow4_phi;
   Float_t         MET_RefMuon_Staco_LCW_NI_eflow4_et;
   Float_t         MET_RefMuon_Staco_LCW_NI_eflow4_sumet;
   Float_t         MET_Muon_Isol_Staco_LCW_NI_eflow4_etx;
   Float_t         MET_Muon_Isol_Staco_LCW_NI_eflow4_ety;
   Float_t         MET_Muon_Isol_Staco_LCW_NI_eflow4_phi;
   Float_t         MET_Muon_Isol_Staco_LCW_NI_eflow4_et;
   Float_t         MET_Muon_Isol_Staco_LCW_NI_eflow4_sumet;
   Float_t         MET_Muon_NonIsol_Staco_LCW_NI_eflow4_etx;
   Float_t         MET_Muon_NonIsol_Staco_LCW_NI_eflow4_ety;
   Float_t         MET_Muon_NonIsol_Staco_LCW_NI_eflow4_phi;
   Float_t         MET_Muon_NonIsol_Staco_LCW_NI_eflow4_et;
   Float_t         MET_Muon_NonIsol_Staco_LCW_NI_eflow4_sumet;
   Float_t         MET_Muon_Total_Staco_LCW_NI_eflow4_etx;
   Float_t         MET_Muon_Total_Staco_LCW_NI_eflow4_ety;
   Float_t         MET_Muon_Total_Staco_LCW_NI_eflow4_phi;
   Float_t         MET_Muon_Total_Staco_LCW_NI_eflow4_et;
   Float_t         MET_Muon_Total_Staco_LCW_NI_eflow4_sumet;
   Float_t         MET_RefMuon_Track_LCW_NI_eflow4_etx;
   Float_t         MET_RefMuon_Track_LCW_NI_eflow4_ety;
   Float_t         MET_RefMuon_Track_LCW_NI_eflow4_phi;
   Float_t         MET_RefMuon_Track_LCW_NI_eflow4_et;
   Float_t         MET_RefMuon_Track_LCW_NI_eflow4_sumet;
   Float_t         MET_RefMuon_Track_Staco_LCW_NI_eflow4_etx;
   Float_t         MET_RefMuon_Track_Staco_LCW_NI_eflow4_ety;
   Float_t         MET_RefMuon_Track_Staco_LCW_NI_eflow4_phi;
   Float_t         MET_RefMuon_Track_Staco_LCW_NI_eflow4_et;
   Float_t         MET_RefMuon_Track_Staco_LCW_NI_eflow4_sumet;
   Float_t         MET_RefFinal_LCW_NI_eflow_400_etx;
   Float_t         MET_RefFinal_LCW_NI_eflow_400_ety;
   Float_t         MET_RefFinal_LCW_NI_eflow_400_phi;
   Float_t         MET_RefFinal_LCW_NI_eflow_400_et;
   Float_t         MET_RefFinal_LCW_NI_eflow_400_sumet;
   Float_t         MET_RefFinal_LCW_NI_eflow_400_etx_CentralReg;
   Float_t         MET_RefFinal_LCW_NI_eflow_400_ety_CentralReg;
   Float_t         MET_RefFinal_LCW_NI_eflow_400_sumet_CentralReg;
   Float_t         MET_RefFinal_LCW_NI_eflow_400_phi_CentralReg;
   Float_t         MET_RefFinal_LCW_NI_eflow_400_etx_EndcapRegion;
   Float_t         MET_RefFinal_LCW_NI_eflow_400_ety_EndcapRegion;
   Float_t         MET_RefFinal_LCW_NI_eflow_400_sumet_EndcapRegion;
   Float_t         MET_RefFinal_LCW_NI_eflow_400_phi_EndcapRegion;
   Float_t         MET_RefFinal_LCW_NI_eflow_400_etx_ForwardReg;
   Float_t         MET_RefFinal_LCW_NI_eflow_400_ety_ForwardReg;
   Float_t         MET_RefFinal_LCW_NI_eflow_400_sumet_ForwardReg;
   Float_t         MET_RefFinal_LCW_NI_eflow_400_phi_ForwardReg;
   Float_t         MET_RefGamma_LCW_NI_eflow_400_etx;
   Float_t         MET_RefGamma_LCW_NI_eflow_400_ety;
   Float_t         MET_RefGamma_LCW_NI_eflow_400_phi;
   Float_t         MET_RefGamma_LCW_NI_eflow_400_et;
   Float_t         MET_RefGamma_LCW_NI_eflow_400_sumet;
   Float_t         MET_RefGamma_LCW_NI_eflow_400_etx_CentralReg;
   Float_t         MET_RefGamma_LCW_NI_eflow_400_ety_CentralReg;
   Float_t         MET_RefGamma_LCW_NI_eflow_400_sumet_CentralReg;
   Float_t         MET_RefGamma_LCW_NI_eflow_400_phi_CentralReg;
   Float_t         MET_RefGamma_LCW_NI_eflow_400_etx_EndcapRegion;
   Float_t         MET_RefGamma_LCW_NI_eflow_400_ety_EndcapRegion;
   Float_t         MET_RefGamma_LCW_NI_eflow_400_sumet_EndcapRegion;
   Float_t         MET_RefGamma_LCW_NI_eflow_400_phi_EndcapRegion;
   Float_t         MET_RefGamma_LCW_NI_eflow_400_etx_ForwardReg;
   Float_t         MET_RefGamma_LCW_NI_eflow_400_ety_ForwardReg;
   Float_t         MET_RefGamma_LCW_NI_eflow_400_sumet_ForwardReg;
   Float_t         MET_RefGamma_LCW_NI_eflow_400_phi_ForwardReg;
   Float_t         MET_RefEle_LCW_NI_eflow_400_etx;
   Float_t         MET_RefEle_LCW_NI_eflow_400_ety;
   Float_t         MET_RefEle_LCW_NI_eflow_400_phi;
   Float_t         MET_RefEle_LCW_NI_eflow_400_et;
   Float_t         MET_RefEle_LCW_NI_eflow_400_sumet;
   Float_t         MET_RefEle_LCW_NI_eflow_400_etx_CentralReg;
   Float_t         MET_RefEle_LCW_NI_eflow_400_ety_CentralReg;
   Float_t         MET_RefEle_LCW_NI_eflow_400_sumet_CentralReg;
   Float_t         MET_RefEle_LCW_NI_eflow_400_phi_CentralReg;
   Float_t         MET_RefEle_LCW_NI_eflow_400_etx_EndcapRegion;
   Float_t         MET_RefEle_LCW_NI_eflow_400_ety_EndcapRegion;
   Float_t         MET_RefEle_LCW_NI_eflow_400_sumet_EndcapRegion;
   Float_t         MET_RefEle_LCW_NI_eflow_400_phi_EndcapRegion;
   Float_t         MET_RefEle_LCW_NI_eflow_400_etx_ForwardReg;
   Float_t         MET_RefEle_LCW_NI_eflow_400_ety_ForwardReg;
   Float_t         MET_RefEle_LCW_NI_eflow_400_sumet_ForwardReg;
   Float_t         MET_RefEle_LCW_NI_eflow_400_phi_ForwardReg;
   Float_t         MET_RefTau_LCW_NI_eflow_400_etx;
   Float_t         MET_RefTau_LCW_NI_eflow_400_ety;
   Float_t         MET_RefTau_LCW_NI_eflow_400_phi;
   Float_t         MET_RefTau_LCW_NI_eflow_400_et;
   Float_t         MET_RefTau_LCW_NI_eflow_400_sumet;
   Float_t         MET_RefTau_LCW_NI_eflow_400_etx_CentralReg;
   Float_t         MET_RefTau_LCW_NI_eflow_400_ety_CentralReg;
   Float_t         MET_RefTau_LCW_NI_eflow_400_sumet_CentralReg;
   Float_t         MET_RefTau_LCW_NI_eflow_400_phi_CentralReg;
   Float_t         MET_RefTau_LCW_NI_eflow_400_etx_EndcapRegion;
   Float_t         MET_RefTau_LCW_NI_eflow_400_ety_EndcapRegion;
   Float_t         MET_RefTau_LCW_NI_eflow_400_sumet_EndcapRegion;
   Float_t         MET_RefTau_LCW_NI_eflow_400_phi_EndcapRegion;
   Float_t         MET_RefTau_LCW_NI_eflow_400_etx_ForwardReg;
   Float_t         MET_RefTau_LCW_NI_eflow_400_ety_ForwardReg;
   Float_t         MET_RefTau_LCW_NI_eflow_400_sumet_ForwardReg;
   Float_t         MET_RefTau_LCW_NI_eflow_400_phi_ForwardReg;
   Float_t         MET_RefJet_LCW_NI_eflow_400_etx;
   Float_t         MET_RefJet_LCW_NI_eflow_400_ety;
   Float_t         MET_RefJet_LCW_NI_eflow_400_phi;
   Float_t         MET_RefJet_LCW_NI_eflow_400_et;
   Float_t         MET_RefJet_LCW_NI_eflow_400_sumet;
   Float_t         MET_RefJet_LCW_NI_eflow_400_etx_CentralReg;
   Float_t         MET_RefJet_LCW_NI_eflow_400_ety_CentralReg;
   Float_t         MET_RefJet_LCW_NI_eflow_400_sumet_CentralReg;
   Float_t         MET_RefJet_LCW_NI_eflow_400_phi_CentralReg;
   Float_t         MET_RefJet_LCW_NI_eflow_400_etx_EndcapRegion;
   Float_t         MET_RefJet_LCW_NI_eflow_400_ety_EndcapRegion;
   Float_t         MET_RefJet_LCW_NI_eflow_400_sumet_EndcapRegion;
   Float_t         MET_RefJet_LCW_NI_eflow_400_phi_EndcapRegion;
   Float_t         MET_RefJet_LCW_NI_eflow_400_etx_ForwardReg;
   Float_t         MET_RefJet_LCW_NI_eflow_400_ety_ForwardReg;
   Float_t         MET_RefJet_LCW_NI_eflow_400_sumet_ForwardReg;
   Float_t         MET_RefJet_LCW_NI_eflow_400_phi_ForwardReg;
   Float_t         MET_CellOut_LCW_NI_eflow_400_etx;
   Float_t         MET_CellOut_LCW_NI_eflow_400_ety;
   Float_t         MET_CellOut_LCW_NI_eflow_400_phi;
   Float_t         MET_CellOut_LCW_NI_eflow_400_et;
   Float_t         MET_CellOut_LCW_NI_eflow_400_sumet;
   Float_t         MET_CellOut_LCW_NI_eflow_400_etx_CentralReg;
   Float_t         MET_CellOut_LCW_NI_eflow_400_ety_CentralReg;
   Float_t         MET_CellOut_LCW_NI_eflow_400_sumet_CentralReg;
   Float_t         MET_CellOut_LCW_NI_eflow_400_phi_CentralReg;
   Float_t         MET_CellOut_LCW_NI_eflow_400_etx_EndcapRegion;
   Float_t         MET_CellOut_LCW_NI_eflow_400_ety_EndcapRegion;
   Float_t         MET_CellOut_LCW_NI_eflow_400_sumet_EndcapRegion;
   Float_t         MET_CellOut_LCW_NI_eflow_400_phi_EndcapRegion;
   Float_t         MET_CellOut_LCW_NI_eflow_400_etx_ForwardReg;
   Float_t         MET_CellOut_LCW_NI_eflow_400_ety_ForwardReg;
   Float_t         MET_CellOut_LCW_NI_eflow_400_sumet_ForwardReg;
   Float_t         MET_CellOut_LCW_NI_eflow_400_phi_ForwardReg;
   Float_t         MET_Cryo_LCW_NI_eflow_400_etx;
   Float_t         MET_Cryo_LCW_NI_eflow_400_ety;
   Float_t         MET_Cryo_LCW_NI_eflow_400_phi;
   Float_t         MET_Cryo_LCW_NI_eflow_400_et;
   Float_t         MET_Cryo_LCW_NI_eflow_400_sumet;
   Float_t         MET_Cryo_LCW_NI_eflow_400_etx_CentralReg;
   Float_t         MET_Cryo_LCW_NI_eflow_400_ety_CentralReg;
   Float_t         MET_Cryo_LCW_NI_eflow_400_sumet_CentralReg;
   Float_t         MET_Cryo_LCW_NI_eflow_400_phi_CentralReg;
   Float_t         MET_Cryo_LCW_NI_eflow_400_etx_EndcapRegion;
   Float_t         MET_Cryo_LCW_NI_eflow_400_ety_EndcapRegion;
   Float_t         MET_Cryo_LCW_NI_eflow_400_sumet_EndcapRegion;
   Float_t         MET_Cryo_LCW_NI_eflow_400_phi_EndcapRegion;
   Float_t         MET_Cryo_LCW_NI_eflow_400_etx_ForwardReg;
   Float_t         MET_Cryo_LCW_NI_eflow_400_ety_ForwardReg;
   Float_t         MET_Cryo_LCW_NI_eflow_400_sumet_ForwardReg;
   Float_t         MET_Cryo_LCW_NI_eflow_400_phi_ForwardReg;
   Float_t         MET_RefMuon_LCW_NI_eflow_400_etx;
   Float_t         MET_RefMuon_LCW_NI_eflow_400_ety;
   Float_t         MET_RefMuon_LCW_NI_eflow_400_phi;
   Float_t         MET_RefMuon_LCW_NI_eflow_400_et;
   Float_t         MET_RefMuon_LCW_NI_eflow_400_sumet;
   Float_t         MET_RefMuon_Staco_LCW_NI_eflow_400_etx;
   Float_t         MET_RefMuon_Staco_LCW_NI_eflow_400_ety;
   Float_t         MET_RefMuon_Staco_LCW_NI_eflow_400_phi;
   Float_t         MET_RefMuon_Staco_LCW_NI_eflow_400_et;
   Float_t         MET_RefMuon_Staco_LCW_NI_eflow_400_sumet;
   Float_t         MET_Muon_Isol_Staco_LCW_NI_eflow_400_etx;
   Float_t         MET_Muon_Isol_Staco_LCW_NI_eflow_400_ety;
   Float_t         MET_Muon_Isol_Staco_LCW_NI_eflow_400_phi;
   Float_t         MET_Muon_Isol_Staco_LCW_NI_eflow_400_et;
   Float_t         MET_Muon_Isol_Staco_LCW_NI_eflow_400_sumet;
   Float_t         MET_Muon_NonIsol_Staco_LCW_NI_eflow_400_etx;
   Float_t         MET_Muon_NonIsol_Staco_LCW_NI_eflow_400_ety;
   Float_t         MET_Muon_NonIsol_Staco_LCW_NI_eflow_400_phi;
   Float_t         MET_Muon_NonIsol_Staco_LCW_NI_eflow_400_et;
   Float_t         MET_Muon_NonIsol_Staco_LCW_NI_eflow_400_sumet;
   Float_t         MET_Muon_Total_Staco_LCW_NI_eflow_400_etx;
   Float_t         MET_Muon_Total_Staco_LCW_NI_eflow_400_ety;
   Float_t         MET_Muon_Total_Staco_LCW_NI_eflow_400_phi;
   Float_t         MET_Muon_Total_Staco_LCW_NI_eflow_400_et;
   Float_t         MET_Muon_Total_Staco_LCW_NI_eflow_400_sumet;
   Float_t         MET_RefMuon_Track_LCW_NI_eflow_400_etx;
   Float_t         MET_RefMuon_Track_LCW_NI_eflow_400_ety;
   Float_t         MET_RefMuon_Track_LCW_NI_eflow_400_phi;
   Float_t         MET_RefMuon_Track_LCW_NI_eflow_400_et;
   Float_t         MET_RefMuon_Track_LCW_NI_eflow_400_sumet;
   Float_t         MET_RefMuon_Track_Staco_LCW_NI_eflow_400_etx;
   Float_t         MET_RefMuon_Track_Staco_LCW_NI_eflow_400_ety;
   Float_t         MET_RefMuon_Track_Staco_LCW_NI_eflow_400_phi;
   Float_t         MET_RefMuon_Track_Staco_LCW_NI_eflow_400_et;
   Float_t         MET_RefMuon_Track_Staco_LCW_NI_eflow_400_sumet;
   Float_t         MET_RefFinal_LCW_pt20_etx;
   Float_t         MET_RefFinal_LCW_pt20_ety;
   Float_t         MET_RefFinal_LCW_pt20_phi;
   Float_t         MET_RefFinal_LCW_pt20_et;
   Float_t         MET_RefFinal_LCW_pt20_sumet;
   Float_t         MET_RefFinal_LCW_pt20_etx_CentralReg;
   Float_t         MET_RefFinal_LCW_pt20_ety_CentralReg;
   Float_t         MET_RefFinal_LCW_pt20_sumet_CentralReg;
   Float_t         MET_RefFinal_LCW_pt20_phi_CentralReg;
   Float_t         MET_RefFinal_LCW_pt20_etx_EndcapRegion;
   Float_t         MET_RefFinal_LCW_pt20_ety_EndcapRegion;
   Float_t         MET_RefFinal_LCW_pt20_sumet_EndcapRegion;
   Float_t         MET_RefFinal_LCW_pt20_phi_EndcapRegion;
   Float_t         MET_RefFinal_LCW_pt20_etx_ForwardReg;
   Float_t         MET_RefFinal_LCW_pt20_ety_ForwardReg;
   Float_t         MET_RefFinal_LCW_pt20_sumet_ForwardReg;
   Float_t         MET_RefFinal_LCW_pt20_phi_ForwardReg;
   Float_t         MET_RefGamma_LCW_pt20_etx;
   Float_t         MET_RefGamma_LCW_pt20_ety;
   Float_t         MET_RefGamma_LCW_pt20_phi;
   Float_t         MET_RefGamma_LCW_pt20_et;
   Float_t         MET_RefGamma_LCW_pt20_sumet;
   Float_t         MET_RefGamma_LCW_pt20_etx_CentralReg;
   Float_t         MET_RefGamma_LCW_pt20_ety_CentralReg;
   Float_t         MET_RefGamma_LCW_pt20_sumet_CentralReg;
   Float_t         MET_RefGamma_LCW_pt20_phi_CentralReg;
   Float_t         MET_RefGamma_LCW_pt20_etx_EndcapRegion;
   Float_t         MET_RefGamma_LCW_pt20_ety_EndcapRegion;
   Float_t         MET_RefGamma_LCW_pt20_sumet_EndcapRegion;
   Float_t         MET_RefGamma_LCW_pt20_phi_EndcapRegion;
   Float_t         MET_RefGamma_LCW_pt20_etx_ForwardReg;
   Float_t         MET_RefGamma_LCW_pt20_ety_ForwardReg;
   Float_t         MET_RefGamma_LCW_pt20_sumet_ForwardReg;
   Float_t         MET_RefGamma_LCW_pt20_phi_ForwardReg;
   Float_t         MET_RefEle_LCW_pt20_etx;
   Float_t         MET_RefEle_LCW_pt20_ety;
   Float_t         MET_RefEle_LCW_pt20_phi;
   Float_t         MET_RefEle_LCW_pt20_et;
   Float_t         MET_RefEle_LCW_pt20_sumet;
   Float_t         MET_RefEle_LCW_pt20_etx_CentralReg;
   Float_t         MET_RefEle_LCW_pt20_ety_CentralReg;
   Float_t         MET_RefEle_LCW_pt20_sumet_CentralReg;
   Float_t         MET_RefEle_LCW_pt20_phi_CentralReg;
   Float_t         MET_RefEle_LCW_pt20_etx_EndcapRegion;
   Float_t         MET_RefEle_LCW_pt20_ety_EndcapRegion;
   Float_t         MET_RefEle_LCW_pt20_sumet_EndcapRegion;
   Float_t         MET_RefEle_LCW_pt20_phi_EndcapRegion;
   Float_t         MET_RefEle_LCW_pt20_etx_ForwardReg;
   Float_t         MET_RefEle_LCW_pt20_ety_ForwardReg;
   Float_t         MET_RefEle_LCW_pt20_sumet_ForwardReg;
   Float_t         MET_RefEle_LCW_pt20_phi_ForwardReg;
   Float_t         MET_RefTau_LCW_pt20_etx;
   Float_t         MET_RefTau_LCW_pt20_ety;
   Float_t         MET_RefTau_LCW_pt20_phi;
   Float_t         MET_RefTau_LCW_pt20_et;
   Float_t         MET_RefTau_LCW_pt20_sumet;
   Float_t         MET_RefTau_LCW_pt20_etx_CentralReg;
   Float_t         MET_RefTau_LCW_pt20_ety_CentralReg;
   Float_t         MET_RefTau_LCW_pt20_sumet_CentralReg;
   Float_t         MET_RefTau_LCW_pt20_phi_CentralReg;
   Float_t         MET_RefTau_LCW_pt20_etx_EndcapRegion;
   Float_t         MET_RefTau_LCW_pt20_ety_EndcapRegion;
   Float_t         MET_RefTau_LCW_pt20_sumet_EndcapRegion;
   Float_t         MET_RefTau_LCW_pt20_phi_EndcapRegion;
   Float_t         MET_RefTau_LCW_pt20_etx_ForwardReg;
   Float_t         MET_RefTau_LCW_pt20_ety_ForwardReg;
   Float_t         MET_RefTau_LCW_pt20_sumet_ForwardReg;
   Float_t         MET_RefTau_LCW_pt20_phi_ForwardReg;
   Float_t         MET_RefJet_LCW_pt20_etx;
   Float_t         MET_RefJet_LCW_pt20_ety;
   Float_t         MET_RefJet_LCW_pt20_phi;
   Float_t         MET_RefJet_LCW_pt20_et;
   Float_t         MET_RefJet_LCW_pt20_sumet;
   Float_t         MET_RefJet_LCW_pt20_etx_CentralReg;
   Float_t         MET_RefJet_LCW_pt20_ety_CentralReg;
   Float_t         MET_RefJet_LCW_pt20_sumet_CentralReg;
   Float_t         MET_RefJet_LCW_pt20_phi_CentralReg;
   Float_t         MET_RefJet_LCW_pt20_etx_EndcapRegion;
   Float_t         MET_RefJet_LCW_pt20_ety_EndcapRegion;
   Float_t         MET_RefJet_LCW_pt20_sumet_EndcapRegion;
   Float_t         MET_RefJet_LCW_pt20_phi_EndcapRegion;
   Float_t         MET_RefJet_LCW_pt20_etx_ForwardReg;
   Float_t         MET_RefJet_LCW_pt20_ety_ForwardReg;
   Float_t         MET_RefJet_LCW_pt20_sumet_ForwardReg;
   Float_t         MET_RefJet_LCW_pt20_phi_ForwardReg;
   Float_t         MET_CellOut_LCW_pt20_etx;
   Float_t         MET_CellOut_LCW_pt20_ety;
   Float_t         MET_CellOut_LCW_pt20_phi;
   Float_t         MET_CellOut_LCW_pt20_et;
   Float_t         MET_CellOut_LCW_pt20_sumet;
   Float_t         MET_CellOut_LCW_pt20_etx_CentralReg;
   Float_t         MET_CellOut_LCW_pt20_ety_CentralReg;
   Float_t         MET_CellOut_LCW_pt20_sumet_CentralReg;
   Float_t         MET_CellOut_LCW_pt20_phi_CentralReg;
   Float_t         MET_CellOut_LCW_pt20_etx_EndcapRegion;
   Float_t         MET_CellOut_LCW_pt20_ety_EndcapRegion;
   Float_t         MET_CellOut_LCW_pt20_sumet_EndcapRegion;
   Float_t         MET_CellOut_LCW_pt20_phi_EndcapRegion;
   Float_t         MET_CellOut_LCW_pt20_etx_ForwardReg;
   Float_t         MET_CellOut_LCW_pt20_ety_ForwardReg;
   Float_t         MET_CellOut_LCW_pt20_sumet_ForwardReg;
   Float_t         MET_CellOut_LCW_pt20_phi_ForwardReg;
   Float_t         MET_Cryo_LCW_pt20_etx;
   Float_t         MET_Cryo_LCW_pt20_ety;
   Float_t         MET_Cryo_LCW_pt20_phi;
   Float_t         MET_Cryo_LCW_pt20_et;
   Float_t         MET_Cryo_LCW_pt20_sumet;
   Float_t         MET_Cryo_LCW_pt20_etx_CentralReg;
   Float_t         MET_Cryo_LCW_pt20_ety_CentralReg;
   Float_t         MET_Cryo_LCW_pt20_sumet_CentralReg;
   Float_t         MET_Cryo_LCW_pt20_phi_CentralReg;
   Float_t         MET_Cryo_LCW_pt20_etx_EndcapRegion;
   Float_t         MET_Cryo_LCW_pt20_ety_EndcapRegion;
   Float_t         MET_Cryo_LCW_pt20_sumet_EndcapRegion;
   Float_t         MET_Cryo_LCW_pt20_phi_EndcapRegion;
   Float_t         MET_Cryo_LCW_pt20_etx_ForwardReg;
   Float_t         MET_Cryo_LCW_pt20_ety_ForwardReg;
   Float_t         MET_Cryo_LCW_pt20_sumet_ForwardReg;
   Float_t         MET_Cryo_LCW_pt20_phi_ForwardReg;
   Float_t         MET_RefMuon_LCW_pt20_etx;
   Float_t         MET_RefMuon_LCW_pt20_ety;
   Float_t         MET_RefMuon_LCW_pt20_phi;
   Float_t         MET_RefMuon_LCW_pt20_et;
   Float_t         MET_RefMuon_LCW_pt20_sumet;
   Float_t         MET_RefMuon_Muid_LCW_pt20_etx;
   Float_t         MET_RefMuon_Muid_LCW_pt20_ety;
   Float_t         MET_RefMuon_Muid_LCW_pt20_phi;
   Float_t         MET_RefMuon_Muid_LCW_pt20_et;
   Float_t         MET_RefMuon_Muid_LCW_pt20_sumet;
   Float_t         MET_Muon_Isol_Muid_LCW_pt20_etx;
   Float_t         MET_Muon_Isol_Muid_LCW_pt20_ety;
   Float_t         MET_Muon_Isol_Muid_LCW_pt20_phi;
   Float_t         MET_Muon_Isol_Muid_LCW_pt20_et;
   Float_t         MET_Muon_Isol_Muid_LCW_pt20_sumet;
   Float_t         MET_Muon_NonIsol_Muid_LCW_pt20_etx;
   Float_t         MET_Muon_NonIsol_Muid_LCW_pt20_ety;
   Float_t         MET_Muon_NonIsol_Muid_LCW_pt20_phi;
   Float_t         MET_Muon_NonIsol_Muid_LCW_pt20_et;
   Float_t         MET_Muon_NonIsol_Muid_LCW_pt20_sumet;
   Float_t         MET_Muon_Total_Muid_LCW_pt20_etx;
   Float_t         MET_Muon_Total_Muid_LCW_pt20_ety;
   Float_t         MET_Muon_Total_Muid_LCW_pt20_phi;
   Float_t         MET_Muon_Total_Muid_LCW_pt20_et;
   Float_t         MET_Muon_Total_Muid_LCW_pt20_sumet;
   Float_t         MET_RefMuon_Track_LCW_pt20_etx;
   Float_t         MET_RefMuon_Track_LCW_pt20_ety;
   Float_t         MET_RefMuon_Track_LCW_pt20_phi;
   Float_t         MET_RefMuon_Track_LCW_pt20_et;
   Float_t         MET_RefMuon_Track_LCW_pt20_sumet;
   Float_t         MET_RefMuon_Track_Muid_LCW_pt20_etx;
   Float_t         MET_RefMuon_Track_Muid_LCW_pt20_ety;
   Float_t         MET_RefMuon_Track_Muid_LCW_pt20_phi;
   Float_t         MET_RefMuon_Track_Muid_LCW_pt20_et;
   Float_t         MET_RefMuon_Track_Muid_LCW_pt20_sumet;
   Float_t         MET_RefFinal_New_etx;
   Float_t         MET_RefFinal_New_ety;
   Float_t         MET_RefFinal_New_phi;
   Float_t         MET_RefFinal_New_et;
   Float_t         MET_RefFinal_New_sumet;
   Float_t         MET_RefFinal_New_etx_CentralReg;
   Float_t         MET_RefFinal_New_ety_CentralReg;
   Float_t         MET_RefFinal_New_sumet_CentralReg;
   Float_t         MET_RefFinal_New_phi_CentralReg;
   Float_t         MET_RefFinal_New_etx_EndcapRegion;
   Float_t         MET_RefFinal_New_ety_EndcapRegion;
   Float_t         MET_RefFinal_New_sumet_EndcapRegion;
   Float_t         MET_RefFinal_New_phi_EndcapRegion;
   Float_t         MET_RefFinal_New_etx_ForwardReg;
   Float_t         MET_RefFinal_New_ety_ForwardReg;
   Float_t         MET_RefFinal_New_sumet_ForwardReg;
   Float_t         MET_RefFinal_New_phi_ForwardReg;
   Float_t         MET_RefGamma_New_etx;
   Float_t         MET_RefGamma_New_ety;
   Float_t         MET_RefGamma_New_phi;
   Float_t         MET_RefGamma_New_et;
   Float_t         MET_RefGamma_New_sumet;
   Float_t         MET_RefGamma_New_etx_CentralReg;
   Float_t         MET_RefGamma_New_ety_CentralReg;
   Float_t         MET_RefGamma_New_sumet_CentralReg;
   Float_t         MET_RefGamma_New_phi_CentralReg;
   Float_t         MET_RefGamma_New_etx_EndcapRegion;
   Float_t         MET_RefGamma_New_ety_EndcapRegion;
   Float_t         MET_RefGamma_New_sumet_EndcapRegion;
   Float_t         MET_RefGamma_New_phi_EndcapRegion;
   Float_t         MET_RefGamma_New_etx_ForwardReg;
   Float_t         MET_RefGamma_New_ety_ForwardReg;
   Float_t         MET_RefGamma_New_sumet_ForwardReg;
   Float_t         MET_RefGamma_New_phi_ForwardReg;
   Float_t         MET_RefEle_New_etx;
   Float_t         MET_RefEle_New_ety;
   Float_t         MET_RefEle_New_phi;
   Float_t         MET_RefEle_New_et;
   Float_t         MET_RefEle_New_sumet;
   Float_t         MET_RefEle_New_etx_CentralReg;
   Float_t         MET_RefEle_New_ety_CentralReg;
   Float_t         MET_RefEle_New_sumet_CentralReg;
   Float_t         MET_RefEle_New_phi_CentralReg;
   Float_t         MET_RefEle_New_etx_EndcapRegion;
   Float_t         MET_RefEle_New_ety_EndcapRegion;
   Float_t         MET_RefEle_New_sumet_EndcapRegion;
   Float_t         MET_RefEle_New_phi_EndcapRegion;
   Float_t         MET_RefEle_New_etx_ForwardReg;
   Float_t         MET_RefEle_New_ety_ForwardReg;
   Float_t         MET_RefEle_New_sumet_ForwardReg;
   Float_t         MET_RefEle_New_phi_ForwardReg;
   Float_t         MET_RefTau_New_etx;
   Float_t         MET_RefTau_New_ety;
   Float_t         MET_RefTau_New_phi;
   Float_t         MET_RefTau_New_et;
   Float_t         MET_RefTau_New_sumet;
   Float_t         MET_RefTau_New_etx_CentralReg;
   Float_t         MET_RefTau_New_ety_CentralReg;
   Float_t         MET_RefTau_New_sumet_CentralReg;
   Float_t         MET_RefTau_New_phi_CentralReg;
   Float_t         MET_RefTau_New_etx_EndcapRegion;
   Float_t         MET_RefTau_New_ety_EndcapRegion;
   Float_t         MET_RefTau_New_sumet_EndcapRegion;
   Float_t         MET_RefTau_New_phi_EndcapRegion;
   Float_t         MET_RefTau_New_etx_ForwardReg;
   Float_t         MET_RefTau_New_ety_ForwardReg;
   Float_t         MET_RefTau_New_sumet_ForwardReg;
   Float_t         MET_RefTau_New_phi_ForwardReg;
   Float_t         MET_RefJet_New_etx;
   Float_t         MET_RefJet_New_ety;
   Float_t         MET_RefJet_New_phi;
   Float_t         MET_RefJet_New_et;
   Float_t         MET_RefJet_New_sumet;
   Float_t         MET_RefJet_New_etx_CentralReg;
   Float_t         MET_RefJet_New_ety_CentralReg;
   Float_t         MET_RefJet_New_sumet_CentralReg;
   Float_t         MET_RefJet_New_phi_CentralReg;
   Float_t         MET_RefJet_New_etx_EndcapRegion;
   Float_t         MET_RefJet_New_ety_EndcapRegion;
   Float_t         MET_RefJet_New_sumet_EndcapRegion;
   Float_t         MET_RefJet_New_phi_EndcapRegion;
   Float_t         MET_RefJet_New_etx_ForwardReg;
   Float_t         MET_RefJet_New_ety_ForwardReg;
   Float_t         MET_RefJet_New_sumet_ForwardReg;
   Float_t         MET_RefJet_New_phi_ForwardReg;
   Float_t         MET_CellOut_New_etx;
   Float_t         MET_CellOut_New_ety;
   Float_t         MET_CellOut_New_phi;
   Float_t         MET_CellOut_New_et;
   Float_t         MET_CellOut_New_sumet;
   Float_t         MET_CellOut_New_etx_CentralReg;
   Float_t         MET_CellOut_New_ety_CentralReg;
   Float_t         MET_CellOut_New_sumet_CentralReg;
   Float_t         MET_CellOut_New_phi_CentralReg;
   Float_t         MET_CellOut_New_etx_EndcapRegion;
   Float_t         MET_CellOut_New_ety_EndcapRegion;
   Float_t         MET_CellOut_New_sumet_EndcapRegion;
   Float_t         MET_CellOut_New_phi_EndcapRegion;
   Float_t         MET_CellOut_New_etx_ForwardReg;
   Float_t         MET_CellOut_New_ety_ForwardReg;
   Float_t         MET_CellOut_New_sumet_ForwardReg;
   Float_t         MET_CellOut_New_phi_ForwardReg;
   Float_t         MET_Cryo_New_etx;
   Float_t         MET_Cryo_New_ety;
   Float_t         MET_Cryo_New_phi;
   Float_t         MET_Cryo_New_et;
   Float_t         MET_Cryo_New_sumet;
   Float_t         MET_Cryo_New_etx_CentralReg;
   Float_t         MET_Cryo_New_ety_CentralReg;
   Float_t         MET_Cryo_New_sumet_CentralReg;
   Float_t         MET_Cryo_New_phi_CentralReg;
   Float_t         MET_Cryo_New_etx_EndcapRegion;
   Float_t         MET_Cryo_New_ety_EndcapRegion;
   Float_t         MET_Cryo_New_sumet_EndcapRegion;
   Float_t         MET_Cryo_New_phi_EndcapRegion;
   Float_t         MET_Cryo_New_etx_ForwardReg;
   Float_t         MET_Cryo_New_ety_ForwardReg;
   Float_t         MET_Cryo_New_sumet_ForwardReg;
   Float_t         MET_Cryo_New_phi_ForwardReg;
   Float_t         MET_RefFinal_New_em_etx;
   Float_t         MET_RefFinal_New_em_ety;
   Float_t         MET_RefFinal_New_em_phi;
   Float_t         MET_RefFinal_New_em_et;
   Float_t         MET_RefFinal_New_em_sumet;
   Float_t         MET_RefFinal_New_em_etx_CentralReg;
   Float_t         MET_RefFinal_New_em_ety_CentralReg;
   Float_t         MET_RefFinal_New_em_sumet_CentralReg;
   Float_t         MET_RefFinal_New_em_phi_CentralReg;
   Float_t         MET_RefFinal_New_em_etx_EndcapRegion;
   Float_t         MET_RefFinal_New_em_ety_EndcapRegion;
   Float_t         MET_RefFinal_New_em_sumet_EndcapRegion;
   Float_t         MET_RefFinal_New_em_phi_EndcapRegion;
   Float_t         MET_RefFinal_New_em_etx_ForwardReg;
   Float_t         MET_RefFinal_New_em_ety_ForwardReg;
   Float_t         MET_RefFinal_New_em_sumet_ForwardReg;
   Float_t         MET_RefFinal_New_em_phi_ForwardReg;
   Float_t         MET_RefGamma_New_em_etx;
   Float_t         MET_RefGamma_New_em_ety;
   Float_t         MET_RefGamma_New_em_phi;
   Float_t         MET_RefGamma_New_em_et;
   Float_t         MET_RefGamma_New_em_sumet;
   Float_t         MET_RefGamma_New_em_etx_CentralReg;
   Float_t         MET_RefGamma_New_em_ety_CentralReg;
   Float_t         MET_RefGamma_New_em_sumet_CentralReg;
   Float_t         MET_RefGamma_New_em_phi_CentralReg;
   Float_t         MET_RefGamma_New_em_etx_EndcapRegion;
   Float_t         MET_RefGamma_New_em_ety_EndcapRegion;
   Float_t         MET_RefGamma_New_em_sumet_EndcapRegion;
   Float_t         MET_RefGamma_New_em_phi_EndcapRegion;
   Float_t         MET_RefGamma_New_em_etx_ForwardReg;
   Float_t         MET_RefGamma_New_em_ety_ForwardReg;
   Float_t         MET_RefGamma_New_em_sumet_ForwardReg;
   Float_t         MET_RefGamma_New_em_phi_ForwardReg;
   Float_t         MET_RefEle_New_em_etx;
   Float_t         MET_RefEle_New_em_ety;
   Float_t         MET_RefEle_New_em_phi;
   Float_t         MET_RefEle_New_em_et;
   Float_t         MET_RefEle_New_em_sumet;
   Float_t         MET_RefEle_New_em_etx_CentralReg;
   Float_t         MET_RefEle_New_em_ety_CentralReg;
   Float_t         MET_RefEle_New_em_sumet_CentralReg;
   Float_t         MET_RefEle_New_em_phi_CentralReg;
   Float_t         MET_RefEle_New_em_etx_EndcapRegion;
   Float_t         MET_RefEle_New_em_ety_EndcapRegion;
   Float_t         MET_RefEle_New_em_sumet_EndcapRegion;
   Float_t         MET_RefEle_New_em_phi_EndcapRegion;
   Float_t         MET_RefEle_New_em_etx_ForwardReg;
   Float_t         MET_RefEle_New_em_ety_ForwardReg;
   Float_t         MET_RefEle_New_em_sumet_ForwardReg;
   Float_t         MET_RefEle_New_em_phi_ForwardReg;
   Float_t         MET_RefTau_New_em_etx;
   Float_t         MET_RefTau_New_em_ety;
   Float_t         MET_RefTau_New_em_phi;
   Float_t         MET_RefTau_New_em_et;
   Float_t         MET_RefTau_New_em_sumet;
   Float_t         MET_RefTau_New_em_etx_CentralReg;
   Float_t         MET_RefTau_New_em_ety_CentralReg;
   Float_t         MET_RefTau_New_em_sumet_CentralReg;
   Float_t         MET_RefTau_New_em_phi_CentralReg;
   Float_t         MET_RefTau_New_em_etx_EndcapRegion;
   Float_t         MET_RefTau_New_em_ety_EndcapRegion;
   Float_t         MET_RefTau_New_em_sumet_EndcapRegion;
   Float_t         MET_RefTau_New_em_phi_EndcapRegion;
   Float_t         MET_RefTau_New_em_etx_ForwardReg;
   Float_t         MET_RefTau_New_em_ety_ForwardReg;
   Float_t         MET_RefTau_New_em_sumet_ForwardReg;
   Float_t         MET_RefTau_New_em_phi_ForwardReg;
   Float_t         MET_RefJet_New_em_etx;
   Float_t         MET_RefJet_New_em_ety;
   Float_t         MET_RefJet_New_em_phi;
   Float_t         MET_RefJet_New_em_et;
   Float_t         MET_RefJet_New_em_sumet;
   Float_t         MET_RefJet_New_em_etx_CentralReg;
   Float_t         MET_RefJet_New_em_ety_CentralReg;
   Float_t         MET_RefJet_New_em_sumet_CentralReg;
   Float_t         MET_RefJet_New_em_phi_CentralReg;
   Float_t         MET_RefJet_New_em_etx_EndcapRegion;
   Float_t         MET_RefJet_New_em_ety_EndcapRegion;
   Float_t         MET_RefJet_New_em_sumet_EndcapRegion;
   Float_t         MET_RefJet_New_em_phi_EndcapRegion;
   Float_t         MET_RefJet_New_em_etx_ForwardReg;
   Float_t         MET_RefJet_New_em_ety_ForwardReg;
   Float_t         MET_RefJet_New_em_sumet_ForwardReg;
   Float_t         MET_RefJet_New_em_phi_ForwardReg;
   Float_t         MET_CellOut_New_em_etx;
   Float_t         MET_CellOut_New_em_ety;
   Float_t         MET_CellOut_New_em_phi;
   Float_t         MET_CellOut_New_em_et;
   Float_t         MET_CellOut_New_em_sumet;
   Float_t         MET_CellOut_New_em_etx_CentralReg;
   Float_t         MET_CellOut_New_em_ety_CentralReg;
   Float_t         MET_CellOut_New_em_sumet_CentralReg;
   Float_t         MET_CellOut_New_em_phi_CentralReg;
   Float_t         MET_CellOut_New_em_etx_EndcapRegion;
   Float_t         MET_CellOut_New_em_ety_EndcapRegion;
   Float_t         MET_CellOut_New_em_sumet_EndcapRegion;
   Float_t         MET_CellOut_New_em_phi_EndcapRegion;
   Float_t         MET_CellOut_New_em_etx_ForwardReg;
   Float_t         MET_CellOut_New_em_ety_ForwardReg;
   Float_t         MET_CellOut_New_em_sumet_ForwardReg;
   Float_t         MET_CellOut_New_em_phi_ForwardReg;
   Float_t         MET_Cryo_New_em_etx;
   Float_t         MET_Cryo_New_em_ety;
   Float_t         MET_Cryo_New_em_phi;
   Float_t         MET_Cryo_New_em_et;
   Float_t         MET_Cryo_New_em_sumet;
   Float_t         MET_Cryo_New_em_etx_CentralReg;
   Float_t         MET_Cryo_New_em_ety_CentralReg;
   Float_t         MET_Cryo_New_em_sumet_CentralReg;
   Float_t         MET_Cryo_New_em_phi_CentralReg;
   Float_t         MET_Cryo_New_em_etx_EndcapRegion;
   Float_t         MET_Cryo_New_em_ety_EndcapRegion;
   Float_t         MET_Cryo_New_em_sumet_EndcapRegion;
   Float_t         MET_Cryo_New_em_phi_EndcapRegion;
   Float_t         MET_Cryo_New_em_etx_ForwardReg;
   Float_t         MET_Cryo_New_em_ety_ForwardReg;
   Float_t         MET_Cryo_New_em_sumet_ForwardReg;
   Float_t         MET_Cryo_New_em_phi_ForwardReg;
   Float_t         MET_RefFinal_LCW_CB_eflow_etx;
   Float_t         MET_RefFinal_LCW_CB_eflow_ety;
   Float_t         MET_RefFinal_LCW_CB_eflow_phi;
   Float_t         MET_RefFinal_LCW_CB_eflow_et;
   Float_t         MET_RefFinal_LCW_CB_eflow_sumet;
   Float_t         MET_RefFinal_LCW_CB_eflow_etx_CentralReg;
   Float_t         MET_RefFinal_LCW_CB_eflow_ety_CentralReg;
   Float_t         MET_RefFinal_LCW_CB_eflow_sumet_CentralReg;
   Float_t         MET_RefFinal_LCW_CB_eflow_phi_CentralReg;
   Float_t         MET_RefFinal_LCW_CB_eflow_etx_EndcapRegion;
   Float_t         MET_RefFinal_LCW_CB_eflow_ety_EndcapRegion;
   Float_t         MET_RefFinal_LCW_CB_eflow_sumet_EndcapRegion;
   Float_t         MET_RefFinal_LCW_CB_eflow_phi_EndcapRegion;
   Float_t         MET_RefFinal_LCW_CB_eflow_etx_ForwardReg;
   Float_t         MET_RefFinal_LCW_CB_eflow_ety_ForwardReg;
   Float_t         MET_RefFinal_LCW_CB_eflow_sumet_ForwardReg;
   Float_t         MET_RefFinal_LCW_CB_eflow_phi_ForwardReg;
   Float_t         MET_RefGamma_LCW_CB_eflow_etx;
   Float_t         MET_RefGamma_LCW_CB_eflow_ety;
   Float_t         MET_RefGamma_LCW_CB_eflow_phi;
   Float_t         MET_RefGamma_LCW_CB_eflow_et;
   Float_t         MET_RefGamma_LCW_CB_eflow_sumet;
   Float_t         MET_RefGamma_LCW_CB_eflow_etx_CentralReg;
   Float_t         MET_RefGamma_LCW_CB_eflow_ety_CentralReg;
   Float_t         MET_RefGamma_LCW_CB_eflow_sumet_CentralReg;
   Float_t         MET_RefGamma_LCW_CB_eflow_phi_CentralReg;
   Float_t         MET_RefGamma_LCW_CB_eflow_etx_EndcapRegion;
   Float_t         MET_RefGamma_LCW_CB_eflow_ety_EndcapRegion;
   Float_t         MET_RefGamma_LCW_CB_eflow_sumet_EndcapRegion;
   Float_t         MET_RefGamma_LCW_CB_eflow_phi_EndcapRegion;
   Float_t         MET_RefGamma_LCW_CB_eflow_etx_ForwardReg;
   Float_t         MET_RefGamma_LCW_CB_eflow_ety_ForwardReg;
   Float_t         MET_RefGamma_LCW_CB_eflow_sumet_ForwardReg;
   Float_t         MET_RefGamma_LCW_CB_eflow_phi_ForwardReg;
   Float_t         MET_RefEle_LCW_CB_eflow_etx;
   Float_t         MET_RefEle_LCW_CB_eflow_ety;
   Float_t         MET_RefEle_LCW_CB_eflow_phi;
   Float_t         MET_RefEle_LCW_CB_eflow_et;
   Float_t         MET_RefEle_LCW_CB_eflow_sumet;
   Float_t         MET_RefEle_LCW_CB_eflow_etx_CentralReg;
   Float_t         MET_RefEle_LCW_CB_eflow_ety_CentralReg;
   Float_t         MET_RefEle_LCW_CB_eflow_sumet_CentralReg;
   Float_t         MET_RefEle_LCW_CB_eflow_phi_CentralReg;
   Float_t         MET_RefEle_LCW_CB_eflow_etx_EndcapRegion;
   Float_t         MET_RefEle_LCW_CB_eflow_ety_EndcapRegion;
   Float_t         MET_RefEle_LCW_CB_eflow_sumet_EndcapRegion;
   Float_t         MET_RefEle_LCW_CB_eflow_phi_EndcapRegion;
   Float_t         MET_RefEle_LCW_CB_eflow_etx_ForwardReg;
   Float_t         MET_RefEle_LCW_CB_eflow_ety_ForwardReg;
   Float_t         MET_RefEle_LCW_CB_eflow_sumet_ForwardReg;
   Float_t         MET_RefEle_LCW_CB_eflow_phi_ForwardReg;
   Float_t         MET_RefTau_LCW_CB_eflow_etx;
   Float_t         MET_RefTau_LCW_CB_eflow_ety;
   Float_t         MET_RefTau_LCW_CB_eflow_phi;
   Float_t         MET_RefTau_LCW_CB_eflow_et;
   Float_t         MET_RefTau_LCW_CB_eflow_sumet;
   Float_t         MET_RefTau_LCW_CB_eflow_etx_CentralReg;
   Float_t         MET_RefTau_LCW_CB_eflow_ety_CentralReg;
   Float_t         MET_RefTau_LCW_CB_eflow_sumet_CentralReg;
   Float_t         MET_RefTau_LCW_CB_eflow_phi_CentralReg;
   Float_t         MET_RefTau_LCW_CB_eflow_etx_EndcapRegion;
   Float_t         MET_RefTau_LCW_CB_eflow_ety_EndcapRegion;
   Float_t         MET_RefTau_LCW_CB_eflow_sumet_EndcapRegion;
   Float_t         MET_RefTau_LCW_CB_eflow_phi_EndcapRegion;
   Float_t         MET_RefTau_LCW_CB_eflow_etx_ForwardReg;
   Float_t         MET_RefTau_LCW_CB_eflow_ety_ForwardReg;
   Float_t         MET_RefTau_LCW_CB_eflow_sumet_ForwardReg;
   Float_t         MET_RefTau_LCW_CB_eflow_phi_ForwardReg;
   Float_t         MET_RefJet_LCW_CB_eflow_etx;
   Float_t         MET_RefJet_LCW_CB_eflow_ety;
   Float_t         MET_RefJet_LCW_CB_eflow_phi;
   Float_t         MET_RefJet_LCW_CB_eflow_et;
   Float_t         MET_RefJet_LCW_CB_eflow_sumet;
   Float_t         MET_RefJet_LCW_CB_eflow_etx_CentralReg;
   Float_t         MET_RefJet_LCW_CB_eflow_ety_CentralReg;
   Float_t         MET_RefJet_LCW_CB_eflow_sumet_CentralReg;
   Float_t         MET_RefJet_LCW_CB_eflow_phi_CentralReg;
   Float_t         MET_RefJet_LCW_CB_eflow_etx_EndcapRegion;
   Float_t         MET_RefJet_LCW_CB_eflow_ety_EndcapRegion;
   Float_t         MET_RefJet_LCW_CB_eflow_sumet_EndcapRegion;
   Float_t         MET_RefJet_LCW_CB_eflow_phi_EndcapRegion;
   Float_t         MET_RefJet_LCW_CB_eflow_etx_ForwardReg;
   Float_t         MET_RefJet_LCW_CB_eflow_ety_ForwardReg;
   Float_t         MET_RefJet_LCW_CB_eflow_sumet_ForwardReg;
   Float_t         MET_RefJet_LCW_CB_eflow_phi_ForwardReg;
   Float_t         MET_CellOut_LCW_CB_eflow_etx;
   Float_t         MET_CellOut_LCW_CB_eflow_ety;
   Float_t         MET_CellOut_LCW_CB_eflow_phi;
   Float_t         MET_CellOut_LCW_CB_eflow_et;
   Float_t         MET_CellOut_LCW_CB_eflow_sumet;
   Float_t         MET_CellOut_LCW_CB_eflow_etx_CentralReg;
   Float_t         MET_CellOut_LCW_CB_eflow_ety_CentralReg;
   Float_t         MET_CellOut_LCW_CB_eflow_sumet_CentralReg;
   Float_t         MET_CellOut_LCW_CB_eflow_phi_CentralReg;
   Float_t         MET_CellOut_LCW_CB_eflow_etx_EndcapRegion;
   Float_t         MET_CellOut_LCW_CB_eflow_ety_EndcapRegion;
   Float_t         MET_CellOut_LCW_CB_eflow_sumet_EndcapRegion;
   Float_t         MET_CellOut_LCW_CB_eflow_phi_EndcapRegion;
   Float_t         MET_CellOut_LCW_CB_eflow_etx_ForwardReg;
   Float_t         MET_CellOut_LCW_CB_eflow_ety_ForwardReg;
   Float_t         MET_CellOut_LCW_CB_eflow_sumet_ForwardReg;
   Float_t         MET_CellOut_LCW_CB_eflow_phi_ForwardReg;
   Float_t         MET_Cryo_LCW_CB_eflow_etx;
   Float_t         MET_Cryo_LCW_CB_eflow_ety;
   Float_t         MET_Cryo_LCW_CB_eflow_phi;
   Float_t         MET_Cryo_LCW_CB_eflow_et;
   Float_t         MET_Cryo_LCW_CB_eflow_sumet;
   Float_t         MET_Cryo_LCW_CB_eflow_etx_CentralReg;
   Float_t         MET_Cryo_LCW_CB_eflow_ety_CentralReg;
   Float_t         MET_Cryo_LCW_CB_eflow_sumet_CentralReg;
   Float_t         MET_Cryo_LCW_CB_eflow_phi_CentralReg;
   Float_t         MET_Cryo_LCW_CB_eflow_etx_EndcapRegion;
   Float_t         MET_Cryo_LCW_CB_eflow_ety_EndcapRegion;
   Float_t         MET_Cryo_LCW_CB_eflow_sumet_EndcapRegion;
   Float_t         MET_Cryo_LCW_CB_eflow_phi_EndcapRegion;
   Float_t         MET_Cryo_LCW_CB_eflow_etx_ForwardReg;
   Float_t         MET_Cryo_LCW_CB_eflow_ety_ForwardReg;
   Float_t         MET_Cryo_LCW_CB_eflow_sumet_ForwardReg;
   Float_t         MET_Cryo_LCW_CB_eflow_phi_ForwardReg;
   Bool_t          L1_2J10;
   Bool_t          L1_2J15;
   Bool_t          L1_2J5;
   Bool_t          L1_J10;
   Bool_t          L1_J15;
   Bool_t          L1_J30;
   Bool_t          L1_J5;
   Bool_t          L1_J55;
   Bool_t          L1_J75;
   Bool_t          L1_J95;
   vector<unsigned int> *trig_L1_TAV;
   vector<short>   *trig_L2_passedPhysics;
   vector<short>   *trig_EF_passedPhysics;
   vector<unsigned int> *trig_L1_TBP;
   vector<unsigned int> *trig_L1_TAP;
   vector<short>   *trig_L2_passedRaw;
   vector<short>   *trig_EF_passedRaw;
   vector<short>   *trig_L2_resurrected;
   vector<short>   *trig_EF_resurrected;
   vector<short>   *trig_L2_passedThrough;
   vector<short>   *trig_EF_passedThrough;
   UInt_t          trig_DB_SMK;
   UInt_t          trig_DB_L1PSK;
   UInt_t          trig_DB_HLTPSK;
   Int_t           mcevt_n;
   vector<int>     *mcevt_signal_process_id;
   vector<int>     *mcevt_event_number;
   vector<double>  *mcevt_event_scale;
   vector<double>  *mcevt_alphaQCD;
   vector<double>  *mcevt_alphaQED;
   vector<int>     *mcevt_pdf_id1;
   vector<int>     *mcevt_pdf_id2;
   vector<double>  *mcevt_pdf_x1;
   vector<double>  *mcevt_pdf_x2;
   vector<double>  *mcevt_pdf_scale;
   vector<double>  *mcevt_pdf1;
   vector<double>  *mcevt_pdf2;
   vector<double>  *mcevt_weight;
   Int_t           mc_n;
   vector<float>   *mc_pt;
   vector<float>   *mc_eta;
   vector<float>   *mc_phi;
   vector<int>     *mc_status;
   vector<int>     *mc_barcode;
   vector<vector<int> > *mc_parents;
   vector<vector<int> > *mc_children;
   vector<int>     *mc_pdgId;
   Int_t           AntiKt4TruthNew_n;
   vector<float>   *AntiKt4TruthNew_E;
   vector<float>   *AntiKt4TruthNew_pt;
   vector<float>   *AntiKt4TruthNew_m;
   vector<float>   *AntiKt4TruthNew_eta;
   vector<float>   *AntiKt4TruthNew_phi;
   Int_t           AntiKt6TruthNew_n;
   vector<float>   *AntiKt6TruthNew_E;
   vector<float>   *AntiKt6TruthNew_pt;
   vector<float>   *AntiKt6TruthNew_m;
   vector<float>   *AntiKt6TruthNew_eta;
   vector<float>   *AntiKt6TruthNew_phi;

   // List of branches
   TBranch        *b_RunNumber;   //!
   TBranch        *b_EventNumber;   //!
   TBranch        *b_lbn;   //!
   TBranch        *b_bcid;   //!
   TBranch        *b_collcand_passCaloTime;   //!
   TBranch        *b_collcand_passMBTSTime;   //!
   TBranch        *b_collcand_passTrigger;   //!
   TBranch        *b_collcand_pass;   //!
   TBranch        *b_beamSpot_x;   //!
   TBranch        *b_beamSpot_y;   //!
   TBranch        *b_beamSpot_z;   //!
   TBranch        *b_vxp_n;   //!
   TBranch        *b_vxp_x;   //!
   TBranch        *b_vxp_y;   //!
   TBranch        *b_vxp_z;   //!
   TBranch        *b_vxp_cov_x;   //!
   TBranch        *b_vxp_cov_y;   //!
   TBranch        *b_vxp_cov_z;   //!
   TBranch        *b_vxp_cov_xy;   //!
   TBranch        *b_vxp_cov_xz;   //!
   TBranch        *b_vxp_cov_yz;   //!
   TBranch        *b_vxp_chi2;   //!
   TBranch        *b_vxp_ndof;   //!
   TBranch        *b_vxp_px;   //!
   TBranch        *b_vxp_py;   //!
   TBranch        *b_vxp_pz;   //!
   TBranch        *b_vxp_E;   //!
   TBranch        *b_vxp_m;   //!
   TBranch        *b_vxp_nTracks;   //!
   TBranch        *b_vxp_sumPt;   //!
   TBranch        *b_vxp_type;   //!
   TBranch        *b_vxp_trk_n;   //!
   TBranch        *b_vxp_trk_index;   //!
   TBranch        *b_el_n;   //!
   TBranch        *b_el_E;   //!
   TBranch        *b_el_Et;   //!
   TBranch        *b_el_pt;   //!
   TBranch        *b_el_m;   //!
   TBranch        *b_el_eta;   //!
   TBranch        *b_el_phi;   //!
   TBranch        *b_el_px;   //!
   TBranch        *b_el_py;   //!
   TBranch        *b_el_pz;   //!
   TBranch        *b_el_charge;   //!
   TBranch        *b_el_author;   //!
   TBranch        *b_el_isEM;   //!
   TBranch        *b_el_loose;   //!
   TBranch        *b_el_medium;   //!
   TBranch        *b_el_mediumIso;   //!
   TBranch        *b_el_tight;   //!
   TBranch        *b_el_tightIso;   //!
   TBranch        *b_el_Etcone45;   //!
   TBranch        *b_el_Etcone20;   //!
   TBranch        *b_el_Etcone30;   //!
   TBranch        *b_el_Etcone40;   //!
   TBranch        *b_el_Es2;   //!
   TBranch        *b_el_etas2;   //!
   TBranch        *b_el_phis2;   //!
   TBranch        *b_el_cl_E;   //!
   TBranch        *b_el_cl_pt;   //!
   TBranch        *b_el_cl_eta;   //!
   TBranch        *b_el_cl_phi;   //!
   TBranch        *b_el_trackd0;   //!
   TBranch        *b_el_trackz0;   //!
   TBranch        *b_el_trackphi;   //!
   TBranch        *b_el_tracktheta;   //!
   TBranch        *b_el_trackqoverp;   //!
   TBranch        *b_el_trackpt;   //!
   TBranch        *b_el_tracketa;   //!
   TBranch        *b_el_vertx;   //!
   TBranch        *b_el_verty;   //!
   TBranch        *b_el_vertz;   //!
   TBranch        *b_EF_e10_NoCut;   //!
   TBranch        *b_EF_e10_loose;   //!
   TBranch        *b_EF_e10_loose_mu10;   //!
   TBranch        *b_EF_e10_loose_mu6;   //!
   TBranch        *b_EF_e10_medium;   //!
   TBranch        *b_EF_e10_medium_IDTrkNoCut;   //!
   TBranch        *b_EF_e10_medium_SiTrk;   //!
   TBranch        *b_EF_e10_medium_TRT;   //!
   TBranch        *b_EF_e10_tight;   //!
   TBranch        *b_EF_e10_tight_TRT;   //!
   TBranch        *b_EF_e15_loose;   //!
   TBranch        *b_EF_e15_loose_IDTrkNoCut;   //!
   TBranch        *b_EF_e15_medium;   //!
   TBranch        *b_EF_e15_medium_SiTrk;   //!
   TBranch        *b_EF_e15_medium_TRT;   //!
   TBranch        *b_EF_e15_tight;   //!
   TBranch        *b_EF_e15_tight_TRT;   //!
   TBranch        *b_EF_e20_loose;   //!
   TBranch        *b_EF_e20_loose_IDTrkNoCut;   //!
   TBranch        *b_EF_e20_loose_TRT;   //!
   TBranch        *b_EF_e20_loose_passEF;   //!
   TBranch        *b_EF_e20_loose_passL2;   //!
   TBranch        *b_EF_e20_loose_xe20;   //!
   TBranch        *b_EF_e20_loose_xe20_noMu;   //!
   TBranch        *b_EF_e20_loose_xe30;   //!
   TBranch        *b_EF_e20_loose_xe30_noMu;   //!
   TBranch        *b_EF_e20_medium;   //!
   TBranch        *b_EF_mu10;   //!
   TBranch        *b_EF_mu10_Ecut12;   //!
   TBranch        *b_EF_mu10_Ecut123;   //!
   TBranch        *b_EF_mu10_Ecut13;   //!
   TBranch        *b_EF_mu10_IDTrkNoCut;   //!
   TBranch        *b_EF_mu10_MG;   //!
   TBranch        *b_EF_mu10_MSonly;   //!
   TBranch        *b_EF_mu10_MSonly_Ecut12;   //!
   TBranch        *b_EF_mu10_MSonly_Ecut123;   //!
   TBranch        *b_EF_mu10_MSonly_Ecut13;   //!
   TBranch        *b_EF_mu10_MSonly_tight;   //!
   TBranch        *b_EF_mu10_NoAlg;   //!
   TBranch        *b_EF_mu10_SiTrk;   //!
   TBranch        *b_EF_mu10_j30;   //!
   TBranch        *b_EF_mu10_tight;   //!
   TBranch        *b_EF_mu10i_loose;   //!
   TBranch        *b_EF_mu13;   //!
   TBranch        *b_EF_mu13_MG;   //!
   TBranch        *b_EF_mu13_MG_tight;   //!
   TBranch        *b_EF_mu13_tight;   //!
   TBranch        *b_EF_mu15;   //!
   TBranch        *b_EF_mu15_MG;   //!
   TBranch        *b_EF_mu15_NoAlg;   //!
   TBranch        *b_L1_2J15_XE10;   //!
   TBranch        *b_L1_2J15_XE15;   //!
   TBranch        *b_L1_2J15_XE25;   //!
   TBranch        *b_L1_EM10;   //!
   TBranch        *b_L1_EM10I;   //!
   TBranch        *b_L1_EM14;   //!
   TBranch        *b_L1_EM14I;   //!
   TBranch        *b_L1_EM14_XE10;   //!
   TBranch        *b_L1_EM14_XE15;   //!
   TBranch        *b_L1_J15_XE15_EM10;   //!
   TBranch        *b_L1_J15_XE15_MU15;   //!
   TBranch        *b_L1_J30_XE10;   //!
   TBranch        *b_L1_J30_XE15;   //!
   TBranch        *b_L1_J30_XE25;   //!
   TBranch        *b_L1_MU10;   //!
   TBranch        *b_L1_MU15;   //!
   TBranch        *b_L1_MU20;   //!
   TBranch        *b_L1_MU6;   //!
   TBranch        *b_L1_XE10;   //!
   TBranch        *b_L1_XE15;   //!
   TBranch        *b_L1_XE20;   //!
   TBranch        *b_L1_XE25;   //!
   TBranch        *b_L1_XE30;   //!
   TBranch        *b_L1_XE35;   //!
   TBranch        *b_L1_XE40;   //!
   TBranch        *b_L1_XE50;   //!
   TBranch        *b_mu_staco_n;   //!
   TBranch        *b_mu_staco_E;   //!
   TBranch        *b_mu_staco_pt;   //!
   TBranch        *b_mu_staco_m;   //!
   TBranch        *b_mu_staco_eta;   //!
   TBranch        *b_mu_staco_phi;   //!
   TBranch        *b_mu_staco_px;   //!
   TBranch        *b_mu_staco_py;   //!
   TBranch        *b_mu_staco_pz;   //!
   TBranch        *b_mu_staco_charge;   //!
   TBranch        *b_mu_staco_allauthor;   //!
   TBranch        *b_mu_staco_author;   //!
   TBranch        *b_mu_staco_beta;   //!
   TBranch        *b_mu_staco_isMuonLikelihood;   //!
   TBranch        *b_mu_staco_matchchi2;   //!
   TBranch        *b_mu_staco_matchndof;   //!
   TBranch        *b_mu_staco_etcone20;   //!
   TBranch        *b_mu_staco_etcone30;   //!
   TBranch        *b_mu_staco_etcone40;   //!
   TBranch        *b_mu_staco_nucone20;   //!
   TBranch        *b_mu_staco_nucone30;   //!
   TBranch        *b_mu_staco_nucone40;   //!
   TBranch        *b_mu_staco_ptcone20;   //!
   TBranch        *b_mu_staco_ptcone30;   //!
   TBranch        *b_mu_staco_ptcone40;   //!
   TBranch        *b_mu_staco_energyLossPar;   //!
   TBranch        *b_mu_staco_energyLossErr;   //!
   TBranch        *b_mu_staco_etCore;   //!
   TBranch        *b_mu_staco_energyLossType;   //!
   TBranch        *b_mu_staco_caloMuonIdTag;   //!
   TBranch        *b_mu_staco_caloLRLikelihood;   //!
   TBranch        *b_mu_staco_bestMatch;   //!
   TBranch        *b_mu_staco_isStandAloneMuon;   //!
   TBranch        *b_mu_staco_isCombinedMuon;   //!
   TBranch        *b_mu_staco_isLowPtReconstructedMuon;   //!
   TBranch        *b_mu_staco_loose;   //!
   TBranch        *b_mu_staco_medium;   //!
   TBranch        *b_mu_staco_tight;   //!
   TBranch        *b_mu_staco_d0_exPV;   //!
   TBranch        *b_mu_staco_z0_exPV;   //!
   TBranch        *b_mu_staco_phi_exPV;   //!
   TBranch        *b_mu_staco_theta_exPV;   //!
   TBranch        *b_mu_staco_qoverp_exPV;   //!
   TBranch        *b_mu_staco_cb_d0_exPV;   //!
   TBranch        *b_mu_staco_cb_z0_exPV;   //!
   TBranch        *b_mu_staco_cb_phi_exPV;   //!
   TBranch        *b_mu_staco_cb_theta_exPV;   //!
   TBranch        *b_mu_staco_cb_qoverp_exPV;   //!
   TBranch        *b_mu_staco_id_d0_exPV;   //!
   TBranch        *b_mu_staco_id_z0_exPV;   //!
   TBranch        *b_mu_staco_id_phi_exPV;   //!
   TBranch        *b_mu_staco_id_theta_exPV;   //!
   TBranch        *b_mu_staco_id_qoverp_exPV;   //!
   TBranch        *b_mu_staco_me_d0_exPV;   //!
   TBranch        *b_mu_staco_me_z0_exPV;   //!
   TBranch        *b_mu_staco_me_phi_exPV;   //!
   TBranch        *b_mu_staco_me_theta_exPV;   //!
   TBranch        *b_mu_staco_me_qoverp_exPV;   //!
   TBranch        *b_mu_staco_ie_d0_exPV;   //!
   TBranch        *b_mu_staco_ie_z0_exPV;   //!
   TBranch        *b_mu_staco_ie_phi_exPV;   //!
   TBranch        *b_mu_staco_ie_theta_exPV;   //!
   TBranch        *b_mu_staco_ie_qoverp_exPV;   //!
   TBranch        *b_mu_staco_SpaceTime_detID;   //!
   TBranch        *b_mu_staco_SpaceTime_t;   //!
   TBranch        *b_mu_staco_SpaceTime_tError;   //!
   TBranch        *b_mu_staco_SpaceTime_weight;   //!
   TBranch        *b_mu_staco_SpaceTime_x;   //!
   TBranch        *b_mu_staco_SpaceTime_y;   //!
   TBranch        *b_mu_staco_SpaceTime_z;   //!
   TBranch        *b_mu_staco_SpaceTime_t_Tile;   //!
   TBranch        *b_mu_staco_SpaceTime_tError_Tile;   //!
   TBranch        *b_mu_staco_SpaceTime_weight_Tile;   //!
   TBranch        *b_mu_staco_SpaceTime_x_Tile;   //!
   TBranch        *b_mu_staco_SpaceTime_y_Tile;   //!
   TBranch        *b_mu_staco_SpaceTime_z_Tile;   //!
   TBranch        *b_mu_staco_SpaceTime_t_TRT;   //!
   TBranch        *b_mu_staco_SpaceTime_tError_TRT;   //!
   TBranch        *b_mu_staco_SpaceTime_weight_TRT;   //!
   TBranch        *b_mu_staco_SpaceTime_x_TRT;   //!
   TBranch        *b_mu_staco_SpaceTime_y_TRT;   //!
   TBranch        *b_mu_staco_SpaceTime_z_TRT;   //!
   TBranch        *b_mu_staco_SpaceTime_t_MDT;   //!
   TBranch        *b_mu_staco_SpaceTime_tError_MDT;   //!
   TBranch        *b_mu_staco_SpaceTime_weight_MDT;   //!
   TBranch        *b_mu_staco_SpaceTime_x_MDT;   //!
   TBranch        *b_mu_staco_SpaceTime_y_MDT;   //!
   TBranch        *b_mu_staco_SpaceTime_z_MDT;   //!
   TBranch        *b_mu_staco_TileCellEnergyLayer1;   //!
   TBranch        *b_mu_staco_TileTimeLayer1;   //!
   TBranch        *b_mu_staco_TileCellRmsNoiseLayer1;   //!
   TBranch        *b_mu_staco_TileCellSignLayer1;   //!
   TBranch        *b_mu_staco_TileCellEnergyLayer2;   //!
   TBranch        *b_mu_staco_TileTimeLayer2;   //!
   TBranch        *b_mu_staco_TileCellRmsNoiseLayer2;   //!
   TBranch        *b_mu_staco_TileCellSignLayer2;   //!
   TBranch        *b_mu_staco_TileCellEnergyLayer3;   //!
   TBranch        *b_mu_staco_TileTimeLayer3;   //!
   TBranch        *b_mu_staco_TileCellRmsNoiseLayer3;   //!
   TBranch        *b_mu_staco_TileCellSignLayer3;   //!
   TBranch        *b_mu_staco_MSTrkT0_1;   //!
   TBranch        *b_mu_staco_MSTrkT0_2;   //!
   TBranch        *b_mu_staco_MSTrkT0_3;   //!
   TBranch        *b_mu_staco_cov_d0_exPV;   //!
   TBranch        *b_mu_staco_cov_z0_exPV;   //!
   TBranch        *b_mu_staco_cov_phi_exPV;   //!
   TBranch        *b_mu_staco_cov_theta_exPV;   //!
   TBranch        *b_mu_staco_cov_qoverp_exPV;   //!
   TBranch        *b_mu_staco_cov_d0_z0_exPV;   //!
   TBranch        *b_mu_staco_cov_d0_phi_exPV;   //!
   TBranch        *b_mu_staco_cov_d0_theta_exPV;   //!
   TBranch        *b_mu_staco_cov_d0_qoverp_exPV;   //!
   TBranch        *b_mu_staco_cov_z0_phi_exPV;   //!
   TBranch        *b_mu_staco_cov_z0_theta_exPV;   //!
   TBranch        *b_mu_staco_cov_z0_qoverp_exPV;   //!
   TBranch        *b_mu_staco_cov_phi_theta_exPV;   //!
   TBranch        *b_mu_staco_cov_phi_qoverp_exPV;   //!
   TBranch        *b_mu_staco_cov_theta_qoverp_exPV;   //!
   TBranch        *b_mu_staco_id_cov_d0_exPV;   //!
   TBranch        *b_mu_staco_id_cov_z0_exPV;   //!
   TBranch        *b_mu_staco_id_cov_phi_exPV;   //!
   TBranch        *b_mu_staco_id_cov_theta_exPV;   //!
   TBranch        *b_mu_staco_id_cov_qoverp_exPV;   //!
   TBranch        *b_mu_staco_me_cov_d0_exPV;   //!
   TBranch        *b_mu_staco_me_cov_z0_exPV;   //!
   TBranch        *b_mu_staco_me_cov_phi_exPV;   //!
   TBranch        *b_mu_staco_me_cov_theta_exPV;   //!
   TBranch        *b_mu_staco_me_cov_qoverp_exPV;   //!
   TBranch        *b_mu_staco_ms_d0;   //!
   TBranch        *b_mu_staco_ms_z0;   //!
   TBranch        *b_mu_staco_ms_phi;   //!
   TBranch        *b_mu_staco_ms_theta;   //!
   TBranch        *b_mu_staco_ms_qoverp;   //!
   TBranch        *b_mu_staco_id_d0;   //!
   TBranch        *b_mu_staco_id_z0;   //!
   TBranch        *b_mu_staco_id_phi;   //!
   TBranch        *b_mu_staco_id_theta;   //!
   TBranch        *b_mu_staco_id_qoverp;   //!
   TBranch        *b_mu_staco_me_d0;   //!
   TBranch        *b_mu_staco_me_z0;   //!
   TBranch        *b_mu_staco_me_phi;   //!
   TBranch        *b_mu_staco_me_theta;   //!
   TBranch        *b_mu_staco_me_qoverp;   //!
   TBranch        *b_mu_staco_ie_d0;   //!
   TBranch        *b_mu_staco_ie_z0;   //!
   TBranch        *b_mu_staco_ie_phi;   //!
   TBranch        *b_mu_staco_ie_theta;   //!
   TBranch        *b_mu_staco_ie_qoverp;   //!
   TBranch        *b_mu_staco_nOutliersOnTrack;   //!
   TBranch        *b_mu_staco_nBLHits;   //!
   TBranch        *b_mu_staco_nPixHits;   //!
   TBranch        *b_mu_staco_nSCTHits;   //!
   TBranch        *b_mu_staco_nTRTHits;   //!
   TBranch        *b_mu_staco_nTRTHighTHits;   //!
   TBranch        *b_mu_staco_nBLSharedHits;   //!
   TBranch        *b_mu_staco_nPixSharedHits;   //!
   TBranch        *b_mu_staco_nPixHoles;   //!
   TBranch        *b_mu_staco_nSCTSharedHits;   //!
   TBranch        *b_mu_staco_nSCTHoles;   //!
   TBranch        *b_mu_staco_nTRTOutliers;   //!
   TBranch        *b_mu_staco_nTRTHighTOutliers;   //!
   TBranch        *b_mu_staco_nGangedPixels;   //!
   TBranch        *b_mu_staco_nPixelDeadSensors;   //!
   TBranch        *b_mu_staco_nSCTDeadSensors;   //!
   TBranch        *b_mu_staco_nTRTDeadStraws;   //!
   TBranch        *b_mu_staco_expectBLayerHit;   //!
   TBranch        *b_mu_staco_nMDTHits;   //!
   TBranch        *b_mu_staco_nMDTHoles;   //!
   TBranch        *b_mu_staco_nCSCEtaHits;   //!
   TBranch        *b_mu_staco_nCSCEtaHoles;   //!
   TBranch        *b_mu_staco_nCSCPhiHits;   //!
   TBranch        *b_mu_staco_nCSCPhiHoles;   //!
   TBranch        *b_mu_staco_nRPCEtaHits;   //!
   TBranch        *b_mu_staco_nRPCEtaHoles;   //!
   TBranch        *b_mu_staco_nRPCPhiHits;   //!
   TBranch        *b_mu_staco_nRPCPhiHoles;   //!
   TBranch        *b_mu_staco_nTGCEtaHits;   //!
   TBranch        *b_mu_staco_nTGCEtaHoles;   //!
   TBranch        *b_mu_staco_nTGCPhiHits;   //!
   TBranch        *b_mu_staco_nTGCPhiHoles;   //!
   TBranch        *b_mu_staco_nMDTBIHits;   //!
   TBranch        *b_mu_staco_nMDTBMHits;   //!
   TBranch        *b_mu_staco_nMDTBOHits;   //!
   TBranch        *b_mu_staco_nMDTBEEHits;   //!
   TBranch        *b_mu_staco_nMDTBIS78Hits;   //!
   TBranch        *b_mu_staco_nMDTEIHits;   //!
   TBranch        *b_mu_staco_nMDTEMHits;   //!
   TBranch        *b_mu_staco_nMDTEOHits;   //!
   TBranch        *b_mu_staco_nMDTEEHits;   //!
   TBranch        *b_mu_staco_nRPCLayer1EtaHits;   //!
   TBranch        *b_mu_staco_nRPCLayer2EtaHits;   //!
   TBranch        *b_mu_staco_nRPCLayer3EtaHits;   //!
   TBranch        *b_mu_staco_nRPCLayer1PhiHits;   //!
   TBranch        *b_mu_staco_nRPCLayer2PhiHits;   //!
   TBranch        *b_mu_staco_nRPCLayer3PhiHits;   //!
   TBranch        *b_mu_staco_nTGCLayer1EtaHits;   //!
   TBranch        *b_mu_staco_nTGCLayer2EtaHits;   //!
   TBranch        *b_mu_staco_nTGCLayer3EtaHits;   //!
   TBranch        *b_mu_staco_nTGCLayer4EtaHits;   //!
   TBranch        *b_mu_staco_nTGCLayer1PhiHits;   //!
   TBranch        *b_mu_staco_nTGCLayer2PhiHits;   //!
   TBranch        *b_mu_staco_nTGCLayer3PhiHits;   //!
   TBranch        *b_mu_staco_nTGCLayer4PhiHits;   //!
   TBranch        *b_mu_staco_barrelSectors;   //!
   TBranch        *b_mu_staco_endcapSectors;   //!
   TBranch        *b_mu_staco_trackd0;   //!
   TBranch        *b_mu_staco_trackz0;   //!
   TBranch        *b_mu_staco_trackphi;   //!
   TBranch        *b_mu_staco_tracktheta;   //!
   TBranch        *b_mu_staco_trackqoverp;   //!
   TBranch        *b_mu_staco_trackcov_d0;   //!
   TBranch        *b_mu_staco_trackcov_z0;   //!
   TBranch        *b_mu_staco_trackcov_phi;   //!
   TBranch        *b_mu_staco_trackcov_theta;   //!
   TBranch        *b_mu_staco_trackcov_qoverp;   //!
   TBranch        *b_mu_staco_trackcov_d0_z0;   //!
   TBranch        *b_mu_staco_trackcov_d0_phi;   //!
   TBranch        *b_mu_staco_trackcov_d0_theta;   //!
   TBranch        *b_mu_staco_trackcov_d0_qoverp;   //!
   TBranch        *b_mu_staco_trackcov_z0_phi;   //!
   TBranch        *b_mu_staco_trackcov_z0_theta;   //!
   TBranch        *b_mu_staco_trackcov_z0_qoverp;   //!
   TBranch        *b_mu_staco_trackcov_phi_theta;   //!
   TBranch        *b_mu_staco_trackcov_phi_qoverp;   //!
   TBranch        *b_mu_staco_trackcov_theta_qoverp;   //!
   TBranch        *b_mu_staco_trackfitchi2;   //!
   TBranch        *b_mu_staco_trackfitndof;   //!
   TBranch        *b_mu_staco_hastrack;   //!
   TBranch        *b_mu_staco_truth_dr;   //!
   TBranch        *b_mu_staco_truth_matched;   //!
   TBranch        *b_mu_staco_EFCB_dr;   //!
   TBranch        *b_mu_staco_EFCB_n;   //!
   TBranch        *b_mu_staco_EFCB_MuonType;   //!
   TBranch        *b_mu_staco_EFCB_pt;   //!
   TBranch        *b_mu_staco_EFCB_eta;   //!
   TBranch        *b_mu_staco_EFCB_phi;   //!
   TBranch        *b_mu_staco_EFCB_hasCB;   //!
   TBranch        *b_mu_staco_EFCB_matched;   //!
   TBranch        *b_mu_staco_EFMG_dr;   //!
   TBranch        *b_mu_staco_EFMG_n;   //!
   TBranch        *b_mu_staco_EFMG_MuonType;   //!
   TBranch        *b_mu_staco_EFMG_pt;   //!
   TBranch        *b_mu_staco_EFMG_eta;   //!
   TBranch        *b_mu_staco_EFMG_phi;   //!
   TBranch        *b_mu_staco_EFMG_hasMG;   //!
   TBranch        *b_mu_staco_EFMG_matched;   //!
   TBranch        *b_mu_staco_EFME_dr;   //!
   TBranch        *b_mu_staco_EFME_n;   //!
   TBranch        *b_mu_staco_EFME_MuonType;   //!
   TBranch        *b_mu_staco_EFME_pt;   //!
   TBranch        *b_mu_staco_EFME_eta;   //!
   TBranch        *b_mu_staco_EFME_phi;   //!
   TBranch        *b_mu_staco_EFME_hasME;   //!
   TBranch        *b_mu_staco_EFME_matched;   //!
   TBranch        *b_mu_staco_L2CB_dr;   //!
   TBranch        *b_mu_staco_L2CB_pt;   //!
   TBranch        *b_mu_staco_L2CB_eta;   //!
   TBranch        *b_mu_staco_L2CB_phi;   //!
   TBranch        *b_mu_staco_L2CB_id_pt;   //!
   TBranch        *b_mu_staco_L2CB_ms_pt;   //!
   TBranch        *b_mu_staco_L2CB_nPixHits;   //!
   TBranch        *b_mu_staco_L2CB_nSCTHits;   //!
   TBranch        *b_mu_staco_L2CB_nTRTHits;   //!
   TBranch        *b_mu_staco_L2CB_nTRTHighTHits;   //!
   TBranch        *b_mu_staco_L2CB_matched;   //!
   TBranch        *b_mu_staco_L1_dr;   //!
   TBranch        *b_mu_staco_L1_pt;   //!
   TBranch        *b_mu_staco_L1_eta;   //!
   TBranch        *b_mu_staco_L1_phi;   //!
   TBranch        *b_mu_staco_L1_thrNumber;   //!
   TBranch        *b_mu_staco_L1_RoINumber;   //!
   TBranch        *b_mu_staco_L1_sectorAddress;   //!
   TBranch        *b_mu_staco_L1_firstCandidate;   //!
   TBranch        *b_mu_staco_L1_moreCandInRoI;   //!
   TBranch        *b_mu_staco_L1_moreCandInSector;   //!
   TBranch        *b_mu_staco_L1_source;   //!
   TBranch        *b_mu_staco_L1_hemisphere;   //!
   TBranch        *b_mu_staco_L1_matched;   //!
   TBranch        *b_el_HR_n;   //!
   TBranch        *b_el_HR_E;   //!
   TBranch        *b_el_HR_Et;   //!
   TBranch        *b_el_HR_pt;   //!
   TBranch        *b_el_HR_m;   //!
   TBranch        *b_el_HR_eta;   //!
   TBranch        *b_el_HR_phi;   //!
   TBranch        *b_el_HR_px;   //!
   TBranch        *b_el_HR_py;   //!
   TBranch        *b_el_HR_pz;   //!
   TBranch        *b_el_HR_charge;   //!
   TBranch        *b_el_HR_author;   //!
   TBranch        *b_el_HR_isEM;   //!
   TBranch        *b_el_HR_OQ;   //!
   TBranch        *b_el_HR_convFlag;   //!
   TBranch        *b_el_HR_isConv;   //!
   TBranch        *b_el_HR_nConv;   //!
   TBranch        *b_el_HR_nSingleTrackConv;   //!
   TBranch        *b_el_HR_nDoubleTrackConv;   //!
   TBranch        *b_el_HR_OQRecalc;   //!
   TBranch        *b_el_HR_type;   //!
   TBranch        *b_el_HR_origin;   //!
   TBranch        *b_el_HR_typebkg;   //!
   TBranch        *b_el_HR_originbkg;   //!
   TBranch        *b_el_HR_truth_E;   //!
   TBranch        *b_el_HR_truth_pt;   //!
   TBranch        *b_el_HR_truth_eta;   //!
   TBranch        *b_el_HR_truth_phi;   //!
   TBranch        *b_el_HR_truth_type;   //!
   TBranch        *b_el_HR_truth_status;   //!
   TBranch        *b_el_HR_truth_barcode;   //!
   TBranch        *b_el_HR_truth_mothertype;   //!
   TBranch        *b_el_HR_truth_motherbarcode;   //!
   TBranch        *b_el_HR_truth_hasHardBrem;   //!
   TBranch        *b_el_HR_truth_index;   //!
   TBranch        *b_el_HR_truth_matched;   //!
   TBranch        *b_el_HR_loose;   //!
   TBranch        *b_el_HR_medium;   //!
   TBranch        *b_el_HR_mediumIso;   //!
   TBranch        *b_el_HR_tight;   //!
   TBranch        *b_el_HR_tightIso;   //!
   TBranch        *b_el_HR_goodOQ;   //!
   TBranch        *b_el_HR_Ethad;   //!
   TBranch        *b_el_HR_Ethad1;   //!
   TBranch        *b_el_HR_f1;   //!
   TBranch        *b_el_HR_f1core;   //!
   TBranch        *b_el_HR_Emins1;   //!
   TBranch        *b_el_HR_fside;   //!
   TBranch        *b_el_HR_Emax2;   //!
   TBranch        *b_el_HR_ws3;   //!
   TBranch        *b_el_HR_wstot;   //!
   TBranch        *b_el_HR_emaxs1;   //!
   TBranch        *b_el_HR_deltaEs;   //!
   TBranch        *b_el_HR_E233;   //!
   TBranch        *b_el_HR_E237;   //!
   TBranch        *b_el_HR_E277;   //!
   TBranch        *b_el_HR_weta2;   //!
   TBranch        *b_el_HR_f3;   //!
   TBranch        *b_el_HR_f3core;   //!
   TBranch        *b_el_HR_rphiallcalo;   //!
   TBranch        *b_el_HR_Etcone45;   //!
   TBranch        *b_el_HR_Etcone15;   //!
   TBranch        *b_el_HR_Etcone20;   //!
   TBranch        *b_el_HR_Etcone25;   //!
   TBranch        *b_el_HR_Etcone30;   //!
   TBranch        *b_el_HR_Etcone35;   //!
   TBranch        *b_el_HR_Etcone40;   //!
   TBranch        *b_el_HR_ptcone20;   //!
   TBranch        *b_el_HR_ptcone30;   //!
   TBranch        *b_el_HR_ptcone40;   //!
   TBranch        *b_el_HR_nucone20;   //!
   TBranch        *b_el_HR_nucone30;   //!
   TBranch        *b_el_HR_nucone40;   //!
   TBranch        *b_el_HR_convanglematch;   //!
   TBranch        *b_el_HR_convtrackmatch;   //!
   TBranch        *b_el_HR_hasconv;   //!
   TBranch        *b_el_HR_convvtxx;   //!
   TBranch        *b_el_HR_convvtxy;   //!
   TBranch        *b_el_HR_convvtxz;   //!
   TBranch        *b_el_HR_Rconv;   //!
   TBranch        *b_el_HR_zconv;   //!
   TBranch        *b_el_HR_convvtxchi2;   //!
   TBranch        *b_el_HR_pt1conv;   //!
   TBranch        *b_el_HR_convtrk1nBLHits;   //!
   TBranch        *b_el_HR_convtrk1nPixHits;   //!
   TBranch        *b_el_HR_convtrk1nSCTHits;   //!
   TBranch        *b_el_HR_convtrk1nTRTHits;   //!
   TBranch        *b_el_HR_pt2conv;   //!
   TBranch        *b_el_HR_convtrk2nBLHits;   //!
   TBranch        *b_el_HR_convtrk2nPixHits;   //!
   TBranch        *b_el_HR_convtrk2nSCTHits;   //!
   TBranch        *b_el_HR_convtrk2nTRTHits;   //!
   TBranch        *b_el_HR_ptconv;   //!
   TBranch        *b_el_HR_pzconv;   //!
   TBranch        *b_el_HR_pos7;   //!
   TBranch        *b_el_HR_etacorrmag;   //!
   TBranch        *b_el_HR_deltaeta1;   //!
   TBranch        *b_el_HR_deltaeta2;   //!
   TBranch        *b_el_HR_deltaphi2;   //!
   TBranch        *b_el_HR_deltaphiRescaled;   //!
   TBranch        *b_el_HR_deltaPhiRot;   //!
   TBranch        *b_el_HR_expectHitInBLayer;   //!
   TBranch        *b_el_HR_trackd0_physics;   //!
   TBranch        *b_el_HR_reta;   //!
   TBranch        *b_el_HR_rphi;   //!
   TBranch        *b_el_HR_refittedTrack_n;   //!
   TBranch        *b_el_HR_firstEdens;   //!
   TBranch        *b_el_HR_cellmaxfrac;   //!
   TBranch        *b_el_HR_longitudinal;   //!
   TBranch        *b_el_HR_secondlambda;   //!
   TBranch        *b_el_HR_lateral;   //!
   TBranch        *b_el_HR_secondR;   //!
   TBranch        *b_el_HR_centerlambda;   //!
   TBranch        *b_el_HR_trackd0;   //!
   TBranch        *b_el_HR_trackz0;   //!
   TBranch        *b_el_HR_trackphi;   //!
   TBranch        *b_el_HR_tracktheta;   //!
   TBranch        *b_el_HR_trackqoverp;   //!
   TBranch        *b_el_HR_trackpt;   //!
   TBranch        *b_el_HR_tracketa;   //!
   TBranch        *b_el_HR_nBLHits;   //!
   TBranch        *b_el_HR_nPixHits;   //!
   TBranch        *b_el_HR_nSCTHits;   //!
   TBranch        *b_el_HR_nTRTHits;   //!
   TBranch        *b_el_HR_nPixHoles;   //!
   TBranch        *b_el_HR_nSCTHoles;   //!
   TBranch        *b_el_HR_nBLSharedHits;   //!
   TBranch        *b_el_HR_nPixSharedHits;   //!
   TBranch        *b_el_HR_nSCTSharedHits;   //!
   TBranch        *b_el_HR_nTRTHighTHits;   //!
   TBranch        *b_el_HR_nTRTOutliers;   //!
   TBranch        *b_el_HR_nTRTHighTOutliers;   //!
   TBranch        *b_el_HR_nSiHits;   //!
   TBranch        *b_el_HR_TRTHighTHitsRatio;   //!
   TBranch        *b_el_HR_TRTHighTHitsRatioOutliers;   //!
   TBranch        *b_el_HR_pixeldEdx;   //!
   TBranch        *b_el_HR_eProbabilityComb;   //!
   TBranch        *b_el_HR_eProbabilityHT;   //!
   TBranch        *b_el_HR_eProbabilityToT;   //!
   TBranch        *b_el_HR_eProbabilityBrem;   //!
   TBranch        *b_el_HR_hastrack;   //!
   TBranch        *b_el_HR_deltaEmax2;   //!
   TBranch        *b_el_HR_calibHitsShowerDepth;   //!
   TBranch        *b_el_HR_trackd0beam;   //!
   TBranch        *b_el_HR_tracksigd0beam;   //!
   TBranch        *b_el_HR_trackd0pv;   //!
   TBranch        *b_el_HR_tracksigd0pv;   //!
   TBranch        *b_el_HR_trackz0pv;   //!
   TBranch        *b_el_HR_tracksigz0pv;   //!
   TBranch        *b_el_HR_trackd0pvunbiased;   //!
   TBranch        *b_el_HR_tracksigd0pvunbiased;   //!
   TBranch        *b_el_HR_trackz0pvunbiased;   //!
   TBranch        *b_el_HR_tracksigz0pvunbiased;   //!
   TBranch        *b_el_HR_isIso;   //!
   TBranch        *b_el_HR_mvaptcone20;   //!
   TBranch        *b_el_HR_mvaptcone30;   //!
   TBranch        *b_el_HR_mvaptcone40;   //!
   TBranch        *b_el_HR_EF_dr;   //!
   TBranch        *b_el_HR_L2_dr;   //!
   TBranch        *b_el_HR_L1_dr;   //!
   TBranch        *b_mu_HR_n;   //!
   TBranch        *b_mu_HR_E;   //!
   TBranch        *b_mu_HR_pt;   //!
   TBranch        *b_mu_HR_m;   //!
   TBranch        *b_mu_HR_eta;   //!
   TBranch        *b_mu_HR_phi;   //!
   TBranch        *b_mu_HR_px;   //!
   TBranch        *b_mu_HR_py;   //!
   TBranch        *b_mu_HR_pz;   //!
   TBranch        *b_mu_HR_charge;   //!
   TBranch        *b_mu_HR_allauthor;   //!
   TBranch        *b_mu_HR_author;   //!
   TBranch        *b_mu_HR_beta;   //!
   TBranch        *b_mu_HR_isMuonLikelihood;   //!
   TBranch        *b_mu_HR_matchchi2;   //!
   TBranch        *b_mu_HR_matchndof;   //!
   TBranch        *b_mu_HR_etcone20;   //!
   TBranch        *b_mu_HR_etcone30;   //!
   TBranch        *b_mu_HR_etcone40;   //!
   TBranch        *b_mu_HR_nucone20;   //!
   TBranch        *b_mu_HR_nucone30;   //!
   TBranch        *b_mu_HR_nucone40;   //!
   TBranch        *b_mu_HR_ptcone20;   //!
   TBranch        *b_mu_HR_ptcone30;   //!
   TBranch        *b_mu_HR_ptcone40;   //!
   TBranch        *b_mu_HR_energyLossPar;   //!
   TBranch        *b_mu_HR_energyLossErr;   //!
   TBranch        *b_mu_HR_etCore;   //!
   TBranch        *b_mu_HR_energyLossType;   //!
   TBranch        *b_mu_HR_caloMuonIdTag;   //!
   TBranch        *b_mu_HR_caloLRLikelihood;   //!
   TBranch        *b_mu_HR_bestMatch;   //!
   TBranch        *b_mu_HR_isStandAloneMuon;   //!
   TBranch        *b_mu_HR_isCombinedMuon;   //!
   TBranch        *b_mu_HR_isLowPtReconstructedMuon;   //!
   TBranch        *b_mu_HR_loose;   //!
   TBranch        *b_mu_HR_medium;   //!
   TBranch        *b_mu_HR_tight;   //!
   TBranch        *b_mu_HR_d0_exPV;   //!
   TBranch        *b_mu_HR_z0_exPV;   //!
   TBranch        *b_mu_HR_phi_exPV;   //!
   TBranch        *b_mu_HR_theta_exPV;   //!
   TBranch        *b_mu_HR_qoverp_exPV;   //!
   TBranch        *b_mu_HR_cb_d0_exPV;   //!
   TBranch        *b_mu_HR_cb_z0_exPV;   //!
   TBranch        *b_mu_HR_cb_phi_exPV;   //!
   TBranch        *b_mu_HR_cb_theta_exPV;   //!
   TBranch        *b_mu_HR_cb_qoverp_exPV;   //!
   TBranch        *b_mu_HR_id_d0_exPV;   //!
   TBranch        *b_mu_HR_id_z0_exPV;   //!
   TBranch        *b_mu_HR_id_phi_exPV;   //!
   TBranch        *b_mu_HR_id_theta_exPV;   //!
   TBranch        *b_mu_HR_id_qoverp_exPV;   //!
   TBranch        *b_mu_HR_me_d0_exPV;   //!
   TBranch        *b_mu_HR_me_z0_exPV;   //!
   TBranch        *b_mu_HR_me_phi_exPV;   //!
   TBranch        *b_mu_HR_me_theta_exPV;   //!
   TBranch        *b_mu_HR_me_qoverp_exPV;   //!
   TBranch        *b_mu_HR_ie_d0_exPV;   //!
   TBranch        *b_mu_HR_ie_z0_exPV;   //!
   TBranch        *b_mu_HR_ie_phi_exPV;   //!
   TBranch        *b_mu_HR_ie_theta_exPV;   //!
   TBranch        *b_mu_HR_ie_qoverp_exPV;   //!
   TBranch        *b_mu_HR_SpaceTime_detID;   //!
   TBranch        *b_mu_HR_SpaceTime_t;   //!
   TBranch        *b_mu_HR_SpaceTime_tError;   //!
   TBranch        *b_mu_HR_SpaceTime_weight;   //!
   TBranch        *b_mu_HR_SpaceTime_x;   //!
   TBranch        *b_mu_HR_SpaceTime_y;   //!
   TBranch        *b_mu_HR_SpaceTime_z;   //!
   TBranch        *b_mu_HR_SpaceTime_t_Tile;   //!
   TBranch        *b_mu_HR_SpaceTime_tError_Tile;   //!
   TBranch        *b_mu_HR_SpaceTime_weight_Tile;   //!
   TBranch        *b_mu_HR_SpaceTime_x_Tile;   //!
   TBranch        *b_mu_HR_SpaceTime_y_Tile;   //!
   TBranch        *b_mu_HR_SpaceTime_z_Tile;   //!
   TBranch        *b_mu_HR_SpaceTime_t_TRT;   //!
   TBranch        *b_mu_HR_SpaceTime_tError_TRT;   //!
   TBranch        *b_mu_HR_SpaceTime_weight_TRT;   //!
   TBranch        *b_mu_HR_SpaceTime_x_TRT;   //!
   TBranch        *b_mu_HR_SpaceTime_y_TRT;   //!
   TBranch        *b_mu_HR_SpaceTime_z_TRT;   //!
   TBranch        *b_mu_HR_SpaceTime_t_MDT;   //!
   TBranch        *b_mu_HR_SpaceTime_tError_MDT;   //!
   TBranch        *b_mu_HR_SpaceTime_weight_MDT;   //!
   TBranch        *b_mu_HR_SpaceTime_x_MDT;   //!
   TBranch        *b_mu_HR_SpaceTime_y_MDT;   //!
   TBranch        *b_mu_HR_SpaceTime_z_MDT;   //!
   TBranch        *b_mu_HR_TileCellEnergyLayer1;   //!
   TBranch        *b_mu_HR_TileTimeLayer1;   //!
   TBranch        *b_mu_HR_TileCellRmsNoiseLayer1;   //!
   TBranch        *b_mu_HR_TileCellSignLayer1;   //!
   TBranch        *b_mu_HR_TileCellEnergyLayer2;   //!
   TBranch        *b_mu_HR_TileTimeLayer2;   //!
   TBranch        *b_mu_HR_TileCellRmsNoiseLayer2;   //!
   TBranch        *b_mu_HR_TileCellSignLayer2;   //!
   TBranch        *b_mu_HR_TileCellEnergyLayer3;   //!
   TBranch        *b_mu_HR_TileTimeLayer3;   //!
   TBranch        *b_mu_HR_TileCellRmsNoiseLayer3;   //!
   TBranch        *b_mu_HR_TileCellSignLayer3;   //!
   TBranch        *b_mu_HR_MSTrkT0_1;   //!
   TBranch        *b_mu_HR_MSTrkT0_2;   //!
   TBranch        *b_mu_HR_MSTrkT0_3;   //!
   TBranch        *b_mu_HR_cov_d0_exPV;   //!
   TBranch        *b_mu_HR_cov_z0_exPV;   //!
   TBranch        *b_mu_HR_cov_phi_exPV;   //!
   TBranch        *b_mu_HR_cov_theta_exPV;   //!
   TBranch        *b_mu_HR_cov_qoverp_exPV;   //!
   TBranch        *b_mu_HR_cov_d0_z0_exPV;   //!
   TBranch        *b_mu_HR_cov_d0_phi_exPV;   //!
   TBranch        *b_mu_HR_cov_d0_theta_exPV;   //!
   TBranch        *b_mu_HR_cov_d0_qoverp_exPV;   //!
   TBranch        *b_mu_HR_cov_z0_phi_exPV;   //!
   TBranch        *b_mu_HR_cov_z0_theta_exPV;   //!
   TBranch        *b_mu_HR_cov_z0_qoverp_exPV;   //!
   TBranch        *b_mu_HR_cov_phi_theta_exPV;   //!
   TBranch        *b_mu_HR_cov_phi_qoverp_exPV;   //!
   TBranch        *b_mu_HR_cov_theta_qoverp_exPV;   //!
   TBranch        *b_mu_HR_ms_d0;   //!
   TBranch        *b_mu_HR_ms_z0;   //!
   TBranch        *b_mu_HR_ms_phi;   //!
   TBranch        *b_mu_HR_ms_theta;   //!
   TBranch        *b_mu_HR_ms_qoverp;   //!
   TBranch        *b_mu_HR_id_d0;   //!
   TBranch        *b_mu_HR_id_z0;   //!
   TBranch        *b_mu_HR_id_phi;   //!
   TBranch        *b_mu_HR_id_theta;   //!
   TBranch        *b_mu_HR_id_qoverp;   //!
   TBranch        *b_mu_HR_me_d0;   //!
   TBranch        *b_mu_HR_me_z0;   //!
   TBranch        *b_mu_HR_me_phi;   //!
   TBranch        *b_mu_HR_me_theta;   //!
   TBranch        *b_mu_HR_me_qoverp;   //!
   TBranch        *b_mu_HR_ie_d0;   //!
   TBranch        *b_mu_HR_ie_z0;   //!
   TBranch        *b_mu_HR_ie_phi;   //!
   TBranch        *b_mu_HR_ie_theta;   //!
   TBranch        *b_mu_HR_ie_qoverp;   //!
   TBranch        *b_mu_HR_trackd0;   //!
   TBranch        *b_mu_HR_trackz0;   //!
   TBranch        *b_mu_HR_trackphi;   //!
   TBranch        *b_mu_HR_tracktheta;   //!
   TBranch        *b_mu_HR_trackqoverp;   //!
   TBranch        *b_mu_HR_trackcov_d0;   //!
   TBranch        *b_mu_HR_trackcov_z0;   //!
   TBranch        *b_mu_HR_trackcov_phi;   //!
   TBranch        *b_mu_HR_trackcov_theta;   //!
   TBranch        *b_mu_HR_trackcov_qoverp;   //!
   TBranch        *b_mu_HR_hastrack;   //!
   TBranch        *b_mu_HR_truth_dr;   //!
   TBranch        *b_mu_HR_truth_E;   //!
   TBranch        *b_mu_HR_truth_pt;   //!
   TBranch        *b_mu_HR_truth_eta;   //!
   TBranch        *b_mu_HR_truth_phi;   //!
   TBranch        *b_mu_HR_truth_type;   //!
   TBranch        *b_mu_HR_truth_status;   //!
   TBranch        *b_mu_HR_truth_barcode;   //!
   TBranch        *b_mu_HR_truth_mothertype;   //!
   TBranch        *b_mu_HR_truth_motherbarcode;   //!
   TBranch        *b_mu_HR_truth_matched;   //!
   TBranch        *b_mu_HR_EFCB_dr;   //!
   TBranch        *b_mu_HR_EFCB_n;   //!
   TBranch        *b_mu_HR_EFCB_MuonType;   //!
   TBranch        *b_mu_HR_EFCB_pt;   //!
   TBranch        *b_mu_HR_EFCB_eta;   //!
   TBranch        *b_mu_HR_EFCB_phi;   //!
   TBranch        *b_mu_HR_EFCB_hasCB;   //!
   TBranch        *b_mu_HR_EFCB_matched;   //!
   TBranch        *b_mu_HR_EFMG_dr;   //!
   TBranch        *b_mu_HR_EFMG_n;   //!
   TBranch        *b_mu_HR_EFMG_MuonType;   //!
   TBranch        *b_mu_HR_EFMG_pt;   //!
   TBranch        *b_mu_HR_EFMG_eta;   //!
   TBranch        *b_mu_HR_EFMG_phi;   //!
   TBranch        *b_mu_HR_EFMG_hasMG;   //!
   TBranch        *b_mu_HR_EFMG_matched;   //!
   TBranch        *b_mu_HR_EFME_dr;   //!
   TBranch        *b_mu_HR_EFME_n;   //!
   TBranch        *b_mu_HR_EFME_MuonType;   //!
   TBranch        *b_mu_HR_EFME_pt;   //!
   TBranch        *b_mu_HR_EFME_eta;   //!
   TBranch        *b_mu_HR_EFME_phi;   //!
   TBranch        *b_mu_HR_EFME_hasME;   //!
   TBranch        *b_mu_HR_EFME_matched;   //!
   TBranch        *b_mu_HR_L2CB_dr;   //!
   TBranch        *b_mu_HR_L2CB_pt;   //!
   TBranch        *b_mu_HR_L2CB_eta;   //!
   TBranch        *b_mu_HR_L2CB_phi;   //!
   TBranch        *b_mu_HR_L2CB_id_pt;   //!
   TBranch        *b_mu_HR_L2CB_ms_pt;   //!
   TBranch        *b_mu_HR_L2CB_matched;   //!
   TBranch        *b_mu_HR_L1_dr;   //!
   TBranch        *b_mu_HR_L1_pt;   //!
   TBranch        *b_mu_HR_L1_eta;   //!
   TBranch        *b_mu_HR_L1_phi;   //!
   TBranch        *b_mu_HR_L1_matched;   //!
   TBranch        *b_RoughRecoil_etx;   //!
   TBranch        *b_RoughRecoil_ety;   //!
   TBranch        *b_RoughRecoil_phi;   //!
   TBranch        *b_RoughRecoil_et;   //!
   TBranch        *b_RoughRecoil_sumet;   //!
   TBranch        *b_ueCorrection_etx;   //!
   TBranch        *b_ueCorrection_ety;   //!
   TBranch        *b_ueCorrection_phi;   //!
   TBranch        *b_ueCorrection_et;   //!
   TBranch        *b_ueCorrection_sumet;   //!
   TBranch        *b_jet_AntiKt4TopoEM_n;   //!
   TBranch        *b_jet_AntiKt4TopoEM_E;   //!
   TBranch        *b_jet_AntiKt4TopoEM_pt;   //!
   TBranch        *b_jet_AntiKt4TopoEM_m;   //!
   TBranch        *b_jet_AntiKt4TopoEM_eta;   //!
   TBranch        *b_jet_AntiKt4TopoEM_phi;   //!
   TBranch        *b_jet_AntiKt4TopoEM_n90;   //!
   TBranch        *b_jet_AntiKt4TopoEM_Timing;   //!
   TBranch        *b_jet_AntiKt4TopoEM_LArQuality;   //!
   TBranch        *b_jet_AntiKt4TopoEM_sumPtTrk;   //!
   TBranch        *b_jet_AntiKt4TopoEM_HECQuality;   //!
   TBranch        *b_jet_AntiKt4TopoEM_BCH_CORR_CELL;   //!
   TBranch        *b_jet_AntiKt4TopoEM_BCH_CORR_DOTX;   //!
   TBranch        *b_jet_AntiKt4TopoEM_SamplingMax;   //!
   TBranch        *b_jet_AntiKt4TopoEM_fracSamplingMax;   //!
   TBranch        *b_jet_AntiKt4TopoEM_hecf;   //!
   TBranch        *b_jet_AntiKt4TopoEM_tgap3f;   //!
   TBranch        *b_jet_AntiKt4TopoEM_isBadLoose;   //!
   TBranch        *b_jet_AntiKt4TopoEM_isBadMedium;   //!
   TBranch        *b_jet_AntiKt4TopoEM_isBadTight;   //!
   TBranch        *b_jet_AntiKt4TopoEM_emfrac;   //!
   TBranch        *b_jet_AntiKt4TopoEM_EMJES;   //!
   TBranch        *b_jet_AntiKt4TopoEM_GCWJES;   //!
   TBranch        *b_jet_AntiKt4TopoEM_emscale_E;   //!
   TBranch        *b_jet_AntiKt4TopoEM_emscale_pt;   //!
   TBranch        *b_jet_AntiKt4TopoEM_emscale_m;   //!
   TBranch        *b_jet_AntiKt4TopoEM_emscale_eta;   //!
   TBranch        *b_jet_AntiKt4TopoEM_emscale_phi;   //!
   TBranch        *b_jet_AntiKt6TopoEM_n;   //!
   TBranch        *b_jet_AntiKt6TopoEM_E;   //!
   TBranch        *b_jet_AntiKt6TopoEM_pt;   //!
   TBranch        *b_jet_AntiKt6TopoEM_m;   //!
   TBranch        *b_jet_AntiKt6TopoEM_eta;   //!
   TBranch        *b_jet_AntiKt6TopoEM_phi;   //!
   TBranch        *b_jet_AntiKt6TopoEM_n90;   //!
   TBranch        *b_jet_AntiKt6TopoEM_Timing;   //!
   TBranch        *b_jet_AntiKt6TopoEM_LArQuality;   //!
   TBranch        *b_jet_AntiKt6TopoEM_sumPtTrk;   //!
   TBranch        *b_jet_AntiKt6TopoEM_HECQuality;   //!
   TBranch        *b_jet_AntiKt6TopoEM_BCH_CORR_CELL;   //!
   TBranch        *b_jet_AntiKt6TopoEM_BCH_CORR_DOTX;   //!
   TBranch        *b_jet_AntiKt6TopoEM_SamplingMax;   //!
   TBranch        *b_jet_AntiKt6TopoEM_fracSamplingMax;   //!
   TBranch        *b_jet_AntiKt6TopoEM_hecf;   //!
   TBranch        *b_jet_AntiKt6TopoEM_tgap3f;   //!
   TBranch        *b_jet_AntiKt6TopoEM_isBadLoose;   //!
   TBranch        *b_jet_AntiKt6TopoEM_isBadMedium;   //!
   TBranch        *b_jet_AntiKt6TopoEM_isBadTight;   //!
   TBranch        *b_jet_AntiKt6TopoEM_emfrac;   //!
   TBranch        *b_jet_AntiKt6TopoEM_EMJES;   //!
   TBranch        *b_jet_AntiKt6TopoEM_GCWJES;   //!
   TBranch        *b_jet_AntiKt6TopoEM_emscale_E;   //!
   TBranch        *b_jet_AntiKt6TopoEM_emscale_pt;   //!
   TBranch        *b_jet_AntiKt6TopoEM_emscale_m;   //!
   TBranch        *b_jet_AntiKt6TopoEM_emscale_eta;   //!
   TBranch        *b_jet_AntiKt6TopoEM_emscale_phi;   //!
   TBranch        *b_jet_AntiKt6LCTopo_n;   //!
   TBranch        *b_jet_AntiKt6LCTopo_E;   //!
   TBranch        *b_jet_AntiKt6LCTopo_pt;   //!
   TBranch        *b_jet_AntiKt6LCTopo_m;   //!
   TBranch        *b_jet_AntiKt6LCTopo_eta;   //!
   TBranch        *b_jet_AntiKt6LCTopo_phi;   //!
   TBranch        *b_jet_AntiKt6LCTopo_n90;   //!
   TBranch        *b_jet_AntiKt6LCTopo_Timing;   //!
   TBranch        *b_jet_AntiKt6LCTopo_LArQuality;   //!
   TBranch        *b_jet_AntiKt6LCTopo_sumPtTrk;   //!
   TBranch        *b_jet_AntiKt6LCTopo_HECQuality;   //!
   TBranch        *b_jet_AntiKt6LCTopo_BCH_CORR_CELL;   //!
   TBranch        *b_jet_AntiKt6LCTopo_BCH_CORR_DOTX;   //!
   TBranch        *b_jet_AntiKt6LCTopo_SamplingMax;   //!
   TBranch        *b_jet_AntiKt6LCTopo_fracSamplingMax;   //!
   TBranch        *b_jet_AntiKt6LCTopo_hecf;   //!
   TBranch        *b_jet_AntiKt6LCTopo_tgap3f;   //!
   TBranch        *b_jet_AntiKt6LCTopo_isBadLoose;   //!
   TBranch        *b_jet_AntiKt6LCTopo_isBadMedium;   //!
   TBranch        *b_jet_AntiKt6LCTopo_isBadTight;   //!
   TBranch        *b_jet_AntiKt6LCTopo_emfrac;   //!
   TBranch        *b_jet_AntiKt6LCTopo_EMJES;   //!
   TBranch        *b_jet_AntiKt6LCTopo_GCWJES;   //!
   TBranch        *b_jet_AntiKt6LCTopo_emscale_E;   //!
   TBranch        *b_jet_AntiKt6LCTopo_emscale_pt;   //!
   TBranch        *b_jet_AntiKt6LCTopo_emscale_m;   //!
   TBranch        *b_jet_AntiKt6LCTopo_emscale_eta;   //!
   TBranch        *b_jet_AntiKt6LCTopo_emscale_phi;   //!
   TBranch        *b_MET_RefFinal_etx;   //!
   TBranch        *b_MET_RefFinal_ety;   //!
   TBranch        *b_MET_RefFinal_phi;   //!
   TBranch        *b_MET_RefFinal_et;   //!
   TBranch        *b_MET_RefFinal_sumet;   //!
   TBranch        *b_MET_RefFinal_etx_CentralReg;   //!
   TBranch        *b_MET_RefFinal_ety_CentralReg;   //!
   TBranch        *b_MET_RefFinal_sumet_CentralReg;   //!
   TBranch        *b_MET_RefFinal_phi_CentralReg;   //!
   TBranch        *b_MET_RefFinal_etx_EndcapRegion;   //!
   TBranch        *b_MET_RefFinal_ety_EndcapRegion;   //!
   TBranch        *b_MET_RefFinal_sumet_EndcapRegion;   //!
   TBranch        *b_MET_RefFinal_phi_EndcapRegion;   //!
   TBranch        *b_MET_RefFinal_etx_ForwardReg;   //!
   TBranch        *b_MET_RefFinal_ety_ForwardReg;   //!
   TBranch        *b_MET_RefFinal_sumet_ForwardReg;   //!
   TBranch        *b_MET_RefFinal_phi_ForwardReg;   //!
   TBranch        *b_MET_Cryo_etx;   //!
   TBranch        *b_MET_Cryo_ety;   //!
   TBranch        *b_MET_Cryo_phi;   //!
   TBranch        *b_MET_Cryo_et;   //!
   TBranch        *b_MET_Cryo_sumet;   //!
   TBranch        *b_MET_Cryo_etx_CentralReg;   //!
   TBranch        *b_MET_Cryo_ety_CentralReg;   //!
   TBranch        *b_MET_Cryo_sumet_CentralReg;   //!
   TBranch        *b_MET_Cryo_phi_CentralReg;   //!
   TBranch        *b_MET_Cryo_etx_EndcapRegion;   //!
   TBranch        *b_MET_Cryo_ety_EndcapRegion;   //!
   TBranch        *b_MET_Cryo_sumet_EndcapRegion;   //!
   TBranch        *b_MET_Cryo_phi_EndcapRegion;   //!
   TBranch        *b_MET_Cryo_etx_ForwardReg;   //!
   TBranch        *b_MET_Cryo_ety_ForwardReg;   //!
   TBranch        *b_MET_Cryo_sumet_ForwardReg;   //!
   TBranch        *b_MET_Cryo_phi_ForwardReg;   //!
   TBranch        *b_MET_RefEle_etx;   //!
   TBranch        *b_MET_RefEle_ety;   //!
   TBranch        *b_MET_RefEle_phi;   //!
   TBranch        *b_MET_RefEle_et;   //!
   TBranch        *b_MET_RefEle_sumet;   //!
   TBranch        *b_MET_RefEle_etx_CentralReg;   //!
   TBranch        *b_MET_RefEle_ety_CentralReg;   //!
   TBranch        *b_MET_RefEle_sumet_CentralReg;   //!
   TBranch        *b_MET_RefEle_phi_CentralReg;   //!
   TBranch        *b_MET_RefEle_etx_EndcapRegion;   //!
   TBranch        *b_MET_RefEle_ety_EndcapRegion;   //!
   TBranch        *b_MET_RefEle_sumet_EndcapRegion;   //!
   TBranch        *b_MET_RefEle_phi_EndcapRegion;   //!
   TBranch        *b_MET_RefEle_etx_ForwardReg;   //!
   TBranch        *b_MET_RefEle_ety_ForwardReg;   //!
   TBranch        *b_MET_RefEle_sumet_ForwardReg;   //!
   TBranch        *b_MET_RefEle_phi_ForwardReg;   //!
   TBranch        *b_MET_RefJet_etx;   //!
   TBranch        *b_MET_RefJet_ety;   //!
   TBranch        *b_MET_RefJet_phi;   //!
   TBranch        *b_MET_RefJet_et;   //!
   TBranch        *b_MET_RefJet_sumet;   //!
   TBranch        *b_MET_RefJet_etx_CentralReg;   //!
   TBranch        *b_MET_RefJet_ety_CentralReg;   //!
   TBranch        *b_MET_RefJet_sumet_CentralReg;   //!
   TBranch        *b_MET_RefJet_phi_CentralReg;   //!
   TBranch        *b_MET_RefJet_etx_EndcapRegion;   //!
   TBranch        *b_MET_RefJet_ety_EndcapRegion;   //!
   TBranch        *b_MET_RefJet_sumet_EndcapRegion;   //!
   TBranch        *b_MET_RefJet_phi_EndcapRegion;   //!
   TBranch        *b_MET_RefJet_etx_ForwardReg;   //!
   TBranch        *b_MET_RefJet_ety_ForwardReg;   //!
   TBranch        *b_MET_RefJet_sumet_ForwardReg;   //!
   TBranch        *b_MET_RefJet_phi_ForwardReg;   //!
   TBranch        *b_MET_SoftJets_etx;   //!
   TBranch        *b_MET_SoftJets_ety;   //!
   TBranch        *b_MET_SoftJets_phi;   //!
   TBranch        *b_MET_SoftJets_et;   //!
   TBranch        *b_MET_SoftJets_sumet;   //!
   TBranch        *b_MET_SoftJets_etx_CentralReg;   //!
   TBranch        *b_MET_SoftJets_ety_CentralReg;   //!
   TBranch        *b_MET_SoftJets_sumet_CentralReg;   //!
   TBranch        *b_MET_SoftJets_phi_CentralReg;   //!
   TBranch        *b_MET_SoftJets_etx_EndcapRegion;   //!
   TBranch        *b_MET_SoftJets_ety_EndcapRegion;   //!
   TBranch        *b_MET_SoftJets_sumet_EndcapRegion;   //!
   TBranch        *b_MET_SoftJets_phi_EndcapRegion;   //!
   TBranch        *b_MET_SoftJets_etx_ForwardReg;   //!
   TBranch        *b_MET_SoftJets_ety_ForwardReg;   //!
   TBranch        *b_MET_SoftJets_sumet_ForwardReg;   //!
   TBranch        *b_MET_SoftJets_phi_ForwardReg;   //!
   TBranch        *b_MET_RefMuon_etx;   //!
   TBranch        *b_MET_RefMuon_ety;   //!
   TBranch        *b_MET_RefMuon_phi;   //!
   TBranch        *b_MET_RefMuon_et;   //!
   TBranch        *b_MET_RefMuon_sumet;   //!
   TBranch        *b_MET_RefMuon_etx_CentralReg;   //!
   TBranch        *b_MET_RefMuon_ety_CentralReg;   //!
   TBranch        *b_MET_RefMuon_sumet_CentralReg;   //!
   TBranch        *b_MET_RefMuon_phi_CentralReg;   //!
   TBranch        *b_MET_RefMuon_etx_EndcapRegion;   //!
   TBranch        *b_MET_RefMuon_ety_EndcapRegion;   //!
   TBranch        *b_MET_RefMuon_sumet_EndcapRegion;   //!
   TBranch        *b_MET_RefMuon_phi_EndcapRegion;   //!
   TBranch        *b_MET_RefMuon_etx_ForwardReg;   //!
   TBranch        *b_MET_RefMuon_ety_ForwardReg;   //!
   TBranch        *b_MET_RefMuon_sumet_ForwardReg;   //!
   TBranch        *b_MET_RefMuon_phi_ForwardReg;   //!
   TBranch        *b_MET_RefMuon_Staco_etx;   //!
   TBranch        *b_MET_RefMuon_Staco_ety;   //!
   TBranch        *b_MET_RefMuon_Staco_phi;   //!
   TBranch        *b_MET_RefMuon_Staco_et;   //!
   TBranch        *b_MET_RefMuon_Staco_sumet;   //!
   TBranch        *b_MET_RefMuon_Staco_etx_CentralReg;   //!
   TBranch        *b_MET_RefMuon_Staco_ety_CentralReg;   //!
   TBranch        *b_MET_RefMuon_Staco_sumet_CentralReg;   //!
   TBranch        *b_MET_RefMuon_Staco_phi_CentralReg;   //!
   TBranch        *b_MET_RefMuon_Staco_etx_EndcapRegion;   //!
   TBranch        *b_MET_RefMuon_Staco_ety_EndcapRegion;   //!
   TBranch        *b_MET_RefMuon_Staco_sumet_EndcapRegion;   //!
   TBranch        *b_MET_RefMuon_Staco_phi_EndcapRegion;   //!
   TBranch        *b_MET_RefMuon_Staco_etx_ForwardReg;   //!
   TBranch        *b_MET_RefMuon_Staco_ety_ForwardReg;   //!
   TBranch        *b_MET_RefMuon_Staco_sumet_ForwardReg;   //!
   TBranch        *b_MET_RefMuon_Staco_phi_ForwardReg;   //!
   TBranch        *b_MET_RefMuon_Muid_etx;   //!
   TBranch        *b_MET_RefMuon_Muid_ety;   //!
   TBranch        *b_MET_RefMuon_Muid_phi;   //!
   TBranch        *b_MET_RefMuon_Muid_et;   //!
   TBranch        *b_MET_RefMuon_Muid_sumet;   //!
   TBranch        *b_MET_RefMuon_Muid_etx_CentralReg;   //!
   TBranch        *b_MET_RefMuon_Muid_ety_CentralReg;   //!
   TBranch        *b_MET_RefMuon_Muid_sumet_CentralReg;   //!
   TBranch        *b_MET_RefMuon_Muid_phi_CentralReg;   //!
   TBranch        *b_MET_RefMuon_Muid_etx_EndcapRegion;   //!
   TBranch        *b_MET_RefMuon_Muid_ety_EndcapRegion;   //!
   TBranch        *b_MET_RefMuon_Muid_sumet_EndcapRegion;   //!
   TBranch        *b_MET_RefMuon_Muid_phi_EndcapRegion;   //!
   TBranch        *b_MET_RefMuon_Muid_etx_ForwardReg;   //!
   TBranch        *b_MET_RefMuon_Muid_ety_ForwardReg;   //!
   TBranch        *b_MET_RefMuon_Muid_sumet_ForwardReg;   //!
   TBranch        *b_MET_RefMuon_Muid_phi_ForwardReg;   //!
   TBranch        *b_MET_RefGamma_etx;   //!
   TBranch        *b_MET_RefGamma_ety;   //!
   TBranch        *b_MET_RefGamma_phi;   //!
   TBranch        *b_MET_RefGamma_et;   //!
   TBranch        *b_MET_RefGamma_sumet;   //!
   TBranch        *b_MET_RefGamma_etx_CentralReg;   //!
   TBranch        *b_MET_RefGamma_ety_CentralReg;   //!
   TBranch        *b_MET_RefGamma_sumet_CentralReg;   //!
   TBranch        *b_MET_RefGamma_phi_CentralReg;   //!
   TBranch        *b_MET_RefGamma_etx_EndcapRegion;   //!
   TBranch        *b_MET_RefGamma_ety_EndcapRegion;   //!
   TBranch        *b_MET_RefGamma_sumet_EndcapRegion;   //!
   TBranch        *b_MET_RefGamma_phi_EndcapRegion;   //!
   TBranch        *b_MET_RefGamma_etx_ForwardReg;   //!
   TBranch        *b_MET_RefGamma_ety_ForwardReg;   //!
   TBranch        *b_MET_RefGamma_sumet_ForwardReg;   //!
   TBranch        *b_MET_RefGamma_phi_ForwardReg;   //!
   TBranch        *b_MET_RefTau_etx;   //!
   TBranch        *b_MET_RefTau_ety;   //!
   TBranch        *b_MET_RefTau_phi;   //!
   TBranch        *b_MET_RefTau_et;   //!
   TBranch        *b_MET_RefTau_sumet;   //!
   TBranch        *b_MET_RefTau_etx_CentralReg;   //!
   TBranch        *b_MET_RefTau_ety_CentralReg;   //!
   TBranch        *b_MET_RefTau_sumet_CentralReg;   //!
   TBranch        *b_MET_RefTau_phi_CentralReg;   //!
   TBranch        *b_MET_RefTau_etx_EndcapRegion;   //!
   TBranch        *b_MET_RefTau_ety_EndcapRegion;   //!
   TBranch        *b_MET_RefTau_sumet_EndcapRegion;   //!
   TBranch        *b_MET_RefTau_phi_EndcapRegion;   //!
   TBranch        *b_MET_RefTau_etx_ForwardReg;   //!
   TBranch        *b_MET_RefTau_ety_ForwardReg;   //!
   TBranch        *b_MET_RefTau_sumet_ForwardReg;   //!
   TBranch        *b_MET_RefTau_phi_ForwardReg;   //!
   TBranch        *b_MET_CellOut_etx;   //!
   TBranch        *b_MET_CellOut_ety;   //!
   TBranch        *b_MET_CellOut_phi;   //!
   TBranch        *b_MET_CellOut_et;   //!
   TBranch        *b_MET_CellOut_sumet;   //!
   TBranch        *b_MET_CellOut_etx_CentralReg;   //!
   TBranch        *b_MET_CellOut_ety_CentralReg;   //!
   TBranch        *b_MET_CellOut_sumet_CentralReg;   //!
   TBranch        *b_MET_CellOut_phi_CentralReg;   //!
   TBranch        *b_MET_CellOut_etx_EndcapRegion;   //!
   TBranch        *b_MET_CellOut_ety_EndcapRegion;   //!
   TBranch        *b_MET_CellOut_sumet_EndcapRegion;   //!
   TBranch        *b_MET_CellOut_phi_EndcapRegion;   //!
   TBranch        *b_MET_CellOut_etx_ForwardReg;   //!
   TBranch        *b_MET_CellOut_ety_ForwardReg;   //!
   TBranch        *b_MET_CellOut_sumet_ForwardReg;   //!
   TBranch        *b_MET_CellOut_phi_ForwardReg;   //!
   TBranch        *b_MET_Track_etx;   //!
   TBranch        *b_MET_Track_ety;   //!
   TBranch        *b_MET_Track_phi;   //!
   TBranch        *b_MET_Track_et;   //!
   TBranch        *b_MET_Track_sumet;   //!
   TBranch        *b_MET_Track_etx_CentralReg;   //!
   TBranch        *b_MET_Track_ety_CentralReg;   //!
   TBranch        *b_MET_Track_sumet_CentralReg;   //!
   TBranch        *b_MET_Track_phi_CentralReg;   //!
   TBranch        *b_MET_Track_etx_EndcapRegion;   //!
   TBranch        *b_MET_Track_ety_EndcapRegion;   //!
   TBranch        *b_MET_Track_sumet_EndcapRegion;   //!
   TBranch        *b_MET_Track_phi_EndcapRegion;   //!
   TBranch        *b_MET_Track_etx_ForwardReg;   //!
   TBranch        *b_MET_Track_ety_ForwardReg;   //!
   TBranch        *b_MET_Track_sumet_ForwardReg;   //!
   TBranch        *b_MET_Track_phi_ForwardReg;   //!
   TBranch        *b_MET_RefFinal_em_etx;   //!
   TBranch        *b_MET_RefFinal_em_ety;   //!
   TBranch        *b_MET_RefFinal_em_phi;   //!
   TBranch        *b_MET_RefFinal_em_et;   //!
   TBranch        *b_MET_RefFinal_em_sumet;   //!
   TBranch        *b_MET_RefFinal_em_etx_CentralReg;   //!
   TBranch        *b_MET_RefFinal_em_ety_CentralReg;   //!
   TBranch        *b_MET_RefFinal_em_sumet_CentralReg;   //!
   TBranch        *b_MET_RefFinal_em_phi_CentralReg;   //!
   TBranch        *b_MET_RefFinal_em_etx_EndcapRegion;   //!
   TBranch        *b_MET_RefFinal_em_ety_EndcapRegion;   //!
   TBranch        *b_MET_RefFinal_em_sumet_EndcapRegion;   //!
   TBranch        *b_MET_RefFinal_em_phi_EndcapRegion;   //!
   TBranch        *b_MET_RefFinal_em_etx_ForwardReg;   //!
   TBranch        *b_MET_RefFinal_em_ety_ForwardReg;   //!
   TBranch        *b_MET_RefFinal_em_sumet_ForwardReg;   //!
   TBranch        *b_MET_RefFinal_em_phi_ForwardReg;   //!
   TBranch        *b_MET_RefEle_em_etx;   //!
   TBranch        *b_MET_RefEle_em_ety;   //!
   TBranch        *b_MET_RefEle_em_phi;   //!
   TBranch        *b_MET_RefEle_em_et;   //!
   TBranch        *b_MET_RefEle_em_sumet;   //!
   TBranch        *b_MET_RefEle_em_etx_CentralReg;   //!
   TBranch        *b_MET_RefEle_em_ety_CentralReg;   //!
   TBranch        *b_MET_RefEle_em_sumet_CentralReg;   //!
   TBranch        *b_MET_RefEle_em_phi_CentralReg;   //!
   TBranch        *b_MET_RefEle_em_etx_EndcapRegion;   //!
   TBranch        *b_MET_RefEle_em_ety_EndcapRegion;   //!
   TBranch        *b_MET_RefEle_em_sumet_EndcapRegion;   //!
   TBranch        *b_MET_RefEle_em_phi_EndcapRegion;   //!
   TBranch        *b_MET_RefEle_em_etx_ForwardReg;   //!
   TBranch        *b_MET_RefEle_em_ety_ForwardReg;   //!
   TBranch        *b_MET_RefEle_em_sumet_ForwardReg;   //!
   TBranch        *b_MET_RefEle_em_phi_ForwardReg;   //!
   TBranch        *b_MET_RefJet_em_etx;   //!
   TBranch        *b_MET_RefJet_em_ety;   //!
   TBranch        *b_MET_RefJet_em_phi;   //!
   TBranch        *b_MET_RefJet_em_et;   //!
   TBranch        *b_MET_RefJet_em_sumet;   //!
   TBranch        *b_MET_RefJet_em_etx_CentralReg;   //!
   TBranch        *b_MET_RefJet_em_ety_CentralReg;   //!
   TBranch        *b_MET_RefJet_em_sumet_CentralReg;   //!
   TBranch        *b_MET_RefJet_em_phi_CentralReg;   //!
   TBranch        *b_MET_RefJet_em_etx_EndcapRegion;   //!
   TBranch        *b_MET_RefJet_em_ety_EndcapRegion;   //!
   TBranch        *b_MET_RefJet_em_sumet_EndcapRegion;   //!
   TBranch        *b_MET_RefJet_em_phi_EndcapRegion;   //!
   TBranch        *b_MET_RefJet_em_etx_ForwardReg;   //!
   TBranch        *b_MET_RefJet_em_ety_ForwardReg;   //!
   TBranch        *b_MET_RefJet_em_sumet_ForwardReg;   //!
   TBranch        *b_MET_RefJet_em_phi_ForwardReg;   //!
   TBranch        *b_MET_SoftJets_em_etx;   //!
   TBranch        *b_MET_SoftJets_em_ety;   //!
   TBranch        *b_MET_SoftJets_em_phi;   //!
   TBranch        *b_MET_SoftJets_em_et;   //!
   TBranch        *b_MET_SoftJets_em_sumet;   //!
   TBranch        *b_MET_SoftJets_em_etx_CentralReg;   //!
   TBranch        *b_MET_SoftJets_em_ety_CentralReg;   //!
   TBranch        *b_MET_SoftJets_em_sumet_CentralReg;   //!
   TBranch        *b_MET_SoftJets_em_phi_CentralReg;   //!
   TBranch        *b_MET_SoftJets_em_etx_EndcapRegion;   //!
   TBranch        *b_MET_SoftJets_em_ety_EndcapRegion;   //!
   TBranch        *b_MET_SoftJets_em_sumet_EndcapRegion;   //!
   TBranch        *b_MET_SoftJets_em_phi_EndcapRegion;   //!
   TBranch        *b_MET_SoftJets_em_etx_ForwardReg;   //!
   TBranch        *b_MET_SoftJets_em_ety_ForwardReg;   //!
   TBranch        *b_MET_SoftJets_em_sumet_ForwardReg;   //!
   TBranch        *b_MET_SoftJets_em_phi_ForwardReg;   //!
   TBranch        *b_MET_RefMuon_em_etx;   //!
   TBranch        *b_MET_RefMuon_em_ety;   //!
   TBranch        *b_MET_RefMuon_em_phi;   //!
   TBranch        *b_MET_RefMuon_em_et;   //!
   TBranch        *b_MET_RefMuon_em_sumet;   //!
   TBranch        *b_MET_RefMuon_em_etx_CentralReg;   //!
   TBranch        *b_MET_RefMuon_em_ety_CentralReg;   //!
   TBranch        *b_MET_RefMuon_em_sumet_CentralReg;   //!
   TBranch        *b_MET_RefMuon_em_phi_CentralReg;   //!
   TBranch        *b_MET_RefMuon_em_etx_EndcapRegion;   //!
   TBranch        *b_MET_RefMuon_em_ety_EndcapRegion;   //!
   TBranch        *b_MET_RefMuon_em_sumet_EndcapRegion;   //!
   TBranch        *b_MET_RefMuon_em_phi_EndcapRegion;   //!
   TBranch        *b_MET_RefMuon_em_etx_ForwardReg;   //!
   TBranch        *b_MET_RefMuon_em_ety_ForwardReg;   //!
   TBranch        *b_MET_RefMuon_em_sumet_ForwardReg;   //!
   TBranch        *b_MET_RefMuon_em_phi_ForwardReg;   //!
   TBranch        *b_MET_RefMuon_Track_em_etx;   //!
   TBranch        *b_MET_RefMuon_Track_em_ety;   //!
   TBranch        *b_MET_RefMuon_Track_em_phi;   //!
   TBranch        *b_MET_RefMuon_Track_em_et;   //!
   TBranch        *b_MET_RefMuon_Track_em_sumet;   //!
   TBranch        *b_MET_RefMuon_Track_em_etx_CentralReg;   //!
   TBranch        *b_MET_RefMuon_Track_em_ety_CentralReg;   //!
   TBranch        *b_MET_RefMuon_Track_em_sumet_CentralReg;   //!
   TBranch        *b_MET_RefMuon_Track_em_phi_CentralReg;   //!
   TBranch        *b_MET_RefMuon_Track_em_etx_EndcapRegion;   //!
   TBranch        *b_MET_RefMuon_Track_em_ety_EndcapRegion;   //!
   TBranch        *b_MET_RefMuon_Track_em_sumet_EndcapRegion;   //!
   TBranch        *b_MET_RefMuon_Track_em_phi_EndcapRegion;   //!
   TBranch        *b_MET_RefMuon_Track_em_etx_ForwardReg;   //!
   TBranch        *b_MET_RefMuon_Track_em_ety_ForwardReg;   //!
   TBranch        *b_MET_RefMuon_Track_em_sumet_ForwardReg;   //!
   TBranch        *b_MET_RefMuon_Track_em_phi_ForwardReg;   //!
   TBranch        *b_MET_RefGamma_em_etx;   //!
   TBranch        *b_MET_RefGamma_em_ety;   //!
   TBranch        *b_MET_RefGamma_em_phi;   //!
   TBranch        *b_MET_RefGamma_em_et;   //!
   TBranch        *b_MET_RefGamma_em_sumet;   //!
   TBranch        *b_MET_RefGamma_em_etx_CentralReg;   //!
   TBranch        *b_MET_RefGamma_em_ety_CentralReg;   //!
   TBranch        *b_MET_RefGamma_em_sumet_CentralReg;   //!
   TBranch        *b_MET_RefGamma_em_phi_CentralReg;   //!
   TBranch        *b_MET_RefGamma_em_etx_EndcapRegion;   //!
   TBranch        *b_MET_RefGamma_em_ety_EndcapRegion;   //!
   TBranch        *b_MET_RefGamma_em_sumet_EndcapRegion;   //!
   TBranch        *b_MET_RefGamma_em_phi_EndcapRegion;   //!
   TBranch        *b_MET_RefGamma_em_etx_ForwardReg;   //!
   TBranch        *b_MET_RefGamma_em_ety_ForwardReg;   //!
   TBranch        *b_MET_RefGamma_em_sumet_ForwardReg;   //!
   TBranch        *b_MET_RefGamma_em_phi_ForwardReg;   //!
   TBranch        *b_MET_RefTau_em_etx;   //!
   TBranch        *b_MET_RefTau_em_ety;   //!
   TBranch        *b_MET_RefTau_em_phi;   //!
   TBranch        *b_MET_RefTau_em_et;   //!
   TBranch        *b_MET_RefTau_em_sumet;   //!
   TBranch        *b_MET_RefTau_em_etx_CentralReg;   //!
   TBranch        *b_MET_RefTau_em_ety_CentralReg;   //!
   TBranch        *b_MET_RefTau_em_sumet_CentralReg;   //!
   TBranch        *b_MET_RefTau_em_phi_CentralReg;   //!
   TBranch        *b_MET_RefTau_em_etx_EndcapRegion;   //!
   TBranch        *b_MET_RefTau_em_ety_EndcapRegion;   //!
   TBranch        *b_MET_RefTau_em_sumet_EndcapRegion;   //!
   TBranch        *b_MET_RefTau_em_phi_EndcapRegion;   //!
   TBranch        *b_MET_RefTau_em_etx_ForwardReg;   //!
   TBranch        *b_MET_RefTau_em_ety_ForwardReg;   //!
   TBranch        *b_MET_RefTau_em_sumet_ForwardReg;   //!
   TBranch        *b_MET_RefTau_em_phi_ForwardReg;   //!
   TBranch        *b_MET_CellOut_em_etx;   //!
   TBranch        *b_MET_CellOut_em_ety;   //!
   TBranch        *b_MET_CellOut_em_phi;   //!
   TBranch        *b_MET_CellOut_em_et;   //!
   TBranch        *b_MET_CellOut_em_sumet;   //!
   TBranch        *b_MET_CellOut_em_etx_CentralReg;   //!
   TBranch        *b_MET_CellOut_em_ety_CentralReg;   //!
   TBranch        *b_MET_CellOut_em_sumet_CentralReg;   //!
   TBranch        *b_MET_CellOut_em_phi_CentralReg;   //!
   TBranch        *b_MET_CellOut_em_etx_EndcapRegion;   //!
   TBranch        *b_MET_CellOut_em_ety_EndcapRegion;   //!
   TBranch        *b_MET_CellOut_em_sumet_EndcapRegion;   //!
   TBranch        *b_MET_CellOut_em_phi_EndcapRegion;   //!
   TBranch        *b_MET_CellOut_em_etx_ForwardReg;   //!
   TBranch        *b_MET_CellOut_em_ety_ForwardReg;   //!
   TBranch        *b_MET_CellOut_em_sumet_ForwardReg;   //!
   TBranch        *b_MET_CellOut_em_phi_ForwardReg;   //!
   TBranch        *b_MET_Muon_Isol_Staco_etx;   //!
   TBranch        *b_MET_Muon_Isol_Staco_ety;   //!
   TBranch        *b_MET_Muon_Isol_Staco_phi;   //!
   TBranch        *b_MET_Muon_Isol_Staco_et;   //!
   TBranch        *b_MET_Muon_Isol_Staco_sumet;   //!
   TBranch        *b_MET_Muon_Isol_Staco_etx_CentralReg;   //!
   TBranch        *b_MET_Muon_Isol_Staco_ety_CentralReg;   //!
   TBranch        *b_MET_Muon_Isol_Staco_sumet_CentralReg;   //!
   TBranch        *b_MET_Muon_Isol_Staco_phi_CentralReg;   //!
   TBranch        *b_MET_Muon_Isol_Staco_etx_EndcapRegion;   //!
   TBranch        *b_MET_Muon_Isol_Staco_ety_EndcapRegion;   //!
   TBranch        *b_MET_Muon_Isol_Staco_sumet_EndcapRegion;   //!
   TBranch        *b_MET_Muon_Isol_Staco_phi_EndcapRegion;   //!
   TBranch        *b_MET_Muon_Isol_Staco_etx_ForwardReg;   //!
   TBranch        *b_MET_Muon_Isol_Staco_ety_ForwardReg;   //!
   TBranch        *b_MET_Muon_Isol_Staco_sumet_ForwardReg;   //!
   TBranch        *b_MET_Muon_Isol_Staco_phi_ForwardReg;   //!
   TBranch        *b_MET_Muon_NonIsol_Staco_etx;   //!
   TBranch        *b_MET_Muon_NonIsol_Staco_ety;   //!
   TBranch        *b_MET_Muon_NonIsol_Staco_phi;   //!
   TBranch        *b_MET_Muon_NonIsol_Staco_et;   //!
   TBranch        *b_MET_Muon_NonIsol_Staco_sumet;   //!
   TBranch        *b_MET_Muon_NonIsol_Staco_etx_CentralReg;   //!
   TBranch        *b_MET_Muon_NonIsol_Staco_ety_CentralReg;   //!
   TBranch        *b_MET_Muon_NonIsol_Staco_sumet_CentralReg;   //!
   TBranch        *b_MET_Muon_NonIsol_Staco_phi_CentralReg;   //!
   TBranch        *b_MET_Muon_NonIsol_Staco_etx_EndcapRegion;   //!
   TBranch        *b_MET_Muon_NonIsol_Staco_ety_EndcapRegion;   //!
   TBranch        *b_MET_Muon_NonIsol_Staco_sumet_EndcapRegion;   //!
   TBranch        *b_MET_Muon_NonIsol_Staco_phi_EndcapRegion;   //!
   TBranch        *b_MET_Muon_NonIsol_Staco_etx_ForwardReg;   //!
   TBranch        *b_MET_Muon_NonIsol_Staco_ety_ForwardReg;   //!
   TBranch        *b_MET_Muon_NonIsol_Staco_sumet_ForwardReg;   //!
   TBranch        *b_MET_Muon_NonIsol_Staco_phi_ForwardReg;   //!
   TBranch        *b_MET_Muon_Total_Staco_etx;   //!
   TBranch        *b_MET_Muon_Total_Staco_ety;   //!
   TBranch        *b_MET_Muon_Total_Staco_phi;   //!
   TBranch        *b_MET_Muon_Total_Staco_et;   //!
   TBranch        *b_MET_Muon_Total_Staco_sumet;   //!
   TBranch        *b_MET_Muon_Total_Staco_etx_CentralReg;   //!
   TBranch        *b_MET_Muon_Total_Staco_ety_CentralReg;   //!
   TBranch        *b_MET_Muon_Total_Staco_sumet_CentralReg;   //!
   TBranch        *b_MET_Muon_Total_Staco_phi_CentralReg;   //!
   TBranch        *b_MET_Muon_Total_Staco_etx_EndcapRegion;   //!
   TBranch        *b_MET_Muon_Total_Staco_ety_EndcapRegion;   //!
   TBranch        *b_MET_Muon_Total_Staco_sumet_EndcapRegion;   //!
   TBranch        *b_MET_Muon_Total_Staco_phi_EndcapRegion;   //!
   TBranch        *b_MET_Muon_Total_Staco_etx_ForwardReg;   //!
   TBranch        *b_MET_Muon_Total_Staco_ety_ForwardReg;   //!
   TBranch        *b_MET_Muon_Total_Staco_sumet_ForwardReg;   //!
   TBranch        *b_MET_Muon_Total_Staco_phi_ForwardReg;   //!
   TBranch        *b_MET_Muon_Isol_Muid_etx;   //!
   TBranch        *b_MET_Muon_Isol_Muid_ety;   //!
   TBranch        *b_MET_Muon_Isol_Muid_phi;   //!
   TBranch        *b_MET_Muon_Isol_Muid_et;   //!
   TBranch        *b_MET_Muon_Isol_Muid_sumet;   //!
   TBranch        *b_MET_Muon_Isol_Muid_etx_CentralReg;   //!
   TBranch        *b_MET_Muon_Isol_Muid_ety_CentralReg;   //!
   TBranch        *b_MET_Muon_Isol_Muid_sumet_CentralReg;   //!
   TBranch        *b_MET_Muon_Isol_Muid_phi_CentralReg;   //!
   TBranch        *b_MET_Muon_Isol_Muid_etx_EndcapRegion;   //!
   TBranch        *b_MET_Muon_Isol_Muid_ety_EndcapRegion;   //!
   TBranch        *b_MET_Muon_Isol_Muid_sumet_EndcapRegion;   //!
   TBranch        *b_MET_Muon_Isol_Muid_phi_EndcapRegion;   //!
   TBranch        *b_MET_Muon_Isol_Muid_etx_ForwardReg;   //!
   TBranch        *b_MET_Muon_Isol_Muid_ety_ForwardReg;   //!
   TBranch        *b_MET_Muon_Isol_Muid_sumet_ForwardReg;   //!
   TBranch        *b_MET_Muon_Isol_Muid_phi_ForwardReg;   //!
   TBranch        *b_MET_Muon_NonIsol_Muid_etx;   //!
   TBranch        *b_MET_Muon_NonIsol_Muid_ety;   //!
   TBranch        *b_MET_Muon_NonIsol_Muid_phi;   //!
   TBranch        *b_MET_Muon_NonIsol_Muid_et;   //!
   TBranch        *b_MET_Muon_NonIsol_Muid_sumet;   //!
   TBranch        *b_MET_Muon_NonIsol_Muid_etx_CentralReg;   //!
   TBranch        *b_MET_Muon_NonIsol_Muid_ety_CentralReg;   //!
   TBranch        *b_MET_Muon_NonIsol_Muid_sumet_CentralReg;   //!
   TBranch        *b_MET_Muon_NonIsol_Muid_phi_CentralReg;   //!
   TBranch        *b_MET_Muon_NonIsol_Muid_etx_EndcapRegion;   //!
   TBranch        *b_MET_Muon_NonIsol_Muid_ety_EndcapRegion;   //!
   TBranch        *b_MET_Muon_NonIsol_Muid_sumet_EndcapRegion;   //!
   TBranch        *b_MET_Muon_NonIsol_Muid_phi_EndcapRegion;   //!
   TBranch        *b_MET_Muon_NonIsol_Muid_etx_ForwardReg;   //!
   TBranch        *b_MET_Muon_NonIsol_Muid_ety_ForwardReg;   //!
   TBranch        *b_MET_Muon_NonIsol_Muid_sumet_ForwardReg;   //!
   TBranch        *b_MET_Muon_NonIsol_Muid_phi_ForwardReg;   //!
   TBranch        *b_MET_Muon_Total_Muid_etx;   //!
   TBranch        *b_MET_Muon_Total_Muid_ety;   //!
   TBranch        *b_MET_Muon_Total_Muid_phi;   //!
   TBranch        *b_MET_Muon_Total_Muid_et;   //!
   TBranch        *b_MET_Muon_Total_Muid_sumet;   //!
   TBranch        *b_MET_Muon_Total_Muid_etx_CentralReg;   //!
   TBranch        *b_MET_Muon_Total_Muid_ety_CentralReg;   //!
   TBranch        *b_MET_Muon_Total_Muid_sumet_CentralReg;   //!
   TBranch        *b_MET_Muon_Total_Muid_phi_CentralReg;   //!
   TBranch        *b_MET_Muon_Total_Muid_etx_EndcapRegion;   //!
   TBranch        *b_MET_Muon_Total_Muid_ety_EndcapRegion;   //!
   TBranch        *b_MET_Muon_Total_Muid_sumet_EndcapRegion;   //!
   TBranch        *b_MET_Muon_Total_Muid_phi_EndcapRegion;   //!
   TBranch        *b_MET_Muon_Total_Muid_etx_ForwardReg;   //!
   TBranch        *b_MET_Muon_Total_Muid_ety_ForwardReg;   //!
   TBranch        *b_MET_Muon_Total_Muid_sumet_ForwardReg;   //!
   TBranch        *b_MET_Muon_Total_Muid_phi_ForwardReg;   //!
   TBranch        *b_MET_MuonBoy_etx;   //!
   TBranch        *b_MET_MuonBoy_ety;   //!
   TBranch        *b_MET_MuonBoy_phi;   //!
   TBranch        *b_MET_MuonBoy_et;   //!
   TBranch        *b_MET_MuonBoy_sumet;   //!
   TBranch        *b_MET_MuonBoy_etx_CentralReg;   //!
   TBranch        *b_MET_MuonBoy_ety_CentralReg;   //!
   TBranch        *b_MET_MuonBoy_sumet_CentralReg;   //!
   TBranch        *b_MET_MuonBoy_phi_CentralReg;   //!
   TBranch        *b_MET_MuonBoy_etx_EndcapRegion;   //!
   TBranch        *b_MET_MuonBoy_ety_EndcapRegion;   //!
   TBranch        *b_MET_MuonBoy_sumet_EndcapRegion;   //!
   TBranch        *b_MET_MuonBoy_phi_EndcapRegion;   //!
   TBranch        *b_MET_MuonBoy_etx_ForwardReg;   //!
   TBranch        *b_MET_MuonBoy_ety_ForwardReg;   //!
   TBranch        *b_MET_MuonBoy_sumet_ForwardReg;   //!
   TBranch        *b_MET_MuonBoy_phi_ForwardReg;   //!
   TBranch        *b_MET_CellOut_Eflow_etx;   //!
   TBranch        *b_MET_CellOut_Eflow_ety;   //!
   TBranch        *b_MET_CellOut_Eflow_phi;   //!
   TBranch        *b_MET_CellOut_Eflow_et;   //!
   TBranch        *b_MET_CellOut_Eflow_sumet;   //!
   TBranch        *b_MET_CellOut_Eflow_etx_CentralReg;   //!
   TBranch        *b_MET_CellOut_Eflow_ety_CentralReg;   //!
   TBranch        *b_MET_CellOut_Eflow_sumet_CentralReg;   //!
   TBranch        *b_MET_CellOut_Eflow_phi_CentralReg;   //!
   TBranch        *b_MET_CellOut_Eflow_etx_EndcapRegion;   //!
   TBranch        *b_MET_CellOut_Eflow_ety_EndcapRegion;   //!
   TBranch        *b_MET_CellOut_Eflow_sumet_EndcapRegion;   //!
   TBranch        *b_MET_CellOut_Eflow_phi_EndcapRegion;   //!
   TBranch        *b_MET_CellOut_Eflow_etx_ForwardReg;   //!
   TBranch        *b_MET_CellOut_Eflow_ety_ForwardReg;   //!
   TBranch        *b_MET_CellOut_Eflow_sumet_ForwardReg;   //!
   TBranch        *b_MET_CellOut_Eflow_phi_ForwardReg;   //!
   TBranch        *b_MET_CellOut_MiniJet_etx;   //!
   TBranch        *b_MET_CellOut_MiniJet_ety;   //!
   TBranch        *b_MET_CellOut_MiniJet_phi;   //!
   TBranch        *b_MET_CellOut_MiniJet_et;   //!
   TBranch        *b_MET_CellOut_MiniJet_sumet;   //!
   TBranch        *b_MET_CellOut_MiniJet_etx_CentralReg;   //!
   TBranch        *b_MET_CellOut_MiniJet_ety_CentralReg;   //!
   TBranch        *b_MET_CellOut_MiniJet_sumet_CentralReg;   //!
   TBranch        *b_MET_CellOut_MiniJet_phi_CentralReg;   //!
   TBranch        *b_MET_CellOut_MiniJet_etx_EndcapRegion;   //!
   TBranch        *b_MET_CellOut_MiniJet_ety_EndcapRegion;   //!
   TBranch        *b_MET_CellOut_MiniJet_sumet_EndcapRegion;   //!
   TBranch        *b_MET_CellOut_MiniJet_phi_EndcapRegion;   //!
   TBranch        *b_MET_CellOut_MiniJet_etx_ForwardReg;   //!
   TBranch        *b_MET_CellOut_MiniJet_ety_ForwardReg;   //!
   TBranch        *b_MET_CellOut_MiniJet_sumet_ForwardReg;   //!
   TBranch        *b_MET_CellOut_MiniJet_phi_ForwardReg;   //!
   TBranch        *b_MET_RefMuon_Track_etx;   //!
   TBranch        *b_MET_RefMuon_Track_ety;   //!
   TBranch        *b_MET_RefMuon_Track_phi;   //!
   TBranch        *b_MET_RefMuon_Track_et;   //!
   TBranch        *b_MET_RefMuon_Track_sumet;   //!
   TBranch        *b_MET_RefMuon_Track_etx_CentralReg;   //!
   TBranch        *b_MET_RefMuon_Track_ety_CentralReg;   //!
   TBranch        *b_MET_RefMuon_Track_sumet_CentralReg;   //!
   TBranch        *b_MET_RefMuon_Track_phi_CentralReg;   //!
   TBranch        *b_MET_RefMuon_Track_etx_EndcapRegion;   //!
   TBranch        *b_MET_RefMuon_Track_ety_EndcapRegion;   //!
   TBranch        *b_MET_RefMuon_Track_sumet_EndcapRegion;   //!
   TBranch        *b_MET_RefMuon_Track_phi_EndcapRegion;   //!
   TBranch        *b_MET_RefMuon_Track_etx_ForwardReg;   //!
   TBranch        *b_MET_RefMuon_Track_ety_ForwardReg;   //!
   TBranch        *b_MET_RefMuon_Track_sumet_ForwardReg;   //!
   TBranch        *b_MET_RefMuon_Track_phi_ForwardReg;   //!
   TBranch        *b_MET_RefMuon_Track_Staco_etx;   //!
   TBranch        *b_MET_RefMuon_Track_Staco_ety;   //!
   TBranch        *b_MET_RefMuon_Track_Staco_phi;   //!
   TBranch        *b_MET_RefMuon_Track_Staco_et;   //!
   TBranch        *b_MET_RefMuon_Track_Staco_sumet;   //!
   TBranch        *b_MET_RefMuon_Track_Staco_etx_CentralReg;   //!
   TBranch        *b_MET_RefMuon_Track_Staco_ety_CentralReg;   //!
   TBranch        *b_MET_RefMuon_Track_Staco_sumet_CentralReg;   //!
   TBranch        *b_MET_RefMuon_Track_Staco_phi_CentralReg;   //!
   TBranch        *b_MET_RefMuon_Track_Staco_etx_EndcapRegion;   //!
   TBranch        *b_MET_RefMuon_Track_Staco_ety_EndcapRegion;   //!
   TBranch        *b_MET_RefMuon_Track_Staco_sumet_EndcapRegion;   //!
   TBranch        *b_MET_RefMuon_Track_Staco_phi_EndcapRegion;   //!
   TBranch        *b_MET_RefMuon_Track_Staco_etx_ForwardReg;   //!
   TBranch        *b_MET_RefMuon_Track_Staco_ety_ForwardReg;   //!
   TBranch        *b_MET_RefMuon_Track_Staco_sumet_ForwardReg;   //!
   TBranch        *b_MET_RefMuon_Track_Staco_phi_ForwardReg;   //!
   TBranch        *b_MET_RefMuon_Track_Muid_etx;   //!
   TBranch        *b_MET_RefMuon_Track_Muid_ety;   //!
   TBranch        *b_MET_RefMuon_Track_Muid_phi;   //!
   TBranch        *b_MET_RefMuon_Track_Muid_et;   //!
   TBranch        *b_MET_RefMuon_Track_Muid_sumet;   //!
   TBranch        *b_MET_RefMuon_Track_Muid_etx_CentralReg;   //!
   TBranch        *b_MET_RefMuon_Track_Muid_ety_CentralReg;   //!
   TBranch        *b_MET_RefMuon_Track_Muid_sumet_CentralReg;   //!
   TBranch        *b_MET_RefMuon_Track_Muid_phi_CentralReg;   //!
   TBranch        *b_MET_RefMuon_Track_Muid_etx_EndcapRegion;   //!
   TBranch        *b_MET_RefMuon_Track_Muid_ety_EndcapRegion;   //!
   TBranch        *b_MET_RefMuon_Track_Muid_sumet_EndcapRegion;   //!
   TBranch        *b_MET_RefMuon_Track_Muid_phi_EndcapRegion;   //!
   TBranch        *b_MET_RefMuon_Track_Muid_etx_ForwardReg;   //!
   TBranch        *b_MET_RefMuon_Track_Muid_ety_ForwardReg;   //!
   TBranch        *b_MET_RefMuon_Track_Muid_sumet_ForwardReg;   //!
   TBranch        *b_MET_RefMuon_Track_Muid_phi_ForwardReg;   //!
   TBranch        *b_MET_CryoCone_etx;   //!
   TBranch        *b_MET_CryoCone_ety;   //!
   TBranch        *b_MET_CryoCone_phi;   //!
   TBranch        *b_MET_CryoCone_et;   //!
   TBranch        *b_MET_CryoCone_sumet;   //!
   TBranch        *b_MET_CryoCone_etx_CentralReg;   //!
   TBranch        *b_MET_CryoCone_ety_CentralReg;   //!
   TBranch        *b_MET_CryoCone_sumet_CentralReg;   //!
   TBranch        *b_MET_CryoCone_phi_CentralReg;   //!
   TBranch        *b_MET_CryoCone_etx_EndcapRegion;   //!
   TBranch        *b_MET_CryoCone_ety_EndcapRegion;   //!
   TBranch        *b_MET_CryoCone_sumet_EndcapRegion;   //!
   TBranch        *b_MET_CryoCone_phi_EndcapRegion;   //!
   TBranch        *b_MET_CryoCone_etx_ForwardReg;   //!
   TBranch        *b_MET_CryoCone_ety_ForwardReg;   //!
   TBranch        *b_MET_CryoCone_sumet_ForwardReg;   //!
   TBranch        *b_MET_CryoCone_phi_ForwardReg;   //!
   TBranch        *b_MET_Final_etx;   //!
   TBranch        *b_MET_Final_ety;   //!
   TBranch        *b_MET_Final_phi;   //!
   TBranch        *b_MET_Final_et;   //!
   TBranch        *b_MET_Final_sumet;   //!
   TBranch        *b_MET_Final_etx_CentralReg;   //!
   TBranch        *b_MET_Final_ety_CentralReg;   //!
   TBranch        *b_MET_Final_sumet_CentralReg;   //!
   TBranch        *b_MET_Final_phi_CentralReg;   //!
   TBranch        *b_MET_Final_etx_EndcapRegion;   //!
   TBranch        *b_MET_Final_ety_EndcapRegion;   //!
   TBranch        *b_MET_Final_sumet_EndcapRegion;   //!
   TBranch        *b_MET_Final_phi_EndcapRegion;   //!
   TBranch        *b_MET_Final_etx_ForwardReg;   //!
   TBranch        *b_MET_Final_ety_ForwardReg;   //!
   TBranch        *b_MET_Final_sumet_ForwardReg;   //!
   TBranch        *b_MET_Final_phi_ForwardReg;   //!
   TBranch        *b_MET_MuonBoy_Spectro_etx;   //!
   TBranch        *b_MET_MuonBoy_Spectro_ety;   //!
   TBranch        *b_MET_MuonBoy_Spectro_phi;   //!
   TBranch        *b_MET_MuonBoy_Spectro_et;   //!
   TBranch        *b_MET_MuonBoy_Spectro_sumet;   //!
   TBranch        *b_MET_MuonBoy_Spectro_etx_CentralReg;   //!
   TBranch        *b_MET_MuonBoy_Spectro_ety_CentralReg;   //!
   TBranch        *b_MET_MuonBoy_Spectro_sumet_CentralReg;   //!
   TBranch        *b_MET_MuonBoy_Spectro_phi_CentralReg;   //!
   TBranch        *b_MET_MuonBoy_Spectro_etx_EndcapRegion;   //!
   TBranch        *b_MET_MuonBoy_Spectro_ety_EndcapRegion;   //!
   TBranch        *b_MET_MuonBoy_Spectro_sumet_EndcapRegion;   //!
   TBranch        *b_MET_MuonBoy_Spectro_phi_EndcapRegion;   //!
   TBranch        *b_MET_MuonBoy_Spectro_etx_ForwardReg;   //!
   TBranch        *b_MET_MuonBoy_Spectro_ety_ForwardReg;   //!
   TBranch        *b_MET_MuonBoy_Spectro_sumet_ForwardReg;   //!
   TBranch        *b_MET_MuonBoy_Spectro_phi_ForwardReg;   //!
   TBranch        *b_MET_MuonBoy_Track_etx;   //!
   TBranch        *b_MET_MuonBoy_Track_ety;   //!
   TBranch        *b_MET_MuonBoy_Track_phi;   //!
   TBranch        *b_MET_MuonBoy_Track_et;   //!
   TBranch        *b_MET_MuonBoy_Track_sumet;   //!
   TBranch        *b_MET_MuonBoy_Track_etx_CentralReg;   //!
   TBranch        *b_MET_MuonBoy_Track_ety_CentralReg;   //!
   TBranch        *b_MET_MuonBoy_Track_sumet_CentralReg;   //!
   TBranch        *b_MET_MuonBoy_Track_phi_CentralReg;   //!
   TBranch        *b_MET_MuonBoy_Track_etx_EndcapRegion;   //!
   TBranch        *b_MET_MuonBoy_Track_ety_EndcapRegion;   //!
   TBranch        *b_MET_MuonBoy_Track_sumet_EndcapRegion;   //!
   TBranch        *b_MET_MuonBoy_Track_phi_EndcapRegion;   //!
   TBranch        *b_MET_MuonBoy_Track_etx_ForwardReg;   //!
   TBranch        *b_MET_MuonBoy_Track_ety_ForwardReg;   //!
   TBranch        *b_MET_MuonBoy_Track_sumet_ForwardReg;   //!
   TBranch        *b_MET_MuonBoy_Track_phi_ForwardReg;   //!
   TBranch        *b_MET_MuonMuid_etx;   //!
   TBranch        *b_MET_MuonMuid_ety;   //!
   TBranch        *b_MET_MuonMuid_phi;   //!
   TBranch        *b_MET_MuonMuid_et;   //!
   TBranch        *b_MET_MuonMuid_sumet;   //!
   TBranch        *b_MET_MuonMuid_etx_CentralReg;   //!
   TBranch        *b_MET_MuonMuid_ety_CentralReg;   //!
   TBranch        *b_MET_MuonMuid_sumet_CentralReg;   //!
   TBranch        *b_MET_MuonMuid_phi_CentralReg;   //!
   TBranch        *b_MET_MuonMuid_etx_EndcapRegion;   //!
   TBranch        *b_MET_MuonMuid_ety_EndcapRegion;   //!
   TBranch        *b_MET_MuonMuid_sumet_EndcapRegion;   //!
   TBranch        *b_MET_MuonMuid_phi_EndcapRegion;   //!
   TBranch        *b_MET_MuonMuid_etx_ForwardReg;   //!
   TBranch        *b_MET_MuonMuid_ety_ForwardReg;   //!
   TBranch        *b_MET_MuonMuid_sumet_ForwardReg;   //!
   TBranch        *b_MET_MuonMuid_phi_ForwardReg;   //!
   TBranch        *b_MET_Muid_etx;   //!
   TBranch        *b_MET_Muid_ety;   //!
   TBranch        *b_MET_Muid_phi;   //!
   TBranch        *b_MET_Muid_et;   //!
   TBranch        *b_MET_Muid_sumet;   //!
   TBranch        *b_MET_Muid_etx_CentralReg;   //!
   TBranch        *b_MET_Muid_ety_CentralReg;   //!
   TBranch        *b_MET_Muid_sumet_CentralReg;   //!
   TBranch        *b_MET_Muid_phi_CentralReg;   //!
   TBranch        *b_MET_Muid_etx_EndcapRegion;   //!
   TBranch        *b_MET_Muid_ety_EndcapRegion;   //!
   TBranch        *b_MET_Muid_sumet_EndcapRegion;   //!
   TBranch        *b_MET_Muid_phi_EndcapRegion;   //!
   TBranch        *b_MET_Muid_etx_ForwardReg;   //!
   TBranch        *b_MET_Muid_ety_ForwardReg;   //!
   TBranch        *b_MET_Muid_sumet_ForwardReg;   //!
   TBranch        *b_MET_Muid_phi_ForwardReg;   //!
   TBranch        *b_MET_Muid_Spectro_etx;   //!
   TBranch        *b_MET_Muid_Spectro_ety;   //!
   TBranch        *b_MET_Muid_Spectro_phi;   //!
   TBranch        *b_MET_Muid_Spectro_et;   //!
   TBranch        *b_MET_Muid_Spectro_sumet;   //!
   TBranch        *b_MET_Muid_Spectro_etx_CentralReg;   //!
   TBranch        *b_MET_Muid_Spectro_ety_CentralReg;   //!
   TBranch        *b_MET_Muid_Spectro_sumet_CentralReg;   //!
   TBranch        *b_MET_Muid_Spectro_phi_CentralReg;   //!
   TBranch        *b_MET_Muid_Spectro_etx_EndcapRegion;   //!
   TBranch        *b_MET_Muid_Spectro_ety_EndcapRegion;   //!
   TBranch        *b_MET_Muid_Spectro_sumet_EndcapRegion;   //!
   TBranch        *b_MET_Muid_Spectro_phi_EndcapRegion;   //!
   TBranch        *b_MET_Muid_Spectro_etx_ForwardReg;   //!
   TBranch        *b_MET_Muid_Spectro_ety_ForwardReg;   //!
   TBranch        *b_MET_Muid_Spectro_sumet_ForwardReg;   //!
   TBranch        *b_MET_Muid_Spectro_phi_ForwardReg;   //!
   TBranch        *b_MET_Muid_Track_etx;   //!
   TBranch        *b_MET_Muid_Track_ety;   //!
   TBranch        *b_MET_Muid_Track_phi;   //!
   TBranch        *b_MET_Muid_Track_et;   //!
   TBranch        *b_MET_Muid_Track_sumet;   //!
   TBranch        *b_MET_Muid_Track_etx_CentralReg;   //!
   TBranch        *b_MET_Muid_Track_ety_CentralReg;   //!
   TBranch        *b_MET_Muid_Track_sumet_CentralReg;   //!
   TBranch        *b_MET_Muid_Track_phi_CentralReg;   //!
   TBranch        *b_MET_Muid_Track_etx_EndcapRegion;   //!
   TBranch        *b_MET_Muid_Track_ety_EndcapRegion;   //!
   TBranch        *b_MET_Muid_Track_sumet_EndcapRegion;   //!
   TBranch        *b_MET_Muid_Track_phi_EndcapRegion;   //!
   TBranch        *b_MET_Muid_Track_etx_ForwardReg;   //!
   TBranch        *b_MET_Muid_Track_ety_ForwardReg;   //!
   TBranch        *b_MET_Muid_Track_sumet_ForwardReg;   //!
   TBranch        *b_MET_Muid_Track_phi_ForwardReg;   //!
   TBranch        *b_MET_Muon_etx;   //!
   TBranch        *b_MET_Muon_ety;   //!
   TBranch        *b_MET_Muon_phi;   //!
   TBranch        *b_MET_Muon_et;   //!
   TBranch        *b_MET_Muon_sumet;   //!
   TBranch        *b_MET_Muon_etx_CentralReg;   //!
   TBranch        *b_MET_Muon_ety_CentralReg;   //!
   TBranch        *b_MET_Muon_sumet_CentralReg;   //!
   TBranch        *b_MET_Muon_phi_CentralReg;   //!
   TBranch        *b_MET_Muon_etx_EndcapRegion;   //!
   TBranch        *b_MET_Muon_ety_EndcapRegion;   //!
   TBranch        *b_MET_Muon_sumet_EndcapRegion;   //!
   TBranch        *b_MET_Muon_phi_EndcapRegion;   //!
   TBranch        *b_MET_Muon_etx_ForwardReg;   //!
   TBranch        *b_MET_Muon_ety_ForwardReg;   //!
   TBranch        *b_MET_Muon_sumet_ForwardReg;   //!
   TBranch        *b_MET_Muon_phi_ForwardReg;   //!
   TBranch        *b_MET_TopoObj_etx;   //!
   TBranch        *b_MET_TopoObj_ety;   //!
   TBranch        *b_MET_TopoObj_phi;   //!
   TBranch        *b_MET_TopoObj_et;   //!
   TBranch        *b_MET_TopoObj_sumet;   //!
   TBranch        *b_MET_TopoObj_etx_CentralReg;   //!
   TBranch        *b_MET_TopoObj_ety_CentralReg;   //!
   TBranch        *b_MET_TopoObj_sumet_CentralReg;   //!
   TBranch        *b_MET_TopoObj_phi_CentralReg;   //!
   TBranch        *b_MET_TopoObj_etx_EndcapRegion;   //!
   TBranch        *b_MET_TopoObj_ety_EndcapRegion;   //!
   TBranch        *b_MET_TopoObj_sumet_EndcapRegion;   //!
   TBranch        *b_MET_TopoObj_phi_EndcapRegion;   //!
   TBranch        *b_MET_TopoObj_etx_ForwardReg;   //!
   TBranch        *b_MET_TopoObj_ety_ForwardReg;   //!
   TBranch        *b_MET_TopoObj_sumet_ForwardReg;   //!
   TBranch        *b_MET_TopoObj_phi_ForwardReg;   //!
   TBranch        *b_MET_LocHadTopoObj_etx;   //!
   TBranch        *b_MET_LocHadTopoObj_ety;   //!
   TBranch        *b_MET_LocHadTopoObj_phi;   //!
   TBranch        *b_MET_LocHadTopoObj_et;   //!
   TBranch        *b_MET_LocHadTopoObj_sumet;   //!
   TBranch        *b_MET_LocHadTopoObj_etx_CentralReg;   //!
   TBranch        *b_MET_LocHadTopoObj_ety_CentralReg;   //!
   TBranch        *b_MET_LocHadTopoObj_sumet_CentralReg;   //!
   TBranch        *b_MET_LocHadTopoObj_phi_CentralReg;   //!
   TBranch        *b_MET_LocHadTopoObj_etx_EndcapRegion;   //!
   TBranch        *b_MET_LocHadTopoObj_ety_EndcapRegion;   //!
   TBranch        *b_MET_LocHadTopoObj_sumet_EndcapRegion;   //!
   TBranch        *b_MET_LocHadTopoObj_phi_EndcapRegion;   //!
   TBranch        *b_MET_LocHadTopoObj_etx_ForwardReg;   //!
   TBranch        *b_MET_LocHadTopoObj_ety_ForwardReg;   //!
   TBranch        *b_MET_LocHadTopoObj_sumet_ForwardReg;   //!
   TBranch        *b_MET_LocHadTopoObj_phi_ForwardReg;   //!
   TBranch        *b_MET_Topo_etx;   //!
   TBranch        *b_MET_Topo_ety;   //!
   TBranch        *b_MET_Topo_phi;   //!
   TBranch        *b_MET_Topo_et;   //!
   TBranch        *b_MET_Topo_sumet;   //!
   TBranch        *b_MET_Topo_SUMET_EMFrac;   //!
   TBranch        *b_MET_Topo_etx_PEMB;   //!
   TBranch        *b_MET_Topo_ety_PEMB;   //!
   TBranch        *b_MET_Topo_sumet_PEMB;   //!
   TBranch        *b_MET_Topo_phi_PEMB;   //!
   TBranch        *b_MET_Topo_etx_EMB;   //!
   TBranch        *b_MET_Topo_ety_EMB;   //!
   TBranch        *b_MET_Topo_sumet_EMB;   //!
   TBranch        *b_MET_Topo_phi_EMB;   //!
   TBranch        *b_MET_Topo_etx_PEMEC;   //!
   TBranch        *b_MET_Topo_ety_PEMEC;   //!
   TBranch        *b_MET_Topo_sumet_PEMEC;   //!
   TBranch        *b_MET_Topo_phi_PEMEC;   //!
   TBranch        *b_MET_Topo_etx_EME;   //!
   TBranch        *b_MET_Topo_ety_EME;   //!
   TBranch        *b_MET_Topo_sumet_EME;   //!
   TBranch        *b_MET_Topo_phi_EME;   //!
   TBranch        *b_MET_Topo_etx_TILE;   //!
   TBranch        *b_MET_Topo_ety_TILE;   //!
   TBranch        *b_MET_Topo_sumet_TILE;   //!
   TBranch        *b_MET_Topo_phi_TILE;   //!
   TBranch        *b_MET_Topo_etx_HEC;   //!
   TBranch        *b_MET_Topo_ety_HEC;   //!
   TBranch        *b_MET_Topo_sumet_HEC;   //!
   TBranch        *b_MET_Topo_phi_HEC;   //!
   TBranch        *b_MET_Topo_etx_FCAL;   //!
   TBranch        *b_MET_Topo_ety_FCAL;   //!
   TBranch        *b_MET_Topo_sumet_FCAL;   //!
   TBranch        *b_MET_Topo_phi_FCAL;   //!
   TBranch        *b_MET_Topo_nCell_PEMB;   //!
   TBranch        *b_MET_Topo_nCell_EMB;   //!
   TBranch        *b_MET_Topo_nCell_PEMEC;   //!
   TBranch        *b_MET_Topo_nCell_EME;   //!
   TBranch        *b_MET_Topo_nCell_TILE;   //!
   TBranch        *b_MET_Topo_nCell_HEC;   //!
   TBranch        *b_MET_Topo_nCell_FCAL;   //!
   TBranch        *b_MET_Topo_etx_CentralReg;   //!
   TBranch        *b_MET_Topo_ety_CentralReg;   //!
   TBranch        *b_MET_Topo_sumet_CentralReg;   //!
   TBranch        *b_MET_Topo_phi_CentralReg;   //!
   TBranch        *b_MET_Topo_etx_EndcapRegion;   //!
   TBranch        *b_MET_Topo_ety_EndcapRegion;   //!
   TBranch        *b_MET_Topo_sumet_EndcapRegion;   //!
   TBranch        *b_MET_Topo_phi_EndcapRegion;   //!
   TBranch        *b_MET_Topo_etx_ForwardReg;   //!
   TBranch        *b_MET_Topo_ety_ForwardReg;   //!
   TBranch        *b_MET_Topo_sumet_ForwardReg;   //!
   TBranch        *b_MET_Topo_phi_ForwardReg;   //!
   TBranch        *b_MET_CorrTopo_etx;   //!
   TBranch        *b_MET_CorrTopo_ety;   //!
   TBranch        *b_MET_CorrTopo_phi;   //!
   TBranch        *b_MET_CorrTopo_et;   //!
   TBranch        *b_MET_CorrTopo_sumet;   //!
   TBranch        *b_MET_CorrTopo_SUMET_EMFrac;   //!
   TBranch        *b_MET_CorrTopo_etx_PEMB;   //!
   TBranch        *b_MET_CorrTopo_ety_PEMB;   //!
   TBranch        *b_MET_CorrTopo_sumet_PEMB;   //!
   TBranch        *b_MET_CorrTopo_phi_PEMB;   //!
   TBranch        *b_MET_CorrTopo_etx_EMB;   //!
   TBranch        *b_MET_CorrTopo_ety_EMB;   //!
   TBranch        *b_MET_CorrTopo_sumet_EMB;   //!
   TBranch        *b_MET_CorrTopo_phi_EMB;   //!
   TBranch        *b_MET_CorrTopo_etx_PEMEC;   //!
   TBranch        *b_MET_CorrTopo_ety_PEMEC;   //!
   TBranch        *b_MET_CorrTopo_sumet_PEMEC;   //!
   TBranch        *b_MET_CorrTopo_phi_PEMEC;   //!
   TBranch        *b_MET_CorrTopo_etx_EME;   //!
   TBranch        *b_MET_CorrTopo_ety_EME;   //!
   TBranch        *b_MET_CorrTopo_sumet_EME;   //!
   TBranch        *b_MET_CorrTopo_phi_EME;   //!
   TBranch        *b_MET_CorrTopo_etx_TILE;   //!
   TBranch        *b_MET_CorrTopo_ety_TILE;   //!
   TBranch        *b_MET_CorrTopo_sumet_TILE;   //!
   TBranch        *b_MET_CorrTopo_phi_TILE;   //!
   TBranch        *b_MET_CorrTopo_etx_HEC;   //!
   TBranch        *b_MET_CorrTopo_ety_HEC;   //!
   TBranch        *b_MET_CorrTopo_sumet_HEC;   //!
   TBranch        *b_MET_CorrTopo_phi_HEC;   //!
   TBranch        *b_MET_CorrTopo_etx_FCAL;   //!
   TBranch        *b_MET_CorrTopo_ety_FCAL;   //!
   TBranch        *b_MET_CorrTopo_sumet_FCAL;   //!
   TBranch        *b_MET_CorrTopo_phi_FCAL;   //!
   TBranch        *b_MET_CorrTopo_nCell_PEMB;   //!
   TBranch        *b_MET_CorrTopo_nCell_EMB;   //!
   TBranch        *b_MET_CorrTopo_nCell_PEMEC;   //!
   TBranch        *b_MET_CorrTopo_nCell_EME;   //!
   TBranch        *b_MET_CorrTopo_nCell_TILE;   //!
   TBranch        *b_MET_CorrTopo_nCell_HEC;   //!
   TBranch        *b_MET_CorrTopo_nCell_FCAL;   //!
   TBranch        *b_MET_CorrTopo_etx_CentralReg;   //!
   TBranch        *b_MET_CorrTopo_ety_CentralReg;   //!
   TBranch        *b_MET_CorrTopo_sumet_CentralReg;   //!
   TBranch        *b_MET_CorrTopo_phi_CentralReg;   //!
   TBranch        *b_MET_CorrTopo_etx_EndcapRegion;   //!
   TBranch        *b_MET_CorrTopo_ety_EndcapRegion;   //!
   TBranch        *b_MET_CorrTopo_sumet_EndcapRegion;   //!
   TBranch        *b_MET_CorrTopo_phi_EndcapRegion;   //!
   TBranch        *b_MET_CorrTopo_etx_ForwardReg;   //!
   TBranch        *b_MET_CorrTopo_ety_ForwardReg;   //!
   TBranch        *b_MET_CorrTopo_sumet_ForwardReg;   //!
   TBranch        *b_MET_CorrTopo_phi_ForwardReg;   //!
   TBranch        *b_MET_LocHadTopo_etx;   //!
   TBranch        *b_MET_LocHadTopo_ety;   //!
   TBranch        *b_MET_LocHadTopo_phi;   //!
   TBranch        *b_MET_LocHadTopo_et;   //!
   TBranch        *b_MET_LocHadTopo_sumet;   //!
   TBranch        *b_MET_LocHadTopo_SUMET_EMFrac;   //!
   TBranch        *b_MET_LocHadTopo_etx_PEMB;   //!
   TBranch        *b_MET_LocHadTopo_ety_PEMB;   //!
   TBranch        *b_MET_LocHadTopo_sumet_PEMB;   //!
   TBranch        *b_MET_LocHadTopo_phi_PEMB;   //!
   TBranch        *b_MET_LocHadTopo_etx_EMB;   //!
   TBranch        *b_MET_LocHadTopo_ety_EMB;   //!
   TBranch        *b_MET_LocHadTopo_sumet_EMB;   //!
   TBranch        *b_MET_LocHadTopo_phi_EMB;   //!
   TBranch        *b_MET_LocHadTopo_etx_PEMEC;   //!
   TBranch        *b_MET_LocHadTopo_ety_PEMEC;   //!
   TBranch        *b_MET_LocHadTopo_sumet_PEMEC;   //!
   TBranch        *b_MET_LocHadTopo_phi_PEMEC;   //!
   TBranch        *b_MET_LocHadTopo_etx_EME;   //!
   TBranch        *b_MET_LocHadTopo_ety_EME;   //!
   TBranch        *b_MET_LocHadTopo_sumet_EME;   //!
   TBranch        *b_MET_LocHadTopo_phi_EME;   //!
   TBranch        *b_MET_LocHadTopo_etx_TILE;   //!
   TBranch        *b_MET_LocHadTopo_ety_TILE;   //!
   TBranch        *b_MET_LocHadTopo_sumet_TILE;   //!
   TBranch        *b_MET_LocHadTopo_phi_TILE;   //!
   TBranch        *b_MET_LocHadTopo_etx_HEC;   //!
   TBranch        *b_MET_LocHadTopo_ety_HEC;   //!
   TBranch        *b_MET_LocHadTopo_sumet_HEC;   //!
   TBranch        *b_MET_LocHadTopo_phi_HEC;   //!
   TBranch        *b_MET_LocHadTopo_etx_FCAL;   //!
   TBranch        *b_MET_LocHadTopo_ety_FCAL;   //!
   TBranch        *b_MET_LocHadTopo_sumet_FCAL;   //!
   TBranch        *b_MET_LocHadTopo_phi_FCAL;   //!
   TBranch        *b_MET_LocHadTopo_nCell_PEMB;   //!
   TBranch        *b_MET_LocHadTopo_nCell_EMB;   //!
   TBranch        *b_MET_LocHadTopo_nCell_PEMEC;   //!
   TBranch        *b_MET_LocHadTopo_nCell_EME;   //!
   TBranch        *b_MET_LocHadTopo_nCell_TILE;   //!
   TBranch        *b_MET_LocHadTopo_nCell_HEC;   //!
   TBranch        *b_MET_LocHadTopo_nCell_FCAL;   //!
   TBranch        *b_MET_LocHadTopo_etx_CentralReg;   //!
   TBranch        *b_MET_LocHadTopo_ety_CentralReg;   //!
   TBranch        *b_MET_LocHadTopo_sumet_CentralReg;   //!
   TBranch        *b_MET_LocHadTopo_phi_CentralReg;   //!
   TBranch        *b_MET_LocHadTopo_etx_EndcapRegion;   //!
   TBranch        *b_MET_LocHadTopo_ety_EndcapRegion;   //!
   TBranch        *b_MET_LocHadTopo_sumet_EndcapRegion;   //!
   TBranch        *b_MET_LocHadTopo_phi_EndcapRegion;   //!
   TBranch        *b_MET_LocHadTopo_etx_ForwardReg;   //!
   TBranch        *b_MET_LocHadTopo_ety_ForwardReg;   //!
   TBranch        *b_MET_LocHadTopo_sumet_ForwardReg;   //!
   TBranch        *b_MET_LocHadTopo_phi_ForwardReg;   //!
   TBranch        *b_MET_Truth_NonInt_etx;   //!
   TBranch        *b_MET_Truth_NonInt_ety;   //!
   TBranch        *b_MET_Truth_NonInt_phi;   //!
   TBranch        *b_MET_Truth_NonInt_et;   //!
   TBranch        *b_MET_Truth_NonInt_sumet;   //!
   TBranch        *b_MET_Truth_Int_etx;   //!
   TBranch        *b_MET_Truth_Int_ety;   //!
   TBranch        *b_MET_Truth_IntCentral_etx;   //!
   TBranch        *b_MET_Truth_IntCentral_ety;   //!
   TBranch        *b_MET_Truth_IntFwd_etx;   //!
   TBranch        *b_MET_Truth_IntFwd_ety;   //!
   TBranch        *b_MET_Truth_IntOutCover_etx;   //!
   TBranch        *b_MET_Truth_IntOutCover_ety;   //!
   TBranch        *b_MET_Truth_IntMuons_etx;   //!
   TBranch        *b_MET_Truth_IntMuons_ety;   //!
   TBranch        *b_MET_Truth_Int_phi;   //!
   TBranch        *b_MET_Truth_IntCentral_phi;   //!
   TBranch        *b_MET_Truth_IntFwd_phi;   //!
   TBranch        *b_MET_Truth_IntOutCover_phi;   //!
   TBranch        *b_MET_Truth_IntMuons_phi;   //!
   TBranch        *b_MET_Truth_Int_et;   //!
   TBranch        *b_MET_Truth_IntCentral_et;   //!
   TBranch        *b_MET_Truth_IntFwd_et;   //!
   TBranch        *b_MET_Truth_IntOutCover_et;   //!
   TBranch        *b_MET_Truth_IntMuons_et;   //!
   TBranch        *b_MET_Truth_Int_sumet;   //!
   TBranch        *b_MET_Truth_IntCentral_sumet;   //!
   TBranch        *b_MET_Truth_IntFwd_sumet;   //!
   TBranch        *b_MET_Truth_IntOutCover_sumet;   //!
   TBranch        *b_MET_Truth_IntMuons_sumet;   //!
   TBranch        *b_MET_Truth_PileUp_NonInt_etx;   //!
   TBranch        *b_MET_Truth_PileUp_NonInt_ety;   //!
   TBranch        *b_MET_Truth_PileUp_NonInt_phi;   //!
   TBranch        *b_MET_Truth_PileUp_NonInt_et;   //!
   TBranch        *b_MET_Truth_PileUp_NonInt_sumet;   //!
   TBranch        *b_MET_Truth_PileUp_Int_etx;   //!
   TBranch        *b_MET_Truth_PileUp_Int_ety;   //!
   TBranch        *b_MET_Truth_PileUp_IntCentral_etx;   //!
   TBranch        *b_MET_Truth_PileUp_IntCentral_ety;   //!
   TBranch        *b_MET_Truth_PileUp_IntFwd_etx;   //!
   TBranch        *b_MET_Truth_PileUp_IntFwd_ety;   //!
   TBranch        *b_MET_Truth_PileUp_IntOutCover_etx;   //!
   TBranch        *b_MET_Truth_PileUp_IntOutCover_ety;   //!
   TBranch        *b_MET_Truth_PileUp_IntMuons_etx;   //!
   TBranch        *b_MET_Truth_PileUp_IntMuons_ety;   //!
   TBranch        *b_MET_Truth_PileUp_Int_phi;   //!
   TBranch        *b_MET_Truth_PileUp_IntCentral_phi;   //!
   TBranch        *b_MET_Truth_PileUp_IntFwd_phi;   //!
   TBranch        *b_MET_Truth_PileUp_IntOutCover_phi;   //!
   TBranch        *b_MET_Truth_PileUp_IntMuons_phi;   //!
   TBranch        *b_MET_Truth_PileUp_Int_et;   //!
   TBranch        *b_MET_Truth_PileUp_IntCentral_et;   //!
   TBranch        *b_MET_Truth_PileUp_IntFwd_et;   //!
   TBranch        *b_MET_Truth_PileUp_IntOutCover_et;   //!
   TBranch        *b_MET_Truth_PileUp_IntMuons_et;   //!
   TBranch        *b_MET_Truth_PileUp_Int_sumet;   //!
   TBranch        *b_MET_Truth_PileUp_IntCentral_sumet;   //!
   TBranch        *b_MET_Truth_PileUp_IntFwd_sumet;   //!
   TBranch        *b_MET_Truth_PileUp_IntOutCover_sumet;   //!
   TBranch        *b_MET_Truth_PileUp_IntMuons_sumet;   //!
   TBranch        *b_MET_DM_Crack1_etx;   //!
   TBranch        *b_MET_DM_Crack1_ety;   //!
   TBranch        *b_MET_DM_Crack1_phi;   //!
   TBranch        *b_MET_DM_Crack1_et;   //!
   TBranch        *b_MET_DM_Crack1_sumet;   //!
   TBranch        *b_MET_DM_Crack2_etx;   //!
   TBranch        *b_MET_DM_Crack2_ety;   //!
   TBranch        *b_MET_DM_Crack2_phi;   //!
   TBranch        *b_MET_DM_Crack2_et;   //!
   TBranch        *b_MET_DM_Crack2_sumet;   //!
   TBranch        *b_MET_DM_All_etx;   //!
   TBranch        *b_MET_DM_All_ety;   //!
   TBranch        *b_MET_DM_All_phi;   //!
   TBranch        *b_MET_DM_All_et;   //!
   TBranch        *b_MET_DM_All_sumet;   //!
   TBranch        *b_MET_DM_Cryo_etx;   //!
   TBranch        *b_MET_DM_Cryo_ety;   //!
   TBranch        *b_MET_DM_Cryo_phi;   //!
   TBranch        *b_MET_DM_Cryo_et;   //!
   TBranch        *b_MET_DM_Cryo_sumet;   //!
   TBranch        *b_el_MET_n;   //!
   TBranch        *b_el_MET_wpx;   //!
   TBranch        *b_el_MET_wpy;   //!
   TBranch        *b_el_MET_wet;   //!
   TBranch        *b_el_MET_statusWord;   //!
   TBranch        *b_ph_MET_n;   //!
   TBranch        *b_ph_MET_wpx;   //!
   TBranch        *b_ph_MET_wpy;   //!
   TBranch        *b_ph_MET_wet;   //!
   TBranch        *b_ph_MET_statusWord;   //!
   TBranch        *b_mu_staco_MET_n;   //!
   TBranch        *b_mu_staco_MET_wpx;   //!
   TBranch        *b_mu_staco_MET_wpy;   //!
   TBranch        *b_mu_staco_MET_wet;   //!
   TBranch        *b_mu_staco_MET_statusWord;   //!
   TBranch        *b_mu_muid_MET_n;   //!
   TBranch        *b_mu_muid_MET_wpx;   //!
   TBranch        *b_mu_muid_MET_wpy;   //!
   TBranch        *b_mu_muid_MET_wet;   //!
   TBranch        *b_mu_muid_MET_statusWord;   //!
   TBranch        *b_tau_MET_n;   //!
   TBranch        *b_tau_MET_wpx;   //!
   TBranch        *b_tau_MET_wpy;   //!
   TBranch        *b_tau_MET_wet;   //!
   TBranch        *b_tau_MET_statusWord;   //!
   TBranch        *b_jet_AntiKt6LCTopo_MET_n;   //!
   TBranch        *b_jet_AntiKt6LCTopo_MET_wpx;   //!
   TBranch        *b_jet_AntiKt6LCTopo_MET_wpy;   //!
   TBranch        *b_jet_AntiKt6LCTopo_MET_wet;   //!
   TBranch        *b_jet_AntiKt6LCTopo_MET_statusWord;   //!
   TBranch        *b_cl_MET_n;   //!
   TBranch        *b_cl_MET_wpx;   //!
   TBranch        *b_cl_MET_wpy;   //!
   TBranch        *b_cl_MET_wet;   //!
   TBranch        *b_cl_MET_statusWord;   //!
   TBranch        *b_trk_MET_n;   //!
   TBranch        *b_trk_MET_wpx;   //!
   TBranch        *b_trk_MET_wpy;   //!
   TBranch        *b_trk_MET_wet;   //!
   TBranch        *b_trk_MET_statusWord;   //!
   TBranch        *b_MET_RefFinal_GCW_pt20_etx;   //!
   TBranch        *b_MET_RefFinal_GCW_pt20_ety;   //!
   TBranch        *b_MET_RefFinal_GCW_pt20_phi;   //!
   TBranch        *b_MET_RefFinal_GCW_pt20_et;   //!
   TBranch        *b_MET_RefFinal_GCW_pt20_sumet;   //!
   TBranch        *b_MET_RefFinal_GCW_pt20_etx_CentralReg;   //!
   TBranch        *b_MET_RefFinal_GCW_pt20_ety_CentralReg;   //!
   TBranch        *b_MET_RefFinal_GCW_pt20_sumet_CentralReg;   //!
   TBranch        *b_MET_RefFinal_GCW_pt20_phi_CentralReg;   //!
   TBranch        *b_MET_RefFinal_GCW_pt20_etx_EndcapRegion;   //!
   TBranch        *b_MET_RefFinal_GCW_pt20_ety_EndcapRegion;   //!
   TBranch        *b_MET_RefFinal_GCW_pt20_sumet_EndcapRegion;   //!
   TBranch        *b_MET_RefFinal_GCW_pt20_phi_EndcapRegion;   //!
   TBranch        *b_MET_RefFinal_GCW_pt20_etx_ForwardReg;   //!
   TBranch        *b_MET_RefFinal_GCW_pt20_ety_ForwardReg;   //!
   TBranch        *b_MET_RefFinal_GCW_pt20_sumet_ForwardReg;   //!
   TBranch        *b_MET_RefFinal_GCW_pt20_phi_ForwardReg;   //!
   TBranch        *b_MET_RefGamma_GCW_pt20_etx;   //!
   TBranch        *b_MET_RefGamma_GCW_pt20_ety;   //!
   TBranch        *b_MET_RefGamma_GCW_pt20_phi;   //!
   TBranch        *b_MET_RefGamma_GCW_pt20_et;   //!
   TBranch        *b_MET_RefGamma_GCW_pt20_sumet;   //!
   TBranch        *b_MET_RefGamma_GCW_pt20_etx_CentralReg;   //!
   TBranch        *b_MET_RefGamma_GCW_pt20_ety_CentralReg;   //!
   TBranch        *b_MET_RefGamma_GCW_pt20_sumet_CentralReg;   //!
   TBranch        *b_MET_RefGamma_GCW_pt20_phi_CentralReg;   //!
   TBranch        *b_MET_RefGamma_GCW_pt20_etx_EndcapRegion;   //!
   TBranch        *b_MET_RefGamma_GCW_pt20_ety_EndcapRegion;   //!
   TBranch        *b_MET_RefGamma_GCW_pt20_sumet_EndcapRegion;   //!
   TBranch        *b_MET_RefGamma_GCW_pt20_phi_EndcapRegion;   //!
   TBranch        *b_MET_RefGamma_GCW_pt20_etx_ForwardReg;   //!
   TBranch        *b_MET_RefGamma_GCW_pt20_ety_ForwardReg;   //!
   TBranch        *b_MET_RefGamma_GCW_pt20_sumet_ForwardReg;   //!
   TBranch        *b_MET_RefGamma_GCW_pt20_phi_ForwardReg;   //!
   TBranch        *b_MET_RefEle_GCW_pt20_etx;   //!
   TBranch        *b_MET_RefEle_GCW_pt20_ety;   //!
   TBranch        *b_MET_RefEle_GCW_pt20_phi;   //!
   TBranch        *b_MET_RefEle_GCW_pt20_et;   //!
   TBranch        *b_MET_RefEle_GCW_pt20_sumet;   //!
   TBranch        *b_MET_RefEle_GCW_pt20_etx_CentralReg;   //!
   TBranch        *b_MET_RefEle_GCW_pt20_ety_CentralReg;   //!
   TBranch        *b_MET_RefEle_GCW_pt20_sumet_CentralReg;   //!
   TBranch        *b_MET_RefEle_GCW_pt20_phi_CentralReg;   //!
   TBranch        *b_MET_RefEle_GCW_pt20_etx_EndcapRegion;   //!
   TBranch        *b_MET_RefEle_GCW_pt20_ety_EndcapRegion;   //!
   TBranch        *b_MET_RefEle_GCW_pt20_sumet_EndcapRegion;   //!
   TBranch        *b_MET_RefEle_GCW_pt20_phi_EndcapRegion;   //!
   TBranch        *b_MET_RefEle_GCW_pt20_etx_ForwardReg;   //!
   TBranch        *b_MET_RefEle_GCW_pt20_ety_ForwardReg;   //!
   TBranch        *b_MET_RefEle_GCW_pt20_sumet_ForwardReg;   //!
   TBranch        *b_MET_RefEle_GCW_pt20_phi_ForwardReg;   //!
   TBranch        *b_MET_RefTau_GCW_pt20_etx;   //!
   TBranch        *b_MET_RefTau_GCW_pt20_ety;   //!
   TBranch        *b_MET_RefTau_GCW_pt20_phi;   //!
   TBranch        *b_MET_RefTau_GCW_pt20_et;   //!
   TBranch        *b_MET_RefTau_GCW_pt20_sumet;   //!
   TBranch        *b_MET_RefTau_GCW_pt20_etx_CentralReg;   //!
   TBranch        *b_MET_RefTau_GCW_pt20_ety_CentralReg;   //!
   TBranch        *b_MET_RefTau_GCW_pt20_sumet_CentralReg;   //!
   TBranch        *b_MET_RefTau_GCW_pt20_phi_CentralReg;   //!
   TBranch        *b_MET_RefTau_GCW_pt20_etx_EndcapRegion;   //!
   TBranch        *b_MET_RefTau_GCW_pt20_ety_EndcapRegion;   //!
   TBranch        *b_MET_RefTau_GCW_pt20_sumet_EndcapRegion;   //!
   TBranch        *b_MET_RefTau_GCW_pt20_phi_EndcapRegion;   //!
   TBranch        *b_MET_RefTau_GCW_pt20_etx_ForwardReg;   //!
   TBranch        *b_MET_RefTau_GCW_pt20_ety_ForwardReg;   //!
   TBranch        *b_MET_RefTau_GCW_pt20_sumet_ForwardReg;   //!
   TBranch        *b_MET_RefTau_GCW_pt20_phi_ForwardReg;   //!
   TBranch        *b_MET_RefJet_GCW_pt20_etx;   //!
   TBranch        *b_MET_RefJet_GCW_pt20_ety;   //!
   TBranch        *b_MET_RefJet_GCW_pt20_phi;   //!
   TBranch        *b_MET_RefJet_GCW_pt20_et;   //!
   TBranch        *b_MET_RefJet_GCW_pt20_sumet;   //!
   TBranch        *b_MET_RefJet_GCW_pt20_etx_CentralReg;   //!
   TBranch        *b_MET_RefJet_GCW_pt20_ety_CentralReg;   //!
   TBranch        *b_MET_RefJet_GCW_pt20_sumet_CentralReg;   //!
   TBranch        *b_MET_RefJet_GCW_pt20_phi_CentralReg;   //!
   TBranch        *b_MET_RefJet_GCW_pt20_etx_EndcapRegion;   //!
   TBranch        *b_MET_RefJet_GCW_pt20_ety_EndcapRegion;   //!
   TBranch        *b_MET_RefJet_GCW_pt20_sumet_EndcapRegion;   //!
   TBranch        *b_MET_RefJet_GCW_pt20_phi_EndcapRegion;   //!
   TBranch        *b_MET_RefJet_GCW_pt20_etx_ForwardReg;   //!
   TBranch        *b_MET_RefJet_GCW_pt20_ety_ForwardReg;   //!
   TBranch        *b_MET_RefJet_GCW_pt20_sumet_ForwardReg;   //!
   TBranch        *b_MET_RefJet_GCW_pt20_phi_ForwardReg;   //!
   TBranch        *b_MET_CellOut_GCW_pt20_etx;   //!
   TBranch        *b_MET_CellOut_GCW_pt20_ety;   //!
   TBranch        *b_MET_CellOut_GCW_pt20_phi;   //!
   TBranch        *b_MET_CellOut_GCW_pt20_et;   //!
   TBranch        *b_MET_CellOut_GCW_pt20_sumet;   //!
   TBranch        *b_MET_CellOut_GCW_pt20_etx_CentralReg;   //!
   TBranch        *b_MET_CellOut_GCW_pt20_ety_CentralReg;   //!
   TBranch        *b_MET_CellOut_GCW_pt20_sumet_CentralReg;   //!
   TBranch        *b_MET_CellOut_GCW_pt20_phi_CentralReg;   //!
   TBranch        *b_MET_CellOut_GCW_pt20_etx_EndcapRegion;   //!
   TBranch        *b_MET_CellOut_GCW_pt20_ety_EndcapRegion;   //!
   TBranch        *b_MET_CellOut_GCW_pt20_sumet_EndcapRegion;   //!
   TBranch        *b_MET_CellOut_GCW_pt20_phi_EndcapRegion;   //!
   TBranch        *b_MET_CellOut_GCW_pt20_etx_ForwardReg;   //!
   TBranch        *b_MET_CellOut_GCW_pt20_ety_ForwardReg;   //!
   TBranch        *b_MET_CellOut_GCW_pt20_sumet_ForwardReg;   //!
   TBranch        *b_MET_CellOut_GCW_pt20_phi_ForwardReg;   //!
   TBranch        *b_MET_Cryo_GCW_pt20_etx;   //!
   TBranch        *b_MET_Cryo_GCW_pt20_ety;   //!
   TBranch        *b_MET_Cryo_GCW_pt20_phi;   //!
   TBranch        *b_MET_Cryo_GCW_pt20_et;   //!
   TBranch        *b_MET_Cryo_GCW_pt20_sumet;   //!
   TBranch        *b_MET_Cryo_GCW_pt20_etx_CentralReg;   //!
   TBranch        *b_MET_Cryo_GCW_pt20_ety_CentralReg;   //!
   TBranch        *b_MET_Cryo_GCW_pt20_sumet_CentralReg;   //!
   TBranch        *b_MET_Cryo_GCW_pt20_phi_CentralReg;   //!
   TBranch        *b_MET_Cryo_GCW_pt20_etx_EndcapRegion;   //!
   TBranch        *b_MET_Cryo_GCW_pt20_ety_EndcapRegion;   //!
   TBranch        *b_MET_Cryo_GCW_pt20_sumet_EndcapRegion;   //!
   TBranch        *b_MET_Cryo_GCW_pt20_phi_EndcapRegion;   //!
   TBranch        *b_MET_Cryo_GCW_pt20_etx_ForwardReg;   //!
   TBranch        *b_MET_Cryo_GCW_pt20_ety_ForwardReg;   //!
   TBranch        *b_MET_Cryo_GCW_pt20_sumet_ForwardReg;   //!
   TBranch        *b_MET_Cryo_GCW_pt20_phi_ForwardReg;   //!
   TBranch        *b_MET_RefMuon_GCW_pt20_etx;   //!
   TBranch        *b_MET_RefMuon_GCW_pt20_ety;   //!
   TBranch        *b_MET_RefMuon_GCW_pt20_phi;   //!
   TBranch        *b_MET_RefMuon_GCW_pt20_et;   //!
   TBranch        *b_MET_RefMuon_GCW_pt20_sumet;   //!
   TBranch        *b_MET_RefMuon_Staco_GCW_pt20_etx;   //!
   TBranch        *b_MET_RefMuon_Staco_GCW_pt20_ety;   //!
   TBranch        *b_MET_RefMuon_Staco_GCW_pt20_phi;   //!
   TBranch        *b_MET_RefMuon_Staco_GCW_pt20_et;   //!
   TBranch        *b_MET_RefMuon_Staco_GCW_pt20_sumet;   //!
   TBranch        *b_MET_Muon_Isol_Staco_GCW_pt20_etx;   //!
   TBranch        *b_MET_Muon_Isol_Staco_GCW_pt20_ety;   //!
   TBranch        *b_MET_Muon_Isol_Staco_GCW_pt20_phi;   //!
   TBranch        *b_MET_Muon_Isol_Staco_GCW_pt20_et;   //!
   TBranch        *b_MET_Muon_Isol_Staco_GCW_pt20_sumet;   //!
   TBranch        *b_MET_Muon_NonIsol_Staco_GCW_pt20_etx;   //!
   TBranch        *b_MET_Muon_NonIsol_Staco_GCW_pt20_ety;   //!
   TBranch        *b_MET_Muon_NonIsol_Staco_GCW_pt20_phi;   //!
   TBranch        *b_MET_Muon_NonIsol_Staco_GCW_pt20_et;   //!
   TBranch        *b_MET_Muon_NonIsol_Staco_GCW_pt20_sumet;   //!
   TBranch        *b_MET_Muon_Total_Staco_GCW_pt20_etx;   //!
   TBranch        *b_MET_Muon_Total_Staco_GCW_pt20_ety;   //!
   TBranch        *b_MET_Muon_Total_Staco_GCW_pt20_phi;   //!
   TBranch        *b_MET_Muon_Total_Staco_GCW_pt20_et;   //!
   TBranch        *b_MET_Muon_Total_Staco_GCW_pt20_sumet;   //!
   TBranch        *b_MET_RefMuon_Track_GCW_pt20_etx;   //!
   TBranch        *b_MET_RefMuon_Track_GCW_pt20_ety;   //!
   TBranch        *b_MET_RefMuon_Track_GCW_pt20_phi;   //!
   TBranch        *b_MET_RefMuon_Track_GCW_pt20_et;   //!
   TBranch        *b_MET_RefMuon_Track_GCW_pt20_sumet;   //!
   TBranch        *b_MET_RefMuon_Track_Staco_GCW_pt20_etx;   //!
   TBranch        *b_MET_RefMuon_Track_Staco_GCW_pt20_ety;   //!
   TBranch        *b_MET_RefMuon_Track_Staco_GCW_pt20_phi;   //!
   TBranch        *b_MET_RefMuon_Track_Staco_GCW_pt20_et;   //!
   TBranch        *b_MET_RefMuon_Track_Staco_GCW_pt20_sumet;   //!
   TBranch        *b_MET_RefFinal_LCW_NI_eflow4_etx;   //!
   TBranch        *b_MET_RefFinal_LCW_NI_eflow4_ety;   //!
   TBranch        *b_MET_RefFinal_LCW_NI_eflow4_phi;   //!
   TBranch        *b_MET_RefFinal_LCW_NI_eflow4_et;   //!
   TBranch        *b_MET_RefFinal_LCW_NI_eflow4_sumet;   //!
   TBranch        *b_MET_RefFinal_LCW_NI_eflow4_etx_CentralReg;   //!
   TBranch        *b_MET_RefFinal_LCW_NI_eflow4_ety_CentralReg;   //!
   TBranch        *b_MET_RefFinal_LCW_NI_eflow4_sumet_CentralReg;   //!
   TBranch        *b_MET_RefFinal_LCW_NI_eflow4_phi_CentralReg;   //!
   TBranch        *b_MET_RefFinal_LCW_NI_eflow4_etx_EndcapRegion;   //!
   TBranch        *b_MET_RefFinal_LCW_NI_eflow4_ety_EndcapRegion;   //!
   TBranch        *b_MET_RefFinal_LCW_NI_eflow4_sumet_EndcapRegion;   //!
   TBranch        *b_MET_RefFinal_LCW_NI_eflow4_phi_EndcapRegion;   //!
   TBranch        *b_MET_RefFinal_LCW_NI_eflow4_etx_ForwardReg;   //!
   TBranch        *b_MET_RefFinal_LCW_NI_eflow4_ety_ForwardReg;   //!
   TBranch        *b_MET_RefFinal_LCW_NI_eflow4_sumet_ForwardReg;   //!
   TBranch        *b_MET_RefFinal_LCW_NI_eflow4_phi_ForwardReg;   //!
   TBranch        *b_MET_RefGamma_LCW_NI_eflow4_etx;   //!
   TBranch        *b_MET_RefGamma_LCW_NI_eflow4_ety;   //!
   TBranch        *b_MET_RefGamma_LCW_NI_eflow4_phi;   //!
   TBranch        *b_MET_RefGamma_LCW_NI_eflow4_et;   //!
   TBranch        *b_MET_RefGamma_LCW_NI_eflow4_sumet;   //!
   TBranch        *b_MET_RefGamma_LCW_NI_eflow4_etx_CentralReg;   //!
   TBranch        *b_MET_RefGamma_LCW_NI_eflow4_ety_CentralReg;   //!
   TBranch        *b_MET_RefGamma_LCW_NI_eflow4_sumet_CentralReg;   //!
   TBranch        *b_MET_RefGamma_LCW_NI_eflow4_phi_CentralReg;   //!
   TBranch        *b_MET_RefGamma_LCW_NI_eflow4_etx_EndcapRegion;   //!
   TBranch        *b_MET_RefGamma_LCW_NI_eflow4_ety_EndcapRegion;   //!
   TBranch        *b_MET_RefGamma_LCW_NI_eflow4_sumet_EndcapRegion;   //!
   TBranch        *b_MET_RefGamma_LCW_NI_eflow4_phi_EndcapRegion;   //!
   TBranch        *b_MET_RefGamma_LCW_NI_eflow4_etx_ForwardReg;   //!
   TBranch        *b_MET_RefGamma_LCW_NI_eflow4_ety_ForwardReg;   //!
   TBranch        *b_MET_RefGamma_LCW_NI_eflow4_sumet_ForwardReg;   //!
   TBranch        *b_MET_RefGamma_LCW_NI_eflow4_phi_ForwardReg;   //!
   TBranch        *b_MET_RefEle_LCW_NI_eflow4_etx;   //!
   TBranch        *b_MET_RefEle_LCW_NI_eflow4_ety;   //!
   TBranch        *b_MET_RefEle_LCW_NI_eflow4_phi;   //!
   TBranch        *b_MET_RefEle_LCW_NI_eflow4_et;   //!
   TBranch        *b_MET_RefEle_LCW_NI_eflow4_sumet;   //!
   TBranch        *b_MET_RefEle_LCW_NI_eflow4_etx_CentralReg;   //!
   TBranch        *b_MET_RefEle_LCW_NI_eflow4_ety_CentralReg;   //!
   TBranch        *b_MET_RefEle_LCW_NI_eflow4_sumet_CentralReg;   //!
   TBranch        *b_MET_RefEle_LCW_NI_eflow4_phi_CentralReg;   //!
   TBranch        *b_MET_RefEle_LCW_NI_eflow4_etx_EndcapRegion;   //!
   TBranch        *b_MET_RefEle_LCW_NI_eflow4_ety_EndcapRegion;   //!
   TBranch        *b_MET_RefEle_LCW_NI_eflow4_sumet_EndcapRegion;   //!
   TBranch        *b_MET_RefEle_LCW_NI_eflow4_phi_EndcapRegion;   //!
   TBranch        *b_MET_RefEle_LCW_NI_eflow4_etx_ForwardReg;   //!
   TBranch        *b_MET_RefEle_LCW_NI_eflow4_ety_ForwardReg;   //!
   TBranch        *b_MET_RefEle_LCW_NI_eflow4_sumet_ForwardReg;   //!
   TBranch        *b_MET_RefEle_LCW_NI_eflow4_phi_ForwardReg;   //!
   TBranch        *b_MET_RefTau_LCW_NI_eflow4_etx;   //!
   TBranch        *b_MET_RefTau_LCW_NI_eflow4_ety;   //!
   TBranch        *b_MET_RefTau_LCW_NI_eflow4_phi;   //!
   TBranch        *b_MET_RefTau_LCW_NI_eflow4_et;   //!
   TBranch        *b_MET_RefTau_LCW_NI_eflow4_sumet;   //!
   TBranch        *b_MET_RefTau_LCW_NI_eflow4_etx_CentralReg;   //!
   TBranch        *b_MET_RefTau_LCW_NI_eflow4_ety_CentralReg;   //!
   TBranch        *b_MET_RefTau_LCW_NI_eflow4_sumet_CentralReg;   //!
   TBranch        *b_MET_RefTau_LCW_NI_eflow4_phi_CentralReg;   //!
   TBranch        *b_MET_RefTau_LCW_NI_eflow4_etx_EndcapRegion;   //!
   TBranch        *b_MET_RefTau_LCW_NI_eflow4_ety_EndcapRegion;   //!
   TBranch        *b_MET_RefTau_LCW_NI_eflow4_sumet_EndcapRegion;   //!
   TBranch        *b_MET_RefTau_LCW_NI_eflow4_phi_EndcapRegion;   //!
   TBranch        *b_MET_RefTau_LCW_NI_eflow4_etx_ForwardReg;   //!
   TBranch        *b_MET_RefTau_LCW_NI_eflow4_ety_ForwardReg;   //!
   TBranch        *b_MET_RefTau_LCW_NI_eflow4_sumet_ForwardReg;   //!
   TBranch        *b_MET_RefTau_LCW_NI_eflow4_phi_ForwardReg;   //!
   TBranch        *b_MET_RefJet_LCW_NI_eflow4_etx;   //!
   TBranch        *b_MET_RefJet_LCW_NI_eflow4_ety;   //!
   TBranch        *b_MET_RefJet_LCW_NI_eflow4_phi;   //!
   TBranch        *b_MET_RefJet_LCW_NI_eflow4_et;   //!
   TBranch        *b_MET_RefJet_LCW_NI_eflow4_sumet;   //!
   TBranch        *b_MET_RefJet_LCW_NI_eflow4_etx_CentralReg;   //!
   TBranch        *b_MET_RefJet_LCW_NI_eflow4_ety_CentralReg;   //!
   TBranch        *b_MET_RefJet_LCW_NI_eflow4_sumet_CentralReg;   //!
   TBranch        *b_MET_RefJet_LCW_NI_eflow4_phi_CentralReg;   //!
   TBranch        *b_MET_RefJet_LCW_NI_eflow4_etx_EndcapRegion;   //!
   TBranch        *b_MET_RefJet_LCW_NI_eflow4_ety_EndcapRegion;   //!
   TBranch        *b_MET_RefJet_LCW_NI_eflow4_sumet_EndcapRegion;   //!
   TBranch        *b_MET_RefJet_LCW_NI_eflow4_phi_EndcapRegion;   //!
   TBranch        *b_MET_RefJet_LCW_NI_eflow4_etx_ForwardReg;   //!
   TBranch        *b_MET_RefJet_LCW_NI_eflow4_ety_ForwardReg;   //!
   TBranch        *b_MET_RefJet_LCW_NI_eflow4_sumet_ForwardReg;   //!
   TBranch        *b_MET_RefJet_LCW_NI_eflow4_phi_ForwardReg;   //!
   TBranch        *b_MET_CellOut_LCW_NI_eflow4_etx;   //!
   TBranch        *b_MET_CellOut_LCW_NI_eflow4_ety;   //!
   TBranch        *b_MET_CellOut_LCW_NI_eflow4_phi;   //!
   TBranch        *b_MET_CellOut_LCW_NI_eflow4_et;   //!
   TBranch        *b_MET_CellOut_LCW_NI_eflow4_sumet;   //!
   TBranch        *b_MET_CellOut_LCW_NI_eflow4_etx_CentralReg;   //!
   TBranch        *b_MET_CellOut_LCW_NI_eflow4_ety_CentralReg;   //!
   TBranch        *b_MET_CellOut_LCW_NI_eflow4_sumet_CentralReg;   //!
   TBranch        *b_MET_CellOut_LCW_NI_eflow4_phi_CentralReg;   //!
   TBranch        *b_MET_CellOut_LCW_NI_eflow4_etx_EndcapRegion;   //!
   TBranch        *b_MET_CellOut_LCW_NI_eflow4_ety_EndcapRegion;   //!
   TBranch        *b_MET_CellOut_LCW_NI_eflow4_sumet_EndcapRegion;   //!
   TBranch        *b_MET_CellOut_LCW_NI_eflow4_phi_EndcapRegion;   //!
   TBranch        *b_MET_CellOut_LCW_NI_eflow4_etx_ForwardReg;   //!
   TBranch        *b_MET_CellOut_LCW_NI_eflow4_ety_ForwardReg;   //!
   TBranch        *b_MET_CellOut_LCW_NI_eflow4_sumet_ForwardReg;   //!
   TBranch        *b_MET_CellOut_LCW_NI_eflow4_phi_ForwardReg;   //!
   TBranch        *b_MET_Cryo_LCW_NI_eflow4_etx;   //!
   TBranch        *b_MET_Cryo_LCW_NI_eflow4_ety;   //!
   TBranch        *b_MET_Cryo_LCW_NI_eflow4_phi;   //!
   TBranch        *b_MET_Cryo_LCW_NI_eflow4_et;   //!
   TBranch        *b_MET_Cryo_LCW_NI_eflow4_sumet;   //!
   TBranch        *b_MET_Cryo_LCW_NI_eflow4_etx_CentralReg;   //!
   TBranch        *b_MET_Cryo_LCW_NI_eflow4_ety_CentralReg;   //!
   TBranch        *b_MET_Cryo_LCW_NI_eflow4_sumet_CentralReg;   //!
   TBranch        *b_MET_Cryo_LCW_NI_eflow4_phi_CentralReg;   //!
   TBranch        *b_MET_Cryo_LCW_NI_eflow4_etx_EndcapRegion;   //!
   TBranch        *b_MET_Cryo_LCW_NI_eflow4_ety_EndcapRegion;   //!
   TBranch        *b_MET_Cryo_LCW_NI_eflow4_sumet_EndcapRegion;   //!
   TBranch        *b_MET_Cryo_LCW_NI_eflow4_phi_EndcapRegion;   //!
   TBranch        *b_MET_Cryo_LCW_NI_eflow4_etx_ForwardReg;   //!
   TBranch        *b_MET_Cryo_LCW_NI_eflow4_ety_ForwardReg;   //!
   TBranch        *b_MET_Cryo_LCW_NI_eflow4_sumet_ForwardReg;   //!
   TBranch        *b_MET_Cryo_LCW_NI_eflow4_phi_ForwardReg;   //!
   TBranch        *b_MET_RefMuon_LCW_NI_eflow4_etx;   //!
   TBranch        *b_MET_RefMuon_LCW_NI_eflow4_ety;   //!
   TBranch        *b_MET_RefMuon_LCW_NI_eflow4_phi;   //!
   TBranch        *b_MET_RefMuon_LCW_NI_eflow4_et;   //!
   TBranch        *b_MET_RefMuon_LCW_NI_eflow4_sumet;   //!
   TBranch        *b_MET_RefMuon_Staco_LCW_NI_eflow4_etx;   //!
   TBranch        *b_MET_RefMuon_Staco_LCW_NI_eflow4_ety;   //!
   TBranch        *b_MET_RefMuon_Staco_LCW_NI_eflow4_phi;   //!
   TBranch        *b_MET_RefMuon_Staco_LCW_NI_eflow4_et;   //!
   TBranch        *b_MET_RefMuon_Staco_LCW_NI_eflow4_sumet;   //!
   TBranch        *b_MET_Muon_Isol_Staco_LCW_NI_eflow4_etx;   //!
   TBranch        *b_MET_Muon_Isol_Staco_LCW_NI_eflow4_ety;   //!
   TBranch        *b_MET_Muon_Isol_Staco_LCW_NI_eflow4_phi;   //!
   TBranch        *b_MET_Muon_Isol_Staco_LCW_NI_eflow4_et;   //!
   TBranch        *b_MET_Muon_Isol_Staco_LCW_NI_eflow4_sumet;   //!
   TBranch        *b_MET_Muon_NonIsol_Staco_LCW_NI_eflow4_etx;   //!
   TBranch        *b_MET_Muon_NonIsol_Staco_LCW_NI_eflow4_ety;   //!
   TBranch        *b_MET_Muon_NonIsol_Staco_LCW_NI_eflow4_phi;   //!
   TBranch        *b_MET_Muon_NonIsol_Staco_LCW_NI_eflow4_et;   //!
   TBranch        *b_MET_Muon_NonIsol_Staco_LCW_NI_eflow4_sumet;   //!
   TBranch        *b_MET_Muon_Total_Staco_LCW_NI_eflow4_etx;   //!
   TBranch        *b_MET_Muon_Total_Staco_LCW_NI_eflow4_ety;   //!
   TBranch        *b_MET_Muon_Total_Staco_LCW_NI_eflow4_phi;   //!
   TBranch        *b_MET_Muon_Total_Staco_LCW_NI_eflow4_et;   //!
   TBranch        *b_MET_Muon_Total_Staco_LCW_NI_eflow4_sumet;   //!
   TBranch        *b_MET_RefMuon_Track_LCW_NI_eflow4_etx;   //!
   TBranch        *b_MET_RefMuon_Track_LCW_NI_eflow4_ety;   //!
   TBranch        *b_MET_RefMuon_Track_LCW_NI_eflow4_phi;   //!
   TBranch        *b_MET_RefMuon_Track_LCW_NI_eflow4_et;   //!
   TBranch        *b_MET_RefMuon_Track_LCW_NI_eflow4_sumet;   //!
   TBranch        *b_MET_RefMuon_Track_Staco_LCW_NI_eflow4_etx;   //!
   TBranch        *b_MET_RefMuon_Track_Staco_LCW_NI_eflow4_ety;   //!
   TBranch        *b_MET_RefMuon_Track_Staco_LCW_NI_eflow4_phi;   //!
   TBranch        *b_MET_RefMuon_Track_Staco_LCW_NI_eflow4_et;   //!
   TBranch        *b_MET_RefMuon_Track_Staco_LCW_NI_eflow4_sumet;   //!
   TBranch        *b_MET_RefFinal_LCW_NI_eflow_400_etx;   //!
   TBranch        *b_MET_RefFinal_LCW_NI_eflow_400_ety;   //!
   TBranch        *b_MET_RefFinal_LCW_NI_eflow_400_phi;   //!
   TBranch        *b_MET_RefFinal_LCW_NI_eflow_400_et;   //!
   TBranch        *b_MET_RefFinal_LCW_NI_eflow_400_sumet;   //!
   TBranch        *b_MET_RefFinal_LCW_NI_eflow_400_etx_CentralReg;   //!
   TBranch        *b_MET_RefFinal_LCW_NI_eflow_400_ety_CentralReg;   //!
   TBranch        *b_MET_RefFinal_LCW_NI_eflow_400_sumet_CentralReg;   //!
   TBranch        *b_MET_RefFinal_LCW_NI_eflow_400_phi_CentralReg;   //!
   TBranch        *b_MET_RefFinal_LCW_NI_eflow_400_etx_EndcapRegion;   //!
   TBranch        *b_MET_RefFinal_LCW_NI_eflow_400_ety_EndcapRegion;   //!
   TBranch        *b_MET_RefFinal_LCW_NI_eflow_400_sumet_EndcapRegion;   //!
   TBranch        *b_MET_RefFinal_LCW_NI_eflow_400_phi_EndcapRegion;   //!
   TBranch        *b_MET_RefFinal_LCW_NI_eflow_400_etx_ForwardReg;   //!
   TBranch        *b_MET_RefFinal_LCW_NI_eflow_400_ety_ForwardReg;   //!
   TBranch        *b_MET_RefFinal_LCW_NI_eflow_400_sumet_ForwardReg;   //!
   TBranch        *b_MET_RefFinal_LCW_NI_eflow_400_phi_ForwardReg;   //!
   TBranch        *b_MET_RefGamma_LCW_NI_eflow_400_etx;   //!
   TBranch        *b_MET_RefGamma_LCW_NI_eflow_400_ety;   //!
   TBranch        *b_MET_RefGamma_LCW_NI_eflow_400_phi;   //!
   TBranch        *b_MET_RefGamma_LCW_NI_eflow_400_et;   //!
   TBranch        *b_MET_RefGamma_LCW_NI_eflow_400_sumet;   //!
   TBranch        *b_MET_RefGamma_LCW_NI_eflow_400_etx_CentralReg;   //!
   TBranch        *b_MET_RefGamma_LCW_NI_eflow_400_ety_CentralReg;   //!
   TBranch        *b_MET_RefGamma_LCW_NI_eflow_400_sumet_CentralReg;   //!
   TBranch        *b_MET_RefGamma_LCW_NI_eflow_400_phi_CentralReg;   //!
   TBranch        *b_MET_RefGamma_LCW_NI_eflow_400_etx_EndcapRegion;   //!
   TBranch        *b_MET_RefGamma_LCW_NI_eflow_400_ety_EndcapRegion;   //!
   TBranch        *b_MET_RefGamma_LCW_NI_eflow_400_sumet_EndcapRegion;   //!
   TBranch        *b_MET_RefGamma_LCW_NI_eflow_400_phi_EndcapRegion;   //!
   TBranch        *b_MET_RefGamma_LCW_NI_eflow_400_etx_ForwardReg;   //!
   TBranch        *b_MET_RefGamma_LCW_NI_eflow_400_ety_ForwardReg;   //!
   TBranch        *b_MET_RefGamma_LCW_NI_eflow_400_sumet_ForwardReg;   //!
   TBranch        *b_MET_RefGamma_LCW_NI_eflow_400_phi_ForwardReg;   //!
   TBranch        *b_MET_RefEle_LCW_NI_eflow_400_etx;   //!
   TBranch        *b_MET_RefEle_LCW_NI_eflow_400_ety;   //!
   TBranch        *b_MET_RefEle_LCW_NI_eflow_400_phi;   //!
   TBranch        *b_MET_RefEle_LCW_NI_eflow_400_et;   //!
   TBranch        *b_MET_RefEle_LCW_NI_eflow_400_sumet;   //!
   TBranch        *b_MET_RefEle_LCW_NI_eflow_400_etx_CentralReg;   //!
   TBranch        *b_MET_RefEle_LCW_NI_eflow_400_ety_CentralReg;   //!
   TBranch        *b_MET_RefEle_LCW_NI_eflow_400_sumet_CentralReg;   //!
   TBranch        *b_MET_RefEle_LCW_NI_eflow_400_phi_CentralReg;   //!
   TBranch        *b_MET_RefEle_LCW_NI_eflow_400_etx_EndcapRegion;   //!
   TBranch        *b_MET_RefEle_LCW_NI_eflow_400_ety_EndcapRegion;   //!
   TBranch        *b_MET_RefEle_LCW_NI_eflow_400_sumet_EndcapRegion;   //!
   TBranch        *b_MET_RefEle_LCW_NI_eflow_400_phi_EndcapRegion;   //!
   TBranch        *b_MET_RefEle_LCW_NI_eflow_400_etx_ForwardReg;   //!
   TBranch        *b_MET_RefEle_LCW_NI_eflow_400_ety_ForwardReg;   //!
   TBranch        *b_MET_RefEle_LCW_NI_eflow_400_sumet_ForwardReg;   //!
   TBranch        *b_MET_RefEle_LCW_NI_eflow_400_phi_ForwardReg;   //!
   TBranch        *b_MET_RefTau_LCW_NI_eflow_400_etx;   //!
   TBranch        *b_MET_RefTau_LCW_NI_eflow_400_ety;   //!
   TBranch        *b_MET_RefTau_LCW_NI_eflow_400_phi;   //!
   TBranch        *b_MET_RefTau_LCW_NI_eflow_400_et;   //!
   TBranch        *b_MET_RefTau_LCW_NI_eflow_400_sumet;   //!
   TBranch        *b_MET_RefTau_LCW_NI_eflow_400_etx_CentralReg;   //!
   TBranch        *b_MET_RefTau_LCW_NI_eflow_400_ety_CentralReg;   //!
   TBranch        *b_MET_RefTau_LCW_NI_eflow_400_sumet_CentralReg;   //!
   TBranch        *b_MET_RefTau_LCW_NI_eflow_400_phi_CentralReg;   //!
   TBranch        *b_MET_RefTau_LCW_NI_eflow_400_etx_EndcapRegion;   //!
   TBranch        *b_MET_RefTau_LCW_NI_eflow_400_ety_EndcapRegion;   //!
   TBranch        *b_MET_RefTau_LCW_NI_eflow_400_sumet_EndcapRegion;   //!
   TBranch        *b_MET_RefTau_LCW_NI_eflow_400_phi_EndcapRegion;   //!
   TBranch        *b_MET_RefTau_LCW_NI_eflow_400_etx_ForwardReg;   //!
   TBranch        *b_MET_RefTau_LCW_NI_eflow_400_ety_ForwardReg;   //!
   TBranch        *b_MET_RefTau_LCW_NI_eflow_400_sumet_ForwardReg;   //!
   TBranch        *b_MET_RefTau_LCW_NI_eflow_400_phi_ForwardReg;   //!
   TBranch        *b_MET_RefJet_LCW_NI_eflow_400_etx;   //!
   TBranch        *b_MET_RefJet_LCW_NI_eflow_400_ety;   //!
   TBranch        *b_MET_RefJet_LCW_NI_eflow_400_phi;   //!
   TBranch        *b_MET_RefJet_LCW_NI_eflow_400_et;   //!
   TBranch        *b_MET_RefJet_LCW_NI_eflow_400_sumet;   //!
   TBranch        *b_MET_RefJet_LCW_NI_eflow_400_etx_CentralReg;   //!
   TBranch        *b_MET_RefJet_LCW_NI_eflow_400_ety_CentralReg;   //!
   TBranch        *b_MET_RefJet_LCW_NI_eflow_400_sumet_CentralReg;   //!
   TBranch        *b_MET_RefJet_LCW_NI_eflow_400_phi_CentralReg;   //!
   TBranch        *b_MET_RefJet_LCW_NI_eflow_400_etx_EndcapRegion;   //!
   TBranch        *b_MET_RefJet_LCW_NI_eflow_400_ety_EndcapRegion;   //!
   TBranch        *b_MET_RefJet_LCW_NI_eflow_400_sumet_EndcapRegion;   //!
   TBranch        *b_MET_RefJet_LCW_NI_eflow_400_phi_EndcapRegion;   //!
   TBranch        *b_MET_RefJet_LCW_NI_eflow_400_etx_ForwardReg;   //!
   TBranch        *b_MET_RefJet_LCW_NI_eflow_400_ety_ForwardReg;   //!
   TBranch        *b_MET_RefJet_LCW_NI_eflow_400_sumet_ForwardReg;   //!
   TBranch        *b_MET_RefJet_LCW_NI_eflow_400_phi_ForwardReg;   //!
   TBranch        *b_MET_CellOut_LCW_NI_eflow_400_etx;   //!
   TBranch        *b_MET_CellOut_LCW_NI_eflow_400_ety;   //!
   TBranch        *b_MET_CellOut_LCW_NI_eflow_400_phi;   //!
   TBranch        *b_MET_CellOut_LCW_NI_eflow_400_et;   //!
   TBranch        *b_MET_CellOut_LCW_NI_eflow_400_sumet;   //!
   TBranch        *b_MET_CellOut_LCW_NI_eflow_400_etx_CentralReg;   //!
   TBranch        *b_MET_CellOut_LCW_NI_eflow_400_ety_CentralReg;   //!
   TBranch        *b_MET_CellOut_LCW_NI_eflow_400_sumet_CentralReg;   //!
   TBranch        *b_MET_CellOut_LCW_NI_eflow_400_phi_CentralReg;   //!
   TBranch        *b_MET_CellOut_LCW_NI_eflow_400_etx_EndcapRegion;   //!
   TBranch        *b_MET_CellOut_LCW_NI_eflow_400_ety_EndcapRegion;   //!
   TBranch        *b_MET_CellOut_LCW_NI_eflow_400_sumet_EndcapRegion;   //!
   TBranch        *b_MET_CellOut_LCW_NI_eflow_400_phi_EndcapRegion;   //!
   TBranch        *b_MET_CellOut_LCW_NI_eflow_400_etx_ForwardReg;   //!
   TBranch        *b_MET_CellOut_LCW_NI_eflow_400_ety_ForwardReg;   //!
   TBranch        *b_MET_CellOut_LCW_NI_eflow_400_sumet_ForwardReg;   //!
   TBranch        *b_MET_CellOut_LCW_NI_eflow_400_phi_ForwardReg;   //!
   TBranch        *b_MET_Cryo_LCW_NI_eflow_400_etx;   //!
   TBranch        *b_MET_Cryo_LCW_NI_eflow_400_ety;   //!
   TBranch        *b_MET_Cryo_LCW_NI_eflow_400_phi;   //!
   TBranch        *b_MET_Cryo_LCW_NI_eflow_400_et;   //!
   TBranch        *b_MET_Cryo_LCW_NI_eflow_400_sumet;   //!
   TBranch        *b_MET_Cryo_LCW_NI_eflow_400_etx_CentralReg;   //!
   TBranch        *b_MET_Cryo_LCW_NI_eflow_400_ety_CentralReg;   //!
   TBranch        *b_MET_Cryo_LCW_NI_eflow_400_sumet_CentralReg;   //!
   TBranch        *b_MET_Cryo_LCW_NI_eflow_400_phi_CentralReg;   //!
   TBranch        *b_MET_Cryo_LCW_NI_eflow_400_etx_EndcapRegion;   //!
   TBranch        *b_MET_Cryo_LCW_NI_eflow_400_ety_EndcapRegion;   //!
   TBranch        *b_MET_Cryo_LCW_NI_eflow_400_sumet_EndcapRegion;   //!
   TBranch        *b_MET_Cryo_LCW_NI_eflow_400_phi_EndcapRegion;   //!
   TBranch        *b_MET_Cryo_LCW_NI_eflow_400_etx_ForwardReg;   //!
   TBranch        *b_MET_Cryo_LCW_NI_eflow_400_ety_ForwardReg;   //!
   TBranch        *b_MET_Cryo_LCW_NI_eflow_400_sumet_ForwardReg;   //!
   TBranch        *b_MET_Cryo_LCW_NI_eflow_400_phi_ForwardReg;   //!
   TBranch        *b_MET_RefMuon_LCW_NI_eflow_400_etx;   //!
   TBranch        *b_MET_RefMuon_LCW_NI_eflow_400_ety;   //!
   TBranch        *b_MET_RefMuon_LCW_NI_eflow_400_phi;   //!
   TBranch        *b_MET_RefMuon_LCW_NI_eflow_400_et;   //!
   TBranch        *b_MET_RefMuon_LCW_NI_eflow_400_sumet;   //!
   TBranch        *b_MET_RefMuon_Staco_LCW_NI_eflow_400_etx;   //!
   TBranch        *b_MET_RefMuon_Staco_LCW_NI_eflow_400_ety;   //!
   TBranch        *b_MET_RefMuon_Staco_LCW_NI_eflow_400_phi;   //!
   TBranch        *b_MET_RefMuon_Staco_LCW_NI_eflow_400_et;   //!
   TBranch        *b_MET_RefMuon_Staco_LCW_NI_eflow_400_sumet;   //!
   TBranch        *b_MET_Muon_Isol_Staco_LCW_NI_eflow_400_etx;   //!
   TBranch        *b_MET_Muon_Isol_Staco_LCW_NI_eflow_400_ety;   //!
   TBranch        *b_MET_Muon_Isol_Staco_LCW_NI_eflow_400_phi;   //!
   TBranch        *b_MET_Muon_Isol_Staco_LCW_NI_eflow_400_et;   //!
   TBranch        *b_MET_Muon_Isol_Staco_LCW_NI_eflow_400_sumet;   //!
   TBranch        *b_MET_Muon_NonIsol_Staco_LCW_NI_eflow_400_etx;   //!
   TBranch        *b_MET_Muon_NonIsol_Staco_LCW_NI_eflow_400_ety;   //!
   TBranch        *b_MET_Muon_NonIsol_Staco_LCW_NI_eflow_400_phi;   //!
   TBranch        *b_MET_Muon_NonIsol_Staco_LCW_NI_eflow_400_et;   //!
   TBranch        *b_MET_Muon_NonIsol_Staco_LCW_NI_eflow_400_sumet;   //!
   TBranch        *b_MET_Muon_Total_Staco_LCW_NI_eflow_400_etx;   //!
   TBranch        *b_MET_Muon_Total_Staco_LCW_NI_eflow_400_ety;   //!
   TBranch        *b_MET_Muon_Total_Staco_LCW_NI_eflow_400_phi;   //!
   TBranch        *b_MET_Muon_Total_Staco_LCW_NI_eflow_400_et;   //!
   TBranch        *b_MET_Muon_Total_Staco_LCW_NI_eflow_400_sumet;   //!
   TBranch        *b_MET_RefMuon_Track_LCW_NI_eflow_400_etx;   //!
   TBranch        *b_MET_RefMuon_Track_LCW_NI_eflow_400_ety;   //!
   TBranch        *b_MET_RefMuon_Track_LCW_NI_eflow_400_phi;   //!
   TBranch        *b_MET_RefMuon_Track_LCW_NI_eflow_400_et;   //!
   TBranch        *b_MET_RefMuon_Track_LCW_NI_eflow_400_sumet;   //!
   TBranch        *b_MET_RefMuon_Track_Staco_LCW_NI_eflow_400_etx;   //!
   TBranch        *b_MET_RefMuon_Track_Staco_LCW_NI_eflow_400_ety;   //!
   TBranch        *b_MET_RefMuon_Track_Staco_LCW_NI_eflow_400_phi;   //!
   TBranch        *b_MET_RefMuon_Track_Staco_LCW_NI_eflow_400_et;   //!
   TBranch        *b_MET_RefMuon_Track_Staco_LCW_NI_eflow_400_sumet;   //!
   TBranch        *b_MET_RefFinal_LCW_pt20_etx;   //!
   TBranch        *b_MET_RefFinal_LCW_pt20_ety;   //!
   TBranch        *b_MET_RefFinal_LCW_pt20_phi;   //!
   TBranch        *b_MET_RefFinal_LCW_pt20_et;   //!
   TBranch        *b_MET_RefFinal_LCW_pt20_sumet;   //!
   TBranch        *b_MET_RefFinal_LCW_pt20_etx_CentralReg;   //!
   TBranch        *b_MET_RefFinal_LCW_pt20_ety_CentralReg;   //!
   TBranch        *b_MET_RefFinal_LCW_pt20_sumet_CentralReg;   //!
   TBranch        *b_MET_RefFinal_LCW_pt20_phi_CentralReg;   //!
   TBranch        *b_MET_RefFinal_LCW_pt20_etx_EndcapRegion;   //!
   TBranch        *b_MET_RefFinal_LCW_pt20_ety_EndcapRegion;   //!
   TBranch        *b_MET_RefFinal_LCW_pt20_sumet_EndcapRegion;   //!
   TBranch        *b_MET_RefFinal_LCW_pt20_phi_EndcapRegion;   //!
   TBranch        *b_MET_RefFinal_LCW_pt20_etx_ForwardReg;   //!
   TBranch        *b_MET_RefFinal_LCW_pt20_ety_ForwardReg;   //!
   TBranch        *b_MET_RefFinal_LCW_pt20_sumet_ForwardReg;   //!
   TBranch        *b_MET_RefFinal_LCW_pt20_phi_ForwardReg;   //!
   TBranch        *b_MET_RefGamma_LCW_pt20_etx;   //!
   TBranch        *b_MET_RefGamma_LCW_pt20_ety;   //!
   TBranch        *b_MET_RefGamma_LCW_pt20_phi;   //!
   TBranch        *b_MET_RefGamma_LCW_pt20_et;   //!
   TBranch        *b_MET_RefGamma_LCW_pt20_sumet;   //!
   TBranch        *b_MET_RefGamma_LCW_pt20_etx_CentralReg;   //!
   TBranch        *b_MET_RefGamma_LCW_pt20_ety_CentralReg;   //!
   TBranch        *b_MET_RefGamma_LCW_pt20_sumet_CentralReg;   //!
   TBranch        *b_MET_RefGamma_LCW_pt20_phi_CentralReg;   //!
   TBranch        *b_MET_RefGamma_LCW_pt20_etx_EndcapRegion;   //!
   TBranch        *b_MET_RefGamma_LCW_pt20_ety_EndcapRegion;   //!
   TBranch        *b_MET_RefGamma_LCW_pt20_sumet_EndcapRegion;   //!
   TBranch        *b_MET_RefGamma_LCW_pt20_phi_EndcapRegion;   //!
   TBranch        *b_MET_RefGamma_LCW_pt20_etx_ForwardReg;   //!
   TBranch        *b_MET_RefGamma_LCW_pt20_ety_ForwardReg;   //!
   TBranch        *b_MET_RefGamma_LCW_pt20_sumet_ForwardReg;   //!
   TBranch        *b_MET_RefGamma_LCW_pt20_phi_ForwardReg;   //!
   TBranch        *b_MET_RefEle_LCW_pt20_etx;   //!
   TBranch        *b_MET_RefEle_LCW_pt20_ety;   //!
   TBranch        *b_MET_RefEle_LCW_pt20_phi;   //!
   TBranch        *b_MET_RefEle_LCW_pt20_et;   //!
   TBranch        *b_MET_RefEle_LCW_pt20_sumet;   //!
   TBranch        *b_MET_RefEle_LCW_pt20_etx_CentralReg;   //!
   TBranch        *b_MET_RefEle_LCW_pt20_ety_CentralReg;   //!
   TBranch        *b_MET_RefEle_LCW_pt20_sumet_CentralReg;   //!
   TBranch        *b_MET_RefEle_LCW_pt20_phi_CentralReg;   //!
   TBranch        *b_MET_RefEle_LCW_pt20_etx_EndcapRegion;   //!
   TBranch        *b_MET_RefEle_LCW_pt20_ety_EndcapRegion;   //!
   TBranch        *b_MET_RefEle_LCW_pt20_sumet_EndcapRegion;   //!
   TBranch        *b_MET_RefEle_LCW_pt20_phi_EndcapRegion;   //!
   TBranch        *b_MET_RefEle_LCW_pt20_etx_ForwardReg;   //!
   TBranch        *b_MET_RefEle_LCW_pt20_ety_ForwardReg;   //!
   TBranch        *b_MET_RefEle_LCW_pt20_sumet_ForwardReg;   //!
   TBranch        *b_MET_RefEle_LCW_pt20_phi_ForwardReg;   //!
   TBranch        *b_MET_RefTau_LCW_pt20_etx;   //!
   TBranch        *b_MET_RefTau_LCW_pt20_ety;   //!
   TBranch        *b_MET_RefTau_LCW_pt20_phi;   //!
   TBranch        *b_MET_RefTau_LCW_pt20_et;   //!
   TBranch        *b_MET_RefTau_LCW_pt20_sumet;   //!
   TBranch        *b_MET_RefTau_LCW_pt20_etx_CentralReg;   //!
   TBranch        *b_MET_RefTau_LCW_pt20_ety_CentralReg;   //!
   TBranch        *b_MET_RefTau_LCW_pt20_sumet_CentralReg;   //!
   TBranch        *b_MET_RefTau_LCW_pt20_phi_CentralReg;   //!
   TBranch        *b_MET_RefTau_LCW_pt20_etx_EndcapRegion;   //!
   TBranch        *b_MET_RefTau_LCW_pt20_ety_EndcapRegion;   //!
   TBranch        *b_MET_RefTau_LCW_pt20_sumet_EndcapRegion;   //!
   TBranch        *b_MET_RefTau_LCW_pt20_phi_EndcapRegion;   //!
   TBranch        *b_MET_RefTau_LCW_pt20_etx_ForwardReg;   //!
   TBranch        *b_MET_RefTau_LCW_pt20_ety_ForwardReg;   //!
   TBranch        *b_MET_RefTau_LCW_pt20_sumet_ForwardReg;   //!
   TBranch        *b_MET_RefTau_LCW_pt20_phi_ForwardReg;   //!
   TBranch        *b_MET_RefJet_LCW_pt20_etx;   //!
   TBranch        *b_MET_RefJet_LCW_pt20_ety;   //!
   TBranch        *b_MET_RefJet_LCW_pt20_phi;   //!
   TBranch        *b_MET_RefJet_LCW_pt20_et;   //!
   TBranch        *b_MET_RefJet_LCW_pt20_sumet;   //!
   TBranch        *b_MET_RefJet_LCW_pt20_etx_CentralReg;   //!
   TBranch        *b_MET_RefJet_LCW_pt20_ety_CentralReg;   //!
   TBranch        *b_MET_RefJet_LCW_pt20_sumet_CentralReg;   //!
   TBranch        *b_MET_RefJet_LCW_pt20_phi_CentralReg;   //!
   TBranch        *b_MET_RefJet_LCW_pt20_etx_EndcapRegion;   //!
   TBranch        *b_MET_RefJet_LCW_pt20_ety_EndcapRegion;   //!
   TBranch        *b_MET_RefJet_LCW_pt20_sumet_EndcapRegion;   //!
   TBranch        *b_MET_RefJet_LCW_pt20_phi_EndcapRegion;   //!
   TBranch        *b_MET_RefJet_LCW_pt20_etx_ForwardReg;   //!
   TBranch        *b_MET_RefJet_LCW_pt20_ety_ForwardReg;   //!
   TBranch        *b_MET_RefJet_LCW_pt20_sumet_ForwardReg;   //!
   TBranch        *b_MET_RefJet_LCW_pt20_phi_ForwardReg;   //!
   TBranch        *b_MET_CellOut_LCW_pt20_etx;   //!
   TBranch        *b_MET_CellOut_LCW_pt20_ety;   //!
   TBranch        *b_MET_CellOut_LCW_pt20_phi;   //!
   TBranch        *b_MET_CellOut_LCW_pt20_et;   //!
   TBranch        *b_MET_CellOut_LCW_pt20_sumet;   //!
   TBranch        *b_MET_CellOut_LCW_pt20_etx_CentralReg;   //!
   TBranch        *b_MET_CellOut_LCW_pt20_ety_CentralReg;   //!
   TBranch        *b_MET_CellOut_LCW_pt20_sumet_CentralReg;   //!
   TBranch        *b_MET_CellOut_LCW_pt20_phi_CentralReg;   //!
   TBranch        *b_MET_CellOut_LCW_pt20_etx_EndcapRegion;   //!
   TBranch        *b_MET_CellOut_LCW_pt20_ety_EndcapRegion;   //!
   TBranch        *b_MET_CellOut_LCW_pt20_sumet_EndcapRegion;   //!
   TBranch        *b_MET_CellOut_LCW_pt20_phi_EndcapRegion;   //!
   TBranch        *b_MET_CellOut_LCW_pt20_etx_ForwardReg;   //!
   TBranch        *b_MET_CellOut_LCW_pt20_ety_ForwardReg;   //!
   TBranch        *b_MET_CellOut_LCW_pt20_sumet_ForwardReg;   //!
   TBranch        *b_MET_CellOut_LCW_pt20_phi_ForwardReg;   //!
   TBranch        *b_MET_Cryo_LCW_pt20_etx;   //!
   TBranch        *b_MET_Cryo_LCW_pt20_ety;   //!
   TBranch        *b_MET_Cryo_LCW_pt20_phi;   //!
   TBranch        *b_MET_Cryo_LCW_pt20_et;   //!
   TBranch        *b_MET_Cryo_LCW_pt20_sumet;   //!
   TBranch        *b_MET_Cryo_LCW_pt20_etx_CentralReg;   //!
   TBranch        *b_MET_Cryo_LCW_pt20_ety_CentralReg;   //!
   TBranch        *b_MET_Cryo_LCW_pt20_sumet_CentralReg;   //!
   TBranch        *b_MET_Cryo_LCW_pt20_phi_CentralReg;   //!
   TBranch        *b_MET_Cryo_LCW_pt20_etx_EndcapRegion;   //!
   TBranch        *b_MET_Cryo_LCW_pt20_ety_EndcapRegion;   //!
   TBranch        *b_MET_Cryo_LCW_pt20_sumet_EndcapRegion;   //!
   TBranch        *b_MET_Cryo_LCW_pt20_phi_EndcapRegion;   //!
   TBranch        *b_MET_Cryo_LCW_pt20_etx_ForwardReg;   //!
   TBranch        *b_MET_Cryo_LCW_pt20_ety_ForwardReg;   //!
   TBranch        *b_MET_Cryo_LCW_pt20_sumet_ForwardReg;   //!
   TBranch        *b_MET_Cryo_LCW_pt20_phi_ForwardReg;   //!
   TBranch        *b_MET_RefMuon_LCW_pt20_etx;   //!
   TBranch        *b_MET_RefMuon_LCW_pt20_ety;   //!
   TBranch        *b_MET_RefMuon_LCW_pt20_phi;   //!
   TBranch        *b_MET_RefMuon_LCW_pt20_et;   //!
   TBranch        *b_MET_RefMuon_LCW_pt20_sumet;   //!
   TBranch        *b_MET_RefMuon_Muid_LCW_pt20_etx;   //!
   TBranch        *b_MET_RefMuon_Muid_LCW_pt20_ety;   //!
   TBranch        *b_MET_RefMuon_Muid_LCW_pt20_phi;   //!
   TBranch        *b_MET_RefMuon_Muid_LCW_pt20_et;   //!
   TBranch        *b_MET_RefMuon_Muid_LCW_pt20_sumet;   //!
   TBranch        *b_MET_Muon_Isol_Muid_LCW_pt20_etx;   //!
   TBranch        *b_MET_Muon_Isol_Muid_LCW_pt20_ety;   //!
   TBranch        *b_MET_Muon_Isol_Muid_LCW_pt20_phi;   //!
   TBranch        *b_MET_Muon_Isol_Muid_LCW_pt20_et;   //!
   TBranch        *b_MET_Muon_Isol_Muid_LCW_pt20_sumet;   //!
   TBranch        *b_MET_Muon_NonIsol_Muid_LCW_pt20_etx;   //!
   TBranch        *b_MET_Muon_NonIsol_Muid_LCW_pt20_ety;   //!
   TBranch        *b_MET_Muon_NonIsol_Muid_LCW_pt20_phi;   //!
   TBranch        *b_MET_Muon_NonIsol_Muid_LCW_pt20_et;   //!
   TBranch        *b_MET_Muon_NonIsol_Muid_LCW_pt20_sumet;   //!
   TBranch        *b_MET_Muon_Total_Muid_LCW_pt20_etx;   //!
   TBranch        *b_MET_Muon_Total_Muid_LCW_pt20_ety;   //!
   TBranch        *b_MET_Muon_Total_Muid_LCW_pt20_phi;   //!
   TBranch        *b_MET_Muon_Total_Muid_LCW_pt20_et;   //!
   TBranch        *b_MET_Muon_Total_Muid_LCW_pt20_sumet;   //!
   TBranch        *b_MET_RefMuon_Track_LCW_pt20_etx;   //!
   TBranch        *b_MET_RefMuon_Track_LCW_pt20_ety;   //!
   TBranch        *b_MET_RefMuon_Track_LCW_pt20_phi;   //!
   TBranch        *b_MET_RefMuon_Track_LCW_pt20_et;   //!
   TBranch        *b_MET_RefMuon_Track_LCW_pt20_sumet;   //!
   TBranch        *b_MET_RefMuon_Track_Muid_LCW_pt20_etx;   //!
   TBranch        *b_MET_RefMuon_Track_Muid_LCW_pt20_ety;   //!
   TBranch        *b_MET_RefMuon_Track_Muid_LCW_pt20_phi;   //!
   TBranch        *b_MET_RefMuon_Track_Muid_LCW_pt20_et;   //!
   TBranch        *b_MET_RefMuon_Track_Muid_LCW_pt20_sumet;   //!
   TBranch        *b_MET_RefFinal_New_etx;   //!
   TBranch        *b_MET_RefFinal_New_ety;   //!
   TBranch        *b_MET_RefFinal_New_phi;   //!
   TBranch        *b_MET_RefFinal_New_et;   //!
   TBranch        *b_MET_RefFinal_New_sumet;   //!
   TBranch        *b_MET_RefFinal_New_etx_CentralReg;   //!
   TBranch        *b_MET_RefFinal_New_ety_CentralReg;   //!
   TBranch        *b_MET_RefFinal_New_sumet_CentralReg;   //!
   TBranch        *b_MET_RefFinal_New_phi_CentralReg;   //!
   TBranch        *b_MET_RefFinal_New_etx_EndcapRegion;   //!
   TBranch        *b_MET_RefFinal_New_ety_EndcapRegion;   //!
   TBranch        *b_MET_RefFinal_New_sumet_EndcapRegion;   //!
   TBranch        *b_MET_RefFinal_New_phi_EndcapRegion;   //!
   TBranch        *b_MET_RefFinal_New_etx_ForwardReg;   //!
   TBranch        *b_MET_RefFinal_New_ety_ForwardReg;   //!
   TBranch        *b_MET_RefFinal_New_sumet_ForwardReg;   //!
   TBranch        *b_MET_RefFinal_New_phi_ForwardReg;   //!
   TBranch        *b_MET_RefGamma_New_etx;   //!
   TBranch        *b_MET_RefGamma_New_ety;   //!
   TBranch        *b_MET_RefGamma_New_phi;   //!
   TBranch        *b_MET_RefGamma_New_et;   //!
   TBranch        *b_MET_RefGamma_New_sumet;   //!
   TBranch        *b_MET_RefGamma_New_etx_CentralReg;   //!
   TBranch        *b_MET_RefGamma_New_ety_CentralReg;   //!
   TBranch        *b_MET_RefGamma_New_sumet_CentralReg;   //!
   TBranch        *b_MET_RefGamma_New_phi_CentralReg;   //!
   TBranch        *b_MET_RefGamma_New_etx_EndcapRegion;   //!
   TBranch        *b_MET_RefGamma_New_ety_EndcapRegion;   //!
   TBranch        *b_MET_RefGamma_New_sumet_EndcapRegion;   //!
   TBranch        *b_MET_RefGamma_New_phi_EndcapRegion;   //!
   TBranch        *b_MET_RefGamma_New_etx_ForwardReg;   //!
   TBranch        *b_MET_RefGamma_New_ety_ForwardReg;   //!
   TBranch        *b_MET_RefGamma_New_sumet_ForwardReg;   //!
   TBranch        *b_MET_RefGamma_New_phi_ForwardReg;   //!
   TBranch        *b_MET_RefEle_New_etx;   //!
   TBranch        *b_MET_RefEle_New_ety;   //!
   TBranch        *b_MET_RefEle_New_phi;   //!
   TBranch        *b_MET_RefEle_New_et;   //!
   TBranch        *b_MET_RefEle_New_sumet;   //!
   TBranch        *b_MET_RefEle_New_etx_CentralReg;   //!
   TBranch        *b_MET_RefEle_New_ety_CentralReg;   //!
   TBranch        *b_MET_RefEle_New_sumet_CentralReg;   //!
   TBranch        *b_MET_RefEle_New_phi_CentralReg;   //!
   TBranch        *b_MET_RefEle_New_etx_EndcapRegion;   //!
   TBranch        *b_MET_RefEle_New_ety_EndcapRegion;   //!
   TBranch        *b_MET_RefEle_New_sumet_EndcapRegion;   //!
   TBranch        *b_MET_RefEle_New_phi_EndcapRegion;   //!
   TBranch        *b_MET_RefEle_New_etx_ForwardReg;   //!
   TBranch        *b_MET_RefEle_New_ety_ForwardReg;   //!
   TBranch        *b_MET_RefEle_New_sumet_ForwardReg;   //!
   TBranch        *b_MET_RefEle_New_phi_ForwardReg;   //!
   TBranch        *b_MET_RefTau_New_etx;   //!
   TBranch        *b_MET_RefTau_New_ety;   //!
   TBranch        *b_MET_RefTau_New_phi;   //!
   TBranch        *b_MET_RefTau_New_et;   //!
   TBranch        *b_MET_RefTau_New_sumet;   //!
   TBranch        *b_MET_RefTau_New_etx_CentralReg;   //!
   TBranch        *b_MET_RefTau_New_ety_CentralReg;   //!
   TBranch        *b_MET_RefTau_New_sumet_CentralReg;   //!
   TBranch        *b_MET_RefTau_New_phi_CentralReg;   //!
   TBranch        *b_MET_RefTau_New_etx_EndcapRegion;   //!
   TBranch        *b_MET_RefTau_New_ety_EndcapRegion;   //!
   TBranch        *b_MET_RefTau_New_sumet_EndcapRegion;   //!
   TBranch        *b_MET_RefTau_New_phi_EndcapRegion;   //!
   TBranch        *b_MET_RefTau_New_etx_ForwardReg;   //!
   TBranch        *b_MET_RefTau_New_ety_ForwardReg;   //!
   TBranch        *b_MET_RefTau_New_sumet_ForwardReg;   //!
   TBranch        *b_MET_RefTau_New_phi_ForwardReg;   //!
   TBranch        *b_MET_RefJet_New_etx;   //!
   TBranch        *b_MET_RefJet_New_ety;   //!
   TBranch        *b_MET_RefJet_New_phi;   //!
   TBranch        *b_MET_RefJet_New_et;   //!
   TBranch        *b_MET_RefJet_New_sumet;   //!
   TBranch        *b_MET_RefJet_New_etx_CentralReg;   //!
   TBranch        *b_MET_RefJet_New_ety_CentralReg;   //!
   TBranch        *b_MET_RefJet_New_sumet_CentralReg;   //!
   TBranch        *b_MET_RefJet_New_phi_CentralReg;   //!
   TBranch        *b_MET_RefJet_New_etx_EndcapRegion;   //!
   TBranch        *b_MET_RefJet_New_ety_EndcapRegion;   //!
   TBranch        *b_MET_RefJet_New_sumet_EndcapRegion;   //!
   TBranch        *b_MET_RefJet_New_phi_EndcapRegion;   //!
   TBranch        *b_MET_RefJet_New_etx_ForwardReg;   //!
   TBranch        *b_MET_RefJet_New_ety_ForwardReg;   //!
   TBranch        *b_MET_RefJet_New_sumet_ForwardReg;   //!
   TBranch        *b_MET_RefJet_New_phi_ForwardReg;   //!
   TBranch        *b_MET_CellOut_New_etx;   //!
   TBranch        *b_MET_CellOut_New_ety;   //!
   TBranch        *b_MET_CellOut_New_phi;   //!
   TBranch        *b_MET_CellOut_New_et;   //!
   TBranch        *b_MET_CellOut_New_sumet;   //!
   TBranch        *b_MET_CellOut_New_etx_CentralReg;   //!
   TBranch        *b_MET_CellOut_New_ety_CentralReg;   //!
   TBranch        *b_MET_CellOut_New_sumet_CentralReg;   //!
   TBranch        *b_MET_CellOut_New_phi_CentralReg;   //!
   TBranch        *b_MET_CellOut_New_etx_EndcapRegion;   //!
   TBranch        *b_MET_CellOut_New_ety_EndcapRegion;   //!
   TBranch        *b_MET_CellOut_New_sumet_EndcapRegion;   //!
   TBranch        *b_MET_CellOut_New_phi_EndcapRegion;   //!
   TBranch        *b_MET_CellOut_New_etx_ForwardReg;   //!
   TBranch        *b_MET_CellOut_New_ety_ForwardReg;   //!
   TBranch        *b_MET_CellOut_New_sumet_ForwardReg;   //!
   TBranch        *b_MET_CellOut_New_phi_ForwardReg;   //!
   TBranch        *b_MET_Cryo_New_etx;   //!
   TBranch        *b_MET_Cryo_New_ety;   //!
   TBranch        *b_MET_Cryo_New_phi;   //!
   TBranch        *b_MET_Cryo_New_et;   //!
   TBranch        *b_MET_Cryo_New_sumet;   //!
   TBranch        *b_MET_Cryo_New_etx_CentralReg;   //!
   TBranch        *b_MET_Cryo_New_ety_CentralReg;   //!
   TBranch        *b_MET_Cryo_New_sumet_CentralReg;   //!
   TBranch        *b_MET_Cryo_New_phi_CentralReg;   //!
   TBranch        *b_MET_Cryo_New_etx_EndcapRegion;   //!
   TBranch        *b_MET_Cryo_New_ety_EndcapRegion;   //!
   TBranch        *b_MET_Cryo_New_sumet_EndcapRegion;   //!
   TBranch        *b_MET_Cryo_New_phi_EndcapRegion;   //!
   TBranch        *b_MET_Cryo_New_etx_ForwardReg;   //!
   TBranch        *b_MET_Cryo_New_ety_ForwardReg;   //!
   TBranch        *b_MET_Cryo_New_sumet_ForwardReg;   //!
   TBranch        *b_MET_Cryo_New_phi_ForwardReg;   //!
   TBranch        *b_MET_RefFinal_New_em_etx;   //!
   TBranch        *b_MET_RefFinal_New_em_ety;   //!
   TBranch        *b_MET_RefFinal_New_em_phi;   //!
   TBranch        *b_MET_RefFinal_New_em_et;   //!
   TBranch        *b_MET_RefFinal_New_em_sumet;   //!
   TBranch        *b_MET_RefFinal_New_em_etx_CentralReg;   //!
   TBranch        *b_MET_RefFinal_New_em_ety_CentralReg;   //!
   TBranch        *b_MET_RefFinal_New_em_sumet_CentralReg;   //!
   TBranch        *b_MET_RefFinal_New_em_phi_CentralReg;   //!
   TBranch        *b_MET_RefFinal_New_em_etx_EndcapRegion;   //!
   TBranch        *b_MET_RefFinal_New_em_ety_EndcapRegion;   //!
   TBranch        *b_MET_RefFinal_New_em_sumet_EndcapRegion;   //!
   TBranch        *b_MET_RefFinal_New_em_phi_EndcapRegion;   //!
   TBranch        *b_MET_RefFinal_New_em_etx_ForwardReg;   //!
   TBranch        *b_MET_RefFinal_New_em_ety_ForwardReg;   //!
   TBranch        *b_MET_RefFinal_New_em_sumet_ForwardReg;   //!
   TBranch        *b_MET_RefFinal_New_em_phi_ForwardReg;   //!
   TBranch        *b_MET_RefGamma_New_em_etx;   //!
   TBranch        *b_MET_RefGamma_New_em_ety;   //!
   TBranch        *b_MET_RefGamma_New_em_phi;   //!
   TBranch        *b_MET_RefGamma_New_em_et;   //!
   TBranch        *b_MET_RefGamma_New_em_sumet;   //!
   TBranch        *b_MET_RefGamma_New_em_etx_CentralReg;   //!
   TBranch        *b_MET_RefGamma_New_em_ety_CentralReg;   //!
   TBranch        *b_MET_RefGamma_New_em_sumet_CentralReg;   //!
   TBranch        *b_MET_RefGamma_New_em_phi_CentralReg;   //!
   TBranch        *b_MET_RefGamma_New_em_etx_EndcapRegion;   //!
   TBranch        *b_MET_RefGamma_New_em_ety_EndcapRegion;   //!
   TBranch        *b_MET_RefGamma_New_em_sumet_EndcapRegion;   //!
   TBranch        *b_MET_RefGamma_New_em_phi_EndcapRegion;   //!
   TBranch        *b_MET_RefGamma_New_em_etx_ForwardReg;   //!
   TBranch        *b_MET_RefGamma_New_em_ety_ForwardReg;   //!
   TBranch        *b_MET_RefGamma_New_em_sumet_ForwardReg;   //!
   TBranch        *b_MET_RefGamma_New_em_phi_ForwardReg;   //!
   TBranch        *b_MET_RefEle_New_em_etx;   //!
   TBranch        *b_MET_RefEle_New_em_ety;   //!
   TBranch        *b_MET_RefEle_New_em_phi;   //!
   TBranch        *b_MET_RefEle_New_em_et;   //!
   TBranch        *b_MET_RefEle_New_em_sumet;   //!
   TBranch        *b_MET_RefEle_New_em_etx_CentralReg;   //!
   TBranch        *b_MET_RefEle_New_em_ety_CentralReg;   //!
   TBranch        *b_MET_RefEle_New_em_sumet_CentralReg;   //!
   TBranch        *b_MET_RefEle_New_em_phi_CentralReg;   //!
   TBranch        *b_MET_RefEle_New_em_etx_EndcapRegion;   //!
   TBranch        *b_MET_RefEle_New_em_ety_EndcapRegion;   //!
   TBranch        *b_MET_RefEle_New_em_sumet_EndcapRegion;   //!
   TBranch        *b_MET_RefEle_New_em_phi_EndcapRegion;   //!
   TBranch        *b_MET_RefEle_New_em_etx_ForwardReg;   //!
   TBranch        *b_MET_RefEle_New_em_ety_ForwardReg;   //!
   TBranch        *b_MET_RefEle_New_em_sumet_ForwardReg;   //!
   TBranch        *b_MET_RefEle_New_em_phi_ForwardReg;   //!
   TBranch        *b_MET_RefTau_New_em_etx;   //!
   TBranch        *b_MET_RefTau_New_em_ety;   //!
   TBranch        *b_MET_RefTau_New_em_phi;   //!
   TBranch        *b_MET_RefTau_New_em_et;   //!
   TBranch        *b_MET_RefTau_New_em_sumet;   //!
   TBranch        *b_MET_RefTau_New_em_etx_CentralReg;   //!
   TBranch        *b_MET_RefTau_New_em_ety_CentralReg;   //!
   TBranch        *b_MET_RefTau_New_em_sumet_CentralReg;   //!
   TBranch        *b_MET_RefTau_New_em_phi_CentralReg;   //!
   TBranch        *b_MET_RefTau_New_em_etx_EndcapRegion;   //!
   TBranch        *b_MET_RefTau_New_em_ety_EndcapRegion;   //!
   TBranch        *b_MET_RefTau_New_em_sumet_EndcapRegion;   //!
   TBranch        *b_MET_RefTau_New_em_phi_EndcapRegion;   //!
   TBranch        *b_MET_RefTau_New_em_etx_ForwardReg;   //!
   TBranch        *b_MET_RefTau_New_em_ety_ForwardReg;   //!
   TBranch        *b_MET_RefTau_New_em_sumet_ForwardReg;   //!
   TBranch        *b_MET_RefTau_New_em_phi_ForwardReg;   //!
   TBranch        *b_MET_RefJet_New_em_etx;   //!
   TBranch        *b_MET_RefJet_New_em_ety;   //!
   TBranch        *b_MET_RefJet_New_em_phi;   //!
   TBranch        *b_MET_RefJet_New_em_et;   //!
   TBranch        *b_MET_RefJet_New_em_sumet;   //!
   TBranch        *b_MET_RefJet_New_em_etx_CentralReg;   //!
   TBranch        *b_MET_RefJet_New_em_ety_CentralReg;   //!
   TBranch        *b_MET_RefJet_New_em_sumet_CentralReg;   //!
   TBranch        *b_MET_RefJet_New_em_phi_CentralReg;   //!
   TBranch        *b_MET_RefJet_New_em_etx_EndcapRegion;   //!
   TBranch        *b_MET_RefJet_New_em_ety_EndcapRegion;   //!
   TBranch        *b_MET_RefJet_New_em_sumet_EndcapRegion;   //!
   TBranch        *b_MET_RefJet_New_em_phi_EndcapRegion;   //!
   TBranch        *b_MET_RefJet_New_em_etx_ForwardReg;   //!
   TBranch        *b_MET_RefJet_New_em_ety_ForwardReg;   //!
   TBranch        *b_MET_RefJet_New_em_sumet_ForwardReg;   //!
   TBranch        *b_MET_RefJet_New_em_phi_ForwardReg;   //!
   TBranch        *b_MET_CellOut_New_em_etx;   //!
   TBranch        *b_MET_CellOut_New_em_ety;   //!
   TBranch        *b_MET_CellOut_New_em_phi;   //!
   TBranch        *b_MET_CellOut_New_em_et;   //!
   TBranch        *b_MET_CellOut_New_em_sumet;   //!
   TBranch        *b_MET_CellOut_New_em_etx_CentralReg;   //!
   TBranch        *b_MET_CellOut_New_em_ety_CentralReg;   //!
   TBranch        *b_MET_CellOut_New_em_sumet_CentralReg;   //!
   TBranch        *b_MET_CellOut_New_em_phi_CentralReg;   //!
   TBranch        *b_MET_CellOut_New_em_etx_EndcapRegion;   //!
   TBranch        *b_MET_CellOut_New_em_ety_EndcapRegion;   //!
   TBranch        *b_MET_CellOut_New_em_sumet_EndcapRegion;   //!
   TBranch        *b_MET_CellOut_New_em_phi_EndcapRegion;   //!
   TBranch        *b_MET_CellOut_New_em_etx_ForwardReg;   //!
   TBranch        *b_MET_CellOut_New_em_ety_ForwardReg;   //!
   TBranch        *b_MET_CellOut_New_em_sumet_ForwardReg;   //!
   TBranch        *b_MET_CellOut_New_em_phi_ForwardReg;   //!
   TBranch        *b_MET_Cryo_New_em_etx;   //!
   TBranch        *b_MET_Cryo_New_em_ety;   //!
   TBranch        *b_MET_Cryo_New_em_phi;   //!
   TBranch        *b_MET_Cryo_New_em_et;   //!
   TBranch        *b_MET_Cryo_New_em_sumet;   //!
   TBranch        *b_MET_Cryo_New_em_etx_CentralReg;   //!
   TBranch        *b_MET_Cryo_New_em_ety_CentralReg;   //!
   TBranch        *b_MET_Cryo_New_em_sumet_CentralReg;   //!
   TBranch        *b_MET_Cryo_New_em_phi_CentralReg;   //!
   TBranch        *b_MET_Cryo_New_em_etx_EndcapRegion;   //!
   TBranch        *b_MET_Cryo_New_em_ety_EndcapRegion;   //!
   TBranch        *b_MET_Cryo_New_em_sumet_EndcapRegion;   //!
   TBranch        *b_MET_Cryo_New_em_phi_EndcapRegion;   //!
   TBranch        *b_MET_Cryo_New_em_etx_ForwardReg;   //!
   TBranch        *b_MET_Cryo_New_em_ety_ForwardReg;   //!
   TBranch        *b_MET_Cryo_New_em_sumet_ForwardReg;   //!
   TBranch        *b_MET_Cryo_New_em_phi_ForwardReg;   //!
   TBranch        *b_MET_RefFinal_LCW_CB_eflow_etx;   //!
   TBranch        *b_MET_RefFinal_LCW_CB_eflow_ety;   //!
   TBranch        *b_MET_RefFinal_LCW_CB_eflow_phi;   //!
   TBranch        *b_MET_RefFinal_LCW_CB_eflow_et;   //!
   TBranch        *b_MET_RefFinal_LCW_CB_eflow_sumet;   //!
   TBranch        *b_MET_RefFinal_LCW_CB_eflow_etx_CentralReg;   //!
   TBranch        *b_MET_RefFinal_LCW_CB_eflow_ety_CentralReg;   //!
   TBranch        *b_MET_RefFinal_LCW_CB_eflow_sumet_CentralReg;   //!
   TBranch        *b_MET_RefFinal_LCW_CB_eflow_phi_CentralReg;   //!
   TBranch        *b_MET_RefFinal_LCW_CB_eflow_etx_EndcapRegion;   //!
   TBranch        *b_MET_RefFinal_LCW_CB_eflow_ety_EndcapRegion;   //!
   TBranch        *b_MET_RefFinal_LCW_CB_eflow_sumet_EndcapRegion;   //!
   TBranch        *b_MET_RefFinal_LCW_CB_eflow_phi_EndcapRegion;   //!
   TBranch        *b_MET_RefFinal_LCW_CB_eflow_etx_ForwardReg;   //!
   TBranch        *b_MET_RefFinal_LCW_CB_eflow_ety_ForwardReg;   //!
   TBranch        *b_MET_RefFinal_LCW_CB_eflow_sumet_ForwardReg;   //!
   TBranch        *b_MET_RefFinal_LCW_CB_eflow_phi_ForwardReg;   //!
   TBranch        *b_MET_RefGamma_LCW_CB_eflow_etx;   //!
   TBranch        *b_MET_RefGamma_LCW_CB_eflow_ety;   //!
   TBranch        *b_MET_RefGamma_LCW_CB_eflow_phi;   //!
   TBranch        *b_MET_RefGamma_LCW_CB_eflow_et;   //!
   TBranch        *b_MET_RefGamma_LCW_CB_eflow_sumet;   //!
   TBranch        *b_MET_RefGamma_LCW_CB_eflow_etx_CentralReg;   //!
   TBranch        *b_MET_RefGamma_LCW_CB_eflow_ety_CentralReg;   //!
   TBranch        *b_MET_RefGamma_LCW_CB_eflow_sumet_CentralReg;   //!
   TBranch        *b_MET_RefGamma_LCW_CB_eflow_phi_CentralReg;   //!
   TBranch        *b_MET_RefGamma_LCW_CB_eflow_etx_EndcapRegion;   //!
   TBranch        *b_MET_RefGamma_LCW_CB_eflow_ety_EndcapRegion;   //!
   TBranch        *b_MET_RefGamma_LCW_CB_eflow_sumet_EndcapRegion;   //!
   TBranch        *b_MET_RefGamma_LCW_CB_eflow_phi_EndcapRegion;   //!
   TBranch        *b_MET_RefGamma_LCW_CB_eflow_etx_ForwardReg;   //!
   TBranch        *b_MET_RefGamma_LCW_CB_eflow_ety_ForwardReg;   //!
   TBranch        *b_MET_RefGamma_LCW_CB_eflow_sumet_ForwardReg;   //!
   TBranch        *b_MET_RefGamma_LCW_CB_eflow_phi_ForwardReg;   //!
   TBranch        *b_MET_RefEle_LCW_CB_eflow_etx;   //!
   TBranch        *b_MET_RefEle_LCW_CB_eflow_ety;   //!
   TBranch        *b_MET_RefEle_LCW_CB_eflow_phi;   //!
   TBranch        *b_MET_RefEle_LCW_CB_eflow_et;   //!
   TBranch        *b_MET_RefEle_LCW_CB_eflow_sumet;   //!
   TBranch        *b_MET_RefEle_LCW_CB_eflow_etx_CentralReg;   //!
   TBranch        *b_MET_RefEle_LCW_CB_eflow_ety_CentralReg;   //!
   TBranch        *b_MET_RefEle_LCW_CB_eflow_sumet_CentralReg;   //!
   TBranch        *b_MET_RefEle_LCW_CB_eflow_phi_CentralReg;   //!
   TBranch        *b_MET_RefEle_LCW_CB_eflow_etx_EndcapRegion;   //!
   TBranch        *b_MET_RefEle_LCW_CB_eflow_ety_EndcapRegion;   //!
   TBranch        *b_MET_RefEle_LCW_CB_eflow_sumet_EndcapRegion;   //!
   TBranch        *b_MET_RefEle_LCW_CB_eflow_phi_EndcapRegion;   //!
   TBranch        *b_MET_RefEle_LCW_CB_eflow_etx_ForwardReg;   //!
   TBranch        *b_MET_RefEle_LCW_CB_eflow_ety_ForwardReg;   //!
   TBranch        *b_MET_RefEle_LCW_CB_eflow_sumet_ForwardReg;   //!
   TBranch        *b_MET_RefEle_LCW_CB_eflow_phi_ForwardReg;   //!
   TBranch        *b_MET_RefTau_LCW_CB_eflow_etx;   //!
   TBranch        *b_MET_RefTau_LCW_CB_eflow_ety;   //!
   TBranch        *b_MET_RefTau_LCW_CB_eflow_phi;   //!
   TBranch        *b_MET_RefTau_LCW_CB_eflow_et;   //!
   TBranch        *b_MET_RefTau_LCW_CB_eflow_sumet;   //!
   TBranch        *b_MET_RefTau_LCW_CB_eflow_etx_CentralReg;   //!
   TBranch        *b_MET_RefTau_LCW_CB_eflow_ety_CentralReg;   //!
   TBranch        *b_MET_RefTau_LCW_CB_eflow_sumet_CentralReg;   //!
   TBranch        *b_MET_RefTau_LCW_CB_eflow_phi_CentralReg;   //!
   TBranch        *b_MET_RefTau_LCW_CB_eflow_etx_EndcapRegion;   //!
   TBranch        *b_MET_RefTau_LCW_CB_eflow_ety_EndcapRegion;   //!
   TBranch        *b_MET_RefTau_LCW_CB_eflow_sumet_EndcapRegion;   //!
   TBranch        *b_MET_RefTau_LCW_CB_eflow_phi_EndcapRegion;   //!
   TBranch        *b_MET_RefTau_LCW_CB_eflow_etx_ForwardReg;   //!
   TBranch        *b_MET_RefTau_LCW_CB_eflow_ety_ForwardReg;   //!
   TBranch        *b_MET_RefTau_LCW_CB_eflow_sumet_ForwardReg;   //!
   TBranch        *b_MET_RefTau_LCW_CB_eflow_phi_ForwardReg;   //!
   TBranch        *b_MET_RefJet_LCW_CB_eflow_etx;   //!
   TBranch        *b_MET_RefJet_LCW_CB_eflow_ety;   //!
   TBranch        *b_MET_RefJet_LCW_CB_eflow_phi;   //!
   TBranch        *b_MET_RefJet_LCW_CB_eflow_et;   //!
   TBranch        *b_MET_RefJet_LCW_CB_eflow_sumet;   //!
   TBranch        *b_MET_RefJet_LCW_CB_eflow_etx_CentralReg;   //!
   TBranch        *b_MET_RefJet_LCW_CB_eflow_ety_CentralReg;   //!
   TBranch        *b_MET_RefJet_LCW_CB_eflow_sumet_CentralReg;   //!
   TBranch        *b_MET_RefJet_LCW_CB_eflow_phi_CentralReg;   //!
   TBranch        *b_MET_RefJet_LCW_CB_eflow_etx_EndcapRegion;   //!
   TBranch        *b_MET_RefJet_LCW_CB_eflow_ety_EndcapRegion;   //!
   TBranch        *b_MET_RefJet_LCW_CB_eflow_sumet_EndcapRegion;   //!
   TBranch        *b_MET_RefJet_LCW_CB_eflow_phi_EndcapRegion;   //!
   TBranch        *b_MET_RefJet_LCW_CB_eflow_etx_ForwardReg;   //!
   TBranch        *b_MET_RefJet_LCW_CB_eflow_ety_ForwardReg;   //!
   TBranch        *b_MET_RefJet_LCW_CB_eflow_sumet_ForwardReg;   //!
   TBranch        *b_MET_RefJet_LCW_CB_eflow_phi_ForwardReg;   //!
   TBranch        *b_MET_CellOut_LCW_CB_eflow_etx;   //!
   TBranch        *b_MET_CellOut_LCW_CB_eflow_ety;   //!
   TBranch        *b_MET_CellOut_LCW_CB_eflow_phi;   //!
   TBranch        *b_MET_CellOut_LCW_CB_eflow_et;   //!
   TBranch        *b_MET_CellOut_LCW_CB_eflow_sumet;   //!
   TBranch        *b_MET_CellOut_LCW_CB_eflow_etx_CentralReg;   //!
   TBranch        *b_MET_CellOut_LCW_CB_eflow_ety_CentralReg;   //!
   TBranch        *b_MET_CellOut_LCW_CB_eflow_sumet_CentralReg;   //!
   TBranch        *b_MET_CellOut_LCW_CB_eflow_phi_CentralReg;   //!
   TBranch        *b_MET_CellOut_LCW_CB_eflow_etx_EndcapRegion;   //!
   TBranch        *b_MET_CellOut_LCW_CB_eflow_ety_EndcapRegion;   //!
   TBranch        *b_MET_CellOut_LCW_CB_eflow_sumet_EndcapRegion;   //!
   TBranch        *b_MET_CellOut_LCW_CB_eflow_phi_EndcapRegion;   //!
   TBranch        *b_MET_CellOut_LCW_CB_eflow_etx_ForwardReg;   //!
   TBranch        *b_MET_CellOut_LCW_CB_eflow_ety_ForwardReg;   //!
   TBranch        *b_MET_CellOut_LCW_CB_eflow_sumet_ForwardReg;   //!
   TBranch        *b_MET_CellOut_LCW_CB_eflow_phi_ForwardReg;   //!
   TBranch        *b_MET_Cryo_LCW_CB_eflow_etx;   //!
   TBranch        *b_MET_Cryo_LCW_CB_eflow_ety;   //!
   TBranch        *b_MET_Cryo_LCW_CB_eflow_phi;   //!
   TBranch        *b_MET_Cryo_LCW_CB_eflow_et;   //!
   TBranch        *b_MET_Cryo_LCW_CB_eflow_sumet;   //!
   TBranch        *b_MET_Cryo_LCW_CB_eflow_etx_CentralReg;   //!
   TBranch        *b_MET_Cryo_LCW_CB_eflow_ety_CentralReg;   //!
   TBranch        *b_MET_Cryo_LCW_CB_eflow_sumet_CentralReg;   //!
   TBranch        *b_MET_Cryo_LCW_CB_eflow_phi_CentralReg;   //!
   TBranch        *b_MET_Cryo_LCW_CB_eflow_etx_EndcapRegion;   //!
   TBranch        *b_MET_Cryo_LCW_CB_eflow_ety_EndcapRegion;   //!
   TBranch        *b_MET_Cryo_LCW_CB_eflow_sumet_EndcapRegion;   //!
   TBranch        *b_MET_Cryo_LCW_CB_eflow_phi_EndcapRegion;   //!
   TBranch        *b_MET_Cryo_LCW_CB_eflow_etx_ForwardReg;   //!
   TBranch        *b_MET_Cryo_LCW_CB_eflow_ety_ForwardReg;   //!
   TBranch        *b_MET_Cryo_LCW_CB_eflow_sumet_ForwardReg;   //!
   TBranch        *b_MET_Cryo_LCW_CB_eflow_phi_ForwardReg;   //!
   TBranch        *b_L1_2J10;   //!
   TBranch        *b_L1_2J15;   //!
   TBranch        *b_L1_2J5;   //!
   TBranch        *b_L1_J10;   //!
   TBranch        *b_L1_J15;   //!
   TBranch        *b_L1_J30;   //!
   TBranch        *b_L1_J5;   //!
   TBranch        *b_L1_J55;   //!
   TBranch        *b_L1_J75;   //!
   TBranch        *b_L1_J95;   //!
   TBranch        *b_trig_L1_TAV;   //!
   TBranch        *b_trig_L2_passedPhysics;   //!
   TBranch        *b_trig_EF_passedPhysics;   //!
   TBranch        *b_trig_L1_TBP;   //!
   TBranch        *b_trig_L1_TAP;   //!
   TBranch        *b_trig_L2_passedRaw;   //!
   TBranch        *b_trig_EF_passedRaw;   //!
   TBranch        *b_trig_L2_resurrected;   //!
   TBranch        *b_trig_EF_resurrected;   //!
   TBranch        *b_trig_L2_passedThrough;   //!
   TBranch        *b_trig_EF_passedThrough;   //!
   TBranch        *b_trig_DB_SMK;   //!
   TBranch        *b_trig_DB_L1PSK;   //!
   TBranch        *b_trig_DB_HLTPSK;   //!
   TBranch        *b_mcevt_n;   //!
   TBranch        *b_mcevt_signal_process_id;   //!
   TBranch        *b_mcevt_event_number;   //!
   TBranch        *b_mcevt_event_scale;   //!
   TBranch        *b_mcevt_alphaQCD;   //!
   TBranch        *b_mcevt_alphaQED;   //!
   TBranch        *b_mcevt_pdf_id1;   //!
   TBranch        *b_mcevt_pdf_id2;   //!
   TBranch        *b_mcevt_pdf_x1;   //!
   TBranch        *b_mcevt_pdf_x2;   //!
   TBranch        *b_mcevt_pdf_scale;   //!
   TBranch        *b_mcevt_pdf1;   //!
   TBranch        *b_mcevt_pdf2;   //!
   TBranch        *b_mcevt_weight;   //!
   TBranch        *b_mc_n;   //!
   TBranch        *b_mc_pt;   //!
   TBranch        *b_mc_eta;   //!
   TBranch        *b_mc_phi;   //!
   TBranch        *b_mc_status;   //!
   TBranch        *b_mc_barcode;   //!
   TBranch        *b_mc_parents;   //!
   TBranch        *b_mc_children;   //!
   TBranch        *b_mc_pdgId;   //!
   TBranch        *b_AntiKt4TruthNew_n;   //!
   TBranch        *b_AntiKt4TruthNew_E;   //!
   TBranch        *b_AntiKt4TruthNew_pt;   //!
   TBranch        *b_AntiKt4TruthNew_m;   //!
   TBranch        *b_AntiKt4TruthNew_eta;   //!
   TBranch        *b_AntiKt4TruthNew_phi;   //!
   TBranch        *b_AntiKt6TruthNew_n;   //!
   TBranch        *b_AntiKt6TruthNew_E;   //!
   TBranch        *b_AntiKt6TruthNew_pt;   //!
   TBranch        *b_AntiKt6TruthNew_m;   //!
   TBranch        *b_AntiKt6TruthNew_eta;   //!
   TBranch        *b_AntiKt6TruthNew_phi;   //!

   oldExample(TTree *tree=0);
   virtual ~oldExample();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef oldExample_cxx
oldExample::oldExample(TTree *tree)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {

#ifdef SINGLE_TREE
      // The following code should be used if you want this class to access
      // a single tree instead of a chain
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("Memory Directory");
      if (!f) {
         f = new TFile("Memory Directory");
         f->cd("Rint:/");
      }
      tree = (TTree*)gDirectory->Get("qcd");

#else // SINGLE_TREE

      // The following code should be used if you want this class to access a chain
      // of trees.
      TChain * chain = new TChain("qcd","");
      chain->Add("/scratch/jgoodson/user.sresconi.group10_v7comp.perf-jets.mc10_7TeV.106043.PythiaWenu_no_filter.merge.AOD.e574_s933_s946_r1659_r2040.WZ.v7_EXT0.110518090132/user.sresconi.002961._00010.qcd.root.1/qcd");
      tree = chain;
#endif // SINGLE_TREE

   }
   Init(tree);
}

oldExample::~oldExample()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t oldExample::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t oldExample::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (!fChain->InheritsFrom(TChain::Class()))  return centry;
   TChain *chain = (TChain*)fChain;
   if (chain->GetTreeNumber() != fCurrent) {
      fCurrent = chain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void oldExample::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   beamSpot_x = 0;
   beamSpot_y = 0;
   beamSpot_z = 0;
   vxp_x = 0;
   vxp_y = 0;
   vxp_z = 0;
   vxp_cov_x = 0;
   vxp_cov_y = 0;
   vxp_cov_z = 0;
   vxp_cov_xy = 0;
   vxp_cov_xz = 0;
   vxp_cov_yz = 0;
   vxp_chi2 = 0;
   vxp_ndof = 0;
   vxp_px = 0;
   vxp_py = 0;
   vxp_pz = 0;
   vxp_E = 0;
   vxp_m = 0;
   vxp_nTracks = 0;
   vxp_sumPt = 0;
   vxp_type = 0;
   vxp_trk_n = 0;
   vxp_trk_index = 0;
   el_E = 0;
   el_Et = 0;
   el_pt = 0;
   el_m = 0;
   el_eta = 0;
   el_phi = 0;
   el_px = 0;
   el_py = 0;
   el_pz = 0;
   el_charge = 0;
   el_author = 0;
   el_isEM = 0;
   el_loose = 0;
   el_medium = 0;
   el_mediumIso = 0;
   el_tight = 0;
   el_tightIso = 0;
   el_Etcone45 = 0;
   el_Etcone20 = 0;
   el_Etcone30 = 0;
   el_Etcone40 = 0;
   el_Es2 = 0;
   el_etas2 = 0;
   el_phis2 = 0;
   el_cl_E = 0;
   el_cl_pt = 0;
   el_cl_eta = 0;
   el_cl_phi = 0;
   el_trackd0 = 0;
   el_trackz0 = 0;
   el_trackphi = 0;
   el_tracktheta = 0;
   el_trackqoverp = 0;
   el_trackpt = 0;
   el_tracketa = 0;
   el_vertx = 0;
   el_verty = 0;
   el_vertz = 0;
   mu_staco_E = 0;
   mu_staco_pt = 0;
   mu_staco_m = 0;
   mu_staco_eta = 0;
   mu_staco_phi = 0;
   mu_staco_px = 0;
   mu_staco_py = 0;
   mu_staco_pz = 0;
   mu_staco_charge = 0;
   mu_staco_allauthor = 0;
   mu_staco_author = 0;
   mu_staco_beta = 0;
   mu_staco_isMuonLikelihood = 0;
   mu_staco_matchchi2 = 0;
   mu_staco_matchndof = 0;
   mu_staco_etcone20 = 0;
   mu_staco_etcone30 = 0;
   mu_staco_etcone40 = 0;
   mu_staco_nucone20 = 0;
   mu_staco_nucone30 = 0;
   mu_staco_nucone40 = 0;
   mu_staco_ptcone20 = 0;
   mu_staco_ptcone30 = 0;
   mu_staco_ptcone40 = 0;
   mu_staco_energyLossPar = 0;
   mu_staco_energyLossErr = 0;
   mu_staco_etCore = 0;
   mu_staco_energyLossType = 0;
   mu_staco_caloMuonIdTag = 0;
   mu_staco_caloLRLikelihood = 0;
   mu_staco_bestMatch = 0;
   mu_staco_isStandAloneMuon = 0;
   mu_staco_isCombinedMuon = 0;
   mu_staco_isLowPtReconstructedMuon = 0;
   mu_staco_loose = 0;
   mu_staco_medium = 0;
   mu_staco_tight = 0;
   mu_staco_d0_exPV = 0;
   mu_staco_z0_exPV = 0;
   mu_staco_phi_exPV = 0;
   mu_staco_theta_exPV = 0;
   mu_staco_qoverp_exPV = 0;
   mu_staco_cb_d0_exPV = 0;
   mu_staco_cb_z0_exPV = 0;
   mu_staco_cb_phi_exPV = 0;
   mu_staco_cb_theta_exPV = 0;
   mu_staco_cb_qoverp_exPV = 0;
   mu_staco_id_d0_exPV = 0;
   mu_staco_id_z0_exPV = 0;
   mu_staco_id_phi_exPV = 0;
   mu_staco_id_theta_exPV = 0;
   mu_staco_id_qoverp_exPV = 0;
   mu_staco_me_d0_exPV = 0;
   mu_staco_me_z0_exPV = 0;
   mu_staco_me_phi_exPV = 0;
   mu_staco_me_theta_exPV = 0;
   mu_staco_me_qoverp_exPV = 0;
   mu_staco_ie_d0_exPV = 0;
   mu_staco_ie_z0_exPV = 0;
   mu_staco_ie_phi_exPV = 0;
   mu_staco_ie_theta_exPV = 0;
   mu_staco_ie_qoverp_exPV = 0;
   mu_staco_SpaceTime_detID = 0;
   mu_staco_SpaceTime_t = 0;
   mu_staco_SpaceTime_tError = 0;
   mu_staco_SpaceTime_weight = 0;
   mu_staco_SpaceTime_x = 0;
   mu_staco_SpaceTime_y = 0;
   mu_staco_SpaceTime_z = 0;
   mu_staco_SpaceTime_t_Tile = 0;
   mu_staco_SpaceTime_tError_Tile = 0;
   mu_staco_SpaceTime_weight_Tile = 0;
   mu_staco_SpaceTime_x_Tile = 0;
   mu_staco_SpaceTime_y_Tile = 0;
   mu_staco_SpaceTime_z_Tile = 0;
   mu_staco_SpaceTime_t_TRT = 0;
   mu_staco_SpaceTime_tError_TRT = 0;
   mu_staco_SpaceTime_weight_TRT = 0;
   mu_staco_SpaceTime_x_TRT = 0;
   mu_staco_SpaceTime_y_TRT = 0;
   mu_staco_SpaceTime_z_TRT = 0;
   mu_staco_SpaceTime_t_MDT = 0;
   mu_staco_SpaceTime_tError_MDT = 0;
   mu_staco_SpaceTime_weight_MDT = 0;
   mu_staco_SpaceTime_x_MDT = 0;
   mu_staco_SpaceTime_y_MDT = 0;
   mu_staco_SpaceTime_z_MDT = 0;
   mu_staco_TileCellEnergyLayer1 = 0;
   mu_staco_TileTimeLayer1 = 0;
   mu_staco_TileCellRmsNoiseLayer1 = 0;
   mu_staco_TileCellSignLayer1 = 0;
   mu_staco_TileCellEnergyLayer2 = 0;
   mu_staco_TileTimeLayer2 = 0;
   mu_staco_TileCellRmsNoiseLayer2 = 0;
   mu_staco_TileCellSignLayer2 = 0;
   mu_staco_TileCellEnergyLayer3 = 0;
   mu_staco_TileTimeLayer3 = 0;
   mu_staco_TileCellRmsNoiseLayer3 = 0;
   mu_staco_TileCellSignLayer3 = 0;
   mu_staco_MSTrkT0_1 = 0;
   mu_staco_MSTrkT0_2 = 0;
   mu_staco_MSTrkT0_3 = 0;
   mu_staco_cov_d0_exPV = 0;
   mu_staco_cov_z0_exPV = 0;
   mu_staco_cov_phi_exPV = 0;
   mu_staco_cov_theta_exPV = 0;
   mu_staco_cov_qoverp_exPV = 0;
   mu_staco_cov_d0_z0_exPV = 0;
   mu_staco_cov_d0_phi_exPV = 0;
   mu_staco_cov_d0_theta_exPV = 0;
   mu_staco_cov_d0_qoverp_exPV = 0;
   mu_staco_cov_z0_phi_exPV = 0;
   mu_staco_cov_z0_theta_exPV = 0;
   mu_staco_cov_z0_qoverp_exPV = 0;
   mu_staco_cov_phi_theta_exPV = 0;
   mu_staco_cov_phi_qoverp_exPV = 0;
   mu_staco_cov_theta_qoverp_exPV = 0;
   mu_staco_id_cov_d0_exPV = 0;
   mu_staco_id_cov_z0_exPV = 0;
   mu_staco_id_cov_phi_exPV = 0;
   mu_staco_id_cov_theta_exPV = 0;
   mu_staco_id_cov_qoverp_exPV = 0;
   mu_staco_me_cov_d0_exPV = 0;
   mu_staco_me_cov_z0_exPV = 0;
   mu_staco_me_cov_phi_exPV = 0;
   mu_staco_me_cov_theta_exPV = 0;
   mu_staco_me_cov_qoverp_exPV = 0;
   mu_staco_ms_d0 = 0;
   mu_staco_ms_z0 = 0;
   mu_staco_ms_phi = 0;
   mu_staco_ms_theta = 0;
   mu_staco_ms_qoverp = 0;
   mu_staco_id_d0 = 0;
   mu_staco_id_z0 = 0;
   mu_staco_id_phi = 0;
   mu_staco_id_theta = 0;
   mu_staco_id_qoverp = 0;
   mu_staco_me_d0 = 0;
   mu_staco_me_z0 = 0;
   mu_staco_me_phi = 0;
   mu_staco_me_theta = 0;
   mu_staco_me_qoverp = 0;
   mu_staco_ie_d0 = 0;
   mu_staco_ie_z0 = 0;
   mu_staco_ie_phi = 0;
   mu_staco_ie_theta = 0;
   mu_staco_ie_qoverp = 0;
   mu_staco_nOutliersOnTrack = 0;
   mu_staco_nBLHits = 0;
   mu_staco_nPixHits = 0;
   mu_staco_nSCTHits = 0;
   mu_staco_nTRTHits = 0;
   mu_staco_nTRTHighTHits = 0;
   mu_staco_nBLSharedHits = 0;
   mu_staco_nPixSharedHits = 0;
   mu_staco_nPixHoles = 0;
   mu_staco_nSCTSharedHits = 0;
   mu_staco_nSCTHoles = 0;
   mu_staco_nTRTOutliers = 0;
   mu_staco_nTRTHighTOutliers = 0;
   mu_staco_nGangedPixels = 0;
   mu_staco_nPixelDeadSensors = 0;
   mu_staco_nSCTDeadSensors = 0;
   mu_staco_nTRTDeadStraws = 0;
   mu_staco_expectBLayerHit = 0;
   mu_staco_nMDTHits = 0;
   mu_staco_nMDTHoles = 0;
   mu_staco_nCSCEtaHits = 0;
   mu_staco_nCSCEtaHoles = 0;
   mu_staco_nCSCPhiHits = 0;
   mu_staco_nCSCPhiHoles = 0;
   mu_staco_nRPCEtaHits = 0;
   mu_staco_nRPCEtaHoles = 0;
   mu_staco_nRPCPhiHits = 0;
   mu_staco_nRPCPhiHoles = 0;
   mu_staco_nTGCEtaHits = 0;
   mu_staco_nTGCEtaHoles = 0;
   mu_staco_nTGCPhiHits = 0;
   mu_staco_nTGCPhiHoles = 0;
   mu_staco_nMDTBIHits = 0;
   mu_staco_nMDTBMHits = 0;
   mu_staco_nMDTBOHits = 0;
   mu_staco_nMDTBEEHits = 0;
   mu_staco_nMDTBIS78Hits = 0;
   mu_staco_nMDTEIHits = 0;
   mu_staco_nMDTEMHits = 0;
   mu_staco_nMDTEOHits = 0;
   mu_staco_nMDTEEHits = 0;
   mu_staco_nRPCLayer1EtaHits = 0;
   mu_staco_nRPCLayer2EtaHits = 0;
   mu_staco_nRPCLayer3EtaHits = 0;
   mu_staco_nRPCLayer1PhiHits = 0;
   mu_staco_nRPCLayer2PhiHits = 0;
   mu_staco_nRPCLayer3PhiHits = 0;
   mu_staco_nTGCLayer1EtaHits = 0;
   mu_staco_nTGCLayer2EtaHits = 0;
   mu_staco_nTGCLayer3EtaHits = 0;
   mu_staco_nTGCLayer4EtaHits = 0;
   mu_staco_nTGCLayer1PhiHits = 0;
   mu_staco_nTGCLayer2PhiHits = 0;
   mu_staco_nTGCLayer3PhiHits = 0;
   mu_staco_nTGCLayer4PhiHits = 0;
   mu_staco_barrelSectors = 0;
   mu_staco_endcapSectors = 0;
   mu_staco_trackd0 = 0;
   mu_staco_trackz0 = 0;
   mu_staco_trackphi = 0;
   mu_staco_tracktheta = 0;
   mu_staco_trackqoverp = 0;
   mu_staco_trackcov_d0 = 0;
   mu_staco_trackcov_z0 = 0;
   mu_staco_trackcov_phi = 0;
   mu_staco_trackcov_theta = 0;
   mu_staco_trackcov_qoverp = 0;
   mu_staco_trackcov_d0_z0 = 0;
   mu_staco_trackcov_d0_phi = 0;
   mu_staco_trackcov_d0_theta = 0;
   mu_staco_trackcov_d0_qoverp = 0;
   mu_staco_trackcov_z0_phi = 0;
   mu_staco_trackcov_z0_theta = 0;
   mu_staco_trackcov_z0_qoverp = 0;
   mu_staco_trackcov_phi_theta = 0;
   mu_staco_trackcov_phi_qoverp = 0;
   mu_staco_trackcov_theta_qoverp = 0;
   mu_staco_trackfitchi2 = 0;
   mu_staco_trackfitndof = 0;
   mu_staco_hastrack = 0;
   mu_staco_truth_dr = 0;
   mu_staco_truth_matched = 0;
   mu_staco_EFCB_dr = 0;
   mu_staco_EFCB_n = 0;
   mu_staco_EFCB_MuonType = 0;
   mu_staco_EFCB_pt = 0;
   mu_staco_EFCB_eta = 0;
   mu_staco_EFCB_phi = 0;
   mu_staco_EFCB_hasCB = 0;
   mu_staco_EFCB_matched = 0;
   mu_staco_EFMG_dr = 0;
   mu_staco_EFMG_n = 0;
   mu_staco_EFMG_MuonType = 0;
   mu_staco_EFMG_pt = 0;
   mu_staco_EFMG_eta = 0;
   mu_staco_EFMG_phi = 0;
   mu_staco_EFMG_hasMG = 0;
   mu_staco_EFMG_matched = 0;
   mu_staco_EFME_dr = 0;
   mu_staco_EFME_n = 0;
   mu_staco_EFME_MuonType = 0;
   mu_staco_EFME_pt = 0;
   mu_staco_EFME_eta = 0;
   mu_staco_EFME_phi = 0;
   mu_staco_EFME_hasME = 0;
   mu_staco_EFME_matched = 0;
   mu_staco_L2CB_dr = 0;
   mu_staco_L2CB_pt = 0;
   mu_staco_L2CB_eta = 0;
   mu_staco_L2CB_phi = 0;
   mu_staco_L2CB_id_pt = 0;
   mu_staco_L2CB_ms_pt = 0;
   mu_staco_L2CB_nPixHits = 0;
   mu_staco_L2CB_nSCTHits = 0;
   mu_staco_L2CB_nTRTHits = 0;
   mu_staco_L2CB_nTRTHighTHits = 0;
   mu_staco_L2CB_matched = 0;
   mu_staco_L1_dr = 0;
   mu_staco_L1_pt = 0;
   mu_staco_L1_eta = 0;
   mu_staco_L1_phi = 0;
   mu_staco_L1_thrNumber = 0;
   mu_staco_L1_RoINumber = 0;
   mu_staco_L1_sectorAddress = 0;
   mu_staco_L1_firstCandidate = 0;
   mu_staco_L1_moreCandInRoI = 0;
   mu_staco_L1_moreCandInSector = 0;
   mu_staco_L1_source = 0;
   mu_staco_L1_hemisphere = 0;
   mu_staco_L1_matched = 0;
   el_HR_E = 0;
   el_HR_Et = 0;
   el_HR_pt = 0;
   el_HR_m = 0;
   el_HR_eta = 0;
   el_HR_phi = 0;
   el_HR_px = 0;
   el_HR_py = 0;
   el_HR_pz = 0;
   el_HR_charge = 0;
   el_HR_author = 0;
   el_HR_isEM = 0;
   el_HR_OQ = 0;
   el_HR_convFlag = 0;
   el_HR_isConv = 0;
   el_HR_nConv = 0;
   el_HR_nSingleTrackConv = 0;
   el_HR_nDoubleTrackConv = 0;
   el_HR_OQRecalc = 0;
   el_HR_type = 0;
   el_HR_origin = 0;
   el_HR_typebkg = 0;
   el_HR_originbkg = 0;
   el_HR_truth_E = 0;
   el_HR_truth_pt = 0;
   el_HR_truth_eta = 0;
   el_HR_truth_phi = 0;
   el_HR_truth_type = 0;
   el_HR_truth_status = 0;
   el_HR_truth_barcode = 0;
   el_HR_truth_mothertype = 0;
   el_HR_truth_motherbarcode = 0;
   el_HR_truth_hasHardBrem = 0;
   el_HR_truth_index = 0;
   el_HR_truth_matched = 0;
   el_HR_loose = 0;
   el_HR_medium = 0;
   el_HR_mediumIso = 0;
   el_HR_tight = 0;
   el_HR_tightIso = 0;
   el_HR_goodOQ = 0;
   el_HR_Ethad = 0;
   el_HR_Ethad1 = 0;
   el_HR_f1 = 0;
   el_HR_f1core = 0;
   el_HR_Emins1 = 0;
   el_HR_fside = 0;
   el_HR_Emax2 = 0;
   el_HR_ws3 = 0;
   el_HR_wstot = 0;
   el_HR_emaxs1 = 0;
   el_HR_deltaEs = 0;
   el_HR_E233 = 0;
   el_HR_E237 = 0;
   el_HR_E277 = 0;
   el_HR_weta2 = 0;
   el_HR_f3 = 0;
   el_HR_f3core = 0;
   el_HR_rphiallcalo = 0;
   el_HR_Etcone45 = 0;
   el_HR_Etcone15 = 0;
   el_HR_Etcone20 = 0;
   el_HR_Etcone25 = 0;
   el_HR_Etcone30 = 0;
   el_HR_Etcone35 = 0;
   el_HR_Etcone40 = 0;
   el_HR_ptcone20 = 0;
   el_HR_ptcone30 = 0;
   el_HR_ptcone40 = 0;
   el_HR_nucone20 = 0;
   el_HR_nucone30 = 0;
   el_HR_nucone40 = 0;
   el_HR_convanglematch = 0;
   el_HR_convtrackmatch = 0;
   el_HR_hasconv = 0;
   el_HR_convvtxx = 0;
   el_HR_convvtxy = 0;
   el_HR_convvtxz = 0;
   el_HR_Rconv = 0;
   el_HR_zconv = 0;
   el_HR_convvtxchi2 = 0;
   el_HR_pt1conv = 0;
   el_HR_convtrk1nBLHits = 0;
   el_HR_convtrk1nPixHits = 0;
   el_HR_convtrk1nSCTHits = 0;
   el_HR_convtrk1nTRTHits = 0;
   el_HR_pt2conv = 0;
   el_HR_convtrk2nBLHits = 0;
   el_HR_convtrk2nPixHits = 0;
   el_HR_convtrk2nSCTHits = 0;
   el_HR_convtrk2nTRTHits = 0;
   el_HR_ptconv = 0;
   el_HR_pzconv = 0;
   el_HR_pos7 = 0;
   el_HR_etacorrmag = 0;
   el_HR_deltaeta1 = 0;
   el_HR_deltaeta2 = 0;
   el_HR_deltaphi2 = 0;
   el_HR_deltaphiRescaled = 0;
   el_HR_deltaPhiRot = 0;
   el_HR_expectHitInBLayer = 0;
   el_HR_trackd0_physics = 0;
   el_HR_reta = 0;
   el_HR_rphi = 0;
   el_HR_refittedTrack_n = 0;
   el_HR_firstEdens = 0;
   el_HR_cellmaxfrac = 0;
   el_HR_longitudinal = 0;
   el_HR_secondlambda = 0;
   el_HR_lateral = 0;
   el_HR_secondR = 0;
   el_HR_centerlambda = 0;
   el_HR_trackd0 = 0;
   el_HR_trackz0 = 0;
   el_HR_trackphi = 0;
   el_HR_tracktheta = 0;
   el_HR_trackqoverp = 0;
   el_HR_trackpt = 0;
   el_HR_tracketa = 0;
   el_HR_nBLHits = 0;
   el_HR_nPixHits = 0;
   el_HR_nSCTHits = 0;
   el_HR_nTRTHits = 0;
   el_HR_nPixHoles = 0;
   el_HR_nSCTHoles = 0;
   el_HR_nBLSharedHits = 0;
   el_HR_nPixSharedHits = 0;
   el_HR_nSCTSharedHits = 0;
   el_HR_nTRTHighTHits = 0;
   el_HR_nTRTOutliers = 0;
   el_HR_nTRTHighTOutliers = 0;
   el_HR_nSiHits = 0;
   el_HR_TRTHighTHitsRatio = 0;
   el_HR_TRTHighTHitsRatioOutliers = 0;
   el_HR_pixeldEdx = 0;
   el_HR_eProbabilityComb = 0;
   el_HR_eProbabilityHT = 0;
   el_HR_eProbabilityToT = 0;
   el_HR_eProbabilityBrem = 0;
   el_HR_hastrack = 0;
   el_HR_deltaEmax2 = 0;
   el_HR_calibHitsShowerDepth = 0;
   el_HR_trackd0beam = 0;
   el_HR_tracksigd0beam = 0;
   el_HR_trackd0pv = 0;
   el_HR_tracksigd0pv = 0;
   el_HR_trackz0pv = 0;
   el_HR_tracksigz0pv = 0;
   el_HR_trackd0pvunbiased = 0;
   el_HR_tracksigd0pvunbiased = 0;
   el_HR_trackz0pvunbiased = 0;
   el_HR_tracksigz0pvunbiased = 0;
   el_HR_isIso = 0;
   el_HR_mvaptcone20 = 0;
   el_HR_mvaptcone30 = 0;
   el_HR_mvaptcone40 = 0;
   el_HR_EF_dr = 0;
   el_HR_L2_dr = 0;
   el_HR_L1_dr = 0;
   mu_HR_E = 0;
   mu_HR_pt = 0;
   mu_HR_m = 0;
   mu_HR_eta = 0;
   mu_HR_phi = 0;
   mu_HR_px = 0;
   mu_HR_py = 0;
   mu_HR_pz = 0;
   mu_HR_charge = 0;
   mu_HR_allauthor = 0;
   mu_HR_author = 0;
   mu_HR_beta = 0;
   mu_HR_isMuonLikelihood = 0;
   mu_HR_matchchi2 = 0;
   mu_HR_matchndof = 0;
   mu_HR_etcone20 = 0;
   mu_HR_etcone30 = 0;
   mu_HR_etcone40 = 0;
   mu_HR_nucone20 = 0;
   mu_HR_nucone30 = 0;
   mu_HR_nucone40 = 0;
   mu_HR_ptcone20 = 0;
   mu_HR_ptcone30 = 0;
   mu_HR_ptcone40 = 0;
   mu_HR_energyLossPar = 0;
   mu_HR_energyLossErr = 0;
   mu_HR_etCore = 0;
   mu_HR_energyLossType = 0;
   mu_HR_caloMuonIdTag = 0;
   mu_HR_caloLRLikelihood = 0;
   mu_HR_bestMatch = 0;
   mu_HR_isStandAloneMuon = 0;
   mu_HR_isCombinedMuon = 0;
   mu_HR_isLowPtReconstructedMuon = 0;
   mu_HR_loose = 0;
   mu_HR_medium = 0;
   mu_HR_tight = 0;
   mu_HR_d0_exPV = 0;
   mu_HR_z0_exPV = 0;
   mu_HR_phi_exPV = 0;
   mu_HR_theta_exPV = 0;
   mu_HR_qoverp_exPV = 0;
   mu_HR_cb_d0_exPV = 0;
   mu_HR_cb_z0_exPV = 0;
   mu_HR_cb_phi_exPV = 0;
   mu_HR_cb_theta_exPV = 0;
   mu_HR_cb_qoverp_exPV = 0;
   mu_HR_id_d0_exPV = 0;
   mu_HR_id_z0_exPV = 0;
   mu_HR_id_phi_exPV = 0;
   mu_HR_id_theta_exPV = 0;
   mu_HR_id_qoverp_exPV = 0;
   mu_HR_me_d0_exPV = 0;
   mu_HR_me_z0_exPV = 0;
   mu_HR_me_phi_exPV = 0;
   mu_HR_me_theta_exPV = 0;
   mu_HR_me_qoverp_exPV = 0;
   mu_HR_ie_d0_exPV = 0;
   mu_HR_ie_z0_exPV = 0;
   mu_HR_ie_phi_exPV = 0;
   mu_HR_ie_theta_exPV = 0;
   mu_HR_ie_qoverp_exPV = 0;
   mu_HR_SpaceTime_detID = 0;
   mu_HR_SpaceTime_t = 0;
   mu_HR_SpaceTime_tError = 0;
   mu_HR_SpaceTime_weight = 0;
   mu_HR_SpaceTime_x = 0;
   mu_HR_SpaceTime_y = 0;
   mu_HR_SpaceTime_z = 0;
   mu_HR_SpaceTime_t_Tile = 0;
   mu_HR_SpaceTime_tError_Tile = 0;
   mu_HR_SpaceTime_weight_Tile = 0;
   mu_HR_SpaceTime_x_Tile = 0;
   mu_HR_SpaceTime_y_Tile = 0;
   mu_HR_SpaceTime_z_Tile = 0;
   mu_HR_SpaceTime_t_TRT = 0;
   mu_HR_SpaceTime_tError_TRT = 0;
   mu_HR_SpaceTime_weight_TRT = 0;
   mu_HR_SpaceTime_x_TRT = 0;
   mu_HR_SpaceTime_y_TRT = 0;
   mu_HR_SpaceTime_z_TRT = 0;
   mu_HR_SpaceTime_t_MDT = 0;
   mu_HR_SpaceTime_tError_MDT = 0;
   mu_HR_SpaceTime_weight_MDT = 0;
   mu_HR_SpaceTime_x_MDT = 0;
   mu_HR_SpaceTime_y_MDT = 0;
   mu_HR_SpaceTime_z_MDT = 0;
   mu_HR_TileCellEnergyLayer1 = 0;
   mu_HR_TileTimeLayer1 = 0;
   mu_HR_TileCellRmsNoiseLayer1 = 0;
   mu_HR_TileCellSignLayer1 = 0;
   mu_HR_TileCellEnergyLayer2 = 0;
   mu_HR_TileTimeLayer2 = 0;
   mu_HR_TileCellRmsNoiseLayer2 = 0;
   mu_HR_TileCellSignLayer2 = 0;
   mu_HR_TileCellEnergyLayer3 = 0;
   mu_HR_TileTimeLayer3 = 0;
   mu_HR_TileCellRmsNoiseLayer3 = 0;
   mu_HR_TileCellSignLayer3 = 0;
   mu_HR_MSTrkT0_1 = 0;
   mu_HR_MSTrkT0_2 = 0;
   mu_HR_MSTrkT0_3 = 0;
   mu_HR_cov_d0_exPV = 0;
   mu_HR_cov_z0_exPV = 0;
   mu_HR_cov_phi_exPV = 0;
   mu_HR_cov_theta_exPV = 0;
   mu_HR_cov_qoverp_exPV = 0;
   mu_HR_cov_d0_z0_exPV = 0;
   mu_HR_cov_d0_phi_exPV = 0;
   mu_HR_cov_d0_theta_exPV = 0;
   mu_HR_cov_d0_qoverp_exPV = 0;
   mu_HR_cov_z0_phi_exPV = 0;
   mu_HR_cov_z0_theta_exPV = 0;
   mu_HR_cov_z0_qoverp_exPV = 0;
   mu_HR_cov_phi_theta_exPV = 0;
   mu_HR_cov_phi_qoverp_exPV = 0;
   mu_HR_cov_theta_qoverp_exPV = 0;
   mu_HR_ms_d0 = 0;
   mu_HR_ms_z0 = 0;
   mu_HR_ms_phi = 0;
   mu_HR_ms_theta = 0;
   mu_HR_ms_qoverp = 0;
   mu_HR_id_d0 = 0;
   mu_HR_id_z0 = 0;
   mu_HR_id_phi = 0;
   mu_HR_id_theta = 0;
   mu_HR_id_qoverp = 0;
   mu_HR_me_d0 = 0;
   mu_HR_me_z0 = 0;
   mu_HR_me_phi = 0;
   mu_HR_me_theta = 0;
   mu_HR_me_qoverp = 0;
   mu_HR_ie_d0 = 0;
   mu_HR_ie_z0 = 0;
   mu_HR_ie_phi = 0;
   mu_HR_ie_theta = 0;
   mu_HR_ie_qoverp = 0;
   mu_HR_trackd0 = 0;
   mu_HR_trackz0 = 0;
   mu_HR_trackphi = 0;
   mu_HR_tracktheta = 0;
   mu_HR_trackqoverp = 0;
   mu_HR_trackcov_d0 = 0;
   mu_HR_trackcov_z0 = 0;
   mu_HR_trackcov_phi = 0;
   mu_HR_trackcov_theta = 0;
   mu_HR_trackcov_qoverp = 0;
   mu_HR_hastrack = 0;
   mu_HR_truth_dr = 0;
   mu_HR_truth_E = 0;
   mu_HR_truth_pt = 0;
   mu_HR_truth_eta = 0;
   mu_HR_truth_phi = 0;
   mu_HR_truth_type = 0;
   mu_HR_truth_status = 0;
   mu_HR_truth_barcode = 0;
   mu_HR_truth_mothertype = 0;
   mu_HR_truth_motherbarcode = 0;
   mu_HR_truth_matched = 0;
   mu_HR_EFCB_dr = 0;
   mu_HR_EFCB_n = 0;
   mu_HR_EFCB_MuonType = 0;
   mu_HR_EFCB_pt = 0;
   mu_HR_EFCB_eta = 0;
   mu_HR_EFCB_phi = 0;
   mu_HR_EFCB_hasCB = 0;
   mu_HR_EFCB_matched = 0;
   mu_HR_EFMG_dr = 0;
   mu_HR_EFMG_n = 0;
   mu_HR_EFMG_MuonType = 0;
   mu_HR_EFMG_pt = 0;
   mu_HR_EFMG_eta = 0;
   mu_HR_EFMG_phi = 0;
   mu_HR_EFMG_hasMG = 0;
   mu_HR_EFMG_matched = 0;
   mu_HR_EFME_dr = 0;
   mu_HR_EFME_n = 0;
   mu_HR_EFME_MuonType = 0;
   mu_HR_EFME_pt = 0;
   mu_HR_EFME_eta = 0;
   mu_HR_EFME_phi = 0;
   mu_HR_EFME_hasME = 0;
   mu_HR_EFME_matched = 0;
   mu_HR_L2CB_dr = 0;
   mu_HR_L2CB_pt = 0;
   mu_HR_L2CB_eta = 0;
   mu_HR_L2CB_phi = 0;
   mu_HR_L2CB_id_pt = 0;
   mu_HR_L2CB_ms_pt = 0;
   mu_HR_L2CB_matched = 0;
   mu_HR_L1_dr = 0;
   mu_HR_L1_pt = 0;
   mu_HR_L1_eta = 0;
   mu_HR_L1_phi = 0;
   mu_HR_L1_matched = 0;
   jet_AntiKt4TopoEM_E = 0;
   jet_AntiKt4TopoEM_pt = 0;
   jet_AntiKt4TopoEM_m = 0;
   jet_AntiKt4TopoEM_eta = 0;
   jet_AntiKt4TopoEM_phi = 0;
   jet_AntiKt4TopoEM_n90 = 0;
   jet_AntiKt4TopoEM_Timing = 0;
   jet_AntiKt4TopoEM_LArQuality = 0;
   jet_AntiKt4TopoEM_sumPtTrk = 0;
   jet_AntiKt4TopoEM_HECQuality = 0;
   jet_AntiKt4TopoEM_BCH_CORR_CELL = 0;
   jet_AntiKt4TopoEM_BCH_CORR_DOTX = 0;
   jet_AntiKt4TopoEM_SamplingMax = 0;
   jet_AntiKt4TopoEM_fracSamplingMax = 0;
   jet_AntiKt4TopoEM_hecf = 0;
   jet_AntiKt4TopoEM_tgap3f = 0;
   jet_AntiKt4TopoEM_isBadLoose = 0;
   jet_AntiKt4TopoEM_isBadMedium = 0;
   jet_AntiKt4TopoEM_isBadTight = 0;
   jet_AntiKt4TopoEM_emfrac = 0;
   jet_AntiKt4TopoEM_EMJES = 0;
   jet_AntiKt4TopoEM_GCWJES = 0;
   jet_AntiKt4TopoEM_emscale_E = 0;
   jet_AntiKt4TopoEM_emscale_pt = 0;
   jet_AntiKt4TopoEM_emscale_m = 0;
   jet_AntiKt4TopoEM_emscale_eta = 0;
   jet_AntiKt4TopoEM_emscale_phi = 0;
   jet_AntiKt6TopoEM_E = 0;
   jet_AntiKt6TopoEM_pt = 0;
   jet_AntiKt6TopoEM_m = 0;
   jet_AntiKt6TopoEM_eta = 0;
   jet_AntiKt6TopoEM_phi = 0;
   jet_AntiKt6TopoEM_n90 = 0;
   jet_AntiKt6TopoEM_Timing = 0;
   jet_AntiKt6TopoEM_LArQuality = 0;
   jet_AntiKt6TopoEM_sumPtTrk = 0;
   jet_AntiKt6TopoEM_HECQuality = 0;
   jet_AntiKt6TopoEM_BCH_CORR_CELL = 0;
   jet_AntiKt6TopoEM_BCH_CORR_DOTX = 0;
   jet_AntiKt6TopoEM_SamplingMax = 0;
   jet_AntiKt6TopoEM_fracSamplingMax = 0;
   jet_AntiKt6TopoEM_hecf = 0;
   jet_AntiKt6TopoEM_tgap3f = 0;
   jet_AntiKt6TopoEM_isBadLoose = 0;
   jet_AntiKt6TopoEM_isBadMedium = 0;
   jet_AntiKt6TopoEM_isBadTight = 0;
   jet_AntiKt6TopoEM_emfrac = 0;
   jet_AntiKt6TopoEM_EMJES = 0;
   jet_AntiKt6TopoEM_GCWJES = 0;
   jet_AntiKt6TopoEM_emscale_E = 0;
   jet_AntiKt6TopoEM_emscale_pt = 0;
   jet_AntiKt6TopoEM_emscale_m = 0;
   jet_AntiKt6TopoEM_emscale_eta = 0;
   jet_AntiKt6TopoEM_emscale_phi = 0;
   jet_AntiKt6LCTopo_E = 0;
   jet_AntiKt6LCTopo_pt = 0;
   jet_AntiKt6LCTopo_m = 0;
   jet_AntiKt6LCTopo_eta = 0;
   jet_AntiKt6LCTopo_phi = 0;
   jet_AntiKt6LCTopo_n90 = 0;
   jet_AntiKt6LCTopo_Timing = 0;
   jet_AntiKt6LCTopo_LArQuality = 0;
   jet_AntiKt6LCTopo_sumPtTrk = 0;
   jet_AntiKt6LCTopo_HECQuality = 0;
   jet_AntiKt6LCTopo_BCH_CORR_CELL = 0;
   jet_AntiKt6LCTopo_BCH_CORR_DOTX = 0;
   jet_AntiKt6LCTopo_SamplingMax = 0;
   jet_AntiKt6LCTopo_fracSamplingMax = 0;
   jet_AntiKt6LCTopo_hecf = 0;
   jet_AntiKt6LCTopo_tgap3f = 0;
   jet_AntiKt6LCTopo_isBadLoose = 0;
   jet_AntiKt6LCTopo_isBadMedium = 0;
   jet_AntiKt6LCTopo_isBadTight = 0;
   jet_AntiKt6LCTopo_emfrac = 0;
   jet_AntiKt6LCTopo_EMJES = 0;
   jet_AntiKt6LCTopo_GCWJES = 0;
   jet_AntiKt6LCTopo_emscale_E = 0;
   jet_AntiKt6LCTopo_emscale_pt = 0;
   jet_AntiKt6LCTopo_emscale_m = 0;
   jet_AntiKt6LCTopo_emscale_eta = 0;
   jet_AntiKt6LCTopo_emscale_phi = 0;
   el_MET_wpx = 0;
   el_MET_wpy = 0;
   el_MET_wet = 0;
   el_MET_statusWord = 0;
   ph_MET_wpx = 0;
   ph_MET_wpy = 0;
   ph_MET_wet = 0;
   ph_MET_statusWord = 0;
   mu_staco_MET_wpx = 0;
   mu_staco_MET_wpy = 0;
   mu_staco_MET_wet = 0;
   mu_staco_MET_statusWord = 0;
   mu_muid_MET_wpx = 0;
   mu_muid_MET_wpy = 0;
   mu_muid_MET_wet = 0;
   mu_muid_MET_statusWord = 0;
   tau_MET_wpx = 0;
   tau_MET_wpy = 0;
   tau_MET_wet = 0;
   tau_MET_statusWord = 0;
   jet_AntiKt6LCTopo_MET_wpx = 0;
   jet_AntiKt6LCTopo_MET_wpy = 0;
   jet_AntiKt6LCTopo_MET_wet = 0;
   jet_AntiKt6LCTopo_MET_statusWord = 0;
   cl_MET_wpx = 0;
   cl_MET_wpy = 0;
   cl_MET_wet = 0;
   cl_MET_statusWord = 0;
   trk_MET_wpx = 0;
   trk_MET_wpy = 0;
   trk_MET_wet = 0;
   trk_MET_statusWord = 0;
   trig_L1_TAV = 0;
   trig_L2_passedPhysics = 0;
   trig_EF_passedPhysics = 0;
   trig_L1_TBP = 0;
   trig_L1_TAP = 0;
   trig_L2_passedRaw = 0;
   trig_EF_passedRaw = 0;
   trig_L2_resurrected = 0;
   trig_EF_resurrected = 0;
   trig_L2_passedThrough = 0;
   trig_EF_passedThrough = 0;
   mcevt_signal_process_id = 0;
   mcevt_event_number = 0;
   mcevt_event_scale = 0;
   mcevt_alphaQCD = 0;
   mcevt_alphaQED = 0;
   mcevt_pdf_id1 = 0;
   mcevt_pdf_id2 = 0;
   mcevt_pdf_x1 = 0;
   mcevt_pdf_x2 = 0;
   mcevt_pdf_scale = 0;
   mcevt_pdf1 = 0;
   mcevt_pdf2 = 0;
   mcevt_weight = 0;
   mc_pt = 0;
   mc_eta = 0;
   mc_phi = 0;
   mc_status = 0;
   mc_barcode = 0;
   mc_parents = 0;
   mc_children = 0;
   mc_pdgId = 0;
   AntiKt4TruthNew_E = 0;
   AntiKt4TruthNew_pt = 0;
   AntiKt4TruthNew_m = 0;
   AntiKt4TruthNew_eta = 0;
   AntiKt4TruthNew_phi = 0;
   AntiKt6TruthNew_E = 0;
   AntiKt6TruthNew_pt = 0;
   AntiKt6TruthNew_m = 0;
   AntiKt6TruthNew_eta = 0;
   AntiKt6TruthNew_phi = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("RunNumber", &RunNumber, &b_RunNumber);
   fChain->SetBranchAddress("EventNumber", &EventNumber, &b_EventNumber);
   fChain->SetBranchAddress("lbn", &lbn, &b_lbn);
   fChain->SetBranchAddress("bcid", &bcid, &b_bcid);
   fChain->SetBranchAddress("collcand_passCaloTime", &collcand_passCaloTime, &b_collcand_passCaloTime);
   fChain->SetBranchAddress("collcand_passMBTSTime", &collcand_passMBTSTime, &b_collcand_passMBTSTime);
   fChain->SetBranchAddress("collcand_passTrigger", &collcand_passTrigger, &b_collcand_passTrigger);
   fChain->SetBranchAddress("collcand_pass", &collcand_pass, &b_collcand_pass);
   fChain->SetBranchAddress("beamSpot_x", &beamSpot_x, &b_beamSpot_x);
   fChain->SetBranchAddress("beamSpot_y", &beamSpot_y, &b_beamSpot_y);
   fChain->SetBranchAddress("beamSpot_z", &beamSpot_z, &b_beamSpot_z);
   fChain->SetBranchAddress("vxp_n", &vxp_n, &b_vxp_n);
   fChain->SetBranchAddress("vxp_x", &vxp_x, &b_vxp_x);
   fChain->SetBranchAddress("vxp_y", &vxp_y, &b_vxp_y);
   fChain->SetBranchAddress("vxp_z", &vxp_z, &b_vxp_z);
   fChain->SetBranchAddress("vxp_cov_x", &vxp_cov_x, &b_vxp_cov_x);
   fChain->SetBranchAddress("vxp_cov_y", &vxp_cov_y, &b_vxp_cov_y);
   fChain->SetBranchAddress("vxp_cov_z", &vxp_cov_z, &b_vxp_cov_z);
   fChain->SetBranchAddress("vxp_cov_xy", &vxp_cov_xy, &b_vxp_cov_xy);
   fChain->SetBranchAddress("vxp_cov_xz", &vxp_cov_xz, &b_vxp_cov_xz);
   fChain->SetBranchAddress("vxp_cov_yz", &vxp_cov_yz, &b_vxp_cov_yz);
   fChain->SetBranchAddress("vxp_chi2", &vxp_chi2, &b_vxp_chi2);
   fChain->SetBranchAddress("vxp_ndof", &vxp_ndof, &b_vxp_ndof);
   fChain->SetBranchAddress("vxp_px", &vxp_px, &b_vxp_px);
   fChain->SetBranchAddress("vxp_py", &vxp_py, &b_vxp_py);
   fChain->SetBranchAddress("vxp_pz", &vxp_pz, &b_vxp_pz);
   fChain->SetBranchAddress("vxp_E", &vxp_E, &b_vxp_E);
   fChain->SetBranchAddress("vxp_m", &vxp_m, &b_vxp_m);
   fChain->SetBranchAddress("vxp_nTracks", &vxp_nTracks, &b_vxp_nTracks);
   fChain->SetBranchAddress("vxp_sumPt", &vxp_sumPt, &b_vxp_sumPt);
   fChain->SetBranchAddress("vxp_type", &vxp_type, &b_vxp_type);
   fChain->SetBranchAddress("vxp_trk_n", &vxp_trk_n, &b_vxp_trk_n);
   fChain->SetBranchAddress("vxp_trk_index", &vxp_trk_index, &b_vxp_trk_index);
   fChain->SetBranchAddress("el_n", &el_n, &b_el_n);
   fChain->SetBranchAddress("el_E", &el_E, &b_el_E);
   fChain->SetBranchAddress("el_Et", &el_Et, &b_el_Et);
   fChain->SetBranchAddress("el_pt", &el_pt, &b_el_pt);
   fChain->SetBranchAddress("el_m", &el_m, &b_el_m);
   fChain->SetBranchAddress("el_eta", &el_eta, &b_el_eta);
   fChain->SetBranchAddress("el_phi", &el_phi, &b_el_phi);
   fChain->SetBranchAddress("el_px", &el_px, &b_el_px);
   fChain->SetBranchAddress("el_py", &el_py, &b_el_py);
   fChain->SetBranchAddress("el_pz", &el_pz, &b_el_pz);
   fChain->SetBranchAddress("el_charge", &el_charge, &b_el_charge);
   fChain->SetBranchAddress("el_author", &el_author, &b_el_author);
   fChain->SetBranchAddress("el_isEM", &el_isEM, &b_el_isEM);
   fChain->SetBranchAddress("el_loose", &el_loose, &b_el_loose);
   fChain->SetBranchAddress("el_medium", &el_medium, &b_el_medium);
   fChain->SetBranchAddress("el_mediumIso", &el_mediumIso, &b_el_mediumIso);
   fChain->SetBranchAddress("el_tight", &el_tight, &b_el_tight);
   fChain->SetBranchAddress("el_tightIso", &el_tightIso, &b_el_tightIso);
   fChain->SetBranchAddress("el_Etcone45", &el_Etcone45, &b_el_Etcone45);
   fChain->SetBranchAddress("el_Etcone20", &el_Etcone20, &b_el_Etcone20);
   fChain->SetBranchAddress("el_Etcone30", &el_Etcone30, &b_el_Etcone30);
   fChain->SetBranchAddress("el_Etcone40", &el_Etcone40, &b_el_Etcone40);
   fChain->SetBranchAddress("el_Es2", &el_Es2, &b_el_Es2);
   fChain->SetBranchAddress("el_etas2", &el_etas2, &b_el_etas2);
   fChain->SetBranchAddress("el_phis2", &el_phis2, &b_el_phis2);
   fChain->SetBranchAddress("el_cl_E", &el_cl_E, &b_el_cl_E);
   fChain->SetBranchAddress("el_cl_pt", &el_cl_pt, &b_el_cl_pt);
   fChain->SetBranchAddress("el_cl_eta", &el_cl_eta, &b_el_cl_eta);
   fChain->SetBranchAddress("el_cl_phi", &el_cl_phi, &b_el_cl_phi);
   fChain->SetBranchAddress("el_trackd0", &el_trackd0, &b_el_trackd0);
   fChain->SetBranchAddress("el_trackz0", &el_trackz0, &b_el_trackz0);
   fChain->SetBranchAddress("el_trackphi", &el_trackphi, &b_el_trackphi);
   fChain->SetBranchAddress("el_tracktheta", &el_tracktheta, &b_el_tracktheta);
   fChain->SetBranchAddress("el_trackqoverp", &el_trackqoverp, &b_el_trackqoverp);
   fChain->SetBranchAddress("el_trackpt", &el_trackpt, &b_el_trackpt);
   fChain->SetBranchAddress("el_tracketa", &el_tracketa, &b_el_tracketa);
   fChain->SetBranchAddress("el_vertx", &el_vertx, &b_el_vertx);
   fChain->SetBranchAddress("el_verty", &el_verty, &b_el_verty);
   fChain->SetBranchAddress("el_vertz", &el_vertz, &b_el_vertz);
   fChain->SetBranchAddress("EF_e10_NoCut", &EF_e10_NoCut, &b_EF_e10_NoCut);
   fChain->SetBranchAddress("EF_e10_loose", &EF_e10_loose, &b_EF_e10_loose);
   fChain->SetBranchAddress("EF_e10_loose_mu10", &EF_e10_loose_mu10, &b_EF_e10_loose_mu10);
   fChain->SetBranchAddress("EF_e10_loose_mu6", &EF_e10_loose_mu6, &b_EF_e10_loose_mu6);
   fChain->SetBranchAddress("EF_e10_medium", &EF_e10_medium, &b_EF_e10_medium);
   fChain->SetBranchAddress("EF_e10_medium_IDTrkNoCut", &EF_e10_medium_IDTrkNoCut, &b_EF_e10_medium_IDTrkNoCut);
   fChain->SetBranchAddress("EF_e10_medium_SiTrk", &EF_e10_medium_SiTrk, &b_EF_e10_medium_SiTrk);
   fChain->SetBranchAddress("EF_e10_medium_TRT", &EF_e10_medium_TRT, &b_EF_e10_medium_TRT);
   fChain->SetBranchAddress("EF_e10_tight", &EF_e10_tight, &b_EF_e10_tight);
   fChain->SetBranchAddress("EF_e10_tight_TRT", &EF_e10_tight_TRT, &b_EF_e10_tight_TRT);
   fChain->SetBranchAddress("EF_e15_loose", &EF_e15_loose, &b_EF_e15_loose);
   fChain->SetBranchAddress("EF_e15_loose_IDTrkNoCut", &EF_e15_loose_IDTrkNoCut, &b_EF_e15_loose_IDTrkNoCut);
   fChain->SetBranchAddress("EF_e15_medium", &EF_e15_medium, &b_EF_e15_medium);
   fChain->SetBranchAddress("EF_e15_medium_SiTrk", &EF_e15_medium_SiTrk, &b_EF_e15_medium_SiTrk);
   fChain->SetBranchAddress("EF_e15_medium_TRT", &EF_e15_medium_TRT, &b_EF_e15_medium_TRT);
   fChain->SetBranchAddress("EF_e15_tight", &EF_e15_tight, &b_EF_e15_tight);
   fChain->SetBranchAddress("EF_e15_tight_TRT", &EF_e15_tight_TRT, &b_EF_e15_tight_TRT);
   fChain->SetBranchAddress("EF_e20_loose", &EF_e20_loose, &b_EF_e20_loose);
   fChain->SetBranchAddress("EF_e20_loose_IDTrkNoCut", &EF_e20_loose_IDTrkNoCut, &b_EF_e20_loose_IDTrkNoCut);
   fChain->SetBranchAddress("EF_e20_loose_TRT", &EF_e20_loose_TRT, &b_EF_e20_loose_TRT);
   fChain->SetBranchAddress("EF_e20_loose_passEF", &EF_e20_loose_passEF, &b_EF_e20_loose_passEF);
   fChain->SetBranchAddress("EF_e20_loose_passL2", &EF_e20_loose_passL2, &b_EF_e20_loose_passL2);
   fChain->SetBranchAddress("EF_e20_loose_xe20", &EF_e20_loose_xe20, &b_EF_e20_loose_xe20);
   fChain->SetBranchAddress("EF_e20_loose_xe20_noMu", &EF_e20_loose_xe20_noMu, &b_EF_e20_loose_xe20_noMu);
   fChain->SetBranchAddress("EF_e20_loose_xe30", &EF_e20_loose_xe30, &b_EF_e20_loose_xe30);
   fChain->SetBranchAddress("EF_e20_loose_xe30_noMu", &EF_e20_loose_xe30_noMu, &b_EF_e20_loose_xe30_noMu);
   fChain->SetBranchAddress("EF_e20_medium", &EF_e20_medium, &b_EF_e20_medium);
   fChain->SetBranchAddress("EF_mu10", &EF_mu10, &b_EF_mu10);
   fChain->SetBranchAddress("EF_mu10_Ecut12", &EF_mu10_Ecut12, &b_EF_mu10_Ecut12);
   fChain->SetBranchAddress("EF_mu10_Ecut123", &EF_mu10_Ecut123, &b_EF_mu10_Ecut123);
   fChain->SetBranchAddress("EF_mu10_Ecut13", &EF_mu10_Ecut13, &b_EF_mu10_Ecut13);
   fChain->SetBranchAddress("EF_mu10_IDTrkNoCut", &EF_mu10_IDTrkNoCut, &b_EF_mu10_IDTrkNoCut);
   fChain->SetBranchAddress("EF_mu10_MG", &EF_mu10_MG, &b_EF_mu10_MG);
   fChain->SetBranchAddress("EF_mu10_MSonly", &EF_mu10_MSonly, &b_EF_mu10_MSonly);
   fChain->SetBranchAddress("EF_mu10_MSonly_Ecut12", &EF_mu10_MSonly_Ecut12, &b_EF_mu10_MSonly_Ecut12);
   fChain->SetBranchAddress("EF_mu10_MSonly_Ecut123", &EF_mu10_MSonly_Ecut123, &b_EF_mu10_MSonly_Ecut123);
   fChain->SetBranchAddress("EF_mu10_MSonly_Ecut13", &EF_mu10_MSonly_Ecut13, &b_EF_mu10_MSonly_Ecut13);
   fChain->SetBranchAddress("EF_mu10_MSonly_tight", &EF_mu10_MSonly_tight, &b_EF_mu10_MSonly_tight);
   fChain->SetBranchAddress("EF_mu10_NoAlg", &EF_mu10_NoAlg, &b_EF_mu10_NoAlg);
   fChain->SetBranchAddress("EF_mu10_SiTrk", &EF_mu10_SiTrk, &b_EF_mu10_SiTrk);
   fChain->SetBranchAddress("EF_mu10_j30", &EF_mu10_j30, &b_EF_mu10_j30);
   fChain->SetBranchAddress("EF_mu10_tight", &EF_mu10_tight, &b_EF_mu10_tight);
   fChain->SetBranchAddress("EF_mu10i_loose", &EF_mu10i_loose, &b_EF_mu10i_loose);
   fChain->SetBranchAddress("EF_mu13", &EF_mu13, &b_EF_mu13);
   fChain->SetBranchAddress("EF_mu13_MG", &EF_mu13_MG, &b_EF_mu13_MG);
   fChain->SetBranchAddress("EF_mu13_MG_tight", &EF_mu13_MG_tight, &b_EF_mu13_MG_tight);
   fChain->SetBranchAddress("EF_mu13_tight", &EF_mu13_tight, &b_EF_mu13_tight);
   fChain->SetBranchAddress("EF_mu15", &EF_mu15, &b_EF_mu15);
   fChain->SetBranchAddress("EF_mu15_MG", &EF_mu15_MG, &b_EF_mu15_MG);
   fChain->SetBranchAddress("EF_mu15_NoAlg", &EF_mu15_NoAlg, &b_EF_mu15_NoAlg);
   fChain->SetBranchAddress("L1_2J15_XE10", &L1_2J15_XE10, &b_L1_2J15_XE10);
   fChain->SetBranchAddress("L1_2J15_XE15", &L1_2J15_XE15, &b_L1_2J15_XE15);
   fChain->SetBranchAddress("L1_2J15_XE25", &L1_2J15_XE25, &b_L1_2J15_XE25);
   fChain->SetBranchAddress("L1_EM10", &L1_EM10, &b_L1_EM10);
   fChain->SetBranchAddress("L1_EM10I", &L1_EM10I, &b_L1_EM10I);
   fChain->SetBranchAddress("L1_EM14", &L1_EM14, &b_L1_EM14);
   fChain->SetBranchAddress("L1_EM14I", &L1_EM14I, &b_L1_EM14I);
   fChain->SetBranchAddress("L1_EM14_XE10", &L1_EM14_XE10, &b_L1_EM14_XE10);
   fChain->SetBranchAddress("L1_EM14_XE15", &L1_EM14_XE15, &b_L1_EM14_XE15);
   fChain->SetBranchAddress("L1_J15_XE15_EM10", &L1_J15_XE15_EM10, &b_L1_J15_XE15_EM10);
   fChain->SetBranchAddress("L1_J15_XE15_MU15", &L1_J15_XE15_MU15, &b_L1_J15_XE15_MU15);
   fChain->SetBranchAddress("L1_J30_XE10", &L1_J30_XE10, &b_L1_J30_XE10);
   fChain->SetBranchAddress("L1_J30_XE15", &L1_J30_XE15, &b_L1_J30_XE15);
   fChain->SetBranchAddress("L1_J30_XE25", &L1_J30_XE25, &b_L1_J30_XE25);
   fChain->SetBranchAddress("L1_MU10", &L1_MU10, &b_L1_MU10);
   fChain->SetBranchAddress("L1_MU15", &L1_MU15, &b_L1_MU15);
   fChain->SetBranchAddress("L1_MU20", &L1_MU20, &b_L1_MU20);
   fChain->SetBranchAddress("L1_MU6", &L1_MU6, &b_L1_MU6);
   fChain->SetBranchAddress("L1_XE10", &L1_XE10, &b_L1_XE10);
   fChain->SetBranchAddress("L1_XE15", &L1_XE15, &b_L1_XE15);
   fChain->SetBranchAddress("L1_XE20", &L1_XE20, &b_L1_XE20);
   fChain->SetBranchAddress("L1_XE25", &L1_XE25, &b_L1_XE25);
   fChain->SetBranchAddress("L1_XE30", &L1_XE30, &b_L1_XE30);
   fChain->SetBranchAddress("L1_XE35", &L1_XE35, &b_L1_XE35);
   fChain->SetBranchAddress("L1_XE40", &L1_XE40, &b_L1_XE40);
   fChain->SetBranchAddress("L1_XE50", &L1_XE50, &b_L1_XE50);
   fChain->SetBranchAddress("mu_staco_n", &mu_staco_n, &b_mu_staco_n);
   fChain->SetBranchAddress("mu_staco_E", &mu_staco_E, &b_mu_staco_E);
   fChain->SetBranchAddress("mu_staco_pt", &mu_staco_pt, &b_mu_staco_pt);
   fChain->SetBranchAddress("mu_staco_m", &mu_staco_m, &b_mu_staco_m);
   fChain->SetBranchAddress("mu_staco_eta", &mu_staco_eta, &b_mu_staco_eta);
   fChain->SetBranchAddress("mu_staco_phi", &mu_staco_phi, &b_mu_staco_phi);
   fChain->SetBranchAddress("mu_staco_px", &mu_staco_px, &b_mu_staco_px);
   fChain->SetBranchAddress("mu_staco_py", &mu_staco_py, &b_mu_staco_py);
   fChain->SetBranchAddress("mu_staco_pz", &mu_staco_pz, &b_mu_staco_pz);
   fChain->SetBranchAddress("mu_staco_charge", &mu_staco_charge, &b_mu_staco_charge);
   fChain->SetBranchAddress("mu_staco_allauthor", &mu_staco_allauthor, &b_mu_staco_allauthor);
   fChain->SetBranchAddress("mu_staco_author", &mu_staco_author, &b_mu_staco_author);
   fChain->SetBranchAddress("mu_staco_beta", &mu_staco_beta, &b_mu_staco_beta);
   fChain->SetBranchAddress("mu_staco_isMuonLikelihood", &mu_staco_isMuonLikelihood, &b_mu_staco_isMuonLikelihood);
   fChain->SetBranchAddress("mu_staco_matchchi2", &mu_staco_matchchi2, &b_mu_staco_matchchi2);
   fChain->SetBranchAddress("mu_staco_matchndof", &mu_staco_matchndof, &b_mu_staco_matchndof);
   fChain->SetBranchAddress("mu_staco_etcone20", &mu_staco_etcone20, &b_mu_staco_etcone20);
   fChain->SetBranchAddress("mu_staco_etcone30", &mu_staco_etcone30, &b_mu_staco_etcone30);
   fChain->SetBranchAddress("mu_staco_etcone40", &mu_staco_etcone40, &b_mu_staco_etcone40);
   fChain->SetBranchAddress("mu_staco_nucone20", &mu_staco_nucone20, &b_mu_staco_nucone20);
   fChain->SetBranchAddress("mu_staco_nucone30", &mu_staco_nucone30, &b_mu_staco_nucone30);
   fChain->SetBranchAddress("mu_staco_nucone40", &mu_staco_nucone40, &b_mu_staco_nucone40);
   fChain->SetBranchAddress("mu_staco_ptcone20", &mu_staco_ptcone20, &b_mu_staco_ptcone20);
   fChain->SetBranchAddress("mu_staco_ptcone30", &mu_staco_ptcone30, &b_mu_staco_ptcone30);
   fChain->SetBranchAddress("mu_staco_ptcone40", &mu_staco_ptcone40, &b_mu_staco_ptcone40);
   fChain->SetBranchAddress("mu_staco_energyLossPar", &mu_staco_energyLossPar, &b_mu_staco_energyLossPar);
   fChain->SetBranchAddress("mu_staco_energyLossErr", &mu_staco_energyLossErr, &b_mu_staco_energyLossErr);
   fChain->SetBranchAddress("mu_staco_etCore", &mu_staco_etCore, &b_mu_staco_etCore);
   fChain->SetBranchAddress("mu_staco_energyLossType", &mu_staco_energyLossType, &b_mu_staco_energyLossType);
   fChain->SetBranchAddress("mu_staco_caloMuonIdTag", &mu_staco_caloMuonIdTag, &b_mu_staco_caloMuonIdTag);
   fChain->SetBranchAddress("mu_staco_caloLRLikelihood", &mu_staco_caloLRLikelihood, &b_mu_staco_caloLRLikelihood);
   fChain->SetBranchAddress("mu_staco_bestMatch", &mu_staco_bestMatch, &b_mu_staco_bestMatch);
   fChain->SetBranchAddress("mu_staco_isStandAloneMuon", &mu_staco_isStandAloneMuon, &b_mu_staco_isStandAloneMuon);
   fChain->SetBranchAddress("mu_staco_isCombinedMuon", &mu_staco_isCombinedMuon, &b_mu_staco_isCombinedMuon);
   fChain->SetBranchAddress("mu_staco_isLowPtReconstructedMuon", &mu_staco_isLowPtReconstructedMuon, &b_mu_staco_isLowPtReconstructedMuon);
   fChain->SetBranchAddress("mu_staco_loose", &mu_staco_loose, &b_mu_staco_loose);
   fChain->SetBranchAddress("mu_staco_medium", &mu_staco_medium, &b_mu_staco_medium);
   fChain->SetBranchAddress("mu_staco_tight", &mu_staco_tight, &b_mu_staco_tight);
   fChain->SetBranchAddress("mu_staco_d0_exPV", &mu_staco_d0_exPV, &b_mu_staco_d0_exPV);
   fChain->SetBranchAddress("mu_staco_z0_exPV", &mu_staco_z0_exPV, &b_mu_staco_z0_exPV);
   fChain->SetBranchAddress("mu_staco_phi_exPV", &mu_staco_phi_exPV, &b_mu_staco_phi_exPV);
   fChain->SetBranchAddress("mu_staco_theta_exPV", &mu_staco_theta_exPV, &b_mu_staco_theta_exPV);
   fChain->SetBranchAddress("mu_staco_qoverp_exPV", &mu_staco_qoverp_exPV, &b_mu_staco_qoverp_exPV);
   fChain->SetBranchAddress("mu_staco_cb_d0_exPV", &mu_staco_cb_d0_exPV, &b_mu_staco_cb_d0_exPV);
   fChain->SetBranchAddress("mu_staco_cb_z0_exPV", &mu_staco_cb_z0_exPV, &b_mu_staco_cb_z0_exPV);
   fChain->SetBranchAddress("mu_staco_cb_phi_exPV", &mu_staco_cb_phi_exPV, &b_mu_staco_cb_phi_exPV);
   fChain->SetBranchAddress("mu_staco_cb_theta_exPV", &mu_staco_cb_theta_exPV, &b_mu_staco_cb_theta_exPV);
   fChain->SetBranchAddress("mu_staco_cb_qoverp_exPV", &mu_staco_cb_qoverp_exPV, &b_mu_staco_cb_qoverp_exPV);
   fChain->SetBranchAddress("mu_staco_id_d0_exPV", &mu_staco_id_d0_exPV, &b_mu_staco_id_d0_exPV);
   fChain->SetBranchAddress("mu_staco_id_z0_exPV", &mu_staco_id_z0_exPV, &b_mu_staco_id_z0_exPV);
   fChain->SetBranchAddress("mu_staco_id_phi_exPV", &mu_staco_id_phi_exPV, &b_mu_staco_id_phi_exPV);
   fChain->SetBranchAddress("mu_staco_id_theta_exPV", &mu_staco_id_theta_exPV, &b_mu_staco_id_theta_exPV);
   fChain->SetBranchAddress("mu_staco_id_qoverp_exPV", &mu_staco_id_qoverp_exPV, &b_mu_staco_id_qoverp_exPV);
   fChain->SetBranchAddress("mu_staco_me_d0_exPV", &mu_staco_me_d0_exPV, &b_mu_staco_me_d0_exPV);
   fChain->SetBranchAddress("mu_staco_me_z0_exPV", &mu_staco_me_z0_exPV, &b_mu_staco_me_z0_exPV);
   fChain->SetBranchAddress("mu_staco_me_phi_exPV", &mu_staco_me_phi_exPV, &b_mu_staco_me_phi_exPV);
   fChain->SetBranchAddress("mu_staco_me_theta_exPV", &mu_staco_me_theta_exPV, &b_mu_staco_me_theta_exPV);
   fChain->SetBranchAddress("mu_staco_me_qoverp_exPV", &mu_staco_me_qoverp_exPV, &b_mu_staco_me_qoverp_exPV);
   fChain->SetBranchAddress("mu_staco_ie_d0_exPV", &mu_staco_ie_d0_exPV, &b_mu_staco_ie_d0_exPV);
   fChain->SetBranchAddress("mu_staco_ie_z0_exPV", &mu_staco_ie_z0_exPV, &b_mu_staco_ie_z0_exPV);
   fChain->SetBranchAddress("mu_staco_ie_phi_exPV", &mu_staco_ie_phi_exPV, &b_mu_staco_ie_phi_exPV);
   fChain->SetBranchAddress("mu_staco_ie_theta_exPV", &mu_staco_ie_theta_exPV, &b_mu_staco_ie_theta_exPV);
   fChain->SetBranchAddress("mu_staco_ie_qoverp_exPV", &mu_staco_ie_qoverp_exPV, &b_mu_staco_ie_qoverp_exPV);
   fChain->SetBranchAddress("mu_staco_SpaceTime_detID", &mu_staco_SpaceTime_detID, &b_mu_staco_SpaceTime_detID);
   fChain->SetBranchAddress("mu_staco_SpaceTime_t", &mu_staco_SpaceTime_t, &b_mu_staco_SpaceTime_t);
   fChain->SetBranchAddress("mu_staco_SpaceTime_tError", &mu_staco_SpaceTime_tError, &b_mu_staco_SpaceTime_tError);
   fChain->SetBranchAddress("mu_staco_SpaceTime_weight", &mu_staco_SpaceTime_weight, &b_mu_staco_SpaceTime_weight);
   fChain->SetBranchAddress("mu_staco_SpaceTime_x", &mu_staco_SpaceTime_x, &b_mu_staco_SpaceTime_x);
   fChain->SetBranchAddress("mu_staco_SpaceTime_y", &mu_staco_SpaceTime_y, &b_mu_staco_SpaceTime_y);
   fChain->SetBranchAddress("mu_staco_SpaceTime_z", &mu_staco_SpaceTime_z, &b_mu_staco_SpaceTime_z);
   fChain->SetBranchAddress("mu_staco_SpaceTime_t_Tile", &mu_staco_SpaceTime_t_Tile, &b_mu_staco_SpaceTime_t_Tile);
   fChain->SetBranchAddress("mu_staco_SpaceTime_tError_Tile", &mu_staco_SpaceTime_tError_Tile, &b_mu_staco_SpaceTime_tError_Tile);
   fChain->SetBranchAddress("mu_staco_SpaceTime_weight_Tile", &mu_staco_SpaceTime_weight_Tile, &b_mu_staco_SpaceTime_weight_Tile);
   fChain->SetBranchAddress("mu_staco_SpaceTime_x_Tile", &mu_staco_SpaceTime_x_Tile, &b_mu_staco_SpaceTime_x_Tile);
   fChain->SetBranchAddress("mu_staco_SpaceTime_y_Tile", &mu_staco_SpaceTime_y_Tile, &b_mu_staco_SpaceTime_y_Tile);
   fChain->SetBranchAddress("mu_staco_SpaceTime_z_Tile", &mu_staco_SpaceTime_z_Tile, &b_mu_staco_SpaceTime_z_Tile);
   fChain->SetBranchAddress("mu_staco_SpaceTime_t_TRT", &mu_staco_SpaceTime_t_TRT, &b_mu_staco_SpaceTime_t_TRT);
   fChain->SetBranchAddress("mu_staco_SpaceTime_tError_TRT", &mu_staco_SpaceTime_tError_TRT, &b_mu_staco_SpaceTime_tError_TRT);
   fChain->SetBranchAddress("mu_staco_SpaceTime_weight_TRT", &mu_staco_SpaceTime_weight_TRT, &b_mu_staco_SpaceTime_weight_TRT);
   fChain->SetBranchAddress("mu_staco_SpaceTime_x_TRT", &mu_staco_SpaceTime_x_TRT, &b_mu_staco_SpaceTime_x_TRT);
   fChain->SetBranchAddress("mu_staco_SpaceTime_y_TRT", &mu_staco_SpaceTime_y_TRT, &b_mu_staco_SpaceTime_y_TRT);
   fChain->SetBranchAddress("mu_staco_SpaceTime_z_TRT", &mu_staco_SpaceTime_z_TRT, &b_mu_staco_SpaceTime_z_TRT);
   fChain->SetBranchAddress("mu_staco_SpaceTime_t_MDT", &mu_staco_SpaceTime_t_MDT, &b_mu_staco_SpaceTime_t_MDT);
   fChain->SetBranchAddress("mu_staco_SpaceTime_tError_MDT", &mu_staco_SpaceTime_tError_MDT, &b_mu_staco_SpaceTime_tError_MDT);
   fChain->SetBranchAddress("mu_staco_SpaceTime_weight_MDT", &mu_staco_SpaceTime_weight_MDT, &b_mu_staco_SpaceTime_weight_MDT);
   fChain->SetBranchAddress("mu_staco_SpaceTime_x_MDT", &mu_staco_SpaceTime_x_MDT, &b_mu_staco_SpaceTime_x_MDT);
   fChain->SetBranchAddress("mu_staco_SpaceTime_y_MDT", &mu_staco_SpaceTime_y_MDT, &b_mu_staco_SpaceTime_y_MDT);
   fChain->SetBranchAddress("mu_staco_SpaceTime_z_MDT", &mu_staco_SpaceTime_z_MDT, &b_mu_staco_SpaceTime_z_MDT);
   fChain->SetBranchAddress("mu_staco_TileCellEnergyLayer1", &mu_staco_TileCellEnergyLayer1, &b_mu_staco_TileCellEnergyLayer1);
   fChain->SetBranchAddress("mu_staco_TileTimeLayer1", &mu_staco_TileTimeLayer1, &b_mu_staco_TileTimeLayer1);
   fChain->SetBranchAddress("mu_staco_TileCellRmsNoiseLayer1", &mu_staco_TileCellRmsNoiseLayer1, &b_mu_staco_TileCellRmsNoiseLayer1);
   fChain->SetBranchAddress("mu_staco_TileCellSignLayer1", &mu_staco_TileCellSignLayer1, &b_mu_staco_TileCellSignLayer1);
   fChain->SetBranchAddress("mu_staco_TileCellEnergyLayer2", &mu_staco_TileCellEnergyLayer2, &b_mu_staco_TileCellEnergyLayer2);
   fChain->SetBranchAddress("mu_staco_TileTimeLayer2", &mu_staco_TileTimeLayer2, &b_mu_staco_TileTimeLayer2);
   fChain->SetBranchAddress("mu_staco_TileCellRmsNoiseLayer2", &mu_staco_TileCellRmsNoiseLayer2, &b_mu_staco_TileCellRmsNoiseLayer2);
   fChain->SetBranchAddress("mu_staco_TileCellSignLayer2", &mu_staco_TileCellSignLayer2, &b_mu_staco_TileCellSignLayer2);
   fChain->SetBranchAddress("mu_staco_TileCellEnergyLayer3", &mu_staco_TileCellEnergyLayer3, &b_mu_staco_TileCellEnergyLayer3);
   fChain->SetBranchAddress("mu_staco_TileTimeLayer3", &mu_staco_TileTimeLayer3, &b_mu_staco_TileTimeLayer3);
   fChain->SetBranchAddress("mu_staco_TileCellRmsNoiseLayer3", &mu_staco_TileCellRmsNoiseLayer3, &b_mu_staco_TileCellRmsNoiseLayer3);
   fChain->SetBranchAddress("mu_staco_TileCellSignLayer3", &mu_staco_TileCellSignLayer3, &b_mu_staco_TileCellSignLayer3);
   fChain->SetBranchAddress("mu_staco_MSTrkT0_1", &mu_staco_MSTrkT0_1, &b_mu_staco_MSTrkT0_1);
   fChain->SetBranchAddress("mu_staco_MSTrkT0_2", &mu_staco_MSTrkT0_2, &b_mu_staco_MSTrkT0_2);
   fChain->SetBranchAddress("mu_staco_MSTrkT0_3", &mu_staco_MSTrkT0_3, &b_mu_staco_MSTrkT0_3);
   fChain->SetBranchAddress("mu_staco_cov_d0_exPV", &mu_staco_cov_d0_exPV, &b_mu_staco_cov_d0_exPV);
   fChain->SetBranchAddress("mu_staco_cov_z0_exPV", &mu_staco_cov_z0_exPV, &b_mu_staco_cov_z0_exPV);
   fChain->SetBranchAddress("mu_staco_cov_phi_exPV", &mu_staco_cov_phi_exPV, &b_mu_staco_cov_phi_exPV);
   fChain->SetBranchAddress("mu_staco_cov_theta_exPV", &mu_staco_cov_theta_exPV, &b_mu_staco_cov_theta_exPV);
   fChain->SetBranchAddress("mu_staco_cov_qoverp_exPV", &mu_staco_cov_qoverp_exPV, &b_mu_staco_cov_qoverp_exPV);
   fChain->SetBranchAddress("mu_staco_cov_d0_z0_exPV", &mu_staco_cov_d0_z0_exPV, &b_mu_staco_cov_d0_z0_exPV);
   fChain->SetBranchAddress("mu_staco_cov_d0_phi_exPV", &mu_staco_cov_d0_phi_exPV, &b_mu_staco_cov_d0_phi_exPV);
   fChain->SetBranchAddress("mu_staco_cov_d0_theta_exPV", &mu_staco_cov_d0_theta_exPV, &b_mu_staco_cov_d0_theta_exPV);
   fChain->SetBranchAddress("mu_staco_cov_d0_qoverp_exPV", &mu_staco_cov_d0_qoverp_exPV, &b_mu_staco_cov_d0_qoverp_exPV);
   fChain->SetBranchAddress("mu_staco_cov_z0_phi_exPV", &mu_staco_cov_z0_phi_exPV, &b_mu_staco_cov_z0_phi_exPV);
   fChain->SetBranchAddress("mu_staco_cov_z0_theta_exPV", &mu_staco_cov_z0_theta_exPV, &b_mu_staco_cov_z0_theta_exPV);
   fChain->SetBranchAddress("mu_staco_cov_z0_qoverp_exPV", &mu_staco_cov_z0_qoverp_exPV, &b_mu_staco_cov_z0_qoverp_exPV);
   fChain->SetBranchAddress("mu_staco_cov_phi_theta_exPV", &mu_staco_cov_phi_theta_exPV, &b_mu_staco_cov_phi_theta_exPV);
   fChain->SetBranchAddress("mu_staco_cov_phi_qoverp_exPV", &mu_staco_cov_phi_qoverp_exPV, &b_mu_staco_cov_phi_qoverp_exPV);
   fChain->SetBranchAddress("mu_staco_cov_theta_qoverp_exPV", &mu_staco_cov_theta_qoverp_exPV, &b_mu_staco_cov_theta_qoverp_exPV);
   fChain->SetBranchAddress("mu_staco_id_cov_d0_exPV", &mu_staco_id_cov_d0_exPV, &b_mu_staco_id_cov_d0_exPV);
   fChain->SetBranchAddress("mu_staco_id_cov_z0_exPV", &mu_staco_id_cov_z0_exPV, &b_mu_staco_id_cov_z0_exPV);
   fChain->SetBranchAddress("mu_staco_id_cov_phi_exPV", &mu_staco_id_cov_phi_exPV, &b_mu_staco_id_cov_phi_exPV);
   fChain->SetBranchAddress("mu_staco_id_cov_theta_exPV", &mu_staco_id_cov_theta_exPV, &b_mu_staco_id_cov_theta_exPV);
   fChain->SetBranchAddress("mu_staco_id_cov_qoverp_exPV", &mu_staco_id_cov_qoverp_exPV, &b_mu_staco_id_cov_qoverp_exPV);
   fChain->SetBranchAddress("mu_staco_me_cov_d0_exPV", &mu_staco_me_cov_d0_exPV, &b_mu_staco_me_cov_d0_exPV);
   fChain->SetBranchAddress("mu_staco_me_cov_z0_exPV", &mu_staco_me_cov_z0_exPV, &b_mu_staco_me_cov_z0_exPV);
   fChain->SetBranchAddress("mu_staco_me_cov_phi_exPV", &mu_staco_me_cov_phi_exPV, &b_mu_staco_me_cov_phi_exPV);
   fChain->SetBranchAddress("mu_staco_me_cov_theta_exPV", &mu_staco_me_cov_theta_exPV, &b_mu_staco_me_cov_theta_exPV);
   fChain->SetBranchAddress("mu_staco_me_cov_qoverp_exPV", &mu_staco_me_cov_qoverp_exPV, &b_mu_staco_me_cov_qoverp_exPV);
   fChain->SetBranchAddress("mu_staco_ms_d0", &mu_staco_ms_d0, &b_mu_staco_ms_d0);
   fChain->SetBranchAddress("mu_staco_ms_z0", &mu_staco_ms_z0, &b_mu_staco_ms_z0);
   fChain->SetBranchAddress("mu_staco_ms_phi", &mu_staco_ms_phi, &b_mu_staco_ms_phi);
   fChain->SetBranchAddress("mu_staco_ms_theta", &mu_staco_ms_theta, &b_mu_staco_ms_theta);
   fChain->SetBranchAddress("mu_staco_ms_qoverp", &mu_staco_ms_qoverp, &b_mu_staco_ms_qoverp);
   fChain->SetBranchAddress("mu_staco_id_d0", &mu_staco_id_d0, &b_mu_staco_id_d0);
   fChain->SetBranchAddress("mu_staco_id_z0", &mu_staco_id_z0, &b_mu_staco_id_z0);
   fChain->SetBranchAddress("mu_staco_id_phi", &mu_staco_id_phi, &b_mu_staco_id_phi);
   fChain->SetBranchAddress("mu_staco_id_theta", &mu_staco_id_theta, &b_mu_staco_id_theta);
   fChain->SetBranchAddress("mu_staco_id_qoverp", &mu_staco_id_qoverp, &b_mu_staco_id_qoverp);
   fChain->SetBranchAddress("mu_staco_me_d0", &mu_staco_me_d0, &b_mu_staco_me_d0);
   fChain->SetBranchAddress("mu_staco_me_z0", &mu_staco_me_z0, &b_mu_staco_me_z0);
   fChain->SetBranchAddress("mu_staco_me_phi", &mu_staco_me_phi, &b_mu_staco_me_phi);
   fChain->SetBranchAddress("mu_staco_me_theta", &mu_staco_me_theta, &b_mu_staco_me_theta);
   fChain->SetBranchAddress("mu_staco_me_qoverp", &mu_staco_me_qoverp, &b_mu_staco_me_qoverp);
   fChain->SetBranchAddress("mu_staco_ie_d0", &mu_staco_ie_d0, &b_mu_staco_ie_d0);
   fChain->SetBranchAddress("mu_staco_ie_z0", &mu_staco_ie_z0, &b_mu_staco_ie_z0);
   fChain->SetBranchAddress("mu_staco_ie_phi", &mu_staco_ie_phi, &b_mu_staco_ie_phi);
   fChain->SetBranchAddress("mu_staco_ie_theta", &mu_staco_ie_theta, &b_mu_staco_ie_theta);
   fChain->SetBranchAddress("mu_staco_ie_qoverp", &mu_staco_ie_qoverp, &b_mu_staco_ie_qoverp);
   fChain->SetBranchAddress("mu_staco_nOutliersOnTrack", &mu_staco_nOutliersOnTrack, &b_mu_staco_nOutliersOnTrack);
   fChain->SetBranchAddress("mu_staco_nBLHits", &mu_staco_nBLHits, &b_mu_staco_nBLHits);
   fChain->SetBranchAddress("mu_staco_nPixHits", &mu_staco_nPixHits, &b_mu_staco_nPixHits);
   fChain->SetBranchAddress("mu_staco_nSCTHits", &mu_staco_nSCTHits, &b_mu_staco_nSCTHits);
   fChain->SetBranchAddress("mu_staco_nTRTHits", &mu_staco_nTRTHits, &b_mu_staco_nTRTHits);
   fChain->SetBranchAddress("mu_staco_nTRTHighTHits", &mu_staco_nTRTHighTHits, &b_mu_staco_nTRTHighTHits);
   fChain->SetBranchAddress("mu_staco_nBLSharedHits", &mu_staco_nBLSharedHits, &b_mu_staco_nBLSharedHits);
   fChain->SetBranchAddress("mu_staco_nPixSharedHits", &mu_staco_nPixSharedHits, &b_mu_staco_nPixSharedHits);
   fChain->SetBranchAddress("mu_staco_nPixHoles", &mu_staco_nPixHoles, &b_mu_staco_nPixHoles);
   fChain->SetBranchAddress("mu_staco_nSCTSharedHits", &mu_staco_nSCTSharedHits, &b_mu_staco_nSCTSharedHits);
   fChain->SetBranchAddress("mu_staco_nSCTHoles", &mu_staco_nSCTHoles, &b_mu_staco_nSCTHoles);
   fChain->SetBranchAddress("mu_staco_nTRTOutliers", &mu_staco_nTRTOutliers, &b_mu_staco_nTRTOutliers);
   fChain->SetBranchAddress("mu_staco_nTRTHighTOutliers", &mu_staco_nTRTHighTOutliers, &b_mu_staco_nTRTHighTOutliers);
   fChain->SetBranchAddress("mu_staco_nGangedPixels", &mu_staco_nGangedPixels, &b_mu_staco_nGangedPixels);
   fChain->SetBranchAddress("mu_staco_nPixelDeadSensors", &mu_staco_nPixelDeadSensors, &b_mu_staco_nPixelDeadSensors);
   fChain->SetBranchAddress("mu_staco_nSCTDeadSensors", &mu_staco_nSCTDeadSensors, &b_mu_staco_nSCTDeadSensors);
   fChain->SetBranchAddress("mu_staco_nTRTDeadStraws", &mu_staco_nTRTDeadStraws, &b_mu_staco_nTRTDeadStraws);
   fChain->SetBranchAddress("mu_staco_expectBLayerHit", &mu_staco_expectBLayerHit, &b_mu_staco_expectBLayerHit);
   fChain->SetBranchAddress("mu_staco_nMDTHits", &mu_staco_nMDTHits, &b_mu_staco_nMDTHits);
   fChain->SetBranchAddress("mu_staco_nMDTHoles", &mu_staco_nMDTHoles, &b_mu_staco_nMDTHoles);
   fChain->SetBranchAddress("mu_staco_nCSCEtaHits", &mu_staco_nCSCEtaHits, &b_mu_staco_nCSCEtaHits);
   fChain->SetBranchAddress("mu_staco_nCSCEtaHoles", &mu_staco_nCSCEtaHoles, &b_mu_staco_nCSCEtaHoles);
   fChain->SetBranchAddress("mu_staco_nCSCPhiHits", &mu_staco_nCSCPhiHits, &b_mu_staco_nCSCPhiHits);
   fChain->SetBranchAddress("mu_staco_nCSCPhiHoles", &mu_staco_nCSCPhiHoles, &b_mu_staco_nCSCPhiHoles);
   fChain->SetBranchAddress("mu_staco_nRPCEtaHits", &mu_staco_nRPCEtaHits, &b_mu_staco_nRPCEtaHits);
   fChain->SetBranchAddress("mu_staco_nRPCEtaHoles", &mu_staco_nRPCEtaHoles, &b_mu_staco_nRPCEtaHoles);
   fChain->SetBranchAddress("mu_staco_nRPCPhiHits", &mu_staco_nRPCPhiHits, &b_mu_staco_nRPCPhiHits);
   fChain->SetBranchAddress("mu_staco_nRPCPhiHoles", &mu_staco_nRPCPhiHoles, &b_mu_staco_nRPCPhiHoles);
   fChain->SetBranchAddress("mu_staco_nTGCEtaHits", &mu_staco_nTGCEtaHits, &b_mu_staco_nTGCEtaHits);
   fChain->SetBranchAddress("mu_staco_nTGCEtaHoles", &mu_staco_nTGCEtaHoles, &b_mu_staco_nTGCEtaHoles);
   fChain->SetBranchAddress("mu_staco_nTGCPhiHits", &mu_staco_nTGCPhiHits, &b_mu_staco_nTGCPhiHits);
   fChain->SetBranchAddress("mu_staco_nTGCPhiHoles", &mu_staco_nTGCPhiHoles, &b_mu_staco_nTGCPhiHoles);
   fChain->SetBranchAddress("mu_staco_nMDTBIHits", &mu_staco_nMDTBIHits, &b_mu_staco_nMDTBIHits);
   fChain->SetBranchAddress("mu_staco_nMDTBMHits", &mu_staco_nMDTBMHits, &b_mu_staco_nMDTBMHits);
   fChain->SetBranchAddress("mu_staco_nMDTBOHits", &mu_staco_nMDTBOHits, &b_mu_staco_nMDTBOHits);
   fChain->SetBranchAddress("mu_staco_nMDTBEEHits", &mu_staco_nMDTBEEHits, &b_mu_staco_nMDTBEEHits);
   fChain->SetBranchAddress("mu_staco_nMDTBIS78Hits", &mu_staco_nMDTBIS78Hits, &b_mu_staco_nMDTBIS78Hits);
   fChain->SetBranchAddress("mu_staco_nMDTEIHits", &mu_staco_nMDTEIHits, &b_mu_staco_nMDTEIHits);
   fChain->SetBranchAddress("mu_staco_nMDTEMHits", &mu_staco_nMDTEMHits, &b_mu_staco_nMDTEMHits);
   fChain->SetBranchAddress("mu_staco_nMDTEOHits", &mu_staco_nMDTEOHits, &b_mu_staco_nMDTEOHits);
   fChain->SetBranchAddress("mu_staco_nMDTEEHits", &mu_staco_nMDTEEHits, &b_mu_staco_nMDTEEHits);
   fChain->SetBranchAddress("mu_staco_nRPCLayer1EtaHits", &mu_staco_nRPCLayer1EtaHits, &b_mu_staco_nRPCLayer1EtaHits);
   fChain->SetBranchAddress("mu_staco_nRPCLayer2EtaHits", &mu_staco_nRPCLayer2EtaHits, &b_mu_staco_nRPCLayer2EtaHits);
   fChain->SetBranchAddress("mu_staco_nRPCLayer3EtaHits", &mu_staco_nRPCLayer3EtaHits, &b_mu_staco_nRPCLayer3EtaHits);
   fChain->SetBranchAddress("mu_staco_nRPCLayer1PhiHits", &mu_staco_nRPCLayer1PhiHits, &b_mu_staco_nRPCLayer1PhiHits);
   fChain->SetBranchAddress("mu_staco_nRPCLayer2PhiHits", &mu_staco_nRPCLayer2PhiHits, &b_mu_staco_nRPCLayer2PhiHits);
   fChain->SetBranchAddress("mu_staco_nRPCLayer3PhiHits", &mu_staco_nRPCLayer3PhiHits, &b_mu_staco_nRPCLayer3PhiHits);
   fChain->SetBranchAddress("mu_staco_nTGCLayer1EtaHits", &mu_staco_nTGCLayer1EtaHits, &b_mu_staco_nTGCLayer1EtaHits);
   fChain->SetBranchAddress("mu_staco_nTGCLayer2EtaHits", &mu_staco_nTGCLayer2EtaHits, &b_mu_staco_nTGCLayer2EtaHits);
   fChain->SetBranchAddress("mu_staco_nTGCLayer3EtaHits", &mu_staco_nTGCLayer3EtaHits, &b_mu_staco_nTGCLayer3EtaHits);
   fChain->SetBranchAddress("mu_staco_nTGCLayer4EtaHits", &mu_staco_nTGCLayer4EtaHits, &b_mu_staco_nTGCLayer4EtaHits);
   fChain->SetBranchAddress("mu_staco_nTGCLayer1PhiHits", &mu_staco_nTGCLayer1PhiHits, &b_mu_staco_nTGCLayer1PhiHits);
   fChain->SetBranchAddress("mu_staco_nTGCLayer2PhiHits", &mu_staco_nTGCLayer2PhiHits, &b_mu_staco_nTGCLayer2PhiHits);
   fChain->SetBranchAddress("mu_staco_nTGCLayer3PhiHits", &mu_staco_nTGCLayer3PhiHits, &b_mu_staco_nTGCLayer3PhiHits);
   fChain->SetBranchAddress("mu_staco_nTGCLayer4PhiHits", &mu_staco_nTGCLayer4PhiHits, &b_mu_staco_nTGCLayer4PhiHits);
   fChain->SetBranchAddress("mu_staco_barrelSectors", &mu_staco_barrelSectors, &b_mu_staco_barrelSectors);
   fChain->SetBranchAddress("mu_staco_endcapSectors", &mu_staco_endcapSectors, &b_mu_staco_endcapSectors);
   fChain->SetBranchAddress("mu_staco_trackd0", &mu_staco_trackd0, &b_mu_staco_trackd0);
   fChain->SetBranchAddress("mu_staco_trackz0", &mu_staco_trackz0, &b_mu_staco_trackz0);
   fChain->SetBranchAddress("mu_staco_trackphi", &mu_staco_trackphi, &b_mu_staco_trackphi);
   fChain->SetBranchAddress("mu_staco_tracktheta", &mu_staco_tracktheta, &b_mu_staco_tracktheta);
   fChain->SetBranchAddress("mu_staco_trackqoverp", &mu_staco_trackqoverp, &b_mu_staco_trackqoverp);
   fChain->SetBranchAddress("mu_staco_trackcov_d0", &mu_staco_trackcov_d0, &b_mu_staco_trackcov_d0);
   fChain->SetBranchAddress("mu_staco_trackcov_z0", &mu_staco_trackcov_z0, &b_mu_staco_trackcov_z0);
   fChain->SetBranchAddress("mu_staco_trackcov_phi", &mu_staco_trackcov_phi, &b_mu_staco_trackcov_phi);
   fChain->SetBranchAddress("mu_staco_trackcov_theta", &mu_staco_trackcov_theta, &b_mu_staco_trackcov_theta);
   fChain->SetBranchAddress("mu_staco_trackcov_qoverp", &mu_staco_trackcov_qoverp, &b_mu_staco_trackcov_qoverp);
   fChain->SetBranchAddress("mu_staco_trackcov_d0_z0", &mu_staco_trackcov_d0_z0, &b_mu_staco_trackcov_d0_z0);
   fChain->SetBranchAddress("mu_staco_trackcov_d0_phi", &mu_staco_trackcov_d0_phi, &b_mu_staco_trackcov_d0_phi);
   fChain->SetBranchAddress("mu_staco_trackcov_d0_theta", &mu_staco_trackcov_d0_theta, &b_mu_staco_trackcov_d0_theta);
   fChain->SetBranchAddress("mu_staco_trackcov_d0_qoverp", &mu_staco_trackcov_d0_qoverp, &b_mu_staco_trackcov_d0_qoverp);
   fChain->SetBranchAddress("mu_staco_trackcov_z0_phi", &mu_staco_trackcov_z0_phi, &b_mu_staco_trackcov_z0_phi);
   fChain->SetBranchAddress("mu_staco_trackcov_z0_theta", &mu_staco_trackcov_z0_theta, &b_mu_staco_trackcov_z0_theta);
   fChain->SetBranchAddress("mu_staco_trackcov_z0_qoverp", &mu_staco_trackcov_z0_qoverp, &b_mu_staco_trackcov_z0_qoverp);
   fChain->SetBranchAddress("mu_staco_trackcov_phi_theta", &mu_staco_trackcov_phi_theta, &b_mu_staco_trackcov_phi_theta);
   fChain->SetBranchAddress("mu_staco_trackcov_phi_qoverp", &mu_staco_trackcov_phi_qoverp, &b_mu_staco_trackcov_phi_qoverp);
   fChain->SetBranchAddress("mu_staco_trackcov_theta_qoverp", &mu_staco_trackcov_theta_qoverp, &b_mu_staco_trackcov_theta_qoverp);
   fChain->SetBranchAddress("mu_staco_trackfitchi2", &mu_staco_trackfitchi2, &b_mu_staco_trackfitchi2);
   fChain->SetBranchAddress("mu_staco_trackfitndof", &mu_staco_trackfitndof, &b_mu_staco_trackfitndof);
   fChain->SetBranchAddress("mu_staco_hastrack", &mu_staco_hastrack, &b_mu_staco_hastrack);
   fChain->SetBranchAddress("mu_staco_truth_dr", &mu_staco_truth_dr, &b_mu_staco_truth_dr);
   fChain->SetBranchAddress("mu_staco_truth_matched", &mu_staco_truth_matched, &b_mu_staco_truth_matched);
   fChain->SetBranchAddress("mu_staco_EFCB_dr", &mu_staco_EFCB_dr, &b_mu_staco_EFCB_dr);
   fChain->SetBranchAddress("mu_staco_EFCB_n", &mu_staco_EFCB_n, &b_mu_staco_EFCB_n);
   fChain->SetBranchAddress("mu_staco_EFCB_MuonType", &mu_staco_EFCB_MuonType, &b_mu_staco_EFCB_MuonType);
   fChain->SetBranchAddress("mu_staco_EFCB_pt", &mu_staco_EFCB_pt, &b_mu_staco_EFCB_pt);
   fChain->SetBranchAddress("mu_staco_EFCB_eta", &mu_staco_EFCB_eta, &b_mu_staco_EFCB_eta);
   fChain->SetBranchAddress("mu_staco_EFCB_phi", &mu_staco_EFCB_phi, &b_mu_staco_EFCB_phi);
   fChain->SetBranchAddress("mu_staco_EFCB_hasCB", &mu_staco_EFCB_hasCB, &b_mu_staco_EFCB_hasCB);
   fChain->SetBranchAddress("mu_staco_EFCB_matched", &mu_staco_EFCB_matched, &b_mu_staco_EFCB_matched);
   fChain->SetBranchAddress("mu_staco_EFMG_dr", &mu_staco_EFMG_dr, &b_mu_staco_EFMG_dr);
   fChain->SetBranchAddress("mu_staco_EFMG_n", &mu_staco_EFMG_n, &b_mu_staco_EFMG_n);
   fChain->SetBranchAddress("mu_staco_EFMG_MuonType", &mu_staco_EFMG_MuonType, &b_mu_staco_EFMG_MuonType);
   fChain->SetBranchAddress("mu_staco_EFMG_pt", &mu_staco_EFMG_pt, &b_mu_staco_EFMG_pt);
   fChain->SetBranchAddress("mu_staco_EFMG_eta", &mu_staco_EFMG_eta, &b_mu_staco_EFMG_eta);
   fChain->SetBranchAddress("mu_staco_EFMG_phi", &mu_staco_EFMG_phi, &b_mu_staco_EFMG_phi);
   fChain->SetBranchAddress("mu_staco_EFMG_hasMG", &mu_staco_EFMG_hasMG, &b_mu_staco_EFMG_hasMG);
   fChain->SetBranchAddress("mu_staco_EFMG_matched", &mu_staco_EFMG_matched, &b_mu_staco_EFMG_matched);
   fChain->SetBranchAddress("mu_staco_EFME_dr", &mu_staco_EFME_dr, &b_mu_staco_EFME_dr);
   fChain->SetBranchAddress("mu_staco_EFME_n", &mu_staco_EFME_n, &b_mu_staco_EFME_n);
   fChain->SetBranchAddress("mu_staco_EFME_MuonType", &mu_staco_EFME_MuonType, &b_mu_staco_EFME_MuonType);
   fChain->SetBranchAddress("mu_staco_EFME_pt", &mu_staco_EFME_pt, &b_mu_staco_EFME_pt);
   fChain->SetBranchAddress("mu_staco_EFME_eta", &mu_staco_EFME_eta, &b_mu_staco_EFME_eta);
   fChain->SetBranchAddress("mu_staco_EFME_phi", &mu_staco_EFME_phi, &b_mu_staco_EFME_phi);
   fChain->SetBranchAddress("mu_staco_EFME_hasME", &mu_staco_EFME_hasME, &b_mu_staco_EFME_hasME);
   fChain->SetBranchAddress("mu_staco_EFME_matched", &mu_staco_EFME_matched, &b_mu_staco_EFME_matched);
   fChain->SetBranchAddress("mu_staco_L2CB_dr", &mu_staco_L2CB_dr, &b_mu_staco_L2CB_dr);
   fChain->SetBranchAddress("mu_staco_L2CB_pt", &mu_staco_L2CB_pt, &b_mu_staco_L2CB_pt);
   fChain->SetBranchAddress("mu_staco_L2CB_eta", &mu_staco_L2CB_eta, &b_mu_staco_L2CB_eta);
   fChain->SetBranchAddress("mu_staco_L2CB_phi", &mu_staco_L2CB_phi, &b_mu_staco_L2CB_phi);
   fChain->SetBranchAddress("mu_staco_L2CB_id_pt", &mu_staco_L2CB_id_pt, &b_mu_staco_L2CB_id_pt);
   fChain->SetBranchAddress("mu_staco_L2CB_ms_pt", &mu_staco_L2CB_ms_pt, &b_mu_staco_L2CB_ms_pt);
   fChain->SetBranchAddress("mu_staco_L2CB_nPixHits", &mu_staco_L2CB_nPixHits, &b_mu_staco_L2CB_nPixHits);
   fChain->SetBranchAddress("mu_staco_L2CB_nSCTHits", &mu_staco_L2CB_nSCTHits, &b_mu_staco_L2CB_nSCTHits);
   fChain->SetBranchAddress("mu_staco_L2CB_nTRTHits", &mu_staco_L2CB_nTRTHits, &b_mu_staco_L2CB_nTRTHits);
   fChain->SetBranchAddress("mu_staco_L2CB_nTRTHighTHits", &mu_staco_L2CB_nTRTHighTHits, &b_mu_staco_L2CB_nTRTHighTHits);
   fChain->SetBranchAddress("mu_staco_L2CB_matched", &mu_staco_L2CB_matched, &b_mu_staco_L2CB_matched);
   fChain->SetBranchAddress("mu_staco_L1_dr", &mu_staco_L1_dr, &b_mu_staco_L1_dr);
   fChain->SetBranchAddress("mu_staco_L1_pt", &mu_staco_L1_pt, &b_mu_staco_L1_pt);
   fChain->SetBranchAddress("mu_staco_L1_eta", &mu_staco_L1_eta, &b_mu_staco_L1_eta);
   fChain->SetBranchAddress("mu_staco_L1_phi", &mu_staco_L1_phi, &b_mu_staco_L1_phi);
   fChain->SetBranchAddress("mu_staco_L1_thrNumber", &mu_staco_L1_thrNumber, &b_mu_staco_L1_thrNumber);
   fChain->SetBranchAddress("mu_staco_L1_RoINumber", &mu_staco_L1_RoINumber, &b_mu_staco_L1_RoINumber);
   fChain->SetBranchAddress("mu_staco_L1_sectorAddress", &mu_staco_L1_sectorAddress, &b_mu_staco_L1_sectorAddress);
   fChain->SetBranchAddress("mu_staco_L1_firstCandidate", &mu_staco_L1_firstCandidate, &b_mu_staco_L1_firstCandidate);
   fChain->SetBranchAddress("mu_staco_L1_moreCandInRoI", &mu_staco_L1_moreCandInRoI, &b_mu_staco_L1_moreCandInRoI);
   fChain->SetBranchAddress("mu_staco_L1_moreCandInSector", &mu_staco_L1_moreCandInSector, &b_mu_staco_L1_moreCandInSector);
   fChain->SetBranchAddress("mu_staco_L1_source", &mu_staco_L1_source, &b_mu_staco_L1_source);
   fChain->SetBranchAddress("mu_staco_L1_hemisphere", &mu_staco_L1_hemisphere, &b_mu_staco_L1_hemisphere);
   fChain->SetBranchAddress("mu_staco_L1_matched", &mu_staco_L1_matched, &b_mu_staco_L1_matched);
   fChain->SetBranchAddress("el_HR_n", &el_HR_n, &b_el_HR_n);
   fChain->SetBranchAddress("el_HR_E", &el_HR_E, &b_el_HR_E);
   fChain->SetBranchAddress("el_HR_Et", &el_HR_Et, &b_el_HR_Et);
   fChain->SetBranchAddress("el_HR_pt", &el_HR_pt, &b_el_HR_pt);
   fChain->SetBranchAddress("el_HR_m", &el_HR_m, &b_el_HR_m);
   fChain->SetBranchAddress("el_HR_eta", &el_HR_eta, &b_el_HR_eta);
   fChain->SetBranchAddress("el_HR_phi", &el_HR_phi, &b_el_HR_phi);
   fChain->SetBranchAddress("el_HR_px", &el_HR_px, &b_el_HR_px);
   fChain->SetBranchAddress("el_HR_py", &el_HR_py, &b_el_HR_py);
   fChain->SetBranchAddress("el_HR_pz", &el_HR_pz, &b_el_HR_pz);
   fChain->SetBranchAddress("el_HR_charge", &el_HR_charge, &b_el_HR_charge);
   fChain->SetBranchAddress("el_HR_author", &el_HR_author, &b_el_HR_author);
   fChain->SetBranchAddress("el_HR_isEM", &el_HR_isEM, &b_el_HR_isEM);
   fChain->SetBranchAddress("el_HR_OQ", &el_HR_OQ, &b_el_HR_OQ);
   fChain->SetBranchAddress("el_HR_convFlag", &el_HR_convFlag, &b_el_HR_convFlag);
   fChain->SetBranchAddress("el_HR_isConv", &el_HR_isConv, &b_el_HR_isConv);
   fChain->SetBranchAddress("el_HR_nConv", &el_HR_nConv, &b_el_HR_nConv);
   fChain->SetBranchAddress("el_HR_nSingleTrackConv", &el_HR_nSingleTrackConv, &b_el_HR_nSingleTrackConv);
   fChain->SetBranchAddress("el_HR_nDoubleTrackConv", &el_HR_nDoubleTrackConv, &b_el_HR_nDoubleTrackConv);
   fChain->SetBranchAddress("el_HR_OQRecalc", &el_HR_OQRecalc, &b_el_HR_OQRecalc);
   fChain->SetBranchAddress("el_HR_type", &el_HR_type, &b_el_HR_type);
   fChain->SetBranchAddress("el_HR_origin", &el_HR_origin, &b_el_HR_origin);
   fChain->SetBranchAddress("el_HR_typebkg", &el_HR_typebkg, &b_el_HR_typebkg);
   fChain->SetBranchAddress("el_HR_originbkg", &el_HR_originbkg, &b_el_HR_originbkg);
   fChain->SetBranchAddress("el_HR_truth_E", &el_HR_truth_E, &b_el_HR_truth_E);
   fChain->SetBranchAddress("el_HR_truth_pt", &el_HR_truth_pt, &b_el_HR_truth_pt);
   fChain->SetBranchAddress("el_HR_truth_eta", &el_HR_truth_eta, &b_el_HR_truth_eta);
   fChain->SetBranchAddress("el_HR_truth_phi", &el_HR_truth_phi, &b_el_HR_truth_phi);
   fChain->SetBranchAddress("el_HR_truth_type", &el_HR_truth_type, &b_el_HR_truth_type);
   fChain->SetBranchAddress("el_HR_truth_status", &el_HR_truth_status, &b_el_HR_truth_status);
   fChain->SetBranchAddress("el_HR_truth_barcode", &el_HR_truth_barcode, &b_el_HR_truth_barcode);
   fChain->SetBranchAddress("el_HR_truth_mothertype", &el_HR_truth_mothertype, &b_el_HR_truth_mothertype);
   fChain->SetBranchAddress("el_HR_truth_motherbarcode", &el_HR_truth_motherbarcode, &b_el_HR_truth_motherbarcode);
   fChain->SetBranchAddress("el_HR_truth_hasHardBrem", &el_HR_truth_hasHardBrem, &b_el_HR_truth_hasHardBrem);
   fChain->SetBranchAddress("el_HR_truth_index", &el_HR_truth_index, &b_el_HR_truth_index);
   fChain->SetBranchAddress("el_HR_truth_matched", &el_HR_truth_matched, &b_el_HR_truth_matched);
   fChain->SetBranchAddress("el_HR_loose", &el_HR_loose, &b_el_HR_loose);
   fChain->SetBranchAddress("el_HR_medium", &el_HR_medium, &b_el_HR_medium);
   fChain->SetBranchAddress("el_HR_mediumIso", &el_HR_mediumIso, &b_el_HR_mediumIso);
   fChain->SetBranchAddress("el_HR_tight", &el_HR_tight, &b_el_HR_tight);
   fChain->SetBranchAddress("el_HR_tightIso", &el_HR_tightIso, &b_el_HR_tightIso);
   fChain->SetBranchAddress("el_HR_goodOQ", &el_HR_goodOQ, &b_el_HR_goodOQ);
   fChain->SetBranchAddress("el_HR_Ethad", &el_HR_Ethad, &b_el_HR_Ethad);
   fChain->SetBranchAddress("el_HR_Ethad1", &el_HR_Ethad1, &b_el_HR_Ethad1);
   fChain->SetBranchAddress("el_HR_f1", &el_HR_f1, &b_el_HR_f1);
   fChain->SetBranchAddress("el_HR_f1core", &el_HR_f1core, &b_el_HR_f1core);
   fChain->SetBranchAddress("el_HR_Emins1", &el_HR_Emins1, &b_el_HR_Emins1);
   fChain->SetBranchAddress("el_HR_fside", &el_HR_fside, &b_el_HR_fside);
   fChain->SetBranchAddress("el_HR_Emax2", &el_HR_Emax2, &b_el_HR_Emax2);
   fChain->SetBranchAddress("el_HR_ws3", &el_HR_ws3, &b_el_HR_ws3);
   fChain->SetBranchAddress("el_HR_wstot", &el_HR_wstot, &b_el_HR_wstot);
   fChain->SetBranchAddress("el_HR_emaxs1", &el_HR_emaxs1, &b_el_HR_emaxs1);
   fChain->SetBranchAddress("el_HR_deltaEs", &el_HR_deltaEs, &b_el_HR_deltaEs);
   fChain->SetBranchAddress("el_HR_E233", &el_HR_E233, &b_el_HR_E233);
   fChain->SetBranchAddress("el_HR_E237", &el_HR_E237, &b_el_HR_E237);
   fChain->SetBranchAddress("el_HR_E277", &el_HR_E277, &b_el_HR_E277);
   fChain->SetBranchAddress("el_HR_weta2", &el_HR_weta2, &b_el_HR_weta2);
   fChain->SetBranchAddress("el_HR_f3", &el_HR_f3, &b_el_HR_f3);
   fChain->SetBranchAddress("el_HR_f3core", &el_HR_f3core, &b_el_HR_f3core);
   fChain->SetBranchAddress("el_HR_rphiallcalo", &el_HR_rphiallcalo, &b_el_HR_rphiallcalo);
   fChain->SetBranchAddress("el_HR_Etcone45", &el_HR_Etcone45, &b_el_HR_Etcone45);
   fChain->SetBranchAddress("el_HR_Etcone15", &el_HR_Etcone15, &b_el_HR_Etcone15);
   fChain->SetBranchAddress("el_HR_Etcone20", &el_HR_Etcone20, &b_el_HR_Etcone20);
   fChain->SetBranchAddress("el_HR_Etcone25", &el_HR_Etcone25, &b_el_HR_Etcone25);
   fChain->SetBranchAddress("el_HR_Etcone30", &el_HR_Etcone30, &b_el_HR_Etcone30);
   fChain->SetBranchAddress("el_HR_Etcone35", &el_HR_Etcone35, &b_el_HR_Etcone35);
   fChain->SetBranchAddress("el_HR_Etcone40", &el_HR_Etcone40, &b_el_HR_Etcone40);
   fChain->SetBranchAddress("el_HR_ptcone20", &el_HR_ptcone20, &b_el_HR_ptcone20);
   fChain->SetBranchAddress("el_HR_ptcone30", &el_HR_ptcone30, &b_el_HR_ptcone30);
   fChain->SetBranchAddress("el_HR_ptcone40", &el_HR_ptcone40, &b_el_HR_ptcone40);
   fChain->SetBranchAddress("el_HR_nucone20", &el_HR_nucone20, &b_el_HR_nucone20);
   fChain->SetBranchAddress("el_HR_nucone30", &el_HR_nucone30, &b_el_HR_nucone30);
   fChain->SetBranchAddress("el_HR_nucone40", &el_HR_nucone40, &b_el_HR_nucone40);
   fChain->SetBranchAddress("el_HR_convanglematch", &el_HR_convanglematch, &b_el_HR_convanglematch);
   fChain->SetBranchAddress("el_HR_convtrackmatch", &el_HR_convtrackmatch, &b_el_HR_convtrackmatch);
   fChain->SetBranchAddress("el_HR_hasconv", &el_HR_hasconv, &b_el_HR_hasconv);
   fChain->SetBranchAddress("el_HR_convvtxx", &el_HR_convvtxx, &b_el_HR_convvtxx);
   fChain->SetBranchAddress("el_HR_convvtxy", &el_HR_convvtxy, &b_el_HR_convvtxy);
   fChain->SetBranchAddress("el_HR_convvtxz", &el_HR_convvtxz, &b_el_HR_convvtxz);
   fChain->SetBranchAddress("el_HR_Rconv", &el_HR_Rconv, &b_el_HR_Rconv);
   fChain->SetBranchAddress("el_HR_zconv", &el_HR_zconv, &b_el_HR_zconv);
   fChain->SetBranchAddress("el_HR_convvtxchi2", &el_HR_convvtxchi2, &b_el_HR_convvtxchi2);
   fChain->SetBranchAddress("el_HR_pt1conv", &el_HR_pt1conv, &b_el_HR_pt1conv);
   fChain->SetBranchAddress("el_HR_convtrk1nBLHits", &el_HR_convtrk1nBLHits, &b_el_HR_convtrk1nBLHits);
   fChain->SetBranchAddress("el_HR_convtrk1nPixHits", &el_HR_convtrk1nPixHits, &b_el_HR_convtrk1nPixHits);
   fChain->SetBranchAddress("el_HR_convtrk1nSCTHits", &el_HR_convtrk1nSCTHits, &b_el_HR_convtrk1nSCTHits);
   fChain->SetBranchAddress("el_HR_convtrk1nTRTHits", &el_HR_convtrk1nTRTHits, &b_el_HR_convtrk1nTRTHits);
   fChain->SetBranchAddress("el_HR_pt2conv", &el_HR_pt2conv, &b_el_HR_pt2conv);
   fChain->SetBranchAddress("el_HR_convtrk2nBLHits", &el_HR_convtrk2nBLHits, &b_el_HR_convtrk2nBLHits);
   fChain->SetBranchAddress("el_HR_convtrk2nPixHits", &el_HR_convtrk2nPixHits, &b_el_HR_convtrk2nPixHits);
   fChain->SetBranchAddress("el_HR_convtrk2nSCTHits", &el_HR_convtrk2nSCTHits, &b_el_HR_convtrk2nSCTHits);
   fChain->SetBranchAddress("el_HR_convtrk2nTRTHits", &el_HR_convtrk2nTRTHits, &b_el_HR_convtrk2nTRTHits);
   fChain->SetBranchAddress("el_HR_ptconv", &el_HR_ptconv, &b_el_HR_ptconv);
   fChain->SetBranchAddress("el_HR_pzconv", &el_HR_pzconv, &b_el_HR_pzconv);
   fChain->SetBranchAddress("el_HR_pos7", &el_HR_pos7, &b_el_HR_pos7);
   fChain->SetBranchAddress("el_HR_etacorrmag", &el_HR_etacorrmag, &b_el_HR_etacorrmag);
   fChain->SetBranchAddress("el_HR_deltaeta1", &el_HR_deltaeta1, &b_el_HR_deltaeta1);
   fChain->SetBranchAddress("el_HR_deltaeta2", &el_HR_deltaeta2, &b_el_HR_deltaeta2);
   fChain->SetBranchAddress("el_HR_deltaphi2", &el_HR_deltaphi2, &b_el_HR_deltaphi2);
   fChain->SetBranchAddress("el_HR_deltaphiRescaled", &el_HR_deltaphiRescaled, &b_el_HR_deltaphiRescaled);
   fChain->SetBranchAddress("el_HR_deltaPhiRot", &el_HR_deltaPhiRot, &b_el_HR_deltaPhiRot);
   fChain->SetBranchAddress("el_HR_expectHitInBLayer", &el_HR_expectHitInBLayer, &b_el_HR_expectHitInBLayer);
   fChain->SetBranchAddress("el_HR_trackd0_physics", &el_HR_trackd0_physics, &b_el_HR_trackd0_physics);
   fChain->SetBranchAddress("el_HR_reta", &el_HR_reta, &b_el_HR_reta);
   fChain->SetBranchAddress("el_HR_rphi", &el_HR_rphi, &b_el_HR_rphi);
   fChain->SetBranchAddress("el_HR_refittedTrack_n", &el_HR_refittedTrack_n, &b_el_HR_refittedTrack_n);
   fChain->SetBranchAddress("el_HR_firstEdens", &el_HR_firstEdens, &b_el_HR_firstEdens);
   fChain->SetBranchAddress("el_HR_cellmaxfrac", &el_HR_cellmaxfrac, &b_el_HR_cellmaxfrac);
   fChain->SetBranchAddress("el_HR_longitudinal", &el_HR_longitudinal, &b_el_HR_longitudinal);
   fChain->SetBranchAddress("el_HR_secondlambda", &el_HR_secondlambda, &b_el_HR_secondlambda);
   fChain->SetBranchAddress("el_HR_lateral", &el_HR_lateral, &b_el_HR_lateral);
   fChain->SetBranchAddress("el_HR_secondR", &el_HR_secondR, &b_el_HR_secondR);
   fChain->SetBranchAddress("el_HR_centerlambda", &el_HR_centerlambda, &b_el_HR_centerlambda);
   fChain->SetBranchAddress("el_HR_trackd0", &el_HR_trackd0, &b_el_HR_trackd0);
   fChain->SetBranchAddress("el_HR_trackz0", &el_HR_trackz0, &b_el_HR_trackz0);
   fChain->SetBranchAddress("el_HR_trackphi", &el_HR_trackphi, &b_el_HR_trackphi);
   fChain->SetBranchAddress("el_HR_tracktheta", &el_HR_tracktheta, &b_el_HR_tracktheta);
   fChain->SetBranchAddress("el_HR_trackqoverp", &el_HR_trackqoverp, &b_el_HR_trackqoverp);
   fChain->SetBranchAddress("el_HR_trackpt", &el_HR_trackpt, &b_el_HR_trackpt);
   fChain->SetBranchAddress("el_HR_tracketa", &el_HR_tracketa, &b_el_HR_tracketa);
   fChain->SetBranchAddress("el_HR_nBLHits", &el_HR_nBLHits, &b_el_HR_nBLHits);
   fChain->SetBranchAddress("el_HR_nPixHits", &el_HR_nPixHits, &b_el_HR_nPixHits);
   fChain->SetBranchAddress("el_HR_nSCTHits", &el_HR_nSCTHits, &b_el_HR_nSCTHits);
   fChain->SetBranchAddress("el_HR_nTRTHits", &el_HR_nTRTHits, &b_el_HR_nTRTHits);
   fChain->SetBranchAddress("el_HR_nPixHoles", &el_HR_nPixHoles, &b_el_HR_nPixHoles);
   fChain->SetBranchAddress("el_HR_nSCTHoles", &el_HR_nSCTHoles, &b_el_HR_nSCTHoles);
   fChain->SetBranchAddress("el_HR_nBLSharedHits", &el_HR_nBLSharedHits, &b_el_HR_nBLSharedHits);
   fChain->SetBranchAddress("el_HR_nPixSharedHits", &el_HR_nPixSharedHits, &b_el_HR_nPixSharedHits);
   fChain->SetBranchAddress("el_HR_nSCTSharedHits", &el_HR_nSCTSharedHits, &b_el_HR_nSCTSharedHits);
   fChain->SetBranchAddress("el_HR_nTRTHighTHits", &el_HR_nTRTHighTHits, &b_el_HR_nTRTHighTHits);
   fChain->SetBranchAddress("el_HR_nTRTOutliers", &el_HR_nTRTOutliers, &b_el_HR_nTRTOutliers);
   fChain->SetBranchAddress("el_HR_nTRTHighTOutliers", &el_HR_nTRTHighTOutliers, &b_el_HR_nTRTHighTOutliers);
   fChain->SetBranchAddress("el_HR_nSiHits", &el_HR_nSiHits, &b_el_HR_nSiHits);
   fChain->SetBranchAddress("el_HR_TRTHighTHitsRatio", &el_HR_TRTHighTHitsRatio, &b_el_HR_TRTHighTHitsRatio);
   fChain->SetBranchAddress("el_HR_TRTHighTHitsRatioOutliers", &el_HR_TRTHighTHitsRatioOutliers, &b_el_HR_TRTHighTHitsRatioOutliers);
   fChain->SetBranchAddress("el_HR_pixeldEdx", &el_HR_pixeldEdx, &b_el_HR_pixeldEdx);
   fChain->SetBranchAddress("el_HR_eProbabilityComb", &el_HR_eProbabilityComb, &b_el_HR_eProbabilityComb);
   fChain->SetBranchAddress("el_HR_eProbabilityHT", &el_HR_eProbabilityHT, &b_el_HR_eProbabilityHT);
   fChain->SetBranchAddress("el_HR_eProbabilityToT", &el_HR_eProbabilityToT, &b_el_HR_eProbabilityToT);
   fChain->SetBranchAddress("el_HR_eProbabilityBrem", &el_HR_eProbabilityBrem, &b_el_HR_eProbabilityBrem);
   fChain->SetBranchAddress("el_HR_hastrack", &el_HR_hastrack, &b_el_HR_hastrack);
   fChain->SetBranchAddress("el_HR_deltaEmax2", &el_HR_deltaEmax2, &b_el_HR_deltaEmax2);
   fChain->SetBranchAddress("el_HR_calibHitsShowerDepth", &el_HR_calibHitsShowerDepth, &b_el_HR_calibHitsShowerDepth);
   fChain->SetBranchAddress("el_HR_trackd0beam", &el_HR_trackd0beam, &b_el_HR_trackd0beam);
   fChain->SetBranchAddress("el_HR_tracksigd0beam", &el_HR_tracksigd0beam, &b_el_HR_tracksigd0beam);
   fChain->SetBranchAddress("el_HR_trackd0pv", &el_HR_trackd0pv, &b_el_HR_trackd0pv);
   fChain->SetBranchAddress("el_HR_tracksigd0pv", &el_HR_tracksigd0pv, &b_el_HR_tracksigd0pv);
   fChain->SetBranchAddress("el_HR_trackz0pv", &el_HR_trackz0pv, &b_el_HR_trackz0pv);
   fChain->SetBranchAddress("el_HR_tracksigz0pv", &el_HR_tracksigz0pv, &b_el_HR_tracksigz0pv);
   fChain->SetBranchAddress("el_HR_trackd0pvunbiased", &el_HR_trackd0pvunbiased, &b_el_HR_trackd0pvunbiased);
   fChain->SetBranchAddress("el_HR_tracksigd0pvunbiased", &el_HR_tracksigd0pvunbiased, &b_el_HR_tracksigd0pvunbiased);
   fChain->SetBranchAddress("el_HR_trackz0pvunbiased", &el_HR_trackz0pvunbiased, &b_el_HR_trackz0pvunbiased);
   fChain->SetBranchAddress("el_HR_tracksigz0pvunbiased", &el_HR_tracksigz0pvunbiased, &b_el_HR_tracksigz0pvunbiased);
   fChain->SetBranchAddress("el_HR_isIso", &el_HR_isIso, &b_el_HR_isIso);
   fChain->SetBranchAddress("el_HR_mvaptcone20", &el_HR_mvaptcone20, &b_el_HR_mvaptcone20);
   fChain->SetBranchAddress("el_HR_mvaptcone30", &el_HR_mvaptcone30, &b_el_HR_mvaptcone30);
   fChain->SetBranchAddress("el_HR_mvaptcone40", &el_HR_mvaptcone40, &b_el_HR_mvaptcone40);
   fChain->SetBranchAddress("el_HR_EF_dr", &el_HR_EF_dr, &b_el_HR_EF_dr);
   fChain->SetBranchAddress("el_HR_L2_dr", &el_HR_L2_dr, &b_el_HR_L2_dr);
   fChain->SetBranchAddress("el_HR_L1_dr", &el_HR_L1_dr, &b_el_HR_L1_dr);
   fChain->SetBranchAddress("mu_HR_n", &mu_HR_n, &b_mu_HR_n);
   fChain->SetBranchAddress("mu_HR_E", &mu_HR_E, &b_mu_HR_E);
   fChain->SetBranchAddress("mu_HR_pt", &mu_HR_pt, &b_mu_HR_pt);
   fChain->SetBranchAddress("mu_HR_m", &mu_HR_m, &b_mu_HR_m);
   fChain->SetBranchAddress("mu_HR_eta", &mu_HR_eta, &b_mu_HR_eta);
   fChain->SetBranchAddress("mu_HR_phi", &mu_HR_phi, &b_mu_HR_phi);
   fChain->SetBranchAddress("mu_HR_px", &mu_HR_px, &b_mu_HR_px);
   fChain->SetBranchAddress("mu_HR_py", &mu_HR_py, &b_mu_HR_py);
   fChain->SetBranchAddress("mu_HR_pz", &mu_HR_pz, &b_mu_HR_pz);
   fChain->SetBranchAddress("mu_HR_charge", &mu_HR_charge, &b_mu_HR_charge);
   fChain->SetBranchAddress("mu_HR_allauthor", &mu_HR_allauthor, &b_mu_HR_allauthor);
   fChain->SetBranchAddress("mu_HR_author", &mu_HR_author, &b_mu_HR_author);
   fChain->SetBranchAddress("mu_HR_beta", &mu_HR_beta, &b_mu_HR_beta);
   fChain->SetBranchAddress("mu_HR_isMuonLikelihood", &mu_HR_isMuonLikelihood, &b_mu_HR_isMuonLikelihood);
   fChain->SetBranchAddress("mu_HR_matchchi2", &mu_HR_matchchi2, &b_mu_HR_matchchi2);
   fChain->SetBranchAddress("mu_HR_matchndof", &mu_HR_matchndof, &b_mu_HR_matchndof);
   fChain->SetBranchAddress("mu_HR_etcone20", &mu_HR_etcone20, &b_mu_HR_etcone20);
   fChain->SetBranchAddress("mu_HR_etcone30", &mu_HR_etcone30, &b_mu_HR_etcone30);
   fChain->SetBranchAddress("mu_HR_etcone40", &mu_HR_etcone40, &b_mu_HR_etcone40);
   fChain->SetBranchAddress("mu_HR_nucone20", &mu_HR_nucone20, &b_mu_HR_nucone20);
   fChain->SetBranchAddress("mu_HR_nucone30", &mu_HR_nucone30, &b_mu_HR_nucone30);
   fChain->SetBranchAddress("mu_HR_nucone40", &mu_HR_nucone40, &b_mu_HR_nucone40);
   fChain->SetBranchAddress("mu_HR_ptcone20", &mu_HR_ptcone20, &b_mu_HR_ptcone20);
   fChain->SetBranchAddress("mu_HR_ptcone30", &mu_HR_ptcone30, &b_mu_HR_ptcone30);
   fChain->SetBranchAddress("mu_HR_ptcone40", &mu_HR_ptcone40, &b_mu_HR_ptcone40);
   fChain->SetBranchAddress("mu_HR_energyLossPar", &mu_HR_energyLossPar, &b_mu_HR_energyLossPar);
   fChain->SetBranchAddress("mu_HR_energyLossErr", &mu_HR_energyLossErr, &b_mu_HR_energyLossErr);
   fChain->SetBranchAddress("mu_HR_etCore", &mu_HR_etCore, &b_mu_HR_etCore);
   fChain->SetBranchAddress("mu_HR_energyLossType", &mu_HR_energyLossType, &b_mu_HR_energyLossType);
   fChain->SetBranchAddress("mu_HR_caloMuonIdTag", &mu_HR_caloMuonIdTag, &b_mu_HR_caloMuonIdTag);
   fChain->SetBranchAddress("mu_HR_caloLRLikelihood", &mu_HR_caloLRLikelihood, &b_mu_HR_caloLRLikelihood);
   fChain->SetBranchAddress("mu_HR_bestMatch", &mu_HR_bestMatch, &b_mu_HR_bestMatch);
   fChain->SetBranchAddress("mu_HR_isStandAloneMuon", &mu_HR_isStandAloneMuon, &b_mu_HR_isStandAloneMuon);
   fChain->SetBranchAddress("mu_HR_isCombinedMuon", &mu_HR_isCombinedMuon, &b_mu_HR_isCombinedMuon);
   fChain->SetBranchAddress("mu_HR_isLowPtReconstructedMuon", &mu_HR_isLowPtReconstructedMuon, &b_mu_HR_isLowPtReconstructedMuon);
   fChain->SetBranchAddress("mu_HR_loose", &mu_HR_loose, &b_mu_HR_loose);
   fChain->SetBranchAddress("mu_HR_medium", &mu_HR_medium, &b_mu_HR_medium);
   fChain->SetBranchAddress("mu_HR_tight", &mu_HR_tight, &b_mu_HR_tight);
   fChain->SetBranchAddress("mu_HR_d0_exPV", &mu_HR_d0_exPV, &b_mu_HR_d0_exPV);
   fChain->SetBranchAddress("mu_HR_z0_exPV", &mu_HR_z0_exPV, &b_mu_HR_z0_exPV);
   fChain->SetBranchAddress("mu_HR_phi_exPV", &mu_HR_phi_exPV, &b_mu_HR_phi_exPV);
   fChain->SetBranchAddress("mu_HR_theta_exPV", &mu_HR_theta_exPV, &b_mu_HR_theta_exPV);
   fChain->SetBranchAddress("mu_HR_qoverp_exPV", &mu_HR_qoverp_exPV, &b_mu_HR_qoverp_exPV);
   fChain->SetBranchAddress("mu_HR_cb_d0_exPV", &mu_HR_cb_d0_exPV, &b_mu_HR_cb_d0_exPV);
   fChain->SetBranchAddress("mu_HR_cb_z0_exPV", &mu_HR_cb_z0_exPV, &b_mu_HR_cb_z0_exPV);
   fChain->SetBranchAddress("mu_HR_cb_phi_exPV", &mu_HR_cb_phi_exPV, &b_mu_HR_cb_phi_exPV);
   fChain->SetBranchAddress("mu_HR_cb_theta_exPV", &mu_HR_cb_theta_exPV, &b_mu_HR_cb_theta_exPV);
   fChain->SetBranchAddress("mu_HR_cb_qoverp_exPV", &mu_HR_cb_qoverp_exPV, &b_mu_HR_cb_qoverp_exPV);
   fChain->SetBranchAddress("mu_HR_id_d0_exPV", &mu_HR_id_d0_exPV, &b_mu_HR_id_d0_exPV);
   fChain->SetBranchAddress("mu_HR_id_z0_exPV", &mu_HR_id_z0_exPV, &b_mu_HR_id_z0_exPV);
   fChain->SetBranchAddress("mu_HR_id_phi_exPV", &mu_HR_id_phi_exPV, &b_mu_HR_id_phi_exPV);
   fChain->SetBranchAddress("mu_HR_id_theta_exPV", &mu_HR_id_theta_exPV, &b_mu_HR_id_theta_exPV);
   fChain->SetBranchAddress("mu_HR_id_qoverp_exPV", &mu_HR_id_qoverp_exPV, &b_mu_HR_id_qoverp_exPV);
   fChain->SetBranchAddress("mu_HR_me_d0_exPV", &mu_HR_me_d0_exPV, &b_mu_HR_me_d0_exPV);
   fChain->SetBranchAddress("mu_HR_me_z0_exPV", &mu_HR_me_z0_exPV, &b_mu_HR_me_z0_exPV);
   fChain->SetBranchAddress("mu_HR_me_phi_exPV", &mu_HR_me_phi_exPV, &b_mu_HR_me_phi_exPV);
   fChain->SetBranchAddress("mu_HR_me_theta_exPV", &mu_HR_me_theta_exPV, &b_mu_HR_me_theta_exPV);
   fChain->SetBranchAddress("mu_HR_me_qoverp_exPV", &mu_HR_me_qoverp_exPV, &b_mu_HR_me_qoverp_exPV);
   fChain->SetBranchAddress("mu_HR_ie_d0_exPV", &mu_HR_ie_d0_exPV, &b_mu_HR_ie_d0_exPV);
   fChain->SetBranchAddress("mu_HR_ie_z0_exPV", &mu_HR_ie_z0_exPV, &b_mu_HR_ie_z0_exPV);
   fChain->SetBranchAddress("mu_HR_ie_phi_exPV", &mu_HR_ie_phi_exPV, &b_mu_HR_ie_phi_exPV);
   fChain->SetBranchAddress("mu_HR_ie_theta_exPV", &mu_HR_ie_theta_exPV, &b_mu_HR_ie_theta_exPV);
   fChain->SetBranchAddress("mu_HR_ie_qoverp_exPV", &mu_HR_ie_qoverp_exPV, &b_mu_HR_ie_qoverp_exPV);
   fChain->SetBranchAddress("mu_HR_SpaceTime_detID", &mu_HR_SpaceTime_detID, &b_mu_HR_SpaceTime_detID);
   fChain->SetBranchAddress("mu_HR_SpaceTime_t", &mu_HR_SpaceTime_t, &b_mu_HR_SpaceTime_t);
   fChain->SetBranchAddress("mu_HR_SpaceTime_tError", &mu_HR_SpaceTime_tError, &b_mu_HR_SpaceTime_tError);
   fChain->SetBranchAddress("mu_HR_SpaceTime_weight", &mu_HR_SpaceTime_weight, &b_mu_HR_SpaceTime_weight);
   fChain->SetBranchAddress("mu_HR_SpaceTime_x", &mu_HR_SpaceTime_x, &b_mu_HR_SpaceTime_x);
   fChain->SetBranchAddress("mu_HR_SpaceTime_y", &mu_HR_SpaceTime_y, &b_mu_HR_SpaceTime_y);
   fChain->SetBranchAddress("mu_HR_SpaceTime_z", &mu_HR_SpaceTime_z, &b_mu_HR_SpaceTime_z);
   fChain->SetBranchAddress("mu_HR_SpaceTime_t_Tile", &mu_HR_SpaceTime_t_Tile, &b_mu_HR_SpaceTime_t_Tile);
   fChain->SetBranchAddress("mu_HR_SpaceTime_tError_Tile", &mu_HR_SpaceTime_tError_Tile, &b_mu_HR_SpaceTime_tError_Tile);
   fChain->SetBranchAddress("mu_HR_SpaceTime_weight_Tile", &mu_HR_SpaceTime_weight_Tile, &b_mu_HR_SpaceTime_weight_Tile);
   fChain->SetBranchAddress("mu_HR_SpaceTime_x_Tile", &mu_HR_SpaceTime_x_Tile, &b_mu_HR_SpaceTime_x_Tile);
   fChain->SetBranchAddress("mu_HR_SpaceTime_y_Tile", &mu_HR_SpaceTime_y_Tile, &b_mu_HR_SpaceTime_y_Tile);
   fChain->SetBranchAddress("mu_HR_SpaceTime_z_Tile", &mu_HR_SpaceTime_z_Tile, &b_mu_HR_SpaceTime_z_Tile);
   fChain->SetBranchAddress("mu_HR_SpaceTime_t_TRT", &mu_HR_SpaceTime_t_TRT, &b_mu_HR_SpaceTime_t_TRT);
   fChain->SetBranchAddress("mu_HR_SpaceTime_tError_TRT", &mu_HR_SpaceTime_tError_TRT, &b_mu_HR_SpaceTime_tError_TRT);
   fChain->SetBranchAddress("mu_HR_SpaceTime_weight_TRT", &mu_HR_SpaceTime_weight_TRT, &b_mu_HR_SpaceTime_weight_TRT);
   fChain->SetBranchAddress("mu_HR_SpaceTime_x_TRT", &mu_HR_SpaceTime_x_TRT, &b_mu_HR_SpaceTime_x_TRT);
   fChain->SetBranchAddress("mu_HR_SpaceTime_y_TRT", &mu_HR_SpaceTime_y_TRT, &b_mu_HR_SpaceTime_y_TRT);
   fChain->SetBranchAddress("mu_HR_SpaceTime_z_TRT", &mu_HR_SpaceTime_z_TRT, &b_mu_HR_SpaceTime_z_TRT);
   fChain->SetBranchAddress("mu_HR_SpaceTime_t_MDT", &mu_HR_SpaceTime_t_MDT, &b_mu_HR_SpaceTime_t_MDT);
   fChain->SetBranchAddress("mu_HR_SpaceTime_tError_MDT", &mu_HR_SpaceTime_tError_MDT, &b_mu_HR_SpaceTime_tError_MDT);
   fChain->SetBranchAddress("mu_HR_SpaceTime_weight_MDT", &mu_HR_SpaceTime_weight_MDT, &b_mu_HR_SpaceTime_weight_MDT);
   fChain->SetBranchAddress("mu_HR_SpaceTime_x_MDT", &mu_HR_SpaceTime_x_MDT, &b_mu_HR_SpaceTime_x_MDT);
   fChain->SetBranchAddress("mu_HR_SpaceTime_y_MDT", &mu_HR_SpaceTime_y_MDT, &b_mu_HR_SpaceTime_y_MDT);
   fChain->SetBranchAddress("mu_HR_SpaceTime_z_MDT", &mu_HR_SpaceTime_z_MDT, &b_mu_HR_SpaceTime_z_MDT);
   fChain->SetBranchAddress("mu_HR_TileCellEnergyLayer1", &mu_HR_TileCellEnergyLayer1, &b_mu_HR_TileCellEnergyLayer1);
   fChain->SetBranchAddress("mu_HR_TileTimeLayer1", &mu_HR_TileTimeLayer1, &b_mu_HR_TileTimeLayer1);
   fChain->SetBranchAddress("mu_HR_TileCellRmsNoiseLayer1", &mu_HR_TileCellRmsNoiseLayer1, &b_mu_HR_TileCellRmsNoiseLayer1);
   fChain->SetBranchAddress("mu_HR_TileCellSignLayer1", &mu_HR_TileCellSignLayer1, &b_mu_HR_TileCellSignLayer1);
   fChain->SetBranchAddress("mu_HR_TileCellEnergyLayer2", &mu_HR_TileCellEnergyLayer2, &b_mu_HR_TileCellEnergyLayer2);
   fChain->SetBranchAddress("mu_HR_TileTimeLayer2", &mu_HR_TileTimeLayer2, &b_mu_HR_TileTimeLayer2);
   fChain->SetBranchAddress("mu_HR_TileCellRmsNoiseLayer2", &mu_HR_TileCellRmsNoiseLayer2, &b_mu_HR_TileCellRmsNoiseLayer2);
   fChain->SetBranchAddress("mu_HR_TileCellSignLayer2", &mu_HR_TileCellSignLayer2, &b_mu_HR_TileCellSignLayer2);
   fChain->SetBranchAddress("mu_HR_TileCellEnergyLayer3", &mu_HR_TileCellEnergyLayer3, &b_mu_HR_TileCellEnergyLayer3);
   fChain->SetBranchAddress("mu_HR_TileTimeLayer3", &mu_HR_TileTimeLayer3, &b_mu_HR_TileTimeLayer3);
   fChain->SetBranchAddress("mu_HR_TileCellRmsNoiseLayer3", &mu_HR_TileCellRmsNoiseLayer3, &b_mu_HR_TileCellRmsNoiseLayer3);
   fChain->SetBranchAddress("mu_HR_TileCellSignLayer3", &mu_HR_TileCellSignLayer3, &b_mu_HR_TileCellSignLayer3);
   fChain->SetBranchAddress("mu_HR_MSTrkT0_1", &mu_HR_MSTrkT0_1, &b_mu_HR_MSTrkT0_1);
   fChain->SetBranchAddress("mu_HR_MSTrkT0_2", &mu_HR_MSTrkT0_2, &b_mu_HR_MSTrkT0_2);
   fChain->SetBranchAddress("mu_HR_MSTrkT0_3", &mu_HR_MSTrkT0_3, &b_mu_HR_MSTrkT0_3);
   fChain->SetBranchAddress("mu_HR_cov_d0_exPV", &mu_HR_cov_d0_exPV, &b_mu_HR_cov_d0_exPV);
   fChain->SetBranchAddress("mu_HR_cov_z0_exPV", &mu_HR_cov_z0_exPV, &b_mu_HR_cov_z0_exPV);
   fChain->SetBranchAddress("mu_HR_cov_phi_exPV", &mu_HR_cov_phi_exPV, &b_mu_HR_cov_phi_exPV);
   fChain->SetBranchAddress("mu_HR_cov_theta_exPV", &mu_HR_cov_theta_exPV, &b_mu_HR_cov_theta_exPV);
   fChain->SetBranchAddress("mu_HR_cov_qoverp_exPV", &mu_HR_cov_qoverp_exPV, &b_mu_HR_cov_qoverp_exPV);
   fChain->SetBranchAddress("mu_HR_cov_d0_z0_exPV", &mu_HR_cov_d0_z0_exPV, &b_mu_HR_cov_d0_z0_exPV);
   fChain->SetBranchAddress("mu_HR_cov_d0_phi_exPV", &mu_HR_cov_d0_phi_exPV, &b_mu_HR_cov_d0_phi_exPV);
   fChain->SetBranchAddress("mu_HR_cov_d0_theta_exPV", &mu_HR_cov_d0_theta_exPV, &b_mu_HR_cov_d0_theta_exPV);
   fChain->SetBranchAddress("mu_HR_cov_d0_qoverp_exPV", &mu_HR_cov_d0_qoverp_exPV, &b_mu_HR_cov_d0_qoverp_exPV);
   fChain->SetBranchAddress("mu_HR_cov_z0_phi_exPV", &mu_HR_cov_z0_phi_exPV, &b_mu_HR_cov_z0_phi_exPV);
   fChain->SetBranchAddress("mu_HR_cov_z0_theta_exPV", &mu_HR_cov_z0_theta_exPV, &b_mu_HR_cov_z0_theta_exPV);
   fChain->SetBranchAddress("mu_HR_cov_z0_qoverp_exPV", &mu_HR_cov_z0_qoverp_exPV, &b_mu_HR_cov_z0_qoverp_exPV);
   fChain->SetBranchAddress("mu_HR_cov_phi_theta_exPV", &mu_HR_cov_phi_theta_exPV, &b_mu_HR_cov_phi_theta_exPV);
   fChain->SetBranchAddress("mu_HR_cov_phi_qoverp_exPV", &mu_HR_cov_phi_qoverp_exPV, &b_mu_HR_cov_phi_qoverp_exPV);
   fChain->SetBranchAddress("mu_HR_cov_theta_qoverp_exPV", &mu_HR_cov_theta_qoverp_exPV, &b_mu_HR_cov_theta_qoverp_exPV);
   fChain->SetBranchAddress("mu_HR_ms_d0", &mu_HR_ms_d0, &b_mu_HR_ms_d0);
   fChain->SetBranchAddress("mu_HR_ms_z0", &mu_HR_ms_z0, &b_mu_HR_ms_z0);
   fChain->SetBranchAddress("mu_HR_ms_phi", &mu_HR_ms_phi, &b_mu_HR_ms_phi);
   fChain->SetBranchAddress("mu_HR_ms_theta", &mu_HR_ms_theta, &b_mu_HR_ms_theta);
   fChain->SetBranchAddress("mu_HR_ms_qoverp", &mu_HR_ms_qoverp, &b_mu_HR_ms_qoverp);
   fChain->SetBranchAddress("mu_HR_id_d0", &mu_HR_id_d0, &b_mu_HR_id_d0);
   fChain->SetBranchAddress("mu_HR_id_z0", &mu_HR_id_z0, &b_mu_HR_id_z0);
   fChain->SetBranchAddress("mu_HR_id_phi", &mu_HR_id_phi, &b_mu_HR_id_phi);
   fChain->SetBranchAddress("mu_HR_id_theta", &mu_HR_id_theta, &b_mu_HR_id_theta);
   fChain->SetBranchAddress("mu_HR_id_qoverp", &mu_HR_id_qoverp, &b_mu_HR_id_qoverp);
   fChain->SetBranchAddress("mu_HR_me_d0", &mu_HR_me_d0, &b_mu_HR_me_d0);
   fChain->SetBranchAddress("mu_HR_me_z0", &mu_HR_me_z0, &b_mu_HR_me_z0);
   fChain->SetBranchAddress("mu_HR_me_phi", &mu_HR_me_phi, &b_mu_HR_me_phi);
   fChain->SetBranchAddress("mu_HR_me_theta", &mu_HR_me_theta, &b_mu_HR_me_theta);
   fChain->SetBranchAddress("mu_HR_me_qoverp", &mu_HR_me_qoverp, &b_mu_HR_me_qoverp);
   fChain->SetBranchAddress("mu_HR_ie_d0", &mu_HR_ie_d0, &b_mu_HR_ie_d0);
   fChain->SetBranchAddress("mu_HR_ie_z0", &mu_HR_ie_z0, &b_mu_HR_ie_z0);
   fChain->SetBranchAddress("mu_HR_ie_phi", &mu_HR_ie_phi, &b_mu_HR_ie_phi);
   fChain->SetBranchAddress("mu_HR_ie_theta", &mu_HR_ie_theta, &b_mu_HR_ie_theta);
   fChain->SetBranchAddress("mu_HR_ie_qoverp", &mu_HR_ie_qoverp, &b_mu_HR_ie_qoverp);
   fChain->SetBranchAddress("mu_HR_trackd0", &mu_HR_trackd0, &b_mu_HR_trackd0);
   fChain->SetBranchAddress("mu_HR_trackz0", &mu_HR_trackz0, &b_mu_HR_trackz0);
   fChain->SetBranchAddress("mu_HR_trackphi", &mu_HR_trackphi, &b_mu_HR_trackphi);
   fChain->SetBranchAddress("mu_HR_tracktheta", &mu_HR_tracktheta, &b_mu_HR_tracktheta);
   fChain->SetBranchAddress("mu_HR_trackqoverp", &mu_HR_trackqoverp, &b_mu_HR_trackqoverp);
   fChain->SetBranchAddress("mu_HR_trackcov_d0", &mu_HR_trackcov_d0, &b_mu_HR_trackcov_d0);
   fChain->SetBranchAddress("mu_HR_trackcov_z0", &mu_HR_trackcov_z0, &b_mu_HR_trackcov_z0);
   fChain->SetBranchAddress("mu_HR_trackcov_phi", &mu_HR_trackcov_phi, &b_mu_HR_trackcov_phi);
   fChain->SetBranchAddress("mu_HR_trackcov_theta", &mu_HR_trackcov_theta, &b_mu_HR_trackcov_theta);
   fChain->SetBranchAddress("mu_HR_trackcov_qoverp", &mu_HR_trackcov_qoverp, &b_mu_HR_trackcov_qoverp);
   fChain->SetBranchAddress("mu_HR_hastrack", &mu_HR_hastrack, &b_mu_HR_hastrack);
   fChain->SetBranchAddress("mu_HR_truth_dr", &mu_HR_truth_dr, &b_mu_HR_truth_dr);
   fChain->SetBranchAddress("mu_HR_truth_E", &mu_HR_truth_E, &b_mu_HR_truth_E);
   fChain->SetBranchAddress("mu_HR_truth_pt", &mu_HR_truth_pt, &b_mu_HR_truth_pt);
   fChain->SetBranchAddress("mu_HR_truth_eta", &mu_HR_truth_eta, &b_mu_HR_truth_eta);
   fChain->SetBranchAddress("mu_HR_truth_phi", &mu_HR_truth_phi, &b_mu_HR_truth_phi);
   fChain->SetBranchAddress("mu_HR_truth_type", &mu_HR_truth_type, &b_mu_HR_truth_type);
   fChain->SetBranchAddress("mu_HR_truth_status", &mu_HR_truth_status, &b_mu_HR_truth_status);
   fChain->SetBranchAddress("mu_HR_truth_barcode", &mu_HR_truth_barcode, &b_mu_HR_truth_barcode);
   fChain->SetBranchAddress("mu_HR_truth_mothertype", &mu_HR_truth_mothertype, &b_mu_HR_truth_mothertype);
   fChain->SetBranchAddress("mu_HR_truth_motherbarcode", &mu_HR_truth_motherbarcode, &b_mu_HR_truth_motherbarcode);
   fChain->SetBranchAddress("mu_HR_truth_matched", &mu_HR_truth_matched, &b_mu_HR_truth_matched);
   fChain->SetBranchAddress("mu_HR_EFCB_dr", &mu_HR_EFCB_dr, &b_mu_HR_EFCB_dr);
   fChain->SetBranchAddress("mu_HR_EFCB_n", &mu_HR_EFCB_n, &b_mu_HR_EFCB_n);
   fChain->SetBranchAddress("mu_HR_EFCB_MuonType", &mu_HR_EFCB_MuonType, &b_mu_HR_EFCB_MuonType);
   fChain->SetBranchAddress("mu_HR_EFCB_pt", &mu_HR_EFCB_pt, &b_mu_HR_EFCB_pt);
   fChain->SetBranchAddress("mu_HR_EFCB_eta", &mu_HR_EFCB_eta, &b_mu_HR_EFCB_eta);
   fChain->SetBranchAddress("mu_HR_EFCB_phi", &mu_HR_EFCB_phi, &b_mu_HR_EFCB_phi);
   fChain->SetBranchAddress("mu_HR_EFCB_hasCB", &mu_HR_EFCB_hasCB, &b_mu_HR_EFCB_hasCB);
   fChain->SetBranchAddress("mu_HR_EFCB_matched", &mu_HR_EFCB_matched, &b_mu_HR_EFCB_matched);
   fChain->SetBranchAddress("mu_HR_EFMG_dr", &mu_HR_EFMG_dr, &b_mu_HR_EFMG_dr);
   fChain->SetBranchAddress("mu_HR_EFMG_n", &mu_HR_EFMG_n, &b_mu_HR_EFMG_n);
   fChain->SetBranchAddress("mu_HR_EFMG_MuonType", &mu_HR_EFMG_MuonType, &b_mu_HR_EFMG_MuonType);
   fChain->SetBranchAddress("mu_HR_EFMG_pt", &mu_HR_EFMG_pt, &b_mu_HR_EFMG_pt);
   fChain->SetBranchAddress("mu_HR_EFMG_eta", &mu_HR_EFMG_eta, &b_mu_HR_EFMG_eta);
   fChain->SetBranchAddress("mu_HR_EFMG_phi", &mu_HR_EFMG_phi, &b_mu_HR_EFMG_phi);
   fChain->SetBranchAddress("mu_HR_EFMG_hasMG", &mu_HR_EFMG_hasMG, &b_mu_HR_EFMG_hasMG);
   fChain->SetBranchAddress("mu_HR_EFMG_matched", &mu_HR_EFMG_matched, &b_mu_HR_EFMG_matched);
   fChain->SetBranchAddress("mu_HR_EFME_dr", &mu_HR_EFME_dr, &b_mu_HR_EFME_dr);
   fChain->SetBranchAddress("mu_HR_EFME_n", &mu_HR_EFME_n, &b_mu_HR_EFME_n);
   fChain->SetBranchAddress("mu_HR_EFME_MuonType", &mu_HR_EFME_MuonType, &b_mu_HR_EFME_MuonType);
   fChain->SetBranchAddress("mu_HR_EFME_pt", &mu_HR_EFME_pt, &b_mu_HR_EFME_pt);
   fChain->SetBranchAddress("mu_HR_EFME_eta", &mu_HR_EFME_eta, &b_mu_HR_EFME_eta);
   fChain->SetBranchAddress("mu_HR_EFME_phi", &mu_HR_EFME_phi, &b_mu_HR_EFME_phi);
   fChain->SetBranchAddress("mu_HR_EFME_hasME", &mu_HR_EFME_hasME, &b_mu_HR_EFME_hasME);
   fChain->SetBranchAddress("mu_HR_EFME_matched", &mu_HR_EFME_matched, &b_mu_HR_EFME_matched);
   fChain->SetBranchAddress("mu_HR_L2CB_dr", &mu_HR_L2CB_dr, &b_mu_HR_L2CB_dr);
   fChain->SetBranchAddress("mu_HR_L2CB_pt", &mu_HR_L2CB_pt, &b_mu_HR_L2CB_pt);
   fChain->SetBranchAddress("mu_HR_L2CB_eta", &mu_HR_L2CB_eta, &b_mu_HR_L2CB_eta);
   fChain->SetBranchAddress("mu_HR_L2CB_phi", &mu_HR_L2CB_phi, &b_mu_HR_L2CB_phi);
   fChain->SetBranchAddress("mu_HR_L2CB_id_pt", &mu_HR_L2CB_id_pt, &b_mu_HR_L2CB_id_pt);
   fChain->SetBranchAddress("mu_HR_L2CB_ms_pt", &mu_HR_L2CB_ms_pt, &b_mu_HR_L2CB_ms_pt);
   fChain->SetBranchAddress("mu_HR_L2CB_matched", &mu_HR_L2CB_matched, &b_mu_HR_L2CB_matched);
   fChain->SetBranchAddress("mu_HR_L1_dr", &mu_HR_L1_dr, &b_mu_HR_L1_dr);
   fChain->SetBranchAddress("mu_HR_L1_pt", &mu_HR_L1_pt, &b_mu_HR_L1_pt);
   fChain->SetBranchAddress("mu_HR_L1_eta", &mu_HR_L1_eta, &b_mu_HR_L1_eta);
   fChain->SetBranchAddress("mu_HR_L1_phi", &mu_HR_L1_phi, &b_mu_HR_L1_phi);
   fChain->SetBranchAddress("mu_HR_L1_matched", &mu_HR_L1_matched, &b_mu_HR_L1_matched);
   fChain->SetBranchAddress("RoughRecoil_etx", &RoughRecoil_etx, &b_RoughRecoil_etx);
   fChain->SetBranchAddress("RoughRecoil_ety", &RoughRecoil_ety, &b_RoughRecoil_ety);
   fChain->SetBranchAddress("RoughRecoil_phi", &RoughRecoil_phi, &b_RoughRecoil_phi);
   fChain->SetBranchAddress("RoughRecoil_et", &RoughRecoil_et, &b_RoughRecoil_et);
   fChain->SetBranchAddress("RoughRecoil_sumet", &RoughRecoil_sumet, &b_RoughRecoil_sumet);
   fChain->SetBranchAddress("ueCorrection_etx", &ueCorrection_etx, &b_ueCorrection_etx);
   fChain->SetBranchAddress("ueCorrection_ety", &ueCorrection_ety, &b_ueCorrection_ety);
   fChain->SetBranchAddress("ueCorrection_phi", &ueCorrection_phi, &b_ueCorrection_phi);
   fChain->SetBranchAddress("ueCorrection_et", &ueCorrection_et, &b_ueCorrection_et);
   fChain->SetBranchAddress("ueCorrection_sumet", &ueCorrection_sumet, &b_ueCorrection_sumet);
   fChain->SetBranchAddress("jet_AntiKt4TopoEM_n", &jet_AntiKt4TopoEM_n, &b_jet_AntiKt4TopoEM_n);
   fChain->SetBranchAddress("jet_AntiKt4TopoEM_E", &jet_AntiKt4TopoEM_E, &b_jet_AntiKt4TopoEM_E);
   fChain->SetBranchAddress("jet_AntiKt4TopoEM_pt", &jet_AntiKt4TopoEM_pt, &b_jet_AntiKt4TopoEM_pt);
   fChain->SetBranchAddress("jet_AntiKt4TopoEM_m", &jet_AntiKt4TopoEM_m, &b_jet_AntiKt4TopoEM_m);
   fChain->SetBranchAddress("jet_AntiKt4TopoEM_eta", &jet_AntiKt4TopoEM_eta, &b_jet_AntiKt4TopoEM_eta);
   fChain->SetBranchAddress("jet_AntiKt4TopoEM_phi", &jet_AntiKt4TopoEM_phi, &b_jet_AntiKt4TopoEM_phi);
   fChain->SetBranchAddress("jet_AntiKt4TopoEM_n90", &jet_AntiKt4TopoEM_n90, &b_jet_AntiKt4TopoEM_n90);
   fChain->SetBranchAddress("jet_AntiKt4TopoEM_Timing", &jet_AntiKt4TopoEM_Timing, &b_jet_AntiKt4TopoEM_Timing);
   fChain->SetBranchAddress("jet_AntiKt4TopoEM_LArQuality", &jet_AntiKt4TopoEM_LArQuality, &b_jet_AntiKt4TopoEM_LArQuality);
   fChain->SetBranchAddress("jet_AntiKt4TopoEM_sumPtTrk", &jet_AntiKt4TopoEM_sumPtTrk, &b_jet_AntiKt4TopoEM_sumPtTrk);
   fChain->SetBranchAddress("jet_AntiKt4TopoEM_HECQuality", &jet_AntiKt4TopoEM_HECQuality, &b_jet_AntiKt4TopoEM_HECQuality);
   fChain->SetBranchAddress("jet_AntiKt4TopoEM_BCH_CORR_CELL", &jet_AntiKt4TopoEM_BCH_CORR_CELL, &b_jet_AntiKt4TopoEM_BCH_CORR_CELL);
   fChain->SetBranchAddress("jet_AntiKt4TopoEM_BCH_CORR_DOTX", &jet_AntiKt4TopoEM_BCH_CORR_DOTX, &b_jet_AntiKt4TopoEM_BCH_CORR_DOTX);
   fChain->SetBranchAddress("jet_AntiKt4TopoEM_SamplingMax", &jet_AntiKt4TopoEM_SamplingMax, &b_jet_AntiKt4TopoEM_SamplingMax);
   fChain->SetBranchAddress("jet_AntiKt4TopoEM_fracSamplingMax", &jet_AntiKt4TopoEM_fracSamplingMax, &b_jet_AntiKt4TopoEM_fracSamplingMax);
   fChain->SetBranchAddress("jet_AntiKt4TopoEM_hecf", &jet_AntiKt4TopoEM_hecf, &b_jet_AntiKt4TopoEM_hecf);
   fChain->SetBranchAddress("jet_AntiKt4TopoEM_tgap3f", &jet_AntiKt4TopoEM_tgap3f, &b_jet_AntiKt4TopoEM_tgap3f);
   fChain->SetBranchAddress("jet_AntiKt4TopoEM_isBadLoose", &jet_AntiKt4TopoEM_isBadLoose, &b_jet_AntiKt4TopoEM_isBadLoose);
   fChain->SetBranchAddress("jet_AntiKt4TopoEM_isBadMedium", &jet_AntiKt4TopoEM_isBadMedium, &b_jet_AntiKt4TopoEM_isBadMedium);
   fChain->SetBranchAddress("jet_AntiKt4TopoEM_isBadTight", &jet_AntiKt4TopoEM_isBadTight, &b_jet_AntiKt4TopoEM_isBadTight);
   fChain->SetBranchAddress("jet_AntiKt4TopoEM_emfrac", &jet_AntiKt4TopoEM_emfrac, &b_jet_AntiKt4TopoEM_emfrac);
   fChain->SetBranchAddress("jet_AntiKt4TopoEM_EMJES", &jet_AntiKt4TopoEM_EMJES, &b_jet_AntiKt4TopoEM_EMJES);
   fChain->SetBranchAddress("jet_AntiKt4TopoEM_GCWJES", &jet_AntiKt4TopoEM_GCWJES, &b_jet_AntiKt4TopoEM_GCWJES);
   fChain->SetBranchAddress("jet_AntiKt4TopoEM_emscale_E", &jet_AntiKt4TopoEM_emscale_E, &b_jet_AntiKt4TopoEM_emscale_E);
   fChain->SetBranchAddress("jet_AntiKt4TopoEM_emscale_pt", &jet_AntiKt4TopoEM_emscale_pt, &b_jet_AntiKt4TopoEM_emscale_pt);
   fChain->SetBranchAddress("jet_AntiKt4TopoEM_emscale_m", &jet_AntiKt4TopoEM_emscale_m, &b_jet_AntiKt4TopoEM_emscale_m);
   fChain->SetBranchAddress("jet_AntiKt4TopoEM_emscale_eta", &jet_AntiKt4TopoEM_emscale_eta, &b_jet_AntiKt4TopoEM_emscale_eta);
   fChain->SetBranchAddress("jet_AntiKt4TopoEM_emscale_phi", &jet_AntiKt4TopoEM_emscale_phi, &b_jet_AntiKt4TopoEM_emscale_phi);
   fChain->SetBranchAddress("jet_AntiKt6TopoEM_n", &jet_AntiKt6TopoEM_n, &b_jet_AntiKt6TopoEM_n);
   fChain->SetBranchAddress("jet_AntiKt6TopoEM_E", &jet_AntiKt6TopoEM_E, &b_jet_AntiKt6TopoEM_E);
   fChain->SetBranchAddress("jet_AntiKt6TopoEM_pt", &jet_AntiKt6TopoEM_pt, &b_jet_AntiKt6TopoEM_pt);
   fChain->SetBranchAddress("jet_AntiKt6TopoEM_m", &jet_AntiKt6TopoEM_m, &b_jet_AntiKt6TopoEM_m);
   fChain->SetBranchAddress("jet_AntiKt6TopoEM_eta", &jet_AntiKt6TopoEM_eta, &b_jet_AntiKt6TopoEM_eta);
   fChain->SetBranchAddress("jet_AntiKt6TopoEM_phi", &jet_AntiKt6TopoEM_phi, &b_jet_AntiKt6TopoEM_phi);
   fChain->SetBranchAddress("jet_AntiKt6TopoEM_n90", &jet_AntiKt6TopoEM_n90, &b_jet_AntiKt6TopoEM_n90);
   fChain->SetBranchAddress("jet_AntiKt6TopoEM_Timing", &jet_AntiKt6TopoEM_Timing, &b_jet_AntiKt6TopoEM_Timing);
   fChain->SetBranchAddress("jet_AntiKt6TopoEM_LArQuality", &jet_AntiKt6TopoEM_LArQuality, &b_jet_AntiKt6TopoEM_LArQuality);
   fChain->SetBranchAddress("jet_AntiKt6TopoEM_sumPtTrk", &jet_AntiKt6TopoEM_sumPtTrk, &b_jet_AntiKt6TopoEM_sumPtTrk);
   fChain->SetBranchAddress("jet_AntiKt6TopoEM_HECQuality", &jet_AntiKt6TopoEM_HECQuality, &b_jet_AntiKt6TopoEM_HECQuality);
   fChain->SetBranchAddress("jet_AntiKt6TopoEM_BCH_CORR_CELL", &jet_AntiKt6TopoEM_BCH_CORR_CELL, &b_jet_AntiKt6TopoEM_BCH_CORR_CELL);
   fChain->SetBranchAddress("jet_AntiKt6TopoEM_BCH_CORR_DOTX", &jet_AntiKt6TopoEM_BCH_CORR_DOTX, &b_jet_AntiKt6TopoEM_BCH_CORR_DOTX);
   fChain->SetBranchAddress("jet_AntiKt6TopoEM_SamplingMax", &jet_AntiKt6TopoEM_SamplingMax, &b_jet_AntiKt6TopoEM_SamplingMax);
   fChain->SetBranchAddress("jet_AntiKt6TopoEM_fracSamplingMax", &jet_AntiKt6TopoEM_fracSamplingMax, &b_jet_AntiKt6TopoEM_fracSamplingMax);
   fChain->SetBranchAddress("jet_AntiKt6TopoEM_hecf", &jet_AntiKt6TopoEM_hecf, &b_jet_AntiKt6TopoEM_hecf);
   fChain->SetBranchAddress("jet_AntiKt6TopoEM_tgap3f", &jet_AntiKt6TopoEM_tgap3f, &b_jet_AntiKt6TopoEM_tgap3f);
   fChain->SetBranchAddress("jet_AntiKt6TopoEM_isBadLoose", &jet_AntiKt6TopoEM_isBadLoose, &b_jet_AntiKt6TopoEM_isBadLoose);
   fChain->SetBranchAddress("jet_AntiKt6TopoEM_isBadMedium", &jet_AntiKt6TopoEM_isBadMedium, &b_jet_AntiKt6TopoEM_isBadMedium);
   fChain->SetBranchAddress("jet_AntiKt6TopoEM_isBadTight", &jet_AntiKt6TopoEM_isBadTight, &b_jet_AntiKt6TopoEM_isBadTight);
   fChain->SetBranchAddress("jet_AntiKt6TopoEM_emfrac", &jet_AntiKt6TopoEM_emfrac, &b_jet_AntiKt6TopoEM_emfrac);
   fChain->SetBranchAddress("jet_AntiKt6TopoEM_EMJES", &jet_AntiKt6TopoEM_EMJES, &b_jet_AntiKt6TopoEM_EMJES);
   fChain->SetBranchAddress("jet_AntiKt6TopoEM_GCWJES", &jet_AntiKt6TopoEM_GCWJES, &b_jet_AntiKt6TopoEM_GCWJES);
   fChain->SetBranchAddress("jet_AntiKt6TopoEM_emscale_E", &jet_AntiKt6TopoEM_emscale_E, &b_jet_AntiKt6TopoEM_emscale_E);
   fChain->SetBranchAddress("jet_AntiKt6TopoEM_emscale_pt", &jet_AntiKt6TopoEM_emscale_pt, &b_jet_AntiKt6TopoEM_emscale_pt);
   fChain->SetBranchAddress("jet_AntiKt6TopoEM_emscale_m", &jet_AntiKt6TopoEM_emscale_m, &b_jet_AntiKt6TopoEM_emscale_m);
   fChain->SetBranchAddress("jet_AntiKt6TopoEM_emscale_eta", &jet_AntiKt6TopoEM_emscale_eta, &b_jet_AntiKt6TopoEM_emscale_eta);
   fChain->SetBranchAddress("jet_AntiKt6TopoEM_emscale_phi", &jet_AntiKt6TopoEM_emscale_phi, &b_jet_AntiKt6TopoEM_emscale_phi);
   fChain->SetBranchAddress("jet_AntiKt6LCTopo_n", &jet_AntiKt6LCTopo_n, &b_jet_AntiKt6LCTopo_n);
   fChain->SetBranchAddress("jet_AntiKt6LCTopo_E", &jet_AntiKt6LCTopo_E, &b_jet_AntiKt6LCTopo_E);
   fChain->SetBranchAddress("jet_AntiKt6LCTopo_pt", &jet_AntiKt6LCTopo_pt, &b_jet_AntiKt6LCTopo_pt);
   fChain->SetBranchAddress("jet_AntiKt6LCTopo_m", &jet_AntiKt6LCTopo_m, &b_jet_AntiKt6LCTopo_m);
   fChain->SetBranchAddress("jet_AntiKt6LCTopo_eta", &jet_AntiKt6LCTopo_eta, &b_jet_AntiKt6LCTopo_eta);
   fChain->SetBranchAddress("jet_AntiKt6LCTopo_phi", &jet_AntiKt6LCTopo_phi, &b_jet_AntiKt6LCTopo_phi);
   fChain->SetBranchAddress("jet_AntiKt6LCTopo_n90", &jet_AntiKt6LCTopo_n90, &b_jet_AntiKt6LCTopo_n90);
   fChain->SetBranchAddress("jet_AntiKt6LCTopo_Timing", &jet_AntiKt6LCTopo_Timing, &b_jet_AntiKt6LCTopo_Timing);
   fChain->SetBranchAddress("jet_AntiKt6LCTopo_LArQuality", &jet_AntiKt6LCTopo_LArQuality, &b_jet_AntiKt6LCTopo_LArQuality);
   fChain->SetBranchAddress("jet_AntiKt6LCTopo_sumPtTrk", &jet_AntiKt6LCTopo_sumPtTrk, &b_jet_AntiKt6LCTopo_sumPtTrk);
   fChain->SetBranchAddress("jet_AntiKt6LCTopo_HECQuality", &jet_AntiKt6LCTopo_HECQuality, &b_jet_AntiKt6LCTopo_HECQuality);
   fChain->SetBranchAddress("jet_AntiKt6LCTopo_BCH_CORR_CELL", &jet_AntiKt6LCTopo_BCH_CORR_CELL, &b_jet_AntiKt6LCTopo_BCH_CORR_CELL);
   fChain->SetBranchAddress("jet_AntiKt6LCTopo_BCH_CORR_DOTX", &jet_AntiKt6LCTopo_BCH_CORR_DOTX, &b_jet_AntiKt6LCTopo_BCH_CORR_DOTX);
   fChain->SetBranchAddress("jet_AntiKt6LCTopo_SamplingMax", &jet_AntiKt6LCTopo_SamplingMax, &b_jet_AntiKt6LCTopo_SamplingMax);
   fChain->SetBranchAddress("jet_AntiKt6LCTopo_fracSamplingMax", &jet_AntiKt6LCTopo_fracSamplingMax, &b_jet_AntiKt6LCTopo_fracSamplingMax);
   fChain->SetBranchAddress("jet_AntiKt6LCTopo_hecf", &jet_AntiKt6LCTopo_hecf, &b_jet_AntiKt6LCTopo_hecf);
   fChain->SetBranchAddress("jet_AntiKt6LCTopo_tgap3f", &jet_AntiKt6LCTopo_tgap3f, &b_jet_AntiKt6LCTopo_tgap3f);
   fChain->SetBranchAddress("jet_AntiKt6LCTopo_isBadLoose", &jet_AntiKt6LCTopo_isBadLoose, &b_jet_AntiKt6LCTopo_isBadLoose);
   fChain->SetBranchAddress("jet_AntiKt6LCTopo_isBadMedium", &jet_AntiKt6LCTopo_isBadMedium, &b_jet_AntiKt6LCTopo_isBadMedium);
   fChain->SetBranchAddress("jet_AntiKt6LCTopo_isBadTight", &jet_AntiKt6LCTopo_isBadTight, &b_jet_AntiKt6LCTopo_isBadTight);
   fChain->SetBranchAddress("jet_AntiKt6LCTopo_emfrac", &jet_AntiKt6LCTopo_emfrac, &b_jet_AntiKt6LCTopo_emfrac);
   fChain->SetBranchAddress("jet_AntiKt6LCTopo_EMJES", &jet_AntiKt6LCTopo_EMJES, &b_jet_AntiKt6LCTopo_EMJES);
   fChain->SetBranchAddress("jet_AntiKt6LCTopo_GCWJES", &jet_AntiKt6LCTopo_GCWJES, &b_jet_AntiKt6LCTopo_GCWJES);
   fChain->SetBranchAddress("jet_AntiKt6LCTopo_emscale_E", &jet_AntiKt6LCTopo_emscale_E, &b_jet_AntiKt6LCTopo_emscale_E);
   fChain->SetBranchAddress("jet_AntiKt6LCTopo_emscale_pt", &jet_AntiKt6LCTopo_emscale_pt, &b_jet_AntiKt6LCTopo_emscale_pt);
   fChain->SetBranchAddress("jet_AntiKt6LCTopo_emscale_m", &jet_AntiKt6LCTopo_emscale_m, &b_jet_AntiKt6LCTopo_emscale_m);
   fChain->SetBranchAddress("jet_AntiKt6LCTopo_emscale_eta", &jet_AntiKt6LCTopo_emscale_eta, &b_jet_AntiKt6LCTopo_emscale_eta);
   fChain->SetBranchAddress("jet_AntiKt6LCTopo_emscale_phi", &jet_AntiKt6LCTopo_emscale_phi, &b_jet_AntiKt6LCTopo_emscale_phi);
   fChain->SetBranchAddress("MET_RefFinal_etx", &MET_RefFinal_etx, &b_MET_RefFinal_etx);
   fChain->SetBranchAddress("MET_RefFinal_ety", &MET_RefFinal_ety, &b_MET_RefFinal_ety);
   fChain->SetBranchAddress("MET_RefFinal_phi", &MET_RefFinal_phi, &b_MET_RefFinal_phi);
   fChain->SetBranchAddress("MET_RefFinal_et", &MET_RefFinal_et, &b_MET_RefFinal_et);
   fChain->SetBranchAddress("MET_RefFinal_sumet", &MET_RefFinal_sumet, &b_MET_RefFinal_sumet);
   fChain->SetBranchAddress("MET_RefFinal_etx_CentralReg", &MET_RefFinal_etx_CentralReg, &b_MET_RefFinal_etx_CentralReg);
   fChain->SetBranchAddress("MET_RefFinal_ety_CentralReg", &MET_RefFinal_ety_CentralReg, &b_MET_RefFinal_ety_CentralReg);
   fChain->SetBranchAddress("MET_RefFinal_sumet_CentralReg", &MET_RefFinal_sumet_CentralReg, &b_MET_RefFinal_sumet_CentralReg);
   fChain->SetBranchAddress("MET_RefFinal_phi_CentralReg", &MET_RefFinal_phi_CentralReg, &b_MET_RefFinal_phi_CentralReg);
   fChain->SetBranchAddress("MET_RefFinal_etx_EndcapRegion", &MET_RefFinal_etx_EndcapRegion, &b_MET_RefFinal_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_RefFinal_ety_EndcapRegion", &MET_RefFinal_ety_EndcapRegion, &b_MET_RefFinal_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_RefFinal_sumet_EndcapRegion", &MET_RefFinal_sumet_EndcapRegion, &b_MET_RefFinal_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_RefFinal_phi_EndcapRegion", &MET_RefFinal_phi_EndcapRegion, &b_MET_RefFinal_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_RefFinal_etx_ForwardReg", &MET_RefFinal_etx_ForwardReg, &b_MET_RefFinal_etx_ForwardReg);
   fChain->SetBranchAddress("MET_RefFinal_ety_ForwardReg", &MET_RefFinal_ety_ForwardReg, &b_MET_RefFinal_ety_ForwardReg);
   fChain->SetBranchAddress("MET_RefFinal_sumet_ForwardReg", &MET_RefFinal_sumet_ForwardReg, &b_MET_RefFinal_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_RefFinal_phi_ForwardReg", &MET_RefFinal_phi_ForwardReg, &b_MET_RefFinal_phi_ForwardReg);
   fChain->SetBranchAddress("MET_Cryo_etx", &MET_Cryo_etx, &b_MET_Cryo_etx);
   fChain->SetBranchAddress("MET_Cryo_ety", &MET_Cryo_ety, &b_MET_Cryo_ety);
   fChain->SetBranchAddress("MET_Cryo_phi", &MET_Cryo_phi, &b_MET_Cryo_phi);
   fChain->SetBranchAddress("MET_Cryo_et", &MET_Cryo_et, &b_MET_Cryo_et);
   fChain->SetBranchAddress("MET_Cryo_sumet", &MET_Cryo_sumet, &b_MET_Cryo_sumet);
   fChain->SetBranchAddress("MET_Cryo_etx_CentralReg", &MET_Cryo_etx_CentralReg, &b_MET_Cryo_etx_CentralReg);
   fChain->SetBranchAddress("MET_Cryo_ety_CentralReg", &MET_Cryo_ety_CentralReg, &b_MET_Cryo_ety_CentralReg);
   fChain->SetBranchAddress("MET_Cryo_sumet_CentralReg", &MET_Cryo_sumet_CentralReg, &b_MET_Cryo_sumet_CentralReg);
   fChain->SetBranchAddress("MET_Cryo_phi_CentralReg", &MET_Cryo_phi_CentralReg, &b_MET_Cryo_phi_CentralReg);
   fChain->SetBranchAddress("MET_Cryo_etx_EndcapRegion", &MET_Cryo_etx_EndcapRegion, &b_MET_Cryo_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_Cryo_ety_EndcapRegion", &MET_Cryo_ety_EndcapRegion, &b_MET_Cryo_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_Cryo_sumet_EndcapRegion", &MET_Cryo_sumet_EndcapRegion, &b_MET_Cryo_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_Cryo_phi_EndcapRegion", &MET_Cryo_phi_EndcapRegion, &b_MET_Cryo_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_Cryo_etx_ForwardReg", &MET_Cryo_etx_ForwardReg, &b_MET_Cryo_etx_ForwardReg);
   fChain->SetBranchAddress("MET_Cryo_ety_ForwardReg", &MET_Cryo_ety_ForwardReg, &b_MET_Cryo_ety_ForwardReg);
   fChain->SetBranchAddress("MET_Cryo_sumet_ForwardReg", &MET_Cryo_sumet_ForwardReg, &b_MET_Cryo_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_Cryo_phi_ForwardReg", &MET_Cryo_phi_ForwardReg, &b_MET_Cryo_phi_ForwardReg);
   fChain->SetBranchAddress("MET_RefEle_etx", &MET_RefEle_etx, &b_MET_RefEle_etx);
   fChain->SetBranchAddress("MET_RefEle_ety", &MET_RefEle_ety, &b_MET_RefEle_ety);
   fChain->SetBranchAddress("MET_RefEle_phi", &MET_RefEle_phi, &b_MET_RefEle_phi);
   fChain->SetBranchAddress("MET_RefEle_et", &MET_RefEle_et, &b_MET_RefEle_et);
   fChain->SetBranchAddress("MET_RefEle_sumet", &MET_RefEle_sumet, &b_MET_RefEle_sumet);
   fChain->SetBranchAddress("MET_RefEle_etx_CentralReg", &MET_RefEle_etx_CentralReg, &b_MET_RefEle_etx_CentralReg);
   fChain->SetBranchAddress("MET_RefEle_ety_CentralReg", &MET_RefEle_ety_CentralReg, &b_MET_RefEle_ety_CentralReg);
   fChain->SetBranchAddress("MET_RefEle_sumet_CentralReg", &MET_RefEle_sumet_CentralReg, &b_MET_RefEle_sumet_CentralReg);
   fChain->SetBranchAddress("MET_RefEle_phi_CentralReg", &MET_RefEle_phi_CentralReg, &b_MET_RefEle_phi_CentralReg);
   fChain->SetBranchAddress("MET_RefEle_etx_EndcapRegion", &MET_RefEle_etx_EndcapRegion, &b_MET_RefEle_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_RefEle_ety_EndcapRegion", &MET_RefEle_ety_EndcapRegion, &b_MET_RefEle_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_RefEle_sumet_EndcapRegion", &MET_RefEle_sumet_EndcapRegion, &b_MET_RefEle_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_RefEle_phi_EndcapRegion", &MET_RefEle_phi_EndcapRegion, &b_MET_RefEle_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_RefEle_etx_ForwardReg", &MET_RefEle_etx_ForwardReg, &b_MET_RefEle_etx_ForwardReg);
   fChain->SetBranchAddress("MET_RefEle_ety_ForwardReg", &MET_RefEle_ety_ForwardReg, &b_MET_RefEle_ety_ForwardReg);
   fChain->SetBranchAddress("MET_RefEle_sumet_ForwardReg", &MET_RefEle_sumet_ForwardReg, &b_MET_RefEle_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_RefEle_phi_ForwardReg", &MET_RefEle_phi_ForwardReg, &b_MET_RefEle_phi_ForwardReg);
   fChain->SetBranchAddress("MET_RefJet_etx", &MET_RefJet_etx, &b_MET_RefJet_etx);
   fChain->SetBranchAddress("MET_RefJet_ety", &MET_RefJet_ety, &b_MET_RefJet_ety);
   fChain->SetBranchAddress("MET_RefJet_phi", &MET_RefJet_phi, &b_MET_RefJet_phi);
   fChain->SetBranchAddress("MET_RefJet_et", &MET_RefJet_et, &b_MET_RefJet_et);
   fChain->SetBranchAddress("MET_RefJet_sumet", &MET_RefJet_sumet, &b_MET_RefJet_sumet);
   fChain->SetBranchAddress("MET_RefJet_etx_CentralReg", &MET_RefJet_etx_CentralReg, &b_MET_RefJet_etx_CentralReg);
   fChain->SetBranchAddress("MET_RefJet_ety_CentralReg", &MET_RefJet_ety_CentralReg, &b_MET_RefJet_ety_CentralReg);
   fChain->SetBranchAddress("MET_RefJet_sumet_CentralReg", &MET_RefJet_sumet_CentralReg, &b_MET_RefJet_sumet_CentralReg);
   fChain->SetBranchAddress("MET_RefJet_phi_CentralReg", &MET_RefJet_phi_CentralReg, &b_MET_RefJet_phi_CentralReg);
   fChain->SetBranchAddress("MET_RefJet_etx_EndcapRegion", &MET_RefJet_etx_EndcapRegion, &b_MET_RefJet_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_RefJet_ety_EndcapRegion", &MET_RefJet_ety_EndcapRegion, &b_MET_RefJet_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_RefJet_sumet_EndcapRegion", &MET_RefJet_sumet_EndcapRegion, &b_MET_RefJet_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_RefJet_phi_EndcapRegion", &MET_RefJet_phi_EndcapRegion, &b_MET_RefJet_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_RefJet_etx_ForwardReg", &MET_RefJet_etx_ForwardReg, &b_MET_RefJet_etx_ForwardReg);
   fChain->SetBranchAddress("MET_RefJet_ety_ForwardReg", &MET_RefJet_ety_ForwardReg, &b_MET_RefJet_ety_ForwardReg);
   fChain->SetBranchAddress("MET_RefJet_sumet_ForwardReg", &MET_RefJet_sumet_ForwardReg, &b_MET_RefJet_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_RefJet_phi_ForwardReg", &MET_RefJet_phi_ForwardReg, &b_MET_RefJet_phi_ForwardReg);
   fChain->SetBranchAddress("MET_SoftJets_etx", &MET_SoftJets_etx, &b_MET_SoftJets_etx);
   fChain->SetBranchAddress("MET_SoftJets_ety", &MET_SoftJets_ety, &b_MET_SoftJets_ety);
   fChain->SetBranchAddress("MET_SoftJets_phi", &MET_SoftJets_phi, &b_MET_SoftJets_phi);
   fChain->SetBranchAddress("MET_SoftJets_et", &MET_SoftJets_et, &b_MET_SoftJets_et);
   fChain->SetBranchAddress("MET_SoftJets_sumet", &MET_SoftJets_sumet, &b_MET_SoftJets_sumet);
   fChain->SetBranchAddress("MET_SoftJets_etx_CentralReg", &MET_SoftJets_etx_CentralReg, &b_MET_SoftJets_etx_CentralReg);
   fChain->SetBranchAddress("MET_SoftJets_ety_CentralReg", &MET_SoftJets_ety_CentralReg, &b_MET_SoftJets_ety_CentralReg);
   fChain->SetBranchAddress("MET_SoftJets_sumet_CentralReg", &MET_SoftJets_sumet_CentralReg, &b_MET_SoftJets_sumet_CentralReg);
   fChain->SetBranchAddress("MET_SoftJets_phi_CentralReg", &MET_SoftJets_phi_CentralReg, &b_MET_SoftJets_phi_CentralReg);
   fChain->SetBranchAddress("MET_SoftJets_etx_EndcapRegion", &MET_SoftJets_etx_EndcapRegion, &b_MET_SoftJets_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_SoftJets_ety_EndcapRegion", &MET_SoftJets_ety_EndcapRegion, &b_MET_SoftJets_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_SoftJets_sumet_EndcapRegion", &MET_SoftJets_sumet_EndcapRegion, &b_MET_SoftJets_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_SoftJets_phi_EndcapRegion", &MET_SoftJets_phi_EndcapRegion, &b_MET_SoftJets_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_SoftJets_etx_ForwardReg", &MET_SoftJets_etx_ForwardReg, &b_MET_SoftJets_etx_ForwardReg);
   fChain->SetBranchAddress("MET_SoftJets_ety_ForwardReg", &MET_SoftJets_ety_ForwardReg, &b_MET_SoftJets_ety_ForwardReg);
   fChain->SetBranchAddress("MET_SoftJets_sumet_ForwardReg", &MET_SoftJets_sumet_ForwardReg, &b_MET_SoftJets_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_SoftJets_phi_ForwardReg", &MET_SoftJets_phi_ForwardReg, &b_MET_SoftJets_phi_ForwardReg);
   fChain->SetBranchAddress("MET_RefMuon_etx", &MET_RefMuon_etx, &b_MET_RefMuon_etx);
   fChain->SetBranchAddress("MET_RefMuon_ety", &MET_RefMuon_ety, &b_MET_RefMuon_ety);
   fChain->SetBranchAddress("MET_RefMuon_phi", &MET_RefMuon_phi, &b_MET_RefMuon_phi);
   fChain->SetBranchAddress("MET_RefMuon_et", &MET_RefMuon_et, &b_MET_RefMuon_et);
   fChain->SetBranchAddress("MET_RefMuon_sumet", &MET_RefMuon_sumet, &b_MET_RefMuon_sumet);
   fChain->SetBranchAddress("MET_RefMuon_etx_CentralReg", &MET_RefMuon_etx_CentralReg, &b_MET_RefMuon_etx_CentralReg);
   fChain->SetBranchAddress("MET_RefMuon_ety_CentralReg", &MET_RefMuon_ety_CentralReg, &b_MET_RefMuon_ety_CentralReg);
   fChain->SetBranchAddress("MET_RefMuon_sumet_CentralReg", &MET_RefMuon_sumet_CentralReg, &b_MET_RefMuon_sumet_CentralReg);
   fChain->SetBranchAddress("MET_RefMuon_phi_CentralReg", &MET_RefMuon_phi_CentralReg, &b_MET_RefMuon_phi_CentralReg);
   fChain->SetBranchAddress("MET_RefMuon_etx_EndcapRegion", &MET_RefMuon_etx_EndcapRegion, &b_MET_RefMuon_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_RefMuon_ety_EndcapRegion", &MET_RefMuon_ety_EndcapRegion, &b_MET_RefMuon_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_RefMuon_sumet_EndcapRegion", &MET_RefMuon_sumet_EndcapRegion, &b_MET_RefMuon_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_RefMuon_phi_EndcapRegion", &MET_RefMuon_phi_EndcapRegion, &b_MET_RefMuon_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_RefMuon_etx_ForwardReg", &MET_RefMuon_etx_ForwardReg, &b_MET_RefMuon_etx_ForwardReg);
   fChain->SetBranchAddress("MET_RefMuon_ety_ForwardReg", &MET_RefMuon_ety_ForwardReg, &b_MET_RefMuon_ety_ForwardReg);
   fChain->SetBranchAddress("MET_RefMuon_sumet_ForwardReg", &MET_RefMuon_sumet_ForwardReg, &b_MET_RefMuon_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_RefMuon_phi_ForwardReg", &MET_RefMuon_phi_ForwardReg, &b_MET_RefMuon_phi_ForwardReg);
   fChain->SetBranchAddress("MET_RefMuon_Staco_etx", &MET_RefMuon_Staco_etx, &b_MET_RefMuon_Staco_etx);
   fChain->SetBranchAddress("MET_RefMuon_Staco_ety", &MET_RefMuon_Staco_ety, &b_MET_RefMuon_Staco_ety);
   fChain->SetBranchAddress("MET_RefMuon_Staco_phi", &MET_RefMuon_Staco_phi, &b_MET_RefMuon_Staco_phi);
   fChain->SetBranchAddress("MET_RefMuon_Staco_et", &MET_RefMuon_Staco_et, &b_MET_RefMuon_Staco_et);
   fChain->SetBranchAddress("MET_RefMuon_Staco_sumet", &MET_RefMuon_Staco_sumet, &b_MET_RefMuon_Staco_sumet);
   fChain->SetBranchAddress("MET_RefMuon_Staco_etx_CentralReg", &MET_RefMuon_Staco_etx_CentralReg, &b_MET_RefMuon_Staco_etx_CentralReg);
   fChain->SetBranchAddress("MET_RefMuon_Staco_ety_CentralReg", &MET_RefMuon_Staco_ety_CentralReg, &b_MET_RefMuon_Staco_ety_CentralReg);
   fChain->SetBranchAddress("MET_RefMuon_Staco_sumet_CentralReg", &MET_RefMuon_Staco_sumet_CentralReg, &b_MET_RefMuon_Staco_sumet_CentralReg);
   fChain->SetBranchAddress("MET_RefMuon_Staco_phi_CentralReg", &MET_RefMuon_Staco_phi_CentralReg, &b_MET_RefMuon_Staco_phi_CentralReg);
   fChain->SetBranchAddress("MET_RefMuon_Staco_etx_EndcapRegion", &MET_RefMuon_Staco_etx_EndcapRegion, &b_MET_RefMuon_Staco_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_RefMuon_Staco_ety_EndcapRegion", &MET_RefMuon_Staco_ety_EndcapRegion, &b_MET_RefMuon_Staco_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_RefMuon_Staco_sumet_EndcapRegion", &MET_RefMuon_Staco_sumet_EndcapRegion, &b_MET_RefMuon_Staco_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_RefMuon_Staco_phi_EndcapRegion", &MET_RefMuon_Staco_phi_EndcapRegion, &b_MET_RefMuon_Staco_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_RefMuon_Staco_etx_ForwardReg", &MET_RefMuon_Staco_etx_ForwardReg, &b_MET_RefMuon_Staco_etx_ForwardReg);
   fChain->SetBranchAddress("MET_RefMuon_Staco_ety_ForwardReg", &MET_RefMuon_Staco_ety_ForwardReg, &b_MET_RefMuon_Staco_ety_ForwardReg);
   fChain->SetBranchAddress("MET_RefMuon_Staco_sumet_ForwardReg", &MET_RefMuon_Staco_sumet_ForwardReg, &b_MET_RefMuon_Staco_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_RefMuon_Staco_phi_ForwardReg", &MET_RefMuon_Staco_phi_ForwardReg, &b_MET_RefMuon_Staco_phi_ForwardReg);
   fChain->SetBranchAddress("MET_RefMuon_Muid_etx", &MET_RefMuon_Muid_etx, &b_MET_RefMuon_Muid_etx);
   fChain->SetBranchAddress("MET_RefMuon_Muid_ety", &MET_RefMuon_Muid_ety, &b_MET_RefMuon_Muid_ety);
   fChain->SetBranchAddress("MET_RefMuon_Muid_phi", &MET_RefMuon_Muid_phi, &b_MET_RefMuon_Muid_phi);
   fChain->SetBranchAddress("MET_RefMuon_Muid_et", &MET_RefMuon_Muid_et, &b_MET_RefMuon_Muid_et);
   fChain->SetBranchAddress("MET_RefMuon_Muid_sumet", &MET_RefMuon_Muid_sumet, &b_MET_RefMuon_Muid_sumet);
   fChain->SetBranchAddress("MET_RefMuon_Muid_etx_CentralReg", &MET_RefMuon_Muid_etx_CentralReg, &b_MET_RefMuon_Muid_etx_CentralReg);
   fChain->SetBranchAddress("MET_RefMuon_Muid_ety_CentralReg", &MET_RefMuon_Muid_ety_CentralReg, &b_MET_RefMuon_Muid_ety_CentralReg);
   fChain->SetBranchAddress("MET_RefMuon_Muid_sumet_CentralReg", &MET_RefMuon_Muid_sumet_CentralReg, &b_MET_RefMuon_Muid_sumet_CentralReg);
   fChain->SetBranchAddress("MET_RefMuon_Muid_phi_CentralReg", &MET_RefMuon_Muid_phi_CentralReg, &b_MET_RefMuon_Muid_phi_CentralReg);
   fChain->SetBranchAddress("MET_RefMuon_Muid_etx_EndcapRegion", &MET_RefMuon_Muid_etx_EndcapRegion, &b_MET_RefMuon_Muid_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_RefMuon_Muid_ety_EndcapRegion", &MET_RefMuon_Muid_ety_EndcapRegion, &b_MET_RefMuon_Muid_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_RefMuon_Muid_sumet_EndcapRegion", &MET_RefMuon_Muid_sumet_EndcapRegion, &b_MET_RefMuon_Muid_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_RefMuon_Muid_phi_EndcapRegion", &MET_RefMuon_Muid_phi_EndcapRegion, &b_MET_RefMuon_Muid_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_RefMuon_Muid_etx_ForwardReg", &MET_RefMuon_Muid_etx_ForwardReg, &b_MET_RefMuon_Muid_etx_ForwardReg);
   fChain->SetBranchAddress("MET_RefMuon_Muid_ety_ForwardReg", &MET_RefMuon_Muid_ety_ForwardReg, &b_MET_RefMuon_Muid_ety_ForwardReg);
   fChain->SetBranchAddress("MET_RefMuon_Muid_sumet_ForwardReg", &MET_RefMuon_Muid_sumet_ForwardReg, &b_MET_RefMuon_Muid_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_RefMuon_Muid_phi_ForwardReg", &MET_RefMuon_Muid_phi_ForwardReg, &b_MET_RefMuon_Muid_phi_ForwardReg);
   fChain->SetBranchAddress("MET_RefGamma_etx", &MET_RefGamma_etx, &b_MET_RefGamma_etx);
   fChain->SetBranchAddress("MET_RefGamma_ety", &MET_RefGamma_ety, &b_MET_RefGamma_ety);
   fChain->SetBranchAddress("MET_RefGamma_phi", &MET_RefGamma_phi, &b_MET_RefGamma_phi);
   fChain->SetBranchAddress("MET_RefGamma_et", &MET_RefGamma_et, &b_MET_RefGamma_et);
   fChain->SetBranchAddress("MET_RefGamma_sumet", &MET_RefGamma_sumet, &b_MET_RefGamma_sumet);
   fChain->SetBranchAddress("MET_RefGamma_etx_CentralReg", &MET_RefGamma_etx_CentralReg, &b_MET_RefGamma_etx_CentralReg);
   fChain->SetBranchAddress("MET_RefGamma_ety_CentralReg", &MET_RefGamma_ety_CentralReg, &b_MET_RefGamma_ety_CentralReg);
   fChain->SetBranchAddress("MET_RefGamma_sumet_CentralReg", &MET_RefGamma_sumet_CentralReg, &b_MET_RefGamma_sumet_CentralReg);
   fChain->SetBranchAddress("MET_RefGamma_phi_CentralReg", &MET_RefGamma_phi_CentralReg, &b_MET_RefGamma_phi_CentralReg);
   fChain->SetBranchAddress("MET_RefGamma_etx_EndcapRegion", &MET_RefGamma_etx_EndcapRegion, &b_MET_RefGamma_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_RefGamma_ety_EndcapRegion", &MET_RefGamma_ety_EndcapRegion, &b_MET_RefGamma_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_RefGamma_sumet_EndcapRegion", &MET_RefGamma_sumet_EndcapRegion, &b_MET_RefGamma_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_RefGamma_phi_EndcapRegion", &MET_RefGamma_phi_EndcapRegion, &b_MET_RefGamma_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_RefGamma_etx_ForwardReg", &MET_RefGamma_etx_ForwardReg, &b_MET_RefGamma_etx_ForwardReg);
   fChain->SetBranchAddress("MET_RefGamma_ety_ForwardReg", &MET_RefGamma_ety_ForwardReg, &b_MET_RefGamma_ety_ForwardReg);
   fChain->SetBranchAddress("MET_RefGamma_sumet_ForwardReg", &MET_RefGamma_sumet_ForwardReg, &b_MET_RefGamma_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_RefGamma_phi_ForwardReg", &MET_RefGamma_phi_ForwardReg, &b_MET_RefGamma_phi_ForwardReg);
   fChain->SetBranchAddress("MET_RefTau_etx", &MET_RefTau_etx, &b_MET_RefTau_etx);
   fChain->SetBranchAddress("MET_RefTau_ety", &MET_RefTau_ety, &b_MET_RefTau_ety);
   fChain->SetBranchAddress("MET_RefTau_phi", &MET_RefTau_phi, &b_MET_RefTau_phi);
   fChain->SetBranchAddress("MET_RefTau_et", &MET_RefTau_et, &b_MET_RefTau_et);
   fChain->SetBranchAddress("MET_RefTau_sumet", &MET_RefTau_sumet, &b_MET_RefTau_sumet);
   fChain->SetBranchAddress("MET_RefTau_etx_CentralReg", &MET_RefTau_etx_CentralReg, &b_MET_RefTau_etx_CentralReg);
   fChain->SetBranchAddress("MET_RefTau_ety_CentralReg", &MET_RefTau_ety_CentralReg, &b_MET_RefTau_ety_CentralReg);
   fChain->SetBranchAddress("MET_RefTau_sumet_CentralReg", &MET_RefTau_sumet_CentralReg, &b_MET_RefTau_sumet_CentralReg);
   fChain->SetBranchAddress("MET_RefTau_phi_CentralReg", &MET_RefTau_phi_CentralReg, &b_MET_RefTau_phi_CentralReg);
   fChain->SetBranchAddress("MET_RefTau_etx_EndcapRegion", &MET_RefTau_etx_EndcapRegion, &b_MET_RefTau_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_RefTau_ety_EndcapRegion", &MET_RefTau_ety_EndcapRegion, &b_MET_RefTau_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_RefTau_sumet_EndcapRegion", &MET_RefTau_sumet_EndcapRegion, &b_MET_RefTau_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_RefTau_phi_EndcapRegion", &MET_RefTau_phi_EndcapRegion, &b_MET_RefTau_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_RefTau_etx_ForwardReg", &MET_RefTau_etx_ForwardReg, &b_MET_RefTau_etx_ForwardReg);
   fChain->SetBranchAddress("MET_RefTau_ety_ForwardReg", &MET_RefTau_ety_ForwardReg, &b_MET_RefTau_ety_ForwardReg);
   fChain->SetBranchAddress("MET_RefTau_sumet_ForwardReg", &MET_RefTau_sumet_ForwardReg, &b_MET_RefTau_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_RefTau_phi_ForwardReg", &MET_RefTau_phi_ForwardReg, &b_MET_RefTau_phi_ForwardReg);
   fChain->SetBranchAddress("MET_CellOut_etx", &MET_CellOut_etx, &b_MET_CellOut_etx);
   fChain->SetBranchAddress("MET_CellOut_ety", &MET_CellOut_ety, &b_MET_CellOut_ety);
   fChain->SetBranchAddress("MET_CellOut_phi", &MET_CellOut_phi, &b_MET_CellOut_phi);
   fChain->SetBranchAddress("MET_CellOut_et", &MET_CellOut_et, &b_MET_CellOut_et);
   fChain->SetBranchAddress("MET_CellOut_sumet", &MET_CellOut_sumet, &b_MET_CellOut_sumet);
   fChain->SetBranchAddress("MET_CellOut_etx_CentralReg", &MET_CellOut_etx_CentralReg, &b_MET_CellOut_etx_CentralReg);
   fChain->SetBranchAddress("MET_CellOut_ety_CentralReg", &MET_CellOut_ety_CentralReg, &b_MET_CellOut_ety_CentralReg);
   fChain->SetBranchAddress("MET_CellOut_sumet_CentralReg", &MET_CellOut_sumet_CentralReg, &b_MET_CellOut_sumet_CentralReg);
   fChain->SetBranchAddress("MET_CellOut_phi_CentralReg", &MET_CellOut_phi_CentralReg, &b_MET_CellOut_phi_CentralReg);
   fChain->SetBranchAddress("MET_CellOut_etx_EndcapRegion", &MET_CellOut_etx_EndcapRegion, &b_MET_CellOut_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_CellOut_ety_EndcapRegion", &MET_CellOut_ety_EndcapRegion, &b_MET_CellOut_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_CellOut_sumet_EndcapRegion", &MET_CellOut_sumet_EndcapRegion, &b_MET_CellOut_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_CellOut_phi_EndcapRegion", &MET_CellOut_phi_EndcapRegion, &b_MET_CellOut_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_CellOut_etx_ForwardReg", &MET_CellOut_etx_ForwardReg, &b_MET_CellOut_etx_ForwardReg);
   fChain->SetBranchAddress("MET_CellOut_ety_ForwardReg", &MET_CellOut_ety_ForwardReg, &b_MET_CellOut_ety_ForwardReg);
   fChain->SetBranchAddress("MET_CellOut_sumet_ForwardReg", &MET_CellOut_sumet_ForwardReg, &b_MET_CellOut_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_CellOut_phi_ForwardReg", &MET_CellOut_phi_ForwardReg, &b_MET_CellOut_phi_ForwardReg);
   fChain->SetBranchAddress("MET_Track_etx", &MET_Track_etx, &b_MET_Track_etx);
   fChain->SetBranchAddress("MET_Track_ety", &MET_Track_ety, &b_MET_Track_ety);
   fChain->SetBranchAddress("MET_Track_phi", &MET_Track_phi, &b_MET_Track_phi);
   fChain->SetBranchAddress("MET_Track_et", &MET_Track_et, &b_MET_Track_et);
   fChain->SetBranchAddress("MET_Track_sumet", &MET_Track_sumet, &b_MET_Track_sumet);
   fChain->SetBranchAddress("MET_Track_etx_CentralReg", &MET_Track_etx_CentralReg, &b_MET_Track_etx_CentralReg);
   fChain->SetBranchAddress("MET_Track_ety_CentralReg", &MET_Track_ety_CentralReg, &b_MET_Track_ety_CentralReg);
   fChain->SetBranchAddress("MET_Track_sumet_CentralReg", &MET_Track_sumet_CentralReg, &b_MET_Track_sumet_CentralReg);
   fChain->SetBranchAddress("MET_Track_phi_CentralReg", &MET_Track_phi_CentralReg, &b_MET_Track_phi_CentralReg);
   fChain->SetBranchAddress("MET_Track_etx_EndcapRegion", &MET_Track_etx_EndcapRegion, &b_MET_Track_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_Track_ety_EndcapRegion", &MET_Track_ety_EndcapRegion, &b_MET_Track_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_Track_sumet_EndcapRegion", &MET_Track_sumet_EndcapRegion, &b_MET_Track_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_Track_phi_EndcapRegion", &MET_Track_phi_EndcapRegion, &b_MET_Track_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_Track_etx_ForwardReg", &MET_Track_etx_ForwardReg, &b_MET_Track_etx_ForwardReg);
   fChain->SetBranchAddress("MET_Track_ety_ForwardReg", &MET_Track_ety_ForwardReg, &b_MET_Track_ety_ForwardReg);
   fChain->SetBranchAddress("MET_Track_sumet_ForwardReg", &MET_Track_sumet_ForwardReg, &b_MET_Track_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_Track_phi_ForwardReg", &MET_Track_phi_ForwardReg, &b_MET_Track_phi_ForwardReg);
   fChain->SetBranchAddress("MET_RefFinal_em_etx", &MET_RefFinal_em_etx, &b_MET_RefFinal_em_etx);
   fChain->SetBranchAddress("MET_RefFinal_em_ety", &MET_RefFinal_em_ety, &b_MET_RefFinal_em_ety);
   fChain->SetBranchAddress("MET_RefFinal_em_phi", &MET_RefFinal_em_phi, &b_MET_RefFinal_em_phi);
   fChain->SetBranchAddress("MET_RefFinal_em_et", &MET_RefFinal_em_et, &b_MET_RefFinal_em_et);
   fChain->SetBranchAddress("MET_RefFinal_em_sumet", &MET_RefFinal_em_sumet, &b_MET_RefFinal_em_sumet);
   fChain->SetBranchAddress("MET_RefFinal_em_etx_CentralReg", &MET_RefFinal_em_etx_CentralReg, &b_MET_RefFinal_em_etx_CentralReg);
   fChain->SetBranchAddress("MET_RefFinal_em_ety_CentralReg", &MET_RefFinal_em_ety_CentralReg, &b_MET_RefFinal_em_ety_CentralReg);
   fChain->SetBranchAddress("MET_RefFinal_em_sumet_CentralReg", &MET_RefFinal_em_sumet_CentralReg, &b_MET_RefFinal_em_sumet_CentralReg);
   fChain->SetBranchAddress("MET_RefFinal_em_phi_CentralReg", &MET_RefFinal_em_phi_CentralReg, &b_MET_RefFinal_em_phi_CentralReg);
   fChain->SetBranchAddress("MET_RefFinal_em_etx_EndcapRegion", &MET_RefFinal_em_etx_EndcapRegion, &b_MET_RefFinal_em_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_RefFinal_em_ety_EndcapRegion", &MET_RefFinal_em_ety_EndcapRegion, &b_MET_RefFinal_em_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_RefFinal_em_sumet_EndcapRegion", &MET_RefFinal_em_sumet_EndcapRegion, &b_MET_RefFinal_em_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_RefFinal_em_phi_EndcapRegion", &MET_RefFinal_em_phi_EndcapRegion, &b_MET_RefFinal_em_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_RefFinal_em_etx_ForwardReg", &MET_RefFinal_em_etx_ForwardReg, &b_MET_RefFinal_em_etx_ForwardReg);
   fChain->SetBranchAddress("MET_RefFinal_em_ety_ForwardReg", &MET_RefFinal_em_ety_ForwardReg, &b_MET_RefFinal_em_ety_ForwardReg);
   fChain->SetBranchAddress("MET_RefFinal_em_sumet_ForwardReg", &MET_RefFinal_em_sumet_ForwardReg, &b_MET_RefFinal_em_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_RefFinal_em_phi_ForwardReg", &MET_RefFinal_em_phi_ForwardReg, &b_MET_RefFinal_em_phi_ForwardReg);
   fChain->SetBranchAddress("MET_RefEle_em_etx", &MET_RefEle_em_etx, &b_MET_RefEle_em_etx);
   fChain->SetBranchAddress("MET_RefEle_em_ety", &MET_RefEle_em_ety, &b_MET_RefEle_em_ety);
   fChain->SetBranchAddress("MET_RefEle_em_phi", &MET_RefEle_em_phi, &b_MET_RefEle_em_phi);
   fChain->SetBranchAddress("MET_RefEle_em_et", &MET_RefEle_em_et, &b_MET_RefEle_em_et);
   fChain->SetBranchAddress("MET_RefEle_em_sumet", &MET_RefEle_em_sumet, &b_MET_RefEle_em_sumet);
   fChain->SetBranchAddress("MET_RefEle_em_etx_CentralReg", &MET_RefEle_em_etx_CentralReg, &b_MET_RefEle_em_etx_CentralReg);
   fChain->SetBranchAddress("MET_RefEle_em_ety_CentralReg", &MET_RefEle_em_ety_CentralReg, &b_MET_RefEle_em_ety_CentralReg);
   fChain->SetBranchAddress("MET_RefEle_em_sumet_CentralReg", &MET_RefEle_em_sumet_CentralReg, &b_MET_RefEle_em_sumet_CentralReg);
   fChain->SetBranchAddress("MET_RefEle_em_phi_CentralReg", &MET_RefEle_em_phi_CentralReg, &b_MET_RefEle_em_phi_CentralReg);
   fChain->SetBranchAddress("MET_RefEle_em_etx_EndcapRegion", &MET_RefEle_em_etx_EndcapRegion, &b_MET_RefEle_em_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_RefEle_em_ety_EndcapRegion", &MET_RefEle_em_ety_EndcapRegion, &b_MET_RefEle_em_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_RefEle_em_sumet_EndcapRegion", &MET_RefEle_em_sumet_EndcapRegion, &b_MET_RefEle_em_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_RefEle_em_phi_EndcapRegion", &MET_RefEle_em_phi_EndcapRegion, &b_MET_RefEle_em_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_RefEle_em_etx_ForwardReg", &MET_RefEle_em_etx_ForwardReg, &b_MET_RefEle_em_etx_ForwardReg);
   fChain->SetBranchAddress("MET_RefEle_em_ety_ForwardReg", &MET_RefEle_em_ety_ForwardReg, &b_MET_RefEle_em_ety_ForwardReg);
   fChain->SetBranchAddress("MET_RefEle_em_sumet_ForwardReg", &MET_RefEle_em_sumet_ForwardReg, &b_MET_RefEle_em_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_RefEle_em_phi_ForwardReg", &MET_RefEle_em_phi_ForwardReg, &b_MET_RefEle_em_phi_ForwardReg);
   fChain->SetBranchAddress("MET_RefJet_em_etx", &MET_RefJet_em_etx, &b_MET_RefJet_em_etx);
   fChain->SetBranchAddress("MET_RefJet_em_ety", &MET_RefJet_em_ety, &b_MET_RefJet_em_ety);
   fChain->SetBranchAddress("MET_RefJet_em_phi", &MET_RefJet_em_phi, &b_MET_RefJet_em_phi);
   fChain->SetBranchAddress("MET_RefJet_em_et", &MET_RefJet_em_et, &b_MET_RefJet_em_et);
   fChain->SetBranchAddress("MET_RefJet_em_sumet", &MET_RefJet_em_sumet, &b_MET_RefJet_em_sumet);
   fChain->SetBranchAddress("MET_RefJet_em_etx_CentralReg", &MET_RefJet_em_etx_CentralReg, &b_MET_RefJet_em_etx_CentralReg);
   fChain->SetBranchAddress("MET_RefJet_em_ety_CentralReg", &MET_RefJet_em_ety_CentralReg, &b_MET_RefJet_em_ety_CentralReg);
   fChain->SetBranchAddress("MET_RefJet_em_sumet_CentralReg", &MET_RefJet_em_sumet_CentralReg, &b_MET_RefJet_em_sumet_CentralReg);
   fChain->SetBranchAddress("MET_RefJet_em_phi_CentralReg", &MET_RefJet_em_phi_CentralReg, &b_MET_RefJet_em_phi_CentralReg);
   fChain->SetBranchAddress("MET_RefJet_em_etx_EndcapRegion", &MET_RefJet_em_etx_EndcapRegion, &b_MET_RefJet_em_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_RefJet_em_ety_EndcapRegion", &MET_RefJet_em_ety_EndcapRegion, &b_MET_RefJet_em_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_RefJet_em_sumet_EndcapRegion", &MET_RefJet_em_sumet_EndcapRegion, &b_MET_RefJet_em_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_RefJet_em_phi_EndcapRegion", &MET_RefJet_em_phi_EndcapRegion, &b_MET_RefJet_em_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_RefJet_em_etx_ForwardReg", &MET_RefJet_em_etx_ForwardReg, &b_MET_RefJet_em_etx_ForwardReg);
   fChain->SetBranchAddress("MET_RefJet_em_ety_ForwardReg", &MET_RefJet_em_ety_ForwardReg, &b_MET_RefJet_em_ety_ForwardReg);
   fChain->SetBranchAddress("MET_RefJet_em_sumet_ForwardReg", &MET_RefJet_em_sumet_ForwardReg, &b_MET_RefJet_em_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_RefJet_em_phi_ForwardReg", &MET_RefJet_em_phi_ForwardReg, &b_MET_RefJet_em_phi_ForwardReg);
   fChain->SetBranchAddress("MET_SoftJets_em_etx", &MET_SoftJets_em_etx, &b_MET_SoftJets_em_etx);
   fChain->SetBranchAddress("MET_SoftJets_em_ety", &MET_SoftJets_em_ety, &b_MET_SoftJets_em_ety);
   fChain->SetBranchAddress("MET_SoftJets_em_phi", &MET_SoftJets_em_phi, &b_MET_SoftJets_em_phi);
   fChain->SetBranchAddress("MET_SoftJets_em_et", &MET_SoftJets_em_et, &b_MET_SoftJets_em_et);
   fChain->SetBranchAddress("MET_SoftJets_em_sumet", &MET_SoftJets_em_sumet, &b_MET_SoftJets_em_sumet);
   fChain->SetBranchAddress("MET_SoftJets_em_etx_CentralReg", &MET_SoftJets_em_etx_CentralReg, &b_MET_SoftJets_em_etx_CentralReg);
   fChain->SetBranchAddress("MET_SoftJets_em_ety_CentralReg", &MET_SoftJets_em_ety_CentralReg, &b_MET_SoftJets_em_ety_CentralReg);
   fChain->SetBranchAddress("MET_SoftJets_em_sumet_CentralReg", &MET_SoftJets_em_sumet_CentralReg, &b_MET_SoftJets_em_sumet_CentralReg);
   fChain->SetBranchAddress("MET_SoftJets_em_phi_CentralReg", &MET_SoftJets_em_phi_CentralReg, &b_MET_SoftJets_em_phi_CentralReg);
   fChain->SetBranchAddress("MET_SoftJets_em_etx_EndcapRegion", &MET_SoftJets_em_etx_EndcapRegion, &b_MET_SoftJets_em_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_SoftJets_em_ety_EndcapRegion", &MET_SoftJets_em_ety_EndcapRegion, &b_MET_SoftJets_em_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_SoftJets_em_sumet_EndcapRegion", &MET_SoftJets_em_sumet_EndcapRegion, &b_MET_SoftJets_em_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_SoftJets_em_phi_EndcapRegion", &MET_SoftJets_em_phi_EndcapRegion, &b_MET_SoftJets_em_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_SoftJets_em_etx_ForwardReg", &MET_SoftJets_em_etx_ForwardReg, &b_MET_SoftJets_em_etx_ForwardReg);
   fChain->SetBranchAddress("MET_SoftJets_em_ety_ForwardReg", &MET_SoftJets_em_ety_ForwardReg, &b_MET_SoftJets_em_ety_ForwardReg);
   fChain->SetBranchAddress("MET_SoftJets_em_sumet_ForwardReg", &MET_SoftJets_em_sumet_ForwardReg, &b_MET_SoftJets_em_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_SoftJets_em_phi_ForwardReg", &MET_SoftJets_em_phi_ForwardReg, &b_MET_SoftJets_em_phi_ForwardReg);
   fChain->SetBranchAddress("MET_RefMuon_em_etx", &MET_RefMuon_em_etx, &b_MET_RefMuon_em_etx);
   fChain->SetBranchAddress("MET_RefMuon_em_ety", &MET_RefMuon_em_ety, &b_MET_RefMuon_em_ety);
   fChain->SetBranchAddress("MET_RefMuon_em_phi", &MET_RefMuon_em_phi, &b_MET_RefMuon_em_phi);
   fChain->SetBranchAddress("MET_RefMuon_em_et", &MET_RefMuon_em_et, &b_MET_RefMuon_em_et);
   fChain->SetBranchAddress("MET_RefMuon_em_sumet", &MET_RefMuon_em_sumet, &b_MET_RefMuon_em_sumet);
   fChain->SetBranchAddress("MET_RefMuon_em_etx_CentralReg", &MET_RefMuon_em_etx_CentralReg, &b_MET_RefMuon_em_etx_CentralReg);
   fChain->SetBranchAddress("MET_RefMuon_em_ety_CentralReg", &MET_RefMuon_em_ety_CentralReg, &b_MET_RefMuon_em_ety_CentralReg);
   fChain->SetBranchAddress("MET_RefMuon_em_sumet_CentralReg", &MET_RefMuon_em_sumet_CentralReg, &b_MET_RefMuon_em_sumet_CentralReg);
   fChain->SetBranchAddress("MET_RefMuon_em_phi_CentralReg", &MET_RefMuon_em_phi_CentralReg, &b_MET_RefMuon_em_phi_CentralReg);
   fChain->SetBranchAddress("MET_RefMuon_em_etx_EndcapRegion", &MET_RefMuon_em_etx_EndcapRegion, &b_MET_RefMuon_em_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_RefMuon_em_ety_EndcapRegion", &MET_RefMuon_em_ety_EndcapRegion, &b_MET_RefMuon_em_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_RefMuon_em_sumet_EndcapRegion", &MET_RefMuon_em_sumet_EndcapRegion, &b_MET_RefMuon_em_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_RefMuon_em_phi_EndcapRegion", &MET_RefMuon_em_phi_EndcapRegion, &b_MET_RefMuon_em_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_RefMuon_em_etx_ForwardReg", &MET_RefMuon_em_etx_ForwardReg, &b_MET_RefMuon_em_etx_ForwardReg);
   fChain->SetBranchAddress("MET_RefMuon_em_ety_ForwardReg", &MET_RefMuon_em_ety_ForwardReg, &b_MET_RefMuon_em_ety_ForwardReg);
   fChain->SetBranchAddress("MET_RefMuon_em_sumet_ForwardReg", &MET_RefMuon_em_sumet_ForwardReg, &b_MET_RefMuon_em_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_RefMuon_em_phi_ForwardReg", &MET_RefMuon_em_phi_ForwardReg, &b_MET_RefMuon_em_phi_ForwardReg);
   fChain->SetBranchAddress("MET_RefMuon_Track_em_etx", &MET_RefMuon_Track_em_etx, &b_MET_RefMuon_Track_em_etx);
   fChain->SetBranchAddress("MET_RefMuon_Track_em_ety", &MET_RefMuon_Track_em_ety, &b_MET_RefMuon_Track_em_ety);
   fChain->SetBranchAddress("MET_RefMuon_Track_em_phi", &MET_RefMuon_Track_em_phi, &b_MET_RefMuon_Track_em_phi);
   fChain->SetBranchAddress("MET_RefMuon_Track_em_et", &MET_RefMuon_Track_em_et, &b_MET_RefMuon_Track_em_et);
   fChain->SetBranchAddress("MET_RefMuon_Track_em_sumet", &MET_RefMuon_Track_em_sumet, &b_MET_RefMuon_Track_em_sumet);
   fChain->SetBranchAddress("MET_RefMuon_Track_em_etx_CentralReg", &MET_RefMuon_Track_em_etx_CentralReg, &b_MET_RefMuon_Track_em_etx_CentralReg);
   fChain->SetBranchAddress("MET_RefMuon_Track_em_ety_CentralReg", &MET_RefMuon_Track_em_ety_CentralReg, &b_MET_RefMuon_Track_em_ety_CentralReg);
   fChain->SetBranchAddress("MET_RefMuon_Track_em_sumet_CentralReg", &MET_RefMuon_Track_em_sumet_CentralReg, &b_MET_RefMuon_Track_em_sumet_CentralReg);
   fChain->SetBranchAddress("MET_RefMuon_Track_em_phi_CentralReg", &MET_RefMuon_Track_em_phi_CentralReg, &b_MET_RefMuon_Track_em_phi_CentralReg);
   fChain->SetBranchAddress("MET_RefMuon_Track_em_etx_EndcapRegion", &MET_RefMuon_Track_em_etx_EndcapRegion, &b_MET_RefMuon_Track_em_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_RefMuon_Track_em_ety_EndcapRegion", &MET_RefMuon_Track_em_ety_EndcapRegion, &b_MET_RefMuon_Track_em_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_RefMuon_Track_em_sumet_EndcapRegion", &MET_RefMuon_Track_em_sumet_EndcapRegion, &b_MET_RefMuon_Track_em_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_RefMuon_Track_em_phi_EndcapRegion", &MET_RefMuon_Track_em_phi_EndcapRegion, &b_MET_RefMuon_Track_em_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_RefMuon_Track_em_etx_ForwardReg", &MET_RefMuon_Track_em_etx_ForwardReg, &b_MET_RefMuon_Track_em_etx_ForwardReg);
   fChain->SetBranchAddress("MET_RefMuon_Track_em_ety_ForwardReg", &MET_RefMuon_Track_em_ety_ForwardReg, &b_MET_RefMuon_Track_em_ety_ForwardReg);
   fChain->SetBranchAddress("MET_RefMuon_Track_em_sumet_ForwardReg", &MET_RefMuon_Track_em_sumet_ForwardReg, &b_MET_RefMuon_Track_em_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_RefMuon_Track_em_phi_ForwardReg", &MET_RefMuon_Track_em_phi_ForwardReg, &b_MET_RefMuon_Track_em_phi_ForwardReg);
   fChain->SetBranchAddress("MET_RefGamma_em_etx", &MET_RefGamma_em_etx, &b_MET_RefGamma_em_etx);
   fChain->SetBranchAddress("MET_RefGamma_em_ety", &MET_RefGamma_em_ety, &b_MET_RefGamma_em_ety);
   fChain->SetBranchAddress("MET_RefGamma_em_phi", &MET_RefGamma_em_phi, &b_MET_RefGamma_em_phi);
   fChain->SetBranchAddress("MET_RefGamma_em_et", &MET_RefGamma_em_et, &b_MET_RefGamma_em_et);
   fChain->SetBranchAddress("MET_RefGamma_em_sumet", &MET_RefGamma_em_sumet, &b_MET_RefGamma_em_sumet);
   fChain->SetBranchAddress("MET_RefGamma_em_etx_CentralReg", &MET_RefGamma_em_etx_CentralReg, &b_MET_RefGamma_em_etx_CentralReg);
   fChain->SetBranchAddress("MET_RefGamma_em_ety_CentralReg", &MET_RefGamma_em_ety_CentralReg, &b_MET_RefGamma_em_ety_CentralReg);
   fChain->SetBranchAddress("MET_RefGamma_em_sumet_CentralReg", &MET_RefGamma_em_sumet_CentralReg, &b_MET_RefGamma_em_sumet_CentralReg);
   fChain->SetBranchAddress("MET_RefGamma_em_phi_CentralReg", &MET_RefGamma_em_phi_CentralReg, &b_MET_RefGamma_em_phi_CentralReg);
   fChain->SetBranchAddress("MET_RefGamma_em_etx_EndcapRegion", &MET_RefGamma_em_etx_EndcapRegion, &b_MET_RefGamma_em_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_RefGamma_em_ety_EndcapRegion", &MET_RefGamma_em_ety_EndcapRegion, &b_MET_RefGamma_em_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_RefGamma_em_sumet_EndcapRegion", &MET_RefGamma_em_sumet_EndcapRegion, &b_MET_RefGamma_em_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_RefGamma_em_phi_EndcapRegion", &MET_RefGamma_em_phi_EndcapRegion, &b_MET_RefGamma_em_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_RefGamma_em_etx_ForwardReg", &MET_RefGamma_em_etx_ForwardReg, &b_MET_RefGamma_em_etx_ForwardReg);
   fChain->SetBranchAddress("MET_RefGamma_em_ety_ForwardReg", &MET_RefGamma_em_ety_ForwardReg, &b_MET_RefGamma_em_ety_ForwardReg);
   fChain->SetBranchAddress("MET_RefGamma_em_sumet_ForwardReg", &MET_RefGamma_em_sumet_ForwardReg, &b_MET_RefGamma_em_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_RefGamma_em_phi_ForwardReg", &MET_RefGamma_em_phi_ForwardReg, &b_MET_RefGamma_em_phi_ForwardReg);
   fChain->SetBranchAddress("MET_RefTau_em_etx", &MET_RefTau_em_etx, &b_MET_RefTau_em_etx);
   fChain->SetBranchAddress("MET_RefTau_em_ety", &MET_RefTau_em_ety, &b_MET_RefTau_em_ety);
   fChain->SetBranchAddress("MET_RefTau_em_phi", &MET_RefTau_em_phi, &b_MET_RefTau_em_phi);
   fChain->SetBranchAddress("MET_RefTau_em_et", &MET_RefTau_em_et, &b_MET_RefTau_em_et);
   fChain->SetBranchAddress("MET_RefTau_em_sumet", &MET_RefTau_em_sumet, &b_MET_RefTau_em_sumet);
   fChain->SetBranchAddress("MET_RefTau_em_etx_CentralReg", &MET_RefTau_em_etx_CentralReg, &b_MET_RefTau_em_etx_CentralReg);
   fChain->SetBranchAddress("MET_RefTau_em_ety_CentralReg", &MET_RefTau_em_ety_CentralReg, &b_MET_RefTau_em_ety_CentralReg);
   fChain->SetBranchAddress("MET_RefTau_em_sumet_CentralReg", &MET_RefTau_em_sumet_CentralReg, &b_MET_RefTau_em_sumet_CentralReg);
   fChain->SetBranchAddress("MET_RefTau_em_phi_CentralReg", &MET_RefTau_em_phi_CentralReg, &b_MET_RefTau_em_phi_CentralReg);
   fChain->SetBranchAddress("MET_RefTau_em_etx_EndcapRegion", &MET_RefTau_em_etx_EndcapRegion, &b_MET_RefTau_em_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_RefTau_em_ety_EndcapRegion", &MET_RefTau_em_ety_EndcapRegion, &b_MET_RefTau_em_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_RefTau_em_sumet_EndcapRegion", &MET_RefTau_em_sumet_EndcapRegion, &b_MET_RefTau_em_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_RefTau_em_phi_EndcapRegion", &MET_RefTau_em_phi_EndcapRegion, &b_MET_RefTau_em_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_RefTau_em_etx_ForwardReg", &MET_RefTau_em_etx_ForwardReg, &b_MET_RefTau_em_etx_ForwardReg);
   fChain->SetBranchAddress("MET_RefTau_em_ety_ForwardReg", &MET_RefTau_em_ety_ForwardReg, &b_MET_RefTau_em_ety_ForwardReg);
   fChain->SetBranchAddress("MET_RefTau_em_sumet_ForwardReg", &MET_RefTau_em_sumet_ForwardReg, &b_MET_RefTau_em_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_RefTau_em_phi_ForwardReg", &MET_RefTau_em_phi_ForwardReg, &b_MET_RefTau_em_phi_ForwardReg);
   fChain->SetBranchAddress("MET_CellOut_em_etx", &MET_CellOut_em_etx, &b_MET_CellOut_em_etx);
   fChain->SetBranchAddress("MET_CellOut_em_ety", &MET_CellOut_em_ety, &b_MET_CellOut_em_ety);
   fChain->SetBranchAddress("MET_CellOut_em_phi", &MET_CellOut_em_phi, &b_MET_CellOut_em_phi);
   fChain->SetBranchAddress("MET_CellOut_em_et", &MET_CellOut_em_et, &b_MET_CellOut_em_et);
   fChain->SetBranchAddress("MET_CellOut_em_sumet", &MET_CellOut_em_sumet, &b_MET_CellOut_em_sumet);
   fChain->SetBranchAddress("MET_CellOut_em_etx_CentralReg", &MET_CellOut_em_etx_CentralReg, &b_MET_CellOut_em_etx_CentralReg);
   fChain->SetBranchAddress("MET_CellOut_em_ety_CentralReg", &MET_CellOut_em_ety_CentralReg, &b_MET_CellOut_em_ety_CentralReg);
   fChain->SetBranchAddress("MET_CellOut_em_sumet_CentralReg", &MET_CellOut_em_sumet_CentralReg, &b_MET_CellOut_em_sumet_CentralReg);
   fChain->SetBranchAddress("MET_CellOut_em_phi_CentralReg", &MET_CellOut_em_phi_CentralReg, &b_MET_CellOut_em_phi_CentralReg);
   fChain->SetBranchAddress("MET_CellOut_em_etx_EndcapRegion", &MET_CellOut_em_etx_EndcapRegion, &b_MET_CellOut_em_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_CellOut_em_ety_EndcapRegion", &MET_CellOut_em_ety_EndcapRegion, &b_MET_CellOut_em_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_CellOut_em_sumet_EndcapRegion", &MET_CellOut_em_sumet_EndcapRegion, &b_MET_CellOut_em_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_CellOut_em_phi_EndcapRegion", &MET_CellOut_em_phi_EndcapRegion, &b_MET_CellOut_em_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_CellOut_em_etx_ForwardReg", &MET_CellOut_em_etx_ForwardReg, &b_MET_CellOut_em_etx_ForwardReg);
   fChain->SetBranchAddress("MET_CellOut_em_ety_ForwardReg", &MET_CellOut_em_ety_ForwardReg, &b_MET_CellOut_em_ety_ForwardReg);
   fChain->SetBranchAddress("MET_CellOut_em_sumet_ForwardReg", &MET_CellOut_em_sumet_ForwardReg, &b_MET_CellOut_em_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_CellOut_em_phi_ForwardReg", &MET_CellOut_em_phi_ForwardReg, &b_MET_CellOut_em_phi_ForwardReg);
   fChain->SetBranchAddress("MET_Muon_Isol_Staco_etx", &MET_Muon_Isol_Staco_etx, &b_MET_Muon_Isol_Staco_etx);
   fChain->SetBranchAddress("MET_Muon_Isol_Staco_ety", &MET_Muon_Isol_Staco_ety, &b_MET_Muon_Isol_Staco_ety);
   fChain->SetBranchAddress("MET_Muon_Isol_Staco_phi", &MET_Muon_Isol_Staco_phi, &b_MET_Muon_Isol_Staco_phi);
   fChain->SetBranchAddress("MET_Muon_Isol_Staco_et", &MET_Muon_Isol_Staco_et, &b_MET_Muon_Isol_Staco_et);
   fChain->SetBranchAddress("MET_Muon_Isol_Staco_sumet", &MET_Muon_Isol_Staco_sumet, &b_MET_Muon_Isol_Staco_sumet);
   fChain->SetBranchAddress("MET_Muon_Isol_Staco_etx_CentralReg", &MET_Muon_Isol_Staco_etx_CentralReg, &b_MET_Muon_Isol_Staco_etx_CentralReg);
   fChain->SetBranchAddress("MET_Muon_Isol_Staco_ety_CentralReg", &MET_Muon_Isol_Staco_ety_CentralReg, &b_MET_Muon_Isol_Staco_ety_CentralReg);
   fChain->SetBranchAddress("MET_Muon_Isol_Staco_sumet_CentralReg", &MET_Muon_Isol_Staco_sumet_CentralReg, &b_MET_Muon_Isol_Staco_sumet_CentralReg);
   fChain->SetBranchAddress("MET_Muon_Isol_Staco_phi_CentralReg", &MET_Muon_Isol_Staco_phi_CentralReg, &b_MET_Muon_Isol_Staco_phi_CentralReg);
   fChain->SetBranchAddress("MET_Muon_Isol_Staco_etx_EndcapRegion", &MET_Muon_Isol_Staco_etx_EndcapRegion, &b_MET_Muon_Isol_Staco_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_Muon_Isol_Staco_ety_EndcapRegion", &MET_Muon_Isol_Staco_ety_EndcapRegion, &b_MET_Muon_Isol_Staco_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_Muon_Isol_Staco_sumet_EndcapRegion", &MET_Muon_Isol_Staco_sumet_EndcapRegion, &b_MET_Muon_Isol_Staco_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_Muon_Isol_Staco_phi_EndcapRegion", &MET_Muon_Isol_Staco_phi_EndcapRegion, &b_MET_Muon_Isol_Staco_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_Muon_Isol_Staco_etx_ForwardReg", &MET_Muon_Isol_Staco_etx_ForwardReg, &b_MET_Muon_Isol_Staco_etx_ForwardReg);
   fChain->SetBranchAddress("MET_Muon_Isol_Staco_ety_ForwardReg", &MET_Muon_Isol_Staco_ety_ForwardReg, &b_MET_Muon_Isol_Staco_ety_ForwardReg);
   fChain->SetBranchAddress("MET_Muon_Isol_Staco_sumet_ForwardReg", &MET_Muon_Isol_Staco_sumet_ForwardReg, &b_MET_Muon_Isol_Staco_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_Muon_Isol_Staco_phi_ForwardReg", &MET_Muon_Isol_Staco_phi_ForwardReg, &b_MET_Muon_Isol_Staco_phi_ForwardReg);
   fChain->SetBranchAddress("MET_Muon_NonIsol_Staco_etx", &MET_Muon_NonIsol_Staco_etx, &b_MET_Muon_NonIsol_Staco_etx);
   fChain->SetBranchAddress("MET_Muon_NonIsol_Staco_ety", &MET_Muon_NonIsol_Staco_ety, &b_MET_Muon_NonIsol_Staco_ety);
   fChain->SetBranchAddress("MET_Muon_NonIsol_Staco_phi", &MET_Muon_NonIsol_Staco_phi, &b_MET_Muon_NonIsol_Staco_phi);
   fChain->SetBranchAddress("MET_Muon_NonIsol_Staco_et", &MET_Muon_NonIsol_Staco_et, &b_MET_Muon_NonIsol_Staco_et);
   fChain->SetBranchAddress("MET_Muon_NonIsol_Staco_sumet", &MET_Muon_NonIsol_Staco_sumet, &b_MET_Muon_NonIsol_Staco_sumet);
   fChain->SetBranchAddress("MET_Muon_NonIsol_Staco_etx_CentralReg", &MET_Muon_NonIsol_Staco_etx_CentralReg, &b_MET_Muon_NonIsol_Staco_etx_CentralReg);
   fChain->SetBranchAddress("MET_Muon_NonIsol_Staco_ety_CentralReg", &MET_Muon_NonIsol_Staco_ety_CentralReg, &b_MET_Muon_NonIsol_Staco_ety_CentralReg);
   fChain->SetBranchAddress("MET_Muon_NonIsol_Staco_sumet_CentralReg", &MET_Muon_NonIsol_Staco_sumet_CentralReg, &b_MET_Muon_NonIsol_Staco_sumet_CentralReg);
   fChain->SetBranchAddress("MET_Muon_NonIsol_Staco_phi_CentralReg", &MET_Muon_NonIsol_Staco_phi_CentralReg, &b_MET_Muon_NonIsol_Staco_phi_CentralReg);
   fChain->SetBranchAddress("MET_Muon_NonIsol_Staco_etx_EndcapRegion", &MET_Muon_NonIsol_Staco_etx_EndcapRegion, &b_MET_Muon_NonIsol_Staco_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_Muon_NonIsol_Staco_ety_EndcapRegion", &MET_Muon_NonIsol_Staco_ety_EndcapRegion, &b_MET_Muon_NonIsol_Staco_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_Muon_NonIsol_Staco_sumet_EndcapRegion", &MET_Muon_NonIsol_Staco_sumet_EndcapRegion, &b_MET_Muon_NonIsol_Staco_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_Muon_NonIsol_Staco_phi_EndcapRegion", &MET_Muon_NonIsol_Staco_phi_EndcapRegion, &b_MET_Muon_NonIsol_Staco_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_Muon_NonIsol_Staco_etx_ForwardReg", &MET_Muon_NonIsol_Staco_etx_ForwardReg, &b_MET_Muon_NonIsol_Staco_etx_ForwardReg);
   fChain->SetBranchAddress("MET_Muon_NonIsol_Staco_ety_ForwardReg", &MET_Muon_NonIsol_Staco_ety_ForwardReg, &b_MET_Muon_NonIsol_Staco_ety_ForwardReg);
   fChain->SetBranchAddress("MET_Muon_NonIsol_Staco_sumet_ForwardReg", &MET_Muon_NonIsol_Staco_sumet_ForwardReg, &b_MET_Muon_NonIsol_Staco_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_Muon_NonIsol_Staco_phi_ForwardReg", &MET_Muon_NonIsol_Staco_phi_ForwardReg, &b_MET_Muon_NonIsol_Staco_phi_ForwardReg);
   fChain->SetBranchAddress("MET_Muon_Total_Staco_etx", &MET_Muon_Total_Staco_etx, &b_MET_Muon_Total_Staco_etx);
   fChain->SetBranchAddress("MET_Muon_Total_Staco_ety", &MET_Muon_Total_Staco_ety, &b_MET_Muon_Total_Staco_ety);
   fChain->SetBranchAddress("MET_Muon_Total_Staco_phi", &MET_Muon_Total_Staco_phi, &b_MET_Muon_Total_Staco_phi);
   fChain->SetBranchAddress("MET_Muon_Total_Staco_et", &MET_Muon_Total_Staco_et, &b_MET_Muon_Total_Staco_et);
   fChain->SetBranchAddress("MET_Muon_Total_Staco_sumet", &MET_Muon_Total_Staco_sumet, &b_MET_Muon_Total_Staco_sumet);
   fChain->SetBranchAddress("MET_Muon_Total_Staco_etx_CentralReg", &MET_Muon_Total_Staco_etx_CentralReg, &b_MET_Muon_Total_Staco_etx_CentralReg);
   fChain->SetBranchAddress("MET_Muon_Total_Staco_ety_CentralReg", &MET_Muon_Total_Staco_ety_CentralReg, &b_MET_Muon_Total_Staco_ety_CentralReg);
   fChain->SetBranchAddress("MET_Muon_Total_Staco_sumet_CentralReg", &MET_Muon_Total_Staco_sumet_CentralReg, &b_MET_Muon_Total_Staco_sumet_CentralReg);
   fChain->SetBranchAddress("MET_Muon_Total_Staco_phi_CentralReg", &MET_Muon_Total_Staco_phi_CentralReg, &b_MET_Muon_Total_Staco_phi_CentralReg);
   fChain->SetBranchAddress("MET_Muon_Total_Staco_etx_EndcapRegion", &MET_Muon_Total_Staco_etx_EndcapRegion, &b_MET_Muon_Total_Staco_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_Muon_Total_Staco_ety_EndcapRegion", &MET_Muon_Total_Staco_ety_EndcapRegion, &b_MET_Muon_Total_Staco_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_Muon_Total_Staco_sumet_EndcapRegion", &MET_Muon_Total_Staco_sumet_EndcapRegion, &b_MET_Muon_Total_Staco_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_Muon_Total_Staco_phi_EndcapRegion", &MET_Muon_Total_Staco_phi_EndcapRegion, &b_MET_Muon_Total_Staco_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_Muon_Total_Staco_etx_ForwardReg", &MET_Muon_Total_Staco_etx_ForwardReg, &b_MET_Muon_Total_Staco_etx_ForwardReg);
   fChain->SetBranchAddress("MET_Muon_Total_Staco_ety_ForwardReg", &MET_Muon_Total_Staco_ety_ForwardReg, &b_MET_Muon_Total_Staco_ety_ForwardReg);
   fChain->SetBranchAddress("MET_Muon_Total_Staco_sumet_ForwardReg", &MET_Muon_Total_Staco_sumet_ForwardReg, &b_MET_Muon_Total_Staco_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_Muon_Total_Staco_phi_ForwardReg", &MET_Muon_Total_Staco_phi_ForwardReg, &b_MET_Muon_Total_Staco_phi_ForwardReg);
   fChain->SetBranchAddress("MET_Muon_Isol_Muid_etx", &MET_Muon_Isol_Muid_etx, &b_MET_Muon_Isol_Muid_etx);
   fChain->SetBranchAddress("MET_Muon_Isol_Muid_ety", &MET_Muon_Isol_Muid_ety, &b_MET_Muon_Isol_Muid_ety);
   fChain->SetBranchAddress("MET_Muon_Isol_Muid_phi", &MET_Muon_Isol_Muid_phi, &b_MET_Muon_Isol_Muid_phi);
   fChain->SetBranchAddress("MET_Muon_Isol_Muid_et", &MET_Muon_Isol_Muid_et, &b_MET_Muon_Isol_Muid_et);
   fChain->SetBranchAddress("MET_Muon_Isol_Muid_sumet", &MET_Muon_Isol_Muid_sumet, &b_MET_Muon_Isol_Muid_sumet);
   fChain->SetBranchAddress("MET_Muon_Isol_Muid_etx_CentralReg", &MET_Muon_Isol_Muid_etx_CentralReg, &b_MET_Muon_Isol_Muid_etx_CentralReg);
   fChain->SetBranchAddress("MET_Muon_Isol_Muid_ety_CentralReg", &MET_Muon_Isol_Muid_ety_CentralReg, &b_MET_Muon_Isol_Muid_ety_CentralReg);
   fChain->SetBranchAddress("MET_Muon_Isol_Muid_sumet_CentralReg", &MET_Muon_Isol_Muid_sumet_CentralReg, &b_MET_Muon_Isol_Muid_sumet_CentralReg);
   fChain->SetBranchAddress("MET_Muon_Isol_Muid_phi_CentralReg", &MET_Muon_Isol_Muid_phi_CentralReg, &b_MET_Muon_Isol_Muid_phi_CentralReg);
   fChain->SetBranchAddress("MET_Muon_Isol_Muid_etx_EndcapRegion", &MET_Muon_Isol_Muid_etx_EndcapRegion, &b_MET_Muon_Isol_Muid_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_Muon_Isol_Muid_ety_EndcapRegion", &MET_Muon_Isol_Muid_ety_EndcapRegion, &b_MET_Muon_Isol_Muid_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_Muon_Isol_Muid_sumet_EndcapRegion", &MET_Muon_Isol_Muid_sumet_EndcapRegion, &b_MET_Muon_Isol_Muid_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_Muon_Isol_Muid_phi_EndcapRegion", &MET_Muon_Isol_Muid_phi_EndcapRegion, &b_MET_Muon_Isol_Muid_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_Muon_Isol_Muid_etx_ForwardReg", &MET_Muon_Isol_Muid_etx_ForwardReg, &b_MET_Muon_Isol_Muid_etx_ForwardReg);
   fChain->SetBranchAddress("MET_Muon_Isol_Muid_ety_ForwardReg", &MET_Muon_Isol_Muid_ety_ForwardReg, &b_MET_Muon_Isol_Muid_ety_ForwardReg);
   fChain->SetBranchAddress("MET_Muon_Isol_Muid_sumet_ForwardReg", &MET_Muon_Isol_Muid_sumet_ForwardReg, &b_MET_Muon_Isol_Muid_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_Muon_Isol_Muid_phi_ForwardReg", &MET_Muon_Isol_Muid_phi_ForwardReg, &b_MET_Muon_Isol_Muid_phi_ForwardReg);
   fChain->SetBranchAddress("MET_Muon_NonIsol_Muid_etx", &MET_Muon_NonIsol_Muid_etx, &b_MET_Muon_NonIsol_Muid_etx);
   fChain->SetBranchAddress("MET_Muon_NonIsol_Muid_ety", &MET_Muon_NonIsol_Muid_ety, &b_MET_Muon_NonIsol_Muid_ety);
   fChain->SetBranchAddress("MET_Muon_NonIsol_Muid_phi", &MET_Muon_NonIsol_Muid_phi, &b_MET_Muon_NonIsol_Muid_phi);
   fChain->SetBranchAddress("MET_Muon_NonIsol_Muid_et", &MET_Muon_NonIsol_Muid_et, &b_MET_Muon_NonIsol_Muid_et);
   fChain->SetBranchAddress("MET_Muon_NonIsol_Muid_sumet", &MET_Muon_NonIsol_Muid_sumet, &b_MET_Muon_NonIsol_Muid_sumet);
   fChain->SetBranchAddress("MET_Muon_NonIsol_Muid_etx_CentralReg", &MET_Muon_NonIsol_Muid_etx_CentralReg, &b_MET_Muon_NonIsol_Muid_etx_CentralReg);
   fChain->SetBranchAddress("MET_Muon_NonIsol_Muid_ety_CentralReg", &MET_Muon_NonIsol_Muid_ety_CentralReg, &b_MET_Muon_NonIsol_Muid_ety_CentralReg);
   fChain->SetBranchAddress("MET_Muon_NonIsol_Muid_sumet_CentralReg", &MET_Muon_NonIsol_Muid_sumet_CentralReg, &b_MET_Muon_NonIsol_Muid_sumet_CentralReg);
   fChain->SetBranchAddress("MET_Muon_NonIsol_Muid_phi_CentralReg", &MET_Muon_NonIsol_Muid_phi_CentralReg, &b_MET_Muon_NonIsol_Muid_phi_CentralReg);
   fChain->SetBranchAddress("MET_Muon_NonIsol_Muid_etx_EndcapRegion", &MET_Muon_NonIsol_Muid_etx_EndcapRegion, &b_MET_Muon_NonIsol_Muid_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_Muon_NonIsol_Muid_ety_EndcapRegion", &MET_Muon_NonIsol_Muid_ety_EndcapRegion, &b_MET_Muon_NonIsol_Muid_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_Muon_NonIsol_Muid_sumet_EndcapRegion", &MET_Muon_NonIsol_Muid_sumet_EndcapRegion, &b_MET_Muon_NonIsol_Muid_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_Muon_NonIsol_Muid_phi_EndcapRegion", &MET_Muon_NonIsol_Muid_phi_EndcapRegion, &b_MET_Muon_NonIsol_Muid_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_Muon_NonIsol_Muid_etx_ForwardReg", &MET_Muon_NonIsol_Muid_etx_ForwardReg, &b_MET_Muon_NonIsol_Muid_etx_ForwardReg);
   fChain->SetBranchAddress("MET_Muon_NonIsol_Muid_ety_ForwardReg", &MET_Muon_NonIsol_Muid_ety_ForwardReg, &b_MET_Muon_NonIsol_Muid_ety_ForwardReg);
   fChain->SetBranchAddress("MET_Muon_NonIsol_Muid_sumet_ForwardReg", &MET_Muon_NonIsol_Muid_sumet_ForwardReg, &b_MET_Muon_NonIsol_Muid_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_Muon_NonIsol_Muid_phi_ForwardReg", &MET_Muon_NonIsol_Muid_phi_ForwardReg, &b_MET_Muon_NonIsol_Muid_phi_ForwardReg);
   fChain->SetBranchAddress("MET_Muon_Total_Muid_etx", &MET_Muon_Total_Muid_etx, &b_MET_Muon_Total_Muid_etx);
   fChain->SetBranchAddress("MET_Muon_Total_Muid_ety", &MET_Muon_Total_Muid_ety, &b_MET_Muon_Total_Muid_ety);
   fChain->SetBranchAddress("MET_Muon_Total_Muid_phi", &MET_Muon_Total_Muid_phi, &b_MET_Muon_Total_Muid_phi);
   fChain->SetBranchAddress("MET_Muon_Total_Muid_et", &MET_Muon_Total_Muid_et, &b_MET_Muon_Total_Muid_et);
   fChain->SetBranchAddress("MET_Muon_Total_Muid_sumet", &MET_Muon_Total_Muid_sumet, &b_MET_Muon_Total_Muid_sumet);
   fChain->SetBranchAddress("MET_Muon_Total_Muid_etx_CentralReg", &MET_Muon_Total_Muid_etx_CentralReg, &b_MET_Muon_Total_Muid_etx_CentralReg);
   fChain->SetBranchAddress("MET_Muon_Total_Muid_ety_CentralReg", &MET_Muon_Total_Muid_ety_CentralReg, &b_MET_Muon_Total_Muid_ety_CentralReg);
   fChain->SetBranchAddress("MET_Muon_Total_Muid_sumet_CentralReg", &MET_Muon_Total_Muid_sumet_CentralReg, &b_MET_Muon_Total_Muid_sumet_CentralReg);
   fChain->SetBranchAddress("MET_Muon_Total_Muid_phi_CentralReg", &MET_Muon_Total_Muid_phi_CentralReg, &b_MET_Muon_Total_Muid_phi_CentralReg);
   fChain->SetBranchAddress("MET_Muon_Total_Muid_etx_EndcapRegion", &MET_Muon_Total_Muid_etx_EndcapRegion, &b_MET_Muon_Total_Muid_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_Muon_Total_Muid_ety_EndcapRegion", &MET_Muon_Total_Muid_ety_EndcapRegion, &b_MET_Muon_Total_Muid_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_Muon_Total_Muid_sumet_EndcapRegion", &MET_Muon_Total_Muid_sumet_EndcapRegion, &b_MET_Muon_Total_Muid_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_Muon_Total_Muid_phi_EndcapRegion", &MET_Muon_Total_Muid_phi_EndcapRegion, &b_MET_Muon_Total_Muid_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_Muon_Total_Muid_etx_ForwardReg", &MET_Muon_Total_Muid_etx_ForwardReg, &b_MET_Muon_Total_Muid_etx_ForwardReg);
   fChain->SetBranchAddress("MET_Muon_Total_Muid_ety_ForwardReg", &MET_Muon_Total_Muid_ety_ForwardReg, &b_MET_Muon_Total_Muid_ety_ForwardReg);
   fChain->SetBranchAddress("MET_Muon_Total_Muid_sumet_ForwardReg", &MET_Muon_Total_Muid_sumet_ForwardReg, &b_MET_Muon_Total_Muid_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_Muon_Total_Muid_phi_ForwardReg", &MET_Muon_Total_Muid_phi_ForwardReg, &b_MET_Muon_Total_Muid_phi_ForwardReg);
   fChain->SetBranchAddress("MET_MuonBoy_etx", &MET_MuonBoy_etx, &b_MET_MuonBoy_etx);
   fChain->SetBranchAddress("MET_MuonBoy_ety", &MET_MuonBoy_ety, &b_MET_MuonBoy_ety);
   fChain->SetBranchAddress("MET_MuonBoy_phi", &MET_MuonBoy_phi, &b_MET_MuonBoy_phi);
   fChain->SetBranchAddress("MET_MuonBoy_et", &MET_MuonBoy_et, &b_MET_MuonBoy_et);
   fChain->SetBranchAddress("MET_MuonBoy_sumet", &MET_MuonBoy_sumet, &b_MET_MuonBoy_sumet);
   fChain->SetBranchAddress("MET_MuonBoy_etx_CentralReg", &MET_MuonBoy_etx_CentralReg, &b_MET_MuonBoy_etx_CentralReg);
   fChain->SetBranchAddress("MET_MuonBoy_ety_CentralReg", &MET_MuonBoy_ety_CentralReg, &b_MET_MuonBoy_ety_CentralReg);
   fChain->SetBranchAddress("MET_MuonBoy_sumet_CentralReg", &MET_MuonBoy_sumet_CentralReg, &b_MET_MuonBoy_sumet_CentralReg);
   fChain->SetBranchAddress("MET_MuonBoy_phi_CentralReg", &MET_MuonBoy_phi_CentralReg, &b_MET_MuonBoy_phi_CentralReg);
   fChain->SetBranchAddress("MET_MuonBoy_etx_EndcapRegion", &MET_MuonBoy_etx_EndcapRegion, &b_MET_MuonBoy_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_MuonBoy_ety_EndcapRegion", &MET_MuonBoy_ety_EndcapRegion, &b_MET_MuonBoy_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_MuonBoy_sumet_EndcapRegion", &MET_MuonBoy_sumet_EndcapRegion, &b_MET_MuonBoy_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_MuonBoy_phi_EndcapRegion", &MET_MuonBoy_phi_EndcapRegion, &b_MET_MuonBoy_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_MuonBoy_etx_ForwardReg", &MET_MuonBoy_etx_ForwardReg, &b_MET_MuonBoy_etx_ForwardReg);
   fChain->SetBranchAddress("MET_MuonBoy_ety_ForwardReg", &MET_MuonBoy_ety_ForwardReg, &b_MET_MuonBoy_ety_ForwardReg);
   fChain->SetBranchAddress("MET_MuonBoy_sumet_ForwardReg", &MET_MuonBoy_sumet_ForwardReg, &b_MET_MuonBoy_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_MuonBoy_phi_ForwardReg", &MET_MuonBoy_phi_ForwardReg, &b_MET_MuonBoy_phi_ForwardReg);
   fChain->SetBranchAddress("MET_CellOut_Eflow_etx", &MET_CellOut_Eflow_etx, &b_MET_CellOut_Eflow_etx);
   fChain->SetBranchAddress("MET_CellOut_Eflow_ety", &MET_CellOut_Eflow_ety, &b_MET_CellOut_Eflow_ety);
   fChain->SetBranchAddress("MET_CellOut_Eflow_phi", &MET_CellOut_Eflow_phi, &b_MET_CellOut_Eflow_phi);
   fChain->SetBranchAddress("MET_CellOut_Eflow_et", &MET_CellOut_Eflow_et, &b_MET_CellOut_Eflow_et);
   fChain->SetBranchAddress("MET_CellOut_Eflow_sumet", &MET_CellOut_Eflow_sumet, &b_MET_CellOut_Eflow_sumet);
   fChain->SetBranchAddress("MET_CellOut_Eflow_etx_CentralReg", &MET_CellOut_Eflow_etx_CentralReg, &b_MET_CellOut_Eflow_etx_CentralReg);
   fChain->SetBranchAddress("MET_CellOut_Eflow_ety_CentralReg", &MET_CellOut_Eflow_ety_CentralReg, &b_MET_CellOut_Eflow_ety_CentralReg);
   fChain->SetBranchAddress("MET_CellOut_Eflow_sumet_CentralReg", &MET_CellOut_Eflow_sumet_CentralReg, &b_MET_CellOut_Eflow_sumet_CentralReg);
   fChain->SetBranchAddress("MET_CellOut_Eflow_phi_CentralReg", &MET_CellOut_Eflow_phi_CentralReg, &b_MET_CellOut_Eflow_phi_CentralReg);
   fChain->SetBranchAddress("MET_CellOut_Eflow_etx_EndcapRegion", &MET_CellOut_Eflow_etx_EndcapRegion, &b_MET_CellOut_Eflow_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_CellOut_Eflow_ety_EndcapRegion", &MET_CellOut_Eflow_ety_EndcapRegion, &b_MET_CellOut_Eflow_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_CellOut_Eflow_sumet_EndcapRegion", &MET_CellOut_Eflow_sumet_EndcapRegion, &b_MET_CellOut_Eflow_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_CellOut_Eflow_phi_EndcapRegion", &MET_CellOut_Eflow_phi_EndcapRegion, &b_MET_CellOut_Eflow_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_CellOut_Eflow_etx_ForwardReg", &MET_CellOut_Eflow_etx_ForwardReg, &b_MET_CellOut_Eflow_etx_ForwardReg);
   fChain->SetBranchAddress("MET_CellOut_Eflow_ety_ForwardReg", &MET_CellOut_Eflow_ety_ForwardReg, &b_MET_CellOut_Eflow_ety_ForwardReg);
   fChain->SetBranchAddress("MET_CellOut_Eflow_sumet_ForwardReg", &MET_CellOut_Eflow_sumet_ForwardReg, &b_MET_CellOut_Eflow_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_CellOut_Eflow_phi_ForwardReg", &MET_CellOut_Eflow_phi_ForwardReg, &b_MET_CellOut_Eflow_phi_ForwardReg);
   fChain->SetBranchAddress("MET_CellOut_MiniJet_etx", &MET_CellOut_MiniJet_etx, &b_MET_CellOut_MiniJet_etx);
   fChain->SetBranchAddress("MET_CellOut_MiniJet_ety", &MET_CellOut_MiniJet_ety, &b_MET_CellOut_MiniJet_ety);
   fChain->SetBranchAddress("MET_CellOut_MiniJet_phi", &MET_CellOut_MiniJet_phi, &b_MET_CellOut_MiniJet_phi);
   fChain->SetBranchAddress("MET_CellOut_MiniJet_et", &MET_CellOut_MiniJet_et, &b_MET_CellOut_MiniJet_et);
   fChain->SetBranchAddress("MET_CellOut_MiniJet_sumet", &MET_CellOut_MiniJet_sumet, &b_MET_CellOut_MiniJet_sumet);
   fChain->SetBranchAddress("MET_CellOut_MiniJet_etx_CentralReg", &MET_CellOut_MiniJet_etx_CentralReg, &b_MET_CellOut_MiniJet_etx_CentralReg);
   fChain->SetBranchAddress("MET_CellOut_MiniJet_ety_CentralReg", &MET_CellOut_MiniJet_ety_CentralReg, &b_MET_CellOut_MiniJet_ety_CentralReg);
   fChain->SetBranchAddress("MET_CellOut_MiniJet_sumet_CentralReg", &MET_CellOut_MiniJet_sumet_CentralReg, &b_MET_CellOut_MiniJet_sumet_CentralReg);
   fChain->SetBranchAddress("MET_CellOut_MiniJet_phi_CentralReg", &MET_CellOut_MiniJet_phi_CentralReg, &b_MET_CellOut_MiniJet_phi_CentralReg);
   fChain->SetBranchAddress("MET_CellOut_MiniJet_etx_EndcapRegion", &MET_CellOut_MiniJet_etx_EndcapRegion, &b_MET_CellOut_MiniJet_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_CellOut_MiniJet_ety_EndcapRegion", &MET_CellOut_MiniJet_ety_EndcapRegion, &b_MET_CellOut_MiniJet_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_CellOut_MiniJet_sumet_EndcapRegion", &MET_CellOut_MiniJet_sumet_EndcapRegion, &b_MET_CellOut_MiniJet_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_CellOut_MiniJet_phi_EndcapRegion", &MET_CellOut_MiniJet_phi_EndcapRegion, &b_MET_CellOut_MiniJet_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_CellOut_MiniJet_etx_ForwardReg", &MET_CellOut_MiniJet_etx_ForwardReg, &b_MET_CellOut_MiniJet_etx_ForwardReg);
   fChain->SetBranchAddress("MET_CellOut_MiniJet_ety_ForwardReg", &MET_CellOut_MiniJet_ety_ForwardReg, &b_MET_CellOut_MiniJet_ety_ForwardReg);
   fChain->SetBranchAddress("MET_CellOut_MiniJet_sumet_ForwardReg", &MET_CellOut_MiniJet_sumet_ForwardReg, &b_MET_CellOut_MiniJet_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_CellOut_MiniJet_phi_ForwardReg", &MET_CellOut_MiniJet_phi_ForwardReg, &b_MET_CellOut_MiniJet_phi_ForwardReg);
   fChain->SetBranchAddress("MET_RefMuon_Track_etx", &MET_RefMuon_Track_etx, &b_MET_RefMuon_Track_etx);
   fChain->SetBranchAddress("MET_RefMuon_Track_ety", &MET_RefMuon_Track_ety, &b_MET_RefMuon_Track_ety);
   fChain->SetBranchAddress("MET_RefMuon_Track_phi", &MET_RefMuon_Track_phi, &b_MET_RefMuon_Track_phi);
   fChain->SetBranchAddress("MET_RefMuon_Track_et", &MET_RefMuon_Track_et, &b_MET_RefMuon_Track_et);
   fChain->SetBranchAddress("MET_RefMuon_Track_sumet", &MET_RefMuon_Track_sumet, &b_MET_RefMuon_Track_sumet);
   fChain->SetBranchAddress("MET_RefMuon_Track_etx_CentralReg", &MET_RefMuon_Track_etx_CentralReg, &b_MET_RefMuon_Track_etx_CentralReg);
   fChain->SetBranchAddress("MET_RefMuon_Track_ety_CentralReg", &MET_RefMuon_Track_ety_CentralReg, &b_MET_RefMuon_Track_ety_CentralReg);
   fChain->SetBranchAddress("MET_RefMuon_Track_sumet_CentralReg", &MET_RefMuon_Track_sumet_CentralReg, &b_MET_RefMuon_Track_sumet_CentralReg);
   fChain->SetBranchAddress("MET_RefMuon_Track_phi_CentralReg", &MET_RefMuon_Track_phi_CentralReg, &b_MET_RefMuon_Track_phi_CentralReg);
   fChain->SetBranchAddress("MET_RefMuon_Track_etx_EndcapRegion", &MET_RefMuon_Track_etx_EndcapRegion, &b_MET_RefMuon_Track_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_RefMuon_Track_ety_EndcapRegion", &MET_RefMuon_Track_ety_EndcapRegion, &b_MET_RefMuon_Track_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_RefMuon_Track_sumet_EndcapRegion", &MET_RefMuon_Track_sumet_EndcapRegion, &b_MET_RefMuon_Track_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_RefMuon_Track_phi_EndcapRegion", &MET_RefMuon_Track_phi_EndcapRegion, &b_MET_RefMuon_Track_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_RefMuon_Track_etx_ForwardReg", &MET_RefMuon_Track_etx_ForwardReg, &b_MET_RefMuon_Track_etx_ForwardReg);
   fChain->SetBranchAddress("MET_RefMuon_Track_ety_ForwardReg", &MET_RefMuon_Track_ety_ForwardReg, &b_MET_RefMuon_Track_ety_ForwardReg);
   fChain->SetBranchAddress("MET_RefMuon_Track_sumet_ForwardReg", &MET_RefMuon_Track_sumet_ForwardReg, &b_MET_RefMuon_Track_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_RefMuon_Track_phi_ForwardReg", &MET_RefMuon_Track_phi_ForwardReg, &b_MET_RefMuon_Track_phi_ForwardReg);
   fChain->SetBranchAddress("MET_RefMuon_Track_Staco_etx", &MET_RefMuon_Track_Staco_etx, &b_MET_RefMuon_Track_Staco_etx);
   fChain->SetBranchAddress("MET_RefMuon_Track_Staco_ety", &MET_RefMuon_Track_Staco_ety, &b_MET_RefMuon_Track_Staco_ety);
   fChain->SetBranchAddress("MET_RefMuon_Track_Staco_phi", &MET_RefMuon_Track_Staco_phi, &b_MET_RefMuon_Track_Staco_phi);
   fChain->SetBranchAddress("MET_RefMuon_Track_Staco_et", &MET_RefMuon_Track_Staco_et, &b_MET_RefMuon_Track_Staco_et);
   fChain->SetBranchAddress("MET_RefMuon_Track_Staco_sumet", &MET_RefMuon_Track_Staco_sumet, &b_MET_RefMuon_Track_Staco_sumet);
   fChain->SetBranchAddress("MET_RefMuon_Track_Staco_etx_CentralReg", &MET_RefMuon_Track_Staco_etx_CentralReg, &b_MET_RefMuon_Track_Staco_etx_CentralReg);
   fChain->SetBranchAddress("MET_RefMuon_Track_Staco_ety_CentralReg", &MET_RefMuon_Track_Staco_ety_CentralReg, &b_MET_RefMuon_Track_Staco_ety_CentralReg);
   fChain->SetBranchAddress("MET_RefMuon_Track_Staco_sumet_CentralReg", &MET_RefMuon_Track_Staco_sumet_CentralReg, &b_MET_RefMuon_Track_Staco_sumet_CentralReg);
   fChain->SetBranchAddress("MET_RefMuon_Track_Staco_phi_CentralReg", &MET_RefMuon_Track_Staco_phi_CentralReg, &b_MET_RefMuon_Track_Staco_phi_CentralReg);
   fChain->SetBranchAddress("MET_RefMuon_Track_Staco_etx_EndcapRegion", &MET_RefMuon_Track_Staco_etx_EndcapRegion, &b_MET_RefMuon_Track_Staco_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_RefMuon_Track_Staco_ety_EndcapRegion", &MET_RefMuon_Track_Staco_ety_EndcapRegion, &b_MET_RefMuon_Track_Staco_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_RefMuon_Track_Staco_sumet_EndcapRegion", &MET_RefMuon_Track_Staco_sumet_EndcapRegion, &b_MET_RefMuon_Track_Staco_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_RefMuon_Track_Staco_phi_EndcapRegion", &MET_RefMuon_Track_Staco_phi_EndcapRegion, &b_MET_RefMuon_Track_Staco_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_RefMuon_Track_Staco_etx_ForwardReg", &MET_RefMuon_Track_Staco_etx_ForwardReg, &b_MET_RefMuon_Track_Staco_etx_ForwardReg);
   fChain->SetBranchAddress("MET_RefMuon_Track_Staco_ety_ForwardReg", &MET_RefMuon_Track_Staco_ety_ForwardReg, &b_MET_RefMuon_Track_Staco_ety_ForwardReg);
   fChain->SetBranchAddress("MET_RefMuon_Track_Staco_sumet_ForwardReg", &MET_RefMuon_Track_Staco_sumet_ForwardReg, &b_MET_RefMuon_Track_Staco_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_RefMuon_Track_Staco_phi_ForwardReg", &MET_RefMuon_Track_Staco_phi_ForwardReg, &b_MET_RefMuon_Track_Staco_phi_ForwardReg);
   fChain->SetBranchAddress("MET_RefMuon_Track_Muid_etx", &MET_RefMuon_Track_Muid_etx, &b_MET_RefMuon_Track_Muid_etx);
   fChain->SetBranchAddress("MET_RefMuon_Track_Muid_ety", &MET_RefMuon_Track_Muid_ety, &b_MET_RefMuon_Track_Muid_ety);
   fChain->SetBranchAddress("MET_RefMuon_Track_Muid_phi", &MET_RefMuon_Track_Muid_phi, &b_MET_RefMuon_Track_Muid_phi);
   fChain->SetBranchAddress("MET_RefMuon_Track_Muid_et", &MET_RefMuon_Track_Muid_et, &b_MET_RefMuon_Track_Muid_et);
   fChain->SetBranchAddress("MET_RefMuon_Track_Muid_sumet", &MET_RefMuon_Track_Muid_sumet, &b_MET_RefMuon_Track_Muid_sumet);
   fChain->SetBranchAddress("MET_RefMuon_Track_Muid_etx_CentralReg", &MET_RefMuon_Track_Muid_etx_CentralReg, &b_MET_RefMuon_Track_Muid_etx_CentralReg);
   fChain->SetBranchAddress("MET_RefMuon_Track_Muid_ety_CentralReg", &MET_RefMuon_Track_Muid_ety_CentralReg, &b_MET_RefMuon_Track_Muid_ety_CentralReg);
   fChain->SetBranchAddress("MET_RefMuon_Track_Muid_sumet_CentralReg", &MET_RefMuon_Track_Muid_sumet_CentralReg, &b_MET_RefMuon_Track_Muid_sumet_CentralReg);
   fChain->SetBranchAddress("MET_RefMuon_Track_Muid_phi_CentralReg", &MET_RefMuon_Track_Muid_phi_CentralReg, &b_MET_RefMuon_Track_Muid_phi_CentralReg);
   fChain->SetBranchAddress("MET_RefMuon_Track_Muid_etx_EndcapRegion", &MET_RefMuon_Track_Muid_etx_EndcapRegion, &b_MET_RefMuon_Track_Muid_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_RefMuon_Track_Muid_ety_EndcapRegion", &MET_RefMuon_Track_Muid_ety_EndcapRegion, &b_MET_RefMuon_Track_Muid_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_RefMuon_Track_Muid_sumet_EndcapRegion", &MET_RefMuon_Track_Muid_sumet_EndcapRegion, &b_MET_RefMuon_Track_Muid_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_RefMuon_Track_Muid_phi_EndcapRegion", &MET_RefMuon_Track_Muid_phi_EndcapRegion, &b_MET_RefMuon_Track_Muid_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_RefMuon_Track_Muid_etx_ForwardReg", &MET_RefMuon_Track_Muid_etx_ForwardReg, &b_MET_RefMuon_Track_Muid_etx_ForwardReg);
   fChain->SetBranchAddress("MET_RefMuon_Track_Muid_ety_ForwardReg", &MET_RefMuon_Track_Muid_ety_ForwardReg, &b_MET_RefMuon_Track_Muid_ety_ForwardReg);
   fChain->SetBranchAddress("MET_RefMuon_Track_Muid_sumet_ForwardReg", &MET_RefMuon_Track_Muid_sumet_ForwardReg, &b_MET_RefMuon_Track_Muid_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_RefMuon_Track_Muid_phi_ForwardReg", &MET_RefMuon_Track_Muid_phi_ForwardReg, &b_MET_RefMuon_Track_Muid_phi_ForwardReg);
   fChain->SetBranchAddress("MET_CryoCone_etx", &MET_CryoCone_etx, &b_MET_CryoCone_etx);
   fChain->SetBranchAddress("MET_CryoCone_ety", &MET_CryoCone_ety, &b_MET_CryoCone_ety);
   fChain->SetBranchAddress("MET_CryoCone_phi", &MET_CryoCone_phi, &b_MET_CryoCone_phi);
   fChain->SetBranchAddress("MET_CryoCone_et", &MET_CryoCone_et, &b_MET_CryoCone_et);
   fChain->SetBranchAddress("MET_CryoCone_sumet", &MET_CryoCone_sumet, &b_MET_CryoCone_sumet);
   fChain->SetBranchAddress("MET_CryoCone_etx_CentralReg", &MET_CryoCone_etx_CentralReg, &b_MET_CryoCone_etx_CentralReg);
   fChain->SetBranchAddress("MET_CryoCone_ety_CentralReg", &MET_CryoCone_ety_CentralReg, &b_MET_CryoCone_ety_CentralReg);
   fChain->SetBranchAddress("MET_CryoCone_sumet_CentralReg", &MET_CryoCone_sumet_CentralReg, &b_MET_CryoCone_sumet_CentralReg);
   fChain->SetBranchAddress("MET_CryoCone_phi_CentralReg", &MET_CryoCone_phi_CentralReg, &b_MET_CryoCone_phi_CentralReg);
   fChain->SetBranchAddress("MET_CryoCone_etx_EndcapRegion", &MET_CryoCone_etx_EndcapRegion, &b_MET_CryoCone_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_CryoCone_ety_EndcapRegion", &MET_CryoCone_ety_EndcapRegion, &b_MET_CryoCone_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_CryoCone_sumet_EndcapRegion", &MET_CryoCone_sumet_EndcapRegion, &b_MET_CryoCone_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_CryoCone_phi_EndcapRegion", &MET_CryoCone_phi_EndcapRegion, &b_MET_CryoCone_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_CryoCone_etx_ForwardReg", &MET_CryoCone_etx_ForwardReg, &b_MET_CryoCone_etx_ForwardReg);
   fChain->SetBranchAddress("MET_CryoCone_ety_ForwardReg", &MET_CryoCone_ety_ForwardReg, &b_MET_CryoCone_ety_ForwardReg);
   fChain->SetBranchAddress("MET_CryoCone_sumet_ForwardReg", &MET_CryoCone_sumet_ForwardReg, &b_MET_CryoCone_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_CryoCone_phi_ForwardReg", &MET_CryoCone_phi_ForwardReg, &b_MET_CryoCone_phi_ForwardReg);
   fChain->SetBranchAddress("MET_Final_etx", &MET_Final_etx, &b_MET_Final_etx);
   fChain->SetBranchAddress("MET_Final_ety", &MET_Final_ety, &b_MET_Final_ety);
   fChain->SetBranchAddress("MET_Final_phi", &MET_Final_phi, &b_MET_Final_phi);
   fChain->SetBranchAddress("MET_Final_et", &MET_Final_et, &b_MET_Final_et);
   fChain->SetBranchAddress("MET_Final_sumet", &MET_Final_sumet, &b_MET_Final_sumet);
   fChain->SetBranchAddress("MET_Final_etx_CentralReg", &MET_Final_etx_CentralReg, &b_MET_Final_etx_CentralReg);
   fChain->SetBranchAddress("MET_Final_ety_CentralReg", &MET_Final_ety_CentralReg, &b_MET_Final_ety_CentralReg);
   fChain->SetBranchAddress("MET_Final_sumet_CentralReg", &MET_Final_sumet_CentralReg, &b_MET_Final_sumet_CentralReg);
   fChain->SetBranchAddress("MET_Final_phi_CentralReg", &MET_Final_phi_CentralReg, &b_MET_Final_phi_CentralReg);
   fChain->SetBranchAddress("MET_Final_etx_EndcapRegion", &MET_Final_etx_EndcapRegion, &b_MET_Final_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_Final_ety_EndcapRegion", &MET_Final_ety_EndcapRegion, &b_MET_Final_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_Final_sumet_EndcapRegion", &MET_Final_sumet_EndcapRegion, &b_MET_Final_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_Final_phi_EndcapRegion", &MET_Final_phi_EndcapRegion, &b_MET_Final_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_Final_etx_ForwardReg", &MET_Final_etx_ForwardReg, &b_MET_Final_etx_ForwardReg);
   fChain->SetBranchAddress("MET_Final_ety_ForwardReg", &MET_Final_ety_ForwardReg, &b_MET_Final_ety_ForwardReg);
   fChain->SetBranchAddress("MET_Final_sumet_ForwardReg", &MET_Final_sumet_ForwardReg, &b_MET_Final_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_Final_phi_ForwardReg", &MET_Final_phi_ForwardReg, &b_MET_Final_phi_ForwardReg);
   fChain->SetBranchAddress("MET_MuonBoy_Spectro_etx", &MET_MuonBoy_Spectro_etx, &b_MET_MuonBoy_Spectro_etx);
   fChain->SetBranchAddress("MET_MuonBoy_Spectro_ety", &MET_MuonBoy_Spectro_ety, &b_MET_MuonBoy_Spectro_ety);
   fChain->SetBranchAddress("MET_MuonBoy_Spectro_phi", &MET_MuonBoy_Spectro_phi, &b_MET_MuonBoy_Spectro_phi);
   fChain->SetBranchAddress("MET_MuonBoy_Spectro_et", &MET_MuonBoy_Spectro_et, &b_MET_MuonBoy_Spectro_et);
   fChain->SetBranchAddress("MET_MuonBoy_Spectro_sumet", &MET_MuonBoy_Spectro_sumet, &b_MET_MuonBoy_Spectro_sumet);
   fChain->SetBranchAddress("MET_MuonBoy_Spectro_etx_CentralReg", &MET_MuonBoy_Spectro_etx_CentralReg, &b_MET_MuonBoy_Spectro_etx_CentralReg);
   fChain->SetBranchAddress("MET_MuonBoy_Spectro_ety_CentralReg", &MET_MuonBoy_Spectro_ety_CentralReg, &b_MET_MuonBoy_Spectro_ety_CentralReg);
   fChain->SetBranchAddress("MET_MuonBoy_Spectro_sumet_CentralReg", &MET_MuonBoy_Spectro_sumet_CentralReg, &b_MET_MuonBoy_Spectro_sumet_CentralReg);
   fChain->SetBranchAddress("MET_MuonBoy_Spectro_phi_CentralReg", &MET_MuonBoy_Spectro_phi_CentralReg, &b_MET_MuonBoy_Spectro_phi_CentralReg);
   fChain->SetBranchAddress("MET_MuonBoy_Spectro_etx_EndcapRegion", &MET_MuonBoy_Spectro_etx_EndcapRegion, &b_MET_MuonBoy_Spectro_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_MuonBoy_Spectro_ety_EndcapRegion", &MET_MuonBoy_Spectro_ety_EndcapRegion, &b_MET_MuonBoy_Spectro_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_MuonBoy_Spectro_sumet_EndcapRegion", &MET_MuonBoy_Spectro_sumet_EndcapRegion, &b_MET_MuonBoy_Spectro_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_MuonBoy_Spectro_phi_EndcapRegion", &MET_MuonBoy_Spectro_phi_EndcapRegion, &b_MET_MuonBoy_Spectro_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_MuonBoy_Spectro_etx_ForwardReg", &MET_MuonBoy_Spectro_etx_ForwardReg, &b_MET_MuonBoy_Spectro_etx_ForwardReg);
   fChain->SetBranchAddress("MET_MuonBoy_Spectro_ety_ForwardReg", &MET_MuonBoy_Spectro_ety_ForwardReg, &b_MET_MuonBoy_Spectro_ety_ForwardReg);
   fChain->SetBranchAddress("MET_MuonBoy_Spectro_sumet_ForwardReg", &MET_MuonBoy_Spectro_sumet_ForwardReg, &b_MET_MuonBoy_Spectro_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_MuonBoy_Spectro_phi_ForwardReg", &MET_MuonBoy_Spectro_phi_ForwardReg, &b_MET_MuonBoy_Spectro_phi_ForwardReg);
   fChain->SetBranchAddress("MET_MuonBoy_Track_etx", &MET_MuonBoy_Track_etx, &b_MET_MuonBoy_Track_etx);
   fChain->SetBranchAddress("MET_MuonBoy_Track_ety", &MET_MuonBoy_Track_ety, &b_MET_MuonBoy_Track_ety);
   fChain->SetBranchAddress("MET_MuonBoy_Track_phi", &MET_MuonBoy_Track_phi, &b_MET_MuonBoy_Track_phi);
   fChain->SetBranchAddress("MET_MuonBoy_Track_et", &MET_MuonBoy_Track_et, &b_MET_MuonBoy_Track_et);
   fChain->SetBranchAddress("MET_MuonBoy_Track_sumet", &MET_MuonBoy_Track_sumet, &b_MET_MuonBoy_Track_sumet);
   fChain->SetBranchAddress("MET_MuonBoy_Track_etx_CentralReg", &MET_MuonBoy_Track_etx_CentralReg, &b_MET_MuonBoy_Track_etx_CentralReg);
   fChain->SetBranchAddress("MET_MuonBoy_Track_ety_CentralReg", &MET_MuonBoy_Track_ety_CentralReg, &b_MET_MuonBoy_Track_ety_CentralReg);
   fChain->SetBranchAddress("MET_MuonBoy_Track_sumet_CentralReg", &MET_MuonBoy_Track_sumet_CentralReg, &b_MET_MuonBoy_Track_sumet_CentralReg);
   fChain->SetBranchAddress("MET_MuonBoy_Track_phi_CentralReg", &MET_MuonBoy_Track_phi_CentralReg, &b_MET_MuonBoy_Track_phi_CentralReg);
   fChain->SetBranchAddress("MET_MuonBoy_Track_etx_EndcapRegion", &MET_MuonBoy_Track_etx_EndcapRegion, &b_MET_MuonBoy_Track_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_MuonBoy_Track_ety_EndcapRegion", &MET_MuonBoy_Track_ety_EndcapRegion, &b_MET_MuonBoy_Track_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_MuonBoy_Track_sumet_EndcapRegion", &MET_MuonBoy_Track_sumet_EndcapRegion, &b_MET_MuonBoy_Track_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_MuonBoy_Track_phi_EndcapRegion", &MET_MuonBoy_Track_phi_EndcapRegion, &b_MET_MuonBoy_Track_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_MuonBoy_Track_etx_ForwardReg", &MET_MuonBoy_Track_etx_ForwardReg, &b_MET_MuonBoy_Track_etx_ForwardReg);
   fChain->SetBranchAddress("MET_MuonBoy_Track_ety_ForwardReg", &MET_MuonBoy_Track_ety_ForwardReg, &b_MET_MuonBoy_Track_ety_ForwardReg);
   fChain->SetBranchAddress("MET_MuonBoy_Track_sumet_ForwardReg", &MET_MuonBoy_Track_sumet_ForwardReg, &b_MET_MuonBoy_Track_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_MuonBoy_Track_phi_ForwardReg", &MET_MuonBoy_Track_phi_ForwardReg, &b_MET_MuonBoy_Track_phi_ForwardReg);
   fChain->SetBranchAddress("MET_MuonMuid_etx", &MET_MuonMuid_etx, &b_MET_MuonMuid_etx);
   fChain->SetBranchAddress("MET_MuonMuid_ety", &MET_MuonMuid_ety, &b_MET_MuonMuid_ety);
   fChain->SetBranchAddress("MET_MuonMuid_phi", &MET_MuonMuid_phi, &b_MET_MuonMuid_phi);
   fChain->SetBranchAddress("MET_MuonMuid_et", &MET_MuonMuid_et, &b_MET_MuonMuid_et);
   fChain->SetBranchAddress("MET_MuonMuid_sumet", &MET_MuonMuid_sumet, &b_MET_MuonMuid_sumet);
   fChain->SetBranchAddress("MET_MuonMuid_etx_CentralReg", &MET_MuonMuid_etx_CentralReg, &b_MET_MuonMuid_etx_CentralReg);
   fChain->SetBranchAddress("MET_MuonMuid_ety_CentralReg", &MET_MuonMuid_ety_CentralReg, &b_MET_MuonMuid_ety_CentralReg);
   fChain->SetBranchAddress("MET_MuonMuid_sumet_CentralReg", &MET_MuonMuid_sumet_CentralReg, &b_MET_MuonMuid_sumet_CentralReg);
   fChain->SetBranchAddress("MET_MuonMuid_phi_CentralReg", &MET_MuonMuid_phi_CentralReg, &b_MET_MuonMuid_phi_CentralReg);
   fChain->SetBranchAddress("MET_MuonMuid_etx_EndcapRegion", &MET_MuonMuid_etx_EndcapRegion, &b_MET_MuonMuid_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_MuonMuid_ety_EndcapRegion", &MET_MuonMuid_ety_EndcapRegion, &b_MET_MuonMuid_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_MuonMuid_sumet_EndcapRegion", &MET_MuonMuid_sumet_EndcapRegion, &b_MET_MuonMuid_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_MuonMuid_phi_EndcapRegion", &MET_MuonMuid_phi_EndcapRegion, &b_MET_MuonMuid_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_MuonMuid_etx_ForwardReg", &MET_MuonMuid_etx_ForwardReg, &b_MET_MuonMuid_etx_ForwardReg);
   fChain->SetBranchAddress("MET_MuonMuid_ety_ForwardReg", &MET_MuonMuid_ety_ForwardReg, &b_MET_MuonMuid_ety_ForwardReg);
   fChain->SetBranchAddress("MET_MuonMuid_sumet_ForwardReg", &MET_MuonMuid_sumet_ForwardReg, &b_MET_MuonMuid_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_MuonMuid_phi_ForwardReg", &MET_MuonMuid_phi_ForwardReg, &b_MET_MuonMuid_phi_ForwardReg);
   fChain->SetBranchAddress("MET_Muid_etx", &MET_Muid_etx, &b_MET_Muid_etx);
   fChain->SetBranchAddress("MET_Muid_ety", &MET_Muid_ety, &b_MET_Muid_ety);
   fChain->SetBranchAddress("MET_Muid_phi", &MET_Muid_phi, &b_MET_Muid_phi);
   fChain->SetBranchAddress("MET_Muid_et", &MET_Muid_et, &b_MET_Muid_et);
   fChain->SetBranchAddress("MET_Muid_sumet", &MET_Muid_sumet, &b_MET_Muid_sumet);
   fChain->SetBranchAddress("MET_Muid_etx_CentralReg", &MET_Muid_etx_CentralReg, &b_MET_Muid_etx_CentralReg);
   fChain->SetBranchAddress("MET_Muid_ety_CentralReg", &MET_Muid_ety_CentralReg, &b_MET_Muid_ety_CentralReg);
   fChain->SetBranchAddress("MET_Muid_sumet_CentralReg", &MET_Muid_sumet_CentralReg, &b_MET_Muid_sumet_CentralReg);
   fChain->SetBranchAddress("MET_Muid_phi_CentralReg", &MET_Muid_phi_CentralReg, &b_MET_Muid_phi_CentralReg);
   fChain->SetBranchAddress("MET_Muid_etx_EndcapRegion", &MET_Muid_etx_EndcapRegion, &b_MET_Muid_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_Muid_ety_EndcapRegion", &MET_Muid_ety_EndcapRegion, &b_MET_Muid_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_Muid_sumet_EndcapRegion", &MET_Muid_sumet_EndcapRegion, &b_MET_Muid_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_Muid_phi_EndcapRegion", &MET_Muid_phi_EndcapRegion, &b_MET_Muid_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_Muid_etx_ForwardReg", &MET_Muid_etx_ForwardReg, &b_MET_Muid_etx_ForwardReg);
   fChain->SetBranchAddress("MET_Muid_ety_ForwardReg", &MET_Muid_ety_ForwardReg, &b_MET_Muid_ety_ForwardReg);
   fChain->SetBranchAddress("MET_Muid_sumet_ForwardReg", &MET_Muid_sumet_ForwardReg, &b_MET_Muid_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_Muid_phi_ForwardReg", &MET_Muid_phi_ForwardReg, &b_MET_Muid_phi_ForwardReg);
   fChain->SetBranchAddress("MET_Muid_Spectro_etx", &MET_Muid_Spectro_etx, &b_MET_Muid_Spectro_etx);
   fChain->SetBranchAddress("MET_Muid_Spectro_ety", &MET_Muid_Spectro_ety, &b_MET_Muid_Spectro_ety);
   fChain->SetBranchAddress("MET_Muid_Spectro_phi", &MET_Muid_Spectro_phi, &b_MET_Muid_Spectro_phi);
   fChain->SetBranchAddress("MET_Muid_Spectro_et", &MET_Muid_Spectro_et, &b_MET_Muid_Spectro_et);
   fChain->SetBranchAddress("MET_Muid_Spectro_sumet", &MET_Muid_Spectro_sumet, &b_MET_Muid_Spectro_sumet);
   fChain->SetBranchAddress("MET_Muid_Spectro_etx_CentralReg", &MET_Muid_Spectro_etx_CentralReg, &b_MET_Muid_Spectro_etx_CentralReg);
   fChain->SetBranchAddress("MET_Muid_Spectro_ety_CentralReg", &MET_Muid_Spectro_ety_CentralReg, &b_MET_Muid_Spectro_ety_CentralReg);
   fChain->SetBranchAddress("MET_Muid_Spectro_sumet_CentralReg", &MET_Muid_Spectro_sumet_CentralReg, &b_MET_Muid_Spectro_sumet_CentralReg);
   fChain->SetBranchAddress("MET_Muid_Spectro_phi_CentralReg", &MET_Muid_Spectro_phi_CentralReg, &b_MET_Muid_Spectro_phi_CentralReg);
   fChain->SetBranchAddress("MET_Muid_Spectro_etx_EndcapRegion", &MET_Muid_Spectro_etx_EndcapRegion, &b_MET_Muid_Spectro_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_Muid_Spectro_ety_EndcapRegion", &MET_Muid_Spectro_ety_EndcapRegion, &b_MET_Muid_Spectro_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_Muid_Spectro_sumet_EndcapRegion", &MET_Muid_Spectro_sumet_EndcapRegion, &b_MET_Muid_Spectro_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_Muid_Spectro_phi_EndcapRegion", &MET_Muid_Spectro_phi_EndcapRegion, &b_MET_Muid_Spectro_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_Muid_Spectro_etx_ForwardReg", &MET_Muid_Spectro_etx_ForwardReg, &b_MET_Muid_Spectro_etx_ForwardReg);
   fChain->SetBranchAddress("MET_Muid_Spectro_ety_ForwardReg", &MET_Muid_Spectro_ety_ForwardReg, &b_MET_Muid_Spectro_ety_ForwardReg);
   fChain->SetBranchAddress("MET_Muid_Spectro_sumet_ForwardReg", &MET_Muid_Spectro_sumet_ForwardReg, &b_MET_Muid_Spectro_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_Muid_Spectro_phi_ForwardReg", &MET_Muid_Spectro_phi_ForwardReg, &b_MET_Muid_Spectro_phi_ForwardReg);
   fChain->SetBranchAddress("MET_Muid_Track_etx", &MET_Muid_Track_etx, &b_MET_Muid_Track_etx);
   fChain->SetBranchAddress("MET_Muid_Track_ety", &MET_Muid_Track_ety, &b_MET_Muid_Track_ety);
   fChain->SetBranchAddress("MET_Muid_Track_phi", &MET_Muid_Track_phi, &b_MET_Muid_Track_phi);
   fChain->SetBranchAddress("MET_Muid_Track_et", &MET_Muid_Track_et, &b_MET_Muid_Track_et);
   fChain->SetBranchAddress("MET_Muid_Track_sumet", &MET_Muid_Track_sumet, &b_MET_Muid_Track_sumet);
   fChain->SetBranchAddress("MET_Muid_Track_etx_CentralReg", &MET_Muid_Track_etx_CentralReg, &b_MET_Muid_Track_etx_CentralReg);
   fChain->SetBranchAddress("MET_Muid_Track_ety_CentralReg", &MET_Muid_Track_ety_CentralReg, &b_MET_Muid_Track_ety_CentralReg);
   fChain->SetBranchAddress("MET_Muid_Track_sumet_CentralReg", &MET_Muid_Track_sumet_CentralReg, &b_MET_Muid_Track_sumet_CentralReg);
   fChain->SetBranchAddress("MET_Muid_Track_phi_CentralReg", &MET_Muid_Track_phi_CentralReg, &b_MET_Muid_Track_phi_CentralReg);
   fChain->SetBranchAddress("MET_Muid_Track_etx_EndcapRegion", &MET_Muid_Track_etx_EndcapRegion, &b_MET_Muid_Track_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_Muid_Track_ety_EndcapRegion", &MET_Muid_Track_ety_EndcapRegion, &b_MET_Muid_Track_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_Muid_Track_sumet_EndcapRegion", &MET_Muid_Track_sumet_EndcapRegion, &b_MET_Muid_Track_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_Muid_Track_phi_EndcapRegion", &MET_Muid_Track_phi_EndcapRegion, &b_MET_Muid_Track_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_Muid_Track_etx_ForwardReg", &MET_Muid_Track_etx_ForwardReg, &b_MET_Muid_Track_etx_ForwardReg);
   fChain->SetBranchAddress("MET_Muid_Track_ety_ForwardReg", &MET_Muid_Track_ety_ForwardReg, &b_MET_Muid_Track_ety_ForwardReg);
   fChain->SetBranchAddress("MET_Muid_Track_sumet_ForwardReg", &MET_Muid_Track_sumet_ForwardReg, &b_MET_Muid_Track_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_Muid_Track_phi_ForwardReg", &MET_Muid_Track_phi_ForwardReg, &b_MET_Muid_Track_phi_ForwardReg);
   fChain->SetBranchAddress("MET_Muon_etx", &MET_Muon_etx, &b_MET_Muon_etx);
   fChain->SetBranchAddress("MET_Muon_ety", &MET_Muon_ety, &b_MET_Muon_ety);
   fChain->SetBranchAddress("MET_Muon_phi", &MET_Muon_phi, &b_MET_Muon_phi);
   fChain->SetBranchAddress("MET_Muon_et", &MET_Muon_et, &b_MET_Muon_et);
   fChain->SetBranchAddress("MET_Muon_sumet", &MET_Muon_sumet, &b_MET_Muon_sumet);
   fChain->SetBranchAddress("MET_Muon_etx_CentralReg", &MET_Muon_etx_CentralReg, &b_MET_Muon_etx_CentralReg);
   fChain->SetBranchAddress("MET_Muon_ety_CentralReg", &MET_Muon_ety_CentralReg, &b_MET_Muon_ety_CentralReg);
   fChain->SetBranchAddress("MET_Muon_sumet_CentralReg", &MET_Muon_sumet_CentralReg, &b_MET_Muon_sumet_CentralReg);
   fChain->SetBranchAddress("MET_Muon_phi_CentralReg", &MET_Muon_phi_CentralReg, &b_MET_Muon_phi_CentralReg);
   fChain->SetBranchAddress("MET_Muon_etx_EndcapRegion", &MET_Muon_etx_EndcapRegion, &b_MET_Muon_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_Muon_ety_EndcapRegion", &MET_Muon_ety_EndcapRegion, &b_MET_Muon_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_Muon_sumet_EndcapRegion", &MET_Muon_sumet_EndcapRegion, &b_MET_Muon_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_Muon_phi_EndcapRegion", &MET_Muon_phi_EndcapRegion, &b_MET_Muon_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_Muon_etx_ForwardReg", &MET_Muon_etx_ForwardReg, &b_MET_Muon_etx_ForwardReg);
   fChain->SetBranchAddress("MET_Muon_ety_ForwardReg", &MET_Muon_ety_ForwardReg, &b_MET_Muon_ety_ForwardReg);
   fChain->SetBranchAddress("MET_Muon_sumet_ForwardReg", &MET_Muon_sumet_ForwardReg, &b_MET_Muon_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_Muon_phi_ForwardReg", &MET_Muon_phi_ForwardReg, &b_MET_Muon_phi_ForwardReg);
   fChain->SetBranchAddress("MET_TopoObj_etx", &MET_TopoObj_etx, &b_MET_TopoObj_etx);
   fChain->SetBranchAddress("MET_TopoObj_ety", &MET_TopoObj_ety, &b_MET_TopoObj_ety);
   fChain->SetBranchAddress("MET_TopoObj_phi", &MET_TopoObj_phi, &b_MET_TopoObj_phi);
   fChain->SetBranchAddress("MET_TopoObj_et", &MET_TopoObj_et, &b_MET_TopoObj_et);
   fChain->SetBranchAddress("MET_TopoObj_sumet", &MET_TopoObj_sumet, &b_MET_TopoObj_sumet);
   fChain->SetBranchAddress("MET_TopoObj_etx_CentralReg", &MET_TopoObj_etx_CentralReg, &b_MET_TopoObj_etx_CentralReg);
   fChain->SetBranchAddress("MET_TopoObj_ety_CentralReg", &MET_TopoObj_ety_CentralReg, &b_MET_TopoObj_ety_CentralReg);
   fChain->SetBranchAddress("MET_TopoObj_sumet_CentralReg", &MET_TopoObj_sumet_CentralReg, &b_MET_TopoObj_sumet_CentralReg);
   fChain->SetBranchAddress("MET_TopoObj_phi_CentralReg", &MET_TopoObj_phi_CentralReg, &b_MET_TopoObj_phi_CentralReg);
   fChain->SetBranchAddress("MET_TopoObj_etx_EndcapRegion", &MET_TopoObj_etx_EndcapRegion, &b_MET_TopoObj_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_TopoObj_ety_EndcapRegion", &MET_TopoObj_ety_EndcapRegion, &b_MET_TopoObj_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_TopoObj_sumet_EndcapRegion", &MET_TopoObj_sumet_EndcapRegion, &b_MET_TopoObj_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_TopoObj_phi_EndcapRegion", &MET_TopoObj_phi_EndcapRegion, &b_MET_TopoObj_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_TopoObj_etx_ForwardReg", &MET_TopoObj_etx_ForwardReg, &b_MET_TopoObj_etx_ForwardReg);
   fChain->SetBranchAddress("MET_TopoObj_ety_ForwardReg", &MET_TopoObj_ety_ForwardReg, &b_MET_TopoObj_ety_ForwardReg);
   fChain->SetBranchAddress("MET_TopoObj_sumet_ForwardReg", &MET_TopoObj_sumet_ForwardReg, &b_MET_TopoObj_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_TopoObj_phi_ForwardReg", &MET_TopoObj_phi_ForwardReg, &b_MET_TopoObj_phi_ForwardReg);
   fChain->SetBranchAddress("MET_LocHadTopoObj_etx", &MET_LocHadTopoObj_etx, &b_MET_LocHadTopoObj_etx);
   fChain->SetBranchAddress("MET_LocHadTopoObj_ety", &MET_LocHadTopoObj_ety, &b_MET_LocHadTopoObj_ety);
   fChain->SetBranchAddress("MET_LocHadTopoObj_phi", &MET_LocHadTopoObj_phi, &b_MET_LocHadTopoObj_phi);
   fChain->SetBranchAddress("MET_LocHadTopoObj_et", &MET_LocHadTopoObj_et, &b_MET_LocHadTopoObj_et);
   fChain->SetBranchAddress("MET_LocHadTopoObj_sumet", &MET_LocHadTopoObj_sumet, &b_MET_LocHadTopoObj_sumet);
   fChain->SetBranchAddress("MET_LocHadTopoObj_etx_CentralReg", &MET_LocHadTopoObj_etx_CentralReg, &b_MET_LocHadTopoObj_etx_CentralReg);
   fChain->SetBranchAddress("MET_LocHadTopoObj_ety_CentralReg", &MET_LocHadTopoObj_ety_CentralReg, &b_MET_LocHadTopoObj_ety_CentralReg);
   fChain->SetBranchAddress("MET_LocHadTopoObj_sumet_CentralReg", &MET_LocHadTopoObj_sumet_CentralReg, &b_MET_LocHadTopoObj_sumet_CentralReg);
   fChain->SetBranchAddress("MET_LocHadTopoObj_phi_CentralReg", &MET_LocHadTopoObj_phi_CentralReg, &b_MET_LocHadTopoObj_phi_CentralReg);
   fChain->SetBranchAddress("MET_LocHadTopoObj_etx_EndcapRegion", &MET_LocHadTopoObj_etx_EndcapRegion, &b_MET_LocHadTopoObj_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_LocHadTopoObj_ety_EndcapRegion", &MET_LocHadTopoObj_ety_EndcapRegion, &b_MET_LocHadTopoObj_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_LocHadTopoObj_sumet_EndcapRegion", &MET_LocHadTopoObj_sumet_EndcapRegion, &b_MET_LocHadTopoObj_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_LocHadTopoObj_phi_EndcapRegion", &MET_LocHadTopoObj_phi_EndcapRegion, &b_MET_LocHadTopoObj_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_LocHadTopoObj_etx_ForwardReg", &MET_LocHadTopoObj_etx_ForwardReg, &b_MET_LocHadTopoObj_etx_ForwardReg);
   fChain->SetBranchAddress("MET_LocHadTopoObj_ety_ForwardReg", &MET_LocHadTopoObj_ety_ForwardReg, &b_MET_LocHadTopoObj_ety_ForwardReg);
   fChain->SetBranchAddress("MET_LocHadTopoObj_sumet_ForwardReg", &MET_LocHadTopoObj_sumet_ForwardReg, &b_MET_LocHadTopoObj_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_LocHadTopoObj_phi_ForwardReg", &MET_LocHadTopoObj_phi_ForwardReg, &b_MET_LocHadTopoObj_phi_ForwardReg);
   fChain->SetBranchAddress("MET_Topo_etx", &MET_Topo_etx, &b_MET_Topo_etx);
   fChain->SetBranchAddress("MET_Topo_ety", &MET_Topo_ety, &b_MET_Topo_ety);
   fChain->SetBranchAddress("MET_Topo_phi", &MET_Topo_phi, &b_MET_Topo_phi);
   fChain->SetBranchAddress("MET_Topo_et", &MET_Topo_et, &b_MET_Topo_et);
   fChain->SetBranchAddress("MET_Topo_sumet", &MET_Topo_sumet, &b_MET_Topo_sumet);
   fChain->SetBranchAddress("MET_Topo_SUMET_EMFrac", &MET_Topo_SUMET_EMFrac, &b_MET_Topo_SUMET_EMFrac);
   fChain->SetBranchAddress("MET_Topo_etx_PEMB", &MET_Topo_etx_PEMB, &b_MET_Topo_etx_PEMB);
   fChain->SetBranchAddress("MET_Topo_ety_PEMB", &MET_Topo_ety_PEMB, &b_MET_Topo_ety_PEMB);
   fChain->SetBranchAddress("MET_Topo_sumet_PEMB", &MET_Topo_sumet_PEMB, &b_MET_Topo_sumet_PEMB);
   fChain->SetBranchAddress("MET_Topo_phi_PEMB", &MET_Topo_phi_PEMB, &b_MET_Topo_phi_PEMB);
   fChain->SetBranchAddress("MET_Topo_etx_EMB", &MET_Topo_etx_EMB, &b_MET_Topo_etx_EMB);
   fChain->SetBranchAddress("MET_Topo_ety_EMB", &MET_Topo_ety_EMB, &b_MET_Topo_ety_EMB);
   fChain->SetBranchAddress("MET_Topo_sumet_EMB", &MET_Topo_sumet_EMB, &b_MET_Topo_sumet_EMB);
   fChain->SetBranchAddress("MET_Topo_phi_EMB", &MET_Topo_phi_EMB, &b_MET_Topo_phi_EMB);
   fChain->SetBranchAddress("MET_Topo_etx_PEMEC", &MET_Topo_etx_PEMEC, &b_MET_Topo_etx_PEMEC);
   fChain->SetBranchAddress("MET_Topo_ety_PEMEC", &MET_Topo_ety_PEMEC, &b_MET_Topo_ety_PEMEC);
   fChain->SetBranchAddress("MET_Topo_sumet_PEMEC", &MET_Topo_sumet_PEMEC, &b_MET_Topo_sumet_PEMEC);
   fChain->SetBranchAddress("MET_Topo_phi_PEMEC", &MET_Topo_phi_PEMEC, &b_MET_Topo_phi_PEMEC);
   fChain->SetBranchAddress("MET_Topo_etx_EME", &MET_Topo_etx_EME, &b_MET_Topo_etx_EME);
   fChain->SetBranchAddress("MET_Topo_ety_EME", &MET_Topo_ety_EME, &b_MET_Topo_ety_EME);
   fChain->SetBranchAddress("MET_Topo_sumet_EME", &MET_Topo_sumet_EME, &b_MET_Topo_sumet_EME);
   fChain->SetBranchAddress("MET_Topo_phi_EME", &MET_Topo_phi_EME, &b_MET_Topo_phi_EME);
   fChain->SetBranchAddress("MET_Topo_etx_TILE", &MET_Topo_etx_TILE, &b_MET_Topo_etx_TILE);
   fChain->SetBranchAddress("MET_Topo_ety_TILE", &MET_Topo_ety_TILE, &b_MET_Topo_ety_TILE);
   fChain->SetBranchAddress("MET_Topo_sumet_TILE", &MET_Topo_sumet_TILE, &b_MET_Topo_sumet_TILE);
   fChain->SetBranchAddress("MET_Topo_phi_TILE", &MET_Topo_phi_TILE, &b_MET_Topo_phi_TILE);
   fChain->SetBranchAddress("MET_Topo_etx_HEC", &MET_Topo_etx_HEC, &b_MET_Topo_etx_HEC);
   fChain->SetBranchAddress("MET_Topo_ety_HEC", &MET_Topo_ety_HEC, &b_MET_Topo_ety_HEC);
   fChain->SetBranchAddress("MET_Topo_sumet_HEC", &MET_Topo_sumet_HEC, &b_MET_Topo_sumet_HEC);
   fChain->SetBranchAddress("MET_Topo_phi_HEC", &MET_Topo_phi_HEC, &b_MET_Topo_phi_HEC);
   fChain->SetBranchAddress("MET_Topo_etx_FCAL", &MET_Topo_etx_FCAL, &b_MET_Topo_etx_FCAL);
   fChain->SetBranchAddress("MET_Topo_ety_FCAL", &MET_Topo_ety_FCAL, &b_MET_Topo_ety_FCAL);
   fChain->SetBranchAddress("MET_Topo_sumet_FCAL", &MET_Topo_sumet_FCAL, &b_MET_Topo_sumet_FCAL);
   fChain->SetBranchAddress("MET_Topo_phi_FCAL", &MET_Topo_phi_FCAL, &b_MET_Topo_phi_FCAL);
   fChain->SetBranchAddress("MET_Topo_nCell_PEMB", &MET_Topo_nCell_PEMB, &b_MET_Topo_nCell_PEMB);
   fChain->SetBranchAddress("MET_Topo_nCell_EMB", &MET_Topo_nCell_EMB, &b_MET_Topo_nCell_EMB);
   fChain->SetBranchAddress("MET_Topo_nCell_PEMEC", &MET_Topo_nCell_PEMEC, &b_MET_Topo_nCell_PEMEC);
   fChain->SetBranchAddress("MET_Topo_nCell_EME", &MET_Topo_nCell_EME, &b_MET_Topo_nCell_EME);
   fChain->SetBranchAddress("MET_Topo_nCell_TILE", &MET_Topo_nCell_TILE, &b_MET_Topo_nCell_TILE);
   fChain->SetBranchAddress("MET_Topo_nCell_HEC", &MET_Topo_nCell_HEC, &b_MET_Topo_nCell_HEC);
   fChain->SetBranchAddress("MET_Topo_nCell_FCAL", &MET_Topo_nCell_FCAL, &b_MET_Topo_nCell_FCAL);
   fChain->SetBranchAddress("MET_Topo_etx_CentralReg", &MET_Topo_etx_CentralReg, &b_MET_Topo_etx_CentralReg);
   fChain->SetBranchAddress("MET_Topo_ety_CentralReg", &MET_Topo_ety_CentralReg, &b_MET_Topo_ety_CentralReg);
   fChain->SetBranchAddress("MET_Topo_sumet_CentralReg", &MET_Topo_sumet_CentralReg, &b_MET_Topo_sumet_CentralReg);
   fChain->SetBranchAddress("MET_Topo_phi_CentralReg", &MET_Topo_phi_CentralReg, &b_MET_Topo_phi_CentralReg);
   fChain->SetBranchAddress("MET_Topo_etx_EndcapRegion", &MET_Topo_etx_EndcapRegion, &b_MET_Topo_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_Topo_ety_EndcapRegion", &MET_Topo_ety_EndcapRegion, &b_MET_Topo_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_Topo_sumet_EndcapRegion", &MET_Topo_sumet_EndcapRegion, &b_MET_Topo_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_Topo_phi_EndcapRegion", &MET_Topo_phi_EndcapRegion, &b_MET_Topo_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_Topo_etx_ForwardReg", &MET_Topo_etx_ForwardReg, &b_MET_Topo_etx_ForwardReg);
   fChain->SetBranchAddress("MET_Topo_ety_ForwardReg", &MET_Topo_ety_ForwardReg, &b_MET_Topo_ety_ForwardReg);
   fChain->SetBranchAddress("MET_Topo_sumet_ForwardReg", &MET_Topo_sumet_ForwardReg, &b_MET_Topo_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_Topo_phi_ForwardReg", &MET_Topo_phi_ForwardReg, &b_MET_Topo_phi_ForwardReg);
   fChain->SetBranchAddress("MET_CorrTopo_etx", &MET_CorrTopo_etx, &b_MET_CorrTopo_etx);
   fChain->SetBranchAddress("MET_CorrTopo_ety", &MET_CorrTopo_ety, &b_MET_CorrTopo_ety);
   fChain->SetBranchAddress("MET_CorrTopo_phi", &MET_CorrTopo_phi, &b_MET_CorrTopo_phi);
   fChain->SetBranchAddress("MET_CorrTopo_et", &MET_CorrTopo_et, &b_MET_CorrTopo_et);
   fChain->SetBranchAddress("MET_CorrTopo_sumet", &MET_CorrTopo_sumet, &b_MET_CorrTopo_sumet);
   fChain->SetBranchAddress("MET_CorrTopo_SUMET_EMFrac", &MET_CorrTopo_SUMET_EMFrac, &b_MET_CorrTopo_SUMET_EMFrac);
   fChain->SetBranchAddress("MET_CorrTopo_etx_PEMB", &MET_CorrTopo_etx_PEMB, &b_MET_CorrTopo_etx_PEMB);
   fChain->SetBranchAddress("MET_CorrTopo_ety_PEMB", &MET_CorrTopo_ety_PEMB, &b_MET_CorrTopo_ety_PEMB);
   fChain->SetBranchAddress("MET_CorrTopo_sumet_PEMB", &MET_CorrTopo_sumet_PEMB, &b_MET_CorrTopo_sumet_PEMB);
   fChain->SetBranchAddress("MET_CorrTopo_phi_PEMB", &MET_CorrTopo_phi_PEMB, &b_MET_CorrTopo_phi_PEMB);
   fChain->SetBranchAddress("MET_CorrTopo_etx_EMB", &MET_CorrTopo_etx_EMB, &b_MET_CorrTopo_etx_EMB);
   fChain->SetBranchAddress("MET_CorrTopo_ety_EMB", &MET_CorrTopo_ety_EMB, &b_MET_CorrTopo_ety_EMB);
   fChain->SetBranchAddress("MET_CorrTopo_sumet_EMB", &MET_CorrTopo_sumet_EMB, &b_MET_CorrTopo_sumet_EMB);
   fChain->SetBranchAddress("MET_CorrTopo_phi_EMB", &MET_CorrTopo_phi_EMB, &b_MET_CorrTopo_phi_EMB);
   fChain->SetBranchAddress("MET_CorrTopo_etx_PEMEC", &MET_CorrTopo_etx_PEMEC, &b_MET_CorrTopo_etx_PEMEC);
   fChain->SetBranchAddress("MET_CorrTopo_ety_PEMEC", &MET_CorrTopo_ety_PEMEC, &b_MET_CorrTopo_ety_PEMEC);
   fChain->SetBranchAddress("MET_CorrTopo_sumet_PEMEC", &MET_CorrTopo_sumet_PEMEC, &b_MET_CorrTopo_sumet_PEMEC);
   fChain->SetBranchAddress("MET_CorrTopo_phi_PEMEC", &MET_CorrTopo_phi_PEMEC, &b_MET_CorrTopo_phi_PEMEC);
   fChain->SetBranchAddress("MET_CorrTopo_etx_EME", &MET_CorrTopo_etx_EME, &b_MET_CorrTopo_etx_EME);
   fChain->SetBranchAddress("MET_CorrTopo_ety_EME", &MET_CorrTopo_ety_EME, &b_MET_CorrTopo_ety_EME);
   fChain->SetBranchAddress("MET_CorrTopo_sumet_EME", &MET_CorrTopo_sumet_EME, &b_MET_CorrTopo_sumet_EME);
   fChain->SetBranchAddress("MET_CorrTopo_phi_EME", &MET_CorrTopo_phi_EME, &b_MET_CorrTopo_phi_EME);
   fChain->SetBranchAddress("MET_CorrTopo_etx_TILE", &MET_CorrTopo_etx_TILE, &b_MET_CorrTopo_etx_TILE);
   fChain->SetBranchAddress("MET_CorrTopo_ety_TILE", &MET_CorrTopo_ety_TILE, &b_MET_CorrTopo_ety_TILE);
   fChain->SetBranchAddress("MET_CorrTopo_sumet_TILE", &MET_CorrTopo_sumet_TILE, &b_MET_CorrTopo_sumet_TILE);
   fChain->SetBranchAddress("MET_CorrTopo_phi_TILE", &MET_CorrTopo_phi_TILE, &b_MET_CorrTopo_phi_TILE);
   fChain->SetBranchAddress("MET_CorrTopo_etx_HEC", &MET_CorrTopo_etx_HEC, &b_MET_CorrTopo_etx_HEC);
   fChain->SetBranchAddress("MET_CorrTopo_ety_HEC", &MET_CorrTopo_ety_HEC, &b_MET_CorrTopo_ety_HEC);
   fChain->SetBranchAddress("MET_CorrTopo_sumet_HEC", &MET_CorrTopo_sumet_HEC, &b_MET_CorrTopo_sumet_HEC);
   fChain->SetBranchAddress("MET_CorrTopo_phi_HEC", &MET_CorrTopo_phi_HEC, &b_MET_CorrTopo_phi_HEC);
   fChain->SetBranchAddress("MET_CorrTopo_etx_FCAL", &MET_CorrTopo_etx_FCAL, &b_MET_CorrTopo_etx_FCAL);
   fChain->SetBranchAddress("MET_CorrTopo_ety_FCAL", &MET_CorrTopo_ety_FCAL, &b_MET_CorrTopo_ety_FCAL);
   fChain->SetBranchAddress("MET_CorrTopo_sumet_FCAL", &MET_CorrTopo_sumet_FCAL, &b_MET_CorrTopo_sumet_FCAL);
   fChain->SetBranchAddress("MET_CorrTopo_phi_FCAL", &MET_CorrTopo_phi_FCAL, &b_MET_CorrTopo_phi_FCAL);
   fChain->SetBranchAddress("MET_CorrTopo_nCell_PEMB", &MET_CorrTopo_nCell_PEMB, &b_MET_CorrTopo_nCell_PEMB);
   fChain->SetBranchAddress("MET_CorrTopo_nCell_EMB", &MET_CorrTopo_nCell_EMB, &b_MET_CorrTopo_nCell_EMB);
   fChain->SetBranchAddress("MET_CorrTopo_nCell_PEMEC", &MET_CorrTopo_nCell_PEMEC, &b_MET_CorrTopo_nCell_PEMEC);
   fChain->SetBranchAddress("MET_CorrTopo_nCell_EME", &MET_CorrTopo_nCell_EME, &b_MET_CorrTopo_nCell_EME);
   fChain->SetBranchAddress("MET_CorrTopo_nCell_TILE", &MET_CorrTopo_nCell_TILE, &b_MET_CorrTopo_nCell_TILE);
   fChain->SetBranchAddress("MET_CorrTopo_nCell_HEC", &MET_CorrTopo_nCell_HEC, &b_MET_CorrTopo_nCell_HEC);
   fChain->SetBranchAddress("MET_CorrTopo_nCell_FCAL", &MET_CorrTopo_nCell_FCAL, &b_MET_CorrTopo_nCell_FCAL);
   fChain->SetBranchAddress("MET_CorrTopo_etx_CentralReg", &MET_CorrTopo_etx_CentralReg, &b_MET_CorrTopo_etx_CentralReg);
   fChain->SetBranchAddress("MET_CorrTopo_ety_CentralReg", &MET_CorrTopo_ety_CentralReg, &b_MET_CorrTopo_ety_CentralReg);
   fChain->SetBranchAddress("MET_CorrTopo_sumet_CentralReg", &MET_CorrTopo_sumet_CentralReg, &b_MET_CorrTopo_sumet_CentralReg);
   fChain->SetBranchAddress("MET_CorrTopo_phi_CentralReg", &MET_CorrTopo_phi_CentralReg, &b_MET_CorrTopo_phi_CentralReg);
   fChain->SetBranchAddress("MET_CorrTopo_etx_EndcapRegion", &MET_CorrTopo_etx_EndcapRegion, &b_MET_CorrTopo_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_CorrTopo_ety_EndcapRegion", &MET_CorrTopo_ety_EndcapRegion, &b_MET_CorrTopo_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_CorrTopo_sumet_EndcapRegion", &MET_CorrTopo_sumet_EndcapRegion, &b_MET_CorrTopo_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_CorrTopo_phi_EndcapRegion", &MET_CorrTopo_phi_EndcapRegion, &b_MET_CorrTopo_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_CorrTopo_etx_ForwardReg", &MET_CorrTopo_etx_ForwardReg, &b_MET_CorrTopo_etx_ForwardReg);
   fChain->SetBranchAddress("MET_CorrTopo_ety_ForwardReg", &MET_CorrTopo_ety_ForwardReg, &b_MET_CorrTopo_ety_ForwardReg);
   fChain->SetBranchAddress("MET_CorrTopo_sumet_ForwardReg", &MET_CorrTopo_sumet_ForwardReg, &b_MET_CorrTopo_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_CorrTopo_phi_ForwardReg", &MET_CorrTopo_phi_ForwardReg, &b_MET_CorrTopo_phi_ForwardReg);
   fChain->SetBranchAddress("MET_LocHadTopo_etx", &MET_LocHadTopo_etx, &b_MET_LocHadTopo_etx);
   fChain->SetBranchAddress("MET_LocHadTopo_ety", &MET_LocHadTopo_ety, &b_MET_LocHadTopo_ety);
   fChain->SetBranchAddress("MET_LocHadTopo_phi", &MET_LocHadTopo_phi, &b_MET_LocHadTopo_phi);
   fChain->SetBranchAddress("MET_LocHadTopo_et", &MET_LocHadTopo_et, &b_MET_LocHadTopo_et);
   fChain->SetBranchAddress("MET_LocHadTopo_sumet", &MET_LocHadTopo_sumet, &b_MET_LocHadTopo_sumet);
   fChain->SetBranchAddress("MET_LocHadTopo_SUMET_EMFrac", &MET_LocHadTopo_SUMET_EMFrac, &b_MET_LocHadTopo_SUMET_EMFrac);
   fChain->SetBranchAddress("MET_LocHadTopo_etx_PEMB", &MET_LocHadTopo_etx_PEMB, &b_MET_LocHadTopo_etx_PEMB);
   fChain->SetBranchAddress("MET_LocHadTopo_ety_PEMB", &MET_LocHadTopo_ety_PEMB, &b_MET_LocHadTopo_ety_PEMB);
   fChain->SetBranchAddress("MET_LocHadTopo_sumet_PEMB", &MET_LocHadTopo_sumet_PEMB, &b_MET_LocHadTopo_sumet_PEMB);
   fChain->SetBranchAddress("MET_LocHadTopo_phi_PEMB", &MET_LocHadTopo_phi_PEMB, &b_MET_LocHadTopo_phi_PEMB);
   fChain->SetBranchAddress("MET_LocHadTopo_etx_EMB", &MET_LocHadTopo_etx_EMB, &b_MET_LocHadTopo_etx_EMB);
   fChain->SetBranchAddress("MET_LocHadTopo_ety_EMB", &MET_LocHadTopo_ety_EMB, &b_MET_LocHadTopo_ety_EMB);
   fChain->SetBranchAddress("MET_LocHadTopo_sumet_EMB", &MET_LocHadTopo_sumet_EMB, &b_MET_LocHadTopo_sumet_EMB);
   fChain->SetBranchAddress("MET_LocHadTopo_phi_EMB", &MET_LocHadTopo_phi_EMB, &b_MET_LocHadTopo_phi_EMB);
   fChain->SetBranchAddress("MET_LocHadTopo_etx_PEMEC", &MET_LocHadTopo_etx_PEMEC, &b_MET_LocHadTopo_etx_PEMEC);
   fChain->SetBranchAddress("MET_LocHadTopo_ety_PEMEC", &MET_LocHadTopo_ety_PEMEC, &b_MET_LocHadTopo_ety_PEMEC);
   fChain->SetBranchAddress("MET_LocHadTopo_sumet_PEMEC", &MET_LocHadTopo_sumet_PEMEC, &b_MET_LocHadTopo_sumet_PEMEC);
   fChain->SetBranchAddress("MET_LocHadTopo_phi_PEMEC", &MET_LocHadTopo_phi_PEMEC, &b_MET_LocHadTopo_phi_PEMEC);
   fChain->SetBranchAddress("MET_LocHadTopo_etx_EME", &MET_LocHadTopo_etx_EME, &b_MET_LocHadTopo_etx_EME);
   fChain->SetBranchAddress("MET_LocHadTopo_ety_EME", &MET_LocHadTopo_ety_EME, &b_MET_LocHadTopo_ety_EME);
   fChain->SetBranchAddress("MET_LocHadTopo_sumet_EME", &MET_LocHadTopo_sumet_EME, &b_MET_LocHadTopo_sumet_EME);
   fChain->SetBranchAddress("MET_LocHadTopo_phi_EME", &MET_LocHadTopo_phi_EME, &b_MET_LocHadTopo_phi_EME);
   fChain->SetBranchAddress("MET_LocHadTopo_etx_TILE", &MET_LocHadTopo_etx_TILE, &b_MET_LocHadTopo_etx_TILE);
   fChain->SetBranchAddress("MET_LocHadTopo_ety_TILE", &MET_LocHadTopo_ety_TILE, &b_MET_LocHadTopo_ety_TILE);
   fChain->SetBranchAddress("MET_LocHadTopo_sumet_TILE", &MET_LocHadTopo_sumet_TILE, &b_MET_LocHadTopo_sumet_TILE);
   fChain->SetBranchAddress("MET_LocHadTopo_phi_TILE", &MET_LocHadTopo_phi_TILE, &b_MET_LocHadTopo_phi_TILE);
   fChain->SetBranchAddress("MET_LocHadTopo_etx_HEC", &MET_LocHadTopo_etx_HEC, &b_MET_LocHadTopo_etx_HEC);
   fChain->SetBranchAddress("MET_LocHadTopo_ety_HEC", &MET_LocHadTopo_ety_HEC, &b_MET_LocHadTopo_ety_HEC);
   fChain->SetBranchAddress("MET_LocHadTopo_sumet_HEC", &MET_LocHadTopo_sumet_HEC, &b_MET_LocHadTopo_sumet_HEC);
   fChain->SetBranchAddress("MET_LocHadTopo_phi_HEC", &MET_LocHadTopo_phi_HEC, &b_MET_LocHadTopo_phi_HEC);
   fChain->SetBranchAddress("MET_LocHadTopo_etx_FCAL", &MET_LocHadTopo_etx_FCAL, &b_MET_LocHadTopo_etx_FCAL);
   fChain->SetBranchAddress("MET_LocHadTopo_ety_FCAL", &MET_LocHadTopo_ety_FCAL, &b_MET_LocHadTopo_ety_FCAL);
   fChain->SetBranchAddress("MET_LocHadTopo_sumet_FCAL", &MET_LocHadTopo_sumet_FCAL, &b_MET_LocHadTopo_sumet_FCAL);
   fChain->SetBranchAddress("MET_LocHadTopo_phi_FCAL", &MET_LocHadTopo_phi_FCAL, &b_MET_LocHadTopo_phi_FCAL);
   fChain->SetBranchAddress("MET_LocHadTopo_nCell_PEMB", &MET_LocHadTopo_nCell_PEMB, &b_MET_LocHadTopo_nCell_PEMB);
   fChain->SetBranchAddress("MET_LocHadTopo_nCell_EMB", &MET_LocHadTopo_nCell_EMB, &b_MET_LocHadTopo_nCell_EMB);
   fChain->SetBranchAddress("MET_LocHadTopo_nCell_PEMEC", &MET_LocHadTopo_nCell_PEMEC, &b_MET_LocHadTopo_nCell_PEMEC);
   fChain->SetBranchAddress("MET_LocHadTopo_nCell_EME", &MET_LocHadTopo_nCell_EME, &b_MET_LocHadTopo_nCell_EME);
   fChain->SetBranchAddress("MET_LocHadTopo_nCell_TILE", &MET_LocHadTopo_nCell_TILE, &b_MET_LocHadTopo_nCell_TILE);
   fChain->SetBranchAddress("MET_LocHadTopo_nCell_HEC", &MET_LocHadTopo_nCell_HEC, &b_MET_LocHadTopo_nCell_HEC);
   fChain->SetBranchAddress("MET_LocHadTopo_nCell_FCAL", &MET_LocHadTopo_nCell_FCAL, &b_MET_LocHadTopo_nCell_FCAL);
   fChain->SetBranchAddress("MET_LocHadTopo_etx_CentralReg", &MET_LocHadTopo_etx_CentralReg, &b_MET_LocHadTopo_etx_CentralReg);
   fChain->SetBranchAddress("MET_LocHadTopo_ety_CentralReg", &MET_LocHadTopo_ety_CentralReg, &b_MET_LocHadTopo_ety_CentralReg);
   fChain->SetBranchAddress("MET_LocHadTopo_sumet_CentralReg", &MET_LocHadTopo_sumet_CentralReg, &b_MET_LocHadTopo_sumet_CentralReg);
   fChain->SetBranchAddress("MET_LocHadTopo_phi_CentralReg", &MET_LocHadTopo_phi_CentralReg, &b_MET_LocHadTopo_phi_CentralReg);
   fChain->SetBranchAddress("MET_LocHadTopo_etx_EndcapRegion", &MET_LocHadTopo_etx_EndcapRegion, &b_MET_LocHadTopo_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_LocHadTopo_ety_EndcapRegion", &MET_LocHadTopo_ety_EndcapRegion, &b_MET_LocHadTopo_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_LocHadTopo_sumet_EndcapRegion", &MET_LocHadTopo_sumet_EndcapRegion, &b_MET_LocHadTopo_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_LocHadTopo_phi_EndcapRegion", &MET_LocHadTopo_phi_EndcapRegion, &b_MET_LocHadTopo_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_LocHadTopo_etx_ForwardReg", &MET_LocHadTopo_etx_ForwardReg, &b_MET_LocHadTopo_etx_ForwardReg);
   fChain->SetBranchAddress("MET_LocHadTopo_ety_ForwardReg", &MET_LocHadTopo_ety_ForwardReg, &b_MET_LocHadTopo_ety_ForwardReg);
   fChain->SetBranchAddress("MET_LocHadTopo_sumet_ForwardReg", &MET_LocHadTopo_sumet_ForwardReg, &b_MET_LocHadTopo_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_LocHadTopo_phi_ForwardReg", &MET_LocHadTopo_phi_ForwardReg, &b_MET_LocHadTopo_phi_ForwardReg);
   fChain->SetBranchAddress("MET_Truth_NonInt_etx", &MET_Truth_NonInt_etx, &b_MET_Truth_NonInt_etx);
   fChain->SetBranchAddress("MET_Truth_NonInt_ety", &MET_Truth_NonInt_ety, &b_MET_Truth_NonInt_ety);
   fChain->SetBranchAddress("MET_Truth_NonInt_phi", &MET_Truth_NonInt_phi, &b_MET_Truth_NonInt_phi);
   fChain->SetBranchAddress("MET_Truth_NonInt_et", &MET_Truth_NonInt_et, &b_MET_Truth_NonInt_et);
   fChain->SetBranchAddress("MET_Truth_NonInt_sumet", &MET_Truth_NonInt_sumet, &b_MET_Truth_NonInt_sumet);
   fChain->SetBranchAddress("MET_Truth_Int_etx", &MET_Truth_Int_etx, &b_MET_Truth_Int_etx);
   fChain->SetBranchAddress("MET_Truth_Int_ety", &MET_Truth_Int_ety, &b_MET_Truth_Int_ety);
   fChain->SetBranchAddress("MET_Truth_IntCentral_etx", &MET_Truth_IntCentral_etx, &b_MET_Truth_IntCentral_etx);
   fChain->SetBranchAddress("MET_Truth_IntCentral_ety", &MET_Truth_IntCentral_ety, &b_MET_Truth_IntCentral_ety);
   fChain->SetBranchAddress("MET_Truth_IntFwd_etx", &MET_Truth_IntFwd_etx, &b_MET_Truth_IntFwd_etx);
   fChain->SetBranchAddress("MET_Truth_IntFwd_ety", &MET_Truth_IntFwd_ety, &b_MET_Truth_IntFwd_ety);
   fChain->SetBranchAddress("MET_Truth_IntOutCover_etx", &MET_Truth_IntOutCover_etx, &b_MET_Truth_IntOutCover_etx);
   fChain->SetBranchAddress("MET_Truth_IntOutCover_ety", &MET_Truth_IntOutCover_ety, &b_MET_Truth_IntOutCover_ety);
   fChain->SetBranchAddress("MET_Truth_IntMuons_etx", &MET_Truth_IntMuons_etx, &b_MET_Truth_IntMuons_etx);
   fChain->SetBranchAddress("MET_Truth_IntMuons_ety", &MET_Truth_IntMuons_ety, &b_MET_Truth_IntMuons_ety);
   fChain->SetBranchAddress("MET_Truth_Int_phi", &MET_Truth_Int_phi, &b_MET_Truth_Int_phi);
   fChain->SetBranchAddress("MET_Truth_IntCentral_phi", &MET_Truth_IntCentral_phi, &b_MET_Truth_IntCentral_phi);
   fChain->SetBranchAddress("MET_Truth_IntFwd_phi", &MET_Truth_IntFwd_phi, &b_MET_Truth_IntFwd_phi);
   fChain->SetBranchAddress("MET_Truth_IntOutCover_phi", &MET_Truth_IntOutCover_phi, &b_MET_Truth_IntOutCover_phi);
   fChain->SetBranchAddress("MET_Truth_IntMuons_phi", &MET_Truth_IntMuons_phi, &b_MET_Truth_IntMuons_phi);
   fChain->SetBranchAddress("MET_Truth_Int_et", &MET_Truth_Int_et, &b_MET_Truth_Int_et);
   fChain->SetBranchAddress("MET_Truth_IntCentral_et", &MET_Truth_IntCentral_et, &b_MET_Truth_IntCentral_et);
   fChain->SetBranchAddress("MET_Truth_IntFwd_et", &MET_Truth_IntFwd_et, &b_MET_Truth_IntFwd_et);
   fChain->SetBranchAddress("MET_Truth_IntOutCover_et", &MET_Truth_IntOutCover_et, &b_MET_Truth_IntOutCover_et);
   fChain->SetBranchAddress("MET_Truth_IntMuons_et", &MET_Truth_IntMuons_et, &b_MET_Truth_IntMuons_et);
   fChain->SetBranchAddress("MET_Truth_Int_sumet", &MET_Truth_Int_sumet, &b_MET_Truth_Int_sumet);
   fChain->SetBranchAddress("MET_Truth_IntCentral_sumet", &MET_Truth_IntCentral_sumet, &b_MET_Truth_IntCentral_sumet);
   fChain->SetBranchAddress("MET_Truth_IntFwd_sumet", &MET_Truth_IntFwd_sumet, &b_MET_Truth_IntFwd_sumet);
   fChain->SetBranchAddress("MET_Truth_IntOutCover_sumet", &MET_Truth_IntOutCover_sumet, &b_MET_Truth_IntOutCover_sumet);
   fChain->SetBranchAddress("MET_Truth_IntMuons_sumet", &MET_Truth_IntMuons_sumet, &b_MET_Truth_IntMuons_sumet);
   fChain->SetBranchAddress("MET_Truth_PileUp_NonInt_etx", &MET_Truth_PileUp_NonInt_etx, &b_MET_Truth_PileUp_NonInt_etx);
   fChain->SetBranchAddress("MET_Truth_PileUp_NonInt_ety", &MET_Truth_PileUp_NonInt_ety, &b_MET_Truth_PileUp_NonInt_ety);
   fChain->SetBranchAddress("MET_Truth_PileUp_NonInt_phi", &MET_Truth_PileUp_NonInt_phi, &b_MET_Truth_PileUp_NonInt_phi);
   fChain->SetBranchAddress("MET_Truth_PileUp_NonInt_et", &MET_Truth_PileUp_NonInt_et, &b_MET_Truth_PileUp_NonInt_et);
   fChain->SetBranchAddress("MET_Truth_PileUp_NonInt_sumet", &MET_Truth_PileUp_NonInt_sumet, &b_MET_Truth_PileUp_NonInt_sumet);
   fChain->SetBranchAddress("MET_Truth_PileUp_Int_etx", &MET_Truth_PileUp_Int_etx, &b_MET_Truth_PileUp_Int_etx);
   fChain->SetBranchAddress("MET_Truth_PileUp_Int_ety", &MET_Truth_PileUp_Int_ety, &b_MET_Truth_PileUp_Int_ety);
   fChain->SetBranchAddress("MET_Truth_PileUp_IntCentral_etx", &MET_Truth_PileUp_IntCentral_etx, &b_MET_Truth_PileUp_IntCentral_etx);
   fChain->SetBranchAddress("MET_Truth_PileUp_IntCentral_ety", &MET_Truth_PileUp_IntCentral_ety, &b_MET_Truth_PileUp_IntCentral_ety);
   fChain->SetBranchAddress("MET_Truth_PileUp_IntFwd_etx", &MET_Truth_PileUp_IntFwd_etx, &b_MET_Truth_PileUp_IntFwd_etx);
   fChain->SetBranchAddress("MET_Truth_PileUp_IntFwd_ety", &MET_Truth_PileUp_IntFwd_ety, &b_MET_Truth_PileUp_IntFwd_ety);
   fChain->SetBranchAddress("MET_Truth_PileUp_IntOutCover_etx", &MET_Truth_PileUp_IntOutCover_etx, &b_MET_Truth_PileUp_IntOutCover_etx);
   fChain->SetBranchAddress("MET_Truth_PileUp_IntOutCover_ety", &MET_Truth_PileUp_IntOutCover_ety, &b_MET_Truth_PileUp_IntOutCover_ety);
   fChain->SetBranchAddress("MET_Truth_PileUp_IntMuons_etx", &MET_Truth_PileUp_IntMuons_etx, &b_MET_Truth_PileUp_IntMuons_etx);
   fChain->SetBranchAddress("MET_Truth_PileUp_IntMuons_ety", &MET_Truth_PileUp_IntMuons_ety, &b_MET_Truth_PileUp_IntMuons_ety);
   fChain->SetBranchAddress("MET_Truth_PileUp_Int_phi", &MET_Truth_PileUp_Int_phi, &b_MET_Truth_PileUp_Int_phi);
   fChain->SetBranchAddress("MET_Truth_PileUp_IntCentral_phi", &MET_Truth_PileUp_IntCentral_phi, &b_MET_Truth_PileUp_IntCentral_phi);
   fChain->SetBranchAddress("MET_Truth_PileUp_IntFwd_phi", &MET_Truth_PileUp_IntFwd_phi, &b_MET_Truth_PileUp_IntFwd_phi);
   fChain->SetBranchAddress("MET_Truth_PileUp_IntOutCover_phi", &MET_Truth_PileUp_IntOutCover_phi, &b_MET_Truth_PileUp_IntOutCover_phi);
   fChain->SetBranchAddress("MET_Truth_PileUp_IntMuons_phi", &MET_Truth_PileUp_IntMuons_phi, &b_MET_Truth_PileUp_IntMuons_phi);
   fChain->SetBranchAddress("MET_Truth_PileUp_Int_et", &MET_Truth_PileUp_Int_et, &b_MET_Truth_PileUp_Int_et);
   fChain->SetBranchAddress("MET_Truth_PileUp_IntCentral_et", &MET_Truth_PileUp_IntCentral_et, &b_MET_Truth_PileUp_IntCentral_et);
   fChain->SetBranchAddress("MET_Truth_PileUp_IntFwd_et", &MET_Truth_PileUp_IntFwd_et, &b_MET_Truth_PileUp_IntFwd_et);
   fChain->SetBranchAddress("MET_Truth_PileUp_IntOutCover_et", &MET_Truth_PileUp_IntOutCover_et, &b_MET_Truth_PileUp_IntOutCover_et);
   fChain->SetBranchAddress("MET_Truth_PileUp_IntMuons_et", &MET_Truth_PileUp_IntMuons_et, &b_MET_Truth_PileUp_IntMuons_et);
   fChain->SetBranchAddress("MET_Truth_PileUp_Int_sumet", &MET_Truth_PileUp_Int_sumet, &b_MET_Truth_PileUp_Int_sumet);
   fChain->SetBranchAddress("MET_Truth_PileUp_IntCentral_sumet", &MET_Truth_PileUp_IntCentral_sumet, &b_MET_Truth_PileUp_IntCentral_sumet);
   fChain->SetBranchAddress("MET_Truth_PileUp_IntFwd_sumet", &MET_Truth_PileUp_IntFwd_sumet, &b_MET_Truth_PileUp_IntFwd_sumet);
   fChain->SetBranchAddress("MET_Truth_PileUp_IntOutCover_sumet", &MET_Truth_PileUp_IntOutCover_sumet, &b_MET_Truth_PileUp_IntOutCover_sumet);
   fChain->SetBranchAddress("MET_Truth_PileUp_IntMuons_sumet", &MET_Truth_PileUp_IntMuons_sumet, &b_MET_Truth_PileUp_IntMuons_sumet);
   fChain->SetBranchAddress("MET_DM_Crack1_etx", &MET_DM_Crack1_etx, &b_MET_DM_Crack1_etx);
   fChain->SetBranchAddress("MET_DM_Crack1_ety", &MET_DM_Crack1_ety, &b_MET_DM_Crack1_ety);
   fChain->SetBranchAddress("MET_DM_Crack1_phi", &MET_DM_Crack1_phi, &b_MET_DM_Crack1_phi);
   fChain->SetBranchAddress("MET_DM_Crack1_et", &MET_DM_Crack1_et, &b_MET_DM_Crack1_et);
   fChain->SetBranchAddress("MET_DM_Crack1_sumet", &MET_DM_Crack1_sumet, &b_MET_DM_Crack1_sumet);
   fChain->SetBranchAddress("MET_DM_Crack2_etx", &MET_DM_Crack2_etx, &b_MET_DM_Crack2_etx);
   fChain->SetBranchAddress("MET_DM_Crack2_ety", &MET_DM_Crack2_ety, &b_MET_DM_Crack2_ety);
   fChain->SetBranchAddress("MET_DM_Crack2_phi", &MET_DM_Crack2_phi, &b_MET_DM_Crack2_phi);
   fChain->SetBranchAddress("MET_DM_Crack2_et", &MET_DM_Crack2_et, &b_MET_DM_Crack2_et);
   fChain->SetBranchAddress("MET_DM_Crack2_sumet", &MET_DM_Crack2_sumet, &b_MET_DM_Crack2_sumet);
   fChain->SetBranchAddress("MET_DM_All_etx", &MET_DM_All_etx, &b_MET_DM_All_etx);
   fChain->SetBranchAddress("MET_DM_All_ety", &MET_DM_All_ety, &b_MET_DM_All_ety);
   fChain->SetBranchAddress("MET_DM_All_phi", &MET_DM_All_phi, &b_MET_DM_All_phi);
   fChain->SetBranchAddress("MET_DM_All_et", &MET_DM_All_et, &b_MET_DM_All_et);
   fChain->SetBranchAddress("MET_DM_All_sumet", &MET_DM_All_sumet, &b_MET_DM_All_sumet);
   fChain->SetBranchAddress("MET_DM_Cryo_etx", &MET_DM_Cryo_etx, &b_MET_DM_Cryo_etx);
   fChain->SetBranchAddress("MET_DM_Cryo_ety", &MET_DM_Cryo_ety, &b_MET_DM_Cryo_ety);
   fChain->SetBranchAddress("MET_DM_Cryo_phi", &MET_DM_Cryo_phi, &b_MET_DM_Cryo_phi);
   fChain->SetBranchAddress("MET_DM_Cryo_et", &MET_DM_Cryo_et, &b_MET_DM_Cryo_et);
   fChain->SetBranchAddress("MET_DM_Cryo_sumet", &MET_DM_Cryo_sumet, &b_MET_DM_Cryo_sumet);
   fChain->SetBranchAddress("el_MET_n", &el_MET_n, &b_el_MET_n);
   fChain->SetBranchAddress("el_MET_wpx", &el_MET_wpx, &b_el_MET_wpx);
   fChain->SetBranchAddress("el_MET_wpy", &el_MET_wpy, &b_el_MET_wpy);
   fChain->SetBranchAddress("el_MET_wet", &el_MET_wet, &b_el_MET_wet);
   fChain->SetBranchAddress("el_MET_statusWord", &el_MET_statusWord, &b_el_MET_statusWord);
   fChain->SetBranchAddress("ph_MET_n", &ph_MET_n, &b_ph_MET_n);
   fChain->SetBranchAddress("ph_MET_wpx", &ph_MET_wpx, &b_ph_MET_wpx);
   fChain->SetBranchAddress("ph_MET_wpy", &ph_MET_wpy, &b_ph_MET_wpy);
   fChain->SetBranchAddress("ph_MET_wet", &ph_MET_wet, &b_ph_MET_wet);
   fChain->SetBranchAddress("ph_MET_statusWord", &ph_MET_statusWord, &b_ph_MET_statusWord);
   fChain->SetBranchAddress("mu_staco_MET_n", &mu_staco_MET_n, &b_mu_staco_MET_n);
   fChain->SetBranchAddress("mu_staco_MET_wpx", &mu_staco_MET_wpx, &b_mu_staco_MET_wpx);
   fChain->SetBranchAddress("mu_staco_MET_wpy", &mu_staco_MET_wpy, &b_mu_staco_MET_wpy);
   fChain->SetBranchAddress("mu_staco_MET_wet", &mu_staco_MET_wet, &b_mu_staco_MET_wet);
   fChain->SetBranchAddress("mu_staco_MET_statusWord", &mu_staco_MET_statusWord, &b_mu_staco_MET_statusWord);
   fChain->SetBranchAddress("mu_muid_MET_n", &mu_muid_MET_n, &b_mu_muid_MET_n);
   fChain->SetBranchAddress("mu_muid_MET_wpx", &mu_muid_MET_wpx, &b_mu_muid_MET_wpx);
   fChain->SetBranchAddress("mu_muid_MET_wpy", &mu_muid_MET_wpy, &b_mu_muid_MET_wpy);
   fChain->SetBranchAddress("mu_muid_MET_wet", &mu_muid_MET_wet, &b_mu_muid_MET_wet);
   fChain->SetBranchAddress("mu_muid_MET_statusWord", &mu_muid_MET_statusWord, &b_mu_muid_MET_statusWord);
   fChain->SetBranchAddress("tau_MET_n", &tau_MET_n, &b_tau_MET_n);
   fChain->SetBranchAddress("tau_MET_wpx", &tau_MET_wpx, &b_tau_MET_wpx);
   fChain->SetBranchAddress("tau_MET_wpy", &tau_MET_wpy, &b_tau_MET_wpy);
   fChain->SetBranchAddress("tau_MET_wet", &tau_MET_wet, &b_tau_MET_wet);
   fChain->SetBranchAddress("tau_MET_statusWord", &tau_MET_statusWord, &b_tau_MET_statusWord);
   fChain->SetBranchAddress("jet_AntiKt6LCTopo_MET_n", &jet_AntiKt6LCTopo_MET_n, &b_jet_AntiKt6LCTopo_MET_n);
   fChain->SetBranchAddress("jet_AntiKt6LCTopo_MET_wpx", &jet_AntiKt6LCTopo_MET_wpx, &b_jet_AntiKt6LCTopo_MET_wpx);
   fChain->SetBranchAddress("jet_AntiKt6LCTopo_MET_wpy", &jet_AntiKt6LCTopo_MET_wpy, &b_jet_AntiKt6LCTopo_MET_wpy);
   fChain->SetBranchAddress("jet_AntiKt6LCTopo_MET_wet", &jet_AntiKt6LCTopo_MET_wet, &b_jet_AntiKt6LCTopo_MET_wet);
   fChain->SetBranchAddress("jet_AntiKt6LCTopo_MET_statusWord", &jet_AntiKt6LCTopo_MET_statusWord, &b_jet_AntiKt6LCTopo_MET_statusWord);
   fChain->SetBranchAddress("cl_MET_n", &cl_MET_n, &b_cl_MET_n);
   fChain->SetBranchAddress("cl_MET_wpx", &cl_MET_wpx, &b_cl_MET_wpx);
   fChain->SetBranchAddress("cl_MET_wpy", &cl_MET_wpy, &b_cl_MET_wpy);
   fChain->SetBranchAddress("cl_MET_wet", &cl_MET_wet, &b_cl_MET_wet);
   fChain->SetBranchAddress("cl_MET_statusWord", &cl_MET_statusWord, &b_cl_MET_statusWord);
   fChain->SetBranchAddress("trk_MET_n", &trk_MET_n, &b_trk_MET_n);
   fChain->SetBranchAddress("trk_MET_wpx", &trk_MET_wpx, &b_trk_MET_wpx);
   fChain->SetBranchAddress("trk_MET_wpy", &trk_MET_wpy, &b_trk_MET_wpy);
   fChain->SetBranchAddress("trk_MET_wet", &trk_MET_wet, &b_trk_MET_wet);
   fChain->SetBranchAddress("trk_MET_statusWord", &trk_MET_statusWord, &b_trk_MET_statusWord);
   fChain->SetBranchAddress("MET_RefFinal_GCW_pt20_etx", &MET_RefFinal_GCW_pt20_etx, &b_MET_RefFinal_GCW_pt20_etx);
   fChain->SetBranchAddress("MET_RefFinal_GCW_pt20_ety", &MET_RefFinal_GCW_pt20_ety, &b_MET_RefFinal_GCW_pt20_ety);
   fChain->SetBranchAddress("MET_RefFinal_GCW_pt20_phi", &MET_RefFinal_GCW_pt20_phi, &b_MET_RefFinal_GCW_pt20_phi);
   fChain->SetBranchAddress("MET_RefFinal_GCW_pt20_et", &MET_RefFinal_GCW_pt20_et, &b_MET_RefFinal_GCW_pt20_et);
   fChain->SetBranchAddress("MET_RefFinal_GCW_pt20_sumet", &MET_RefFinal_GCW_pt20_sumet, &b_MET_RefFinal_GCW_pt20_sumet);
   fChain->SetBranchAddress("MET_RefFinal_GCW_pt20_etx_CentralReg", &MET_RefFinal_GCW_pt20_etx_CentralReg, &b_MET_RefFinal_GCW_pt20_etx_CentralReg);
   fChain->SetBranchAddress("MET_RefFinal_GCW_pt20_ety_CentralReg", &MET_RefFinal_GCW_pt20_ety_CentralReg, &b_MET_RefFinal_GCW_pt20_ety_CentralReg);
   fChain->SetBranchAddress("MET_RefFinal_GCW_pt20_sumet_CentralReg", &MET_RefFinal_GCW_pt20_sumet_CentralReg, &b_MET_RefFinal_GCW_pt20_sumet_CentralReg);
   fChain->SetBranchAddress("MET_RefFinal_GCW_pt20_phi_CentralReg", &MET_RefFinal_GCW_pt20_phi_CentralReg, &b_MET_RefFinal_GCW_pt20_phi_CentralReg);
   fChain->SetBranchAddress("MET_RefFinal_GCW_pt20_etx_EndcapRegion", &MET_RefFinal_GCW_pt20_etx_EndcapRegion, &b_MET_RefFinal_GCW_pt20_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_RefFinal_GCW_pt20_ety_EndcapRegion", &MET_RefFinal_GCW_pt20_ety_EndcapRegion, &b_MET_RefFinal_GCW_pt20_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_RefFinal_GCW_pt20_sumet_EndcapRegion", &MET_RefFinal_GCW_pt20_sumet_EndcapRegion, &b_MET_RefFinal_GCW_pt20_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_RefFinal_GCW_pt20_phi_EndcapRegion", &MET_RefFinal_GCW_pt20_phi_EndcapRegion, &b_MET_RefFinal_GCW_pt20_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_RefFinal_GCW_pt20_etx_ForwardReg", &MET_RefFinal_GCW_pt20_etx_ForwardReg, &b_MET_RefFinal_GCW_pt20_etx_ForwardReg);
   fChain->SetBranchAddress("MET_RefFinal_GCW_pt20_ety_ForwardReg", &MET_RefFinal_GCW_pt20_ety_ForwardReg, &b_MET_RefFinal_GCW_pt20_ety_ForwardReg);
   fChain->SetBranchAddress("MET_RefFinal_GCW_pt20_sumet_ForwardReg", &MET_RefFinal_GCW_pt20_sumet_ForwardReg, &b_MET_RefFinal_GCW_pt20_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_RefFinal_GCW_pt20_phi_ForwardReg", &MET_RefFinal_GCW_pt20_phi_ForwardReg, &b_MET_RefFinal_GCW_pt20_phi_ForwardReg);
   fChain->SetBranchAddress("MET_RefGamma_GCW_pt20_etx", &MET_RefGamma_GCW_pt20_etx, &b_MET_RefGamma_GCW_pt20_etx);
   fChain->SetBranchAddress("MET_RefGamma_GCW_pt20_ety", &MET_RefGamma_GCW_pt20_ety, &b_MET_RefGamma_GCW_pt20_ety);
   fChain->SetBranchAddress("MET_RefGamma_GCW_pt20_phi", &MET_RefGamma_GCW_pt20_phi, &b_MET_RefGamma_GCW_pt20_phi);
   fChain->SetBranchAddress("MET_RefGamma_GCW_pt20_et", &MET_RefGamma_GCW_pt20_et, &b_MET_RefGamma_GCW_pt20_et);
   fChain->SetBranchAddress("MET_RefGamma_GCW_pt20_sumet", &MET_RefGamma_GCW_pt20_sumet, &b_MET_RefGamma_GCW_pt20_sumet);
   fChain->SetBranchAddress("MET_RefGamma_GCW_pt20_etx_CentralReg", &MET_RefGamma_GCW_pt20_etx_CentralReg, &b_MET_RefGamma_GCW_pt20_etx_CentralReg);
   fChain->SetBranchAddress("MET_RefGamma_GCW_pt20_ety_CentralReg", &MET_RefGamma_GCW_pt20_ety_CentralReg, &b_MET_RefGamma_GCW_pt20_ety_CentralReg);
   fChain->SetBranchAddress("MET_RefGamma_GCW_pt20_sumet_CentralReg", &MET_RefGamma_GCW_pt20_sumet_CentralReg, &b_MET_RefGamma_GCW_pt20_sumet_CentralReg);
   fChain->SetBranchAddress("MET_RefGamma_GCW_pt20_phi_CentralReg", &MET_RefGamma_GCW_pt20_phi_CentralReg, &b_MET_RefGamma_GCW_pt20_phi_CentralReg);
   fChain->SetBranchAddress("MET_RefGamma_GCW_pt20_etx_EndcapRegion", &MET_RefGamma_GCW_pt20_etx_EndcapRegion, &b_MET_RefGamma_GCW_pt20_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_RefGamma_GCW_pt20_ety_EndcapRegion", &MET_RefGamma_GCW_pt20_ety_EndcapRegion, &b_MET_RefGamma_GCW_pt20_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_RefGamma_GCW_pt20_sumet_EndcapRegion", &MET_RefGamma_GCW_pt20_sumet_EndcapRegion, &b_MET_RefGamma_GCW_pt20_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_RefGamma_GCW_pt20_phi_EndcapRegion", &MET_RefGamma_GCW_pt20_phi_EndcapRegion, &b_MET_RefGamma_GCW_pt20_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_RefGamma_GCW_pt20_etx_ForwardReg", &MET_RefGamma_GCW_pt20_etx_ForwardReg, &b_MET_RefGamma_GCW_pt20_etx_ForwardReg);
   fChain->SetBranchAddress("MET_RefGamma_GCW_pt20_ety_ForwardReg", &MET_RefGamma_GCW_pt20_ety_ForwardReg, &b_MET_RefGamma_GCW_pt20_ety_ForwardReg);
   fChain->SetBranchAddress("MET_RefGamma_GCW_pt20_sumet_ForwardReg", &MET_RefGamma_GCW_pt20_sumet_ForwardReg, &b_MET_RefGamma_GCW_pt20_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_RefGamma_GCW_pt20_phi_ForwardReg", &MET_RefGamma_GCW_pt20_phi_ForwardReg, &b_MET_RefGamma_GCW_pt20_phi_ForwardReg);
   fChain->SetBranchAddress("MET_RefEle_GCW_pt20_etx", &MET_RefEle_GCW_pt20_etx, &b_MET_RefEle_GCW_pt20_etx);
   fChain->SetBranchAddress("MET_RefEle_GCW_pt20_ety", &MET_RefEle_GCW_pt20_ety, &b_MET_RefEle_GCW_pt20_ety);
   fChain->SetBranchAddress("MET_RefEle_GCW_pt20_phi", &MET_RefEle_GCW_pt20_phi, &b_MET_RefEle_GCW_pt20_phi);
   fChain->SetBranchAddress("MET_RefEle_GCW_pt20_et", &MET_RefEle_GCW_pt20_et, &b_MET_RefEle_GCW_pt20_et);
   fChain->SetBranchAddress("MET_RefEle_GCW_pt20_sumet", &MET_RefEle_GCW_pt20_sumet, &b_MET_RefEle_GCW_pt20_sumet);
   fChain->SetBranchAddress("MET_RefEle_GCW_pt20_etx_CentralReg", &MET_RefEle_GCW_pt20_etx_CentralReg, &b_MET_RefEle_GCW_pt20_etx_CentralReg);
   fChain->SetBranchAddress("MET_RefEle_GCW_pt20_ety_CentralReg", &MET_RefEle_GCW_pt20_ety_CentralReg, &b_MET_RefEle_GCW_pt20_ety_CentralReg);
   fChain->SetBranchAddress("MET_RefEle_GCW_pt20_sumet_CentralReg", &MET_RefEle_GCW_pt20_sumet_CentralReg, &b_MET_RefEle_GCW_pt20_sumet_CentralReg);
   fChain->SetBranchAddress("MET_RefEle_GCW_pt20_phi_CentralReg", &MET_RefEle_GCW_pt20_phi_CentralReg, &b_MET_RefEle_GCW_pt20_phi_CentralReg);
   fChain->SetBranchAddress("MET_RefEle_GCW_pt20_etx_EndcapRegion", &MET_RefEle_GCW_pt20_etx_EndcapRegion, &b_MET_RefEle_GCW_pt20_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_RefEle_GCW_pt20_ety_EndcapRegion", &MET_RefEle_GCW_pt20_ety_EndcapRegion, &b_MET_RefEle_GCW_pt20_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_RefEle_GCW_pt20_sumet_EndcapRegion", &MET_RefEle_GCW_pt20_sumet_EndcapRegion, &b_MET_RefEle_GCW_pt20_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_RefEle_GCW_pt20_phi_EndcapRegion", &MET_RefEle_GCW_pt20_phi_EndcapRegion, &b_MET_RefEle_GCW_pt20_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_RefEle_GCW_pt20_etx_ForwardReg", &MET_RefEle_GCW_pt20_etx_ForwardReg, &b_MET_RefEle_GCW_pt20_etx_ForwardReg);
   fChain->SetBranchAddress("MET_RefEle_GCW_pt20_ety_ForwardReg", &MET_RefEle_GCW_pt20_ety_ForwardReg, &b_MET_RefEle_GCW_pt20_ety_ForwardReg);
   fChain->SetBranchAddress("MET_RefEle_GCW_pt20_sumet_ForwardReg", &MET_RefEle_GCW_pt20_sumet_ForwardReg, &b_MET_RefEle_GCW_pt20_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_RefEle_GCW_pt20_phi_ForwardReg", &MET_RefEle_GCW_pt20_phi_ForwardReg, &b_MET_RefEle_GCW_pt20_phi_ForwardReg);
   fChain->SetBranchAddress("MET_RefTau_GCW_pt20_etx", &MET_RefTau_GCW_pt20_etx, &b_MET_RefTau_GCW_pt20_etx);
   fChain->SetBranchAddress("MET_RefTau_GCW_pt20_ety", &MET_RefTau_GCW_pt20_ety, &b_MET_RefTau_GCW_pt20_ety);
   fChain->SetBranchAddress("MET_RefTau_GCW_pt20_phi", &MET_RefTau_GCW_pt20_phi, &b_MET_RefTau_GCW_pt20_phi);
   fChain->SetBranchAddress("MET_RefTau_GCW_pt20_et", &MET_RefTau_GCW_pt20_et, &b_MET_RefTau_GCW_pt20_et);
   fChain->SetBranchAddress("MET_RefTau_GCW_pt20_sumet", &MET_RefTau_GCW_pt20_sumet, &b_MET_RefTau_GCW_pt20_sumet);
   fChain->SetBranchAddress("MET_RefTau_GCW_pt20_etx_CentralReg", &MET_RefTau_GCW_pt20_etx_CentralReg, &b_MET_RefTau_GCW_pt20_etx_CentralReg);
   fChain->SetBranchAddress("MET_RefTau_GCW_pt20_ety_CentralReg", &MET_RefTau_GCW_pt20_ety_CentralReg, &b_MET_RefTau_GCW_pt20_ety_CentralReg);
   fChain->SetBranchAddress("MET_RefTau_GCW_pt20_sumet_CentralReg", &MET_RefTau_GCW_pt20_sumet_CentralReg, &b_MET_RefTau_GCW_pt20_sumet_CentralReg);
   fChain->SetBranchAddress("MET_RefTau_GCW_pt20_phi_CentralReg", &MET_RefTau_GCW_pt20_phi_CentralReg, &b_MET_RefTau_GCW_pt20_phi_CentralReg);
   fChain->SetBranchAddress("MET_RefTau_GCW_pt20_etx_EndcapRegion", &MET_RefTau_GCW_pt20_etx_EndcapRegion, &b_MET_RefTau_GCW_pt20_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_RefTau_GCW_pt20_ety_EndcapRegion", &MET_RefTau_GCW_pt20_ety_EndcapRegion, &b_MET_RefTau_GCW_pt20_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_RefTau_GCW_pt20_sumet_EndcapRegion", &MET_RefTau_GCW_pt20_sumet_EndcapRegion, &b_MET_RefTau_GCW_pt20_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_RefTau_GCW_pt20_phi_EndcapRegion", &MET_RefTau_GCW_pt20_phi_EndcapRegion, &b_MET_RefTau_GCW_pt20_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_RefTau_GCW_pt20_etx_ForwardReg", &MET_RefTau_GCW_pt20_etx_ForwardReg, &b_MET_RefTau_GCW_pt20_etx_ForwardReg);
   fChain->SetBranchAddress("MET_RefTau_GCW_pt20_ety_ForwardReg", &MET_RefTau_GCW_pt20_ety_ForwardReg, &b_MET_RefTau_GCW_pt20_ety_ForwardReg);
   fChain->SetBranchAddress("MET_RefTau_GCW_pt20_sumet_ForwardReg", &MET_RefTau_GCW_pt20_sumet_ForwardReg, &b_MET_RefTau_GCW_pt20_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_RefTau_GCW_pt20_phi_ForwardReg", &MET_RefTau_GCW_pt20_phi_ForwardReg, &b_MET_RefTau_GCW_pt20_phi_ForwardReg);
   fChain->SetBranchAddress("MET_RefJet_GCW_pt20_etx", &MET_RefJet_GCW_pt20_etx, &b_MET_RefJet_GCW_pt20_etx);
   fChain->SetBranchAddress("MET_RefJet_GCW_pt20_ety", &MET_RefJet_GCW_pt20_ety, &b_MET_RefJet_GCW_pt20_ety);
   fChain->SetBranchAddress("MET_RefJet_GCW_pt20_phi", &MET_RefJet_GCW_pt20_phi, &b_MET_RefJet_GCW_pt20_phi);
   fChain->SetBranchAddress("MET_RefJet_GCW_pt20_et", &MET_RefJet_GCW_pt20_et, &b_MET_RefJet_GCW_pt20_et);
   fChain->SetBranchAddress("MET_RefJet_GCW_pt20_sumet", &MET_RefJet_GCW_pt20_sumet, &b_MET_RefJet_GCW_pt20_sumet);
   fChain->SetBranchAddress("MET_RefJet_GCW_pt20_etx_CentralReg", &MET_RefJet_GCW_pt20_etx_CentralReg, &b_MET_RefJet_GCW_pt20_etx_CentralReg);
   fChain->SetBranchAddress("MET_RefJet_GCW_pt20_ety_CentralReg", &MET_RefJet_GCW_pt20_ety_CentralReg, &b_MET_RefJet_GCW_pt20_ety_CentralReg);
   fChain->SetBranchAddress("MET_RefJet_GCW_pt20_sumet_CentralReg", &MET_RefJet_GCW_pt20_sumet_CentralReg, &b_MET_RefJet_GCW_pt20_sumet_CentralReg);
   fChain->SetBranchAddress("MET_RefJet_GCW_pt20_phi_CentralReg", &MET_RefJet_GCW_pt20_phi_CentralReg, &b_MET_RefJet_GCW_pt20_phi_CentralReg);
   fChain->SetBranchAddress("MET_RefJet_GCW_pt20_etx_EndcapRegion", &MET_RefJet_GCW_pt20_etx_EndcapRegion, &b_MET_RefJet_GCW_pt20_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_RefJet_GCW_pt20_ety_EndcapRegion", &MET_RefJet_GCW_pt20_ety_EndcapRegion, &b_MET_RefJet_GCW_pt20_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_RefJet_GCW_pt20_sumet_EndcapRegion", &MET_RefJet_GCW_pt20_sumet_EndcapRegion, &b_MET_RefJet_GCW_pt20_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_RefJet_GCW_pt20_phi_EndcapRegion", &MET_RefJet_GCW_pt20_phi_EndcapRegion, &b_MET_RefJet_GCW_pt20_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_RefJet_GCW_pt20_etx_ForwardReg", &MET_RefJet_GCW_pt20_etx_ForwardReg, &b_MET_RefJet_GCW_pt20_etx_ForwardReg);
   fChain->SetBranchAddress("MET_RefJet_GCW_pt20_ety_ForwardReg", &MET_RefJet_GCW_pt20_ety_ForwardReg, &b_MET_RefJet_GCW_pt20_ety_ForwardReg);
   fChain->SetBranchAddress("MET_RefJet_GCW_pt20_sumet_ForwardReg", &MET_RefJet_GCW_pt20_sumet_ForwardReg, &b_MET_RefJet_GCW_pt20_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_RefJet_GCW_pt20_phi_ForwardReg", &MET_RefJet_GCW_pt20_phi_ForwardReg, &b_MET_RefJet_GCW_pt20_phi_ForwardReg);
   fChain->SetBranchAddress("MET_CellOut_GCW_pt20_etx", &MET_CellOut_GCW_pt20_etx, &b_MET_CellOut_GCW_pt20_etx);
   fChain->SetBranchAddress("MET_CellOut_GCW_pt20_ety", &MET_CellOut_GCW_pt20_ety, &b_MET_CellOut_GCW_pt20_ety);
   fChain->SetBranchAddress("MET_CellOut_GCW_pt20_phi", &MET_CellOut_GCW_pt20_phi, &b_MET_CellOut_GCW_pt20_phi);
   fChain->SetBranchAddress("MET_CellOut_GCW_pt20_et", &MET_CellOut_GCW_pt20_et, &b_MET_CellOut_GCW_pt20_et);
   fChain->SetBranchAddress("MET_CellOut_GCW_pt20_sumet", &MET_CellOut_GCW_pt20_sumet, &b_MET_CellOut_GCW_pt20_sumet);
   fChain->SetBranchAddress("MET_CellOut_GCW_pt20_etx_CentralReg", &MET_CellOut_GCW_pt20_etx_CentralReg, &b_MET_CellOut_GCW_pt20_etx_CentralReg);
   fChain->SetBranchAddress("MET_CellOut_GCW_pt20_ety_CentralReg", &MET_CellOut_GCW_pt20_ety_CentralReg, &b_MET_CellOut_GCW_pt20_ety_CentralReg);
   fChain->SetBranchAddress("MET_CellOut_GCW_pt20_sumet_CentralReg", &MET_CellOut_GCW_pt20_sumet_CentralReg, &b_MET_CellOut_GCW_pt20_sumet_CentralReg);
   fChain->SetBranchAddress("MET_CellOut_GCW_pt20_phi_CentralReg", &MET_CellOut_GCW_pt20_phi_CentralReg, &b_MET_CellOut_GCW_pt20_phi_CentralReg);
   fChain->SetBranchAddress("MET_CellOut_GCW_pt20_etx_EndcapRegion", &MET_CellOut_GCW_pt20_etx_EndcapRegion, &b_MET_CellOut_GCW_pt20_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_CellOut_GCW_pt20_ety_EndcapRegion", &MET_CellOut_GCW_pt20_ety_EndcapRegion, &b_MET_CellOut_GCW_pt20_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_CellOut_GCW_pt20_sumet_EndcapRegion", &MET_CellOut_GCW_pt20_sumet_EndcapRegion, &b_MET_CellOut_GCW_pt20_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_CellOut_GCW_pt20_phi_EndcapRegion", &MET_CellOut_GCW_pt20_phi_EndcapRegion, &b_MET_CellOut_GCW_pt20_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_CellOut_GCW_pt20_etx_ForwardReg", &MET_CellOut_GCW_pt20_etx_ForwardReg, &b_MET_CellOut_GCW_pt20_etx_ForwardReg);
   fChain->SetBranchAddress("MET_CellOut_GCW_pt20_ety_ForwardReg", &MET_CellOut_GCW_pt20_ety_ForwardReg, &b_MET_CellOut_GCW_pt20_ety_ForwardReg);
   fChain->SetBranchAddress("MET_CellOut_GCW_pt20_sumet_ForwardReg", &MET_CellOut_GCW_pt20_sumet_ForwardReg, &b_MET_CellOut_GCW_pt20_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_CellOut_GCW_pt20_phi_ForwardReg", &MET_CellOut_GCW_pt20_phi_ForwardReg, &b_MET_CellOut_GCW_pt20_phi_ForwardReg);
   fChain->SetBranchAddress("MET_Cryo_GCW_pt20_etx", &MET_Cryo_GCW_pt20_etx, &b_MET_Cryo_GCW_pt20_etx);
   fChain->SetBranchAddress("MET_Cryo_GCW_pt20_ety", &MET_Cryo_GCW_pt20_ety, &b_MET_Cryo_GCW_pt20_ety);
   fChain->SetBranchAddress("MET_Cryo_GCW_pt20_phi", &MET_Cryo_GCW_pt20_phi, &b_MET_Cryo_GCW_pt20_phi);
   fChain->SetBranchAddress("MET_Cryo_GCW_pt20_et", &MET_Cryo_GCW_pt20_et, &b_MET_Cryo_GCW_pt20_et);
   fChain->SetBranchAddress("MET_Cryo_GCW_pt20_sumet", &MET_Cryo_GCW_pt20_sumet, &b_MET_Cryo_GCW_pt20_sumet);
   fChain->SetBranchAddress("MET_Cryo_GCW_pt20_etx_CentralReg", &MET_Cryo_GCW_pt20_etx_CentralReg, &b_MET_Cryo_GCW_pt20_etx_CentralReg);
   fChain->SetBranchAddress("MET_Cryo_GCW_pt20_ety_CentralReg", &MET_Cryo_GCW_pt20_ety_CentralReg, &b_MET_Cryo_GCW_pt20_ety_CentralReg);
   fChain->SetBranchAddress("MET_Cryo_GCW_pt20_sumet_CentralReg", &MET_Cryo_GCW_pt20_sumet_CentralReg, &b_MET_Cryo_GCW_pt20_sumet_CentralReg);
   fChain->SetBranchAddress("MET_Cryo_GCW_pt20_phi_CentralReg", &MET_Cryo_GCW_pt20_phi_CentralReg, &b_MET_Cryo_GCW_pt20_phi_CentralReg);
   fChain->SetBranchAddress("MET_Cryo_GCW_pt20_etx_EndcapRegion", &MET_Cryo_GCW_pt20_etx_EndcapRegion, &b_MET_Cryo_GCW_pt20_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_Cryo_GCW_pt20_ety_EndcapRegion", &MET_Cryo_GCW_pt20_ety_EndcapRegion, &b_MET_Cryo_GCW_pt20_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_Cryo_GCW_pt20_sumet_EndcapRegion", &MET_Cryo_GCW_pt20_sumet_EndcapRegion, &b_MET_Cryo_GCW_pt20_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_Cryo_GCW_pt20_phi_EndcapRegion", &MET_Cryo_GCW_pt20_phi_EndcapRegion, &b_MET_Cryo_GCW_pt20_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_Cryo_GCW_pt20_etx_ForwardReg", &MET_Cryo_GCW_pt20_etx_ForwardReg, &b_MET_Cryo_GCW_pt20_etx_ForwardReg);
   fChain->SetBranchAddress("MET_Cryo_GCW_pt20_ety_ForwardReg", &MET_Cryo_GCW_pt20_ety_ForwardReg, &b_MET_Cryo_GCW_pt20_ety_ForwardReg);
   fChain->SetBranchAddress("MET_Cryo_GCW_pt20_sumet_ForwardReg", &MET_Cryo_GCW_pt20_sumet_ForwardReg, &b_MET_Cryo_GCW_pt20_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_Cryo_GCW_pt20_phi_ForwardReg", &MET_Cryo_GCW_pt20_phi_ForwardReg, &b_MET_Cryo_GCW_pt20_phi_ForwardReg);
   fChain->SetBranchAddress("MET_RefMuon_GCW_pt20_etx", &MET_RefMuon_GCW_pt20_etx, &b_MET_RefMuon_GCW_pt20_etx);
   fChain->SetBranchAddress("MET_RefMuon_GCW_pt20_ety", &MET_RefMuon_GCW_pt20_ety, &b_MET_RefMuon_GCW_pt20_ety);
   fChain->SetBranchAddress("MET_RefMuon_GCW_pt20_phi", &MET_RefMuon_GCW_pt20_phi, &b_MET_RefMuon_GCW_pt20_phi);
   fChain->SetBranchAddress("MET_RefMuon_GCW_pt20_et", &MET_RefMuon_GCW_pt20_et, &b_MET_RefMuon_GCW_pt20_et);
   fChain->SetBranchAddress("MET_RefMuon_GCW_pt20_sumet", &MET_RefMuon_GCW_pt20_sumet, &b_MET_RefMuon_GCW_pt20_sumet);
   fChain->SetBranchAddress("MET_RefMuon_Staco_GCW_pt20_etx", &MET_RefMuon_Staco_GCW_pt20_etx, &b_MET_RefMuon_Staco_GCW_pt20_etx);
   fChain->SetBranchAddress("MET_RefMuon_Staco_GCW_pt20_ety", &MET_RefMuon_Staco_GCW_pt20_ety, &b_MET_RefMuon_Staco_GCW_pt20_ety);
   fChain->SetBranchAddress("MET_RefMuon_Staco_GCW_pt20_phi", &MET_RefMuon_Staco_GCW_pt20_phi, &b_MET_RefMuon_Staco_GCW_pt20_phi);
   fChain->SetBranchAddress("MET_RefMuon_Staco_GCW_pt20_et", &MET_RefMuon_Staco_GCW_pt20_et, &b_MET_RefMuon_Staco_GCW_pt20_et);
   fChain->SetBranchAddress("MET_RefMuon_Staco_GCW_pt20_sumet", &MET_RefMuon_Staco_GCW_pt20_sumet, &b_MET_RefMuon_Staco_GCW_pt20_sumet);
   fChain->SetBranchAddress("MET_Muon_Isol_Staco_GCW_pt20_etx", &MET_Muon_Isol_Staco_GCW_pt20_etx, &b_MET_Muon_Isol_Staco_GCW_pt20_etx);
   fChain->SetBranchAddress("MET_Muon_Isol_Staco_GCW_pt20_ety", &MET_Muon_Isol_Staco_GCW_pt20_ety, &b_MET_Muon_Isol_Staco_GCW_pt20_ety);
   fChain->SetBranchAddress("MET_Muon_Isol_Staco_GCW_pt20_phi", &MET_Muon_Isol_Staco_GCW_pt20_phi, &b_MET_Muon_Isol_Staco_GCW_pt20_phi);
   fChain->SetBranchAddress("MET_Muon_Isol_Staco_GCW_pt20_et", &MET_Muon_Isol_Staco_GCW_pt20_et, &b_MET_Muon_Isol_Staco_GCW_pt20_et);
   fChain->SetBranchAddress("MET_Muon_Isol_Staco_GCW_pt20_sumet", &MET_Muon_Isol_Staco_GCW_pt20_sumet, &b_MET_Muon_Isol_Staco_GCW_pt20_sumet);
   fChain->SetBranchAddress("MET_Muon_NonIsol_Staco_GCW_pt20_etx", &MET_Muon_NonIsol_Staco_GCW_pt20_etx, &b_MET_Muon_NonIsol_Staco_GCW_pt20_etx);
   fChain->SetBranchAddress("MET_Muon_NonIsol_Staco_GCW_pt20_ety", &MET_Muon_NonIsol_Staco_GCW_pt20_ety, &b_MET_Muon_NonIsol_Staco_GCW_pt20_ety);
   fChain->SetBranchAddress("MET_Muon_NonIsol_Staco_GCW_pt20_phi", &MET_Muon_NonIsol_Staco_GCW_pt20_phi, &b_MET_Muon_NonIsol_Staco_GCW_pt20_phi);
   fChain->SetBranchAddress("MET_Muon_NonIsol_Staco_GCW_pt20_et", &MET_Muon_NonIsol_Staco_GCW_pt20_et, &b_MET_Muon_NonIsol_Staco_GCW_pt20_et);
   fChain->SetBranchAddress("MET_Muon_NonIsol_Staco_GCW_pt20_sumet", &MET_Muon_NonIsol_Staco_GCW_pt20_sumet, &b_MET_Muon_NonIsol_Staco_GCW_pt20_sumet);
   fChain->SetBranchAddress("MET_Muon_Total_Staco_GCW_pt20_etx", &MET_Muon_Total_Staco_GCW_pt20_etx, &b_MET_Muon_Total_Staco_GCW_pt20_etx);
   fChain->SetBranchAddress("MET_Muon_Total_Staco_GCW_pt20_ety", &MET_Muon_Total_Staco_GCW_pt20_ety, &b_MET_Muon_Total_Staco_GCW_pt20_ety);
   fChain->SetBranchAddress("MET_Muon_Total_Staco_GCW_pt20_phi", &MET_Muon_Total_Staco_GCW_pt20_phi, &b_MET_Muon_Total_Staco_GCW_pt20_phi);
   fChain->SetBranchAddress("MET_Muon_Total_Staco_GCW_pt20_et", &MET_Muon_Total_Staco_GCW_pt20_et, &b_MET_Muon_Total_Staco_GCW_pt20_et);
   fChain->SetBranchAddress("MET_Muon_Total_Staco_GCW_pt20_sumet", &MET_Muon_Total_Staco_GCW_pt20_sumet, &b_MET_Muon_Total_Staco_GCW_pt20_sumet);
   fChain->SetBranchAddress("MET_RefMuon_Track_GCW_pt20_etx", &MET_RefMuon_Track_GCW_pt20_etx, &b_MET_RefMuon_Track_GCW_pt20_etx);
   fChain->SetBranchAddress("MET_RefMuon_Track_GCW_pt20_ety", &MET_RefMuon_Track_GCW_pt20_ety, &b_MET_RefMuon_Track_GCW_pt20_ety);
   fChain->SetBranchAddress("MET_RefMuon_Track_GCW_pt20_phi", &MET_RefMuon_Track_GCW_pt20_phi, &b_MET_RefMuon_Track_GCW_pt20_phi);
   fChain->SetBranchAddress("MET_RefMuon_Track_GCW_pt20_et", &MET_RefMuon_Track_GCW_pt20_et, &b_MET_RefMuon_Track_GCW_pt20_et);
   fChain->SetBranchAddress("MET_RefMuon_Track_GCW_pt20_sumet", &MET_RefMuon_Track_GCW_pt20_sumet, &b_MET_RefMuon_Track_GCW_pt20_sumet);
   fChain->SetBranchAddress("MET_RefMuon_Track_Staco_GCW_pt20_etx", &MET_RefMuon_Track_Staco_GCW_pt20_etx, &b_MET_RefMuon_Track_Staco_GCW_pt20_etx);
   fChain->SetBranchAddress("MET_RefMuon_Track_Staco_GCW_pt20_ety", &MET_RefMuon_Track_Staco_GCW_pt20_ety, &b_MET_RefMuon_Track_Staco_GCW_pt20_ety);
   fChain->SetBranchAddress("MET_RefMuon_Track_Staco_GCW_pt20_phi", &MET_RefMuon_Track_Staco_GCW_pt20_phi, &b_MET_RefMuon_Track_Staco_GCW_pt20_phi);
   fChain->SetBranchAddress("MET_RefMuon_Track_Staco_GCW_pt20_et", &MET_RefMuon_Track_Staco_GCW_pt20_et, &b_MET_RefMuon_Track_Staco_GCW_pt20_et);
   fChain->SetBranchAddress("MET_RefMuon_Track_Staco_GCW_pt20_sumet", &MET_RefMuon_Track_Staco_GCW_pt20_sumet, &b_MET_RefMuon_Track_Staco_GCW_pt20_sumet);
   fChain->SetBranchAddress("MET_RefFinal_LCW_NI_eflow4_etx", &MET_RefFinal_LCW_NI_eflow4_etx, &b_MET_RefFinal_LCW_NI_eflow4_etx);
   fChain->SetBranchAddress("MET_RefFinal_LCW_NI_eflow4_ety", &MET_RefFinal_LCW_NI_eflow4_ety, &b_MET_RefFinal_LCW_NI_eflow4_ety);
   fChain->SetBranchAddress("MET_RefFinal_LCW_NI_eflow4_phi", &MET_RefFinal_LCW_NI_eflow4_phi, &b_MET_RefFinal_LCW_NI_eflow4_phi);
   fChain->SetBranchAddress("MET_RefFinal_LCW_NI_eflow4_et", &MET_RefFinal_LCW_NI_eflow4_et, &b_MET_RefFinal_LCW_NI_eflow4_et);
   fChain->SetBranchAddress("MET_RefFinal_LCW_NI_eflow4_sumet", &MET_RefFinal_LCW_NI_eflow4_sumet, &b_MET_RefFinal_LCW_NI_eflow4_sumet);
   fChain->SetBranchAddress("MET_RefFinal_LCW_NI_eflow4_etx_CentralReg", &MET_RefFinal_LCW_NI_eflow4_etx_CentralReg, &b_MET_RefFinal_LCW_NI_eflow4_etx_CentralReg);
   fChain->SetBranchAddress("MET_RefFinal_LCW_NI_eflow4_ety_CentralReg", &MET_RefFinal_LCW_NI_eflow4_ety_CentralReg, &b_MET_RefFinal_LCW_NI_eflow4_ety_CentralReg);
   fChain->SetBranchAddress("MET_RefFinal_LCW_NI_eflow4_sumet_CentralReg", &MET_RefFinal_LCW_NI_eflow4_sumet_CentralReg, &b_MET_RefFinal_LCW_NI_eflow4_sumet_CentralReg);
   fChain->SetBranchAddress("MET_RefFinal_LCW_NI_eflow4_phi_CentralReg", &MET_RefFinal_LCW_NI_eflow4_phi_CentralReg, &b_MET_RefFinal_LCW_NI_eflow4_phi_CentralReg);
   fChain->SetBranchAddress("MET_RefFinal_LCW_NI_eflow4_etx_EndcapRegion", &MET_RefFinal_LCW_NI_eflow4_etx_EndcapRegion, &b_MET_RefFinal_LCW_NI_eflow4_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_RefFinal_LCW_NI_eflow4_ety_EndcapRegion", &MET_RefFinal_LCW_NI_eflow4_ety_EndcapRegion, &b_MET_RefFinal_LCW_NI_eflow4_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_RefFinal_LCW_NI_eflow4_sumet_EndcapRegion", &MET_RefFinal_LCW_NI_eflow4_sumet_EndcapRegion, &b_MET_RefFinal_LCW_NI_eflow4_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_RefFinal_LCW_NI_eflow4_phi_EndcapRegion", &MET_RefFinal_LCW_NI_eflow4_phi_EndcapRegion, &b_MET_RefFinal_LCW_NI_eflow4_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_RefFinal_LCW_NI_eflow4_etx_ForwardReg", &MET_RefFinal_LCW_NI_eflow4_etx_ForwardReg, &b_MET_RefFinal_LCW_NI_eflow4_etx_ForwardReg);
   fChain->SetBranchAddress("MET_RefFinal_LCW_NI_eflow4_ety_ForwardReg", &MET_RefFinal_LCW_NI_eflow4_ety_ForwardReg, &b_MET_RefFinal_LCW_NI_eflow4_ety_ForwardReg);
   fChain->SetBranchAddress("MET_RefFinal_LCW_NI_eflow4_sumet_ForwardReg", &MET_RefFinal_LCW_NI_eflow4_sumet_ForwardReg, &b_MET_RefFinal_LCW_NI_eflow4_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_RefFinal_LCW_NI_eflow4_phi_ForwardReg", &MET_RefFinal_LCW_NI_eflow4_phi_ForwardReg, &b_MET_RefFinal_LCW_NI_eflow4_phi_ForwardReg);
   fChain->SetBranchAddress("MET_RefGamma_LCW_NI_eflow4_etx", &MET_RefGamma_LCW_NI_eflow4_etx, &b_MET_RefGamma_LCW_NI_eflow4_etx);
   fChain->SetBranchAddress("MET_RefGamma_LCW_NI_eflow4_ety", &MET_RefGamma_LCW_NI_eflow4_ety, &b_MET_RefGamma_LCW_NI_eflow4_ety);
   fChain->SetBranchAddress("MET_RefGamma_LCW_NI_eflow4_phi", &MET_RefGamma_LCW_NI_eflow4_phi, &b_MET_RefGamma_LCW_NI_eflow4_phi);
   fChain->SetBranchAddress("MET_RefGamma_LCW_NI_eflow4_et", &MET_RefGamma_LCW_NI_eflow4_et, &b_MET_RefGamma_LCW_NI_eflow4_et);
   fChain->SetBranchAddress("MET_RefGamma_LCW_NI_eflow4_sumet", &MET_RefGamma_LCW_NI_eflow4_sumet, &b_MET_RefGamma_LCW_NI_eflow4_sumet);
   fChain->SetBranchAddress("MET_RefGamma_LCW_NI_eflow4_etx_CentralReg", &MET_RefGamma_LCW_NI_eflow4_etx_CentralReg, &b_MET_RefGamma_LCW_NI_eflow4_etx_CentralReg);
   fChain->SetBranchAddress("MET_RefGamma_LCW_NI_eflow4_ety_CentralReg", &MET_RefGamma_LCW_NI_eflow4_ety_CentralReg, &b_MET_RefGamma_LCW_NI_eflow4_ety_CentralReg);
   fChain->SetBranchAddress("MET_RefGamma_LCW_NI_eflow4_sumet_CentralReg", &MET_RefGamma_LCW_NI_eflow4_sumet_CentralReg, &b_MET_RefGamma_LCW_NI_eflow4_sumet_CentralReg);
   fChain->SetBranchAddress("MET_RefGamma_LCW_NI_eflow4_phi_CentralReg", &MET_RefGamma_LCW_NI_eflow4_phi_CentralReg, &b_MET_RefGamma_LCW_NI_eflow4_phi_CentralReg);
   fChain->SetBranchAddress("MET_RefGamma_LCW_NI_eflow4_etx_EndcapRegion", &MET_RefGamma_LCW_NI_eflow4_etx_EndcapRegion, &b_MET_RefGamma_LCW_NI_eflow4_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_RefGamma_LCW_NI_eflow4_ety_EndcapRegion", &MET_RefGamma_LCW_NI_eflow4_ety_EndcapRegion, &b_MET_RefGamma_LCW_NI_eflow4_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_RefGamma_LCW_NI_eflow4_sumet_EndcapRegion", &MET_RefGamma_LCW_NI_eflow4_sumet_EndcapRegion, &b_MET_RefGamma_LCW_NI_eflow4_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_RefGamma_LCW_NI_eflow4_phi_EndcapRegion", &MET_RefGamma_LCW_NI_eflow4_phi_EndcapRegion, &b_MET_RefGamma_LCW_NI_eflow4_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_RefGamma_LCW_NI_eflow4_etx_ForwardReg", &MET_RefGamma_LCW_NI_eflow4_etx_ForwardReg, &b_MET_RefGamma_LCW_NI_eflow4_etx_ForwardReg);
   fChain->SetBranchAddress("MET_RefGamma_LCW_NI_eflow4_ety_ForwardReg", &MET_RefGamma_LCW_NI_eflow4_ety_ForwardReg, &b_MET_RefGamma_LCW_NI_eflow4_ety_ForwardReg);
   fChain->SetBranchAddress("MET_RefGamma_LCW_NI_eflow4_sumet_ForwardReg", &MET_RefGamma_LCW_NI_eflow4_sumet_ForwardReg, &b_MET_RefGamma_LCW_NI_eflow4_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_RefGamma_LCW_NI_eflow4_phi_ForwardReg", &MET_RefGamma_LCW_NI_eflow4_phi_ForwardReg, &b_MET_RefGamma_LCW_NI_eflow4_phi_ForwardReg);
   fChain->SetBranchAddress("MET_RefEle_LCW_NI_eflow4_etx", &MET_RefEle_LCW_NI_eflow4_etx, &b_MET_RefEle_LCW_NI_eflow4_etx);
   fChain->SetBranchAddress("MET_RefEle_LCW_NI_eflow4_ety", &MET_RefEle_LCW_NI_eflow4_ety, &b_MET_RefEle_LCW_NI_eflow4_ety);
   fChain->SetBranchAddress("MET_RefEle_LCW_NI_eflow4_phi", &MET_RefEle_LCW_NI_eflow4_phi, &b_MET_RefEle_LCW_NI_eflow4_phi);
   fChain->SetBranchAddress("MET_RefEle_LCW_NI_eflow4_et", &MET_RefEle_LCW_NI_eflow4_et, &b_MET_RefEle_LCW_NI_eflow4_et);
   fChain->SetBranchAddress("MET_RefEle_LCW_NI_eflow4_sumet", &MET_RefEle_LCW_NI_eflow4_sumet, &b_MET_RefEle_LCW_NI_eflow4_sumet);
   fChain->SetBranchAddress("MET_RefEle_LCW_NI_eflow4_etx_CentralReg", &MET_RefEle_LCW_NI_eflow4_etx_CentralReg, &b_MET_RefEle_LCW_NI_eflow4_etx_CentralReg);
   fChain->SetBranchAddress("MET_RefEle_LCW_NI_eflow4_ety_CentralReg", &MET_RefEle_LCW_NI_eflow4_ety_CentralReg, &b_MET_RefEle_LCW_NI_eflow4_ety_CentralReg);
   fChain->SetBranchAddress("MET_RefEle_LCW_NI_eflow4_sumet_CentralReg", &MET_RefEle_LCW_NI_eflow4_sumet_CentralReg, &b_MET_RefEle_LCW_NI_eflow4_sumet_CentralReg);
   fChain->SetBranchAddress("MET_RefEle_LCW_NI_eflow4_phi_CentralReg", &MET_RefEle_LCW_NI_eflow4_phi_CentralReg, &b_MET_RefEle_LCW_NI_eflow4_phi_CentralReg);
   fChain->SetBranchAddress("MET_RefEle_LCW_NI_eflow4_etx_EndcapRegion", &MET_RefEle_LCW_NI_eflow4_etx_EndcapRegion, &b_MET_RefEle_LCW_NI_eflow4_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_RefEle_LCW_NI_eflow4_ety_EndcapRegion", &MET_RefEle_LCW_NI_eflow4_ety_EndcapRegion, &b_MET_RefEle_LCW_NI_eflow4_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_RefEle_LCW_NI_eflow4_sumet_EndcapRegion", &MET_RefEle_LCW_NI_eflow4_sumet_EndcapRegion, &b_MET_RefEle_LCW_NI_eflow4_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_RefEle_LCW_NI_eflow4_phi_EndcapRegion", &MET_RefEle_LCW_NI_eflow4_phi_EndcapRegion, &b_MET_RefEle_LCW_NI_eflow4_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_RefEle_LCW_NI_eflow4_etx_ForwardReg", &MET_RefEle_LCW_NI_eflow4_etx_ForwardReg, &b_MET_RefEle_LCW_NI_eflow4_etx_ForwardReg);
   fChain->SetBranchAddress("MET_RefEle_LCW_NI_eflow4_ety_ForwardReg", &MET_RefEle_LCW_NI_eflow4_ety_ForwardReg, &b_MET_RefEle_LCW_NI_eflow4_ety_ForwardReg);
   fChain->SetBranchAddress("MET_RefEle_LCW_NI_eflow4_sumet_ForwardReg", &MET_RefEle_LCW_NI_eflow4_sumet_ForwardReg, &b_MET_RefEle_LCW_NI_eflow4_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_RefEle_LCW_NI_eflow4_phi_ForwardReg", &MET_RefEle_LCW_NI_eflow4_phi_ForwardReg, &b_MET_RefEle_LCW_NI_eflow4_phi_ForwardReg);
   fChain->SetBranchAddress("MET_RefTau_LCW_NI_eflow4_etx", &MET_RefTau_LCW_NI_eflow4_etx, &b_MET_RefTau_LCW_NI_eflow4_etx);
   fChain->SetBranchAddress("MET_RefTau_LCW_NI_eflow4_ety", &MET_RefTau_LCW_NI_eflow4_ety, &b_MET_RefTau_LCW_NI_eflow4_ety);
   fChain->SetBranchAddress("MET_RefTau_LCW_NI_eflow4_phi", &MET_RefTau_LCW_NI_eflow4_phi, &b_MET_RefTau_LCW_NI_eflow4_phi);
   fChain->SetBranchAddress("MET_RefTau_LCW_NI_eflow4_et", &MET_RefTau_LCW_NI_eflow4_et, &b_MET_RefTau_LCW_NI_eflow4_et);
   fChain->SetBranchAddress("MET_RefTau_LCW_NI_eflow4_sumet", &MET_RefTau_LCW_NI_eflow4_sumet, &b_MET_RefTau_LCW_NI_eflow4_sumet);
   fChain->SetBranchAddress("MET_RefTau_LCW_NI_eflow4_etx_CentralReg", &MET_RefTau_LCW_NI_eflow4_etx_CentralReg, &b_MET_RefTau_LCW_NI_eflow4_etx_CentralReg);
   fChain->SetBranchAddress("MET_RefTau_LCW_NI_eflow4_ety_CentralReg", &MET_RefTau_LCW_NI_eflow4_ety_CentralReg, &b_MET_RefTau_LCW_NI_eflow4_ety_CentralReg);
   fChain->SetBranchAddress("MET_RefTau_LCW_NI_eflow4_sumet_CentralReg", &MET_RefTau_LCW_NI_eflow4_sumet_CentralReg, &b_MET_RefTau_LCW_NI_eflow4_sumet_CentralReg);
   fChain->SetBranchAddress("MET_RefTau_LCW_NI_eflow4_phi_CentralReg", &MET_RefTau_LCW_NI_eflow4_phi_CentralReg, &b_MET_RefTau_LCW_NI_eflow4_phi_CentralReg);
   fChain->SetBranchAddress("MET_RefTau_LCW_NI_eflow4_etx_EndcapRegion", &MET_RefTau_LCW_NI_eflow4_etx_EndcapRegion, &b_MET_RefTau_LCW_NI_eflow4_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_RefTau_LCW_NI_eflow4_ety_EndcapRegion", &MET_RefTau_LCW_NI_eflow4_ety_EndcapRegion, &b_MET_RefTau_LCW_NI_eflow4_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_RefTau_LCW_NI_eflow4_sumet_EndcapRegion", &MET_RefTau_LCW_NI_eflow4_sumet_EndcapRegion, &b_MET_RefTau_LCW_NI_eflow4_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_RefTau_LCW_NI_eflow4_phi_EndcapRegion", &MET_RefTau_LCW_NI_eflow4_phi_EndcapRegion, &b_MET_RefTau_LCW_NI_eflow4_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_RefTau_LCW_NI_eflow4_etx_ForwardReg", &MET_RefTau_LCW_NI_eflow4_etx_ForwardReg, &b_MET_RefTau_LCW_NI_eflow4_etx_ForwardReg);
   fChain->SetBranchAddress("MET_RefTau_LCW_NI_eflow4_ety_ForwardReg", &MET_RefTau_LCW_NI_eflow4_ety_ForwardReg, &b_MET_RefTau_LCW_NI_eflow4_ety_ForwardReg);
   fChain->SetBranchAddress("MET_RefTau_LCW_NI_eflow4_sumet_ForwardReg", &MET_RefTau_LCW_NI_eflow4_sumet_ForwardReg, &b_MET_RefTau_LCW_NI_eflow4_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_RefTau_LCW_NI_eflow4_phi_ForwardReg", &MET_RefTau_LCW_NI_eflow4_phi_ForwardReg, &b_MET_RefTau_LCW_NI_eflow4_phi_ForwardReg);
   fChain->SetBranchAddress("MET_RefJet_LCW_NI_eflow4_etx", &MET_RefJet_LCW_NI_eflow4_etx, &b_MET_RefJet_LCW_NI_eflow4_etx);
   fChain->SetBranchAddress("MET_RefJet_LCW_NI_eflow4_ety", &MET_RefJet_LCW_NI_eflow4_ety, &b_MET_RefJet_LCW_NI_eflow4_ety);
   fChain->SetBranchAddress("MET_RefJet_LCW_NI_eflow4_phi", &MET_RefJet_LCW_NI_eflow4_phi, &b_MET_RefJet_LCW_NI_eflow4_phi);
   fChain->SetBranchAddress("MET_RefJet_LCW_NI_eflow4_et", &MET_RefJet_LCW_NI_eflow4_et, &b_MET_RefJet_LCW_NI_eflow4_et);
   fChain->SetBranchAddress("MET_RefJet_LCW_NI_eflow4_sumet", &MET_RefJet_LCW_NI_eflow4_sumet, &b_MET_RefJet_LCW_NI_eflow4_sumet);
   fChain->SetBranchAddress("MET_RefJet_LCW_NI_eflow4_etx_CentralReg", &MET_RefJet_LCW_NI_eflow4_etx_CentralReg, &b_MET_RefJet_LCW_NI_eflow4_etx_CentralReg);
   fChain->SetBranchAddress("MET_RefJet_LCW_NI_eflow4_ety_CentralReg", &MET_RefJet_LCW_NI_eflow4_ety_CentralReg, &b_MET_RefJet_LCW_NI_eflow4_ety_CentralReg);
   fChain->SetBranchAddress("MET_RefJet_LCW_NI_eflow4_sumet_CentralReg", &MET_RefJet_LCW_NI_eflow4_sumet_CentralReg, &b_MET_RefJet_LCW_NI_eflow4_sumet_CentralReg);
   fChain->SetBranchAddress("MET_RefJet_LCW_NI_eflow4_phi_CentralReg", &MET_RefJet_LCW_NI_eflow4_phi_CentralReg, &b_MET_RefJet_LCW_NI_eflow4_phi_CentralReg);
   fChain->SetBranchAddress("MET_RefJet_LCW_NI_eflow4_etx_EndcapRegion", &MET_RefJet_LCW_NI_eflow4_etx_EndcapRegion, &b_MET_RefJet_LCW_NI_eflow4_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_RefJet_LCW_NI_eflow4_ety_EndcapRegion", &MET_RefJet_LCW_NI_eflow4_ety_EndcapRegion, &b_MET_RefJet_LCW_NI_eflow4_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_RefJet_LCW_NI_eflow4_sumet_EndcapRegion", &MET_RefJet_LCW_NI_eflow4_sumet_EndcapRegion, &b_MET_RefJet_LCW_NI_eflow4_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_RefJet_LCW_NI_eflow4_phi_EndcapRegion", &MET_RefJet_LCW_NI_eflow4_phi_EndcapRegion, &b_MET_RefJet_LCW_NI_eflow4_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_RefJet_LCW_NI_eflow4_etx_ForwardReg", &MET_RefJet_LCW_NI_eflow4_etx_ForwardReg, &b_MET_RefJet_LCW_NI_eflow4_etx_ForwardReg);
   fChain->SetBranchAddress("MET_RefJet_LCW_NI_eflow4_ety_ForwardReg", &MET_RefJet_LCW_NI_eflow4_ety_ForwardReg, &b_MET_RefJet_LCW_NI_eflow4_ety_ForwardReg);
   fChain->SetBranchAddress("MET_RefJet_LCW_NI_eflow4_sumet_ForwardReg", &MET_RefJet_LCW_NI_eflow4_sumet_ForwardReg, &b_MET_RefJet_LCW_NI_eflow4_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_RefJet_LCW_NI_eflow4_phi_ForwardReg", &MET_RefJet_LCW_NI_eflow4_phi_ForwardReg, &b_MET_RefJet_LCW_NI_eflow4_phi_ForwardReg);
   fChain->SetBranchAddress("MET_CellOut_LCW_NI_eflow4_etx", &MET_CellOut_LCW_NI_eflow4_etx, &b_MET_CellOut_LCW_NI_eflow4_etx);
   fChain->SetBranchAddress("MET_CellOut_LCW_NI_eflow4_ety", &MET_CellOut_LCW_NI_eflow4_ety, &b_MET_CellOut_LCW_NI_eflow4_ety);
   fChain->SetBranchAddress("MET_CellOut_LCW_NI_eflow4_phi", &MET_CellOut_LCW_NI_eflow4_phi, &b_MET_CellOut_LCW_NI_eflow4_phi);
   fChain->SetBranchAddress("MET_CellOut_LCW_NI_eflow4_et", &MET_CellOut_LCW_NI_eflow4_et, &b_MET_CellOut_LCW_NI_eflow4_et);
   fChain->SetBranchAddress("MET_CellOut_LCW_NI_eflow4_sumet", &MET_CellOut_LCW_NI_eflow4_sumet, &b_MET_CellOut_LCW_NI_eflow4_sumet);
   fChain->SetBranchAddress("MET_CellOut_LCW_NI_eflow4_etx_CentralReg", &MET_CellOut_LCW_NI_eflow4_etx_CentralReg, &b_MET_CellOut_LCW_NI_eflow4_etx_CentralReg);
   fChain->SetBranchAddress("MET_CellOut_LCW_NI_eflow4_ety_CentralReg", &MET_CellOut_LCW_NI_eflow4_ety_CentralReg, &b_MET_CellOut_LCW_NI_eflow4_ety_CentralReg);
   fChain->SetBranchAddress("MET_CellOut_LCW_NI_eflow4_sumet_CentralReg", &MET_CellOut_LCW_NI_eflow4_sumet_CentralReg, &b_MET_CellOut_LCW_NI_eflow4_sumet_CentralReg);
   fChain->SetBranchAddress("MET_CellOut_LCW_NI_eflow4_phi_CentralReg", &MET_CellOut_LCW_NI_eflow4_phi_CentralReg, &b_MET_CellOut_LCW_NI_eflow4_phi_CentralReg);
   fChain->SetBranchAddress("MET_CellOut_LCW_NI_eflow4_etx_EndcapRegion", &MET_CellOut_LCW_NI_eflow4_etx_EndcapRegion, &b_MET_CellOut_LCW_NI_eflow4_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_CellOut_LCW_NI_eflow4_ety_EndcapRegion", &MET_CellOut_LCW_NI_eflow4_ety_EndcapRegion, &b_MET_CellOut_LCW_NI_eflow4_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_CellOut_LCW_NI_eflow4_sumet_EndcapRegion", &MET_CellOut_LCW_NI_eflow4_sumet_EndcapRegion, &b_MET_CellOut_LCW_NI_eflow4_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_CellOut_LCW_NI_eflow4_phi_EndcapRegion", &MET_CellOut_LCW_NI_eflow4_phi_EndcapRegion, &b_MET_CellOut_LCW_NI_eflow4_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_CellOut_LCW_NI_eflow4_etx_ForwardReg", &MET_CellOut_LCW_NI_eflow4_etx_ForwardReg, &b_MET_CellOut_LCW_NI_eflow4_etx_ForwardReg);
   fChain->SetBranchAddress("MET_CellOut_LCW_NI_eflow4_ety_ForwardReg", &MET_CellOut_LCW_NI_eflow4_ety_ForwardReg, &b_MET_CellOut_LCW_NI_eflow4_ety_ForwardReg);
   fChain->SetBranchAddress("MET_CellOut_LCW_NI_eflow4_sumet_ForwardReg", &MET_CellOut_LCW_NI_eflow4_sumet_ForwardReg, &b_MET_CellOut_LCW_NI_eflow4_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_CellOut_LCW_NI_eflow4_phi_ForwardReg", &MET_CellOut_LCW_NI_eflow4_phi_ForwardReg, &b_MET_CellOut_LCW_NI_eflow4_phi_ForwardReg);
   fChain->SetBranchAddress("MET_Cryo_LCW_NI_eflow4_etx", &MET_Cryo_LCW_NI_eflow4_etx, &b_MET_Cryo_LCW_NI_eflow4_etx);
   fChain->SetBranchAddress("MET_Cryo_LCW_NI_eflow4_ety", &MET_Cryo_LCW_NI_eflow4_ety, &b_MET_Cryo_LCW_NI_eflow4_ety);
   fChain->SetBranchAddress("MET_Cryo_LCW_NI_eflow4_phi", &MET_Cryo_LCW_NI_eflow4_phi, &b_MET_Cryo_LCW_NI_eflow4_phi);
   fChain->SetBranchAddress("MET_Cryo_LCW_NI_eflow4_et", &MET_Cryo_LCW_NI_eflow4_et, &b_MET_Cryo_LCW_NI_eflow4_et);
   fChain->SetBranchAddress("MET_Cryo_LCW_NI_eflow4_sumet", &MET_Cryo_LCW_NI_eflow4_sumet, &b_MET_Cryo_LCW_NI_eflow4_sumet);
   fChain->SetBranchAddress("MET_Cryo_LCW_NI_eflow4_etx_CentralReg", &MET_Cryo_LCW_NI_eflow4_etx_CentralReg, &b_MET_Cryo_LCW_NI_eflow4_etx_CentralReg);
   fChain->SetBranchAddress("MET_Cryo_LCW_NI_eflow4_ety_CentralReg", &MET_Cryo_LCW_NI_eflow4_ety_CentralReg, &b_MET_Cryo_LCW_NI_eflow4_ety_CentralReg);
   fChain->SetBranchAddress("MET_Cryo_LCW_NI_eflow4_sumet_CentralReg", &MET_Cryo_LCW_NI_eflow4_sumet_CentralReg, &b_MET_Cryo_LCW_NI_eflow4_sumet_CentralReg);
   fChain->SetBranchAddress("MET_Cryo_LCW_NI_eflow4_phi_CentralReg", &MET_Cryo_LCW_NI_eflow4_phi_CentralReg, &b_MET_Cryo_LCW_NI_eflow4_phi_CentralReg);
   fChain->SetBranchAddress("MET_Cryo_LCW_NI_eflow4_etx_EndcapRegion", &MET_Cryo_LCW_NI_eflow4_etx_EndcapRegion, &b_MET_Cryo_LCW_NI_eflow4_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_Cryo_LCW_NI_eflow4_ety_EndcapRegion", &MET_Cryo_LCW_NI_eflow4_ety_EndcapRegion, &b_MET_Cryo_LCW_NI_eflow4_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_Cryo_LCW_NI_eflow4_sumet_EndcapRegion", &MET_Cryo_LCW_NI_eflow4_sumet_EndcapRegion, &b_MET_Cryo_LCW_NI_eflow4_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_Cryo_LCW_NI_eflow4_phi_EndcapRegion", &MET_Cryo_LCW_NI_eflow4_phi_EndcapRegion, &b_MET_Cryo_LCW_NI_eflow4_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_Cryo_LCW_NI_eflow4_etx_ForwardReg", &MET_Cryo_LCW_NI_eflow4_etx_ForwardReg, &b_MET_Cryo_LCW_NI_eflow4_etx_ForwardReg);
   fChain->SetBranchAddress("MET_Cryo_LCW_NI_eflow4_ety_ForwardReg", &MET_Cryo_LCW_NI_eflow4_ety_ForwardReg, &b_MET_Cryo_LCW_NI_eflow4_ety_ForwardReg);
   fChain->SetBranchAddress("MET_Cryo_LCW_NI_eflow4_sumet_ForwardReg", &MET_Cryo_LCW_NI_eflow4_sumet_ForwardReg, &b_MET_Cryo_LCW_NI_eflow4_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_Cryo_LCW_NI_eflow4_phi_ForwardReg", &MET_Cryo_LCW_NI_eflow4_phi_ForwardReg, &b_MET_Cryo_LCW_NI_eflow4_phi_ForwardReg);
   fChain->SetBranchAddress("MET_RefMuon_LCW_NI_eflow4_etx", &MET_RefMuon_LCW_NI_eflow4_etx, &b_MET_RefMuon_LCW_NI_eflow4_etx);
   fChain->SetBranchAddress("MET_RefMuon_LCW_NI_eflow4_ety", &MET_RefMuon_LCW_NI_eflow4_ety, &b_MET_RefMuon_LCW_NI_eflow4_ety);
   fChain->SetBranchAddress("MET_RefMuon_LCW_NI_eflow4_phi", &MET_RefMuon_LCW_NI_eflow4_phi, &b_MET_RefMuon_LCW_NI_eflow4_phi);
   fChain->SetBranchAddress("MET_RefMuon_LCW_NI_eflow4_et", &MET_RefMuon_LCW_NI_eflow4_et, &b_MET_RefMuon_LCW_NI_eflow4_et);
   fChain->SetBranchAddress("MET_RefMuon_LCW_NI_eflow4_sumet", &MET_RefMuon_LCW_NI_eflow4_sumet, &b_MET_RefMuon_LCW_NI_eflow4_sumet);
   fChain->SetBranchAddress("MET_RefMuon_Staco_LCW_NI_eflow4_etx", &MET_RefMuon_Staco_LCW_NI_eflow4_etx, &b_MET_RefMuon_Staco_LCW_NI_eflow4_etx);
   fChain->SetBranchAddress("MET_RefMuon_Staco_LCW_NI_eflow4_ety", &MET_RefMuon_Staco_LCW_NI_eflow4_ety, &b_MET_RefMuon_Staco_LCW_NI_eflow4_ety);
   fChain->SetBranchAddress("MET_RefMuon_Staco_LCW_NI_eflow4_phi", &MET_RefMuon_Staco_LCW_NI_eflow4_phi, &b_MET_RefMuon_Staco_LCW_NI_eflow4_phi);
   fChain->SetBranchAddress("MET_RefMuon_Staco_LCW_NI_eflow4_et", &MET_RefMuon_Staco_LCW_NI_eflow4_et, &b_MET_RefMuon_Staco_LCW_NI_eflow4_et);
   fChain->SetBranchAddress("MET_RefMuon_Staco_LCW_NI_eflow4_sumet", &MET_RefMuon_Staco_LCW_NI_eflow4_sumet, &b_MET_RefMuon_Staco_LCW_NI_eflow4_sumet);
   fChain->SetBranchAddress("MET_Muon_Isol_Staco_LCW_NI_eflow4_etx", &MET_Muon_Isol_Staco_LCW_NI_eflow4_etx, &b_MET_Muon_Isol_Staco_LCW_NI_eflow4_etx);
   fChain->SetBranchAddress("MET_Muon_Isol_Staco_LCW_NI_eflow4_ety", &MET_Muon_Isol_Staco_LCW_NI_eflow4_ety, &b_MET_Muon_Isol_Staco_LCW_NI_eflow4_ety);
   fChain->SetBranchAddress("MET_Muon_Isol_Staco_LCW_NI_eflow4_phi", &MET_Muon_Isol_Staco_LCW_NI_eflow4_phi, &b_MET_Muon_Isol_Staco_LCW_NI_eflow4_phi);
   fChain->SetBranchAddress("MET_Muon_Isol_Staco_LCW_NI_eflow4_et", &MET_Muon_Isol_Staco_LCW_NI_eflow4_et, &b_MET_Muon_Isol_Staco_LCW_NI_eflow4_et);
   fChain->SetBranchAddress("MET_Muon_Isol_Staco_LCW_NI_eflow4_sumet", &MET_Muon_Isol_Staco_LCW_NI_eflow4_sumet, &b_MET_Muon_Isol_Staco_LCW_NI_eflow4_sumet);
   fChain->SetBranchAddress("MET_Muon_NonIsol_Staco_LCW_NI_eflow4_etx", &MET_Muon_NonIsol_Staco_LCW_NI_eflow4_etx, &b_MET_Muon_NonIsol_Staco_LCW_NI_eflow4_etx);
   fChain->SetBranchAddress("MET_Muon_NonIsol_Staco_LCW_NI_eflow4_ety", &MET_Muon_NonIsol_Staco_LCW_NI_eflow4_ety, &b_MET_Muon_NonIsol_Staco_LCW_NI_eflow4_ety);
   fChain->SetBranchAddress("MET_Muon_NonIsol_Staco_LCW_NI_eflow4_phi", &MET_Muon_NonIsol_Staco_LCW_NI_eflow4_phi, &b_MET_Muon_NonIsol_Staco_LCW_NI_eflow4_phi);
   fChain->SetBranchAddress("MET_Muon_NonIsol_Staco_LCW_NI_eflow4_et", &MET_Muon_NonIsol_Staco_LCW_NI_eflow4_et, &b_MET_Muon_NonIsol_Staco_LCW_NI_eflow4_et);
   fChain->SetBranchAddress("MET_Muon_NonIsol_Staco_LCW_NI_eflow4_sumet", &MET_Muon_NonIsol_Staco_LCW_NI_eflow4_sumet, &b_MET_Muon_NonIsol_Staco_LCW_NI_eflow4_sumet);
   fChain->SetBranchAddress("MET_Muon_Total_Staco_LCW_NI_eflow4_etx", &MET_Muon_Total_Staco_LCW_NI_eflow4_etx, &b_MET_Muon_Total_Staco_LCW_NI_eflow4_etx);
   fChain->SetBranchAddress("MET_Muon_Total_Staco_LCW_NI_eflow4_ety", &MET_Muon_Total_Staco_LCW_NI_eflow4_ety, &b_MET_Muon_Total_Staco_LCW_NI_eflow4_ety);
   fChain->SetBranchAddress("MET_Muon_Total_Staco_LCW_NI_eflow4_phi", &MET_Muon_Total_Staco_LCW_NI_eflow4_phi, &b_MET_Muon_Total_Staco_LCW_NI_eflow4_phi);
   fChain->SetBranchAddress("MET_Muon_Total_Staco_LCW_NI_eflow4_et", &MET_Muon_Total_Staco_LCW_NI_eflow4_et, &b_MET_Muon_Total_Staco_LCW_NI_eflow4_et);
   fChain->SetBranchAddress("MET_Muon_Total_Staco_LCW_NI_eflow4_sumet", &MET_Muon_Total_Staco_LCW_NI_eflow4_sumet, &b_MET_Muon_Total_Staco_LCW_NI_eflow4_sumet);
   fChain->SetBranchAddress("MET_RefMuon_Track_LCW_NI_eflow4_etx", &MET_RefMuon_Track_LCW_NI_eflow4_etx, &b_MET_RefMuon_Track_LCW_NI_eflow4_etx);
   fChain->SetBranchAddress("MET_RefMuon_Track_LCW_NI_eflow4_ety", &MET_RefMuon_Track_LCW_NI_eflow4_ety, &b_MET_RefMuon_Track_LCW_NI_eflow4_ety);
   fChain->SetBranchAddress("MET_RefMuon_Track_LCW_NI_eflow4_phi", &MET_RefMuon_Track_LCW_NI_eflow4_phi, &b_MET_RefMuon_Track_LCW_NI_eflow4_phi);
   fChain->SetBranchAddress("MET_RefMuon_Track_LCW_NI_eflow4_et", &MET_RefMuon_Track_LCW_NI_eflow4_et, &b_MET_RefMuon_Track_LCW_NI_eflow4_et);
   fChain->SetBranchAddress("MET_RefMuon_Track_LCW_NI_eflow4_sumet", &MET_RefMuon_Track_LCW_NI_eflow4_sumet, &b_MET_RefMuon_Track_LCW_NI_eflow4_sumet);
   fChain->SetBranchAddress("MET_RefMuon_Track_Staco_LCW_NI_eflow4_etx", &MET_RefMuon_Track_Staco_LCW_NI_eflow4_etx, &b_MET_RefMuon_Track_Staco_LCW_NI_eflow4_etx);
   fChain->SetBranchAddress("MET_RefMuon_Track_Staco_LCW_NI_eflow4_ety", &MET_RefMuon_Track_Staco_LCW_NI_eflow4_ety, &b_MET_RefMuon_Track_Staco_LCW_NI_eflow4_ety);
   fChain->SetBranchAddress("MET_RefMuon_Track_Staco_LCW_NI_eflow4_phi", &MET_RefMuon_Track_Staco_LCW_NI_eflow4_phi, &b_MET_RefMuon_Track_Staco_LCW_NI_eflow4_phi);
   fChain->SetBranchAddress("MET_RefMuon_Track_Staco_LCW_NI_eflow4_et", &MET_RefMuon_Track_Staco_LCW_NI_eflow4_et, &b_MET_RefMuon_Track_Staco_LCW_NI_eflow4_et);
   fChain->SetBranchAddress("MET_RefMuon_Track_Staco_LCW_NI_eflow4_sumet", &MET_RefMuon_Track_Staco_LCW_NI_eflow4_sumet, &b_MET_RefMuon_Track_Staco_LCW_NI_eflow4_sumet);
   fChain->SetBranchAddress("MET_RefFinal_LCW_NI_eflow_400_etx", &MET_RefFinal_LCW_NI_eflow_400_etx, &b_MET_RefFinal_LCW_NI_eflow_400_etx);
   fChain->SetBranchAddress("MET_RefFinal_LCW_NI_eflow_400_ety", &MET_RefFinal_LCW_NI_eflow_400_ety, &b_MET_RefFinal_LCW_NI_eflow_400_ety);
   fChain->SetBranchAddress("MET_RefFinal_LCW_NI_eflow_400_phi", &MET_RefFinal_LCW_NI_eflow_400_phi, &b_MET_RefFinal_LCW_NI_eflow_400_phi);
   fChain->SetBranchAddress("MET_RefFinal_LCW_NI_eflow_400_et", &MET_RefFinal_LCW_NI_eflow_400_et, &b_MET_RefFinal_LCW_NI_eflow_400_et);
   fChain->SetBranchAddress("MET_RefFinal_LCW_NI_eflow_400_sumet", &MET_RefFinal_LCW_NI_eflow_400_sumet, &b_MET_RefFinal_LCW_NI_eflow_400_sumet);
   fChain->SetBranchAddress("MET_RefFinal_LCW_NI_eflow_400_etx_CentralReg", &MET_RefFinal_LCW_NI_eflow_400_etx_CentralReg, &b_MET_RefFinal_LCW_NI_eflow_400_etx_CentralReg);
   fChain->SetBranchAddress("MET_RefFinal_LCW_NI_eflow_400_ety_CentralReg", &MET_RefFinal_LCW_NI_eflow_400_ety_CentralReg, &b_MET_RefFinal_LCW_NI_eflow_400_ety_CentralReg);
   fChain->SetBranchAddress("MET_RefFinal_LCW_NI_eflow_400_sumet_CentralReg", &MET_RefFinal_LCW_NI_eflow_400_sumet_CentralReg, &b_MET_RefFinal_LCW_NI_eflow_400_sumet_CentralReg);
   fChain->SetBranchAddress("MET_RefFinal_LCW_NI_eflow_400_phi_CentralReg", &MET_RefFinal_LCW_NI_eflow_400_phi_CentralReg, &b_MET_RefFinal_LCW_NI_eflow_400_phi_CentralReg);
   fChain->SetBranchAddress("MET_RefFinal_LCW_NI_eflow_400_etx_EndcapRegion", &MET_RefFinal_LCW_NI_eflow_400_etx_EndcapRegion, &b_MET_RefFinal_LCW_NI_eflow_400_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_RefFinal_LCW_NI_eflow_400_ety_EndcapRegion", &MET_RefFinal_LCW_NI_eflow_400_ety_EndcapRegion, &b_MET_RefFinal_LCW_NI_eflow_400_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_RefFinal_LCW_NI_eflow_400_sumet_EndcapRegion", &MET_RefFinal_LCW_NI_eflow_400_sumet_EndcapRegion, &b_MET_RefFinal_LCW_NI_eflow_400_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_RefFinal_LCW_NI_eflow_400_phi_EndcapRegion", &MET_RefFinal_LCW_NI_eflow_400_phi_EndcapRegion, &b_MET_RefFinal_LCW_NI_eflow_400_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_RefFinal_LCW_NI_eflow_400_etx_ForwardReg", &MET_RefFinal_LCW_NI_eflow_400_etx_ForwardReg, &b_MET_RefFinal_LCW_NI_eflow_400_etx_ForwardReg);
   fChain->SetBranchAddress("MET_RefFinal_LCW_NI_eflow_400_ety_ForwardReg", &MET_RefFinal_LCW_NI_eflow_400_ety_ForwardReg, &b_MET_RefFinal_LCW_NI_eflow_400_ety_ForwardReg);
   fChain->SetBranchAddress("MET_RefFinal_LCW_NI_eflow_400_sumet_ForwardReg", &MET_RefFinal_LCW_NI_eflow_400_sumet_ForwardReg, &b_MET_RefFinal_LCW_NI_eflow_400_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_RefFinal_LCW_NI_eflow_400_phi_ForwardReg", &MET_RefFinal_LCW_NI_eflow_400_phi_ForwardReg, &b_MET_RefFinal_LCW_NI_eflow_400_phi_ForwardReg);
   fChain->SetBranchAddress("MET_RefGamma_LCW_NI_eflow_400_etx", &MET_RefGamma_LCW_NI_eflow_400_etx, &b_MET_RefGamma_LCW_NI_eflow_400_etx);
   fChain->SetBranchAddress("MET_RefGamma_LCW_NI_eflow_400_ety", &MET_RefGamma_LCW_NI_eflow_400_ety, &b_MET_RefGamma_LCW_NI_eflow_400_ety);
   fChain->SetBranchAddress("MET_RefGamma_LCW_NI_eflow_400_phi", &MET_RefGamma_LCW_NI_eflow_400_phi, &b_MET_RefGamma_LCW_NI_eflow_400_phi);
   fChain->SetBranchAddress("MET_RefGamma_LCW_NI_eflow_400_et", &MET_RefGamma_LCW_NI_eflow_400_et, &b_MET_RefGamma_LCW_NI_eflow_400_et);
   fChain->SetBranchAddress("MET_RefGamma_LCW_NI_eflow_400_sumet", &MET_RefGamma_LCW_NI_eflow_400_sumet, &b_MET_RefGamma_LCW_NI_eflow_400_sumet);
   fChain->SetBranchAddress("MET_RefGamma_LCW_NI_eflow_400_etx_CentralReg", &MET_RefGamma_LCW_NI_eflow_400_etx_CentralReg, &b_MET_RefGamma_LCW_NI_eflow_400_etx_CentralReg);
   fChain->SetBranchAddress("MET_RefGamma_LCW_NI_eflow_400_ety_CentralReg", &MET_RefGamma_LCW_NI_eflow_400_ety_CentralReg, &b_MET_RefGamma_LCW_NI_eflow_400_ety_CentralReg);
   fChain->SetBranchAddress("MET_RefGamma_LCW_NI_eflow_400_sumet_CentralReg", &MET_RefGamma_LCW_NI_eflow_400_sumet_CentralReg, &b_MET_RefGamma_LCW_NI_eflow_400_sumet_CentralReg);
   fChain->SetBranchAddress("MET_RefGamma_LCW_NI_eflow_400_phi_CentralReg", &MET_RefGamma_LCW_NI_eflow_400_phi_CentralReg, &b_MET_RefGamma_LCW_NI_eflow_400_phi_CentralReg);
   fChain->SetBranchAddress("MET_RefGamma_LCW_NI_eflow_400_etx_EndcapRegion", &MET_RefGamma_LCW_NI_eflow_400_etx_EndcapRegion, &b_MET_RefGamma_LCW_NI_eflow_400_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_RefGamma_LCW_NI_eflow_400_ety_EndcapRegion", &MET_RefGamma_LCW_NI_eflow_400_ety_EndcapRegion, &b_MET_RefGamma_LCW_NI_eflow_400_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_RefGamma_LCW_NI_eflow_400_sumet_EndcapRegion", &MET_RefGamma_LCW_NI_eflow_400_sumet_EndcapRegion, &b_MET_RefGamma_LCW_NI_eflow_400_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_RefGamma_LCW_NI_eflow_400_phi_EndcapRegion", &MET_RefGamma_LCW_NI_eflow_400_phi_EndcapRegion, &b_MET_RefGamma_LCW_NI_eflow_400_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_RefGamma_LCW_NI_eflow_400_etx_ForwardReg", &MET_RefGamma_LCW_NI_eflow_400_etx_ForwardReg, &b_MET_RefGamma_LCW_NI_eflow_400_etx_ForwardReg);
   fChain->SetBranchAddress("MET_RefGamma_LCW_NI_eflow_400_ety_ForwardReg", &MET_RefGamma_LCW_NI_eflow_400_ety_ForwardReg, &b_MET_RefGamma_LCW_NI_eflow_400_ety_ForwardReg);
   fChain->SetBranchAddress("MET_RefGamma_LCW_NI_eflow_400_sumet_ForwardReg", &MET_RefGamma_LCW_NI_eflow_400_sumet_ForwardReg, &b_MET_RefGamma_LCW_NI_eflow_400_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_RefGamma_LCW_NI_eflow_400_phi_ForwardReg", &MET_RefGamma_LCW_NI_eflow_400_phi_ForwardReg, &b_MET_RefGamma_LCW_NI_eflow_400_phi_ForwardReg);
   fChain->SetBranchAddress("MET_RefEle_LCW_NI_eflow_400_etx", &MET_RefEle_LCW_NI_eflow_400_etx, &b_MET_RefEle_LCW_NI_eflow_400_etx);
   fChain->SetBranchAddress("MET_RefEle_LCW_NI_eflow_400_ety", &MET_RefEle_LCW_NI_eflow_400_ety, &b_MET_RefEle_LCW_NI_eflow_400_ety);
   fChain->SetBranchAddress("MET_RefEle_LCW_NI_eflow_400_phi", &MET_RefEle_LCW_NI_eflow_400_phi, &b_MET_RefEle_LCW_NI_eflow_400_phi);
   fChain->SetBranchAddress("MET_RefEle_LCW_NI_eflow_400_et", &MET_RefEle_LCW_NI_eflow_400_et, &b_MET_RefEle_LCW_NI_eflow_400_et);
   fChain->SetBranchAddress("MET_RefEle_LCW_NI_eflow_400_sumet", &MET_RefEle_LCW_NI_eflow_400_sumet, &b_MET_RefEle_LCW_NI_eflow_400_sumet);
   fChain->SetBranchAddress("MET_RefEle_LCW_NI_eflow_400_etx_CentralReg", &MET_RefEle_LCW_NI_eflow_400_etx_CentralReg, &b_MET_RefEle_LCW_NI_eflow_400_etx_CentralReg);
   fChain->SetBranchAddress("MET_RefEle_LCW_NI_eflow_400_ety_CentralReg", &MET_RefEle_LCW_NI_eflow_400_ety_CentralReg, &b_MET_RefEle_LCW_NI_eflow_400_ety_CentralReg);
   fChain->SetBranchAddress("MET_RefEle_LCW_NI_eflow_400_sumet_CentralReg", &MET_RefEle_LCW_NI_eflow_400_sumet_CentralReg, &b_MET_RefEle_LCW_NI_eflow_400_sumet_CentralReg);
   fChain->SetBranchAddress("MET_RefEle_LCW_NI_eflow_400_phi_CentralReg", &MET_RefEle_LCW_NI_eflow_400_phi_CentralReg, &b_MET_RefEle_LCW_NI_eflow_400_phi_CentralReg);
   fChain->SetBranchAddress("MET_RefEle_LCW_NI_eflow_400_etx_EndcapRegion", &MET_RefEle_LCW_NI_eflow_400_etx_EndcapRegion, &b_MET_RefEle_LCW_NI_eflow_400_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_RefEle_LCW_NI_eflow_400_ety_EndcapRegion", &MET_RefEle_LCW_NI_eflow_400_ety_EndcapRegion, &b_MET_RefEle_LCW_NI_eflow_400_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_RefEle_LCW_NI_eflow_400_sumet_EndcapRegion", &MET_RefEle_LCW_NI_eflow_400_sumet_EndcapRegion, &b_MET_RefEle_LCW_NI_eflow_400_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_RefEle_LCW_NI_eflow_400_phi_EndcapRegion", &MET_RefEle_LCW_NI_eflow_400_phi_EndcapRegion, &b_MET_RefEle_LCW_NI_eflow_400_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_RefEle_LCW_NI_eflow_400_etx_ForwardReg", &MET_RefEle_LCW_NI_eflow_400_etx_ForwardReg, &b_MET_RefEle_LCW_NI_eflow_400_etx_ForwardReg);
   fChain->SetBranchAddress("MET_RefEle_LCW_NI_eflow_400_ety_ForwardReg", &MET_RefEle_LCW_NI_eflow_400_ety_ForwardReg, &b_MET_RefEle_LCW_NI_eflow_400_ety_ForwardReg);
   fChain->SetBranchAddress("MET_RefEle_LCW_NI_eflow_400_sumet_ForwardReg", &MET_RefEle_LCW_NI_eflow_400_sumet_ForwardReg, &b_MET_RefEle_LCW_NI_eflow_400_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_RefEle_LCW_NI_eflow_400_phi_ForwardReg", &MET_RefEle_LCW_NI_eflow_400_phi_ForwardReg, &b_MET_RefEle_LCW_NI_eflow_400_phi_ForwardReg);
   fChain->SetBranchAddress("MET_RefTau_LCW_NI_eflow_400_etx", &MET_RefTau_LCW_NI_eflow_400_etx, &b_MET_RefTau_LCW_NI_eflow_400_etx);
   fChain->SetBranchAddress("MET_RefTau_LCW_NI_eflow_400_ety", &MET_RefTau_LCW_NI_eflow_400_ety, &b_MET_RefTau_LCW_NI_eflow_400_ety);
   fChain->SetBranchAddress("MET_RefTau_LCW_NI_eflow_400_phi", &MET_RefTau_LCW_NI_eflow_400_phi, &b_MET_RefTau_LCW_NI_eflow_400_phi);
   fChain->SetBranchAddress("MET_RefTau_LCW_NI_eflow_400_et", &MET_RefTau_LCW_NI_eflow_400_et, &b_MET_RefTau_LCW_NI_eflow_400_et);
   fChain->SetBranchAddress("MET_RefTau_LCW_NI_eflow_400_sumet", &MET_RefTau_LCW_NI_eflow_400_sumet, &b_MET_RefTau_LCW_NI_eflow_400_sumet);
   fChain->SetBranchAddress("MET_RefTau_LCW_NI_eflow_400_etx_CentralReg", &MET_RefTau_LCW_NI_eflow_400_etx_CentralReg, &b_MET_RefTau_LCW_NI_eflow_400_etx_CentralReg);
   fChain->SetBranchAddress("MET_RefTau_LCW_NI_eflow_400_ety_CentralReg", &MET_RefTau_LCW_NI_eflow_400_ety_CentralReg, &b_MET_RefTau_LCW_NI_eflow_400_ety_CentralReg);
   fChain->SetBranchAddress("MET_RefTau_LCW_NI_eflow_400_sumet_CentralReg", &MET_RefTau_LCW_NI_eflow_400_sumet_CentralReg, &b_MET_RefTau_LCW_NI_eflow_400_sumet_CentralReg);
   fChain->SetBranchAddress("MET_RefTau_LCW_NI_eflow_400_phi_CentralReg", &MET_RefTau_LCW_NI_eflow_400_phi_CentralReg, &b_MET_RefTau_LCW_NI_eflow_400_phi_CentralReg);
   fChain->SetBranchAddress("MET_RefTau_LCW_NI_eflow_400_etx_EndcapRegion", &MET_RefTau_LCW_NI_eflow_400_etx_EndcapRegion, &b_MET_RefTau_LCW_NI_eflow_400_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_RefTau_LCW_NI_eflow_400_ety_EndcapRegion", &MET_RefTau_LCW_NI_eflow_400_ety_EndcapRegion, &b_MET_RefTau_LCW_NI_eflow_400_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_RefTau_LCW_NI_eflow_400_sumet_EndcapRegion", &MET_RefTau_LCW_NI_eflow_400_sumet_EndcapRegion, &b_MET_RefTau_LCW_NI_eflow_400_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_RefTau_LCW_NI_eflow_400_phi_EndcapRegion", &MET_RefTau_LCW_NI_eflow_400_phi_EndcapRegion, &b_MET_RefTau_LCW_NI_eflow_400_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_RefTau_LCW_NI_eflow_400_etx_ForwardReg", &MET_RefTau_LCW_NI_eflow_400_etx_ForwardReg, &b_MET_RefTau_LCW_NI_eflow_400_etx_ForwardReg);
   fChain->SetBranchAddress("MET_RefTau_LCW_NI_eflow_400_ety_ForwardReg", &MET_RefTau_LCW_NI_eflow_400_ety_ForwardReg, &b_MET_RefTau_LCW_NI_eflow_400_ety_ForwardReg);
   fChain->SetBranchAddress("MET_RefTau_LCW_NI_eflow_400_sumet_ForwardReg", &MET_RefTau_LCW_NI_eflow_400_sumet_ForwardReg, &b_MET_RefTau_LCW_NI_eflow_400_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_RefTau_LCW_NI_eflow_400_phi_ForwardReg", &MET_RefTau_LCW_NI_eflow_400_phi_ForwardReg, &b_MET_RefTau_LCW_NI_eflow_400_phi_ForwardReg);
   fChain->SetBranchAddress("MET_RefJet_LCW_NI_eflow_400_etx", &MET_RefJet_LCW_NI_eflow_400_etx, &b_MET_RefJet_LCW_NI_eflow_400_etx);
   fChain->SetBranchAddress("MET_RefJet_LCW_NI_eflow_400_ety", &MET_RefJet_LCW_NI_eflow_400_ety, &b_MET_RefJet_LCW_NI_eflow_400_ety);
   fChain->SetBranchAddress("MET_RefJet_LCW_NI_eflow_400_phi", &MET_RefJet_LCW_NI_eflow_400_phi, &b_MET_RefJet_LCW_NI_eflow_400_phi);
   fChain->SetBranchAddress("MET_RefJet_LCW_NI_eflow_400_et", &MET_RefJet_LCW_NI_eflow_400_et, &b_MET_RefJet_LCW_NI_eflow_400_et);
   fChain->SetBranchAddress("MET_RefJet_LCW_NI_eflow_400_sumet", &MET_RefJet_LCW_NI_eflow_400_sumet, &b_MET_RefJet_LCW_NI_eflow_400_sumet);
   fChain->SetBranchAddress("MET_RefJet_LCW_NI_eflow_400_etx_CentralReg", &MET_RefJet_LCW_NI_eflow_400_etx_CentralReg, &b_MET_RefJet_LCW_NI_eflow_400_etx_CentralReg);
   fChain->SetBranchAddress("MET_RefJet_LCW_NI_eflow_400_ety_CentralReg", &MET_RefJet_LCW_NI_eflow_400_ety_CentralReg, &b_MET_RefJet_LCW_NI_eflow_400_ety_CentralReg);
   fChain->SetBranchAddress("MET_RefJet_LCW_NI_eflow_400_sumet_CentralReg", &MET_RefJet_LCW_NI_eflow_400_sumet_CentralReg, &b_MET_RefJet_LCW_NI_eflow_400_sumet_CentralReg);
   fChain->SetBranchAddress("MET_RefJet_LCW_NI_eflow_400_phi_CentralReg", &MET_RefJet_LCW_NI_eflow_400_phi_CentralReg, &b_MET_RefJet_LCW_NI_eflow_400_phi_CentralReg);
   fChain->SetBranchAddress("MET_RefJet_LCW_NI_eflow_400_etx_EndcapRegion", &MET_RefJet_LCW_NI_eflow_400_etx_EndcapRegion, &b_MET_RefJet_LCW_NI_eflow_400_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_RefJet_LCW_NI_eflow_400_ety_EndcapRegion", &MET_RefJet_LCW_NI_eflow_400_ety_EndcapRegion, &b_MET_RefJet_LCW_NI_eflow_400_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_RefJet_LCW_NI_eflow_400_sumet_EndcapRegion", &MET_RefJet_LCW_NI_eflow_400_sumet_EndcapRegion, &b_MET_RefJet_LCW_NI_eflow_400_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_RefJet_LCW_NI_eflow_400_phi_EndcapRegion", &MET_RefJet_LCW_NI_eflow_400_phi_EndcapRegion, &b_MET_RefJet_LCW_NI_eflow_400_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_RefJet_LCW_NI_eflow_400_etx_ForwardReg", &MET_RefJet_LCW_NI_eflow_400_etx_ForwardReg, &b_MET_RefJet_LCW_NI_eflow_400_etx_ForwardReg);
   fChain->SetBranchAddress("MET_RefJet_LCW_NI_eflow_400_ety_ForwardReg", &MET_RefJet_LCW_NI_eflow_400_ety_ForwardReg, &b_MET_RefJet_LCW_NI_eflow_400_ety_ForwardReg);
   fChain->SetBranchAddress("MET_RefJet_LCW_NI_eflow_400_sumet_ForwardReg", &MET_RefJet_LCW_NI_eflow_400_sumet_ForwardReg, &b_MET_RefJet_LCW_NI_eflow_400_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_RefJet_LCW_NI_eflow_400_phi_ForwardReg", &MET_RefJet_LCW_NI_eflow_400_phi_ForwardReg, &b_MET_RefJet_LCW_NI_eflow_400_phi_ForwardReg);
   fChain->SetBranchAddress("MET_CellOut_LCW_NI_eflow_400_etx", &MET_CellOut_LCW_NI_eflow_400_etx, &b_MET_CellOut_LCW_NI_eflow_400_etx);
   fChain->SetBranchAddress("MET_CellOut_LCW_NI_eflow_400_ety", &MET_CellOut_LCW_NI_eflow_400_ety, &b_MET_CellOut_LCW_NI_eflow_400_ety);
   fChain->SetBranchAddress("MET_CellOut_LCW_NI_eflow_400_phi", &MET_CellOut_LCW_NI_eflow_400_phi, &b_MET_CellOut_LCW_NI_eflow_400_phi);
   fChain->SetBranchAddress("MET_CellOut_LCW_NI_eflow_400_et", &MET_CellOut_LCW_NI_eflow_400_et, &b_MET_CellOut_LCW_NI_eflow_400_et);
   fChain->SetBranchAddress("MET_CellOut_LCW_NI_eflow_400_sumet", &MET_CellOut_LCW_NI_eflow_400_sumet, &b_MET_CellOut_LCW_NI_eflow_400_sumet);
   fChain->SetBranchAddress("MET_CellOut_LCW_NI_eflow_400_etx_CentralReg", &MET_CellOut_LCW_NI_eflow_400_etx_CentralReg, &b_MET_CellOut_LCW_NI_eflow_400_etx_CentralReg);
   fChain->SetBranchAddress("MET_CellOut_LCW_NI_eflow_400_ety_CentralReg", &MET_CellOut_LCW_NI_eflow_400_ety_CentralReg, &b_MET_CellOut_LCW_NI_eflow_400_ety_CentralReg);
   fChain->SetBranchAddress("MET_CellOut_LCW_NI_eflow_400_sumet_CentralReg", &MET_CellOut_LCW_NI_eflow_400_sumet_CentralReg, &b_MET_CellOut_LCW_NI_eflow_400_sumet_CentralReg);
   fChain->SetBranchAddress("MET_CellOut_LCW_NI_eflow_400_phi_CentralReg", &MET_CellOut_LCW_NI_eflow_400_phi_CentralReg, &b_MET_CellOut_LCW_NI_eflow_400_phi_CentralReg);
   fChain->SetBranchAddress("MET_CellOut_LCW_NI_eflow_400_etx_EndcapRegion", &MET_CellOut_LCW_NI_eflow_400_etx_EndcapRegion, &b_MET_CellOut_LCW_NI_eflow_400_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_CellOut_LCW_NI_eflow_400_ety_EndcapRegion", &MET_CellOut_LCW_NI_eflow_400_ety_EndcapRegion, &b_MET_CellOut_LCW_NI_eflow_400_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_CellOut_LCW_NI_eflow_400_sumet_EndcapRegion", &MET_CellOut_LCW_NI_eflow_400_sumet_EndcapRegion, &b_MET_CellOut_LCW_NI_eflow_400_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_CellOut_LCW_NI_eflow_400_phi_EndcapRegion", &MET_CellOut_LCW_NI_eflow_400_phi_EndcapRegion, &b_MET_CellOut_LCW_NI_eflow_400_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_CellOut_LCW_NI_eflow_400_etx_ForwardReg", &MET_CellOut_LCW_NI_eflow_400_etx_ForwardReg, &b_MET_CellOut_LCW_NI_eflow_400_etx_ForwardReg);
   fChain->SetBranchAddress("MET_CellOut_LCW_NI_eflow_400_ety_ForwardReg", &MET_CellOut_LCW_NI_eflow_400_ety_ForwardReg, &b_MET_CellOut_LCW_NI_eflow_400_ety_ForwardReg);
   fChain->SetBranchAddress("MET_CellOut_LCW_NI_eflow_400_sumet_ForwardReg", &MET_CellOut_LCW_NI_eflow_400_sumet_ForwardReg, &b_MET_CellOut_LCW_NI_eflow_400_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_CellOut_LCW_NI_eflow_400_phi_ForwardReg", &MET_CellOut_LCW_NI_eflow_400_phi_ForwardReg, &b_MET_CellOut_LCW_NI_eflow_400_phi_ForwardReg);
   fChain->SetBranchAddress("MET_Cryo_LCW_NI_eflow_400_etx", &MET_Cryo_LCW_NI_eflow_400_etx, &b_MET_Cryo_LCW_NI_eflow_400_etx);
   fChain->SetBranchAddress("MET_Cryo_LCW_NI_eflow_400_ety", &MET_Cryo_LCW_NI_eflow_400_ety, &b_MET_Cryo_LCW_NI_eflow_400_ety);
   fChain->SetBranchAddress("MET_Cryo_LCW_NI_eflow_400_phi", &MET_Cryo_LCW_NI_eflow_400_phi, &b_MET_Cryo_LCW_NI_eflow_400_phi);
   fChain->SetBranchAddress("MET_Cryo_LCW_NI_eflow_400_et", &MET_Cryo_LCW_NI_eflow_400_et, &b_MET_Cryo_LCW_NI_eflow_400_et);
   fChain->SetBranchAddress("MET_Cryo_LCW_NI_eflow_400_sumet", &MET_Cryo_LCW_NI_eflow_400_sumet, &b_MET_Cryo_LCW_NI_eflow_400_sumet);
   fChain->SetBranchAddress("MET_Cryo_LCW_NI_eflow_400_etx_CentralReg", &MET_Cryo_LCW_NI_eflow_400_etx_CentralReg, &b_MET_Cryo_LCW_NI_eflow_400_etx_CentralReg);
   fChain->SetBranchAddress("MET_Cryo_LCW_NI_eflow_400_ety_CentralReg", &MET_Cryo_LCW_NI_eflow_400_ety_CentralReg, &b_MET_Cryo_LCW_NI_eflow_400_ety_CentralReg);
   fChain->SetBranchAddress("MET_Cryo_LCW_NI_eflow_400_sumet_CentralReg", &MET_Cryo_LCW_NI_eflow_400_sumet_CentralReg, &b_MET_Cryo_LCW_NI_eflow_400_sumet_CentralReg);
   fChain->SetBranchAddress("MET_Cryo_LCW_NI_eflow_400_phi_CentralReg", &MET_Cryo_LCW_NI_eflow_400_phi_CentralReg, &b_MET_Cryo_LCW_NI_eflow_400_phi_CentralReg);
   fChain->SetBranchAddress("MET_Cryo_LCW_NI_eflow_400_etx_EndcapRegion", &MET_Cryo_LCW_NI_eflow_400_etx_EndcapRegion, &b_MET_Cryo_LCW_NI_eflow_400_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_Cryo_LCW_NI_eflow_400_ety_EndcapRegion", &MET_Cryo_LCW_NI_eflow_400_ety_EndcapRegion, &b_MET_Cryo_LCW_NI_eflow_400_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_Cryo_LCW_NI_eflow_400_sumet_EndcapRegion", &MET_Cryo_LCW_NI_eflow_400_sumet_EndcapRegion, &b_MET_Cryo_LCW_NI_eflow_400_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_Cryo_LCW_NI_eflow_400_phi_EndcapRegion", &MET_Cryo_LCW_NI_eflow_400_phi_EndcapRegion, &b_MET_Cryo_LCW_NI_eflow_400_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_Cryo_LCW_NI_eflow_400_etx_ForwardReg", &MET_Cryo_LCW_NI_eflow_400_etx_ForwardReg, &b_MET_Cryo_LCW_NI_eflow_400_etx_ForwardReg);
   fChain->SetBranchAddress("MET_Cryo_LCW_NI_eflow_400_ety_ForwardReg", &MET_Cryo_LCW_NI_eflow_400_ety_ForwardReg, &b_MET_Cryo_LCW_NI_eflow_400_ety_ForwardReg);
   fChain->SetBranchAddress("MET_Cryo_LCW_NI_eflow_400_sumet_ForwardReg", &MET_Cryo_LCW_NI_eflow_400_sumet_ForwardReg, &b_MET_Cryo_LCW_NI_eflow_400_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_Cryo_LCW_NI_eflow_400_phi_ForwardReg", &MET_Cryo_LCW_NI_eflow_400_phi_ForwardReg, &b_MET_Cryo_LCW_NI_eflow_400_phi_ForwardReg);
   fChain->SetBranchAddress("MET_RefMuon_LCW_NI_eflow_400_etx", &MET_RefMuon_LCW_NI_eflow_400_etx, &b_MET_RefMuon_LCW_NI_eflow_400_etx);
   fChain->SetBranchAddress("MET_RefMuon_LCW_NI_eflow_400_ety", &MET_RefMuon_LCW_NI_eflow_400_ety, &b_MET_RefMuon_LCW_NI_eflow_400_ety);
   fChain->SetBranchAddress("MET_RefMuon_LCW_NI_eflow_400_phi", &MET_RefMuon_LCW_NI_eflow_400_phi, &b_MET_RefMuon_LCW_NI_eflow_400_phi);
   fChain->SetBranchAddress("MET_RefMuon_LCW_NI_eflow_400_et", &MET_RefMuon_LCW_NI_eflow_400_et, &b_MET_RefMuon_LCW_NI_eflow_400_et);
   fChain->SetBranchAddress("MET_RefMuon_LCW_NI_eflow_400_sumet", &MET_RefMuon_LCW_NI_eflow_400_sumet, &b_MET_RefMuon_LCW_NI_eflow_400_sumet);
   fChain->SetBranchAddress("MET_RefMuon_Staco_LCW_NI_eflow_400_etx", &MET_RefMuon_Staco_LCW_NI_eflow_400_etx, &b_MET_RefMuon_Staco_LCW_NI_eflow_400_etx);
   fChain->SetBranchAddress("MET_RefMuon_Staco_LCW_NI_eflow_400_ety", &MET_RefMuon_Staco_LCW_NI_eflow_400_ety, &b_MET_RefMuon_Staco_LCW_NI_eflow_400_ety);
   fChain->SetBranchAddress("MET_RefMuon_Staco_LCW_NI_eflow_400_phi", &MET_RefMuon_Staco_LCW_NI_eflow_400_phi, &b_MET_RefMuon_Staco_LCW_NI_eflow_400_phi);
   fChain->SetBranchAddress("MET_RefMuon_Staco_LCW_NI_eflow_400_et", &MET_RefMuon_Staco_LCW_NI_eflow_400_et, &b_MET_RefMuon_Staco_LCW_NI_eflow_400_et);
   fChain->SetBranchAddress("MET_RefMuon_Staco_LCW_NI_eflow_400_sumet", &MET_RefMuon_Staco_LCW_NI_eflow_400_sumet, &b_MET_RefMuon_Staco_LCW_NI_eflow_400_sumet);
   fChain->SetBranchAddress("MET_Muon_Isol_Staco_LCW_NI_eflow_400_etx", &MET_Muon_Isol_Staco_LCW_NI_eflow_400_etx, &b_MET_Muon_Isol_Staco_LCW_NI_eflow_400_etx);
   fChain->SetBranchAddress("MET_Muon_Isol_Staco_LCW_NI_eflow_400_ety", &MET_Muon_Isol_Staco_LCW_NI_eflow_400_ety, &b_MET_Muon_Isol_Staco_LCW_NI_eflow_400_ety);
   fChain->SetBranchAddress("MET_Muon_Isol_Staco_LCW_NI_eflow_400_phi", &MET_Muon_Isol_Staco_LCW_NI_eflow_400_phi, &b_MET_Muon_Isol_Staco_LCW_NI_eflow_400_phi);
   fChain->SetBranchAddress("MET_Muon_Isol_Staco_LCW_NI_eflow_400_et", &MET_Muon_Isol_Staco_LCW_NI_eflow_400_et, &b_MET_Muon_Isol_Staco_LCW_NI_eflow_400_et);
   fChain->SetBranchAddress("MET_Muon_Isol_Staco_LCW_NI_eflow_400_sumet", &MET_Muon_Isol_Staco_LCW_NI_eflow_400_sumet, &b_MET_Muon_Isol_Staco_LCW_NI_eflow_400_sumet);
   fChain->SetBranchAddress("MET_Muon_NonIsol_Staco_LCW_NI_eflow_400_etx", &MET_Muon_NonIsol_Staco_LCW_NI_eflow_400_etx, &b_MET_Muon_NonIsol_Staco_LCW_NI_eflow_400_etx);
   fChain->SetBranchAddress("MET_Muon_NonIsol_Staco_LCW_NI_eflow_400_ety", &MET_Muon_NonIsol_Staco_LCW_NI_eflow_400_ety, &b_MET_Muon_NonIsol_Staco_LCW_NI_eflow_400_ety);
   fChain->SetBranchAddress("MET_Muon_NonIsol_Staco_LCW_NI_eflow_400_phi", &MET_Muon_NonIsol_Staco_LCW_NI_eflow_400_phi, &b_MET_Muon_NonIsol_Staco_LCW_NI_eflow_400_phi);
   fChain->SetBranchAddress("MET_Muon_NonIsol_Staco_LCW_NI_eflow_400_et", &MET_Muon_NonIsol_Staco_LCW_NI_eflow_400_et, &b_MET_Muon_NonIsol_Staco_LCW_NI_eflow_400_et);
   fChain->SetBranchAddress("MET_Muon_NonIsol_Staco_LCW_NI_eflow_400_sumet", &MET_Muon_NonIsol_Staco_LCW_NI_eflow_400_sumet, &b_MET_Muon_NonIsol_Staco_LCW_NI_eflow_400_sumet);
   fChain->SetBranchAddress("MET_Muon_Total_Staco_LCW_NI_eflow_400_etx", &MET_Muon_Total_Staco_LCW_NI_eflow_400_etx, &b_MET_Muon_Total_Staco_LCW_NI_eflow_400_etx);
   fChain->SetBranchAddress("MET_Muon_Total_Staco_LCW_NI_eflow_400_ety", &MET_Muon_Total_Staco_LCW_NI_eflow_400_ety, &b_MET_Muon_Total_Staco_LCW_NI_eflow_400_ety);
   fChain->SetBranchAddress("MET_Muon_Total_Staco_LCW_NI_eflow_400_phi", &MET_Muon_Total_Staco_LCW_NI_eflow_400_phi, &b_MET_Muon_Total_Staco_LCW_NI_eflow_400_phi);
   fChain->SetBranchAddress("MET_Muon_Total_Staco_LCW_NI_eflow_400_et", &MET_Muon_Total_Staco_LCW_NI_eflow_400_et, &b_MET_Muon_Total_Staco_LCW_NI_eflow_400_et);
   fChain->SetBranchAddress("MET_Muon_Total_Staco_LCW_NI_eflow_400_sumet", &MET_Muon_Total_Staco_LCW_NI_eflow_400_sumet, &b_MET_Muon_Total_Staco_LCW_NI_eflow_400_sumet);
   fChain->SetBranchAddress("MET_RefMuon_Track_LCW_NI_eflow_400_etx", &MET_RefMuon_Track_LCW_NI_eflow_400_etx, &b_MET_RefMuon_Track_LCW_NI_eflow_400_etx);
   fChain->SetBranchAddress("MET_RefMuon_Track_LCW_NI_eflow_400_ety", &MET_RefMuon_Track_LCW_NI_eflow_400_ety, &b_MET_RefMuon_Track_LCW_NI_eflow_400_ety);
   fChain->SetBranchAddress("MET_RefMuon_Track_LCW_NI_eflow_400_phi", &MET_RefMuon_Track_LCW_NI_eflow_400_phi, &b_MET_RefMuon_Track_LCW_NI_eflow_400_phi);
   fChain->SetBranchAddress("MET_RefMuon_Track_LCW_NI_eflow_400_et", &MET_RefMuon_Track_LCW_NI_eflow_400_et, &b_MET_RefMuon_Track_LCW_NI_eflow_400_et);
   fChain->SetBranchAddress("MET_RefMuon_Track_LCW_NI_eflow_400_sumet", &MET_RefMuon_Track_LCW_NI_eflow_400_sumet, &b_MET_RefMuon_Track_LCW_NI_eflow_400_sumet);
   fChain->SetBranchAddress("MET_RefMuon_Track_Staco_LCW_NI_eflow_400_etx", &MET_RefMuon_Track_Staco_LCW_NI_eflow_400_etx, &b_MET_RefMuon_Track_Staco_LCW_NI_eflow_400_etx);
   fChain->SetBranchAddress("MET_RefMuon_Track_Staco_LCW_NI_eflow_400_ety", &MET_RefMuon_Track_Staco_LCW_NI_eflow_400_ety, &b_MET_RefMuon_Track_Staco_LCW_NI_eflow_400_ety);
   fChain->SetBranchAddress("MET_RefMuon_Track_Staco_LCW_NI_eflow_400_phi", &MET_RefMuon_Track_Staco_LCW_NI_eflow_400_phi, &b_MET_RefMuon_Track_Staco_LCW_NI_eflow_400_phi);
   fChain->SetBranchAddress("MET_RefMuon_Track_Staco_LCW_NI_eflow_400_et", &MET_RefMuon_Track_Staco_LCW_NI_eflow_400_et, &b_MET_RefMuon_Track_Staco_LCW_NI_eflow_400_et);
   fChain->SetBranchAddress("MET_RefMuon_Track_Staco_LCW_NI_eflow_400_sumet", &MET_RefMuon_Track_Staco_LCW_NI_eflow_400_sumet, &b_MET_RefMuon_Track_Staco_LCW_NI_eflow_400_sumet);
   fChain->SetBranchAddress("MET_RefFinal_LCW_pt20_etx", &MET_RefFinal_LCW_pt20_etx, &b_MET_RefFinal_LCW_pt20_etx);
   fChain->SetBranchAddress("MET_RefFinal_LCW_pt20_ety", &MET_RefFinal_LCW_pt20_ety, &b_MET_RefFinal_LCW_pt20_ety);
   fChain->SetBranchAddress("MET_RefFinal_LCW_pt20_phi", &MET_RefFinal_LCW_pt20_phi, &b_MET_RefFinal_LCW_pt20_phi);
   fChain->SetBranchAddress("MET_RefFinal_LCW_pt20_et", &MET_RefFinal_LCW_pt20_et, &b_MET_RefFinal_LCW_pt20_et);
   fChain->SetBranchAddress("MET_RefFinal_LCW_pt20_sumet", &MET_RefFinal_LCW_pt20_sumet, &b_MET_RefFinal_LCW_pt20_sumet);
   fChain->SetBranchAddress("MET_RefFinal_LCW_pt20_etx_CentralReg", &MET_RefFinal_LCW_pt20_etx_CentralReg, &b_MET_RefFinal_LCW_pt20_etx_CentralReg);
   fChain->SetBranchAddress("MET_RefFinal_LCW_pt20_ety_CentralReg", &MET_RefFinal_LCW_pt20_ety_CentralReg, &b_MET_RefFinal_LCW_pt20_ety_CentralReg);
   fChain->SetBranchAddress("MET_RefFinal_LCW_pt20_sumet_CentralReg", &MET_RefFinal_LCW_pt20_sumet_CentralReg, &b_MET_RefFinal_LCW_pt20_sumet_CentralReg);
   fChain->SetBranchAddress("MET_RefFinal_LCW_pt20_phi_CentralReg", &MET_RefFinal_LCW_pt20_phi_CentralReg, &b_MET_RefFinal_LCW_pt20_phi_CentralReg);
   fChain->SetBranchAddress("MET_RefFinal_LCW_pt20_etx_EndcapRegion", &MET_RefFinal_LCW_pt20_etx_EndcapRegion, &b_MET_RefFinal_LCW_pt20_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_RefFinal_LCW_pt20_ety_EndcapRegion", &MET_RefFinal_LCW_pt20_ety_EndcapRegion, &b_MET_RefFinal_LCW_pt20_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_RefFinal_LCW_pt20_sumet_EndcapRegion", &MET_RefFinal_LCW_pt20_sumet_EndcapRegion, &b_MET_RefFinal_LCW_pt20_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_RefFinal_LCW_pt20_phi_EndcapRegion", &MET_RefFinal_LCW_pt20_phi_EndcapRegion, &b_MET_RefFinal_LCW_pt20_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_RefFinal_LCW_pt20_etx_ForwardReg", &MET_RefFinal_LCW_pt20_etx_ForwardReg, &b_MET_RefFinal_LCW_pt20_etx_ForwardReg);
   fChain->SetBranchAddress("MET_RefFinal_LCW_pt20_ety_ForwardReg", &MET_RefFinal_LCW_pt20_ety_ForwardReg, &b_MET_RefFinal_LCW_pt20_ety_ForwardReg);
   fChain->SetBranchAddress("MET_RefFinal_LCW_pt20_sumet_ForwardReg", &MET_RefFinal_LCW_pt20_sumet_ForwardReg, &b_MET_RefFinal_LCW_pt20_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_RefFinal_LCW_pt20_phi_ForwardReg", &MET_RefFinal_LCW_pt20_phi_ForwardReg, &b_MET_RefFinal_LCW_pt20_phi_ForwardReg);
   fChain->SetBranchAddress("MET_RefGamma_LCW_pt20_etx", &MET_RefGamma_LCW_pt20_etx, &b_MET_RefGamma_LCW_pt20_etx);
   fChain->SetBranchAddress("MET_RefGamma_LCW_pt20_ety", &MET_RefGamma_LCW_pt20_ety, &b_MET_RefGamma_LCW_pt20_ety);
   fChain->SetBranchAddress("MET_RefGamma_LCW_pt20_phi", &MET_RefGamma_LCW_pt20_phi, &b_MET_RefGamma_LCW_pt20_phi);
   fChain->SetBranchAddress("MET_RefGamma_LCW_pt20_et", &MET_RefGamma_LCW_pt20_et, &b_MET_RefGamma_LCW_pt20_et);
   fChain->SetBranchAddress("MET_RefGamma_LCW_pt20_sumet", &MET_RefGamma_LCW_pt20_sumet, &b_MET_RefGamma_LCW_pt20_sumet);
   fChain->SetBranchAddress("MET_RefGamma_LCW_pt20_etx_CentralReg", &MET_RefGamma_LCW_pt20_etx_CentralReg, &b_MET_RefGamma_LCW_pt20_etx_CentralReg);
   fChain->SetBranchAddress("MET_RefGamma_LCW_pt20_ety_CentralReg", &MET_RefGamma_LCW_pt20_ety_CentralReg, &b_MET_RefGamma_LCW_pt20_ety_CentralReg);
   fChain->SetBranchAddress("MET_RefGamma_LCW_pt20_sumet_CentralReg", &MET_RefGamma_LCW_pt20_sumet_CentralReg, &b_MET_RefGamma_LCW_pt20_sumet_CentralReg);
   fChain->SetBranchAddress("MET_RefGamma_LCW_pt20_phi_CentralReg", &MET_RefGamma_LCW_pt20_phi_CentralReg, &b_MET_RefGamma_LCW_pt20_phi_CentralReg);
   fChain->SetBranchAddress("MET_RefGamma_LCW_pt20_etx_EndcapRegion", &MET_RefGamma_LCW_pt20_etx_EndcapRegion, &b_MET_RefGamma_LCW_pt20_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_RefGamma_LCW_pt20_ety_EndcapRegion", &MET_RefGamma_LCW_pt20_ety_EndcapRegion, &b_MET_RefGamma_LCW_pt20_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_RefGamma_LCW_pt20_sumet_EndcapRegion", &MET_RefGamma_LCW_pt20_sumet_EndcapRegion, &b_MET_RefGamma_LCW_pt20_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_RefGamma_LCW_pt20_phi_EndcapRegion", &MET_RefGamma_LCW_pt20_phi_EndcapRegion, &b_MET_RefGamma_LCW_pt20_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_RefGamma_LCW_pt20_etx_ForwardReg", &MET_RefGamma_LCW_pt20_etx_ForwardReg, &b_MET_RefGamma_LCW_pt20_etx_ForwardReg);
   fChain->SetBranchAddress("MET_RefGamma_LCW_pt20_ety_ForwardReg", &MET_RefGamma_LCW_pt20_ety_ForwardReg, &b_MET_RefGamma_LCW_pt20_ety_ForwardReg);
   fChain->SetBranchAddress("MET_RefGamma_LCW_pt20_sumet_ForwardReg", &MET_RefGamma_LCW_pt20_sumet_ForwardReg, &b_MET_RefGamma_LCW_pt20_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_RefGamma_LCW_pt20_phi_ForwardReg", &MET_RefGamma_LCW_pt20_phi_ForwardReg, &b_MET_RefGamma_LCW_pt20_phi_ForwardReg);
   fChain->SetBranchAddress("MET_RefEle_LCW_pt20_etx", &MET_RefEle_LCW_pt20_etx, &b_MET_RefEle_LCW_pt20_etx);
   fChain->SetBranchAddress("MET_RefEle_LCW_pt20_ety", &MET_RefEle_LCW_pt20_ety, &b_MET_RefEle_LCW_pt20_ety);
   fChain->SetBranchAddress("MET_RefEle_LCW_pt20_phi", &MET_RefEle_LCW_pt20_phi, &b_MET_RefEle_LCW_pt20_phi);
   fChain->SetBranchAddress("MET_RefEle_LCW_pt20_et", &MET_RefEle_LCW_pt20_et, &b_MET_RefEle_LCW_pt20_et);
   fChain->SetBranchAddress("MET_RefEle_LCW_pt20_sumet", &MET_RefEle_LCW_pt20_sumet, &b_MET_RefEle_LCW_pt20_sumet);
   fChain->SetBranchAddress("MET_RefEle_LCW_pt20_etx_CentralReg", &MET_RefEle_LCW_pt20_etx_CentralReg, &b_MET_RefEle_LCW_pt20_etx_CentralReg);
   fChain->SetBranchAddress("MET_RefEle_LCW_pt20_ety_CentralReg", &MET_RefEle_LCW_pt20_ety_CentralReg, &b_MET_RefEle_LCW_pt20_ety_CentralReg);
   fChain->SetBranchAddress("MET_RefEle_LCW_pt20_sumet_CentralReg", &MET_RefEle_LCW_pt20_sumet_CentralReg, &b_MET_RefEle_LCW_pt20_sumet_CentralReg);
   fChain->SetBranchAddress("MET_RefEle_LCW_pt20_phi_CentralReg", &MET_RefEle_LCW_pt20_phi_CentralReg, &b_MET_RefEle_LCW_pt20_phi_CentralReg);
   fChain->SetBranchAddress("MET_RefEle_LCW_pt20_etx_EndcapRegion", &MET_RefEle_LCW_pt20_etx_EndcapRegion, &b_MET_RefEle_LCW_pt20_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_RefEle_LCW_pt20_ety_EndcapRegion", &MET_RefEle_LCW_pt20_ety_EndcapRegion, &b_MET_RefEle_LCW_pt20_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_RefEle_LCW_pt20_sumet_EndcapRegion", &MET_RefEle_LCW_pt20_sumet_EndcapRegion, &b_MET_RefEle_LCW_pt20_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_RefEle_LCW_pt20_phi_EndcapRegion", &MET_RefEle_LCW_pt20_phi_EndcapRegion, &b_MET_RefEle_LCW_pt20_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_RefEle_LCW_pt20_etx_ForwardReg", &MET_RefEle_LCW_pt20_etx_ForwardReg, &b_MET_RefEle_LCW_pt20_etx_ForwardReg);
   fChain->SetBranchAddress("MET_RefEle_LCW_pt20_ety_ForwardReg", &MET_RefEle_LCW_pt20_ety_ForwardReg, &b_MET_RefEle_LCW_pt20_ety_ForwardReg);
   fChain->SetBranchAddress("MET_RefEle_LCW_pt20_sumet_ForwardReg", &MET_RefEle_LCW_pt20_sumet_ForwardReg, &b_MET_RefEle_LCW_pt20_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_RefEle_LCW_pt20_phi_ForwardReg", &MET_RefEle_LCW_pt20_phi_ForwardReg, &b_MET_RefEle_LCW_pt20_phi_ForwardReg);
   fChain->SetBranchAddress("MET_RefTau_LCW_pt20_etx", &MET_RefTau_LCW_pt20_etx, &b_MET_RefTau_LCW_pt20_etx);
   fChain->SetBranchAddress("MET_RefTau_LCW_pt20_ety", &MET_RefTau_LCW_pt20_ety, &b_MET_RefTau_LCW_pt20_ety);
   fChain->SetBranchAddress("MET_RefTau_LCW_pt20_phi", &MET_RefTau_LCW_pt20_phi, &b_MET_RefTau_LCW_pt20_phi);
   fChain->SetBranchAddress("MET_RefTau_LCW_pt20_et", &MET_RefTau_LCW_pt20_et, &b_MET_RefTau_LCW_pt20_et);
   fChain->SetBranchAddress("MET_RefTau_LCW_pt20_sumet", &MET_RefTau_LCW_pt20_sumet, &b_MET_RefTau_LCW_pt20_sumet);
   fChain->SetBranchAddress("MET_RefTau_LCW_pt20_etx_CentralReg", &MET_RefTau_LCW_pt20_etx_CentralReg, &b_MET_RefTau_LCW_pt20_etx_CentralReg);
   fChain->SetBranchAddress("MET_RefTau_LCW_pt20_ety_CentralReg", &MET_RefTau_LCW_pt20_ety_CentralReg, &b_MET_RefTau_LCW_pt20_ety_CentralReg);
   fChain->SetBranchAddress("MET_RefTau_LCW_pt20_sumet_CentralReg", &MET_RefTau_LCW_pt20_sumet_CentralReg, &b_MET_RefTau_LCW_pt20_sumet_CentralReg);
   fChain->SetBranchAddress("MET_RefTau_LCW_pt20_phi_CentralReg", &MET_RefTau_LCW_pt20_phi_CentralReg, &b_MET_RefTau_LCW_pt20_phi_CentralReg);
   fChain->SetBranchAddress("MET_RefTau_LCW_pt20_etx_EndcapRegion", &MET_RefTau_LCW_pt20_etx_EndcapRegion, &b_MET_RefTau_LCW_pt20_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_RefTau_LCW_pt20_ety_EndcapRegion", &MET_RefTau_LCW_pt20_ety_EndcapRegion, &b_MET_RefTau_LCW_pt20_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_RefTau_LCW_pt20_sumet_EndcapRegion", &MET_RefTau_LCW_pt20_sumet_EndcapRegion, &b_MET_RefTau_LCW_pt20_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_RefTau_LCW_pt20_phi_EndcapRegion", &MET_RefTau_LCW_pt20_phi_EndcapRegion, &b_MET_RefTau_LCW_pt20_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_RefTau_LCW_pt20_etx_ForwardReg", &MET_RefTau_LCW_pt20_etx_ForwardReg, &b_MET_RefTau_LCW_pt20_etx_ForwardReg);
   fChain->SetBranchAddress("MET_RefTau_LCW_pt20_ety_ForwardReg", &MET_RefTau_LCW_pt20_ety_ForwardReg, &b_MET_RefTau_LCW_pt20_ety_ForwardReg);
   fChain->SetBranchAddress("MET_RefTau_LCW_pt20_sumet_ForwardReg", &MET_RefTau_LCW_pt20_sumet_ForwardReg, &b_MET_RefTau_LCW_pt20_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_RefTau_LCW_pt20_phi_ForwardReg", &MET_RefTau_LCW_pt20_phi_ForwardReg, &b_MET_RefTau_LCW_pt20_phi_ForwardReg);
   fChain->SetBranchAddress("MET_RefJet_LCW_pt20_etx", &MET_RefJet_LCW_pt20_etx, &b_MET_RefJet_LCW_pt20_etx);
   fChain->SetBranchAddress("MET_RefJet_LCW_pt20_ety", &MET_RefJet_LCW_pt20_ety, &b_MET_RefJet_LCW_pt20_ety);
   fChain->SetBranchAddress("MET_RefJet_LCW_pt20_phi", &MET_RefJet_LCW_pt20_phi, &b_MET_RefJet_LCW_pt20_phi);
   fChain->SetBranchAddress("MET_RefJet_LCW_pt20_et", &MET_RefJet_LCW_pt20_et, &b_MET_RefJet_LCW_pt20_et);
   fChain->SetBranchAddress("MET_RefJet_LCW_pt20_sumet", &MET_RefJet_LCW_pt20_sumet, &b_MET_RefJet_LCW_pt20_sumet);
   fChain->SetBranchAddress("MET_RefJet_LCW_pt20_etx_CentralReg", &MET_RefJet_LCW_pt20_etx_CentralReg, &b_MET_RefJet_LCW_pt20_etx_CentralReg);
   fChain->SetBranchAddress("MET_RefJet_LCW_pt20_ety_CentralReg", &MET_RefJet_LCW_pt20_ety_CentralReg, &b_MET_RefJet_LCW_pt20_ety_CentralReg);
   fChain->SetBranchAddress("MET_RefJet_LCW_pt20_sumet_CentralReg", &MET_RefJet_LCW_pt20_sumet_CentralReg, &b_MET_RefJet_LCW_pt20_sumet_CentralReg);
   fChain->SetBranchAddress("MET_RefJet_LCW_pt20_phi_CentralReg", &MET_RefJet_LCW_pt20_phi_CentralReg, &b_MET_RefJet_LCW_pt20_phi_CentralReg);
   fChain->SetBranchAddress("MET_RefJet_LCW_pt20_etx_EndcapRegion", &MET_RefJet_LCW_pt20_etx_EndcapRegion, &b_MET_RefJet_LCW_pt20_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_RefJet_LCW_pt20_ety_EndcapRegion", &MET_RefJet_LCW_pt20_ety_EndcapRegion, &b_MET_RefJet_LCW_pt20_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_RefJet_LCW_pt20_sumet_EndcapRegion", &MET_RefJet_LCW_pt20_sumet_EndcapRegion, &b_MET_RefJet_LCW_pt20_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_RefJet_LCW_pt20_phi_EndcapRegion", &MET_RefJet_LCW_pt20_phi_EndcapRegion, &b_MET_RefJet_LCW_pt20_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_RefJet_LCW_pt20_etx_ForwardReg", &MET_RefJet_LCW_pt20_etx_ForwardReg, &b_MET_RefJet_LCW_pt20_etx_ForwardReg);
   fChain->SetBranchAddress("MET_RefJet_LCW_pt20_ety_ForwardReg", &MET_RefJet_LCW_pt20_ety_ForwardReg, &b_MET_RefJet_LCW_pt20_ety_ForwardReg);
   fChain->SetBranchAddress("MET_RefJet_LCW_pt20_sumet_ForwardReg", &MET_RefJet_LCW_pt20_sumet_ForwardReg, &b_MET_RefJet_LCW_pt20_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_RefJet_LCW_pt20_phi_ForwardReg", &MET_RefJet_LCW_pt20_phi_ForwardReg, &b_MET_RefJet_LCW_pt20_phi_ForwardReg);
   fChain->SetBranchAddress("MET_CellOut_LCW_pt20_etx", &MET_CellOut_LCW_pt20_etx, &b_MET_CellOut_LCW_pt20_etx);
   fChain->SetBranchAddress("MET_CellOut_LCW_pt20_ety", &MET_CellOut_LCW_pt20_ety, &b_MET_CellOut_LCW_pt20_ety);
   fChain->SetBranchAddress("MET_CellOut_LCW_pt20_phi", &MET_CellOut_LCW_pt20_phi, &b_MET_CellOut_LCW_pt20_phi);
   fChain->SetBranchAddress("MET_CellOut_LCW_pt20_et", &MET_CellOut_LCW_pt20_et, &b_MET_CellOut_LCW_pt20_et);
   fChain->SetBranchAddress("MET_CellOut_LCW_pt20_sumet", &MET_CellOut_LCW_pt20_sumet, &b_MET_CellOut_LCW_pt20_sumet);
   fChain->SetBranchAddress("MET_CellOut_LCW_pt20_etx_CentralReg", &MET_CellOut_LCW_pt20_etx_CentralReg, &b_MET_CellOut_LCW_pt20_etx_CentralReg);
   fChain->SetBranchAddress("MET_CellOut_LCW_pt20_ety_CentralReg", &MET_CellOut_LCW_pt20_ety_CentralReg, &b_MET_CellOut_LCW_pt20_ety_CentralReg);
   fChain->SetBranchAddress("MET_CellOut_LCW_pt20_sumet_CentralReg", &MET_CellOut_LCW_pt20_sumet_CentralReg, &b_MET_CellOut_LCW_pt20_sumet_CentralReg);
   fChain->SetBranchAddress("MET_CellOut_LCW_pt20_phi_CentralReg", &MET_CellOut_LCW_pt20_phi_CentralReg, &b_MET_CellOut_LCW_pt20_phi_CentralReg);
   fChain->SetBranchAddress("MET_CellOut_LCW_pt20_etx_EndcapRegion", &MET_CellOut_LCW_pt20_etx_EndcapRegion, &b_MET_CellOut_LCW_pt20_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_CellOut_LCW_pt20_ety_EndcapRegion", &MET_CellOut_LCW_pt20_ety_EndcapRegion, &b_MET_CellOut_LCW_pt20_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_CellOut_LCW_pt20_sumet_EndcapRegion", &MET_CellOut_LCW_pt20_sumet_EndcapRegion, &b_MET_CellOut_LCW_pt20_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_CellOut_LCW_pt20_phi_EndcapRegion", &MET_CellOut_LCW_pt20_phi_EndcapRegion, &b_MET_CellOut_LCW_pt20_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_CellOut_LCW_pt20_etx_ForwardReg", &MET_CellOut_LCW_pt20_etx_ForwardReg, &b_MET_CellOut_LCW_pt20_etx_ForwardReg);
   fChain->SetBranchAddress("MET_CellOut_LCW_pt20_ety_ForwardReg", &MET_CellOut_LCW_pt20_ety_ForwardReg, &b_MET_CellOut_LCW_pt20_ety_ForwardReg);
   fChain->SetBranchAddress("MET_CellOut_LCW_pt20_sumet_ForwardReg", &MET_CellOut_LCW_pt20_sumet_ForwardReg, &b_MET_CellOut_LCW_pt20_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_CellOut_LCW_pt20_phi_ForwardReg", &MET_CellOut_LCW_pt20_phi_ForwardReg, &b_MET_CellOut_LCW_pt20_phi_ForwardReg);
   fChain->SetBranchAddress("MET_Cryo_LCW_pt20_etx", &MET_Cryo_LCW_pt20_etx, &b_MET_Cryo_LCW_pt20_etx);
   fChain->SetBranchAddress("MET_Cryo_LCW_pt20_ety", &MET_Cryo_LCW_pt20_ety, &b_MET_Cryo_LCW_pt20_ety);
   fChain->SetBranchAddress("MET_Cryo_LCW_pt20_phi", &MET_Cryo_LCW_pt20_phi, &b_MET_Cryo_LCW_pt20_phi);
   fChain->SetBranchAddress("MET_Cryo_LCW_pt20_et", &MET_Cryo_LCW_pt20_et, &b_MET_Cryo_LCW_pt20_et);
   fChain->SetBranchAddress("MET_Cryo_LCW_pt20_sumet", &MET_Cryo_LCW_pt20_sumet, &b_MET_Cryo_LCW_pt20_sumet);
   fChain->SetBranchAddress("MET_Cryo_LCW_pt20_etx_CentralReg", &MET_Cryo_LCW_pt20_etx_CentralReg, &b_MET_Cryo_LCW_pt20_etx_CentralReg);
   fChain->SetBranchAddress("MET_Cryo_LCW_pt20_ety_CentralReg", &MET_Cryo_LCW_pt20_ety_CentralReg, &b_MET_Cryo_LCW_pt20_ety_CentralReg);
   fChain->SetBranchAddress("MET_Cryo_LCW_pt20_sumet_CentralReg", &MET_Cryo_LCW_pt20_sumet_CentralReg, &b_MET_Cryo_LCW_pt20_sumet_CentralReg);
   fChain->SetBranchAddress("MET_Cryo_LCW_pt20_phi_CentralReg", &MET_Cryo_LCW_pt20_phi_CentralReg, &b_MET_Cryo_LCW_pt20_phi_CentralReg);
   fChain->SetBranchAddress("MET_Cryo_LCW_pt20_etx_EndcapRegion", &MET_Cryo_LCW_pt20_etx_EndcapRegion, &b_MET_Cryo_LCW_pt20_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_Cryo_LCW_pt20_ety_EndcapRegion", &MET_Cryo_LCW_pt20_ety_EndcapRegion, &b_MET_Cryo_LCW_pt20_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_Cryo_LCW_pt20_sumet_EndcapRegion", &MET_Cryo_LCW_pt20_sumet_EndcapRegion, &b_MET_Cryo_LCW_pt20_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_Cryo_LCW_pt20_phi_EndcapRegion", &MET_Cryo_LCW_pt20_phi_EndcapRegion, &b_MET_Cryo_LCW_pt20_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_Cryo_LCW_pt20_etx_ForwardReg", &MET_Cryo_LCW_pt20_etx_ForwardReg, &b_MET_Cryo_LCW_pt20_etx_ForwardReg);
   fChain->SetBranchAddress("MET_Cryo_LCW_pt20_ety_ForwardReg", &MET_Cryo_LCW_pt20_ety_ForwardReg, &b_MET_Cryo_LCW_pt20_ety_ForwardReg);
   fChain->SetBranchAddress("MET_Cryo_LCW_pt20_sumet_ForwardReg", &MET_Cryo_LCW_pt20_sumet_ForwardReg, &b_MET_Cryo_LCW_pt20_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_Cryo_LCW_pt20_phi_ForwardReg", &MET_Cryo_LCW_pt20_phi_ForwardReg, &b_MET_Cryo_LCW_pt20_phi_ForwardReg);
   fChain->SetBranchAddress("MET_RefMuon_LCW_pt20_etx", &MET_RefMuon_LCW_pt20_etx, &b_MET_RefMuon_LCW_pt20_etx);
   fChain->SetBranchAddress("MET_RefMuon_LCW_pt20_ety", &MET_RefMuon_LCW_pt20_ety, &b_MET_RefMuon_LCW_pt20_ety);
   fChain->SetBranchAddress("MET_RefMuon_LCW_pt20_phi", &MET_RefMuon_LCW_pt20_phi, &b_MET_RefMuon_LCW_pt20_phi);
   fChain->SetBranchAddress("MET_RefMuon_LCW_pt20_et", &MET_RefMuon_LCW_pt20_et, &b_MET_RefMuon_LCW_pt20_et);
   fChain->SetBranchAddress("MET_RefMuon_LCW_pt20_sumet", &MET_RefMuon_LCW_pt20_sumet, &b_MET_RefMuon_LCW_pt20_sumet);
   fChain->SetBranchAddress("MET_RefMuon_Muid_LCW_pt20_etx", &MET_RefMuon_Muid_LCW_pt20_etx, &b_MET_RefMuon_Muid_LCW_pt20_etx);
   fChain->SetBranchAddress("MET_RefMuon_Muid_LCW_pt20_ety", &MET_RefMuon_Muid_LCW_pt20_ety, &b_MET_RefMuon_Muid_LCW_pt20_ety);
   fChain->SetBranchAddress("MET_RefMuon_Muid_LCW_pt20_phi", &MET_RefMuon_Muid_LCW_pt20_phi, &b_MET_RefMuon_Muid_LCW_pt20_phi);
   fChain->SetBranchAddress("MET_RefMuon_Muid_LCW_pt20_et", &MET_RefMuon_Muid_LCW_pt20_et, &b_MET_RefMuon_Muid_LCW_pt20_et);
   fChain->SetBranchAddress("MET_RefMuon_Muid_LCW_pt20_sumet", &MET_RefMuon_Muid_LCW_pt20_sumet, &b_MET_RefMuon_Muid_LCW_pt20_sumet);
   fChain->SetBranchAddress("MET_Muon_Isol_Muid_LCW_pt20_etx", &MET_Muon_Isol_Muid_LCW_pt20_etx, &b_MET_Muon_Isol_Muid_LCW_pt20_etx);
   fChain->SetBranchAddress("MET_Muon_Isol_Muid_LCW_pt20_ety", &MET_Muon_Isol_Muid_LCW_pt20_ety, &b_MET_Muon_Isol_Muid_LCW_pt20_ety);
   fChain->SetBranchAddress("MET_Muon_Isol_Muid_LCW_pt20_phi", &MET_Muon_Isol_Muid_LCW_pt20_phi, &b_MET_Muon_Isol_Muid_LCW_pt20_phi);
   fChain->SetBranchAddress("MET_Muon_Isol_Muid_LCW_pt20_et", &MET_Muon_Isol_Muid_LCW_pt20_et, &b_MET_Muon_Isol_Muid_LCW_pt20_et);
   fChain->SetBranchAddress("MET_Muon_Isol_Muid_LCW_pt20_sumet", &MET_Muon_Isol_Muid_LCW_pt20_sumet, &b_MET_Muon_Isol_Muid_LCW_pt20_sumet);
   fChain->SetBranchAddress("MET_Muon_NonIsol_Muid_LCW_pt20_etx", &MET_Muon_NonIsol_Muid_LCW_pt20_etx, &b_MET_Muon_NonIsol_Muid_LCW_pt20_etx);
   fChain->SetBranchAddress("MET_Muon_NonIsol_Muid_LCW_pt20_ety", &MET_Muon_NonIsol_Muid_LCW_pt20_ety, &b_MET_Muon_NonIsol_Muid_LCW_pt20_ety);
   fChain->SetBranchAddress("MET_Muon_NonIsol_Muid_LCW_pt20_phi", &MET_Muon_NonIsol_Muid_LCW_pt20_phi, &b_MET_Muon_NonIsol_Muid_LCW_pt20_phi);
   fChain->SetBranchAddress("MET_Muon_NonIsol_Muid_LCW_pt20_et", &MET_Muon_NonIsol_Muid_LCW_pt20_et, &b_MET_Muon_NonIsol_Muid_LCW_pt20_et);
   fChain->SetBranchAddress("MET_Muon_NonIsol_Muid_LCW_pt20_sumet", &MET_Muon_NonIsol_Muid_LCW_pt20_sumet, &b_MET_Muon_NonIsol_Muid_LCW_pt20_sumet);
   fChain->SetBranchAddress("MET_Muon_Total_Muid_LCW_pt20_etx", &MET_Muon_Total_Muid_LCW_pt20_etx, &b_MET_Muon_Total_Muid_LCW_pt20_etx);
   fChain->SetBranchAddress("MET_Muon_Total_Muid_LCW_pt20_ety", &MET_Muon_Total_Muid_LCW_pt20_ety, &b_MET_Muon_Total_Muid_LCW_pt20_ety);
   fChain->SetBranchAddress("MET_Muon_Total_Muid_LCW_pt20_phi", &MET_Muon_Total_Muid_LCW_pt20_phi, &b_MET_Muon_Total_Muid_LCW_pt20_phi);
   fChain->SetBranchAddress("MET_Muon_Total_Muid_LCW_pt20_et", &MET_Muon_Total_Muid_LCW_pt20_et, &b_MET_Muon_Total_Muid_LCW_pt20_et);
   fChain->SetBranchAddress("MET_Muon_Total_Muid_LCW_pt20_sumet", &MET_Muon_Total_Muid_LCW_pt20_sumet, &b_MET_Muon_Total_Muid_LCW_pt20_sumet);
   fChain->SetBranchAddress("MET_RefMuon_Track_LCW_pt20_etx", &MET_RefMuon_Track_LCW_pt20_etx, &b_MET_RefMuon_Track_LCW_pt20_etx);
   fChain->SetBranchAddress("MET_RefMuon_Track_LCW_pt20_ety", &MET_RefMuon_Track_LCW_pt20_ety, &b_MET_RefMuon_Track_LCW_pt20_ety);
   fChain->SetBranchAddress("MET_RefMuon_Track_LCW_pt20_phi", &MET_RefMuon_Track_LCW_pt20_phi, &b_MET_RefMuon_Track_LCW_pt20_phi);
   fChain->SetBranchAddress("MET_RefMuon_Track_LCW_pt20_et", &MET_RefMuon_Track_LCW_pt20_et, &b_MET_RefMuon_Track_LCW_pt20_et);
   fChain->SetBranchAddress("MET_RefMuon_Track_LCW_pt20_sumet", &MET_RefMuon_Track_LCW_pt20_sumet, &b_MET_RefMuon_Track_LCW_pt20_sumet);
   fChain->SetBranchAddress("MET_RefMuon_Track_Muid_LCW_pt20_etx", &MET_RefMuon_Track_Muid_LCW_pt20_etx, &b_MET_RefMuon_Track_Muid_LCW_pt20_etx);
   fChain->SetBranchAddress("MET_RefMuon_Track_Muid_LCW_pt20_ety", &MET_RefMuon_Track_Muid_LCW_pt20_ety, &b_MET_RefMuon_Track_Muid_LCW_pt20_ety);
   fChain->SetBranchAddress("MET_RefMuon_Track_Muid_LCW_pt20_phi", &MET_RefMuon_Track_Muid_LCW_pt20_phi, &b_MET_RefMuon_Track_Muid_LCW_pt20_phi);
   fChain->SetBranchAddress("MET_RefMuon_Track_Muid_LCW_pt20_et", &MET_RefMuon_Track_Muid_LCW_pt20_et, &b_MET_RefMuon_Track_Muid_LCW_pt20_et);
   fChain->SetBranchAddress("MET_RefMuon_Track_Muid_LCW_pt20_sumet", &MET_RefMuon_Track_Muid_LCW_pt20_sumet, &b_MET_RefMuon_Track_Muid_LCW_pt20_sumet);
   fChain->SetBranchAddress("MET_RefFinal_New_etx", &MET_RefFinal_New_etx, &b_MET_RefFinal_New_etx);
   fChain->SetBranchAddress("MET_RefFinal_New_ety", &MET_RefFinal_New_ety, &b_MET_RefFinal_New_ety);
   fChain->SetBranchAddress("MET_RefFinal_New_phi", &MET_RefFinal_New_phi, &b_MET_RefFinal_New_phi);
   fChain->SetBranchAddress("MET_RefFinal_New_et", &MET_RefFinal_New_et, &b_MET_RefFinal_New_et);
   fChain->SetBranchAddress("MET_RefFinal_New_sumet", &MET_RefFinal_New_sumet, &b_MET_RefFinal_New_sumet);
   fChain->SetBranchAddress("MET_RefFinal_New_etx_CentralReg", &MET_RefFinal_New_etx_CentralReg, &b_MET_RefFinal_New_etx_CentralReg);
   fChain->SetBranchAddress("MET_RefFinal_New_ety_CentralReg", &MET_RefFinal_New_ety_CentralReg, &b_MET_RefFinal_New_ety_CentralReg);
   fChain->SetBranchAddress("MET_RefFinal_New_sumet_CentralReg", &MET_RefFinal_New_sumet_CentralReg, &b_MET_RefFinal_New_sumet_CentralReg);
   fChain->SetBranchAddress("MET_RefFinal_New_phi_CentralReg", &MET_RefFinal_New_phi_CentralReg, &b_MET_RefFinal_New_phi_CentralReg);
   fChain->SetBranchAddress("MET_RefFinal_New_etx_EndcapRegion", &MET_RefFinal_New_etx_EndcapRegion, &b_MET_RefFinal_New_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_RefFinal_New_ety_EndcapRegion", &MET_RefFinal_New_ety_EndcapRegion, &b_MET_RefFinal_New_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_RefFinal_New_sumet_EndcapRegion", &MET_RefFinal_New_sumet_EndcapRegion, &b_MET_RefFinal_New_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_RefFinal_New_phi_EndcapRegion", &MET_RefFinal_New_phi_EndcapRegion, &b_MET_RefFinal_New_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_RefFinal_New_etx_ForwardReg", &MET_RefFinal_New_etx_ForwardReg, &b_MET_RefFinal_New_etx_ForwardReg);
   fChain->SetBranchAddress("MET_RefFinal_New_ety_ForwardReg", &MET_RefFinal_New_ety_ForwardReg, &b_MET_RefFinal_New_ety_ForwardReg);
   fChain->SetBranchAddress("MET_RefFinal_New_sumet_ForwardReg", &MET_RefFinal_New_sumet_ForwardReg, &b_MET_RefFinal_New_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_RefFinal_New_phi_ForwardReg", &MET_RefFinal_New_phi_ForwardReg, &b_MET_RefFinal_New_phi_ForwardReg);
   fChain->SetBranchAddress("MET_RefGamma_New_etx", &MET_RefGamma_New_etx, &b_MET_RefGamma_New_etx);
   fChain->SetBranchAddress("MET_RefGamma_New_ety", &MET_RefGamma_New_ety, &b_MET_RefGamma_New_ety);
   fChain->SetBranchAddress("MET_RefGamma_New_phi", &MET_RefGamma_New_phi, &b_MET_RefGamma_New_phi);
   fChain->SetBranchAddress("MET_RefGamma_New_et", &MET_RefGamma_New_et, &b_MET_RefGamma_New_et);
   fChain->SetBranchAddress("MET_RefGamma_New_sumet", &MET_RefGamma_New_sumet, &b_MET_RefGamma_New_sumet);
   fChain->SetBranchAddress("MET_RefGamma_New_etx_CentralReg", &MET_RefGamma_New_etx_CentralReg, &b_MET_RefGamma_New_etx_CentralReg);
   fChain->SetBranchAddress("MET_RefGamma_New_ety_CentralReg", &MET_RefGamma_New_ety_CentralReg, &b_MET_RefGamma_New_ety_CentralReg);
   fChain->SetBranchAddress("MET_RefGamma_New_sumet_CentralReg", &MET_RefGamma_New_sumet_CentralReg, &b_MET_RefGamma_New_sumet_CentralReg);
   fChain->SetBranchAddress("MET_RefGamma_New_phi_CentralReg", &MET_RefGamma_New_phi_CentralReg, &b_MET_RefGamma_New_phi_CentralReg);
   fChain->SetBranchAddress("MET_RefGamma_New_etx_EndcapRegion", &MET_RefGamma_New_etx_EndcapRegion, &b_MET_RefGamma_New_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_RefGamma_New_ety_EndcapRegion", &MET_RefGamma_New_ety_EndcapRegion, &b_MET_RefGamma_New_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_RefGamma_New_sumet_EndcapRegion", &MET_RefGamma_New_sumet_EndcapRegion, &b_MET_RefGamma_New_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_RefGamma_New_phi_EndcapRegion", &MET_RefGamma_New_phi_EndcapRegion, &b_MET_RefGamma_New_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_RefGamma_New_etx_ForwardReg", &MET_RefGamma_New_etx_ForwardReg, &b_MET_RefGamma_New_etx_ForwardReg);
   fChain->SetBranchAddress("MET_RefGamma_New_ety_ForwardReg", &MET_RefGamma_New_ety_ForwardReg, &b_MET_RefGamma_New_ety_ForwardReg);
   fChain->SetBranchAddress("MET_RefGamma_New_sumet_ForwardReg", &MET_RefGamma_New_sumet_ForwardReg, &b_MET_RefGamma_New_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_RefGamma_New_phi_ForwardReg", &MET_RefGamma_New_phi_ForwardReg, &b_MET_RefGamma_New_phi_ForwardReg);
   fChain->SetBranchAddress("MET_RefEle_New_etx", &MET_RefEle_New_etx, &b_MET_RefEle_New_etx);
   fChain->SetBranchAddress("MET_RefEle_New_ety", &MET_RefEle_New_ety, &b_MET_RefEle_New_ety);
   fChain->SetBranchAddress("MET_RefEle_New_phi", &MET_RefEle_New_phi, &b_MET_RefEle_New_phi);
   fChain->SetBranchAddress("MET_RefEle_New_et", &MET_RefEle_New_et, &b_MET_RefEle_New_et);
   fChain->SetBranchAddress("MET_RefEle_New_sumet", &MET_RefEle_New_sumet, &b_MET_RefEle_New_sumet);
   fChain->SetBranchAddress("MET_RefEle_New_etx_CentralReg", &MET_RefEle_New_etx_CentralReg, &b_MET_RefEle_New_etx_CentralReg);
   fChain->SetBranchAddress("MET_RefEle_New_ety_CentralReg", &MET_RefEle_New_ety_CentralReg, &b_MET_RefEle_New_ety_CentralReg);
   fChain->SetBranchAddress("MET_RefEle_New_sumet_CentralReg", &MET_RefEle_New_sumet_CentralReg, &b_MET_RefEle_New_sumet_CentralReg);
   fChain->SetBranchAddress("MET_RefEle_New_phi_CentralReg", &MET_RefEle_New_phi_CentralReg, &b_MET_RefEle_New_phi_CentralReg);
   fChain->SetBranchAddress("MET_RefEle_New_etx_EndcapRegion", &MET_RefEle_New_etx_EndcapRegion, &b_MET_RefEle_New_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_RefEle_New_ety_EndcapRegion", &MET_RefEle_New_ety_EndcapRegion, &b_MET_RefEle_New_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_RefEle_New_sumet_EndcapRegion", &MET_RefEle_New_sumet_EndcapRegion, &b_MET_RefEle_New_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_RefEle_New_phi_EndcapRegion", &MET_RefEle_New_phi_EndcapRegion, &b_MET_RefEle_New_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_RefEle_New_etx_ForwardReg", &MET_RefEle_New_etx_ForwardReg, &b_MET_RefEle_New_etx_ForwardReg);
   fChain->SetBranchAddress("MET_RefEle_New_ety_ForwardReg", &MET_RefEle_New_ety_ForwardReg, &b_MET_RefEle_New_ety_ForwardReg);
   fChain->SetBranchAddress("MET_RefEle_New_sumet_ForwardReg", &MET_RefEle_New_sumet_ForwardReg, &b_MET_RefEle_New_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_RefEle_New_phi_ForwardReg", &MET_RefEle_New_phi_ForwardReg, &b_MET_RefEle_New_phi_ForwardReg);
   fChain->SetBranchAddress("MET_RefTau_New_etx", &MET_RefTau_New_etx, &b_MET_RefTau_New_etx);
   fChain->SetBranchAddress("MET_RefTau_New_ety", &MET_RefTau_New_ety, &b_MET_RefTau_New_ety);
   fChain->SetBranchAddress("MET_RefTau_New_phi", &MET_RefTau_New_phi, &b_MET_RefTau_New_phi);
   fChain->SetBranchAddress("MET_RefTau_New_et", &MET_RefTau_New_et, &b_MET_RefTau_New_et);
   fChain->SetBranchAddress("MET_RefTau_New_sumet", &MET_RefTau_New_sumet, &b_MET_RefTau_New_sumet);
   fChain->SetBranchAddress("MET_RefTau_New_etx_CentralReg", &MET_RefTau_New_etx_CentralReg, &b_MET_RefTau_New_etx_CentralReg);
   fChain->SetBranchAddress("MET_RefTau_New_ety_CentralReg", &MET_RefTau_New_ety_CentralReg, &b_MET_RefTau_New_ety_CentralReg);
   fChain->SetBranchAddress("MET_RefTau_New_sumet_CentralReg", &MET_RefTau_New_sumet_CentralReg, &b_MET_RefTau_New_sumet_CentralReg);
   fChain->SetBranchAddress("MET_RefTau_New_phi_CentralReg", &MET_RefTau_New_phi_CentralReg, &b_MET_RefTau_New_phi_CentralReg);
   fChain->SetBranchAddress("MET_RefTau_New_etx_EndcapRegion", &MET_RefTau_New_etx_EndcapRegion, &b_MET_RefTau_New_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_RefTau_New_ety_EndcapRegion", &MET_RefTau_New_ety_EndcapRegion, &b_MET_RefTau_New_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_RefTau_New_sumet_EndcapRegion", &MET_RefTau_New_sumet_EndcapRegion, &b_MET_RefTau_New_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_RefTau_New_phi_EndcapRegion", &MET_RefTau_New_phi_EndcapRegion, &b_MET_RefTau_New_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_RefTau_New_etx_ForwardReg", &MET_RefTau_New_etx_ForwardReg, &b_MET_RefTau_New_etx_ForwardReg);
   fChain->SetBranchAddress("MET_RefTau_New_ety_ForwardReg", &MET_RefTau_New_ety_ForwardReg, &b_MET_RefTau_New_ety_ForwardReg);
   fChain->SetBranchAddress("MET_RefTau_New_sumet_ForwardReg", &MET_RefTau_New_sumet_ForwardReg, &b_MET_RefTau_New_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_RefTau_New_phi_ForwardReg", &MET_RefTau_New_phi_ForwardReg, &b_MET_RefTau_New_phi_ForwardReg);
   fChain->SetBranchAddress("MET_RefJet_New_etx", &MET_RefJet_New_etx, &b_MET_RefJet_New_etx);
   fChain->SetBranchAddress("MET_RefJet_New_ety", &MET_RefJet_New_ety, &b_MET_RefJet_New_ety);
   fChain->SetBranchAddress("MET_RefJet_New_phi", &MET_RefJet_New_phi, &b_MET_RefJet_New_phi);
   fChain->SetBranchAddress("MET_RefJet_New_et", &MET_RefJet_New_et, &b_MET_RefJet_New_et);
   fChain->SetBranchAddress("MET_RefJet_New_sumet", &MET_RefJet_New_sumet, &b_MET_RefJet_New_sumet);
   fChain->SetBranchAddress("MET_RefJet_New_etx_CentralReg", &MET_RefJet_New_etx_CentralReg, &b_MET_RefJet_New_etx_CentralReg);
   fChain->SetBranchAddress("MET_RefJet_New_ety_CentralReg", &MET_RefJet_New_ety_CentralReg, &b_MET_RefJet_New_ety_CentralReg);
   fChain->SetBranchAddress("MET_RefJet_New_sumet_CentralReg", &MET_RefJet_New_sumet_CentralReg, &b_MET_RefJet_New_sumet_CentralReg);
   fChain->SetBranchAddress("MET_RefJet_New_phi_CentralReg", &MET_RefJet_New_phi_CentralReg, &b_MET_RefJet_New_phi_CentralReg);
   fChain->SetBranchAddress("MET_RefJet_New_etx_EndcapRegion", &MET_RefJet_New_etx_EndcapRegion, &b_MET_RefJet_New_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_RefJet_New_ety_EndcapRegion", &MET_RefJet_New_ety_EndcapRegion, &b_MET_RefJet_New_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_RefJet_New_sumet_EndcapRegion", &MET_RefJet_New_sumet_EndcapRegion, &b_MET_RefJet_New_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_RefJet_New_phi_EndcapRegion", &MET_RefJet_New_phi_EndcapRegion, &b_MET_RefJet_New_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_RefJet_New_etx_ForwardReg", &MET_RefJet_New_etx_ForwardReg, &b_MET_RefJet_New_etx_ForwardReg);
   fChain->SetBranchAddress("MET_RefJet_New_ety_ForwardReg", &MET_RefJet_New_ety_ForwardReg, &b_MET_RefJet_New_ety_ForwardReg);
   fChain->SetBranchAddress("MET_RefJet_New_sumet_ForwardReg", &MET_RefJet_New_sumet_ForwardReg, &b_MET_RefJet_New_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_RefJet_New_phi_ForwardReg", &MET_RefJet_New_phi_ForwardReg, &b_MET_RefJet_New_phi_ForwardReg);
   fChain->SetBranchAddress("MET_CellOut_New_etx", &MET_CellOut_New_etx, &b_MET_CellOut_New_etx);
   fChain->SetBranchAddress("MET_CellOut_New_ety", &MET_CellOut_New_ety, &b_MET_CellOut_New_ety);
   fChain->SetBranchAddress("MET_CellOut_New_phi", &MET_CellOut_New_phi, &b_MET_CellOut_New_phi);
   fChain->SetBranchAddress("MET_CellOut_New_et", &MET_CellOut_New_et, &b_MET_CellOut_New_et);
   fChain->SetBranchAddress("MET_CellOut_New_sumet", &MET_CellOut_New_sumet, &b_MET_CellOut_New_sumet);
   fChain->SetBranchAddress("MET_CellOut_New_etx_CentralReg", &MET_CellOut_New_etx_CentralReg, &b_MET_CellOut_New_etx_CentralReg);
   fChain->SetBranchAddress("MET_CellOut_New_ety_CentralReg", &MET_CellOut_New_ety_CentralReg, &b_MET_CellOut_New_ety_CentralReg);
   fChain->SetBranchAddress("MET_CellOut_New_sumet_CentralReg", &MET_CellOut_New_sumet_CentralReg, &b_MET_CellOut_New_sumet_CentralReg);
   fChain->SetBranchAddress("MET_CellOut_New_phi_CentralReg", &MET_CellOut_New_phi_CentralReg, &b_MET_CellOut_New_phi_CentralReg);
   fChain->SetBranchAddress("MET_CellOut_New_etx_EndcapRegion", &MET_CellOut_New_etx_EndcapRegion, &b_MET_CellOut_New_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_CellOut_New_ety_EndcapRegion", &MET_CellOut_New_ety_EndcapRegion, &b_MET_CellOut_New_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_CellOut_New_sumet_EndcapRegion", &MET_CellOut_New_sumet_EndcapRegion, &b_MET_CellOut_New_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_CellOut_New_phi_EndcapRegion", &MET_CellOut_New_phi_EndcapRegion, &b_MET_CellOut_New_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_CellOut_New_etx_ForwardReg", &MET_CellOut_New_etx_ForwardReg, &b_MET_CellOut_New_etx_ForwardReg);
   fChain->SetBranchAddress("MET_CellOut_New_ety_ForwardReg", &MET_CellOut_New_ety_ForwardReg, &b_MET_CellOut_New_ety_ForwardReg);
   fChain->SetBranchAddress("MET_CellOut_New_sumet_ForwardReg", &MET_CellOut_New_sumet_ForwardReg, &b_MET_CellOut_New_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_CellOut_New_phi_ForwardReg", &MET_CellOut_New_phi_ForwardReg, &b_MET_CellOut_New_phi_ForwardReg);
   fChain->SetBranchAddress("MET_Cryo_New_etx", &MET_Cryo_New_etx, &b_MET_Cryo_New_etx);
   fChain->SetBranchAddress("MET_Cryo_New_ety", &MET_Cryo_New_ety, &b_MET_Cryo_New_ety);
   fChain->SetBranchAddress("MET_Cryo_New_phi", &MET_Cryo_New_phi, &b_MET_Cryo_New_phi);
   fChain->SetBranchAddress("MET_Cryo_New_et", &MET_Cryo_New_et, &b_MET_Cryo_New_et);
   fChain->SetBranchAddress("MET_Cryo_New_sumet", &MET_Cryo_New_sumet, &b_MET_Cryo_New_sumet);
   fChain->SetBranchAddress("MET_Cryo_New_etx_CentralReg", &MET_Cryo_New_etx_CentralReg, &b_MET_Cryo_New_etx_CentralReg);
   fChain->SetBranchAddress("MET_Cryo_New_ety_CentralReg", &MET_Cryo_New_ety_CentralReg, &b_MET_Cryo_New_ety_CentralReg);
   fChain->SetBranchAddress("MET_Cryo_New_sumet_CentralReg", &MET_Cryo_New_sumet_CentralReg, &b_MET_Cryo_New_sumet_CentralReg);
   fChain->SetBranchAddress("MET_Cryo_New_phi_CentralReg", &MET_Cryo_New_phi_CentralReg, &b_MET_Cryo_New_phi_CentralReg);
   fChain->SetBranchAddress("MET_Cryo_New_etx_EndcapRegion", &MET_Cryo_New_etx_EndcapRegion, &b_MET_Cryo_New_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_Cryo_New_ety_EndcapRegion", &MET_Cryo_New_ety_EndcapRegion, &b_MET_Cryo_New_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_Cryo_New_sumet_EndcapRegion", &MET_Cryo_New_sumet_EndcapRegion, &b_MET_Cryo_New_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_Cryo_New_phi_EndcapRegion", &MET_Cryo_New_phi_EndcapRegion, &b_MET_Cryo_New_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_Cryo_New_etx_ForwardReg", &MET_Cryo_New_etx_ForwardReg, &b_MET_Cryo_New_etx_ForwardReg);
   fChain->SetBranchAddress("MET_Cryo_New_ety_ForwardReg", &MET_Cryo_New_ety_ForwardReg, &b_MET_Cryo_New_ety_ForwardReg);
   fChain->SetBranchAddress("MET_Cryo_New_sumet_ForwardReg", &MET_Cryo_New_sumet_ForwardReg, &b_MET_Cryo_New_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_Cryo_New_phi_ForwardReg", &MET_Cryo_New_phi_ForwardReg, &b_MET_Cryo_New_phi_ForwardReg);
   fChain->SetBranchAddress("MET_RefFinal_New_em_etx", &MET_RefFinal_New_em_etx, &b_MET_RefFinal_New_em_etx);
   fChain->SetBranchAddress("MET_RefFinal_New_em_ety", &MET_RefFinal_New_em_ety, &b_MET_RefFinal_New_em_ety);
   fChain->SetBranchAddress("MET_RefFinal_New_em_phi", &MET_RefFinal_New_em_phi, &b_MET_RefFinal_New_em_phi);
   fChain->SetBranchAddress("MET_RefFinal_New_em_et", &MET_RefFinal_New_em_et, &b_MET_RefFinal_New_em_et);
   fChain->SetBranchAddress("MET_RefFinal_New_em_sumet", &MET_RefFinal_New_em_sumet, &b_MET_RefFinal_New_em_sumet);
   fChain->SetBranchAddress("MET_RefFinal_New_em_etx_CentralReg", &MET_RefFinal_New_em_etx_CentralReg, &b_MET_RefFinal_New_em_etx_CentralReg);
   fChain->SetBranchAddress("MET_RefFinal_New_em_ety_CentralReg", &MET_RefFinal_New_em_ety_CentralReg, &b_MET_RefFinal_New_em_ety_CentralReg);
   fChain->SetBranchAddress("MET_RefFinal_New_em_sumet_CentralReg", &MET_RefFinal_New_em_sumet_CentralReg, &b_MET_RefFinal_New_em_sumet_CentralReg);
   fChain->SetBranchAddress("MET_RefFinal_New_em_phi_CentralReg", &MET_RefFinal_New_em_phi_CentralReg, &b_MET_RefFinal_New_em_phi_CentralReg);
   fChain->SetBranchAddress("MET_RefFinal_New_em_etx_EndcapRegion", &MET_RefFinal_New_em_etx_EndcapRegion, &b_MET_RefFinal_New_em_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_RefFinal_New_em_ety_EndcapRegion", &MET_RefFinal_New_em_ety_EndcapRegion, &b_MET_RefFinal_New_em_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_RefFinal_New_em_sumet_EndcapRegion", &MET_RefFinal_New_em_sumet_EndcapRegion, &b_MET_RefFinal_New_em_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_RefFinal_New_em_phi_EndcapRegion", &MET_RefFinal_New_em_phi_EndcapRegion, &b_MET_RefFinal_New_em_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_RefFinal_New_em_etx_ForwardReg", &MET_RefFinal_New_em_etx_ForwardReg, &b_MET_RefFinal_New_em_etx_ForwardReg);
   fChain->SetBranchAddress("MET_RefFinal_New_em_ety_ForwardReg", &MET_RefFinal_New_em_ety_ForwardReg, &b_MET_RefFinal_New_em_ety_ForwardReg);
   fChain->SetBranchAddress("MET_RefFinal_New_em_sumet_ForwardReg", &MET_RefFinal_New_em_sumet_ForwardReg, &b_MET_RefFinal_New_em_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_RefFinal_New_em_phi_ForwardReg", &MET_RefFinal_New_em_phi_ForwardReg, &b_MET_RefFinal_New_em_phi_ForwardReg);
   fChain->SetBranchAddress("MET_RefGamma_New_em_etx", &MET_RefGamma_New_em_etx, &b_MET_RefGamma_New_em_etx);
   fChain->SetBranchAddress("MET_RefGamma_New_em_ety", &MET_RefGamma_New_em_ety, &b_MET_RefGamma_New_em_ety);
   fChain->SetBranchAddress("MET_RefGamma_New_em_phi", &MET_RefGamma_New_em_phi, &b_MET_RefGamma_New_em_phi);
   fChain->SetBranchAddress("MET_RefGamma_New_em_et", &MET_RefGamma_New_em_et, &b_MET_RefGamma_New_em_et);
   fChain->SetBranchAddress("MET_RefGamma_New_em_sumet", &MET_RefGamma_New_em_sumet, &b_MET_RefGamma_New_em_sumet);
   fChain->SetBranchAddress("MET_RefGamma_New_em_etx_CentralReg", &MET_RefGamma_New_em_etx_CentralReg, &b_MET_RefGamma_New_em_etx_CentralReg);
   fChain->SetBranchAddress("MET_RefGamma_New_em_ety_CentralReg", &MET_RefGamma_New_em_ety_CentralReg, &b_MET_RefGamma_New_em_ety_CentralReg);
   fChain->SetBranchAddress("MET_RefGamma_New_em_sumet_CentralReg", &MET_RefGamma_New_em_sumet_CentralReg, &b_MET_RefGamma_New_em_sumet_CentralReg);
   fChain->SetBranchAddress("MET_RefGamma_New_em_phi_CentralReg", &MET_RefGamma_New_em_phi_CentralReg, &b_MET_RefGamma_New_em_phi_CentralReg);
   fChain->SetBranchAddress("MET_RefGamma_New_em_etx_EndcapRegion", &MET_RefGamma_New_em_etx_EndcapRegion, &b_MET_RefGamma_New_em_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_RefGamma_New_em_ety_EndcapRegion", &MET_RefGamma_New_em_ety_EndcapRegion, &b_MET_RefGamma_New_em_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_RefGamma_New_em_sumet_EndcapRegion", &MET_RefGamma_New_em_sumet_EndcapRegion, &b_MET_RefGamma_New_em_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_RefGamma_New_em_phi_EndcapRegion", &MET_RefGamma_New_em_phi_EndcapRegion, &b_MET_RefGamma_New_em_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_RefGamma_New_em_etx_ForwardReg", &MET_RefGamma_New_em_etx_ForwardReg, &b_MET_RefGamma_New_em_etx_ForwardReg);
   fChain->SetBranchAddress("MET_RefGamma_New_em_ety_ForwardReg", &MET_RefGamma_New_em_ety_ForwardReg, &b_MET_RefGamma_New_em_ety_ForwardReg);
   fChain->SetBranchAddress("MET_RefGamma_New_em_sumet_ForwardReg", &MET_RefGamma_New_em_sumet_ForwardReg, &b_MET_RefGamma_New_em_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_RefGamma_New_em_phi_ForwardReg", &MET_RefGamma_New_em_phi_ForwardReg, &b_MET_RefGamma_New_em_phi_ForwardReg);
   fChain->SetBranchAddress("MET_RefEle_New_em_etx", &MET_RefEle_New_em_etx, &b_MET_RefEle_New_em_etx);
   fChain->SetBranchAddress("MET_RefEle_New_em_ety", &MET_RefEle_New_em_ety, &b_MET_RefEle_New_em_ety);
   fChain->SetBranchAddress("MET_RefEle_New_em_phi", &MET_RefEle_New_em_phi, &b_MET_RefEle_New_em_phi);
   fChain->SetBranchAddress("MET_RefEle_New_em_et", &MET_RefEle_New_em_et, &b_MET_RefEle_New_em_et);
   fChain->SetBranchAddress("MET_RefEle_New_em_sumet", &MET_RefEle_New_em_sumet, &b_MET_RefEle_New_em_sumet);
   fChain->SetBranchAddress("MET_RefEle_New_em_etx_CentralReg", &MET_RefEle_New_em_etx_CentralReg, &b_MET_RefEle_New_em_etx_CentralReg);
   fChain->SetBranchAddress("MET_RefEle_New_em_ety_CentralReg", &MET_RefEle_New_em_ety_CentralReg, &b_MET_RefEle_New_em_ety_CentralReg);
   fChain->SetBranchAddress("MET_RefEle_New_em_sumet_CentralReg", &MET_RefEle_New_em_sumet_CentralReg, &b_MET_RefEle_New_em_sumet_CentralReg);
   fChain->SetBranchAddress("MET_RefEle_New_em_phi_CentralReg", &MET_RefEle_New_em_phi_CentralReg, &b_MET_RefEle_New_em_phi_CentralReg);
   fChain->SetBranchAddress("MET_RefEle_New_em_etx_EndcapRegion", &MET_RefEle_New_em_etx_EndcapRegion, &b_MET_RefEle_New_em_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_RefEle_New_em_ety_EndcapRegion", &MET_RefEle_New_em_ety_EndcapRegion, &b_MET_RefEle_New_em_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_RefEle_New_em_sumet_EndcapRegion", &MET_RefEle_New_em_sumet_EndcapRegion, &b_MET_RefEle_New_em_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_RefEle_New_em_phi_EndcapRegion", &MET_RefEle_New_em_phi_EndcapRegion, &b_MET_RefEle_New_em_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_RefEle_New_em_etx_ForwardReg", &MET_RefEle_New_em_etx_ForwardReg, &b_MET_RefEle_New_em_etx_ForwardReg);
   fChain->SetBranchAddress("MET_RefEle_New_em_ety_ForwardReg", &MET_RefEle_New_em_ety_ForwardReg, &b_MET_RefEle_New_em_ety_ForwardReg);
   fChain->SetBranchAddress("MET_RefEle_New_em_sumet_ForwardReg", &MET_RefEle_New_em_sumet_ForwardReg, &b_MET_RefEle_New_em_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_RefEle_New_em_phi_ForwardReg", &MET_RefEle_New_em_phi_ForwardReg, &b_MET_RefEle_New_em_phi_ForwardReg);
   fChain->SetBranchAddress("MET_RefTau_New_em_etx", &MET_RefTau_New_em_etx, &b_MET_RefTau_New_em_etx);
   fChain->SetBranchAddress("MET_RefTau_New_em_ety", &MET_RefTau_New_em_ety, &b_MET_RefTau_New_em_ety);
   fChain->SetBranchAddress("MET_RefTau_New_em_phi", &MET_RefTau_New_em_phi, &b_MET_RefTau_New_em_phi);
   fChain->SetBranchAddress("MET_RefTau_New_em_et", &MET_RefTau_New_em_et, &b_MET_RefTau_New_em_et);
   fChain->SetBranchAddress("MET_RefTau_New_em_sumet", &MET_RefTau_New_em_sumet, &b_MET_RefTau_New_em_sumet);
   fChain->SetBranchAddress("MET_RefTau_New_em_etx_CentralReg", &MET_RefTau_New_em_etx_CentralReg, &b_MET_RefTau_New_em_etx_CentralReg);
   fChain->SetBranchAddress("MET_RefTau_New_em_ety_CentralReg", &MET_RefTau_New_em_ety_CentralReg, &b_MET_RefTau_New_em_ety_CentralReg);
   fChain->SetBranchAddress("MET_RefTau_New_em_sumet_CentralReg", &MET_RefTau_New_em_sumet_CentralReg, &b_MET_RefTau_New_em_sumet_CentralReg);
   fChain->SetBranchAddress("MET_RefTau_New_em_phi_CentralReg", &MET_RefTau_New_em_phi_CentralReg, &b_MET_RefTau_New_em_phi_CentralReg);
   fChain->SetBranchAddress("MET_RefTau_New_em_etx_EndcapRegion", &MET_RefTau_New_em_etx_EndcapRegion, &b_MET_RefTau_New_em_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_RefTau_New_em_ety_EndcapRegion", &MET_RefTau_New_em_ety_EndcapRegion, &b_MET_RefTau_New_em_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_RefTau_New_em_sumet_EndcapRegion", &MET_RefTau_New_em_sumet_EndcapRegion, &b_MET_RefTau_New_em_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_RefTau_New_em_phi_EndcapRegion", &MET_RefTau_New_em_phi_EndcapRegion, &b_MET_RefTau_New_em_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_RefTau_New_em_etx_ForwardReg", &MET_RefTau_New_em_etx_ForwardReg, &b_MET_RefTau_New_em_etx_ForwardReg);
   fChain->SetBranchAddress("MET_RefTau_New_em_ety_ForwardReg", &MET_RefTau_New_em_ety_ForwardReg, &b_MET_RefTau_New_em_ety_ForwardReg);
   fChain->SetBranchAddress("MET_RefTau_New_em_sumet_ForwardReg", &MET_RefTau_New_em_sumet_ForwardReg, &b_MET_RefTau_New_em_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_RefTau_New_em_phi_ForwardReg", &MET_RefTau_New_em_phi_ForwardReg, &b_MET_RefTau_New_em_phi_ForwardReg);
   fChain->SetBranchAddress("MET_RefJet_New_em_etx", &MET_RefJet_New_em_etx, &b_MET_RefJet_New_em_etx);
   fChain->SetBranchAddress("MET_RefJet_New_em_ety", &MET_RefJet_New_em_ety, &b_MET_RefJet_New_em_ety);
   fChain->SetBranchAddress("MET_RefJet_New_em_phi", &MET_RefJet_New_em_phi, &b_MET_RefJet_New_em_phi);
   fChain->SetBranchAddress("MET_RefJet_New_em_et", &MET_RefJet_New_em_et, &b_MET_RefJet_New_em_et);
   fChain->SetBranchAddress("MET_RefJet_New_em_sumet", &MET_RefJet_New_em_sumet, &b_MET_RefJet_New_em_sumet);
   fChain->SetBranchAddress("MET_RefJet_New_em_etx_CentralReg", &MET_RefJet_New_em_etx_CentralReg, &b_MET_RefJet_New_em_etx_CentralReg);
   fChain->SetBranchAddress("MET_RefJet_New_em_ety_CentralReg", &MET_RefJet_New_em_ety_CentralReg, &b_MET_RefJet_New_em_ety_CentralReg);
   fChain->SetBranchAddress("MET_RefJet_New_em_sumet_CentralReg", &MET_RefJet_New_em_sumet_CentralReg, &b_MET_RefJet_New_em_sumet_CentralReg);
   fChain->SetBranchAddress("MET_RefJet_New_em_phi_CentralReg", &MET_RefJet_New_em_phi_CentralReg, &b_MET_RefJet_New_em_phi_CentralReg);
   fChain->SetBranchAddress("MET_RefJet_New_em_etx_EndcapRegion", &MET_RefJet_New_em_etx_EndcapRegion, &b_MET_RefJet_New_em_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_RefJet_New_em_ety_EndcapRegion", &MET_RefJet_New_em_ety_EndcapRegion, &b_MET_RefJet_New_em_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_RefJet_New_em_sumet_EndcapRegion", &MET_RefJet_New_em_sumet_EndcapRegion, &b_MET_RefJet_New_em_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_RefJet_New_em_phi_EndcapRegion", &MET_RefJet_New_em_phi_EndcapRegion, &b_MET_RefJet_New_em_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_RefJet_New_em_etx_ForwardReg", &MET_RefJet_New_em_etx_ForwardReg, &b_MET_RefJet_New_em_etx_ForwardReg);
   fChain->SetBranchAddress("MET_RefJet_New_em_ety_ForwardReg", &MET_RefJet_New_em_ety_ForwardReg, &b_MET_RefJet_New_em_ety_ForwardReg);
   fChain->SetBranchAddress("MET_RefJet_New_em_sumet_ForwardReg", &MET_RefJet_New_em_sumet_ForwardReg, &b_MET_RefJet_New_em_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_RefJet_New_em_phi_ForwardReg", &MET_RefJet_New_em_phi_ForwardReg, &b_MET_RefJet_New_em_phi_ForwardReg);
   fChain->SetBranchAddress("MET_CellOut_New_em_etx", &MET_CellOut_New_em_etx, &b_MET_CellOut_New_em_etx);
   fChain->SetBranchAddress("MET_CellOut_New_em_ety", &MET_CellOut_New_em_ety, &b_MET_CellOut_New_em_ety);
   fChain->SetBranchAddress("MET_CellOut_New_em_phi", &MET_CellOut_New_em_phi, &b_MET_CellOut_New_em_phi);
   fChain->SetBranchAddress("MET_CellOut_New_em_et", &MET_CellOut_New_em_et, &b_MET_CellOut_New_em_et);
   fChain->SetBranchAddress("MET_CellOut_New_em_sumet", &MET_CellOut_New_em_sumet, &b_MET_CellOut_New_em_sumet);
   fChain->SetBranchAddress("MET_CellOut_New_em_etx_CentralReg", &MET_CellOut_New_em_etx_CentralReg, &b_MET_CellOut_New_em_etx_CentralReg);
   fChain->SetBranchAddress("MET_CellOut_New_em_ety_CentralReg", &MET_CellOut_New_em_ety_CentralReg, &b_MET_CellOut_New_em_ety_CentralReg);
   fChain->SetBranchAddress("MET_CellOut_New_em_sumet_CentralReg", &MET_CellOut_New_em_sumet_CentralReg, &b_MET_CellOut_New_em_sumet_CentralReg);
   fChain->SetBranchAddress("MET_CellOut_New_em_phi_CentralReg", &MET_CellOut_New_em_phi_CentralReg, &b_MET_CellOut_New_em_phi_CentralReg);
   fChain->SetBranchAddress("MET_CellOut_New_em_etx_EndcapRegion", &MET_CellOut_New_em_etx_EndcapRegion, &b_MET_CellOut_New_em_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_CellOut_New_em_ety_EndcapRegion", &MET_CellOut_New_em_ety_EndcapRegion, &b_MET_CellOut_New_em_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_CellOut_New_em_sumet_EndcapRegion", &MET_CellOut_New_em_sumet_EndcapRegion, &b_MET_CellOut_New_em_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_CellOut_New_em_phi_EndcapRegion", &MET_CellOut_New_em_phi_EndcapRegion, &b_MET_CellOut_New_em_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_CellOut_New_em_etx_ForwardReg", &MET_CellOut_New_em_etx_ForwardReg, &b_MET_CellOut_New_em_etx_ForwardReg);
   fChain->SetBranchAddress("MET_CellOut_New_em_ety_ForwardReg", &MET_CellOut_New_em_ety_ForwardReg, &b_MET_CellOut_New_em_ety_ForwardReg);
   fChain->SetBranchAddress("MET_CellOut_New_em_sumet_ForwardReg", &MET_CellOut_New_em_sumet_ForwardReg, &b_MET_CellOut_New_em_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_CellOut_New_em_phi_ForwardReg", &MET_CellOut_New_em_phi_ForwardReg, &b_MET_CellOut_New_em_phi_ForwardReg);
   fChain->SetBranchAddress("MET_Cryo_New_em_etx", &MET_Cryo_New_em_etx, &b_MET_Cryo_New_em_etx);
   fChain->SetBranchAddress("MET_Cryo_New_em_ety", &MET_Cryo_New_em_ety, &b_MET_Cryo_New_em_ety);
   fChain->SetBranchAddress("MET_Cryo_New_em_phi", &MET_Cryo_New_em_phi, &b_MET_Cryo_New_em_phi);
   fChain->SetBranchAddress("MET_Cryo_New_em_et", &MET_Cryo_New_em_et, &b_MET_Cryo_New_em_et);
   fChain->SetBranchAddress("MET_Cryo_New_em_sumet", &MET_Cryo_New_em_sumet, &b_MET_Cryo_New_em_sumet);
   fChain->SetBranchAddress("MET_Cryo_New_em_etx_CentralReg", &MET_Cryo_New_em_etx_CentralReg, &b_MET_Cryo_New_em_etx_CentralReg);
   fChain->SetBranchAddress("MET_Cryo_New_em_ety_CentralReg", &MET_Cryo_New_em_ety_CentralReg, &b_MET_Cryo_New_em_ety_CentralReg);
   fChain->SetBranchAddress("MET_Cryo_New_em_sumet_CentralReg", &MET_Cryo_New_em_sumet_CentralReg, &b_MET_Cryo_New_em_sumet_CentralReg);
   fChain->SetBranchAddress("MET_Cryo_New_em_phi_CentralReg", &MET_Cryo_New_em_phi_CentralReg, &b_MET_Cryo_New_em_phi_CentralReg);
   fChain->SetBranchAddress("MET_Cryo_New_em_etx_EndcapRegion", &MET_Cryo_New_em_etx_EndcapRegion, &b_MET_Cryo_New_em_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_Cryo_New_em_ety_EndcapRegion", &MET_Cryo_New_em_ety_EndcapRegion, &b_MET_Cryo_New_em_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_Cryo_New_em_sumet_EndcapRegion", &MET_Cryo_New_em_sumet_EndcapRegion, &b_MET_Cryo_New_em_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_Cryo_New_em_phi_EndcapRegion", &MET_Cryo_New_em_phi_EndcapRegion, &b_MET_Cryo_New_em_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_Cryo_New_em_etx_ForwardReg", &MET_Cryo_New_em_etx_ForwardReg, &b_MET_Cryo_New_em_etx_ForwardReg);
   fChain->SetBranchAddress("MET_Cryo_New_em_ety_ForwardReg", &MET_Cryo_New_em_ety_ForwardReg, &b_MET_Cryo_New_em_ety_ForwardReg);
   fChain->SetBranchAddress("MET_Cryo_New_em_sumet_ForwardReg", &MET_Cryo_New_em_sumet_ForwardReg, &b_MET_Cryo_New_em_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_Cryo_New_em_phi_ForwardReg", &MET_Cryo_New_em_phi_ForwardReg, &b_MET_Cryo_New_em_phi_ForwardReg);
   fChain->SetBranchAddress("MET_RefFinal_LCW_CB_eflow_etx", &MET_RefFinal_LCW_CB_eflow_etx, &b_MET_RefFinal_LCW_CB_eflow_etx);
   fChain->SetBranchAddress("MET_RefFinal_LCW_CB_eflow_ety", &MET_RefFinal_LCW_CB_eflow_ety, &b_MET_RefFinal_LCW_CB_eflow_ety);
   fChain->SetBranchAddress("MET_RefFinal_LCW_CB_eflow_phi", &MET_RefFinal_LCW_CB_eflow_phi, &b_MET_RefFinal_LCW_CB_eflow_phi);
   fChain->SetBranchAddress("MET_RefFinal_LCW_CB_eflow_et", &MET_RefFinal_LCW_CB_eflow_et, &b_MET_RefFinal_LCW_CB_eflow_et);
   fChain->SetBranchAddress("MET_RefFinal_LCW_CB_eflow_sumet", &MET_RefFinal_LCW_CB_eflow_sumet, &b_MET_RefFinal_LCW_CB_eflow_sumet);
   fChain->SetBranchAddress("MET_RefFinal_LCW_CB_eflow_etx_CentralReg", &MET_RefFinal_LCW_CB_eflow_etx_CentralReg, &b_MET_RefFinal_LCW_CB_eflow_etx_CentralReg);
   fChain->SetBranchAddress("MET_RefFinal_LCW_CB_eflow_ety_CentralReg", &MET_RefFinal_LCW_CB_eflow_ety_CentralReg, &b_MET_RefFinal_LCW_CB_eflow_ety_CentralReg);
   fChain->SetBranchAddress("MET_RefFinal_LCW_CB_eflow_sumet_CentralReg", &MET_RefFinal_LCW_CB_eflow_sumet_CentralReg, &b_MET_RefFinal_LCW_CB_eflow_sumet_CentralReg);
   fChain->SetBranchAddress("MET_RefFinal_LCW_CB_eflow_phi_CentralReg", &MET_RefFinal_LCW_CB_eflow_phi_CentralReg, &b_MET_RefFinal_LCW_CB_eflow_phi_CentralReg);
   fChain->SetBranchAddress("MET_RefFinal_LCW_CB_eflow_etx_EndcapRegion", &MET_RefFinal_LCW_CB_eflow_etx_EndcapRegion, &b_MET_RefFinal_LCW_CB_eflow_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_RefFinal_LCW_CB_eflow_ety_EndcapRegion", &MET_RefFinal_LCW_CB_eflow_ety_EndcapRegion, &b_MET_RefFinal_LCW_CB_eflow_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_RefFinal_LCW_CB_eflow_sumet_EndcapRegion", &MET_RefFinal_LCW_CB_eflow_sumet_EndcapRegion, &b_MET_RefFinal_LCW_CB_eflow_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_RefFinal_LCW_CB_eflow_phi_EndcapRegion", &MET_RefFinal_LCW_CB_eflow_phi_EndcapRegion, &b_MET_RefFinal_LCW_CB_eflow_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_RefFinal_LCW_CB_eflow_etx_ForwardReg", &MET_RefFinal_LCW_CB_eflow_etx_ForwardReg, &b_MET_RefFinal_LCW_CB_eflow_etx_ForwardReg);
   fChain->SetBranchAddress("MET_RefFinal_LCW_CB_eflow_ety_ForwardReg", &MET_RefFinal_LCW_CB_eflow_ety_ForwardReg, &b_MET_RefFinal_LCW_CB_eflow_ety_ForwardReg);
   fChain->SetBranchAddress("MET_RefFinal_LCW_CB_eflow_sumet_ForwardReg", &MET_RefFinal_LCW_CB_eflow_sumet_ForwardReg, &b_MET_RefFinal_LCW_CB_eflow_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_RefFinal_LCW_CB_eflow_phi_ForwardReg", &MET_RefFinal_LCW_CB_eflow_phi_ForwardReg, &b_MET_RefFinal_LCW_CB_eflow_phi_ForwardReg);
   fChain->SetBranchAddress("MET_RefGamma_LCW_CB_eflow_etx", &MET_RefGamma_LCW_CB_eflow_etx, &b_MET_RefGamma_LCW_CB_eflow_etx);
   fChain->SetBranchAddress("MET_RefGamma_LCW_CB_eflow_ety", &MET_RefGamma_LCW_CB_eflow_ety, &b_MET_RefGamma_LCW_CB_eflow_ety);
   fChain->SetBranchAddress("MET_RefGamma_LCW_CB_eflow_phi", &MET_RefGamma_LCW_CB_eflow_phi, &b_MET_RefGamma_LCW_CB_eflow_phi);
   fChain->SetBranchAddress("MET_RefGamma_LCW_CB_eflow_et", &MET_RefGamma_LCW_CB_eflow_et, &b_MET_RefGamma_LCW_CB_eflow_et);
   fChain->SetBranchAddress("MET_RefGamma_LCW_CB_eflow_sumet", &MET_RefGamma_LCW_CB_eflow_sumet, &b_MET_RefGamma_LCW_CB_eflow_sumet);
   fChain->SetBranchAddress("MET_RefGamma_LCW_CB_eflow_etx_CentralReg", &MET_RefGamma_LCW_CB_eflow_etx_CentralReg, &b_MET_RefGamma_LCW_CB_eflow_etx_CentralReg);
   fChain->SetBranchAddress("MET_RefGamma_LCW_CB_eflow_ety_CentralReg", &MET_RefGamma_LCW_CB_eflow_ety_CentralReg, &b_MET_RefGamma_LCW_CB_eflow_ety_CentralReg);
   fChain->SetBranchAddress("MET_RefGamma_LCW_CB_eflow_sumet_CentralReg", &MET_RefGamma_LCW_CB_eflow_sumet_CentralReg, &b_MET_RefGamma_LCW_CB_eflow_sumet_CentralReg);
   fChain->SetBranchAddress("MET_RefGamma_LCW_CB_eflow_phi_CentralReg", &MET_RefGamma_LCW_CB_eflow_phi_CentralReg, &b_MET_RefGamma_LCW_CB_eflow_phi_CentralReg);
   fChain->SetBranchAddress("MET_RefGamma_LCW_CB_eflow_etx_EndcapRegion", &MET_RefGamma_LCW_CB_eflow_etx_EndcapRegion, &b_MET_RefGamma_LCW_CB_eflow_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_RefGamma_LCW_CB_eflow_ety_EndcapRegion", &MET_RefGamma_LCW_CB_eflow_ety_EndcapRegion, &b_MET_RefGamma_LCW_CB_eflow_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_RefGamma_LCW_CB_eflow_sumet_EndcapRegion", &MET_RefGamma_LCW_CB_eflow_sumet_EndcapRegion, &b_MET_RefGamma_LCW_CB_eflow_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_RefGamma_LCW_CB_eflow_phi_EndcapRegion", &MET_RefGamma_LCW_CB_eflow_phi_EndcapRegion, &b_MET_RefGamma_LCW_CB_eflow_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_RefGamma_LCW_CB_eflow_etx_ForwardReg", &MET_RefGamma_LCW_CB_eflow_etx_ForwardReg, &b_MET_RefGamma_LCW_CB_eflow_etx_ForwardReg);
   fChain->SetBranchAddress("MET_RefGamma_LCW_CB_eflow_ety_ForwardReg", &MET_RefGamma_LCW_CB_eflow_ety_ForwardReg, &b_MET_RefGamma_LCW_CB_eflow_ety_ForwardReg);
   fChain->SetBranchAddress("MET_RefGamma_LCW_CB_eflow_sumet_ForwardReg", &MET_RefGamma_LCW_CB_eflow_sumet_ForwardReg, &b_MET_RefGamma_LCW_CB_eflow_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_RefGamma_LCW_CB_eflow_phi_ForwardReg", &MET_RefGamma_LCW_CB_eflow_phi_ForwardReg, &b_MET_RefGamma_LCW_CB_eflow_phi_ForwardReg);
   fChain->SetBranchAddress("MET_RefEle_LCW_CB_eflow_etx", &MET_RefEle_LCW_CB_eflow_etx, &b_MET_RefEle_LCW_CB_eflow_etx);
   fChain->SetBranchAddress("MET_RefEle_LCW_CB_eflow_ety", &MET_RefEle_LCW_CB_eflow_ety, &b_MET_RefEle_LCW_CB_eflow_ety);
   fChain->SetBranchAddress("MET_RefEle_LCW_CB_eflow_phi", &MET_RefEle_LCW_CB_eflow_phi, &b_MET_RefEle_LCW_CB_eflow_phi);
   fChain->SetBranchAddress("MET_RefEle_LCW_CB_eflow_et", &MET_RefEle_LCW_CB_eflow_et, &b_MET_RefEle_LCW_CB_eflow_et);
   fChain->SetBranchAddress("MET_RefEle_LCW_CB_eflow_sumet", &MET_RefEle_LCW_CB_eflow_sumet, &b_MET_RefEle_LCW_CB_eflow_sumet);
   fChain->SetBranchAddress("MET_RefEle_LCW_CB_eflow_etx_CentralReg", &MET_RefEle_LCW_CB_eflow_etx_CentralReg, &b_MET_RefEle_LCW_CB_eflow_etx_CentralReg);
   fChain->SetBranchAddress("MET_RefEle_LCW_CB_eflow_ety_CentralReg", &MET_RefEle_LCW_CB_eflow_ety_CentralReg, &b_MET_RefEle_LCW_CB_eflow_ety_CentralReg);
   fChain->SetBranchAddress("MET_RefEle_LCW_CB_eflow_sumet_CentralReg", &MET_RefEle_LCW_CB_eflow_sumet_CentralReg, &b_MET_RefEle_LCW_CB_eflow_sumet_CentralReg);
   fChain->SetBranchAddress("MET_RefEle_LCW_CB_eflow_phi_CentralReg", &MET_RefEle_LCW_CB_eflow_phi_CentralReg, &b_MET_RefEle_LCW_CB_eflow_phi_CentralReg);
   fChain->SetBranchAddress("MET_RefEle_LCW_CB_eflow_etx_EndcapRegion", &MET_RefEle_LCW_CB_eflow_etx_EndcapRegion, &b_MET_RefEle_LCW_CB_eflow_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_RefEle_LCW_CB_eflow_ety_EndcapRegion", &MET_RefEle_LCW_CB_eflow_ety_EndcapRegion, &b_MET_RefEle_LCW_CB_eflow_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_RefEle_LCW_CB_eflow_sumet_EndcapRegion", &MET_RefEle_LCW_CB_eflow_sumet_EndcapRegion, &b_MET_RefEle_LCW_CB_eflow_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_RefEle_LCW_CB_eflow_phi_EndcapRegion", &MET_RefEle_LCW_CB_eflow_phi_EndcapRegion, &b_MET_RefEle_LCW_CB_eflow_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_RefEle_LCW_CB_eflow_etx_ForwardReg", &MET_RefEle_LCW_CB_eflow_etx_ForwardReg, &b_MET_RefEle_LCW_CB_eflow_etx_ForwardReg);
   fChain->SetBranchAddress("MET_RefEle_LCW_CB_eflow_ety_ForwardReg", &MET_RefEle_LCW_CB_eflow_ety_ForwardReg, &b_MET_RefEle_LCW_CB_eflow_ety_ForwardReg);
   fChain->SetBranchAddress("MET_RefEle_LCW_CB_eflow_sumet_ForwardReg", &MET_RefEle_LCW_CB_eflow_sumet_ForwardReg, &b_MET_RefEle_LCW_CB_eflow_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_RefEle_LCW_CB_eflow_phi_ForwardReg", &MET_RefEle_LCW_CB_eflow_phi_ForwardReg, &b_MET_RefEle_LCW_CB_eflow_phi_ForwardReg);
   fChain->SetBranchAddress("MET_RefTau_LCW_CB_eflow_etx", &MET_RefTau_LCW_CB_eflow_etx, &b_MET_RefTau_LCW_CB_eflow_etx);
   fChain->SetBranchAddress("MET_RefTau_LCW_CB_eflow_ety", &MET_RefTau_LCW_CB_eflow_ety, &b_MET_RefTau_LCW_CB_eflow_ety);
   fChain->SetBranchAddress("MET_RefTau_LCW_CB_eflow_phi", &MET_RefTau_LCW_CB_eflow_phi, &b_MET_RefTau_LCW_CB_eflow_phi);
   fChain->SetBranchAddress("MET_RefTau_LCW_CB_eflow_et", &MET_RefTau_LCW_CB_eflow_et, &b_MET_RefTau_LCW_CB_eflow_et);
   fChain->SetBranchAddress("MET_RefTau_LCW_CB_eflow_sumet", &MET_RefTau_LCW_CB_eflow_sumet, &b_MET_RefTau_LCW_CB_eflow_sumet);
   fChain->SetBranchAddress("MET_RefTau_LCW_CB_eflow_etx_CentralReg", &MET_RefTau_LCW_CB_eflow_etx_CentralReg, &b_MET_RefTau_LCW_CB_eflow_etx_CentralReg);
   fChain->SetBranchAddress("MET_RefTau_LCW_CB_eflow_ety_CentralReg", &MET_RefTau_LCW_CB_eflow_ety_CentralReg, &b_MET_RefTau_LCW_CB_eflow_ety_CentralReg);
   fChain->SetBranchAddress("MET_RefTau_LCW_CB_eflow_sumet_CentralReg", &MET_RefTau_LCW_CB_eflow_sumet_CentralReg, &b_MET_RefTau_LCW_CB_eflow_sumet_CentralReg);
   fChain->SetBranchAddress("MET_RefTau_LCW_CB_eflow_phi_CentralReg", &MET_RefTau_LCW_CB_eflow_phi_CentralReg, &b_MET_RefTau_LCW_CB_eflow_phi_CentralReg);
   fChain->SetBranchAddress("MET_RefTau_LCW_CB_eflow_etx_EndcapRegion", &MET_RefTau_LCW_CB_eflow_etx_EndcapRegion, &b_MET_RefTau_LCW_CB_eflow_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_RefTau_LCW_CB_eflow_ety_EndcapRegion", &MET_RefTau_LCW_CB_eflow_ety_EndcapRegion, &b_MET_RefTau_LCW_CB_eflow_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_RefTau_LCW_CB_eflow_sumet_EndcapRegion", &MET_RefTau_LCW_CB_eflow_sumet_EndcapRegion, &b_MET_RefTau_LCW_CB_eflow_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_RefTau_LCW_CB_eflow_phi_EndcapRegion", &MET_RefTau_LCW_CB_eflow_phi_EndcapRegion, &b_MET_RefTau_LCW_CB_eflow_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_RefTau_LCW_CB_eflow_etx_ForwardReg", &MET_RefTau_LCW_CB_eflow_etx_ForwardReg, &b_MET_RefTau_LCW_CB_eflow_etx_ForwardReg);
   fChain->SetBranchAddress("MET_RefTau_LCW_CB_eflow_ety_ForwardReg", &MET_RefTau_LCW_CB_eflow_ety_ForwardReg, &b_MET_RefTau_LCW_CB_eflow_ety_ForwardReg);
   fChain->SetBranchAddress("MET_RefTau_LCW_CB_eflow_sumet_ForwardReg", &MET_RefTau_LCW_CB_eflow_sumet_ForwardReg, &b_MET_RefTau_LCW_CB_eflow_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_RefTau_LCW_CB_eflow_phi_ForwardReg", &MET_RefTau_LCW_CB_eflow_phi_ForwardReg, &b_MET_RefTau_LCW_CB_eflow_phi_ForwardReg);
   fChain->SetBranchAddress("MET_RefJet_LCW_CB_eflow_etx", &MET_RefJet_LCW_CB_eflow_etx, &b_MET_RefJet_LCW_CB_eflow_etx);
   fChain->SetBranchAddress("MET_RefJet_LCW_CB_eflow_ety", &MET_RefJet_LCW_CB_eflow_ety, &b_MET_RefJet_LCW_CB_eflow_ety);
   fChain->SetBranchAddress("MET_RefJet_LCW_CB_eflow_phi", &MET_RefJet_LCW_CB_eflow_phi, &b_MET_RefJet_LCW_CB_eflow_phi);
   fChain->SetBranchAddress("MET_RefJet_LCW_CB_eflow_et", &MET_RefJet_LCW_CB_eflow_et, &b_MET_RefJet_LCW_CB_eflow_et);
   fChain->SetBranchAddress("MET_RefJet_LCW_CB_eflow_sumet", &MET_RefJet_LCW_CB_eflow_sumet, &b_MET_RefJet_LCW_CB_eflow_sumet);
   fChain->SetBranchAddress("MET_RefJet_LCW_CB_eflow_etx_CentralReg", &MET_RefJet_LCW_CB_eflow_etx_CentralReg, &b_MET_RefJet_LCW_CB_eflow_etx_CentralReg);
   fChain->SetBranchAddress("MET_RefJet_LCW_CB_eflow_ety_CentralReg", &MET_RefJet_LCW_CB_eflow_ety_CentralReg, &b_MET_RefJet_LCW_CB_eflow_ety_CentralReg);
   fChain->SetBranchAddress("MET_RefJet_LCW_CB_eflow_sumet_CentralReg", &MET_RefJet_LCW_CB_eflow_sumet_CentralReg, &b_MET_RefJet_LCW_CB_eflow_sumet_CentralReg);
   fChain->SetBranchAddress("MET_RefJet_LCW_CB_eflow_phi_CentralReg", &MET_RefJet_LCW_CB_eflow_phi_CentralReg, &b_MET_RefJet_LCW_CB_eflow_phi_CentralReg);
   fChain->SetBranchAddress("MET_RefJet_LCW_CB_eflow_etx_EndcapRegion", &MET_RefJet_LCW_CB_eflow_etx_EndcapRegion, &b_MET_RefJet_LCW_CB_eflow_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_RefJet_LCW_CB_eflow_ety_EndcapRegion", &MET_RefJet_LCW_CB_eflow_ety_EndcapRegion, &b_MET_RefJet_LCW_CB_eflow_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_RefJet_LCW_CB_eflow_sumet_EndcapRegion", &MET_RefJet_LCW_CB_eflow_sumet_EndcapRegion, &b_MET_RefJet_LCW_CB_eflow_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_RefJet_LCW_CB_eflow_phi_EndcapRegion", &MET_RefJet_LCW_CB_eflow_phi_EndcapRegion, &b_MET_RefJet_LCW_CB_eflow_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_RefJet_LCW_CB_eflow_etx_ForwardReg", &MET_RefJet_LCW_CB_eflow_etx_ForwardReg, &b_MET_RefJet_LCW_CB_eflow_etx_ForwardReg);
   fChain->SetBranchAddress("MET_RefJet_LCW_CB_eflow_ety_ForwardReg", &MET_RefJet_LCW_CB_eflow_ety_ForwardReg, &b_MET_RefJet_LCW_CB_eflow_ety_ForwardReg);
   fChain->SetBranchAddress("MET_RefJet_LCW_CB_eflow_sumet_ForwardReg", &MET_RefJet_LCW_CB_eflow_sumet_ForwardReg, &b_MET_RefJet_LCW_CB_eflow_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_RefJet_LCW_CB_eflow_phi_ForwardReg", &MET_RefJet_LCW_CB_eflow_phi_ForwardReg, &b_MET_RefJet_LCW_CB_eflow_phi_ForwardReg);
   fChain->SetBranchAddress("MET_CellOut_LCW_CB_eflow_etx", &MET_CellOut_LCW_CB_eflow_etx, &b_MET_CellOut_LCW_CB_eflow_etx);
   fChain->SetBranchAddress("MET_CellOut_LCW_CB_eflow_ety", &MET_CellOut_LCW_CB_eflow_ety, &b_MET_CellOut_LCW_CB_eflow_ety);
   fChain->SetBranchAddress("MET_CellOut_LCW_CB_eflow_phi", &MET_CellOut_LCW_CB_eflow_phi, &b_MET_CellOut_LCW_CB_eflow_phi);
   fChain->SetBranchAddress("MET_CellOut_LCW_CB_eflow_et", &MET_CellOut_LCW_CB_eflow_et, &b_MET_CellOut_LCW_CB_eflow_et);
   fChain->SetBranchAddress("MET_CellOut_LCW_CB_eflow_sumet", &MET_CellOut_LCW_CB_eflow_sumet, &b_MET_CellOut_LCW_CB_eflow_sumet);
   fChain->SetBranchAddress("MET_CellOut_LCW_CB_eflow_etx_CentralReg", &MET_CellOut_LCW_CB_eflow_etx_CentralReg, &b_MET_CellOut_LCW_CB_eflow_etx_CentralReg);
   fChain->SetBranchAddress("MET_CellOut_LCW_CB_eflow_ety_CentralReg", &MET_CellOut_LCW_CB_eflow_ety_CentralReg, &b_MET_CellOut_LCW_CB_eflow_ety_CentralReg);
   fChain->SetBranchAddress("MET_CellOut_LCW_CB_eflow_sumet_CentralReg", &MET_CellOut_LCW_CB_eflow_sumet_CentralReg, &b_MET_CellOut_LCW_CB_eflow_sumet_CentralReg);
   fChain->SetBranchAddress("MET_CellOut_LCW_CB_eflow_phi_CentralReg", &MET_CellOut_LCW_CB_eflow_phi_CentralReg, &b_MET_CellOut_LCW_CB_eflow_phi_CentralReg);
   fChain->SetBranchAddress("MET_CellOut_LCW_CB_eflow_etx_EndcapRegion", &MET_CellOut_LCW_CB_eflow_etx_EndcapRegion, &b_MET_CellOut_LCW_CB_eflow_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_CellOut_LCW_CB_eflow_ety_EndcapRegion", &MET_CellOut_LCW_CB_eflow_ety_EndcapRegion, &b_MET_CellOut_LCW_CB_eflow_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_CellOut_LCW_CB_eflow_sumet_EndcapRegion", &MET_CellOut_LCW_CB_eflow_sumet_EndcapRegion, &b_MET_CellOut_LCW_CB_eflow_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_CellOut_LCW_CB_eflow_phi_EndcapRegion", &MET_CellOut_LCW_CB_eflow_phi_EndcapRegion, &b_MET_CellOut_LCW_CB_eflow_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_CellOut_LCW_CB_eflow_etx_ForwardReg", &MET_CellOut_LCW_CB_eflow_etx_ForwardReg, &b_MET_CellOut_LCW_CB_eflow_etx_ForwardReg);
   fChain->SetBranchAddress("MET_CellOut_LCW_CB_eflow_ety_ForwardReg", &MET_CellOut_LCW_CB_eflow_ety_ForwardReg, &b_MET_CellOut_LCW_CB_eflow_ety_ForwardReg);
   fChain->SetBranchAddress("MET_CellOut_LCW_CB_eflow_sumet_ForwardReg", &MET_CellOut_LCW_CB_eflow_sumet_ForwardReg, &b_MET_CellOut_LCW_CB_eflow_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_CellOut_LCW_CB_eflow_phi_ForwardReg", &MET_CellOut_LCW_CB_eflow_phi_ForwardReg, &b_MET_CellOut_LCW_CB_eflow_phi_ForwardReg);
   fChain->SetBranchAddress("MET_Cryo_LCW_CB_eflow_etx", &MET_Cryo_LCW_CB_eflow_etx, &b_MET_Cryo_LCW_CB_eflow_etx);
   fChain->SetBranchAddress("MET_Cryo_LCW_CB_eflow_ety", &MET_Cryo_LCW_CB_eflow_ety, &b_MET_Cryo_LCW_CB_eflow_ety);
   fChain->SetBranchAddress("MET_Cryo_LCW_CB_eflow_phi", &MET_Cryo_LCW_CB_eflow_phi, &b_MET_Cryo_LCW_CB_eflow_phi);
   fChain->SetBranchAddress("MET_Cryo_LCW_CB_eflow_et", &MET_Cryo_LCW_CB_eflow_et, &b_MET_Cryo_LCW_CB_eflow_et);
   fChain->SetBranchAddress("MET_Cryo_LCW_CB_eflow_sumet", &MET_Cryo_LCW_CB_eflow_sumet, &b_MET_Cryo_LCW_CB_eflow_sumet);
   fChain->SetBranchAddress("MET_Cryo_LCW_CB_eflow_etx_CentralReg", &MET_Cryo_LCW_CB_eflow_etx_CentralReg, &b_MET_Cryo_LCW_CB_eflow_etx_CentralReg);
   fChain->SetBranchAddress("MET_Cryo_LCW_CB_eflow_ety_CentralReg", &MET_Cryo_LCW_CB_eflow_ety_CentralReg, &b_MET_Cryo_LCW_CB_eflow_ety_CentralReg);
   fChain->SetBranchAddress("MET_Cryo_LCW_CB_eflow_sumet_CentralReg", &MET_Cryo_LCW_CB_eflow_sumet_CentralReg, &b_MET_Cryo_LCW_CB_eflow_sumet_CentralReg);
   fChain->SetBranchAddress("MET_Cryo_LCW_CB_eflow_phi_CentralReg", &MET_Cryo_LCW_CB_eflow_phi_CentralReg, &b_MET_Cryo_LCW_CB_eflow_phi_CentralReg);
   fChain->SetBranchAddress("MET_Cryo_LCW_CB_eflow_etx_EndcapRegion", &MET_Cryo_LCW_CB_eflow_etx_EndcapRegion, &b_MET_Cryo_LCW_CB_eflow_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_Cryo_LCW_CB_eflow_ety_EndcapRegion", &MET_Cryo_LCW_CB_eflow_ety_EndcapRegion, &b_MET_Cryo_LCW_CB_eflow_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_Cryo_LCW_CB_eflow_sumet_EndcapRegion", &MET_Cryo_LCW_CB_eflow_sumet_EndcapRegion, &b_MET_Cryo_LCW_CB_eflow_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_Cryo_LCW_CB_eflow_phi_EndcapRegion", &MET_Cryo_LCW_CB_eflow_phi_EndcapRegion, &b_MET_Cryo_LCW_CB_eflow_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_Cryo_LCW_CB_eflow_etx_ForwardReg", &MET_Cryo_LCW_CB_eflow_etx_ForwardReg, &b_MET_Cryo_LCW_CB_eflow_etx_ForwardReg);
   fChain->SetBranchAddress("MET_Cryo_LCW_CB_eflow_ety_ForwardReg", &MET_Cryo_LCW_CB_eflow_ety_ForwardReg, &b_MET_Cryo_LCW_CB_eflow_ety_ForwardReg);
   fChain->SetBranchAddress("MET_Cryo_LCW_CB_eflow_sumet_ForwardReg", &MET_Cryo_LCW_CB_eflow_sumet_ForwardReg, &b_MET_Cryo_LCW_CB_eflow_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_Cryo_LCW_CB_eflow_phi_ForwardReg", &MET_Cryo_LCW_CB_eflow_phi_ForwardReg, &b_MET_Cryo_LCW_CB_eflow_phi_ForwardReg);
   fChain->SetBranchAddress("L1_2J10", &L1_2J10, &b_L1_2J10);
   fChain->SetBranchAddress("L1_2J15", &L1_2J15, &b_L1_2J15);
   fChain->SetBranchAddress("L1_2J5", &L1_2J5, &b_L1_2J5);
   fChain->SetBranchAddress("L1_J10", &L1_J10, &b_L1_J10);
   fChain->SetBranchAddress("L1_J15", &L1_J15, &b_L1_J15);
   fChain->SetBranchAddress("L1_J30", &L1_J30, &b_L1_J30);
   fChain->SetBranchAddress("L1_J5", &L1_J5, &b_L1_J5);
   fChain->SetBranchAddress("L1_J55", &L1_J55, &b_L1_J55);
   fChain->SetBranchAddress("L1_J75", &L1_J75, &b_L1_J75);
   fChain->SetBranchAddress("L1_J95", &L1_J95, &b_L1_J95);
   fChain->SetBranchAddress("trig_L1_TAV", &trig_L1_TAV, &b_trig_L1_TAV);
   fChain->SetBranchAddress("trig_L2_passedPhysics", &trig_L2_passedPhysics, &b_trig_L2_passedPhysics);
   fChain->SetBranchAddress("trig_EF_passedPhysics", &trig_EF_passedPhysics, &b_trig_EF_passedPhysics);
   fChain->SetBranchAddress("trig_L1_TBP", &trig_L1_TBP, &b_trig_L1_TBP);
   fChain->SetBranchAddress("trig_L1_TAP", &trig_L1_TAP, &b_trig_L1_TAP);
   fChain->SetBranchAddress("trig_L2_passedRaw", &trig_L2_passedRaw, &b_trig_L2_passedRaw);
   fChain->SetBranchAddress("trig_EF_passedRaw", &trig_EF_passedRaw, &b_trig_EF_passedRaw);
   fChain->SetBranchAddress("trig_L2_resurrected", &trig_L2_resurrected, &b_trig_L2_resurrected);
   fChain->SetBranchAddress("trig_EF_resurrected", &trig_EF_resurrected, &b_trig_EF_resurrected);
   fChain->SetBranchAddress("trig_L2_passedThrough", &trig_L2_passedThrough, &b_trig_L2_passedThrough);
   fChain->SetBranchAddress("trig_EF_passedThrough", &trig_EF_passedThrough, &b_trig_EF_passedThrough);
   fChain->SetBranchAddress("trig_DB_SMK", &trig_DB_SMK, &b_trig_DB_SMK);
   fChain->SetBranchAddress("trig_DB_L1PSK", &trig_DB_L1PSK, &b_trig_DB_L1PSK);
   fChain->SetBranchAddress("trig_DB_HLTPSK", &trig_DB_HLTPSK, &b_trig_DB_HLTPSK);
   fChain->SetBranchAddress("mcevt_n", &mcevt_n, &b_mcevt_n);
   fChain->SetBranchAddress("mcevt_signal_process_id", &mcevt_signal_process_id, &b_mcevt_signal_process_id);
   fChain->SetBranchAddress("mcevt_event_number", &mcevt_event_number, &b_mcevt_event_number);
   fChain->SetBranchAddress("mcevt_event_scale", &mcevt_event_scale, &b_mcevt_event_scale);
   fChain->SetBranchAddress("mcevt_alphaQCD", &mcevt_alphaQCD, &b_mcevt_alphaQCD);
   fChain->SetBranchAddress("mcevt_alphaQED", &mcevt_alphaQED, &b_mcevt_alphaQED);
   fChain->SetBranchAddress("mcevt_pdf_id1", &mcevt_pdf_id1, &b_mcevt_pdf_id1);
   fChain->SetBranchAddress("mcevt_pdf_id2", &mcevt_pdf_id2, &b_mcevt_pdf_id2);
   fChain->SetBranchAddress("mcevt_pdf_x1", &mcevt_pdf_x1, &b_mcevt_pdf_x1);
   fChain->SetBranchAddress("mcevt_pdf_x2", &mcevt_pdf_x2, &b_mcevt_pdf_x2);
   fChain->SetBranchAddress("mcevt_pdf_scale", &mcevt_pdf_scale, &b_mcevt_pdf_scale);
   fChain->SetBranchAddress("mcevt_pdf1", &mcevt_pdf1, &b_mcevt_pdf1);
   fChain->SetBranchAddress("mcevt_pdf2", &mcevt_pdf2, &b_mcevt_pdf2);
   fChain->SetBranchAddress("mcevt_weight", &mcevt_weight, &b_mcevt_weight);
   fChain->SetBranchAddress("mc_n", &mc_n, &b_mc_n);
   fChain->SetBranchAddress("mc_pt", &mc_pt, &b_mc_pt);
   fChain->SetBranchAddress("mc_eta", &mc_eta, &b_mc_eta);
   fChain->SetBranchAddress("mc_phi", &mc_phi, &b_mc_phi);
   fChain->SetBranchAddress("mc_status", &mc_status, &b_mc_status);
   fChain->SetBranchAddress("mc_barcode", &mc_barcode, &b_mc_barcode);
   fChain->SetBranchAddress("mc_parents", &mc_parents, &b_mc_parents);
   fChain->SetBranchAddress("mc_children", &mc_children, &b_mc_children);
   fChain->SetBranchAddress("mc_pdgId", &mc_pdgId, &b_mc_pdgId);
   fChain->SetBranchAddress("AntiKt4TruthNew_n", &AntiKt4TruthNew_n, &b_AntiKt4TruthNew_n);
   fChain->SetBranchAddress("AntiKt4TruthNew_E", &AntiKt4TruthNew_E, &b_AntiKt4TruthNew_E);
   fChain->SetBranchAddress("AntiKt4TruthNew_pt", &AntiKt4TruthNew_pt, &b_AntiKt4TruthNew_pt);
   fChain->SetBranchAddress("AntiKt4TruthNew_m", &AntiKt4TruthNew_m, &b_AntiKt4TruthNew_m);
   fChain->SetBranchAddress("AntiKt4TruthNew_eta", &AntiKt4TruthNew_eta, &b_AntiKt4TruthNew_eta);
   fChain->SetBranchAddress("AntiKt4TruthNew_phi", &AntiKt4TruthNew_phi, &b_AntiKt4TruthNew_phi);
   fChain->SetBranchAddress("AntiKt6TruthNew_n", &AntiKt6TruthNew_n, &b_AntiKt6TruthNew_n);
   fChain->SetBranchAddress("AntiKt6TruthNew_E", &AntiKt6TruthNew_E, &b_AntiKt6TruthNew_E);
   fChain->SetBranchAddress("AntiKt6TruthNew_pt", &AntiKt6TruthNew_pt, &b_AntiKt6TruthNew_pt);
   fChain->SetBranchAddress("AntiKt6TruthNew_m", &AntiKt6TruthNew_m, &b_AntiKt6TruthNew_m);
   fChain->SetBranchAddress("AntiKt6TruthNew_eta", &AntiKt6TruthNew_eta, &b_AntiKt6TruthNew_eta);
   fChain->SetBranchAddress("AntiKt6TruthNew_phi", &AntiKt6TruthNew_phi, &b_AntiKt6TruthNew_phi);
   Notify();
}

Bool_t oldExample::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void oldExample::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t oldExample::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef oldExample_cxx
