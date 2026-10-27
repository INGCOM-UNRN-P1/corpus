
#include <stdio.h>
#include "mis_funciones.h"

#define MAX_DIGITOS 10

int main(int argc, char *argv[])
{
    long int entero;
    char entrada[MAX_DIGITOS + 1] = {"\0"};

    do {
        printf("Ingrese un numero n: ");
        if (ingreso_sin_newline(entrada, sizeof(entrada), stdin)){
            printf("\n*** Error en ingreso de numero entero\n");
	    return (-1);
        }
        if (parseLong(entrada, &entero, 10)){
            printf("\n*** Debe ingresar un numero entero\n");
	    return (-1);
        }

	if (entero < 101)
            printf("El numero es menor a 100.\n\n");

    } while (entero < 101);

    printf("El numero es mayor a 100.\n");

    return 0;
}
