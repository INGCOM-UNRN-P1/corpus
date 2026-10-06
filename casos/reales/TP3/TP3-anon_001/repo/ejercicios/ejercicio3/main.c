/**
 * @file main.c
 * @brief Programa principal del Ejercicio 3.
 */

#include <stdio.h>
#include "recorrido.h"

static void imprimir_arreglo(const char *mensaje, const int *arreglo, size_t cantidad)
{
    printf("%s: [", mensaje);
    for (size_t i = 0; i < cantidad; i++)
    {
        printf("%d%s", arreglo[i], (i < cantidad - 1) ? ", " : "");
    }
    printf("]\n");
}

int main(void)
{
    int origen[] = {1, 2, 3, 4, 5};
    size_t cantidad = sizeof(origen) / sizeof(origen[0]);
    int destino[5] = {0};

    printf("=== DEMOSTRACION EJERCICIO 3 ===\n\n");

    imprimir_arreglo("Original", origen, cantidad);

    // 1. Probar copia con aritmética de punteros
    if (copiar_arreglo(origen, destino, cantidad))
    {
        imprimir_arreglo("Copia en destino", destino, cantidad);
    }

    // 2. Probar inversión in-place con punteros
    if (invertir_arreglo(destino, cantidad))
    {
        imprimir_arreglo("Copia invertida", destino, cantidad);
    }

    return 0;
}