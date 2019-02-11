#include "TrackingAction.hh" 

#include "G4Track.hh" 

#include <stdexcept>

TrackingAction* TrackingAction::instance = 0; 

TrackingAction::TrackingAction()
: G4UserTrackingAction()
{
    if (instance)
        throw std::logic_error("SteppingActtion already exists");
    
    instance = this; 

    G4cout << "create TrackingAction" << G4endl;
}

void TrackingAction::reset() 
{
    linkMap.clear(); 
    primaryTrackMap.clear();
}

void TrackingAction::PreUserTrackingAction(const G4Track* track)
{
    linkMap.insert( {track->GetTrackID(), track->GetParentID()} );

    if (track->GetParentID() == 0 )
    {
        PrimaryParticleInfo info ; info.id = track->GetTrackID() ; info.momentum = track->GetMomentum() ; info.pdg = track->GetParticleDefinition()->GetPDGEncoding() ;
        primaryTrackMap.insert( {info.id , info} ) ;
    }
}

G4int TrackingAction::getPrimaryParent(const G4Track* track) const
{
    G4int parent= track->GetTrackID();

    while ( true )
	{
		if ( linkMap.at(parent) == 0 )
			return parent ;

		parent = linkMap.at(parent) ;
    }

}

TrackingAction::PrimaryParticleInfo TrackingAction::getPrimaryParticleInfo(G4int id) const
{
	TrackingAction::PrimaryParticleInfo info ;
	try
	{
		info = primaryTrackMap.at(id) ;
	}
	catch (std::out_of_range&)
	{
		G4cout << "TrackingAction::getPrimaryParticleInfo(" << id << ") -> error" << G4endl ;
	}
	return info ;
}