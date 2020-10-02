#include "shell.h"

int main(){
    status=1;
    strcpy(prev,"~");
    char **diffcomm,**incomm;
    getcwd(homedir,1023);
    back_cnt=0;
    bg_order_len = 0;
    signal(SIGCHLD, exit_handler);
    while(status){
        prompt();
        char *input=_read();
         //printf("bondu");
         if(input[0]=='\n')
            continue;
        diffcomm =tokenize(input,";");
        int i=0;
         //printf("bondu");
        while(diffcomm[i]!=NULL){
            execute_with_pipes(diffcomm[i],-1);
            i++;
        }

    }
    
    return 0;
}