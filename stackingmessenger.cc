#include "stackingmessenger.hh"

stackingmessenger::stackingmessenger(stackingaction* stacking_) : f_stack(stacking_){

  // set directory to kill particles
  fKillParticles = new G4UIdirectory("/kill");
  fKillParticles->SetGuidance("Select secondary particles to kill tracking");

  //Various commands for killing neutrino
  fneutrino = new G4UIcmdWithABool("/kill/neutrino",this);
  fneutrino->SetGuidance("Kill secondary neutrinos generated, Active = true, Kill =false");
  fneutrino->AvailableForStates(G4State_PreInit,G4State_Idle);
  // fneutrino->SetToBeBroadcasted(false);

  //Various commands for killing neutrino
  fneutron = new G4UIcmdWithABool("/kill/neutron",this);
  fneutron->SetGuidance("Kill secondary neutron generated, Active = true, Kill =false");
  fneutron->AvailableForStates(G4State_PreInit,G4State_Idle);
  // fneutron->SetToBeBroadcasted(false);
  
}

stackingmessenger::~stackingmessenger()
{
  delete fneutrino;
  delete fneutron;
}

void stackingmessenger::SetNewValue(G4UIcommand* command, G4String newValue)
{
  if( command == fneutrino ){
    f_stack->SetKillNeutrino(fneutrino->GetNewBoolValue(newValue));
  }

  if( command == fneutron ){
    f_stack->SetKillNeutron(fneutron->GetNewBoolValue(newValue));
  }
}

