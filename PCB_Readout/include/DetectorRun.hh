//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
#ifndef DetectorRun_h
#define DetectorRun_h

#include "globals.hh" 
#include "G4Run.hh" 

class G4Event; 

class DetectorRun : public G4Run
{
    public: 
        DetectorRun(); 
        virtual ~DetectorRun(); 

        protected: 

};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
#endif 