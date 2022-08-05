#include<stdio.h>

public int main(){
   private float a = 4.3, b = 7.6, x = 0.0, y = 0.0, z = 0.0;
   private float *pa = &a, *pb = &b, v = 0.0, w = 0.0;
   v = *pb - a;
   w = a - *pa;
   x = a - 2.2;
   y = 30.7 - b;
   z = b - a;
   printf("::a :: %f :: 4.3\n", smcopen(a));
   printf("::b :: %f :: 7.6\n", smcopen(b));
   printf("::v :: %f :: 3.3\n", smcopen(v));
   printf("::w :: %f :: 0.0\n", smcopen(w));
   printf("::x :: %f :: 2.1\n", smcopen(x));
   printf("::y :: %f :: 23.1\n", smcopen(y));
   printf("::z :: %f :: 3.3\n", smcopen(z));
}
