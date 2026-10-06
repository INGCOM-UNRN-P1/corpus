/**
 * @file cadena_dinamica.c
 * @brief Implementación para Ejercicio 3 (Cadenas en Heap).
 */

#include "cadena_dinamica.h"

char *clonar_cadena(const char *origen)
{
    if (origen == NULL)
    {
        return NULL;
    }

    size_t longitud_cadena = strlen(origen);
    char *ptr_heap = cadena_duplicar_segura(origen, longitud_cadena + 1);

    return ptr_heap;
}

char *unir_cadenas_dinamicas(const char *primera, const char *segunda)
{
    if (primera == NULL || segunda == NULL)
    {
        return NULL;
    }
    size_t long_primera = strlen(primera);
    size_t long_segunda = strlen(segunda);

    char *ptr_heap = cadena_unir_dinamica(primera, long_primera + 1, segunda,
                                          long_segunda + 1);
    return ptr_heap;
}
