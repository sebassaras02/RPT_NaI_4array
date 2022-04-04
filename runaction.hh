#ifndef runaction_hh

#define runaction_hh

#include "G4UserRunAction.hh"
//#include "g4root.hh"
#include "G4AnalysisManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4Run.hh"
#include "G4Accumulable.hh"
#include "G4AccumulableManager.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"
#include "G4RunManager.hh"
#include "detectorconstruction.hh"
#include "G4UnitsTable.hh"
#include "globals.hh"
#include "G4UserRunAction.hh"

class runaction : public G4UserRunAction{
    public:
    runaction();
    ~runaction();
    
    
    // create the functions to manage Run Action class
    virtual void BeginOfRunAction(const G4Run*);
    virtual void EndOfRunAction(const G4Run*);

    void AddEventEdep (G4double edep) {fEvEdep+=edep;};

    private:
    G4Accumulable<G4double> fEvEdep = 0.;
};

#endif
