
#include <stdio.h>

int fibonacci(int n)
{
    volatile int retorno;

    if(n == 0)
    {
        retorno = 0;
    }
    else
    {
        if(n == 1)
        {
            retorno = 1;
        }
        else
        {
            retorno = fibonacci(n - 1) + fibonacci(n - 2);
        }
    }
    return retorno;
}

int main()
{
    volatile int numero = 0, i = 1;
    volatile int j;

    while(numero < 100)
    {
        printf("Ingrese un numero entero mayor a 100: ");
        scanf("%d", &numero);
    }

    while(fibonacci(i) < numero)
    {
        i++;
    }

    printf("Los numeros de la sucesion de fibonacci menor a %d son: ", numero);

    for(j = 0; j < i; j++)
    {
        printf("%d, ", fibonacci(j));
    }

    printf("\n");
    return 0;
}
