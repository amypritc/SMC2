## This is a guide to the different types of sample programs contained in this directory 

### NOTE: All files in the main testing suite have corresponding Vanilla C files to check their behavior against. 
### If you make changes to any of these files, mirror the change in the corresponding Vanilla C file to avoid breaking the correctness check.

### Main testing suite 
* basic-ops
   * Files to test various basic SMC operations on their own 
   * lt, gt, eqeq, neq, add, mul, div, sub, etc. 
* basic-ops
   * Float versions of the files from directory basic-ops
* basic-ptr
   * Files to test various basic pointer operations on their own (not inside private-condioned if)
   * Pointer dereference - lt, gt, eqeq, neq, add, mul, div, sub, etc. 
   * Pointer - eqeq, neq (other comparisons not meaningful/important)
   * Pointer assignments (deref & regular), pmalloc, pfree
* basic-ptr-flt
   * Float pointer versions of the files from directory basic-ptr
* smc-funs
   * Files to test the functionality of smcinput, smcoutput, and smcopen functions
* pub-cond-if-else
   * Files to ensure if statements with public conditions are working properly
* priv-cond-if-neq
   * Files to test private conditioned if statements where the condition is (var != 0); int variables 
   * These are runnable on with Vanilla PICCO to allow correctness testing/comparison with the modified version of PICCO
* priv-cond-if-neq-flt
   * Files to test private conditioned if statements where the condition is (var != 0); float variables 
   * These are runnable on with Vanilla PICCO to allow correctness testing/comparison with the modified version of PICCO
* priv-cond-if-var
   * Files to test private conditioned if statements where the condition is a single (int) variable 
   * These correspond to the if statements in directory priv-cond-if-neq
* priv-cond-if-var-flt
   * Files to test private conditioned if statements where the condition is a single (float) variable 
   * These correspond to the if statements in directory priv-cond-if-neq-flt
* priv-cond-if-ops
   * Files to test private conditioned if statements with conditions using various operations
* priv-cond-if-ops-flt
   * Float variable version of directory priv-cond-if-ops
* priv-cond-if-deref-ptr
   * Files to test private conditioned if statements where the condition involves pointer dereferencing
* priv-cond-if-deref-ptr-flt
   * Float variable version of directory priv-cond-if-deref-ptr
* priv-cond-if-nest
   * General files to test private conditioned if statements with varying levels of nesting 
* priv-cond-if-nest-flt
   * Float variable version of directory priv-cond-if-nest

### Additional testing directories/files 
* input
   * input files corresponding to the programs requiring input data
* thread
   * Programs to test threaded operations
* non-thread
   * More complex and interesting programs to test out PICCO functionality
* simple 
   * A set of programs to use to test. 
   * basic-test.c and test-code.c include instructions on compiling, running, and obtaining the output for the given program using PICCO.
* transactional-test
   * A variety of additional programs to test out private-conditioned if statements
