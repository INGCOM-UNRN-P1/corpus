



#include <stdio.h>

/**
 * Calcula la potencia de un número dado.
 *
 * @pre exponente >= 0
 * @param base La base de la potencia.
 * @param exponente El exponente de la potencia.
 * @return El resultado de la potencia.
 */
int potencia(int base, int exponente)
{
    int ret;
    if (exponente == 0)
    {
        ret = 1;
    }
    else
    {
        ret = base * potencia(base, exponente - 1);
    }
    return ret;
}

/**
 * Calcula la suma de dos números.
 *
 * @pre b >= 0
 * @param a El primer número.
 * @param b El segundo número.
 * @return La suma de los dos números.
 */
int suma(int a, int b)
{
    int ret;
    if (b == 0)
    {
        ret = a;
    }
    else
    {
        ret = suma(a + 1, b - 1);
    }
    return ret;
}

/**
 * Calcula el producto de dos números.
 *
 * @pre b >= 0
 * @param a El primer número.
 * @param b El segundo número.
 * @return El producto de los dos números.
 */
int producto(int a, int b)
{
    int ret;
    if ( b == 0)
    {
        ret = 0;
    }
    else
    {
        ret = a + producto(a, b - 1);
    }
    return ret;
}

int main() 
{
    int a, b;
    printf("Ingrese el primer número:\n");
    scanf("%d", &a);
    printf("Ingrese el segundo número:\n");
    scanf("%d", &b);
    printf("Suma: %d+%d=%d\n", a, b, suma(a, b));
    printf("Producto: %d*%d=%d\n", a, b, producto(a, b));
    printf("Potencia: %d^%d=%d\n", a, b, potencia(a, b));
    return 0;
}