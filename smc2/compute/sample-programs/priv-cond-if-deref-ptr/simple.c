#include<stdio.h>

public int main(){
   private int a = 2, b = 7, c = 0;
   private int *pa = &a, *pb = &b;
   if(a < b){
      c = *pa;
   }
   else{
      c = *pb;
   }
   printf("::a :: %d :: 2\n", smcopen(a));
   printf("::b :: %d :: 7\n", smcopen(b));
   printf("::c :: %d :: 2\n", smcopen(c));
}

