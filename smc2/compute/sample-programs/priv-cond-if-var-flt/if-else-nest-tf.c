#include<stdio.h>


public int main(){
   private float a = 3.4, b = 0.0, c = 0.0;
   if (a) {
      c = 1.2;
      if (b) {
         c = 2.3;
      }
      else{
         c = 3.2;
      }
   }
   else {
      c = 4.5;
      if (b) {
         c = 5.6;
      }
      else{
         c = 6.7;
      }
   }
   printf("::a :: %f :: 3.4\n", smcopen(a));
   printf("::b :: %f :: 0.0\n", smcopen(b));
   printf("::c :: %f :: 3.2\n", smcopen(c));
}


