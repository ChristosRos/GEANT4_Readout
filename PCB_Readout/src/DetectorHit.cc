#include "DetectorHit.hh" 

#include "G4Step.hh" 
#include "G4TouchableHistory.hh"
#include "TrackingAction.hh" 

#include "DetectorStrip.hh" 

DetectorHit::DetectorHit()
{
}

DetectorHit::DetectorHit(const G4Step* step, DetectorStrip* _strip)
{
    strip = _strip; 

    beginPos = step->GetPreStepPoint()->GetPosition();
    endPos = step->GetPostStepPoint()->GetPosition(); 
    deltaPos = endPos - beginPos; 
    trackID = step->GetTrack()->GetTrackID();
    energyDeposited = step->GetTotalEnergyDeposit();

    stripID = strip->getID();
}

void DetectorHit::computePosition()
{
    G4ThreeVector globalPosition = 0.5*(endPos + beginPos); 
}

void DetectorHit::updateWith(const G4Step* step) 
{
    endPos = step->GetPostStepPoint()->GetPosition();
    deltaPos = endPos - beginPos; 
    energyDeposited += step->GetTotalEnergyDeposit();
    trueLength += step->GetDeltaPosition().mag();
    isLeavingStep = (step->GetPostStepPoint()->GetStepStatus() == fGeomBoundary) ;
    if( trackStatus < step->GetTrack()->GetTrackStatus() )
        trackStatus = step->GetTrack()->GetTrackStatus() ;
}

void DetectorHit::finalize()
{
    computePosition();
}

void DetectorHit::Print()
{
    std::cout << "Hit at " << "I:" << I << " J:" << J << " K:" << stripID << " at pos " << endPos-beginPos << std::endl ;
}
