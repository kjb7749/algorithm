#!/bin/bash

printf "start\n\n"
cmake CMakeLists.txt
make
./app
printf "end\n\n"