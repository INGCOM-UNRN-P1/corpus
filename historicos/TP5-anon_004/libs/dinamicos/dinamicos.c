/**
 * @file dinamicos.c
 * @brief Implementacion de la biblioteca libdinamicos con structs.
 *
 * Trabajo Practico 5 - Programacion 1
 * Universidad Nacional de Rio Negro - Ingenieria en Computacion
 */

#include <stdlib.h>
#include "dinamicos.h"

bool arreglo_dinamico_crear(arreglo_dinamico_t *arreglo, size_t capacidad_inicial)
{
    size_t cap = 0;
    int *bloque = NULL;

    if (arreglo == NULL) {
        return false;
    }
    cap = (capacidad_inicial == 0) ? 4 : capacidad_inicial;
    bloque = malloc(cap * sizeof(int));
    if (bloque == NULL) {
        arreglo->datos = NULL;
        arreglo->cantidad = 0;
        arreglo->capacidad = 0;
        return false;
    }
    arreglo->datos = bloque;
    arreglo->cantidad = 0;
    arreglo->capacidad = cap;
    return true;
}

void arreglo_dinamico_destruir(arreglo_dinamico_t *arreglo)
{
    if (arreglo == NULL) {
        return;
    }
    free(arreglo->datos);
    arreglo->datos = NULL;
    arreglo->cantidad = 0;
    arreglo->capacidad = 0;
}

bool arreglo_dinamico_agregar(arreglo_dinamico_t *arreglo, int valor)
{
    size_t nueva_capacidad = 0;
    int *nuevo_bloque = NULL;

    if (arreglo == NULL || arreglo->datos == NULL) {
        return false;
    }
    if (arreglo->cantidad >= arreglo->capacidad) {
        nueva_capacidad = (arreglo->capacidad == 0) ? 4 : (arreglo->capacidad * 2);
        nuevo_bloque = realloc(arreglo->datos, nueva_capacidad * sizeof(int));
        if (nuevo_bloque == NULL) {
            return false;
        }
        arreglo->datos = nuevo_bloque;
        arreglo->capacidad = nueva_capacidad;
    }
    arreglo->datos[arreglo->cantidad] = valor;
    arreglo->cantidad++;
    return true;
}

int *arreglo_dinamico_obtener(const arreglo_dinamico_t *arreglo, size_t indice)
{
    if (arreglo == NULL || arreglo->datos == NULL || indice >= arreglo->cantidad) {
        return NULL;
    }
    return arreglo->datos + indice;
}

bool arreglo_dinamico_filtrar_pares(const arreglo_dinamico_t *origen,
                                    arreglo_dinamico_t *destino)
{
    size_t i = 0;

    if (origen == NULL || origen->datos == NULL || destino == NULL || origen == destino) {
        return false;
    }
    if (!arreglo_dinamico_crear(destino, (origen->cantidad > 0) ? origen->cantidad : 4)) {
        return false;
    }
    for (i = 0; i < origen->cantidad; i++) {
        if (origen->datos[i] % 2 == 0) {
            if (!arreglo_dinamico_agregar(destino, origen->datos[i])) {
                arreglo_dinamico_destruir(destino);
                return false;
            }
        }
    }
    return true;
}

int arreglo_dinamico_buscar(const arreglo_dinamico_t *arreglo, int valor)
{
    size_t i = 0;

    if (arreglo == NULL || arreglo->datos == NULL) {
        return -1;
    }
    for (i = 0; i < arreglo->cantidad; i++) {
        if (arreglo->datos[i] == valor) {
            return (int)i;
        }
    }
    return -1;
}

void arreglo_dinamico_invertir(arreglo_dinamico_t *arreglo)
{
    size_t i = 0;
    size_t j = 0;
    int temp = 0;

    if (arreglo == NULL || arreglo->datos == NULL || arreglo->cantidad <= 1) {
        return;
    }
    i = 0;
    j = arreglo->cantidad - 1;
    while (i < j) {
        temp = arreglo->datos[i];
        arreglo->datos[i] = arreglo->datos[j];
        arreglo->datos[j] = temp;
        i++;
        j--;
    }
}

size_t arreglo_dinamico_compactar(arreglo_dinamico_t *arreglo, int valor)
{
    size_t j = 0;
    size_t eliminados = 0;
    size_t i = 0;

    if (arreglo == NULL || arreglo->datos == NULL || arreglo->cantidad == 0) {
        return 0;
    }
    for (i = 0; i < arreglo->cantidad; i++) {
        if (arreglo->datos[i] != valor) {
            arreglo->datos[j] = arreglo->datos[i];
            j++;
        } else {
            eliminados++;
        }
    }
    arreglo->cantidad = j;
    return eliminados;
}
