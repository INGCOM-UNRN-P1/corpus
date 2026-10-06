/**
 * @file main.c
 * @brief Programa principal del Ejercicio 2.
 */

#include <stdio.h>
#include "estadistica.h"

int main(void)
{
    printf("Ejercicio 2: Estadisticas y Filtrado por Rango\n");

    int arreglo_estadistica[] = {10, 20, 30, 40};
    size_t total_elementos = sizeof(arreglo_estadistica) / sizeof(arreglo_estadistica[0]);

    int minimo = 0;
    int maximo = 0;
    double promedio = 0.0;

    bool estado_calculo_estadistica = calcular_estadisticas(arreglo_estadistica, total_elementos, &minimo, &maximo, &promedio);

    if(estado_calculo_estadistica == true)
    {
        printf("Minimo: %d\n", minimo);
        printf("Maximo: %d\n", maximo);
        printf("Promedio: %.2f\n", promedio);
    }

    int arreglo_rango[] = {5, 12, 18, 25, 30, 42};
    size_t cant_rango = sizeof(arreglo_rango) / sizeof(arreglo_rango[0]);

    size_t coincidencias = 0;
    int limite_inf = 10;
    int limite_sup = 30;

    bool estado_rango = contar_en_rango(arreglo_rango, cant_rango, limite_inf, limite_sup, &coincidencias);

    if(estado_rango == true)
    {
        printf("Elementos en el rango [%d, %d]: %zu\n", limite_inf, limite_sup, coincidencias);
    }

    return 0;
}
