public int main() {
   
   // SS = S*S
   public int S = 100;    // size = 7
   public int SS = 10000;   // size = 14
   private int A[S]; 
   public int B[S]; 
   smcinput(A, 1, S); 
   smcinput(B, 2, S); 

   public int i, j;       // size = 7 (bounded by S)
   private int<1> C[S*S], D[S*S];   // size = 1 (always '==' op, returns size 1)
   
   for (i = 0; i < S; i++) {
     for (j = 0; j < S; j++) {
       C[i*S+j] = A[i] == A[j];    // C size = 1
       D[i*S+j] = A[i] == B[j];    // D size = 1
     }
   }

   smcoutput(C, 1, SS);
   smcoutput(D, 1, SS);
   
   return 0;
}
