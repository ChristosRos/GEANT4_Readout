#include "RORunAction.hh" 

#include "G4Run.hh" 
#include "G4RunManager.hh" 

RORunAction::RORunAction()
: G4UserRunAction()
{
    // set printing event number per each 100 events
    G4RunManager::GetRunManager()->SetPrintProgress(1000);
}

RORunAction::~RORunAction()
{}

void RORunAction::BeginOfRunAction(const G4Run*)
{
    // inform the runManager to save random number seed 
    G4RunManager::GetRunManager()->SetRandomNumberStore(false);
}

void RORunAction::EndOfRunAction(const G4Run*)
{}