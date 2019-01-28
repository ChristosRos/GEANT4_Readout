#ifndef ROEventAction_h
#define ROEventAction_h 1

#include "G4UserEventAction.hh"

#include "globals.hh" 

/// Event Action class 

class ROEventAction : public G4UserEventAction
{
    public: 
        ROEventAction(); 
        virtual ~ROEventAction(); 

        virtual void BeginOfEventAction(const G4Event* );
        virtual void   EndOfEventAction(const G4Event* ); 
};

#endif