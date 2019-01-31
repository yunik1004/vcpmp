# vcpmp

## Overview
vcpkg per project

## Build

### Prerequisites
* Git
* Cmake
* For windows, following should be required:
  * MinGW-w64

### How to Build

First, clone this repository recursively:
```bash
git clone --recursive
```

#### Linux and OSX
Run the following codes:
```bash
mkdir build
cd build
cmake -A x64 .. -DCMAKE_BUILD_TYPE=RELEASE
make
```

#### Windows

##### MinGW-w64
Run the following codes:
```powershell
mkdir build
cd build
cmake -G "MinGW Makefiles" .. -DCMAKE_BUILD_TYPE=RELEASE
mingw32-make
```

## Contributions
* [**yunik1004**](https://github.com/yunik1004) - *Initial work*
