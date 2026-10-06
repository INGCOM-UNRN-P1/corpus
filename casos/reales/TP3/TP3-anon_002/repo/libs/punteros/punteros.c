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

#include "punteros.h"

void intercambiar(int *primer, int *segundo)
{

    if (primer == NULL || segundo == NULL)
    {
    }
    else if (primer  == segundo)
    {
    }
    else
    {
        int intercambiado = 0;

        intercambiado = *primer;

        *primer = *segundo;

        *segundo = intercambiado;
    }
}

bool obtener_min_max(const int *arreglo, size_t cantidad, int *minimo, int *maximo)
{
    bool resultado = false;

    if (arreglo == NULL || cantidad == 0)
    {
        resultado = false;
    }
    else if (minimo == NULL || maximo == NULL)
    {
        resultado = false;
    }
    else
    {
        int min_local = 0;
        int max_local = 0;

        min_local = *arreglo;
        max_local = *arreglo;

        const int *p_actual = arreglo;
        const int *p_final = arreglo + cantidad;

        while (p_actual < p_final)
        {
            if (*p_actual < min_local)
            {
                min_local = *p_actual;
            }
            if (*p_actual > max_local)
            {
                max_local = *p_actual;
            }
            p_actual++;
        }

        *minimo = min_local;
        *maximo = max_local;

        resultado = true;
    }
    return resultado;
}
