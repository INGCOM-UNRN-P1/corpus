/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_039 de GitHub
*************************/
#include <stdio.h>

void linea(int n);
void cuadrado(int n);
void triangulo_rectangulo(int n);

int main(int argc, char *argv[])
{
    int n = 0;
    while(1)
    {
        printf("Ingrese un numero para crear una linea, un cuadrado y un triangulo rectangulo de asteriscos de esa longitud/altura: ");
        scanf("%d", &n);
        if(n > 0)
        {
            printf("\nLINEA\n");
            linea(n);
            printf("\nCUADRADO\n");
            cuadrado(n);
            printf("\nTRIANGULO RECTANGULO\n");
            triangulo_rectangulo(n);
            break;
        }
        else
        {
            printf("El numero no puede ser negativo ni 0");
        }
    }
    return 0;
}

void linea(int n)
{
    int i;
    
    for(i = 0; i < n ; i = i + 1)
    {
        printf("*");
    }
}

void cuadrado(int n)
{
    int i;
    int j;
    
    for(i = 0; i < n ; i = i + 1)
    {
        for(j = 0; j < n ; j = j + 1)
        {
            printf("*");
        }
        printf("\n");
    }
}

void triangulo_rectangulo(int n)
{
    int i;
    int j;
    int lado = 1;
    
    for(i = 1; i <= n ; i = i + 1)
    {
        for(j = 1; j <= lado ; j = j + 1)
        {
            printf("*");
        }
        
        printf("\n");
        lado = lado + 1;
    }
}