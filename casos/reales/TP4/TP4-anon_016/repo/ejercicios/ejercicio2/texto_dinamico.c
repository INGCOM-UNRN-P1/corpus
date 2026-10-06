/**
 * @file texto_dinamico.c
 * @brief Implementación de funciones de texto dinámico en heap.
 */

#include <stdlib.h>
#include "texto_dinamico.h"

char *cadena_recortar_espacios(const char *origen)
{
    char *resultado = NULL;
 
    if (origen != NULL)
    {
        const char *inicio = origen;
        while (*inicio == ' ')
        {
            inicio++;
        }
 
        const char *fin = inicio;
        while (*fin != '\0')
        {
            fin++;
        }
 
        while (fin > inicio && *(fin - 1) == ' ')
        {
            fin--;
        }
 
        size_t cantidad = (size_t)(fin - inicio);
        if (cantidad > 0)
        {
            resultado = cadena_subcadena_dinamica(inicio, cantidad, 0,
                                                  cantidad);
        }
    }
 
    return resultado;
}
 
char *cadena_repetir(const char *origen, size_t veces)
{
    char *resultado = NULL;
 
    if (origen != NULL)
    {
        const char *recorrido = origen;
        size_t longitud = 0;
        while (*recorrido != '\0')
        {
            longitud++;
            recorrido++;
        }
 
        resultado = malloc((longitud * veces + 1) * sizeof(*resultado));
        if (resultado != NULL)
        {
            char *destino = resultado;
            size_t contador = 0;
 
            while (contador < veces)
            {
                const char *fuente = origen;
                while (*fuente != '\0')
                {
                    *destino = *fuente;
                    destino++;
                    fuente++;
                }
                contador++;
            }
            *destino = '\0';
        }
    }
 
    return resultado;
}
