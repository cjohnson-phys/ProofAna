/********************************************************************
* eventbuilders/EventBuilder_jet17all_Cint.h
* CAUTION: DON'T CHANGE THIS FILE. THIS FILE IS AUTOMATICALLY GENERATED
*          FROM HEADER FILES LISTED IN G__setup_cpp_environmentXXX().
*          CHANGE THOSE HEADER FILES AND REGENERATE THIS FILE.
********************************************************************/
#ifdef __CINT__
#error eventbuilders/EventBuilder_jet17all_Cint.h/C is only for compilation. Abort cint.
#endif
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define G__ANSIHEADER
#define G__DICTIONARY
#define G__PRIVATE_GVALUE
#include "G__ci.h"
#include "FastAllocString.h"
extern "C" {
extern void G__cpp_setup_tagtableEventBuilder_jet17all_Cint();
extern void G__cpp_setup_inheritanceEventBuilder_jet17all_Cint();
extern void G__cpp_setup_typetableEventBuilder_jet17all_Cint();
extern void G__cpp_setup_memvarEventBuilder_jet17all_Cint();
extern void G__cpp_setup_globalEventBuilder_jet17all_Cint();
extern void G__cpp_setup_memfuncEventBuilder_jet17all_Cint();
extern void G__cpp_setup_funcEventBuilder_jet17all_Cint();
extern void G__set_cpp_environmentEventBuilder_jet17all_Cint();
}


#include "TObject.h"
#include "TMemberInspector.h"
#include "eventbuilders/EventBuilder_jet17all.h"
#include "core/AnaConfig.h"
#include "core/AnalysisBase.h"
#include "core/AnalysisChain.h"
#include "core/Aux.h"
#include "core/Error.h"
#include "core/EventBuilderBase.h"
#include "core/Event.h"
#include "core/Key.h"
#include "core/MomentObj.h"
#include "core/Particle.h"
#include "core/Point.h"
#include "core/ProofAna.h"
#include "core/SelectorBase.h"
#include "core/TDirCache.h"
#include "core/Timer.h"
#include <algorithm>
namespace std { }
using namespace std;

#ifndef G__MEMFUNCBODY
#endif

extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_TClass;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_TBuffer;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_TDirectory;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_TMemberInspector;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_vectorlEunsignedsPintcOallocatorlEunsignedsPintgRsPgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_iteratorlEbidirectional_iterator_tagcOTObjectmUcOlongcOconstsPTObjectmUmUcOconstsPTObjectmUaNgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_TTree;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_maplEstringcOintcOlesslEstringgRcOallocatorlEpairlEconstsPstringcOintgRsPgRsPgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_pairlEintcOintgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_maplEstringcOTObjArraymUcOlesslEstringgRcOallocatorlEpairlEconstsPstringcOTObjArraymUgRsPgRsPgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_vectorlEintcOallocatorlEintgRsPgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_reverse_iteratorlEvectorlEintcOallocatorlEintgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_setlEstringcOlesslEstringgRcOallocatorlEstringgRsPgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_vectorlEInternalKeymUcOallocatorlEInternalKeymUgRsPgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_reverse_iteratorlEvectorlEInternalKeymUcOallocatorlEInternalKeymUgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_maplEInternalKeymUcOInternalKeymUcOlesslEInternalKeymUgRcOallocatorlEpairlEInternalKeymUsPconstcOInternalKeymUgRsPgRsPgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_maplEInternalKeymUcOmaplEInternalKeymUcOInternalKeymUcOlesslEInternalKeymUgRcOallocatorlEpairlEInternalKeymUsPconstcOInternalKeymUgRsPgRsPgRcOlesslEInternalKeymUgRcOallocatorlEpairlEInternalKeymUsPconstcOmaplEInternalKeymUcOInternalKeymUcOlesslEInternalKeymUgRcOallocatorlEpairlEInternalKeymUsPconstcOInternalKeymUgRsPgRsPgRsPgRsPgRsPgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_AnalysisBase;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_EventBuilderBase;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_setlEKeylE1gRcOlesslEKeylE1gRsPgRcOallocatorlEKeylE1gRsPgRsPgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_maplEKeylE1gRcOThinContainercOlesslEKeylE1gRsPgRcOallocatorlEpairlEconstsPKeylE1gRcOThinContainergRsPgRsPgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_maplEKeylE1gRcOSizeContainercOlesslEKeylE1gRsPgRcOallocatorlEpairlEconstsPKeylE1gRcOSizeContainergRsPgRsPgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_maplEKeylE1gRcOBranchContainercOlesslEKeylE1gRsPgRcOallocatorlEpairlEconstsPKeylE1gRcOBranchContainergRsPgRsPgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_TMatrixTBaselEfloatgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_TMatrixTBaselEdoublegR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_TVectorTlEfloatgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_TVectorTlEdoublegR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_TElementActionTlEfloatgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_TElementPosActionTlEfloatgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_TMatrixTlEfloatgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_TMatrixTRow_constlEfloatgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_TMatrixTRowlEfloatgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_TMatrixTDiag_constlEfloatgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_TMatrixTColumn_constlEfloatgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_TMatrixTFlat_constlEfloatgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_TMatrixTSub_constlEfloatgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_TMatrixTSparseRow_constlEfloatgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_TMatrixTSparseDiag_constlEfloatgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_TMatrixTColumnlEfloatgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_TMatrixTDiaglEfloatgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_TMatrixTFlatlEfloatgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_TMatrixTSublEfloatgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_TMatrixTSparseRowlEfloatgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_TMatrixTSparseDiaglEfloatgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_vectorlEFeatureIndexcOallocatorlEFeatureIndexgRsPgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_reverse_iteratorlEvectorlEFeatureIndexcOallocatorlEFeatureIndexgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_maplEintcOstringcOlesslEintgRcOallocatorlEpairlEconstsPintcOstringgRsPgRsPgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_vectorlEstringcOallocatorlEstringgRsPgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_reverse_iteratorlEvectorlEstringcOallocatorlEstringgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_maplEintcOFeatureIndexcOlesslEintgRcOallocatorlEpairlEconstsPintcOFeatureIndexgRsPgRsPgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_maplEintcOvectorlEFeatureIndexcOallocatorlEFeatureIndexgRsPgRcOlesslEintgRcOallocatorlEpairlEconstsPintcOvectorlEFeatureIndexcOallocatorlEFeatureIndexgRsPgRsPgRsPgRsPgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_vectorlEMuonRoILinkscOallocatorlEMuonRoILinksgRsPgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_reverse_iteratorlEvectorlEMuonRoILinkscOallocatorlEMuonRoILinksgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_vectorlEElectronRoILinkscOallocatorlEElectronRoILinksgRsPgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_reverse_iteratorlEvectorlEElectronRoILinkscOallocatorlEElectronRoILinksgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_vectorlECombLinkscOallocatorlECombLinksgRsPgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_reverse_iteratorlEvectorlECombLinkscOallocatorlECombLinksgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_vectorlETauRoILinkscOallocatorlETauRoILinksgRsPgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_reverse_iteratorlEvectorlETauRoILinkscOallocatorlETauRoILinksgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_vectorlEJetRoILinkscOallocatorlEJetRoILinksgRsPgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_reverse_iteratorlEvectorlEJetRoILinkscOallocatorlEJetRoILinksgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_vectorlEvectorlEintcOallocatorlEintgRsPgRcOallocatorlEvectorlEintcOallocatorlEintgRsPgRsPgRsPgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_reverse_iteratorlEvectorlEvectorlEintcOallocatorlEintgRsPgRcOallocatorlEvectorlEintcOallocatorlEintgRsPgRsPgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_vectorlEChainEntrycOallocatorlEChainEntrygRsPgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_reverse_iteratorlEvectorlEChainEntrycOallocatorlEChainEntrygRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_vectorlETBranchmUcOallocatorlETBranchmUgRsPgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_reverse_iteratorlEvectorlETBranchmUcOallocatorlETBranchmUgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_maplEstringcOvectorlEshortcOallocatorlEshortgRsPgRmUcOlesslEstringgRcOallocatorlEpairlEconstsPstringcOvectorlEshortcOallocatorlEshortgRsPgRmUgRsPgRsPgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_maplEstringcOvectorlEintcOallocatorlEintgRsPgRmUcOlesslEstringgRcOallocatorlEpairlEconstsPstringcOvectorlEintcOallocatorlEintgRsPgRmUgRsPgRsPgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_maplEstringcOvectorlEvectorlEintcOallocatorlEintgRsPgRcOallocatorlEvectorlEintcOallocatorlEintgRsPgRsPgRsPgRmUcOlesslEstringgRcOallocatorlEpairlEconstsPstringcOvectorlEvectorlEintcOallocatorlEintgRsPgRcOallocatorlEvectorlEintcOallocatorlEintgRsPgRsPgRsPgRmUgRsPgRsPgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_maplEstringcOstringcOlesslEstringgRcOallocatorlEpairlEconstsPstringcOstringgRsPgRsPgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_maplEintcOCombLinkscOlesslEintgRcOallocatorlEpairlEconstsPintcOCombLinksgRsPgRsPgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_maplEstringcOmaplEintcOCombLinkscOlesslEintgRcOallocatorlEpairlEconstsPintcOCombLinksgRsPgRsPgRcOlesslEstringgRcOallocatorlEpairlEconstsPstringcOmaplEintcOCombLinkscOlesslEintgRcOallocatorlEpairlEconstsPintcOCombLinksgRsPgRsPgRsPgRsPgRsPgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_D3PD;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_pairlEintcOpairlEintcOintgRsPgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_maplEpairlEintcOpairlEintcOintgRsPgRcOintcOlesslEpairlEintcOpairlEintcOintgRsPgRsPgRcOallocatorlEpairlEconstsPpairlEintcOpairlEintcOintgRsPgRcOintgRsPgRsPgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_D3PDcLcLTrigDecisionToolD3PD;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_vectorlETStringcOallocatorlETStringgRsPgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_reverse_iteratorlEvectorlETStringcOallocatorlETStringgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_vectorlETH2DmUcOallocatorlETH2DmUgRsPgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_reverse_iteratorlEvectorlETH2DmUcOallocatorlETH2DmUgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_JetCalibrationTool;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_Root;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_RootcLcLTGoodRunsList;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_EventBuilder_jet17all;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_vectorlETObjectmUcOallocatorlETObjectmUgRsPgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_reverse_iteratorlEvectorlETObjectmUcOallocatorlETObjectmUgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_maplETObjectmUcOunsignedsPintcOlesslETObjectmUgRcOallocatorlEpairlETObjectmUsPconstcOunsignedsPintgRsPgRsPgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_maplETObjectmUcOTObjectmUcOlesslETObjectmUgRcOallocatorlEpairlETObjectmUsPconstcOTObjectmUgRsPgRsPgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_maplEKeylE0gRcOMapObjmUcOlesslEKeylE0gRsPgRcOallocatorlEpairlEconstsPKeylE0gRcOMapObjmUgRsPgRsPgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_maplETStringcOunsignedsPintcOlesslETStringgRcOallocatorlEpairlEconstsPTStringcOunsignedsPintgRsPgRsPgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_pairlEKeylE2gRcOunsignedsPintgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_vectorlEpairlEKeylE2gRcOunsignedsPintgRcOallocatorlEpairlEKeylE2gRcOunsignedsPintgRsPgRsPgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_reverse_iteratorlEvectorlEpairlEKeylE2gRcOunsignedsPintgRcOallocatorlEpairlEKeylE2gRcOunsignedsPintgRsPgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_maplEKeylE2gRcOunsignedsPintcOlesslEKeylE2gRsPgRcOallocatorlEpairlEconstsPKeylE2gRcOunsignedsPintgRsPgRsPgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_maplEKeylE2gRcOTObjectmUcOlesslEKeylE2gRsPgRcOallocatorlEpairlEconstsPKeylE2gRcOTObjectmUgRsPgRsPgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_maplEKeylE2gRcOboolcOlesslEKeylE2gRsPgRcOallocatorlEpairlEconstsPKeylE2gRcOboolgRsPgRsPgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_setlEKeylE2gRcOlesslEKeylE2gRsPgRcOallocatorlEKeylE2gRsPgRsPgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_maplETDirectorymUcOTDirCachemUcOlesslETDirectorymUgRcOallocatorlEpairlETDirectorymUsPconstcOTDirCachemUgRsPgRsPgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_vectorlEAnalysisBasemUcOallocatorlEAnalysisBasemUgRsPgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_reverse_iteratorlEvectorlEAnalysisBasemUcOallocatorlEAnalysisBasemUgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_maplETStringcOTProofcLcLMD5Mod_tcOlesslETStringgRcOallocatorlEpairlEconstsPTStringcOTProofcLcLMD5Mod_tgRsPgRsPgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_maplEKeylE2gRcOAnalysisBasemUcOlesslEKeylE2gRsPgRcOallocatorlEpairlEconstsPKeylE2gRcOAnalysisBasemUgRsPgRsPgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_maplEKeylE2gRcOOutputFilecOlesslEKeylE2gRsPgRcOallocatorlEpairlEconstsPKeylE2gRcOOutputFilegRsPgRsPgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_vectorlEKeylE2gRcOallocatorlEKeylE2gRsPgRsPgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_reverse_iteratorlEvectorlEKeylE2gRcOallocatorlEKeylE2gRsPgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__EventBuilder_jet17all_CintLN_maplEKeylE2gRcOvectorlEKeylE2gRcOallocatorlEKeylE2gRsPgRsPgRcOlesslEKeylE2gRsPgRcOallocatorlEpairlEconstsPKeylE2gRcOvectorlEKeylE2gRcOallocatorlEKeylE2gRsPgRsPgRsPgRsPgRsPgR;

/* STUB derived class for protected member access */