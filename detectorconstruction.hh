// define de header file 
// it's telling that please if is not define something (detector construction)
#ifndef detectorconstruction_hh
// please define detector construction with the next stuffs
#define detectorconstruction_hh

#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
// charge the class which helps to allow our own units
#include "G4SystemOfUnits.hh"
// charge classes for material definitions
#include "G4Isotope.hh"
#include "G4Element.hh"
#include "G4Material.hh"
#include "G4UnitsTable.hh"
// classes for NIST data base
#include "globals.hh"
#include "G4Material.hh"
#include "G4NistManager.hh"
// classes for solids
#include "G4Tubs.hh"
#include "G4Box.hh"
// clases for boleean operations
#include "G4SubtractionSolid.hh"
#include "G4UnionSolid.hh"
// classes for logical and physical volumes
#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4ThreeVector.hh"
#include "G4GenericMessenger.hh"
#include "G4VisAttributes.hh"
#include "G4RunManager.hh"
#include "detectormessenger.hh"


class detectormessenger;

// define the class
class detectorconstruction:public G4VUserDetectorConstruction
{
    // creater class constructor and  destructor
    public:
    detectorconstruction();
    ~detectorconstruction();
    
    G4LogicalVolume *GetScoringVolume1() const {return fScoringVolume1;}
    G4LogicalVolume *GetScoringVolume2() const {return fScoringVolume2;}
    G4LogicalVolume *GetScoringVolume3() const {return fScoringVolume3;}
    G4LogicalVolume *GetScoringVolume4() const {return fScoringVolume4;}

    // for detector position messegers
    void SetPos_NaI1(G4ThreeVector dims);
    void SetPos_NaI2(G4ThreeVector dims);
    void SetPos_NaI3(G4ThreeVector dims);
    void SetPos_NaI4(G4ThreeVector dims);

    // for detector angle messenger along Y axis
    void SetAng_NaI1(G4double ang);
    void SetAng_NaI2(G4double ang);
    void SetAng_NaI3(G4double ang);
    void SetAng_NaI4(G4double ang);

 
    // for pipe messenger
    void SetPipeDimCyl(G4ThreeVector pipe_dim);
    void SetPipeDimBox(G4ThreeVector pipe_dim);
    void SetPipeCyl(G4bool g1);
    void SetPipeBox(G4bool g1);


    // for detector rotation
    void SetRotationDet1(G4bool a);
    void SetRotationDet2(G4bool a);
    void SetRotationDet3(G4bool a);
    void SetRotationDet4(G4bool a);


    // method to construct cylinder pipe
    void ConstructCylinderPipe();
    void ConstructBoxPipe();
    

    // methods to construct NaI detectors
    void ConstructNaI1();
    void ConstructNaI2();
    void ConstructNaI3();
    void ConstructNaI4();

    // methods to rotate X,Y, and Z for each NaI detector
    void Set_Rotate_X_NaI1(G4bool a),Set_Rotate_Y_NaI1(G4bool a),Set_Rotate_Z_NaI1(G4bool a);
    void Set_Rotate_X_NaI2(G4bool a),Set_Rotate_Y_NaI2(G4bool a),Set_Rotate_Z_NaI2(G4bool a);
    void Set_Rotate_X_NaI3(G4bool a),Set_Rotate_Y_NaI3(G4bool a),Set_Rotate_Z_NaI3(G4bool a);
    void Set_Rotate_X_NaI4(G4bool a),Set_Rotate_Y_NaI4(G4bool a),Set_Rotate_Z_NaI4(G4bool a);

    
    // create the function to create detector
    virtual G4VPhysicalVolume* Construct();

    
private:
    // solids
    G4Box *solidWorld, *cuadbox_solid,*water_solid_box;
    G4Tubs  *pipe_solid, *water_solid, *al_solid, *si_solid, *mg_solid,*na_solid;
    // logical volumes
    G4LogicalVolume *pipe_logic, *water_logic,*logicWorld, *logic_nai1, *logic_nai2, *logic_nai3, *logic_nai4;
    G4LogicalVolume *al_logic,*si_logic, *mg_logic;
    G4LogicalVolume *al_logic2, *si_logic2, *mg_logic2;
    G4LogicalVolume *al_logic3, *si_logic3, *mg_logic3;
    G4LogicalVolume *al_logic4, *si_logic4, *mg_logic4;
    // scoring volumes
    G4LogicalVolume *fScoringVolume1, *fScoringVolume2, *fScoringVolume3, *fScoringVolume4;
    // physical volumes
    G4VPhysicalVolume *physWorld, *pipe_phys, *water_phys, *al_phys, *si_phys, *mg_phys, *na_phys1;
    G4VPhysicalVolume *al_phys2, *si_phys2, *mg_phys2, *na_phys2; 
    G4VPhysicalVolume *al_phys3, *si_phys3, *mg_phys3, *na_phys3;
    G4VPhysicalVolume *al_phys4, *si_phys4, *mg_phys4, *na_phys4;
    // rotation
    G4RotationMatrix* m_rot,*m_rot1,*m_rot2,*m_rot3,*m_rot4;

    // define materials
    G4Material *air, *cu, *water, *al_mat, *si_mat, *mg_mat, *na_mat;

    // messenger
    detectormessenger *fmessenger;
    // position first detector
    G4double posNaI_x, posNaI_y, posNaI_z;
    // it is defined inner radius and thickness 
    G4double len_pipe, ra_pipe, th_pipe;
    G4double len_pipebox, y_pipe, z_pipe;
    // positions of detectors
    G4double posX1, posY1, posZ1; 
    G4double posX2, posY2, posZ2; 
    G4double posX3, posY3, posZ3; 
    G4double posX4, posY4, posZ4; 
    // angles for rotation matrix of detectors
    G4double ang1, ang2,ang3,ang4;

    // variables of messengers to construct one kind of pipe
    G4bool isPipeBox, isPipeCylinder;

    // variables of messegers to rotate detectors in one direction
    G4bool isRotX_NaI1, isRotY_NaI1, isRotZ_NaI1;
    G4bool isRotX_NaI2, isRotY_NaI2, isRotZ_NaI2;
    G4bool isRotX_NaI3, isRotY_NaI3, isRotZ_NaI3;
    G4bool isRotX_NaI4, isRotY_NaI4, isRotZ_NaI4;


    // positions for detector's parts
    G4double j=(4.1025-0.05-0.15)*cm;
    G4ThreeVector pos2 = G4ThreeVector(0,0,-j);
    G4double j1=(0.15)*cm;
    G4ThreeVector pos3 = G4ThreeVector(0,0,j1);
    G4double j2=(0.0915)*cm;
    G4ThreeVector pos4 = G4ThreeVector(0,0,-j2);


    void DefineMaterials();
    void DefaultValues();
    
};

#endif
// end up all this definition
