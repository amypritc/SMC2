#include<stdio.h>

public int main(){
   private float *p, a;
   printf("init a\n");
   a = 1.234;
   printf("init p\n");
   p = &a;
   printf("open p\n");
   smcopen(p);
   printf("done\n");
}
