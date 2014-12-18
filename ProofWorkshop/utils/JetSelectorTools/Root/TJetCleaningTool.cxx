// Dear emacs, this is -*-c++-*-

/******************************************************************************
Name:        TJetCleaningTool

Author:      Karsten Koeneke (CERN)
Modified:    Harinder Bawa (for rel17), Haifeng Li <Haifeng.Li@cern.ch>
Created:     July 2011

Description: Example tool to select objects in pure ROOT
******************************************************************************/

// Preprocessor magic for debugging
#define XXX std::cout << "I am here: " << __FILE__ << ":" << __LINE__ << std::endl;

// This class header
#include "JetSelectorTools/TJetCleaningTool.h"

// STL includes
#include <iostream>
#include <cfloat>
#include <math.h>

// ROOT includes
#include "TString.h"



//=============================================================================
// Constructor
//=============================================================================
Root::TJetCleaningTool::TJetCleaningTool(const char* name) :
  TSelectorToolBase(name),
  HECLooserHECfMax(DBL_MAX), 
  HECLooserHECQMax(DBL_MAX),
  HECLooserLArQMeanMax(DBL_MAX), 
  EMLooserHECEMFMax(DBL_MAX), 
  EMLooserLArQMax(DBL_MAX),
  EMLooserLArQMeanMax(DBL_MAX),
  EMLooserEtaMin(-DBL_MAX) ,
  CosmicTightCHFMin(-DBL_MAX),  
  CosmicTightEtaMin(-DBL_MAX),
  //
  HECfMax(DBL_MAX),
  HECQMax(DBL_MAX),
  HECfandQMax(DBL_MAX),
  NegEMax(DBL_MAX),
  EMNoiseEMfMax(DBL_MAX),
  EMNoiseLArQMax(DBL_MAX),
  EMNoiseAbsEtaMin(-DBL_MAX),
  LArQMax(DBL_MAX),
  EMNoiseTightEMfMax(DBL_MAX),
  EMNoiseTightLArQMax(DBL_MAX),
  TimeMax(DBL_MAX),
  CosmicsEMfMin(-DBL_MAX),
  CosmicsChfMin(-DBL_MAX),
  CosmicsChfMinTight(-DBL_MAX),//rel 17
  CosmicsAbsEtaMin(-DBL_MAX),
  CosmicsAbsEtaMinTight(-DBL_MAX),//rel 17
  CosmicsHighEtaEMfMin(-DBL_MAX),
  CosmicsAbsEtaMax(DBL_MAX),
  Cosmics2EMfMax(DBL_MAX),
  Cosmics2ChfMin(-DBL_MAX),
  Cosmics2AbsEtaMin(-DBL_MAX),
  Cosmics3EMfMax(DBL_MAX),
  Cosmics3ChfMin(-DBL_MAX),
  Cosmics3AbsEtaMin(-DBL_MAX),
  CosmicsFMaxMax(DBL_MAX),
  CosmicsFMaxAbsEtaMin(-DBL_MAX),
  //
  m_cutNameHECLooserLArQMean("HECLooserLArQMean"), 
  m_cutPositionHECLooserLArQMean(-9),
  m_cutNameHECLooserEMF("HECLooserEMF"), 
  m_cutPositionHECLooserEMF(-9), 
  m_cutPositionCosmicTightCHF(-9), 
  m_cutNameCosmicTightCHF("CosmicTightCHF"),
  m_cutNameHECfQ("HECforHECQ"),
  m_cutPositionHECfQ(-9),
  m_cutNameHECfandQ("HECfandHECQ"),
  m_cutPositionHECfandQ(-9),
  m_cutNameNegE("NegativeE"),
  m_cutPositionNegE(-9),
  m_cutNameEMNoise("EMNoise"),
  m_cutPositionEMNoise(-9),
  m_cutNameLArQ("LArQ"),
  m_cutPositionLArQ(-9),
  m_cutNameEMNoiseTight("EMNoiseTight"),
  m_cutPositionEMNoiseTight(-9),
  m_cutNameTime("Timing"),
  m_cutPositionTime(-9),
  m_cutNameCosmicsEMfChf("CosmicsEMfChf"),
  m_cutPositionCosmicsEMfChf(-9),
  m_cutNameCosmicsChfTight("CosmicsChfTight"),//added for rel17
  m_cutPositionCosmicsChfTight(-9),
  m_cutNameCosmicsHighEta("CosmicsHighEta"),
  m_cutPositionCosmicsHighEta(-9),
  m_cutNameCosmics2EMfChf("Cosmics2EMfChf"),
  m_cutPositionCosmics2EMfChf(-9),
  m_cutNameCosmics3EMfChf("Cosmics3EMfChf"),
  m_cutPositionCosmics3EMfChf(-9),
  m_cutNameCosmicsFMax("CosmicsFMax"),
  m_cutPositionCosmicsFMax(-9)
{
}



//=============================================================================
// Destructor
//=============================================================================
Root::TJetCleaningTool::~TJetCleaningTool()
{
}



//=============================================================================
// Initialize this selector tool
//=============================================================================
int Root::TJetCleaningTool::initialize()
{
  // use an int as a StatusCode
  int sc(1);


  // --------------------------------------------------------------------------
  // Register the cuts and check that the registration worked:
  // NOTE: THE ORDER IS IMPORTANT!!!


  m_cutPositionHECLooserLArQMean = m_accept.addCut( m_cutNameHECLooserLArQMean, 
						    Form( "HECf< %g or |HECQ| < %g or LArQMean < %g",  
							  HECLooserHECfMax , HECLooserHECQMax, HECLooserLArQMeanMax ) )  ; 
  
  if ( m_cutPositionHECLooserLArQMean < 0 ) sc = 0 ;  


  m_cutPositionHECLooserEMF =  m_accept.addCut( m_cutNameHECLooserEMF, 
						Form ( "EMf < %g or |LArQ| < %g or LArQMean < %g or |eta| > %g", 
						       EMLooserHECEMFMax, EMLooserLArQMax, EMLooserLArQMeanMax, EMLooserEtaMin ) ) ; 

  if (  m_cutPositionHECLooserEMF < 0 ) sc = 0 ; 


  


  // HECf && HECQ
  m_cutPositionHECfQ = m_accept.addCut( m_cutNameHECfQ,
                                        Form("HECf < %g or |HECQ| < %g", HECfMax, HECQMax) );
  if ( m_cutPositionHECfQ < 0 ) sc = 0; // Exceeded the number of allowed cuts

  // HECf + HECQ
  m_cutPositionHECfandQ = m_accept.addCut( m_cutNameHECfandQ, Form("HECf + |HECQ| < %g", HECfandQMax) );
  if ( m_cutPositionHECfandQ < 0 ) sc = 0; // Exceeded the number of allowed cuts

  // negative energy
  m_cutPositionNegE = m_accept.addCut( m_cutNameNegE, Form("|negative energy| < %g", NegEMax) );
  if ( m_cutPositionNegE < 0 ) sc = 0; // Exceeded the number of allowed cuts



  // EM coherent noise
  m_cutPositionEMNoise = m_accept.addCut( m_cutNameEMNoise,
                                          Form("EMf < %g or |LArQ| < %g or |eta| > %g",
                                               EMNoiseEMfMax, EMNoiseLArQMax, EMNoiseAbsEtaMin) );
  if ( m_cutPositionEMNoise < 0 ) sc = 0; // Exceeded the number of allowed cuts

  // LAr quality
  m_cutPositionLArQ = m_accept.addCut( m_cutNameLArQ, Form("fabs(LArQ) < %g", LArQMax) );
  if ( m_cutPositionLArQ < 0 ) sc = 0; // Exceeded the number of allowed cuts

  // EM coherent noise tight
  m_cutPositionEMNoiseTight = m_accept.addCut( m_cutNameEMNoiseTight,
                                               Form("EMf < %g or |LArQ| < %g",
                                                    EMNoiseTightEMfMax, EMNoiseTightLArQMax) );
  if ( m_cutPositionEMNoiseTight < 0 ) sc = 0; // Exceeded the number of allowed cuts



  // Timing
  m_cutPositionTime = m_accept.addCut( m_cutNameTime, Form("fabs(time) < %g", TimeMax) );
  if ( m_cutPositionTime < 0 ) sc = 0; // Exceeded the number of allowed cuts

  // Cosmics EM fraction and Charge fraction at low |eta|
  m_cutPositionCosmicsEMfChf = m_accept.addCut( m_cutNameCosmicsEMfChf,
                                                Form("EMf > %g or Chf > %g or |eta| > %g",
                                                     CosmicsEMfMin, CosmicsChfMin, CosmicsAbsEtaMin) );
  if ( m_cutPositionCosmicsEMfChf < 0 ) sc = 0; // Exceeded the number of allowed cuts


   // Cosmics Charge fraction at low |eta|  added for rel 17
  m_cutPositionCosmicsChfTight = m_accept.addCut( m_cutNameCosmicsChfTight,
                                                Form("Chf > %g or |eta| > %g",
                                                     CosmicsChfMinTight, CosmicsAbsEtaMinTight) );
  if ( m_cutPositionCosmicsChfTight < 0 ) sc = 0; // Exceeded the number of allowed cuts


  // Cosmics EM fraction fraction at high |eta|
  m_cutPositionCosmicsHighEta = m_accept.addCut( m_cutNameCosmicsHighEta,
                                                Form("EMf > %g or |eta| =< %g",
                                                     CosmicsHighEtaEMfMin, CosmicsAbsEtaMax) );
  if ( m_cutPositionCosmicsHighEta < 0 ) sc = 0; // Exceeded the number of allowed cuts


  // Cosmics 2 EM fraction and Charge fraction at low |eta|
  m_cutPositionCosmics2EMfChf = m_accept.addCut( m_cutNameCosmics2EMfChf,
                                                 Form("EMf < %g or Chf > %g or |eta| > %g",
                                                      Cosmics2EMfMax, Cosmics2ChfMin, Cosmics2AbsEtaMin) );
  if ( m_cutPositionCosmics2EMfChf < 0 ) sc = 0; // Exceeded the number of allowed cuts

  // Cosmics 3 EM fraction and Charge fraction at low |eta|
  m_cutPositionCosmics3EMfChf = m_accept.addCut( m_cutNameCosmics3EMfChf,
                                                 Form("EMf < %g or Chf > %g or |eta| > %g",
                                                      Cosmics3EMfMax, Cosmics3ChfMin, Cosmics3AbsEtaMin) );
  if ( m_cutPositionCosmics3EMfChf < 0 ) sc = 0; // Exceeded the number of allowed cuts

  // Cosmics Fmax
  m_cutPositionCosmicsFMax = m_accept.addCut( m_cutNameCosmicsFMax,
                                              Form("Fmax < %g or |eta| > %g",
                                                   CosmicsFMaxMax, CosmicsFMaxAbsEtaMin) );
  if ( m_cutPositionCosmicsFMax < 0 ) sc = 0; // Exceeded the number of allowed cuts


  m_cutPositionCosmicTightCHF = m_accept.addCut( m_cutNameCosmicTightCHF, 
						 Form("CHF > %g or |eta| > %g", CosmicTightCHFMin,  CosmicTightEtaMin )) ; 

  if ( m_cutPositionCosmicTightCHF < 0 ) sc = 0 ;

  return sc;
}



//=============================================================================
// Calculate the actual accept of each cut individually.
//=============================================================================
const Root::TAccept& Root::TJetCleaningTool::accept( double eta,
                                                     double negativeEnergy,
                                                     double hecf,
                                                     double hecq,
                                                     double emf,
                                                     double chf,
                                                     double larq,
                                                     double time,
                                                     double fmax, 
						     double AverageLArQF )
{
  // Reset the cut result bits to zero (= fail cut)
  m_accept.clear();

  // -----------------------------------------------------------
  // Do the actual selection

  //--- Add by Haifeng Li 

  double LArQmean = AverageLArQF / 65535. ;  
  
  // Looser HEC Spikes
  m_accept.setCutResult( m_cutPositionHECLooserLArQMean,  
			 ( hecf < HECLooserHECfMax || fabs(hecq) < HECLooserHECQMax || LArQmean < HECLooserLArQMeanMax) ? true : false ) ; 

  // Looser EM Coherent Noise
  m_accept.setCutResult( m_cutPositionHECLooserEMF, 
			 ( emf < EMLooserHECEMFMax || fabs(larq) < EMLooserLArQMax || LArQmean < EMLooserLArQMeanMax || fabs(eta) > EMLooserEtaMin) ? true : false );
  // Tight Cosmic
  m_accept.setCutResult( m_cutPositionCosmicTightCHF, 
			 ( chf > CosmicTightCHFMin || fabs(eta) > CosmicTightEtaMin ) ? true : false )  ; 


  // HECf or HECQ 
  m_accept.setCutResult( m_cutPositionHECfQ, ( hecf < HECfMax || fabs(hecq) < HECQMax ) ? true : false );

  // HECf and HECQ 
  m_accept.setCutResult( m_cutPositionHECfandQ, ( hecf + fabs(hecq) < HECfandQMax ) ? true : false );

  // Negative energy
  m_accept.setCutResult( m_cutPositionNegE, (fabs(negativeEnergy) < NegEMax) ? true : false );



  // EM coherent noise
  m_accept.setCutResult( m_cutPositionEMNoise,
                         (emf < EMNoiseEMfMax || fabs(larq) < EMNoiseLArQMax || fabs(eta) > EMNoiseAbsEtaMin) ? true : false );

  // LAr quality
  m_accept.setCutResult( m_cutPositionLArQ, (fabs(larq) < LArQMax) ? true : false );

  // EM coherent noise tight
  m_accept.setCutResult( m_cutPositionEMNoiseTight,
                         (emf < EMNoiseTightEMfMax || fabs(larq) < EMNoiseTightLArQMax) ? true : false );



  // Timing
  m_accept.setCutResult( m_cutPositionTime, (fabs(time) < TimeMax) ? true : false );


  // medium2:: Cosmics EM fraction and Charge fraction at low |eta|
     m_accept.setCutResult( m_cutPositionCosmicsEMfChf,
                         (emf > CosmicsEMfMin || chf > CosmicsChfMin || fabs(eta) > CosmicsAbsEtaMin) ? true : false );

 // tight1:: Cosmics charge fraction at low |eta|***   added for rel 17
     m_accept.setCutResult( m_cutPositionCosmicsChfTight,
                         (chf > CosmicsChfMinTight || fabs(eta) > CosmicsAbsEtaMinTight) ? true : false );



  //loose(3) :  Cosmics EM fraction fraction at high |eta|
  m_accept.setCutResult( m_cutPositionCosmicsHighEta,
                         (emf > CosmicsHighEtaEMfMin || fabs(eta) <= CosmicsAbsEtaMax) ? true : false );


  // medium(3): Cosmics 2 EM fraction and Charge fraction at low |eta|
  m_accept.setCutResult( m_cutPositionCosmics2EMfChf,
                         (emf < Cosmics2EMfMax || chf > Cosmics2ChfMin || fabs(eta) > Cosmics2AbsEtaMin) ? true : false );



  // tight(3): Cosmics 3 EM fraction and Charge fraction at low |eta|
  m_accept.setCutResult( m_cutPositionCosmics3EMfChf,
                         (emf < Cosmics3EMfMax || chf > Cosmics3ChfMin || fabs(eta) > Cosmics3AbsEtaMin) ? true : false );



  // loose (4): Cosmics Fmax cut at low |eta|
  m_accept.setCutResult( m_cutPositionCosmicsFMax,
                         (fmax < CosmicsFMaxMax || fabs(eta) >= CosmicsFMaxAbsEtaMin) ? true : false );


  return m_accept;
}

