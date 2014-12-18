#include "../scripts/runLocal.C"
#include "../scripts/runProof.C"
#include "../scripts/helperFunc.C"
#include "../scripts/helperJetMETCommon.C"
#include "../scripts/loadLibraries.C"
#include <TFile.h>
#include <TString.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>

void runEflow(TString mode       = "local",         // local, lite, or cluster
TString identifier = "Eflow",                      // tag 
TString dataset    = "JZ1W_example.Eflow",
TString username   = "pnef",                               // username (e.g. swiatlow, fizisist)
bool mcweights     = false,                                 // use mc weights?
bool debug         = false,                                // debug mode
Long64_t nentries  = 100                              // nevents
    ) 
{ 
    
    TString date(currentDateTime().c_str());
    identifier = date+"_"+identifier;

    ///----------------------------------------------------------------
    /// Load libraries , set the config file, treenam, and cluster info
    ///----------------------------------------------------------------

    cout << "trying to load libraries" << endl; 
    loadLibraries();

    cout << " Libraries loaded " << endl;

    // SetConfig 
    TString configfile("../config/Eflow.config");

    
    // Best to leave alone  
    TString pathLite("");
    TString pathCluster("root://atlprf01.slac.stanford.edu:2094//atlas/output/");
    pathCluster.Append(username);
    pathCluster.Append("/");

    // Determine eventbuilder from dataset name
    TString eventbuilder(dataset);
    eventbuilder.Remove(0,eventbuilder.Last('.')+1); 
    
    //Change if defaulting to wrong TTree, otherwise leave
    TString treename = "test";
   
 
    ///----------------------------------------------------------------
    /// Filename paths, URLs for PROOF running
    ///----------------------------------------------------------------
    TString url(mode);
    TString path("");
    if(mode.CompareTo("lite")==0) {
        url = "lite://";
        path = pathLite;
    }
    else if(mode.CompareTo("cluster")==0) {
        url = TString(username+"@atlprf01.slac.stanford.edu");
        path = pathCluster;
    }
    
    // Make an options file, edit as needed
    TFile* options = new TFile("options.root","RECREATE");

    ///----------------------------------------------------------------
    /// Overall Configuration
    ///----------------------------------------------------------------
    bool doBasic          = true;
    bool doTrack          = false;
    bool doVertex         = false;
    bool doLCCluster      = false; 
    bool doEMCluster      = false;
    bool doTruth          = true;
    float LUMI               = 1;

    bool doEflow          = true;


    ///----------------------------------------------------------------
    /// Nominal Configuration
    /// set up the actual analyses
    ///----------------------------------------------------------------
    Config* Eflow = new Config("Eflow",configfile);
    Eflow->Set("ANALYSIS","Eflow");
    Eflow->Set("DEBUG",debug);
    
    Config* chain = new Config("chain",configfile);
    chain->AddVec("ANALYSIS");
    chain->Add("ANALYSIS",Eflow);

    // set up configurations, this overwrites configs from configfile
    chain->Set("DEBUG"           , debug           );
    chain->Set("MCWEIGHTS"       , mcweights       );
    chain->Set("DOBASIC"         , doBasic         );
    chain->Set("DOTRACK"         , doTrack         );
    chain->Set("DOLCCLUSTER"     , doLCCluster     );
    chain->Set("DOEMCLUSTER"     , doEMCluster     );
    chain->Set("DOTRUTH"         , doTruth         );
    chain->Set("DOVTX"           , doVertex        );
    chain->Set("LUMI"            , LUMI);
    chain->Set("DOEFLOW"         , doEflow);

  

    // set cuts and selections
    chain->Write();


    WriteJetCalibrationObjects(options);
    WriteGRLObject("data12_8TeV.periodAB_HEAD_DQDefects-00-01-00_PHYS_StandardGRL_All_Good.xml");



    //if (chain->Exists("GRL")) WriteGRLObject(chain->String("GRL"));  

    ///----------------------------------------------------------------
    /// ProofAna global Config object
    ///----------------------------------------------------------------
    Config* confProofAna = new Config("ProofAna");
    
    confProofAna->Set("DEBUG"          , false        );  // "false", 0, "0" etc. also works
    confProofAna->Set("SAVETIMERS"     , false        );  // ProofAna timer histos in output file   
    confProofAna->Set("IDENTIFIER"     , identifier   );
    confProofAna->Set("DATASET"        , dataset      );
    confProofAna->Set("OUTPUTPATH"     , path         );
    confProofAna->Set("EVENTBUILDER"   , eventbuilder );
    confProofAna->Set("MERGE",true);     // enable dataset mode
   
    cout << "set eventbuilder to " << eventbuilder << endl;
 
    ///----------------------------------------------------------------
    /// Read information used in MC weighting, multi-dataset jobs
    ///----------------------------------------------------------------
    ReadDatasetInfo(dataset  , confProofAna  ); 
    //WriteGroomedPRWO(options , "EF_j240_a4tc_EFFS" );
    confProofAna->Write();
    options->Close();
    delete options;
 
 
    cout << "All setup, ready to go " << endl; 
    int runNevents=1; 
 

    // Decide to run local or on the cluster
    if(mode.CompareTo("local")==0) runLocal(dataset,treename,nentries);
    else{
        runProof(url,dataset,-1,treename);
    }
    gSystem->Unlink("options.root");

}


const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y%m%d.%H.%M", &tstruct);
    return buf;
}
