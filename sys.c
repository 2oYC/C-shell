#include "shell.h"

int sys(char **argv, int argc, int input_fd, int output_fd) {
    if (argc == 0) 
        return 0;
      
    else if (strcmp (argv[0], "quit") == 0 || strcmp (argv[0], "exit") == 0)
        exit (EXIT_SUCCESS);

    pid_t pid, wpid;
    int status;

    int background = 0;
    if (argv[argc-1][0] == '&') {
        background = 1;
        free (argv[argc]);
        argv[--argc] = NULL;
    }
    flag=0;
     execute_inblt (argv, argc);


    pid = fork();
    if (pid < 0) {
        perror("Forking error");
    }
    else if (pid == 0) {
       
        if (input_fd >= 0) {
            dup2(input_fd, STDIN_FILENO);
            close(input_fd);
        }
        if (output_fd >= 0) {
            dup2(output_fd, STDOUT_FILENO);
            close(output_fd);
        }
         setpgrp();
       if(!flag){
        if (execvp(argv[0], argv) == -1) {
            perror(argv[0]);
        }
       }
        exit(EXIT_FAILURE);
    } 
    else{
        // Parent process
        if (input_fd >= 0) close (input_fd);
        if (output_fd >= 0) close (output_fd);
        if(background){
            bg_order[bg_order_len] = pid;
            bg_processes[bg_order_len] = malloc (1300);
            strcpy (bg_processes[bg_order_len], argv[0]);
            bg_order_len++;
        }
         else { // Not a background process
            do {
                global=pid;
                wpid = waitpid(pid, &status, WUNTRACED);
            } while (!(WIFEXITED(status) || WIFSIGNALED(status)));
        }
    } 

    return 1;
}