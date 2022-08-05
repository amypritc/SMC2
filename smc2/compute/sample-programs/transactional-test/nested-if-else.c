#include<stdio.h>


public int main(){
   private int a = 3, b = 7, c = 5, d = 1;
   private float f = 2.4;
   if (a < b) {
      a = a + b;
      if (a < c){
         a = a + c;
         d = a;
      }
      else{
         a = a + a;
      }
   }
   else {
      f = f * f;
      if(a < c){
         a = a + c;
      }
      else{
         a = a + a;
      }
   }
   printf("a:%d :: 20\n", smcopen(a));
   printf("b:%d :: 7\n", smcopen(b));
   printf("c:%d :: 5\n", smcopen(c));
   printf("d:%d :: 1\n", smcopen(d));
   printf("f:%d :: 2.4\n", smcopen(f));
}


