/**
 * @file main.c
 * @brief Programa principal del Ejercicio 2.
 */

#include <stdio.h>
#include "estadistica.h"

int main(void)
{
    printf("Ejercicio 2: Estadisticas con punteros\n\n");

    int datos[] = {10, 20, 30, 40, 50};
    size_t cantidad = sizeof(datos) / sizeof(datos[0]);

    
    int minimo = 0;
    int maximo = 0;
    printf("obtener_min_max:\n");
    if (obtener_min_max(datos, cantidad, &minimo, &maximo))
    {
        printf("  Minimo: %d, Maximo: %d\n\n", minimo, maximo);
    }
    else
    {
        printf("  Error: parametros invalidos.\n\n");
    }

    
    int min_est = 0;
    int max_est = 0;
    double promedio = 0.0;
    printf("calcular_estadisticas:\n");
    if (calcular_estadisticas(datos, cantidad, &min_est, &max_est, &promedio))
    {
        printf("  Minimo: %d, Maximo: %d, Promedio: %.2f\n\n", min_est, max_est, promedio);
    }
    else
    {
        printf("  Error: parametros invalidos.\n\n");
    }

    
    int limite_inf = 15;
    int limite_sup = 45;
    size_t coincidencias = 0;
    printf("contar_en_rango (rango [%d, %d]):\n", limite_inf, limite_sup);
    if (contar_en_rango(datos, cantidad, limite_inf, limite_sup, &coincidencias))
    {
        printf("  Coincidencias: %zu\n", coincidencias);
    }
    else
    {
        printf("  Error: parametros invalidos.\n");
    }

    return 0;
}
