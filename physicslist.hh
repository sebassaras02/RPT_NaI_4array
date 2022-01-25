// define de header file 
// it's telling that please if is not define something (detector construction)
#ifndef physicslist_hh
// please define detector construction with the next stuffs
#define physicslist_hh

// call mandatory classes
#include "G4VModularPhysicsList.hh"
#include "G4RadioactiveDecayPhysics.hh"
#include "G4EmStandardPhysics.hh"
#include "G4DecayPhysics.hh"

//create the class
class physicslist: public G4VModularPhysicsList
{
public:
    // create constructor
    physicslist();
    // create destructor
    ~physicslist();
    
};

#endif
