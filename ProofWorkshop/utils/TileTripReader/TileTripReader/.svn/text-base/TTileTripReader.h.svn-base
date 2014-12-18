/* 
 * File:   TTileTripReader.h
 * Author: Stephen Cole <stephen.cole@cern.ch>
 *
 * Created on August 7, 2012, 4:21 PM
 */

#ifndef TTILETRIPREADER_H
#define	TTILETRIPREADER_H

#include <vector>
#include <map>
#include <iostream>
#include <iosfwd>

#ifndef __STANDALONE__
#include "PATCore/TSelectorToolBase.h"
#include "PATCore/TAccept.h"
#include "PATCore/TCalculatorToolBase.h"
#include "PATCore/TResult.h"
#endif /*__STANDALONE__*/


class TChain;



struct TripRegion{
    double eta1;
    double eta2;
    double phi1;
    double phi2;
};


namespace Root{

class TTileTripReader
#ifndef __STANDALONE__
        : public TSelectorToolBase,
          public TCalculatorToolBase
#endif /*__STANDALONE__*/
{
public:
    enum Verbosity{
        Default=0,
        Debug=1
    };
    
    TTileTripReader(const char* name="TTileTripReader" );
    virtual ~TTileTripReader();
    
#ifndef __STANDALONE__
    /**
     * 
     * @param run Run number
     * @param lbn Lumiblock number
     * @param event Event number
     * @param eta Eta position
     * @param phi Phi position
     * @return Constant TAccept& containing the result of the check
     * 
     * Trip result is stored under "InTrip", event check is stored under "BadEvent"
     */
    const TAccept& accept(int run,int lbn, unsigned int event=0,double eta=-99.9,double phi=-99.9);
#endif /*__STANDALONE__*/
    
    /**
     * 
     * @param run the run number
     * @param lbn the lumiblock number
     * @param eta the area central eta coordinate
     * @param phi the area central phi coordinate
     * @param dR the area size
     * @return The fraction of the area in eta phi space covered by tripped modules
     */
    double areaTripFraction(int run, int lbn, double eta, double phi, double dR);
    
#ifndef __STANDALONE__
    /**
     * 
     * @param run Run number
     * @param lbn Lumiblock number
     * @param eta Eta value of cone center
     * @param phi Phi value of cone center
     * @param dR Radius of the cone in (eta,phi) space
     * @return constant TResult& containing the fraction of the area in eta phi space covered by tripped modules
     * 
     * Result is stored under "TripAreaFrac" in the returned TResult&
     */
    const TResult& calculate(int run, int lbn, double eta, double phi, double dR);
#endif /*__STANDALONE__*/
    
    
    /**
     * 
     * @param run the run number
     * @param lbn the lumiblock number
     * @param eta eta value to check
     * @param phi phi value to check
     * @return true if there's a tripped module in the region
     */
    bool checkEtaPhi(int run,int lbn,double eta,double phi);
    
    /**
     * 
     * @param run Run number
     * @param lbn Lumiblock number
     * @param event event number
     * @return true if event is good false if bad
     * 
     * Checks against an internal map of 433 bad events
     */
    bool checkEvent(unsigned int run,unsigned int lbn,unsigned int event);
    
    inline int finalize() { return 1; }
    
    /**
     * 
     * @param run the run number
     * @param lbn the lumiblock number
     * @return a vector containing TripRegions structs for all trip regions
     */
    std::vector<TripRegion> getEtaPhi(int run, int lbn);
    
    int initialize();
    
    /**
     * 
     * @param part tile partition: LBA=0, LBC=1, EBA=2, EBC=3
     * @param mod tile module. Note: starts at 0, not 1
     * @return A TripRegion struct containing the limits of the module
     */
    TripRegion partModToEtaPhi(int part, int mod);
    
    /**
     * 
     * @param file the file path to the trip list root file
     * @return the number of files added
     * 
     * The trip reader uses TChain to read the TTrees inside the root file.  
     * You can load multiple files by using wildcards.
     */
    int setTripFile(const char* file);
    
    void setVerbosity(int v=Debug,std::ostream& stream=std::cout){
        m_verbosity=v;
        m_msglog=&stream;
    }
private:
    /**
     * Attempts to correct for improperly built trip list files. *DEPRECIATED*
     */
    void buildOffsets();
    
    /**
     * 
     * @param run Run number
     * @return Position in trip TTree where the run starts
     */
    int findStartEntry(int run);
    
    /**
     * Fills the bad event map
     */
    void setBadEventList();
    TChain* m_trips;
    TChain* m_runMap;
    int m_mapRun;
    int m_Run;
    int m_FirstEntry;
    int m_currentRun;
    int m_currentLbn;
    int m_startEntry;
    int m_verbosity;
    std::map<unsigned int,std::map<unsigned short,unsigned int> > m_badEvents;
    std::vector<TripRegion> m_currentTrips;
    std::vector<int> m_Offsets;
    std::vector<char>* m_Partition;
    std::vector<char>* m_Module;
    int m_LumiStart;
    std::vector<int>* m_LumiEnd;
    std::ostream* m_msglog;
    

};
}

#endif	/* TTILETRIPREADER_H */

