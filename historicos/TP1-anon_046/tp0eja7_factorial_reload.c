
#include <stdio.h>
#include "mis_funciones.h"

#define MAX_DIGITOS 10

long int factorial(long int numero){
    long int factorial = 1;

    while (numero > 1){
        factorial *= numero;
	numero--;
    }

    return factorial;
}

int main(int argc, char *argv[])
{
    long int entero, temp;
    char entrada[MAX_DIGITOS + 1] = {"\0"};

    printf("Ingrese el valor n: ");
    if (ingreso_sin_newline(entrada, sizeof(entrada), stdin)){
        printf("\n*** Error en ingreso de numero entero\n");
	return (-1);
    }
    if (parseLong(entrada, &entero, 10) || entero < 1){
        printf("\n*** Debe ingresar un numero entero positivo\n");
	return (-1);
    }

    while (entero >= 1){
        printf("El factorial de %ld!: %u\n", entero, factorial(entero));
	entero--;
    }

    return 0;
}
