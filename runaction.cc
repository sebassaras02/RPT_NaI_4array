#include "runaction.hh"


// define the constructor
runaction::runaction(){
  // add new units for dose
  //
  const G4double milligray = 1.e-3*gray;
  const G4double microgray = 1.e-6*gray;
  const G4double nanogray  = 1.e-9*gray;
  const G4double picogray  = 1.e-12*gray;

  new G4UnitDefinition("milligray", "milliGy" , "Dose", milligray);
  new G4UnitDefinition("microgray", "microGy" , "Dose", microgray);
  new G4UnitDefinition("nanogray" , "nanoGy"  , "Dose", nanogray);
  new G4UnitDefinition("picogray" , "picoGy"  , "Dose", picogray);

  // Register accumulable to the accumulable manager
  G4AccumulableManager* accumulableManager = G4AccumulableManager::Instance();
  accumulableManager->RegisterAccumulable(fEvEdep);
}
// define the destructor
runaction::~runaction(){}

void runaction::BeginOfRunAction(const G4Run* run){

    // inform the runManager to save random number seed
    G4RunManager::GetRunManager()->SetRandomNumberStore(false);

    // reset accumulables to their initial values
    G4AccumulableManager* accumulableManager = G4AccumulableManager::Instance();
    accumulableManager->Reset();


    // initializate the run manager to store the hits
    G4AnalysisManager*man = G4AnalysisManager::Instance();
    //man->SetHistoDictoryName("histograms");
    // create a file for each run

    G4int RunID = run->GetRunID();
    std::stringstream strRunID;
    strRunID<<RunID;

    man->OpenFile("output"+strRunID.str()+".root");

    
    man->CreateNtuple("Detector_1","Edep");
    man->CreateNtupleDColumn("fedep1");
    man->FinishNtuple(0);   

    man->CreateNtuple("Detector_2","Edep");
    man->CreateNtupleDColumn("fedep2");
    man->FinishNtuple(1);

    man->CreateNtuple("Detector_3","Edep");
    man->CreateNtupleDColumn("fedep3");
    man->FinishNtuple(2);

    man->CreateNtuple("Detector_4","Edep");
    man->CreateNtupleDColumn("fedep4");
    man->FinishNtuple(3);
   
    
}
void runaction::EndOfRunAction(const G4Run*){


    // Merge accumulables
    G4AccumulableManager* accumulableManager = G4AccumulableManager::Instance();
    accumulableManager->Merge();

    // Compute dose = total energy deposit in a run and its variance
    //
    G4double edep  = fEvEdep.GetValue();

    const detectorconstruction* detectorConstruction = static_cast<const detectorconstruction*>
        (G4RunManager::GetRunManager()->GetUserDetectorConstruction());

    G4double mass = detectorConstruction->GetScoringVolume1()->GetMass();
    mass=mass/kg;
    edep=edep/joule;
    G4double dose=edep/mass;


    // initializate the run manager to store the hits
    G4AnalysisManager*man = G4AnalysisManager::Instance();
    // write all the edep in the root file
    man->Write();
    // close root file
    man->CloseFile();
    #ifndef G4MULTITHREADED
        G4cout<<"Radioactive Particle Tracking Application"<<G4endl;
        G4cout<<"This example simulates a radioactive source inside a pipe"<<G4endl;
        G4cout<<"Code made by: Sebastian Sarasti Zambonino"<<G4endl;
        G4cout<<"Nuclear Science Department"<<G4endl;
        G4cout<<"Escuela Politecnica Nacional"<<G4endl;
    #endif
    G4cout<<"Dose deposited in detector 1 is: "<< dose*1e12 << " picoGy"<<G4endl;
    G4cout<<"Mass of detector 1 is: "<< mass <<"kg"<<G4endl;


}
