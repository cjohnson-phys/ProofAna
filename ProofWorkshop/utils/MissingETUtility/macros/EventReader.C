#define EventReader_cxx
// The class definition in EventReader.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.

// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// Root > T->Process("EventReader.C")
// Root > T->Process("EventReader.C","some options")
// Root > T->Process("EventReader.C+")
//

#include "EventReader.h"
#include <TH2.h>
#include <TStyle.h>


void EventReader::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

void EventReader::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

Bool_t EventReader::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // It can be passed to either EventReader::GetEntry() or TBranch::GetEntry()
   // to read either all or the required parts of the data. When processing
   // keyed objects with PROOF, the object is already loaded and is available
   // via the fObject pointer.
   //
   // This function should contain the "body" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.


  GetEntry(entry);

   mu_n = mu_staco_n;
   mu_pt = mu_staco_pt;
   mu_eta = mu_staco_eta;
   mu_phi = mu_staco_phi;
   mu_charge = mu_staco_charge;
   mu_ptcone20 = mu_staco_ptcone20;
   mu_isStandAloneMuon = mu_staco_isStandAloneMuon;
   mu_isCombinedMuon = mu_staco_isCombinedMuon;
   mu_isSegmentTaggedMuon = mu_staco_isSegmentTaggedMuon;
   mu_z0_exPV = mu_staco_z0_exPV;
   mu_id_phi_exPV = mu_staco_id_phi_exPV;
   mu_id_theta_exPV = mu_staco_id_theta_exPV;
   mu_id_qoverp_exPV = mu_staco_id_qoverp_exPV;
   mu_ms_phi = mu_staco_ms_phi;
   mu_ms_theta = mu_staco_ms_theta;
   mu_ms_qoverp = mu_staco_ms_qoverp;
   mu_nBLHits = mu_staco_nBLHits;
   mu_nPixHits = mu_staco_nPixHits;
   mu_nSCTHits = mu_staco_nSCTHits;
   mu_nTRTHits = mu_staco_nTRTHits;
   mu_nPixHoles = mu_staco_nPixHoles;
   mu_nSCTHoles = mu_staco_nSCTHoles;
   mu_nTRTOutliers = mu_staco_nTRTOutliers;
   mu_nPixelDeadSensors = mu_staco_nPixelDeadSensors;
   mu_nSCTDeadSensors = mu_staco_nSCTDeadSensors;
   mu_expectBLayerHit = mu_staco_expectBLayerHit;
   jet_n = jet_AntiKt4LCTopo_n;
   jet_E = jet_AntiKt4LCTopo_E;
   jet_pt = jet_AntiKt4LCTopo_pt;
   jet_eta = jet_AntiKt4LCTopo_eta;
   jet_phi = jet_AntiKt4LCTopo_phi;
   jet_isBadLooseMinus = jet_AntiKt4LCTopo_isBadLooseMinus;
   jet_emscale_pt = jet_AntiKt4LCTopo_emscale_pt;
   jet_ActiveAreaPx = jet_AntiKt4LCTopo_ActiveAreaPx;
   jet_ActiveAreaPy = jet_AntiKt4LCTopo_ActiveAreaPy;
   jet_ActiveAreaPz = jet_AntiKt4LCTopo_ActiveAreaPz;
   jet_ActiveAreaE = jet_AntiKt4LCTopo_ActiveAreaE;
   jet_constscale_E = jet_AntiKt4LCTopo_constscale_E;
   jet_constscale_m = jet_AntiKt4LCTopo_constscale_m;
   jet_constscale_eta = jet_AntiKt4LCTopo_constscale_eta;
   jet_constscale_phi = jet_AntiKt4LCTopo_constscale_phi;
   jet_flavor_truth_label = jet_AntiKt4LCTopo_flavor_truth_label;
   mu_MET_wpx = mu_staco_MET_wpx;
   mu_MET_wpy = mu_staco_MET_wpy;
   mu_MET_wet = mu_staco_MET_wet;
   mu_MET_statusWord = mu_staco_MET_statusWord;
   jet_MET_wpx = jet_AntiKt4LCTopo_MET_wpx;
   jet_MET_wpy = jet_AntiKt4LCTopo_MET_wpy;
   jet_MET_wet = jet_AntiKt4LCTopo_MET_wet;
   jet_MET_statusWord = jet_AntiKt4LCTopo_MET_statusWord;


   return kTRUE;
}

void EventReader::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void EventReader::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

}
