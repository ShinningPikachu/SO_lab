#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>

void error_y_exit (char *msg, int exit_status)
{
  perror (msg);
  exit (exit_status);
}


void Usage() {

    char buf[80];

    sprintf(buf, "Usage: inserte  de 1 - 10 nombres de documentos\n");
    write(1,buf,strlen(buf));

    exit(0);
}


int main(int a, char *b[]){
    char buff[256];
    int orden = 0;
    int pids[a-1];
    if(a == 1 || a > 11) Usage;
    for (int i = 1; i < a; i++){
        int pid = fork();
        pids[i-1] = pid;
        if (pid == 0){
            sprintf(buff, "hijos: trato el documento: %s \n", b[i]);
            
            write(1, buff, strlen(buff));
            exit(orden);
        }else if (pid == -1){
        error_y_exit("error fork", 1);
        }
        orden++;
    }
    sleep(1);
    for(int i = 0; i < a-1; i++){
        int exit_code = 0;
        waitpid(pids[i], &exit_code, 0);
        int statcode = WEXITSTATUS(exit_code);
        sprintf(buff, "pid_hijo: %d; orden: %d\n", pids[i], statcode);
        write(1, buff, strlen(buff));
    }
}
