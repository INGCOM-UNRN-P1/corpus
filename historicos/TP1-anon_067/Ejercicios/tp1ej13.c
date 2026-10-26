/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_067
*************************/
#include <stdio.h>

int esPrimo(int numero);

int main(int argc, char *argv[])
{
    int numero;

    printf("Ingrese un numero entero: ");
    scanf("%d", &numero);
    printf("esPrimo = %d\n", esPrimo(numero));
    if(esPrimo(numero))
        printf("El numero es primo\n");
    else
        printf("El numero no es primo\n");

    return 1;
}

int esPrimo(int numero)
{
    if(numero > 0)
        for(int i = 2; i < numero; i++)
            if(numero % i == 0)
                return 0;
    else if(numero < 0)
        for(int i = -2; i > numero; i--)
            if(numero % i == 0)
                return 0;
    return 1;
}
