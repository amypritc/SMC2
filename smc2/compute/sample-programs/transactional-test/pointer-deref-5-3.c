#include<stdio.h>


public int main(){
   private int a = 3, b = 7, c = 5;
   private int *p1, *p2;
   if (a < b){
      p1 = &a;
      p2 = &b;
   }
   else{
      p1 = &b;
      p2 = &c;
   }
   if (a < b) {
      *p2 = a;
      *p2 = *p2 + a;
   }
   else {
      *p1 = b + a;
      *p1 = *p1 + b;
   }
   printf("a:%d :: 3\n", smcopen(a));
   printf("b:%d :: 6\n", smcopen(b));
   printf("c:%d :: 5\n", smcopen(c));
}

/* Correct results:
   a = 3
   b = 6
   c = 5
*/
