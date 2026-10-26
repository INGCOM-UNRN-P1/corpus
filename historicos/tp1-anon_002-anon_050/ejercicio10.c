

#include <stdio.h>

long factorial(int numero)
{
    long i;
    long result = 1;
    for (i = 1; i <= numero; ++i) {
        result *= i;
    }
    return result;
}

int main()
{
    long n = 0;
    long resultado;
    printf("Ingreser un número: ");
    scanf("%u", &n);
    resultado = factorial(n);
    printf("El resultado es: %d\n", resultado);
    return 0;
}