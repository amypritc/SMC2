#include<stdio.h>


public int main(){
   private int a = 3, b = 7, c = 5;
   private int *p;
   p = &a;
   if (a < b) {
      *p = c;
   }
   else {
      *p = b;
   }
   printf("a:%d :: 5\n", smcopen(a));
   printf("b:%d :: 7\n", smcopen(b));
   printf("c:%d :: 5\n", smcopen(c));
}
/* Correct results: 
   a = 5
   b = 7
   c = 5
 */

