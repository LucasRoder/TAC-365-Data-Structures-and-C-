#!/bin/bash
# �2023 Nathan Greenfield

# Pull the graded tests
wget "https://drive.google.com/uc?export=download&id=1tFu9DHi4DOtoYNpzteOr1Xmb1PZyPXCG" -O hw03.tar.gz
tar xzf hw03.tar.gz

# Cmake into build directory
echo "Compiling..."
mkdir build
cd build
RELEASE=ON CC=clang CXX=clang++ cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON .. || exit 1
make || exit 1

# Return to root folder (so cwd is correct)
cd ..

# Run graded tests
echo "Running graded tests..."
# timeout 30 build/tests/tests [graded] || exit 1
timeout 30 build/tests/tests [graded] -r=github || { echo "::error::Not all graded tests passed!"; exit 1; }

