/**
 * @file main.c
 * @brief Programa principal del Ejercicio 1.
 */

#include <stdio.h>
#include "vector.h"
#include "vector_enteros.h"

static void mostrar_bloque(const char *etiqueta, const int *bloque, size_t n)
{
    printf("%s [%zu elementos]: [ ", etiqueta, n);
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", *(bloque + i));
    }
    printf("]\n");
}

int main(void)
{
    printf("=== Ejercicio 1: Vector Dinamico de Enteros ===\n\n");

    int originales[] = {12, 7, 9, 24, 18, 5, 30, 11};
    size_t n_originales = sizeof(originales) / sizeof(*(originales + 0));

    mostrar_bloque("Arreglo base", originales, n_originales);

    printf("\n1. Clonando bloque en heap...\n");
    int *clon = clonar_arreglo_enteros(originales, n_originales);
    if (clon != NULL)
    {
        mostrar_bloque("Bloque clonado", clon, n_originales);
    }

    printf("\n2. Filtrando numeros pares del bloque original...\n");
    size_t cant_pares = 0;
    int *pares = filtrar_arreglo_pares(originales, n_originales, &cant_pares);
    if (pares != NULL)
    {
        mostrar_bloque("Bloque de pares", pares, cant_pares);
    }

    printf("\n3. Liberando memoria dinámica reservada...\n");
    liberar_bloque_enteros(&clon);
    liberar_bloque_enteros(&pares);

    printf("Puntero clon tras liberar : %p\n", (void *)clon);
    printf("Puntero pares tras liberar: %p\n", (void *)pares);

    return 0;
}