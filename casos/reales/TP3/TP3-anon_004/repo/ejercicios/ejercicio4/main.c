/**
 * @file main.c
 * @brief Programa principal del Ejercicio 4.
 */

#include <stdio.h>
#include "busqueda.h"

int main(void)
{
    int lista[7] = {12, 45, 78, 23, 56, 89, 23};
    int buscado = 0;
    const int *hallado = NULL;
    size_t distancia = 0;
    bool estado = false;

    printf("--- Ejercicio 4: Busqueda y Distancia de Punteros ---\n\n");
    printf("Arreglo: {12, 45, 78, 23, 56, 89, 23}\n");
    printf("Ingrese valor a buscar: ");
    if (scanf("%d", &buscado) != 1)
    {
        return 1;
    }

    hallado = buscar_primero(lista, 7, buscado);
    if (hallado != NULL)
    {
        estado = distancia_punteros(lista, hallado, &distancia);
        if (estado)
        {
            printf("Elemento hallado: %d en indice relativo: %zu\n", *hallado, distancia);
        }
    }
    else
    {
        printf("El elemento %d no existe en el arreglo.\n", buscado);
    }

    return 0;
}
