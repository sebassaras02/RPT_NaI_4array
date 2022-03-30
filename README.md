# Radioactive Particle Tracking NaI4 - GEANT4

## Done by: Sebastián Sarasti Zambonino

> This application and research was founded by PIGR-19-09 project for the Nuclear Science Department in the Escuela Politécnica Nacional, Quito-Ecuador.

## Features

The simulation has own macrocommands to change NaI detector positions.
- /NaI/detector1/ for detector 1
- /NaI/detector2/ for detector 2
- /NaI/detector3/ for detector 3
- /NaI/detector4/ for detector 4

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

## License

MIT

You are free to use this application and improve it. The commercial use it is not allowed without the owner permission (Sebastián Sarasti).
