// Dear emacs, this is -*-c++-*-

#ifndef __ARAJETCLEANINGTOOL__
#define __ARAJETCLEANINGTOOL__

/**
   @class ARAJetCleaningTool
   @brief Tool to select objects in AthenaRootAccess using an underlying pure ROOT tool.

   @author Karsten Koeneke (CERN)
   @date   July 2011

*/


// Include the return object and the underlying ROOT tool
#include "ObjectSelectorCore/TAccept.h"
#include "JetSelectorTools/TJetCleaningTool.h"

// Include the base class
#include "ObjectSelectorCore/ARASelectorToolBase.h"

// Atlas includes
#include "AraTool/AraToolBase.h"
#include "JetEvent/Jet.h"
#include "EventKernel/INavigable4Momentum.h"



static const InterfaceID IID_ARAJetCleaningTool("ARAJetCleaningTool", 1, 0);


class ARAJetCleaningTool : public ARASelectorToolBase, virtual public AraToolBase
{

public:
  /** Standard constructor */
  ARAJetCleaningTool(PropertyMgr *pmgr=0);

  /** Standard destructor */
  virtual ~ARAJetCleaningTool();

public:
  /** AlgTool interface methods */
  static const InterfaceID& interfaceID() { return IID_ARAJetCleaningTool; }

public:
  /** Gaudi Service Interface method implementations */
  virtual StatusCode initialize();

  /** Gaudi Service Interface method implementations */
  virtual StatusCode finalize();


  // Main methods
public:
  /** The main accept method for INavigable4Momentum: 
      It tries to cast to Jet and then calls the accept(const Jet*) method */
  const Root::TAccept& accept( const INavigable4Momentum* part );

  /** The main accept method: the actual cuts are applied here */
  const Root::TAccept& accept( const Jet* jet );


  // Public methods
public:
  /** Method to get the underlying ROOT tool */
  inline Root::TJetCleaningTool* getRootTool() { return m_rootTool; };


  // Private members
private:
  /** Pointer to the underlying ROOT based tool */
  Root::TJetCleaningTool* m_rootTool;


}; // End: class definition


///////////////////////////////////////////////////////////////////
// Inline methods:
///////////////////////////////////////////////////////////////////

/** The main accept method for INavigable4Momentum: 
    It tries to cast to Jet and then calls the accept(const Jet*) method */
inline const Root::TAccept& ARAJetCleaningTool::accept( const INavigable4Momentum* part )
{
  const Jet* jet = dynamic_cast<const Jet*>(part);
  if ( jet )
    {
      return accept(jet);
    }
  else
    {
      std::cerr << "Could NOT cast to a const Jet!!!" << std::endl;
      return m_acceptDummy;
    }
}

#endif

