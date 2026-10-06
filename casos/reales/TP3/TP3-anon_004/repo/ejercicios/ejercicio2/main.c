/**
 * @file main.c
 * @brief Programa principal del Ejercicio 2.
 */

#include <stdio.h>
#include "estadistica.h"

int main(void)
{
    int lista[6] = {15, -4, 28, 0, 7, -10};
    int minimo = 0;
    int maximo = 0;
    double promedio = 0.0;
    int inf = 0;
    int sup = 0;
    size_t cantidad = 0;
    bool estado = false;

    printf("--- Ejercicio 2: Estadisticas y Rango ---\n\n");
    printf("Arreglo base: {15, -4, 28, 0, 7, -10}\n");

    estado = calcular_estadisticas(lista, 6, &minimo, &maximo, &promedio);
    if (estado)
    {
        printf("Minimo: %d\n", minimo);
        printf("Maximo: %d\n", maximo);
        printf("Promedio: %.2f\n\n", promedio);
    }

    printf("Ingrese limite inferior: ");
    if (scanf("%d", &inf) != 1)
    {
        return 1;
    }
    printf("Ingrese limite superior: ");
    if (scanf("%d", &sup) != 1)
    {
        return 1;
    }

    estado = contar_en_rango(lista, 6, inf, sup, &cantidad);
    if (estado)
    {
        printf("Elementos en rango [%d, %d]: %zu\n", inf, sup, cantidad);
    }
    else
    {
        printf("Error: limites invalidos.\n");
    }

    return 0;
}
