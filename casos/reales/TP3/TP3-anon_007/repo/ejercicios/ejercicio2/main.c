/**
 * @file main.c
 * @brief Programa principal del Ejercicio 2.
 */

#include <stdio.h>
#include "estadistica.h"

int main(void)
{
    printf("Ejercicio 2: Estadísticas con punteros\n");
    //---------------------------- VARIABLES ----------------------------
    int arreglo[] = {123, 12, 99, 66, 99, 13};
    size_t cantidad_arreglo = 6;
    double promedio = 0;
    int minimo = 0;
    int maximo = 0;
    int limite_inf = 20;
    int limite_sup = 100;
    size_t coincidencias = 0;
    //---------------------------- Calcular estadisticas ----------------------------
    printf("Calcular estadisticas.\nArreglo al cual se le extraeran las estadisticas: ");
    imprimir_arreglo(arreglo, cantidad_arreglo);
    if (calcular_estadisticas(arreglo, cantidad_arreglo, &minimo, &maximo, &promedio))
    {
        printf("Las estadisticas son: \nMinimo: [%d]\nMaximo: [%d]\nPromedio: [%lf]\n",minimo, maximo, promedio);
    }
    //---------------------------- Contar en Rango ----------------------------
    printf("Contar en Rango.\nArreglo al que se le contaran los elementos en cierto rango: ");
    imprimir_arreglo(arreglo, cantidad_arreglo);
    if (contar_en_rango(arreglo, cantidad_arreglo, limite_inf, limite_sup, &coincidencias))
    {
        printf("Cantidad de elementos coincidentes entre los valores %d y %d es: %zu \n", limite_inf, limite_sup, coincidencias);
    }
    printf("Fin del programa!\n");
    return 0;
}
