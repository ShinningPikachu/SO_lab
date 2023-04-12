

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "mis_funciones.h"

#define MAX_SIZE 8
 
int main(int arg, char *a[])
{
if (arg == 1){
	usage();
	return 0;
	} 
char buf[80]; 
int res = 0;
for (int i = 1; i < arg; i++) {      
	if (!esNumero (a[i])) {
		sprintf (buf, "Error: el parámetro “%s” no es un número\n", a[i]);
		write (1, buf, strlen (buf));
		return -1;
	}
	else res += mi_atoi(a[i]);    
}
sprintf (buf, "La suma es %d\n", res);
write (1, buf, strlen (buf));
return 0;
}
