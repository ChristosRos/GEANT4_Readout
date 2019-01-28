// Generate muons for the readout. 
// Consider MIPs 

#ifndef ROPrimaryGeneratorAction_h 
#define ROPrimaryGeneratorAction_h 1 


#include "G4VUserPrimaryGeneratorAction.hh"

#include "G4ParticleGun.hh"
#include "globals.hh" 

class G4ParticleGun; 
class G4Event; 

class ROPrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
    public: 
        ROPrimaryGeneratorAction();
        virtual ~ROPrimaryGeneratorAction(); 

        virtual void GeneratePrimaries(G4Event* );

        G4ParticleGun* GetParticleGun() {return fParticleGun;} 

        // Set methods 
        void SetRandomFlag(G4bool );


    private: 
        G4ParticleGun* fParticleGun; 
    
};

#endif

