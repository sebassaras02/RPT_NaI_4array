#include <iostream>
#include "G4RunManager.hh"
#include "G4MTRunManager.hh"
#include "G4UIExecutive.hh"
#include "G4VisManager.hh"
#include "G4UImanager.hh"
#include "G4UIExecutive.hh"
#include "G4VisExecutive.hh"
/*create principal function
 create autoshell of Geant4*/
#include "detectorconstruction.hh"
#include "physicslist.hh"
#include "action.hh"
int main (int argc, char** argv)
{
    G4UIExecutive *ui = 0;

    #ifdef G4MULTITHREADED
        G4MTRunManager* runmanager= new G4MTRunManager();
        G4cout<<"Multithread execution"<<G4endl;
    #else
    /* always use G4RunManager which is the top of execution of Geant4*/
        G4RunManager* runmanager= new G4RunManager();
        G4cout<<"Single execution"<<G4endl;
    #endif
  
    runmanager->SetNumberOfThreads(6);

    // tell geant4 to inizilitation of detector construction
    runmanager->SetUserInitialization(new detectorconstruction());
    runmanager->SetUserInitialization(new physicslist());
    runmanager->SetUserInitialization(new actioninitialization());
    // only initialize runmanger just in case you have all mandatory classes
     runmanager->Initialize();
    // need user interfase
    // define the graphical execution only without an entry
    
    if (argc==1)
    {
        ui= new G4UIExecutive(argc, argv);
    }
    // need a visualization, it has to be first to have a view and after that have the volumes
    G4VisManager *vis= new G4VisExecutive();
    vis->Initialize();
    // only when we have arguments this line is executing
     G4UImanager* UIManager=  G4UImanager::GetUIpointer();
    if(ui)
    {
        // Open the example with OPENGL
        UIManager->ApplyCommand("/control/execute vis.mac");
        ui->SessionStart();
    }
    else{
        G4String command = "/control/execute "; // tell g4 to execute a macrofile
        G4String filename = argv[1];
        UIManager->ApplyCommand(command+filename);
    }


    return 0;
}
