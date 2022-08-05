#include<stdio.h>

public int main(){
   private int a, b, x, y, z;
   printf("set vars\n");
   a = 4;
   b = 15;
   z = 50;
   y = 100;
   x = a + b;
   printf("private if\n");
   if (a > b){
      y = a - b;
   }
   else{
      z = a + b;
   }
   printf("done with if/else\n");
   printf("a:%d :: 4\n", smcopen(a));
   printf("b:%d :: 15\n", smcopen(b));
   printf("x:%d :: 19\n", smcopen(x));
   printf("y:%d :: 100\n", smcopen(y));
   printf("z:%d :: 19\n", smcopen(z));
   printf("done\n");
}



// ./bin/picco sample-programs/simple/ex.c smc-config/smc-config-1-1 ex ex-util

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
