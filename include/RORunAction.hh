#ifndef RORunAction_h
#define RORunAction_h 1 

#include "G4UserRunAction.hh"
#include "globals.hh"   

class G4Run; 

//Run Action class 
class RORunAction : public G4UserRunAction
{
    public:
        RORunAction(); 
        virtual ~RORunAction(); 

        virtual void BeginOfRunAction(const G4Run* run);
        virtual void   EndOfRunAction(const G4Run* run);
};

#endif

