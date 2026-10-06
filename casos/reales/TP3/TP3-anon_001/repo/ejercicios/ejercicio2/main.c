/**
 * @file main.c
 * @brief Programa principal del Ejercicio 2.
 */

#include <stdio.h>
#include "estadistica.h"

int main(void) {
    int arr[] = {3, 1, 8, 5, 2};
    size_t cant = 5;

    int min, max;
    double prom;
    size_t coincidencia;

    // Probar calcular_estadisticas
    if (calcular_estadisticas(arr, cant, &min, &max, &prom)) {
        printf("Min: %d | Max: %d | Prom: %.2f\n", min, max, prom);
    }

    // Probar contar_en_rango (rango inclusivo [2, 5])
    if (contar_en_rango(arr, cant, 2, 5, &coincidencia)) {
        printf("Elementos en rango [2, 5]: %zu\n", coincidencia);
    }

    return 0;
}
