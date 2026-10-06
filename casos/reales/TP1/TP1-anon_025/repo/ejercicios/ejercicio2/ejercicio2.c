

#include <stdio.h>
#include "ejercicio2.h"

int fibonacci(int n)
{
    if (n < 0)
    {
        return -1;
    }
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int suma_fibonacci(int n)
{
    int suma = 0;

    if (n < 0)
    {
        return -1;
    }
    for(int i = 0; i <= n; i++)
    {
        suma = suma + fibonacci(i);
    }
    return suma;
}