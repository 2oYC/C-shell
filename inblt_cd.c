#include "shell.h"
#define lim 1300
void inblt_cd(char **argv){
   // printf("%s %s",argv[0], argv[1]);
     if (argv[1]!=NULL){ 
        char upath[lim];
        char *fpath = upath;

        if (argv[1][0] == '~') 
            sprintf(fpath, "%s%s", homedir, &argv[1][1]);
        else if(argv[1][0] == '-')
           sprintf(fpath, "%s%s", prev, &argv[1][1]);
        else 
            fpath = argv[1];
           // printf("%s",fpath);
         // char temp[1300];
          //strcpy(temp,prev);
          getcwd(prev,1023);
        if(chdir (fpath) == -1) 
            perror (fpath);
         if(argv[1][0]=='-')
            printf("%s\n",prev);
     }
     else{
          char upath[lim];
          char *fpath = upath;
          sprintf(fpath, "%s", homedir);
          if(chdir (fpath) == -1) 
            perror (fpath);
     }
     //printf("hi");
   return ;
}