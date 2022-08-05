/* File generated from [sample-programs/basic-ptr/gt.c] by PICCO Mon Feb  8 17:41:05 2021
 */

#include <limits.h>

#include <float.h>

//extern void *memcpy(void*,const void*,unsigned int);

//# 1 "ort.onoff.defs"

extern  "C" int   ort_initialize(int*, char***);
 extern "C" void  ort_finalize(int);


/* File generated from [sample-programs/basic-ptr/gt.c] by PICCO Mon Feb  8 17:41:05 2021
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
   mpz_t _picco_priv_tmp1, _picco_priv_tmp2;
  mpz_init(_picco_priv_tmp1);
  mpz_init(_picco_priv_tmp2);
  priv_ptr _picco_tmp_int_ptr1 = __s->smc_new_ptr(1, 0);
  priv_ptr _picco_tmp_int_ptr2 = __s->smc_new_ptr(1, 0);
mpz_t a;
  mpz_init(a);
  __s->smc_set(2, a, -1, 32, "int", -1);
  mpz_t b;
  mpz_init(b);
  __s->smc_set(7, b, -1, 32, "int", -1);
  mpz_t b1;
  mpz_init(b1);
  __s->smc_set(7, b1, -1, 32, "int", -1);
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

  mpz_t v;
  mpz_init(v);
  __s->smc_set(0, v, -1, 32, "int", -1);
  mpz_t v1;
  mpz_init(v1);
  __s->smc_set(0, v1, -1, 32, "int", -1);
  mpz_t v2;
  mpz_init(v2);
  __s->smc_set(0, v2, -1, 32, "int", -1);
  mpz_t w;
  mpz_init(w);
  __s->smc_set(0, w, -1, 32, "int", -1);
  mpz_t w1;
  mpz_init(w1);
  __s->smc_set(0, w1, -1, 32, "int", -1);
  mpz_t w2;
  mpz_init(w2);
  __s->smc_set(0, w2, -1, 32, "int", -1);

  priv_ptr pa = __s->smc_new_ptr(1, 0);
  __s->smc_set_int_ptr(pa, &a, "int", -1);
  priv_ptr pb = __s->smc_new_ptr(1, 0);
  __s->smc_set_int_ptr(pb, &b, "int", -1);
  priv_ptr pb1 = __s->smc_new_ptr(1, 0);
  __s->smc_set_int_ptr(pb1, &b1, "int", -1);

    __s->smc_dereference_read_ptr(pa, _picco_priv_tmp1, 1, NULL, "int", -1);
__s->smc_gt(_picco_priv_tmp1, 0, _picco_tmp1, 32, -1, 1, "int", -1);
  __s->smc_set(_picco_tmp1, x, 1, 32, "int", -1);

    __s->smc_dereference_read_ptr(pa, _picco_priv_tmp1, 1, NULL, "int", -1);
__s->smc_gt(_picco_priv_tmp1, 2, _picco_tmp1, 32, -1, 1, "int", -1);
  __s->smc_set(_picco_tmp1, x1, 1, 32, "int", -1);

    __s->smc_dereference_read_ptr(pa, _picco_priv_tmp1, 1, NULL, "int", -1);
__s->smc_gt(_picco_priv_tmp1, 5, _picco_tmp1, 32, -1, 1, "int", -1);
  __s->smc_set(_picco_tmp1, x2, 1, 32, "int", -1);

    __s->smc_dereference_read_ptr(pb, _picco_priv_tmp2, 1, NULL, "int", -1);
__s->smc_gt(9, _picco_priv_tmp2, _picco_tmp1, -1, 32, 1, "int", -1);
  __s->smc_set(_picco_tmp1, y, 1, 32, "int", -1);

    __s->smc_dereference_read_ptr(pb, _picco_priv_tmp2, 1, NULL, "int", -1);
__s->smc_gt(7, _picco_priv_tmp2, _picco_tmp1, -1, 32, 1, "int", -1);
  __s->smc_set(_picco_tmp1, y1, 1, 32, "int", -1);

    __s->smc_dereference_read_ptr(pb, _picco_priv_tmp2, 1, NULL, "int", -1);
__s->smc_gt(1, _picco_priv_tmp2, _picco_tmp1, -1, 32, 1, "int", -1);
  __s->smc_set(_picco_tmp1, y2, 1, 32, "int", -1);

    __s->smc_dereference_read_ptr(pb, _picco_priv_tmp1, 1, NULL, "int", -1);
__s->smc_gt(_picco_priv_tmp1, a, _picco_tmp1, 32, 32, 1, "int", -1);
  __s->smc_set(_picco_tmp1, v, 1, 32, "int", -1);

    __s->smc_dereference_read_ptr(pb, _picco_priv_tmp1, 1, NULL, "int", -1);
__s->smc_gt(_picco_priv_tmp1, b1, _picco_tmp1, 32, 32, 1, "int", -1);
  __s->smc_set(_picco_tmp1, v1, 1, 32, "int", -1);

    __s->smc_dereference_read_ptr(pa, _picco_priv_tmp1, 1, NULL, "int", -1);
__s->smc_gt(_picco_priv_tmp1, b, _picco_tmp1, 32, 32, 1, "int", -1);
  __s->smc_set(_picco_tmp1, v2, 1, 32, "int", -1);

    __s->smc_dereference_read_ptr(pa, _picco_priv_tmp2, 1, NULL, "int", -1);
__s->smc_gt(b, _picco_priv_tmp2, _picco_tmp1, 32, 32, 1, "int", -1);
  __s->smc_set(_picco_tmp1, w, 1, 32, "int", -1);

    __s->smc_dereference_read_ptr(pb1, _picco_priv_tmp2, 1, NULL, "int", -1);
__s->smc_gt(b, _picco_priv_tmp2, _picco_tmp1, 32, 32, 1, "int", -1);
  __s->smc_set(_picco_tmp1, w1, 1, 32, "int", -1);

    __s->smc_dereference_read_ptr(pb, _picco_priv_tmp2, 1, NULL, "int", -1);
__s->smc_gt(a, _picco_priv_tmp2, _picco_tmp1, 32, 32, 1, "int", -1);
  __s->smc_set(_picco_tmp1, w2, 1, 32, "int", -1);

    __s->smc_dereference_read_ptr(pb, _picco_priv_tmp1, 1, NULL, "int", -1);
  __s->smc_dereference_read_ptr(pa, _picco_priv_tmp2, 1, NULL, "int", -1);
__s->smc_gt(_picco_priv_tmp1, _picco_priv_tmp2, _picco_tmp1, 32, 32, 1, "int", -1);
  __s->smc_set(_picco_tmp1, z, 1, 32, "int", -1);

    __s->smc_dereference_read_ptr(pb, _picco_priv_tmp1, 1, NULL, "int", -1);
  __s->smc_dereference_read_ptr(pb1, _picco_priv_tmp2, 1, NULL, "int", -1);
__s->smc_gt(_picco_priv_tmp1, _picco_priv_tmp2, _picco_tmp1, 32, 32, 1, "int", -1);
  __s->smc_set(_picco_tmp1, z1, 1, 32, "int", -1);

    __s->smc_dereference_read_ptr(pa, _picco_priv_tmp1, 1, NULL, "int", -1);
  __s->smc_dereference_read_ptr(pb, _picco_priv_tmp2, 1, NULL, "int", -1);
__s->smc_gt(_picco_priv_tmp1, _picco_priv_tmp2, _picco_tmp1, 32, 32, 1, "int", -1);
  __s->smc_set(_picco_tmp1, z2, 1, 32, "int", -1);

  printf("::a :: %d :: 2\n", __s->smc_open(a, -1), -1);

  printf("::b :: %d :: 7\n", __s->smc_open(b, -1), -1);

  printf("::b1 :: %d :: 7\n", __s->smc_open(b1, -1), -1);

  printf("::v :: %d :: 1\n", __s->smc_open(v, -1), -1);

  printf("::v1 :: %d :: 0\n", __s->smc_open(v1, -1), -1);

  printf("::v2 :: %d :: 0\n", __s->smc_open(v2, -1), -1);

  printf("::w :: %d :: 1\n", __s->smc_open(w, -1), -1);

  printf("::w1 :: %d :: 0\n", __s->smc_open(w1, -1), -1);

  printf("::w2 :: %d :: 0\n", __s->smc_open(w2, -1), -1);

  printf("::x :: %d :: 1\n", __s->smc_open(x, -1), -1);

  printf("::x1 :: %d :: 0\n", __s->smc_open(x1, -1), -1);

  printf("::x2 :: %d :: 0\n", __s->smc_open(x2, -1), -1);

  printf("::y :: %d :: 1\n", __s->smc_open(y, -1), -1);

  printf("::y1 :: %d :: 0\n", __s->smc_open(y1, -1), -1);

  printf("::y2 :: %d :: 0\n", __s->smc_open(y2, -1), -1);

  printf("::z :: %d :: 1\n", __s->smc_open(z, -1), -1);

  printf("::z1 :: %d :: 0\n", __s->smc_open(z1, -1), -1);

  printf("::z2 :: %d :: 0\n", __s->smc_open(z2, -1), -1);
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

