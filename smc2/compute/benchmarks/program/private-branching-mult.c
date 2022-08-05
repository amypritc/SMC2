#include <stdio.h>

public int main() {
   
   public int S = 100;
   private int A[S]; 
   private int B[S]; 
   smcinput(A, 1, S); 
   smcinput(B, 1, S); 

   private int c;
   public int i, j;
   
   for (i = 0; i < S; i++) {
      if (A[i] < B[i]){
         c = A[i];
         c = c + B[i];
         c = c * 2;
      }
      else{
         c = B[i];
         c = c + B[i];
         c = c + 2;
      }
   }
   smcoutput(c, 1);
   for (i = 0; i < S; i++) {
      if (A[i] < B[i]){
         c = A[i];
         c = c + B[i];
         c = c * 2;
      }
      else{
         c = B[i];
         c = c + B[i];
         c = c + 2;
      }
   }
   smcoutput(c, 1);
   for (i = 0; i < S; i++) {
      if (A[i] < B[i]){
         c = A[i];
         c = c + B[i];
         c = c * 2;
      }
      else{
         c = B[i];
         c = c + B[i];
         c = c + 2;
      }
   }
   smcoutput(c, 1);
   for (i = 0; i < S; i++) {
      if (A[i] < B[i]){
         c = A[i];
         c = c + B[i];
         c = c * 2;
      }
      else{
         c = B[i];
         c = c + B[i];
         c = c + 2;
      }
   }
   smcoutput(c, 1);
   for (i = 0; i < 1000; i++) {
      j = i%100;
      if (A[j] < B[j]){
         c = A[j];
         c = c + B[j];
         c = c * 2;
      }
      else{
         c = B[j];
         c = c + B[j];
         c = c + 2;
      }
   }
   smcoutput(c, 1);
   
   return 0;
}
