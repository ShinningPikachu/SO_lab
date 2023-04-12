#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define MAX_SIZE 8
int esNumero(char *str){
if (str==NULL){
return 0;
}
if (*str == '-')
{
str++;
}
int g = 0;
while (str[g] != '\0'){
if (str[g] < '0' || str[g] > '9' || g > MAX_SIZE){
return 0;
}
g++;
}
return 1;
}


int main(int argc, char *argv[]){
char buf[80];
for(int i = 1; i < argc; i++){
if (esNumero(argv[i]) ){
sprintf(buf, "%s es un numero\n", argv[i]);
}else{
sprintf(buf, "%s es no es un numero\nS", argv[i]);
}
write(1, buf, strlen(buf));
}

return 0;

}
