/*************************
Ingenieria en Computacion - UNRN Andina
Programacion 1
anon_046 de GitHub
*************************/
#include <stdio.h>
#include "mis_funciones.h"

#define MAX_DIGITOS 10

int es_primo(int numero){
    int divisor, tope;

    
    if (numero == 2)
        return 1;

    
    if (!(numero % 2))
        return 0;

    
    divisor = 3;
    tope = numero;
    while (numero % divisor != 0 && tope >= divisor){
        tope = numero / divisor;
	divisor += 2;
    }
    if (tope < divisor)
        return 1;
    return 0;
}

int main(int argc, char *argv[])
{
    long int numero;
    char entrada[MAX_DIGITOS + 1] = {"\0"};

    printf("Ingrese un numero natural: ");
    if (ingreso_sin_newline(entrada, sizeof(entrada), stdin)){
        printf("\n*** Error en ingreso de numero\n");
        return (-1);
    }
    if (parseLong(entrada, &numero, 10) || numero <= 0){
        printf("\n*** Debe ingresar un numero natural\n");
        return (-1);
    }

    printf("El numero %ld%s es primo\n",
            numero, es_primo(numero)?" si":" no");

    return 0;
}
