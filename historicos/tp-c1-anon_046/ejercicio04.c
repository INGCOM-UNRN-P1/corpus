

#include <stdio.h>
#include "mis_funciones.h"

#define MAX_DIGITOS  10
#define BASE_DECIMAL 10


int compara(long int entero1, long int entero2)
{
    if (entero1 - entero2 == 0) {
        return 0;
    }
    if (entero1 - entero2 > 0) {
        return 1;
    }

    return -1;
}

int main()
{
    long int resultado, entero1, entero2;
    char entrada[MAX_DIGITOS + 1] = {"\0"};


    printf("Ingrese el primer numero entero para comparar: ");
    if (ingreso_sin_newline(entrada, sizeof(entrada), stdin)) {
        printf("\n*** Error en ingreso de datos\n");
        return (-1);
    }
    if (parse_long(entrada, &entero1, BASE_DECIMAL)) {
        printf("\n*** Debe ser un numero entero (largo)\n");
        return (-1);
    }

    printf("Ingrese el segundo numero entero para comparar: ");
    if (ingreso_sin_newline(entrada, sizeof(entrada), stdin)) {
        printf("\n*** Error en ingreso de datos\n");
        return (-1);
    }
    if (parse_long(entrada, &entero2, BASE_DECIMAL)) {
        printf("\n*** Debe ser un numero entero (largo)\n");
        return (-1);
    }

    resultado = compara(entero1, entero2);
    printf("%ld\n", resultado);

    return 0;
}
