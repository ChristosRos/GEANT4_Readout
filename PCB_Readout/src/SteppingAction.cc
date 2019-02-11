#include "SteppingAction.hh" 
#include "DetectorConstruction.hh" 

#include "G4Step.hh"
#include "G4RunManager.hh"
#include "G4UnitsTable.hh"

#include <vector> 

#include <stdexcept>

#include "G4PhysicalVolumeStore.hh" 
#include "G4LogicalVolumeStore.hh"
#include "G4Box.hh"
#include "g4root.hh" 

SteppingAction* SteppingAction::instance = 0;

SteppingAction::SteppingAction()
: G4UserSteppingAction()
{
    if (instance)
		throw std::logic_error("SteppingAction already exists") ;

    G4cout << "Create SteppingAction" << G4endl ;

    instance = this ;
	depositedEnergy = 0.0 ;
	lastStepTime = 0.0 ;
    interestedRegion = NULL ;
}

void SteppingAction::UserSteppingAction(const G4Step* step) 
{
    G4Region* stepRegion = step->GetPreStepPoint()->GetPhysicalVolume()->GetLogicalVolume()->GetRegion() ;
	if (stepRegion != interestedRegion)
		return ;

	StepInfo stepInfo ;
	stepInfo.energyDeposited = step->GetTotalEnergyDeposit() ;
	stepInfo.time = step->GetPostStepPoint()->GetGlobalTime() ;
	stepInfo.preStepPoint = step->GetPreStepPoint()->GetPosition() ;
	stepInfo.postStepPoint = step->GetPostStepPoint()->GetPosition() ;   


    steps.push_back( stepInfo ) ;
}

void SteppingAction::processSteps()
{
	for ( std::vector<StepInfo>::iterator it = steps.begin() ; it != steps.end() ; ++it )
	{
		depositedEnergy += it->energyDeposited ;
	}
}

void SteppingAction::PrintTableEnergy()
{
	for (std::map<G4int,G4double>::iterator it=depositedEnergyPerParticleType.begin() ; it != depositedEnergyPerParticleType.end() ; ++it)
		G4cout << it->first << " = " << it->second/CLHEP::MeV << " MeV" << G4endl ;
}

void SteppingAction::reset()
{
    steps.clear() ;

	depositedEnergy = 0.0 ;

	depositedEnergyPerParticleType.clear() ;

    lastStepTime = 0.0 ;
}