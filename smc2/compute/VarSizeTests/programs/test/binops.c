#include<stdio.h>

public int main(){
   private int<2> a = 1; 
   private int<3> b = 2;
   private int c;
   private int d;
   c = a + b;
   c = a * b;
   c = b - a; 
   c = b / a;
   d = b == a;
   d = b < a;
   d = b != a;
   printf("c:%d\n", smcopen(c));
   printf("done\n");
}





/* ****** RUNNING THIS PROGRAM ********
### COMPILE WITH PICCO ###
./bin/picco VarSizeTests/programs/test/binops.c smc-config/smc-config-1-1 binops binops-util

### CREATE THE UTILITY FILE ###
./bin/picco-utility -I 1 sample-programs/input/test-code.txt test-code-util test-code

### MAKE THE PROGRAM EXECUTABLE ###
make

### RUN THE PROGRAM ###
./test-code 3 runtime-config keys/key3.pem 1 1 test-code3 out-test-code

./test-code 2 runtime-config keys/key2.pem 1 1 test-code2 out-test-code

./test-code 1 runtime-config keys/key1.pem 1 1 test-code1 out-test-code

./bin/picco-seed runtime-config test-code-util

### GET OUTPUT ###
./bin/picco-utility -O 1 out-test-code test-code-util test-code-output
*/
