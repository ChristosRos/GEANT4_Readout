#include "PrimaryGeneratorAction.hh" 

#include "DetectorConstruction.hh" 

#include "G4Event.hh"
#include "G4ParticleGun.hh" 
#include "G4ParticleTable.hh" 
#include "G4ParticleDefinition.hh" 
#include "G4PrimaryParticle.hh"
#include "G4PrimaryVertex.hh"
#include "G4SystemOfUnits.hh"
#include "G4ios.hh" 

#include "G4String.hh" 

#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iterator>

PrimaryGeneratorAction::PrimaryGeneratorAction()
: G4VUserPrimaryGeneratorAction(),
fParticleGun(0)
{
    G4int n_particle = 1; 
    fParticleGun = new G4ParticleGun(n_particle);

    G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
    G4String particleName;
    G4ParticleDefinition* particle
                        = particleTable->FindParticle(particleName="mu-");
    fParticleGun->SetParticleDefinition(particle);
    //fParticleGun->SetParticlePosition(G4ThreeVector(0.5*cm,0.5*cm,0.1*m));
    fParticleGun->SetParticlePosition(G4ThreeVector(-11*cm,+10*cm,0.1*m));
    fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0.,0.,-1.*cm));
    fParticleGun->SetParticleEnergy(5.*GeV);
}

PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
    delete fParticleGun;
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* event)
{
    fParticleGun->GeneratePrimaryVertex(event);
}

