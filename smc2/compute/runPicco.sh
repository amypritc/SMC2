#!/bin/bash

#script for compiling and running a single program locally
#bash runPicco.sh <directoryName> <programName> <inputFileName> <numberInputParties> <numberOutputParties>

dirr="$1"
prog="$2"
inp="$3"
inpN="$4"
outN="$5"
timeout="$6"

#runs program - two parts
#assumes runtime-config is configured properly for locally running programs
#First starts nodes in decreasing order
#X <ID> <runtime config> <privkey file> M K <share file 1> ... <share file M> <output 1> ... <output K>
./compiled/"$dirr"/"$prog" 3 runtime-config keys/key3.pem "$inpN" "$outN" inputShares/"$dirr"/"$prog"3 output/"$dirr"/"$prog"-out > output/"$dirr"/"$prog"3.txt & _pidA=$! 
#echo "pid3 = $_pidA" 
sleep 2

./compiled/"$dirr"/"$prog" 2 runtime-config keys/key2.pem "$inpN" "$outN" inputShares/"$dirr"/"$prog"2 output/"$dirr"/"$prog"-out > output/"$dirr"/"$prog"2.txt & _pidB=$! 
#echo "pid2 = $_pidB" 
sleep 2

./compiled/"$dirr"/"$prog" 1 runtime-config keys/key1.pem "$inpN" "$outN" inputShares/"$dirr"/"$prog"1 output/"$dirr"/"$prog"-out > output/"$dirr"/"$prog"1.txt & _pidC=$! 
#echo "pid1 = $_pidC" 
sleep 2

#echo "$_pidA :: $_pidB :: $_pidC" > pid.txt

#Second, runs picco-seed
#picco-seed <runtime config> <utility config>

./bin/picco-seed runtime-config utility/"$dirr"/"$prog"-util
sleep $6

killall -q "$prog"




