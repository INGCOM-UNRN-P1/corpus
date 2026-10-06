/**
 * @file main.c
 * @brief Programa principal del Ejercicio 3.
 */

#include <stdio.h>
#include "recorrido.h"

int main(void)
{
    printf("Ejercicio 3: Recorrido e inversion con punteros\n");

    int original[] = {10, 20, 30, 40, 50};
    int copia[5] = {0};
    size_t cantidad = 5;

    if (copiar_arreglo(original, copia, cantidad))
    {
        printf("Arreglo copiado con exito.\n");
    }

    if (invertir_arreglo(copia, cantidad))
    {
        printf("Arreglo invertido in-place con exito.\n");
        printf("Resultados de la copia invertida:\n");
        
        int *fin = copia + cantidad;
        for (int *p = copia; p < fin; p++)
        {
            printf("%d\n", *p);
        }
    }

    return 0;
}