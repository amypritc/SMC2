#include<stdio.h>

public int main(){
   private float a = 12.0, b = 2.0, x = 0.0, y = 0.0, z = 0.0;
   private float *px = &x, *py = &y, *pz = &z;
   *px = 4.0;
   *py = a;
   *pz = b + 3.0;
   printf("::a :: %f :: 12.0\n", smcopen(a));
   printf("::b :: %f :: 2.0\n", smcopen(b));
   printf("::x :: %f :: 4.0\n", smcopen(x));
   printf("::y :: %f :: 12.0\n", smcopen(y));
   printf("::z :: %f :: 5.0\n", smcopen(z));
}
