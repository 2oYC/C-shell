#include "shell.h"

void execute( char **argv){
    if(argv[0]==NULL)
        return ;
    if(strcmp(argv[0],"cd")==0)
        inblt_cd(argv);
    else if(strcmp(argv[0],"echo")==0)
        inblt_echo(argv);
    else if(strcmp(argv[0],"pwd")==0)
        inblt_pwd();
    else if(strcmp(argv[0],"ls")==0)
        ls(argv);
    else if(strcmp(argv[0],"pinfo")==0)
        pinfo(argv);
    else{
        sys(argv);
    }

    return ;
    
}