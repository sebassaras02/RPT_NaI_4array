#include "event.hh"
#include "G4SystemOfUnits.hh"

// initialize constructor
eventaction::eventaction(runaction*){
    // create variable 
    fEdep1=0.;
    fEdep2=0.;
    fEdep3=0.;
    fEdep4=0.;
    tof1=0.;
}
// initialize destructor
eventaction::~eventaction(){}

// functions

void eventaction::BeginOfEventAction(const G4Event*){

    fEdep1=0.; // this reset the value of energy deposited in each event
    fEdep2=0.;
    fEdep3=0.;
    fEdep4=0.;
    tof1=0.;
}

void eventaction::EndOfEventAction(const G4Event*){
    
    // at the end of each event it is neccesary to save the data recolected
    G4AnalysisManager* man= G4AnalysisManager::Instance();

    if (fEdep1>0.0*MeV){
        man->FillNtupleDColumn(0,0,fEdep1);
        man->AddNtupleRow(0);
    }
    
    if (fEdep2>0.0*MeV){
        man->FillNtupleDColumn(1,0,fEdep2);
        man->AddNtupleRow(1);
    }
    
    if (fEdep3>0.0*MeV){
        man->FillNtupleDColumn(2,0,fEdep3);
        man->AddNtupleRow(2);
    }

    if (fEdep4>0.0*MeV){
        man->FillNtupleDColumn(3,0,fEdep4);
        man->AddNtupleRow(3);
    }
    
    if (tof1>0*ns){
        man->FillNtupleDColumn(4,0,tof1);
        man->AddNtupleRow(4);

    }

}
