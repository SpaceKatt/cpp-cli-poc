#!/usr/bin/env bash
BUILD_DIR="./build"

# nuke build dir
[ -d $BUILD_DIR ] && rm -rf $BUILD_DIR && echo 'Nuked build dir...' \
  || echo 'Building from clean slate...' \
  && echo

# TODO Test flag
# create build system
mkdir build
cd build
cmake ../

# execute build
cmake --build .

# run tests
ctest
