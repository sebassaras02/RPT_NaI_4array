#include "runaction.hh"


// define the constructor
runaction::runaction(){

}
// define the destructor
runaction::~runaction(){}

void runaction::BeginOfRunAction(const G4Run* run){
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

}
