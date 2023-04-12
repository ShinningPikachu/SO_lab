include "mis_funciones.h"
void usage(){
	char buf[110];
	sprintf(buf,"Usage: suma arg1 arg2..argn\nEste programa escribe por su salida una suma de dos o mas numeros que recibe\n");
	write(1,buf,strlen(buf));
}
int esNumero (char *str)
{
	if (str == NULL)
   	 return 0;
	if (*str == '-')
  	  ++str;
	int i = 0;
	while (str[i] != '\0')
	{   
	if (!(str[i] >= '0' && str[i] <= '9') || i >= MAX_SIZE)
	return 0;
	++i;
	}
	return 1;
}
unsigned int char2int (char c){
	return c-'0'
}
int mi_atoi(char *s){
	int sum = 0;
	int n = 0;
	if (*s == '-') {
		++s;
		n = 1;
	}
	while (*s != '\0') {
		sum += char2int(*s);
		sum *= 10;
		s++;
	}
	sum = sum/10;

	if (n) return -n;
	else return n;
}

