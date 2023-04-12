#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

void recive_alarm(){
	printf("alarm!!!\n");
	//write(1, buff, strlen(buff));
}

int main(int a, char* b[]){

struct sigaction sa;

sa.sa_handler = &recive_alarm;
sa.sa_flags = 0;
sigfillset (&sa.sa_mask);
sigaction (SIGALRM, &sa, NULL);


char buff[60];
sprintf(buff, "enter bucle\n");
write(1, buff, strlen(buff));

while (1);


}
