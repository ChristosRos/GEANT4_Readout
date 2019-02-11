//.........ooooooOOOOOOOOOOooooooOOOOOOOOOooooooooo.......//
#ifndef DetectorConstruction_h
#define DetectorConstruction_h

#include "G4VUserDetectorConstruction.hh"
#include "SteppingAction.hh" 

class DetectorConstruction: public G4VUserDetectorConstruction
{ 
    public: 
        DetectorConstruction();
        virtual ~DetectorConstruction();

        G4VPhysicalVolume* Construct();

        static G4double sizeX; 
        static G4double sizeY;


};

#endif