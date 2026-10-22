@echo off 
cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Debug -B build
cmake --build build 
cd build\bin
pong.exe
