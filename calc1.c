#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>

int * hijos_pids;
int pos = 0;
int nfi = 1;
void error (char *msg, int exit_status)
{
  perror (msg);
  exit (exit_status);
}

void Usage() {

    char buf[80];

    sprintf(buf, "Usage:listaParametros arg1 entero positivi, arg2 nombre de un fichero\n");
    write(1,buf,strlen(buf));
    exit(0);
}
int tratar_exit (int exit_code, int pid_hijo){
    int statcode,signcode;
    char buffer[120];
    if (WIFEXITED(exit_code)) {
        statcode = WEXITSTATUS(exit_code);
        if(statcode == 0){
            sprintf(buffer, "%d ended correctly", pid_hijo);
            write(2, buffer, strlen(buffer));
            for(int i = 0; i < pos; i++){
                kill(hijos_pids[i], SIGKILL);
            }
            nfi = 0;
            exit(0);
        }else{
            sprintf(buffer,"El proceso %d termina con exit code %d\n", getpid(),statcode);
            write(2,buffer,strlen(buffer));
        }
    }
    else {
        signcode = WTERMSIG(exit_code);
        sprintf(buffer,"El proceso %d termina por el signal %d\n", getpid(),
        signcode);
        write(2,buffer,strlen(buffer));
        return 0;
    }
}
void tratar_hijos(){
    int exit_code = 0;
    int pid_hijo = waitpid(-1, &exit_code, 0);
    tratar_exit(exit_code, pid_hijo);
}
int main(int argc, char *argv[]){
    if(argc != 3){
        Usage();
    }
    int n = atoi(argv[1]);
    int pid = 0;
    //hijos_pids(n, 0);^
    sigset_t mask;
    sigemptyset (&mask);
    sigaddset (&mask, SIGCHLD);
    
    sigprocmask (SIG_BLOCK, &mask, NULL); //block signal hijo
    
    struct sigaction sa;
    sa.sa_handler = &tratar_hijos;
    sa.sa_flags = SA_RESTART;
    sigfillset(&sa.sa_mask);
    
    
    //const struct sigaction sb = sa;
    sigaction(SIGCHLD, &sa, NULL);
    
    for(int i = 0; i < n && nfi; i++){
        pid = fork();
        if (pid == 0){
            execlp("./hijo1", "./hijo1", argv[2], (char*)NULL);
            error("execlp", 0);
        }else if (pid < 0){
            error("fork", 0);
        }else{
            hijos_pids[pos] = pid;
            pos++;
        }
        
    }
    /*
    sigfillset (&mask);
    sigdelset (&mask, SIGCHLD);
    sigsuspend (&mask);*/
    int exi = 0;
    int pid_hijo= 0;
    while((pid_hijo = waitpid(-1, &exi , 0)) > 0){
        tratar_exit(exi, pid_hijo);
    }
    char f[256];
    sprintf(f, "Incalculable");
    write(2, f, strlen(f));
}
