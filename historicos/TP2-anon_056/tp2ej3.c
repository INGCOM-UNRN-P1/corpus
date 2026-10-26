/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_056
*************************/

#include <stdio.h>

int factorial(int n)
{
    int factorial = 1;

    for (int i = 1; i <= n; i++)
    {
        factorial = (factorial*i);
    }

    return factorial;
}

int combinatorio(int n, int k)
{
    int combinatorio;

    if (k <= n)
    {
        combinatorio = factorial(n)/(factorial(k)*factorial(n-k));
        return combinatorio;
    }
    else
    {
        printf("El valor k es menor a n\n");
    }
}


int main(int argc, char const *argv[])
{
    int n;
    int k;
    int m;

    printf("Ingrese el valor n: ");
    scanf("%d", &n);
    printf("Ingrese el valor k: ");
    scanf("%d", &k);
    printf("Ingrese el valor m: ");
    scanf("%d", &m);

    printf("Factorial n => %d\n", factorial(n));
    printf("Combinatorio => %d\n", combinatorio(n,k));
    printf("Combinatorio m<n:\n");

    for (int i = 0; i < m; i++)
    {
        printf("%d\n", combinatorio(n, i));
    }
    
    return 0;
}
