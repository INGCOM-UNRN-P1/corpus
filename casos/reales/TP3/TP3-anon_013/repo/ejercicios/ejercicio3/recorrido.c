/**
 * @file recorrido.c
 * @brief Implementación de recorrido, copia e inversión con aritmética de punteros.
 */

#include "recorrido.h"

bool copiar_arreglo (int *origen, size_t cantidad_origen, int *destino, size_t cantidad_destino, size_t inicio, size_t cantidad_a_copiar)
{
    if (origen == NULL || destino == NULL || inicio > cantidad_origen)
    {
        return false;
    }
    bool resultado = true;

    if (cantidad_a_copiar > cantidad_origen - inicio)
    {
        resultado = false;
        cantidad_a_copiar = cantidad_origen - inicio;
    }
    if (cantidad_a_copiar > cantidad_destino)
    {
        resultado = false;
        cantidad_a_copiar = cantidad_destino;
    }

    origen = origen + inicio;    // Coloco el puntero directamente en la posición desde donde comienza a copiar.
    for (size_t i = 0; i < cantidad_a_copiar; i++)
    {
        *destino = *origen;
        origen++;
        destino++;
    }
    return resultado;
}

bool invertir_arreglo (int *arreglo, size_t cantidad)
{
    if (arreglo == NULL)
    {
        return false;
    }
    if (cantidad == 0)
    {
        return true;
    }
    int *inicio = arreglo;
    int *fin = arreglo + cantidad - 1;
    while (inicio < fin)
    {
        intercambiar(inicio, fin);
        inicio++;
        fin--;
    }
    return true;
}