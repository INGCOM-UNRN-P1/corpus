/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_056
*************************/

#include <stdio.h>

int linea(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("*");
    }
}

int cuadrado(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int y = 0; y < n; y++)
        {
            printf("*");
        }
        printf("\n");  
    }
}

int triangulo(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int x = 1; x <= i; x++)
        {
            printf("*");
        }
        printf("\n");    
    }

}


int main(int argc, char const *argv[])
{

    int n;

    printf("Ingrese valor n: ");
    scanf("%d", &n);

    linea(n);
    printf("\n\n");
    cuadrado(n);
    printf("\n");
    triangulo(n);

    return 0;
}
