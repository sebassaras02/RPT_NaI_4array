#ifndef runaction_hh

#define runaction_hh

#include "G4UserRunAction.hh"
//#include "g4root.hh"
#include "G4AnalysisManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4Run.hh"

class runaction : public G4UserRunAction{
    public:
    runaction();
    ~runaction();
    
    
    // create the functions to manage Run Action class
    virtual void BeginOfRunAction(const G4Run*);
    virtual void EndOfRunAction(const G4Run*);
};

#endif
