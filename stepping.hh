#ifndef stepping_hh
#define stepping_hh

#include "G4UserSteppingAction.hh"
#include "G4Step.hh"

#include "detectorconstruction.hh"
#include "event.hh"


class steppingaction : public G4UserSteppingAction{
    
    public:
    steppingaction(eventaction* eventAction);
    ~steppingaction();
    
    // call functions 
    virtual void UserSteppingAction(const G4Step*);
    
    private:
    // save the edep in event action class
    eventaction* fEventAction;
};


#endif
