#include "shell.h"

char **tokenize(char *input, char* c){
    char *token,**diffcomm=malloc( 1000 * sizeof(char*));;
    token =strtok(input,c);
    int i=0;
    while(token){
        diffcomm[i]=token;
        token=strtok(NULL,c);
        i++;
    }
    diffcomm[i]=NULL;

    return diffcomm;
}