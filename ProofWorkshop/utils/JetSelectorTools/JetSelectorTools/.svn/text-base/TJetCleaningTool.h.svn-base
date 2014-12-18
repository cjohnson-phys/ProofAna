// Dear emacs, this is -*-c++-*-

#ifndef __TJETCLEANINGTOOL__
#define __TJETCLEANINGTOOL__

/**
   @class TJetCleaningTool
   @brief Example tool to select objects in pure ROOT

   @author Karsten Koeneke (CERN)
   @date   July 2011
*/


// ROOT includes
#include <TString.h>

// Include the return object and the base class 
#include "ObjectSelectorCore/TAccept.h"
#include "ObjectSelectorCore/TSelectorToolBase.h"


namespace Root {
  class TJetCleaningTool : public TSelectorToolBase
  {

  public: 
    /** Standard constructor */
    TJetCleaningTool(const char* name="TJetCleaningTool");

    /** Standard destructor */
    ~TJetCleaningTool();

#ifdef ROOTCORE
    /** For PROOF streaming */
    ClassDef(TJetCleaningTool,1);
#endif

    // Main methods
  public:
    /** Initialize this class */
    int initialize();

    /** Finalize this class; everything that should be done after the event loop should go here */
    inline int finalize() { return 1; };

    /** The main accept method: the actual cuts are applied here */
    const Root::TAccept& accept( double eta,
                                 double negativeEnergy,
                                 double hecf,
                                 double hecq,
                                 double emf,
                                 double chf,
                                 double larq,
                                 double time,
                                 double fmax, 
				 double AverageLArQF );


    // Public members (the cut values)
  public:

    
    double HECLooserHECfMax , HECLooserHECQMax, HECLooserLArQMeanMax ;
    double EMLooserHECEMFMax , EMLooserLArQMax, EMLooserLArQMeanMax , EMLooserEtaMin; 
    double CosmicTightCHFMin,  CosmicTightEtaMin ;
    
    /** maximum HECf cut value */
    double HECfMax;

    /** maximum HECQ cut value */
    double HECQMax;

    /** maximum HECfandQ cut value */
    double HECfandQMax;

    /** maximum negative energy cut value */
    double NegEMax;

    /** maximum EMf for EM coherent noise cut */
    double EMNoiseEMfMax;

    /** maximum LAr quality for EM coherent noise cut */
    double EMNoiseLArQMax;

    /** minimum |eta| for EM coherent noise cut */
    double EMNoiseAbsEtaMin;

    /** maximum LAr quality cut */
    double LArQMax;

    /** maximum EMf for EM coherent noise tight cut */
    double EMNoiseTightEMfMax;

    /** maximum LAr quality for EM coherent noise tight cut */
    double EMNoiseTightLArQMax;

    /** maximum time cut value */
    double TimeMax;

    /** minimum EMf for cosmics cut */
    double CosmicsEMfMin;

    /** minimum charge fraction for cosmics cut */
    double CosmicsChfMin;

    /** minimum charge fraction for cosmics cut *****rel 17***/
        double CosmicsChfMinTight;//rel 17


    /** minimum |eta| for cosmics cut */
    double CosmicsAbsEtaMin;

    /** minimum |eta| for cosmics cut ******rel 17***/
    double CosmicsAbsEtaMinTight;


    /** minimum EMf for cosmics cut at high |eta| */
    double CosmicsHighEtaEMfMin;

    /** maximum |eta| for cosmics cut */
    double CosmicsAbsEtaMax;

    /** maximum EMf for cosmics cut 2 */
    double Cosmics2EMfMax;

    /** minimum charge fraction for cosmics cut 2 */
    double Cosmics2ChfMin;

    /** minimum |eta| for cosmics cut 2 */
    double Cosmics2AbsEtaMin;

    /** maximum EMf for cosmics cut 3 */
    double Cosmics3EMfMax;

    /** minimum charge fraction for cosmics cut 3 */
    double Cosmics3ChfMin;

    /** minimum |eta| for cosmics cut 3 */
    double Cosmics3AbsEtaMin;

    /** minimum EMf for cosmics Fmax cut */
    double CosmicsFMaxMax;

    /** minimum |eta| for cosmics Fmax cut */
    double CosmicsFMaxAbsEtaMin;




    // Private members
  private:

    const TString m_cutNameHECLooserLArQMean ; 
    int m_cutPositionHECLooserLArQMean ; 

    const TString m_cutNameHECLooserEMF ;
    int m_cutPositionHECLooserEMF ; 
    
    int m_cutPositionCosmicTightCHF ;
    const TString  m_cutNameCosmicTightCHF ;

    /** Name of the HECf || HECQ cut */
    const TString m_cutNameHECfQ;

    /** Position of the HECf || HECQ cut */
    int m_cutPositionHECfQ;


    /** Name of the HECf && HECQ cut */
    const TString m_cutNameHECfandQ;

    /** Position of the HECf && HECQ cut */
    int m_cutPositionHECfandQ;


    /** Name of the negative energy cut */
    const TString m_cutNameNegE;

    /** Position of the negative energy cut */
    int m_cutPositionNegE;


    /** Name of the EM coherent noise cut */
    const TString m_cutNameEMNoise;

    /** Position of the EM coherent noise cut */
    int m_cutPositionEMNoise;


    /** Name of the LAr quality cut */
    const TString m_cutNameLArQ;

    /** Position of the LAr quality cut */
    int m_cutPositionLArQ;


    /** Name of the EM coherent noise tight cut */
    const TString m_cutNameEMNoiseTight;

    /** Position of the EM coherent noise tight cut */
    int m_cutPositionEMNoiseTight;


    /** Name of the time cut */
    const TString m_cutNameTime;

    /** Position of the time cut */
    int m_cutPositionTime;


    /** Name of the cosmics cut */
    const TString m_cutNameCosmicsEMfChf;

    /** Position of the cosmics cut */
    int m_cutPositionCosmicsEMfChf;


    /** Name of the cosmics cut */
    const TString m_cutNameCosmicsChfTight;    //for rel 17

    /** Position of the cosmics cut */
    int m_cutPositionCosmicsChfTight;    //for rel 17


    /** Name of the cosmics cut at high |eta| */
    const TString m_cutNameCosmicsHighEta;

    /** Position of the cosmics cut at high |eta| */
    int m_cutPositionCosmicsHighEta;


    /** Name of the cosmics cut 2 */
    const TString m_cutNameCosmics2EMfChf;

    /** Position of the cosmics cut 2 */
    int m_cutPositionCosmics2EMfChf;


    /** Name of the cosmics cut 3 */
    const TString m_cutNameCosmics3EMfChf;

    /** Position of the cosmics cut 3 */
    int m_cutPositionCosmics3EMfChf;


    /** Name of the cosmics Fmax cut */
    const TString m_cutNameCosmicsFMax;

    /** Position of the cosmics Fmax cut */
    int m_cutPositionCosmicsFMax;


  }; // End: class definition

} // End: namespace Root

#endif

