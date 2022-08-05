import os
import sys
from FILES import *
# script to clean up old executables and files and make sure all directories exist

DIRS = ["inputShares", "output", "utility", "compiled"]

def cleanDirs():
   for directory in DIRS:
      os.system("rm -rf " + directory)
      os.makedirs(directory)


def clearProgs():
   f = open("programs.mk", 'w')
   f.write("PROGRAMS +=")
   f.close()


def clean(directories, programs):
   for directory in directories:
      for prog in programs:
         os.system("rm -f " + directory + "/" + prog)
         os.system("rm -f " + directory + "/" + prog + ".txt")


if __name__ == "__main__":
   cleanDirs()
   clearProgs()
   clean(BASIC_OPS_DIRS, BASIC_OPS)
   clean(BASIC_OPS_PTR_DIRS, BASIC_OPS_PTR)
   clean(BASIC_OPS_PTR_DIRS, PTR_EQ)
   clean(IF_VAR_DIRS, IF_VAR)
   clean(IF_VAR_DIRS_FLT, IF_VAR)
   clean(INC_DEC_DIR, INC_DEC)
   clean(INC_DEC_DIR_VAR, INC_DEC_VAR)
   clean(IF_COND_OPS_DIRS, IF_COND_OPS)


