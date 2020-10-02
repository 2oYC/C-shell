#include "shell.h"

void ctrlc(int sig){
     pid_t process = global;
    if (process !=0 && process!=-1) 
    {
        kill(process, SIGINT);
        printf("\n");
        fflush(stdout);
    } 
    else 
    {
        printf("\n");
        // print_dirname(size);
        prompt();
        fflush(stdout);
    }
}