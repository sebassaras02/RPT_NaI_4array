#ifndef stackmessenger_h
#define stackmessenger_h 


#include "G4UImessenger.hh"
#include "globals.hh"
#include "stacking.hh"
#include "G4UIcommand.hh"
#include "G4UIcmdWithABool.hh"
#include "G4UIdirectory.hh"


class stackingaction;

/// stacking messenger class to select which particles to kill

class stackingmessenger : public  G4UImessenger
{
  public:
    stackingmessenger(stackingaction* stacking_);
    virtual ~stackingmessenger();

    virtual void SetNewValue(G4UIcommand*, G4String);

  private:
    
    G4UIdirectory *fKillParticles;
    G4UIcmdWithABool *fneutrino, *fneutron;
    stackingaction *f_stack;

    
};


#endif