# GLFW Helloworld Windows

## Purpose
This repository contains the source code to build graphical applications in Windows using the GLFW library.

## Prerequisite software
* [CMake](https://cmake.org/download/)
* [Microsoft Visual Studio Community Edition](https://visualstudio.microsoft.com/downloads/)
* [Git](https://git-scm.com/download/win)
* [Python](https://www.python.org/downloads/)

## Optionally
* [Qt Creator (for the "jom" tool)](https://www.qt.io/download)

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
```

To compile, you can either use `nmake` or `jom`. The former can only utilize a single core to build the program, but that is fine since we have not many files. If you want to use all your CPU cores, you can use `jom`.

```
nmake
```

or for parallel compilation (change the 9 for the total number of threads + 1)

```
C:\Qt\Tools\QtCreator\bin\jom.exe -j9
```
