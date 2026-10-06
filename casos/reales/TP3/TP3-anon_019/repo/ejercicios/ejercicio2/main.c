/**
 * @file main.c
 * @brief Programa principal del Ejercicio 2.
 */

#include <stdio.h>
#include "estadistica.h"

int main(void)
{
    printf("Ejercicio 2: Estadísticas con punteros\n");

    int datos[] = {10, 25, -5, 40, 15, 30};
    size_t cantidad = 6;

    int min = 0;
    int max = 0;
    double prom = 0.0;

    if (calcular_estadisticas(datos, cantidad, &min, &max, &prom))
    {
        printf("Resultados del arreglo:\n");
        printf("- Minimo: %d\n", min);
        printf("- Maximo: %d\n", max);
        printf("- Promedio: %.2f\n\n", prom);
    }

    size_t conteo = 0;
    int limite_inf = 10;
    int limite_sup = 30;

    if (contar_en_rango(datos, cantidad, limite_inf, limite_sup, &conteo))
    {
        printf("Elementos en el rango [%d, %d]: %zu\n", limite_inf, limite_sup, conteo);
    }

    return 0;
}