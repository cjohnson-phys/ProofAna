// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dOdOdIsrcdITriggerMenuNtupleDict

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "ChainEntry.h"
#include "CombLinks.h"
#include "RoILinks.h"
#include "FeatureIndex.h"
#include "ElectronRoILinks.h"
#include "JetRoILinks.h"
#include "MuonRoILinks.h"
#include "TauRoILinks.h"
#include "TMNUtil.h"
#include "TrigDecSummary.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static TClass *ChainEntry_Dictionary();
   static void ChainEntry_TClassManip(TClass*);
   static void *new_ChainEntry(void *p = 0);
   static void *newArray_ChainEntry(Long_t size, void *p);
   static void delete_ChainEntry(void *p);
   static void deleteArray_ChainEntry(void *p);
   static void destruct_ChainEntry(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::ChainEntry*)
   {
      ::ChainEntry *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::ChainEntry),0);
      static ::ROOT::TGenericClassInfo 
         instance("ChainEntry", "ChainEntry.h", 11,
                  typeid(::ChainEntry), DefineBehavior(ptr, ptr),
                  &ChainEntry_Dictionary, isa_proxy, 4,
                  sizeof(::ChainEntry) );
      instance.SetNew(&new_ChainEntry);
      instance.SetNewArray(&newArray_ChainEntry);
      instance.SetDelete(&delete_ChainEntry);
      instance.SetDeleteArray(&deleteArray_ChainEntry);
      instance.SetDestructor(&destruct_ChainEntry);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::ChainEntry*)
   {
      return GenerateInitInstanceLocal((::ChainEntry*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::ChainEntry*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ChainEntry_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::ChainEntry*)0x0)->GetClass();
      ChainEntry_TClassManip(theClass);
   return theClass;
   }

   static void ChainEntry_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *CombLinks_Dictionary();
   static void CombLinks_TClassManip(TClass*);
   static void *new_CombLinks(void *p = 0);
   static void *newArray_CombLinks(Long_t size, void *p);
   static void delete_CombLinks(void *p);
   static void deleteArray_CombLinks(void *p);
   static void destruct_CombLinks(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CombLinks*)
   {
      ::CombLinks *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::CombLinks),0);
      static ::ROOT::TGenericClassInfo 
         instance("CombLinks", "CombLinks.h", 11,
                  typeid(::CombLinks), DefineBehavior(ptr, ptr),
                  &CombLinks_Dictionary, isa_proxy, 4,
                  sizeof(::CombLinks) );
      instance.SetNew(&new_CombLinks);
      instance.SetNewArray(&newArray_CombLinks);
      instance.SetDelete(&delete_CombLinks);
      instance.SetDeleteArray(&deleteArray_CombLinks);
      instance.SetDestructor(&destruct_CombLinks);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CombLinks*)
   {
      return GenerateInitInstanceLocal((::CombLinks*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::CombLinks*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *CombLinks_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::CombLinks*)0x0)->GetClass();
      CombLinks_TClassManip(theClass);
   return theClass;
   }

   static void CombLinks_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RoILinks_Dictionary();
   static void RoILinks_TClassManip(TClass*);
   static void *new_RoILinks(void *p = 0);
   static void *newArray_RoILinks(Long_t size, void *p);
   static void delete_RoILinks(void *p);
   static void deleteArray_RoILinks(void *p);
   static void destruct_RoILinks(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RoILinks*)
   {
      ::RoILinks *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RoILinks),0);
      static ::ROOT::TGenericClassInfo 
         instance("RoILinks", "RoILinks.h", 15,
                  typeid(::RoILinks), DefineBehavior(ptr, ptr),
                  &RoILinks_Dictionary, isa_proxy, 4,
                  sizeof(::RoILinks) );
      instance.SetNew(&new_RoILinks);
      instance.SetNewArray(&newArray_RoILinks);
      instance.SetDelete(&delete_RoILinks);
      instance.SetDeleteArray(&deleteArray_RoILinks);
      instance.SetDestructor(&destruct_RoILinks);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RoILinks*)
   {
      return GenerateInitInstanceLocal((::RoILinks*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::RoILinks*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RoILinks_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RoILinks*)0x0)->GetClass();
      RoILinks_TClassManip(theClass);
   return theClass;
   }

   static void RoILinks_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *FeatureIndex_Dictionary();
   static void FeatureIndex_TClassManip(TClass*);
   static void *new_FeatureIndex(void *p = 0);
   static void *newArray_FeatureIndex(Long_t size, void *p);
   static void delete_FeatureIndex(void *p);
   static void deleteArray_FeatureIndex(void *p);
   static void destruct_FeatureIndex(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::FeatureIndex*)
   {
      ::FeatureIndex *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::FeatureIndex),0);
      static ::ROOT::TGenericClassInfo 
         instance("FeatureIndex", "FeatureIndex.h", 10,
                  typeid(::FeatureIndex), DefineBehavior(ptr, ptr),
                  &FeatureIndex_Dictionary, isa_proxy, 4,
                  sizeof(::FeatureIndex) );
      instance.SetNew(&new_FeatureIndex);
      instance.SetNewArray(&newArray_FeatureIndex);
      instance.SetDelete(&delete_FeatureIndex);
      instance.SetDeleteArray(&deleteArray_FeatureIndex);
      instance.SetDestructor(&destruct_FeatureIndex);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::FeatureIndex*)
   {
      return GenerateInitInstanceLocal((::FeatureIndex*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::FeatureIndex*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *FeatureIndex_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::FeatureIndex*)0x0)->GetClass();
      FeatureIndex_TClassManip(theClass);
   return theClass;
   }

   static void FeatureIndex_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *TMNUtil_Dictionary();
   static void TMNUtil_TClassManip(TClass*);
   static void *new_TMNUtil(void *p = 0);
   static void *newArray_TMNUtil(Long_t size, void *p);
   static void delete_TMNUtil(void *p);
   static void deleteArray_TMNUtil(void *p);
   static void destruct_TMNUtil(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TMNUtil*)
   {
      ::TMNUtil *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::TMNUtil),0);
      static ::ROOT::TGenericClassInfo 
         instance("TMNUtil", "TMNUtil.h", 26,
                  typeid(::TMNUtil), DefineBehavior(ptr, ptr),
                  &TMNUtil_Dictionary, isa_proxy, 4,
                  sizeof(::TMNUtil) );
      instance.SetNew(&new_TMNUtil);
      instance.SetNewArray(&newArray_TMNUtil);
      instance.SetDelete(&delete_TMNUtil);
      instance.SetDeleteArray(&deleteArray_TMNUtil);
      instance.SetDestructor(&destruct_TMNUtil);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TMNUtil*)
   {
      return GenerateInitInstanceLocal((::TMNUtil*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::TMNUtil*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TMNUtil_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::TMNUtil*)0x0)->GetClass();
      TMNUtil_TClassManip(theClass);
   return theClass;
   }

   static void TMNUtil_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *TrigDecSummary_Dictionary();
   static void TrigDecSummary_TClassManip(TClass*);
   static void *new_TrigDecSummary(void *p = 0);
   static void *newArray_TrigDecSummary(Long_t size, void *p);
   static void delete_TrigDecSummary(void *p);
   static void deleteArray_TrigDecSummary(void *p);
   static void destruct_TrigDecSummary(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TrigDecSummary*)
   {
      ::TrigDecSummary *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::TrigDecSummary),0);
      static ::ROOT::TGenericClassInfo 
         instance("TrigDecSummary", "TrigDecSummary.h", 8,
                  typeid(::TrigDecSummary), DefineBehavior(ptr, ptr),
                  &TrigDecSummary_Dictionary, isa_proxy, 4,
                  sizeof(::TrigDecSummary) );
      instance.SetNew(&new_TrigDecSummary);
      instance.SetNewArray(&newArray_TrigDecSummary);
      instance.SetDelete(&delete_TrigDecSummary);
      instance.SetDeleteArray(&deleteArray_TrigDecSummary);
      instance.SetDestructor(&destruct_TrigDecSummary);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TrigDecSummary*)
   {
      return GenerateInitInstanceLocal((::TrigDecSummary*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::TrigDecSummary*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TrigDecSummary_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::TrigDecSummary*)0x0)->GetClass();
      TrigDecSummary_TClassManip(theClass);
   return theClass;
   }

   static void TrigDecSummary_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_ChainEntry(void *p) {
      return  p ? new(p) ::ChainEntry : new ::ChainEntry;
   }
   static void *newArray_ChainEntry(Long_t nElements, void *p) {
      return p ? new(p) ::ChainEntry[nElements] : new ::ChainEntry[nElements];
   }
   // Wrapper around operator delete
   static void delete_ChainEntry(void *p) {
      delete ((::ChainEntry*)p);
   }
   static void deleteArray_ChainEntry(void *p) {
      delete [] ((::ChainEntry*)p);
   }
   static void destruct_ChainEntry(void *p) {
      typedef ::ChainEntry current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::ChainEntry

namespace ROOT {
   // Wrappers around operator new
   static void *new_CombLinks(void *p) {
      return  p ? new(p) ::CombLinks : new ::CombLinks;
   }
   static void *newArray_CombLinks(Long_t nElements, void *p) {
      return p ? new(p) ::CombLinks[nElements] : new ::CombLinks[nElements];
   }
   // Wrapper around operator delete
   static void delete_CombLinks(void *p) {
      delete ((::CombLinks*)p);
   }
   static void deleteArray_CombLinks(void *p) {
      delete [] ((::CombLinks*)p);
   }
   static void destruct_CombLinks(void *p) {
      typedef ::CombLinks current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::CombLinks

namespace ROOT {
   // Wrappers around operator new
   static void *new_RoILinks(void *p) {
      return  p ? new(p) ::RoILinks : new ::RoILinks;
   }
   static void *newArray_RoILinks(Long_t nElements, void *p) {
      return p ? new(p) ::RoILinks[nElements] : new ::RoILinks[nElements];
   }
   // Wrapper around operator delete
   static void delete_RoILinks(void *p) {
      delete ((::RoILinks*)p);
   }
   static void deleteArray_RoILinks(void *p) {
      delete [] ((::RoILinks*)p);
   }
   static void destruct_RoILinks(void *p) {
      typedef ::RoILinks current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RoILinks

namespace ROOT {
   // Wrappers around operator new
   static void *new_FeatureIndex(void *p) {
      return  p ? new(p) ::FeatureIndex : new ::FeatureIndex;
   }
   static void *newArray_FeatureIndex(Long_t nElements, void *p) {
      return p ? new(p) ::FeatureIndex[nElements] : new ::FeatureIndex[nElements];
   }
   // Wrapper around operator delete
   static void delete_FeatureIndex(void *p) {
      delete ((::FeatureIndex*)p);
   }
   static void deleteArray_FeatureIndex(void *p) {
      delete [] ((::FeatureIndex*)p);
   }
   static void destruct_FeatureIndex(void *p) {
      typedef ::FeatureIndex current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::FeatureIndex

namespace ROOT {
   // Wrappers around operator new
   static void *new_TMNUtil(void *p) {
      return  p ? new(p) ::TMNUtil : new ::TMNUtil;
   }
   static void *newArray_TMNUtil(Long_t nElements, void *p) {
      return p ? new(p) ::TMNUtil[nElements] : new ::TMNUtil[nElements];
   }
   // Wrapper around operator delete
   static void delete_TMNUtil(void *p) {
      delete ((::TMNUtil*)p);
   }
   static void deleteArray_TMNUtil(void *p) {
      delete [] ((::TMNUtil*)p);
   }
   static void destruct_TMNUtil(void *p) {
      typedef ::TMNUtil current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TMNUtil

namespace ROOT {
   // Wrappers around operator new
   static void *new_TrigDecSummary(void *p) {
      return  p ? new(p) ::TrigDecSummary : new ::TrigDecSummary;
   }
   static void *newArray_TrigDecSummary(Long_t nElements, void *p) {
      return p ? new(p) ::TrigDecSummary[nElements] : new ::TrigDecSummary[nElements];
   }
   // Wrapper around operator delete
   static void delete_TrigDecSummary(void *p) {
      delete ((::TrigDecSummary*)p);
   }
   static void deleteArray_TrigDecSummary(void *p) {
      delete [] ((::TrigDecSummary*)p);
   }
   static void destruct_TrigDecSummary(void *p) {
      typedef ::TrigDecSummary current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TrigDecSummary

namespace ROOT {
   static TClass *vectorlEunsignedsPintgR_Dictionary();
   static void vectorlEunsignedsPintgR_TClassManip(TClass*);
   static void *new_vectorlEunsignedsPintgR(void *p = 0);
   static void *newArray_vectorlEunsignedsPintgR(Long_t size, void *p);
   static void delete_vectorlEunsignedsPintgR(void *p);
   static void deleteArray_vectorlEunsignedsPintgR(void *p);
   static void destruct_vectorlEunsignedsPintgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<unsigned int>*)
   {
      vector<unsigned int> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<unsigned int>),0);
      static ::ROOT::TGenericClassInfo 
         instance("vector<unsigned int>", -2, "vector", 481,
                  typeid(vector<unsigned int>), DefineBehavior(ptr, ptr),
                  &vectorlEunsignedsPintgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<unsigned int>) );
      instance.SetNew(&new_vectorlEunsignedsPintgR);
      instance.SetNewArray(&newArray_vectorlEunsignedsPintgR);
      instance.SetDelete(&delete_vectorlEunsignedsPintgR);
      instance.SetDeleteArray(&deleteArray_vectorlEunsignedsPintgR);
      instance.SetDestructor(&destruct_vectorlEunsignedsPintgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<unsigned int> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<unsigned int>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEunsignedsPintgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<unsigned int>*)0x0)->GetClass();
      vectorlEunsignedsPintgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEunsignedsPintgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEunsignedsPintgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<unsigned int> : new vector<unsigned int>;
   }
   static void *newArray_vectorlEunsignedsPintgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<unsigned int>[nElements] : new vector<unsigned int>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEunsignedsPintgR(void *p) {
      delete ((vector<unsigned int>*)p);
   }
   static void deleteArray_vectorlEunsignedsPintgR(void *p) {
      delete [] ((vector<unsigned int>*)p);
   }
   static void destruct_vectorlEunsignedsPintgR(void *p) {
      typedef vector<unsigned int> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<unsigned int>

namespace ROOT {
   static TClass *vectorlEintgR_Dictionary();
   static void vectorlEintgR_TClassManip(TClass*);
   static void *new_vectorlEintgR(void *p = 0);
   static void *newArray_vectorlEintgR(Long_t size, void *p);
   static void delete_vectorlEintgR(void *p);
   static void deleteArray_vectorlEintgR(void *p);
   static void destruct_vectorlEintgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<int>*)
   {
      vector<int> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<int>),0);
      static ::ROOT::TGenericClassInfo 
         instance("vector<int>", -2, "vector", 481,
                  typeid(vector<int>), DefineBehavior(ptr, ptr),
                  &vectorlEintgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<int>) );
      instance.SetNew(&new_vectorlEintgR);
      instance.SetNewArray(&newArray_vectorlEintgR);
      instance.SetDelete(&delete_vectorlEintgR);
      instance.SetDeleteArray(&deleteArray_vectorlEintgR);
      instance.SetDestructor(&destruct_vectorlEintgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<int> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<int>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEintgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<int>*)0x0)->GetClass();
      vectorlEintgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEintgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEintgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<int> : new vector<int>;
   }
   static void *newArray_vectorlEintgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<int>[nElements] : new vector<int>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEintgR(void *p) {
      delete ((vector<int>*)p);
   }
   static void deleteArray_vectorlEintgR(void *p) {
      delete [] ((vector<int>*)p);
   }
   static void destruct_vectorlEintgR(void *p) {
      typedef vector<int> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<int>

namespace ROOT {
   static TClass *vectorlETauRoILinksgR_Dictionary();
   static void vectorlETauRoILinksgR_TClassManip(TClass*);
   static void *new_vectorlETauRoILinksgR(void *p = 0);
   static void *newArray_vectorlETauRoILinksgR(Long_t size, void *p);
   static void delete_vectorlETauRoILinksgR(void *p);
   static void deleteArray_vectorlETauRoILinksgR(void *p);
   static void destruct_vectorlETauRoILinksgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<TauRoILinks>*)
   {
      vector<TauRoILinks> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<TauRoILinks>),0);
      static ::ROOT::TGenericClassInfo 
         instance("vector<TauRoILinks>", -2, "vector", 481,
                  typeid(vector<TauRoILinks>), DefineBehavior(ptr, ptr),
                  &vectorlETauRoILinksgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<TauRoILinks>) );
      instance.SetNew(&new_vectorlETauRoILinksgR);
      instance.SetNewArray(&newArray_vectorlETauRoILinksgR);
      instance.SetDelete(&delete_vectorlETauRoILinksgR);
      instance.SetDeleteArray(&deleteArray_vectorlETauRoILinksgR);
      instance.SetDestructor(&destruct_vectorlETauRoILinksgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<TauRoILinks> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<TauRoILinks>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlETauRoILinksgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<TauRoILinks>*)0x0)->GetClass();
      vectorlETauRoILinksgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlETauRoILinksgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlETauRoILinksgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<TauRoILinks> : new vector<TauRoILinks>;
   }
   static void *newArray_vectorlETauRoILinksgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<TauRoILinks>[nElements] : new vector<TauRoILinks>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlETauRoILinksgR(void *p) {
      delete ((vector<TauRoILinks>*)p);
   }
   static void deleteArray_vectorlETauRoILinksgR(void *p) {
      delete [] ((vector<TauRoILinks>*)p);
   }
   static void destruct_vectorlETauRoILinksgR(void *p) {
      typedef vector<TauRoILinks> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<TauRoILinks>

namespace ROOT {
   static TClass *vectorlETBranchmUgR_Dictionary();
   static void vectorlETBranchmUgR_TClassManip(TClass*);
   static void *new_vectorlETBranchmUgR(void *p = 0);
   static void *newArray_vectorlETBranchmUgR(Long_t size, void *p);
   static void delete_vectorlETBranchmUgR(void *p);
   static void deleteArray_vectorlETBranchmUgR(void *p);
   static void destruct_vectorlETBranchmUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<TBranch*>*)
   {
      vector<TBranch*> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<TBranch*>),0);
      static ::ROOT::TGenericClassInfo 
         instance("vector<TBranch*>", -2, "vector", 481,
                  typeid(vector<TBranch*>), DefineBehavior(ptr, ptr),
                  &vectorlETBranchmUgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<TBranch*>) );
      instance.SetNew(&new_vectorlETBranchmUgR);
      instance.SetNewArray(&newArray_vectorlETBranchmUgR);
      instance.SetDelete(&delete_vectorlETBranchmUgR);
      instance.SetDeleteArray(&deleteArray_vectorlETBranchmUgR);
      instance.SetDestructor(&destruct_vectorlETBranchmUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<TBranch*> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<TBranch*>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlETBranchmUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<TBranch*>*)0x0)->GetClass();
      vectorlETBranchmUgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlETBranchmUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlETBranchmUgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<TBranch*> : new vector<TBranch*>;
   }
   static void *newArray_vectorlETBranchmUgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<TBranch*>[nElements] : new vector<TBranch*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlETBranchmUgR(void *p) {
      delete ((vector<TBranch*>*)p);
   }
   static void deleteArray_vectorlETBranchmUgR(void *p) {
      delete [] ((vector<TBranch*>*)p);
   }
   static void destruct_vectorlETBranchmUgR(void *p) {
      typedef vector<TBranch*> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<TBranch*>

namespace ROOT {
   static TClass *vectorlEMuonRoILinksgR_Dictionary();
   static void vectorlEMuonRoILinksgR_TClassManip(TClass*);
   static void *new_vectorlEMuonRoILinksgR(void *p = 0);
   static void *newArray_vectorlEMuonRoILinksgR(Long_t size, void *p);
   static void delete_vectorlEMuonRoILinksgR(void *p);
   static void deleteArray_vectorlEMuonRoILinksgR(void *p);
   static void destruct_vectorlEMuonRoILinksgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<MuonRoILinks>*)
   {
      vector<MuonRoILinks> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<MuonRoILinks>),0);
      static ::ROOT::TGenericClassInfo 
         instance("vector<MuonRoILinks>", -2, "vector", 481,
                  typeid(vector<MuonRoILinks>), DefineBehavior(ptr, ptr),
                  &vectorlEMuonRoILinksgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<MuonRoILinks>) );
      instance.SetNew(&new_vectorlEMuonRoILinksgR);
      instance.SetNewArray(&newArray_vectorlEMuonRoILinksgR);
      instance.SetDelete(&delete_vectorlEMuonRoILinksgR);
      instance.SetDeleteArray(&deleteArray_vectorlEMuonRoILinksgR);
      instance.SetDestructor(&destruct_vectorlEMuonRoILinksgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<MuonRoILinks> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<MuonRoILinks>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEMuonRoILinksgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<MuonRoILinks>*)0x0)->GetClass();
      vectorlEMuonRoILinksgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEMuonRoILinksgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEMuonRoILinksgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MuonRoILinks> : new vector<MuonRoILinks>;
   }
   static void *newArray_vectorlEMuonRoILinksgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MuonRoILinks>[nElements] : new vector<MuonRoILinks>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEMuonRoILinksgR(void *p) {
      delete ((vector<MuonRoILinks>*)p);
   }
   static void deleteArray_vectorlEMuonRoILinksgR(void *p) {
      delete [] ((vector<MuonRoILinks>*)p);
   }
   static void destruct_vectorlEMuonRoILinksgR(void *p) {
      typedef vector<MuonRoILinks> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<MuonRoILinks>

namespace ROOT {
   static TClass *vectorlEJetRoILinksgR_Dictionary();
   static void vectorlEJetRoILinksgR_TClassManip(TClass*);
   static void *new_vectorlEJetRoILinksgR(void *p = 0);
   static void *newArray_vectorlEJetRoILinksgR(Long_t size, void *p);
   static void delete_vectorlEJetRoILinksgR(void *p);
   static void deleteArray_vectorlEJetRoILinksgR(void *p);
   static void destruct_vectorlEJetRoILinksgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<JetRoILinks>*)
   {
      vector<JetRoILinks> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<JetRoILinks>),0);
      static ::ROOT::TGenericClassInfo 
         instance("vector<JetRoILinks>", -2, "vector", 481,
                  typeid(vector<JetRoILinks>), DefineBehavior(ptr, ptr),
                  &vectorlEJetRoILinksgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<JetRoILinks>) );
      instance.SetNew(&new_vectorlEJetRoILinksgR);
      instance.SetNewArray(&newArray_vectorlEJetRoILinksgR);
      instance.SetDelete(&delete_vectorlEJetRoILinksgR);
      instance.SetDeleteArray(&deleteArray_vectorlEJetRoILinksgR);
      instance.SetDestructor(&destruct_vectorlEJetRoILinksgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<JetRoILinks> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<JetRoILinks>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEJetRoILinksgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<JetRoILinks>*)0x0)->GetClass();
      vectorlEJetRoILinksgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEJetRoILinksgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEJetRoILinksgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<JetRoILinks> : new vector<JetRoILinks>;
   }
   static void *newArray_vectorlEJetRoILinksgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<JetRoILinks>[nElements] : new vector<JetRoILinks>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEJetRoILinksgR(void *p) {
      delete ((vector<JetRoILinks>*)p);
   }
   static void deleteArray_vectorlEJetRoILinksgR(void *p) {
      delete [] ((vector<JetRoILinks>*)p);
   }
   static void destruct_vectorlEJetRoILinksgR(void *p) {
      typedef vector<JetRoILinks> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<JetRoILinks>

namespace ROOT {
   static TClass *vectorlEFeatureIndexgR_Dictionary();
   static void vectorlEFeatureIndexgR_TClassManip(TClass*);
   static void *new_vectorlEFeatureIndexgR(void *p = 0);
   static void *newArray_vectorlEFeatureIndexgR(Long_t size, void *p);
   static void delete_vectorlEFeatureIndexgR(void *p);
   static void deleteArray_vectorlEFeatureIndexgR(void *p);
   static void destruct_vectorlEFeatureIndexgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<FeatureIndex>*)
   {
      vector<FeatureIndex> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<FeatureIndex>),0);
      static ::ROOT::TGenericClassInfo 
         instance("vector<FeatureIndex>", -2, "vector", 481,
                  typeid(vector<FeatureIndex>), DefineBehavior(ptr, ptr),
                  &vectorlEFeatureIndexgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<FeatureIndex>) );
      instance.SetNew(&new_vectorlEFeatureIndexgR);
      instance.SetNewArray(&newArray_vectorlEFeatureIndexgR);
      instance.SetDelete(&delete_vectorlEFeatureIndexgR);
      instance.SetDeleteArray(&deleteArray_vectorlEFeatureIndexgR);
      instance.SetDestructor(&destruct_vectorlEFeatureIndexgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<FeatureIndex> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<FeatureIndex>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEFeatureIndexgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<FeatureIndex>*)0x0)->GetClass();
      vectorlEFeatureIndexgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEFeatureIndexgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEFeatureIndexgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<FeatureIndex> : new vector<FeatureIndex>;
   }
   static void *newArray_vectorlEFeatureIndexgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<FeatureIndex>[nElements] : new vector<FeatureIndex>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEFeatureIndexgR(void *p) {
      delete ((vector<FeatureIndex>*)p);
   }
   static void deleteArray_vectorlEFeatureIndexgR(void *p) {
      delete [] ((vector<FeatureIndex>*)p);
   }
   static void destruct_vectorlEFeatureIndexgR(void *p) {
      typedef vector<FeatureIndex> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<FeatureIndex>

namespace ROOT {
   static TClass *vectorlEElectronRoILinksgR_Dictionary();
   static void vectorlEElectronRoILinksgR_TClassManip(TClass*);
   static void *new_vectorlEElectronRoILinksgR(void *p = 0);
   static void *newArray_vectorlEElectronRoILinksgR(Long_t size, void *p);
   static void delete_vectorlEElectronRoILinksgR(void *p);
   static void deleteArray_vectorlEElectronRoILinksgR(void *p);
   static void destruct_vectorlEElectronRoILinksgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<ElectronRoILinks>*)
   {
      vector<ElectronRoILinks> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<ElectronRoILinks>),0);
      static ::ROOT::TGenericClassInfo 
         instance("vector<ElectronRoILinks>", -2, "vector", 481,
                  typeid(vector<ElectronRoILinks>), DefineBehavior(ptr, ptr),
                  &vectorlEElectronRoILinksgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<ElectronRoILinks>) );
      instance.SetNew(&new_vectorlEElectronRoILinksgR);
      instance.SetNewArray(&newArray_vectorlEElectronRoILinksgR);
      instance.SetDelete(&delete_vectorlEElectronRoILinksgR);
      instance.SetDeleteArray(&deleteArray_vectorlEElectronRoILinksgR);
      instance.SetDestructor(&destruct_vectorlEElectronRoILinksgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<ElectronRoILinks> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<ElectronRoILinks>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEElectronRoILinksgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<ElectronRoILinks>*)0x0)->GetClass();
      vectorlEElectronRoILinksgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEElectronRoILinksgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEElectronRoILinksgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<ElectronRoILinks> : new vector<ElectronRoILinks>;
   }
   static void *newArray_vectorlEElectronRoILinksgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<ElectronRoILinks>[nElements] : new vector<ElectronRoILinks>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEElectronRoILinksgR(void *p) {
      delete ((vector<ElectronRoILinks>*)p);
   }
   static void deleteArray_vectorlEElectronRoILinksgR(void *p) {
      delete [] ((vector<ElectronRoILinks>*)p);
   }
   static void destruct_vectorlEElectronRoILinksgR(void *p) {
      typedef vector<ElectronRoILinks> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<ElectronRoILinks>

namespace ROOT {
   static TClass *vectorlECombLinksgR_Dictionary();
   static void vectorlECombLinksgR_TClassManip(TClass*);
   static void *new_vectorlECombLinksgR(void *p = 0);
   static void *newArray_vectorlECombLinksgR(Long_t size, void *p);
   static void delete_vectorlECombLinksgR(void *p);
   static void deleteArray_vectorlECombLinksgR(void *p);
   static void destruct_vectorlECombLinksgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<CombLinks>*)
   {
      vector<CombLinks> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<CombLinks>),0);
      static ::ROOT::TGenericClassInfo 
         instance("vector<CombLinks>", -2, "vector", 481,
                  typeid(vector<CombLinks>), DefineBehavior(ptr, ptr),
                  &vectorlECombLinksgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<CombLinks>) );
      instance.SetNew(&new_vectorlECombLinksgR);
      instance.SetNewArray(&newArray_vectorlECombLinksgR);
      instance.SetDelete(&delete_vectorlECombLinksgR);
      instance.SetDeleteArray(&deleteArray_vectorlECombLinksgR);
      instance.SetDestructor(&destruct_vectorlECombLinksgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<CombLinks> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<CombLinks>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlECombLinksgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<CombLinks>*)0x0)->GetClass();
      vectorlECombLinksgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlECombLinksgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlECombLinksgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<CombLinks> : new vector<CombLinks>;
   }
   static void *newArray_vectorlECombLinksgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<CombLinks>[nElements] : new vector<CombLinks>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlECombLinksgR(void *p) {
      delete ((vector<CombLinks>*)p);
   }
   static void deleteArray_vectorlECombLinksgR(void *p) {
      delete [] ((vector<CombLinks>*)p);
   }
   static void destruct_vectorlECombLinksgR(void *p) {
      typedef vector<CombLinks> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<CombLinks>

namespace ROOT {
   static TClass *vectorlEChainEntrygR_Dictionary();
   static void vectorlEChainEntrygR_TClassManip(TClass*);
   static void *new_vectorlEChainEntrygR(void *p = 0);
   static void *newArray_vectorlEChainEntrygR(Long_t size, void *p);
   static void delete_vectorlEChainEntrygR(void *p);
   static void deleteArray_vectorlEChainEntrygR(void *p);
   static void destruct_vectorlEChainEntrygR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<ChainEntry>*)
   {
      vector<ChainEntry> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<ChainEntry>),0);
      static ::ROOT::TGenericClassInfo 
         instance("vector<ChainEntry>", -2, "vector", 481,
                  typeid(vector<ChainEntry>), DefineBehavior(ptr, ptr),
                  &vectorlEChainEntrygR_Dictionary, isa_proxy, 0,
                  sizeof(vector<ChainEntry>) );
      instance.SetNew(&new_vectorlEChainEntrygR);
      instance.SetNewArray(&newArray_vectorlEChainEntrygR);
      instance.SetDelete(&delete_vectorlEChainEntrygR);
      instance.SetDeleteArray(&deleteArray_vectorlEChainEntrygR);
      instance.SetDestructor(&destruct_vectorlEChainEntrygR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<ChainEntry> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<ChainEntry>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEChainEntrygR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<ChainEntry>*)0x0)->GetClass();
      vectorlEChainEntrygR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEChainEntrygR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEChainEntrygR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<ChainEntry> : new vector<ChainEntry>;
   }
   static void *newArray_vectorlEChainEntrygR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<ChainEntry>[nElements] : new vector<ChainEntry>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEChainEntrygR(void *p) {
      delete ((vector<ChainEntry>*)p);
   }
   static void deleteArray_vectorlEChainEntrygR(void *p) {
      delete [] ((vector<ChainEntry>*)p);
   }
   static void destruct_vectorlEChainEntrygR(void *p) {
      typedef vector<ChainEntry> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<ChainEntry>

namespace ROOT {
   static TClass *setlEstringgR_Dictionary();
   static void setlEstringgR_TClassManip(TClass*);
   static void *new_setlEstringgR(void *p = 0);
   static void *newArray_setlEstringgR(Long_t size, void *p);
   static void delete_setlEstringgR(void *p);
   static void deleteArray_setlEstringgR(void *p);
   static void destruct_setlEstringgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const set<string>*)
   {
      set<string> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(set<string>),0);
      static ::ROOT::TGenericClassInfo 
         instance("set<string>", -2, "set", 398,
                  typeid(set<string>), DefineBehavior(ptr, ptr),
                  &setlEstringgR_Dictionary, isa_proxy, 0,
                  sizeof(set<string>) );
      instance.SetNew(&new_setlEstringgR);
      instance.SetNewArray(&newArray_setlEstringgR);
      instance.SetDelete(&delete_setlEstringgR);
      instance.SetDeleteArray(&deleteArray_setlEstringgR);
      instance.SetDestructor(&destruct_setlEstringgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Insert< set<string> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const set<string>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *setlEstringgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const set<string>*)0x0)->GetClass();
      setlEstringgR_TClassManip(theClass);
   return theClass;
   }

   static void setlEstringgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_setlEstringgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) set<string> : new set<string>;
   }
   static void *newArray_setlEstringgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) set<string>[nElements] : new set<string>[nElements];
   }
   // Wrapper around operator delete
   static void delete_setlEstringgR(void *p) {
      delete ((set<string>*)p);
   }
   static void deleteArray_setlEstringgR(void *p) {
      delete [] ((set<string>*)p);
   }
   static void destruct_setlEstringgR(void *p) {
      typedef set<string> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class set<string>

namespace ROOT {
   static TClass *maplEstringcOvectorlEvectorlEintgRsPgRmUgR_Dictionary();
   static void maplEstringcOvectorlEvectorlEintgRsPgRmUgR_TClassManip(TClass*);
   static void *new_maplEstringcOvectorlEvectorlEintgRsPgRmUgR(void *p = 0);
   static void *newArray_maplEstringcOvectorlEvectorlEintgRsPgRmUgR(Long_t size, void *p);
   static void delete_maplEstringcOvectorlEvectorlEintgRsPgRmUgR(void *p);
   static void deleteArray_maplEstringcOvectorlEvectorlEintgRsPgRmUgR(void *p);
   static void destruct_maplEstringcOvectorlEvectorlEintgRsPgRmUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<string,vector<vector<int> >*>*)
   {
      map<string,vector<vector<int> >*> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<string,vector<vector<int> >*>),0);
      static ::ROOT::TGenericClassInfo 
         instance("map<string,vector<vector<int> >*>", -2, "map", 783,
                  typeid(map<string,vector<vector<int> >*>), DefineBehavior(ptr, ptr),
                  &maplEstringcOvectorlEvectorlEintgRsPgRmUgR_Dictionary, isa_proxy, 0,
                  sizeof(map<string,vector<vector<int> >*>) );
      instance.SetNew(&new_maplEstringcOvectorlEvectorlEintgRsPgRmUgR);
      instance.SetNewArray(&newArray_maplEstringcOvectorlEvectorlEintgRsPgRmUgR);
      instance.SetDelete(&delete_maplEstringcOvectorlEvectorlEintgRsPgRmUgR);
      instance.SetDeleteArray(&deleteArray_maplEstringcOvectorlEvectorlEintgRsPgRmUgR);
      instance.SetDestructor(&destruct_maplEstringcOvectorlEvectorlEintgRsPgRmUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<string,vector<vector<int> >*> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const map<string,vector<vector<int> >*>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEstringcOvectorlEvectorlEintgRsPgRmUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<string,vector<vector<int> >*>*)0x0)->GetClass();
      maplEstringcOvectorlEvectorlEintgRsPgRmUgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEstringcOvectorlEvectorlEintgRsPgRmUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEstringcOvectorlEvectorlEintgRsPgRmUgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) map<string,vector<vector<int> >*> : new map<string,vector<vector<int> >*>;
   }
   static void *newArray_maplEstringcOvectorlEvectorlEintgRsPgRmUgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) map<string,vector<vector<int> >*>[nElements] : new map<string,vector<vector<int> >*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEstringcOvectorlEvectorlEintgRsPgRmUgR(void *p) {
      delete ((map<string,vector<vector<int> >*>*)p);
   }
   static void deleteArray_maplEstringcOvectorlEvectorlEintgRsPgRmUgR(void *p) {
      delete [] ((map<string,vector<vector<int> >*>*)p);
   }
   static void destruct_maplEstringcOvectorlEvectorlEintgRsPgRmUgR(void *p) {
      typedef map<string,vector<vector<int> >*> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<string,vector<vector<int> >*>

namespace ROOT {
   static TClass *maplEstringcOvectorlEshortgRmUgR_Dictionary();
   static void maplEstringcOvectorlEshortgRmUgR_TClassManip(TClass*);
   static void *new_maplEstringcOvectorlEshortgRmUgR(void *p = 0);
   static void *newArray_maplEstringcOvectorlEshortgRmUgR(Long_t size, void *p);
   static void delete_maplEstringcOvectorlEshortgRmUgR(void *p);
   static void deleteArray_maplEstringcOvectorlEshortgRmUgR(void *p);
   static void destruct_maplEstringcOvectorlEshortgRmUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<string,vector<short>*>*)
   {
      map<string,vector<short>*> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<string,vector<short>*>),0);
      static ::ROOT::TGenericClassInfo 
         instance("map<string,vector<short>*>", -2, "map", 783,
                  typeid(map<string,vector<short>*>), DefineBehavior(ptr, ptr),
                  &maplEstringcOvectorlEshortgRmUgR_Dictionary, isa_proxy, 0,
                  sizeof(map<string,vector<short>*>) );
      instance.SetNew(&new_maplEstringcOvectorlEshortgRmUgR);
      instance.SetNewArray(&newArray_maplEstringcOvectorlEshortgRmUgR);
      instance.SetDelete(&delete_maplEstringcOvectorlEshortgRmUgR);
      instance.SetDeleteArray(&deleteArray_maplEstringcOvectorlEshortgRmUgR);
      instance.SetDestructor(&destruct_maplEstringcOvectorlEshortgRmUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<string,vector<short>*> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const map<string,vector<short>*>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEstringcOvectorlEshortgRmUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<string,vector<short>*>*)0x0)->GetClass();
      maplEstringcOvectorlEshortgRmUgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEstringcOvectorlEshortgRmUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEstringcOvectorlEshortgRmUgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) map<string,vector<short>*> : new map<string,vector<short>*>;
   }
   static void *newArray_maplEstringcOvectorlEshortgRmUgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) map<string,vector<short>*>[nElements] : new map<string,vector<short>*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEstringcOvectorlEshortgRmUgR(void *p) {
      delete ((map<string,vector<short>*>*)p);
   }
   static void deleteArray_maplEstringcOvectorlEshortgRmUgR(void *p) {
      delete [] ((map<string,vector<short>*>*)p);
   }
   static void destruct_maplEstringcOvectorlEshortgRmUgR(void *p) {
      typedef map<string,vector<short>*> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<string,vector<short>*>

namespace ROOT {
   static TClass *maplEstringcOvectorlEintgRmUgR_Dictionary();
   static void maplEstringcOvectorlEintgRmUgR_TClassManip(TClass*);
   static void *new_maplEstringcOvectorlEintgRmUgR(void *p = 0);
   static void *newArray_maplEstringcOvectorlEintgRmUgR(Long_t size, void *p);
   static void delete_maplEstringcOvectorlEintgRmUgR(void *p);
   static void deleteArray_maplEstringcOvectorlEintgRmUgR(void *p);
   static void destruct_maplEstringcOvectorlEintgRmUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<string,vector<int>*>*)
   {
      map<string,vector<int>*> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<string,vector<int>*>),0);
      static ::ROOT::TGenericClassInfo 
         instance("map<string,vector<int>*>", -2, "map", 783,
                  typeid(map<string,vector<int>*>), DefineBehavior(ptr, ptr),
                  &maplEstringcOvectorlEintgRmUgR_Dictionary, isa_proxy, 0,
                  sizeof(map<string,vector<int>*>) );
      instance.SetNew(&new_maplEstringcOvectorlEintgRmUgR);
      instance.SetNewArray(&newArray_maplEstringcOvectorlEintgRmUgR);
      instance.SetDelete(&delete_maplEstringcOvectorlEintgRmUgR);
      instance.SetDeleteArray(&deleteArray_maplEstringcOvectorlEintgRmUgR);
      instance.SetDestructor(&destruct_maplEstringcOvectorlEintgRmUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<string,vector<int>*> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const map<string,vector<int>*>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEstringcOvectorlEintgRmUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<string,vector<int>*>*)0x0)->GetClass();
      maplEstringcOvectorlEintgRmUgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEstringcOvectorlEintgRmUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEstringcOvectorlEintgRmUgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) map<string,vector<int>*> : new map<string,vector<int>*>;
   }
   static void *newArray_maplEstringcOvectorlEintgRmUgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) map<string,vector<int>*>[nElements] : new map<string,vector<int>*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEstringcOvectorlEintgRmUgR(void *p) {
      delete ((map<string,vector<int>*>*)p);
   }
   static void deleteArray_maplEstringcOvectorlEintgRmUgR(void *p) {
      delete [] ((map<string,vector<int>*>*)p);
   }
   static void destruct_maplEstringcOvectorlEintgRmUgR(void *p) {
      typedef map<string,vector<int>*> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<string,vector<int>*>

namespace ROOT {
   static TClass *maplEstringcOstringgR_Dictionary();
   static void maplEstringcOstringgR_TClassManip(TClass*);
   static void *new_maplEstringcOstringgR(void *p = 0);
   static void *newArray_maplEstringcOstringgR(Long_t size, void *p);
   static void delete_maplEstringcOstringgR(void *p);
   static void deleteArray_maplEstringcOstringgR(void *p);
   static void destruct_maplEstringcOstringgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<string,string>*)
   {
      map<string,string> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<string,string>),0);
      static ::ROOT::TGenericClassInfo 
         instance("map<string,string>", -2, "map", 783,
                  typeid(map<string,string>), DefineBehavior(ptr, ptr),
                  &maplEstringcOstringgR_Dictionary, isa_proxy, 0,
                  sizeof(map<string,string>) );
      instance.SetNew(&new_maplEstringcOstringgR);
      instance.SetNewArray(&newArray_maplEstringcOstringgR);
      instance.SetDelete(&delete_maplEstringcOstringgR);
      instance.SetDeleteArray(&deleteArray_maplEstringcOstringgR);
      instance.SetDestructor(&destruct_maplEstringcOstringgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<string,string> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const map<string,string>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEstringcOstringgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<string,string>*)0x0)->GetClass();
      maplEstringcOstringgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEstringcOstringgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEstringcOstringgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) map<string,string> : new map<string,string>;
   }
   static void *newArray_maplEstringcOstringgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) map<string,string>[nElements] : new map<string,string>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEstringcOstringgR(void *p) {
      delete ((map<string,string>*)p);
   }
   static void deleteArray_maplEstringcOstringgR(void *p) {
      delete [] ((map<string,string>*)p);
   }
   static void destruct_maplEstringcOstringgR(void *p) {
      typedef map<string,string> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<string,string>

namespace ROOT {
   static TClass *maplEstringcOmaplEintcOCombLinksgRsPgR_Dictionary();
   static void maplEstringcOmaplEintcOCombLinksgRsPgR_TClassManip(TClass*);
   static void *new_maplEstringcOmaplEintcOCombLinksgRsPgR(void *p = 0);
   static void *newArray_maplEstringcOmaplEintcOCombLinksgRsPgR(Long_t size, void *p);
   static void delete_maplEstringcOmaplEintcOCombLinksgRsPgR(void *p);
   static void deleteArray_maplEstringcOmaplEintcOCombLinksgRsPgR(void *p);
   static void destruct_maplEstringcOmaplEintcOCombLinksgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<string,map<int,CombLinks> >*)
   {
      map<string,map<int,CombLinks> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<string,map<int,CombLinks> >),0);
      static ::ROOT::TGenericClassInfo 
         instance("map<string,map<int,CombLinks> >", -2, "map", 783,
                  typeid(map<string,map<int,CombLinks> >), DefineBehavior(ptr, ptr),
                  &maplEstringcOmaplEintcOCombLinksgRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(map<string,map<int,CombLinks> >) );
      instance.SetNew(&new_maplEstringcOmaplEintcOCombLinksgRsPgR);
      instance.SetNewArray(&newArray_maplEstringcOmaplEintcOCombLinksgRsPgR);
      instance.SetDelete(&delete_maplEstringcOmaplEintcOCombLinksgRsPgR);
      instance.SetDeleteArray(&deleteArray_maplEstringcOmaplEintcOCombLinksgRsPgR);
      instance.SetDestructor(&destruct_maplEstringcOmaplEintcOCombLinksgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<string,map<int,CombLinks> > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const map<string,map<int,CombLinks> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEstringcOmaplEintcOCombLinksgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<string,map<int,CombLinks> >*)0x0)->GetClass();
      maplEstringcOmaplEintcOCombLinksgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEstringcOmaplEintcOCombLinksgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEstringcOmaplEintcOCombLinksgRsPgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) map<string,map<int,CombLinks> > : new map<string,map<int,CombLinks> >;
   }
   static void *newArray_maplEstringcOmaplEintcOCombLinksgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) map<string,map<int,CombLinks> >[nElements] : new map<string,map<int,CombLinks> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEstringcOmaplEintcOCombLinksgRsPgR(void *p) {
      delete ((map<string,map<int,CombLinks> >*)p);
   }
   static void deleteArray_maplEstringcOmaplEintcOCombLinksgRsPgR(void *p) {
      delete [] ((map<string,map<int,CombLinks> >*)p);
   }
   static void destruct_maplEstringcOmaplEintcOCombLinksgRsPgR(void *p) {
      typedef map<string,map<int,CombLinks> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<string,map<int,CombLinks> >

namespace ROOT {
   static TClass *maplEstringcOintgR_Dictionary();
   static void maplEstringcOintgR_TClassManip(TClass*);
   static void *new_maplEstringcOintgR(void *p = 0);
   static void *newArray_maplEstringcOintgR(Long_t size, void *p);
   static void delete_maplEstringcOintgR(void *p);
   static void deleteArray_maplEstringcOintgR(void *p);
   static void destruct_maplEstringcOintgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<string,int>*)
   {
      map<string,int> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<string,int>),0);
      static ::ROOT::TGenericClassInfo 
         instance("map<string,int>", -2, "map", 783,
                  typeid(map<string,int>), DefineBehavior(ptr, ptr),
                  &maplEstringcOintgR_Dictionary, isa_proxy, 0,
                  sizeof(map<string,int>) );
      instance.SetNew(&new_maplEstringcOintgR);
      instance.SetNewArray(&newArray_maplEstringcOintgR);
      instance.SetDelete(&delete_maplEstringcOintgR);
      instance.SetDeleteArray(&deleteArray_maplEstringcOintgR);
      instance.SetDestructor(&destruct_maplEstringcOintgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<string,int> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const map<string,int>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEstringcOintgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<string,int>*)0x0)->GetClass();
      maplEstringcOintgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEstringcOintgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEstringcOintgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) map<string,int> : new map<string,int>;
   }
   static void *newArray_maplEstringcOintgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) map<string,int>[nElements] : new map<string,int>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEstringcOintgR(void *p) {
      delete ((map<string,int>*)p);
   }
   static void deleteArray_maplEstringcOintgR(void *p) {
      delete [] ((map<string,int>*)p);
   }
   static void destruct_maplEstringcOintgR(void *p) {
      typedef map<string,int> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<string,int>

namespace ROOT {
   static TClass *maplEintcOvectorlEFeatureIndexgRsPgR_Dictionary();
   static void maplEintcOvectorlEFeatureIndexgRsPgR_TClassManip(TClass*);
   static void *new_maplEintcOvectorlEFeatureIndexgRsPgR(void *p = 0);
   static void *newArray_maplEintcOvectorlEFeatureIndexgRsPgR(Long_t size, void *p);
   static void delete_maplEintcOvectorlEFeatureIndexgRsPgR(void *p);
   static void deleteArray_maplEintcOvectorlEFeatureIndexgRsPgR(void *p);
   static void destruct_maplEintcOvectorlEFeatureIndexgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<int,vector<FeatureIndex> >*)
   {
      map<int,vector<FeatureIndex> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<int,vector<FeatureIndex> >),0);
      static ::ROOT::TGenericClassInfo 
         instance("map<int,vector<FeatureIndex> >", -2, "map", 783,
                  typeid(map<int,vector<FeatureIndex> >), DefineBehavior(ptr, ptr),
                  &maplEintcOvectorlEFeatureIndexgRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(map<int,vector<FeatureIndex> >) );
      instance.SetNew(&new_maplEintcOvectorlEFeatureIndexgRsPgR);
      instance.SetNewArray(&newArray_maplEintcOvectorlEFeatureIndexgRsPgR);
      instance.SetDelete(&delete_maplEintcOvectorlEFeatureIndexgRsPgR);
      instance.SetDeleteArray(&deleteArray_maplEintcOvectorlEFeatureIndexgRsPgR);
      instance.SetDestructor(&destruct_maplEintcOvectorlEFeatureIndexgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<int,vector<FeatureIndex> > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const map<int,vector<FeatureIndex> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEintcOvectorlEFeatureIndexgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<int,vector<FeatureIndex> >*)0x0)->GetClass();
      maplEintcOvectorlEFeatureIndexgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEintcOvectorlEFeatureIndexgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEintcOvectorlEFeatureIndexgRsPgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) map<int,vector<FeatureIndex> > : new map<int,vector<FeatureIndex> >;
   }
   static void *newArray_maplEintcOvectorlEFeatureIndexgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) map<int,vector<FeatureIndex> >[nElements] : new map<int,vector<FeatureIndex> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEintcOvectorlEFeatureIndexgRsPgR(void *p) {
      delete ((map<int,vector<FeatureIndex> >*)p);
   }
   static void deleteArray_maplEintcOvectorlEFeatureIndexgRsPgR(void *p) {
      delete [] ((map<int,vector<FeatureIndex> >*)p);
   }
   static void destruct_maplEintcOvectorlEFeatureIndexgRsPgR(void *p) {
      typedef map<int,vector<FeatureIndex> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<int,vector<FeatureIndex> >

namespace ROOT {
   static TClass *maplEintcOFeatureIndexgR_Dictionary();
   static void maplEintcOFeatureIndexgR_TClassManip(TClass*);
   static void *new_maplEintcOFeatureIndexgR(void *p = 0);
   static void *newArray_maplEintcOFeatureIndexgR(Long_t size, void *p);
   static void delete_maplEintcOFeatureIndexgR(void *p);
   static void deleteArray_maplEintcOFeatureIndexgR(void *p);
   static void destruct_maplEintcOFeatureIndexgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<int,FeatureIndex>*)
   {
      map<int,FeatureIndex> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<int,FeatureIndex>),0);
      static ::ROOT::TGenericClassInfo 
         instance("map<int,FeatureIndex>", -2, "map", 783,
                  typeid(map<int,FeatureIndex>), DefineBehavior(ptr, ptr),
                  &maplEintcOFeatureIndexgR_Dictionary, isa_proxy, 0,
                  sizeof(map<int,FeatureIndex>) );
      instance.SetNew(&new_maplEintcOFeatureIndexgR);
      instance.SetNewArray(&newArray_maplEintcOFeatureIndexgR);
      instance.SetDelete(&delete_maplEintcOFeatureIndexgR);
      instance.SetDeleteArray(&deleteArray_maplEintcOFeatureIndexgR);
      instance.SetDestructor(&destruct_maplEintcOFeatureIndexgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<int,FeatureIndex> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const map<int,FeatureIndex>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEintcOFeatureIndexgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<int,FeatureIndex>*)0x0)->GetClass();
      maplEintcOFeatureIndexgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEintcOFeatureIndexgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEintcOFeatureIndexgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) map<int,FeatureIndex> : new map<int,FeatureIndex>;
   }
   static void *newArray_maplEintcOFeatureIndexgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) map<int,FeatureIndex>[nElements] : new map<int,FeatureIndex>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEintcOFeatureIndexgR(void *p) {
      delete ((map<int,FeatureIndex>*)p);
   }
   static void deleteArray_maplEintcOFeatureIndexgR(void *p) {
      delete [] ((map<int,FeatureIndex>*)p);
   }
   static void destruct_maplEintcOFeatureIndexgR(void *p) {
      typedef map<int,FeatureIndex> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<int,FeatureIndex>

namespace ROOT {
   static TClass *maplEintcOCombLinksgR_Dictionary();
   static void maplEintcOCombLinksgR_TClassManip(TClass*);
   static void *new_maplEintcOCombLinksgR(void *p = 0);
   static void *newArray_maplEintcOCombLinksgR(Long_t size, void *p);
   static void delete_maplEintcOCombLinksgR(void *p);
   static void deleteArray_maplEintcOCombLinksgR(void *p);
   static void destruct_maplEintcOCombLinksgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<int,CombLinks>*)
   {
      map<int,CombLinks> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<int,CombLinks>),0);
      static ::ROOT::TGenericClassInfo 
         instance("map<int,CombLinks>", -2, "map", 783,
                  typeid(map<int,CombLinks>), DefineBehavior(ptr, ptr),
                  &maplEintcOCombLinksgR_Dictionary, isa_proxy, 0,
                  sizeof(map<int,CombLinks>) );
      instance.SetNew(&new_maplEintcOCombLinksgR);
      instance.SetNewArray(&newArray_maplEintcOCombLinksgR);
      instance.SetDelete(&delete_maplEintcOCombLinksgR);
      instance.SetDeleteArray(&deleteArray_maplEintcOCombLinksgR);
      instance.SetDestructor(&destruct_maplEintcOCombLinksgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<int,CombLinks> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const map<int,CombLinks>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEintcOCombLinksgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<int,CombLinks>*)0x0)->GetClass();
      maplEintcOCombLinksgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEintcOCombLinksgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEintcOCombLinksgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) map<int,CombLinks> : new map<int,CombLinks>;
   }
   static void *newArray_maplEintcOCombLinksgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) map<int,CombLinks>[nElements] : new map<int,CombLinks>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEintcOCombLinksgR(void *p) {
      delete ((map<int,CombLinks>*)p);
   }
   static void deleteArray_maplEintcOCombLinksgR(void *p) {
      delete [] ((map<int,CombLinks>*)p);
   }
   static void destruct_maplEintcOCombLinksgR(void *p) {
      typedef map<int,CombLinks> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<int,CombLinks>

namespace {
  void TriggerDictionaryInitialization_TriggerMenuNtupleDict_Impl() {
    static const char* headers[] = {
"ChainEntry.h",
"CombLinks.h",
"RoILinks.h",
"FeatureIndex.h",
"ElectronRoILinks.h",
"JetRoILinks.h",
"MuonRoILinks.h",
"TauRoILinks.h",
"TMNUtil.h",
"TrigDecSummary.h",
0
    };
    static const char* includePaths[] = {
"..",
"-I/Users/Alex/Desktop/ProofAna/ProofWorkshop/utils/TriggerMenuNtuple/TriggerMenuNtuple",
"/Users/Alex/Desktop/HEP/ROOT6/include",
"/Users/Alex/Desktop/HEP/ROOT6/include",
"/Users/Alex/Desktop/ProofAna/ProofWorkshop/utils/TriggerMenuNtuple/TriggerMenuNtuple/",
0
    };
    static const char* fwdDeclCode = 
R"DICTFWDDCLS(
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$ChainEntry.h")))  ChainEntry;
class __attribute__((annotate("$clingAutoload$CombLinks.h")))  CombLinks;
class __attribute__((annotate("$clingAutoload$RoILinks.h")))  RoILinks;
class __attribute__((annotate("$clingAutoload$CombLinks.h")))  FeatureIndex;
class __attribute__((annotate("$clingAutoload$TMNUtil.h")))  TMNUtil;
class __attribute__((annotate("$clingAutoload$TrigDecSummary.h")))  TrigDecSummary;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "ChainEntry.h"
#include "CombLinks.h"
#include "RoILinks.h"
#include "FeatureIndex.h"
#include "ElectronRoILinks.h"
#include "JetRoILinks.h"
#include "MuonRoILinks.h"
#include "TauRoILinks.h"
#include "TMNUtil.h"
#include "TrigDecSummary.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"ChainEntry", payloadCode, "@",
"CombLinks", payloadCode, "@",
"FeatureIndex", payloadCode, "@",
"RoILinks", payloadCode, "@",
"TMNUtil", payloadCode, "@",
"TrigDecSummary", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TriggerMenuNtupleDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TriggerMenuNtupleDict_Impl, {}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TriggerMenuNtupleDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TriggerMenuNtupleDict() {
  TriggerDictionaryInitialization_TriggerMenuNtupleDict_Impl();
}
