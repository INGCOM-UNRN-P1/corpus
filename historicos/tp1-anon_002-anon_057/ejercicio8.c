

#include <stdio.h>




int suma_rango(int n, int m)
{
    int suma = 0;
    if (n < m)
    {
        for (; n <= m; n++)
        {
            suma = suma + n;
        }
    }
    else if (n > m)
    {
        for (; m < n; m++)
        {
            suma = suma + m;
        }
    }
    else // n == m
    {
        suma = 0;
    }
    return suma;
}


int main() 
{
    int inicio = -5;
    int fin = 10;

    int resultado = suma_rango(inicio, fin);

    printf("La suma de los enteros en el rango [%d, %d) es: %d\n", inicio, fin, resultado);

    return 0;
}
