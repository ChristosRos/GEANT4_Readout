#ifndef HistoManager_h
#define HistoManager_h 1 

#include "globals.hh" 

#include "g4root.hh" 

class HistoManager
{
    public: 
        HistoManager();
        ~HistoManager();

        void Book();
        void Save(); 

        void FillHisto(G4int id, G4double e, G4double weight = 1.0);
        void Normalize(G4int id, G4double fac); 

        void FillNtuple(G4double EnergyAbs, G4double TrackAbs);

        void PrintStatistic();
    
    private: 
        G4bool fFactoryOn; 
};

#endif