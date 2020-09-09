#include "shell.h"

void pinfo(char **argv){
    char pid[1300];
    if(argv[1]==NULL)
        sprintf(pid,"%d",getpid());
    else
        sprintf(pid,"%s",argv[1]);
    printf("pid -- %s\n",pid);

        char file[1500];
		sprintf(file,"/proc/%s/stat",pid);
		FILE *f = fopen(file,"r");
        if(f== NULL){
            perror("not valid pid");
            return;
        }
		int status1;
		char state,status2[1300];
		fscanf(f,"%d %s %c",&status1,status2,&state);
		printf("Process Status -- %c\n",state);	
		fclose(f);

		int mem;
		sprintf(file,"/proc/%s/statm",pid);
		FILE *f1 = fopen(file,"r");
		fscanf(f1,"%d",&mem);
		printf("memory -- %d\n",mem);
		fclose(f1);

		char loc[1000]={0};
		sprintf(file,"/proc/%s/exe",pid);
		int len = readlink(file,loc,sizeof(loc));
		loc[len] = '\n';	
		printf("Executable Path -- %s",loc);

    
    

    
} 