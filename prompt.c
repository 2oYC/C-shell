#include "shell.h"
#define blue    "\x1b[34m"
#define res     "\x1b[0m"

void prompt(){
    char hostname[1300],pcwd[1300];
    gethostname(hostname, 1023);
    getcwd(cwd,1023);
    if(strcmp(cwd,homedir)==0)
        strcpy(pcwd,"~");
    else{
       
  /*      int i=0, flag=0, len = strlen(cwd), j;
    while(homedir[i]!='\0') {
        if(cwd[i]!=homedir[i])
        flag = 1; break;
        i++;
        
    }
        if(flag){
            strcpy(pcwd,cwd);
    } else {
        char newCWD[1300];
        newCWD[0]='~';
        while(i<len){
        newCWD[j] = cwd[i];
        j++; i++;
        }
        strcpy(pcwd, newCWD);
        
    }*/ int i, flag=0, len = strlen(cwd), j;
  for(i=0; homedir[i]!='\0'; i++) {
    if(cwd[i]!=homedir[i]){
      flag = 1;
      break;
    }
  }
  if(flag){
    strcpy(pcwd,cwd);
  } else {
    char newCWD[len-i+3];
    newCWD[0]='~';
    j=1;
    while(i<len){
      newCWD[j] = cwd[i];
      i++; j++;
    }
    newCWD[j]='\0';
    strcpy(pcwd, newCWD);
  }
    }


    printf(blue "<%s@%s:%s>" res,getlogin(),hostname,pcwd);


}