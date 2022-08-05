#!/bin/bash

#script for compiling a single program 
#bash compilePicco.sh <programName>

# programs that can be compiled with this script:
# LR-parser, h_analysis, pay-gap
prog="$1"

echo compiling with picco
#picco <program name> <smc-config file> <compiled program name> <picco utility name>
echo ./../bin/picco program/"$prog".c ../smc-config/smc-config-1-1 "$prog" utility/"$prog"-util

./../bin/picco program/"$prog".c ../smc-config/smc-config-1-1 "$prog" utility/"$prog"-util

echo creating input shares with picco-utility
#create input shares
#picco-utility -I <input party ID> <input filename> <utility config> <shares filename>
echo ./../bin/picco-utility -I 1 input/"$prog".txt utility/"$prog"-util inputShares/"$prog" 
./../bin/picco-utility -I 1 input/"$prog".txt utility/"$prog"-util inputShares/"$prog"

