# Linux Shell in C
## Overview
Here,I tried to mimic the behaviour of the shell, implementing the various commands given in assignment pdf.
It supports semi colon separated commands.

## To run the shell
- > make
- > ./a.out 

## Brief info of each file and funtions contained in it

### shell.c
-  main(): contains main infinite loop.

### prompt.c
-  prompt(): It updates and prints prompt window. 

### read.c
-  _read(): Basically takes input.

### tokenize.c
-  tokenize(): It takes char array and char delimeter as input and outputs a double array after tokenizing the input.(delimeter separated output)

### execute.c
-  execute(): It directs every command to the respective function for execution.

### inblt_pwd.c
-  inblt_pwd(): prints current directory.

### inblt_cd.c
-  inblt_cd(): changes directory according to directory specified and all the flags mentioned in the assignment pdf.

### inblt_echo.c
-  inblt__echo(): prints whatever is given as argument after echo after tokenizing 1st with semi-colons and then tabs, newlines.

### ls.c
-  ls(): prints info about specified or current files depending upon flags, multiple directories supported.

### pinfo.c 
-  pinfo(): prints pid , process state , memory , executable path either for given pid or current process.

### sys.c
-  sys(): Executes commands other than inbuilt ones either in the foreground or in the backgroud depending upon & operator in input command space separated. For background process it prints a message that process started corresponding to pid.

### bg_handler.c
-  handler(): Notify us for background process completion with print statement.