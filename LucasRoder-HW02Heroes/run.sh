#!/bin/bash

# Copyright (c) 2023 Nathan Greenfield. All rights reserved

# Pull the graded tests
wget "https://drive.google.com/uc?export=download&id=1Uiit8SAz_ZlehSbGO_ud8W_6X-bwAqDK" -O hw02.tar.gz
tar xzf hw02.tar.gz

# Cmake into build directory
echo "Compiling..."
mkdir build
cd build || exit
CC=clang CXX=clang++ cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON .. || exit 1
make || exit 1

# Return to root folder (so cwd is correct)
cd ..

# Run graded tests
echo "Running graded tests..."
timeout 30 build/tests/tests [graded] -r=github|| exit 1
