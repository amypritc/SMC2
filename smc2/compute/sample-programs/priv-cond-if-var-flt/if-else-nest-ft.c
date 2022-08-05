#include<stdio.h>


public int main(){
   private float a = 0.0, b = 7.8, c = 0.0;
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
   printf("::b :: %f :: 7.8\n", smcopen(b));
   printf("::c :: %f :: 5.6\n", smcopen(c));
}


