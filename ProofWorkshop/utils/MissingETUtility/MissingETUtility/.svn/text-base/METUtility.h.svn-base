////////////-*-c++-*-///////////////////////
//METUtility.h
//Authors: Jet Goodson, TJ Khoo, Caterina Pizio
//First version: 5/5/2011
//
//The METUtility is intended to provide the user at D3PD level 
//with the correct recipe and information for rebuilding MET to include
//scaling and smearing, and for calculating the systematic 
//uncertainty on MET.
//
//While it's designed for D3PD/Ntuples, we hope to keep it usable by AOD users
////////////////////////////////////////////
//Instructions:
//Prior to root macro
// .L METUtility.h+
// 
////////////////////////////////////////////

#ifndef _METUTILITY_
#define _METUTILITY_

#include "TNamed.h"
#include "TLorentzVector.h"
#include "TVector2.h"
#include "TMath.h"
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <bitset>

using namespace std;

struct MissingETTags {//copied from MissingETEvent/MissingETComposition -- changed tag to Tag to avoid potential conflicts

  enum Tags {
    UNKNOWN            = 0x0000,
    DEFAULT            = 0x0001,
    SPECTRO            = 0x0002, // Apply to muons
    TRACK              = 0x0004,
    REFMUON            = 0x0008,
    MUID               = 0x0010,
    EFLOW_CLUSTER      = 0x0020, // Apply to CellOut clusters
    REMOVED_CLUSTER    = 0x0040,
    //
    PILEUP_CORRECTED   = 0x1000,
    CPU_TRACK_STVF     = 0x1100, // Renamed PU to CPU to clarify that this applies to SoftTerms
    CPU_TRACK_SUM      = 0x1200,
    CPU_TRACK_CONE     = 0x1400,
    CPU_JET_AREA       = 0x1800,
    JPU_CORRECTION     = 0x3000, // Renamed PU to JPU to clarify that this applies to RefJet
    JPU_JET_JVF        = 0x3100,
    JPU_JET_CUSTOM_JVF = 0x3200,
    JPU_JET_JVFCUT     = 0x3300,
    JPU_JET_AREA_JET   = 0x3800
  };

  // test equality
  static bool isCODE(unsigned short compare, unsigned short tag)
  { return tag == compare; }

  // test that tag matches all bits in compare (though other bits can be set)
  static bool usesCODE(unsigned short compare, unsigned short tag)
  { return tag & compare; }

  static void setCODE(unsigned short set, unsigned short &tag)
  { tag = tag | set;}
};

namespace METUtil {
  enum Terms {
    RefEle, RefGamma, RefTau, RefJet, RefMuon,
    MuonTotal, SoftTerms,
    Truth, RefFinal, HardTerms
  };

  enum Objects {
    Electrons, Photons, Taus, Jets, Muons, Clusters, Tracks,
    SpectroMuons, MuonsComboMS, MuonsComboID
  };

  // These are signed, and are used for most cases.
  // Three separate options for the soft terms' systematics:
  //    * AllClusters -- sumET-dependent uncertainty derived around PLHC '11
  //    * ResoSoftTerms -- adds resolution smearing
  //    * ScaleSoftTerms -- scaling to the envelope of the scale uncertainty
  // The latter two are in two variants, worked on by the Milano (SoftTerms)
  // and Frascati (SoftTerms_ptHard) groups. The latter is only usable in MC.
  // Some information is available here:
  //  https://indico.cern.ch/conferenceDisplay.py?confId=179819
  enum Systematics {
    None=0,
    EESUp, EESDown, EERUp, EERDown,
    PESUp, PESDown, PERUp, PERDown,
    TESUp, TESDown, TERUp, TERDown,
    // Single JES parameter used until Summer 2012
    JESUp, JESDown, JERUp, JERDown,
    MERIDUp, MERIDDown, MERMSUp, MERMSDown, MESUp, MESDown,
    CESUp, CESDown, CERUp, CERDown,
    TrkESUp, TrkESDown, TrkERUp, TrkERDown,
    ResoSoftTermsUp, ResoSoftTermsDown,
    ScaleSoftTermsUp, ScaleSoftTermsDown,
    ResoSoftTermsUp_ptHard, ResoSoftTermsDown_ptHard,
    ResoSoftTermsUpDown_ptHard, ResoSoftTermsDownUp_ptHard,
    ScaleSoftTermsUp_ptHard, ScaleSoftTermsDown_ptHard
  };

  // These are unsigned, and used for diff/delta computation.
  enum SystType {
    JES, JER, EES, EER, PES, PER, TES, TER,
    MERID, MERMS, MES, CES, CER, TrkES, TrkER,
    ResoSoftTermsSyst, ScaleSoftTermsSyst,
    ResoSoftTermsCo_ptHard, ResoSoftTermsAnti_ptHard, ResoSoftTermsSyst_ptHard, ScaleSoftTermsSyst_ptHard,
    All, All_ptHard
  };

  // Region names, encoding specific eta ranges.
  enum Region {
    Central, EndCap, Forward
  };

  inline string getTermName(int term) {
    Terms metterm = Terms(term);
    switch(metterm) {
    case RefEle:     return "RefEle";
    case RefGamma:   return "RefGamma";
    case RefJet:     return "RefJet";
    case RefTau:     return "RefTau";
    case RefMuon:    return "RefMuon";
    case MuonTotal:  return "MuonTotal";
    case SoftTerms:  return "SoftTerms";
    case Truth:      return "Truth";
    case RefFinal:   return "RefFinal";
    case HardTerms:  return "HardTerms";
    }
    return "";
  }

  inline string getObjectName(int object) {
    Objects metobject = Objects(object);
    switch(metobject) {
    case Electrons: return "Electrons";
    case Photons:   return "Photons";
    case Jets:      return "Jets";
    case Taus:      return "Taus";
    case Muons:     return "Muons";
    case Clusters:  return "Clusters";
    case Tracks:    return "Tracks";
    case SpectroMuons: return "SpectroMuons";
    case MuonsComboMS: return "MuonsComboMS";
    case MuonsComboID: return "MuonsComboID";
    }
    return "";
  }

  inline string getSystName(METUtil::Systematics systematic) {
    Systematics metsyst = Systematics(systematic);
    switch(metsyst) {
    case None: return "None";
    case EESUp: return "EESUp";
    case EESDown: return "EESDown";
    case EERUp: return "EERUp";
    case EERDown: return "EERDown";
    case PESUp: return "PESUp";
    case PESDown: return "PESDown";
    case PERUp: return "PERUp";
    case PERDown: return "PERDown";
    case TESUp: return "TESUp";
    case TESDown: return "TESDown";
    case TERUp: return "TERUp";
    case TERDown: return "TERDown";
    case JESUp: return "JESUp";
    case JESDown: return "JESDown";
    case JERUp: return "JERUp";
    case JERDown: return "JERDown";
    case MERIDUp: return "MERIDUp";
    case MERIDDown: return "MERIDDown";
    case MERMSUp: return "MERMSUp";
    case MERMSDown: return "MERMSDown";
    case MESUp: return "MESUp";
    case MESDown: return "MESDown";
    case CESUp: return "CESUp";
    case CESDown: return "CESDown";
    case CERUp: return "CERUp";
    case CERDown: return "CERDown";
    case TrkESUp: return "TrkESUp";
    case TrkESDown: return "TrkESDown";
    case TrkERUp: return "TrkERUp";
    case TrkERDown: return "TrkERDown";
    case ResoSoftTermsUp: return "ResoSoftTermsUp";
    case ResoSoftTermsDown: return "ResoSoftTermsDown";
    case ScaleSoftTermsUp: return "ScaleSoftTermsUp";
    case ScaleSoftTermsDown: return "ScaleSoftTermsDown";
    case ResoSoftTermsUp_ptHard: return "ResoSoftTermsUp_ptHard";
    case ResoSoftTermsDown_ptHard: return "ResoSoftTermsDown_ptHard";
    case ResoSoftTermsUpDown_ptHard: return "ResoSoftTermsUpDown_ptHard";
    case ResoSoftTermsDownUp_ptHard: return "ResoSoftTermsDownUp_ptHard";
    case ScaleSoftTermsUp_ptHard: return "ScaleSoftTermsUp_ptHard";
    case ScaleSoftTermsDown_ptHard: return "ScaleSoftTermsDown_ptHard";
    }
    return "";
  }

  class MultiSyst { // A class to handle multiple systematics at once

  public:
    MultiSyst() {}; // default constructor, nothing needs doing.
    MultiSyst(std::bitset<65> systbits) {m_systbits = systbits;}; // default constructor, nothing needs doing.
    MultiSyst(METUtil::Systematics syst) {m_systbits.set(syst);};
    ~MultiSyst() {};

    MultiSyst& operator+=(MultiSyst rhs) {
      m_systbits |= rhs.getBitSet(); return *this;
    };

    std::bitset<65> getBitSet() const {return m_systbits;};
    void setSyst(METUtil::Systematics syst) {m_systbits.set(syst);};
    void resetSyst(METUtil::Systematics syst) {m_systbits.reset(syst);};

    bool hasSyst(METUtil::Systematics syst) const {
      return m_systbits.test(syst);
    };

  private:
    std::bitset<65> m_systbits;
    // The size should be at least equal to the number of values in METUtil::Systematics.
  };

}

inline METUtil::MultiSyst operator+(METUtil::MultiSyst lhs, const METUtil::MultiSyst& rhs) {
  lhs += rhs;
  return lhs;
}

inline METUtil::MultiSyst operator+(METUtil::Systematics lhs, const METUtil::Systematics rhs) {
  return METUtil::MultiSyst(lhs) + METUtil::MultiSyst(rhs);
}

inline bool operator==(const METUtil::MultiSyst& lhs, const METUtil::MultiSyst& rhs) {
  return lhs.getBitSet() == rhs.getBitSet();
}

inline bool operator==(const METUtil::MultiSyst& lhs, METUtil::Systematics rhs) {
  return lhs.getBitSet() == METUtil::MultiSyst(rhs);
}

class METUtility : public TNamed {

public:

  class METObject : public TNamed {
  public:
    METObject(){m_etx = 0.0; m_ety = 0.0; m_sumet = 0.0; m_et = -1.0; m_significance = 0; m_isValid = false;}//will return false until changed, preferably after etx/ety/sumet are set
    METObject(float _etx, float _ety, float _sumet){m_significance = 0; m_sumet = _sumet; m_etx = _etx; m_ety = _ety; m_et = -1.0; m_isValid = true;}
    ~METObject(){}

    float etx() const {return m_etx;}
    float ety() const {return m_ety;}
    float sumet() const {return m_sumet;}
    float phi() const {return atan2(m_ety, m_etx);}
    float et() const {return ((m_et < 0) ? sqrt(m_etx*m_etx + m_ety*m_ety) : m_et);}
    float sig() const {return et()/(.5*TMath::Sqrt(m_sumet));}
    float significance() const {return m_significance;} //for the more complex MET significance
    bool isValid() const {return m_isValid;}
    TVector2 getTVector2() {return TVector2(m_etx,m_ety);}

    void setEtx(float _etx) {m_etx = _etx;}
    void setEty(float _ety) {m_ety = _ety;}
    void setSumet(float _sumet){m_sumet = _sumet;}
    void setEt(float _et) {m_et = _et;} //don't do this unless you know what you're doing, it's mostly for systematic diffs. if you're doing actually MET let etx/ety compute et
    void setBase(float _etx, float _ety, float _sumet){m_sumet = _sumet; m_etx = _etx; m_ety = _ety;}
    void setSignificance(float _sig){m_significance = _sig;}
    void setIsValid(bool status){m_isValid = status;}

    // Safe redefinitions of ET and phi, such that the existing phi or ET is not changed,
    // unlike setEt, which will produce an ET inconsistent with the stored etx and ety.
    void resetEt(float _et) {float _phi = phi(); m_etx = _et*cos(_phi); m_ety = _et*sin(_phi);}
    void resetPhi(float _phi) {float _et = et(); m_etx = _et*cos(_phi); m_ety = _et*sin(_phi);}

  private:
    float m_sumet;
    float m_etx;
    float m_ety;

    float m_et; //this is mostly for return systematic diffs, i.e., (up - down)/none
    float m_significance;
    bool m_isValid;

#ifdef METUTIL_STANDALONE
    ClassDef(METObject,1);
#endif //METUTIL_STANDALONE

  };


  METUtility(bool doRefEle=true,
	     bool doRefGamma=true,
	     bool doRefTau=true,
	     bool doRefJet=true,
	     bool doRefMuon=false,
	     bool doMuonTotal=true,
	     bool doSoftTerms=true,
	     bool isMuid=false,
	     bool isEflow=true,
	     bool verbose=false);
  ~METUtility();

  // reset all data
  void reset();

  // methods to read things out
  inline METObject getMissingET(METUtil::Terms term, METUtil::MultiSyst systematic=METUtil::None, int iShift=-1)
  {return MissingETHelper(term,systematic,iShift);};
  METObject getMissingETDiff(METUtil::Terms term, METUtil::SystType systtype=METUtil::All, int iShift=-1);
  METObject deltaMissingET(METUtil::Terms term, METUtil::SystType systtype=METUtil::All);
  METObject deltaMissingET(METUtil::Terms term, const vector<METUtil::SystType> &systtypes);
  METObject absDeltaMissingET(METUtil::Terms term, METUtil::SystType systtype=METUtil::All);
  
  // methods to set up objects
  void setObjects(METUtil::Objects type, const vector<TLorentzVector>& momenta,
		  const vector<vector<float> > *wet, const vector<vector<float> > *wex, const vector<vector<float> > *wey, const vector<vector<unsigned int> > *statusWord);
  void setObjects(METUtil::Objects type, const vector<float> *pT, const vector<float> *eta, const vector<float> *phi, const vector<float> *E,
		  const vector<vector<float> > *wet, const vector<vector<float> > *wex, const vector<vector<float> > *wey, const vector<vector<unsigned int> > *statusWord);
  void setObjects(METUtil::Objects type, const vector<float> *pT, const vector<float> *eta, const vector<float> *phi, const vector<float> *E,
		  const vector<float> *wet, const vector<float> *wex, const vector<float> *wey, const vector<unsigned short> *statusWord);

  void setObjectEnergyUncertainties(METUtil::Objects type, const vector<float> energyUp, const vector<float> energyDown, int iShift=0); 
  void setObjectResolutionShift(METUtil::Objects type, const vector<float> resUp, const vector<float> resDown); 
  void setObjectResolutions(METUtil::Objects type, const vector<float> resolutions);
  void setObjectMomenta(METUtil::Objects type, vector<float> pT, vector<float> eta, vector<float> phi, vector<float> E);
  void setMETTerm(METUtil::Terms term, float _etx, float _ety, float _sumet);

  // Configuration of METUtility options
  inline void setIsMuid(bool status){m_isMuid = status;}
  inline void setIsEflow(bool status){m_isEflow = status;}
  inline void setVerbosity(bool status){m_verbose = status;}
  inline void doSignificance(bool status){m_doSignificance = status;}
  inline void setNvtx(int nvtx) {m_nvtx = nvtx;}
  inline void setAverageIntPerXing(float averageIntPerXing) {m_averageIntPerXing = averageIntPerXing;}
  inline void setClusterDefaults(bool energyStat, bool resStat=false){m_useStandardClusterRes = resStat; m_useStandardClusterEnergySigma = energyStat;}
  inline void setObjectEtaCut(float etaLow=0., float etaHigh=10){m_etaCut[0] = etaLow; m_etaCut[1] = etaHigh;}
  //  inline void setUseJesEigenvectors(bool useJesEigenvectors) {m_useJesEigenvectors = useJesEigenvectors;}
  //  inline void setAddJesPileupSyst(bool addJesPileupSyst) {m_addJesPileupSyst = addJesPileupSyst;}
  inline void setCaloRegion(METUtil::Region reg){
    switch(reg) {
    case METUtil::Central: setObjectEtaCut(0,1.5); break;
    case METUtil::EndCap:  setObjectEtaCut(1.5,3.2); break;
    case METUtil::Forward: setObjectEtaCut(3.2,4.9); break;
    }
  }
  inline void setJetPUcode(unsigned short code){m_jet_pu_statusWord = MissingETTags::Tags(code | MissingETTags::DEFAULT);}
  inline void setSoftTermsPUcode(unsigned short code){m_st_pu_statusWord = MissingETTags::Tags(code | MissingETTags::DEFAULT);}

  inline void setDoJetJVF(bool status){m_doJetJVF = status;}
  inline void setDoMuEloss(bool status){m_doMuEloss = status;}  

  //////////////////////////////////////////////////////////////////////////////
  // Intended as a temporary fix to be validated
  //
  inline void configEgammaJetFix(bool doFix, bool useConstPt, bool moveToCellOut, double dR)
  { m_doEgammaJetFix = doFix;
    m_useConstPtForFix = useConstPt;
    m_moveOLJetToCellOut = moveToCellOut;
    m_egammaJetFixDeltaR = dR;
  }
  //
  void setJetConst4vec(vector<float>* constPt, vector<float>* constEta,
		       vector<float>* constPhi, vector<float>* constE);
  //
  inline double getJetEstWeight(double elpt, double jetpt) {
    return (1. - elpt / jetpt);
  }
  //
  //     electron-jet overlap removal patch
  //////////////////////////////////////////////////////////////////////////////

  void defineMissingET(bool doRefEle, bool doRefGamma, bool doRefTau, bool doRefJet, bool doRefMuon, bool doMuonTotal, bool doSoftTerms);
  void configMissingET(bool is2012, bool isSTVF);

  float METSignificance(METUtil::MultiSyst systematic);

  ///helper functions to deal with odd variables
  void setJetParameters(const vector<float> *pT, const vector<float> *eta, const vector<float> *phi, const vector<float> *E,
			const vector<vector<float> > *wet, const vector<vector<float> > *wex, const vector<vector<float> > *wey, const vector<vector<unsigned int> > *statusWord);
  void setJetJVFWeights(const vector<float> *weights);
  //   void setExtraJetParameters(const vector<float> *moment, const vector<float> *mass, const vector<float> *eta, const vector<float> *phi);
  //
  void setElectronParameters(const vector<float> *pT, const vector<float> *eta, const vector<float> *phi, 
			     const vector<vector<float> > *wet, const vector<vector<float> > *wex, const vector<vector<float> > *wey, const vector<vector<unsigned int> > *statusWord);
  //
  void setPhotonParameters(const vector<float> *pT, const vector<float> *eta, const vector<float> *phi,
			   const vector<vector<float> > *wet, const vector<vector<float> > *wex, const vector<vector<float> > *wey, const vector<vector<unsigned int> > *statusWord);
  //
  void setTauParameters(const vector<float> *pT, const vector<float> *eta, const vector<float> *phi,
			const vector<vector<float> > *wet, const vector<vector<float> > *wex, const vector<vector<float> > *wey, const vector<vector<unsigned int> > *statusWord);
  //
  void setClusterParameters(const vector<float> *pT, const vector<float> *eta, const vector<float> *phi, const vector<float> *E,
			    const vector<vector<float> > *wet, const vector<vector<float> > *wex, const vector<vector<float> > *wey, const vector<vector<unsigned int> > *statusWord);
  //
  void setTrackParameters(const vector<float> *pT, const vector<float> *eta, const vector<float> *phi, const vector<float> *E,
			  const vector<vector<float> > *wet, const vector<vector<float> > *wex, const vector<vector<float> > *wey, const vector<vector<unsigned int> > *statusWord);
  //
  void setMuonParameters(const vector<float> *pT, const vector<float> *eta, const vector<float> *phi,
			 const vector<vector<float> > *wet, const vector<vector<float> > *wex, const vector<vector<float> > *wey, const vector<vector<unsigned int> > *statusWord);
  void setExtraMuonParameters(const vector<float> *qOverPSpectro, const vector<float> *thetaSpectro, const vector<float> *phiSpectro, const vector<float> *charge);
  void setExtraMuonParameters(const vector<float> *mu_staco_ms_pt, const vector<float> *thetaSpectro, const vector<float> *phiSpectro);
  void setMuonEloss(const vector<float> *mu_energyLossPar);

  //

  void setJetParameters(const vector<float> *pT, const vector<float> *eta, const vector<float> *phi, const vector<float> *E,
			const vector<float> *wet, const vector<float> *wex, const vector<float> *wey, const vector<unsigned short> *statusWord);
  //
  void setElectronParameters(const vector<float> *pT, const vector<float> *eta, const vector<float> *phi,
			     const vector<float> *wet, const vector<float> *wex, const vector<float> *wey, const vector<unsigned short> *statusWord);
  //
  void setPhotonParameters(const vector<float> *pT, const vector<float> *eta, const vector<float> *phi,
			   const vector<float> *wet, const vector<float> *wex, const vector<float> *wey, const vector<unsigned short> *statusWord);
  //
  void setTauParameters(const vector<float> *pT, const vector<float> *eta, const vector<float> *phi,
			const vector<float> *wet, const vector<float> *wex, const vector<float> *wey, const vector<unsigned short> *statusWord);
  //
  void setClusterParameters(const vector<float> *pT, const vector<float> *eta, const vector<float> *phi,
			    const vector<float> *E, const vector<float> *wet, const vector<float> *wex, const vector<float> *wey, const vector<unsigned short> *statusWord);
  //
  void setTrackParameters(const vector<float> *pT, const vector<float> *eta, const vector<float> *phi,
			  const vector<float> *E, const vector<float> *wet, const vector<float> *wex, const vector<float> *wey, const vector<unsigned short> *statusWord);
  //
  void setMuonParameters(const vector<float> *pT, const vector<float> *eta, const vector<float> *phi,
			 const vector<float> *wet, const vector<float> *wex, const vector<float> *wey, const vector<unsigned short> *statusWord);

  //

  bool checkConsistency(METUtility::METObject met_test, const int metterm, METUtility::METObject &diff);
  bool checkConsistency(const vector<pair<int, METUtility::METObject> > & testvector, METObject &diff);

  bool checkConsistency(METUtility::METObject met_test, const int metterm=METUtil::RefFinal) {METObject diff; return checkConsistency(met_test,metterm,diff);};
  bool checkConsistency(const vector<pair<int, METUtility::METObject> > & testvector) {METObject diff; return checkConsistency(testvector,diff);};

  // leave PhysicsObject public until I figure out how to make it private without breaking 
  // RootCore and StandAlone compilation.
  // private:

  ///////////////////////////////////////////////////////////////////////////////////

  class PhysicsObject : public TNamed {
  public:
    PhysicsObject();
    ~PhysicsObject();

    void setMomenergy(float _pT, float _eta, float _phi, float _E, bool isSecondary=false);
    void setMomenergy(const TLorentzVector& _vec, bool isSecondary=false);
    void setWeights(float _wex, float _wey, float _wet){m_weights[0] = _wex; m_weights[1] = _wey; m_weights[2] = _wet;}
    void setStatusCode(unsigned int status){m_statusWord = status;}
    void setEnergyUncertainty(float energyUp, float energyDown, int iShift=0);
    inline void setResolution(float res) {m_relativeResolution = res;}
    void setResShift(float resUp, float resDown, const unsigned short type = 0);
    void setIndex(int _index){m_index = _index;}
    inline void setMiscScaleFac(float fac) {m_miscScaleFac = fac;}
 
    inline float E(bool isSecondary=false) const
    {return mom(isSecondary).E();}
    inline float Et(bool isSecondary=false) const
    {return mom(isSecondary).Et();}
    inline float Pt(bool isSecondary=false) const
    {return mom(isSecondary).Pt();}
    inline float Px(bool isSecondary=false) const
    {return mom(isSecondary).Px();}
    inline float Py(bool isSecondary=false) const
    {return mom(isSecondary).Py();}
    inline float phi(bool isSecondary=false) const
    {return mom(isSecondary).Phi();}
    inline float eta(bool isSecondary=false) const
    {return mom(isSecondary).Eta();}
    inline TLorentzVector& mom(bool isSecondary=false)
    { return isSecondary ? m_secondaryMomenergy : m_momenergy; }
    inline TLorentzVector mom(bool isSecondary=false) const
    { return isSecondary ? m_secondaryMomenergy : m_momenergy; }
    inline float wex() const {return m_weights[0];}
    inline float wey() const {return m_weights[1];}
    inline float wet() const {return m_weights[2];}
    inline unsigned int statusWord() const {return m_statusWord;}
    inline float resolution() const {return m_relativeResolution;}
    inline unsigned int index() const {return m_index;}
    inline float miscScaleFac() const {return m_miscScaleFac;}
    pair<float, float> resShift(unsigned short type=0) const;
    pair<float, float> energyShift(unsigned short type=0, int iShift=0) const;
    inline int nEnergyShift() const
    { return m_relEnergyUncertainty.size();}
 
  private:
    TLorentzVector m_momenergy;
    TLorentzVector m_secondaryMomenergy;
    float m_weights[3];
    unsigned int m_statusWord;
    float m_relativeResolution;
    unsigned int m_index;   // used for keeping track of uncertainties and weights for in vector<vector<> >
    float m_miscScaleFac;   // custom JVF RefJet or muon Eloss


    vector<pair<float, float> > m_relEnergyUncertainty; 
    pair<float, float> m_relativeResolutionShift;
 

    // bool m_isMuon; // muons have different pts, combined, track, spectro
    // let's just ComboID  in m_relativeResolutionShift
    pair<float, float> m_relativeResolutionComboMS;
    pair<float, float> m_relativeResolutionSpectro;

#ifdef METUTIL_STANDALONE
    ClassDef(PhysicsObject,1);
#endif //METUTIL_STANDALONE

  };

  METObject MissingETHelper(METUtil::Terms term, METUtil::MultiSyst systematic=METUtil::None, int iShift=0);
  void setObjectsHelper(METUtil::Objects type, vector<float> pT, vector<float> eta, vector<float> phi, vector<float> E,
			vector<vector<float> > wet, vector<vector<float> > wex, vector<vector<float> > wey, vector<vector<unsigned int> > statusWord);
  void setObjectsHelper(METUtil::Objects type, vector<float> pT, vector<float> eta, vector<float> phi, vector<float> E,
			vector<float> wet, vector<float> wex, vector<float> wey, vector<unsigned short> statusWord);
  void setObjectEnergyUncertaintiesHelper(vector<METUtility::PhysicsObject> &objects, vector<float> energyUp, vector<float> energyDown, int iShift=0);
  void setObjectResolutionShiftHelper(vector<METUtility::PhysicsObject> &objects, vector<float> resUp, vector<float> resDown, unsigned short type);
  void setObjectResolutionsHelper(vector<METUtility::PhysicsObject> &objects, vector<float> resolutions);
  void setObjectMomentaHelper(vector<METUtility::PhysicsObject> &objects, vector<float> pT, vector<float> eta, vector<float> phi, vector<float> E, bool isSecondary=false);
 
  METObject RefEle(METUtil::MultiSyst systematic, int iShift=-1);
  METObject RefGamma(METUtil::MultiSyst systematic, int iShift=-1);
  METObject RefTau(METUtil::MultiSyst systematic, int iShift=-1);
  METObject RefJet(METUtil::MultiSyst systematic, int iShift=-1);
  METObject RefMuon(METUtil::MultiSyst systematic, int iShift=-1);
  METObject MuonTotal(METUtil::MultiSyst systematic, int iShift=-1);
  METObject SoftTerms(METUtil::MultiSyst systematic, int iShift=-1);
  METObject SoftTerms_ptHard(METUtil::MultiSyst systematic, int iShift=-1);
  TVector2  calculate_ptHard();
  void      getUncert_ptHard(double pthard_GeV, bool isSTVF, double& meancs, double& rsig_l_pthard, double& rsig_t_pthard, double& dmean_l_pthard);

protected:

  vector<PhysicsObject> m_objects[7];

  // These hold the original inputs, for instance with SoftTerms we don't
  // want to feed a systematically altered term to the next systematic
  METObject m_terms[12];

  // These hold the currently scaled terms.
  METObject m_termsScaled[12];
  
  //control variables

  //check whether momenta are set
  bool m_momentaSet[7];

  //check whether energy scale uncertainties are set
  bool m_scaleShiftsSet[7];

  //check whether resolution shifts are set
  bool m_resShiftsSet[10];

  //check whether resolutions are set
  bool m_resolutionsSet[10];

  //////////////////////////////////////////////////////////////////////////////
  // Configuration members
  //

  // which terms to do
  bool m_doTerm[9];

  float m_etaCut[2];

  bool m_isMuid;
  bool m_isEflow;

  bool m_doMuEloss; // correct muons for Eloss in calo material
  bool m_muElossSet;
  bool m_doJetJVF;  // apply JVF pileup-suppression to RefJet
  bool m_jetJVFset;

  // switches to do the default cluster resolution and energy
  bool m_useStandardClusterRes;
  bool m_useStandardClusterEnergySigma;
  
  // switches for expanded JES components
  //  bool m_useJesEigenvectors;
  //  bool m_addJesPileupSyst;

  bool m_doSignificance;

  bool m_verbose;

  bool m_is2012;
  bool m_isSTVF;

  int m_nvtx;
  float m_averageIntPerXing;
  float m_softTermsResUnc;
  float m_softTermsScaleUnc;

  MissingETTags::Tags m_jet_pu_statusWord;
  MissingETTags::Tags m_st_pu_statusWord;

  //////////////////////////////////////////////////////////////////////////////
  // Intended as a temporary fix to be validated
  //
  bool m_doEgammaJetFix;
  bool m_useConstPtForFix;
  bool m_moveOLJetToCellOut;
  double m_egammaJetFixDeltaR;
  //
  //     electron-jet overlap removal patch
  //////////////////////////////////////////////////////////////////////////////

#ifdef METUTIL_STANDALONE
  ClassDef(METUtility,1);
#endif //METUTIL_STANDALONE
 
};//end of METUtility class



#endif // _METUTILITY_
