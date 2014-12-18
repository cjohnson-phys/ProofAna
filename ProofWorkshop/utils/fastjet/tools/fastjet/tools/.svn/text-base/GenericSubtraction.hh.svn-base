#ifndef __FASTJET_GENERIC_SUBTRACTION_HH__
#define __FASTJET_GENERIC_SUBTRACTION_HH__

#include <iomanip>
#include <fastjet/FunctionOfPseudoJet.hh>
#include <fastjet/tools/JetMedianBackgroundEstimator.hh>

namespace fastjet{

/// a subtractor for a generic observable
///
/// Assuming the jet has a hard (h) and background (b) component. For
/// a pt-dependent quantity we use
///   f(h+b) = f(h) + rho * A * ghost_area * df/d(ghost_scale)
/// 
/// Then we want the "dt=mt-pt" dependence. For that, we'd need to
/// keep the pt fixed and vary dt.
///   dt = mt-pt = sqrt(m^2+pt^2)-pt
///     => (dt+pt)^2 = m^2 + pt^2
///     => m = sqrt((dt+pt)^2 - pt^2)
///          = sqrt(dt (dt+2 pt))
class GenericSubtractor{
public: 
  /// empty ctor (useless)
  GenericSubtractor() : _bge(0), _verbose(false){};
  
  /// ctor with background info
  GenericSubtractor(JetMedianBackgroundEstimator *bge)
    : _bge(bge), _verbose(false){};

  /// description
  std::string description() const{ return "generic subtractor";}
  
  /// subtract a given FOfPJ for a given jet
  double operator()(const FunctionOfPseudoJet<double> &f, 
                    const PseudoJet &jet) const;

  // get a few intermediate steps FROM THE LAST CALL
  double result_unsubtracted() const{ return _result_unsubtracted;}
  double result_pt_only() const{ return _result_pt_only;}
  double result_1st_order() const{ return _result_1st_order;}
  double result_pt_only_1st_order() const{ return _result_pt_only_1st_order;}
  double estimated_error() const{ return _estimated_error;}

  void set_verbose(bool verbose=true){ _verbose=verbose;}

protected:
  class FunctionAndDerivatives{
  public:
    double f;
    double deriv_p, deriv_m;
    double deriv_pp, deriv_pm, deriv_mm;
    double deriv_ppp, deriv_ppm, deriv_pmm, deriv_mmm;
    double hp_used, hm_used;
  };

  /// compute the function and its derivatives
  FunctionAndDerivatives
  _efficient_derivatives(const FunctionOfPseudoJet<double> &f,
                         const PseudoJet &jet,
                         double ghost_scale) const;

private:
  //BackgroundEstimatorBase *_bge;
  JetMedianBackgroundEstimator *_bge;
  BackgroundJetPtMDensity m_density;

  bool _verbose;

  // access to intermediate results
  mutable double _result_unsubtracted;
  mutable double _result_pt_only;
  mutable double _result_1st_order;
  mutable double _result_pt_only_1st_order;
  mutable double _estimated_error;
};

}

#endif // __FASTJET_GENERIC_SUBTRACTION_HH__
