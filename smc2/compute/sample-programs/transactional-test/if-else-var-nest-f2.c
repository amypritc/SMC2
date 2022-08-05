#include<stdio.h>


public int main(){
   private int a = 3, b = 0, c = 5;
   if (a) {
      c = c + a;
      if (b) {
         c = c + b;
      }
      else {
         c = a;
      }
   }
   else {
      c = c + b;
   }
   printf("a:%d :: 3\n", smcopen(a));
   printf("b:%d :: 0\n", smcopen(b));
   printf("c:%d :: 3\n", smcopen(c));
}


