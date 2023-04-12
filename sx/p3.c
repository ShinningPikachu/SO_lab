#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>

int main(int a, char*b[]){
    char buff[256];
    for(int i = 1; i < a; i++){
        sprintf(buff, "n %c \n", b[i]);
        write(1, buff, strlen(buff));
    }
}
