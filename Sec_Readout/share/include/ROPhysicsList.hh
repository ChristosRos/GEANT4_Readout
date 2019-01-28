#ifndef ROPhysicsList_h
#define ROPhysicsList_h 1

#include "G4VModularPhysicsList.hh"

/// Modular physics list
///
/// It includes the folowing physics builders
/// - G4DecayPhysics
/// - G4RadioactiveDecayPhysics
/// - G4EmStandardPhysics

class ROPhysicsList: public G4VModularPhysicsList
{
public:
  ROPhysicsList();
  virtual ~ROPhysicsList();

  //virtual void SetCuts();
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
