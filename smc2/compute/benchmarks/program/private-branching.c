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
      }
      else{
         c = B[i];
      }
   }
   smcoutput(c, 1);
   for (i = 0; i < S; i++) {
      if (A[i] > B[i]){
         c = A[i];
      }
      else{
         c = B[i];
      }
   }
   smcoutput(c, 1);
   for (i = 0; i < S; i++) {
      if (A[i] < B[i]){
         c = B[i] - A[i];
      }
      else{
         c = A[i] - B[i];
      }
   }
   smcoutput(c, 1);
   for (i = 0; i < S; i++) {
      if (A[i] > B[i]){
         c = A[i] - B[i];
      }
      else{
         c = B[i] - A[i];
      }
   }
   smcoutput(c, 1);
   for (i = 0; i < 1000; i++) {
      j = i%100;
      if (A[j] < B[j]){
         c = A[j];
      }
      else{
         c = B[j];
      }
   }
   smcoutput(c, 1);
   
   return 0;
}
