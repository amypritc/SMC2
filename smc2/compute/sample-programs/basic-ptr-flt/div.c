#include<stdio.h>

public int main(){
   private float a = 12.4, b = 2.5, x = 0.0, y = 0.0, z = 0.0;
   private float *pa = &a, *pb = &b, v = 0.0, w = 8.0;
   v = *pa / a;
   w = w / *pb;
   x = a / 4.0;
   y = 14.5 / b;
   z = a / b;
   printf("::a :: %f :: 12.4\n", smcopen(a));
   printf("::b :: %f :: 2.5\n", smcopen(b));
   printf("::v :: %f :: 1.0\n", smcopen(v));
   printf("::w :: %f :: 3.2\n", smcopen(w));
   printf("::x :: %f :: 3.1\n", smcopen(x));
   printf("::y :: %f :: 5.8\n", smcopen(y));
   printf("::z :: %f :: 4.96\n", smcopen(z));
}
