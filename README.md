# vcpmp

[![Build Status](https://travis-ci.com/yunik1004/vcpmp.svg?branch=master)](https://travis-ci.com/yunik1004/vcpmp) [![Build status](https://ci.appveyor.com/api/projects/status/tfair23wjxblvyt2/branch/master?svg=true)](https://ci.appveyor.com/project/yunik1004/vcpmp/branch/master)

## Overview
vcpkg per project

## Build

### Prerequisites
* Git
* Cmake
* Clang
* Ninja

### How to Build

First, clone this repository recursively:
```bash
git clone --recursive
```

Next, run the following codes:
```bash
mkdir build
cd build
cmake .. -G Ninja -DCMAKE_BUILD_TYPE=RELEASE -DCMAKE_C_COMPILER=clang-cl -DCMAKE_CXX_COMPILER=clang-cl
ninja
```

### Possible Errors

If you are using Windows10/powershell then the following CMake Error might be occurred
```powershell
The C compiler
   "C:/.../clang-cl.exe"
  is not able to compile a simple test program.
```

Then, run the following command before building to remove this error
```powershell
cmd /c "`"C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvarsall.bat`" x86_amd64 & powershell"
```

## Document

First of all, assert that environment variable 'VCPKG_ROOT' is set.

Next, you need to make 'vcpkg.config.yaml' file like follows:

```yaml
default:
  os: windows
  arch: x86
  link: dynamic

library:
  opengl:
    arch: current
    link: static
  glew:
  glfw:
    arch: current
    link: dynamic
```

In default node, you can change default os, architecture, link type.

In library node, you can change architecture, link type of each libraries. If you don't set any option, then it will use default options.

Current possible options:
- os: windows, linux, osx, uwp
- arch: x86, x64, arm, arm64, current
- link: dynamic, static

> If you use 'current' option, then it will depend on your current system

Default options:
- os: your operating system
- arch:
   * Windows: x86
   * Other platform: x64
- link: dynamic

Next, you have to run the following command in the same directory with created 'vcpkg.config.yaml' file.
```bash
./vcpmp --install
```

Then, this program will automatically install every package using vcpkg.

## Contributions
* [**yunik1004**](https://github.com/yunik1004) - *Initial work*
