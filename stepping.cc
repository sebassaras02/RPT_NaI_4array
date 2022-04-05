#include "stepping.hh"
#include "G4RunManager.hh"



steppingaction::steppingaction(eventaction* eventAction){
    
    fEventAction=eventAction;
}

steppingaction::~steppingaction(){}

void steppingaction::UserSteppingAction (const G4Step* step){
    
    const detectorconstruction* detectorConstruction = static_cast<const detectorconstruction*>
        (G4RunManager::GetRunManager()->GetUserDetectorConstruction());
        
    G4LogicalVolume* fScoringVolume1 = detectorConstruction->GetScoringVolume1();
    G4LogicalVolume* fScoringVolume2 = detectorConstruction->GetScoringVolume2();
    G4LogicalVolume* fScoringVolume3 = detectorConstruction->GetScoringVolume3();
    G4LogicalVolume* fScoringVolume4 = detectorConstruction->GetScoringVolume4();
    
    G4LogicalVolume *volume = step->GetPreStepPoint()->GetTouchableHandle()
      ->GetVolume()->GetLogicalVolume();
      
    G4double edep= step->GetTotalEnergyDeposit();
    
    G4int k1=0;

    if (volume == fScoringVolume1 && k1==0) {
        G4StepPoint *preStepPoint = step->GetPreStepPoint();
        G4double tof1 = preStepPoint->GetGlobalTime();
        k1+=1;
        fEventAction->AddTOF1(tof1);
    }

    if (volume == fScoringVolume1) {
        fEventAction->AddEdep1(edep);
    }
    else if(volume == fScoringVolume2) {
        fEventAction->AddEdep2(edep);
    }
    else if(volume == fScoringVolume3) {
        fEventAction->AddEdep3(edep);
    }
    else if(volume == fScoringVolume4) {
        fEventAction->AddEdep4(edep);
    }

    
    
}
