/**
 * @file main.c
 * @brief Programa principal del Ejercicio 4.
 */

#include <stdio.h>
#include "busqueda.h"

int main(void)
{
    printf("Ejercicio 4: Búsqueda con punteros\n");
    size_t capacidad = 5;
    int valor_buscado = 3;
    int arreglo[] = {1, 5, 2, 3, 4};
    const int *encontrado = buscar_primero(arreglo, capacidad, valor_buscado);
    if (encontrado != NULL) {
   
        int posicion = distancia_punteros(arreglo, encontrado);
    
        printf("El valor buscado %d, aparecio por primera vez en" 
            "la posicion %d.\n", valor_buscado, posicion);
    } else {
        printf("El valor %d no se encontro en el arreglo.\n", valor_buscado);
    }
}