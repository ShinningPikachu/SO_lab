#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

int main(){
    sigset_t mask;
    
    sigemptyset(&mask);
    sigaddset(&mask, SIGINT);
    sigaddset(&mask, SIGALRM);
    sigprocmask(SIG_BLOCK, &mask, NULL);
    
    int i = fork();
    
    alarm(10);
    
    if(i == 0){
    execlp("./bucle", "bucle", (char*)NULL);
    }
    
    sigfillset(&mask);
    sigdelset(&mask, SIGALRM);
    sigdelset(&mask, SIGINT);
    sigsuspend(&mask);
    
    while(1);
}
