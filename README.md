# Radioactive Particle Tracking NaI4 - GEANT4

## Done by: Sebastián Sarasti Zambonino

> This application and research was founded by PIGR-19-09 project for the Nuclear Science Department in the Escuela Politécnica Nacional, Quito-Ecuador.

## Features

The simulation has own macrocommands to change NaI detector positions.
- /NaI/detector1/ for detector 1
- /NaI/detector2/ for detector 2
- /NaI/detector3/ for detector 3
- /NaI/detector4/ for detector 4

For each detector, you can change the position and the angle of the detector. 

Position is changed by: 
- /NaI/detector1/dimensions

You have to give X, Y and Z values in cm

Detector angle is changed by: 
- /NaI/detector1/ang

At the same time, you can change the geometry of your pipe. You must use the next macrocommand:
- /pipe/dim

You have to thickness, radious and length values in cm

The units of the macrocommands are in centimetters, but you can change that in detectormessenger class.

## Details of the application:

The simulation connects several classes to work properly:

- Detector construction class: there is defined the materials and volumes
- Physics list: there is defined the process the simulation will use and setcut range value (default)
- Primary generator: there is defined the method to generate particles, in this application was used general particle source to be user-friendly
- Run Action: generates a graph per run and save it like root file
- Event Action: plot the result of energy deposited per event
- Stepping Action: get the energy deposited of each step in the target volumes
- Messengers: this class is to generate own user macrocommands

## Installation

Copy the repository in your Linux operative system. Then create a folder where you are going to compile the application (build folder).

To compile
```sh
cd build
cmake ..
make -j (number of threads of your PC)
```

To execute without bash mode
```sh
./naidetector 
```

To execute in bash mode
```sh
./naidetector  macrocommand.mac
```

## Visualization

MULTI-THREAD MODE:
If you would like to see geometry changes done through macrocommands, you must turn off the initialization in main function, the number threads do too. You have to set the  number of threads and initilizate the run manager in your macrocommands. If you want to change the geometry through macrocommands provided follow the next steps:

```sh
./naidetector 
/NaI/detector1/dimensions -40 10 0 cm
/NaI/detector1/angle 90 deg
{run whatever order that you want}
/run/numberOfThreads 6
/run/initialize 
{run your primary generator specifications}
/run/beamOn 10
```
If you see any errors in red color (The scene has no extent), it is because the run manager is not initializated until you run the last code, so vis.mac fails. You have to ignored them


SINGLE-THREAD MODE:
If you would like to see geometry changes done through macrocommands, you can set the number of threads and initilizate the run manager. To see the changes execute follow the next steps:

```sh
./naidetector 
/NaI/detector1/dimensions -40 10 0 cm
/NaI/detector1/angle 90 deg
/run/reinitializeGeometry 
{run whatever order that you want}
{run your primary generator specifications}
/run/beamOn 10
```

## License

MIT

You are free to use this application and improve it. The commercial use it is not allowed without the owner permission (Sebastián Sarasti).
