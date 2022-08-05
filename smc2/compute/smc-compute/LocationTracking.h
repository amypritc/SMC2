#ifndef LOCATION_TRACKING_H_
#define LOCATION_TRACKING_H_

#include <cstdlib>
#include "Headers.h"
#include "SMC_Utils.h"


typedef struct delta_ *delta;
typedef struct Delta_ *Delta;

enum branch_id {B_THEN = 1, B_ELSE = 2, B_NONE = 0, B_INIT = 3, B_ERR = 4};

struct delta_ {
   int nest_level;   // level of nesting of current branch
   int isFlt;        // int = 0; float = 1
   int isPtr;        // is pointer = 1; is not pointer = 0
   int hasNext;      // there exists a next node
   union {
      mpz_t* int_location; // pointer to the int location that is being modified
      mpz_t** float_location; // pointer to the float location that is being modified
      priv_ptr ptr_location;
   } loc;
   int tag;          // tag for whether the then val has been set or not
   union {
      struct {       // int
         mpz_t origVal;
         mpz_t thenVal;
         //mpz_t elseVal;
      } i;
      struct {       // float
         mpz_t* origVal;
         mpz_t* thenVal;
         //mpz_t* elseVal;
      } flt;
      struct {       // pointer
         priv_ptr origVal;
         priv_ptr thenVal;
         //spriv_ptr elseVal;
      } ptr;
   } u;
   int updated_then;
   struct delta_ *prev;
   struct delta_ *next;
   struct delta_ *last;
};

/* Currently not using - instead just using an array of struct delta
      (size of array = max nesting level found at compile time) */
struct Delta_ {
   int nest_level;
   delta curr;    // first
   delta prev;
   delta next;
};


/* Using the Transactional Semantics to update various types of locations */
void add_int_location(delta, mpz_t*, mpz_t, int);
void check_int_pointer(delta, priv_ptr, int, int);
void check_int_pointer_ptr(delta, priv_ptr, int, int);

void add_float_location(delta, mpz_t**, mpz_t*, int, enum branch_id);
void add_int_pointer_location(delta, priv_ptr, priv_ptr, int, enum branch_id);
void add_float_pointer_location(delta, priv_ptr, priv_ptr, int, enum branch_id);

/* Restoring values after the THEN branch has been executed */
void location_based_restore(delta, int, SMC_Utils *__s);

/* Resolving true values after the execution of the ELSE branch */
void location_based_resolve(delta, int, mpz_t, SMC_Utils *__s, int threadID);



#endif
