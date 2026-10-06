/**
 * @file vector.c
 * @brief Implementación de la biblioteca libvector (sin estructuras).
 */

#include <stdlib.h>
#include "vector.h"

int *crear_bloque_enteros(size_t cantidad)
{
    int *resultado = NULL;

    if ( cantidad > 0 )
    {
        resultado = calloc( cantidad , sizeof(*resultado) );
    }

    return resultado;
}

void liberar_bloque_enteros(int **puntero_bloque)
{
   if (puntero_bloque != NULL && *puntero_bloque != NULL)
   {
        free(*puntero_bloque);
        *puntero_bloque = NULL;
   }
}

int *redimensionar_bloque_enteros(int *bloque, size_t nueva_cantidad)
{
    int *resultado = NULL;

    if (nueva_cantidad == 0)
    {
        free(bloque);
    }
    else
    {
        int *temporal = realloc( bloque ,nueva_cantidad * sizeof(*temporal) );
        if ( temporal != NULL )
        {
            resultado = temporal;
        }
    }

    return resultado;
}




 int *fusionar_bloques_enteros(const int *primero, size_t cant_primero,
                              const int *segundo, size_t cant_segundo)
{
    int *resultado = NULL;

    size_t aporte_primero = 0;
    if (primero != NULL)
    {
        aporte_primero = cant_primero;
    }

    size_t aporte_segundo = 0;
    if (segundo != NULL)
    {
        aporte_segundo = cant_segundo;
    }

    size_t total = aporte_primero + aporte_segundo;

    if (total > 0)
    {
        resultado = malloc (total * sizeof(*resultado));
        if (resultado != NULL)
        {
            int *destino = resultado;
            const int *fuente_1 = primero;
            size_t copiados = 0;

            while (copiados < aporte_primero)
            {
                *destino = *fuente_1;
                destino++;
                copiados++;
                fuente_1++;
            }
             const int *fuente_2 = segundo;
            copiados = 0;
            while (copiados < aporte_segundo)
            {
                *destino = *fuente_2;
                destino++;
                copiados++;
                fuente_2++;
            }
            
        }
    }

    return resultado;
}

bool agregar_al_bloque_enteros(int **puntero_bloque, size_t *cantidad, int valor)
{
    bool resultado = false;

    if (puntero_bloque != NULL && cantidad != NULL)
    {
        int *temporal = realloc(*puntero_bloque, (*cantidad + 1) * sizeof(*temporal));
        if (temporal != NULL)
        {
            *puntero_bloque = temporal;
            (*puntero_bloque)[*cantidad] = valor;
            (*cantidad)++;
            resultado = true;
        }
    }

    return resultado;
}