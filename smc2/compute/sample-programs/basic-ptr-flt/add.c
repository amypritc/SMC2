#include<stdio.h>

public int main(){
   private float a = 2.3, b = 7.8, x = 0.0, y = 0.0, z = 0.0;
   private float *pa = &a, *pb = &b, v = 0.0, w = 0.0;
   v = *pb + a;
   w = a + *pa;
   x = a + 4.5;
   y = 3.4 + b;
   z = b + a;
   printf("::a :: %f :: 2.3\n", smcopen(a));
   printf("::b :: %f :: 7.8\n", smcopen(b));
   printf("::v :: %f :: 10.1\n", smcopen(v));
   printf("::w :: %f :: 4.6\n", smcopen(w));
   printf("::x :: %f :: 6.8\n", smcopen(x));
   printf("::y :: %f :: 11.2\n", smcopen(y));
   printf("::z :: %f :: 10.1\n", smcopen(z));
}
