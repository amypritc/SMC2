#include<stdio.h>

public int main(){
   private float a = 2.2, b = 7.8, x = 0.0, y = 0.0, z = 0.0;
   private float *pa = &a, *pb = &b, v = 3.4, w = 0.0;
   v = *pb * v;
   w = a * *pa;
   x = a * 4.4;
   y = 3.4 * b;
   z = b * a;
   printf("::a :: %f :: 2.2\n", smcopen(a));
   printf("::b :: %f :: 7.8\n", smcopen(b));
   printf("::v :: %f :: 26.52\n", smcopen(v));
   printf("::w :: %f :: 4.84\n", smcopen(w));
   printf("::x :: %f :: 9.68\n", smcopen(x));
   printf("::y :: %f :: 26.52\n", smcopen(y));
   printf("::z :: %f :: 17.16\n", smcopen(z));
}
