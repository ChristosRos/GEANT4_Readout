#ifndef HistoManager_h
#define HistoManager_h 1 

#include "globals.hh"  


class TFile;
class TTree;
class TH1D;

const G4int kMaxHisto = 2;


class HistoManager
{
    public: 
        HistoManager();
        ~HistoManager();

        void Book();
        void Save(); 

        void FillHisto(G4int id, G4double bin, G4double weight = 1.0 );
        void Normalize(G4int id, G4double fac); 

        void FillNtuple(G4double energyAbs, G4double trackLAbs);

        void PrintStatistic(); 

    private: 
        TFile* fRootFile;
        TH1D*   fHisto[kMaxHisto];
        TTree*  fNtuple1;
        TTree*  fNtuple2;

        G4double fEabs;
        G4double fLabs;
};

#endif 
