/**
 * @file puntero_cadena.c
 * @brief Implementación de copia y concatenación de cadenas mediante punteros.
 */

#include "puntero_cadena.h"

bool copiar_con_punteros(char *destino, size_t capacidad, const char *origen)
{
    if (destino == NULL || origen == NULL || capacidad == 0) {
        return false;
    }

    char *puntero_destino = destino;
    const char *puntero_origen = origen;
    size_t caracteres_copiados = 0;

    while (*puntero_origen != '\0' && caracteres_copiados < capacidad - 1) {
        *puntero_destino = *puntero_origen;
        puntero_destino++;
        puntero_origen++;
        caracteres_copiados++;
    }

    *puntero_destino = '\0';

    return (*puntero_origen == '\0');
}

bool concatenar_con_punteros(char *destino, size_t capacidad, const char *origen)
{
    if (destino == NULL || origen == NULL || capacidad == 0) {
        return false;
    }

    char *puntero_destino = destino;
    size_t espacio_ocupado = 0;

    while (*puntero_destino != '\0' && espacio_ocupado < capacidad) {
        puntero_destino++;
        espacio_ocupado++;
    }

    if (espacio_ocupado >= capacidad) {
        return false;
    }

    const char *puntero_origen = origen;

    while (*puntero_origen != '\0' && espacio_ocupado < capacidad - 1) {
        *puntero_destino = *puntero_origen;
        puntero_destino++;
        puntero_origen++;
        espacio_ocupado++;
    }

    *puntero_destino = '\0';

    return (*puntero_origen == '\0');
}
