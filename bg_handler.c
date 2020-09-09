#include "shell.h"

void handler(int sig)
{
  pid_t pid;
  pid = waitpid(-1, NULL, WNOHANG);
  if(pid!=-1){
      printf("%d\n",back_cnt);
      for(int i=0; i<back_cnt; i++){
          //printf("culla\n");
          if(back_procs[i].proc_id == pid){
            printf("\n %s with pid %d completed.\n", back_procs[i].cmd,pid);
          }
      }
  }

}
