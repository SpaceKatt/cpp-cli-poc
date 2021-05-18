# cpp-cli-poc

[![Build Status](https://travis-ci.com/SpaceKatt/cpp-cli-poc.svg?branch=main)](https://travis-ci.com/SpaceKatt/cpp-cli-poc)

Proof of concept (POC) for creating a command-line interface with C++.

- [cpp-cli-poc](#cpp-cli-poc)
  - [Using the Command-line Interface](#using-the-command-line-interface)
    - [Help Dump](#help-dump)
    - [Usage Examples](#usage-examples)
  - [Development](#development)
    - [Build Toolchain](#build-toolchain)
    - [Dependencies](#dependencies)
    - [Build](#build)
    - [Install](#install)
    - [Test](#test)
    - [Lint](#lint)

## Using the Command-line Interface

This section provides examples for how to use the CLI (after you [install](#install) it).

### Help Dump

Yarr be the help message.

```bash
$ cpp-cli-poc --help

USAGE:

   cpp-cli-poc  [-h] [--version] {-a|-m|-s} arguments ...


Where:

   One of:
      -a,  --add
        finds the sum of a series, a + b + ... + n

      -s,  --subtract
        subtracts a series of numbers, a - b - ... - n

      -m,  --multiply
        multiplies a series of numbers, a * b * ... * n

   --,  --ignore_rest
     Ignores the rest of the labeled arguments following this flag.

   --version
     Displays version information and exits.

   -h,  --help
     Displays usage information and exits.

   arguments (accepted multiple times) <args>
     (required) Numbers to operate upon.

   Simple proof of concept to demonstrate a command-line interface in C++.
```

### Usage Examples

One may add numbers...

```bash
$ cpp-cli-poc --add 1 2 3 4
10
```

Subtract a series of numbers from an initial value...

```bash
$ cpp-cli-poc --subtract 10 4
6
$ cpp-cli-poc --subtract 10 4 3
3
```

Or, multiply a series of numbers...

```bash
$ cpp-cli-poc --multiply 1 2 3 4 5
120
```

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
