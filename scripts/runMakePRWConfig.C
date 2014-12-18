#include <string>
#include <fstream>

///=========================================
/// Create a PRW config file
///=========================================
runMakePRWConfig(const char *name = "", const TString period = "MC12a", TString treename = "jets", TString outname = "prw", bool debug = false)
{

  //-------------------------------
  // Compile the processing code
  //-------------------------------
  //gSystem->AddIncludePath(" -I${HOME}/RootUtils ");
  gSystem->Load("libPhysics.so");
  gSystem->Load("libHist");
  gSystem->AddIncludePath(" -I../utils/PileupReweighting ");
  gSystem->Load("PileupReweighting/StandAlone/libPileupReweighting.so");
  gSystem->CompileMacro("MakeConfig.C", "k");

  if (debug) cout << "Compilations are done" << endl;
 
  //-------------------------------
  // Create the TChain
  //-------------------------------
  TChain *inputChain = new TChain(treename); 

  //-------------------------------
  // Fill TChain from the filelists
  //-------------------------------
  ifstream fin( name ); 
  char buffer[2560]; 
  while ( !fin.eof() ) {
    fin.getline( buffer, sizeof(buffer) ); 
    TString buf_str = buffer; 
    if (debug) cout << "Adding file : " << buf_str << endl;
    inputChain->Add(buf_str);
  } 
  fin.close();
  if (debug) cout << "Chain has " << inputChain->GetEntries() << " entries" << endl;

  //-------------------------------
  // Create the analysis & Run!
  //-------------------------------
  MakeConfig myConfig(inputChain, debug);  
  myConfig.initialize(period, outname); 
  myConfig.Run();
  myConfig.finalize(); 
  
}
