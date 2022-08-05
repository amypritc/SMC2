/* File generated from [sample-programs/basic-ops/postinc.c] by PICCO Mon Feb  8 17:40:54 2021
 */

#include <limits.h>

#include <float.h>

//extern void *memcpy(void*,const void*,unsigned int);

//# 1 "ort.onoff.defs"

extern  "C" int   ort_initialize(int*, char***);
 extern "C" void  ort_finalize(int);


/* File generated from [sample-programs/basic-ops/postinc.c] by PICCO Mon Feb  8 17:40:54 2021
 */

#include "smc-compute/SMC_Utils.h"

#include <gmp.h>

#include <omp.h>


SMC_Utils *__s;



int  __original_main(int _argc_ignored, char **_argv_ignored)
{
  
  void* _picco_temp_;
 mpz_t a;
  mpz_init(a);
  __s->smc_set(2, a, -1, 32, "int", -1);
  mpz_t b;
  mpz_init(b);
  __s->smc_set(0, b, -1, 32, "int", -1);
  mpz_t c;
  mpz_init(c);
  __s->smc_set(0, c, -1, 32, "int", -1);

    __s->smc_set(a, b, 32, 32, "int", -1);

    __s->smc_set(a++, c, 32, 32, "int", -1);

  printf("::a :: %d :: 3\n", __s->smc_open(a, -1), -1);

  printf("::b :: %d :: 2\n", __s->smc_open(b, -1), -1);

  printf("::c :: %d :: 2\n", __s->smc_open(c, -1), -1);
}


/* smc-compiler generated main() */
int main(int argc, char **argv)
{

 if(argc < 8){
fprintf(stderr,"Incorrect input parameters\n");
fprintf(stderr,"Usage: <id> <runtime-config> <privatekey-filename> <number-of-input-parties> <number-of-output-parties> <input-share> <output>\n");
exit(1);
}

 std::string IO_files[atoi(argv[4]) + atoi(argv[5])];
for(int i = 0; i < argc-6; i++)
   IO_files[i] = argv[6+i];

__s = new SMC_Utils(atoi(argv[1]), argv[2], argv[3], atoi(argv[4]), atoi(argv[5]), IO_files, 3, 1, 33, "4294967311", 1);

struct timeval tv1;
struct timeval tv2;  int _xval = 0;

  gettimeofday(&tv1,NULL);
  _xval = (int) __original_main(argc, argv);
  gettimeofday(&tv2, NULL);
  std::cout << "Time: " << __s->time_diff(&tv1,&tv2) << std::endl;
  return (_xval);
}

