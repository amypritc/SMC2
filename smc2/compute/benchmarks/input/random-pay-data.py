
import os
import random as r


fileName = "pay-gap.txt"
f = open(fileName, 'w')
inputSize = [r.randint(5,100)]
f.write("inputSize = {},".format(inputSize[0]))
for i in range(1, 99):
   inputSize.append(r.randint(5,100))
   f.write("{},".format(inputSize[i]))
inputSize.append(r.randint(5,100))
f.write("{}\n".format(inputSize[99]))


for i in range(0, 100):
   f.write("gender = {},".format(r.randint(0,1)))
   #for j in range(1, inputSize[i]-1):
   for i in range(1, 99):
      f.write("{},".format(r.randint(0,1)))
   f.write("{}\n".format(r.randint(0,1)))
   

for i in range(0, 100):
   maxSalary = r.randint(80000,120000)
   minSalary = maxSalary - 30000
   f.write("salary = {},".format(r.randint(minSalary,maxSalary)))
   #for j in range(1, inputSize[i]-1):
   for i in range(1, 99):
      f.write("{},".format(r.randint(minSalary,maxSalary)))
   f.write("{}\n".format(r.randint(minSalary,maxSalary)))
   
f.close()

