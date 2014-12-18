//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Apr  5 14:19:37 2013 by ROOT version 5.30/05
// from TTree qcd/qcd
// found on file: /r02/atlas/khoo/sample_D3PD/CellOutSTVF_check/mc12_8TeV.107663.AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp3.merge.NTUP_JETMET.e1218_s1469_s1470_r3542_r3549_p1344_tid01115626_00/NTUP_JETMET.01115626._000007.root.1
//////////////////////////////////////////////////////////

#ifndef EventReader_h
#define EventReader_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>

class EventReader : public TSelector {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain

   // Declaration of leaf types
   UInt_t          RunNumber;
   UInt_t          EventNumber;
   Float_t         averageIntPerXing;
   UInt_t          mc_channel_number;
   UInt_t          larError;
   Int_t           vxp_n;
   vector<float>   *vxp_z;
   vector<int>     *vxp_type;
   vector<int>     *vxp_nTracks;
   Int_t           el_n;
   vector<float>   *el_E;
   vector<float>   *el_pt;
   vector<float>   *el_eta;
   vector<float>   *el_phi;
   vector<float>   *el_charge;
   vector<int>     *el_author;
   vector<int>     *el_mediumPP;
   vector<float>   *el_Etcone40;
   vector<float>   *el_cl_E;
   vector<float>   *el_cl_pt;
   vector<float>   *el_cl_eta;
   vector<float>   *el_cl_phi;
   Int_t           ph_n;
   vector<float>   *ph_E;
   vector<float>   *ph_pt;
   vector<float>   *ph_eta;
   vector<float>   *ph_phi;
   vector<int>     *ph_isConv;
   vector<float>   *ph_cl_E;
   vector<float>   *ph_cl_pt;
   vector<float>   *ph_cl_eta;
   vector<float>   *ph_cl_phi;
   Int_t           mu_staco_n;
   vector<float>   *mu_staco_pt;
   vector<float>   *mu_staco_eta;
   vector<float>   *mu_staco_phi;
   vector<float>   *mu_staco_charge;
   vector<float>   *mu_staco_ptcone20;
   vector<int>     *mu_staco_isStandAloneMuon;
   vector<int>     *mu_staco_isCombinedMuon;
   vector<int>     *mu_staco_isSegmentTaggedMuon;
   vector<float>   *mu_staco_z0_exPV;
   vector<float>   *mu_staco_id_phi_exPV;
   vector<float>   *mu_staco_id_theta_exPV;
   vector<float>   *mu_staco_id_qoverp_exPV;
   vector<float>   *mu_staco_ms_phi;
   vector<float>   *mu_staco_ms_theta;
   vector<float>   *mu_staco_ms_qoverp;
   vector<int>     *mu_staco_nBLHits;
   vector<int>     *mu_staco_nPixHits;
   vector<int>     *mu_staco_nSCTHits;
   vector<int>     *mu_staco_nTRTHits;
   vector<int>     *mu_staco_nPixHoles;
   vector<int>     *mu_staco_nSCTHoles;
   vector<int>     *mu_staco_nTRTOutliers;
   vector<int>     *mu_staco_nPixelDeadSensors;
   vector<int>     *mu_staco_nSCTDeadSensors;
   vector<int>     *mu_staco_expectBLayerHit;
   Int_t           tau_n;
   vector<float>   *tau_pt;
   vector<float>   *tau_eta;
   vector<float>   *tau_phi;
   vector<int>     *tau_JetBDTSigMedium;
   vector<int>     *tau_nProng;
   Int_t           jet_AntiKt4LCTopo_n;
   vector<float>   *jet_AntiKt4LCTopo_E;
   vector<float>   *jet_AntiKt4LCTopo_pt;
   vector<float>   *jet_AntiKt4LCTopo_eta;
   vector<float>   *jet_AntiKt4LCTopo_phi;
   vector<int>     *jet_AntiKt4LCTopo_isBadLooseMinus;
   vector<float>   *jet_AntiKt4LCTopo_emscale_pt;
   vector<float>   *jet_AntiKt4LCTopo_ActiveAreaPx;
   vector<float>   *jet_AntiKt4LCTopo_ActiveAreaPy;
   vector<float>   *jet_AntiKt4LCTopo_ActiveAreaPz;
   vector<float>   *jet_AntiKt4LCTopo_ActiveAreaE;
   vector<float>   *jet_AntiKt4LCTopo_constscale_E;
   vector<float>   *jet_AntiKt4LCTopo_constscale_m;
   vector<float>   *jet_AntiKt4LCTopo_constscale_eta;
   vector<float>   *jet_AntiKt4LCTopo_constscale_phi;
   vector<int>     *jet_AntiKt4LCTopo_flavor_truth_label;
   Float_t         MET_RefFinal_etx;
   Float_t         MET_RefFinal_ety;
   Float_t         MET_RefFinal_phi;
   Float_t         MET_RefFinal_et;
   Float_t         MET_RefFinal_sumet;
   Float_t         MET_RefEle_etx;
   Float_t         MET_RefEle_ety;
   Float_t         MET_RefEle_phi;
   Float_t         MET_RefEle_et;
   Float_t         MET_RefEle_sumet;
   Float_t         MET_RefJet_etx;
   Float_t         MET_RefJet_ety;
   Float_t         MET_RefJet_phi;
   Float_t         MET_RefJet_et;
   Float_t         MET_RefJet_sumet;
   Float_t         MET_SoftJets_etx;
   Float_t         MET_SoftJets_ety;
   Float_t         MET_SoftJets_phi;
   Float_t         MET_SoftJets_et;
   Float_t         MET_SoftJets_sumet;
   Float_t         MET_RefMuon_etx;
   Float_t         MET_RefMuon_ety;
   Float_t         MET_RefMuon_phi;
   Float_t         MET_RefMuon_et;
   Float_t         MET_RefMuon_sumet;
   Float_t         MET_RefGamma_etx;
   Float_t         MET_RefGamma_ety;
   Float_t         MET_RefGamma_phi;
   Float_t         MET_RefGamma_et;
   Float_t         MET_RefGamma_sumet;
   Float_t         MET_RefTau_etx;
   Float_t         MET_RefTau_ety;
   Float_t         MET_RefTau_phi;
   Float_t         MET_RefTau_et;
   Float_t         MET_RefTau_sumet;
   Float_t         MET_MuonBoy_etx;
   Float_t         MET_MuonBoy_ety;
   Float_t         MET_MuonBoy_phi;
   Float_t         MET_MuonBoy_et;
   Float_t         MET_MuonBoy_sumet;
   Float_t         MET_RefJet_JVFCut_etx;
   Float_t         MET_RefJet_JVFCut_ety;
   Float_t         MET_RefJet_JVFCut_sumet;
   Float_t         MET_CellOut_Eflow_STVF_etx;
   Float_t         MET_CellOut_Eflow_STVF_ety;
   Float_t         MET_CellOut_Eflow_STVF_sumet;
   Float_t         MET_RefFinal_STVF_etx;
   Float_t         MET_RefFinal_STVF_ety;
   Float_t         MET_RefFinal_STVF_sumet;
   Float_t         MET_CellOut_Eflow_etx;
   Float_t         MET_CellOut_Eflow_ety;
   Float_t         MET_CellOut_Eflow_phi;
   Float_t         MET_CellOut_Eflow_et;
   Float_t         MET_CellOut_Eflow_sumet;
   Float_t         MET_Truth_NonInt_etx;
   Float_t         MET_Truth_NonInt_ety;
   Float_t         MET_Truth_NonInt_phi;
   Float_t         MET_Truth_NonInt_et;
   Float_t         MET_Truth_NonInt_sumet;
   vector<vector<float> > *el_MET_wpx;
   vector<vector<float> > *el_MET_wpy;
   vector<vector<float> > *el_MET_wet;
   vector<vector<unsigned int> > *el_MET_statusWord;
   vector<vector<float> > *ph_MET_wpx;
   vector<vector<float> > *ph_MET_wpy;
   vector<vector<float> > *ph_MET_wet;
   vector<vector<unsigned int> > *ph_MET_statusWord;
   vector<vector<float> > *mu_staco_MET_wpx;
   vector<vector<float> > *mu_staco_MET_wpy;
   vector<vector<float> > *mu_staco_MET_wet;
   vector<vector<unsigned int> > *mu_staco_MET_statusWord;
   vector<vector<float> > *tau_MET_wpx;
   vector<vector<float> > *tau_MET_wpy;
   vector<vector<float> > *tau_MET_wet;
   vector<vector<unsigned int> > *tau_MET_statusWord;
   vector<vector<float> > *jet_AntiKt4LCTopo_MET_wpx;
   vector<vector<float> > *jet_AntiKt4LCTopo_MET_wpy;
   vector<vector<float> > *jet_AntiKt4LCTopo_MET_wet;
   vector<vector<unsigned int> > *jet_AntiKt4LCTopo_MET_statusWord;
   Float_t         Eventshape_rhoKt4LC;

  // Generic aliases for objects with multiple types
  Int_t mu_n;
  vector<float> *mu_pt;
  vector<float> *mu_eta;
  vector<float> *mu_phi;
  vector<float> *mu_charge;
  vector<float> *mu_ptcone20;
  vector<int> *mu_isStandAloneMuon;
  vector<int> *mu_isCombinedMuon;
  vector<int> *mu_isSegmentTaggedMuon;
  vector<float> *mu_z0_exPV;
  vector<float> *mu_id_phi_exPV;
  vector<float> *mu_id_theta_exPV;
  vector<float> *mu_id_qoverp_exPV;
  vector<float> *mu_ms_phi;
  vector<float> *mu_ms_theta;
  vector<float> *mu_ms_qoverp;
  vector<int> *mu_nBLHits;
  vector<int> *mu_nPixHits;
  vector<int> *mu_nSCTHits;
  vector<int> *mu_nTRTHits;
  vector<int> *mu_nPixHoles;
  vector<int> *mu_nSCTHoles;
  vector<int> *mu_nTRTOutliers;
  vector<int> *mu_nPixelDeadSensors;
  vector<int> *mu_nSCTDeadSensors;
  vector<int> *mu_expectBLayerHit;
  Int_t jet_n;
  vector<float> *jet_E;
  vector<float> *jet_pt;
  vector<float> *jet_eta;
  vector<float> *jet_phi;
  vector<int> *jet_isBadLooseMinus;
  vector<float> *jet_emscale_pt;
  vector<float> *jet_ActiveAreaPx;
  vector<float> *jet_ActiveAreaPy;
  vector<float> *jet_ActiveAreaPz;
  vector<float> *jet_ActiveAreaE;
  vector<float> *jet_constscale_E;
  vector<float> *jet_constscale_m;
  vector<float> *jet_constscale_eta;
  vector<float> *jet_constscale_phi;
  vector<int> *jet_flavor_truth_label;
  vector<vector<float> > *mu_MET_wpx;
  vector<vector<float> > *mu_MET_wpy;
  vector<vector<float> > *mu_MET_wet;
  vector<vector<unsigned int> > *mu_MET_statusWord;
  vector<vector<float> > *jet_MET_wpx;
  vector<vector<float> > *jet_MET_wpy;
  vector<vector<float> > *jet_MET_wet;
  vector<vector<unsigned int> > *jet_MET_statusWord;

   // List of branches
   TBranch        *b_RunNumber;   //!
   TBranch        *b_EventNumber;   //!
   TBranch        *b_averageIntPerXing;   //!
   TBranch        *b_mc_channel_number;   //!
   TBranch        *b_larError;   //!
   TBranch        *b_vxp_n;   //!
   TBranch        *b_vxp_z;   //!
   TBranch        *b_vxp_type;   //!
   TBranch        *b_vxp_nTracks;   //!
   TBranch        *b_el_n;   //!
   TBranch        *b_el_E;   //!
   TBranch        *b_el_pt;   //!
   TBranch        *b_el_eta;   //!
   TBranch        *b_el_phi;   //!
   TBranch        *b_el_charge;   //!
   TBranch        *b_el_author;   //!
   TBranch        *b_el_mediumPP;   //!
   TBranch        *b_el_Etcone40;   //!
   TBranch        *b_el_cl_E;   //!
   TBranch        *b_el_cl_pt;   //!
   TBranch        *b_el_cl_eta;   //!
   TBranch        *b_el_cl_phi;   //!
   TBranch        *b_ph_n;   //!
   TBranch        *b_ph_E;   //!
   TBranch        *b_ph_pt;   //!
   TBranch        *b_ph_eta;   //!
   TBranch        *b_ph_phi;   //!
   TBranch        *b_ph_isConv;   //!
   TBranch        *b_ph_cl_E;   //!
   TBranch        *b_ph_cl_pt;   //!
   TBranch        *b_ph_cl_eta;   //!
   TBranch        *b_ph_cl_phi;   //!
   TBranch        *b_mu_staco_n;   //!
   TBranch        *b_mu_staco_pt;   //!
   TBranch        *b_mu_staco_eta;   //!
   TBranch        *b_mu_staco_phi;   //!
   TBranch        *b_mu_staco_charge;   //!
   TBranch        *b_mu_staco_ptcone20;   //!
   TBranch        *b_mu_staco_isStandAloneMuon;   //!
   TBranch        *b_mu_staco_isCombinedMuon;   //!
   TBranch        *b_mu_staco_isSegmentTaggedMuon;   //!
   TBranch        *b_mu_staco_z0_exPV;   //!
   TBranch        *b_mu_staco_id_phi_exPV;   //!
   TBranch        *b_mu_staco_id_theta_exPV;   //!
   TBranch        *b_mu_staco_id_qoverp_exPV;   //!
   TBranch        *b_mu_staco_ms_phi;   //!
   TBranch        *b_mu_staco_ms_theta;   //!
   TBranch        *b_mu_staco_ms_qoverp;   //!
   TBranch        *b_mu_staco_nBLHits;   //!
   TBranch        *b_mu_staco_nPixHits;   //!
   TBranch        *b_mu_staco_nSCTHits;   //!
   TBranch        *b_mu_staco_nTRTHits;   //!
   TBranch        *b_mu_staco_nPixHoles;   //!
   TBranch        *b_mu_staco_nSCTHoles;   //!
   TBranch        *b_mu_staco_nTRTOutliers;   //!
   TBranch        *b_mu_staco_nPixelDeadSensors;   //!
   TBranch        *b_mu_staco_nSCTDeadSensors;   //!
   TBranch        *b_mu_staco_expectBLayerHit;   //!
   TBranch        *b_tau_n;   //!
   TBranch        *b_tau_pt;   //!
   TBranch        *b_tau_eta;   //!
   TBranch        *b_tau_phi;   //!
   TBranch        *b_tau_JetBDTSigMedium;   //!
   TBranch        *b_tau_nProng;   //!
   TBranch        *b_jet_AntiKt4LCTopo_n;   //!
   TBranch        *b_jet_AntiKt4LCTopo_E;   //!
   TBranch        *b_jet_AntiKt4LCTopo_pt;   //!
   TBranch        *b_jet_AntiKt4LCTopo_eta;   //!
   TBranch        *b_jet_AntiKt4LCTopo_phi;   //!
   TBranch        *b_jet_AntiKt4LCTopo_isBadLooseMinus;   //!
   TBranch        *b_jet_AntiKt4LCTopo_emscale_pt;   //!
   TBranch        *b_jet_AntiKt4LCTopo_ActiveAreaPx;   //!
   TBranch        *b_jet_AntiKt4LCTopo_ActiveAreaPy;   //!
   TBranch        *b_jet_AntiKt4LCTopo_ActiveAreaPz;   //!
   TBranch        *b_jet_AntiKt4LCTopo_ActiveAreaE;   //!
   TBranch        *b_jet_AntiKt4LCTopo_constscale_E;   //!
   TBranch        *b_jet_AntiKt4LCTopo_constscale_m;   //!
   TBranch        *b_jet_AntiKt4LCTopo_constscale_eta;   //!
   TBranch        *b_jet_AntiKt4LCTopo_constscale_phi;   //!
   TBranch        *b_jet_AntiKt4LCTopo_flavor_truth_label;   //!
   TBranch        *b_MET_RefFinal_etx;   //!
   TBranch        *b_MET_RefFinal_ety;   //!
   TBranch        *b_MET_RefFinal_phi;   //!
   TBranch        *b_MET_RefFinal_et;   //!
   TBranch        *b_MET_RefFinal_sumet;   //!
   TBranch        *b_MET_RefEle_etx;   //!
   TBranch        *b_MET_RefEle_ety;   //!
   TBranch        *b_MET_RefEle_phi;   //!
   TBranch        *b_MET_RefEle_et;   //!
   TBranch        *b_MET_RefEle_sumet;   //!
   TBranch        *b_MET_RefJet_etx;   //!
   TBranch        *b_MET_RefJet_ety;   //!
   TBranch        *b_MET_RefJet_phi;   //!
   TBranch        *b_MET_RefJet_et;   //!
   TBranch        *b_MET_RefJet_sumet;   //!
   TBranch        *b_MET_SoftJets_etx;   //!
   TBranch        *b_MET_SoftJets_ety;   //!
   TBranch        *b_MET_SoftJets_phi;   //!
   TBranch        *b_MET_SoftJets_et;   //!
   TBranch        *b_MET_SoftJets_sumet;   //!
   TBranch        *b_MET_RefMuon_etx;   //!
   TBranch        *b_MET_RefMuon_ety;   //!
   TBranch        *b_MET_RefMuon_phi;   //!
   TBranch        *b_MET_RefMuon_et;   //!
   TBranch        *b_MET_RefMuon_sumet;   //!
   TBranch        *b_MET_RefGamma_etx;   //!
   TBranch        *b_MET_RefGamma_ety;   //!
   TBranch        *b_MET_RefGamma_phi;   //!
   TBranch        *b_MET_RefGamma_et;   //!
   TBranch        *b_MET_RefGamma_sumet;   //!
   TBranch        *b_MET_RefTau_etx;   //!
   TBranch        *b_MET_RefTau_ety;   //!
   TBranch        *b_MET_RefTau_phi;   //!
   TBranch        *b_MET_RefTau_et;   //!
   TBranch        *b_MET_RefTau_sumet;   //!
   TBranch        *b_MET_MuonBoy_etx;   //!
   TBranch        *b_MET_MuonBoy_ety;   //!
   TBranch        *b_MET_MuonBoy_phi;   //!
   TBranch        *b_MET_MuonBoy_et;   //!
   TBranch        *b_MET_MuonBoy_sumet;   //!
   TBranch        *b_MET_RefJet_JVFCut_etx;   //!
   TBranch        *b_MET_RefJet_JVFCut_ety;   //!
   TBranch        *b_MET_RefJet_JVFCut_sumet;   //!
   TBranch        *b_MET_CellOut_Eflow_STVF_etx;   //!
   TBranch        *b_MET_CellOut_Eflow_STVF_ety;   //!
   TBranch        *b_MET_CellOut_Eflow_STVF_sumet;   //!
   TBranch        *b_MET_RefFinal_STVF_etx;   //!
   TBranch        *b_MET_RefFinal_STVF_ety;   //!
   TBranch        *b_MET_RefFinal_STVF_sumet;   //!
   TBranch        *b_MET_CellOut_Eflow_etx;   //!
   TBranch        *b_MET_CellOut_Eflow_ety;   //!
   TBranch        *b_MET_CellOut_Eflow_phi;   //!
   TBranch        *b_MET_CellOut_Eflow_et;   //!
   TBranch        *b_MET_CellOut_Eflow_sumet;   //!
   TBranch        *b_MET_Truth_NonInt_etx;   //!
   TBranch        *b_MET_Truth_NonInt_ety;   //!
   TBranch        *b_MET_Truth_NonInt_phi;   //!
   TBranch        *b_MET_Truth_NonInt_et;   //!
   TBranch        *b_MET_Truth_NonInt_sumet;   //!
   TBranch        *b_el_MET_wpx;   //!
   TBranch        *b_el_MET_wpy;   //!
   TBranch        *b_el_MET_wet;   //!
   TBranch        *b_el_MET_statusWord;   //!
   TBranch        *b_ph_MET_wpx;   //!
   TBranch        *b_ph_MET_wpy;   //!
   TBranch        *b_ph_MET_wet;   //!
   TBranch        *b_ph_MET_statusWord;   //!
   TBranch        *b_mu_staco_MET_wpx;   //!
   TBranch        *b_mu_staco_MET_wpy;   //!
   TBranch        *b_mu_staco_MET_wet;   //!
   TBranch        *b_mu_staco_MET_statusWord;   //!
   TBranch        *b_tau_MET_wpx;   //!
   TBranch        *b_tau_MET_wpy;   //!
   TBranch        *b_tau_MET_wet;   //!
   TBranch        *b_tau_MET_statusWord;   //!
   TBranch        *b_jet_AntiKt4LCTopo_MET_wpx;   //!
   TBranch        *b_jet_AntiKt4LCTopo_MET_wpy;   //!
   TBranch        *b_jet_AntiKt4LCTopo_MET_wet;   //!
   TBranch        *b_jet_AntiKt4LCTopo_MET_statusWord;   //!
   TBranch        *b_Eventshape_rhoKt4LC;   //!

   EventReader(TTree * /*tree*/ =0) { }
   virtual ~EventReader() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(EventReader,0);
};

#endif

#ifdef EventReader_cxx
void EventReader::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   vxp_z = 0;
   vxp_type = 0;
   vxp_nTracks = 0;
   el_E = 0;
   el_pt = 0;
   el_eta = 0;
   el_phi = 0;
   el_charge = 0;
   el_author = 0;
   el_mediumPP = 0;
   el_Etcone40 = 0;
   el_cl_E = 0;
   el_cl_pt = 0;
   el_cl_eta = 0;
   el_cl_phi = 0;
   ph_E = 0;
   ph_pt = 0;
   ph_eta = 0;
   ph_phi = 0;
   ph_isConv = 0;
   ph_cl_E = 0;
   ph_cl_pt = 0;
   ph_cl_eta = 0;
   ph_cl_phi = 0;
   mu_staco_pt = 0;
   mu_staco_eta = 0;
   mu_staco_phi = 0;
   mu_staco_charge = 0;
   mu_staco_ptcone20 = 0;
   mu_staco_isStandAloneMuon = 0;
   mu_staco_isCombinedMuon = 0;
   mu_staco_isSegmentTaggedMuon = 0;
   mu_staco_z0_exPV = 0;
   mu_staco_id_phi_exPV = 0;
   mu_staco_id_theta_exPV = 0;
   mu_staco_id_qoverp_exPV = 0;
   mu_staco_ms_phi = 0;
   mu_staco_ms_theta = 0;
   mu_staco_ms_qoverp = 0;
   mu_staco_nBLHits = 0;
   mu_staco_nPixHits = 0;
   mu_staco_nSCTHits = 0;
   mu_staco_nTRTHits = 0;
   mu_staco_nPixHoles = 0;
   mu_staco_nSCTHoles = 0;
   mu_staco_nTRTOutliers = 0;
   mu_staco_nPixelDeadSensors = 0;
   mu_staco_nSCTDeadSensors = 0;
   mu_staco_expectBLayerHit = 0;
   tau_pt = 0;
   tau_eta = 0;
   tau_phi = 0;
   tau_JetBDTSigMedium = 0;
   tau_nProng = 0;
   jet_AntiKt4LCTopo_E = 0;
   jet_AntiKt4LCTopo_pt = 0;
   jet_AntiKt4LCTopo_eta = 0;
   jet_AntiKt4LCTopo_phi = 0;
   jet_AntiKt4LCTopo_isBadLooseMinus = 0;
   jet_AntiKt4LCTopo_emscale_pt = 0;
   jet_AntiKt4LCTopo_ActiveAreaPx = 0;
   jet_AntiKt4LCTopo_ActiveAreaPy = 0;
   jet_AntiKt4LCTopo_ActiveAreaPz = 0;
   jet_AntiKt4LCTopo_ActiveAreaE = 0;
   jet_AntiKt4LCTopo_constscale_E = 0;
   jet_AntiKt4LCTopo_constscale_m = 0;
   jet_AntiKt4LCTopo_constscale_eta = 0;
   jet_AntiKt4LCTopo_constscale_phi = 0;
   jet_AntiKt4LCTopo_flavor_truth_label = 0;
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
   tau_MET_wpx = 0;
   tau_MET_wpy = 0;
   tau_MET_wet = 0;
   tau_MET_statusWord = 0;
   jet_AntiKt4LCTopo_MET_wpx = 0;
   jet_AntiKt4LCTopo_MET_wpy = 0;
   jet_AntiKt4LCTopo_MET_wet = 0;
   jet_AntiKt4LCTopo_MET_statusWord = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("RunNumber", &RunNumber, &b_RunNumber);
   fChain->SetBranchAddress("EventNumber", &EventNumber, &b_EventNumber);
   fChain->SetBranchAddress("averageIntPerXing", &averageIntPerXing, &b_averageIntPerXing);
   fChain->SetBranchAddress("mc_channel_number", &mc_channel_number, &b_mc_channel_number);
   fChain->SetBranchAddress("larError", &larError, &b_larError);
   fChain->SetBranchAddress("vxp_n", &vxp_n, &b_vxp_n);
   fChain->SetBranchAddress("vxp_z", &vxp_z, &b_vxp_z);
   fChain->SetBranchAddress("vxp_type", &vxp_type, &b_vxp_type);
   fChain->SetBranchAddress("vxp_nTracks", &vxp_nTracks, &b_vxp_nTracks);
   fChain->SetBranchAddress("el_n", &el_n, &b_el_n);
   fChain->SetBranchAddress("el_E", &el_E, &b_el_E);
   fChain->SetBranchAddress("el_pt", &el_pt, &b_el_pt);
   fChain->SetBranchAddress("el_eta", &el_eta, &b_el_eta);
   fChain->SetBranchAddress("el_phi", &el_phi, &b_el_phi);
   fChain->SetBranchAddress("el_charge", &el_charge, &b_el_charge);
   fChain->SetBranchAddress("el_author", &el_author, &b_el_author);
   fChain->SetBranchAddress("el_mediumPP", &el_mediumPP, &b_el_mediumPP);
   fChain->SetBranchAddress("el_Etcone40", &el_Etcone40, &b_el_Etcone40);
   fChain->SetBranchAddress("el_cl_E", &el_cl_E, &b_el_cl_E);
   fChain->SetBranchAddress("el_cl_pt", &el_cl_pt, &b_el_cl_pt);
   fChain->SetBranchAddress("el_cl_eta", &el_cl_eta, &b_el_cl_eta);
   fChain->SetBranchAddress("el_cl_phi", &el_cl_phi, &b_el_cl_phi);
   fChain->SetBranchAddress("ph_n", &ph_n, &b_ph_n);
   fChain->SetBranchAddress("ph_E", &ph_E, &b_ph_E);
   fChain->SetBranchAddress("ph_pt", &ph_pt, &b_ph_pt);
   fChain->SetBranchAddress("ph_eta", &ph_eta, &b_ph_eta);
   fChain->SetBranchAddress("ph_phi", &ph_phi, &b_ph_phi);
   fChain->SetBranchAddress("ph_isConv", &ph_isConv, &b_ph_isConv);
   fChain->SetBranchAddress("ph_cl_E", &ph_cl_E, &b_ph_cl_E);
   fChain->SetBranchAddress("ph_cl_pt", &ph_cl_pt, &b_ph_cl_pt);
   fChain->SetBranchAddress("ph_cl_eta", &ph_cl_eta, &b_ph_cl_eta);
   fChain->SetBranchAddress("ph_cl_phi", &ph_cl_phi, &b_ph_cl_phi);
   fChain->SetBranchAddress("mu_staco_n", &mu_staco_n, &b_mu_staco_n);
   fChain->SetBranchAddress("mu_staco_pt", &mu_staco_pt, &b_mu_staco_pt);
   fChain->SetBranchAddress("mu_staco_eta", &mu_staco_eta, &b_mu_staco_eta);
   fChain->SetBranchAddress("mu_staco_phi", &mu_staco_phi, &b_mu_staco_phi);
   fChain->SetBranchAddress("mu_staco_charge", &mu_staco_charge, &b_mu_staco_charge);
   fChain->SetBranchAddress("mu_staco_ptcone20", &mu_staco_ptcone20, &b_mu_staco_ptcone20);
   fChain->SetBranchAddress("mu_staco_isStandAloneMuon", &mu_staco_isStandAloneMuon, &b_mu_staco_isStandAloneMuon);
   fChain->SetBranchAddress("mu_staco_isCombinedMuon", &mu_staco_isCombinedMuon, &b_mu_staco_isCombinedMuon);
   fChain->SetBranchAddress("mu_staco_isSegmentTaggedMuon", &mu_staco_isSegmentTaggedMuon, &b_mu_staco_isSegmentTaggedMuon);
   fChain->SetBranchAddress("mu_staco_z0_exPV", &mu_staco_z0_exPV, &b_mu_staco_z0_exPV);
   fChain->SetBranchAddress("mu_staco_id_phi_exPV", &mu_staco_id_phi_exPV, &b_mu_staco_id_phi_exPV);
   fChain->SetBranchAddress("mu_staco_id_theta_exPV", &mu_staco_id_theta_exPV, &b_mu_staco_id_theta_exPV);
   fChain->SetBranchAddress("mu_staco_id_qoverp_exPV", &mu_staco_id_qoverp_exPV, &b_mu_staco_id_qoverp_exPV);
   fChain->SetBranchAddress("mu_staco_ms_phi", &mu_staco_ms_phi, &b_mu_staco_ms_phi);
   fChain->SetBranchAddress("mu_staco_ms_theta", &mu_staco_ms_theta, &b_mu_staco_ms_theta);
   fChain->SetBranchAddress("mu_staco_ms_qoverp", &mu_staco_ms_qoverp, &b_mu_staco_ms_qoverp);
   fChain->SetBranchAddress("mu_staco_nBLHits", &mu_staco_nBLHits, &b_mu_staco_nBLHits);
   fChain->SetBranchAddress("mu_staco_nPixHits", &mu_staco_nPixHits, &b_mu_staco_nPixHits);
   fChain->SetBranchAddress("mu_staco_nSCTHits", &mu_staco_nSCTHits, &b_mu_staco_nSCTHits);
   fChain->SetBranchAddress("mu_staco_nTRTHits", &mu_staco_nTRTHits, &b_mu_staco_nTRTHits);
   fChain->SetBranchAddress("mu_staco_nPixHoles", &mu_staco_nPixHoles, &b_mu_staco_nPixHoles);
   fChain->SetBranchAddress("mu_staco_nSCTHoles", &mu_staco_nSCTHoles, &b_mu_staco_nSCTHoles);
   fChain->SetBranchAddress("mu_staco_nTRTOutliers", &mu_staco_nTRTOutliers, &b_mu_staco_nTRTOutliers);
   fChain->SetBranchAddress("mu_staco_nPixelDeadSensors", &mu_staco_nPixelDeadSensors, &b_mu_staco_nPixelDeadSensors);
   fChain->SetBranchAddress("mu_staco_nSCTDeadSensors", &mu_staco_nSCTDeadSensors, &b_mu_staco_nSCTDeadSensors);
   fChain->SetBranchAddress("mu_staco_expectBLayerHit", &mu_staco_expectBLayerHit, &b_mu_staco_expectBLayerHit);
   fChain->SetBranchAddress("tau_n", &tau_n, &b_tau_n);
   fChain->SetBranchAddress("tau_pt", &tau_pt, &b_tau_pt);
   fChain->SetBranchAddress("tau_eta", &tau_eta, &b_tau_eta);
   fChain->SetBranchAddress("tau_phi", &tau_phi, &b_tau_phi);
   fChain->SetBranchAddress("tau_JetBDTSigMedium", &tau_JetBDTSigMedium, &b_tau_JetBDTSigMedium);
   fChain->SetBranchAddress("tau_nProng", &tau_nProng, &b_tau_nProng);
   fChain->SetBranchAddress("jet_AntiKt4LCTopo_n", &jet_AntiKt4LCTopo_n, &b_jet_AntiKt4LCTopo_n);
   fChain->SetBranchAddress("jet_AntiKt4LCTopo_E", &jet_AntiKt4LCTopo_E, &b_jet_AntiKt4LCTopo_E);
   fChain->SetBranchAddress("jet_AntiKt4LCTopo_pt", &jet_AntiKt4LCTopo_pt, &b_jet_AntiKt4LCTopo_pt);
   fChain->SetBranchAddress("jet_AntiKt4LCTopo_eta", &jet_AntiKt4LCTopo_eta, &b_jet_AntiKt4LCTopo_eta);
   fChain->SetBranchAddress("jet_AntiKt4LCTopo_phi", &jet_AntiKt4LCTopo_phi, &b_jet_AntiKt4LCTopo_phi);
   fChain->SetBranchAddress("jet_AntiKt4LCTopo_isBadLooseMinus", &jet_AntiKt4LCTopo_isBadLooseMinus, &b_jet_AntiKt4LCTopo_isBadLooseMinus);
   fChain->SetBranchAddress("jet_AntiKt4LCTopo_emscale_pt", &jet_AntiKt4LCTopo_emscale_pt, &b_jet_AntiKt4LCTopo_emscale_pt);
   fChain->SetBranchAddress("jet_AntiKt4LCTopo_ActiveAreaPx", &jet_AntiKt4LCTopo_ActiveAreaPx, &b_jet_AntiKt4LCTopo_ActiveAreaPx);
   fChain->SetBranchAddress("jet_AntiKt4LCTopo_ActiveAreaPy", &jet_AntiKt4LCTopo_ActiveAreaPy, &b_jet_AntiKt4LCTopo_ActiveAreaPy);
   fChain->SetBranchAddress("jet_AntiKt4LCTopo_ActiveAreaPz", &jet_AntiKt4LCTopo_ActiveAreaPz, &b_jet_AntiKt4LCTopo_ActiveAreaPz);
   fChain->SetBranchAddress("jet_AntiKt4LCTopo_ActiveAreaE", &jet_AntiKt4LCTopo_ActiveAreaE, &b_jet_AntiKt4LCTopo_ActiveAreaE);
   fChain->SetBranchAddress("jet_AntiKt4LCTopo_constscale_E", &jet_AntiKt4LCTopo_constscale_E, &b_jet_AntiKt4LCTopo_constscale_E);
   fChain->SetBranchAddress("jet_AntiKt4LCTopo_constscale_m", &jet_AntiKt4LCTopo_constscale_m, &b_jet_AntiKt4LCTopo_constscale_m);
   fChain->SetBranchAddress("jet_AntiKt4LCTopo_constscale_eta", &jet_AntiKt4LCTopo_constscale_eta, &b_jet_AntiKt4LCTopo_constscale_eta);
   fChain->SetBranchAddress("jet_AntiKt4LCTopo_constscale_phi", &jet_AntiKt4LCTopo_constscale_phi, &b_jet_AntiKt4LCTopo_constscale_phi);
   fChain->SetBranchAddress("jet_AntiKt4LCTopo_flavor_truth_label", &jet_AntiKt4LCTopo_flavor_truth_label, &b_jet_AntiKt4LCTopo_flavor_truth_label);
   fChain->SetBranchAddress("MET_RefFinal_etx", &MET_RefFinal_etx, &b_MET_RefFinal_etx);
   fChain->SetBranchAddress("MET_RefFinal_ety", &MET_RefFinal_ety, &b_MET_RefFinal_ety);
   fChain->SetBranchAddress("MET_RefFinal_phi", &MET_RefFinal_phi, &b_MET_RefFinal_phi);
   fChain->SetBranchAddress("MET_RefFinal_et", &MET_RefFinal_et, &b_MET_RefFinal_et);
   fChain->SetBranchAddress("MET_RefFinal_sumet", &MET_RefFinal_sumet, &b_MET_RefFinal_sumet);
   fChain->SetBranchAddress("MET_RefEle_etx", &MET_RefEle_etx, &b_MET_RefEle_etx);
   fChain->SetBranchAddress("MET_RefEle_ety", &MET_RefEle_ety, &b_MET_RefEle_ety);
   fChain->SetBranchAddress("MET_RefEle_phi", &MET_RefEle_phi, &b_MET_RefEle_phi);
   fChain->SetBranchAddress("MET_RefEle_et", &MET_RefEle_et, &b_MET_RefEle_et);
   fChain->SetBranchAddress("MET_RefEle_sumet", &MET_RefEle_sumet, &b_MET_RefEle_sumet);
   fChain->SetBranchAddress("MET_RefJet_etx", &MET_RefJet_etx, &b_MET_RefJet_etx);
   fChain->SetBranchAddress("MET_RefJet_ety", &MET_RefJet_ety, &b_MET_RefJet_ety);
   fChain->SetBranchAddress("MET_RefJet_phi", &MET_RefJet_phi, &b_MET_RefJet_phi);
   fChain->SetBranchAddress("MET_RefJet_et", &MET_RefJet_et, &b_MET_RefJet_et);
   fChain->SetBranchAddress("MET_RefJet_sumet", &MET_RefJet_sumet, &b_MET_RefJet_sumet);
   fChain->SetBranchAddress("MET_SoftJets_etx", &MET_SoftJets_etx, &b_MET_SoftJets_etx);
   fChain->SetBranchAddress("MET_SoftJets_ety", &MET_SoftJets_ety, &b_MET_SoftJets_ety);
   fChain->SetBranchAddress("MET_SoftJets_phi", &MET_SoftJets_phi, &b_MET_SoftJets_phi);
   fChain->SetBranchAddress("MET_SoftJets_et", &MET_SoftJets_et, &b_MET_SoftJets_et);
   fChain->SetBranchAddress("MET_SoftJets_sumet", &MET_SoftJets_sumet, &b_MET_SoftJets_sumet);
   fChain->SetBranchAddress("MET_RefMuon_etx", &MET_RefMuon_etx, &b_MET_RefMuon_etx);
   fChain->SetBranchAddress("MET_RefMuon_ety", &MET_RefMuon_ety, &b_MET_RefMuon_ety);
   fChain->SetBranchAddress("MET_RefMuon_phi", &MET_RefMuon_phi, &b_MET_RefMuon_phi);
   fChain->SetBranchAddress("MET_RefMuon_et", &MET_RefMuon_et, &b_MET_RefMuon_et);
   fChain->SetBranchAddress("MET_RefMuon_sumet", &MET_RefMuon_sumet, &b_MET_RefMuon_sumet);
   fChain->SetBranchAddress("MET_RefGamma_etx", &MET_RefGamma_etx, &b_MET_RefGamma_etx);
   fChain->SetBranchAddress("MET_RefGamma_ety", &MET_RefGamma_ety, &b_MET_RefGamma_ety);
   fChain->SetBranchAddress("MET_RefGamma_phi", &MET_RefGamma_phi, &b_MET_RefGamma_phi);
   fChain->SetBranchAddress("MET_RefGamma_et", &MET_RefGamma_et, &b_MET_RefGamma_et);
   fChain->SetBranchAddress("MET_RefGamma_sumet", &MET_RefGamma_sumet, &b_MET_RefGamma_sumet);
   fChain->SetBranchAddress("MET_RefTau_etx", &MET_RefTau_etx, &b_MET_RefTau_etx);
   fChain->SetBranchAddress("MET_RefTau_ety", &MET_RefTau_ety, &b_MET_RefTau_ety);
   fChain->SetBranchAddress("MET_RefTau_phi", &MET_RefTau_phi, &b_MET_RefTau_phi);
   fChain->SetBranchAddress("MET_RefTau_et", &MET_RefTau_et, &b_MET_RefTau_et);
   fChain->SetBranchAddress("MET_RefTau_sumet", &MET_RefTau_sumet, &b_MET_RefTau_sumet);
   fChain->SetBranchAddress("MET_MuonBoy_etx", &MET_MuonBoy_etx, &b_MET_MuonBoy_etx);
   fChain->SetBranchAddress("MET_MuonBoy_ety", &MET_MuonBoy_ety, &b_MET_MuonBoy_ety);
   fChain->SetBranchAddress("MET_MuonBoy_phi", &MET_MuonBoy_phi, &b_MET_MuonBoy_phi);
   fChain->SetBranchAddress("MET_MuonBoy_et", &MET_MuonBoy_et, &b_MET_MuonBoy_et);
   fChain->SetBranchAddress("MET_MuonBoy_sumet", &MET_MuonBoy_sumet, &b_MET_MuonBoy_sumet);
   fChain->SetBranchAddress("MET_RefJet_JVFCut_etx", &MET_RefJet_JVFCut_etx, &b_MET_RefJet_JVFCut_etx);
   fChain->SetBranchAddress("MET_RefJet_JVFCut_ety", &MET_RefJet_JVFCut_ety, &b_MET_RefJet_JVFCut_ety);
   fChain->SetBranchAddress("MET_RefJet_JVFCut_sumet", &MET_RefJet_JVFCut_sumet, &b_MET_RefJet_JVFCut_sumet);
   fChain->SetBranchAddress("MET_CellOut_Eflow_STVF_etx", &MET_CellOut_Eflow_STVF_etx, &b_MET_CellOut_Eflow_STVF_etx);
   fChain->SetBranchAddress("MET_CellOut_Eflow_STVF_ety", &MET_CellOut_Eflow_STVF_ety, &b_MET_CellOut_Eflow_STVF_ety);
   fChain->SetBranchAddress("MET_CellOut_Eflow_STVF_sumet", &MET_CellOut_Eflow_STVF_sumet, &b_MET_CellOut_Eflow_STVF_sumet);
   fChain->SetBranchAddress("MET_RefFinal_STVF_etx", &MET_RefFinal_STVF_etx, &b_MET_RefFinal_STVF_etx);
   fChain->SetBranchAddress("MET_RefFinal_STVF_ety", &MET_RefFinal_STVF_ety, &b_MET_RefFinal_STVF_ety);
   fChain->SetBranchAddress("MET_RefFinal_STVF_sumet", &MET_RefFinal_STVF_sumet, &b_MET_RefFinal_STVF_sumet);
   fChain->SetBranchAddress("MET_CellOut_Eflow_etx", &MET_CellOut_Eflow_etx, &b_MET_CellOut_Eflow_etx);
   fChain->SetBranchAddress("MET_CellOut_Eflow_ety", &MET_CellOut_Eflow_ety, &b_MET_CellOut_Eflow_ety);
   fChain->SetBranchAddress("MET_CellOut_Eflow_phi", &MET_CellOut_Eflow_phi, &b_MET_CellOut_Eflow_phi);
   fChain->SetBranchAddress("MET_CellOut_Eflow_et", &MET_CellOut_Eflow_et, &b_MET_CellOut_Eflow_et);
   fChain->SetBranchAddress("MET_CellOut_Eflow_sumet", &MET_CellOut_Eflow_sumet, &b_MET_CellOut_Eflow_sumet);
   fChain->SetBranchAddress("MET_Truth_NonInt_etx", &MET_Truth_NonInt_etx, &b_MET_Truth_NonInt_etx);
   fChain->SetBranchAddress("MET_Truth_NonInt_ety", &MET_Truth_NonInt_ety, &b_MET_Truth_NonInt_ety);
   fChain->SetBranchAddress("MET_Truth_NonInt_phi", &MET_Truth_NonInt_phi, &b_MET_Truth_NonInt_phi);
   fChain->SetBranchAddress("MET_Truth_NonInt_et", &MET_Truth_NonInt_et, &b_MET_Truth_NonInt_et);
   fChain->SetBranchAddress("MET_Truth_NonInt_sumet", &MET_Truth_NonInt_sumet, &b_MET_Truth_NonInt_sumet);
   fChain->SetBranchAddress("el_MET_wpx", &el_MET_wpx, &b_el_MET_wpx);
   fChain->SetBranchAddress("el_MET_wpy", &el_MET_wpy, &b_el_MET_wpy);
   fChain->SetBranchAddress("el_MET_wet", &el_MET_wet, &b_el_MET_wet);
   fChain->SetBranchAddress("el_MET_statusWord", &el_MET_statusWord, &b_el_MET_statusWord);
   fChain->SetBranchAddress("ph_MET_wpx", &ph_MET_wpx, &b_ph_MET_wpx);
   fChain->SetBranchAddress("ph_MET_wpy", &ph_MET_wpy, &b_ph_MET_wpy);
   fChain->SetBranchAddress("ph_MET_wet", &ph_MET_wet, &b_ph_MET_wet);
   fChain->SetBranchAddress("ph_MET_statusWord", &ph_MET_statusWord, &b_ph_MET_statusWord);
   fChain->SetBranchAddress("mu_staco_MET_wpx", &mu_staco_MET_wpx, &b_mu_staco_MET_wpx);
   fChain->SetBranchAddress("mu_staco_MET_wpy", &mu_staco_MET_wpy, &b_mu_staco_MET_wpy);
   fChain->SetBranchAddress("mu_staco_MET_wet", &mu_staco_MET_wet, &b_mu_staco_MET_wet);
   fChain->SetBranchAddress("mu_staco_MET_statusWord", &mu_staco_MET_statusWord, &b_mu_staco_MET_statusWord);
   fChain->SetBranchAddress("tau_MET_wpx", &tau_MET_wpx, &b_tau_MET_wpx);
   fChain->SetBranchAddress("tau_MET_wpy", &tau_MET_wpy, &b_tau_MET_wpy);
   fChain->SetBranchAddress("tau_MET_wet", &tau_MET_wet, &b_tau_MET_wet);
   fChain->SetBranchAddress("tau_MET_statusWord", &tau_MET_statusWord, &b_tau_MET_statusWord);
   fChain->SetBranchAddress("jet_AntiKt4LCTopo_MET_wpx", &jet_AntiKt4LCTopo_MET_wpx, &b_jet_AntiKt4LCTopo_MET_wpx);
   fChain->SetBranchAddress("jet_AntiKt4LCTopo_MET_wpy", &jet_AntiKt4LCTopo_MET_wpy, &b_jet_AntiKt4LCTopo_MET_wpy);
   fChain->SetBranchAddress("jet_AntiKt4LCTopo_MET_wet", &jet_AntiKt4LCTopo_MET_wet, &b_jet_AntiKt4LCTopo_MET_wet);
   fChain->SetBranchAddress("jet_AntiKt4LCTopo_MET_statusWord", &jet_AntiKt4LCTopo_MET_statusWord, &b_jet_AntiKt4LCTopo_MET_statusWord);
   fChain->SetBranchAddress("Eventshape_rhoKt4LC", &Eventshape_rhoKt4LC, &b_Eventshape_rhoKt4LC);
}

Bool_t EventReader::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

#endif // #ifdef EventReader_cxx
