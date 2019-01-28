#include "PrimaryGeneratorAction.hh" 

#include "DetectorConstruction.hh" 

#include "G4Event.hh" 
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh" 
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh" 

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

PrimaryGeneratorAction::PrimaryGeneratorAction(DetectorConstruction *DC)
: G4VUserPrimaryGeneratorAction(),
  fParticleGun(0),
  fDetector(DC)
  {
      G4int n_particle = 1; 
      fParticleGun = new G4ParticleGun(n_particle); 

      // default particle kinematic

      G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
      G4String particleName;
      G4ParticleDefinition* particle
                        = particleTable->FindParticle(particleName="mu-");
      fParticleGun->SetParticleDefinition(particle);
      fParticleGun->SetParticlePosition(G4ThreeVector(0.5*cm,0.5*cm,0.1*m));
      //fParticleGun->SetParticlePosition(G4ThreeVector(-11*cm,+10*cm,0.1*m));
      fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0.,0.,-1.*cm));
      fParticleGun->SetParticleEnergy(5.*GeV);
      
    }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
    delete fParticleGun;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
    // this function is called at the beginning of event
    //
    fParticleGun->GeneratePrimaryVertex(anEvent);
}