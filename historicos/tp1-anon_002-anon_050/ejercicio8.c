

#include <stdio.h>

int suma_rango(int n, int m)
{
    int i;
    int resultado = 0;
    for (i = n; i < m; i++)
    {
        resultado = resultado + i;
    }
    return resultado;
}

int main()
{
    int inicial;
    int final;
    int suma;
    printf("Ingrese la primer cota: ");
    scanf("%d\n", &inicial);
    printf("Ingrese la segunda cota: ");
    scanf("%d\n", &final);

    suma = suma_rango(inicial, final);
    printf("La suma es: %d", suma);
    return 0;
}