#include <stddef.h>
#include <limits.h>
#include <linux/limits.h>
#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{               
    remove("LocalList.txt") ; 
    FILE *fp ; 

 
     printf(("\033[36m############Welcome at My Own Shell############\n\033[0m")) ;
 
    int Process ; 
    int  status ;
    char * d_space=" " ; 
    char * d_equal="=" ; 
    char *tok ;
    while (1)
    {
        
     char *args[100];
     char * args_env[100] ;
     char Cmd [100]; 
     printf("\033[32mMoElSayed@Shell\033[0m::");
     printf("\033[34m%s>>\033[0m",getcwd(NULL, 0));
     fgets(Cmd,100,stdin);
     int Length=strlen(Cmd);
     Cmd[Length-1]= 0 ; 
     if (Cmd[0]== 0)
            continue; 
     // Creation Process !
     tok=strtok(Cmd,d_space);
        int x = 0 ;
     while (tok!=NULL)
     {
        args[x]=tok ;      
        tok=strtok(NULL,d_space);
            x++ ;
     }
        args[x]=0 ;
    
      
    
       
         
     Process=fork() ; 




     if (Process > 0 )
     {
        // Parent Process ! 
        
        wait(& status);   

     }
     else if (Process ==  0 )
     {
          if(!strcmp(args[0],"export"))
            {
                tok=strtok(args[1],d_equal);
                int y = 0 ;
                char *args_env[2]; 
                while (tok!=NULL)
                {
                args_env[y]=tok ;      
                tok=strtok(NULL,d_equal);
                y++ ;
                }
                //printf("%s %s", args_env[0],args_env[1]); 
                setenv((char*)args_env[0],(char*)args_env[1],1);
                

            }
            if(!strcmp(Cmd,"set"))
            {
            char* new_args[]={"cat","LocalList.txt",NULL} ; 
            execvp("cat", new_args);

            }
            if(strchr(Cmd,'=')!=NULL  )
            {    
            
            fp=fopen("LocalList.txt", "a"); 
            fprintf(fp, "%s\n",(char*)Cmd);
            fclose(fp) ; 
           
            }
            if (!strcmp(args[0],"cd")) 
            {    
            chdir((char*)args[1]); 
            }        
            else
             {
            execvp(args[0], args);
            //printf("Failure  Execution !!!! \n"); 
            return -1 ;
            }
        
           
     }        



    

    }
    return 0 ; 



}   
