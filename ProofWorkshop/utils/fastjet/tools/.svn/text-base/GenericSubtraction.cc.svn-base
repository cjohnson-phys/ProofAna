#include <fastjet/tools/GenericSubtraction.hh>
#include <iomanip>
//#include "rescaler.hh"
#include <fastjet/tools/rescaler.hh>


FASTJET_BEGIN_NAMESPACE

using namespace std;

//------------------------------------------------------------------------
// a subtractor for a generic observable
//
// Assuming the jet has a hard (h) and background (b) component. For
// a pt-dependent quantity we use
//   f(h+b) = f(h) + rho * A * ghost_area * df/d(ghost_scale)
// 
// Then we want the "dt=mt-pt" dependence. For that, we'd need to
// keep the pt fixed and vary dt.
//   dt = mt-pt = sqrt(m^2+pt^2)-pt
//     => (dt+pt)^2 = m^2 + pt^2
//     => m = sqrt((dt+pt)^2 - pt^2)
//          = sqrt(dt (dt+2 pt))
//------------------------------------------------------------------------
  // subtract a given FOfPJ for a given jet
double GenericSubtractor::operator()(const FunctionOfPseudoJet<double> &f, 
                                     const PseudoJet &jet) const{
  // make sure that the jet has an area!!
  if (!jet.has_area()){
    throw Error("GenericSubtractor can only be applied on jets with an area");
  }

  // compute a reference ghost scale
  vector<PseudoJet> ghosts = SelectorIsPureGhost()(jet.constituents());
  if (ghosts.size() == 0){ 
    double fn = f(jet);
    _result_unsubtracted = _result_pt_only_1st_order =
      _result_pt_only = _result_1st_order = fn;
    return fn;
  }

  double ghost_scale=0.0;
  for (vector<PseudoJet>::iterator git=ghosts.begin(); git!=ghosts.end();git++)
    ghost_scale+=git->perp();
  ghost_scale/=ghosts.size();
  // TODO: turn that into a fastjet::Error
  assert(_bge);

  // get the background densities in pt and "mt-pt"
  double rhoA_pt = _bge->rho(jet) * ghosts[0].area();
  const FunctionOfPseudoJet<double> * p_density = _bge->jet_density_class();
  _bge->set_jet_density_class(&m_density);
  double rhoA_mt = _bge->rho(jet) * ghosts[0].area();
  _bge->set_jet_density_class(p_density);
  
  // now compute the derivatives
  // 
  // originally, we were chosing the step size from the stability of
  // the 1st pt derivative. But this led to some instabilities in the
  // "mt" derivative so we need to have a different scale for that
  // one.
  //
  // Also, we noticed some likely unstabilities in the final result
  // which apparently did not appear in the 1st derivative, so at teh
  // end of the day it might be better to test for stability on the
  // full final result. 
  //
  // Unfortunately, this is not very prictactical from a computation
  // time point of view: doing a scan in both pt and mt would be time
  // consuming.
  //
  // So, an intermediate compromise could be to do 2 scans, one in pt
  // and one in mt, and for each of them test the stability of the
  // total correction:
  //   -rhot A df/dpt + 1/2 (rhot A)^2 d^2f/dpt^2
  //   -rhom A df/dmt + 1/2 (rhom A)^2 d^2f/dmt^2
  // and then hope the crossed derivative would be under control.

  // compute the value of the function at the orignal point once and for all
  //
  // Note that we assume that the pt of 1e-100 does not play any role
  // (i.e. behaves like if it was pt=0)
  double f0 = f(jet);
  _result_unsubtracted = f0;

  // do the scale swipe for the 1st derivative in x
  //
  // we need to compute the derivative using steps 
  //   h_i = 2^{-i} h0             i=0, ..., nh
  //
  // Even with a very good numerical precision, a scale of
  // h=1e-3..1e-4 gave very good results, so we shall use h0=pt,
  // nh=30 (to have a margin of security and go down to 1e-6 for pt=1000)
  //
  // For each of these stepsizes, we need to compute the derivative at
  //   x, x+h_i/4, x+h_i/2, x+3*h_i/4, x+h_i
  //
  // We start by computing the derivatives at each scale
  const int nh=30;
  const double h0 = jet.pt();

  double d1[nh+1], d2[nh+1], corr[nh+1];
  double f1, f2, f3, f4;

  double h = h0*pow(2.0,-nh);

  f1 = f(Rescaler(h/4, 0.0, ghost_scale)(jet));
  f2 = f(Rescaler(h/2, 0.0, ghost_scale)(jet));
  for (int i=0;i<=nh;i++){
    f3 = f(Rescaler(3*h/4, 0.0, ghost_scale)(jet));
    f4 = f(Rescaler(h,     0.0, ghost_scale)(jet));

    // apply a forward 5-point rule (including f0)
    d1[nh-i] = (25.0/3.0*(f1-f0) - 23.0/3.0*(f2-f1)
               +13.0/3.0*(f3-f2) -  1.0    *(f4-f3))/h;
    double s1 = (f0-f1)/h-(f1-f2)/h;
    double s2 = (f1-f2)/h-(f2-f3)/h;
    double s3 = (f2-f3)/h-(f3-f4)/h;
    d2[nh-i] = (140.0/3.0*s1-136/3.0*s2+44/3.0*s3)/h;
    if (_verbose) cout << "stepderiv " << h << " " << d1[nh-i] << " " << d2[nh-i] 
		       << " (f0=" << f0 << ", f1=" << f1 << ", f2=" << f2
		       << ", f3=" << f3 << ", f4=" << f4 << ")"  << endl;

    corr[nh-i] = - rhoA_pt*d1[nh-i] + 0.5*rhoA_pt*rhoA_pt*d2[nh-i];

    // some of the points can be reused for the next scale
    h = h0*pow(2.0,-nh+i+1);
    f1 = f2;
    f2 = f4;
  }

  // now search for a plateau that minimises fluctuations in the derivative
  int n_plateau = 4;
  double mindiff = numeric_limits<double>::max();
  int n_mindiff = -1;
  for (int iscale = n_plateau/2; iscale <= ((int) nh)-n_plateau/2+1; iscale++){
    // TO IMPROVE
    // ignore cases where one of the derivatives is zero (could this
    // get us into trouble if the derivative is genuinely zero?)
    if (corr[iscale-1] == 0 || corr[iscale] == 0 || corr[iscale+1] == 0){
      // assumes the derivative is really 0
      mindiff = 0.0;
      n_mindiff = iscale;
      break;
    }
    double diff=0;
    for (int i = -n_plateau/2+1; i <= n_plateau/2-1; i++)
      diff += abs(corr[iscale+i] - corr[iscale+i-1]);
    if (diff < mindiff){
      mindiff = diff;
      n_mindiff = iscale;
    }
  }

  // record the result of the 1st pt derivative
  _result_pt_only_1st_order = _result_unsubtracted - rhoA_pt*d1[n_mindiff];
  _result_pt_only = _result_unsubtracted + corr[n_mindiff];

  double deriv_p = d1[n_mindiff];
  double deriv_pp = d2[n_mindiff];
  double hp = h0*pow(2.0,-n_mindiff);
  if (_verbose) cout << "Using pt step " << hp << endl;

  //----------------------------------------------------------------------
  // now do the same in mt
  h = h0*pow(2.0,-nh);

  f1 = f(Rescaler(ghost_scale, h/4, ghost_scale)(jet));
  f2 = f(Rescaler(ghost_scale, h/2, ghost_scale)(jet));
  for (int i=0;i<=nh;i++){
    f3 = f(Rescaler(ghost_scale, 3*h/4, ghost_scale)(jet));
    f4 = f(Rescaler(ghost_scale, h,     ghost_scale)(jet));

    // apply a forward 5-point rule (including f0)
    d1[nh-i] = (25.0/3.0*(f1-f0) - 23.0/3.0*(f2-f1)
               +13.0/3.0*(f3-f2) -  1.0    *(f4-f3))/h;
    double s1 = (f0-f1)/h-(f1-f2)/h;
    double s2 = (f1-f2)/h-(f2-f3)/h;
    double s3 = (f2-f3)/h-(f3-f4)/h;
    d2[nh-i] = (140.0/3.0*s1-136/3.0*s2+44/3.0*s3)/h;
    if (_verbose) cout << "stepderiv " << h << " " << d1[nh-i] << " " << d2[nh-i]
		       << " (f0=" << f0 << ", f1=" << f1 << ", f2=" << f2
		       << ", f3=" << f3 << ", f4=" << f4 << ")"  << endl;

    corr[nh-i] = - rhoA_mt*d1[nh-i] + 0.5*rhoA_mt*rhoA_mt*d2[nh-i];

    // some of the points can be reused for the next scale
    h = h0*pow(2.0,-nh+i+1);
    f1 = f2;
    f2 = f4;
  }

  // now search for a plateau that minimises fluctuations in the derivative
  mindiff = numeric_limits<double>::max();
  n_mindiff = -1;
  for (int iscale = n_plateau/2; iscale <= ((int) nh)-n_plateau/2+1; iscale++){
    // ignore cases where one of the derivatives is zero (could this
    // get us into trouble if the derivative is genuinely zero?)
    if (corr[iscale-1] == 0 || corr[iscale] == 0 || corr[iscale+1] == 0){
      // assumes the derivative is really 0
      mindiff = 0.0;
      n_mindiff = iscale;
      break;
    }
    double diff=0;
    for (int i = -n_plateau/2+1; i <= n_plateau/2-1; i++)
      diff += abs(corr[iscale+i] - corr[iscale+i-1]);
    if (diff < mindiff){
      mindiff = diff;
      n_mindiff = iscale;
    }
  }

  // record the result of the 1st derivative
  _result_1st_order = _result_pt_only_1st_order - rhoA_mt*d1[n_mindiff];

  double deriv_m = d1[n_mindiff];
  double deriv_mm = d2[n_mindiff];
  double hm = h0*pow(2.0,-n_mindiff);
  if (_verbose) cout << "Using mt step " << hm << endl;


  //----------------------------------------------------------------------
  // now compute the values of the function needed for all the
  // remaining derivatives
  //
  // Her we re-compute the 4 points used for the 1st derivative. That
  // could be avoided if needed by storing all the functions computed
  // above.

  double f00 = f0;
  double f01 = f(Rescaler(ghost_scale       ,   hm/4, ghost_scale)(jet)); if(_verbose) cout << "f01: " << f01 << endl; 
  double f02 = f(Rescaler(ghost_scale       ,   hm/2, ghost_scale)(jet)); if(_verbose) cout << "f02: " << f02 << endl; 
  double f03 = f(Rescaler(ghost_scale       , 3*hm/4, ghost_scale)(jet)); if(_verbose) cout << "f03: " << f03 << endl; 
  double f04 = f(Rescaler(ghost_scale       ,   hm  , ghost_scale)(jet)); if(_verbose) cout << "f04: " << f04 << endl; 
  double f10 = f(Rescaler(ghost_scale+  hp/4, 0*hm  , ghost_scale)(jet)); if(_verbose) cout << "f10: " << f10 << endl; 
  double f11 = f(Rescaler(ghost_scale+  hp/4,   hm/4, ghost_scale)(jet)); if(_verbose) cout << "f11: " << f11 << endl; 
  double f12 = f(Rescaler(ghost_scale+  hp/4,   hm/2, ghost_scale)(jet)); if(_verbose) cout << "f12: " << f12 << endl; 
  double f13 = f(Rescaler(ghost_scale+  hp/4, 3*hm/4, ghost_scale)(jet)); if(_verbose) cout << "f13: " << f13 << endl; 
  double f20 = f(Rescaler(ghost_scale+  hp/2, 0*hm  , ghost_scale)(jet)); if(_verbose) cout << "f20: " << f20 << endl; 
  double f21 = f(Rescaler(ghost_scale+  hp/2,   hm/4, ghost_scale)(jet)); if(_verbose) cout << "f21: " << f21 << endl; 
  double f22 = f(Rescaler(ghost_scale+  hp/2,   hm/2, ghost_scale)(jet)); if(_verbose) cout << "f22: " << f22 << endl; 
  double f30 = f(Rescaler(ghost_scale+3*hp/4, 0*hm  , ghost_scale)(jet)); if(_verbose) cout << "f30: " << f30 << endl; 
  double f31 = f(Rescaler(ghost_scale+3*hp/4,   hm/4, ghost_scale)(jet)); if(_verbose) cout << "f31: " << f31 << endl; 
  double f40 = f(Rescaler(ghost_scale+  hp  , 0*hm  , ghost_scale)(jet)); if(_verbose) cout << "f40: " << f40 << endl; 

  // crossed term  
  double s00=((f11-f10)/hm-(f01-f00)/hm); if(_verbose) cout << "s00/hp: " << s00/hp << endl; 
  double s10=((f21-f20)/hm-(f11-f10)/hm); if(_verbose) cout << "s10/hp: " << s10/hp << endl; 
  double s20=((f31-f30)/hm-(f21-f20)/hm); if(_verbose) cout << "s20/hp: " << s20/hp << endl; 
  double s01=((f12-f11)/hm-(f02-f01)/hm); if(_verbose) cout << "s01/hp: " << s01/hp << endl; 
  double s11=((f22-f21)/hm-(f12-f11)/hm); if(_verbose) cout << "s11/hp: " << s11/hp << endl; 
  double s02=((f13-f12)/hm-(f03-f02)/hm); if(_verbose) cout << "s02/hp: " << s02/hp << endl; 

  double deriv_pm = (140/3.0*s00-68/3.0*(s10+s01)+16.0*(s20+s02)/3+4.0*s11)/hp;

  // 3rd derivatives (for error estimate)
  double s1 = (f00-f10)/hp-(f10-f20)/hp;
  double s2 = (f10-f20)/hp-(f20-f30)/hp;
  double s3 = (f20-f30)/hp-(f30-f40)/hp;
  double t1 = (s2-s1)/hp;
  double t2 = (s3-s2)/hp;
  double deriv_ppp = (160*t1-96*t2)/hp;

  s1 = (f00-f01)/hm-(f01-f02)/hm;
  s2 = (f01-f02)/hm-(f02-f03)/hm;
  s3 = (f02-f03)/hm-(f03-f04)/hm;
  t1 = (s2-s1)/hm;
  t2 = (s3-s2)/hm;
  double deriv_mmm = (160*t1-96*t2)/hm;

  double t00=(s10-s00)/hp;
  double t10=(s20-s10)/hp;
  double t01=(s11-s01)/hp;
  double deriv_ppm = (160*t00-64*t10-32*t01)/hm;

  t00=(s01-s00)/hm;
  t10=(s02-s01)/hm;
  t01=(s11-s10)/hm;
  double deriv_pmm = (160*t00-64*t01-32*t10)/hp;

  _estimated_error = (1.0*rhoA_pt*rhoA_pt*rhoA_pt*deriv_ppp
		     +3.0*rhoA_pt*rhoA_pt*rhoA_mt*deriv_ppm
		     +3.0*rhoA_pt*rhoA_mt*rhoA_mt*deriv_pmm
		     +1.0*rhoA_mt*rhoA_mt*rhoA_mt*deriv_mmm)/6.0;

  if (_verbose){
    cout << "1st pt derivative: " << deriv_p << endl
         << "1st mt derivative: " << deriv_m << endl
         << "2nd pt derivative: " << deriv_pp << endl
         << "pt-mt  derivative: " << deriv_pm << endl
         << "2nd mt derivative: " << deriv_mm << endl
         << "3 ppp  derivative: " << deriv_ppp << endl
         << "3 ppm  derivative: " << deriv_ppm << endl
         << "3 pmm  derivative: " << deriv_pmm << endl
         << "3 mmm  derivative: " << deriv_mmm << endl;
    cout << "res uns  : " << _result_unsubtracted << endl
         << "res pt1st: " << _result_pt_only_1st_order << endl
         << "res pt   : " << _result_pt_only << endl
         << "res 1st  : " << _result_1st_order << endl
         << "error    : " << _estimated_error << endl;
  }    

  return _result_pt_only + corr[n_mindiff] + rhoA_pt*rhoA_mt*deriv_pm;
}

// compute the function and its derivatives
// \todo: adapt the "f calls"
GenericSubtractor::FunctionAndDerivatives
GenericSubtractor::_efficient_derivatives(const FunctionOfPseudoJet<double> &f, 
                                          const PseudoJet &jet, double ghost_scale) const{

  FunctionAndDerivatives fnd;
  
  double hard_scale = jet.perp();

  // the strategy is as follows:
  //
  //  - start by computing the 1st derivative in the 1st variable. To
  //    do that, make a scan in the scale used for the computation and
  //    use the one that gives the most stable output (by looking at
  //    the stability of the result when varying the scale around that
  //    value)
  //
  //  - fix that "optimal" scale once and for all
  //
  //  - compute all the derivatives (first and second including the
  //    crossed term)
  //
  // Note that we use a 5-point rule for each computation

  //----------------------------------------------------------------------
  // compute the value of the function at the orignal point once and for all
  fnd.f = f(jet);

  //----------------------------------------------------------------------
  // do the scale swipe for the 1st derivative in x
  //
  // we need to compute the derivative using steps 
  //   h_i = 2^{-i} h0             i=0, ..., nh
  //
  // Even with a very good numerical precision, a scale of
  // h=1e-3..1e-4 gave very good results, so we shall use h0=pt,
  // nh=30 (to have a margin of security and go down to 1e-6 for pt=1000)
  //
  // For each of these stepsizes, we need to compute the derivative at
  //   x, x+h_i/4, x+h_i/2, x+3*h_i/4, x+h_i
  //
  // We start by computing the derivatives at each scale
  const int nh=30;
  const double h0 = hard_scale;

  double derivs[nh+1];
  double f0, f1, f2, f3, f4;

  double h = h0*pow(2.0,-nh);

  f0 = fnd.f; // common to all expressions
  f1 = f(Rescaler(h/4, ghost_scale, ghost_scale)(jet));
  f2 = f(Rescaler(h/2, ghost_scale, ghost_scale)(jet));
  for (int i=0;i<=nh;i++){
    f3 = f(Rescaler(3*h/4, ghost_scale, ghost_scale)(jet));
    f4 = f(Rescaler(h,     ghost_scale, ghost_scale)(jet));

    // apply a forward 5-point rule (including f0)
    derivs[nh-i] = (25.0/3.0*(f1-f0) - 23.0/3.0*(f2-f1)
                   +13.0/3.0*(f3-f2) -  1.0    *(f4-f3))/h;
    if (_verbose) cout << "stepderiv " << h << " " << derivs[nh-i] << endl;

    // some of the points can be reused for the next scale
    h = h0*pow(2.0,-nh+i+1);
    f1 = f2;
    f2 = f4;
  }

  // now search for a plateau that minimises fluctuations in the derivative
  int n_plateau = 4;
  double mindiff = numeric_limits<double>::max();
  double n_mindiff = -1;
  double deriv_final = numeric_limits<double>::max();
  for (int iscale = n_plateau/2; iscale <= ((int) nh)-n_plateau/2+1; iscale++){
    // ignore cases where one of the derivatives is zero (could this
    // get us into trouble if the derivative is genuinely zero?)
    if (derivs[iscale-1] == 0 || 
        derivs[iscale]   == 0 || 
        derivs[iscale+1] == 0){
      // assumes the derivative is really 0
      mindiff = deriv_final = 0.0;
      n_mindiff = iscale;
      break;
    }
    double diff=0;
    for (int i = -n_plateau/2+1; i <= n_plateau/2-1; i++)
      diff += abs(derivs[iscale+i] - derivs[iscale+i-1]);
    if (_verbose) cout << "scalediff: " << iscale << " " << diff << endl;
    if (diff < mindiff){
      mindiff = diff;
      deriv_final = derivs[iscale];
      n_mindiff = iscale;
    }
  }

  // record the result of the 1st derivative
  fnd.deriv_p = deriv_final;
  fnd.hp_used = h0*pow(2.0,-n_mindiff);

  double hp = fnd.hp_used; // a shorthand
  if (_verbose) cout << " ---> Using pt step " << hp << endl;

  //----------------------------------------------------------------------
  // now do the same in mt
  h = h0*pow(2.0,-nh);

  f0 = fnd.f; // common to all expressions
  f1 = f(Rescaler(ghost_scale, h/4, ghost_scale)(jet));
  f2 = f(Rescaler(ghost_scale, h/2, ghost_scale)(jet));
  for (int i=0;i<=nh;i++){
    f3 = f(Rescaler(ghost_scale, 3*h/4, ghost_scale)(jet));
    f4 = f(Rescaler(ghost_scale, h,     ghost_scale)(jet));

    // apply a forward 5-point rule (including f0)
    derivs[nh-i] = (25.0/3.0*(f1-f0) - 23.0/3.0*(f2-f1)
                   +13.0/3.0*(f3-f2) -  1.0    *(f4-f3))/h;
    if (_verbose) cout << "stepderiv " << h << " " << derivs[nh-i] << endl;

    // some of the points can be reused for the next scale
    h = h0*pow(2.0,-nh+i+1);
    f1 = f2;
    f2 = f4;
  }

  // now search for a plateau that minimises fluctuations in the derivative
  mindiff = numeric_limits<double>::max();
  n_mindiff = -1;
  deriv_final = numeric_limits<double>::max();
  for (int iscale = n_plateau/2; iscale <= ((int) nh)-n_plateau/2+1; iscale++){
    // ignore cases where one of the derivatives is zero (could this
    // get us into trouble if the derivative is genuinely zero?)
    if (derivs[iscale-1] == 0 || 
        derivs[iscale]   == 0 || 
        derivs[iscale+1] == 0){
      // assumes the derivative is really 0
      mindiff = deriv_final = 0.0;
      n_mindiff = iscale;
      break;
    }
    double diff=0;
    for (int i = -n_plateau/2+1; i <= n_plateau/2-1; i++)
      diff += abs(derivs[iscale+i] - derivs[iscale+i-1]);
    if (_verbose) cout << "scalediff: " << iscale << " " << diff << endl;
    if (diff < mindiff){
      mindiff = diff;
      deriv_final = derivs[iscale];
      n_mindiff = iscale;
    }
  }

  // record the result of the 1st derivative
  fnd.deriv_m = deriv_final;
  fnd.hm_used = h0*pow(2.0,-n_mindiff);

  double hm = fnd.hm_used; // a shorthand
  if (_verbose) cout << " ---> Using mt step " << hm << endl;


  //----------------------------------------------------------------------
  // now compute the values of the function needed for all the
  // remaining derivatives
  //
  // Her we re-compute the 4 points used for the 1st derivative. That
  // could be avoided if needed by storing all the functions computed
  // above.

  double f00 = f(Rescaler(ghost_scale       , ghost_scale       , ghost_scale)(jet));
  double f01 = f(Rescaler(ghost_scale       , ghost_scale+  hm/4, ghost_scale)(jet));
  double f02 = f(Rescaler(ghost_scale       , ghost_scale+  hm/2, ghost_scale)(jet));
  double f03 = f(Rescaler(ghost_scale       , ghost_scale+3*hm/4, ghost_scale)(jet));
  double f04 = f(Rescaler(ghost_scale       , ghost_scale+  hm  , ghost_scale)(jet));
  double f10 = f(Rescaler(ghost_scale+  hp/4, ghost_scale       , ghost_scale)(jet));
  double f11 = f(Rescaler(ghost_scale+  hp/4, ghost_scale+  hm/4, ghost_scale)(jet));
  double f12 = f(Rescaler(ghost_scale+  hp/4, ghost_scale+  hm/2, ghost_scale)(jet));
  double f13 = f(Rescaler(ghost_scale+  hp/4, ghost_scale+3*hm/4, ghost_scale)(jet));
  double f20 = f(Rescaler(ghost_scale+  hp/2, ghost_scale       , ghost_scale)(jet));
  double f21 = f(Rescaler(ghost_scale+  hp/2, ghost_scale+  hm/4, ghost_scale)(jet));
  double f22 = f(Rescaler(ghost_scale+  hp/2, ghost_scale+  hm/2, ghost_scale)(jet));
  double f30 = f(Rescaler(ghost_scale+3*hp/4, ghost_scale       , ghost_scale)(jet));
  double f31 = f(Rescaler(ghost_scale+3*hp/4, ghost_scale+  hm/4, ghost_scale)(jet));
  double f40 = f(Rescaler(ghost_scale+  hp  , ghost_scale       , ghost_scale)(jet));

  //// 1st deriv in y
  //fnd.deriv_m = (25.0/3.0*(f01-f00)-23.0/3.0*(f02-f01)+13.0/3.0*(f03-f02)-(f04-f03))/h;
  
  // 2nd deriv in x
  double s1 = (f00-f10)/hp-(f10-f20)/hp;
  double s2 = (f10-f20)/hp-(f20-f30)/hp;
  double s3 = (f20-f30)/hp-(f30-f40)/hp;
  fnd.deriv_pp = (140.0/3.0*s1-136/3.0*s2+44/3.0*s3)/hp;

  // 3rd derivative (for error estimate)
  double t1 = (s2-s1)/hp;
  double t2 = (s3-s2)/hp;
  fnd.deriv_ppp = (160*t1-96*t2)/hp;

  // 2nd deriv in y
  s1 = (f00-f01)/hm-(f01-f02)/hm;
  s2 = (f01-f02)/hm-(f02-f03)/hm;
  s3 = (f02-f03)/hm-(f03-f04)/hm;
  fnd.deriv_mm = (140.0/3.0*s1-136/3.0*s2+44/3.0*s3)/hm;

  // 3rd derivative (for error estimate)
  t1 = (s2-s1)/hm;
  t2 = (s3-s2)/hm;
  fnd.deriv_mmm = (160*t1-96*t2)/hm;

  // crossed term  
  double s00=((f11-f10)/hm-(f01-f00)/hm);
  double s10=((f21-f20)/hm-(f11-f10)/hm);
  double s20=((f31-f30)/hm-(f21-f20)/hm);
  double s01=((f12-f11)/hm-(f02-f01)/hm);
  double s11=((f22-f21)/hm-(f12-f11)/hm);
  double s02=((f13-f12)/hm-(f03-f02)/hm);

  fnd.deriv_pm = (140/3.0*s00-68/3.0*(s10+s01)+16.0*(s20+s02)/3+4.0*s11)/hp;

  // 3rd derivative (for error estimate)
  double t00=(s10-s00)/hp;
  double t10=(s20-s10)/hp;
  double t01=(s11-s01)/hp;
  fnd.deriv_ppm = (160*t00-64*t10-32*t01)/hm;

  t00=(s01-s00)/hm;
  t10=(s02-s01)/hm;
  t01=(s11-s10)/hm;
  fnd.deriv_pmm = (160*t00-64*t01-32*t10)/hp;

  return fnd;
}

FASTJET_END_NAMESPACE
