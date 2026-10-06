/**
 * @file main.c
 * @brief Programa principal del Ejercicio 2.
 */

#include <stdio.h>
#include "estadistica.h"

int main(void)
{
    printf("Ejercicio 2: Estadísticas con punteros\n");

    int arreglo[] = {10, 5, 20, 8, 15};
    size_t cantidad = sizeof(arreglo) / sizeof(*arreglo);

    int minimo;
    int maximo;
    double promedio;

    if (calcular_estadisticas(arreglo,
                               cantidad,
                               &minimo,
                               &maximo,
                               &promedio))
    {
        printf("Mínimo: %d\n", minimo);
        printf("Máximo: %d\n", maximo);
        printf("Promedio: %.2f\n", promedio);
    }

    size_t coincidencias;

    if (contar_en_rango(arreglo,
                        cantidad,
                        8,
                        15,
                        &coincidencias))
    {
        printf("Elementos entre 8 y 15: %zu\n", coincidencias);
    }

    return 0;
}