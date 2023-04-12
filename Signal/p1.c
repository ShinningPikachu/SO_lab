#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
void func(){
    printf("gg \n");
}

int main(int a, char *b[]){
    
    struct sigaction trat;
    
    sigset_t mask;
    
    sigemptyset(&mask);//mask vacia a 0;
    
    trat.sa_flags = 0; //usar la configuracion por defecto
    
    trat.sa_handler = func; //Tratamiento de sigaction
    
    trat.sa_mask = mask;
    
    
    
    sigaction(SIGINT, &trat, NULL);
    sigaction(SIGTERM, &trat, NULL);
    
    while(1){
        printf("1 \n");
        sleep(5);
    }
}
