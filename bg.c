#include "shell.h"

void bgg(char **argv, int argc){
    if(argc==1)
        perror("job no. not provided");
    else{
        int no;
        no= atoi(argv[1]);
        if(no<=bg_order_len)
            kill(bg_order[no-1],SIGCONT);
        else
        perror("invalid job no.");
    }
    return ;
}