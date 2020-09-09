#include "shell.h"

void sys(char **argv){
    int i=0,bg_check=0;
    while(argv[i]!=NULL)
        i++;
    i--;
    int len=strlen(argv[i]);
    if(argv[i][len-1]=='&'){
        bg_check=1;
        //printf("%c dulla\n",argv[i][len-1]);
        argv[i]=NULL;
       // printf("%c\n",argv[i][len-1]);
    }
  //  printf("%s %s\n",argv[0], argv[1]);

  int pid, wpid;
  int status;
  

  pid = fork();
  if (pid < 0) {
    perror("error in forking");
  }
  else if (!pid) {
      setpgrp();
    if (execvp(argv[0], argv) == -1) {
      perror("execvp failure");
    }
    exit(1);
  } 

  if (bg_check) {
    
     printf("process with pid %d started\n",  pid);
     back_procs[back_cnt].proc_id= pid;
     back_procs[back_cnt].cmd=argv[0];
     back_cnt++;
        // waitpid(-1, NULL, WNOHANG);
         signal(SIGCHLD, handler);
  } else {
        waitpid(pid, &status, WUNTRACED);
   // WUNTRACED: return if process has exited or process has stopped 
  }
  return ;
    
}