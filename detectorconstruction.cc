#include "detectorconstruction.hh"


// contructor
detectorconstruction::detectorconstruction()
{
  
  // default values

  fmessenger=  new detectormessenger(this);
  DefaultValues();
  DefineMaterials();

}
// destructor
detectorconstruction::~detectorconstruction()
{}
// function for default values of messenger
void detectorconstruction::DefaultValues(){
  // pipe
  ra_pipe=2*cm;
  len_pipe=0.5*m;
  th_pipe=0.01*cm;
  // first detector
  posX1=-20*cm; 
  posY1=0*cm;
  posZ1=20*cm;
  // second detector
  posX2=-20*cm; 
  posY2=0*cm;
  posZ2=-20*cm;
  // third detector)
  posX3=20*cm;  
  posY3=0*cm;
  posZ3=20*cm;
  // fourth detector
  posX4=20*cm;  
  posY4=0*cm;
  posZ4=-20*cm;
  // angles for detectors
  ang1=180*deg;
  ang2=0*deg;
  ang3=180*deg;
  ang4=0*deg;
  // default values for the box pipe
  len_pipebox=0.5*m;
  y_pipe=(15/2)*cm;
  z_pipe=(15/2)*cm;
  // default values to construct the kind og pipe
  isPipeBox=true;
  isPipeCylinder=false;
}
// 

// define the action constructors
// first detector

void detectorconstruction::SetPipeDimCyl(G4ThreeVector pipe_dim) {
  th_pipe=pipe_dim[0];
  ra_pipe=pipe_dim[1];
  len_pipe=pipe_dim[2];
  G4RunManager::GetRunManager()->ReinitializeGeometry();
}

void detectorconstruction::SetPipeDimBox(G4ThreeVector pipe_dim) {
  len_pipebox=pipe_dim[0];
  y_pipe=pipe_dim[1];
  z_pipe=pipe_dim[2];
  G4RunManager::GetRunManager()->ReinitializeGeometry();
}

void detectorconstruction::SetPos_NaI1(G4ThreeVector dims) {
  posX1=dims[0];
  posY1=dims[1];
  posZ1=dims[2];
  G4RunManager::GetRunManager()->ReinitializeGeometry();
}

void detectorconstruction::SetPos_NaI2(G4ThreeVector dims) {
  posX2=dims[0];
  posY2=dims[1];
  posZ2=dims[2];
  G4RunManager::GetRunManager()->ReinitializeGeometry();
}

void detectorconstruction::SetPos_NaI3(G4ThreeVector dims) {
  posX3=dims[0];
  posY3=dims[1];
  posZ3=dims[2];
  G4RunManager::GetRunManager()->ReinitializeGeometry();
}

void detectorconstruction::SetPos_NaI4(G4ThreeVector dims) {
  posX4=dims[0];
  posY4=dims[1];
  posZ4=dims[2];
  G4RunManager::GetRunManager()->ReinitializeGeometry();
}

void detectorconstruction::SetAng_NaI1(G4double ang) {
  ang1=ang;
  G4RunManager::GetRunManager()->ReinitializeGeometry();
}

void detectorconstruction::SetAng_NaI2(G4double ang) {
  ang2=ang;
  G4RunManager::GetRunManager()->ReinitializeGeometry();
}

void detectorconstruction::SetAng_NaI3(G4double ang) {
  ang3=ang;
  G4RunManager::GetRunManager()->ReinitializeGeometry();
}

void detectorconstruction::SetAng_NaI4(G4double ang) {
  ang4=ang;
  G4RunManager::GetRunManager()->ReinitializeGeometry();
}

void detectorconstruction::SetPipeCyl(G4bool g1){
  isPipeCylinder=g1;
  if (g1==true){
    isPipeBox=false;
  }
  G4RunManager::GetRunManager()->ReinitializeGeometry();
}

void detectorconstruction::SetPipeBox(G4bool g1){
  isPipeBox=g1;
  if (g1==true){
    isPipeCylinder=false;
  }
  G4RunManager::GetRunManager()->ReinitializeGeometry();
}

// define a function of materials

void detectorconstruction::DefineMaterials(){
    G4NistManager*  nist = G4NistManager::Instance();
    nist->SetVerbose(1);
    air = nist->FindOrBuildMaterial("G4_AIR");
    cu= nist->FindOrBuildMaterial("G4_Cu");
    water= nist->FindOrBuildMaterial("G4_WATER");
    al_mat = nist->FindOrBuildMaterial("G4_Al");
    si_mat = nist->FindOrBuildMaterial("G4_SILICON_DIOXIDE");
    mg_mat = nist->FindOrBuildMaterial("G4_MAGNESIUM_OXIDE");
    na_mat = nist->FindOrBuildMaterial("G4_SODIUM_IODIDE");
}

void detectorconstruction::ConstructCylinderPipe(){
  // DEFINE PIPE LINE
    // solid
    // define thickness
    
    pipe_solid= new G4Tubs ("pipe_solid",0*cm,(ra_pipe+th_pipe),len_pipe,0.*deg,360.*deg);
    pipe_logic= new G4LogicalVolume(pipe_solid, cu,"pipe_logic");
    // define rotation matrix
    m_rot= new G4RotationMatrix();
    m_rot->rotateY(90.*deg);
    // define physical volume
    pipe_phys= new G4PVPlacement(m_rot,                       //no rotation
                G4ThreeVector(),                    //at position
                pipe_logic,                //its logical volume
                "pipe_phys",              //its name
                logicWorld,                   //its mother  volume
                false,                   //no boolean operation
                0,                       //copy number
                true);          //overlaps checking
    

    // define the water inside the pipe
    water_solid= new G4Tubs ("water_solid",0*cm,ra_pipe,(len_pipe-0.001*cm),0.*deg,360.*deg);
    water_logic= new G4LogicalVolume(water_solid, water,"water_logic");
    // define physical volume
    water_phys= new G4PVPlacement(0,                       //no rotation
                G4ThreeVector(),                    //at position
                water_logic,                //its logical volume
                "water_phys",              //its name
                pipe_logic,                   //its mother  volume
                false,                   //no boolean operation
                0,                       //copy number
                true);          //overlaps checking
}

void detectorconstruction::ConstructBoxPipe(){
  // DEFINE PIPE LINE
    // solid
    // define thickness
    
    cuadbox_solid = new G4Box ("pipe_solid",len_pipebox,y_pipe,z_pipe);
    pipe_logic    = new G4LogicalVolume(cuadbox_solid, cu,"pipe_logic");

    // define physical volume
    pipe_phys= new G4PVPlacement(m_rot,                       //no rotation
                G4ThreeVector(),                    //at position
                pipe_logic,                //its logical volume
                "pipe_phys",              //its name
                logicWorld,                   //its mother  volume
                false,                   //no boolean operation
                0,                       //copy number
                true);          //overlaps checking
    

    // define the water inside the pipe
    water_solid_box = new G4Box ("water_solid",len_pipebox,(y_pipe-0.001*cm),(z_pipe-0.001*cm));
    water_logic     = new G4LogicalVolume(water_solid_box, water,"water_logic");
    // define physical volume
    water_phys= new G4PVPlacement(0,                       //no rotation
                G4ThreeVector(),                    //at position
                water_logic,                //its logical volume
                "water_phys",              //its name
                pipe_logic,                //its mother  volume
                false,                   //no boolean operation
                0,                       //copy number
                true);          //overlaps checking
}


void detectorconstruction::ConstructNaI1()
{
// define aluminium layer
    // define solid
    al_solid= new G4Tubs ("al_solid",0.0*cm,4.045*cm,4.1025*cm,0.*deg,360.*deg);
    // define logic
    al_logic= new G4LogicalVolume(al_solid,         //its solid
                                                    al_mat,                 //its material
                                                    "Aluminium_logic");         //its name
    G4ThreeVector ps_d1= G4ThreeVector (posX1, posY1, posZ1);

    // define rotation matrix
    m_rot1= new G4RotationMatrix();
    m_rot1->rotateY(ang1);

    // define physical volume
    al_phys= new G4PVPlacement(m_rot1,                       //no rotation
                    ps_d1,                    //at position
                    al_logic,                //its logical volume
                    "detector_1",              //its name
                    logicWorld,                   //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    true);          //overlaps checking
                    
    // define SiO2 layer
    // define solid
    si_solid= new G4Tubs ("si_solid",0.0*cm,3.995*cm,0.15*cm,0.*deg,360.*deg);
    // define logic
    si_logic= new G4LogicalVolume(si_solid,         //its solid
                                                    si_mat,                 //its material
                                                  "si_logic");         //its name
    
    // define physical volume
    si_phys= new G4PVPlacement(0,                       //no rotation
                    pos2,                    //at position
                    si_logic,                //its logical volume
                    "si_phys",              //its name
                    al_logic,                   //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    true);          //overlaps checking
                    
    // define MgO layer
    // define solid
    mg_solid= new G4Tubs ("mg_solid",0.0*cm,3.995*cm,3.9025*cm,0.*deg,360.*deg);
    // define logic
    mg_logic= new G4LogicalVolume(mg_solid,         //its solid
                                                    mg_mat,                 //its material
                                                  "mg_logic");         //its name
    
    // define physical volume
    mg_phys= new G4PVPlacement(0,                       //no rotation
                    pos3,                    //at position
                    mg_logic,                //its logical volume
                    "mg_phys",              //its name
                    al_logic,                   //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    true);          //overlaps checking
    
    
    // define solid
    na_solid= new G4Tubs ("na_solid",0.0*cm,3.81*cm,3.81*cm,0.*deg,360.*deg);
    // define logic
    logic_nai1 =  new G4LogicalVolume(na_solid,         //its solid
                        na_mat,                 //its material
                        "na_logic");         //its name
               
        
    na_phys1=new G4PVPlacement(0,                       //no rotation
                    pos4,                    //at position
                    logic_nai1,             //its logical volume
                    "na_phys",              //its name
                    mg_logic,              //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    true);          //overlaps checking
                    
    fScoringVolume1=logic_nai1;
}

// add properties and volumenes
G4VPhysicalVolume* detectorconstruction::Construct()
{
    // define the world 
    // define the size
    G4double long_x1= 1*m;
    G4double long_y1= 1*m;
    G4double long_z1= 1*m;
    
    
    // define world solid
    solidWorld =    
    new G4Box("World",                       //its name
        long_x1, long_y1, long_z1);           //its size
    // define world logic
    logicWorld =                         
    new G4LogicalVolume(solidWorld,          //its solid
                        air,           //its material
                        "World");            //its name
                                    
    // define physics solid
    physWorld = 
    new G4PVPlacement(0,                     //no rotation
                      G4ThreeVector(),       //at (0,0,0)
                      logicWorld,            //its logical volume
                      "World",               //its name
                      0,                     //its mother  volume
                      false,                 //no boolean operation
                      0,                     //copy number
                      true);        //overlaps checking
                     
    // DEFINE PIPE LINE
    
    if (isPipeBox==true){
      ConstructBoxPipe();
    }

    if (isPipeCylinder==true){
      ConstructCylinderPipe();
    }

    // DEFINE DETECTORS GEOMETRIES


    // FIRST DETECTOR
    ConstructNaI1();
   
    // SECOND DETECTOR
    
     // define aluminium layer
    // define logic
    G4ThreeVector pos5 = G4ThreeVector(posX2,posY2,posZ2);
    
    al_logic2= new G4LogicalVolume(al_solid,         //its solid
                                                    al_mat,                 //its material
                                                    "Aluminium_logic");         //its name
    
    // define rotation matrix
    m_rot2= new G4RotationMatrix();
    m_rot2->rotateY(ang2);
    
    // define physical volume
    al_phys2= new G4PVPlacement(m_rot2,                       //no rotation
                    pos5,                    //at position
                    al_logic2,                //its logical volume
                    "detector_2",              //its name
                    logicWorld,                   //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    true);          //overlaps checking
                    
    // define SiO2 layer
    // define logic
    si_logic2= new G4LogicalVolume(si_solid,         //its solid
                                                    si_mat,                 //its material
                                                  "si_logic");         //its name
            
    // define physical volume
    si_phys2= new G4PVPlacement(0,                       //no rotation
                    pos2,                    //at position
                    si_logic2,                //its logical volume
                    "si_phys",              //its name
                    al_logic2,                   //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    true);          //overlaps checking
                    
    // define MgO layer
    // define logic
    mg_logic2= new G4LogicalVolume(mg_solid,         //its solid
                                                    mg_mat,                 //its material
                                                  "mg_logic");         //its name
    // define physical volume
    mg_phys2=new G4PVPlacement(0,                       //no rotation
                    pos3,                    //at position
                    mg_logic2,                //its logical volume
                    "mg_phys",              //its name
                    al_logic2,                   //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    true);          //overlaps checking

    logic_nai2 =  new G4LogicalVolume(na_solid,         //its solid
                        na_mat,                 //its material
                        "na_logic");         //its name
               
    na_phys2= new G4PVPlacement(0,                       //no rotation
                     pos4,                    //at position
                    logic_nai2,             //its logical volume
                    "na_phys2",              //its name
                    mg_logic2,              //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    true);          //overlaps checking
    
    fScoringVolume2=logic_nai2;


    // THIRD DETECTOR
    
     // define aluminium layer
    // define logic
    G4ThreeVector pos6 = G4ThreeVector(posX3,posY3,posZ3);
    
    al_logic3= new G4LogicalVolume(al_solid,         //its solid
                                                    al_mat,                 //its material
                                                    "Aluminium_logic");         //its name
    
    // define rotation matrix
    m_rot3= new G4RotationMatrix();
    m_rot3->rotateY(ang3);
    

    // define physical volume
    al_phys3= new G4PVPlacement(m_rot3,                       //no rotation
                    pos6,                    //at position
                    al_logic3,                //its logical volume
                    "detector_3",              //its name
                    logicWorld,                   //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    true);          //overlaps checking
                    
    // define SiO2 layer
    // define logic
    si_logic3= new G4LogicalVolume(si_solid,         //its solid
                                                    si_mat,                 //its material
                                                  "si_logic");         //its name
            
    // define physical volume
    si_phys3 = new G4PVPlacement(0,                       //no rotation
                    pos2,                    //at position
                    si_logic3,                //its logical volume
                    "si_phys",              //its name
                    al_logic3,                   //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    true);          //overlaps checking
                    
    // define MgO layer
    // define logic
    mg_logic3= new G4LogicalVolume(mg_solid,         //its solid
                                                    mg_mat,                 //its material
                                                  "mg_logic");         //its name
    // define physical volume
    mg_phys3= new G4PVPlacement(0,                       //no rotation
                    pos3,                    //at position
                    mg_logic3,                //its logical volume
                    "mg_phys",              //its name
                    al_logic3,                   //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    true);          //overlaps checking

    logic_nai3 =  new G4LogicalVolume(na_solid,         //its solid
                        na_mat,                 //its material
                        "na_logic");         //its name
               
    na_phys3= new G4PVPlacement(0,                       //no rotation
                     pos4,                    //at position
                    logic_nai3,             //its logical volume
                    "na_phys2",              //its name
                    mg_logic3,              //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    true);          //overlaps checking
    
    fScoringVolume3=logic_nai3;

    // FOURTH DETECTOR
    
    // define aluminium layer
    // define logic
    G4ThreeVector pos7 = G4ThreeVector(posX4,posY4,posZ4);
    
    al_logic4= new G4LogicalVolume(al_solid,         //its solid
                                                    al_mat,                 //its material
                                                    "Aluminium_logic");         //its name
    
    // define rotation matrix
    m_rot4= new G4RotationMatrix();
    m_rot4->rotateY(ang4);
    
    
    // define physical volume
    al_phys4= new G4PVPlacement(m_rot4,                       //no rotation
                    pos7,                    //at position
                    al_logic4,                //its logical volume
                    "detector_4",              //its name
                    logicWorld,                   //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    true);          //overlaps checking
                    
    // define SiO2 layer
    // define logic
    si_logic4= new G4LogicalVolume(si_solid,         //its solid
                                                    si_mat,                 //its material
                                                  "si_logic");         //its name
            
    // define physical volume
    si_phys4= new G4PVPlacement(0,                       //no rotation
                    pos2,                    //at position
                    si_logic4,                //its logical volume
                    "si_phys",              //its name
                    al_logic4,                   //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    true);          //overlaps checking
                    
    // define MgO layer
    // define logic
    mg_logic4= new G4LogicalVolume(mg_solid,         //its solid
                                                    mg_mat,                 //its material
                                                  "mg_logic");         //its name
    // define physical volume
    mg_phys4= new G4PVPlacement(0,                       //no rotation
                    pos3,                    //at position
                    mg_logic4,                //its logical volume
                    "mg_phys",              //its name
                    al_logic4,                   //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    true);          //overlaps checking

    logic_nai4 =  new G4LogicalVolume(na_solid,         //its solid
                        na_mat,                 //its material
                        "na_logic");         //its name
               
    na_phys4= new G4PVPlacement(0,                       //no rotation
                     pos4,                    //at position
                    logic_nai4,             //its logical volume
                    "na_phys2",              //its name
                    mg_logic4,              //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    true);          //overlaps checking
    
    fScoringVolume4=logic_nai4;

  // VISUALIZATION ATRIBUTES

  logicWorld->SetVisAttributes (G4VisAttributes::GetInvisible());

  auto pipe_VisAtt= new G4VisAttributes(G4Colour(0.0,0.0,1.0));
  pipe_VisAtt->SetVisibility(true);
  pipe_logic->SetVisAttributes(pipe_VisAtt);
  water_logic->SetVisAttributes(pipe_VisAtt);

  // visualization atributes for first detector 
  // red one
  auto dt1_VisAtt= new G4VisAttributes(G4Colour(1.0,0.0,0.0));
  dt1_VisAtt->SetVisibility(true);
  al_logic->SetVisAttributes(dt1_VisAtt);
  logic_nai1->SetVisAttributes(dt1_VisAtt);
  si_logic->SetVisAttributes(dt1_VisAtt);
  mg_logic->SetVisAttributes(dt1_VisAtt);


  // visualization atributes for second detector
  // green one
  auto dt2_VisAtt= new G4VisAttributes(G4Colour(0.0,1.0,0.0));
  dt2_VisAtt->SetVisibility(true);
  al_logic2->SetVisAttributes(dt2_VisAtt);
  logic_nai2->SetVisAttributes(dt2_VisAtt);
  si_logic2->SetVisAttributes(dt2_VisAtt);
  mg_logic2->SetVisAttributes(dt2_VisAtt);


  // visualization atributes for third detector
  // yellow one
  auto dt3_VisAtt= new G4VisAttributes(G4Colour(1.0,1.0,0.0));
  dt3_VisAtt->SetVisibility(true);
  al_logic3->SetVisAttributes(dt3_VisAtt);
  logic_nai3->SetVisAttributes(dt3_VisAtt);
  si_logic3->SetVisAttributes(dt3_VisAtt);
  mg_logic3->SetVisAttributes(dt3_VisAtt);

  // visualization atributes for fourth detector
  // magenta one
  auto dt4_VisAtt= new G4VisAttributes(G4Colour(1.0,0.0,1.0));
  dt4_VisAtt->SetVisibility(true);
  al_logic4->SetVisAttributes(dt4_VisAtt);
  logic_nai4->SetVisAttributes(dt4_VisAtt);
  si_logic4->SetVisAttributes(dt4_VisAtt);
  mg_logic4->SetVisAttributes(dt4_VisAtt);
    
  
  
  return physWorld;
}



