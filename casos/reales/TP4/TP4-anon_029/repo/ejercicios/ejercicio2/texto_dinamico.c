/**
 * @file texto_dinamico.c
 * @brief Implementación de funciones de texto dinámico en heap.
 */

#include "texto_dinamico.h"
#include <stdlib.h>

/**
 * @brief Descripción de la función cadena_recortar_espacios.
 *
 * @param origen Descripción del parámetro origen.
 * @return Descripción del valor de retorno.
 */
char *cadena_recortar_espacios(const char *origen)
{
    size_t indice = 0;
    size_t inicio = 0;
    size_t fin = 0;
    size_t largo = 0;
    if (origen == NULL)
    {
        return NULL;
    }

    while (origen[indice] == ' ' && origen[indice] != '\0')
    {
        indice++;
        inicio++;
    }

    if (origen[inicio] == '\0')
    {
        return NULL;
    }

    fin = inicio;

    while (origen[fin] != '\0')
    {
        fin++;
    }
    fin--; // ultimo caracter visible(anterior al '\0').

    while (fin > inicio && origen[fin] == ' ')
    {
        fin--;
    }
    size_t cantidad = ((fin - inicio) + 1);

    while (origen[largo] != '\0')
    {
        largo++;
    }

    char *limpio =
        cadena_subcadena_dinamica(origen, (largo + 1), inicio, cantidad);

    return limpio;
}

/**
 * @brief Descripción de la función cadena_repetir.
 *
 * @param origen Descripción del parámetro origen.
 * @param veces Descripción del parámetro veces.
 * @return Descripción del valor de retorno.
 */
char *cadena_repetir(const char *origen, size_t veces)
{
    size_t largo = 0;
    if (origen == NULL)
    {
        return NULL;
    }

    const char *aux = origen;
    while (*aux != '\0')
    {
        largo++;
        aux++;
    }

    if (veces == 0 || largo == 0)
    {
        char *vacia = (char *)calloc(1, sizeof(char));
        if (vacia != NULL)
        {
            vacia[0] = '\0';
        }
        return vacia;
    }

    size_t largo_total = ((largo * veces) + 1);

    char *repetido = (char *)calloc(largo_total, sizeof(char));

    if (repetido == NULL)
    {
        return NULL;
    }

    for (size_t vueltas = 0; vueltas < veces; vueltas++)
    {
        cadena_copiar(repetido + (vueltas * largo), (largo + 1), origen);
        
    }
    *(repetido + (largo * veces)) = '\0';

    return repetido;
}
