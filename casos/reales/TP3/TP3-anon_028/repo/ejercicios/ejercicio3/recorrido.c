/**
 * @file recorrido.c
 * @brief Implementación de recorrido, copia e inversión con aritmética de punteros.
 */

#include "recorrido.h"
#include "punteros.h"

bool copiar_arreglo(const int *origen, int *destino, size_t cantidad)
{
    if (origen == NULL || destino == NULL) {
        return false;
    }

    const int *puntero_origen = origen;
    const int *puntero_origen_fin = origen + cantidad;
    int *puntero_destino = destino;

    while (puntero_origen < puntero_origen_fin) {
        *puntero_destino = *puntero_origen;
        puntero_origen++;
        puntero_destino++;
    }

    return true;
}

bool invertir_arreglo(int *arreglo, size_t cantidad)
{
    if (arreglo == NULL) {
        return false;
    }

    if (cantidad <= 1) {
        return true;
    }

    int *inicio = arreglo;
    int *fin = arreglo + cantidad - 1;

    while (inicio < fin) {
        intercambiar(inicio, fin);
        inicio++;
        fin--;
    }

    return true;
}

