#include<stdio.h>

public int main(){
   private int a, b;
   private int *p;
   printf("init a\n");
   a = 1;
   printf("init b\n");
   b = 2;
   printf("priv cond\n");
   if(a < b){
      p = &a;
   }
   else{
      p = &b;
   }
   printf("done\n");
}
