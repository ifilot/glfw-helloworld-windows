# GLFW Helloworld Windows

## Purpose
This repository contains the source code to build graphical applications in Windows using the GLFW library.

## Prerequisite software
* [CMake](https://cmake.org/download/)
* [Microsoft Visual Studio Community Edition](https://visualstudio.microsoft.com/downloads/)
* [Qt Creator (for the "jom" tool)](https://www.qt.io/download)
* [Git](https://git-scm.com/download/win)
* [Python](https://www.python.org/downloads/)

## Dependencies
* GLFW
* Boost
* Glew
* GLM

You can easily download these dependencies by double-clicking on `download_dep.py` in the `vendor` folder. This might take a while though!

## Compilation
Open a native x64 Native Tools Command Prompt and go to the repository root folder.

Create a build directory and execute CMake
```
mkdir build
cd build
cmake ..\src -G "NMake Makefiles"
C:\Qt\Tools\QtCreator\bin\jom.exe -j9
```