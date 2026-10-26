/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_014 de GitHub
**************************/
#include <stdio.h>

char asteriscos(int lado);

int main(int argc, char *argv[])
{
    int numero;
    printf("Introduzca el lado del cuadrado: ");
    scanf("%d", &numero);
    
    asteriscos(numero);
    return 0;
    
}

char asteriscos(int lado)
{
    for(int i=1; i <= lado; i ++)
    {
        for(int j=1; j<=lado;j++)
        {
            if(i==1 || i==lado || j==1 || j==lado)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }                
        }
        printf("\n");
    }
    return 0;
}