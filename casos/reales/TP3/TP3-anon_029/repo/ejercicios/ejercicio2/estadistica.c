/**
 * @file estadistica.c
 * @brief Implementación de estadísticas y filtrado por rango con punteros.
 *
 * Observación:
 * Recuerden que no está permitido utilizar ALV's, pero también, este ejercicio
 * no está pensado para utilizar memoria dinámica.
 */

#include "estadistica.h"

bool calcular_estadisticas(const int *arreglo, size_t cantidad, int *minimo,
     int *maximo, double *promedio)
{
  if (cantidad == 0 || arreglo == NULL || minimo == NULL ||
     maximo == NULL || promedio == NULL)
  {
    return false;
  }

  obtener_min_max(arreglo, cantidad, minimo, maximo);
  
    int const *puntero = arreglo;
    int const *fin = arreglo + cantidad;
    long long suma = 0;
    while (puntero < fin)
    {
        suma = suma + *puntero;
        puntero ++;
    }
    *promedio = (double)suma / cantidad;
    return true;
}

bool contar_en_rango(const int *arreglo, size_t cantidad, int limite_inf,
     int limite_sup, size_t *coincidencias)
{
    if (arreglo == NULL || coincidencias == NULL || cantidad == 0 ||
         limite_inf > limite_sup)
    {
    return false;
    }
    *coincidencias = 0;
    int const *puntero = arreglo;
    int const *fin = arreglo + cantidad;
    while (puntero < fin)
    {
        if (*puntero >= limite_inf && *puntero <= limite_sup)
        {
            (*coincidencias)++;
        }
        puntero ++;
    }
    return true;
}

