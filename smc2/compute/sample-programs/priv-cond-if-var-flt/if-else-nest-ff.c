#include<stdio.h>


public int main(){
   private float a = 0.0, b = 0.0, c = 0.0;
   if (a) {
      c = 1.2;
      if (b) {
         c = 2.3;
      }
      else{
         c = 3.4;
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
   printf("::a :: %f :: 0.0\n", smcopen(a));
   printf("::b :: %f :: 0.0\n", smcopen(b));
   printf("::c :: %f :: 6.7\n", smcopen(c));
}


