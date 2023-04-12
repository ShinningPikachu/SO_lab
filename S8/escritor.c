#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void main(int argc, char *argv[])
{
	int id = open("a", O_WRONLY);

	char g;
	while(read(0, &g, sizeof(char)) > 0)
	{
		write(id, &g, sizeof(char));
	}
}


