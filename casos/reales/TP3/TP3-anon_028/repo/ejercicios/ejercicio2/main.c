/**
 * @file main.c
 * @brief Programa principal del Ejercicio 2.
 */

#include <stdio.h>
#include "estadistica.h"

int main(void)
{
    printf("Ejercicio 2: Estadísticas con punteros\n");

    int datos[] = {12, 5, 8, 20, 15, 3};
    size_t tam = sizeof(datos) / sizeof(datos[0]);

    int min, max;
    double prom;
    if (calcular_estadisticas(datos, tam, &min, &max, &prom)) {
        printf("Minimo: %d, Maximo: %d, Promedio: %.2f\n", min, max, prom);
    }

    size_t dentro_rango;
    if (contar_en_rango(datos, tam, 5, 15, &dentro_rango)) {
        printf("Elementos entre 5 y 15: %zu\n", dentro_rango);
    }

    return 0;
}
