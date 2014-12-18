#include "../scripts/runLocal.C"
#include "../scripts/runProof.C"
#include "../scripts/runGrid.C"
#include "../scripts/helperFunc.C"
#include "../scripts/helperExampleFunc.C"
#include "../scripts/loadLibraries.C"
#include <TFile.h>
#include <TString.h>

void runGRJETSv11(TString mode       = "lite",            // local, lite, or cluster
               TString identifier = "run1",               // tag 
               TString dataset    = "Wprime1200.GRJETSv11",  // dataset name as in the fileList  
               TString username   = "swiatlow",           // username (e.g. swiatlow, fizisist)
               bool mcweights     = false,                 // use mc weights?
               bool doHists       = true,                 // do histograms or enable dataset mode 
               bool doSys         = false,                // do systematics 
               bool debug         = false,                // turn on debugging
               int  nWorkers      = 4                     //specify number of workers for proof(-1 for all available)
             ) 
{
    
    ///----------------------------------------------------------------
    /// Load libraries , set the config file, treenam, and cluster info
    ///----------------------------------------------------------------

    TString gridusername = "mswiatlo";
    cout << "trying to load libraries" << endl;
    loadLibraries();

    cout << " Libraries loaded " << endl;

    // SetConfig
    TString configfile("../config/grjetsv11.config");

    // Change if defaulting to wrong TTree, otherwise leave
    TString treename("jets");
    
    // Best to leave alone  
    TString pathLite("");

    TString pathCluster("root://atlprf01.slac.stanford.edu:2094//atlas/output/");

    pathCluster.Append(username);
    pathCluster.Append("/");



    // Determine eventbuilder from dataset name
    TString eventbuilder(dataset);
    eventbuilder.Remove(0,eventbuilder.Last('.')+1);
    
    ///----------------------------------------------------------------
    /// Filename paths, URLs for PROOF running
    ///----------------------------------------------------------------
    TString url(mode);
    TString path("");
    if (mode.CompareTo("lite")==0) {
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
    bool doPRW           = false;
    bool doBasic         = true;
    bool doTruthLinks    = false;
    bool doTrackJetLinks = true;
    bool doTruthJetLinks = true;
    bool doJetStructure  = true;
    bool doConstituents  = true;
    bool doTruthConstit  = true;
    bool doParentChild   = true;
    bool doTrack         = true;
    bool doLCCluster     = true;
    bool doEMCluster     = false;
    bool doTruth         = true;
    bool doVertex        = true;
    bool doPhotons       = false;
    
    /// JET TYPES
    bool doSomeJetTypes  = false;
    bool doMinJetTypes   = true;
    
    /// SELECTIONS
    float minJetPt       =  20.000;
    float maxJetEta      =   3.199;
    float minFatJetPt    = 100.000;
    float minJetJVF      =   0.750;
    float maxJetTrkDR    =   0.300;
    float maxJetTruthDR  =   0.300;
    TString badJetType   = "AntiKt4LCTopoAOD";
    TString badJetDef    = "isBadLooseMinus";
    
    /// Substructure
    int   nStdJetCut     = 4;
    float lowMassCRcut   = 100.000;
    float threeBodyCRcut =   0.700;
    
    ///----------------------------------------------------------------
    /// Jet types
    ///----------------------------------------------------------------
    
    TString aktCal = "AntiKt10LCTopo";
    TString aktTrk = "AntiKt10TrackZ";
    TString aktTru = "AntiKt10Truth";
    TString caCal  = "CamKt12LCTopo";
    TString caTrk  = "CamKt12TrackZ";
    TString caTru  = "CamKt12Truth";
    
    TString aktCalTrim = "AntiKt10LCTopoTrimmedPtFrac1SmallR20,AntiKt10LCTopoTrimmedPtFrac3SmallR20,AntiKt10LCTopoTrimmedPtFrac5SmallR20,AntiKt10LCTopoTrimmedPtFrac1SmallR30,AntiKt10LCTopoTrimmedPtFrac3SmallR30,AntiKt10LCTopoTrimmedPtFrac5SmallR30";
    TString aktCalPrun = "AntiKt10LCTopoPrunedKtRcutFactor10Zcut5,AntiKt10LCTopoPrunedKtRcutFactor20Zcut5,AntiKt10LCTopoPrunedKtRcutFactor30Zcut5,AntiKt10LCTopoPrunedKtRcutFactor10Zcut10,AntiKt10LCTopoPrunedKtRcutFactor20Zcut10,AntiKt10LCTopoPrunedKtRcutFactor30Zcut10";
    TString aktTrkTrim = "AntiKt10TrackZTrimmedPtFrac1SmallR20,AntiKt10TrackZTrimmedPtFrac3SmallR20,AntiKt10TrackZTrimmedPtFrac5SmallR20,AntiKt10TrackZTrimmedPtFrac1SmallR30,AntiKt10TrackZTrimmedPtFrac3SmallR30,AntiKt10TrackZTrimmedPtFrac5SmallR30";
    TString aktTrkPrun = "AntiKt10TrackZPrunedKtRcutFactor10Zcut5,AntiKt10TrackZPrunedKtRcutFactor20Zcut5,AntiKt10TrackZPrunedKtRcutFactor30Zcut5,AntiKt10TrackZPrunedKtRcutFactor10Zcut10,AntiKt10TrackZPrunedKtRcutFactor20Zcut10,AntiKt10TrackZPrunedKtRcutFactor30Zcut10";
    TString aktTruTrim = "AntiKt10TruthTrimmedPtFrac1SmallR20,AntiKt10TruthTrimmedPtFrac3SmallR20,AntiKt10TruthTrimmedPtFrac5SmallR20,AntiKt10TruthTrimmedPtFrac1SmallR30,AntiKt10TruthTrimmedPtFrac3SmallR30,AntiKt10TruthTrimmedPtFrac5SmallR30";
    TString aktTruPrun = "AntiKt10TruthPrunedKtRcutFactor10Zcut5,AntiKt10TruthPrunedKtRcutFactor20Zcut5,AntiKt10TruthPrunedKtRcutFactor30Zcut5,AntiKt10TruthPrunedKtRcutFactor10Zcut10,AntiKt10TruthPrunedKtRcutFactor20Zcut10,AntiKt10TruthPrunedKtRcutFactor30Zcut10";
    
    TString caCalTrim  = "CamKt12LCTopoTrimmedPtFrac1SmallR20,CamKt12LCTopoTrimmedPtFrac3SmallR20,CamKt12LCTopoTrimmedPtFrac5SmallR20,CamKt12LCTopoTrimmedPtFrac1SmallR30,CamKt12LCTopoTrimmedPtFrac3SmallR30,CamKt12LCTopoTrimmedPtFrac5SmallR30";
    TString caCalPrun  = "CamKt12LCTopoPrunedKtRcutFactor10Zcut5,CamKt12LCTopoPrunedKtRcutFactor20Zcut5,CamKt12LCTopoPrunedKtRcutFactor30Zcut5,CamKt12LCTopoPrunedKtRcutFactor10Zcut10,CamKt12LCTopoPrunedKtRcutFactor20Zcut10,CamKt12LCTopoPrunedKtRcutFactor30Zcut10";
    TString caCalFilt  = "CamKt12LCTopoSplitFilteredmassFraction20minSplitR0,CamKt12LCTopoSplitFilteredmassFraction33minSplitR0,CamKt12LCTopoSplitFilteredmassFraction67minSplitR0";
    TString caTrkTrim  = "CamKt12TrackZTrimmedPtFrac1SmallR20,CamKt12TrackZTrimmedPtFrac3SmallR20,CamKt12TrackZTrimmedPtFrac5SmallR20,CamKt12TrackZTrimmedPtFrac1SmallR30,CamKt12TrackZTrimmedPtFrac3SmallR30,CamKt12TrackZTrimmedPtFrac5SmallR30";
    TString caTrkPrun  = "CamKt12TrackZPrunedKtRcutFactor10Zcut5,CamKt12TrackZPrunedKtRcutFactor20Zcut5,CamKt12TrackZPrunedKtRcutFactor30Zcut5,CamKt12TrackZPrunedKtRcutFactor10Zcut10,CamKt12TrackZPrunedKtRcutFactor20Zcut10,CamKt12TrackZPrunedKtRcutFactor30Zcut10";
    TString caTrkFilt  = "CamKt12TrackZSplitFilteredmassFraction20minSplitR0,CamKt12TrackZSplitFilteredmassFraction33minSplitR0,CamKt12TrackZSplitFilteredmassFraction67minSplitR0";
    TString caTruTrim  = "CamKt12TruthTrimmedPtFrac1SmallR20,CamKt12TruthTrimmedPtFrac3SmallR20,CamKt12TruthTrimmedPtFrac5SmallR20,CamKt12TruthTrimmedPtFrac1SmallR30,CamKt12TruthTrimmedPtFrac3SmallR30,CamKt12TruthTrimmedPtFrac5SmallR30";
    TString caTruPrun  = "CamKt12TruthPrunedKtRcutFactor10Zcut5,CamKt12TruthPrunedKtRcutFactor20Zcut5,CamKt12TruthPrunedKtRcutFactor30Zcut5,CamKt12TruthPrunedKtRcutFactor10Zcut10,CamKt12TruthPrunedKtRcutFactor20Zcut10,CamKt12TruthPrunedKtRcutFactor30Zcut10";
    TString caTruFilt  = "CamKt12TruthSplitFilteredmassFraction20minSplitR0,CamKt12TruthSplitFilteredmassFraction33minSplitR0,CamKt12TruthSplitFilteredmassFraction67minSplitR0";
    
    
    //// Make derived lists
    TString aktData = aktCal + "," + aktTrk + "," + aktCalTrim + "," + aktCalPrun + "," + aktTrkTrim + "," + aktTrkPrun;
    TString aktMC   = aktTru + "," + aktTruTrim + "," + aktTruPrun;
    
    TString caData = caCal + "," + caTrk + "," + caCalTrim + "," + caCalPrun + "," + caCalFilt + "," + caTrkTrim + "," + caTrkPrun + "," + caTrkFilt;
    TString caMC   = caTru + "," + caTruTrim + "," + caTruPrun + "," + caTruFilt;
    
    
    //// DEFAULT FULL LIST
    TString jetTypes = aktData + "," + caData;
    if (!dataset.Contains("data")) jetTypes += "," + aktMC + "," + caMC;

    //// REDUCED SET OF JETS
    if (doSomeJetTypes) {
      jetTypes   = "AntiKt10LCTopo,CamKt12LCTopo,AntiKt10LCTopoTrimmedPtFrac3SmallR30,AntiKt10LCTopoTrimmedPtFrac5SmallR30,CamKt12LCTopoSplitFilteredmassFraction67minSplitR0,AntiKt10TrackZ,CamKt12TrackZ,AntiKt10TrackZTrimmedPtFrac3SmallR30,AntiKt10TrackZTrimmedPtFrac5SmallR30,CamKt12TrackZSplitFilteredmassFraction67minSplitR0";
        if (!dataset.Contains("data")) jetTypes += ",AntiKt10Truth,CamKt12Truth,AntiKt10TruthTrimmedPtFrac3SmallR30,AntiKt10TruthTrimmedPtFrac5SmallR30,CamKt12TruthSplitFilteredmassFraction67minSplitR0";
    }
    
    else if (!doSomeJetTypes && doMinJetTypes) {
      jetTypes   = "AntiKt10LCTopo,CamKt12LCTopo,AntiKt10LCTopoTrimmedPtFrac5SmallR30,CamKt12LCTopoSplitFilteredmassFraction67minSplitR0,AntiKt10TrackZ,CamKt12TrackZ,AntiKt10TrackZTrimmedPtFrac5SmallR30,CamKt12TrackZSplitFilteredmassFraction67minSplitR0";
        if (!dataset.Contains("data")) jetTypes += ",AntiKt10Truth,CamKt12Truth,AntiKt10TruthTrimmedPtFrac5SmallR30,CamKt12TruthSplitFilteredmassFraction67minSplitR0";
    }
        
    //jetTypes = aktCal + "," + aktTrk + "," + aktCalTrim + "," + aktTrkTrim;
    //jetTypes = caCal + "," + caTrk + "," + caCalTrim + "," + caTrkTrim;
    //jetTypes = aktCalPrun + "," + aktTrkPrun + "," + caCalPrun + "," + caTrkPrun;
    //jetTypes = caCalFilt + "," + caTrkFilt;
  
    
    // Be careful when loading up subjettypes and btagtypes: check that 
    // these exist in the D3PD before trying to register them!
    TString subjetTypes = "AntiKt10LCTopoTrimmedSubjetsPtFrac3SmallR30,AntiKt10TrackZTrimmedSubjetsPtFrac3SmallR30,AntiKt10TruthTrimmedSubjetsPtFrac3SmallR30";
    TString btagTypes = "AntiKt10LCTopoTrimmedSubjetsPtFrac3SmallR30";


    ///---------------------------------------------------------------
    /// New jet types! These will be constructed on the fly
    ///---------------------------------------------------------------

    TString baseCustomTrimming = "AntiKtLCTopo15";
    TString ptFracCustomTrimming = "0.05";
    TString smallRCustomTrimming = "0.3";


    ///----------------------------------------------------------------
    /// Nominal Configuration
    ///----------------------------------------------------------------
    Config* chain = new Config("chain",configfile);
    chain->AddVec("ANALYSIS");


    Config* setup = new Config("setup", configfile);
    setup->Set("ANALYSIS","GRJETSexample_setup");
    setup->Set("DEBUG",debug);
    chain->Add("ANALYSIS",setup);

    Config* example = new Config("example", configfile);
    example->Set("ANALYSIS","GRJETSexample");
    example->Set("DEBUG",debug);
    chain->Add("ANALYSIS",example);
    

    cout << endl << "+++ Using jet types: " << jetTypes << endl << endl;


    chain->Set("MCWEIGHTS"       , mcweights       );
    chain->Set("DEBUG"           , debug           );
    chain->Set("PILE"            , doPRW           );
    chain->Set("DOBASIC"         , doBasic         );
    chain->Set("DOTRUTHLINKS"    , doTruthLinks    );
    chain->Set("DOTRACKJETLINKS" , doTrackJetLinks );
    chain->Set("DOTRUTHJETLINKS" , doTruthJetLinks );
    chain->Set("DOJETSTRUCT"     , doJetStructure  );
    chain->Set("DOCONSTIT"       , doConstituents  );
    chain->Set("DOTRUTHCONSTIT"  , doTruthConstit  );
    chain->Set("DOPARENTCHILD"   , doParentChild   );
    chain->Set("DOTRACK"         , doTrack         );
    chain->Set("DOLCCLUSTER"     , doLCCluster     );
    chain->Set("DOEMCLUSTER"     , doEMCluster     );
    chain->Set("DOTRUTH"         , doTruth         );
    chain->Set("DOVTX"           , doVertex        );
    chain->Set("DOPHOTON"        , doPhotons       );
    
    /// Set Systematics
    chain->Set("DOTRACKSYST"     , false           );
    chain->Set("DOJETSYS"        , 0               );
    
    /// Set cuts and jet types and such
    chain->Set("BASECUSTOMTRIMMING",   baseCustomTrimming);
    chain->Set("PTFRACCUSTOMTRIMMING", ptFracCustomTrimming);
    chain->Set("SMALLRCUSTOMTRIMMING", smallRCustomTrimming);
    chain->Set("JETTYPES"       , jetTypes         );
    chain->Set("SUBJETTYPES"    , subjetTypes      );
    chain->Set("BTAGTYPES"      , btagTypes        );
    chain->Set("BADJETTYPE"     , badJetType       );
    chain->Set("BADJETDEF"      , badJetDef        );
    chain->Set("MINJETPT"       , minJetPt         );
    chain->Set("MAXJETETA"      , maxJetEta        );
    chain->Set("MINFATJETPT"    , minFatJetPt      );
    chain->Set("MAXFATJETETA"   , maxJetEta        );
    chain->Set("MINJETJVF"      , minJetJVF        );
    chain->Set("MAXJETTRKJETDR" , maxJetTrkDR      );
    chain->Set("MAXTRUTHJETDR"  , maxJetTruthDR    );
    
    chain->Set("NStdJetCut"     , 4                );
    chain->Set("LowMassCRcut"   , 100.             );
    chain->Set("ThreeBodyCRcut" , 0.7              );
    chain->Set("y12CRcut"       , 0.4              );
    
    ///----------------------------------------------------------------
    /// Trigger Information
    ///----------------------------------------------------------------
    TString trigTypes  = "EF_j360_a10tcem";
    TString trigParams = "jet_AntiKt10LCTopo_pt";
    TString trigCuts   = "450000.";               /// NEEDS TO BE IN MEV
    TString trigLumis  = "5725.04";               /// UPDATE ME!
    
    chain->Set("TRIGTYPES"      , trigTypes      );
    chain->Set("TRIGPARAM"      , trigParams     );
    chain->Set("TRIGCUT"        , trigCuts       );
    chain->Set("TRIGLUMI"       , trigLumis      );
    
    ///----------------------------------------------------------------
    /// Luminosity for trigger weighting
    ///----------------------------------------------------------------
    Float_t lumiVal = 5725.04;
    
    chain->Set("LUMI"           , lumiVal        );
    
    chain->Write();

    if (chain->Exists("GRL")) WriteGRLObject(chain->String("GRL"));  
  
		
	

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
    if (!doHists) 
      confProofAna->Set("MERGE"        , false        );     // enable dataset mode
    
    ///----------------------------------------------------------------
    /// Read information used in MC weighting, multi-dataset jobs
    ///----------------------------------------------------------------
    ReadDatasetInfo(dataset  , confProofAna  ); 
    WriteGroomedPRWO(options , "EF_j360_a10tcem_PeriodB" );
    confProofAna->Write();  
    options->Close();
    delete options;


    cout << "All setup, ready to go " << endl;    
    // Decide to run local or on the cluster
    if (mode.CompareTo("local") == 0) runLocal(dataset, treename);
    else if(mode.CompareTo("lite")==0||mode.CompareTo("cluster")==0) 
      runProof(url,dataset,-1,treename);
    else if(mode.CompareTo("grid")==0){
      TString gridname = "user."+gridusername+"."+identifier;
      cout << "submitting with gridname " << gridname << endl;
      runGrid(gridname);
    }   
    gSystem->Unlink("options.root");
}
