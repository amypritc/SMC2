#include<stdio.h>


public int main(){
   private int a = 3, b = 0, c = 0;
   if (a) {
      c = 1;
      if (b) {
         c = 2;
      }
   }
   printf("::a :: %d :: 3\n", smcopen(a));
   printf("::b :: %d :: 0\n", smcopen(b));
   printf("::c :: %d :: 1\n", smcopen(c));
}


