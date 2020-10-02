#include "shell.h"

void execute_inblt( char **argv, int argc){
    if(argv[0]==NULL)
        return ;
    if(strcmp(argv[0],"cd")==0){
            inblt_cd(argv);
            flag=1;
            //exit(EXIT_SUCCESS);
    }
    else if(strcmp(argv[0],"echo")==0){
        inblt_echo(argv);
        flag=1;
        //exit(EXIT_SUCCESS);
    }
    else if(strcmp(argv[0],"pwd")==0){
        inblt_pwd();
        flag=1;
        //exit(EXIT_SUCCESS);
    }
    else if(strcmp(argv[0],"ls")==0){
        ls(argv);
        flag=1;
          //exit(EXIT_SUCCESS);
    }
    else if(strcmp(argv[0],"pinfo")==0){
        pinfo(argv);
        flag=1;
       //exit(EXIT_SUCCESS);
    }
    else if(strcmp(argv[0],"jobs")==0){
        jobs();
        flag=1;
        //exit(EXIT_SUCCESS);
    }
    else if(strcmp(argv[0],"kjob")==0){
        kjob(argv,argc);
        flag=1;
        //exit(EXIT_SUCCESS);
    }
    else if(strcmp(argv[0],"overkill")==0){
        overkill();
        flag=1;
        //exit(EXIT_SUCCESS);
    }
    else if(strcmp(argv[0],"bg")==0){
        bgg(argv,argc);
        flag=1;
        //exit(EXIT_SUCCESS);
    }
    else if(strcmp(argv[0],"fg")==0){
        fgg(argv,argc);
        flag=1;
               //printf("yo");
        //exit(EXIT_SUCCESS);
    }
  
    else if(strcmp(argv[0],"setenv")==0){
        senv(argv,argc);
        flag=1;
        //exit(EXIT_SUCCESS);
    }
    else if(strcmp(argv[0],"unsetenv")==0){
        uenv(argv,argc);
        flag=1;
        //exit(EXIT_SUCCESS);
    }
    

    return ;
    
}