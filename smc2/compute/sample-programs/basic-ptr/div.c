#include<stdio.h>

public int main(){
   private int a = 12, b = 2, x = 0, y = 0, z = 0;
   private int *pa = &a, *pb = &b, v = 0, w = 0;
   v = *pa / b;
   w = b / *pb;
   x = *pa / 3;
   y = 14 / *pb;
   z = *pa / *pb;
   printf("::a :: %d :: 12\n", smcopen(a));
   printf("::b :: %d :: 2\n", smcopen(b));
   printf("::v :: %d :: 6\n", smcopen(v));
   printf("::w :: %d :: 1\n", smcopen(w));
   printf("::x :: %d :: 4\n", smcopen(x));
   printf("::y :: %d :: 7\n", smcopen(y));
   printf("::z :: %d :: 6\n", smcopen(z));
}
