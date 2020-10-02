#include "shell.h"
#define red    "\x1b[31m"
#define res     "\x1b[0m"

void abt_folder(char folder[],int lflag, int aflag){

            struct dirent ** list;
    int number_of_files = scandir(folder, &list, NULL, alphasort );
    if(number_of_files < 0)
    {
        perror("ERROR : ls failed!");
        return ;
    }
    else
    {
        printf(red "\n%s\n" res,folder);
        for(int i = 0 ; i<number_of_files ; i++)
        {
            char *path,  *name = list[i]->d_name; 
            if(aflag == 0)
            {
                if(name[0] == '.')
                continue;
            }
            if(lflag == 1)
            {

                struct stat data;
                char file[1024];
                strcpy(file,folder);
                strcat(file, "/");
                strcat(file, name);
                stat(file, &data);
                char *permissions = (char *)malloc(1024*sizeof(char));
                strcpy(permissions, "----------");
                if(S_ISDIR(data.st_mode))
                    permissions[0] = 'd';
                if(data.st_mode & S_IRUSR)
                    permissions[1] = 'r';
                if(data.st_mode & S_IWUSR)
                    permissions[2] = 'w';
                if(data.st_mode & S_IXUSR)
                    permissions[3] = 'x';
                if(data.st_mode & S_IRGRP)
                    permissions[4] = 'r';
                if(data.st_mode & S_IWGRP)
                    permissions[5] = 'w';
                if(data.st_mode & S_IXGRP)
                    permissions[6] = 'x';
                if(data.st_mode & S_IROTH)
                    permissions[7] = 'r';
                if(data.st_mode & S_IWOTH)
                    permissions[8] = 'w';
                if(data.st_mode & S_IXOTH)
                    permissions[9] = 'x';
                
            
                char user[1024], group[1024];
                if(data.st_uid == 1000)
                {
                    getlogin_r(user, sizeof(user));
                }
                else if(data.st_uid == 0)
                {
                    strcpy(user,"root");
                }

                if(data.st_gid == 1000)
                {
                    getlogin_r(group, sizeof(group));
                }

                char * times = (char*)malloc(50*sizeof(char));
                times = ctime(&data.st_atime);
                
                long long int size = data.st_size;


                printf("%s %s %s %lld %s %s\n", permissions, user, group, size, times, name);
            }
            else
            {
                printf("%s   \n", name);
            }
        }
       // printf("\n");
        free(list);

           }

}



void ls(char ** argv)
{
	int argc=0;
	while(argv[argc]!=NULL)
		argc++;
	
    char folder[1300];
    strcpy(folder, ".");
   
    int lflag = 0, aflag = 0,cnt=0;

    for(int i = 1 ; i<argc ; i++)
    {
        if(!(strcmp(argv[i], "-l") )) 
            lflag = 1;
        
        else if(!(strcmp(argv[i], "-a") ))  
            aflag = 1;
        else if(strcmp(argv[i], "-al")==0 || strcmp(argv[i], "-la")==0){
            aflag=1;
            lflag=1;
        }
        else
        cnt++;
              
    }
     if(!cnt){
         //ls given as input without directory
        char currpath[1300];
        getcwd(currpath,1023);
        strcpy(folder,currpath);
        abt_folder(folder,lflag,aflag);
   
    }
      
    else{
    for(int i = 1 ; i<argc ; i++)
    {
        if(argv[i][0] != '-'){
            if(argv[i][0] == '~')
            {
                strcpy(folder, homedir);
                strcat(folder, argv[i]+1);
                folder[strlen(folder)+1] = '\0';
            }
            else
            {

                getcwd(folder,1023);
                strcat(folder, "/");
                strcat(folder, argv[i]);
                folder[strlen(folder) + 1] = '\0';
            }

            abt_folder(folder,lflag,aflag);
         }
      }
    }

    
    return ;
}