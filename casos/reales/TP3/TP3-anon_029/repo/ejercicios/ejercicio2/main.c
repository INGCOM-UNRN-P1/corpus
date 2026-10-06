/**
 * @file main.c
 * @brief Programa principal del Ejercicio 2.
 */

#include <stdio.h>
#include "estadistica.h"

int main(void)
{
    int arreglo[] = {3, 3, 5, 7, 4};
    int minimo = 0;
    int maximo = 0;
    double promedio = 0;
    printf("Ejercicio 2: Estadísticas con punteros\n");
    calcular_estadisticas(arreglo, 5, &minimo, &maximo, &promedio);
    printf("El promedio de 'arreglo' es: %f.\n El minimo del arreglo es: %d.\n"
    "El maximo del arreglo es: %d.\n", promedio, minimo, maximo);
    
    int limite_inf = 3;
    int limite_sup = 5;
    size_t coincidencias;
    contar_en_rango(arreglo, 5, limite_inf, limite_sup, &coincidencias);
    printf("La cantidad de coincidencias enontradas en el rango de %d y %d, es de: %zu.\n", limite_inf, limite_sup, coincidencias);
    return 0;
}
