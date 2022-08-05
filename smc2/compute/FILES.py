

BASIC_OPS = ["add", "div", "mul", "sub", "eqeq", "neq", "gt", "gteq", "lt", "lteq", 
             "postdec", "postinc", "predec", "preinc"]
BASIC_OPS_DIRS = ["basic-ops", "basic-ops-flt"]

BASIC_OPS_PTR = ["add", "div", "mul", "sub", "eqeq", "neq", "gt", "gteq", "lt", "lteq", "deref-assign"]
PTR_EQ = ["ptr-eq", "ptr-neq"]
BASIC_OPS_PTR_DIRS = ["basic-ptr", "basic-ptr-flt"]

IF_VAR = ["if-f", "if-t", "if-nest-ff", "if-nest-ft", "if-nest-tf", "if-nest-tt",
          "if-else-f", "if-else-t", "if-else-nest-ff", "if-else-nest-ft", "if-else-nest-tf", "if-else-nest-tt"]
IF_VAR_DIRS = ["priv-cond-if-neq", "priv-cond-if-var"]
IF_VAR_DIRS_FLT = ["priv-cond-if-neq-flt", "priv-cond-if-var-flt"]

INC_DEC = ["preinc-t", "preinc-tt", "preinc-tf", "preinc-f", "preinc-ff", "preinc-ft",
           "postinc-t", "postinc-tt", "postinc-tf", "postinc-f", "postinc-ff", "postinc-ft",
           "predec-t", "predec-tt", "predec-tf", "predec-f", "predec-ff", "predec-ft",
           "postdec-t", "postdec-tt", "postdec-tf", "postdec-f", "postdec-ff", "postdec-ft"]
INC_DEC_DIR = ["priv-cond-if-inc-dec"]
INC_DEC_VAR = ["multiple-levels-ff", "multiple-levels-ft", "multiple-levels-tt", "multiple-levels-tff", "multiple-levels-tft",
           "preinc-t", "preinc-tt", "preinc-tf", "preinc-f", "preinc-ff", "preinc-ft",
           "postinc-t", "postinc-tt", "postinc-tf", "postinc-f", "postinc-ff", "postinc-ft",
           "predec-t", "predec-tt", "predec-tf", "predec-f", "predec-ff", "predec-ft",
           "postdec-t", "postdec-tt", "postdec-tf", "postdec-f", "postdec-ff", "postdec-ft"]
INC_DEC_DIR_VAR = ["priv-cond-if-inc-dec-var"]

IF_COND_OPS = ["eqeq-t", "eqeq-f", "neq-t", "neq-f", "gt-t", "gt-f",
               "gteq-t", "gteq-f", "lt-t", "lt-f", "lteq-t", "lteq-f"]
IF_COND_OPS_DIRS = ["priv-cond-if-ops", "priv-cond-if-ops-flt"]



NON_THREAD = ["hmm"]
NON_THREAD_1 = ["array-operations", "batch-div", "matrix-multiply"]
NON_THREAD_DIR = ["non-thread"]



TEST = ["private-branching-reuse"]
TEST1 = ["private-branching", "private-branching-mult", "private-branching-add", 
         "private-branching-reuse"]
TEST_DIR = ["test"]

BENCHMARK = ["pay-gap", "h_analysis", "LR-parser"]
BENCHMARK_DIR = ["benchmarks"]


