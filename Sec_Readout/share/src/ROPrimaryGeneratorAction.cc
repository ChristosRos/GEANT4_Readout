#include "ROPrimaryGeneratorAction.hh"

#include "G4LogicalVolumeStore.hh" 
#include "G4LogicalVolume.hh" 
#include "G4Box.hh" 
#include "G4Event.hh" 
#include "G4ParticleGun.hh" 
#include "G4ParticleTable.hh" 
#include "G4ParticleDefinition.hh" 
#include "G4SystemOfUnits.hh" 

#include "Randomize.hh" 

ROPrimaryGeneratorAction::ROPrimaryGeneratorAction()
 : G4VUserPrimaryGeneratorAction()
 {
     G4int nofParticles = 1;
     fParticleGun = new G4ParticleGun(nofParticles);

     //default particle kinematic
     G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
     G4ParticleDefinition* particle = particleTable->FindParticle("mu-");

    fParticleGun->SetParticleDefinition(particle);
    fParticleGun->SetParticlePosition(G4ThreeVector(0.,0.,-0.05*mm));
    fParticleGun->SetParticleEnergy(4.0*GeV);
    fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0.2*mm,0.2*mm,1.*cm));
    
 } 


 ROPrimaryGeneratorAction::~ROPrimaryGeneratorAction()
 {
     delete fParticleGun;
 }

 void ROPrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
 {

     G4double worldZHalfLength = 0; 
     G4LogicalVolume* worldLV
      = G4LogicalVolumeStore::GetInstance()->GetVolume("World");

    G4Box* worldBox = NULL;

    if (worldLV) worldBox = dynamic_cast<G4Box*>(worldLV->GetSolid());
    if (worldBox) worldZHalfLength = worldBox->GetZHalfLength();
    else  {
    G4cerr << "World volume of box not found." << G4endl;
    G4cerr << "Perhaps you have changed geometry." << G4endl;
    G4cerr << "The gun will be place in the center." << G4endl;
  }

  fParticleGun->SetParticlePosition(G4ThreeVector(0., 0., -worldZHalfLength));

  fParticleGun->GeneratePrimaryVertex(anEvent);
}

