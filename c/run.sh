#!/bin/bash

rm -f *.out
rm -f *.o

gcc -c bitvec.c
gcc -Wno-format bitvec.o $1.c
./a.out

rm -f *.out
rm -f *.o
