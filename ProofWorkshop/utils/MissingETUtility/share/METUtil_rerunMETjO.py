# Rerun MET computation
from AthenaCommon.AthenaCommonFlags import athenaCommonFlags
athenaCommonFlags.FilesInput = [
   '/r02/atlas/khoo/sample_AOD/mc12_8TeV.107654.AlpgenJimmy_AUET2CTEQ6L1_ZeeNp4.merge.AOD.e1218_s1469_s1470_r3542_r3549_tid00807724_00/AOD.00807724._000001.pool.root.1'
   ]

from RecExConfig.RecFlags import rec
rec.doCBNT.set_Value_and_Lock(False)
rec.doWriteESD.set_Value_and_Lock(False)
rec.doWriteAOD.set_Value_and_Lock(True)
rec.readAOD.set_Value_and_Lock(True)
rec.readESD.set_Value_and_Lock(False)
rec.doAOD.set_Value_and_Lock(False)
rec.doESD.set_Value_and_Lock(False)
rec.doDPD.set_Value_and_Lock(False)
rec.doWriteTAG.set_Value_and_Lock(False)

athenaCommonFlags.PoolAODOutput = "AOD.rerunMET.pool.root"

from RecExConfig.RecAlgsFlags import recAlgs
recAlgs.doMissingET.set_Value_and_Lock(True)

include("RecExCommon/RecExCommon_topOptions.py")

# Configure the tool to distinguish simulation from data
from RecExConfig.InputFilePeeker import inputFileSummary

from AthenaCommon.AlgSequence import AlgSequence
job = AlgSequence()

from GaudiSvc.GaudiSvcConf import THistSvc
svcMgr += THistSvc()

from MissingETUtility.MissingETUtilityConf import MissingETUtility__METUtilAlg as METUtilAlg
from MissingETUtility.MissingETUtilityConf import MissingETUtility__METUtilityAthTool as METUtilityAthTool

svcMgr.THistSvc.Output += ["outfile DATAFILE='metUtilTest_rerunMET.root' OPT='RECREATE'"]
svcMgr.THistSvc.PrintAll = True

from JetRec.JetRecFlags import jetFlags
jetFlags.jetPerformanceJob = True # make sure the latest configuration is on

from JetMomentTools.JetMomentsConfigHelpers import recommendedAreaAndJVFMoments
# recompute moments on AntiKt4LCTopoJets. For the meaning of the oldMomentNames argument, see below.
jetmomAlg = recommendedAreaAndJVFMoments('AntiKt4LCTopoJets',oldMomentNames=True)

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
# Customisation
# Setup below is to rebuild MET_RefFinal from objects
ToolSvc.MyMETUtil.ClusterKey = ''
ToolSvc.MyMETUtil.TrackKey = ''
ToolSvc.MyMETUtil.CellOutEflowKey = 'MET_CellOut_Eflow'

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

svcMgr.EventSelector.SkipEvents = 299
theApp.EvtMax = 2

THistSvc.Dump = True
