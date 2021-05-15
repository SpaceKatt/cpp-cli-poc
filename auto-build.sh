#!/usr/bin/env bash
BUILD_DIR="./build"
declare TEST_STATE

while getopts ":t" opt; do
  case $opt in
    t)
      TEST_STATE="ON"
      ;;
    \?)
      echo "Invalid option: -$OPTARG" >&2
      exit 1
      ;;
  esac
done

# nuke build dir
[ -d $BUILD_DIR ] && rm -rf $BUILD_DIR && echo 'Nuked build dir...' \
  || echo 'Building from clean slate...' \
  && echo

# create build system
mkdir build
cd build
cmake -DBUILD_TESTING=${TEST_STATE} ../

# execute build
cmake --build .

# run tests
[[ $TEST_STATE ]] && ctest
