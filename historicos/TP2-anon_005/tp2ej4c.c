/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
Agostina Biagini - anon_005 en Github
Ejercicio 4 - Parte C - Triángulo de asteriscos
*************************/
#include <stdio.h>
#include <stdlib.h>

void triangulo_asterisco(int num);

int main(int argc, char *argv[])
{
    int numero;
    printf("Ingrese un numero mayor a 0: \n");
    scanf("%d",&numero);
    printf("numero: %d\n", numero);
    printf("\n");
    triangulo_asterisco(numero);
    printf("\n");

    return 0;
}

void triangulo_asterisco(int num)
{
    if (num >= 1)
    {
        for (int i = 1; i < num+1; i++)
        {
            printf("\n");
            for(int j=1; j<(num+2)-i; j++)
            {
                printf(" * ");	
            }
        }
    }
    else
    {
        printf("El numero ingresado no es valido");
    }
}