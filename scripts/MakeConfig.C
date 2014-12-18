#include "MakeConfig.h"
#include <iostream>
#include <fstream>

#include <TH1F.h>
#include <TH2F.h>
#include <TFile.h>

///=========================================
/// initialize: this initializes the PRW
///=========================================
bool MakeConfig::initialize(const TString period, TString name) 
{

  if (m_verbose) cout << "MakeConfig::initialize(): Making the MC config file with PERIOD = " << period << "; NAME = " << name << endl;

  // Initialize the pile-up reweighting tool
  m_pileupTool = new Root::TPileupReweighting(name);
  if (m_verbose) {
    m_pileupTool->EnableDebugging(true);
    cout << "MakeConfig::initialize(): Enabled debugging and setting PERIOD = " << period << endl;
  }
  //m_pileupTool->UsePeriodConfig(period);
  m_pileupTool->AddPeriod(195847,200804,999999);
  m_pileupTool->AddBinning("pileup",50,-0.5,49.5);
  //m_pileupTool->AddBinning("pileup",100,0.,50.0);
  m_pileupTool->Initialize();

  return true;   
}


///=========================================
/// Run: this is the event loop
///=========================================
void MakeConfig::Run()
{
   if (m_verbose) cout << "MakeConfig::Run(): Running the event loop" << endl;

   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   for (Long64_t jentry=0; jentry < nentries; jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      processEvent(ientry);
   }
}


///=========================================
/// processEvent: This fills the mu histo
///=========================================
bool MakeConfig::processEvent(Long64_t ientry) 
{
  if (m_verbose) cout << "MakeConfig::processEvent(): Processing event ientry = " << ientry << endl;

  // Get run & event info
  b_averageIntPerXing ->GetEntry(ientry);
  b_mc_channel_number ->GetEntry(ientry);
  b_RunNumber         ->GetEntry(ientry);
  b_mc_event_weight   ->GetEntry(ientry);
//cout << "MakeConfig::processEvent(): Getting ww" << endl;  b_mcevt_weight      ->GetEntry(ientry);

  

  if (m_verbose) {
    cout << "MakeConfig::processEvent(): Filling the mu histogram " << endl;
    cout << "MakeConfig::processEvent(): RunNumber = " << RunNumber 
                           << "; mc_channel_number = " << mc_channel_number 
                           << "; mcevt_weight      = " << mc_event_weight
                           << "; averageIntPerXing = " << averageIntPerXing
                           << endl;
  }
  // Fill mu histogram
//  m_pileupTool        ->Fill( (Int_t)RunNumber, (Int_t)mc_channel_number, (mcevt_weight->at(0)).at(0), (Float_t)averageIntPerXing);
  m_pileupTool        ->Fill( (Int_t)RunNumber, (Int_t)mc_channel_number, mc_event_weight, (Float_t)averageIntPerXing);

  return true;
}


///=========================================
/// finalize: this writes out the histo
///=========================================
bool MakeConfig::finalize() 
{
  if (m_verbose) cout << "MakeConfig::finalize(): Writing PRW file to disk" << endl;

  m_pileupTool->WriteToFile();

  return true;
  
}

