#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_SIZE 8
//Indica la funcionalidad de la programa en la pantalla
void usage();
//Comprueba si la cadena de entrada es un numero
int esNumero (char *str);
//Convierte en una letra char en int asumiendo que es un numero
unsigned int char2int (char c);
//Calcula y devuelve una cadena de char en un numero negativo o positivo
int mi_atoi(char *s);
