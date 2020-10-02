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
#include<fcntl.h>
#define SKIP_EMPTY while (*input == ' ' || *input == '\t') input++



char homedir[1300],cwd[1300];
void prompt();
char *_read();
char **tokenize(char *input, char* c);
void execute_inblt( char **argv, int argc);
void inblt_cd(char **argv);
void inblt_echo (char **argv);
void inblt_pwd();
void ls(char **argv);
void pinfo(char **argv);
int sys(char **argv, int argc, int input_fd, int output_fd);
void exit_handler (int sig);
void execute_with_pipes(char *input, int input_pipe );
void put_word_in_string (char **input, char **output);
int parse_line (char *input, char **argv, char **input_redir, char **output_redir, int *append);
void jobs();
void kjob(char **argv, int argc);
void overkill();
void bgg(char **argv, int argc);
void uenv(char **argv, int argc);
void senv(char **argv, int argc);
void fgg(char **argv, int argc);

int flag,status;
char prev[1300];
typedef struct bgp{
	int proc_id;
	char * cmd;
}bgp;
char *bg_processes[32768];
int bg_order[32768];
int bg_order_len;
int back_cnt;
bgp back_procs[1300];

