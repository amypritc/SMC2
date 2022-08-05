#include<stdio.h>


public int main(){
   private int a = 3, b = 7, c = 5;
   private int *p;
   p = &a;
   if (a > b) {
      a = b;
      *p = c;
   }
   else {
      a = c;
      *p = b;
   }
   printf("a:%d :: 7\n", smcopen(a));
   printf("b:%d :: 7\n", smcopen(b));
   printf("c:%d :: 5\n", smcopen(c));
}

/* Correct results:
   a = 7
   b = 7
   c = 5
*/

