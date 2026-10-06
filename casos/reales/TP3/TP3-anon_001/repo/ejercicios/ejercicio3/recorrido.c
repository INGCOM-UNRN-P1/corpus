/**
 * @file recorrido.c
 * @brief Implementación de recorrido, copia e inversión con aritmética de punteros.
 */

#include "recorrido.h"
#include "punteros.h"




bool copiar_arreglo(const int *origen, int *destino, size_t cantidad)
{
    bool estado = false;
    if ((origen != NULL) && (destino != NULL))
    {
        estado = true;
        for (size_t i = 0; i < cantidad; i++)
        {
            *destino = *origen;
            destino ++;
            origen++;
        }
    }
    return estado;
}


bool invertir_arreglo(int *arreglo, size_t cantidad)
{
    bool estado = false;
    if (arreglo != NULL)
    {
        estado = true;
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
    }

    return estado;
}