#include "shell.h"

void inblt_echo (char **argv) {
    int i,argc=0;
    while (argv[argc]!=NULL){
        argc++;
    }
     if(argc==1){
        printf("\n");
        return ;
     }
    for (i = 1; i < argc - 1; i++) 
        printf("%s ", argv[i]);
    printf("%s\n", argv[i]);
}
