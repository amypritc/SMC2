#include<stdio.h>

public int main(){
   private int a = 2, b = 7, x = 0, y = 0, z = 0;
   private int *pa = &a, *pb = &b, v = 0, w = 0;
   v = *pb + a;
   w = a + *pa;
   x = *pa + 4;
   y = 3 + *pb;
   z = *pb + *pa;
   printf("::a :: %d :: 2\n", smcopen(a));
   printf("::b :: %d :: 7\n", smcopen(b));
   printf("::v :: %d :: 9\n", smcopen(v));
   printf("::w :: %d :: 4\n", smcopen(w));
   printf("::x :: %d :: 6\n", smcopen(x));
   printf("::y :: %d :: 10\n", smcopen(y));
   printf("::z :: %d :: 9\n", smcopen(z));
}
