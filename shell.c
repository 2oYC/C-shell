#include "shell.h"

int main(){
    int status=1;
    char **diffcomm,**incomm;
    getcwd(homedir,1023);
    back_cnt=0;
    while(status){
        prompt();
        char *input=_read();
         //printf("bondu");
         if(input[0]=='\n')
            continue;
        diffcomm =tokenize(input,";");
        int i=0;
         //printf("bondu");
        while(diffcomm[i]!=NULL){
            incomm= tokenize(diffcomm[i]," \t\r\n\a");
            if(incomm[0]!=NULL){
                   int  j=1;
                while(incomm[j]==NULL)
                    j++;
                    j--;
               // printf("bondu");
                execute(incomm);
                //printf("bondu");
                i++;
            }
        }

    }
    
    return 0;
}