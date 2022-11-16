# -*- coding: utf-8 -*-
"""
Created on Thu Nov  3 14:00:42 2022

@author: Lars Øvergård
@email: lars.overgard@nmbu.no

Made to split binary files, to make it work with cin in c++

"""

# Read file
f = open("data.txt", "r")
data = f.read()
f.close()

# Noise removal (spaces)
data_slim = data.replace(' ', '')
data_split = data_slim.split("\n")

# Make/overwrite file
f_fix = open("data.dat", "w")

wid = len(data_split[0])
llen = len(data_split)

# Write info
f_fix.write(str(wid) + " " + str(llen) + "\n")

# Write picture
for line in data_split:
    for num in line:
        f_fix.write(str(num) + " ")
    f_fix.write('\n')

# Close file
f_fix.close()