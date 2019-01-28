#include "HistoManager.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh" 



HistoManager::HistoManager()
: fFactoryOn(false)
{}

HistoManager::~HistoManager()
{}

void HistoManager::Book()
{
    // Create or get analysis manager
    // The choice of analysis technology is done vie selection of a namespace
    // in HistoManager.hh
    G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
    analysisManager->SetVerboseLevel(1);
    analysisManager->SetNtupleMerging(true);

    // create directories
    analysisManager->SetHistoDirectoryName("histo");
    analysisManager->SetNtupleDirectoryName("ntuple");


    // Open an input file 
    //
    G4bool fileOpen = analysisManager->OpenFile("Readout");
    if (! fileOpen) {
        G4cerr << "\n---> HistoManager::Book(): cannot open "
               << analysisManager->GetFileName() << G4endl; 
        return;
    }

    // Create Histograms.
    // Histogram ids are generated automatically starting from 0.
    // The srart value can be changed by:
    // analysisManager->SetFirstHistoId(1);

    // id = 0
    analysisManager->CreateH1("Eabs", "Eddp in absorber (GeV)", 100, 0, 1*GeV);
    // id = 1
    analysisManager->CreateH1("LAbs", "trackL in aborber (cm)", 100, 0, 1*m);

    // Create ntuples 
    // Ntuples ids are generated automatically starting from 0. 
    // The start value can be changed by
    // analysisManager->SetFirstNtupleId(1);

    // Create 1st ntuple (id=0)
    analysisManager->CreateNtuple("Ntuple", "Edep");
    analysisManager->CreateNtupleDColumn("Eabs"); // column id = 0
    analysisManager->FinishNtuple();

    //create 2nd ntuple (id = 1)
    analysisManager->CreateNtuple("Ntuple2", "TrackL");
    analysisManager->CreateNtupleDColumn("Labs");
    analysisManager->FinishNtuple(); 

    fFactoryOn = true; 

    G4cout << "\n---> Output file is open in " 
           << analysisManager->GetFileName() << "."
           << analysisManager->GetFileType() << G4endl;
}

void HistoManager::Save()
{
    if (! fFactoryOn) return; 

    G4AnalysisManager* analysisManager = G4AnalysisManager::Instance(); 
    analysisManager->Write(); 
    analysisManager->CloseFile(); 

    G4cout << "\n---> Histograms and ntuplesare saved\n" << G4endl;

    delete G4AnalysisManager::Instance(); 
    fFactoryOn = false;
}

void HistoManager::FillHisto(G4int ih, G4double xbin, G4double weight)
{
    G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
    analysisManager->FillH1(ih,xbin, weight);
}


void HistoManager::Normalize(G4int ih, G4double fac)
{
    G4AnalysisManager* analysisManager = G4AnalysisManager::Instance(); 
    G4H1* h1 = analysisManager->GetH1(ih);
    if (h1) h1->scale(fac);
}

void HistoManager::FillNtuple(G4double energyAbs, G4double trackLabs)
{
    G4AnalysisManager* analysisManager = G4AnalysisManager::Instance(); 
    //Fill 1st ntuple (id = 0) 
    analysisManager->FillNtupleDColumn(0,0, energyAbs); 
    analysisManager->AddNtupleRow(0);
    //Fill 2nd ntuple (id = 1) 
    analysisManager->FillNtupleDColumn(1,0, trackLabs);
    analysisManager->AddNtupleRow(1);
}

void HistoManager::PrintStatistic()
{
    if ( ! fFactoryOn) return; 

    G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();

    G4cout << "\n ----> print histograms statistic \n" << G4endl;
    for (G4int i=0; i<analysisManager->GetNofH1s(); ++i) {
        G4String name = analysisManager->GetH1Name(i);
        G4H1* h1 = analysisManager->GetH1(i);

        G4String unitCategory; 
        if (name[0U] == 'E' ) unitCategory = "Energy";
        if (name[0U] == 'L' ) unitCategory = "Length";

        G4cout << name
               << ": mean" << G4BestUnit(h1->mean(), unitCategory)
               << " rms " << G4BestUnit(h1->rms(), unitCategory)
               << G4endl;
    }
}
