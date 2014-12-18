// Dear emacs, this is -*-c++-*-

#ifndef __ATHJETCLEANINGTOOL__
#define __ATHJETCLEANINGTOOL__

/**
   @class AthJetCleaningTool
   @brief Tool to select objects in Athena using an underlying ARA and pure ROOT tool.

   @author Karsten Koeneke (CERN)
   @date   July 2011

*/

// Include the interface
#include "ObjectSelectorCore/IAthSelectorTool.h"

// Include the athena/ARA dual use wrapper
#include "AraTool/AraAlgToolWrapper.h"

// Include the AthenaRootAccess tool
#include "ARAJetCleaningTool.h"


class AthJetCleaningTool
  : virtual public IAthSelectorTool,
    public  AraAlgToolWrapper< ARAJetCleaningTool >
{

public: 
  /** Standard constructor */
  AthJetCleaningTool( const std::string& type,
                      const std::string& name,
                      const IInterface* parent )
    : AlgTool( type, name, parent ),
      AraAlgToolWrapper< ARAJetCleaningTool > ( type, name, parent )
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

