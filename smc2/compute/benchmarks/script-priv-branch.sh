#!/bin/bash

# script for controlling compilation, making, running, and obtaining output 
# bash script.sh

echo compiling programs and creating input shares
echo 
# compile programs and move compiled program to outer directory to make executable
for i in private-branching private-branching-add private-branching-mult private-branching-reuse
do   
   echo $i
   ./../bin/picco program/$i.c ../smc-config/smc-config-1-1 $i utility/$i-util
   ./../bin/picco-utility -I 1 input/private-branching.txt utility/$i-util inputShares/$i
   mv $i.cpp ../$i.cpp
   echo 
done

# move to outer directory to use makefile
cd ../


echo
echo making executables
echo
# make executables
make 

# move compiled programs back into benchmarks directory
for i in private-branching private-branching-add private-branching-mult private-branching-reuse
do 
   mv $i.cpp benchmarks/compiled/$i.cpp
   mv $i.o benchmarks/compiled/$i.o
   mv $i benchmarks/compiled/$i
done


echo
echo running programs 
echo 
# run the program executables
for i in private-branching private-branching-mult private-branching-add 
do 
   echo $i
   echo
   bash benchmarks/runPicco.sh $i 10s
   echo
done

for i in private-branching-reuse
do 
   echo $i
   echo
   bash benchmarks/runPicco.sh $i 180s
   echo
done
   

cd benchmarks

echo 
echo decrypting output
echo 
# combine the output shares to retrive the output
for i in private-branching private-branching-add private-branching-mult private-branching-reuse
do 
   echo $i
   echo
   bash getOutput.sh $i
   echo
done



echo 
echo checking output
echo 
# check the output with the expected output
for i in private-branching private-branching-add private-branching-mult private-branching-reuse
do 
   echo $i
   echo
   diff output/$i.out expected-output/$i.out
   echo
done





