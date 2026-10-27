
#include <stdio.h>
#include <stdlib.h>
#include "mis_funciones.h"

#define MAX_DIGITOS 10


int linea(int numero, const char caracter){

    while (numero > 0){
        printf("%c", caracter);
	numero--;
    }

    return 0;
}

int cuadrado(int numero, const char caracter){
    int lado = numero;

    linea(lado, caracter);
    printf("\n");
    while (numero > 2){
        numero--;
        printf("%c", caracter);
	linea(lado - 2, ' ');
        printf("%c\n", caracter);
    }
    linea(lado, caracter);

    return 0;
}

int triangulo_rectangulo(int numero, const char caracter){
    int lado = numero;

    linea(lado, caracter);
    printf("\n");
    lado -= 2;
    while (lado > 1){
        lado--;
        printf("%c", caracter);
	linea(lado, ' ');
        printf("%c\n", caracter);
    }
    printf("%c\n", caracter);

    return 0;
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

    long int numero;

    printf("Para formar una linea, un cuadrado y un triangulo rectangulo\n");
    numero = ingreso_de_entero("\tIngrese la cantidad de asteriscos del lado");

    printf("\n");
    linea(numero, '*');
    printf("\n\n");

    cuadrado(numero, '*');
    printf("\n\n");

    triangulo_rectangulo(numero, '*');
    printf("\n");

    return 0;
}
