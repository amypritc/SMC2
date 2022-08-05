/* File generated from [sample-programs/basic-ops-flt/gt.c] by PICCO Mon Feb  8 17:41:01 2021
 */

#include <limits.h>

#include <float.h>

//extern void *memcpy(void*,const void*,unsigned int);

//# 1 "ort.onoff.defs"

extern  "C" int   ort_initialize(int*, char***);
 extern "C" void  ort_finalize(int);


/* File generated from [sample-programs/basic-ops-flt/gt.c] by PICCO Mon Feb  8 17:41:01 2021
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
 mpz_t* a; 
  a = (mpz_t*)malloc(sizeof(mpz_t) * (4));
  for (int _picco_i = 0; _picco_i < 4; _picco_i++)
        mpz_init(a[_picco_i]);
  __s->smc_set(1.5, a, -1, -1, 32, 9, "float", -1);
  mpz_t* b; 
  b = (mpz_t*)malloc(sizeof(mpz_t) * (4));
  for (int _picco_i = 0; _picco_i < 4; _picco_i++)
        mpz_init(b[_picco_i]);
  __s->smc_set(0.125, b, -1, -1, 32, 9, "float", -1);
  mpz_t* b1; 
  b1 = (mpz_t*)malloc(sizeof(mpz_t) * (4));
  for (int _picco_i = 0; _picco_i < 4; _picco_i++)
        mpz_init(b1[_picco_i]);
  __s->smc_set(0.125, b1, -1, -1, 32, 9, "float", -1);

  mpz_t x;
  mpz_init(x);
  __s->smc_set(0, x, -1, 32, "int", -1);
  mpz_t y;
  mpz_init(y);
  __s->smc_set(0, y, -1, 32, "int", -1);
  mpz_t z;
  mpz_init(z);
  __s->smc_set(0, z, -1, 32, "int", -1);
  mpz_t x1;
  mpz_init(x1);
  __s->smc_set(0, x1, -1, 32, "int", -1);
  mpz_t y1;
  mpz_init(y1);
  __s->smc_set(0, y1, -1, 32, "int", -1);
  mpz_t z1;
  mpz_init(z1);
  __s->smc_set(0, z1, -1, 32, "int", -1);
  mpz_t x2;
  mpz_init(x2);
  __s->smc_set(0, x2, -1, 32, "int", -1);
  mpz_t y2;
  mpz_init(y2);
  __s->smc_set(0, y2, -1, 32, "int", -1);
  mpz_t z2;
  mpz_init(z2);
  __s->smc_set(0, z2, -1, 32, "int", -1);

  __s->smc_gt(a, 0.0, _picco_tmp1, 32, 9, -1, -1, 1, "float", -1);
  __s->smc_set(_picco_tmp1, x, 1, 32, "int", -1);

  __s->smc_gt(a, 1.5, _picco_tmp1, 32, 9, -1, -1, 1, "float", -1);
  __s->smc_set(_picco_tmp1, x1, 1, 32, "int", -1);

  __s->smc_gt(a, 2.7, _picco_tmp1, 32, 9, -1, -1, 1, "float", -1);
  __s->smc_set(_picco_tmp1, x2, 1, 32, "int", -1);

  __s->smc_gt(9.5, b, _picco_tmp1, -1, -1, 32, 9, 1, "float", -1);
  __s->smc_set(_picco_tmp1, y, 1, 32, "int", -1);

  __s->smc_gt(0.125, b, _picco_tmp1, -1, -1, 32, 9, 1, "float", -1);
  __s->smc_set(_picco_tmp1, y1, 1, 32, "int", -1);

  __s->smc_gt(0.025, b, _picco_tmp1, -1, -1, 32, 9, 1, "float", -1);
  __s->smc_set(_picco_tmp1, y2, 1, 32, "int", -1);

  __s->smc_gt(b, a, _picco_tmp1, 32, 9, 32, 9, 1, "float", -1);
  __s->smc_set(_picco_tmp1, z, 1, 32, "int", -1);

  __s->smc_gt(b, b1, _picco_tmp1, 32, 9, 32, 9, 1, "float", -1);
  __s->smc_set(_picco_tmp1, z1, 1, 32, "int", -1);

  __s->smc_gt(a, b, _picco_tmp1, 32, 9, 32, 9, 1, "float", -1);
  __s->smc_set(_picco_tmp1, z2, 1, 32, "int", -1);

  printf("::a :: %f :: 1.5\n", __s->smc_open(a, -1), -1);

  printf("::b :: %f :: 0.125\n", __s->smc_open(b, -1), -1);

  printf("::b1 :: %f :: 0.125\n", __s->smc_open(b1, -1), -1);

  printf("::x :: %d :: 1\n", __s->smc_open(x, -1), -1);

  printf("::x1 :: %d :: 0\n", __s->smc_open(x1, -1), -1);

  printf("::x2 :: %d :: 0\n", __s->smc_open(x2, -1), -1);

  printf("::y :: %d :: 1\n", __s->smc_open(y, -1), -1);

  printf("::y1 :: %d :: 0\n", __s->smc_open(y1, -1), -1);

  printf("::y2 :: %d :: 0\n", __s->smc_open(y2, -1), -1);

  printf("::z :: %d :: 0\n", __s->smc_open(z, -1), -1);

  printf("::z1 :: %d :: 0\n", __s->smc_open(z1, -1), -1);

  printf("::z2 :: %d :: 1\n", __s->smc_open(z2, -1), -1);
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

__s = new SMC_Utils(atoi(argv[1]), argv[2], argv[3], atoi(argv[4]), atoi(argv[5]), IO_files, 3, 1, 82, "2417851639229258349412499", 1);

struct timeval tv1;
struct timeval tv2;  int _xval = 0;

  gettimeofday(&tv1,NULL);
  _xval = (int) __original_main(argc, argv);
  gettimeofday(&tv2, NULL);
  std::cout << "Time: " << __s->time_diff(&tv1,&tv2) << std::endl;
  return (_xval);
}

