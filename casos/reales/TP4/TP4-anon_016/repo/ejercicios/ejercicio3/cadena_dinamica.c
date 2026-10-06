/**
 * @file cadena_dinamica.c
 * @brief Implementación para Ejercicio 3 (Cadenas en Heap).
 */

#include "cadena_dinamica.h"
#include "cadenas.h"

char *clonar_cadena(const char *origen)
{
    char *resultado = NULL;

    if (origen != NULL)
    {
        const char *fin = origen;
        while (*fin != '\0')
        {
            fin++;
        }
        
        resultado = cadena_duplicar_segura(origen, (size_t)(fin - origen) + 1);
    }

    return resultado;
}

char *unir_cadenas_dinamicas(const char *primera, const char *segunda)
{
    char *resultado = NULL;

    if (primera != NULL && segunda != NULL)
    {
        const char *fin_primera = primera;
        while (*fin_primera != '\0')
        {
            fin_primera++;
        }

        const char *fin_segunda = segunda;
        while (*fin_segunda != '\0')
        {
            fin_segunda++;
        }

        size_t cap_primera = (size_t)(fin_primera - primera) + 1;
        size_t cap_segunda = (size_t)(fin_segunda - segunda) + 1;

        
        resultado = cadena_unir_dinamica(primera, cap_primera,
                                         segunda, cap_segunda);
    }

    return resultado;
}