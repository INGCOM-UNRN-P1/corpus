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
    bool verificacion = true;
    if (arreglo == NULL || minimo == NULL || maximo == NULL || promedio == NULL || cantidad == 0)
    {
        verificacion = false;
    }
    else
    {
        obtener_min_max(arreglo, cantidad, minimo, maximo);
        long long acumulador = 0;
        const int *actual = NULL;
        actual = arreglo;//apunto inicio del arreglo
        const int *limite = NULL;
        limite = arreglo + cantidad;
        while (actual < limite)
        {
            acumulador = acumulador + *actual;
            actual = actual +1;
        }
        *promedio = (double)acumulador/cantidad;//uso double para no perder decimales
        verificacion = true;
    }
    
    return verificacion;
}

bool contar_en_rango(const int *arreglo, size_t cantidad, int limite_inf, int limite_sup, size_t *coincidencias)
{
   bool verificacion = false;
   if (arreglo == NULL || coincidencias == NULL)
   {
    verificacion = false;
   }
   else
   {
    verificacion = true;
    size_t contador = 0; //variable para ir llevando la cuenta de cuantos elementos cumple
    const int *actual = NULL;//puntero auxiliar de lectura
    actual = arreglo;
    const int *limite = NULL; //puntero limite
    limite = arreglo + cantidad;

    while (actual < limite)
    {
        if (*actual >= limite_inf && *actual <= limite_sup)
        {
            contador = contador +1;
        }

        actual = actual +1;
        
    }
    *coincidencias= contador;
   }
    return verificacion;
}
