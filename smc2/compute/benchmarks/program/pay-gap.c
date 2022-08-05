
public int main() {
   public int numParticipants = 100, i, j;
   public int maxInputSize = 100;
   public int inputSize[numParticipants], inputNum;
   private int salary[numParticipants][maxInputSize];
   private int<1> gender[numParticipants][maxInputSize];
   private int avgMaleSalary = 0, avgFemaleSalary = 0;
   private int maleCount = 0, femaleCount = 0;
   public int historicFemaleSalaryAvg, historicMaleSalaryAvg;
   //printf("reading input - inputSize\n");
   smcinput(inputSize, 1, numParticipants);
   //printf("reading input - salary\n");
   smcinput(gender, 1, numParticipants, maxInputSize);
   //printf("reading input - gender\n");
   smcinput(salary, 1, numParticipants, maxInputSize);
   smcinput(historicFemaleSalaryAvg, 1);
   smcinput(historicMaleSalaryAvg, 1);
   //printf("adding\n");
   for (i = 0; i < numParticipants; i++){
      for (j = 0; j < inputSize[i]; j++){
         if (gender[i][j] == 0) {
            avgFemaleSalary += salary[i][j];
            femaleCount++;
         }
         else {
            avgMaleSalary += salary[i][j];
            maleCount++;
         }

      }
      //printf("count = %d - %d\n", smcopen(femaleCount), smcopen(maleCount));
      //printf("avgSal = %d - %d\n", smcopen(avgFemaleSalary), smcopen(avgMaleSalary));
   }
   //printf("averaging\n");
   avgFemaleSalary = (avgFemaleSalary / femaleCount)/2 + historicFemaleSalaryAvg/2;
   avgMaleSalary = (avgMaleSalary / maleCount)/2 + historicFemaleSalaryAvg/2;
   //printf("writing output\n");
   smcoutput(avgFemaleSalary, 1); 
   smcoutput(avgMaleSalary, 1);
   //printf("done\n");
	return 1;
}
