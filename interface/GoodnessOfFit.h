#ifndef HiggsAnalysis_CombinedLimit_GoodnessOfFit_h
#define HiggsAnalysis_CombinedLimit_GoodnessOfFit_h
/** \class GoodnessOfFit
 *
 * Do a ML fit of the data with background and signal+background hypothesis and print out diagnostics plots 
 *
 * \author Giovanni Petrucciani (UCSD)
 *
 *
 */
#ifndef ROOT_Rtypes
#include "Rtypes.h"
#endif

#include "../interface/LimitAlgo.h"
#include "../interface/ProfileLikelihood.h"

class GoodnessOfFit : public LimitAlgo {
public:
  GoodnessOfFit() ;
  virtual bool run(RooWorkspace *w, RooStats::ModelConfig *mc_s, RooStats::ModelConfig *mc_b, RooAbsData &data, double &limit, double &limitErr, const double *hint);
  virtual const std::string & name() const {
    static const std::string name("GoodnessOfFit");
    return name;
  }
  virtual void applyOptions(const boost::program_options::variables_map &vm) ;

  virtual bool runSaturatedModel(RooWorkspace *w, RooStats::ModelConfig *mc_s, RooStats::ModelConfig *mc_b, RooAbsData &data, double &limit, double &limitErr, const double *hint);
  virtual bool runAndeDarlKolmSmir(RooWorkspace *w, RooStats::ModelConfig *mc_s, RooStats::ModelConfig *mc_b, RooAbsData &data, double &limit, double &limitErr, const double *hint, bool kolmo);

  void initKS(RooStats::ModelConfig *mc_s);

  double EvaluateADDistance(RooAbsPdf& pdf, RooAbsData& data, RooRealVar& observable, bool kolmo);
 
protected:
  static std::string algo_;

  static std::string minimizerAlgo_;
  static float       minimizerTolerance_;
  static int         minimizerStrategy_;

  static float mu_;
  static bool  fixedMu_;
  static bool  makePlots_;
  static TDirectory *plotDir_;

  static std::vector<std::string>  binNames_;
  static std::vector<float>        qVals_;


  // Return a pdf that matches this data perfectly.
  RooAbsPdf *makeSaturatedPdf(RooAbsData &data);
  mutable std::vector<RooAbsData*> tempData_;

};


#endif
