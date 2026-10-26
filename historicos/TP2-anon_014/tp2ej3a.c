/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_014 de GitHub
**************************/
#include <stdio.h>

int factorial(int numero);

int main(int argc, char *argv[])
{
    int numero;
    printf("Ingrese el Numero n: ");
    scanf("%d", &numero);    
    printf("El factorial de %d es: %0d", numero, factorial(numero));
    
    return 0;
}

int factorial(int numero)
{
    int factorial;
    factorial = numero;
    while (numero > 1)
    {
        numero= numero-1;
        factorial = factorial*numero;
    }
    return factorial;
}