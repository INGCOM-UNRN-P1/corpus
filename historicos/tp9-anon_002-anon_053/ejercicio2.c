

#include <stdio.h>

int fibonacci(int numero);
int factorial(int numero);

int main() 
{
    int numero = 0;

    printf("Ingrese un número positivo para calcular: ");
    scanf("%d", &numero);

    printf("El valor de fibonacci(%d) es: %d\n numero", numero, fibonacci(numero));
    printf("El valor de factorial(%d) es: %d\n numero", numero, factorial(numero));

    return 0;
}


int fibonacci(int numero) 
{
    if (numero == 0)//caso base 1 
    {
        return 0;
    }
    else if (numero == 1)//caso base 2 
    {
        return 1;
    } 
    else 
    {
        return fibonacci(numero - 1) + fibonacci(numero - 2);
    }
}


int factorial(int numero) 
{
    if (numero == 0)// caso base 
    {
        return 1;
    } 
    else 
    {
        return numero * factorial(numero - 1);
    }
}

