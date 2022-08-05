/* File generated from [sample-programs/priv-cond-if-ops-flt/eqeq-f.c] by PICCO Mon Feb  8 17:42:04 2021
 */

#include <limits.h>

#include <float.h>

//extern void *memcpy(void*,const void*,unsigned int);

//# 1 "ort.onoff.defs"

extern  "C" int   ort_initialize(int*, char***);
 extern "C" void  ort_finalize(int);


/* File generated from [sample-programs/priv-cond-if-ops-flt/eqeq-f.c] by PICCO Mon Feb  8 17:42:04 2021
 */

#include "smc-compute/SMC_Utils.h"

#include <gmp.h>

#include <omp.h>


SMC_Utils *__s;



int  __original_main(int _argc_ignored, char **_argv_ignored)
{
  
  mpz_t _picco_tmp1, _picco_tmp2;
  mpz_init(_picco_tmp1);
  mpz_init(_picco_tmp2);

  mpz_t* _picco_ftmp1 = (mpz_t*)malloc(sizeof(mpz_t) * 4);
  for(int _picco_j = 0; _picco_j < 4; _picco_j++)
    mpz_init(_picco_ftmp1[_picco_j]);
  void* _picco_temp_;
 mpz_t* a; 
  a = (mpz_t*)malloc(sizeof(mpz_t) * (4));
  for (int _picco_i = 0; _picco_i < 4; _picco_i++)
        mpz_init(a[_picco_i]);
  __s->smc_set(3, a, -1, -1, 32, 9, "float", -1);
  mpz_t* b; 
  b = (mpz_t*)malloc(sizeof(mpz_t) * (4));
  for (int _picco_i = 0; _picco_i < 4; _picco_i++)
        mpz_init(b[_picco_i]);
  __s->smc_set(6, b, -1, -1, 32, 9, "float", -1);

  mpz_t c;
  mpz_init(c);
  __s->smc_set(0, c, -1, 32, "int", -1);

  __s->smc_eqeq(b, a, _picco_tmp1, 32, 9, 32, 9, 1, "float", -1);
    {
mpz_t _picco_condtmp1;
mpz_init(_picco_condtmp1);
__s->smc_sub(1, _picco_tmp1, _picco_condtmp1, 1, 1, 1, "int", -1);
mpz_t _picco_priv_int_c_1_then;
mpz_init(_picco_priv_int_c_1_then);
mpz_t _picco_priv_int_c_1_else;
mpz_init(_picco_priv_int_c_1_else);
__s->smc_set(c, _picco_priv_int_c_1_else, 32, 32, "int", -1);

{
      {
                __s->smc_set(1, c, -1, 32, "int", -1);
      }
    }
__s->smc_set(c, _picco_priv_int_c_1_then, 32, 32, "int", -1);
__s->smc_set(_picco_priv_int_c_1_else, c, 32, 32, "int", -1);

    {
      {
                __s->smc_set(2, c, -1, 32, "int", -1);
      }
    }
__s->smc_priv_eval(c, _picco_priv_int_c_1_then, _picco_condtmp1, -1);
mpz_clear(_picco_condtmp1);
mpz_clear(_picco_priv_int_c_1_then);
mpz_clear(_picco_priv_int_c_1_else);
}

  printf("::a :: %f :: 3\n", __s->smc_open(a, -1), -1);

  printf("::b :: %f :: 6\n", __s->smc_open(b, -1), -1);

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

__s = new SMC_Utils(atoi(argv[1]), argv[2], argv[3], atoi(argv[4]), atoi(argv[5]), IO_files, 3, 1, 81, "1208925819614629174706411", 1);

struct timeval tv1;
struct timeval tv2;  int _xval = 0;

  gettimeofday(&tv1,NULL);
  _xval = (int) __original_main(argc, argv);
  gettimeofday(&tv2, NULL);
  std::cout << "Time: " << __s->time_diff(&tv1,&tv2) << std::endl;
  return (_xval);
}

