// Program to illustrate the use of the FlavKtPlugin within FastJet
//
// run this program as
//    ./fastjet-example < event-with-pdgids.dat
//

#include "fastjet/FlavKtPlugin.hh"
#include "fastjet/Selector.hh"
#include <iostream>
#include <iomanip>

using namespace fastjet;
using namespace std;

ostream & operator<<(ostream&, const PseudoJet & j);
ostream& print_header(ostream& ostr);

//----------------------------------------------------------------------
int main() {
  // read in the input particles and their PDG IDs
  double px, py, pz, E;
  int    pdg_id;
  vector<PseudoJet> input_particles;
  while (cin >> px >> py >> pz >> E >> pdg_id) {
    // create a fastjet::PseudoJet with these components and put it onto
    // back of the input_particles vector
    PseudoJet p(px,py,pz,E);
    // assign information relative to the flavour
    p.set_user_info(new FlavInfo(pdg_id)); // delete will be handled automatically by FJ.
    input_particles.push_back(p); 
  }
  
  // add the beam particles to the list (assume we had incoming protons).
  // One must explicitly label them as incoming "beam" particles.
  PseudoJet beam1(0,0,+7000,7000);
  beam1.set_user_info(new FlavInfo(2212, FlavInfo::beam));
  input_particles.push_back(beam1);

  PseudoJet beam2(0,0,-7000,7000);
  beam2.set_user_info(new FlavInfo(2212, FlavInfo::beam));
  input_particles.push_back(beam2);
  
  //input_particles = sorted_by_rapidity(input_particles); // helps to read event

  ClusterSequence::print_banner(); // have this at start, rather than in between subsequent I/O

  // output the flavoured part of the event
  cout << "All flavoured input particles " << endl;
  cout << "------------------------------" << endl;
  cout << "index ";
  print_header(cout) << endl;
  double Etot = 0;
  for (unsigned i = 0; i < input_particles.size(); i++) {
    Etot += input_particles[i].E();
    if (input_particles[i].user_info<FlavInfo>().is_flavourless()) continue;
    cout << setw(5) << i << " " << input_particles[i] << endl;
  }

  // specify the jet algorithm
  // flavour kt with alpha=1 (see FlavKtPlugin.hh for other options)
  int imode = ialg_pp_ktf1_E;  // try ktf2 and ktLI to see how event changes
  double  R = 0.7;
  JetDefinition jet_def = new FlavKtPlugin(imode, R);
  ClusterSequence cs(input_particles, jet_def);
  
  // first look at the "inclusive" jets above 20 GeV
  vector<PseudoJet> jets = sorted_by_pt(cs.inclusive_jets(20.0));
  cout << endl;
  cout << "Inclusive jets about 20 GeV " << endl;
  cout << "------------------------------" << endl;
  print_header(cout) << endl;
  for (unsigned i = 0; i < jets.size(); i++) cout << jets[i] << endl;

  // next look at the exclusive clustering, viewing this as a 2-jet event
  // (beware when doing this with "ktfs" type algorithms, which leave
  // clusterings that lead to non-partonic flavours, e.g. ud, until the very end)
  int n_excl = 2;
  jets = cs.exclusive_jets(n_excl);
  cout << endl;
  cout << "Event viewed as " << n_excl << " exclusive jets" << endl;
  cout << "--------------------------------" << endl;
  print_header(cout) << endl;
  for (unsigned i = 0; i < jets.size(); i++) cout << jets[i] << endl;
  // to get the beam flavours in the exclusive view, we need "extras" from the cs;
  const FlavKtPlugin::Extras * extras = dynamic_cast<const FlavKtPlugin::Extras *>(cs.extras());
  if (extras != 0) {
    cout << "   forward  beam flavour: " << extras->beam_flav_forward(n_excl).description()  << endl;
    cout << "   backward beam flavour: " << extras->beam_flav_backward(n_excl).description() << endl;
    cout << endl;
  }
  
}


//----------------------------------------------------------------------
// helpers
ostream & operator<<(ostream& ostr, const PseudoJet & j) {
  ostr << setw(12) << j.perp()
       << setw(12) << j.rap()
       << setw(12) << j.phi();
  if (j.has_user_info<FlavInfo>()) ostr << "  " << j.user_info<FlavInfo>().description();
  return ostr;
}
ostream& print_header(ostream& ostr) {
  ostr << setw(12) << "pt"
       << setw(12) << "rapidity"
       << setw(12) << "phi";
  ostr << "  flav";
  return ostr;
}
