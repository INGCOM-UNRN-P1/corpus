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
    long int entero;
    long int anterior = 0;
    long int fibonacci = 1;
    char entrada[MAX_DIGITOS + 1] = {"\0"};

    printf("Ingrese un numero entero mayor a 10: n: ");
    if (ingreso_sin_newline(entrada, sizeof(entrada), stdin)){
        printf("\n*** Error en ingreso de numero entero\n");
	return (-1);
    }
    if (parseLong(entrada, &entero, 10) || entero <= 10){
        printf("\n*** Debe ingresar un numero entero mayor a 10\n");
	return (-1);
    }

    printf("Los numeros de la sucesion de fibonacci menor a %ld son: 0", entero);
    while (fibonacci < entero){
        printf(", %ld", fibonacci);
	fibonacci += anterior;
	anterior = fibonacci - anterior;
    }
    printf("\n");

    return 0;
}
