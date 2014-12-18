##=============================================================================
## Name:        JetCleaningCutDefs
##
## Author:      Karsten Koeneke (CERN)
## Created:     July 2011
##
## Description: Define the cut values for jet cleaning
##
##=============================================================================

# import the needed Reflex and ROOT stuff
import PyCintex
PyCintex.Cintex.Enable()
import ROOT

# Import a needed helper
from ObjectSelectorCore.HelperUtils import *

# Define GeV
GeV = 1000.0



def JetCleaningToolConfig_VeryLoose(theTool) :
    """
    This defines the jet cleaning cut values for the very Loose (Looser) operating point
    """
    theTool = GetTool(theTool)

    # HEC Spikes
    theTool.HECLooserHECfMax     = 0.5
    theTool.HECLooserHECQMax     = 0.5
    theTool.HECLooserLArQMeanMax = 0.8
    theTool.NegEMax              = 60.0*GeV

    # EM Coherent Noise 
    theTool.EMLooserHECEMFMax    = 0.95
    theTool.EMLooserLArQMax      = 0.8
    theTool.EMLooserLArQMeanMax  = 0.8
    theTool.EMLooserEtaMin       = 2.8 

    # Non-collision Background
    theTool.CosmicsEMfMin        = 0.05
    theTool.CosmicsChfMin        = 0.05
    theTool.CosmicsAbsEtaMin     = 2.0
    theTool.CosmicsHighEtaEMfMin = 0.05
    theTool.CosmicsAbsEtaMax     = 2.0
    theTool.CosmicsFMaxMax       = 0.99
    theTool.CosmicsFMaxAbsEtaMin = 2.0
    pass



def JetCleaningToolConfig_Loose(theTool) :
    """
    This defines the jet cleaning cut values for the Loose operating point.
    """
    theTool = GetTool(theTool)
    
    # HEC Spikes
    theTool.HECLooserHECfMax     = 0.5
    theTool.HECLooserHECQMax     = 0.5
    theTool.HECLooserLArQMeanMax = 0.8
    theTool.NegEMax              = 60.0*GeV

    theTool.HECfMax              = 0.5
    theTool.HECQMax              = 0.5
    
    

    # EM Coherent Noise 
    theTool.EMLooserHECEMFMax    = 0.95
    theTool.EMLooserLArQMax      = 0.8
    theTool.EMLooserLArQMeanMax  = 0.8
    theTool.EMLooserEtaMin       = 2.8 

    theTool.EMNoiseEMfMax        = 0.95
    theTool.EMNoiseLArQMax       = 0.8
    theTool.EMNoiseAbsEtaMin     = 2.8



    # Non-collision Background
    theTool.CosmicsEMfMin        = 0.05
    theTool.CosmicsChfMin        = 0.05
    theTool.CosmicsAbsEtaMin     = 2.0
    theTool.CosmicsHighEtaEMfMin = 0.05
    theTool.CosmicsAbsEtaMax     = 2.0
    theTool.CosmicsFMaxMax       = 0.99
    theTool.CosmicsFMaxAbsEtaMin = 2.0

    theTool.TimeMax              = 25.0 # ns
    

    

    pass




def JetCleaningToolConfig_Medium(theTool) :
    """
    This defines the jet cleaning cut values for the Medium operating point.
    """
    theTool = GetTool(theTool)
    
    # HEC Spikes
    theTool.HECLooserHECfMax     = 0.5
    theTool.HECLooserHECQMax     = 0.5
    theTool.HECLooserLArQMeanMax = 0.8
    theTool.NegEMax              = 60.0*GeV

    theTool.HECfMax              = 0.5
    theTool.HECQMax              = 0.5
    
    theTool.HECfandQMax          = 1.0

    # EM Coherent Noise 
    theTool.EMLooserHECEMFMax    = 0.95
    theTool.EMLooserLArQMax      = 0.8
    theTool.EMLooserLArQMeanMax  = 0.8
    theTool.EMLooserEtaMin       = 2.8 

    theTool.EMNoiseEMfMax        = 0.9 
    theTool.EMNoiseLArQMax       = 0.8
    theTool.EMNoiseAbsEtaMin     = 2.8


    # Non-collision Background
    theTool.CosmicsEMfMin        = 0.05
    theTool.CosmicsChfMin        = 0.1
    theTool.CosmicsAbsEtaMin     = 2.0
    theTool.CosmicsHighEtaEMfMin = 0.05
    theTool.CosmicsAbsEtaMax     = 2.0
    theTool.CosmicsFMaxMax       = 0.99
    theTool.CosmicsFMaxAbsEtaMin = 2.0

    theTool.Cosmics2EMfMax       = 0.95
    theTool.Cosmics2ChfMin       = 0.05
    theTool.Cosmics2AbsEtaMin    = 2.0

    
    theTool.TimeMax              = 10. # ns

    pass


def JetCleaningToolConfig_Tight(theTool) :
    """
    This defines the jet cleaning cut values for the Tight operating point.
    """
    theTool = GetTool(theTool)

    # HEC Spikes
    theTool.HECLooserHECfMax     = 0.5
    theTool.HECLooserHECQMax     = 0.5
    theTool.HECLooserLArQMeanMax = 0.8
    theTool.NegEMax              = 60.0*GeV

    theTool.HECfMax              = 0.5
    theTool.HECQMax              = 0.5
    
    theTool.HECfandQMax          = 1.0

    
    # EM Coherent Noise 
    theTool.EMLooserHECEMFMax    = 0.95
    theTool.EMLooserLArQMax      = 0.8
    theTool.EMLooserLArQMeanMax  = 0.8
    theTool.EMLooserEtaMin       = 2.8 

    theTool.EMNoiseEMfMax        = 0.9 
    theTool.EMNoiseLArQMax       = 0.8
    theTool.EMNoiseAbsEtaMin     = 2.8

    theTool.LArQMax              = 0.95
    theTool.EMNoiseTightEMfMax   = 0.98
    theTool.EMNoiseTightLArQMax  = 0.05

    

    # Non-collision Background
    theTool.CosmicsEMfMin        = 0.05
    theTool.CosmicsChfMin        = 0.1
    theTool.CosmicsAbsEtaMin     = 2.0

    theTool.CosmicsHighEtaEMfMin = 0.1
    theTool.CosmicsAbsEtaMax     = 2.0

    theTool.CosmicsFMaxMax       = 0.99
    theTool.CosmicsFMaxAbsEtaMin = 2.0

    theTool.Cosmics2EMfMax       = 0.9
    theTool.Cosmics2ChfMin       = 0.1
    theTool.Cosmics2AbsEtaMin    = 2.5
    
    theTool.TimeMax              = 10. # ns

    theTool.CosmicTightCHFMin    = 0.2
    theTool.CosmicTightEtaMin    = 2.5 
    

    
    pass

