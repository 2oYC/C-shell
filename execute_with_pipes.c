#include "shell.h"

void execute_with_pipes(char *input, int input_pipe ){
    char *next_command; 
    next_command = strstr(input, "|");
    char **argv = malloc(1300);
    char *input_redir = NULL;
    char *output_redir = NULL;
    int i, argc, append, pipefd[2],input_fd = -1, output_fd = -1;

    if (next_command != NULL) {
        *next_command = '\0';
        next_command++;
        if (pipe(pipefd) < 0) perror("Unable to create pipes");
    }

   
    argc = parse_line (input, argv, &input_redir, &output_redir, &append);

    if (input_redir != NULL)
         input_fd = open(input_redir, O_RDONLY, 0); 
    else if (input_pipe>=0) 
        input_fd = input_pipe;

    if (output_redir != NULL) {
        int flags = O_WRONLY | O_CREAT;
        if (append) flags |= O_APPEND;
        else flags |= O_TRUNC;
        output_fd = open(output_redir, flags, 0644);
    }
    else if (next_command != NULL) 
            output_fd = pipefd[1];
   

    sys (argv, argc, input_fd, output_fd);
    for (i = 0; i < argc; i++) 
        free (argv[i]);
    free (input_redir);
    free (output_redir);
    free (argv);
    if (next_command != NULL) 
            execute_with_pipes (next_command, pipefd[0]);

}