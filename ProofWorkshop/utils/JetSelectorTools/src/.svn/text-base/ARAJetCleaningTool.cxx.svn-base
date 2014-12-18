// Dear emacs, this is -*-c++-*-

/**
   @class ARAJetCleaningTool
   @brief Example tool to select objects in AthenaRootAccess using an underlying pure ROOT tool.

   @author Karsten Koeneke (CERN)
   @date   July 2011

*/

// Include this class's header
#include "JetSelectorTools/ARAJetCleaningTool.h"

// STL includes
#include <string>
#include <cfloat>
#include <iostream>

// Include the return object
#include "ObjectSelectorCore/TAccept.h"

// Atlas includes
#include "JetEvent/Jet.h"
#include "EventKernel/INavigable4Momentum.h"

// Needed jet helpers
#include "JetUtils/JetCaloQualityUtils.h"
#include "JetUtils/JetCaloHelper.h"


//=============================================================================
// Standard constructor
//=============================================================================
ARAJetCleaningTool::ARAJetCleaningTool( PropertyMgr *pmgr ):
  AraToolBase(pmgr),
  ARASelectorToolBase(pmgr),
  m_rootTool(0)
{
  m_rootTool = new Root::TJetCleaningTool();
  // Declare the needed properties
  declareProperty( "HECfMax",              m_rootTool->HECfMax,              "Cut HECfMax");
  declareProperty( "HECQMax",              m_rootTool->HECQMax,              "Cut HECQMax");
  declareProperty( "HECfandQMax",          m_rootTool->HECfandQMax,          "Cut HECfandQMax");
  declareProperty( "NegEMax",              m_rootTool->NegEMax,              "Cut NegEMax");
  declareProperty( "EMNoiseEMfMax",        m_rootTool->EMNoiseEMfMax,        "Cut EMNoiseEMfMax");
  declareProperty( "EMNoiseLArQMax",       m_rootTool->EMNoiseLArQMax,       "Cut EMNoiseLArQMax");
  declareProperty( "EMNoiseAbsEtaMin",     m_rootTool->EMNoiseAbsEtaMin,     "Cut EMNoiseAbsEtaMin");
  declareProperty( "LArQMax",              m_rootTool->LArQMax,              "Cut LArQMax");
  declareProperty( "EMNoiseTightEMfMax",   m_rootTool->EMNoiseTightEMfMax,   "Cut EMNoiseTightEMfMax");
  declareProperty( "EMNoiseTightLArQMax",  m_rootTool->EMNoiseTightLArQMax,  "Cut EMNoiseTightLArQMax");
  declareProperty( "TimeMax",              m_rootTool->TimeMax,              "Cut TimeMax");
  declareProperty( "CosmicsEMfMin",        m_rootTool->CosmicsEMfMin,        "Cut CosmicsEMfMin");
  declareProperty( "CosmicsChfMin",        m_rootTool->CosmicsChfMin,        "Cut CosmicsChfMin");
  declareProperty( "CosmicsAbsEtaMin",     m_rootTool->CosmicsAbsEtaMin,     "Cut CosmicsAbsEtaMin");
  declareProperty( "CosmicsHighEtaEMfMin", m_rootTool->CosmicsHighEtaEMfMin, "Cut CosmicsHighEtaEMfMin");
  declareProperty( "CosmicsAbsEtaMax",     m_rootTool->CosmicsAbsEtaMax,     "Cut CosmicsAbsEtaMax");
  declareProperty( "Cosmics2EMfMax",       m_rootTool->Cosmics2EMfMax,       "Cut Cosmics2EMfMax");
  declareProperty( "Cosmics2ChfMin",       m_rootTool->Cosmics2ChfMin,       "Cut Cosmics2ChfMin");
  declareProperty( "Cosmics2AbsEtaMin",    m_rootTool->Cosmics2AbsEtaMin,    "Cut Cosmics2AbsEtaMin");
  declareProperty( "Cosmics3EMfMax",       m_rootTool->Cosmics3EMfMax,       "Cut Cosmics3EMfMax");
  declareProperty( "Cosmics3ChfMin",       m_rootTool->Cosmics3ChfMin,       "Cut Cosmics3ChfMin");
  declareProperty( "Cosmics3AbsEtaMin",    m_rootTool->Cosmics3AbsEtaMin,    "Cut Cosmics3AbsEtaMin");
  declareProperty( "CosmicsFMaxMax",       m_rootTool->CosmicsFMaxMax,       "Cut CosmicsFMaxMax");
  declareProperty( "CosmicsFMaxAbsEtaMin", m_rootTool->CosmicsFMaxAbsEtaMin, "Cut CosmicsFMaxAbsEtaMin");

  declareProperty( "CosmicTightCHFMin",    m_rootTool->CosmicTightCHFMin,    "Cut CosmicTightCHFMin");
  declareProperty( "CosmicTightEtaMin",    m_rootTool->CosmicTightEtaMin,    "Cut CosmicTightEtaMin");

  declareProperty( "HECLooserHECfMax",     m_rootTool->HECLooserHECfMax,     "HECLooserHECfMax" ) ;  
  declareProperty( "HECLooserHECQMax",     m_rootTool->HECLooserHECQMax,     "HECLooserHECQMax" ) ;  
  declareProperty( "HECLooserLArQMeanMax", m_rootTool->HECLooserLArQMeanMax, "HECLooserLArQMeanMax" );
  declareProperty( "EMLooserHECEMFMax"  ,  m_rootTool->EMLooserHECEMFMax,    "EMLooserHECEMFMax" ) ; 
  declareProperty( "EMLooserLArQMax" ,     m_rootTool->EMLooserLArQMax ,     "EMLooserLArQMax"   ) ; 
  declareProperty( "EMLooserLArQMeanMax" , m_rootTool->EMLooserLArQMeanMax,  "EMLooserLArQMeanMax" ) ;  
  declareProperty( "EMLooserEtaMin"   ,    m_rootTool->EMLooserEtaMin,       "EMLooserEtaMin"    ) ; 

}


//=============================================================================
// Standard destructor
//=============================================================================
ARAJetCleaningTool::~ARAJetCleaningTool()
{
  if ( m_rootTool ) delete m_rootTool;
}


//=============================================================================
// Athena initialize method
//=============================================================================
StatusCode ARAJetCleaningTool::initialize()
{
  // The standard status code
  StatusCode sc = StatusCode::SUCCESS ;

  // We need to initialize the underlying ROOT TSelectorTool
  if ( 0 == m_rootTool->initialize() )
    {
      std::cerr << "ERROR! Could not initialize the TJetCleaningTool!" << std::endl;
      sc = StatusCode::FAILURE;
      return sc;
    }

  return sc ;
}


//=============================================================================
// Athena finalize method
//=============================================================================
StatusCode ARAJetCleaningTool::finalize()
{
  // The standard status code
  StatusCode sc = StatusCode::SUCCESS ;

  if ( !(m_rootTool->finalize()) )
    {
      std::cerr << "ERROR! Something went wrong at finalize!" << std::endl;
      sc = StatusCode::FAILURE;
    }

  return sc ;
}


//=============================================================================
// The main accept method: the actual cuts are applied here 
//=============================================================================
const Root::TAccept& ARAJetCleaningTool::accept( const Jet* jet )
{
  if ( jet )
    {
      // Here, you have to make the translation from the ATLAS EDM object to the variables of simple type
      double pt     = jet->pt();
      double eta    = jet->eta(P4SignalState::JETEMSCALE) ;  // jet->eta();
      double negE   = jet->getMoment("NegativeE");
      double hecf   = JetCaloQualityUtils::hecF(jet);
      double hecq   = jet->getMoment("HECQuality");          // JetCaloQualityUtils::jetQualityHEC(jet);
      double emf    = JetCaloHelper::jetEMFraction(jet);
      double larq   = jet->getMoment("LArQuality");
      double time   = jet->getMoment("Timing");
      double AverageLArQF = jet->getMoment("AverageLArQF") ; 

      double chf(10.0);
      if ( pt != 0.0 )
        {
          chf = jet ->getMoment("sumPtTrk") / pt;
        }

      int SamplingMax = CaloSampling::Unknown; 
      double fmax     = JetCaloQualityUtils::fracSamplingMax(jet,SamplingMax); 

      // Call the underlying root tool
      return m_rootTool->accept( eta,
                                 negE,
                                 hecf,
                                 hecq,
                                 emf,
                                 chf,
                                 larq,
                                 time,
                                 fmax , AverageLArQF );
    }
  else
    {
      return m_acceptDummy;
    }
}

