/**
 * @file main.c
 * @brief Programa principal del Ejercicio 1.
 */

#include <stdio.h>
#include "vector.h"
#include "vector_enteros.h"
 
int main(void)
{
    int estado = 0;
 
    printf("Ejercicio 1: Vector Dinámico de Enteros\n");
 
    int datos[] = {1, 2, 3, 4, 5, 6};
    size_t cantidad = 6;
 
    int *clon = clonar_arreglo_enteros(datos, cantidad);
    if (clon == NULL) {
        printf("Error: no se pudo clonar el arreglo\n");
        estado = 1;
    } else {
        printf("Clon:");
        for (size_t i = 0; i < cantidad; ++i) {
            printf(" %d", clon[i]);
        }
        printf("\n");
 
        size_t cantidad_pares = 0;
        int *pares = filtrar_arreglo_pares(clon, cantidad, &cantidad_pares);
        if (pares == NULL) {
            printf("No hay pares en el arreglo\n");
        } else {
            printf("Pares (%zu):", cantidad_pares);
            for (size_t i = 0; i < cantidad_pares; ++i) {
                printf(" %d", pares[i]);
            }
            printf("\n");
        }
 
        liberar_bloque_enteros(&pares);
        liberar_bloque_enteros(&clon);
    }
    return estado;
}