# cpp-cli-poc

[![Build Status](https://travis-ci.com/SpaceKatt/cpp-cli-poc.svg?branch=main)](https://travis-ci.com/SpaceKatt/cpp-cli-poc)

Proof of concept (POC) for creating a command-line interface with C++.

- [cpp-cli-poc](#cpp-cli-poc)
  - [Development](#development)
    - [Build Toolchain](#build-toolchain)
    - [Dependencies](#dependencies)
    - [Build](#build)
    - [Install](#install)
    - [Test](#test)
    - [Lint](#lint)

## Development

### Build Toolchain

This project uses `cmake`, `cppcheck`, `cpplint`, and `g++` to provide consistent builds.

```bash
sudo apt update
sudo apt install cmake g++ cppcheck
sudo python -m pip install cpplint
```

### Dependencies

This project uses [`Catch2`](https://github.com/catchorg/Catch2) and includes it as a `git submodule`. Please initialize the submodule before building the project.

```bash
# If you have already cloned the repo...
git submodule update --init --recursive

# If you have yet to clone this repo (and clone using SSH)...
git clone --recurse-submodules -j8 git@github.com:SpaceKatt/cpp-cli-poc.git
```

### Build

A script, `auto-build.sh`, is provided to automate the build process.

```bash
# clean build, generate build system
./clean-build.sh
```

> One may also save time by reusing the build system generated in `build/`, instead of running the whole `auto-build.sh` script everytime.

```bash
# reuse compiled libs and build system
./recycle-build.sh
```

### Install

Once the CLI builds, we may also install it using the `install.sh` script.

```bash
# install CLI for global bash use (requires sudo)
./install.sh
```

### Test

[`Catch2`](https://github.com/catchorg/Catch2) and `CTest` are used for testing this project. The aforementioned build script will also build tests if passed the `-t` flag.

```bash
# run tests, after clean build and generating build system
./clean-build.sh -t
```

> One may also save time by reusing the build system generated in `build/`, instead of running the whole `auto-build.sh` script everytime.

```bash
# compile and run tests and reuse compiled libs and build system
./recycle-build.sh -t
```

> NOTE: `./recycle-build.sh -t` will fail if `./clean-build.sh` is first called without the `-t` flag.

### Lint

[`cppcheck`](http://cppcheck.sourceforge.net/) is used for linting the project. A script, `./lint.sh`, is provided for ease of use.

```bash
# lint project, show warnings, exit 0
./lint.sh

# lint project, exit in error (1) on warnings
./lint.sh -e
```
