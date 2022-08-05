#!/bin/bash

#script for compiling and running a single program locally
#bash runPicco.sh <directoryName> <programName> <inputFileName> <numberInputParties> <numberOutputParties>

#dirr="$1"
prog="$1"
#inp="$3"
#inpN="$4"
#outN="$5"
#timeout="$6"


./"$prog" 1 runtime-config keys/key1.pem 1 1 "$prog"1 "$prog"-out 


#./bin/picco-seed runtime-config "$prog"-util





