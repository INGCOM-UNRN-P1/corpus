/**
 * @file recorrido.c
 * @brief Implementación de recorrido, copia e inversión con aritmética de punteros.
 */

#include "recorrido.h"
#include "punteros.h"

bool copiar_arreglo(const int *origen, int *destino, size_t cantidad)
{
    bool operacion_exitosa = false;

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

        operacion_exitosa = true;
    }

    return operacion_exitosa;
}

bool invertir_arreglo(int *arreglo, size_t cantidad)
{
    bool operacion_exitosa = false;

    if (arreglo != NULL)
    {
        if (cantidad > 1)
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

        operacion_exitosa = true;
    }

    return operacion_exitosa;
}
