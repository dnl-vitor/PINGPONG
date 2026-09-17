#!/bin/bash

cmake -B build
cmake --build build
cd build/bin && ./pong
