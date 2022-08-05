#include<stdio.h>

public int main(){
   private int a, b, c;
   private int *p;
   printf("set a, b\n");
   a = 7;
   b = 5;
   printf("private if\n");
   if (a < b){
      c = a - b;
   }
   else{
      c = a + b;
   }
   printf("done with if/else\n");
   printf("c:%d\n", smcopen(c));
   printf("done\n");
}





/* ****** RUNNING THIS PROGRAM ********
### COMPILE WITH PICCO ###
./bin/picco sample-programs/simple/test-code.c smc-config/smc-config-1-1 test-code test-code-util

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
