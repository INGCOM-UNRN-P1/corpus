

#include <stdio.h>
#include "mis_funciones.h"

#define MAX_DIGITOS  10
#define BASE_DECIMAL 10


int signo(long int entero)
{
    if (entero - entero == 0 && entero + entero == 0) {
        return 0;
    }
    if (entero + entero > 0) {
        return 1;
    }

    return -1;
}

int main()
{
    long int resultado, entero;
    char entrada[MAX_DIGITOS + 1] = {"\0"};

    printf("Ingrese el numero entero para ver su signo: ");
    if (ingreso_sin_newline(entrada, sizeof(entrada), stdin)) {
        printf("\n*** Error en ingreso de datos\n");
        return (-1);
    }
    if (parse_long(entrada, &entero, BASE_DECIMAL)) {
        printf("\n*** Debe ser un numero entero (largo)\n");
        return (-1);
    }

    resultado = signo(entero);
    switch(resultado) {
    case 0:
        printf("\n* El numero %ld es: cero\n", entero);
        break;
    case 1:
        printf("\n* El numero %ld es: positivo\n", entero);
        break;
    default:
        printf("\n* El numero %ld es: negativo\n", entero);
        break;
    }

    return 0;
}
