//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
#ifndef SensitiveDetector_h
#define SensitiveDetector_h 

#include "G4VSensitiveDetector.hh" 
#include "G4HCofThisEvent.hh" 
#include "G4Event.hh" 

#include <set> 

#include "DetectorHit.hh"

class G4Step; 
class G4HCofThisEvent;
class DetectorStrip;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
class SensitiveDetector: public G4VSensitiveDetector
{
    public: 
        SensitiveDetector(G4String name, DetectorStrip* _strip);
        virtual ~SensitiveDetector(); 

        virtual void Initialize(G4HCofThisEvent*);
        virtual G4bool ProcessHits(G4Step* step, G4TouchableHistory*);

        virtual void EndOfEvent(G4HCofThisEvent*);

        virtual G4bool Interested(const G4Step* step) const ;

        void finalizeLastHit(); 

        static inline const std::set<SensitiveDetector*>& getSensitiveDetectorVec() { return sensitiveDetectorVec ;}


    protected: 
        static std::set<SensitiveDetector*> sensitiveDetectorVec;
        DetectorHitCollection* hitsCollection; 

        G4int ID; 

        DetectorStrip* strip; 

        DetectorHit* currentHit;
 
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
#endif 