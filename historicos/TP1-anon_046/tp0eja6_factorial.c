
#include <stdio.h>
#include "mis_funciones.h"

#define MAX_DIGITOS 10

int main(int argc, char *argv[])
{
    long int entero, temp;
    unsigned int factorial = 1;
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

    temp = entero;
    while (temp > 1){
        factorial *= temp;
	temp--;
    }
    printf("El factorial de %ld!: %u\n", entero, factorial);

    return 0;
}
