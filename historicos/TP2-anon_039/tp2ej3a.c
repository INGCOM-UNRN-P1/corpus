/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_039 de GitHub
*************************/
#include <stdio.h>

unsigned int factorial(int n);

int main(int argc, char *argv[])
{
    int n = 0;
    int resultado_factorial = 0;
    while(1)
    {
        printf("Ingrese el numero (n) : ");
        scanf("%d", &n);
        if (n > 0)
        {
            resultado_factorial = factorial(n);
            printf("El factorial de n (n!) es = %d", resultado_factorial);
            break;
        }
        else
        {
            printf("Ingrese un numero natural");
        }
    }
    
    return 0;
}

unsigned int factorial(int n)
{
    int i;
    int resultado = 1;
    
    for(i = 1;i <= n;i++)
    {
        resultado = resultado * i;
    }
    
    return resultado;
}