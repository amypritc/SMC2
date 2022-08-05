
// length of input set
public int K=1000; // max size 10 (constant 1000)

public int main()
{
	public int i;	// max size 10 - constant K bounded
	private int year1[K], year2[K];
	private int temp[K]; 	// max size = max(size(year2),size(year1)) + 10
	private int final[K];	// max size = size(temp)

	smcinput(year1, 1, K); 
	smcinput(year2, 1, K);
	
	for(i = 0; i < K; i++){
		temp[i] = (year2[i] - year1[i]) * 1000;
	}
	
	for(i = 0; i < K; i++)[
		final[i] = temp[i] / year1[i];
	]
	
	
	smcoutput(final, 1, K);
	

	return 0;
}
