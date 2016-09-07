# PUCMM 2D Asteroids

This is a simple Asteroids game created for the 2D C++ Game Development class lectured by Raul Roa at PUCMM University , Santo Domingo, Dominican Republic.  This class started on May 25 2016 and it's going to end on June 17 2016.

The objective of the game is to mock a simple Asteroids multiplatform game using C++ with OpenGL and SDL libraries.

## Building the project for Windows

If you are using the Windows Operating System you will find the Microsoft Visual Studio solution (.sln file) that you could just simply double click and you should be ready to build.

Microsoft Visual Studio 2015 Express Edition was used for creating the project but it builds for any version of Visual Studio from 2012 or later. Just be aware that if you are using a older version that 2015 you should right click on the project, and change the build tools version to your VS version, it will build fine after that.

## Building the project for Linux

You first need to install all the required tools in your environment (OPENGL and SDL).

You can do that by performing the following commands:

    sudo apt update

### INSTALL apt-file

apt-file is a command line tool for searching files in packages for the APT package management system.

    sudo apt install apt-file

    sudo apt-file update

### INSTALL DEV TOOLS
    sudo apt install build-essential

### INSTALL LibX libraries and MESA dev Libraries
    sudo apt install libx11-dev

    sudo apt install mesa-common-dev

    sudo apt install libglu1-mesa-dev

    sudo apt install mesa-utils

### INSTALL GLEW
    sudo apt install build-essential libxmu-dev libxi-dev libgl-dev libosmesa-dev git

    sudo apt install libglew-dev

### INSTALL Library (SDL2, GLUT, etc...)
    sudo apt install libsdl2-dev

#Building for Mac

If you want to build for Mac, you will need to install the OpenGL and SDL2 frameworks. And then you could easily build this project using XCode.  

After you've installed OpenGL and SDL2 whether using the Homebrew Mac package manager or manually. Just create a new C++ project, then click on its name in the XCode window, in the **TARGETS** section, select the name of your project, click on **Build Phases** , then click on **Link Binary with Libraries**. Click on the plus sign, then look for OpenGL and SDL2 frameworks, they should be located at /System/Library/Frameworks/ if you've installed it manually or at /usr/local/Cellar if you've used `brew` .

After doing this you should be able to build this project.

This video can help you on configuring it.

[![Setup your dev environment for OpenGL with SDL in MAC](http://img.youtube.com/vi/0PvLtUTariA/0.jpg)](http://www.youtube.com/watch?v=0PvLtUTariA)

