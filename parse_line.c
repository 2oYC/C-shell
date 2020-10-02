#include "shell.h"

void put_word_in_string (char **input, char **output) {
    if (output != NULL) *output = malloc(1300);
    int c;
    for (c = 0; **input != '\0' && **input != ' ' && **input != '\n'; (*input)++, c++) {
        if (output != NULL) (*output)[c] = **input;
        // printf("%c %c\n", **input, (*output)[c]);
    }
    if (output != NULL) (*output)[c] = '\0';
}

int parse_line (char *input, char **argv, char **input_redir, char **output_redir, int *append) {
    int c, argc = 0;
   // while (*input == '\t' || *input == ' ') input++;
   SKIP_EMPTY;
    if (*input == '\n') return 0;
     SKIP_EMPTY;
    while (*input != '\0' && *input != '\n') {
        SKIP_EMPTY;
        if (*input == '<') {
             SKIP_EMPTY;
            input++;
            SKIP_EMPTY;
            put_word_in_string(&input, input_redir);
            SKIP_EMPTY;
        } else if (*input == '>') {
             SKIP_EMPTY;
            input++;
             SKIP_EMPTY;
            if (append) *append = 0;
             SKIP_EMPTY;
            if (*input == '>') {
                if (append) *append = 1;
                input++;
            }
            SKIP_EMPTY;
            put_word_in_string(&input, output_redir);
            SKIP_EMPTY;
        } else {
             SKIP_EMPTY;
            put_word_in_string(&input, &argv[argc]);
            SKIP_EMPTY;
            argc++;
        }
    }
    argv[argc] = NULL;
    return argc;
}