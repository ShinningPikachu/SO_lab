#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
    /*int fd1 = open("ent", O_RDONLY);
    int fd2 = open("ext", O_WRONLY);
    char c;
    int pos_act= 0;
    int size = lseek(fd2, 0, SEEK_END);
    int n = read(fd1, &c, 256);
    lseek(fd2, -5, SEEK_CUR);
    write(fd2, &c, n);*/
    
    int fd1 = open("1", O_RDWR|O_CREAT, S_IRUSR|S_IWURS);
    int fd2 = open("2", O_RDWR|O_CREAT, S_IRUSR|S_IWURS);
    
    int fd[2];
    pipe(fd);
    
}
