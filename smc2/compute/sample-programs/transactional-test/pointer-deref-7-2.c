#include<stdio.h>


public int main(){
   private int a = 3, b = 7, c = 5;
   private int *p;
   p = NULL;
   if (a > b) {
      p = &a;
      *p = c;
   }
   else {
      p = &b;
   }
   printf("a:%d :: \n", smcopen(a));
   printf("b:%d :: \n", smcopen(b));
   printf("c:%d :: \n", smcopen(c));
}

/* Correct results:
   a =
   b =
   c =
*/
