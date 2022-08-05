#include<stdio.h>


public int main(){
   private float a = 3.4, b = 7.8, c = 0.1;
   if (a) {
      c = 1.2;
      if (b) {
         c = 2.3;
      }
   }
   printf("::a :: %f :: 3.4\n", smcopen(a));
   printf("::b :: %f :: 7.8\n", smcopen(b));
   printf("::c :: %f :: 2.3\n", smcopen(c));
}


