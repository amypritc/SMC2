#include<stdio.h>


public int main(){
   private int a = 3, b = 7, c = 5, d = 0;
   if (a < b) {
      d = c++;
   }
   else {
      c = 4;
   }
   printf("::a :: %d :: 3\n", smcopen(a));
   printf("::b :: %d :: 7\n", smcopen(b));
   printf("::c :: %d :: 6\n", smcopen(c));
   printf("::d :: %d :: 5\n", smcopen(d));
}


