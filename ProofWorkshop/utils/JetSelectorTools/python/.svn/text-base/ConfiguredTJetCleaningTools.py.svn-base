##=============================================================================
## Name:        ConfiguredTJetCleaningTools
##
## Author:      Karsten Koeneke (CERN)
## Created:     July 2011
##
## Description: Apply the default configurations for the TJetCleaningTool.
##
## Usage: In your ROOT session (after loading the libraries from RootCore):
##        TPython::LoadMacro("./path/to/this/file/ConfiguredTJetCleaningTools.py");
##        Root::TJetCleaningTool* myLooseJetCleanTool = (void*)TPython::Eval("ConfiguredTJetCleaningTool_Loose()");
##        myLooseJetCleanTool->initialize();
##
##=============================================================================

# import the needed Reflex and ROOT stuff
import PyCintex
PyCintex.Cintex.Enable()
import ROOT

# Import the needed stuff specific to the JetCleaning
from JetSelectorTools.JetCleaningCutDefs import *

def ConfiguredTJetCleaningTool_VeryLoose():
    """
    Configure the TJetCleaningTool with the default VeryLoose cuts
    """    
    jetCleanTool = ROOT.Root.TJetCleaningTool()
    JetCleaningToolConfig_VeryLoose(jetCleanTool)
    return jetCleanTool



def ConfiguredTJetCleaningTool_Loose():
    """
    Configure the TJetCleaningTool with the default Loose cuts
    """    
    jetCleanTool = ROOT.Root.TJetCleaningTool()
    JetCleaningToolConfig_Loose(jetCleanTool)
    return jetCleanTool



def ConfiguredTJetCleaningTool_Medium():
    """
    Configure the TJetCleaningTool with the default Medium cuts
    """    
    jetCleanTool = ROOT.Root.TJetCleaningTool()
    JetCleaningToolConfig_Medium(jetCleanTool)
    return jetCleanTool



def ConfiguredTJetCleaningTool_Tight():
    """
    Configure the TJetCleaningTool with the default Tight cuts
    """    
    jetCleanTool = ROOT.Root.TJetCleaningTool()
    JetCleaningToolConfig_Tight(jetCleanTool)
    return jetCleanTool
