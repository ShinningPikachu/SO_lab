#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>


void error_exit(const char error[], const int exitstatus){
	perror(error);
	exit(exitstatus);
}

void main(int argc, char *argv[])
{
	int fd[2];

	if(pipe(fd) == -1)
	{
		error_exit("Error pipe.\n", 1);
	}

	int id = fork();

	if(id == -1)
	{
		error_exit("Error fork.\n", 1);
	}
	else if(id == 0)
	{
		close(0);
		dup(fd[0]);

		close(fd[0]);
		close(fd[1]);

		execlp("cat", "cat", (char*)NULL);

		error_exit("Error on execlp.\n", 1);
	}
	else
	{
		char buff[80];
		sprintf(buff, "Inicio\n");
		write(fd[1], &buff, strlen(buff));

		close(fd[1]);

		int exit_status;
		waitpid(-1, &exit_status, 0);

		sprintf(buff, "Fin\n");
		write(1, buff, strlen(buff2));
	}
}

