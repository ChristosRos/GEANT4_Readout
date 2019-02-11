#include "DetectorConstruction.hh" 
#include "PrimaryGeneratorAction.hh" 
#include "RunAction.hh" 
#include "TrackingAction.hh" 

#include "G4PhysListFactory.hh"

#include "G4RunManager.hh" 
#include "G4UImanager.hh" 
#include "G4VisExecutive.hh"
#include "FTFP_BERT.hh"


#include "G4UIexecutive.hh"

#include <string>

int main(int argc, char** argv)
{
    G4UIExecutive* ui = 0;
    if (argc==1) {
        ui = new G4UIExecutive(argc, argv);
    }

    #ifdef G4MULTITHREADED
        G4int nThreads = 4; 
        G4MTRunManager * runManager = new G4MTRunManager;
        runManager->SetNumberOfThreads(nThreads);
    #else
        G4RunManager * runManager = new G4RunManager;
    #endif
    

    DetectorConstruction* detector = new DetectorConstruction; 
    runManager->SetUserInitialization(detector); 
    runManager->SetUserInitialization(new FTFP_BERT);

    //Primary generator action 
    runManager->SetUserAction(new PrimaryGeneratorAction());

    
    RunAction* runAction = new RunAction();
    
    runAction->setRootFileName("Readout_output.root");

    runManager->SetUserAction(runAction);

    runManager->SetUserAction( SteppingAction::Instance() ) ;
    runManager->SetUserAction( TrackingAction::Instance() ) ;

    runManager->Initialize() ;

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
    

    delete visManager; 
    delete runManager ;

    return 0 ;
}
