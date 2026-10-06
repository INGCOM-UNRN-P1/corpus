/**
 * @file vector.c
 * @brief Implementación de la biblioteca libvector (sin estructuras).
 */

#include <stdlib.h>
#include "vector.h"

int *crear_bloque_enteros(size_t cantidad)
{
    int *arreglo;

    if (cantidad == 0)
    {
        return NULL;
    }

    arreglo = calloc(cantidad, sizeof(*arreglo));
    if (arreglo == NULL)
    {
        return NULL;
    }

    return arreglo;
}

void liberar_bloque_enteros(int **puntero_bloque)
{
    if (puntero_bloque == NULL || *puntero_bloque == NULL)
    {
        return;
    }

    free(*puntero_bloque);
    *puntero_bloque = NULL;
}

int *redimensionar_bloque_enteros(int *bloque, size_t nueva_cantidad)
{
    int *temp;

    if (nueva_cantidad == 0)
    {
        free(bloque);
        return NULL;
    }

    temp = realloc(bloque, nueva_cantidad * sizeof(*temp));
    if (temp == NULL)
    {
        return NULL;
    }

    return temp;
}


int *fusionar_bloques_enteros(const int *primero, size_t cant_primero,
                             const int *segundo, size_t cant_segundo)
{
    int *resultado;
    size_t total;
    size_t i;
    size_t j;

    if ((primero == NULL && cant_primero > 0)
        || (segundo == NULL && cant_segundo > 0))
    {
        return NULL;
    }

    if (cant_primero == 0 && cant_segundo == 0)
    {
        return NULL;
    }

    total = cant_primero + cant_segundo;
    resultado = malloc(total * sizeof(*resultado));
    if (resultado == NULL)
    {
        return NULL;
    }

    j = 0;
    for (i = 0; i < cant_primero; ++i)
    {
        resultado[j] = primero[i];
        ++j;
    }

    for (i = 0; i < cant_segundo; ++i)
    {
        resultado[j] = segundo[i];
        ++j;
    }

    return resultado;
}

bool agregar_al_bloque_enteros(int **puntero_bloque, size_t *cantidad,
                             int valor)
{
    int *nuevo_bloque;
    size_t nueva_cantidad;

    if (puntero_bloque == NULL || cantidad == NULL)
    {
        return false;
    }

    nueva_cantidad = *cantidad + 1;
    nuevo_bloque = realloc(*puntero_bloque, nueva_cantidad * sizeof(*nuevo_bloque));
    if (nuevo_bloque == NULL)
    {
        return false;
    }

    nuevo_bloque[*cantidad] = valor;
    *puntero_bloque = nuevo_bloque;
    *cantidad = nueva_cantidad;

    return true;
}