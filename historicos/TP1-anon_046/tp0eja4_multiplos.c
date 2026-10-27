
#include <stdio.h>
#include "mis_funciones.h"

#define MAX_DIGITOS 10

int main(int argc, char *argv[])
{
    long int entero;
    int divisor;
    char entrada[MAX_DIGITOS + 1] = {"\0"};

    printf("Ingrese un numero entero mayor a 100: A = ");
    if (ingreso_sin_newline(entrada, sizeof(entrada), stdin)){
        printf("\n*** Error en ingreso de numero entero\n");
	return (-1);
    }
    if (parseLong(entrada, &entero, 10) || entero < 101){
        printf("\n*** Debe ingresar un numero entero mayor a 100\n");
	return (-1);
    }

    for (divisor = 2; divisor < 7; divisor++){
        printf("Es multiplo de %d: %s\n", divisor, entero%divisor?"NO":"SI");
    }

    return 0;
}
