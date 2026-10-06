/**
 * @file busqueda.c
 * @brief Implementación de búsqueda lineal con retorno de puntero y resta de punteros.
 */

#include "busqueda.h"

const int *buscar_primero(const int *arreglo, size_t capacidad, int valor_buscado)
{
    if (arreglo == NULL || capacidad == 0)
    {
        return NULL;
    }
        const int *puntero_actual = arreglo;
        const int *fin = arreglo + capacidad;
        while(puntero_actual < fin)
        {
        if (*puntero_actual == valor_buscado)
        {
            return puntero_actual;
        }
        puntero_actual ++;
        }
        return NULL;
}

int distancia_punteros(const int *inicio, const int *puntero)
{
if (inicio == NULL || puntero == NULL || puntero < inicio)
{
    return -1;
}
int resultado = puntero - inicio;
return resultado;
}