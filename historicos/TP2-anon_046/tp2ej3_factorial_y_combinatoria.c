
#include <stdio.h>
#include <stdlib.h>
#include "mis_funciones.h"

#define MAX_DIGITOS 10


int factorial(int numero){
    int resultado = numero;

    while (numero > 2)
        resultado *= --numero;

    return resultado;
}


int combinatoria(int total, int elementos){

    return factorial(total) / 
                ( factorial(elementos) * factorial(total-elementos) );
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

    printf("Para realizar factorial y combinatoria\n");
    numero1 = ingreso_de_entero("\tIngrese el total de elementos");
    numero2 = ingreso_de_entero(
              "\tIngrese la cantidad de elementos a combinar");

    printf("\n%ld! = %ld\n\n", 
            numero1, factorial(numero1));
    printf("La combinatoria de %ld elementos elegidos entre %ld es: %ld\n\n", 
            numero2, numero1, combinatoria(numero1, numero2));
    for (numero2 = numero1 - 1; numero2 > 0; numero2--)
        printf("La combinatoria de %ld elementos elegidos entre %ld es: %ld\n", 
            numero2, numero1, combinatoria(numero1, numero2));

    return 0;
}
