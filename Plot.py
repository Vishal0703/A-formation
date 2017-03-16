#!/usr/bin/python

import matplotlib.pyplot as mp
import numpy as np


text=open("f.txt", "r")
lines=text.readlines()

input1=lines[0].split(' ')
input2=lines[1].split(' ')



arr1=map(float, input1[:-1])
arr2=map(float, input2[:-1])

mp.plot(arr1, arr2, "go")

mp.axes().set_aspect('equal', 'datalim')


mp.show()
