// this is -*-c++-*-
#ifndef _IMETUTILITYATHTOOL_
#define _IMETUTILITYATHTOOL_

#include "GaudiKernel/IAlgTool.h"
#include "MissingETUtility/METUtility.h"

class MissingET;

static const InterfaceID IID_IMETUtilityAthTool( "IMETUtilityAthTool", 1, 0 );

namespace MissingETUtility {

  class IMETUtilityAthTool : virtual public METUtility, virtual public IAlgTool {

  public:
 
    static const InterfaceID& interfaceID() { return IID_IMETUtilityAthTool; };
 
    virtual StatusCode process() = 0;

    virtual StatusCode setupJets(const std::string &collectionName) = 0;
    virtual StatusCode setupElectrons(const std::string &collectionName) = 0;
    virtual StatusCode setupPhotons(const std::string &collectionName) = 0;
    virtual StatusCode setupTaus(const std::string &collectionName) = 0;
    virtual StatusCode setupMuons(const std::string &collectionName,
				  const std::string &matchCollectionName,
				  const unsigned short userStatusWord) = 0;
    virtual StatusCode setupClusters(const std::string &collectionName,
				     const unsigned short userStatusWord) = 0;
    virtual StatusCode setupTracks(const std::string &collectionName) = 0;
    
    virtual void       setMETTerm(const METUtil::Terms term, const MissingET* thisMET) = 0;
    virtual MissingET  getMETTerm(const METUtil::Terms term,
				  const METUtil::Systematics systematic = METUtil::None) = 0;

  };

}

#endif
