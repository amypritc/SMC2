/* File generated from [sample-programs/priv-cond-if-var/if-else-t.c] by PICCO Mon Feb  8 17:41:21 2021
 */

#include <limits.h>

#include <float.h>

//extern void *memcpy(void*,const void*,unsigned int);

//# 1 "ort.onoff.defs"

extern  "C" int   ort_initialize(int*, char***);
 extern "C" void  ort_finalize(int);


/* File generated from [sample-programs/priv-cond-if-var/if-else-t.c] by PICCO Mon Feb  8 17:41:21 2021
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

  void* _picco_temp_;
 mpz_t a;
  mpz_init(a);
  __s->smc_set(3, a, -1, 32, "int", -1);
  mpz_t b;
  mpz_init(b);

      {
mpz_t _picco_condtmp1;
mpz_init(_picco_condtmp1);
__s->smc_neq(a, 0, _picco_condtmp1, 32, -1, 1, "int", -1);
__s->smc_sub(1, _picco_condtmp1, _picco_condtmp1, 1, 1, 1, "int", -1);
mpz_t _picco_priv_int_b_1_then;
mpz_init(_picco_priv_int_b_1_then);
mpz_t _picco_priv_int_b_1_else;
mpz_init(_picco_priv_int_b_1_else);
__s->smc_set(b, _picco_priv_int_b_1_else, 32, 32, "int", -1);

{
      {
                __s->smc_update_ptr(b, (null), _picco_condtmp1, 1, -1);
