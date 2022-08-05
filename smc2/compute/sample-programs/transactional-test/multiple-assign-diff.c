#include<stdio.h>


public int main(){
   private int a = 3, b = 7, c = 5;
   if (a < b) {
      a = a * 2;
      b = b - a;
      c = c + a;
   }
   else {
      a = b + a + c;
      b = b * 2;
      c = c + a;
   }
   printf("a:%d :: 6\n", smcopen(a));
   printf("b:%d :: 1\n", smcopen(b));
   printf("c:%d :: 11\n", smcopen(c));
}
/* Correct results:
   a = 6
   b = 1
   c = 11
 */

