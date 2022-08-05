#include<stdio.h>


public int main(){
   private int a = 3, b = 7, c = 5, d = 1, e = 1, f = 1;
   if (a < b) {
      if (a < c){
         a = a + b + c;
         d = a;
      }
      else{
         a = a + b;
         e = a;
      }
   }
   else {
      if(a > c){
         a = a + c;
         f = a;
      }
   }
   printf("a:%d :: 15\n", smcopen(a));
   printf("b:%d :: 7\n", smcopen(b));
   printf("c:%d :: 5\n", smcopen(c));
   printf("d:%d :: 15\n", smcopen(d));
   printf("e:%d :: 1\n", smcopen(e));
   printf("f:%d :: 1\n", smcopen(f));
}
/* Correct results: 
   a = 15
   b = 7
   c = 5
 */

