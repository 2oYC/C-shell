#include "shell.h"

void senv(char **argv, int argc){
   // printf("hi");
    if(!(argc==2 || argc==3)){
        perror("invalid no. of arguments");
        return ;
    }
   // printf("%s %s",argv[1],argv[2]);
    if(argv[2]==NULL)
        argv[2]=" ";
    if(setenv(argv[1],argv[2],1)==-1)
        perror("setenv failure");

return;
}