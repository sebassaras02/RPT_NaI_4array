#include "detectormessenger.hh"

detectormessenger::detectormessenger(detectorconstruction* detector_):f_det(detector_){

  // first detector
  // set directory to change NaI
  fDetectorDir1 = new G4UIdirectory("/NaI/detector1/");
  fDetectorDir1->SetGuidance("Detector 1 geometry position");

  //Various commands for modifying detector geometry
  pos_NaI1 = new G4UIcmdWith3VectorAndUnit("/NaI/detector1/dimensions",this);
  pos_NaI1->SetGuidance("Set the positions of the detector volume 1");
  pos_NaI1->SetParameterName("scint_x1","scint_y1","scint_z1",false);
  pos_NaI1->SetDefaultUnit("cm");
  pos_NaI1->AvailableForStates(G4State_PreInit,G4State_Idle);
  pos_NaI1->SetToBeBroadcasted(false);

  // second detector
  // set directory to change NaI
  fDetectorDir2= new G4UIdirectory("/NaI/detector2/");
  fDetectorDir2->SetGuidance("Detector 2 geometry position");

  //Various commands for modifying detector geometry
  pos_NaI2 = new G4UIcmdWith3VectorAndUnit("/NaI/detector2/dimensions",this);
  pos_NaI2->SetGuidance("Set the positions of the detector volume 2");
  pos_NaI2->SetParameterName("scint_x2","scint_y2","scint_z2",false);
  pos_NaI2->SetDefaultUnit("cm");
  pos_NaI2->AvailableForStates(G4State_PreInit,G4State_Idle);
  pos_NaI2->SetToBeBroadcasted(false);

  // third detector
  // set directory to change NaI
  fDetectorDir3= new G4UIdirectory("/NaI/detector3/");
  fDetectorDir3->SetGuidance("Detector 3 geometry position");

  //Various commands for modifying detector geometry
  pos_NaI3 = new G4UIcmdWith3VectorAndUnit("/NaI/detector3/dimensions",this);
  pos_NaI3->SetGuidance("Set the positions of the detector volume 2");
  pos_NaI3->SetParameterName("scint_x2","scint_y2","scint_z2",false);
  pos_NaI3->SetDefaultUnit("cm");
  pos_NaI3->AvailableForStates(G4State_PreInit,G4State_Idle);
  pos_NaI3->SetToBeBroadcasted(false);

  // fourth detector
  // set directory to change NaI
  fDetectorDir4= new G4UIdirectory("/NaI/detector4/");
  fDetectorDir4->SetGuidance("Detector 4 geometry position");

  //Various commands for modifying detector geometry
  pos_NaI4 = new G4UIcmdWith3VectorAndUnit("/NaI/detector4/dimensions",this);
  pos_NaI4->SetGuidance("Set the positions of the detector volume 2");
  pos_NaI4->SetParameterName("scint_x2","scint_y2","scint_z2",false);
  pos_NaI4->SetDefaultUnit("cm");
  pos_NaI4->AvailableForStates(G4State_PreInit,G4State_Idle);
  pos_NaI4->SetToBeBroadcasted(false);
}

detectormessenger::~detectormessenger(){
  delete pos_NaI1;
  delete pos_NaI2;
  delete pos_NaI3;
  delete pos_NaI4;
}

void detectormessenger::SetNewValue(G4UIcommand* command, G4String newValue)
{
  if( command == pos_NaI1 ){
    f_det->SetPos_NaI1(pos_NaI1->GetNew3VectorValue(newValue));
  }

  if( command == pos_NaI2 ){
    f_det->SetPos_NaI2(pos_NaI2->GetNew3VectorValue(newValue));
  }

  if( command == pos_NaI3 ){
    f_det->SetPos_NaI3(pos_NaI3->GetNew3VectorValue(newValue));
  }

  if( command == pos_NaI4 ){
    f_det->SetPos_NaI4(pos_NaI4->GetNew3VectorValue(newValue));
  }
}

