#include<stdio.h>


public int main(){
   private int a = 3, b = 7, c = 5;
   private int *p1, *p2;
   p1 = &a;
   p2 = &b;
   if (a > b) {
      *p2 = a;
      *p2 = *p2 + a;
   }
   else {
      *p1 = b + a;
      *p1 = *p1 + b;
   }
   printf("a:%d :: 17\n", smcopen(a));
   printf("b:%d :: 7\n", smcopen(b));
   printf("c:%d :: 5\n", smcopen(c));
}

/* Correct results:
   a = 17
   b = 7
   c = 5
*/
