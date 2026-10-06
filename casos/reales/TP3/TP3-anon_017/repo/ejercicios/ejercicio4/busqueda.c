/**
 * @file busqueda.c
 * @brief Implementación de búsqueda lineal con retorno de puntero y resta de punteros.
 */

#include "busqueda.h"

const int *buscar_primero(const int *arreglo, size_t cantidad, int valor)
{
    const int *ptr_salida = NULL;
    if((arreglo != NULL) && (cantidad > 0))
    {
        size_t contador = 0;
        bool bandera_salida = false;
        while((contador < cantidad) && !bandera_salida)
        {
            if(*arreglo == valor)
            {
                ptr_salida = arreglo;
                bandera_salida = true;
            }
            contador = contador + 1;
            arreglo = arreglo + 1;
        }
    }
    return ptr_salida;
}
