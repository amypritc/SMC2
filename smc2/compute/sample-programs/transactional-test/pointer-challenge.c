#include<stdio.h>


public int main(){
   public int x;
   private int a = 3, b = 7, c = 5;
   private int *p;
   p = &a;
   if (a < b) {
      *p = c;
   }
   else {
      p = &b;
   }
   x = smcopen(b);
   printf("a:%d :: 5\n", smcopen(a));
   printf("b:%d :: 7\n", x);
   printf("c:%d :: 5\n", smcopen(c));
}

/* Pointer Challenge Example, shown in Figure 2 in paper.
Correct results:
a = 5
b = 7
c = 5
p = &a
 */
