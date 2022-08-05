#!/bin/bash

#script for compiling and running a single program locally
#bash runPicco.sh <programName> 

prog="$1"
timeout="$2"

#runs program - two parts
#assumes runtime-config is configured properly for locally running programs
#First starts nodes in decreasing order
#X <ID> <runtime config> <privkey file> M K <share file 1> ... <share file M> <output 1> ... <output K>
./benchmarks/compiled/"$prog" 3 runtime-config keys/key3.pem 1 1 benchmarks/inputShares/"$prog"3 benchmarks/output/"$prog"-out  &  
sleep 2

./benchmarks/compiled/"$prog" 2 runtime-config keys/key2.pem 1 1 benchmarks/inputShares/"$prog"2 benchmarks/output/"$prog"-out & 
sleep 2

./benchmarks/compiled/"$prog" 1 runtime-config keys/key1.pem 1 1 benchmarks/inputShares/"$prog"1 benchmarks/output/"$prog"-out &  
sleep 2


#Second, runs picco-seed
#picco-seed <runtime config> <utility config>

./bin/picco-seed runtime-config benchmarks/utility/"$prog"-util
sleep "$timeout"

killall -q "$prog"




