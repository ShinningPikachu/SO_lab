

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int arg,char *a[])
{
char buf[80];
	for (int i=0;i<arg;i++){
		if (i==0){
			sprintf(buf,"El argumento %d es %s (es el nombre del ejecutable)\n",i,a[i]);
		}else{
			sprintf(buf,"El argumento %d es %s\n",i,a[i]);
		}
		write(1,buf,strlen(buf));
	}
	return 0;
}
