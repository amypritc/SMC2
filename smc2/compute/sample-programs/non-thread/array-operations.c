
public int K = 10, K1 = 2, K2 = 5; // K needs to be equal to K1*K2

public int main() {

  public int i,j;
  int A[K], B[K];
  float C[K], D[K];
  
  smcinput(A, 1, K); 
  smcinput(C, 1, K);
  
  //integer array operations 
  A = A * A;            // size = size(A) + size(A)
  smcoutput(A, 1, K); 
  A = A + A;           // size = size(A) + 1
  smcoutput(A, 1, K); 
  B = A == A;          // size = 1
  smcoutput(B, 1, K); 
	
  //float array operations
  B = C == C;           // size = 1
  smcoutput(B, 1, K); 
  B = C < C;            // size = 1
  smcoutput(B, 1, K); 
  D = C + C;            // size = size(C) + 1
  smcoutput(D, 1, K); 
  
  private int a; 
  a = A @ B; 
  smcoutput(a, 1);

  int E[K1][K2];
  for (i = 0; i < K1; i++)
    for (j = 0; j < K2; j++)
      E[i][j] = A[i*K1 + j];    // size = size(A)
  
  if(A[0] < 100){	
    for(i = 0; i < K1; i++)[
      if(A[i] < 100)
	B[i] = E[i] @ E[i]; 
      ]
  }
  smcoutput(B, 1, K2); 		

  return 0;
}
