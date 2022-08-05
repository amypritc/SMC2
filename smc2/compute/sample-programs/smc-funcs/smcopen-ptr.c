#include<stdio.h>

public int main(){
   private int *p, a;
   printf("init a\n");
   a = 1;
   printf("init p\n");
   p = &a;
   printf("open p\n");
   smcopen(p);
   printf("done\n");
}
