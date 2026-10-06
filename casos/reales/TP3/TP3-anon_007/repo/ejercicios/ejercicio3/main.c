/**
 * @file main.c
 * @brief Programa principal del Ejercicio 3.
 */

#include <stdio.h>
#include "recorrido.h"

int main(void)
{
    printf("Ejercicio 3: Recorrido e inversión con punteros\n");
    //---------------------------- VARIABLES ----------------------------
    int arreglo[] = {123, 12, 99, 66, 99, 13};
    size_t cantidad_arreglo = 6;
    int arreglo_copia[cantidad_arreglo];
    //---------------------------- Copia de arreglo ----------------------------
    printf("Copiar arreglo.\nArreglo original: ");
    imprimir_arreglo(arreglo, cantidad_arreglo);
    if (copiar_arreglo(arreglo, arreglo_copia, cantidad_arreglo, cantidad_arreglo))
    {
        printf("Copia del arreglo: \n");
        imprimir_arreglo(arreglo_copia, cantidad_arreglo);
    }
    //---------------------------- Contar en Rango ----------------------------
    printf("Invertir Arreglo.\nArreglo original: ");
    imprimir_arreglo(arreglo, cantidad_arreglo);
    printf("Arreglo invertido: \n");
    imprimir_arreglo(arreglo, cantidad_arreglo);
    printf("Fin del programa!\n");
    return 0;
}
