#include "shell.h"

void fgg(char **argv, int argc){
    if(argc==2){
        int no;
        int x=getpid();
        no=atoi(argv[1]);
        if(no>bg_order_len){
            perror("invalid job no.");
            return ;
        }
       // printf("hi");
        int pid=bg_order[no-1];
       // printf("%d %s",pid,bg_processes[no-1]);
        for(int j=no-1; j < bg_order_len-1; j++)
          {
                strcpy(bg_processes[j], bg_processes[j+1]);
                bg_order[j] = bg_order[j+1];
          }
        bg_order_len--;
         //  printf("hi");

        signal(SIGTTIN, SIG_IGN); signal(SIGTTOU, SIG_IGN); tcsetpgrp(STDIN_FILENO,getpgid(pid));
        kill(pid, SIGCONT);
        int status;
          // printf("hi");
        waitpid(pid, NULL, WUNTRACED);
           //printf("hi");
        
            tcsetpgrp(STDIN_FILENO,x);
            signal(SIGTTIN,SIG_DFL);
            signal(SIGTTOU,SIG_DFL);
              // printf("hi"); 

    }
    else 
        perror("invalid no. of arguments");

    return ;
}