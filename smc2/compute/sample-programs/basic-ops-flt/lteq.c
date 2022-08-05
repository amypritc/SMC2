#include<stdio.h>

public int main(){
   private float a = 1.5, b = 0.125, b1 = 0.125;
   private int x = 0, y = 0, z = 0, x1 = 0, y1 = 0, z1 = 0, x2 = 0, y2 = 0, z2 = 0;
   x = a <= 0.0;
   x1 = a <= 1.5;
   x2 = a <= 2.7;
   y = 9.5 <= b;
   y1 = 0.125 <= b;
   y2 = 0.025 <= b;
   z = b <= a;
   z1 = b <= b1;
   z2 = a <= b;
   printf("::a :: %f :: 1.5\n", smcopen(a));
   printf("::b :: %f :: 0.125\n", smcopen(b));
   printf("::b1 :: %f :: 0.125\n", smcopen(b1));
   printf("::x :: %d :: 0\n", smcopen(x));
   printf("::x1 :: %d :: 1\n", smcopen(x1));
   printf("::x2 :: %d :: 1\n", smcopen(x2));
   printf("::y :: %d :: 0\n", smcopen(y));
   printf("::y1 :: %d :: 1\n", smcopen(y1));
   printf("::y2 :: %d :: 1\n", smcopen(y2));
   printf("::z :: %d :: 1\n", smcopen(z));
   printf("::z1 :: %d :: 1\n", smcopen(z1));
   printf("::z2 :: %d :: 0\n", smcopen(z2));
}
