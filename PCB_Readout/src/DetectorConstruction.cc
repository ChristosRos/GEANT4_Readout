#include "DetectorConstruction.hh" 

#include "G4NistManager.hh" 
#include "G4Box.hh" 

#include "G4LogicalVolume.hh" 
#include "G4VPhysicalVolume.hh" 
#include "G4PVPlacement.hh" 
#include "G4RotationMatrix.hh" 
#include "G4SystemOfUnits.hh"
#include "G4Material.hh"

#include "G4Region.hh" 
#include "G4RegionStore.hh"

#include "DetectorStrip.hh" 


DetectorConstruction::DetectorConstruction()
{}

DetectorConstruction::~DetectorConstruction()
{}

G4VPhysicalVolume* DetectorConstruction::Construct()
{
    G4int NStrips = 10; 
    G4double nposX = 1*cm;
    G4double nposY = 17*cm;
    G4double nposZ = 0.05*cm;  

    G4NistManager* man = G4NistManager::Instance();
    G4Material* defaultMaterial = man->FindOrBuildMaterial("G4_Galactic");
    G4Material* ROMaterial = man ->FindOrBuildMaterial("G4_Pb");
 

    G4int worldSizeX = 60*cm;  G4int worldSizeY = 60*cm; G4int worldSizeZ = 60*cm;
    

    //World 
    G4Box* solidWorld = new G4Box("World", worldSizeX, worldSizeY, worldSizeZ);
    G4LogicalVolume* logicWorld = new G4LogicalVolume(solidWorld, defaultMaterial, "World");
    G4VPhysicalVolume* physiWorld = new G4PVPlacement(0,
                                                      G4ThreeVector(),
                                                      logicWorld,
                                                      "World",
                                                      0,
                                                      false,
                                                      0,
                                                      true);

    //Readout
    G4int ROpos = 10*mm; 
    G4int PCBSizeXY = 30*cm;
    G4double PCBthickness = 0.15*cm;

    G4Box* solidPCB = new G4Box("ROPCB", PCBSizeXY, PCBSizeXY, PCBthickness);
    G4LogicalVolume* logicPCB = new G4LogicalVolume(solidPCB,ROMaterial,"ROPCB");
    new G4PVPlacement(0,
                      G4ThreeVector(0,0,ROpos),
                      logicPCB,
                      "ROPCB",
                      logicWorld,
                      false,
                      0,
                      true);


    //Strips
    G4double gap = 1.*cm;
    
    G4RotationMatrix* rotm = new G4RotationMatrix();
    rotm -> rotateZ(60*deg);
    G4RotationMatrix* rots = new G4RotationMatrix();
    rots -> rotateZ(-60*deg);

    G4double dx = (nposX+gap);
    G4double pos = PCBthickness-(0.5*PCBthickness);

    std::vector<DetectorStrip*> stripVec;
    for (G4int i=0; i<NStrips; i++)
    {
        stripVec.push_back( new DetectorStrip(i, nposX, nposY, nposZ));
        std::stringstream name ; name << "Strip" << i ;
        stripVec.at(i)->createPhysicalVolume(rotm,
                                             G4ThreeVector(i*dx-11*cm,-i*dx+10*cm,pos),
                                             logicPCB);
    }
    
    //for stepping action 
    G4Region* regionRO = G4RegionStore::GetInstance()->FindOrCreateRegion("RegionReadout");
    regionRO->AddRootLogicalVolume(logicPCB);

    G4VisAttributes* green = new G4VisAttributes(G4Colour::Green());
    green->SetVisibility(true);
    green->SetForceSolid(true);
    logicPCB->SetVisAttributes(green);



    

    return physiWorld; 
}
