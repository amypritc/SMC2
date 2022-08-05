#include<stdio.h>

public int main(){
   private int a = 2, b = 7, x = 0, y = 0;
   private int *pa = &a, *pb = &b, *pb1 = &b;
   x = pb != pa;
   y = pb != pb1;
   printf("::a :: %d :: 2\n", smcopen(a));
   printf("::b :: %d :: 7\n", smcopen(b));
   printf("::x :: %d :: 1\n", smcopen(x));
   printf("::y :: %d :: 0\n", smcopen(y));
}
