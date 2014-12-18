theApp.EvtMax = 1000

# Necessary and sufficient to read Athena pool files!
import AthenaPoolCnvSvc.ReadAthenaPool
from AthenaCommon.AthenaCommonFlags import athenaCommonFlags
## import os
## sourcedir = '/r02/atlas/khoo/sample_AOD/mc12_8TeV.107654.AlpgenJimmy_AUET2CTEQ6L1_ZeeNp4.merge.AOD.e1218_s1469_s1470_r3542_r3549_tid00807724_00/'
## filelist = os.listdir(sourcedir)
## for i in filelist:
##     svcMgr.EventSelector.InputCollections.append(sourcedir+i)
filelist  = [
   '/r02/atlas/khoo/sample_AOD/mc12_8TeV.107654.AlpgenJimmy_AUET2CTEQ6L1_ZeeNp4.merge.AOD.e1218_s1469_s1470_r3542_r3549_tid00807724_00/AOD.00807724._000001.pool.root.1'
   ]
athenaCommonFlags.FilesInput = filelist
svcMgr.EventSelector.InputCollections = filelist
svcMgr.EventSelector.SkipEvents = 0

from AthenaCommon.AlgSequence import AlgSequence
job = AlgSequence()

from GaudiSvc.GaudiSvcConf import THistSvc
svcMgr += THistSvc()

from MissingETUtility.MissingETUtilityConf import MissingETUtility__METUtilAlg as METUtilAlg
from MissingETUtility.MissingETUtilityConf import MissingETUtility__METUtilityAthTool as METUtilityAthTool

svcMgr.THistSvc.Output += ["outfile DATAFILE='metUtilTest.root' OPT='RECREATE'"]
svcMgr.THistSvc.PrintAll = True

# Compute the event density for jet calibration
from EventShapeRec.EventEtDensityConfig import calculateSimpleEventDensity
calculateSimpleEventDensity(Radius=0.4, SignalState="UNCALIBRATED")

# Set up the algorithm
alg = METUtilAlg( 'METUtilTest' )
alg.OutputLevel = DEBUG

# Setup for the MET Utility tool
ToolSvc = Service( 'ToolSvc' )
ToolSvc += METUtilityAthTool( 'MyMETUtil' )
ToolSvc.MyMETUtil.OutputLevel = DEBUG

# Configure the tool to distinguish simulation from data
from RecExConfig.InputFilePeeker import inputFileSummary
if inputFileSummary['evt_type'][0] == "IS_DATA":
   ToolSvc.MyMETUtil.IsData = True
elif inputFileSummary['evt_type'][0] == "IS_SIMULATION":
   ToolSvc.MyMETUtil.IsData = False

# Assign the tool to the algorithm
alg.MetUtil = ToolSvc.MyMETUtil

# Add the algorithm to the sequence
job += alg

THistSvc.Dump = True
