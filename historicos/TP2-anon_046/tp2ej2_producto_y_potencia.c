/*************************
Ingenieria en Computacion - UNRN Andina
Programacion 1
anon_046 de GitHub
*************************/
#include <stdio.h>
#include <stdlib.h>
#include "mis_funciones.h"

#define MAX_DIGITOS 10

int producto(int factor1, int factor2){
    return factor1 * factor2;
}

int potencia(int base, int exponente){
    int resultado = 1;

    while (exponente > 0){
        resultado = producto(resultado, base);
	exponente -= 1;
    }

    return resultado;
}

int ingreso_de_entero(const char *mensaje){
    long int entero;
    char entrada[MAX_DIGITOS + 1] = {"\0"};

    printf("%s: ", mensaje);
    if (ingreso_sin_newline(entrada, sizeof(entrada), stdin)){
        printf("\n*** Error en ingreso de numero entero\n");
        exit (-1);
    }
    if (parseLong(entrada, &entero, 10) || entero < 0){
        printf("\n*** Debe ingresar un numero entero positivo\n");
        exit (-1);
    }

    return entero;
}

int main(int argc, char *argv[])
{

    long int numero1, numero2;

    printf("Para realizar el producto\n");
    numero1 = ingreso_de_entero("\tIngrese el primer factor");
    numero2 = ingreso_de_entero("\tIngrese el segundo factor");
    printf("El producto entre %ld y %ld es: %ld\n\n", 
            numero1, numero2, producto(numero1, numero2));

    printf("Para realizar la potencia\n");
    numero1 = ingreso_de_entero("\tIngrese la base");
    numero2 = ingreso_de_entero("\tIngrese el exponente");
    printf("La potencia de %ld elevado a %ld es: %ld\n\n", 
            numero1, numero2, potencia(numero1, numero2));

    return 0;
}
