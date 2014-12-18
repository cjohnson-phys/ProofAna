runExample() {

  gROOT->ProcessLine(".exception");

  gSystem->AddIncludePath("-I/usera/khoo/Work_2013/TestAreas/METUtil_dev/Reconstruction/Jet/JetAnalysisTools/ApplyJetResolutionSmearing/");
  gSystem->AddIncludePath("-I/usera/khoo/Work_2013/TestAreas/METUtil_dev/Reconstruction/Jet/ApplyJetCalibration");
  gSystem->AddIncludePath("-I/usera/khoo/Work_2013/TestAreas/METUtil_dev/Reconstruction/Jet/JetUncertainties");
  gSystem->AddIncludePath("-I/usera/khoo/Work_2013/TestAreas/METUtil_dev/Reconstruction/Jet/JetResolution");
  gSystem->AddIncludePath("-I/usera/khoo/Work_2013/TestAreas/METUtil_dev/Reconstruction/egamma/egammaAnalysis/egammaAnalysisUtils");
  gSystem->AddIncludePath("-I/usera/khoo/Work_2013/TestAreas/METUtil_dev/PhysicsAnalysis/MuonID/MuonIDAnalysis/MuonMomentumCorrections");
  gSystem->AddIncludePath("-I/usera/khoo/Work_2013/TestAreas/METUtil_dev/PhysicsAnalysis/TauID/TesUncertaintyProvider");

  gSystem->AddLinkedLibs("-L/usera/khoo/Work_2013/TestAreas/METUtil_dev/InstallArea/x86_64-slc5-gcc43-opt/lib");
  gSystem->AddLinkedLibs("-lApplyJetCalibrationLib");
  gSystem->AddLinkedLibs("-lApplyJetResolutionSmearing");
  gSystem->AddLinkedLibs("-lJetUncertainties");
  gSystem->AddLinkedLibs("-lJetResolution");
  gSystem->AddLinkedLibs("-lMuonMomentumCorrections");
  gSystem->AddLinkedLibs("-legammaAnalysisUtils");
  gSystem->AddLinkedLibs("-lTesUncertaintyProvider");
  gSystem->AddLinkedLibs("-lMissingETUtilityLib");

  gROOT->ProcessLine(".L EventReader.C+");

//   TFile* rootfile = TFile::Open("mc12_8TeV.105200.McAtNloJimmy_CT10_ttbar/NTUP_JETMET.00955143._000216.root.1");
//  TFile* rootfile = TFile::Open("/r02/atlas/khoo/sample_D3PD/CellOutSTVF_check/mc12_8TeV.107663.AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp3.merge.NTUP_JETMET.e1218_s1469_s1470_r3542_r3549_p1344_tid01115626_00/NTUP_JETMET.01115626._000007.root.1");
//  TFile* rootfile = TFile::Open("/r02/atlas/khoo/sample_D3PD/non_SUSY/user.sresconi.mc12_8TeV.147803.PowhegPythia8_AU2CT10_Wminenu.merge.AOD.e1169_s1469_s1470_r3542_r3549.R172test.JETMET.v6_EXT0.120607151801/user.sresconi.006202._00156.qcd.root");
//  TFile* rootfile = TFile::Open("/r02/atlas/khoo/sample_D3PD/CellOutSTVF_check/mc12_8TeV.107663.AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp3.merge.NTUP_SMWZ.e1218_s1469_s1470_r3542_r3549_p1328_tid01109228_00/NTUP_SMWZ.01109228._000004.root.1");
//  TTree* physics = (TTree*) rootfile->Get("physics");
//  physics->Process("Example.C+");

   TFile* rootfile = TFile::Open("/r02/atlas/khoo/D3PD/ElJetOL/mc12_8TeV.107654.AlpgenJimmy_AUET2CTEQ6L1_ZeeNp4.merge.NTUP_SUSY.e1571_s1499_s1504_r3658_r3549_p1328/NTUP_SUSY.01116582._000001.root.1");
   TTree* susy = (TTree*) rootfile->Get("susy");
   susy->Process("Example.C+");
}
