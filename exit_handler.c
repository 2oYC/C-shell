#include "shell.h"

void exit_handler (int sig) {
    pid_t pid;
    int status;
     fflush (NULL);
    pid = waitpid (-1,&status,WNOHANG);
    for(int i=0; i<bg_order_len; i++)
    if (bg_order[i]==pid) {
        printf ("\nprocess %s with pid %d exited ", bg_processes[i], pid);
        if (WIFEXITED(status)) printf ("normally.\n");
        else printf ("with exit status %d.\n", WEXITSTATUS(status));
       // free (bg_processes[i]); 
        for(int j=i; j < bg_order_len-1; j++)
         {
                strcpy(bg_processes[j], bg_processes[j+1]);
                bg_order[j] = bg_order[j+1];
        }
     
        bg_order_len--;
        prompt();
        fflush (NULL);
    }
}