#include "ROActionInitialization.hh"
#include "ROPrimaryGeneratorAction.hh"
#include "RORunAction.hh"
#include "ROEventAction.hh" 

ROActionInitialization::ROActionInitialization()
 : G4VUserActionInitialization()
 {}

 ROActionInitialization::~ROActionInitialization()
 {}

 void ROActionInitialization::BuildForMaster() const 
 {
     SetUserAction(new RORunAction);
 }

 void ROActionInitialization::Build() const 
 {
     SetUserAction(new ROPrimaryGeneratorAction);
     SetUserAction(new RORunAction);
     SetUserAction(new ROEventAction);
 }