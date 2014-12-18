/**************************************************************************
 **
 **   File:         Event.h
 **
 **   Description:  Event class
 **                 
 **
 **   Author:       B. Butler
 **
 **   Created:      3-7-11
 **   Modified:
 **
 **************************************************************************/

#ifndef Event_h
#define Event_h

#include "TROOT.h"
#include "Particle.h"
#include "Point.h"
#include <iostream>

class Config;

class Event : public MomentObj {
public :

	Event()	: fFirstEvent(true), fPrevChannelNumber(-1), fWeight(0.), fDefaultWeight(0.), fCrossSectionWeight(0.), fLumi(0.) { ResetDefaults(); }
	virtual 					~Event();
	
	void						MoveEvent(Event& evt) {
									MomentObj::Move(evt);
									fWeight = evt.fWeight;
									fDefaultWeight = evt.fDefaultWeight;
									fCrossSectionWeight = evt.fCrossSectionWeight;
									fLumi = evt.fLumi;

									fDefaultLeptons = evt.fDefaultLeptons;
									fDefaultElectrons = evt.fDefaultElectrons;
									fDefaultMuons = evt.fDefaultMuons;
									fDefaultTaus = evt.fDefaultTaus;
									fDefaultJets = evt.fDefaultJets;
									fDefaultVtxs = evt.fDefaultVtxs;
									fDefaultMetx = evt.fDefaultMetx;
									fDefaultMety = evt.fDefaultMety;
									fDefaultTracks = evt.fDefaultTracks;
									fDefaultPhotons = evt.fDefaultPhotons;
									fDefaultClusters = evt.fDefaultClusters;
									fDefaultTruths = evt.fDefaultTruths;
									fDefaultRecos = evt.fDefaultRecos;
								}

	//Set input	
	void    					ClearEvent();
	void    					InitEvent();
	double						DefaultWeight() {return fDefaultWeight;}
	double						CrossSectionWeight() {return fCrossSectionWeight;}
	double						Lumi() {return fLumi;}
    double						Weight() {return fWeight;} 
    void						Weight(double w) {fWeight=w;}
	
	//Defaults
	void						ResetDefaults();
	void						SetTruthDefaults();
	
	void						SetDefaultLeptons(const MomKey name) { static const MomKey k("leptons"); fDefaultLeptons = k + name; }
	void						SetDefaultElectrons(const MomKey name) { static const MomKey k("electrons"); fDefaultElectrons = k + name; }
	void						SetDefaultMuons(const MomKey name) { static const MomKey k("muons"); fDefaultMuons = k + name; }
	void						SetDefaultTaus(const MomKey name) { static const MomKey k("taus"); fDefaultTaus = k + name; }
	void						SetDefaultJets(const MomKey name) {  static const MomKey k("jets"); fDefaultJets = k + name; }
	void						SetDefaultVtxs(const MomKey name) { static const MomKey k("vtxs"); fDefaultVtxs = k + name; }
	void						SetDefaultTracks(const MomKey name) { static const MomKey k("tracks"); fDefaultTracks = k + name; }
	void						SetDefaultPhotons(const MomKey name) { static const MomKey k("photons"); fDefaultPhotons = k + name; }
	void						SetDefaultClusters(const MomKey name) { static const MomKey k("clusters"); fDefaultClusters = k + name; }
	void						SetDefaultTruths(const MomKey name) { static const MomKey k("truths"); fDefaultTruths = k + name; }
	void						SetDefaultRecos(const MomKey name) { static const MomKey k("recos"); fDefaultRecos = k + name; }
	void						SetDefaultMet(const MomKey name) { 
									static const MomKey mx("Metx"), my("Mety"); 
									fDefaultMetx = mx + name;
									fDefaultMety = my + name;
								}
    
  //Event access
  bool						isMC();
  int							RunNumber() { static const MomKey rn("RunNumber"); return Int(rn);}
  int							ChannelNumber() { static const MomKey chn("ChannelNumber"), rn("RunNumber"); return Exists(chn) ? Int(chn) : Int(rn);}
  int							EventNumber() { static const MomKey evn("EventNumber"); return Int(evn);}
  int							LumiBlockNumber() { static const MomKey lbn("LumiBlockNumber"); return Int(lbn);}
  bool						Trig(const MomKey name) { return Bool(name);} //not really required, for clarity
  float           MCEventWeight() { static const MomKey mcevt("MCEventWeight"); return Float(mcevt);}
  float           AvgIntXing() { static const MomKey avInt("AverageIntPerXing");return Float(avInt);}    

  //for PDF reweighting
  int             pdf_id1() { static const MomKey pdf_id1("MCevt_pdf_id1");return Int(pdf_id1);}
  int             pdf_id2() { static const MomKey pdf_id2("MCevt_pdf_id2");return Int(pdf_id2);}
  float           pdf_x1() { static const MomKey pdf_x1("MCevt_pdf_x1");return Float(pdf_x1);}
  float           pdf_x2() { static const MomKey pdf_x2("MCevt_pdf_x2");return Float(pdf_x2);}
  float           pdf_scale() { static const MomKey pdf_scale("MCevt_pdf_scale");return Float(pdf_scale);}
  
  
  //Met
  TVector2					metVec() { return TVector2(Double(fDefaultMetx),Double(fDefaultMety)); } 
  double						met() {return metVec().Mod(); }
  TVector2					metVec(const MomKey name) { static const MomKey mx("Metx"), my("Mety"); return TVector2(Double(mx+name),Double(my+name)); } 
  double						met(const MomKey name) { return metVec(name).Mod(); }

    //Access to objects
    //Defaults
    int							leptons() { return Objs(fDefaultLeptons); }
	Particle&					lepton(const int i) { return particle(fDefaultLeptons,i); } 
    
    int							electrons() { return Objs(fDefaultElectrons); }
	Particle&					electron(const int i) { return particle(fDefaultElectrons,i); } 

    int							muons() { return Objs(fDefaultMuons); }    
	Particle&					muon(const int i) { return particle(fDefaultMuons,i); } 

    int							taus() { return Objs(fDefaultTaus); }    
	Particle&					tau(const int i) { return particle(fDefaultTaus,i); } 

    int							jets() { return Objs(fDefaultJets); }  
	Particle&					jet(const int i) { return particle(fDefaultJets,i); } 

    int							vtxs() { return Objs(fDefaultVtxs); } 
	Point&						vtx(const int i) { return point(fDefaultVtxs,i); } 

    int							tracks() { return Objs(fDefaultTracks); } 
	Particle&					track(const int i) { return particle(fDefaultTracks,i); } 
    
    int							photons() { return Objs(fDefaultPhotons); }  
	Particle&					photon(const int i) { return particle(fDefaultPhotons,i); } 

    int							clusters() { return Objs(fDefaultClusters); } 
	Particle&					cluster(const int i) { return particle(fDefaultClusters,i); } 

    int							truths() { return Objs(fDefaultTruths); } 
	Particle&					truth(const int i) { return particle(fDefaultTruths,i); } 
	
  	int                         recos() { return Objs(fDefaultRecos); } 
	Particle&					reco(const int i) { return particle(fDefaultRecos,i); }  

	//Non-defaults
    int							leptons(const MomKey name) { static const MomKey k("leptons"); return Objs(k+name); }
	Particle&					lepton(const int i, const MomKey name) { static const MomKey k("leptons"); return particle(k+name,i); } 
    
    int							electrons(const MomKey name) { static const MomKey k("electrons"); return Objs(k+name); }
	Particle&					electron(const int i, const MomKey name) { static const MomKey k("electrons"); return particle(k+name,i); } 

    int							muons(const MomKey name) { static const MomKey k("muons"); return Objs(k+name); }
	Particle&					muon(const int i, const MomKey name) { static const MomKey k("muons"); return particle(k+name,i); } 

    int							taus(const MomKey name) { static const MomKey k("taus"); return Objs(k+name); }
	Particle&					tau(const int i, const MomKey name) { static const MomKey k("taus"); return particle(k+name,i); } 

    int							jets(const MomKey name) { static const MomKey k("jets"); return Objs(k+name); }
	Particle&					jet(const int i, const MomKey name) { static const MomKey k("jets"); return particle(k+name,i); } 
	
    int							vtxs(const MomKey name) { static const MomKey k("vtxs"); return Objs(k+name); }
	Point&						vtx(const int i, const MomKey name) { static const MomKey k("vtxs"); return point(k+name,i); }  

    int							tracks(const MomKey name) { static const MomKey k("tracks"); return Objs(k+name); }
	Particle&					track(const int i, const MomKey name) { static const MomKey k("tracks"); return particle(k+name,i); }  
    
    int							photons(const MomKey name) { static const MomKey k("photons"); return Objs(k+name); }
	Particle&					photon(const int i, const MomKey name) { static const MomKey k("photons"); return particle(k+name,i); }  

    int							clusters(const MomKey name) { static const MomKey k("clusters"); return Objs(k+name); }
	Particle&					cluster(const int i, const MomKey name) { static const MomKey k("clusters"); return particle(k+name,i); }  

    int							truths(const MomKey name) { static const MomKey k("truths"); return Objs(k+name); }
	Particle&					truth(const int i, const MomKey name) { static const MomKey k("truths"); return particle(k+name,i); }  
  	
  	int                         recos(const MomKey name) { static const MomKey k("recos"); return Objs(k+name); }
	Particle&					reco(const int i, const MomKey name) { static const MomKey k("recos"); return particle(k+name,i); }  

	//Overridden in Analysis_base, access to configuration, etc.
	virtual Config*		     	Cfg() { return 0; }
	virtual Config*		     	DatasetCfg() { return 0; }
	virtual Bool_t      		Debug() { return false; }
	
	ClassDef(Event,1);

private :

	void						ComputeCrossSectionWeight();
	
  	Particle&					particle(const MomKey key, const int index) { return *(static_cast<Particle*>(Obj(key,index))); }
  	Point&						point(const MomKey key, const int index) { return *(static_cast<Point*>(Obj(key,index))); }
	
	//Defaults
	MomKey						fDefaultLeptons; //!
	MomKey						fDefaultElectrons; //!
	MomKey						fDefaultMuons; //!
	MomKey						fDefaultTaus; //!
	MomKey						fDefaultJets; //!
	MomKey						fDefaultVtxs; //!
	MomKey						fDefaultMetx; //!
	MomKey						fDefaultMety; //!
	MomKey						fDefaultTracks; //!
	MomKey						fDefaultPhotons; //!
	MomKey						fDefaultClusters; //!
	MomKey						fDefaultTruths; //!
	MomKey						fDefaultRecos; //!

	bool						fFirstEvent; //!
	int							fPrevChannelNumber; //!
	double						fWeight;
	double						fDefaultWeight;
	double						fCrossSectionWeight;
	double						fLumi;

};

#endif

