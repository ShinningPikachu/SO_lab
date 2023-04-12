#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char *argv[]){
	int id = open("a", O_RDONLY);

	char i;
	while(read(id, &i, sizeof(char)) > 0)
		write(1, &i, sizeof(char));
}
