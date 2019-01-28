#include "TH1D.h" 
#include <TFile.h>
#include <TTree.h>
#include "CLHEP/Units/SystemOfUnits.h" 

#include "HistoManager.hh"
#include "G4UnitsTable.hh"


HistoManager::HistoManager()
: fRootFile(0),
  fNtuple1(0), fNtuple2(0),
  fEabs(0.), fLabs(0.)
  {
      
      // Histograms 
      for (G4int k=0; k<kMaxHisto; k++) fHisto[k] = 0; 

      // ntuple
      fNtuple1 = 0; 
      fNtuple2 = 0; 
  }


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
  HistoManager::~HistoManager()
  {
      if (fRootFile) delete fRootFile;
  }


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
  void HistoManager::Book()
  {
      // Creating a tree contatiner to handle histograms and ntuples. 
      // This tree is associated to an output file 
      //
      G4String fileName = "Readout.root";
      fRootFile = new TFile(fileName, "RECREATE");
      if (! fRootFile) {
          G4cout << " HistoManager::Book :"
                 << " problem creating the ROOT TFile "
                 << G4endl;
          return;
      }

      fHisto[0] = new TH1D("Ebas",  "Edep in Cu strips [GeV]", 100, 0., 10*CLHEP::GeV);
      fHisto[1] = new TH1D ("LAbs", "trackL in the Cu strips [mm]", 100, 0., 1*CLHEP::m);

      for ( G4int i=0; i<kMaxHisto; ++i) {
          if (! fHisto[i]) G4cout << "\n can't create histo " << i << G4endl;
      }

      // create 1st ntuple
      fNtuple1 = new TTree("Ntuple1", "Edep");
      fNtuple1->Branch("Eabs", &fEabs, "Eabs/D");
 
      // create 2nd ntuple
      fNtuple2 = new TTree("Ntuple2", "TrackL");
      fNtuple2->Branch("Labs", &fLabs, "Labs/D");

      G4cout << "\n----> Output file is open in " << fileName << G4endl;
  }


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
  void HistoManager::Save()
  {
      if (! fRootFile) return;

      fRootFile->Write();   // Writing the histograms to the file
      fRootFile->Close();   // and closing the tree (and the file) 

      G4cout << "\n----> Histograms and ntuples are saved\n" << G4endl;
  }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
void HistoManager::FillHisto(G4int ih, G4double xbin, G4double weight)
{
    if (ih >= kMaxHisto) {
        G4cerr << "----> warning from HistoManager::FillHisto() : histo " << ih 
               << " does not exist. (xbin=" << xbin << " weight=" << weight << ")"
               << G4endl;
        return;
    }
    if   (fHisto[ih]) { fHisto[ih]->Fill(xbin, weight); }
}


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
void HistoManager::Normalize(G4int ih, G4double fac)
{
    if (ih >= kMaxHisto) {
        G4cout << "---> warning from HistoManager::Normalize() : histo " << ih
               << " does not exist. (fac=" << fac << ")" << G4endl;
        return; 
    }
    if (fHisto[ih]) fHisto[ih]->Scale(fac); 
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
void HistoManager::FillNtuple(G4double energyAbs, G4double trackLAbs)
{
    fEabs = energyAbs;
    fLabs = trackLAbs;

    if (fNtuple1) fNtuple1->Fill();
    if (fNtuple2) fNtuple2->Fill();
}


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
void HistoManager::PrintStatistic()
{
    G4cout << "\n ----> print histograms statistic \n" << G4endl; 
    for ( G4int i=0; i<kMaxHisto; ++i ) {
        TH1D* h1 = fHisto[i];
        const G4String name = h1->GetName(); 

        G4String unitCategory; 
        if (name[0] == 'E' ) unitCategory = "Energy"; 
        if (name[0] == 'L' ) unitCategory = "Length";

        G4cout << name 
               << ": mean = " << G4BestUnit(h1->GetMean(), unitCategory)
               << " rms  = " << G4BestUnit(h1->GetRMS(), unitCategory )
               << G4endl;
    }
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
