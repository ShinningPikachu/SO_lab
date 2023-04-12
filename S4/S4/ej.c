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
    
    alarm(10);
    
    while(1);
}
