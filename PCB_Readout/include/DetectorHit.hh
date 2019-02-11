//.........ooooooOOOOOOOOOOooooooOOOOOOOOOooooooooo.......//
#ifndef DetectorHit_h
#define DetectorHit_h

#include "G4VHit.hh"
#include "G4ThreeVector.hh"
#include "G4THitsCollection.hh"
#include "G4PrimaryParticle.hh"
#include "DetectorStrip.hh"

class G4Step; 

class DetectorHit : public G4VHit
{
    public: 
        DetectorHit(const G4Step* step, DetectorStrip* _strip);
        virtual ~DetectorHit() {;} 

        void updateWith(const G4Step* step); 
        void finalize(); 
        virtual void computePosition(); 

        const G4ThreeVector GetPos() const { return 0.5*(endPos + beginPos) ; }
        const G4ThreeVector& getBeginPos() const { return beginPos; }
        const G4ThreeVector& getEndPos() const { return endPos; } 
        const G4ThreeVector& getDeltaPos() const { return deltaPos; }


        inline G4int getTrackID() const {return trackID; } 
        inline G4int getEnergyDeposited() const { return energyDeposited; } 
        inline DetectorStrip* getStrip() const { return strip; }
        inline G4int getStripID() const { return stripID; }
        inline G4int getTrackStatus() const { return trackStatus ; }
        inline G4int getI() const { return I ; }
		inline G4int getJ() const { return J ; }
		inline G4bool isEntering() const { return isEnteringStep ; }
        inline G4bool isLeaving() const { return isLeavingStep ; }
        inline G4double getTrueLength() const { return trueLength ; }

    
        virtual void Print(); 

    protected: 
        DetectorHit() ; 
        G4ThreeVector beginPos ; 
        G4ThreeVector endPos ; 
        G4ThreeVector deltaPos ; 
        G4int trackID ;
        G4int I ;
		G4int J ;
		G4bool isEnteringStep ;
        G4bool isLeavingStep ;
        G4double energyDeposited; 
        G4double trueLength ;
        DetectorStrip* strip;
        G4int stripID;  

        G4int trackStatus ;
};

typedef G4THitsCollection<DetectorHit> DetectorHitCollection; 

#endif 

