/**
 * @file main.c
 * @brief Programa principal del Ejercicio 1.
 */

#include "vector_enteros.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    size_t cantidad_origen = 0;

    printf("=== Ejercicio 1: Gestion de Arreglos Dinamicos ===\n\n");
    printf("Ingrese la cantidad de elementos del arreglo: ");
    if (scanf("%zu", &cantidad_origen) != 1 || cantidad_origen == 0) {
        printf("Cantidad invalida o arreglo vacio.\n");
        return 1;
    }

    int *origen = malloc(cantidad_origen * sizeof(int));
    if (origen == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    printf("Ingrese %zu numeros enteros separados por espacio:\n", cantidad_origen);
    for (size_t i = 0; i < cantidad_origen; i++) {
        if (scanf("%d", &origen[i]) != 1) {
            printf("Lectura de dato invalida.\n");
            free(origen);
            return 1;
        }
    }

    //  Demostración 1: clonar_arreglo_enteros 
    int *clon = clonar_arreglo_enteros(origen, cantidad_origen);
    printf("\n--- Demostracion: clonar_arreglo_enteros ---\n");
    if (clon != NULL) {
        printf("Copia creada exitosamente en otra direccion de memoria.\n");
        printf("Arreglo clonado: [ ");
        for (size_t i = 0; i < cantidad_origen; i++) {
            printf("%d ", clon[i]);
        }
        printf("]\n");
    } else {
        printf("Error al clonar el arreglo.\n");
    }

    // Demostración 2: filtrar_arreglo_pares
    size_t cantidad_pares = 0;
    int *pares = filtrar_arreglo_pares(origen, cantidad_origen, &cantidad_pares);

    printf("\n--- Demostracion: filtrar_arreglo_pares ---\n");
    printf("Cantidad de numeros pares encontrados: %zu\n", cantidad_pares);

    if (pares != NULL && cantidad_pares > 0) {
        printf("Arreglo de pares: [ ");
        for (size_t i = 0; i < cantidad_pares; i++) {
            printf("%d ", pares[i]);
        }
        printf("]\n");
    } else {
        printf("No se encontraron elementos pares en el arreglo.\n");
    }

    // Liberación de memoria reservada en el heap
    free(origen);
    free(clon);
    free(pares);

    return 0;
}
