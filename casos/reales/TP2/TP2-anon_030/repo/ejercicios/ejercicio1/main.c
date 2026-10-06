#include <stdio.h>
#include "operaciones.h"
#include "arreglos.h"

int main(void)
{
    int numeros[] = {12, 45, -3, 8, 27, 4};
    size_t cantidad = sizeof(numeros) / sizeof(numeros[0]);

    printf("=== Ejercicio 1: Demo de Arreglos ===\n");

    printf("Arreglo original: ");
    for (size_t posicion = 0; posicion < cantidad; ++posicion)
    {
        printf("%d ", numeros[posicion]);
    }
    printf("\n");

    long long suma = arreglo_sumar(numeros, cantidad);
    double promedio = calcular_promedio(numeros, cantidad);
    bool ordenado = arreglo_ordenado(numeros, cantidad);
    size_t apariciones = arreglo_contar(numeros, cantidad, 8);

    printf("Suma: %lld\n", suma);
    printf("Promedio: %.2f\n", promedio);
    printf("Ordenado ascendentemente: %s\n", ordenado ? "si" : "no");
    printf("Apariciones de 8: %zu\n", apariciones);

    arreglo_invertir(numeros, cantidad);

    printf("Invertido: ");
    for (size_t posicion = 0; posicion < cantidad; ++posicion)
    {
        printf("%d ", numeros[posicion]);
    }
    printf("\n");

    return 0;
}