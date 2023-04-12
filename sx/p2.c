#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int a, char *b[]){
    int i = 1;
    char buf[80];
    while (i < a){
        sprintf(buf, "entrada %s\n", b[i]);
        write(1, buf, strlen(buf));
        i++;
    }
}
