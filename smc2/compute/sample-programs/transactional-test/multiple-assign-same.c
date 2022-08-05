#include<stdio.h>


public int main(){
   private int a = 3, b = 7, c = 5;
   if (a < b) {
      a = a + b;
      a = a + c;
      a = a * 2;
   }
   else {
      b = b + a + c;
      b = b * 2;
   }
   printf("a:%d :: 30\n", smcopen(a));
   printf("b:%d :: 7\n", smcopen(b));
   printf("c:%d :: 5\n", smcopen(c));
}
/* Correct results:
   a = 30
   b = 7
   c = 5
 */


