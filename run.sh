#!/bin/bash

# install_name_tool -add_rpath /Users/benlandrette/Qt/6.8.1/macos/lib out/main
# ./out/main

cd out
cmake ..
make
mv main ..
../main
mv ../main .
make clean 
cd ..
