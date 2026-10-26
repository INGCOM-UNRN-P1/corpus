/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_014 de GitHub
**************************/
#include <stdio.h>

int factorial(int numero);

int main(int argc, char *argv[])
{
    int numero, otronumero, combinatorio;
    printf("Ingrese el Numero n: ");
    scanf("%d", &numero);
    printf("Ingrese el Numero k: ");
    scanf("%d", &otronumero);     
    
    if (otronumero < numero)
    {
       combinatorio = factorial(numero)/(factorial(otronumero)*factorial(numero-otronumero)); 
    }
    else
    {
        printf("El numero k no es menor al numero n\n");
    }
    printf("El combinatorio es: %d", combinatorio);
    
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