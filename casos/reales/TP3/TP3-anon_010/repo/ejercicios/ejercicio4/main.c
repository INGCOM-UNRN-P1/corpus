/**
 * @file main.c
 * @brief Programa principal del Ejercicio 4.
 */

#include <stdio.h>
#include "busqueda.h"

int main(void)
{
    printf("Ejercicio 4: Busqueda con punteros\n\n");

    int datos[] = {5, 12, 18, 12, 30};
    size_t cantidad = sizeof(datos) / sizeof(datos[0]);

    printf("buscar_primero (valor 12):\n");
    const int *encontrado = buscar_primero(datos, cantidad, 12);
    if (encontrado != NULL)
    {
        printf("  Encontrado, valor: %d\n", *encontrado);

        ptrdiff_t distancia = distancia_punteros(datos, encontrado);
        printf("  Distancia desde el inicio: %td\n", distancia);
    }
    else
    {
        printf("  No encontrado.\n");
    }

    printf("\nbuscar_primero (valor 99, no existe):\n");
    const int *no_encontrado = buscar_primero(datos, cantidad, 99);
    if (no_encontrado == NULL)
    {
        printf("  No encontrado.\n");
    }

    return 0;
}
