//.........ooooooOOOOOOOOOOooooooOOOOOOOOOooooooooo.......//
#ifndef PrimaryGeneratorAction_h
#define PrimaryGeneratorAction_h

#include "G4VUserPrimaryGeneratorAction.hh" 
#include "globals.hh"

class G4ParticleGun;
class G4Event; 
class DetectorConstruction;


//.........ooooooOOOOOOOOOOooooooOOOOOOOOOooooooooo.......//
class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
    public: 
        PrimaryGeneratorAction();
        virtual ~PrimaryGeneratorAction(); 

        virtual void GeneratePrimaries(G4Event*);

    private:
        G4ParticleGun* fParticleGun; // pointer to a G4 class
};

//.........ooooooOOOOOOOOOOooooooOOOOOOOOOooooooooo.......//
#endif