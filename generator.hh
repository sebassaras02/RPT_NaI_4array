#ifndef generator_hh

#define generator_hh

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4GeneralParticleSource.hh"
#include "G4SystemOfUnits.hh"
#include "G4ParticleTable.hh"

class primarygenerator: public G4VUserPrimaryGeneratorAction{
    public:
    primarygenerator();
    ~primarygenerator();
    
    virtual void GeneratePrimaries(G4Event*);
    // this is because the only one function needed is Generate Primaries and this inpunts have to be an varible of type G4Event
    private:
    G4GeneralParticleSource* fparticlegun;
    
};
#endif
