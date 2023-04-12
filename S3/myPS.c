
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void error_y_exit(char *msg,int exit_status)
{
perror(msg);
exit(exit_status);
}
void muta_a_PS(char *username)
{
 execlp("ps", "ps", "-u", username, (char*)NULL);
 error_y_exit("Ha fallado la mutación al ps", 1);
}

int main(int arg, char *argu[]){
int i = fork();
char buf[60];
if (arg != 2){
error_y_exit("error: debe especificar al menos un paràmtro", -1);
}
if(i == -1){
error_y_exit("Error en fork", -1);
}
sprintf(buf, "Soy proceso con pid %d\n", getpid());
write(1, buf, strlen(buf));
if (i == 0){
i = getpid();
sprintf(buf, "Soy el hijo con pid %d y me llamo %s\n", i, argu[1]);
write(1, buf, strlen(buf));
muta_a_PS(argu[1]);
}
while(1);
}
