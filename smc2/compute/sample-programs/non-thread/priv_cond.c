
public int main() {
   private int a, b, d; 
   private float fa, fb, fc, fd;  

   smcinput(a, 1);
   smcinput(b, 1);
   smcinput(fa, 1);
   smcinput(fb, 1);
   smcinput(fc, 1);
   
   printf("INT PRIVATE CONDITION...\n"); 
   if(a > b)         // (3) size(d) = max(1,2) = 2
   	d = 1;         // (1) size(d) = 1
   else
	   d = 2;         // (2) size(d) = 2
   smcoutput(d, 1); 
   printf("\n"); 
	
   printf("FLOAT PRIVATE CONDITION...\n"); 
   if(fa >  fb)   // (6) size(fd) = 2 = max(1,2)
	   fd = 1;     // (4) size(fd) = 1
   else 
	   fd = 2;     // (5) size(fd) = 2
   smcoutput(fd, 1); 
   printf("\n"); 

   printf("COMBINATION\n"); 
   if(a < b){           // (11) size(fa) = max(2,1) = 2
                        //      size(fd) = max(4,2) = 4
                        //      size(d) = max(3,2) = 3
	   fa = 2;           // (7) size(fa) = 2
   	if(fb < fc){      // (10) size(fd) = max(4,2)
                        //      size(d) = max(3,2)
		   fd = 10;       // (8) size(fd) = 4
		   d = 5;         // (9) size(d) = 3
	   }
   }
   smcoutput(fa, 1); 
   printf("\n"); 
   smcoutput(fd, 1); 
   printf("\n"); 
   smcoutput(d, 1); 
   printf("\n"); 

   if(a < b && fb < fc){    // (18) size(fa) = max(2,2) = 2
                            //      size(fd) = max(5,4) = 5
                            //      size(d) = max(5,3) = 5
	   fa = 2;               // (12) size(fa) = 2 
   	if(a > b || fb > fc){ // (17) size(fd) = max(5,5) = 5
                            //      size(d) = max(4,5) = 5
		   fd = 20;           // (13) size(fd) = 5
		   d = 10;            // (14) size(d) = 4
	   }
	   else{
		   fd = 30;           // (15) size(fd) = 5
		   d = 20;            // (16) size(d) = 5
	   }
   }

   smcoutput(fa, 1); 
   printf("\n"); 
   smcoutput(fd, 1); 
   printf("\n"); 
   smcoutput(d, 1); 
   printf("\n"); 
   return 0;
}
