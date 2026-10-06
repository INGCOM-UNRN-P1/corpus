/**
 * @file main.c
 * @brief Programa principal del Ejercicio 2.
 */

#include <stdio.h>
#include "estadistica.h"

int main(void)
{
    printf("Ejercicio 2: Estadísticas con punteros\n");

    int datos[] = {5, 12, 18, 25, 30, 42};
    size_t cantidad = sizeof(datos) / sizeof(*datos);
    printf("Datos: {5, 12, 18, 25, 30, 42}\n");

    int menor = 0;
    int mayor = 0;
    if (obtener_min_max(datos, cantidad, &menor, &mayor) == true)
    {
        printf("obtener_min_max -> minimo: %d, maximo: %d\n", menor, mayor);
    }

    int minimo = 0;
    int maximo = 0;
    double promedio = 0.0;
    if (calcular_estadisticas(datos, cantidad, &minimo, &maximo,
                              &promedio) == true)
    {
        printf("Minimo: %d, maximo: %d, promedio: %.2f\n",
               minimo, maximo, promedio);
    }

    size_t en_rango = 0;
    if (contar_en_rango(datos, cantidad, 10, 30, &en_rango) == true)
    {
        printf("Elementos en [10, 30]: %zu\n", en_rango);
    }

    return 0;
}
