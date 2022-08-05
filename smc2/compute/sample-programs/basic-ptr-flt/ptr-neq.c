#include<stdio.h>

public int main(){
   private float a = 1.5, b = 4.0;
   private int x = 0, y = 0;
   private float *pa = &a, *pb = &b, *pb1 = &b;
   x = pb != pa;
   y = pb != pb1;
   printf("::a :: %f :: 1.5\n", smcopen(a));
   printf("::b :: %f :: 4.0\n", smcopen(b));
   printf("::x :: %d :: 1\n", smcopen(x));
   printf("::y :: %d :: 0\n", smcopen(y));
}
