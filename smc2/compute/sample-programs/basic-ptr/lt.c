#include<stdio.h>

public int main(){
   private int a = 2, b = 7, b1 = 7, x = 0, y = 0, z = 0;
   private int x1 = 0, y1 = 0, z1 = 0, x2 = 0, y2 = 0, z2 = 0;
   private int v = 0, v1 = 0, v2 = 0, w = 0, w1 = 0, w2 = 0;
   private int *pa = &a, *pb = &b, *pb1 = &b1;
   x = *pa < 0;
   x1 = *pa < 2;
   x2 = *pa < 5;
   y = 9 < *pb;
   y1 = 7 < *pb;
   y2 = 1 < *pb;
   v = *pb < a;
   v1 = *pb < b1;
   v2 = *pa < b;
   w = b < *pa;
   w1 = b < *pb1;
   w2 = a < *pb;
   z = *pb < *pa;
   z1 = *pb < *pb1;
   z2 = *pa < *pb;
   printf("::a :: %d :: 2\n", smcopen(a));
   printf("::b :: %d :: 7\n", smcopen(b));
   printf("::b1 :: %d :: 7\n", smcopen(b1));
   printf("::v :: %d :: 0\n", smcopen(v));
   printf("::v1 :: %d :: 0\n", smcopen(v1));
   printf("::v2 :: %d :: 1\n", smcopen(v2));
   printf("::w :: %d :: 0\n", smcopen(w));
   printf("::w1 :: %d :: 0\n", smcopen(w1));
   printf("::w2 :: %d :: 1\n", smcopen(w2));
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
