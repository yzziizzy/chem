#!/bin/bash


g++ -o chem main.cpp moly.cpp csv.cpp smiles.cpp -lm -ggdb -O0 -Wno-write-strings
