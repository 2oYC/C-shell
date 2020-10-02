#include "shell.h"

char *_read(){
    char *str;
    ssize_t size =0 ;
    getline(&str, &size, stdin);
    if(strcmp(str,"\0")==0)
    {
        printf("\n");
        status=0;
    }
    return str;

}