#include<stdio.h>


public int main(){
   public int a = 3, b = 7, c = 5, d = 1;
   if (a > b) {
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
      if(a < c){
         a = a + c;
      }
      else{
         a = a + a;
      }
   }
   printf("::a :: %d :: 8\n", a);
   printf("::b :: %d :: 7\n", b);
   printf("::c :: %d :: 5\n", c);
   printf("::d :: %d :: 1\n", d);
}

