/* File generated from [sample-programs/test/test4.c] by PICCO Wed Jul 20 11:14:04 2022
 */

#include <limits.h>

#include <float.h>

//extern void *memcpy(void*,const void*,unsigned int);

//# 1 "ort.onoff.defs"

extern  "C" int   ort_initialize(int*, char***);
 extern "C" void  ort_finalize(int);


/* File generated from [sample-programs/test/test4.c] by PICCO Wed Jul 20 11:14:04 2022
 */

#include "smc-compute/SMC_Utils.h"

#include "smc-compute/LocationTracking.h"

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
 mpz_t a;
  mpz_init(a);
 /* size(a) = 24, 24*/
   __s->smc_set(1780, a, -1, 24, "int", -1);
  mpz_t b;
  mpz_init(b);
 /* size(b) = 24, 24*/
   __s->smc_set(3456, b, -1, 24, "int", -1);
  mpz_t c;
  mpz_init(c);
 /* size(c) = 24, 24*/
   __s->smc_set(2345, c, -1, 24, "int", -1);

  mpz_t x;
  mpz_init(x);
 /* size(x) = 32, 0*/
   mpz_t z;
  mpz_init(z);
 /* size(z) = 32, 0*/
 
  int i;

  i = 0;
  for ( ;i < 1000; )
  {
    {
      __s->smc_add(a, b, _picco_tmp1, 24, 24, 24, "int", -1);
      __s->smc_shr(_picco_tmp1, 1, _picco_tmp1, 24, -1, 24, "int", -1);
      __s->smc_set(_picco_tmp1, x, 24, 32, "int", -1);

      __s->smc_gt(x, c, _picco_tmp1, 32, 24, 1, "int", -1);
      __s->smc_set(_picco_tmp1, z, 1, 32, "int", -1);
    }
    i = i + 1;
  }

    mpz_clear(z);
  mpz_clear(x);
  mpz_clear(c);
  mpz_clear(b);
  mpz_clear(a);
  mpz_clear(_picco_tmp1);
  mpz_clear(_picco_tmp2);
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

__s = new SMC_Utils(atoi(argv[1]), argv[2], argv[3], atoi(argv[4]), atoi(argv[5]), IO_files, 3, 1, 81, "1208925819614629174706411", 1);

struct timeval tv1;
struct timeval tv2;  int _xval = 0;

  gettimeofday(&tv1,NULL);
  _xval = (int) __original_main(argc, argv);
  gettimeofday(&tv2, NULL);
  std::cout << "Time: " << __s->time_diff(&tv1,&tv2) << std::endl;
  return (_xval);
}

