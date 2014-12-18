/*
 *  Calculates global sequential jet calibration factors
 *   -Requires jet branches trackWIDTH, nTrk, Tile0, EM3
 *   -Apply using
 *    1. No jet area correction: JetCalibrationTool::ApplyOffsetEtaJESGSC
 *    2. With jet area correction (not yet supported): JetCalibrationTool::ApplyJetAreaOffsetEtaJESGSC
 *   -GSC correction factor is returned by JetCalibrationTool::GetGSC
 *    TFile* inputFile = NULL;
    inputFile = openInputFile(m_fileName);
 *
 *  Extension of the ApplyJetCalibrationTool
 *
 *  Authors: Joe Taenzer (joseph.taenzer@cern.ch), Reina Camacho
 *
 */

#include "ApplyJetCalibration/GSC.h"
#include <TMath.h>
#include <TSystem.h>
#include <TObjArray.h>
#include <TEnv.h>
#include <TKey.h>
#include <TObjString.h>

GSCTool::GSCTool()
  :   _binSize(0.1), _trackWIDTHMaxEtaBin(25), _nTrkMaxEtaBin(25), _Tile0MaxEtaBin(17), _EM3MaxEtaBin(35), _etaGapMin(0), _etaGapMax(0)
{

}

GSCTool::GSCTool(TString jetAlgo, TString GSCFactorsFile)
  :   _binSize(0.1), _trackWIDTHMaxEtaBin(25), _nTrkMaxEtaBin(25), _Tile0MaxEtaBin(17), _EM3MaxEtaBin(35), _etaGapMin(0), _etaGapMax(0)
{
  initGSC(jetAlgo, GSCFactorsFile);
}

GSCTool::~GSCTool()
{

}

double GSCTool::ReadPtjetPropertyHisto(double pT, double eta, double jetProperty, VecTH2D respFactors) {

  //int neta = respFactors.size();
  //eta bins have size _binSize=0.1 and are numbered sequentially from 0, so |eta|=2.4 is in eta bin #24
  int eta_index = eta/_binSize;
  double etaMax = (double)respFactors.size()*_binSize;

  if(eta>etaMax-(1e-6)) return 1.;

 int pTbin = respFactors[eta_index]->GetXaxis()->FindBin(pT);
 int pTMinbin = respFactors[eta_index]->GetXaxis()->GetFirst();
 int pTMaxbin = respFactors[eta_index]->GetXaxis()->GetLast();

 int jetPropbin = respFactors[eta_index]->GetYaxis()->FindBin(jetProperty);
 int jetPropMinbin = respFactors[eta_index]->GetYaxis()->GetFirst();
 int jetPropMaxbin = respFactors[eta_index]->GetYaxis()->GetLast();
 
 //If the pT or jetProperty is not in the histogram range, TH2::Interpolate will use the underflow/overflow bins and return junk values
 //So we just return the bin content of the closest bin instead.
 if (pTbin < pTMinbin && jetPropbin < jetPropMinbin)      return respFactors[eta_index]->GetBinContent(pTMinbin,jetPropMinbin);
 else if (pTbin > pTMaxbin && jetPropbin < jetPropMinbin) return respFactors[eta_index]->GetBinContent(pTMaxbin,jetPropMinbin);
 else if (pTbin < pTMinbin && jetPropbin > jetPropMaxbin) return respFactors[eta_index]->GetBinContent(pTMinbin,jetPropMaxbin);
 else if (pTbin > pTMaxbin && jetPropbin > jetPropMaxbin) return respFactors[eta_index]->GetBinContent(pTMaxbin,jetPropMaxbin);
 else if (pTbin < pTMinbin)                               return respFactors[eta_index]->GetBinContent(pTMinbin,jetPropbin);
 else if (pTbin > pTMaxbin)                               return respFactors[eta_index]->GetBinContent(pTMaxbin,jetPropMinbin);
 else if (jetPropbin < jetPropMinbin)                     return respFactors[eta_index]->GetBinContent(pTbin,jetPropMinbin);
 else if (jetPropbin > jetPropMaxbin)                     return respFactors[eta_index]->GetBinContent(pTbin,jetPropMaxbin);
 
 //TH2::Interpolate is a bilinear interpolation from the bin centers.
 else                                                     return respFactors[eta_index]->Interpolate(pT, jetProperty);
}

double GSCTool::GettrackWIDTHResponse(double pT, double eta, double trackWIDTH) {
  //jets with no tracks are assigned a trackWIDTH of -1, we use the trackWIDTH=0 correction in those cases
  if(trackWIDTH==-1) trackWIDTH=0;
  double trackWIDTHResponse = ReadPtjetPropertyHisto(pT, eta, trackWIDTH, _respFactorstrackWIDTH);
  return trackWIDTHResponse;
}

double GSCTool::GetnTrkResponse(double pT, double eta, double nTrk) {
  double nTrkResponse = ReadPtjetPropertyHisto(pT, eta, nTrk, _respFactorsnTrk);
  return nTrkResponse;
}

double GSCTool::GetTile0Response(double pT, double eta, double Tile0) {
  double Tile0Response = ReadPtjetPropertyHisto(pT, eta, Tile0, _respFactorsTile0);
  return Tile0Response;
}

double GSCTool::GetEM3Response(double pT, double eta, double EM3) {
  double EM3Response = ReadPtjetPropertyHisto(pT, eta, EM3, _respFactorsEM3);
  return EM3Response;
}

double GSCTool::GetGSCCorrection(double pT, double eta, double nTrk, double trackWIDTH, double Tile0, double EM3, TString depth) {
 
  double Tile0Corr = 1./GetTile0Response(pT, eta, Tile0);
  double EM3Corr = 1./GetEM3Response(pT*Tile0Corr, eta, EM3);
  double nTrkCorr = 1./GetnTrkResponse(pT*Tile0Corr*EM3Corr, eta, nTrk);
  double trackWIDTHCorr = 1./GettrackWIDTHResponse(pT*Tile0Corr*EM3Corr*nTrkCorr, eta, trackWIDTH);
  
  if(depth.Contains("Tile0")) return Tile0Corr;
  else if(depth.Contains("EM3")) return Tile0Corr*EM3Corr;
  else if(depth.Contains("nTrk")) return Tile0Corr*EM3Corr*nTrkCorr;
  else if(depth.Contains("trackWIDTH") || depth.Contains("Full")) return Tile0Corr*EM3Corr*nTrkCorr*trackWIDTHCorr;
  else error("GSCDepth flag is not properly set, please check your config file."); return 0;
}

void GSCTool::initGSC(TString jetAlgo, TString GSCFile) {

  if(GSCFile=="") error("No GSC factors file specified.");
  if(jetAlgo=="") error("No jet algorithm specified.");

  printf("\n\n");
  printf("===================================\n\n");
  printf("  Initializing the Global Sequential Calibration tool\n");
  printf("  for %s jets\n\n",jetAlgo.Data());

  //find the ROOT file containing response histograms, path comes from the config file.
  TString fn = FindFile(GSCFile);
  TFile *inputFile = NULL;
  inputFile = openInputFile(fn);
  if (inputFile==NULL) error("Cannot open GSC factors file"+fn);

  //Get a TList of TKeys pointing to the histograms contained in the ROOT file
  inputFile->cd();
  TList *keys = inputFile->GetListOfKeys();
  std::vector<TString> histoNames;
  //fill the names of the TKeys into a vector of TStrings
  TIter ikeys(keys);
  while(TKey *iterobj = (TKey*)ikeys()) { histoNames.push_back(iterobj->GetName()); }

  //Grab the TH2Ds from the ROOT file and put them into a vectors of TH2Ds
  for(uint ihisto=0; ihisto<histoNames.size(); ++ihisto) {
    if(!histoNames[ihisto].Contains(jetAlgo.Data())) continue;
    else if(ihisto>0 && histoNames[ihisto].Contains(histoNames[ihisto-1].Data())) continue;
    else if(histoNames[ihisto].Contains("EM3") && _respFactorsEM3.size() < _EM3MaxEtaBin) _respFactorsEM3.push_back( (TH2D*)GetHisto(inputFile,histoNames[ihisto]) );
    else if(histoNames[ihisto].Contains("nTrk") && _respFactorsnTrk.size() < _nTrkMaxEtaBin) _respFactorsnTrk.push_back( (TH2D*)GetHisto(inputFile,histoNames[ihisto]) );
    else if(histoNames[ihisto].Contains("Tile0") && _respFactorsTile0.size() < _Tile0MaxEtaBin) _respFactorsTile0.push_back( (TH2D*)GetHisto(inputFile,histoNames[ihisto]) );
    else if(histoNames[ihisto].Contains("trackWIDTH") && _respFactorstrackWIDTH.size() < _trackWIDTHMaxEtaBin) _respFactorstrackWIDTH.push_back( (TH2D*)GetHisto(inputFile,histoNames[ihisto]) );
  }

  //Make sure we put something in the vectors of TH2Ds
  if(_respFactorsEM3.size()<3) error("Vector of EM3 histograms may be empty. Please check your GSCFactors file: "+GSCFile);
  else if(_respFactorsnTrk.size()<3) error("Vector of nTrk histograms may be empty. Please check your GSCFactors file: "+GSCFile);
  else if(_respFactorsTile0.size()<3) error("Vector of Tile0 histograms may be empty. Please check your GSCFactors file: "+GSCFile);
  else if(_respFactorstrackWIDTH.size()<3) error("Vector of trackWIDTH histograms may be empty. Please check your GSCFactors file: "+GSCFile);
  else printf("\n  GSC Tool has been initialized with binning and eta fit factors from %s\n", fn.Data());

}

// Find configuration file
TString GSCTool::FindFile(TString filename) {
  TString fn(filename);

  // First check the actual path
  if (gSystem->AccessPathName(fn)==false) { 
    TString path(fn); path.ReplaceAll(gSystem->BaseName(fn),"");
    path.ReplaceAll("CalibrationConfigs/",""); path.ReplaceAll("CalibrationFactors/","");
    _basePath=path;
    return fn;
  }

  // if not there, check the directory were the last found file was ...
  if (gSystem->AccessPathName(_basePath+fn)==false) return _basePath+fn;

  // Let's try to pick up the calibration files in the RootCore folder
  TString RootCoreDir = gSystem->Getenv("ROOTCOREBIN");
  if (RootCoreDir == "") RootCoreDir = gSystem->Getenv("ROOTCOREDIR");
  if (RootCoreDir != "") {
    _basePath=RootCoreDir+"/data/ApplyJetCalibration/"; // this should always work
    if (gSystem->AccessPathName(_basePath+fn)==false) return _basePath+fn;
    _basePath=RootCoreDir+"../ApplyJetCalibration/data/";
    if (gSystem->AccessPathName(_basePath+fn)==false) return _basePath+fn;
  }
  
  // getting a bit desperate here... check if its one level up
  _basePath="ApplyJetCalibration/data/";
  if (gSystem->AccessPathName(_basePath+fn)==false) return _basePath+fn;

  // if needed, can here add a loop over the gSystem->GetIncludePath() list of directories

  printf("Cannot find file %s\n",filename.Data());
  printf("Searched in:\n  ./%s\n",filename.Data());
  if (RootCoreDir!="") 
    printf("  %s\n  %s\n",
	   (RootCoreDir+"/data/ApplyJetCalibration/"+fn).Data(),
	   (RootCoreDir+"/../ApplyJetCalibration/data/"+fn).Data());
  printf("  ./ApplyJetCalibration/data/%s\n",filename.Data());
  error("Cannot find file "+filename);
  return "";
}
