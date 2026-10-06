/**
 * @file estadistica.c
 * @brief Implementación de estadísticas y filtrado por rango con punteros.
 *
 * Observación:
 * Recuerden que no está permitido utilizar ALV's, pero también, este ejercicio
 * no está pensado para utilizar memoria dinámica.
 */

#include "estadistica.h"



bool calcular_estadisticas(const int *arreglo, size_t cantidad, int *minimo, int *maximo, double *promedio)
{
    bool resultado = false;
    if (arreglo == NULL || minimo == NULL || maximo == NULL)
    {
        resultado = false;
    }
    else if (cantidad == 0 || promedio == NULL)
    {
        resultado = false;
    }
    else
    {
        obtener_min_max(arreglo, cantidad, minimo, maximo);

        const int *p_inicio = arreglo;
        const int *limite = arreglo + cantidad;
        long long suma = 0;

        while (p_inicio < limite)
        {
            suma = suma + *p_inicio;
            p_inicio++;
        }
        *promedio = (double)suma / cantidad;

        resultado = true;
    }

    return resultado;
}

bool contar_en_rango(const int *arreglo, size_t cantidad, int limite_inf, int limite_sup, size_t *coincidencias)
{
    bool exito = false;

    if (arreglo == NULL || coincidencias == NULL)
    {
        exito = false;
    }
    else
    {
        size_t contador = 0;
        const int *p_local = arreglo;
        const int *limite_local = arreglo + cantidad;

        while (p_local < limite_local)
        {

            if (*p_local >= limite_inf && *p_local <= limite_sup)
            {
                contador++;
            }
            p_local++;
        }

        *coincidencias = contador;

        exito = true;
    }

    return exito;
}
