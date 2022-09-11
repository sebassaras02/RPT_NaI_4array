
# SAS Application for Radioactive Particle Tracking in Pipes

The application is built to simulate the RPT along opaque ducts. 
The quantities recorded are energy deposition spectra and doses (TOF is developing).


## Installation

Copy the repository in your Linux operative system. Then create a folder where you are going to compile the application (build folder).

To compile
```sh
mkdir build
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

## SAS Application Features Reference

#### Detector position

This macrocommand let the user change the position of the detector. 
It is available for each detector, just change the number of the detector.

```http
  /NaI/detector1/dim **value**
```

| Parameter | Type     | Description                |
| :-------- | :------- | :------------------------- |
| `X, Y, and Z` | `Float` | **Example: -10 -10 -20 cm**|

#### Detector angle
The use can select the angle of rotation for each detector following the next macrocommand:

```http
  /NaI/detector1/ang **value**
```

| Parameter | Type     | Description                |
| :-------- | :------- | :------------------------- |
| `0-360 deg`      | `Float` | **Example: 90 deg** |

#### Detector rotation axes
In addition, the user can select the axes for the rotation. 
rotX for X, rotY for Y, and rotZ for Z.
```http
  /NaI/detector1/rotX  **value**
```
| Parameter | Type     | Description                |
| :-------- | :------- | :------------------------- |
| `true or false`      | `Bool` | **Example: true** |


#### Pipe construction
The user can choose between a cylindrical or box pipe. 
The geometry choosen needs to be activaed first, and the set the dimensions.
The input dimensions are the half in each axes, respectively.

For box pipes: 
```http
  /pipe/box/activate true
  /pipe/box/dim **value**
```
| Parameter | Type     | Description                |
| :-------- | :------- | :------------------------- |
| `X, Y, and Z` | `Float` | **Example: -10 -10 -20 cm**|

For cylindrical pipes: 
```http
  /pipe/cyl/activate true
  /pipe/cyl/dim **value**
```
You have to thickness, radious and the half of the length values in cm.

| Parameter | Type     | Description                |
| :-------- | :------- | :------------------------- |
| `thickness, radious, and half of length` | `Float` | **Example: -10 -10 -20 cm**|

The default units of the macrocommands for geometry changes are  all in centimetters,
but you can change that in detectormessenger class.

#### add(num1, num2)

Takes two numbers and returns the sum.


## Visualization

MULTI-THREAD MODE:
If you would like to see geometry changes done through macrocommands, 
you must turn off the initialization in main function, and the number threads do too. You have to set the  number of threads and initilizate the run manager in your macrocommands. If you want to change the geometry through macrocommands provided follow the next steps:

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
If you would like to see geometry changes done through macrocommands, 
you can set the number of threads and initilizate the run manager in the main function.
To see the changes execute follow the next steps:

```sh
./naidetector 
/NaI/detector1/dimensions -40 10 0 cm
/NaI/detector1/angle 90 deg
/run/reinitializeGeometry 
{run whatever order that you want}
{run your primary generator specifications}
/run/beamOn 10
```

## Acknowledgements

This application and research was founded by PIGR-19-09 project 
for the Nuclear Science Department  (DCN) in the Escuela Politécnica Nacional (EPN), Quito-Ecuador.

 - [DCN - EPN ](https://www.epn.edu.ec/departamento-de-ciencias-nucleares-dcn/)
 - [EPN](https://www.epn.edu.ec/)


## Contacts:

- [Twitter](https://twitter.com/sarasti_seb)
- [LinkedIn](https://linkedin.com/in/sebastiansarasti)
- [ResearchGate](https://www.researchgate.net/profile/Sebastian-Sarasti-2)


## License

You are free to use this application and improve it for educational purposes. The commercial use it is not allowed without the owner permission (Sebastian Sarasti Zambonino).

