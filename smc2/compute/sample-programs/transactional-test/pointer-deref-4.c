#include<stdio.h>


public int main(){
   private int a = 3, b = 7, c = 5;
   private int *p1, *p2;
   p1 = &a;
   p2 = &b;
   if (a < b) {
      *p2 = a + b;
      *p1 = c - a;
   }
   else {
      *p2 = *p1 + *p2;
      *p1 = b * a;
   }
   printf("a:%d :: 2\n", smcopen(a));
   printf("b:%d :: 10\n", smcopen(b));
   printf("c:%d :: 5\n", smcopen(c));
}

/* Correct results:
   a = 2
   b = 10
   c = 5
*/
