#include<stdio.h>

public int main(){
   private int a = 4, b = 7, x = 0, y = 0, z = 0;
   private int *pa = &a, *pb = &b, v = 0, w = 0;
   v = *pb - a;
   w = b - *pa;
   x = *pa - 2;
   y = 30 - *pb;
   z = *pb - *pa;
   printf("::a :: %d :: 4\n", smcopen(a));
   printf("::b :: %d :: 7\n", smcopen(b));
   printf("::v :: %d :: 3\n", smcopen(v));
   printf("::w :: %d :: 3\n", smcopen(w));
   printf("::x :: %d :: 2\n", smcopen(x));
   printf("::y :: %d :: 23\n", smcopen(y));
   printf("::z :: %d :: 3\n", smcopen(z));
}
