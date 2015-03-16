#ifndef ALIMULTEVENTCLASSIFIER_H
#define ALIMULTEVENTCLASSIFIER_H
#include <TNamed.h>
class TList;
class TH2;
class TArrayD;
class AliAODMultEventClass;
class AliESDEvent;
class AliPPVsMultUtils;

/** 
 * Collect different types of mulitplicity event classifiers
 * 
 * See 
 * - https://aliceinfo.cern.ch/Notes/node/362
 * 
 */
class AliMultEventClassifier : public TNamed
{
public:
  /** 
   * Default constructor - only for ROOT I/O
   */
  AliMultEventClassifier()
    : TNamed(),
      fUtil(0),
      fMax(0),
      fList(0),
      fCorrV0M(0),
      fCorrV0A(0),
      fCorrV0C(0),
      fCorrV0MEq(0),
      fCorrV0AEq(0),
      fCorrV0CEq(0),
      fMultCND(0),
      fMultV0M(0),
      fMultV0A(0),
      fMultV0C(0),
      fMultV0MEq(0),
      fMultV0AEq(0),
      fMultV0CEq(0)
  {}
  /** 
   * Constructor 
   */
  AliMultEventClassifier(const char*)
    : TNamed("multEventClass", "Classifier of pp events"),
      fUtil(0),
      fMax(0),
      fList(0),
      fCorrV0M(0),
      fCorrV0A(0),
      fCorrV0C(0),
      fCorrV0MEq(0),
      fCorrV0AEq(0),
      fCorrV0CEq(0),
      fMultCND(0),
      fMultV0M(0),
      fMultV0A(0),
      fMultV0C(0),
      fMultV0MEq(0),
      fMultV0AEq(0),
      fMultV0CEq(0)
  {}
  /** 
   * Copy constructor 
   * 
   * @param o Object to copy from 
   */
  AliMultEventClassifier(const AliMultEventClassifier& o)
    : TNamed(o),
      fUtil(0),
      fMax(0),
      fList(0),
      fCorrV0M(0),
      fCorrV0A(0),
      fCorrV0C(0),
      fCorrV0MEq(0),
      fCorrV0AEq(0),
      fCorrV0CEq(0),
      fMultCND(0),
      fMultV0M(0),
      fMultV0A(0),
      fMultV0C(0),
      fMultV0MEq(0),
      fMultV0AEq(0),
      fMultV0CEq(0)
  {}
  /** 
   * Assignement operator 
   * 
   * @param o Object to assign from 
   * 
   * @return Reference to this 
   */
  AliMultEventClassifier& operator=(const AliMultEventClassifier& o)
  {
    return *this;
  }
  /** 
   * Create our output histograms and store in list 
   * 
   * @param l Parent list
   */
  void CreateOutputObjects(TList* l);
  /** 
   * Process an event
   * 
   * @param esd  ESD event 
   * @param data Output data
   */
  void Process(AliESDEvent* esd,
	       AliAODMultEventClass* data);
    
protected:
  /** 
   * Get a centrality from both algorithms, histogram, and store 
   * 
   * @param esd   Event
   * @param data  Output 
   * @param mult  Reference multiplicity
   * @param which Which centrality estimator 
   */
  void GetCentrality(AliESDEvent* esd,
		     AliAODMultEventClass* data,
		     Int_t        mult,
		     UShort_t     which);
  /** 
   * Get the name of a centrality estimator 
   * 
   * @param which The estimator 
   * 
   * @return Name of estimator or null
   */
  const char* GetCentName(UShort_t which) const;
  /** 
   * Get the correlation histogram
   * 
   * @param which Which estimator 
   * 
   * @return Pointer to histogram or null
   */
  TH2* GetCorr(UShort_t which) const;
  /** 
   * Get the reference multiplicity versus centrality estimator histogram
   * 
   * @param which Which estimator 
   * 
   * @return Pointer to histogram or null
   */
  TH2* GetVs(UShort_t which) const;
  /** 
   * Maek correation histogram
   * 
   * @param which Centrlaity estimator 
   * 
   * @return histogram or null
   */
  TH2*  MakeCorr(UShort_t which);
  /** 
   * Make a reference multiplicity versus centrality estimator histogram
   * 
   * @param which Which estimator 
   * 
   * @return Pointer to histogram or null
   */
  TH2*  MakeVs(UShort_t which, const TArrayD& bins);
  AliPPVsMultUtils* fUtil;
  UInt_t fMax;         // 
  TList* fList;        // Container of output object
  TH2*   fCorrV0M;     // Correlation of V0M estimator 
  TH2*   fCorrV0A;     // Correlation of V0A estimator 
  TH2*   fCorrV0C;     // Correlation of V0C estimator 
  TH2*   fCorrV0MEq;   // Correlation of V0MEq estimator 
  TH2*   fCorrV0AEq;   // Correlation of V0AEq estimator 
  TH2*   fCorrV0CEq;   // Correlation of V0CEq estimator 
  TH2*   fMultCND;     // Reference Mult vs V0M estimator 
  TH2*   fMultV0M;     // Reference Mult vs V0M estimator 
  TH2*   fMultV0A;     // Reference Mult vs V0A estimator 
  TH2*   fMultV0C;     // Reference Mult vs V0C estimator 
  TH2*   fMultV0MEq;   // Reference Mult vs V0MEq estimator 
  TH2*   fMultV0AEq;   // Reference Mult vs V0AEq estimator 
  TH2*   fMultV0CEq;   // Reference Mult vs V0CEq estimator

  ClassDef(AliMultEventClassifier,1);
};

#endif
// Local Variables:
//   mode: C++
// End:



