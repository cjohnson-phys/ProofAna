/**************************************************************************
 **
 **   File:         Analysis_Eflow.cxx
 **
 **   Description:  See header
 **                 
 **   Authors:      P. Nef
 **
 **************************************************************************/

#define Analysis_Eflow_cxx

#include "Analysis_Eflow.h"
#include "AnaConfig.h"
#include <TROOT.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TTree.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>      // std::setprecision
#include <cstdlib>
#include <sstream>
#include "TKey.h"
#include "TObjString.h"
#include "TObjArray.h"
#include "TMVA/Reader.h"
#include "TMVA/Config.h"
#include "TMVA/Tools.h"
#include "TMVA/MethodCuts.h"
#include "fastjet/ClusterSequenceArea.hh"
#include "fastjet/ClusterSequenceActiveAreaExplicitGhosts.hh"
#include "fastjet/PseudoJet.hh"
#include "fastjet/tools/Subtractor.hh"


///=========================================
/// WorkerBegin: setup binning, etc
///=========================================
 void Analysis_Eflow::WorkerBegin()
 {
  if (Debug()) cout << "Analysis_Eflow: DEBUG In WorkerBegin() " << endl;

  Analysis_JetMET_Base::WorkerBegin();


  if (Debug()) cout << "Analysis_Eflow: DEBUG Finish WorkerBegin()" << endl;  
} 

///=========================================
/// ProcessEvent: run the analysis
///=========================================  
bool Analysis_Eflow::ProcessEvent()
{

  if (Debug()) cout << "Analysis_Eflow: DEBUG In ProcessEvent(): RunNumber = " << RunNumber() 
		    << "; Channel = " << ChannelNumber() << "; EventNumber = " << EventNumber() << endl;

  OutputDir()->cd();



  cout << ">>> New Event ------------------------------------" << endl;
  for(int iEFO=0; iEFO<recos("EFO"); ++iEFO){
//  reco(iEFO,"EFO").Show();
    if(reco(iEFO,"EFO").Int("eflow_charge")==0) Fill("EFO_neutral_e", reco(iEFO,"EFO").p.E(), 1, 100, 0, 10);
    if(reco(iEFO,"EFO").Int("eflow_charge")!=0) Fill("EFO_charged_e", reco(iEFO,"EFO").p.E(), 1, 100, 0, 10);
  }

  // Make Eflow jets --------------
  fastjet::JetAlgorithm algo = fastjet::antikt_algorithm;
  MakeJets(algo, 0.4, "recosEFO", "Eflow");
// cout << "show jets -------------------" << endl;
  for(int ij=0; ij<jets("AntiKt4Eflow"); ++ij){
//    jet(ij, "AntiKt4Eflow").Show();
  }
//  Show();

  return true;
}

///=========================================
/// WorkerTerminate: clean up
///=========================================
void Analysis_Eflow::WorkerTerminate()
{


  // Nothing more

}



