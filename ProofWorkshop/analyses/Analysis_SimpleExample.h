/**************************************************************************
 **
 **   File:         Analysis_SimpleExample.h
 **
 **   Description:  Computation and plotting of SimpleExample studies.
 **                 
 ** 
 **   Authors:      M. Swiatlowski
 **
 **   Created:      2013-01-22
 **
 **************************************************************************/

#ifndef Analysis_SimpleExample_h
#define Analysis_SimpleExample_h

#include "Analysis_JetMET_Base.h"
 
using std::cout;
using std::endl;



class Analysis_SimpleExample : public Analysis_JetMET_Base {

 public :
  
  Analysis_SimpleExample(TTree* /*tree*/ = 0) { 
    fDetail = false; 
  }
  
  virtual ~Analysis_SimpleExample() { }
  
  ClassDef(Analysis_SimpleExample, 0);
  
  
  
  Bool_t  fDetail;
  
  virtual bool    ProcessEvent();
  virtual void    WorkerBegin(); 
  virtual void    WorkerTerminate();
  
  
  AnaKey GetPtBin(const MomKey JetKey, const int iJet);
  AnaKey GetEtaBin(const MomKey JetKey, const int iJet);
  
  bool   MakeJetMassCut(MomKey JetKey);
  bool   MakeJetPtCut(MomKey JetKey);

  void   CalculateVolatilities(const MomKey JetKey, const MomKey QKey, const int NJetsCompute = 2);

  // helper functions to facilitate similar types of plots
  void MakeJetPlots(const MomKey JetKey);


  private :			  
    vector<double>  ptBounds;
    vector<double>  etaBounds;

};

#endif

