/**
 * @file main.c
 * @brief Programa principal del Ejercicio 2.
 */

#include <stdio.h>
#include "estadistica.h"

int main(void)
{
    printf("Ejercicio 2: Estadísticas con punteros\n");

    printf("\n===== Calcular Estadisticas =====\n");

    int arreglo[] = {1,3,2,4,6,5};
    size_t cantidad = sizeof(arreglo)/sizeof(arreglo[0]);
    int minimo = 0;
    int maximo = 0;
    double promedio = 0;
    printf("ARREGLO: ");
    for (size_t i = 0; i < cantidad; i++)
    {
        printf("%d, ", arreglo[i]);
    }
    printf("\n");
    printf("ANTES: minimo = %d, maximo = %d, promedio = %.2f\n", minimo, maximo, promedio);
    calcular_estadisticas(arreglo, cantidad, &minimo, &maximo, &promedio);
    printf("DESPUES: minimo = %d, maximo = %d, promedio = %.2f\n", minimo, maximo, promedio);

    printf("\n===== Contar en Rango =====\n");
    size_t coincidencias = 0;
    int limite_inf = 2;
    int limite_sup = 4;
    printf("ANTES: limite_inf = %d, limite_sup = %d, coincidencias = %zu\n", limite_inf, limite_sup, coincidencias);
    contar_en_rango(arreglo, cantidad, limite_inf, limite_sup, &coincidencias);
    printf("Despues: limite_inf = %d, limite_sup = %d, coincidencias = %zu\n", limite_inf, limite_sup, coincidencias);

    return 0;
}
