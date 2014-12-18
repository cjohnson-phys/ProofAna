// This is -*-c++-*-
#ifndef METUTILITY_EXAMPLEALG
#define METUTILITY_EXAMPLEALG

// header for AthAlgorithm
#include "AthenaBaseComps/AthAlgorithm.h"
#include "GaudiKernel/ToolHandle.h"
#include "MissingETUtility/IMETUtilityAthTool.h"

class ITHistSvc;
class TH1F;
class TDirectory;

namespace MissingETUtility {
  
  const double GeV = 1000.;

  class METUtilAlg : public AthAlgorithm {

  public:
    // Default constructor format for AthAlgorithm
    // Need to pass constructor arguments to the base class constructor
    METUtilAlg(const std::string& name, ISvcLocator* pSvcLocator);
    virtual ~METUtilAlg();

    // Required methods for all Athena algs
    virtual StatusCode initialize();
    virtual StatusCode execute();
    virtual StatusCode finalize();

  private:
    ITHistSvc *m_tHistSvc;

    bool m_doSoftJets;

    ToolHandle< IMETUtilityAthTool > m_METUtilHandle;
  };

}

#endif
