/**
 * @file punteros.c
 * @brief Esqueleto de implementación para la biblioteca libpunteros.
 *
 * Trabajo Práctico 3 - Programación 1
 * Universidad Nacional de Río Negro - Ingeniería en Computación
 *
 * Observación:
 * Recuerden que no está permitido utilizar ALV's, pero también, este ejercicio
 * no está pensado para utilizar memoria dinámica.
 */

#include <stdio.h>
#include "punteros.h"

void intercambiar(int *primer, int *segundo)
{
    if (primer == NULL || segundo == NULL || primer == segundo)
    {
        return;
    }

    int temporal = *primer;
    *primer = *segundo;
    *segundo = temporal;
}

bool obtener_min_max(const int *arreglo, size_t cantidad, int *minimo,
                     int *maximo)
{
    if (arreglo == NULL || minimo == NULL || maximo == NULL || cantidad == 0)
    {
        return false;
    }

    const int *cursor = arreglo;
    const int *fin = arreglo + cantidad;
    int valor_minimo = *arreglo;
    int valor_maximo = *arreglo;

    for (cursor = arreglo + 1; cursor < fin; cursor++)
    {
        if (*cursor < valor_minimo)
        {
            valor_minimo = *cursor;
        }
        if (*cursor > valor_maximo)
        {
            valor_maximo = *cursor;
        }
    }

    *minimo = valor_minimo;
    *maximo = valor_maximo;
    return true;
}

void leer_arreglo_int(int *arreglo, size_t cantidad)
{
    if (arreglo == NULL || cantidad == 0)
    {
        return;
    }

    int *cursor = arreglo;
    int *fin = arreglo + cantidad;

    while (cursor < fin)
    {
        scanf("%d", cursor);
        cursor++;
    }
}

void mostrar_arreglo_int(const int *arreglo, size_t cantidad)
{
    if (arreglo == NULL || cantidad == 0)
    {
        printf("[]\n");
        return;
    }

    const int *cursor = arreglo;
    const int *fin = arreglo + cantidad;

    printf("[");
    while (cursor < fin)
    {
        printf("%d", *cursor);
        cursor++;
        if (cursor < fin)
        {
            printf(", ");
        }
    }
    printf("]\n");
}
