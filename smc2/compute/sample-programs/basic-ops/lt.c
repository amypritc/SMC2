#include<stdio.h>

public int main(){
   private int a = 2, b = 7, b1 = 7, x = 0, y = 0, z = 0;
   private int x1 = 0, y1 = 0, z1 = 0, x2 = 0, y2 = 0, z2 = 0;
   x = a < 0;
   x1 = a < 2;
   x2 = a < 5;
   y = 9 < b;
   y1 = 7 < b;
   y2 = 1 < b;
   z = b < a;
   z1 = b < b1;
   z2 = a < b;
   printf("::a :: %d :: 2\n", smcopen(a));
   printf("::b :: %d :: 7\n", smcopen(b));
   printf("::b1 :: %d :: 7\n", smcopen(b1));
   printf("::x :: %d :: 0\n", smcopen(x));
   printf("::x1 :: %d :: 0\n", smcopen(x1));
   printf("::x2 :: %d :: 1\n", smcopen(x2));
   printf("::y :: %d :: 0\n", smcopen(y));
   printf("::y1 :: %d :: 0\n", smcopen(y1));
   printf("::y2 :: %d :: 1\n", smcopen(y2));
   printf("::z :: %d :: 0\n", smcopen(z));
   printf("::z1 :: %d :: 0\n", smcopen(z1));
   printf("::z2 :: %d :: 1\n", smcopen(z2));
}
