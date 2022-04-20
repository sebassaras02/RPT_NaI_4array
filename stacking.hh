#ifndef stacking_h
#define stacking_h

#include "G4UserStackingAction.hh"
#include "globals.hh"
#include "G4Track.hh"
#include "G4NeutrinoE.hh"
#include "G4Neutron.hh"
#include "stackingmessenger.hh"


class stackingmessenger;


class stackingaction : public G4UserStackingAction
{
  public:
    stackingaction();
    ~stackingaction();

    G4ClassificationOfNewTrack ClassifyNewTrack(const G4Track*);

    void SetKillNeutrino(G4bool a);
    void SetKillNeutron(G4bool a);
    void SetDefaultValues();

  private:
    G4bool killnuetrinofun;
    G4bool killnuetronfun;

    stackingmessenger *fStackmessenger;
};


#endif

