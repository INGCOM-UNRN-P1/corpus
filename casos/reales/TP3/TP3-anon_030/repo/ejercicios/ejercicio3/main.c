/**
 * @file main.c
 * @brief Programa principal del Ejercicio 3.
 */

#include <stdio.h>
#include "recorrido.h"

static void mostrar_arreglo(const int *arreglo, size_t cantidad)
{
    const int *actual = arreglo;
    const int *fin = arreglo + cantidad;

    while (actual < fin)
    {
        printf("%d ", *actual);
        actual++;
    }

    printf("\n");
}

int main(void)
{
    int origen[] = {10, 20, 30, 40, 50};
    int copia[5];

    size_t cantidad = 5;

    printf("Ejercicio 3: Recorrido e inversion con punteros\n");

    printf("Arreglo original: ");
    mostrar_arreglo(origen, cantidad);

    copiar_arreglo(origen, copia, cantidad);

    printf("Arreglo copiado: ");
    mostrar_arreglo(copia, cantidad);

    invertir_arreglo(copia, cantidad);

    printf("Arreglo invertido: ");
    mostrar_arreglo(copia, cantidad);

    return 0;
}
