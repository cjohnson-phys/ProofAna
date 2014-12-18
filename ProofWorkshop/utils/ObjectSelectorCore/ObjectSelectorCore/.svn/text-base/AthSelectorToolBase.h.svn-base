// Dear emacs, this is -*-c++-*-

#ifndef __ATHSELECTORTOOLBASE__
#define __ATHSELECTORTOOLBASE__

/**
   @class AthSelectorToolBase
   @brief Base tool to select objects in Athena using an underlying ARA and pure ROOT tool.

   @author Karsten Koeneke (CERN)
   @date   April 2011

*/

// Include the interface
#include "ObjectSelectorCore/IAthSelectorTool.h"

// Include the athena/ARA dual use wrapper
#include "AraTool/AraAlgToolWrapper.h"

// Include the AthenaROOTAccess base tool
#include "ObjectSelectorCore/ARASelectorToolBase.h"


class AthSelectorToolBase
  : virtual public IAthSelectorTool,
    public  AraAlgToolWrapper< ARASelectorToolBase >
{

public: 
  /** Standard constructor */
  AthSelectorToolBase( const std::string& type,
                       const std::string& name,
                       const IInterface* parent )
    : AlgTool( type, name, parent ),
      AraAlgToolWrapper< ARASelectorToolBase > ( type, name, parent )  
  {
    AlgTool::declareInterface< IAthSelectorTool >(this);
  };


  /** We have to declare the main method here because the IAthXXXTool method is declared as pure virtual */
  virtual const Root::TAccept& accept( const INavigable4Momentum* part )
  {
    return this->getTool()->accept(part);
  };


}; // End: class definition


#endif
