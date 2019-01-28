#include "DetectorMessenger.hh"
#include "DetectorConstruction.hh" 

#include "G4tgbDetectorConstruction.hh"
#include "G4UIdirectory.hh"
#include "G4UIcmdWithAString.hh"
#include "G4Box.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"


DetectorMessenger::DetectorMessenger( DetectorConstruction* Det)
: G4UImessenger(),
 fDetector(Det),
 fR01Dir(0),
 fDetDir(0),
 fAbsMaterCmd(0)
 {
     fR01Dir = new G4UIdirectory(" /Readout01/");
     fR01Dir->SetGuidance("UI commands of this analysis"); 

     G4bool broadcast = false; 
     fDetDir = new G4UIdirectory(" /Readout01/det/",broadcast); 
     fDetDir->SetGuidance("detector control"); 

     fAbsMaterCmd = new G4UIcmdWithAString(" /Readout01/det/setGapMat", this); 
     fAbsMaterCmd->SetGuidance("Select Material of the Absorber.");
     fAbsMaterCmd->SetParameterName("choice",false);
     fAbsMaterCmd->AvailableForStates(G4State_PreInit,G4State_Idle);
 }

 DetectorMessenger::~DetectorMessenger()
 {
     delete fAbsMaterCmd;
     delete fDetDir;   
     delete fR01Dir;
 }

 void DetectorMessenger::SetNewValue(G4UIcommand* command, G4String newValue)
 {
     if ( command == fAbsMaterCmd )
     { fDetector->SetTargetMaterial(newValue); }
 }

 