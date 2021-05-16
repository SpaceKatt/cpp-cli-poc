#!/usr/bin/env bash
set -e

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

./lint.sh -eq

cd $BUILD_DIR
cmake --build .