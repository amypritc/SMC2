/* File generated from [sample-programs/test/test.c] by PICCO Mon Jul 18 15:12:22 2022
 */

#include <limits.h>

#include <float.h>

//extern void *memcpy(void*,const void*,unsigned int);

//# 1 "ort.onoff.defs"

extern  "C" int   ort_initialize(int*, char***);
 extern "C" void  ort_finalize(int);


/* File generated from [sample-programs/test/test.c] by PICCO Mon Jul 18 15:12:22 2022
 */

#include "smc-compute/SMC_Utils.h"

#include "smc-compute/LocationTracking.h"

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
 // entered ast_priv_decl_show: DLIST, 1 
// entered ast_priv_decl_show: DINIT
// entered ast_priv_decl_show: DECLARATOR
mpz_t a;
  mpz_init(a);
 /* size(a) = 3, 3*/
 // exit ast_priv_decl_show: DECLARATOR
   /* size set3: 3, 3 */
__s->smc_set(7, a, 3, 3, "int", -1);
// exit ast_priv_decl_show: DINIT
  // entered ast_priv_decl_show: DINIT
// entered ast_priv_decl_show: DECLARATOR
mpz_t c;
  mpz_init(c);
 /* size(c) = 3, 3*/
 // exit ast_priv_decl_show: DECLARATOR
   /* size set3: 3, 3 */
__s->smc_set(1, c, 1, 3, "int", -1);
// exit ast_priv_decl_show: DINIT
// exit ast_priv_decl_show: DLIST

  // entered ast_priv_decl_show: DECLARATOR
mpz_t d;
  mpz_init(d);
 /* size(d) = 16, 16*/
 // exit ast_priv_decl_show: DECLARATOR

  // entered ast_priv_decl_show: DECLARATOR
mpz_t b;
  mpz_init(b);
 /* size(b) = 32, 0*/
 // exit ast_priv_decl_show: DECLARATOR

  __s->smc_add(a, c, _picco_tmp1, 3, 3, 4, "int", -1);
 /*a7: 3, 3, 3 */
   __s->smc_set(_picco_tmp1, b, 4, 4, "int", -1) /*a4: 3, 32 */ ;

  __s->smc_mult(a, c, _picco_tmp1, 3, 3, 6, "int", -1);
 /*a7: 3, 3, 3 */
   __s->smc_set(_picco_tmp1, b, 6, 6, "int", -1) /*a4: 3, 32 */ ;

  __s->smc_sub(a, c, _picco_tmp1, 3, 3, 4, "int", -1);
 /*a7: 3, 3, 3 */
   __s->smc_set(_picco_tmp1, b, 4, 4, "int", -1) /*a4: 3, 32 */ ;

  __s->smc_div(a, c, _picco_tmp1, 3, 3, 3, "int", -1);
 /*a7: 3, 3, 3 */
   __s->smc_set(_picco_tmp1, b, 3, 3, "int", -1) /*a4: 3, 32 */ ;

  __s->smc_shl(b, 1, _picco_tmp1, 3, 1, 4, "int", -1);
 /*a7: 32, -1, 32 */
   __s->smc_set(_picco_tmp1, b, 4, 4, "int", -1) /*a4: 32, 32 */ ;

  __s->smc_shr(a, 1, _picco_tmp1, 3, 1, 2, "int", -1);
 /*a7: 3, -1, 3 */
   __s->smc_set(_picco_tmp1, a, 2, 2, "int", -1) /*a4: 3, 3 */ ;

  __s->smc_lt(a, c, _picco_tmp1, 2, 3, 1, "int", -1);
 /*a7: 3, 3, 1 */
   __s->smc_set(_picco_tmp1, b, 1, 1, "int", -1) /*a4: 1, 32 */ ;

  __s->smc_add(a, b, _picco_tmp1, 2, 1, 3, "int", -1);
 /*a7: 3, 32, 32 */
   __s->smc_set(_picco_tmp1, d, 3, 3, "int", -1) /*a4: 32, 16 */ ;

  __s->smc_gt(d, 1, _picco_tmp1, 3, 1, 1, "int", -1);
 /*a7: 16, -1, 1 */
   __s->smc_set(_picco_tmp1, d, 1, 1, "int", -1) /*a4: 1, 16 */ ;

    mpz_clear(b);
  mpz_clear(d);
  mpz_clear(c);
  mpz_clear(a);
  mpz_clear(_picco_tmp1);
  for(int _picco_j = 0; _picco_j < 4; _picco_j++)
    mpz_clear(_picco_ftmp1[_picco_j]);
  free(_picco_ftmp1);
  return (0);
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

__s = new SMC_Utils(atoi(argv[1]), argv[2], argv[3], atoi(argv[4]), atoi(argv[5]), IO_files, 3, 1, 65, "18446744073709551667", 1);

struct timeval tv1;
struct timeval tv2;  int _xval = 0;

  gettimeofday(&tv1,NULL);
  _xval = (int) __original_main(argc, argv);
  gettimeofday(&tv2, NULL);
  std::cout << "Time: " << __s->time_diff(&tv1,&tv2) << std::endl;
  return (_xval);
}

