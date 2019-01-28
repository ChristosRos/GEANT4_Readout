#include "ROReadoutHit.hh" 
#include "G4UnitsTable.hh" 
#include "G4VisManager.hh" 
#include "G4Circle.hh" 
#include "G4Colour.hh" 
#include "G4VisAttributes.hh" 

#include <iomanip> 

G4ThreadLocal G4Allocator<ROReadoutHit>* ROReadoutHitAllocator=0; 

ROReadoutHit::ROReadoutHit()
  : G4VHit(),
    fTrackID(-1),
    fReadoutNb(-1),
    fEdep(0.),
    fPos(G4ThreeVector())
{}

ROReadoutHit::~ROReadoutHit() {}

ROReadoutHit::ROReadoutHit(const ROReadoutHit& right)
  : G4VHit()
{
    fTrackID   = right.fTrackID;
    fReadoutNb = right.fReadoutNb;
    fEdep      = right.fEdep; 
    fPos       = right.fPos; 
}

const ROReadoutHit& ROReadoutHit::operator=(const ROReadoutHit& right)
{
    fTrackID   = right.fTrackID;
    fReadoutNb = right.fReadoutNb; 
    fEdep      = right.fEdep;
    fPos       = right.fPos;

    return *this; 
}

G4int ROReadoutHit::operator==(const ROReadoutHit& right) const
{
    return ( this == &right ) ? 1 : 0;
}


void ROReadoutHit::Draw()
{
    G4VVisManager* pVVisManager = G4VVisManager::GetConcreteInstance();
    if(pVVisManager)
    {
        G4Circle circle(fPos);
        circle.SetScreenSize(4.);
        circle.SetFillStyle(G4Circle::filled);
        G4Colour colour (1.,0.,0.);
        G4VisAttributes attribs(colour); 
        circle.SetVisAttributes(attribs); 
        pVVisManager->Draw(circle); 
    }
}

void ROReadoutHit::Print()
{
    G4cout
       << "  trackID: " << fTrackID << " chamberNb: " << fReadoutNb
       << "Edep: "
       << std::setw(7) << G4BestUnit(fEdep,"Energy")
       << " Position: "
       << std::setw(7) << G4BestUnit( fPos,"Length")
       << G4endl;
}
