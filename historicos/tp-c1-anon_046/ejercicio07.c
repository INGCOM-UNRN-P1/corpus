

#include <stdio.h>
#include "mis_funciones.h"

#define TRUE  1
#define FALSE 0
#define MAX_DIGITOS  10
#define BASE_DECIMAL 10


int es_primo(int numero) {
    int divisor, tope;

    
    if (numero == 2)
        return TRUE;

    
    if (!(numero % 2))
        return FALSE;

    
    divisor = 3;
    tope = numero;
    while (numero % divisor != 0 && tope >= divisor) {
        tope = numero / divisor;
        divisor += 2;
    }
    if (tope < divisor)
        return TRUE;
    return FALSE;
}

int main()
{
    long int numero;
    char entrada[MAX_DIGITOS + 1] = {"\0"};

    printf("Ingrese un numero natural: ");
    if (ingreso_sin_newline(entrada, sizeof(entrada), stdin)) {
        printf("\n*** Error en ingreso de numero\n");
        return (-1);
    }
    if (parse_long(entrada, &numero, BASE_DECIMAL) || numero <= 0) {
        printf("\n*** Debe ingresar un numero natural\n");
        return (-1);
    }

    printf("El numero %ld es primo? %s\n",
           numero, es_primo(numero)?"TRUE":"FALSE");

    return 0;
}
