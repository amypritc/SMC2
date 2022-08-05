/* File generated from [VarSizeTests/programs/test/binops.c] by PICCO Mon Jun 27 13:55:03 2022
 */

#include <limits.h>

#include <float.h>

//extern void *memcpy(void*,const void*,unsigned int);

//# 1 "ort.onoff.defs"

extern  "C" int   ort_initialize(int*, char***);
 extern "C" void  ort_finalize(int);


/* File generated from [VarSizeTests/programs/test/binops.c] by PICCO Mon Jun 27 13:55:03 2022
 */

#include "smc-compute/SMC_Utils.h"

#include "smc-compute/LocationTracking.h"

#include <gmp.h>

#include <omp.h>


SMC_Utils *__s;



int  __original_main(int _argc_ignored/* bit_size(_argc_ignored) = 0 */, char **_argv_ignored/* bit_size(_argv_ignored) = 0 */)
{
  
  mpz_t _picco_tmp1;
  mpz_init(_picco_tmp1);

  mpz_t* _picco_ftmp1 = (mpz_t*)malloc(sizeof(mpz_t) * 4);
  for(int _picco_j = 0; _picco_j < 4; _picco_j++)
    mpz_init(_picco_ftmp1[_picco_j]);
  void* _picco_temp_;
 // entered ast_decl_stmt_show, 0
mpz_t a;
  mpz_init(a);
 /*size(a) = 0*/
  /*size(a) = 0*/
   __s->smc_set(1, a, -1, 2, "int", -1);

  // entered ast_decl_stmt_show, 0
mpz_t b;
  mpz_init(b);
 /*size(b) = 0*/
  /*size(b) = 0*/
   __s->smc_set(2, b, -1, 3, "int", -1);

  // entered ast_decl_stmt_show, 0
mpz_t c;
  mpz_init(c);
 /*size(c) = 0*/
  /*size(c) = 0*/
 
  // entered ast_decl_stmt_show, 0
mpz_t d;
  mpz_init(d);
 /*size(d) = 0*/
  /*size(d) = 0*/
 
  __s->smc_add(a, b, _picco_tmp1, 2, 3, 3, "int", -1);
  __s->smc_set(_picco_tmp1, c, 3, 32, "int", -1);

  __s->smc_mult(a, b, _picco_tmp1, 2, 3, 3, "int", -1);
  __s->smc_set(_picco_tmp1, c, 3, 32, "int", -1);

  __s->smc_sub(b, a, _picco_tmp1, 3, 2, 3, "int", -1);
  __s->smc_set(_picco_tmp1, c, 3, 32, "int", -1);

  __s->smc_div(b, a, _picco_tmp1, 3, 2, 3, "int", -1);
  __s->smc_set(_picco_tmp1, c, 3, 32, "int", -1);

  __s->smc_eqeq(b, a, _picco_tmp1, 3, 2, 1, "int", -1);
  __s->smc_set(_picco_tmp1, d, 1, 32, "int", -1);

  __s->smc_lt(b, a, _picco_tmp1, 3, 2, 1, "int", -1);
  __s->smc_set(_picco_tmp1, d, 1, 32, "int", -1);

  __s->smc_neq(b, a, _picco_tmp1, 3, 2, 1, "int", -1);
  __s->smc_set(_picco_tmp1, d, 1, 32, "int", -1);

  printf("c:%d\n", __s->smc_open(c, -1), -1);

  printf("done\n");
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

__s = new SMC_Utils(atoi(argv[1]), argv[2], argv[3], atoi(argv[4]), atoi(argv[5]), IO_files, 3, 1, 63, "4611686018427388039", 1);

struct timeval tv1;
struct timeval tv2;  int _xval = 0;

  gettimeofday(&tv1,NULL);
  _xval = (int) __original_main(argc, argv);
  gettimeofday(&tv2, NULL);
  std::cout << "Time: " << __s->time_diff(&tv1,&tv2) << std::endl;
  return (_xval);
}

