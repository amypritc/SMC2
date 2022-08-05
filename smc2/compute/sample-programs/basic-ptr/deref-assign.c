#include<stdio.h>

public int main(){
   private int a = 12, b = 2, x = 0, y = 0, z = 0;
   private int *px = &x, *py = &y, *pz = &z;
   *px = 4;
   *py = a;
   *pz = b + 3;
   printf("::a :: %d :: 12\n", smcopen(a));
   printf("::b :: %d :: 2\n", smcopen(b));
   printf("::x :: %d :: 4\n", smcopen(x));
   printf("::y :: %d :: 12\n", smcopen(y));
   printf("::z :: %d :: 5\n", smcopen(z));
}
