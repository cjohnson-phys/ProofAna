#ifndef ROOTCORE_PACKAGES_H
#define ROOTCORE_PACKAGES_H

// This file contains one define statement for each package detected by
// RootCore.  It is meant to allow to write package A in a form that
// it uses the services of package B when available, but otherwise
// skips it without failing.  For this to work properly you need to list
// package B in the PACKAGE_TRYDEP of package A.

#define ROOTCORE_PACKAGE_RootCore
#define ROOTCORE_PACKAGE_ApplyJetCalibration
#define ROOTCORE_PACKAGE_JetResolution
#define ROOTCORE_PACKAGE_ApplyJetResolutionSmearing
#define ROOTCORE_PACKAGE_CalibrationDataInterface
#define ROOTCORE_PACKAGE_egammaAnalysisUtils
#define ROOTCORE_PACKAGE_GoodRunsLists
#define ROOTCORE_PACKAGE_ObjectSelectorCore
#define ROOTCORE_PACKAGE_JetSelectorTools
#define ROOTCORE_PACKAGE_JetUncertainties
#define ROOTCORE_PACKAGE_MuonMomentumCorrections
#define ROOTCORE_PACKAGE_MissingETUtility
#define ROOTCORE_PACKAGE_PATCore
#define ROOTCORE_PACKAGE_PileupReweighting
#define ROOTCORE_PACKAGE_ReweightUtils
#define ROOTCORE_PACKAGE_TileTripReader
#define ROOTCORE_PACKAGE_TrigRootAnalysis

#endif
