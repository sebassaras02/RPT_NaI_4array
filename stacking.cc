#include "stacking.hh"

stackingaction::stackingaction()
{ 
  fStackmessenger=  new stackingmessenger(this);
  SetDefaultValues();

}

stackingaction::~stackingaction()
{ }

void stackingaction::SetKillNeutrino(G4bool a)
{
  killnuetrinofun=a;
}

void stackingaction::SetKillNeutron(G4bool a)
{
  killnuetronfun=a;
}

void stackingaction::SetDefaultValues()
{
  killnuetrinofun=true;
  killnuetronfun=true;
}

G4ClassificationOfNewTrack stackingaction::ClassifyNewTrack(const G4Track* track)
{
  if (track->GetParentID() == 0) return fUrgent;

  if (killnuetrinofun == true){
    //kill secondary neutrino
    if (track->GetDefinition() == G4NeutrinoE::NeutrinoE()) return fKill;
    else return fUrgent;     
  }
  else return fUrgent;  

  if (killnuetronfun == true){
    if (track->GetDefinition() == G4Neutron::Neutron()) return fKill;
    else return fUrgent;
  }
  else return fUrgent;

}
