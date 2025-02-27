#!/bin/bash
if [ ! -d build ]; then
    mkdir build
fi 
cd build
cmake ..
make
cd ..
echo 
./build/run_dsa














