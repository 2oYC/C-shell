#include "shell.h"

char *_read(){
    char *str;
    ssize_t size =0 ;
    getline(&str, &size, stdin);

    return str;

}