/**
 * @file main.c
 * @brief Programa principal del Ejercicio 1.
 */

#include <stdio.h>
#include "intercambio.h"

int main(void)
{
    printf("Ejercicio 1: Intercambio con punteros\n");
    //---------------------------- VARIABLES ----------------------------
    int arreglo[] = {123, 12, 99};
    size_t cantidad_arreglo = 3;
    long long resultado = 0;
    //---------------------------- Ordenamiento de pares ----------------------------
    printf("Ordenamiento de pares.\nArreglo sin ordenar los primeros dos parametros: ");
    imprimir_arreglo(arreglo, cantidad_arreglo);
    ordenar_par(arreglo, (arreglo+1));
    printf("Primeros dos elementos del arreglo ordenados: ");
    imprimir_arreglo(arreglo, cantidad_arreglo);
    //---------------------------- Ordenamiento de tria ----------------------------
    printf("Ordenar Tria.\nArreglo que previamente se ordenaron dos de sus 3 elementos: ");
    imprimir_arreglo(arreglo, cantidad_arreglo);
    ordenar_tria(arreglo, (arreglo + 1), (arreglo + 2));
    printf("Arreglo ordenado de manera ascendente: ");
    imprimir_arreglo(arreglo, cantidad_arreglo);
    //---------------------------- Ordenamiento de tria ----------------------------
    printf("Suma acumulada de arreglo.\nElementos a sumar del arreglo: ");
    imprimir_arreglo(arreglo, cantidad_arreglo);
    sumar_acumulado(arreglo, cantidad_arreglo, &resultado);
    printf("Resultado de la suma: %lld \nFin del programa!\n", resultado);
    return 0;
}
