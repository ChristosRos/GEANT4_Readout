#ifndef DetectorStrip_h
#define DetectorStrip_h 1

#include "globals.hh"
#include "G4Material.hh" 

#include "G4VPhysicalVolume.hh" 
#include "G4AffineTransform.hh"

#include "G4VisAttributes.hh"
#include "G4Colour.hh" 
#include "G4TouchableHistory.hh"
#include "G4GRSVolume.hh"

#include <vector>
#include <set>

class G4LogicalVolume; 

class DetectorStrip
{
    public:     
        DetectorStrip(G4int _id, G4double _nposX, G4double _nposY, G4double _nposZ) ; 
        virtual ~DetectorStrip();

        G4LogicalVolume* getLogicStrip() { return LogicStrip; }
        G4VPhysicalVolume* getPhysiStrip() { return PhysiStrip; }
        
        inline G4double getnposX() const { return nposX ; }
		inline G4double getnposY() const { return nposY ; }
		inline G4double getnposZ() const { return nposZ ; }
        inline G4int getID() const { return id ; }
        


        G4VPhysicalVolume* createPhysicalVolume(G4RotationMatrix* rot , G4ThreeVector trans , G4LogicalVolume* motherLogic) ;

    protected: 
        static std::set<DetectorStrip*> allTheStrips;

        DetectorStrip() { ; } // Just for derived class

        virtual void GetMaterials(); 
        virtual void build(); 

        

        G4int id; 
        G4double nposX;
        G4double nposY;
        G4double nposZ;

        G4bool oldConfig = false;

        G4String name; 

        G4Material* stripMaterial; 

        G4LogicalVolume* LogicStrip; 
        G4VPhysicalVolume* PhysiStrip; 
};

#endif 