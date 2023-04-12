#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void error_y_exit (char *msg, int exit_status){
    perror(msg);
    exit(exit_status);
}

int main(int a, char *b[]){
    int i = 0;
    char buff[180] ;
    /*
    while (i < a){
        sprintf(buff,"let  %s\n", b[i]);
        write(1, buff, strlen(buff));
        i++;
    }
    int pid = fork();
    if (pid == 0)execl("./p2","./p2", "jinheng", "lin", "is", "stupid", (char*)NULL);
    else {
        waitpid (pid,NULL, 0);
        error_y_exit("try    gg", 1);
        
    }*/
    
    while(i < 10){
        int pid = fork();
        if(pid == 0){
            sprintf(buff, "soy hijo %d \n", getpid());
            write(1, buff, strlen(buff));
            //exit(0);
            execl("./p2","./p2","stupid",(char*)NULL);
        }else {
            waitpid(pid, NULL, 0);
            sprintf(buff, "amo es %s \n", b[1]);
            write(1, buff, strlen(buff));
        }
        i++;
    }
    return 0;
}
