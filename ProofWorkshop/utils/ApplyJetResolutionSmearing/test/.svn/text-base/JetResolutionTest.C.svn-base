#include <iostream>
#include "ApplyJetResolutionSmearing/ApplyJetSmearing.h"
#include "ApplyJetCalibration/ApplyJetCalibration.h"
#include <TCanvas.h>
#include <TLatex.h>
#include <TGraphErrors.h>
#include <TLine.h>
#include <TROOT.h>
#include <TH1F.h>
#include <TSystem.h>
#include <TStyle.h>
#include <TRandom.h>
#include <iostream>
#include <fstream>
#include <string>

TCanvas *Can;
TLatex *tex;
TString tag, ps, date;

void MakeJERPlots(TString jetAlgo);

using namespace std;

typedef TGraphErrors Graph;

int main() {

  gRandom->SetSeed(12345678);

  // To access what Jet resolution tag is being used...
  TString rcdir=gSystem->Getenv("ROOTCOREDIR");
  TString svnpath=rcdir+"/include/JetResolution/.svn/entries";
  TString cmd=Form("head %s | grep tags | awk -F tags '{print $2}' | cut -d'/' -f2 > tmp_file",svnpath.Data());
  gSystem->Exec(cmd);
  ifstream myfile ("tmp_file"); string line; 
  if (myfile.is_open()&&myfile.good()) getline (myfile,line);
  tag=line;
  myfile.close(); gSystem->Exec("rm -f tmp_file");
  if (tag=="") { 
    gSystem->Exec("date '+%b %d, %Y'> tmp_file"); 
    ifstream myfile2 ("tmp_file"); getline (myfile2,line);
    //printf("Using JetResolution trunk as of %s\n",line.c_str()); 
    tag="JetResolution trunk "+line;
    myfile2.close(); gSystem->Exec("rm -f tmp_file");
  } 
  printf("The Jet resolution tag is %s\n",tag.Data());


  tex=new TLatex(); tex->SetNDC(); tex->SetTextSize(0.04); tex->SetTextFont(42);
  Can = new TCanvas("Can","",800,600);

  ps=tag+".ps";
  if (tag.Contains("trunk")) ps="JERtrunk.ps";
  ps.ReplaceAll(".config",".ps");
  Can->Print(ps+"[");

  MakeJERPlots("AntiKt4TopoEM");
  MakeJERPlots("AntiKt4LCTopo");
  MakeJERPlots("AntiKt6TopoEM");
  MakeJERPlots("AntiKt6LCTopo");

  Can->Print(ps+"]");
  TString pdf=TString(ps).ReplaceAll(".ps",".pdf");
  gSystem->Exec("ps2pdf "+ps+" "+pdf); gSystem->Exec("rm -f "+ps);
  printf("\n  Plots saved in:\n    %s\n\n",pdf.Data());

}

void error(TString msg) { printf("ERROR:\n  %s\n\n",msg.Data()); abort(); };

void MakeJERPlots(TString jetAlgo) {
  int jetR = jetAlgo.Contains("Kt6")?6:4;
  TString calib="EM";

  TFile *inf = TFile::Open("ResolutionFunctionsForShima.root");
  if (inf==NULL) error("can't open file");
  
  
  JetCalibrationTool *myJES = new JetCalibrationTool(jetAlgo);
  JetSmearingTool *myJER = new JetSmearingTool(jetAlgo);
  myJES->UseGeV(); myJER->UseGeV();
  
  TH1F *mallR = new TH1F("mallR"+jetAlgo,"",10,0,300); mallR->SetStats(0);
  mallR->SetXTitle("jet p_{T} [GeV]"); mallR->SetYTitle("Relative JER, #sigma_{E}/E"); mallR->SetMaximum(0.35);

  TH1F *mallU = new TH1F("mallU"+jetAlgo,"",10,0,300); mallU->SetStats(0);
  mallU->SetXTitle("jet p_{T} [GeV]"); mallR->SetYTitle("Fractional JER uncertainty"); mallU->SetMaximum(0.05);

  int Npt=50; double etas[] = {0.0,0.8,1.2,2.1,2.8,3.6,4.5};
  for (int ieta=0;ieta<6;++ieta) {
    double etaMin=etas[ieta], etaMax=etas[ieta+1], eta=(etaMin+etaMax)/2;

    TString etaRange(Form("%.1f-%.1f",etaMin,etaMax));
    if (etaMax==0.8) etaRange="0-0.3";
    TString fname=Form("Resolution_AntiKt%d_%sJES_pt_%s",jetR,calib.Data(),etaRange.Data());
    //Resolution_AntiKt4_EMJES_pt_2.1-2.8
    //Resolution_AntiKt4Topo_4_pt_2.8-3.6
    if ( etaMin == 2.8 ) fname=Form("Resolution_AntiKt%dTopo_%d_pt_%s",jetR,jetR,etaRange.Data());
    TF1 *reso = (TF1*)inf->Get(fname);
    if (reso==NULL) error("Can't get resolution function: "+fname);
    //Resolution_AntiKt6Topo_6_pt_2.8-3.6_FractionalUncertainty
    TH1 *oldU = (TH1*)inf->Get(fname+"_FractionalUncertainty");
    if (oldU==NULL) error("Can't get 2010 uncertainty");

    Graph *dReso = new Graph(), *mcReso = new Graph(), *uReso = new Graph(), *U = new Graph(), *SF = new Graph();
    Graph *SF2010 = new Graph();

    //Resolution_AntiKt4_EMJES_pt_0-0.3
    for (int ipt=0;ipt<Npt;++ipt) {
      double pt = 20 + 250.0/Npt*ipt;
      if (pt*cosh(eta)>3000) continue;
      double sigmaD=myJER->GetJER_Data(pt,eta), sigmaMC=myJER->GetJER_MC(pt,eta), sigmaU=myJER->GetJER_Uncert(pt,eta);
      dReso->SetPoint(ipt,pt,sigmaD);
      mcReso->SetPoint(ipt,pt,sigmaMC);
      uReso->SetPoint(ipt,pt,sigmaMC+sigmaU);
      SF->SetPoint(ipt,pt,sqrt(pow(sigmaMC+sigmaU,2)-pow(sigmaMC,2)));
      U->SetPoint(ipt,pt,myJER->GetJER_Uncert(pt,eta));
      double sig2010 = reso->Eval(pt), u2010 = oldU->Interpolate(pt);
      SF2010->SetPoint(ipt,pt,sqrt(pow(sig2010+u2010*sig2010,2)-pow(sig2010,2)));
    }
    
    mallR->Draw(); dReso->Draw("PL"); 
    mcReso->SetLineColor(kRed); mcReso->Draw("PL"); 
    uReso->SetLineColor(kRed); uReso->SetLineStyle(2); uReso->Draw("PL");
    SF->SetLineColor(kBlue); SF->SetLineStyle(2); SF->SetLineWidth(2); SF->Draw("PL");

    tex->SetTextAlign(32);
    tex->DrawLatex(0.85,0.85,myJER->GetJetAlgoDescription());
    tex->DrawLatex(0.85,0.8,Form("%.1f #leq |#eta| < %.1f",etaMin,etaMax));
    tex->SetTextAlign(12); tex->DrawLatex(0.15,0.85,tag);
    tex->SetTextAlign(32); tex->DrawLatex(0.85,0.75,"Solid: Data");
    tex->SetTextColor(kRed); tex->DrawLatex(0.85,0.70,"Solid: MC");
    tex->DrawLatex(0.85,0.65,"Dashed: MC + 1#sigma");
    tex->SetTextColor(kBlue); tex->DrawLatex(0.85,0.60,"Rel 17 Smearing factor");
    tex->SetTextColor(kBlack); 
    
    Can->Print(ps);

    if (jetAlgo.Contains("TopoEM")) {
      SF2010->SetLineColor(kGreen+1); SF2010->SetLineStyle(2); SF2010->SetLineWidth(2); SF2010->Draw("PL");
      reso->SetLineWidth(2); reso->SetLineColor(kGreen+1); reso->Draw("same");
      tex->SetTextColor(kGreen+1); tex->DrawLatex(0.85,0.55,"2010 reso & SF");
      tex->SetTextColor(kBlack); 
      Can->Print(ps);
    }
    //mallU->Draw(); U->Draw("PL"); Can->Print(ps);
  }

  TH1F *mallReta = new TH1F("mallReta","",10,-5,5); mallReta->SetStats(0);
  mallReta->SetXTitle("jet #eta"); mallReta->SetYTitle("Relative JER, #sigma_{E}/E"); mallReta->SetMaximum(0.35);
  
  Graph *dResoEta = new Graph(), *mcResoEta = new Graph(), *uResoEta = new Graph(), *UEta = new Graph(), *SFEta = new Graph();
  int Neta=450; double pts[] = {30, 80, 220};
  for (int ipt=0;ipt<3;++ipt) {
    double pt=pts[ipt];
    for (int ieta=0;ieta<Neta;++ieta) {
      double eta=-4.5+9.0/Neta*ieta;
      //double PT=pt;
      //if (pt*cosh(eta)>3500) pt=3500/cosh(eta);
      double sigmaD=myJER->GetJER_Data(pt,eta), sigmaMC=myJER->GetJER_MC(pt,eta), sigmaU=myJER->GetJER_Uncert(pt,eta);
      dResoEta->SetPoint(ieta,eta,sigmaD);
      mcResoEta->SetPoint(ieta,eta,sigmaMC);
      uResoEta->SetPoint(ieta,eta,sigmaMC+sigmaU);
      SFEta->SetPoint(ieta,eta,sqrt(pow(sigmaMC+sigmaU,2)-pow(sigmaMC,2)));
    }
    mallReta->Draw(); dResoEta->Draw("PL"); 
    mcResoEta->SetLineColor(kRed); mcResoEta->Draw("PL"); 
    uResoEta->SetLineColor(kRed); uResoEta->SetLineStyle(2); uResoEta->Draw("PL");
    SFEta->SetLineColor(kBlue); SFEta->SetLineStyle(2); SFEta->SetLineWidth(2); SFEta->Draw("PL");

    tex->SetTextAlign(12); tex->DrawLatex(0.15,0.85,tag);
    tex->SetTextAlign(32); tex->DrawLatex(0.85,0.75,"Solid: Data");
    tex->SetTextColor(kRed); tex->DrawLatex(0.85,0.70,"Solid: MC");
    tex->DrawLatex(0.85,0.65,"Dashed: MC + 1#sigma");
    tex->SetTextColor(kBlue); tex->DrawLatex(0.85,0.60,"Smearing factor");
    tex->SetTextColor(kBlack);

    tex->SetTextAlign(32);
    tex->DrawLatex(0.85,0.85,myJER->GetJetAlgoDescription());
    tex->DrawLatex(0.85,0.8,Form("p_{T} = %.0f",pt));
    Can->Print(ps);
  }

  if (0) {

  TH1F *hRmc = new TH1F("Rmc","",100,0.2,1.8); 
  hRmc->SetXTitle("p_{T}(reco) / p_{T}(true)"); hRmc->SetStats(0);
  TH1F *hRd  = new TH1F("Rd","",100,0.2,1.8); hRd->SetLineColor(kBlack);
  TH1F *hRdu = new TH1F("Rdu","",100,0.2,1.8); hRdu->SetLineColor(kBlack);
  for (int ipt=0;ipt<3;++ipt) {
    hRmc->Reset(); hRd->Reset(); hRdu->Reset();
    double pt=pts[ipt], eta=3.0;
    for (int evt=111;evt<10100;evt++) {
      myJER->SetSeed(evt);
      for (int jeti=0;jeti<6;++jeti) {
	double sigmaMC=myJER->GetJER_MC(pt,eta);
	double thePt = pt*gRandom->Gaus(1.0,sigmaMC);
	hRmc->Fill(thePt/pt);

	// smear the pt to data:
	double ptSmeared = thePt*myJER->GetRandomSmearingFactor(thePt,eta);
	hRd->Fill(ptSmeared/pt);

	// oversmear the pt to data+1sigma of the uncertainty
	double ptOverSmeared = ptSmeared*myJER->GetRandomSmearingFactorSyst(ptSmeared,eta);
	hRdu->Fill(ptOverSmeared/pt);
      }
    }
    TF1 *f = new TF1(Form("f%d",ipt),"gaus",0.6,1.4);
    hRdu->Fit(f,"R"); hRmc->GetXaxis()->SetRangeUser(0.5,1.5);
    hRmc->SetLineColor(kRed); hRmc->Draw(); hRmc->Draw("samee");
    hRd->Draw("same"); hRd->Draw("samee");
    hRdu->SetLineStyle(2); hRdu->Draw("same"); hRdu->Draw("samee");
    tex->SetTextAlign(32);
    tex->DrawLatex(0.85,0.85,myJER->GetJetAlgoDescription());
    tex->DrawLatex(0.85,0.8,Form("p_{T}(true) = %.0f GeV",pt));
    tex->DrawLatex(0.85,0.75,Form("#eta = %.1f",eta));
    tex->DrawLatex(0.85,0.7,Form("Desired: %.1f%%",myJER->GetJER_MC(pt,eta)*100));
    tex->DrawLatex(0.85,0.65,Form("Desired: %.1f%%",myJER->GetJER_Data(pt,eta)*100));
    tex->DrawLatex(0.85,0.6,Form("Desired: %.1f%%",
				 (myJER->GetJER_Data(pt,eta)+myJER->GetJER_Uncert(pt,eta))*100));

    tex->SetTextAlign(12);
    tex->DrawLatex(0.12,0.7,Form("Histogram RMS: %.1f%%",hRmc->GetRMS()*100));
    tex->DrawLatex(0.12,0.65,Form("Histogram RMS: %.1f%%",hRd->GetRMS()*100));
    tex->DrawLatex(0.12,0.6,Form("Histogram RMS: %.1f%%",hRdu->GetRMS()*100));
    tex->DrawLatex(0.12,0.55,Form("Fit: %.1f%%",f->GetParameter(2)*100));


    Can->Print(ps);
  }
  }

  //cout << "hello" << endl;
  /*
  double pt=15;
  printf("Reso for a %6.1f GeV data/MC jet: %.2f%% / %.2f%%\n",pt,myJER->GetJER_Data(pt,0)*100,myJER->GetJER_MC(pt,0)*100);
  pt=50;
  printf("Reso for a %6.1f GeV data/MC jet: %.2f%% / %.2f%%\n",pt,myJER->GetJER_Data(pt,0)*100,myJER->GetJER_MC(pt,0)*100);
  pt=500;
  printf("Reso for a %6.1f GeV data/MC jet: %.2f%% / %.2f%%\n",pt,myJER->GetJER_Data(pt,0)*100,myJER->GetJER_MC(pt,0)*100);
  */

}
