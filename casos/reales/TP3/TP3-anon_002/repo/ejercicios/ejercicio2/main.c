/**
 * @file main.c
 * @brief Programa principal del Ejercicio 2.
 */

#include <stdio.h>
#include "estadistica.h"

int main(void)
{
    printf("Ejercicio 2: Estadisticas con punteros\n");

    int datos[] = {10, 20, 30, 40};
    size_t cantidad = 4;

    int minimo = 0;
    int maximo = 0;
    double promedio = 0.0;

    obtener_min_max(datos, cantidad, &minimo, &maximo);

    printf("Minimo: %d\n", minimo);
    printf("Maximo: %d\n", maximo);

    calcular_estadisticas(datos, cantidad, &minimo, &maximo, &promedio);

    printf("Minimo: %d\n", minimo);
    printf("Maximo: %d\n", maximo);
    printf("Promedio: %.2f\n", promedio);

    return 0;
}