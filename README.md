# cpp-cli-poc

[![Build Status](https://travis-ci.com/SpaceKatt/cpp-cli-poc.svg?branch=main)](https://travis-ci.com/SpaceKatt/cpp-cli-poc)

Proof of concept (POC) for creating a command-line interface with C++.

- [cpp-cli-poc](#cpp-cli-poc)
  - [Development](#development)
    - [Build Toolchain](#build-toolchain)
    - [Dependencies](#dependencies)
    - [Build](#build)
    - [Test](#test)

## Development

### Build Toolchain

This project uses `cmake` and `g++` to provide consistent builds.

```bash
apt install cmake g++
```

### Dependencies

This project uses [`Catch2`](https://github.com/catchorg/Catch2) and includes it as a `git submodule`. Please initialize the submodule before building the project.

```bash
# If you have already cloned the repo...
git submodule update --init --recursive

#If you have yet to clone this repo (and clone using SSH)...
git clone --recurse-submodules -j8 git@github.com:SpaceKatt/cpp-cli-poc.git
```

### Build

A script, `auto-build.sh`, is provided to automate the build process.

```bash
# clean build, generate build system
./auto-build.sh

# reuse compiled libs and build system
cd build
cmake --build .
```

### Test

[`Catch2`](https://github.com/catchorg/Catch2) and `CTTest` are used for testing this project. The aforementioned build script will also build tests if passed the `-t` flag.

```bash
# run tests, after clean build and generating build system
./auto-build.sh -t

# compile and run tests and reuse compiled libs and build system
cd build
cmake --build .
ctest
```
