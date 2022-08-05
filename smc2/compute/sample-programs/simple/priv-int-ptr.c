#include<stdio.h>

public int main(){
   private int *p;
   printf("init p\n");
   p = (private int *)pmalloc(1, private int);
   printf("set p\n");
   *p = 2;
   printf("free p\n");
   pfree(p);
   printf("done\n");
}
