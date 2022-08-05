#include <stdio.h>

public int main() {
   
   public int S = 100;
   private int A[S]; 
   private int B[S]; 
   smcinput(A, 1, S); 
   smcinput(B, 1, S); 

   private int c = 0, d = 0, e = 0;
   public int i, j;
   
   for (i = 0; i < 100000; i++) {
      j = i%100;
      if (A[j] < B[j]){
         c = c + A[j];
         e = e + c;
         d = d + c;
         e = e - 2;
         c = c + B[j];
         e = e + d;
         d = d + c;
         e = e - c;
         c = c + 2;
         e = e - 2;
         d = d + c;
         e = e + 10;
         e = e - 100;
         e = e + d - c;
      }
      else{
         c = c + B[j];
         e = e + c;
         d = d + c;
         e = e + d;
         c = c + B[j];
         e = e - 50;
         d = d + c;
         e = e + e;
         c = c + 2;
         e = e - c - d;
         d = d + c;
         e = e + 10;
         e = e - 100;
         e = e + d - c;
      }
      if(e > 100000){
         e = e - 100000;
      }
      if(i%50 == 0){
         c = 0;
         d = 0;
         e = 0;
      }
   }
   smcoutput(c, 1);
   smcoutput(d, 1);
   smcoutput(e, 1);
   
   return 0;
}
