/**
 * @file main.c
 * @brief Programa principal del Ejercicio 2.
 */

#include <stdio.h>
#include "estadistica.h"
#include "punteros.h"

int main(void)
{
    int datos[10] = {0};
    int minimo = 0;
    int maximo = 0;
    double promedio = 0.0;
    size_t coincidencias = 0;
    size_t cantidad = 0;
    int limite_inf = 0;
    int limite_sup = 0;

    printf("Ejercicio 2: Estadísticas con punteros\n");
    printf("Ingrese la cantidad de elementos (max 10): ");
    scanf("%zu", &cantidad);
    if (cantidad == 0 || cantidad > 10)
    {
        printf("Cantidad inválida.\n");
        return 1;
    }

    printf("Ingrese %zu enteros: ", cantidad);
    leer_arreglo_int(datos, cantidad);
    printf("Arreglo ingresado: ");
    mostrar_arreglo_int(datos, cantidad);

    if (calcular_estadisticas(datos, cantidad, &minimo, &maximo, &promedio))
    {
        printf("Mínimo: %d\n", minimo);
        printf("Máximo: %d\n", maximo);
        printf("Promedio: %.2f\n", promedio);
    }

    printf("Ingrese el límite inferior y superior del rango: ");
    scanf("%d %d", &limite_inf, &limite_sup);
    if (contar_en_rango(datos, cantidad, limite_inf, limite_sup, &coincidencias))
    {
        printf("Elementos en el rango [%d, %d]: %zu\n",
               limite_inf, limite_sup, coincidencias);
    }

    return 0;
}
