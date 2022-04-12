#ifndef event_hh
#define  event_hh

#include "G4UserEventAction.hh"
#include "G4Event.hh"

//#include "g4root.hh"
#include "G4AnalysisManager.hh"
#include "runaction.hh"

class eventaction : public G4UserEventAction 
{
public:
    eventaction(runaction*);
    ~eventaction();
    
    // call necessary methods
    virtual void BeginOfEventAction(const G4Event*);
    virtual void EndOfEventAction(const G4Event*);
    
    // create a function to add all values of each event
    void AddEdep1(G4double edep){fEdep1+=edep;};
    void AddEdep2(G4double edep){fEdep2+=edep;};
    void AddEdep3(G4double edep){fEdep3+=edep;};
    void AddEdep4(G4double edep){fEdep4+=edep;};

    // create a function to save TOF of each event
    void AddTOF1(G4double time){tof1+=time;};
    
    private:
    G4double fEdep1, fEdep2, fEdep3, fEdep4;
    G4double cfdet;
    G4double tof1;
};

#endif
