

#include <stdio.h>

int suma_lenta(int numero, int otronumero)
{
    int i;
    for (i = 0; i < otronumero; ++i)
    {
        numero++;
    }
    return numero;
}

int main()
{
    int valor_a, valor_b;
    printf("Ingrese el primer número, debe ser entero positivo: ");
    scanf("%d", &valor_a);
    if (valor_a < 0)
        {
            printf("Entrada incorrecta.\n");
            return 1;
        }
    printf("Ingrese el segundo número, debe ser entero positivo: ");
    scanf("%d", &valor_b);
    if (valor_b < 0)
        {
            printf("Entrada incorrecta.\n");
            return 1;
        }

    printf("El resultado es: %d\n", suma_lenta(valor_a, valor_b));
    return 0;
}