# -*- coding: utf-8 -*-
"""
Created on Thu Nov  3 14:00:42 2022

@author: Lars Øvergård
@email: lars.overgard@nmbu.no

Made to split binary files, to make it work with cin in c++

"""

f = open("data.txt", "r")
data = f.read()
f.close()

data_split = data.split()

f_fix = open("data.dat", "w")

wid = len(data_split[0])
llen = len(data_split)

f_fix.write(str(wid) + " " + str(llen) + "\n")

for line in data_split:
    for num in line:
        f_fix.write(str(num) + " ")
    f_fix.write('\n')

f_fix.close()
