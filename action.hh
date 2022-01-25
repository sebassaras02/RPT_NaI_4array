#ifndef action_hh

#define action_hh

//call mandatory class
#include "G4VUserActionInitialization.hh"
#include "runaction.hh"

class actioninitialization: public G4VUserActionInitialization{
    public:
    actioninitialization();
    ~actioninitialization();
    
    virtual void Build() const;
    virtual void BuildForMaster() const;
    
};
#endif
