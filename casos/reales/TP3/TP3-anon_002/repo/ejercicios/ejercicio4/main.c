/**
 * @file main.c
 * @brief Programa principal del Ejercicio 4.
 */

#include <stdio.h>
#include "busqueda.h"

int main(void)
{
    printf("Ejercicio 4: Búsqueda con punteros\n");

    int arreglo[] = {10, 20, 30, 40, 50};

    const int *resultado = buscar_primero(arreglo, 5, 40);

    printf("Valor buscado: %d\n", *resultado);

    ptrdiff_t distancia = distancia_punteros(arreglo, resultado);

    printf("Posicion: %td\n", distancia);

    return 0;
}
