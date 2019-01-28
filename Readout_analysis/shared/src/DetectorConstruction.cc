#include "DetectorConstruction.hh"
#include "DetectorMessenger.hh" 

#include "G4Material.hh" 
#include "G4NistManager.hh" 

#include "G4Box.hh" 
#include "G4LogicalVolume.hh" 
#include "G4PVPlacement.hh" 
#include "G4PVReplica.hh" 

#include "G4GeometryManager.hh" 
#include "G4PhysicalVolumeStore.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4SolidStore.hh" 

#include "G4VisAttributes.hh"
#include "G4Colour.hh" 
#include "G4SystemOfUnits.hh" 
#include "G4RotationMatrix.hh"
#include "G4RunManager.hh"
#include "G4UserLimits.hh"




//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DetectorConstruction::DetectorConstruction()
:G4VUserDetectorConstruction(),
 fStripMaterial(0),fDefaultMaterial(0), 
 fSolidWorld(0),fLogicWorld(0),fPhysiWorld(0),
 fSolidRO(0),fLogicRO(0),fPhysiRO(0),
 fSolidStrip(0),fLogicStrip(0),fPhysiStrip(0),
 fDetectorMessenger(0)
 {
     fNbOfLayers = 1; 
     fStripThickness = 0.05*cm;
     fROThickness = 0.15*cm;
     fROSizeXY = 30*cm;

     ComputeROParameters();

     // materials 
     DefineMaterials();
     SetTargetMaterial("G4_Cu");
     //SetReadoutMaterial("G4_Pb");

     // create commands for interactive definition of the Readout
     fDetectorMessenger = new DetectorMessenger(this); 
 }

 DetectorConstruction::~DetectorConstruction()
 { delete fDetectorMessenger;}

 G4VPhysicalVolume* DetectorConstruction::Construct()
 {
     return ConstructRO();
 }


 void DetectorConstruction::DefineMaterials()
 {
     // Use G4-Nist materials data base 
     G4NistManager* man = G4NistManager::Instance(); 
     fDefaultMaterial = man->FindOrBuildMaterial("G4_Galactic");
     man->FindOrBuildMaterial("G4_Cu");
     man->FindOrBuildMaterial("G4_Pb");

    // print table
    //
    G4cout<< *(G4Material::GetMaterialTable()) << G4endl;
 }

 G4VPhysicalVolume* DetectorConstruction::ConstructRO()
 {
     // Clean Old geometry, if any 
     G4GeometryManager::GetInstance()->OpenGeometry();
     G4PhysicalVolumeStore::GetInstance()->Clean();
     G4LogicalVolumeStore::GetInstance()->Clean();
     G4SolidStore::GetInstance()->Clean();

     // compute the Readout parameters definition 
     ComputeROParameters();

     //
     // World
     // 
    //G4double W_X = 50*cm;
    //G4double W_Y = 50*cm;
    //G4double W_Z = 50*cm;

     fSolidWorld = new G4Box("World",                                           //its name 
                            fWorldSizeXY, fWorldSizeXY, fWorldSizeZ);       //its size 

    fLogicWorld = new G4LogicalVolume(fSolidWorld,                              //its solid 
                                      fDefaultMaterial,                         //its material
                                      "World");                                 //its name

    fPhysiWorld = new G4PVPlacement(0,                                          //no rotation (always)
                                    G4ThreeVector(),                            //at (0,0,0)
                                    fLogicWorld,                                //its logical volume     
                                    "World",                                    //its name 
                                    0,                                          //its mother volume
                                    false,                                      //no boolean operation
                                    0);                                         //copy number

    //
    // Readout
    // 
    fSolidRO=0; fLogicRO=0; fPhysiRO=0; 

    if (fROThickness > 0.)
    { fSolidRO = new G4Box("Readout",                                       //its name
                            fROSizeXY, fROSizeXY, fROThickness);    //its size

      fLogicRO = new G4LogicalVolume(fSolidRO,                              //its solid
                                     fDefaultMaterial,                      //its material 
                                     "Readout" );                           //its name

      G4double position = 10*mm;
      fPhysiRO = new G4PVPlacement(0,                                       //no rotation
                                   G4ThreeVector(0,0,position),             // at (0,0,5mm)
                                   fLogicRO,                                //its logical volume
                                   "Readout",                               //its name 
                                   fLogicWorld,                             //its mother volume
                                   false,                                   //no boolean operator
                                   0);                                      //copy number

    }
    //
    // Strips
    // 

        fSolidStrip=0; fLogicStrip=0; fPhysiStrip=0;
   
        G4double strip_dx=1*cm; 
        G4double strip_dy=17*cm;
        G4double strip_dz=0.05*cm;

        G4int nb_strips = 10;
        G4double gap = 1.*cm;
        
        
        G4RotationMatrix* rotm = new G4RotationMatrix();
        rotm -> rotateZ(60*deg);
        G4RotationMatrix* rots = new G4RotationMatrix();
        rots -> rotateZ(-60*deg);
        
        G4VisAttributes* silver = new G4VisAttributes(G4Colour::Grey());
        silver->SetVisibility(true);
        silver->SetForceSolid(true);

        
        fSolidStrip = new G4Box("Strip",                                    //its name
                                strip_dx, strip_dy, strip_dz);              //its size
        
        
       
        fLogicStrip = new G4LogicalVolume(fSolidStrip,                      //its Solid
                                          fStripMaterial,                   //its material
                                          fStripMaterial->GetName());       //its name
        
        
     
        fLogicStrip->SetVisAttributes(silver);

        
        G4double dx = (strip_dx+gap);
        G4double pos = fROThickness-(0.1*fROThickness);
       
        
        fPhysiStrip = new G4PVPlacement(rotm,
                                        G4ThreeVector(-10*cm,+10*cm,pos),
                                        fLogicStrip,
                                        fStripMaterial->GetName(),
                                        fLogicRO,
                                        false,
                                        0);
       
        fPhysiStrip = new G4PVPlacement(rotm,
                                        G4ThreeVector(dx-10*cm, -dx+10*cm,pos),
                                        fLogicStrip,
                                        fStripMaterial->GetName(),
                                        fLogicRO,
                                        false,
                                        1);
         
        fPhysiStrip = new G4PVPlacement(rotm,
                                        G4ThreeVector(2*dx-10*cm, -2*dx+10*cm,pos),
                                        fLogicStrip,
                                        fStripMaterial->GetName(),
                                        fLogicRO,
                                        false,
                                        2);

        fPhysiStrip = new G4PVPlacement(rotm,
                                        G4ThreeVector(3*dx-10*cm, -3*dx+10*cm,pos),
                                        fLogicStrip,
                                        fStripMaterial->GetName(),
                                        fLogicRO,
                                        false,
                                        3);
        
        fPhysiStrip = new G4PVPlacement(rotm,
                                        G4ThreeVector(4*dx-10*cm, -4*dx+10*cm,pos),
                                        fLogicStrip,
                                        fStripMaterial->GetName(),
                                        fLogicRO,
                                        false,
                                        4);

        fPhysiStrip = new G4PVPlacement(rotm,
                                        G4ThreeVector(5*dx-10*cm, -5*dx+10*cm,pos),
                                        fLogicStrip,
                                        fStripMaterial->GetName(),
                                        fLogicRO,
                                        false,
                                        5);
        /*
        for (G4int copyNo = 0; copyNo<6; copyNo++)
        {
            
            //G4Transform3D transform = G4Transform3D(rotm,pos);
            fPhysiStrip = new G4PVPlacement(rotm,                      // rotation of the strips by 60 degrees
                                            G4ThreeVector(copyNo*dx-11*cm,-copyNo*dx+10*cm,pos),
                                            fLogicStrip,                    // its logical volume
                                            fStripMaterial->GetName(),      // its name
                                            fLogicRO,                        // its mother volume
                                            false,                          // no boolean operator
                                            copyNo);                        // copy no

           
        }
       


        /*G4int nb_Strips = 10; 
        G4double gap = 1.*cm;

        //Place strips on the Readout

         fPhysiStrip = new G4PVPlacement(rots,                      // rotation of the strips by 60 degrees
                                            G4ThreeVector(-copyNo*dx+10*cm,copyNo*dx-11*cm,pos),
                                            fLogicStrip,                    // its logical volume
                                            fStripMaterial->GetName(),      // its name
                                            fLogicRO,                        // its mother volume
                                            false,                          // no boolean operator
                                            copyNo);                        // copy no
        for(G4int istrip = 0; istrip < nb_Strips; istrip++)
        {
            G4double dx = istrip*(strip_dx + gap)-11*cm;
            G4double dy = istrip*(strip_dx + gap)-11*cm;
            G4RotationMatrix rotm = G4RotationMatrix();
            rotm.rotateZ(60*deg);
            G4ThreeVector pos = G4ThreeVector(dx,dy,fROThickness-(0.1*fROThickness));
            G4Transform3D transform = G4Transform3D(rotm,pos);

            fPhysiStrip = new G4PVPlacement(transform,                      // rotation of the strips by 60 degrees
                                            fLogicStrip,                    // its logical volume
                                            fStripMaterial->GetName(),      // its name
                                            fLogicRO,                       // its mother volume
                                            false,                          // no boolean operator
                                            istrip);                        // copy no

        }*/
    PrintROParameters();

    fLogicWorld->SetVisAttributes (G4VisAttributes::GetInvisible());

    G4VisAttributes* green = new G4VisAttributes(G4Colour::Green());
    green->SetVisibility(true);
    green->SetForceSolid(true);
    fLogicRO->SetVisAttributes(green);
    
  


    

    return fPhysiWorld;        
}


void DetectorConstruction::PrintROParameters()
{
    G4cout << "\n------------------------------------------------------------"
         << "\n---> The readout is " << fNbOfLayers << " 1 PCB: [ "
         << fStripThickness/mm << "mm of" << fStripMaterial->GetName()
         << "\n------------------------------------------------------------\n";
}

void DetectorConstruction::SetTargetMaterial(G4String materialChoice)
{
    // search the material by its name   
  G4Material* pttoMaterial =
  G4NistManager::Instance()->FindOrBuildMaterial(materialChoice);      
  if (pttoMaterial)
  {
      fStripMaterial = pttoMaterial;
      if ( fLogicStrip )
      {   
          
        if (fLogicStrip)  fLogicStrip->SetMaterial(fStripMaterial);
           
        G4RunManager::GetRunManager()->PhysicsHasBeenModified();
      }
  }
}

void DetectorConstruction::SetTargetThickness(G4double val)
{
    fStripThickness = val; 
    G4RunManager::GetRunManager()->ReinitializeGeometry();
}

void DetectorConstruction::SetROSizeXY(G4double val)
{
    fROSizeXY = val;
    G4RunManager::GetRunManager()->ReinitializeGeometry();
}

void DetectorConstruction::SetNbOfLayers(G4int val)
{
    fNbOfLayers = val;
    G4RunManager::GetRunManager()->ReinitializeGeometry();
}
