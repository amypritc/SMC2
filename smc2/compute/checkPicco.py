import os
import sys
from FILES import *
# script to compile, run, and check over the output of each program to see if the expected results are correct
# can also create output files to check against (in PICCO output-style) using arg '-out'

_INPUT = "test-code"
_TIMEOUT = "60s"

'''
Create the set of program/file names for the makefile to use

@directory:  where to find the program
@programs:       the program name
'''
def makePrograms(directory, programs):
   f = open("programs.mk", 'w')
   f.write("PROGRAMS +=")
   for prog in programs: 
      f.write(" " + prog)
   f.close()
   os.system("make")
   for prog in programs: 
      if(os.path.exists(prog)):
         os.system("mv " + prog + " compiled/" + directory + "/" + prog)
      if(os.path.exists(prog + ".cpp")):
         os.system("mv "+ prog + ".cpp compiled/" + directory + "/" + prog + ".cpp")
      if(os.path.exists(prog + ".o")):
         os.system("mv "+ prog + ".o compiled/" + directory + "/" + prog + ".o")
  

'''
Add the programs to the makefile.
Compile each program with PICCO.
Get the input files for each program using PICCO-UTIL.

@directories:  where to find the programs
@programs:     program names
@inp:          input file name
@inpNum:       number of input parties
@outNum:       number of output parties
'''
def compilePICCO(directories, programs, inp, inpNum, outNum):
   for directory in directories:
      try:
         os.makedirs("compiled/" + directory)
      except OSError as e:
         pass
      try: 
         os.makedirs("inputShares/" + directory)
      except OSError as e:
         pass
      try:
         os.makedirs("output/" + directory)
      except OSError as e:
         pass
      try:
         os.makedirs("utility/" + directory)
      except OSError as e:
         pass
      for prog in programs: 
         if(inp):
            os.system("bash compilePicco.sh " + directory + " " + prog + " " + inp + " " + str(inpNum) + " " + str(outNum))
         else:
            os.system("bash compilePicco.sh " + directory + " " + prog + " " + prog + " " + str(inpNum) + " " + str(outNum))
      makePrograms(directory, programs)


'''
Run each program.
Get the output.

@directories:  where to find the programs
@programs:     program names
@inp:          input file name
@inpNum:       number of input parties
@outNum:       number of output parties
'''
def runPICCO(directories, programs, inp, inpNum, outNum):
   for directory in directories:
      for prog in programs: 
         if(os.path.exists("compiled/" + directory + "/" + prog)):
            print("\n running: " + directory + "/" + prog + ":\n")
            if(inp):
               os.system("bash runPicco.sh " + directory + " " + prog + " " + inp + " " + str(inpNum) + " " + str(outNum) + " " + _TIMEOUT)
            else:
               os.system("bash runPicco.sh " + directory + " " + prog + " " + prog + " " + str(inpNum) + " " + str(outNum) + " " + _TIMEOUT)
         else:
            print("\n" + directory + "/" + prog + ":\n executable not found\n")
         
   


'''
Check the output against the C output for each corresponding program.
If the C output files do not exist, run script to create them.

@directories:  where to find the programs
@programs:     program names
@inp:          input file name
@inpNum:       number of input parties
@outNum:       number of output parties
'''
def checkOutput(directories, programs, inp, inpNum, outNum):
   os.chdir("output")
   for directory in directories:
      os.chdir(directory)
      for prog in programs: 
         fileName = prog + "1.txt"
         print(directory + "/" + prog)
         PASS = True
         if(os.path.exists(fileName)):
            f = open(fileName, 'r')
            for line in f:
               if(line[0:2] == "::"):
                  res = line[2:].strip()
                  res1 = res.split(" :: ")
                  if(float(res1[1]) != float(res1[2])):
                     PASS = False
                     print("\texpected: " + res1[0] + "=" + res1[2] + "; actual: " + res1[0] + "=" + res1[1])
            f.close()
         else:
            PASS = False
            print("\tFile not found.")
         if(PASS):
            print("\tPASS")
         else:
            print("\tFAIL")
      os.chdir("..")
   os.chdir("..")


def createOutput(directory, prog):
   PASS = False
   inFileName = "output/" + directory + "/" + prog + "1.txt"
   outFileName = "output/" + directory + "/" + prog + ".out"
   inFile = open(inFileName, 'r')
   outFile = open(outFileName, 'w')
   for line in inFile:
      if(line[0:2] == "::"):
         PASS = True
         res = line[2:].strip()
         res1 = res.split(" :: ")
         var = res1[0]
         actual = res1[1]
         outFile.write("{} = {}\n".format(var, actual))
   inFile.close()
   outFile.close()
   return PASS


'''
Check output with the expected output from running the C equivalent program

@directories:  where to find the programs
@programs:     program names
@inp:          input file name
@inpNum:       number of input parties
@outNum:       number of output parties
'''
def checkExpectedOutput(directories, programs, inp, inpNum, outNum):
   for directory in directories:
      for prog in programs: 
         expectedFileName = "expected-output/" + directory + "/" + prog + ".out"
         actualFileName = "output/" + directory + "/" + prog + ".out"
         print(directory + "/" + prog)
         PASS = True
         if(os.path.exists("output/" + directory + "/" + prog + "1.txt")):
            PASS = createOutput(directory, prog)
            if(not PASS):
               print("\tProgram run failed; results not printed.")
               continue
            expectedFile = open(expectedFileName, 'r')
            actualFile = open(actualFileName, 'r')
            expected = expectedFile.readlines()
            actual = actualFile.readlines()
            expectedFile.close()
            actualFile.close()
            nExp = len(expected)
            nAct = len(actual)
            n = max(nAct, nExp)  
            for i in range(0,n):
               lineAct = actual[i]
               lineExp = expected[i]
               if (lineAct != lineExp):
                  lineAct = lineAct.strip()
                  lineExp = lineExp.strip()
                  Act = lineAct.split(" = ")
                  Exp = lineExp.split(" = ")
                  if (Act[0] != Exp[0]):
                     print("variable names do not match: " +  Act[0] + " != " + Exp[0])
                     PASS = False
                  elif (float(Act[1]) != float(Exp[1])):
                     PASS = False
                     print("\tactual: " + Act[0] + "=" + Act[1] + "; expected: " + Exp[0] + "=" + Exp[1])
            if(nAct > nExp):
               print("unmatched lines:")
               for j in range(n, nAct):
                  print(Act[j].strip())
            elif(nExp > nAct):
               print("unmatched lines:")
               for j in range(n, nExp):
                  print(Exp[j].strip())
         else:
            PASS = False
            print("\tFile not found.")
         if(PASS):
            print("\tPASS")
         else:
            print("\tFAIL")
 


'''
Global boolean variables to control which programs should be used for testing
'''
ALL_PROGS = True
_TEST = False
_BASIC = False
_FLT_BASIC = False
_PTR_BASIC = False
_PTR_FLT_BASIC = False
_PTR_BASIC_EQ = False
_IF_NEQ = False
_FLT_IF_NEQ = False
_IF_VAR = False
_FLT_IF_VAR = False
_INC_DEC = False
_INC_DEC_VAR = False
_FLT_INC_DEC = False
_FLT_INC_DEC_VAR = False
_IF_COND = False
_FLT_IF_COND = False
_OUTPUT = False
_NON_THREAD = False
_BENCHMARK = False

'''
Function to choose which set of programs to test PICCO with. 

@func: the function to call on the subset of programs
'''
def choosePrograms(func):
   if(ALL_PROGS):
      func(BASIC_OPS_DIRS, BASIC_OPS, _INPUT, 1, 1)
      func(BASIC_OPS_PTR_DIRS, BASIC_OPS_PTR, _INPUT, 1, 1)
      func(BASIC_OPS_PTR_DIRS, PTR_EQ, _INPUT, 1, 1)
      func(IF_VAR_DIRS, IF_VAR, _INPUT, 1, 1)
      func(IF_VAR_DIRS_FLT, IF_VAR, _INPUT, 1, 1)
      func(INC_DEC_DIR, INC_DEC, _INPUT, 1, 1)
      func(INC_DEC_DIR_VAR, INC_DEC_VAR, _INPUT, 1, 1)
      func(IF_COND_OPS_DIRS, IF_COND_OPS, _INPUT, 1, 1)
   if(_BENCHMARK):
      func(BENCHMARK_DIR, BENCHMARK, None, 1, 1)
   if(_BASIC):
      func([BASIC_OPS_DIRS[0]], BASIC_OPS, _INPUT, 1, 1)
   if(_FLT_BASIC):
      func([BASIC_OPS_DIRS[1]], BASIC_OPS, _INPUT, 1, 1)
   if(_PTR_BASIC):
      func([BASIC_OPS_PTR_DIRS[0]], BASIC_OPS_PTR, _INPUT, 1, 1)
      func([BASIC_OPS_PTR_DIRS[0]], PTR_EQ, _INPUT, 1, 1)
   if(_PTR_FLT_BASIC):
      func([BASIC_OPS_PTR_DIRS[1]], BASIC_OPS_PTR, _INPUT, 1, 1)
      func([BASIC_OPS_PTR_DIRS[1]], PTR_EQ, _INPUT, 1, 1)
   if(_PTR_BASIC_EQ):
      func([BASIC_OPS_PTR_DIRS[0]], PTR_EQ, _INPUT, 1, 1)
   if(_IF_NEQ):
      func([IF_VAR_DIRS[0]], IF_VAR, _INPUT, 1, 1)
   if(_FLT_IF_NEQ):
      func([IF_VAR_DIRS_FLT[0]], IF_VAR, _INPUT, 1, 1)
   if(_IF_VAR):
      func([IF_VAR_DIRS[1]], IF_VAR, _INPUT, 1, 1)
   if(_FLT_IF_VAR):
      func([IF_VAR_DIRS_FLT[1]], IF_VAR, _INPUT, 1, 1)
   if(_INC_DEC):
      func([INC_DEC_DIR[0]], INC_DEC, _INPUT, 1, 1)
   if(_INC_DEC_VAR):
      func([INC_DEC_DIR_VAR[0]], INC_DEC_VAR, _INPUT, 1, 1)
   if(_FLT_INC_DEC):
      func([INC_DEC_DIR[1]], INC_DEC_VAR, _INPUT, 1, 1)
   if(_FLT_INC_DEC_VAR):
      func([INC_DEC_DIR_VAR[1]], INC_DEC_VAR, _INPUT, 1, 1)
   if(_IF_COND):
      func([IF_COND_OPS_DIRS[0]], IF_COND_OPS, _INPUT, 1, 1)
   if(_FLT_IF_COND):
      func([IF_COND_OPS_DIRS[1]], IF_COND_OPS, _INPUT, 1, 1)
   if(_NON_THREAD): 
      func(NON_THREAD_DIR, NON_THREAD, None, 1, 1)
   if(_TEST):
      func(TEST_DIR, TEST, "private-branching", 1, 1)
   if(_1D_ARRAY):
      func(1D_ARRAY_DIR, ARRAY, None, 1, 1)
   if(_2D_ARRAY):
      func(2D_ARRAY_DIR, ARRAY, None, 1, 1)


_STARS = "\n****************************************************\n"

'''
Main control of execution of the testing script
'''
def checkPICCO():
   if(_OUTPUT):
      choosePrograms(checkExpectedOutput)
   else:
      # clean up any files from the previous set of tests
#     os.system("python clean.py")
      # write programs to the makefile, compile with PICCO, get input shares with PICCO-UTIL, and make executables
      print(_STARS + "COMPILING  PROGRAMS" + _STARS)
      choosePrograms(compilePICCO)
      # run the executables
      print(_STARS + "RUNNING  PROGRAMS" + _STARS)
      choosePrograms(runPICCO)
      # check the output obtained from running the programs
      print(_STARS + "CKECKING  OUTPUT" + _STARS)
      choosePrograms(checkExpectedOutput)


if __name__ == "__main__":
   if (len(sys.argv) > 1):
      ALL_PROGS = False
      for i in range(1, len(sys.argv)):
         if (str(sys.argv[i]) == "-basic"):
            _BASIC = True
         elif (str(sys.argv[i]) == "-basicptr"):
            _PTR_BASIC = True
            _PTR_BASIC_EQ = True
         elif (str(sys.argv[i]) == "-ifvar"):
            _IF_NEQ = True
            _IF_VAR = True
         elif (str(sys.argv[i]) == "-incdec"):
            _INC_DEC = True
            _INC_DEC_VAR = True
         elif (str(sys.argv[i]) == "-nonptr"):
            _BASIC = True
            _PTR_BASIC = False
            _PTR_FLT_BASIC = False
            _PTR_BASIC_EQ = False
            _IF_NEQ = True
            _FLT_IF_NEQ = True
            _IF_VAR = True
            _FLT_IF_VAR = True
            _INC_DEC = True
            _INC_DEC_VAR = True
            _FLT_INC_DEC = True
            _FLT_INC_DEC_VAR = True
            _IF_COND = True
            _FLT_IF_COND = True
         elif (str(sys.argv[i]) == "-nonflt"):
            _BASIC = True
            _FLT_BASIC = False
            _PTR_BASIC = True
            _PTR_FLT_BASIC = False
            _PTR_BASIC_EQ = True
            _IF_NEQ = True
            _FLT_IF_NEQ = False
            _IF_VAR = True
            _FLT_IF_VAR = False
            _INC_DEC = True
            _INC_DEC_VAR = True
            _FLT_INC_DEC = False
            _FLT_INC_DEC_VAR = False
            _IF_COND = True
            _FLT_IF_COND = False
         elif (str(sys.argv[i]) == "-nonptrflt"):
            _BASIC = True
            _FLT_BASIC = False
            _PTR_BASIC = False
            _PTR_FLT_BASIC = False
            _PTR_BASIC_EQ = False
            _IF_NEQ = True
            _FLT_IF_NEQ = False
            _IF_VAR = True
            _FLT_IF_VAR = False
            _INC_DEC = True
            _INC_DEC_VAR = True
            _FLT_INC_DEC = False
            _FLT_INC_DEC_VAR = False
            _IF_COND = True
            _FLT_IF_COND = False
         elif (str(sys.argv[i]) == "-fltnonptr"):
            _FLT_BASIC = True
            _PTR_BASIC = False
            _PTR_FLT_BASIC = False
            _PTR_BASIC_EQ = False
            _FLT_IF_NEQ = True
            _FLT_IF_VAR = True
            _FLT_INC_DEC = True
            _FLT_INC_DEC_VAR = True
            _FLT_IF_COND = True
         elif (str(sys.argv[i]) == "-flt"):
            _FLT_BASIC = True
            _PTR_FLT_BASIC = True
            _FLT_IF_NEQ = True
            _FLT_IF_VAR = True
            _FLT_INC_DEC = True
            _FLT_INC_DEC_VAR = True
            _FLT_IF_COND = True
         elif (str(sys.argv[i]) == "-ptr"):
            _PTR_BASIC = True
            _PTR_FLT_BASIC = True
            _PTR_BASIC_EQ = True
         elif (str(sys.argv[i]) == "-vanilla"):
            _BASIC = True
            _FLT_BASIC = True
            _PTR_BASIC = True
            _PTR_FLT_BASIC = True
            _PTR_BASIC_EQ = True
            _IF_NEQ = True
            _FLT_IF_NEQ = True
            _IF_VAR = False
            _FLT_IF_VAR = False
            _INC_DEC = True
            _INC_DEC_VAR = True
            _FLT_INC_DEC = True
            _FLT_INC_DEC_VAR = True
            _IF_COND = True
            _FLT_IF_COND = True
         elif (str(sys.argv[i]) == "-test"):
            # this arg is intended for running whatever short set of 
            # tests you're currently working on
            _TEST = True
         elif (str(sys.argv[i]) == "-non-thread"):
            _NON_THREAD = True
         elif (str(sys.argv[i]) == "-output"):
            _OUTPUT = True
            _INC_DEC = True
            _INC_DEC_VAR = True
            #ALL_PROGS = True
         elif (str(sys.argv[i]) == "-array"):
            _1D_ARRAY = True
         elif (str(sys.argv[i]) == "-benchmark"):
            _BENCHMARK = True
         else:
            print("unknown arg: " + str(sys.argv[i]))
   checkPICCO()


