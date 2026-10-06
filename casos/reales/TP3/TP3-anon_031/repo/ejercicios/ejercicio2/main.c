/**
 * @file main.c
 * @brief Programa principal del Ejercicio 2.
 */

#include <stdio.h>
#include "estadistica.h"

int main(void)
{
    int datos[] = {10, 20, 30, 40};
    size_t cantidad = 4;

    int minimo = 0;
    int maximo = 0;
    double promedio = 0.0;

    size_t coincidencias = 0;
    int limite_inferior = 15;
    int limite_superior = 35;

    printf("Ejercicio 2: Estadisticas con punteros\n");

    if (calcular_estadisticas(datos, cantidad, &minimo, &maximo, &promedio))
    {
        printf("Minimo: %d\n", minimo);
        printf("Maximo: %d\n", maximo);
        printf("Promedio: %.2f\n", promedio);
    }
    else
    {
        printf("No se pudieron calcular las estadisticas.\n");
    }

    if (contar_en_rango(datos, cantidad, limite_inferior, limite_superior, &coincidencias))
    {
        printf("Cantidad de valores entre %d y %d: %zu\n",
               limite_inferior, limite_superior, coincidencias);
    }
    else
    {
        printf("No se pudo realizar el conteo.\n");
    }

    return 0;
}