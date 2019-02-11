#include "RunAction.hh" 
#include "DetectorRun.hh" 
#include "RootWriter.hh" 


#include "globals.hh" 
#include <ctime>


RunAction::RunAction()
	: G4UserRunAction()
{
}


G4Run* RunAction::GenerateRun()
{
    return new DetectorRun;
}

void RunAction::BeginOfRunAction(const G4Run*)
{
    RootWriter* rootWriter = RootWriter::Instance();
    rootWriter->createRootFile( rootFileName );
}

void RunAction::EndOfRunAction(const G4Run*) 
{
    RootWriter* rootWriter = RootWriter::Instance();
    rootWriter->closeRootFile();

    RootWriter::deleteInstance();
}