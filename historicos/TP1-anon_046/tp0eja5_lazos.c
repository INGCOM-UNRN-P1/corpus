/*************************
Ingenieria en Computacion - UNRN Andina
Programacion 1
anon_046 de GitHub
*************************/
#include <stdio.h>
#include "mis_funciones.h"

#define MAX_DIGITOS 10

int main(int argc, char *argv[])
{
    long int entero1, entero2;
    int divisor;
    char entrada[MAX_DIGITOS + 1] = {"\0"};

    printf("primer numero: ");
    if (ingreso_sin_newline(entrada, sizeof(entrada), stdin)){
        printf("\n*** Error en ingreso de numero entero\n");
	return (-1);
    }
    if (parseLong(entrada, &entero1, 10)){
        printf("\n*** Debe ingresar un numero entero\n");
	return (-1);
    }
    printf("segundo numero: ");
    if (ingreso_sin_newline(entrada, sizeof(entrada), stdin)){
        printf("\n*** Error en ingreso de numero entero\n");
	return (-1);
    }
    if (parseLong(entrada, &entero2, 10)){
        printf("\n*** Debe ingresar un numero entero\n");
	return (-1);
    }

    if (entero1 > entero2){
        entero2 += entero1;
	entero1 = entero2 - entero1;
	entero2 = entero2 - entero1;
    }
    while (entero1 <= entero2){
        printf("%d\n", entero1);
	entero1++;
    }

    return 0;
}
