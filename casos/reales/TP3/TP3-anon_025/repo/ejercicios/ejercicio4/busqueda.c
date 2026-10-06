/**
 * @file busqueda.c
 * @brief Implementación de búsqueda lineal con retorno de puntero y resta de punteros.
 */

#include "busqueda.h"

const int* buscar_primero(const int *arreglo_fuente, size_t cantidad_elementos, int valor_buscado)
{
    if (arreglo_fuente == NULL || cantidad_elementos == 0)
    {
        return NULL;
    }

    const int *cursor_actual = arreglo_fuente;

    for (size_t elementos_procesados = 0; elementos_procesados < cantidad_elementos; elementos_procesados++)
    {
      if (*cursor_actual == valor_buscado)
      {
        return cursor_actual;
      }  
      cursor_actual ++;
    }
    return NULL;
}

ptrdiff_t distancia_punteros(const int *puntero_inicio, const int *puntero_elementos)
{
    if (puntero_inicio == NULL || puntero_elementos == NULL || puntero_elementos < puntero_inicio)
    {
        return -1;
    }
    return (puntero_elementos - puntero_inicio);
}


