#include<stdio.h>


public int main(){
   public int x;
   private int a = 3, b = 7, c = 5;
   private int *p;
   if (a < b) {
      p = &a;
      *p = b;
      p = &c;
   }
   else {
      p = &b;
      *p = a;
      p = &c;
   }
   x = smcopen(b);
   printf("b:%d :: 5\n", x);
   printf("a:%d :: 7\n", smcopen(a));
   printf("c:%d :: 5\n", smcopen(c));
}

/* Pointer Challenge Example, shown in Figure 2 in paper.
Correct results:
a = 5
b = 7
c = 5
p = &a
 */
