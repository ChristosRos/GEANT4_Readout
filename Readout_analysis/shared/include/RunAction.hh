#ifndef RunAction_h
#define RunAction_h 1

#include "G4UserRunAction.hh"
#include "globals.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class G4Run;
class HistoManager;

class RunAction : public G4UserRunAction
{
public:
  RunAction(HistoManager*);
  virtual ~RunAction();

  virtual void BeginOfRunAction(const G4Run*);
  virtual void   EndOfRunAction(const G4Run*);
    
  void FillPerEvent(G4double, G4double); 

private:
  HistoManager* fHistoManager;

  G4double fSumEAbs, fSum2EAbs;
    
  G4double fSumLAbs, fSum2LAbs;    
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

