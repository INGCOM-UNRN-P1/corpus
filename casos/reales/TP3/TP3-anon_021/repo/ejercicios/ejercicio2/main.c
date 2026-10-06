/**
 * @file main.c
 * @brief Programa principal del Ejercicio 2.
 */

#include <stdio.h>
#include "estadistica.h"

int main(void)
{
    printf("Estadísticas, Promedio y Rango con Punteros \n");
    int datos[] = {15, 3, 22, 8, 42, 10, 19};
    size_t cantidad = sizeof(datos) / sizeof(datos[0]);

    printf("Arreglo analizado: {15, 3, 22, 8, 42, 10, 19}\n");
    printf("Cantidad de elementos: %zu\n\n", cantidad);

    int min_parcial = 0;
    int max_parcial = 0;
    
    printf("obtener_min_max \n");
    if (obtener_min_max(datos, cantidad, &min_parcial, &max_parcial))
    {
        printf("Extremos -> Mínimo: %d | Máximo: %d\n\n", min_parcial, max_parcial);
    }

    int minimo = 0;
    int maximo = 0;
    double promedio = 0.0;

    printf("calcular_estadisticas \n");
    if (calcular_estadisticas(datos, cantidad, &minimo, &maximo, &promedio))
    {
        printf("Estadísticas calculadas con exito:\n");
        printf(" > Minimo: %d\n", minimo);
        printf(" > Maximo: %d\n", maximo);
        printf(" > Promedio: %.2f\n\n", promedio);
    }
    else
    {
        printf("Error al calcular estadisticas.\n\n");
    }

    int limite_inf = 10;
    int limite_sup = 30;
    size_t coincidencias = 0;

    printf("contar_en_rango \n");
    printf("Buscando elementos dentro del intervalo cerrado [%d, %d]\n", limite_inf, limite_sup);
    
    if (contar_en_rango(datos, cantidad, limite_inf, limite_sup, &coincidencias))
    {
        printf("Coincidencias encontradas: %zu elementos.\n", coincidencias);
    }
    else
    {
        printf("Error al realizar el conteo en rango.\n");
    }

    return 0;
}
