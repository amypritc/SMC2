#include<stdio.h>


public int main(){
   private int a = 3, b = 7, c = 5;
   private int *p;
   if (a < b){
      p = &a;
   }
   else{
      p = &b;
   }
   if (a < b) {
      a = b;
      *p = c;
   }
   else {
      a = c;
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

