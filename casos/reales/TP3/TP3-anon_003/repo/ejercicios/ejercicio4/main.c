/**
 * @file main.c
 * @brief Programa principal del Ejercicio 4.
 */

#include <stdio.h>
#include "busqueda.h"

int main(void)
{
    printf("Ejercicio 4: Búsqueda con punteros\n");
    int arreglo[] = {10, 25, 30, 42, 50};
    size_t cantidad = 5;
    int buscado = 42;
    const int *resultado = buscar_primero(arreglo, cantidad, buscado);
    if (resultado != NULL){
        printf("encontrado en %d", *resultado);
    }
    
    if (buscar_primero(NULL, cantidad, buscado) == NULL) {
        printf("resultado NULL.\n");
    }
    return 0;
}
