//Construction of the Readout attempt2

#include "RODetectorConstruction.hh" 
#include "ROReadoutSD.hh"

#include "G4Material.hh"
#include "G4NistManager.hh" 
#include "G4SDManager.hh" 
#include "G4LogicalVolume.hh"

#include "G4Box.hh" 
#include "G4VSolid.hh"
#include "G4SubtractionSolid.hh"
#include "G4IntersectionSolid.hh"
#include "G4PVPlacement.hh"
#include "G4Transform3D.hh"

#include "G4VisAttributes.hh"
#include "G4GDMLParser.hh" 
#include "G4LogicalVolumeStore.hh"

#include "G4GeometryManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4PSEnergyDeposit.hh"
#include "G4PhysicalConstants.hh"
#include "G4RotationMatrix.hh"
#include "G4UserLimits.hh"
#include "G4UnitsTable.hh"

RODetectorConstruction::RODetectorConstruction()
:G4VUserDetectorConstruction(),
fNbOfReadout(0),
fLogicTarget(NULL), fLogicReadout(NULL),
fTargetMaterial(NULL), fReadoutMaterial(NULL),
fStepLimit(NULL),
fCheckOverlaps(true)
{
    fNbOfReadout = 1;
    fLogicReadout = new G4LogicalVolume*[fNbOfReadout];    
}

RODetectorConstruction::~RODetectorConstruction()
{  
    delete [] fLogicReadout;
    delete fStepLimit;
}


G4VPhysicalVolume* RODetectorConstruction::Construct()
{
    //Define Materials
    DefineMaterials();

    //Define Volumes
    return DefineVolumes();
}

void RODetectorConstruction::DefineMaterials()
{
    //Material Definition

    G4NistManager* nistManager = G4NistManager::Instance();

    // Air define using NIST Manager
    nistManager->FindOrBuildMaterial("G4_AIR");

    // Copper Defined using NIST Manager
    fTargetMaterial = nistManager->FindOrBuildMaterial("G4_Cu");

    // Lead Defined using NIST Manager
    fReadoutMaterial = nistManager->FindOrBuildMaterial("G4_Pb");

    //Print Materials
    G4cout << *(G4Material::GetMaterialTable()) << G4endl;
}

G4VPhysicalVolume* RODetectorConstruction::DefineVolumes()
{
    G4Material* air = G4Material::GetMaterial("G4_AIR");

    //Sizes of the principal geometrical components (solids) 

    //Build the World 

    G4double WorldSizeX = 50*cm;  
    G4double WorldSizeY = 50*cm;
    G4double WorldSizeZ = 50*cm;

    G4double worldLength = 1.2 * WorldSizeX ; 
    G4GeometryManager::GetInstance()->SetWorldMaximumExtent(worldLength);

    //Creates the World Box
    G4Box* WorldBox = new G4Box("world", //its name
                                 WorldSizeX, //x coordinate
                                 WorldSizeY, //y coordinate
                                 WorldSizeZ); //z coordinate

    //Must place the World Physical volume unrotated at (0,0,0),
    //
    //Create the Logical Volume
    G4LogicalVolume* WorldLog = new G4LogicalVolume(WorldBox,    //Implement the created WorldBox
                                                    air, //define the material of the world
                                                    "World"); //its name

    
    //Create the physical Volume
    G4VPhysicalVolume* WorldPhys = 
        new G4PVPlacement(0,                 //no rotation
                          G4ThreeVector(),   //at (0,0,0)
                          WorldLog,          //Its logical Volume
                          "World",      //Its name
                          0,                //its mother volume
                          false,            //no boolean operation
                          0,
                          fCheckOverlaps);  //checking overlaps 

    //Set Visual Attributes
    G4VisAttributes *worldAttributes = new G4VisAttributes; 
    worldAttributes->SetVisibility(false);
    WorldLog->SetVisAttributes(worldAttributes);


    //Create the FR4 
    G4double frX = 30*cm; 
    G4double frY = 30*cm;
    G4double frZ = 0.15*cm;

    G4Box* FRPCB = new G4Box("PCB", //it name
                             frX,   // x dimension
                             frY,   // y dimension
                             frZ);  // z dimension

    G4LogicalVolume* FRPCBLog = new G4LogicalVolume(FRPCB,  //takes the volume that was created
                                                    fReadoutMaterial,     //the material (FR4)
                                                     "PCBLog"); //its name

    G4double FRposition = 0.005*mm;
    //Place the FR4 in the world
    new G4PVPlacement(0,                     //no rotation
                      G4ThreeVector(0,0,FRposition),       //at (0,0,0)
                      FRPCBLog,               //its logical world
                      "PCBFR",              //its name
                      WorldLog,              //its mothervolume
                      false,                 //no boolean operator
                      0,
                      fCheckOverlaps);       //checking for overlaps

    //Define the colour of the PCB
    G4VisAttributes* green = new G4VisAttributes(G4Colour::Green());
    green->SetVisibility(true);
    green->SetForceSolid(true);
    FRPCBLog->SetVisAttributes(green);


    //Create the Strips
    G4double Strip_dX = 1*cm; 
    G4double Strip_dY = 17*cm;
    G4double Strip_dZ = 0.05*cm;
    G4double gap = 1.5*cm;

    G4Box* Strip = new G4Box("Strip",   //its name
                             Strip_dX,  //x dimension
                             Strip_dY,  //y dimension
                             Strip_dZ); //z dimension

    G4LogicalVolume* StripLog = new G4LogicalVolume(Strip,
                                                    fTargetMaterial,
                                                    "StripLog");

    G4int nb_Strips = 10;

    //Place strips on the PCB
    for(G4int istrip = 0; istrip < nb_Strips; istrip++)
    {
        G4double dX = istrip*(Strip_dX + gap)-11*cm;
        G4double dY = istrip*(Strip_dX + gap)-11*cm;
        G4RotationMatrix rotm = G4RotationMatrix();
        rotm.rotateZ(60*deg);
        //rotm.rotateX(60*deg);
        G4ThreeVector position = G4ThreeVector(dX,dY,-frZ);
        G4Transform3D transform = G4Transform3D(rotm,position);


        new G4PVPlacement(transform,                // no rotation
                          StripLog,
                          "StripPhys",
                          FRPCBLog,          //its mother volume
                          false,             //no boolean operatos
                          istrip,            //copy number
                          fCheckOverlaps);   //checking overlaps
                          
        G4double mindX = istrip*(Strip_dX + gap)-11*cm;
        G4double mindY = istrip*(-Strip_dX -gap)+11*cm;
        //G4double mindY = 10*cm;
        G4RotationMatrix minrotm = G4RotationMatrix();
        minrotm.rotateZ(-60*deg);
        G4ThreeVector minposition = G4ThreeVector(mindX,mindY+0.2*cm,-frZ);
        G4Transform3D mintransform = G4Transform3D(minrotm,minposition);

        new G4PVPlacement(mintransform,                // no rotation
                          StripLog,
                          "minStripPhys",
                          FRPCBLog,          //its mother volume
                          false,             //no boolean operatos
                          istrip,            //copy number
                          fCheckOverlaps);   //checking overlaps
    }


    //Define the colour of the Strips
    G4VisAttributes* silver = new G4VisAttributes(G4Colour::Grey());
    silver->SetVisibility(true);
    silver->SetForceSolid(true);
    StripLog->SetVisAttributes(silver);
    
    return WorldPhys;
}


void RODetectorConstruction::SetTargetMaterial(G4String materialName)
{
    G4NistManager* nistManager = G4NistManager::Instance();

    G4Material* pttoMaterial = 
                    nistManager->FindOrBuildMaterial(materialName);

    if (fTargetMaterial != pttoMaterial) { 
        if (pttoMaterial) {
            fTargetMaterial = pttoMaterial;
            if (fLogicTarget) fLogicTarget->SetMaterial(fTargetMaterial);
             G4cout 
                << G4endl 
                << "----> The target is made of " << materialName << G4endl;
        }else {
            G4cout 
                << G4endl 
                << "-->  WARNING from SetTargetMaterial : "
                << materialName << " not found" << G4endl;
        }
    }
}

void RODetectorConstruction::SetReadoutMaterial(G4String materialName)
{
  G4NistManager* nistManager = G4NistManager::Instance();

  G4Material* pttoMaterial =
              nistManager->FindOrBuildMaterial(materialName);

  if (fReadoutMaterial != pttoMaterial) {
     if ( pttoMaterial ) {
        fReadoutMaterial = pttoMaterial;
        for (G4int copyNo=0; copyNo<fNbOfReadout; copyNo++) {
            if (fLogicReadout[copyNo]) fLogicReadout[copyNo]->
                                               SetMaterial(fReadoutMaterial);
        }
        G4cout 
          << G4endl 
          << "----> The chambers are made of " << materialName << G4endl;
     } else {
        G4cout 
          << G4endl 
          << "-->  WARNING from SetChamberMaterial : "
          << materialName << " not found" << G4endl;
     }
  }
}

void RODetectorConstruction::SetMaxStep(G4double maxStep)
{
    if ((fStepLimit)&&(maxStep>0.)) fStepLimit->SetMaxAllowedStep(maxStep);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void RODetectorConstruction::SetCheckOverlaps(G4bool checkOverlaps)
{
  fCheckOverlaps = checkOverlaps;
}  

