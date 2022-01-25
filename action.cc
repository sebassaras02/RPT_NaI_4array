#include "action.hh"
#include "generator.hh"
#include "event.hh"
#include "stepping.hh"

// contructor
actioninitialization::actioninitialization(){}
// destructor
actioninitialization::~actioninitialization(){}

void actioninitialization::BuildForMaster() const{
      
    runaction* runAction= new runaction();
    SetUserAction(runAction);
    
}

void actioninitialization::Build() const{
    primarygenerator* generator= new primarygenerator();
    SetUserAction(generator);
    
    runaction* runAction= new runaction();
    SetUserAction(runAction);
    
    eventaction* EventAction= new eventaction(runAction);
    SetUserAction(EventAction);
    
    steppingaction* SteppingAction= new steppingaction(EventAction);
    SetUserAction(SteppingAction);
}

