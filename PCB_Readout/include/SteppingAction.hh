#ifndef SteppingAction_h
#define SteppingAction_h

#include <G4Step.hh>
#include <G4UserSteppingAction.hh>
#include <G4ThreeVector.hh>
#include <G4RegionStore.hh>
#include <G4VPhysicalVolume.hh>
#include <G4AffineTransform.hh>
#include <globals.hh>

#include <vector>
#include <map>

class G4LogicalVolume; 
class G4Region; 

struct StepInfo 
{
    G4double energyDeposited; 
    G4double time; 
    G4ThreeVector preStepPoint ;
    G4ThreeVector postStepPoint ; 
}; 

class SteppingAction : public G4UserSteppingAction
{ 
        static SteppingAction* instance; 
    protected: 
        SteppingAction();
        static void initInstance() { new SteppingAction ; } 
        virtual ~SteppingAction() { instance = nullptr ; } 

    public: 
        static SteppingAction* Instance()
        {
            if ( !instance ) 
                    initInstance() ; 
            return instance; 
        }

    public: 

        virtual void UserSteppingAction(const G4Step* step) ; 

        void reset();
        void processSteps(); 

        inline void setInterestedRegion(G4Region* region) { interestedRegion = region ; } 
        inline void setPhysicalVolume(G4VPhysicalVolume* volume) { readout = volume ;  }

        G4double getDepositedEnergy() const { return depositedEnergy ; }
        

        std::map<G4int, G4double> getDepositedEnergyPerParticleType() const { return depositedEnergyPerParticleType;}

        void PrintTableEnergy(); 

        inline G4double getLastStepTime() const {return lastStepTime; }
        inline const std::vector<StepInfo>& getSteps() const {return steps; }


    private: 
        G4Region* interestedRegion; 
        G4VPhysicalVolume* readout; 

        G4double depositedEnergy;

        std::map<G4int, G4double> depositedEnergyPerParticleType;

        G4double lastStepTime;
        std::vector<StepInfo> steps;

};

#endif 
