#ifndef RootWriter_h
#define RootWriter_h

#include "TFile.h" 
#include "TTree.h" 

#include "G4ThreeVector.hh"
#include "globals.hh" 

#include <vector> 

class RootWriter
{
        static RootWriter* instance; 
    protected: 
        RootWriter(); 
        void static initInstance() { new RootWriter ; }
        virtual ~RootWriter() { instance = NULL ; }

    public: 
        static RootWriter* Instance() 
        {
            if ( !instance )
                initInstance() ; 
            return instance ; 
        }

        static void deleteInstance()
        {
            if ( !instance ) 
            {
                std::cout << "WARNING in the RootWriter::deleteInstance() : No instance of RootWriter -> do nothing"
                          << std::endl;
                return ; 
            }
            delete instance;
        }

    public: 
        void createRootFile( std::string fileName ) ;
        void closeRootFile(); 

        void fillTree(); 

        inline void setEventNumber(int value) { eventNumber = value; }
        inline void setNHit(int value) { nHit = value; } 
        inline void setPrimaryEnergy(double value) { primaryEnergy = value; }
        void setPrimaryPos(G4ThreeVector value) { primaryPos[0] = value.x(); primaryPos[1] = value.y(); primaryPos[2] = value.z(); }
        inline void setDepositedEnergy(double value) { depositedEnergy = value; } 
        inline void SetStepLength(std::vector<double> value) { stepLength = value; }
        inline void setStepTime(std::vector<double> value) { stepTime = value; }


    protected: 
        TFile* file; 
        TTree* tree; 

        int eventNumber ; 
        int nHit; 
        double primaryEnergy; 
        double primaryPos[3]; 
        double depositedEnergy; 
        
        std::vector<double> stepLength; 
        std::vector<double> stepTime; 
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
#endif