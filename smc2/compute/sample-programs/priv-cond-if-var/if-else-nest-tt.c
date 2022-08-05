#include<stdio.h>


public int main(){
   private int a = 3, b = 7, c = 0;
   if (a) {
      c = 1;
      if (b) {
         c = 2;
      }
      else{
         c = 3;
      }
   }
   else {
      c = 4;
      if (b) {
         c = 5;
      }
      else{
         c = 6;
      }
   }
   printf("::a :: %d :: 3\n", smcopen(a));
   printf("::b :: %d :: 7\n", smcopen(b));
   printf("::c :: %d :: 2\n", smcopen(c));
}


