// Dear emacs, this is -*-c++-*-

#ifndef __ARASELECTORTOOLBASE__
#define __ARASELECTORTOOLBASE__

/**
   @class ARASelectorToolBase
   @brief Base tool to select objects in AthenaRootAccess using an underlying pure ROOT tool.

   @author Karsten Koeneke (CERN)
   @date   April 2011

*/


// Include the return object
#include "ObjectSelectorCore/TAccept.h"

// Atlas includes
//#include "GaudiKernel/AlgTool.h"
#include "AraTool/AraToolBase.h"

// Include the interface
#include "ObjectSelectorCore/IAthSelectorTool.h"



class INavigable4Momentum;


static const InterfaceID IID_ARASelectorToolBase("ARASelectorToolBase", 1, 0);


class ARASelectorToolBase : virtual public AraToolBase
{

public: 
  /** Standard constructor */
  ARASelectorToolBase(PropertyMgr *pmgr=0) :
    AraToolBase(pmgr),
    m_acceptDummy("TAcceptDummyInARASelectorToolBase")
  {
    //AlgTool::declareInterface< IAthSelectorTool >(this);
  }
    
  /** Standard destructor */
  virtual ~ARASelectorToolBase(){};
  
public:
  /** AlgTool interface methods */
  static const InterfaceID& interfaceID() { return IID_ARASelectorToolBase; }

public:
  /** Gaudi Service Interface method implementations */
  virtual StatusCode initialize()
  {
    return StatusCode::SUCCESS;
  }

  
  /** Gaudi Service Interface method implementations */
  virtual StatusCode finalize()
  {
    return StatusCode::SUCCESS;
  }

  // Main methods
public:
  /** The main accept method: the actual cuts are applied here */
  virtual const Root::TAccept& accept( const INavigable4Momentum* /*part*/ )
  {
    return m_acceptDummy;
  }

  // Protected member variables
protected:
  /** A dummy return TAccept object */
  Root::TAccept m_acceptDummy;


}; // End: class definition


#endif
