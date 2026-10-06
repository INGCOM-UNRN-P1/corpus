/**
 * @file recorrido.c
 * @brief Implementación de recorrido, copia e inversión con aritmética de punteros.
 */

#include "recorrido.h"
#include "punteros.h"


bool copiar_arreglo(const int *origen, size_t cantidad, int *destino)
{
    bool exito = false;

    if (origen != NULL && destino != NULL)
    {
        const int *actual_origen = origen;
        const int *fin_origen = origen + cantidad;
        int *actual_destino = destino;

        while (actual_origen < fin_origen)
        {
            *actual_destino = *actual_origen;
            actual_origen++;
            actual_destino++;
        }
        exito = true;
    }
    return exito;
}

bool invertir_arreglo(int *arreglo, size_t cantidad)
{
    bool exito = false;

    if (arreglo != NULL)
    {
        if (cantidad > 0)
        {
            int *inicio = arreglo;
            int *fin = arreglo + cantidad - 1;

            while (inicio < fin)
            {
                intercambiar(inicio, fin);
                inicio++;
                fin--;
            }
        }
        exito = true;
    }
    return exito;
}