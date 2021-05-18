#!/usr/bin/env bash
set -e

./clean-build.sh -t
cd build/
sudo cmake --build . --target install
