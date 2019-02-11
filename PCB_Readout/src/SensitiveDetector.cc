#include "SensitiveDetector.hh"

#include "G4VProcess.hh" 
#include "G4Track.hh" 
#include "G4Step.hh" 
#include "G4SDManager.hh" 
#include "G4ios.hh" 


#include <sstream> 

#include "DetectorStrip.hh" 

std::set<SensitiveDetector*> SensitiveDetector::sensitiveDetectorVec;


SensitiveDetector::SensitiveDetector(G4String name, DetectorStrip* _strip)
: G4VSensitiveDetector(name)
{
    strip = _strip; 
    ID = strip->getID();

    std::stringstream colName; colName << "HitsStrip" << ID;
    collectionName.insert( colName.str() );

    currentHit = NULL;
    hitsCollection = NULL; 

    sensitiveDetectorVec.insert(this);
}

SensitiveDetector::~SensitiveDetector()
{
    std::set<SensitiveDetector*>::iterator it = sensitiveDetectorVec.find(this) ;
    sensitiveDetectorVec.erase(it) ;
}


void SensitiveDetector::Initialize(G4HCofThisEvent* HCE)
{
    currentHit = NULL; 

    hitsCollection = new DetectorHitCollection(SensitiveDetectorName, collectionName.at(0));
    HCE->AddHitsCollection(ID, hitsCollection);
}

G4bool SensitiveDetector::ProcessHits(G4Step* step, G4TouchableHistory*)
{
    if ( !Interested(step) )
		return true ;

	if (currentHit)
	{
		if ( currentHit->getTrackID() == step->GetTrack()->GetTrackID() &&
			 currentHit->getEndPos() == step->GetPreStepPoint()->GetPosition() )
		{
			currentHit->updateWith(step) ;
		}
		else
		{
			currentHit->finalize() ;
			hitsCollection->insert(currentHit) ;
			currentHit = new DetectorHit(step , strip) ;
		}
	}
	else
	{
		currentHit = new DetectorHit(step , strip) ;
	}

	if ( currentHit->isLeaving() )
	{
		currentHit->finalize() ;
		hitsCollection->insert(currentHit) ;
		currentHit = NULL ;
	}

return true ;
}


G4bool SensitiveDetector::Interested(const G4Step* step) const
{
	return static_cast<G4bool>( step->GetTrack()->GetDynamicParticle()->GetCharge() ) ;
}


void SensitiveDetector::finalizeLastHit()
{
	if (!currentHit)
		return ;

	currentHit->finalize() ;
	hitsCollection->insert(currentHit) ;
	currentHit = NULL ;
}

void SensitiveDetector::EndOfEvent(G4HCofThisEvent*)
{
	finalizeLastHit() ;
}