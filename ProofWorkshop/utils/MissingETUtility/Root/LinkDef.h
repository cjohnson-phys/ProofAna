/// Dear emacs, this is -*-c++-*-
#ifndef __MISSINGETUTILITY__
#define __MISSINGETUTILITY__

#ifdef __CINT__
#include "MissingETUtility/METUtility.h"

#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;
#pragma link C++ nestedclasses;

#pragma link C++ std::pair<float,float> ;
#pragma link C++ std::vector< pair<float,float> > ;
#pragma link C++ std::vector< float > ;
#pragma link C++ std::vector< vector<float> > ;

#pragma link C++ namespace METUtil ; 
#pragma link C++ class METUtil::MultiSyst+ ; 

#pragma link C++ struct MissingETTags ;

#pragma link C++ class METUtility+ ;
#pragma link C++ class METUtility::PhysicsObject+ ;
#pragma link C++ class METUtility::METObject+ ; 

#endif

#endif

