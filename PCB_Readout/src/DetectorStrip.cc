#include "DetectorStrip.hh"

#include <fstream>
#include <iostream> 

#include <vector> 
#include <sstream> 

#include "G4Material.hh" 
#include "G4NistManager.hh"

#include "G4Box.hh"

#include "G4LogicalVolume.hh" 
#include "G4ThreeVector.hh" 
#include "G4PVPlacement.hh"

#include "globals.hh" 
#include "G4GeometryManager.hh"
#include "G4PhysicalVolumeStore.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4SolidStore.hh"
#include "G4RegionStore.hh" 
#include "G4Region.hh" 
#include "G4SystemOfUnits.hh"


std::set<DetectorStrip*> DetectorStrip::allTheStrips;


DetectorStrip::DetectorStrip(G4int _id, G4double _nposX, G4double _nposY, G4double _nposZ)
{
    
    id = _id; 

    G4LogicalVolumeStore* store = G4LogicalVolumeStore::GetInstance();
    std::stringstream sname ; sname << "Strip" << id ;
    name = sname.str();

    if (store -> GetVolume(name , false))
    {
        G4cout << "Warning: Strip with ID=" << id << " already existing" << G4endl;
    }

    nposX = _nposX;
    nposY = _nposY;
    nposZ = _nposZ;

    LogicStrip = NULL;
    PhysiStrip = NULL;

    DetectorStrip::GetMaterials();
    DetectorStrip::build();

    allTheStrips.insert(this);

}

DetectorStrip::~DetectorStrip()
{
    std::set<DetectorStrip*>::iterator it = allTheStrips.find(this);
    allTheStrips.erase(it);
}

void DetectorStrip::build()
{
    G4double strip_dx = 1*cm;
    G4double strip_dy = 17*cm; 
    G4double strip_dz = 0.05*cm; 

    nposX = strip_dx;
    nposY = strip_dy;
    nposZ = strip_dz; 

    G4Box* SolidStrip = new G4Box("Strip",nposX,nposY,nposZ);
    G4LogicalVolume* LogicCStrip = new G4LogicalVolume(SolidStrip,stripMaterial,name);

    LogicStrip = LogicCStrip ; 

    G4VisAttributes* silver = new G4VisAttributes(G4Colour::Grey());
    silver->SetVisibility(true);
    silver->SetForceSolid(true);
    LogicStrip->SetVisAttributes(silver);

}

G4VPhysicalVolume* DetectorStrip::createPhysicalVolume(G4RotationMatrix* rot , G4ThreeVector trans , G4LogicalVolume* motherLogic)
{
	PhysiStrip = new G4PVPlacement(rot , trans , LogicStrip , name , motherLogic , false , 0 , true) ;
	return PhysiStrip ;
}

void DetectorStrip::GetMaterials()
{
    G4NistManager* man = G4NistManager::Instance();

    stripMaterial = man->FindOrBuildMaterial("G4_Cu");
}
