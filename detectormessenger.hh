#ifndef detectormessenger_h
#define detectormessenger_h 


#include "G4UImessenger.hh"
#include "globals.hh"
#include "detectorconstruction.hh"
#include "G4UIcmdWith3VectorAndUnit.hh"
#include "G4UIcommand.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"

class detectorconstruction;

// hola mi primer cambio 
/// Detector construction class to define materials and geometry.

class detectormessenger : public  G4UImessenger
{
  public:
    detectormessenger(detectorconstruction* detector_);
    virtual ~detectormessenger();

    virtual void SetNewValue(G4UIcommand*, G4String);

  private:
    
    G4UIdirectory *fDetectorDir1, *fDetectorDir2, *fDetectorDir3, *fDetectorDir4;
    G4UIcmdWith3VectorAndUnit *pos_NaI1, *pos_NaI2, *pos_NaI3, *pos_NaI4;
    G4UIcmdWithADoubleAndUnit *angdet1, *angdet2, *angdet3, *angdet4;
    detectorconstruction *f_det;

    
};


#endif