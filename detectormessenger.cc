#include "detectormessenger.hh"

detectormessenger::detectormessenger(detectorconstruction* detector_):f_det(detector_){

  // first detector
  // set directory to change NaI
  fDetectorDir1 = new G4UIdirectory("/NaI/detector1/");
  fDetectorDir1->SetGuidance("Detector 1 geometry position");

  //Various commands for modifying detector 1 geometry
  pos_NaI1 = new G4UIcmdWith3VectorAndUnit("/NaI/detector1/dimensions",this);
  pos_NaI1->SetGuidance("Set the positions of the detector 1");
  pos_NaI1->SetParameterName("scint_x1","scint_y1","scint_z1",false);
  pos_NaI1->SetDefaultUnit("cm");
  pos_NaI1->AvailableForStates(G4State_PreInit,G4State_Idle);
  pos_NaI1->SetToBeBroadcasted(false);
  
  //Commands for modifying detector 1 angle
  angdet1 = new G4UIcmdWithADoubleAndUnit("/NaI/detector1/angle",this);
  angdet1->SetGuidance("Set angle of detector 1");
  angdet1->SetParameterName("ang_det1", false);
  angdet1->SetDefaultUnit("deg");
  angdet1->AvailableForStates(G4State_PreInit,G4State_Idle);
  angdet1->SetToBeBroadcasted(false);

  isRotx1 = new G4UIcmdWithABool("/NaI/detector1/rotX",this); 
  isRotx1->SetGuidance("Rotate the detector along X axis");
  isRotx1->AvailableForStates(G4State_PreInit,G4State_Idle);
  isRotx1->SetToBeBroadcasted(false);

  isRoty1 = new G4UIcmdWithABool("/NaI/detector1/rotY",this);
  isRoty1->SetGuidance("Rotate the detector along Y axis");
  isRoty1->AvailableForStates(G4State_PreInit,G4State_Idle);
  isRoty1->SetToBeBroadcasted(false);

  isRotz1 = new G4UIcmdWithABool("/NaI/detector1/rotZ",this);
  isRotz1->SetGuidance("Rotate the detector along Z axis");
  isRotz1->AvailableForStates(G4State_PreInit,G4State_Idle);
  isRotz1->SetToBeBroadcasted(false);
  
  // second detector
  // set directory to change NaI
  fDetectorDir2= new G4UIdirectory("/NaI/detector2/");
  fDetectorDir2->SetGuidance("Detector 2 geometry position");

  //Various commands for modifying detector 2 geometry
  pos_NaI2 = new G4UIcmdWith3VectorAndUnit("/NaI/detector2/dimensions",this);
  pos_NaI2->SetGuidance("Set the positions of the detector volume 2");
  pos_NaI2->SetParameterName("scint_x2","scint_y2","scint_z2",false);
  pos_NaI2->SetDefaultUnit("cm");
  pos_NaI2->AvailableForStates(G4State_PreInit,G4State_Idle);
  pos_NaI2->SetToBeBroadcasted(false);

  //Commands for modifying detector 2 angle
  angdet2 = new G4UIcmdWithADoubleAndUnit("/NaI/detector2/angle",this);
  angdet2->SetGuidance("Set angle of detector 2");
  angdet2->SetParameterName("ang_det2", false);
  angdet2->SetDefaultUnit("deg");
  angdet2->AvailableForStates(G4State_PreInit,G4State_Idle);
  angdet2->SetToBeBroadcasted(false);

  isRotx2 = new G4UIcmdWithABool("/NaI/detector2/rotX",this); 
  isRotx2->SetGuidance("Rotate the detector along X axis");
  isRotx2->AvailableForStates(G4State_PreInit,G4State_Idle);
  isRotx2->SetToBeBroadcasted(false);

  isRoty2 = new G4UIcmdWithABool("/NaI/detector2/rotY",this);
  isRoty2->SetGuidance("Rotate the detector along Y axis");
  isRoty2->AvailableForStates(G4State_PreInit,G4State_Idle);
  isRoty2->SetToBeBroadcasted(false);

  isRotz2 = new G4UIcmdWithABool("/NaI/detector2/rotZ",this);
  isRotz2->SetGuidance("Rotate the detector along Z axis");
  isRotz2->AvailableForStates(G4State_PreInit,G4State_Idle);
  isRotz2->SetToBeBroadcasted(false);

  // third detector
  // set directory to change NaI
  fDetectorDir3= new G4UIdirectory("/NaI/detector3/");
  fDetectorDir3->SetGuidance("Detector 3 geometry position");

  //Various commands for modifying detector 3 geometry
  pos_NaI3 = new G4UIcmdWith3VectorAndUnit("/NaI/detector3/dimensions",this);
  pos_NaI3->SetGuidance("Set the positions of the detector volume 2");
  pos_NaI3->SetParameterName("scint_x2","scint_y2","scint_z2",false);
  pos_NaI3->SetDefaultUnit("cm");
  pos_NaI3->AvailableForStates(G4State_PreInit,G4State_Idle);
  pos_NaI3->SetToBeBroadcasted(false);

  //Commands for modifying detector 3 angle
  angdet3 = new G4UIcmdWithADoubleAndUnit("/NaI/detector3/angle",this);
  angdet3->SetGuidance("Set angle of detector 3");
  angdet3->SetParameterName("ang_det3", false);
  angdet3->SetDefaultUnit("deg");
  angdet3->AvailableForStates(G4State_PreInit,G4State_Idle);
  angdet3->SetToBeBroadcasted(false);

  isRotx3 = new G4UIcmdWithABool("/NaI/detector3/rotX",this); 
  isRotx3->SetGuidance("Rotate the detector along X axis");
  isRotx3->AvailableForStates(G4State_PreInit,G4State_Idle);
  isRotx3->SetToBeBroadcasted(false);

  isRoty3 = new G4UIcmdWithABool("/NaI/detector3/rotY",this);
  isRoty3->SetGuidance("Rotate the detector along Y axis");
  isRoty3->AvailableForStates(G4State_PreInit,G4State_Idle);
  isRoty3->SetToBeBroadcasted(false);

  isRotz3 = new G4UIcmdWithABool("/NaI/detector3/rotZ",this);
  isRotz3->SetGuidance("Rotate the detector along Z axis");
  isRotz3->AvailableForStates(G4State_PreInit,G4State_Idle);
  isRotz3->SetToBeBroadcasted(false);

  // fourth detector
  // set directory to change NaI
  fDetectorDir4= new G4UIdirectory("/NaI/detector4/");
  fDetectorDir4->SetGuidance("Detector 4 geometry position");

  //Various commands for modifying detector 4 geometry
  pos_NaI4 = new G4UIcmdWith3VectorAndUnit("/NaI/detector4/dimensions",this);
  pos_NaI4->SetGuidance("Set the positions of the detector volume 2");
  pos_NaI4->SetParameterName("scint_x2","scint_y2","scint_z2",false);
  pos_NaI4->SetDefaultUnit("cm");
  pos_NaI4->AvailableForStates(G4State_PreInit,G4State_Idle);
  pos_NaI4->SetToBeBroadcasted(false);

  //Commands for modifying detector 4 angle
  angdet4 = new G4UIcmdWithADoubleAndUnit("/NaI/detector4/angle",this);
  angdet4->SetGuidance("Set angle of detector 4");
  angdet4->SetParameterName("ang_det4", false);
  angdet4->SetDefaultUnit("deg");
  angdet4->AvailableForStates(G4State_PreInit,G4State_Idle);
  angdet4->SetToBeBroadcasted(false);

  isRotx4 = new G4UIcmdWithABool("/NaI/detector4/rotX",this); 
  isRotx4->SetGuidance("Rotate the detector along X axis");
  isRotx4->AvailableForStates(G4State_PreInit,G4State_Idle);
  isRotx4->SetToBeBroadcasted(false);

  isRoty4 = new G4UIcmdWithABool("/NaI/detector4/rotY",this);
  isRoty4->SetGuidance("Rotate the detector along Y axis");
  isRoty4->AvailableForStates(G4State_PreInit,G4State_Idle);
  isRoty4->SetToBeBroadcasted(false);

  isRotz4 = new G4UIcmdWithABool("/NaI/detector4/rotZ",this);
  isRotz4->SetGuidance("Rotate the detector along Z axis");
  isRotz4->AvailableForStates(G4State_PreInit,G4State_Idle);
  isRotz4->SetToBeBroadcasted(false);

  // Pipe properties
  // Set directory to change the pipe properties
  UIfpipe = new G4UIdirectory("/pipe/");
  UIfpipe->SetGuidance("Change pipe length");

  // commands to create cylinder
  isCyl = new G4UIcmdWithABool("/pipe/cyl/activate",this);
  isCyl->SetGuidance("Create a cylinder pipe");
  isCyl->AvailableForStates(G4State_PreInit,G4State_Idle);
  isCyl->SetToBeBroadcasted(false);

  // commands to change cylinder pipe's geometry
  fpipe_cyl = new G4UIcmdWith3VectorAndUnit("/pipe/cyl/dim",this);
  fpipe_cyl->SetGuidance("Set thickness, radious, and length of the pipe in cm");
  fpipe_cyl->SetParameterName("thickness","radious","length",false);
  fpipe_cyl->SetDefaultUnit("cm");
  fpipe_cyl->AvailableForStates(G4State_PreInit,G4State_Idle);
  fpipe_cyl->SetToBeBroadcasted(false);

  // commands to create box
  isBox = new G4UIcmdWithABool("/pipe/box/activate",this);
  isBox->SetGuidance("Create a box pipe");
  isBox->AvailableForStates(G4State_PreInit,G4State_Idle);
  isBox->SetToBeBroadcasted(false);

  // commands to change cylinder pipe's geometry
  fpipe_box = new G4UIcmdWith3VectorAndUnit("/pipe/box/dim",this);
  fpipe_box->SetGuidance("Set x, y, and z dimensions of the pipe in cm (x is the depth, and x-y the perpendicular surface)");
  fpipe_box->SetParameterName("x-length","y-length","z-length",false);
  fpipe_box->SetDefaultUnit("cm");
  fpipe_box->AvailableForStates(G4State_PreInit,G4State_Idle);
  fpipe_box->SetToBeBroadcasted(false);

}

detectormessenger::~detectormessenger(){
  delete pos_NaI1;
  delete pos_NaI2;
  delete pos_NaI3;
  delete pos_NaI4;
  delete pos_NaI4;
  delete angdet1;
  delete angdet2;
  delete angdet3;
  delete angdet4;
  delete fpipe_cyl;
  delete fpipe_box;
  delete isBox;
  delete isCyl;
  delete isRotx1, delete isRoty1, delete isRotz1;
  delete isRotx2, delete isRoty2, delete isRotz2;
  delete isRotx3, delete isRoty3, delete isRotz3;
  delete isRotx4, delete isRoty4, delete isRotz4;
}

void detectormessenger::SetNewValue(G4UIcommand* command, G4String newValue)
{

  if( command == fpipe_cyl ){
    f_det->SetPipeDimCyl(fpipe_cyl->GetNew3VectorValue(newValue));
  }

  if( command == fpipe_box ){
    f_det->SetPipeDimBox(fpipe_box->GetNew3VectorValue(newValue));
  }

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

  if( command == angdet1 ){
    f_det->SetAng_NaI1(angdet1->GetNewDoubleValue(newValue));
  }

  if( command == angdet2 ){
    f_det->SetAng_NaI2(angdet2->GetNewDoubleValue(newValue));
  }

  if( command == angdet3 ){
    f_det->SetAng_NaI3(angdet3->GetNewDoubleValue(newValue));
  }

  
  if( command == angdet4 ){
    f_det->SetAng_NaI4(angdet4->GetNewDoubleValue(newValue));
  }

  if( command == isBox ){
    f_det->SetPipeBox(isBox->GetNewBoolValue(newValue));
  }

  if( command == isCyl ){
    f_det->SetPipeCyl(isCyl->GetNewBoolValue(newValue));
  }

  if( command == isRotx1 ){
    f_det->Set_Rotate_X_NaI1(isRotx1->GetNewBoolValue(newValue));
  }

  if( command == isRoty1 ){
    f_det->Set_Rotate_Y_NaI1(isRoty1->GetNewBoolValue(newValue));
  }

  if( command == isRotz1 ){
    f_det->Set_Rotate_Z_NaI1(isRotz1->GetNewBoolValue(newValue));
  }


  if( command == isRotx2 ){
    f_det->Set_Rotate_X_NaI2(isRotx2->GetNewBoolValue(newValue));
  }

  if( command == isRoty2 ){
    f_det->Set_Rotate_Y_NaI2(isRoty2->GetNewBoolValue(newValue));
  }

  if( command == isRotz2 ){
    f_det->Set_Rotate_Z_NaI2(isRotz2->GetNewBoolValue(newValue));
  }

  if( command == isRotx3 ){
    f_det->Set_Rotate_X_NaI3(isRotx3->GetNewBoolValue(newValue));
  }

  if( command == isRoty3 ){
    f_det->Set_Rotate_Y_NaI3(isRoty3->GetNewBoolValue(newValue));
  }

  if( command == isRotz3 ){
    f_det->Set_Rotate_Z_NaI3(isRotz3->GetNewBoolValue(newValue));
  }

  if( command == isRotx4 ){
    f_det->Set_Rotate_X_NaI4(isRotx4->GetNewBoolValue(newValue));
  }

  if( command == isRoty4 ){
    f_det->Set_Rotate_Y_NaI4(isRoty4->GetNewBoolValue(newValue));
  }

  if( command == isRotz4 ){
    f_det->Set_Rotate_Z_NaI4(isRotz4->GetNewBoolValue(newValue));
  }


}

