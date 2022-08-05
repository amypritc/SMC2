#include<stdio.h>


public int main(){
   private int a = 0, b = 7, c = 5;
   if (a) {
      c = c + 10;
      if (b) {
         c = c + 3;
      }
   }
   else {
      c = c + 15;
   }
   printf("a:%d :: 0\n", smcopen(a));
   printf("b:%d :: 7\n", smcopen(b));
   printf("c:%d :: 20\n", smcopen(c));
}


