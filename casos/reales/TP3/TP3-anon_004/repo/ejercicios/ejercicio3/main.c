/**
 * @file main.c
 * @brief Programa principal del Ejercicio 3.
 */

#include <stdio.h>
#include "recorrido.h"

static void mostrar_lista(const int *arreglo, size_t cantidad)
{
    const int *actual = arreglo;
    const int *limite = arreglo + cantidad;

    while (actual < limite)
    {
        printf("%d ", *actual);
        actual++;
    }
    printf("\n");
}

int main(void)
{
    int origen[5] = {10, 20, 30, 40, 50};
    int copia[5] = {0};
    bool estado = false;

    printf("--- Ejercicio 3: Copia e Inversion con Punteros ---\n\n");
    printf("Arreglo original: ");
    mostrar_lista(origen, 5);

    estado = copiar_arreglo(copia, origen, 5);
    if (estado)
    {
        printf("Arreglo copiado:  ");
        mostrar_lista(copia, 5);
    }

    printf("Invirtiendo copia in-place...\n");
    invertir_arreglo(copia, 5);
    printf("Copia invertida:  ");
    mostrar_lista(copia, 5);

    return 0;
}