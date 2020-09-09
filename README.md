# Linux Shell in C
## Overview
Here,I tried to mimic the behaviour of the shell, implementing the various commands given in assignment pdf.

## To run the shell
- > make
- > ./a.out 

## Brief info of each file

### shell.c
1. main(): contains main infinite loop.

### prompt.c
1. prompt(): It updates and prints prompt window. 

### read.c
1. _read(): Basically takes input.

### tokenize.c
1. tokenize(): It takes char array and char delimeter as input and outputs a double array after tokenizing the input.(delimeter separated output)

### 