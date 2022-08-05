/* File generated from [sample-programs/basic-ptr-flt/ptr-eq.c] by PICCO Mon Feb  8 17:41:13 2021
 */

#include <limits.h>

#include <float.h>

//extern void *memcpy(void*,const void*,unsigned int);

//# 1 "ort.onoff.defs"

extern  "C" int   ort_initialize(int*, char***);
 extern "C" void  ort_finalize(int);


/* File generated from [sample-programs/basic-ptr-flt/ptr-eq.c] by PICCO Mon Feb  8 17:41:13 2021
 */

#include "smc-compute/SMC_Utils.h"

#include <gmp.h>

#include <omp.h>


SMC_Utils *__s;



int  __original_main(int _argc_ignored, char **_argv_ignored)
{
  
  mpz_t _picco_tmp1;
  mpz_init(_picco_tmp1);

  mpz_t* _picco_ftmp1 = (mpz_t*)malloc(sizeof(mpz_t) * 4);
  for(int _picco_j = 0; _picco_j < 4; _picco_j++)
    mpz_init(_picco_ftmp1[_picco_j]);
  void* _picco_temp_;
   mpz_t *_picco_priv_ftmp1 = (mpz_t*)malloc(sizeof(mpz_t) * 4);
  mpz_t *_picco_priv_ftmp2 = (mpz_t*)malloc(sizeof(mpz_t) * 4);
  for(int i = 0; i < 4; i++){
    mpz_init(_picco_priv_ftmp1[i]);
    mpz_init(_picco_priv_ftmp2[i]);
}
  priv_ptr _picco_tmp_float_ptr1 = __s->smc_new_ptr(1, 1);
  priv_ptr _picco_tmp_float_ptr2 = __s->smc_new_ptr(1, 1);
mpz_t* a; 
  a = (mpz_t*)malloc(sizeof(mpz_t) * (4));
  for (int _picco_i = 0; _picco_i < 4; _picco_i++)
        mpz_init(a[_picco_i]);
  __s->smc_set(1.5, a, -1, -1, 32, 9, "float", -1);
  mpz_t* b; 
  b = (mpz_t*)malloc(sizeof(mpz_t) * (4));
  for (int _picco_i = 0; _picco_i < 4; _picco_i++)
        mpz_init(b[_picco_i]);
  __s->smc_set(4.0, b, -1, -1, 32, 9, "float", -1);

  mpz_t x;
  mpz_init(x);
  __s->smc_set(0, x, -1, 32, "int", -1);
  mpz_t y;
  mpz_init(y);
  __s->smc_set(0, y, -1, 32, "int", -1);

  priv_ptr pa = __s->smc_new_ptr(1, 1);
  __s->smc_set_float_ptr(pa, &a, "float", -1);
  priv_ptr pb = __s->smc_new_ptr(1, 1);
  __s->smc_set_float_ptr(pb, &b, "float", -1);
  priv_ptr pb1 = __s->smc_new_ptr(1, 1);
  __s->smc_set_float_ptr(pb1, &b, "float", -1);

  __s->smc_eqeq(pb, pa, _picco_tmp1, 32, 9, 32, 9, 1, "float", -1);
  __s->smc_set(_picco_tmp1, x, 1, 32, "int", -1);

  __s->smc_eqeq(pb, pb1, _picco_tmp1, 32, 9, 32, 9, 1, "float", -1);
  __s->smc_set(_picco_tmp1, y, 1, 32, "int", -1);

  printf("::a :: %f :: 1.5\n", __s->smc_open(a, -1), -1);

  printf("::b :: %f :: 4.0\n", __s->smc_open(b, -1), -1);

  printf("::x :: %d :: 0\n", __s->smc_open(x, -1), -1);

  printf("::y :: %d :: 1\n", __s->smc_open(y, -1), -1);
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

