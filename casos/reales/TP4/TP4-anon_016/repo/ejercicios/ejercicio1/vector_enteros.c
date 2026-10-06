/**
 * @file vector_enteros.c
 * @brief Implementación de clonación y filtrado dinámico de enteros (sin structs).
 */

#include <stdlib.h>
#include "vector_enteros.h"

int *clonar_arreglo_enteros(const int *origen, size_t cantidad)
{
   int *resultado = NULL;
   if (origen != NULL && cantidad != 0)
   {
        resultado = calloc( cantidad , sizeof(*resultado) );
    
        if(resultado != NULL)
        {
            int *destino = resultado;
            const int *fuente = origen;
            size_t copiados = 0;

            while (copiados < cantidad)
            {
                *destino = *fuente;
                destino++;
                copiados++;
                fuente++;
            }
        } 
   }
    return resultado;
}

int *filtrar_arreglo_pares(const int *origen, size_t cantidad_origen, size_t *cantidad_pares)
{
    int *resultado = NULL;

    if (origen != NULL && cantidad_pares != NULL)
    {
        *cantidad_pares = 0;

        int pares = 0;
        const int *inicio = origen;
        const int *fin = origen + cantidad_origen;
        while(inicio < fin)
        {
            if (*inicio % 2 == 0)
            {
                pares++;
            }
            inicio++;
        }
    
    if (pares > 0)
    {
        resultado = calloc( pares, sizeof(*resultado) );
        if(resultado != NULL)
    {
        int *destino = resultado;
        const int *fuente = origen;

        while (fuente < fin)
        {
             if (*fuente % 2 == 0)
            {
                *destino = *fuente;
                destino++;
            }
            fuente++;
        }
        *cantidad_pares = pares;
    } 
}
    }
    return resultado;
}
