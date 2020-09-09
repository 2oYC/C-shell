# Linux Shell in C
## Overview
Here,I tried to mimic the behaviour of the shell, implementing the various commands given in assignment pdf.
It supports semi colon separated commands.

## To run the shell
- > make
- > ./a.out 

## Brief info of each file and funtions contained in it

### shell.c
1. main(): contains main infinite loop.

### prompt.c
1. prompt(): It updates and prints prompt window. 

### read.c
1. _read(): Basically takes input.

### tokenize.c
1. tokenize(): It takes char array and char delimeter as input and outputs a double array after tokenizing the input.(delimeter separated output)

### execute.c
1. execute(): It directs every command to the respective function for execution.

### inblt_pwd.c
1. inblt_pwd(): prints current directory.

### inblt_cd.c
1. inblt_cd(): changes directory according to directory specified and all the flags mentioned in the assignment pdf.

### inblt_echo.c
1. inblt__echo(): prints whatever is given as argument after echo after tokenizing 1st with semi-colons and then tabs, newlines.

### ls.c
1. ls(): prints info about specified or current files depending upon flags, multiple directories supported.

### pinfo.c 
1. pinfo(): prints pid , process state , memory , executable path either for given pid or current process.

### sys.c
1. sys(): Executes commands other than inbuilt ones either in the foreground or in the backgroud depending upon & operator in input command space separated. For background process it prints a message that process started corresponding to pid.

### bg_handler.c
1. handler(): Notify us for background process completion with print statement.