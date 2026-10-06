/**
 * @file matriz_dinamica.c
 * @brief Implementación de matrices planas dinámicas en heap.
 */

#include "matriz_dinamica.h"
#include <stdlib.h>


int *crear_matriz_plana(size_t filas, size_t columnas)
{
    int *matriz = NULL;

    if (filas > 0 && columnas > 0)
    {
        matriz = calloc(filas * columnas, sizeof(int));
    }

    return matriz;
}


int obtener_celda(const int *matriz, size_t columnas, size_t fila,
                  size_t columna)
{
    int valor = 0;

    if (matriz != NULL && columnas > 0)
    {
        valor = *(matriz + fila * columnas + columna);
    }

    return valor;
}


void asignar_celda(int *matriz, size_t columnas, size_t fila, size_t columna,
                   int valor)
{
    if (matriz != NULL && columnas > 0)
    {
        *(matriz + fila * columnas + columna) = valor;
    }
}


void liberar_matriz_plana(int *matriz)
{
    if (matriz != NULL)
    {
        free(matriz);
    }
}
