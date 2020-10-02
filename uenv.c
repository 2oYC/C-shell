#include "shell.h"

void uenv(char **argv, int argc){
    if(argc==2){
        if(unsetenv(argv[1])==-1)
            perror("unsetenv failure");
    }
    else{
        perror("invalid no, of arguments");
    }

    return ;
}