/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_014 de GitHub
**************************/
#include <stdio.h>

char asteriscos(int cantidad);

int main(int argc, char *argv[])
{    
    int numero;
    printf("Ingrese el Numero n: ");
    scanf("%d", &numero);
    asteriscos(numero);
    return 0;
}

char asteriscos(int cantidad)
{    
    for (int i=0; i < cantidad; i++)
    {
        printf("*");
    }
    return 0;
}
