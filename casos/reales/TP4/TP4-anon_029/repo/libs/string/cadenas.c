/**
 * @file string.c
 * @brief Implementación de la biblioteca libstring.
 */

#include "cadenas.h"
#include <stdlib.h>
/**
 * @brief Descripción de la función cadena_duplicar_segura.
 *
 * @param origen Descripción del parámetro origen.
 * @param capacidad_max Descripción del parámetro capacidad_max.
 * @return Descripción del valor de retorno.
 */
char *cadena_duplicar_segura(const char *origen, size_t capacidad_max)
{
    if (origen == NULL || capacidad_max == 0)
    {
        return NULL;
    }

    char *copia = (char *)malloc((capacidad_max + 1) * (sizeof(char)));

    if (copia == NULL)
    {
        return NULL;
    }

    cadena_copiar(copia, (capacidad_max + 1), origen);

    return copia;
}

/**
 * @brief Descripción de la función cadena_unir_dinamica.
 *
 * @param primera Descripción del parámetro primera.
 * @param cap_primera Descripción del parámetro cap_primera.
 * @param segunda Descripción del parámetro segunda.
 * @param cap_segunda Descripción del parámetro cap_segunda.
 * @return Descripción del valor de retorno.
 */
char *cadena_unir_dinamica(const char *primera, size_t cap_primera,
                           const char *segunda, size_t cap_segunda)
{
    if (primera == NULL || segunda == NULL || cap_primera == 0 ||
        cap_segunda == 0)
    {
        return NULL;
    }

    size_t largo_total = cadena_longitud(primera, cap_primera) +
                         cadena_longitud(segunda, cap_segunda) + 1;

    char *cadena_unida = (char *)malloc((largo_total) * (sizeof(char)));

    if (cadena_unida == NULL) // valida que haya espacio en memoria
    {
        return NULL;
    }

    
    cadena_copiar(cadena_unida, (largo_total), primera);

    cadena_concatenar(cadena_unida, largo_total, segunda);

    return cadena_unida;
}

/**
 * @brief Descripción de la función cadena_liberar_segura.
 *
 * @param puntero_cadena Descripción del parámetro puntero_cadena.
 */
void cadena_liberar_segura(char **puntero_cadena)
{
    if (puntero_cadena == NULL || *puntero_cadena == NULL)
    {
        return;
    }

    free(*puntero_cadena);

    *puntero_cadena = NULL;
}

/**
 * @brief Descripción de la función cadena_subcadena_dinamica.
 *
 * @param origen Descripción del parámetro origen.
 * @param capacidad_max Descripción del parámetro capacidad_max.
 * @param inicio Descripción del parámetro inicio.
 * @param cantidad Descripción del parámetro cantidad.
 * @return Descripción del valor de retorno.
 */
char *cadena_subcadena_dinamica(const char *origen, size_t capacidad_max,
                                size_t inicio, size_t cantidad)
{
    if (origen == NULL || capacidad_max == 0)
    {
        return NULL;
    }

    size_t largo = cadena_longitud(origen, capacidad_max);

    if (inicio >= largo || cantidad == 0)
    {
        char *vacia = (char *)malloc(1 * (sizeof(char)));

        if (vacia == NULL)
        {
            return NULL;
        }

        vacia[0] = '\0';

        return vacia;
    }

    char *pedazo_cadena = (char *)malloc((cantidad + 1) * (sizeof(char)));

    cadena_subcadena(pedazo_cadena, (cantidad + 1), origen, inicio, cantidad);

    return pedazo_cadena;
}

/**
 * @brief Descripción de la función cadena_invertir_dinamica.
 *
 * @param origen Descripción del parámetro origen.
 * @param capacidad_max Descripción del parámetro capacidad_max.
 * @return Descripción del valor de retorno.
 */
char *cadena_invertir_dinamica(const char *origen, size_t capacidad_max)
{
    if (origen == NULL || capacidad_max == 0)
    {
        return NULL;
    }

    char *invertida = (char *)malloc((capacidad_max + 1) * (sizeof(char)));

    if (invertida == NULL)
    {
        return NULL;
    }

    size_t largo = cadena_longitud(origen, capacidad_max);

    if (largo == 0)
    {
        char *vacia = (char *)malloc(1 * (sizeof(char)));

        if (vacia == NULL)
        {
            return NULL;
        }

        vacia[0] = '\0';

        return vacia;
    }

    cadena_invertir(invertida, largo);

    return invertida;
}
