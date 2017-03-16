# A-formation

This repository provides the code for formation and plotting of the co-ordinates so as to form an 'A' when provided 
with an input = no. of bots.

The input is to be taken from command line as ./A 100 (100 represents the number of bots)

The A.cpp program calculates the co-ordinates of the bots and stores it in the file "f.txt".

The Plot.py program takes the co-ordinates from "f.txt" and plots it.

The compiled code and the file for n=100 has been provided here. You can change it as you like.

The A.cpp program uses opencv, so compile it using the command provided below.

g++ -ggdb -std=c++11 `pkg-config --cflags opencv` -o `basename A.cpp .cpp` A.cpp `pkg-config --libs opencv`

To compile the Plot.py program use:

python Plot.py


And enjoy... :)
