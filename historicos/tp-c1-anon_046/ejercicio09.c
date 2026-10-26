

#include <stdio.h>
#include "mis_funciones.h"

#define MAX_DIGITOS  10
#define BASE_DECIMAL 10
#define False 0
#define True  1


int es_multiplo(long int numero, long int multiplo) {

    
    if (numero == 0 || multiplo == 0) {
        return False;
    }
    
    if (numero < 0) {
        numero = -numero;
    }
    if (multiplo < 0) {
        multiplo = -multiplo;
    }

    while (numero > 0) {
        numero -= multiplo;
    }
    if (numero == 0) {
        return True;
    }

    return False;
}

int main()
{
    long int entero[2];
    char entrada[MAX_DIGITOS + 1] = {"\0"};

    printf("Ingrese dos numeros enteros de a uno\n");
    for (int i = 0; i < 2; i++) {
        printf("\t%d: ", i + 1);
        if (ingreso_sin_newline(entrada, sizeof(entrada), stdin)) {
            printf("\n*** Error en ingreso de numero entero\n");
            return (-1);
        }
        if (parse_long(entrada, &entero[i], BASE_DECIMAL)) {
            printf("\n*** Debe ingresar un numero entero\n");
            return (-1);
        }
    }

    if (es_multiplo(entero[0], entero[1])) {
        printf("%ld es multiplo de %ld\n", entero[1], entero[0]);
    } else if(es_multiplo(entero[1], entero[0])) {
        printf("%ld es multiplo de %ld\n", entero[0], entero[1]);
    } else printf("%ld y %ld no son multiplos entre si\n", entero[0], entero[1]);

    return 0;
}
