

#include <stdio.h>



int fibonacci(int numero)
{
    int i = 0;
    int a = 0;
    int b = 1;
    int suma_anteriores = 0;
    int suma_digitos = 0;

    while(i < numero)
    {
        suma_digitos = suma_digitos + a;

        suma_anteriores = a + b;
        a = b;
        b = suma_anteriores;

        i++;
    }

    return suma_digitos;
}

int main()
{
    int numero;
    int resultado;

    printf("Ingrese el limite para la suma de la serie de fibonacci: ");
    scanf("%d", &numero);

    resultado = fibonacci(numero);

    printf("El resultado es: %d", resultado);

    return 0;
}