
public int main()
{
  private int<6> A, B, C;
  // size(C) = size(A) + size(B) = 6 + 6 = 12
  
  smcinput(A, 1); 
  smcinput(B, 1); 
  
  // measuring performance of a large number of multiplications
  for(i = 0; i < 10000000; i++)
    C = A * B;                  
  printf("first done...\n"); 
  for(i = 0; i < 10000000; i++)
    C = A * B;  
  printf("second done...\n"); 
  for(i = 0; i < 10000000; i++)
    C = A * B;  
  printf("third done...\n"); 
  for(i = 0; i < 10000000; i++)
    C = A * B;  
  printf("fourth done...\n");

  smcoutput(C, 1);
  return 0;
}
