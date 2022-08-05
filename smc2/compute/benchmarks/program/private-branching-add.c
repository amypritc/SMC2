#include <stdio.h>

public int main() {
   
   public int S = 100;
   private int A[S]; 
   private int B[S]; 
   smcinput(A, 1, S); 
   smcinput(B, 1, S); 

   private int c, d;
   public int i, j;
   
   for (i = 0; i < S; i++) {
      if (A[i] < B[i]){
         c = A[i];
         d = c;
         c = c + B[i];
         d = d * c;
         c = c * 2;
         d = d + c;
      }
      else{
         c = B[i];
         d = c;
         c = c + B[i];
         d = d * c;
         c = c + 2;
         d = d + c;
      }      
   }
   smcoutput(c, 1);
   smcoutput(d, 1);
   for (i = 0; i < S; i++) {
      if (A[i] < B[i]){
         c = A[i];
         d = c;
         c = c + B[i];
         d = d * c;
         c = c * 2;
         d = d + c;
      }
      else{
         c = B[i];
         d = c;
         c = c + B[i];
         d = d * c;
         c = c + 2;
         d = d + c;
      }
   }
   smcoutput(c, 1);
   smcoutput(d, 1);
   for (i = 0; i < S; i++) {
      if (A[i] < B[i]){
         c = A[i];
         d = c;
         c = c + B[i];
         d = d * c;
         c = c * 2;
         d = d + c;
      }
      else{
         c = B[i];
         d = c;
         c = c + B[i];
         d = d * c;
         c = c + 2;
         d = d + c;
      }
   }
   smcoutput(c, 1);
   smcoutput(d, 1);
   for (i = 0; i < S; i++) {
      if (A[i] < B[i]){
         c = A[i];
         d = c;
         c = c + B[i];
         d = d * c;
         c = c * 2;
         d = d + c;
      }
      else{
         c = B[i];
         d = c;
         c = c + B[i];
         d = d * c;
         c = c + 2;
         d = d + c;
      }
   }
   smcoutput(c, 1);
   smcoutput(d, 1);
   for (i = 0; i < 1000; i++) {
      j = i%100;
      if (A[j] < B[j]){
         c = A[j];
         d = c;
         c = c + B[j];
         d = d * c;
         c = c * 2;
         d = d + c;
      }
      else{
         c = B[j];
         d = c;
         c = c + B[j];
         d = d * c;
         c = c + 2;
         d = d + c;
      }
   }
   smcoutput(c, 1);
   smcoutput(d, 1);
   
   return 0;
}
