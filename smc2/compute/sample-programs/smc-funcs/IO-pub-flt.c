#include<stdio.h>

public int main(){
   public float a, b[5], c[2][2];
   printf("get a\n");
   smcinput(a, 1);
   printf("get b\n");
   smcinput(b, 1, 5);
   printf("get c\n");
   smcinput(c, 1, 2, 2);
   printf("output a\n");
   smcoutput(a, 1);
   printf("output b\n");
   smcoutput(b, 1, 5);
   printf("output c\n");
   smcoutput(c, 1, 2, 2);
   printf("done\n");
}
