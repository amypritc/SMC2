#!/bin/bash

#script for compiling a single program 
#bash compilePicco.sh <directoryName> <programName> <inputFileName> <numberInputParties> <numberOutputParties>

dirr="$1"
prog="$2"
inp="$3"
inpN="$4"
outN="$5"

echo compiling with picco
echo ./bin/picco sample-programs/"$dirr"/"$prog".c smc-config/smc-config-"$inpN"-"$outN" "$prog" utility/"$dirr"/"$prog"-util

./bin/picco sample-programs/"$dirr"/"$prog".c smc-config/smc-config-"$inpN"-"$outN" "$prog" utility/"$dirr"/"$prog"-util

echo creating input shares with picco-utility

#create input shares
#picco-utility -I <input party ID> <input filename> <utility config> <shares filename>
for i in $(seq 1 $inpN) 
do 
   echo ./bin/picco-utility -I "$i" sample-programs/input/"$inp".txt utility/"$dirr"/"$prog"-util inputShares/"$dirr"/"$prog"
   ./bin/picco-utility -I "$i" sample-programs/input/"$inp".txt utility/"$dirr"/"$prog"-util inputShares/"$dirr"/"$prog"
done

