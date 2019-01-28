//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "EventAction.hh"

#include "RunAction.hh"
#include "HistoManager.hh"

#include "G4Event.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

EventAction::EventAction(RunAction* run, HistoManager* histo)
:G4UserEventAction(),
 fRunAct(run),fHistoManager(histo),
 fEnergyAbs(0.),
 fTrackLAbs(0.),
 fPrintModulo(0)                             
{
 fPrintModulo = 100; }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

EventAction::~EventAction()
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void EventAction::BeginOfEventAction(const G4Event* evt)
{  
  G4int evtNb = evt->GetEventID();
  if (evtNb%fPrintModulo == 0) 
    G4cout << "\n---> Begin of event: " << evtNb << G4endl;
 
 // initialisation per event
 fEnergyAbs = 0.;
 fTrackLAbs = 0.;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void EventAction::EndOfEventAction(const G4Event*)
{
  //accumulates statistic
  //
  fRunAct->FillPerEvent(fEnergyAbs, fTrackLAbs);
  
  //fill histograms
  //
  fHistoManager->FillHisto(0, fEnergyAbs);
  fHistoManager->FillHisto(1, fTrackLAbs);
  
  //fill ntuple
  //
  fHistoManager->FillNtuple(fEnergyAbs, fTrackLAbs);
}  

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
