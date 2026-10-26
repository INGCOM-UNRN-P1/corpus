

#include <stdio.h>
#include "mis_funciones.h"

#define MAX_DIGITOS  10
#define BASE_DECIMAL 10
#define MIN_NATURAL   1
#define MAX_NATURAL  33


unsigned int factorial(long int entero) {
    unsigned int factorial = 1;
    while (entero > 1) {
        factorial *= entero;
        entero--;
    }

    return factorial;
}

int main()
{
    long int entero;
    char entrada[MAX_DIGITOS + 1] = {"\0"};

    printf("Ingrese el valor n: ");
    if (ingreso_sin_newline(entrada, sizeof(entrada), stdin)) {
        printf("\n*** Error en ingreso de numero natural\n");
        return (-1);
    }
    if (parse_long(entrada, &entero, BASE_DECIMAL) || entero < MIN_NATURAL || entero > MAX_NATURAL) {
        printf("\n*** Debe ingresar un numero positivo menor a %d\n", MAX_NATURAL + 1);
        return (-1);
    }

    printf("El factorial de %ld!: %u\n", entero, factorial(entero));

    return 0;
}
