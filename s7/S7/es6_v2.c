#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <signal.h>
#include <string.h>

void func(int s) {
	char buf[128] = "recibido\n";
	write(1, &buf, strlen(buf));
}

int main(){
	struct sigaction sa;

	sa.sa_handler = &func;
	//sa.sa_flags = SA_RESTART;
	sigfillset(&sa.sa_mask);
	sigaction(SIGINT, &sa, NULL);


	char buff[256];
	char d;

	int ret = read(0, &d, sizeof(char));


	if (ret >= 0) {
		sprintf(buff, "read correcto\n");
		write(1,buff,strlen(buff));
	} else {
		if (errno == EINTR) {
			sprintf(buff, "read interrumpido por signal\n");
			write(1,buff,strlen(buff));
		} else {
			sprintf(buff, "read con error\n");
			write(1,buff,strlen(buff));
		}
	}
}
