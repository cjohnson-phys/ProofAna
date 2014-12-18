/**************************************************************************
 **
 **   File:         Analysis_GRJETSexample_setup.h
 **
 **   Description:  Base Analysis class for H-->bb analysess analyzing the v7 HbbSubstructure D3PDs. 
 **                                  
 **
 **   Authors:      M. Kagan
 **
 **   Created:      2012-08-16
 **
 **************************************************************************/

#ifndef Analysis_GRJETSexample_setup_h
#define Analysis_GRJETSexample_setup_h

#include "AnalysisBase.h"
#include "Analysis_JetMET_Base.h"

//#include "TLVC.h"

#include <map>
#include <string>
#include <TH1.h>
#include "fastjet/PseudoJet.hh"
#include "fastjet/tools/Filter.hh"
#include "fastjet/ClusterSequenceArea.hh"
#include "fastjet/GhostedAreaSpec.hh"


using std::cout;
using std::endl;


class Analysis_GRJETSexample_setup : public Analysis_JetMET_Base {

public :

  Analysis_GRJETSexample_setup(TTree* /*tree*/ = 0) { 
    fDetail = false; 
  }
  virtual ~Analysis_GRJETSexample_setup() { }    
  
  ClassDef(Analysis_GRJETSexample_setup, 0);
  
 

  Bool_t  fDetail;
	
  bool    ProcessEvent();
  void    WorkerBegin();
  void    WorkerTerminate();

  

 
    /////////////////////////////////////

    // Calculational Tools: Use these on jets to add extra info
    // Safe to call more than once on a jet; if it detects an already
    // existing variable of the name it's trying to add, it will abort
    // for that jet.
    // Make new jets!
    bool AddTrimmedJets(TString jetCollection, float ptFrac = 0.05, float R = 0.3);

    // Track Quality Selection
    bool AddGoodTracks();

    // Helper Functions for manipulation of jet substructure info
    bool CopyParentConstituents(Particle*);
    bool AddTrackingDR(Particle* jet, float dr);



    vector<TString> jetVec;
    vector<TString> newJetType;

    vector<TString> baseCustomTrimming;
    vector<float>   ptFracCustomTrimming;
    vector<float>   smallRCustomTrimming;


 private:
   
};

#endif

