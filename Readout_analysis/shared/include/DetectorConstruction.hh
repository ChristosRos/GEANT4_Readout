//Readout construction 

#ifndef DetectorConstruction_h 
#define DetectorConstruction_h 1 

#include "globals.hh" 
#include "G4VUserDetectorConstruction.hh"

class G4Box;
class G4VPhysicalVolume;
class G4LogicalVolume; 
class G4Material; 
class G4UserLimits;
class DetectorMessenger; 

class DetectorConstruction : public G4VUserDetectorConstruction
{
    public: 
        DetectorConstruction(); 
        virtual ~DetectorConstruction(); 

    public: 
        
        // Set methods 
        void SetTargetMaterial (G4String ); 
        void SetTargetThickness (G4double );

        void SetNbOfLayers (G4int);
        //void SetReadoutMaterial(G4String);
        void SetROSizeXY(G4double);

        virtual G4VPhysicalVolume* Construct(); 
 
    public:
        void PrintROParameters();

        G4double GetWorldSizeXY()   {return fWorldSizeXY;};
        G4double GetWorldSizeZ()    {return fWorldSizeZ;};

        G4double GetROThickness()   {return fROThickness;};
        G4double GetROSizeXY()      {return fROSizeXY;};

        G4int GetNbOfLayers()       {return fNbOfStrips;};

        //G4Material* GetReadoutMaterial() {return fReadoutMaterial;};
        G4Material* GetStripMaterial() {return fStripMaterial;};
        G4double    GetStripThickness() {return fStripThickness;};

        const G4VPhysicalVolume* GetPhysiWorld() {return fPhysiWorld;};
        const G4VPhysicalVolume* GetStrips()     {return fPhysiStrip;};        


   private: 
    

        G4Material* fStripMaterial;
        G4double    fStripThickness;


        //G4Material* fReadoutMaterial;
        //G4double    fReadoutThickness;

        G4int       fNbOfStrips;

        G4double    fROSizeXY;
        G4double    fROThickness;

        G4Material* fDefaultMaterial;
        G4double    fWorldSizeXY;
        G4double    fWorldSizeZ;

        G4Box*             fSolidWorld;  // pointer to the solid World
        G4LogicalVolume*   fLogicWorld;  // pointer to the logical World
        G4VPhysicalVolume* fPhysiWorld;  // pointer to the physical WOrld

        G4Box*              fSolidRO;    // pointer to the solid Readout
        G4LogicalVolume*    fLogicRO;    // pointer to the logical Readout
        G4VPhysicalVolume*   fPhysiRO;    // pointer to the physical Readout

        G4Box*              fSolidStrip;  // pointer to the solid strip 
        G4LogicalVolume*    fLogicStrip;  // pointer to the logical strip x
        G4VPhysicalVolume*  fPhysiStrip;  // pointer to the physical strip 


// Added a new way in order to glue everything together and let's see what happens .##########
        //G4Box*              fSolidDetector; //pointer to the unified detector
        //G4LogicalVolume*    fLogicDetector; //point to the logical detector
        //G4VPhysicalVolume*  fPhysiDetector; // pointer to the physical detector (RO+strips)
//##################-------------------------------#########------#######-------#####

        DetectorMessenger*  fDetectorMessenger;   //pointer to the Messenger

    private: 

        void DefineMaterials();
        void ComputeROParameters();
        G4VPhysicalVolume* ConstructRO(); 
};


inline void DetectorConstruction::ComputeROParameters()
{
    // Compute derived parameters of the calorimeter
    fROThickness = fROThickness + fStripThickness;

    fWorldSizeZ = 5*fROThickness;
    fWorldSizeXY = 3*fROSizeXY;
}

#endif