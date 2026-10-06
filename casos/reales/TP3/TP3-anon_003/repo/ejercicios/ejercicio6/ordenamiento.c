/**
 * @file ordenamiento.c
 * @brief Implementación de ordenamiento por selección empleando aritmética de punteros.
 *
 * @brief buscar_puntero_minimo
 * Busca el elemento mínimo dentro de un rango de enteros, recorriedo el puntero
 *
 * 
 *
 * @pre inicio debe apuntar al primer elemento del rango.
 * @pre fin debe apuntar al final del rango.
 *
 * @param inicio Puntero al primer elemento del rango.
 * @param fin Puntero al final del rango, sin incluirlo.
 *
 * @return Puntero constante al elemento mínimo.
 * @return NULL si el rango es inválido o inicio es NULL.
 *
 * @brief ordenar_seleccion_punteros
 * Ordena un arreglo de enteros de forma ascendente.
 *
 *
 * @pre arreglo debe apuntar a un arreglo válido.
 *
 * @param arreglo arreglo de enteros que se desea ordenar
 * @param cantidad cantidad de elementos del arreglo
 *
 * @return true si el arreglo fue ordenado correctamente.
 * @return false si el arreglo es NULL o la cantidad es invalida.
 */

#include "ordenamiento.h"

const int *buscar_puntero_minimo(const int *inicio, const int *fin)
{
    if (inicio == NULL || fin == NULL || inicio >= fin){
        return NULL;
    }

    const int *minimo = inicio;
    const int *actual = inicio + 1;

    while (actual < fin){
        if (*actual < *minimo){
            minimo = actual;
        }

        actual++;
    }

    return minimo;
}

bool ordenar_seleccion_punteros(int *arreglo, size_t cantidad)
{
    if (arreglo == NULL || cantidad < 2){
        return false;
    }

    int *actual = arreglo;
    int *fin = arreglo + cantidad;

    while (actual < fin - 1){
        const int *minimo = buscar_puntero_minimo(actual, fin);

        if (minimo != actual){
            int auxiliar = *actual;
            *actual = *minimo;
            *(int *)minimo = auxiliar;
        }

        actual++;
    }

    return true;
}
