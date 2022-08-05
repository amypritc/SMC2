#include<stdio.h>


public int main(){
   private int a = 3, b = 7, c = 5;
   private int *p1 = &b;
   private int **x = &p1;
   if (a > b) {
      private int *p = 0;
      &p = x;
      *p = 3;
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
