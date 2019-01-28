#ifndef ROActionInitialization_h
#define ROActionInitialization_h 1

#include "G4VUserActionInitialization.hh"

class RODetectorConstruction; 

class ROActionInitialization : public G4VUserActionInitialization
{
    public:
        ROActionInitialization(RODetectorConstruction* detector); 
        virtual ~ROActionInitialization();

        virtual void BuildForMaster() const; 
        virtual void Build() const; 

    private:
        RODetectorConstruction* fDetector; 
};

#endif