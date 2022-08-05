#!/bin/bash

# script for compiling a single program 
# bash compilePicco.sh <programName> 

prog="$1"

echo creating output shares with picco-utility

#create input shares
#picco-utility -O <input party ID> <shares filename> <utility config> <output filename>
echo ./../bin/picco-utility -O 1 output/"$prog"-out utility/"$prog"-util output/"$prog".out
./../bin/picco-utility -O 1 output/"$prog"-out utility/"$prog"-util output/"$prog".out


