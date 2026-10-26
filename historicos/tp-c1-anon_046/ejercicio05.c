

#include <stdio.h>
#include "mis_funciones.h"

#define MAX_DIGITOS  10
#define BASE_DECIMAL 10


long int suma_lenta(long int numero1, long int numero2) {
    int signo;

    
    if (numero1 == 0) {
        return numero2;
    }
    if (numero2 == 0) {
        return numero1;
    }

    if (numero2 < 0) {
        signo = -1;
        numero2 = -numero2;
    } else {
        signo = 1;
    }

    while (numero2 > 0) {
        numero1 = numero1 + signo;
        numero2 = numero2 - 1;
    }

    return numero1;
}

int main()
{
    long int entero[2];
    char entrada[MAX_DIGITOS + 1] = {"\0"};

    printf("Ingrese dos numeros naturales de a uno\n");
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

    printf("Resultado de suma lenta de %ld + %ld = %ld\n", entero[0],
           entero[1], suma_lenta(entero[0], entero[1]));

    return 0;
}
