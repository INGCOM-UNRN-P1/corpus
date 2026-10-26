



#include <stdio.h>

/**
 * Calcula el número de Fibonacci correspondiente a un índice dado.
 *
 * @pre n >= 0
 * @param n El índice del número de Fibonacci que se desea calcular.
 * @return El número de Fibonacci correspondiente al índice dado.
 */
int fibonacci(int n)
{
    int ret;
    if (n == 0)
    {
        ret = 0;
    }
    else if (n == 1)
    {
        ret = 1;
    }
    else 
    {
        ret = fibonacci(n - 1) + fibonacci(n - 2);
    }
    return ret;
}

/**
 * Calcula el factorial de un número dado.
 *
 * @pre n >= 0
 * @param n El número del que se desea calcular el factorial.
 * @return El factorial del número dado.
 */
int factorial(int n)
{
    int ret;
    if (n == 0)
    {
        ret = 1;
    }
    else
    {
        ret = n * factorial(n - 1);
    }
    return ret;
}

int main() 
{
    int n;
    printf("Ingrese el número a calcular:\n");
    scanf("%d", &n);
    printf("Fibonacci: fib(%d) = %d\n", n, fibonacci(n));
    printf("Factorial: %d! = %d\n", n, factorial(n));
    return 0;
}