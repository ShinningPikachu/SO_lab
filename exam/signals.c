#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>

int tratar_exit (int exit_code){
    int statcode,signcode;
    char buffer[120];
    if (WIFEXITED(exit_code)) {
        statcode = WEXITSTATUS(exit_code);
        sprintf(buffer,"El proceso %d termina con exit code %d\n", getpid(),
        statcode);
        write(1,buffer,strlen(buffer));
        return 1;

    }
    else {
        signcode = WTERMSIG(exit_code);
        sprintf(buffer,"El proceso %d termina por el signal %d\n", getpid(),
        signcode);
        write(1,buffer,strlen(buffer));
        return 0;
}

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


void enviar_URS(){

}


int main(int a, char *b[]){
    char buff[256];
    int orden = 0;
    int pids[a-1];
    if(a == 1 || a > 11) Usage;
    
    sigset_t mask;
    sigemptyset (&mask);
    sigaddset (&mask, SIGALRM);
    sigaddset (&mask, SIGINT);
    sigaddset (&mask, SIGUSR1);
    sigprocmask (SIG_BLOCK, &mask, NULL);
    
    SIGALRM(2);
    
    struct sigaction sa,sb;
    sa.sa_handler = &tratar_hijo;
    sa.sa_flags = SA_RESTART;
    sigfillset(&sa.sa_mask);
    
    for (int i = 1; i < a; i++){
        int pid = fork();
        pids[i-1] = pid;
        if (pid == 0){
        sigfillset (&mask);
        sigdelset (&mask, SIGUSR1);
        sigsuspend (&mask);
            sprintf(buff, "hijos: trato el documento: %s \n", b[i]);
            
            write(1, buff, strlen(buff));
            exit(orden);
        }else if (pid == -1){
        error_y_exit("error fork", 1);
        }
        orden++;
    }
    
    for (int i = 0; i < a-1; i++){
        sigfillset (&mask);
        sigdelset (&mask, SIGINT);
        sigsuspend (&mask);
        
        sigkill(pids[i], SIGUSR1);
    }
    
    
    sleep(1);
    for(int i = 0; i < a-1; i++){
        int exit_code = 0;
        waitpid(pids[i], &exit_code, 0);
        tratar_exit(exit_code);
    }
}
