/**************************************************************************
 **
 **   File:         Analysis_GRJETSexample.h
 **
 **   Description:  Analysis class for analyzing the v7 GRJETS D3PDs. Use
 **                 cases include but are not limited to the following:
 **
 **                   -- Measurement of performance characteristics of
 **                      non-standard and groomed jets
 **                   -- Measurement of systematics associated with jet
 **                      shapes and kinematic (E, pT, m) scales and resol.
 **                   -- Measurement of in-situ jet mass via hadronic W
 **                      and Z peaks
 **                   -- Observation of hadronic top quark mass peaks as
 **                      both a demonstration and a validation of 3-body
 **                      mass calibrations
 **                 
 **
 **   Authors:      D. W. Miller and M. Swiatlowski
 **
 **   Created:      2012-02-22
 **   Modified:     2012-02-22 - DWM
 **                 2012-05-09 - DWM
 **
 **************************************************************************/

#ifndef Analysis_GRJETSexample_h
#define Analysis_GRJETSexample_h

#include "AnalysisBase.h"
#include "Analysis_JetMET_Base.h"

using std::cout;
using std::endl;


class Analysis_GRJETSexample : public Analysis_JetMET_Base {

public :

    Analysis_GRJETSexample(TTree* /*tree*/ = 0) { fDetail = false; }
    virtual ~Analysis_GRJETSexample() { }

    ClassDef(Analysis_GRJETSexample, 0);

private :

    Bool_t  fDetail;
	
    bool    ProcessEvent();
    void    WorkerBegin(); 
    void    WorkerTerminate();
    void    Book(const TString& prefix);
    void    BookBasic();
    void    BookDetail();
    
    bool doJetStructure;
	bool doParentChild;
	bool doConstituents;
	bool doTruthConstituents;
	bool doTrack;
	bool doPhotons;
	bool doLCCluster;
	bool doEMCluster;
	bool doTruth;
	bool doVertex;
	bool doTruthLinks;
	bool doTruthJetLinks;
	bool doTrackJetLinks;
	bool doTrigger;
	
	TString smallJetType;

    TString pre;

    TString Pre(){ return pre; }	
    TString GetPtBin(int iJET);
    TString GetEtaBin(int iJET);

    Bool_t PassesJetCuts(int iJET);
    void   DumpJetInfo(int iJET);
 
    vector<double>  ptBounds;
    vector<double>  etaBounds;
    
    vector<float> lumi;
    vector<TString> trigVec;
    vector<TString> jetVec;

    void SetTriggerWeight(int);
};

#endif

