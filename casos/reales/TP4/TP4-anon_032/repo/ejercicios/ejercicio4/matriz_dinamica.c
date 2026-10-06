/**
 * @file matriz_dinamica.c
 * @brief Implementación para Ejercicio 4 (Matrices Dinámicas).
 */

#include "matriz_dinamica.h"
// Simular una matriz de filas × columnas enteros usando un 
// único bloque contiguo int *, 
// donde el elemento (i, j) se accede como bloque[i * columnas + j]


int *crear_matriz_plana(size_t filas, size_t columnas)
{
    return crear_bloque_enteros(filas * columnas);
}

bool obtener_celda(const int *m, size_t columnas, size_t fila, size_t col, int *valor)
{
    if (m == NULL || valor == NULL || col >= columnas)
    {
        return false;
    }

    *valor = m[fila * columnas + col];

    return true;
}

bool asignar_celda(int *m, size_t columnas, size_t fila, size_t col, int valor)
{
    if (m == NULL || col >= columnas)
    {
        return false;
    }

    m[fila * columnas + col] = valor;

    return true;
}

void liberar_matriz_plana(int **m)
{
    liberar_bloque_enteros(m);
}
