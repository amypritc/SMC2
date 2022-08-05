#include<stdio.h>


public int main(){
   private int a = 3, b = 7, c;
   private int *p;
   p = &c;
   if (a < b){
      p = &a;
      c = a - b;
   }
   else{
      p = &b;
      c = a + b;
   }
   if (a < b) {
      *p = c;
   }
   else {
      p = &b;
   }
   printf("a:%d :: -4\n", smcopen(a));
   printf("b:%d :: 7\n", smcopen(b));
   printf("c:%d :: -4\n", smcopen(c));
}

/* Pointer Challenge Example, shown in Figure 2 in paper.
Correct results:
a = -4
b = 7
c = -4
p = &a
 */
