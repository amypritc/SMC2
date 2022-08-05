// Searches input (character) array A for a pattern stored in (character)
// array B 
// The program determines all locations where the pattern is found, but
// outputs the smaller of the first 10 and actual number found

public int K=20; // the length of the array to be searched
public int L=5;  // the length of the search pattern


public int main()
{
	public int i, j, k;
	private int match[K-L+1][L];	//counter for matching elements 
	private int<5> match_index = 0; // counts the current number of matches
	private int<8> total_match[K-L+1]; 
	private int<1> m[K-L+1];
	private int<8> A[K]; // array that holds party 1's input
	private int<8> B[L];    // the pattern being searched for
	private int<10> loc[10]; // array that holds the first 10 positions where a match was found

	smcinput(A, 1, K);
	smcinput(B, 1, L);
	
	for(i = 0; i < K-L+1; i++) {	
	  for(k = 0; k < L; k++)
	    match[i][k] = 0; 
	  total_match[i] = 0;
	}
	
	for(i = 0; i < K-L+1; i++) [ 
	  for(j = 0; j < L; j++) [ 	
	    if(A[i+j] == B[j])
	      match[i][j] = 1;		
	  ]
	]

	for(i = 0; i < K-L+1; i++)
	  for(k = 0; k < L; k++)
	    total_match[i] = total_match[i] + match[i][k];
	 
	for(i = 0; i < K-L+1; i++)
	[	
		if (total_match[i] == L)
			m[i] = 1;
		else
			m[i] = 0;
	]

	for (i = 0; i < K-L+1; i++) {
	  if (m[i] == 1 && match_index < 10) {
	    loc[match_index] = i;
	    match_index = match_index + 1;	
	  }
	}
	smcoutput(loc, 1, 10);
	return 0;
}
