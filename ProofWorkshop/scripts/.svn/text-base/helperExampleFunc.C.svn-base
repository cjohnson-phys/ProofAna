#include <fstream>

void WriteDefaultQGPRWO(TFile* options, TString file){
  Root::TPileupReweighting* myPile = new Root::TPileupReweighting();
//  myPile->AddConfigFile("../config/lumicalcs_R17/gj.prw.root");
  myPile->AddConfigFile("../utils/PileupReweighting/share/mc11b_defaults.prw.root");
  myPile->AddLumiCalcFile("../config/lumicalcs_R17/"+file+".root");
  myPile->SetUnrepresentedDataAction(2); //Action needs investigation
  myPile->DisableWarnings(true);
  myPile->Initialize();
  myPile->SetName(file);
  options->cd();
  myPile->Write();

}

void WriteGammaQGPRWO(TFile* options, TString file){
  Root::TPileupReweighting* myPile = new Root::TPileupReweighting();
  myPile->AddConfigFile("../config/lumicalcs_R17/gj.prw.root");
  //myPile->AddConfigFile("../utils/PileupReweighting/share/mc11b_defaults.prw.root");
  myPile->AddLumiCalcFile("../config/lumicalcs_R17/"+file+".root");
  myPile->SetUnrepresentedDataAction(2); //Action needs investigation
  myPile->DisableWarnings(true);
  myPile->Initialize();
  myPile->SetName(file);
  options->cd();
  myPile->Write();
}

void WriteDijetQGPRWO(TFile* options, TString file){
  Root::TPileupReweighting* myPile = new Root::TPileupReweighting();
  //myPile->EnableDebugging(true);
  //cout << "Setting up prw object for " << file << ".root" << endl;
  myPile->AddConfigFile("../config/lumicalcs_R17/dj.prw.root");
  //myPile->AddConfigFile("../utils/PileupReweighting/share/mc11b_defaults.prw.root");
  myPile->AddLumiCalcFile("../config/lumicalcs_R17/"+file+".root");
  myPile->SetUnrepresentedDataAction(2); //Action needs investigation
  myPile->DisableWarnings(true);
  myPile->Initialize();
  myPile->SetName(file);
  options->cd();
  myPile->Write();
}

void WriteGroomedPRWO(TFile* options, TString file){
  Root::TPileupReweighting* myPile = new Root::TPileupReweighting();
  //myPile->EnableDebugging(true);
  //cout << "Setting up prw object for " << file << ".root" << endl;
  myPile->AddConfigFile("../config/groomedPRW/groomed.prw.root");
  myPile->AddLumiCalcFile("../config/groomedPRW/"+file+".root");
  myPile->SetUnrepresentedDataAction(2); //Action needs investigation
  myPile->DisableWarnings(true);
  myPile->Initialize();
  myPile->SetName(file);
  options->cd();
  myPile->Write();
}

void WriteHbbPRWO(TFile* options){
  Root::TPileupReweighting* myPile = new Root::TPileupReweighting();
  //myPile->EnableDebugging(true);
  //cout << "Setting up prw object for " << file << ".root" << endl;
  myPile->AddConfigFile("../utils/PileupReweighting/share/mc12a_defaults.prw.root");
  myPile->AddLumiCalcFile("../config/lumicalcs_R17/ilumicalc_histograms_None_200841-212272.root"); //made by mkagan, no prescale in trigger
  myPile->SetUnrepresentedDataAction(2); //Action needs investigation
  myPile->DisableWarnings(true);
  myPile->Initialize();
  myPile->SetName("myPRW_Hbb");
  options->cd();
  myPile->Write();
}

void WriteGRLObject(TString xmlfile)
{
	///++++++++++++++++++++++++++++++++++++++++++++++++
	/// Good Run List reader
	///++++++++++++++++++++++++++++++++++++++++++++++++
	Root::TGoodRunsListReader reader;   
	reader.SetXMLFile(TString("../config/grl/").Append(xmlfile));
	reader.Interpret();
	Root::TGoodRunsList* m_GRL = new Root::TGoodRunsList(reader.GetMergedGoodRunsList());  
	m_GRL->SetName("myGRL");
	m_GRL->Write();
}

