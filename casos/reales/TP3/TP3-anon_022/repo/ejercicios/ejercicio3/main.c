/**
 * @file main.c
 * @brief Programa principal del Ejercicio 3.
 */

#include <stdio.h>
#include "recorrido.h"

static void imprimir_arreglo(const int *arreglo, size_t cantidad)
{
    const int *fin = arreglo + cantidad;
    const int *cursor = arreglo;

    while (cursor < fin)
    {
        printf("%d ", *cursor);
        cursor++;
    }

    printf("\n");
}

int main(void)
{
    int origen[] = {10, 20, 30, 40, 50};
    int copia[5] = {0};
    size_t cantidad = sizeof(origen) / sizeof(int);

    printf("Ejercicio 3: Recorrido e inversión con punteros\n\n");

    printf("Arreglo original: ");
    imprimir_arreglo(origen, cantidad);

    copiar_arreglo(origen, cantidad, copia);
    printf("Arreglo copiado:  ");
    imprimir_arreglo(copia, cantidad);

    invertir_arreglo(copia, cantidad);
    printf("Copia invertida:  ");
    imprimir_arreglo(copia, cantidad);

    return 0;
}