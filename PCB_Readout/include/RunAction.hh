#ifndef RunAction_h
#define RunAction_h

#include "globals.hh"
#include "G4UserRunAction.hh"   

#include "RootWriter.hh"

#include <string> 

class G4Run;

class RunAction : public G4UserRunAction
{
    public: 
        RunAction(); 
        virtual ~RunAction() = default; 

        G4Run* GenerateRun();

        virtual void BeginOfRunAction(const G4Run*);
        virtual void EndOfRunAction(const G4Run*);

        inline void setRootFileName(G4String name) { rootFileName = name; }

    protected: 
        G4String rootFileName = "Readout_output.root";
};

#endif