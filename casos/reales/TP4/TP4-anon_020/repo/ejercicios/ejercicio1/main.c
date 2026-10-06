/**
 * @file main.c
 * @brief Programa principal del Ejercicio 1.
 */

#include <stdio.h>
#include "consola.h"
#include "punteros.h"
#include "vector.h"
#include "vector_enteros.h"

int main(void)
{
    int *original = NULL;
    int *clon = NULL;
    int *pares = NULL;
    size_t capacidad = 0U;
    size_t cantidad_pares = 0U;
    int valor = 0;
    size_t i = 0U;

    printf("Ejercicio 1: Vector Dinámico de Enteros\n");

    capacidad = (size_t)leer_entero_entre("Cantidad de elementos", 1, 20);
    original = crear_bloque_enteros(capacidad);
    if (original == NULL)
    {
        printf("No se pudo reservar el vector.\n");
        return 1;
    }

    for (i = 0U; i < capacidad; ++i)
    {
        valor = leer_entero("Ingrese un entero");
        original[i] = valor;
    }

    printf("Vector original:\n");
    mostrar_arreglo_int(original, capacidad);

    clon = clonar_arreglo_enteros(original, capacidad);
    if (clon != NULL)
    {
        printf("Clon del vector:\n");
        mostrar_arreglo_int(clon, capacidad);
    }
    else
    {
        printf("No se pudo clonar el vector.\n");
    }

    pares = filtrar_arreglo_pares(original, capacidad, &cantidad_pares);
    printf("Pares encontrados: %zu\n", cantidad_pares);
    if (pares != NULL)
    {
        mostrar_arreglo_int(pares, cantidad_pares);
    }
    else
    {
        printf("No hay valores pares en el vector.\n");
    }

    liberar_bloque_enteros(&clon);
    liberar_bloque_enteros(&pares);
    liberar_bloque_enteros(&original);
    return 0;
}