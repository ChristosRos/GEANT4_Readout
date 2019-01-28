#ifndef ROReadoutSD_h
#define ROReadoutSD_h 1

#include "G4VSensitiveDetector.hh"

#include "ROReadoutHit.hh" 

#include <vector> 

class G4Step; 
class HCofThisEvent; 

/// The hits are accounted in hits in ProcessHits() function which is called
/// by Geant4 kernel at each step. A hit is created with each step with non zero
/// energy deposit

class ROReadoutSD : public G4VSensitiveDetector
{
    public: 
        ROReadoutSD(const G4String& name, 
                    const G4String& hitsCollectionName); 
    virtual ~ROReadoutSD();

    // methods from base class
    virtual void Initialize(G4HCofThisEvent* hitCollection);
    virtual G4bool ProcessHits(G4Step* step, G4TouchableHistory* history); 
    virtual void EndOfEvent(G4HCofThisEvent* hitCollection);

    private: 
        ROReadoutHitsCollection* fHitsCollection;
};

#endif