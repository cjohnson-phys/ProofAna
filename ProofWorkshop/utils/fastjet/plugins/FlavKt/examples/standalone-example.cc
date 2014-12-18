// Program to illustrate the use of the FlavKtPlugin within FastJet
//
// run this program as
//    ./standalone-example < event-with-flavours.dat
//

#include<iostream>
#include<fstream>
#include "ktflavf77.h"
#include "JetIModes.h"

using namespace std;

int main() {
  int np; 

  // read number of particles
  cin >> np;

  // array containing particle momenta
  double parr[np*4];

  // array containing particle flavour
  int pflav[np*6];

  // array containing the flavour of the two beams
  int beamflav[12] = { 1, 2,0,0,0,0,    // proton
		       -1,-2,0,0,0,0};  // antiproton
  int incomingflav[12] = {0,0,0,0,0,0,
			  0,0,0,0,0,0};

  for (int ip=0; ip < np ; ip++) {
    // read particle four momentum
    cin    >> parr[4*ip+0]  // px
	   >> parr[4*ip+1]  // py
	   >> parr[4*ip+2]  // px
	   >> parr[4*ip+3]  // E
    // read particle flavour
           >> pflav[6*ip+0]  // d
	   >> pflav[6*ip+1]  // u
	   >> pflav[6*ip+2]  // s
	   >> pflav[6*ip+3]  // c
	   >> pflav[6*ip+4]  // b
	   >> pflav[6*ip+5]; // t
  }

  // jet algorithm
  int imode=ialg_pp_ktf1_E;
  const double R = 0.7;
  // useless in this case because we require inclusive clustering
  double dcut = 0.0;

  // array containing jet momenta
  double jetarr[np*4];
  // require inclusive jet clustering
  int njets = -1;

  // array containing jet flavour
  int nflav = 6;
  int jetflav[np*nflav];
  
  // filter flavour so that only b-particles are considered flavoured
  //const int id = 5;
  //filterflavour(np,nflav,pflav,id);

  // finally invoke the jet algorithm
  ktflavf77(imode,R,np,parr,nflav,pflav,beamflav,njets,jetarr,
  			 jetflav,incomingflav,dcut);

  // write momentum and flavour of the two highest pt jets 
  cout << endl;
  cout << "----> Reading in event from file event.txt" << endl;
  cout << "----> Running kt-flavour algorithm" << endl;
  cout << "----> Printing flavour (net nr of {d,u,s,c,b,t}) and momenta (px,py,pz,E) of the two highest pt inclusive jets" << endl;
  cout << endl;
  cout << "Flavour  of jet 1: "
       << jetflav[0] << " " 
       << jetflav[1] << " " 
       << jetflav[2] << " " 
       << jetflav[3] << " " 
       << jetflav[4] << " " 
       << jetflav[5] << " " 
       << endl; 
  cout << "Momentum of jet 1 (px py pz E): " 
       << jetarr[0] << " " 
       << jetarr[1] << " " 
       << jetarr[2] << " " 
       << jetarr[3] << " " 
       << endl; 
  cout << "Flavour  of jet 2: "
       << jetflav[nflav+0] << " "
       << jetflav[nflav+1] << " "
       << jetflav[nflav+2] << " "
       << jetflav[nflav+3] << " "
       << jetflav[nflav+4] << " "
       << jetflav[nflav+5] << " "
       << endl; 
  cout << "Momentum of jet 2: " 
       << jetarr[4+0] << " "
       << jetarr[4+1] << " "
       << jetarr[4+2] << " "
       << jetarr[4+3] << " "
       << endl; 
  cout << endl;

  return 0;

}
