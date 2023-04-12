#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void error_y_exit(char *msg,int exit_status)
{
perror(msg);
exit(exit_status);
}
int main(int arg, char *argu[]){
int i = fork();
char buf[60];
if (arg != 2){
error_y_exit("error: debe especificar al menos un paràmtro", -1);
}
if(i == -1){
error_y_exit("Error en fork", 1);
}
sprintf(buf, "Soy proceso con pid %d\n", getpid());
write(1, buf, strlen(buf));
if (i == 0){
i = getpid();
sprintf(buf, "Soy el hijo con pid %d y me llamo %s\n", i, argu[1]);
write(1, buf, strlen(buf));
}
while(1);
}
