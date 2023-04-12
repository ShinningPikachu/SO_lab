#include <stdio.h>
#include <string.h>
#include <unistd.h>
int main(){
    char buf[60];
    sprintf(buf, "joc de proves \n");
    write(1,buf,strlen(buf));
}
