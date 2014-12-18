##=============================================================================
## Name:        ConfiguredARAJetCleaningTools
##
## Author:      Karsten Koeneke (CERN)
## Created:     July 2011
##
## Description: Apply the default configurations for the ARAJetCleaningTool.
##
## Usage: In your pyARA session:
##        from JetSelectorTools.ConfiguredARAJetCleaningTools import *
##        myLooseJetCleanTool = ConfiguredARAJetCleaningTool_Loose()
##        myLooseJetCleanTool->initialize();
##
##=============================================================================

# import the needed Reflex and ROOT stuff
import PyCintex
PyCintex.Cintex.Enable()
import ROOT

# Import the needed stuff specific to the JetCleaning
from JetSelectorTools.JetCleaningCutDefs import *

def ConfiguredARAJetCleaningTool_VeryLoose():
    """
    Configure the ARAJetCleaningTool with the default VeryLoose cuts
    """    
    jetCleanTool = ROOT.ARAJetCleaningTool()
    JetCleaningToolConfig_VeryLoose(jetCleanTool)
    return jetCleanTool



def ConfiguredARAJetCleaningTool_Loose():
    """
    Configure the ARAJetCleaningTool with the default Loose cuts
    """    
    jetCleanTool = ROOT.ARAJetCleaningTool()
    JetCleaningToolConfig_Loose(jetCleanTool)
    return jetCleanTool



def ConfiguredARAJetCleaningTool_Medium():
    """
    Configure the ARAJetCleaningTool with the default Medium cuts
    """    
    jetCleanTool = ROOT.ARAJetCleaningTool()
    JetCleaningToolConfig_Medium(jetCleanTool)
    return jetCleanTool



def ConfiguredARAJetCleaningTool_Tight():
    """
    Configure the ARAJetCleaningTool with the default Tight cuts
    """    
    jetCleanTool = ROOT.ARAJetCleaningTool()
    JetCleaningToolConfig_Tight(jetCleanTool)
    return jetCleanTool
