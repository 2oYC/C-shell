#include "shell.h"

void inblt_pwd(){
    char temp[1300];
    getcwd(temp,1023);
    printf("%s\n",temp);
}