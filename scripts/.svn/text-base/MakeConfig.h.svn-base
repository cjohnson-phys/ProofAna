#ifndef MAKECONFIG_H
#define MAKECONFIG_H

#include "PileupReweighting/TPileupReweighting.h"

#include <string>
#include <map>
#include <iostream>
#include <fstream>

#include "TBranch.h"
#include "TChain.h"
#include "TTree.h"
#include "TString.h"

#ifdef __MAKECINT__
#pragma link C++ class vector< vector<double> >;
#endif

class MakeConfig {
  
 public:
  
  MakeConfig(TTree *tree = 0, bool debug = false);
 
  virtual          ~MakeConfig() { }
  virtual void     Run();
  virtual void     InitTree(TTree *tree);
  virtual Int_t    GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
  virtual Long64_t LoadTree(Long64_t entry);

  virtual bool    initialize(const TString period = "MC12a", TString name = "prw");
  virtual void    setVerbose(bool debug = false) { m_verbose = debug; }
  virtual bool    processEvent(Long64_t ientry);
  virtual bool    finalize();

  TTree          *fChain;  
  Int_t           fCurrent; 
  Root::TPileupReweighting* m_pileupTool;

 private:
  
  UInt_t          RunNumber;
  UInt_t          EventNumber;  
  Float_t         actualIntPerXing;
  Float_t         averageIntPerXing;
  UInt_t          mc_channel_number;
  Float_t         mc_event_weight;
  vector<vector<double> > *mcevt_weight;

  TBranch        *b_RunNumber;   
  TBranch        *b_EventNumber;  
  TBranch        *b_actualIntPerXing;  
  TBranch        *b_averageIntPerXing; 
  TBranch        *b_mc_channel_number; 
  TBranch        *b_mc_event_weight;  
  TBranch        *b_mcevt_weight;   
  
  bool m_verbose;

};

#endif // #ifndef MAKECONFIG_H



//#ifdef make_config_cxx

///=========================================
/// Constructor
///=========================================
MakeConfig::MakeConfig(TTree *tree, bool debug)
{

   if (tree == 0) {
     cout << "ERROR! No tree specified" << endl;
     return;
   }
   
   m_verbose = debug;
   
   InitTree(tree);
}

///=========================================
/// LoadTree: loads the tree in the chain
///=========================================
Long64_t MakeConfig::LoadTree(Long64_t entry)
{
   if (m_verbose) cout << "MakeConfig::LoadTree(): Loading the tree" << endl;

   if (!fChain) return -5;

   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;

   if (!fChain->InheritsFrom(TChain::Class()))  return centry;

   TChain *chain = (TChain*)fChain;

   if (chain->GetTreeNumber() != fCurrent) {
      fCurrent = chain->GetTreeNumber();
      if (m_verbose) cout << "MakeConfig::LoadTree(): Current tree number = " << fCurrent << endl;
   }

   return centry;
}

///=========================================
/// InitTree: Sets the branches
///=========================================
void MakeConfig::InitTree(TTree *tree) 
{

  if (m_verbose) cout << "MakeConfig::InitTree(): Initializing the tree" << endl;

  fChain = tree;

  fChain->SetBranchAddress("RunNumber",         &RunNumber,         &b_RunNumber);
  fChain->SetBranchAddress("EventNumber",       &EventNumber,       &b_EventNumber);
  fChain->SetBranchAddress("actualIntPerXing",  &actualIntPerXing,  &b_actualIntPerXing);
  fChain->SetBranchAddress("averageIntPerXing", &averageIntPerXing, &b_averageIntPerXing);
  fChain->SetBranchAddress("mc_channel_number", &mc_channel_number, &b_mc_channel_number);
  fChain->SetBranchAddress("mc_event_weight",   &mc_event_weight,   &b_mc_event_weight);
  fChain->SetBranchAddress("mcevt_weight",      &mcevt_weight,      &b_mcevt_weight);

  fChain->SetBranchStatus("*", 0);
  fChain->SetBranchStatus("RunNumber", 1);
  fChain->SetBranchStatus("EventNumber", 1);
  fChain->SetBranchStatus("actualIntPerXing", 1);
  fChain->SetBranchStatus("averageIntPerXing", 1);
  fChain->SetBranchStatus("mc_channel_number", 1);
  fChain->SetBranchStatus("mc_event_weight", 1);
  fChain->SetBranchStatus("mcevt_weight", 1);

  if (m_verbose) cout << "MakeConfig::InitTree(): Finished" << endl;

}

//#endif // #ifdef make_config_cxx
