/**
 * @file main.c
 * @brief Programa principal del Ejercicio 4.
 */

#include <stdio.h>
#include "busqueda.h"

int main(void)
{
    printf("Ejercicio 4: Búsqueda con punteros\n");

    int arreglo[5] = {10, 20, 30, 40, 50};
    int valor_buscado = 40;

    const int *encontrado = buscar_primero(arreglo, 5, valor_buscado);
    
    if (encontrado != NULL) {
        long dist = distancia_punteros(arreglo, encontrado);
        printf("El valor %d fue encontrado en el índice relativo %ld.\n", valor_buscado, dist);
    } else {
        printf("El valor %d no fue encontrado.\n", valor_buscado);
    }

    return 0;
}
