public int M = 32; 		// size = 6

public int main()
{
	private int a, b, c; 
	smcinput(a, 1); 
	public int i; 		// size = 5 (constant propagation/computation results in max 28.8)

	for(i = 0; i < 0.9 * M; i++) 
		b = a * a;					// size = size(a) + size(a)
	for(i = 0; i < 0.1 * M; i++)
		c = a + a; 					// size = size(a) + 1

	smcoutput(b, 1);
	smcoutput(c, 1);
	return 0; 
}
