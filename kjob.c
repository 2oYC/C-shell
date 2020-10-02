#include "shell.h"

void kjob(char **argv,int argc){
    if(argc==3){
        int no,signal;
        no=atoi(argv[1]);
        signal=atoi(argv[2]);
        if(no>bg_order_len){
            perror("invalid pid");
            return;
        }
        kill(bg_order[no-1], signal);

    }
    else
        perror("no. of arguments not valid");
    return ;
}