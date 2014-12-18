 /*
 *  Class definition of GSCTool - see Root/GSC.cxx for more details
 *  Joe Taenzer (joseph.taenzer@cern.ch), Nov 2012
 */

#ifndef _GLOBALSEQUENTIALCALIBRATION_
#define _GLOBALSEQUENTIALCALIBRATION_

#include <iostream>
#include <fstream>
#include <TROOT.h>
#include <TSystem.h>
#include <TFile.h>
#include <TMath.h>
#include <TString.h>
#include <TH2D.h>
#include <TGraph2D.h>
#include <vector>

class GSCTool : public TNamed {

 public:

  GSCTool();
  GSCTool(TString jetAlgo, TString GSCFactorsFile);
  virtual ~GSCTool();

#ifdef ROOTCORE
      ClassDef(GSCTool,1);
#endif

  //shared typedefs with Jet Calibration Tool
  typedef std::vector<TH2D*> VecTH2D;
  typedef std::vector<double> VecD;
  typedef std::vector<TString> StrV;
  typedef unsigned int uint;
  //end shared typedefs

  void initGSC(TString jetAlgo, TString GSCFile);

  double GettrackWIDTHResponse(double pT, double eta, double trackWIDTH);
  double GetnTrkResponse(double pT, double eta, double nTrk);
  double GetTile0Response(double pT, double eta, double Tile0);
  double GetEM3Response(double pT, double eta, double EM3);

  double GetGSCCorrection(double pT, double eta,
			  double nTrk, double trackWIDTH, double Tile0, double EM3, TString depth="Full");

  double GetjetPropertyMax(TString jetPropName, unsigned int etabin) {
    if ( jetPropName.Contains("EM3") && etabin < _EM3MaxEtaBin ) return _respFactorsEM3[etabin]->GetYaxis()->GetXmax();
    else if ( jetPropName.Contains("Tile0") && etabin < _Tile0MaxEtaBin ) return _respFactorsTile0[etabin]->GetYaxis()->GetXmax();
    else if ( jetPropName.Contains("nTrk") && etabin < _nTrkMaxEtaBin ) return _respFactorsnTrk[etabin]->GetYaxis()->GetXmax();
    else if ( jetPropName.Contains("trackWIDTH") && etabin < _trackWIDTHMaxEtaBin ) return _respFactorstrackWIDTH[etabin]->GetYaxis()->GetXmax();
    else return 1;
  }

 private:

  double ReadPtjetPropertyHisto(double pT, double eta, double jetProperty,
			     VecTH2D respFactors);

  bool FileExist(TString fn) { return gSystem->AccessPathName(fn)==false; };

  TFile* openInputFile(TString fn) { 
    if ( !FileExist(fn)) error("Cannot open GSC factors file"+fn);
    TFile* fileHandle = new TFile(fn);
    if (fileHandle == NULL) error( "Found but could not open file %s"+fn);
    return fileHandle;
  };

  TH2D *GetHisto(TFile *file, TString hname) {
    TH2D *h = (TH2D*)file->Get(hname);
    if (h==NULL) printf("WARNING: Cannot access histogram \"%s\" in file %s",hname.Data(),file->GetName());
    return h;
  }

  //shared functions/variables with JetCalibrationTool
  void error(TString msg) 
  { printf("\nERROR - GSCTool:\n\n  %s\n\n",msg.Data()); abort(); }

  TString FindFile(TString fn);
  //end shared functions
  TString _basePath;

  VecTH2D _respFactorsEM3, _respFactorsnTrk, _respFactorstrackWIDTH, _respFactorsTile0;

  double _binSize;
  uint _trackWIDTHMaxEtaBin, _nTrkMaxEtaBin, _Tile0MaxEtaBin, _EM3MaxEtaBin;
  double _etaGapMin, _etaGapMax;

};

#endif
