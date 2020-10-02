#include "shell.h"

void jobs(){
   char file[1500];
    for(int i=0; i<bg_order_len; i++){
		sprintf(file,"/proc/%d/stat",bg_order[i]);
		FILE *f = fopen(file,"r");
        if(f== NULL){
            perror("unable to open");
        }
        else{
            int status1;
            char state,status2[1300],temp[1300];
            fscanf(f,"%d %s %c",&status1,status2,&state);
            if(state=='T')
                strcpy(temp,"Stopped");
            else
                strcpy(temp,"Running");
            printf("[%d] %s %s [%d]\n",i+1,temp,bg_processes[i],bg_order[i]);
            fclose(f);
        }
    }  
}