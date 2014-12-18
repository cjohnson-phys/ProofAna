#ifndef __RESCALER_HH__
#define __RESCALER_HH__

#include <fastjet/FunctionOfPseudoJet.hh>
#include <fastjet/ClusterSequenceArea.hh>
#include <fastjet/Error.hh>

using namespace fastjet;
using namespace std;

// Note on 4-vector rescaling of the ghosts:
// 
// This depends on 2 parameters:
//  - the pt scale 
//  - the dt=mt-pt scale (denoted by mt in the code)
// For a givben pt and dt, the mass of the ghost should be
//  m^2 = mt^2 - pt^2
//      = (mt-pt) (mt+pt)
//      = dt (2 pt + mt)
// mt should by default be set to 0

class CSrescaler : public FunctionOfPseudoJet<PseudoJet>{
public: 
  CSrescaler(double pt_scale, double mt_scale, double ghost_scale) 
    : _pt_scale(pt_scale), _mt_scale(mt_scale), _ghost_scale(ghost_scale){}

  PseudoJet result(const PseudoJet &jet) const{
    throw Error("CSrescaler has to be applied on a vector of PseudoJet");
  }

  vector<PseudoJet> operator()(const vector<PseudoJet> &jets) const{
    const ClusterSequence *cs = jets[0].validated_cs();
    const vector<ClusterSequence::history_element> & hist = cs->history();
    const JetDefinition::Recombiner * rec = cs->jet_def().recombiner();

    PseudoJet j1, j2;

    vector<PseudoJet> scaled_jets(jets.size());
    for (unsigned int i=0;i<jets.size();i++){
      const PseudoJet & jet = jets[i];
      if (jet.has_parents(j1, j2)){
	rec->recombine(scaled_jets[hist[j1.cluster_hist_index()].jetp_index],
		       scaled_jets[hist[j2.cluster_hist_index()].jetp_index],
		       scaled_jets[i]);
      } else if (jet.is_pure_ghost()){
	scaled_jets[i] = jet;
	double pt = _pt_scale*(jet.perp()/_ghost_scale);
	double m = sqrt(_mt_scale*(_mt_scale+2*pt));
	scaled_jets[i].reset_momentum(PtYPhiM(pt, jet.rap(), jet.phi(), m));
      } else {
	scaled_jets[i] = jets[i];
      }
    }

    return scaled_jets;
  }

private:
  double _pt_scale, _mt_scale, _ghost_scale;
};


class Rescaler : public FunctionOfPseudoJet<PseudoJet>{
public:
  Rescaler(double pt_scale, double mt_scale, double ghost_scale)
    : _pt_scale(pt_scale), _mt_scale(mt_scale), _ghost_scale(ghost_scale){};

  PseudoJet result(const PseudoJet &jet) const{
    // directly remove the case os a composite jet
    if (!jet.has_associated_cluster_sequence()){
      // just handle the case of a composite jet here
      if (!jet.has_pieces())
	throw Error("Rescaler applies only on jets with an associated CS or composite jets");
      
      return join((*this)(jet.pieces()));
    }

    // ensure the CS is valid and has area
    ClusterSequenceAreaBase *csa = new ClusterSequenceAreaBase();
    CSrescaler resc(_pt_scale, _mt_scale, _ghost_scale);
    csa->transfer_from_sequence(*(jet.validated_csab()), &resc);
    PseudoJet res = csa->jets()[csa->history()[jet.cluster_hist_index()].jetp_index];
    csa->delete_self_when_unused();
    return res;
  }

private:
  double _pt_scale, _mt_scale, _ghost_scale;
};


#endif // __RESCALER_HH__