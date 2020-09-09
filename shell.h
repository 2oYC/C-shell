#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<dirent.h>
#include <errno.h>
#include<time.h>
#include<wait.h>
#include<signal.h>

char homedir[1300],cwd[1300];
void prompt();
char *_read();
char **tokenize(char *input, char* c);
void execute( char **argv);
void inblt_cd(char **argv);
void inblt_echo (char **argv);
void inblt_pwd();
void ls(char **argv);
void pinfo(char **argv);
void sys(char **argv);
void handler();

typedef struct bgp{
	int proc_id;
	char * cmd;
}bgp;
int back_cnt;
bgp back_procs[1300];