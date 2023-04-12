#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
int main (int argu, char *argv[]){
    char buff[80];
    int calls = 0;
    int i = 1;
    while(argv[i] != '\0'){
        int g = i;
        while(argv[i] != '\0'){
            i++;
        }
        calls++;
        int pid = frok();
        if (pid == 0){
            muta_a_touch(argv[g]);
        }else if (pid == -1){
            error_y_exit("Error en crear el hijo", -1);
        }
        i++;
    }
    for(int i = 0; i < calls; i++){
        int f = waitpid(-1);
        sprintf(buff, "Fecha %s actualizada por %n\n", )
    }
}

void muta_a_touch(char *file)
{
 execlp("touch", "touch", file, (char*)NULL);
 error_y_exit("Ha fallado la mutación al touch", 1);
}

void error_y_exit(char *msg,int exit_status)
{
perror(msg);
exit(exit_status);
}

void usage(){
    char buff[256];
    sprintf
}
