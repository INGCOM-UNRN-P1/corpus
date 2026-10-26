


#include <stdio.h>
#include "mis_funciones.h"

#define MAX_DIGITOS  10
#define BASE_DECIMAL 10

typedef struct division {
    long int cociente;
    long int resto;
} division_t;


long int division_lenta(long int dividendo, long int divisor) {
    long int cociente = 0;
    long int signo = 1;

    if (dividendo < 0) {
        signo = -signo;
        dividendo = -dividendo;
    }
    if (divisor < 0) {
        signo = -signo;
        divisor = -divisor;
    }

    while (dividendo >= divisor) {
        cociente = cociente + 1;
        dividendo = dividendo - divisor;
    }

    return cociente * signo;
}


long int resto_lento(long int dividendo, long int divisor) {
    long int signo = 1;

    if (dividendo < 0) {
        signo = -signo;
        dividendo = -dividendo;
    }
    if (divisor < 0) {
        divisor = -divisor;
    }

    while (dividendo >= divisor) {
        dividendo = dividendo - divisor;
    }

    return dividendo * signo;
}


int	cociente_y_resto(division_t* resultado, long int numerador, long int denominador) {
    resultado->cociente = division_lenta(numerador, denominador);
    resultado->resto    = resto_lento(numerador, denominador);

    return OK;
}

int main()
{
    long int numero[2];
    division_t resultado;
    char entrada[MAX_DIGITOS + 1] = {"\0"};

    printf("Ingrese dos numeros enteros de a uno, el segundo debe ser distinto de 0\n");
    for (int i = 0; i < 2; i++) {
        printf("\t%d: ", i + 1);
        if (ingreso_sin_newline(entrada, sizeof(entrada), stdin)) {
            printf("\n*** Error en ingreso de numero entero\n");
            return (-1);
        }
        if (parse_long(entrada, &numero[i], BASE_DECIMAL) || (i == 1 && numero[i] == 0)) {
            printf("\n*** Debe ingresar un numero entero distinto de 0\n");
            return (-1);
        }
    }

    cociente_y_resto(&resultado, numero[0], numero[1]);
    printf("* Cociente de la division lenta: %ld\n* Resto de la division lenta: %ld\n",
           resultado.cociente, resultado.resto);

    return 0;
}
