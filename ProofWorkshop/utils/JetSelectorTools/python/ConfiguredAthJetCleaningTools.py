##=============================================================================
## Name:        ConfiguredAthJetCleaningTools
##
## Author:      Karsten Koeneke (CERN)
## Created:     July 2011
##
## Description: Apply the default configurations for the AthJetCleaningTools,
##              but allow for overwriting them with user-defined values.
##
##=============================================================================

# Import the needed general stuff
from ObjectSelectorCore.HelperUtils import *
from AthenaCommon import CfgMgr

# Import the needed stuff specific to the JetCleaning
from JetSelectorTools.JetSelectorToolsConf import AthJetCleaningTool
from JetSelectorTools.JetCleaningCutDefs import *



def ConfiguredAthJetCleaningTool_VeryLoose( name, **kw ):
    """
    Configure the AthJetCleaningTool with the default VeryLoose cuts
    and allow for (re-)setting of all provided cuts.
    """    
    # Create and instance of the tool
    tool = CfgMgr.AthJetCleaningTool(name, **kw)

    # Configure it with the standard configuration
    JetCleaningToolConfig_VeryLoose( tool )

    # Get all provided properties and overwrite the default values with them
    SetToolProperties( tool, **kw )
    
    return tool




def ConfiguredAthJetCleaningTool_Loose( name, **kw ):
    """
    Configure the AthJetCleaningTool with the default Loose cuts
    and allow for (re-)setting of all provided cuts.
    """    
    # Create and instance of the tool
    tool = CfgMgr.AthJetCleaningTool(name, **kw)

    # Configure it with the standard configuration
    JetCleaningToolConfig_Loose( tool )

    # Get all provided properties and overwrite the default values with them
    SetToolProperties( tool, **kw )
    
    return tool




def ConfiguredAthJetCleaningTool_Medium( name, **kw ):
    """
    Configure the AthJetCleaningTool with the default Medium cuts
    and allow for (re-)setting of all provided cuts.
    """    
    # Create and instance of the tool
    tool = CfgMgr.AthJetCleaningTool(name, **kw)

    # Configure it with the standard configuration
    JetCleaningToolConfig_Medium( tool )

    # Get all provided properties and overwrite the default values with them
    SetToolProperties( tool, **kw )
    
    return tool




def ConfiguredAthJetCleaningTool_Tight( name, **kw ):
    """
    Configure the AthJetCleaningTool with the default Tight cuts
    and allow for (re-)setting of all provided cuts.
    """    
    # Create and instance of the tool
    tool = CfgMgr.AthJetCleaningTool(name, **kw)

    # Configure it with the standard configuration
    JetCleaningToolConfig_Tight( tool )

    # Get all provided properties and overwrite the default values with them
    SetToolProperties( tool, **kw )
    
    return tool

