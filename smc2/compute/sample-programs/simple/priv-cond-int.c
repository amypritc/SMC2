#include<stdio.h>

public int main(){
   private int a, b, c;
   printf("init a\n");
   a = 1;
   printf("init b\n");
   b = 2;
   printf("priv cond\n");
   if(a < b){
      c = a;
   }
   else{
      c = b;
   }
   printf("done\n");
}
