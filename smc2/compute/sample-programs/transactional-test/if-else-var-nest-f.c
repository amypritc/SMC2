#include<stdio.h>


public int main(){
   private int a = 3, b = 0, c = 5;
   if (a) {
      c = c + a;
      if (b) {
         c = c + 2;
      }
   }
   else {
      c = c + 2;
   }
   printf("a:%d :: 3\n", smcopen(a));
   printf("b:%d :: 0\n", smcopen(b));
   printf("c:%d :: 8\n", smcopen(c));
}


