#include "G4RunManager.hh"

#include "G4UImanager.hh"
#include "FTFP_BERT.hh"

#include "DetectorConstruction.hh" 
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"
//#include "ActionInitialization.hh"
#include "EventAction.hh"
#include "SteppingAction.hh"
#include "HistoManager.hh" 

#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......


int main(int argc,char** argv)
{
    // Detect interactive mode (if no arguments) and define UI session
    //
    G4UIExecutive* ui = 0;
    if ( argc == 1 ) {
        ui = new G4UIExecutive(argc, argv);
    }

    // Construct the default run manager
    //
    #ifdef G4MULTITHREADED
        G4int nThreads = 4; 
        G4MTRunManager * runManager = new G4MTRunManager;
        runManager->SetNumberOfThreads(nThreads);
    #else
        G4RunManager * runManager = new G4RunManager;
    #endif

    // Set Mandatory initialization classes
    //
    DetectorConstruction* detector = new DetectorConstruction; 
    runManager->SetUserInitialization(detector);
    runManager->SetUserInitialization(new FTFP_BERT);
    //runManager->SetUserInitialization(new ActionInitialization(detector));
    
    //
   
    
    // Set an HistoManager
    //
    HistoManager* histo = new HistoManager(); 

    // Set user action classes
    //
    PrimaryGeneratorAction* gen_action = 
                            new PrimaryGeneratorAction(detector);
    runManager->SetUserAction(gen_action);
    //
    RunAction* run_action = new RunAction(histo); 
    runManager->SetUserAction(run_action);
    //
    EventAction* event_action = new EventAction(run_action, histo);
    runManager->SetUserAction(event_action);
    //
    SteppingAction* stepping_action = 
                        new SteppingAction(detector, event_action);
    runManager->SetUserAction(stepping_action);

    // Initialize G4 kernel
    //
    runManager->Initialize();
    



    // Initialize visualization
    //
    G4VisManager* visManager = new G4VisExecutive;
    visManager->Initialize();

    // Get the pointer to the User interface manager
    //
    G4UImanager* UImanager = G4UImanager::GetUIpointer();

    if ( ! ui ) {
        // batch mode
        G4String command = "/control/execute ";
        G4String fileName = argv[1];
        UImanager->ApplyCommand(command+fileName);
    }
    else {
        // interactive mode
        UImanager->ApplyCommand("/control/execute init_vis.mac");
        ui->SessionStart();
        delete ui;
    }
    
    // Job termination
    delete visManager;
    delete histo;
    delete runManager; 

    return 0;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......