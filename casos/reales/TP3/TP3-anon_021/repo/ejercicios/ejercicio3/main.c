/**
 * @file main.c
 * @brief Programa principal del Ejercicio 3.
 */

#include <stdio.h>
#include "recorrido.h"

int main(void)
{
    printf("Copia e Inversión con Aritmética de Punteros\n\n");
    int origen[] = {10, 20, 30, 40, 50};
    size_t cantidad = sizeof(origen) / sizeof(origen[0]);
    int destino[5] = {0}; // Inicializado en ceros

    printf("copiar_arreglo \n");
    printf("Arreglo origen:  {10, 20, 30, 40, 50}\n");

    if (copiar_arreglo(origen, destino, cantidad))
    {
        printf("Copia exitosa al arreglo destino.\n");
        printf("Arreglo destino: {%d, %d, %d, %d, %d}\n\n", 
               destino[0], destino[1], destino[2], destino[3], destino[4]);
    }
    else
    {
        printf("Error al realizar la copia del arreglo.\n\n");
    }

    int a_invertir[] = {1, 2, 3, 4, 5, 6};
    size_t cantidad_inv = sizeof(a_invertir) / sizeof(a_invertir[0]);

    printf("invertir_arreglo \n");
    printf("Arreglo antes de invertir:   {1, 2, 3, 4, 5, 6}\n");

    if (invertir_arreglo(a_invertir, cantidad_inv))
    {
        printf("Inversión realizada con éxito.\n");
        printf("Arreglo después de invertir: {%d, %d, %d, %d, %d, %d}\n", 
               a_invertir[0], a_invertir[1], a_invertir[2], 
               a_invertir[3], a_invertir[4], a_invertir[5]);
    }
    else
    {
        printf("Error al intentar invertir el arreglo.\n");
    }

    return 0;
}
