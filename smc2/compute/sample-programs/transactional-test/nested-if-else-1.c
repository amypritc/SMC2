#include<stdio.h>


public int main(){
   private int a = 3, b = 7, c = 5, d = 1, e = 1, f = 1, g = 1, h = 1;
   if (a < b) {         // TRUE
      a = a + b;        // a = 10
      d = a;            // d = 10
      if (a < c){       // FALSE
         a = a + c;           // a = 15
         e = a;               // e = 15
      }
      else{
         a = a + a;     // a = 20
         f = a;         // f = 20
      }
   }
   else {
      if(a < c){           // TRUE
         a = a + c;        // a = 8
         g = a;            // g = 8
      }
      else{
         a = a + a;        // a = 6
         h = a;            // h = 6
      }
   }
   printf("a:%d :: 20\n", smcopen(a));
   printf("b:%d :: 7\n", smcopen(b));
   printf("c:%d :: 5\n", smcopen(c));
   printf("d:%d :: 10\n", smcopen(d));
   printf("e:%d :: 1\n", smcopen(e));
   printf("f:%d :: 20\n", smcopen(f));
   printf("g:%d :: 1\n", smcopen(g));
   printf("h:%d :: 1\n", smcopen(h));
}
/* Correct results: 
   a = 20
   b = 7
   c = 5
 */

