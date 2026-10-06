    /**
     * @file busqueda.c
     * @brief Implementación de búsqueda lineal con retorno de puntero y resta de punteros.
     */

    #include "busqueda.h"

    const int *buscar_primero(const int *arreglo, size_t cantidad, int valor)
    {
        if (arreglo == NULL || cantidad == 0)
        {
            return NULL;
        }

        const int *fin = arreglo + cantidad;

        for (const int *p = arreglo; p < fin; p++)
        {
            if (*p == valor)
            {
                return p; 
            }
        }

        return NULL; 
    }

    int distancia_punteros(const int *inicio, const int *elemento)
    {
        if (inicio == NULL || elemento == NULL || elemento < inicio)
        {
            return -1;
        }

        return (int)(elemento - inicio);
    }