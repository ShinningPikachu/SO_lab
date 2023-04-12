#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]){ 
char buf[80];
int n = 0;
int i =0;
while(*argv[i] != '\0'){
if (argv[i] == '.' or argv[i] == '\n' or argv[i] == ',' or argv[i] == ' '){
n++;
}
i++;
}
n++;
sprintf (buf, "%d palabras", n);
write (1, buf, strlen (buf));
}
