#include "stacking.hh"

stackingaction::stackingaction()
{ }

stackingaction::~stackingaction()
{ }

G4ClassificationOfNewTrack stackingaction::ClassifyNewTrack(const G4Track* track)
{
  if (track->GetParentID() == 0) return fUrgent;

  if (track->GetDefinition() == G4NeutrinoE::NeutrinoE()) return fKill;
    else return fUrgent;  

  if (track->GetDefinition() == G4Neutron::Neutron()) return fKill;
    else return fUrgent;

}
