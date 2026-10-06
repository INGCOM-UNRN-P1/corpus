/**
 * @file main.c
 * @brief Programa principal interactivo y demostrativo del Ejercicio 2.
 */

#include <stdio.h>
#include "estadistica.h"

static void imprimir_arreglo(const int *arreglo, size_t cantidad)
{
    const int *actual = arreglo;
    const int *fin = arreglo + cantidad;

    printf("[ ");
    while (actual < fin)
    {
        printf("%d ", *actual);
        actual++;
    }
    printf("]\n");
}

int main(void)
{
    printf("=== Demostracion Ejercicio 2: Estadisticas y Rango con Punteros ===\n\n");

    int datos[] = {12, 5, 8, 20, 15, 3, 30};
    size_t cantidad = sizeof(datos) / sizeof(*(datos + 0));

    printf("Arreglo de prueba: ");
    imprimir_arreglo(datos, cantidad);

    int min = 0;
    int max = 0;
    double prom = 0.0;

    if (calcular_estadisticas(datos, cantidad, &min, &max, &prom))
    {
        printf("Minimo hallado : %d\n", min);
        printf("Maximo hallado : %d\n", max);
        printf("Promedio       : %.2f\n", prom);
    }

    int lim_inf = 10;
    int lim_sup = 20;
    size_t coincidencias = 0;

    if (contar_en_rango(datos, cantidad, lim_inf, lim_sup, &coincidencias))
    {
        printf("Elementos en rango [%d, %d]: %zu\n", lim_inf, lim_sup, coincidencias);
    }

    return 0;
}
