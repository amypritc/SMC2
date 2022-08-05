#include<stdio.h>

public int main(){
   private float a = 1.5, b = 0.125, b1 = 0.125;
   private int x = 0, y = 0, z = 0, x1 = 0, y1 = 0, z1 = 0, x2 = 0, y2 = 0, z2 = 0;
   private int v = 0, v1 = 0, v2 = 0, w = 0, w1 = 0, w2 = 0;
   private float *pa = &a, *pb = &b, *pb1 = &b1;
   x = a <= 0.0;
   x1 = a <= 1.5;
   x2 = a <= 2.7;
   y = 9.5 <= b;
   y1 = 0.125 <= b;
   y2 = 0.025 <= b;
   v = *pb <= a;
   v1 = *pb <= b1;
   v2 = *pa <= b;
   w = b <= *pa;
   w1 = b <= *pb1;
   w2 = a <= *pb;
   z = b <= a;
   z1 = b <= b1;
   z2 = a <= b;
   printf("::a :: %f :: 1.5\n", smcopen(a));
   printf("::b :: %f :: 0.125\n", smcopen(b));
   printf("::b1 :: %f :: 0.125\n", smcopen(b1));
   printf("::v :: %d :: 1\n", smcopen(v));
   printf("::v1 :: %d :: 1\n", smcopen(v1));
   printf("::v2 :: %d :: 0\n", smcopen(v2));
   printf("::w :: %d :: 1\n", smcopen(w));
   printf("::w1 :: %d :: 1\n", smcopen(w1));
   printf("::w2 :: %d :: 0\n", smcopen(w2));
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
