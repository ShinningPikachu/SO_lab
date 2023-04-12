#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>

void usage(){
    char buff[256];
    sprintf (buff, "Usage: solo un parametro entero \n");
    write(1, buff, strlen(buff));
    exit(0);
}

void hijos(int pid) {
    char b[256];
    sprintf (b, "hijo mayor %d\n", pid);
    write(1, b, strlen(b));
}

void error_exit(char* msg, int exit_status){
    perror(msg);
    exit(exit_status);
}

int main(int a, char *b[]){
    char buf[256];
    if( a != 2 ){
        usage();
    }
    int n = atoi(b[1]);
    int *p = malloc(sizeof(int)*n);
    for(int i = 0; i < n; i++){
        int pid = fork();
        if (pid != 0) p[i] = pid;
        if(pid == 0 && i == 0){
            hijos(getppid());
            exit(1);
        }else if (pid == 0){
            hijos(p[i-1]);
            exit(1);
        }
        sleep(1);
    }
    
    
    for(int i = 0; i < n; i++){
        waitpid(-1, NULL, 0);
    }
    
    while(1);
    
    free(p);
    
    
    
}
