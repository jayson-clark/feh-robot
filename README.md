# Proteus Template Project

This project provides a template for developing software with the Proteus platform. It includes an example class, installation scripts, and build instructions for both a simulator environment and the physical Proteus hardware. The proteus platform is a proprietary platform used throughout The Ohio State University FEH program. This project allows for more organized code and allows for one codebase to be compiled to both the simulator and physical proteus.

This is done by replacing the default makefiles with modified versions. If you would like to add additional modified files, put them inside of the `install_scripts/mod_files` directory. Header files should be placed inside of the `include` directory in the root of the project. Source files should be placed inside of the `src` directory.

The templates and documentation provided by OSU can be found [here](http://https://u.osu.edu/fehproteus/ "here").


## Installation

Before you begin development or compile the project, you need to set up your environment. This project includes a Python script, `install.py`, designed to automate the setup process.

### Using the `install.py` Script

To use the `install.py` script, ensure that you have Python installed on your system. Then, navigate to root directory of the project and execute the script from your terminal:

```bash
python install_scripts/install.py
```

### Installing dependencies
To compile projects for the physical proteus, you must install the proteus dependencies:
[Proteus Dependencies](https://u.osu.edu/fehproteus/vs-code-environment/installation-instructions/ "Proteus Dependencies")

## Compilation Instructions
Depending on your target platform (simulator or physical Proteus device), follow the instructions below to compile the project.

### Compiling for the Simulator
To compile the project for the simulator, use the following command in the terminal from the root directory of the project: 
```bash 
mingw32-make simulator
```

The executable will be generated in the `build` directory.

### Compiling for the Physical Proteus Device
To compile the project for the physical Proteus device, use the following command in the terminal from the root directory of the project:

```bash
mingw32-make physical
```

This command builds the project and installs it on the SD card for the Proteus.
