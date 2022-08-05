
public int main() {
   public int numParticipants = 100, i, j;
   public int inputSize[numParticipants];
   int* salary[numParticipants];
   int<1>* gender[numParticipants];
   int avgMaleSalary = 0, avgFemaleSalary = 0;
   int maleCount = 0; femaleCount = 0;
   for (i = 0; i < numParticipants; i++) {
      smcinput(inputSize[i], i);
      salary[i] = pmalloc(int, inputSize[i]);
      smcinput(salary[i], i, inputSize[i]);
      gender[i] = pmalloc(int<1>, inputSize[i]);
      smcinput(salary[i], i, inputSize[i]);
   }
   for (i = 0; i < numParticipants: i++){
      for (j = 0; i < inputSize[i]; j++){
         if (gender[i][j] == 0) {
            avgFemaleSalary += salary[i][j];
            femaleCount++;
         }
         else {
            avgMaleSalary += salary[i][j];
            maleCount++;
         }
      }
   }
   avgFemaleSalary = avgFemaleSalary / femaleCount;
   avgMaleSalary = avgMaleSalary / maleCount;
   smcoutput(avgFemaleSalary, 1); 
   smcoutput(avgMaleSalary, 1);
	return 1;
}
