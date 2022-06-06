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

    G4Track *track = step->GetTrack();
    
    if (volume == fScoringVolume1) {
        fEventAction->AddEdep1(edep);

        G4bool st1 = step->IsFirstStepInVolume();
        
        if (st1 == true){
            G4double tof1 = track->GetGlobalTime();
            fEventAction->AddTOF1(tof1);
        }
    }
    else if(volume == fScoringVolume2) {
        fEventAction->AddEdep2(edep);
        
        G4bool st2= step->IsFirstStepInVolume();
        
        if (st2 == true){
            G4double tof2 = track->GetGlobalTime();
            fEventAction->AddTOF2(tof2);
        }
    }
    else if(volume == fScoringVolume3) {
        fEventAction->AddEdep3(edep);

        G4bool st3= step->IsFirstStepInVolume();
        
        if (st3 == true){
            G4double tof3 = track->GetGlobalTime();
            fEventAction->AddTOF3(tof3);
        }

    }
    else if(volume == fScoringVolume4) {
        fEventAction->AddEdep4(edep);

        G4bool st4= step->IsFirstStepInVolume();
        
        if (st4 == true){
            G4double tof4 = track->GetGlobalTime();
            fEventAction->AddTOF4(tof4);
        }

    }

    
    
}
