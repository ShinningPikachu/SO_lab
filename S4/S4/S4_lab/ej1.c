#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>




int main(){
/*sigset_t mask;
sigemptyset (&mask);
sigaddset (&mask, SIGALRM);
sigprocmask (SIG_BLOCK, &mask, NULL);
sigemptyset (&mask);
sigprocmask (SIG_SETMASK, &mask, NULL);*/
fork();
alarm (10);
execlp("./bucle", "bucle", (char*)NULL);
}
