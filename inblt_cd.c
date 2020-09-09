#include "shell.h"
#define lim 1300
void inblt_cd(char **argv){
     if (argv[1]!=NULL){ 
        char upath[lim];
        char *fpath = upath;
        if (argv[1][0] == '~') 
            sprintf(fpath, "%s%s", homedir, &argv[1][1]);
        else 
            fpath = argv[1];
        if(chdir (fpath) == -1) 
            perror (fpath);
     }
     else{
          char upath[lim];
          char *fpath = upath;
          sprintf(fpath, "%s", homedir);
          if(chdir (fpath) == -1) 
            perror (fpath);
     }
}