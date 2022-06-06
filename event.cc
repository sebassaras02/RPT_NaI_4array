#include "event.hh"
#include "G4SystemOfUnits.hh"

// initialize constructor
eventaction::eventaction(runaction* runAction){
    // create variable 
    fEdep1=0.;
    fEdep2=0.;
    fEdep3=0.;
    fEdep4=0.;
    fRunAction=runAction;
    tof1=0.;
    tof2=0.;
    tof3=0.;
    tof4=0.;
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
    tof2=0.;
    tof3=0.;
    tof4=0.;
}

void eventaction::EndOfEventAction(const G4Event*){
    
    // at the end of each event it is neccesary to save the data recolected
    G4AnalysisManager* man= G4AnalysisManager::Instance();

    if (fEdep1>0.0*MeV){
        man->FillNtupleDColumn(0,0,fEdep1);
        man->AddNtupleRow(0);
        fRunAction->AddEventEdep1(fEdep1);
    }
    
    if (fEdep2>0.0*MeV){
        man->FillNtupleDColumn(1,0,fEdep2);
        man->AddNtupleRow(1);
        fRunAction->AddEventEdep2(fEdep2);
    }
    
    if (fEdep3>0.0*MeV){
        man->FillNtupleDColumn(2,0,fEdep3);
        man->AddNtupleRow(2);
        fRunAction->AddEventEdep3(fEdep3);
    }

    if (fEdep4>0.0*MeV){
        man->FillNtupleDColumn(3,0,fEdep4);
        man->AddNtupleRow(3);
        fRunAction->AddEventEdep4(fEdep4);
    }
    
    if (tof1>0*ns){
        man->FillNtupleDColumn(4,0,tof1);
        man->AddNtupleRow(4);

    }

    if (tof2>0*ns){
        man->FillNtupleDColumn(5,0,tof2);
        man->AddNtupleRow(5);

    }

    if (tof3>0*ns){
        man->FillNtupleDColumn(6,0,tof3);
        man->AddNtupleRow(6);

    }

    if (tof4>0*ns){
        man->FillNtupleDColumn(7,0,tof4);
        man->AddNtupleRow(7);

    }

}
