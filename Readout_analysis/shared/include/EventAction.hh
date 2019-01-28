//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#ifndef EventAction_h
#define EventAction_h 1

#include "G4UserEventAction.hh"
#include "globals.hh"

class RunAction;
class HistoManager;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class EventAction : public G4UserEventAction
{
public:
  EventAction(RunAction*, HistoManager*);
  virtual ~EventAction();

  virtual void  BeginOfEventAction(const G4Event*);
  virtual void    EndOfEventAction(const G4Event*);
    
  void AddAbs(G4double de, G4double dl) {fEnergyAbs += de; fTrackLAbs += dl;};
  
    
private:
   RunAction*    fRunAct;
   HistoManager* fHistoManager;
      
   G4double  fEnergyAbs;
   G4double  fTrackLAbs;
                     
   G4int     fPrintModulo;                             
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif