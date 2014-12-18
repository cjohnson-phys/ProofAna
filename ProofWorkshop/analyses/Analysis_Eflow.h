/**************************************************************************
 **
 **   File:         Analysis_Eflow.h
 **
 **   Description:  Prototype PileUp Analysis
 **                 
 ** 
 **   Authors:      P. Nef
 **
 **   Created:      4/12/2013
 **
 **************************************************************************/

#ifndef Analysis_Eflow_h
#define Analysis_Eflow_h

#include "Analysis_JetMET_Base.h"
#include <TTree.h>
#include "Particle.h"
#include "TMVA/Reader.h"

 
using std::cout;
using std::endl;


class Analysis_Eflow : public Analysis_JetMET_Base {

 public :
  
  Analysis_Eflow(TTree* /*tree*/ = 0) { 
    fDetail = false; 
  }
  
  virtual ~Analysis_Eflow() { }
  
  ClassDef(Analysis_Eflow, 0);
  
  Bool_t  fDetail;
  
  virtual bool    ProcessEvent();
  virtual void    WorkerBegin(); 
  virtual void    WorkerTerminate();


  private :			  


};

#endif

