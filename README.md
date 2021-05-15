# cpp-cli-poc

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

A script, `ci-build.sh`, is provided to automate the build process.

```bash
./auto-build.sh
```

### Test

```bash
./auto-build -t
```
