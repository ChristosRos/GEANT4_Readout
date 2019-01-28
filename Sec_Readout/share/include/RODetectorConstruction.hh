#ifndef RODetectorConstruction_h 
#define RODetectorConstruction_h 1 


#include "G4VUserDetectorConstruction.hh" 

#include "globals.hh"

class G4VPhysicalVolume;
class G4LogicalVolume; 
class G4Material; 
class G4UserLimits; 

#include <list> 
#include <string>
#include <cmath> 

#include "G4RotationMatrix.hh"  
#include "G4ThreeVector.hh" 
#include "G4ProductionCuts.hh" 
#include "G4Region.hh"
#include "G4Trd.hh" 


class RODetectorConstruction : public G4VUserDetectorConstruction
{
    public: 
        RODetectorConstruction(); 
        virtual ~RODetectorConstruction();

    public: 
        virtual G4VPhysicalVolume* Construct();

        //Set methods 
        void SetTargetMaterial (G4String );
        void SetReadoutMaterial (G4String ); 
        void SetMaxStep (G4double ); 
        void SetCheckOverlaps (G4bool ); 

    private:
        //methods 
        void DefineMaterials();
        G4VPhysicalVolume* DefineVolumes();

        //data members
        G4int fNbOfReadout;
        G4LogicalVolume* fLogicTarget; //pointer to the logical Target
        G4LogicalVolume** fLogicReadout; //pointer to the logical chamber

        G4Material* fTargetMaterial;  // pointer to the target material 
        G4Material* fReadoutMaterial; //pointer to the chamber material

        G4UserLimits* fStepLimit; //pointer to use step limits


        G4bool fCheckOverlaps; //option to activate checking of volumes overlaps
};

#endif