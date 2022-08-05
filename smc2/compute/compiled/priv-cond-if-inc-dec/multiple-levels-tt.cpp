/* File generated from [sample-programs/priv-cond-if-inc-dec/multiple-levels-tt.c] by PICCO Mon Feb 22 20:48:18 2021
 */

#include <limits.h>

#include <float.h>

//extern void *memcpy(void*,const void*,unsigned int);

//# 1 "ort.onoff.defs"

extern  "C" int   ort_initialize(int*, char***);
 extern "C" void  ort_finalize(int);


/* File generated from [sample-programs/priv-cond-if-inc-dec/multiple-levels-tt.c] by PICCO Mon Feb 22 20:48:18 2021
 */

#include "smc-compute/SMC_Utils.h"

#include <gmp.h>

#include <omp.h>


SMC_Utils *__s;



int  __original_main(int _argc_ignored, char **_argv_ignored)
{
  
  mpz_t _picco_tmp1, _picco_tmp2, _picco_tmp3, _picco_tmp4;
  mpz_init(_picco_tmp1);
  mpz_init(_picco_tmp2);
  mpz_init(_picco_tmp3);
  mpz_init(_picco_tmp4);

  mpz_t* _picco_ftmp1 = (mpz_t*)malloc(sizeof(mpz_t) * 4);
  for(int _picco_j = 0; _picco_j < 4; _picco_j++)
    mpz_init(_picco_ftmp1[_picco_j]);
  void* _picco_temp_;
 mpz_t a;
  mpz_init(a);
  __s->smc_set(3, a, -1, 32, "int", -1);
  mpz_t b;
  mpz_init(b);
  __s->smc_set(7, b, -1, 32, "int", -1);
  mpz_t c;
  mpz_init(c);
  __s->smc_set(5, c, -1, 32, "int", -1);
  mpz_t d;
  mpz_init(d);
  __s->smc_set(9, d, -1, 32, "int", -1);
  mpz_t e;
  mpz_init(e);
  __s->smc_set(13, e, -1, 32, "int", -1);
  mpz_t f;
  mpz_init(f);
  __s->smc_set(17, f, -1, 32, "int", -1);
  mpz_t g;
  mpz_init(g);
  __s->smc_set(0, g, -1, 32, "int", -1);

  __s->smc_lt(a, b, _picco_tmp1, 32, 32, 1, "int", -1);
    {
mpz_t _picco_condtmp1;
mpz_init(_picco_condtmp1);
__s->smc_sub(1, _picco_tmp1, _picco_condtmp1, 1, 1, 1, "int", -1);
mpz_t _picco_priv_int_d_1_then;
mpz_init(_picco_priv_int_d_1_then);
mpz_t _picco_priv_int_d_1_else;
mpz_init(_picco_priv_int_d_1_else);
__s->smc_set(d, _picco_priv_int_d_1_else, 32, 32, "int", -1);

mpz_t _picco_priv_int_e_1_then;
mpz_init(_picco_priv_int_e_1_then);
mpz_t _picco_priv_int_e_1_else;
mpz_init(_picco_priv_int_e_1_else);
__s->smc_set(e, _picco_priv_int_e_1_else, 32, 32, "int", -1);

mpz_t _picco_priv_int_f_1_then;
mpz_init(_picco_priv_int_f_1_then);
mpz_t _picco_priv_int_f_1_else;
mpz_init(_picco_priv_int_f_1_else);
__s->smc_set(f, _picco_priv_int_f_1_else, 32, 32, "int", -1);

mpz_t _picco_priv_int_c_1_then;
mpz_init(_picco_priv_int_c_1_then);
mpz_t _picco_priv_int_c_1_else;
mpz_init(_picco_priv_int_c_1_else);
__s->smc_set(c, _picco_priv_int_c_1_else, 32, 32, "int", -1);

mpz_t _picco_priv_int_g_1_then;
mpz_init(_picco_priv_int_g_1_then);
mpz_t _picco_priv_int_g_1_else;
mpz_init(_picco_priv_int_g_1_else);
__s->smc_set(g, _picco_priv_int_g_1_else, 32, 32, "int", -1);

{
      {
                        __s->smc_set(c++, g, 32, 32, "int", -1);

        __s->smc_gt(f, e, _picco_tmp2, 32, 32, 1, "int", -1);
          {
mpz_t _picco_condtmp2;
mpz_init(_picco_condtmp2);
__s->smc_sub(1, _picco_tmp2, _picco_condtmp2, 1, 1, 1, "int", -1);
mpz_t _picco_priv_int_d_2_then;
mpz_init(_picco_priv_int_d_2_then);
mpz_t _picco_priv_int_d_2_else;
mpz_init(_picco_priv_int_d_2_else);
__s->smc_set(d, _picco_priv_int_d_2_else, 32, 32, "int", -1);

mpz_t _picco_priv_int_e_2_then;
mpz_init(_picco_priv_int_e_2_then);
mpz_t _picco_priv_int_e_2_else;
mpz_init(_picco_priv_int_e_2_else);
__s->smc_set(e, _picco_priv_int_e_2_else, 32, 32, "int", -1);

mpz_t _picco_priv_int_f_2_then;
mpz_init(_picco_priv_int_f_2_then);
mpz_t _picco_priv_int_f_2_else;
mpz_init(_picco_priv_int_f_2_else);
__s->smc_set(f, _picco_priv_int_f_2_else, 32, 32, "int", -1);

mpz_t _picco_priv_int_g_2_then;
mpz_init(_picco_priv_int_g_2_then);
mpz_t _picco_priv_int_g_2_else;
mpz_init(_picco_priv_int_g_2_else);
__s->smc_set(g, _picco_priv_int_g_2_else, 32, 32, "int", -1);

{
            {
                                          __s->smc_set(++f, g, 32, 32, "int", -1);
            }
          }
__s->smc_set(d, _picco_priv_int_d_2_then, 32, 32, "int", -1);
__s->smc_set(_picco_priv_int_d_2_else, d, 32, 32, "int", -1);

__s->smc_set(e, _picco_priv_int_e_2_then, 32, 32, "int", -1);
__s->smc_set(_picco_priv_int_e_2_else, e, 32, 32, "int", -1);

__s->smc_set(f, _picco_priv_int_f_2_then, 32, 32, "int", -1);
__s->smc_set(_picco_priv_int_f_2_else, f, 32, 32, "int", -1);

__s->smc_set(g, _picco_priv_int_g_2_then, 32, 32, "int", -1);
__s->smc_set(_picco_priv_int_g_2_else, g, 32, 32, "int", -1);

          {
            {
                            mpz_sub_ui(e, e, 1);

              __s->smc_gt(f, d, _picco_tmp3, 32, 32, 1, "int", -1);
                {
mpz_t _picco_condtmp3;
mpz_init(_picco_condtmp3);
__s->smc_sub(1, _picco_tmp3, _picco_condtmp3, 1, 1, 1, "int", -1);
mpz_t _picco_priv_int_d_3_then;
mpz_init(_picco_priv_int_d_3_then);
mpz_t _picco_priv_int_d_3_else;
mpz_init(_picco_priv_int_d_3_else);
__s->smc_set(d, _picco_priv_int_d_3_else, 32, 32, "int", -1);

mpz_t _picco_priv_int_g_3_then;
mpz_init(_picco_priv_int_g_3_then);
mpz_t _picco_priv_int_g_3_else;
mpz_init(_picco_priv_int_g_3_else);
__s->smc_set(g, _picco_priv_int_g_3_else, 32, 32, "int", -1);

{
                  {
                                                            __s->smc_set(d--, g, 32, 32, "int", -1);
                  }
                }
__s->smc_set(d, _picco_priv_int_d_3_then, 32, 32, "int", -1);
__s->smc_set(_picco_priv_int_d_3_else, d, 32, 32, "int", -1);

__s->smc_set(g, _picco_priv_int_g_3_then, 32, 32, "int", -1);
__s->smc_set(_picco_priv_int_g_3_else, g, 32, 32, "int", -1);

__s->smc_priv_eval(d, _picco_priv_int_d_3_then, _picco_condtmp3, -1);
__s->smc_priv_eval(g, _picco_priv_int_g_3_then, _picco_condtmp3, -1);
mpz_clear(_picco_condtmp3);
mpz_clear(_picco_priv_int_d_3_then);
mpz_clear(_picco_priv_int_d_3_else);
mpz_clear(_picco_priv_int_g_3_then);
mpz_clear(_picco_priv_int_g_3_else);
}
            }
          }
__s->smc_priv_eval(d, _picco_priv_int_d_2_then, _picco_condtmp2, -1);
__s->smc_priv_eval(e, _picco_priv_int_e_2_then, _picco_condtmp2, -1);
__s->smc_priv_eval(f, _picco_priv_int_f_2_then, _picco_condtmp2, -1);
__s->smc_priv_eval(g, _picco_priv_int_g_2_then, _picco_condtmp2, -1);
mpz_clear(_picco_condtmp2);
mpz_clear(_picco_priv_int_d_2_then);
mpz_clear(_picco_priv_int_d_2_else);
mpz_clear(_picco_priv_int_e_2_then);
mpz_clear(_picco_priv_int_e_2_else);
mpz_clear(_picco_priv_int_f_2_then);
mpz_clear(_picco_priv_int_f_2_else);
mpz_clear(_picco_priv_int_g_2_then);
mpz_clear(_picco_priv_int_g_2_else);
}
      }
    }
__s->smc_set(d, _picco_priv_int_d_1_then, 32, 32, "int", -1);
__s->smc_set(_picco_priv_int_d_1_else, d, 32, 32, "int", -1);

__s->smc_set(e, _picco_priv_int_e_1_then, 32, 32, "int", -1);
__s->smc_set(_picco_priv_int_e_1_else, e, 32, 32, "int", -1);

__s->smc_set(f, _picco_priv_int_f_1_then, 32, 32, "int", -1);
__s->smc_set(_picco_priv_int_f_1_else, f, 32, 32, "int", -1);

__s->smc_set(c, _picco_priv_int_c_1_then, 32, 32, "int", -1);
__s->smc_set(_picco_priv_int_c_1_else, c, 32, 32, "int", -1);

__s->smc_set(g, _picco_priv_int_g_1_then, 32, 32, "int", -1);
__s->smc_set(_picco_priv_int_g_1_else, g, 32, 32, "int", -1);

    {
      {
                        __s->smc_set(++c, g, 32, 32, "int", -1);

        __s->smc_lt(b, d, _picco_tmp2, 32, 32, 1, "int", -1);
          {
mpz_t _picco_condtmp2;
mpz_init(_picco_condtmp2);
__s->smc_sub(1, _picco_tmp2, _picco_condtmp2, 1, 1, 1, "int", -1);
mpz_t _picco_priv_int_d_2_then;
mpz_init(_picco_priv_int_d_2_then);
mpz_t _picco_priv_int_d_2_else;
mpz_init(_picco_priv_int_d_2_else);
__s->smc_set(d, _picco_priv_int_d_2_else, 32, 32, "int", -1);

mpz_t _picco_priv_int_g_2_then;
mpz_init(_picco_priv_int_g_2_then);
mpz_t _picco_priv_int_g_2_else;
mpz_init(_picco_priv_int_g_2_else);
__s->smc_set(g, _picco_priv_int_g_2_else, 32, 32, "int", -1);

{
            {
                            __s->smc_add(mpz_sub_ui(d, d, 1), 2, _picco_tmp3, 32, -1, 32, "int", -1);
              __s->smc_set(_picco_tmp3, g, 32, 32, "int", -1);
            }
          }
__s->smc_set(d, _picco_priv_int_d_2_then, 32, 32, "int", -1);
__s->smc_set(_picco_priv_int_d_2_else, d, 32, 32, "int", -1);

__s->smc_set(g, _picco_priv_int_g_2_then, 32, 32, "int", -1);
__s->smc_set(_picco_priv_int_g_2_else, g, 32, 32, "int", -1);

          {
            {
                            mpz_add_ui(d, d, 1);
            }
          }
__s->smc_priv_eval(d, _picco_priv_int_d_2_then, _picco_condtmp2, -1);
__s->smc_priv_eval(g, _picco_priv_int_g_2_then, _picco_condtmp2, -1);
mpz_clear(_picco_condtmp2);
mpz_clear(_picco_priv_int_d_2_then);
mpz_clear(_picco_priv_int_d_2_else);
mpz_clear(_picco_priv_int_g_2_then);
mpz_clear(_picco_priv_int_g_2_else);
}
      }
    }
__s->smc_priv_eval(d, _picco_priv_int_d_1_then, _picco_condtmp1, -1);
__s->smc_priv_eval(e, _picco_priv_int_e_1_then, _picco_condtmp1, -1);
__s->smc_priv_eval(f, _picco_priv_int_f_1_then, _picco_condtmp1, -1);
__s->smc_priv_eval(c, _picco_priv_int_c_1_then, _picco_condtmp1, -1);
__s->smc_priv_eval(g, _picco_priv_int_g_1_then, _picco_condtmp1, -1);
mpz_clear(_picco_condtmp1);
mpz_clear(_picco_priv_int_d_1_then);
mpz_clear(_picco_priv_int_d_1_else);
mpz_clear(_picco_priv_int_e_1_then);
mpz_clear(_picco_priv_int_e_1_else);
mpz_clear(_picco_priv_int_f_1_then);
mpz_clear(_picco_priv_int_f_1_else);
mpz_clear(_picco_priv_int_c_1_then);
mpz_clear(_picco_priv_int_c_1_else);
mpz_clear(_picco_priv_int_g_1_then);
mpz_clear(_picco_priv_int_g_1_else);
}

  printf("::a :: %d :: 3\n", __s->smc_open(a, -1), -1);

  printf("::b :: %d :: 7\n", __s->smc_open(b, -1), -1);

  printf("::c :: %d :: 6\n", __s->smc_open(c, -1), -1);

  printf("::d :: %d :: 9\n", __s->smc_open(d, -1), -1);

  printf("::e :: %d :: 13\n", __s->smc_open(e, -1), -1);

  printf("::f :: %d :: 18\n", __s->smc_open(f, -1), -1);

  printf("::g :: %d :: 18\n", __s->smc_open(g, -1), -1);
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

