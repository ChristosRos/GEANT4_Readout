#ifndef ROActionInitialization_h
#define ROActionInitialization_h 1

#include "G4VUserActionInitialization.hh"

class B4DetectorConstruction; 

class ROActionInitialization : public G4VUserActionInitialization
{
    public:
        ROActionInitialization(); 
        virtual ~ROActionInitialization();

        virtual void BuildForMaster() const; 
        virtual void Build() const; 
};

#endif