#include "ROActionInitialization.hh"
#include "HistoManager.hh"
#include "ROPrimaryGeneratorAction.hh"
#include "RORunAction.hh"
//#include "ROEventAction.hh" 

ROActionInitialization::ROActionInitialization(RODetectorConstruction* detector)
 : G4VUserActionInitialization()
 {}

 ROActionInitialization::~ROActionInitialization()
 {}

 void ROActionInitialization::BuildForMaster() const 
 {
     //Histo Manager
     HistoManager* histo = new HistoManager();

     //Actions
     SetUserAction(new RORunAction(histo));
 }

 void ROActionInitialization::Build() const 
 {
     // Histo Manager
     HistoManager* histo = new HistoManager(); 


     SetUserAction(new ROPrimaryGeneratorAction(fDetector));

     RORunAction* runAction = new RORunAction(histo);
     SetUserAction(runAction);
     //SetUserAction(new ROEventAction);
 }