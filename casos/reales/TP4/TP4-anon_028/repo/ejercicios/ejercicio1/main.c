/**
 * @file main.c
 * @brief Programa principal del Ejercicio 1.
 */

#include <stdio.h>
#include "vector.h"
#include "vector_enteros.h"

int main(void)
{
    printf("ejercicio 1:\n");
    int datos[] = {1, 4, 7, 8, 10, 13};
    size_t tamano = sizeof(datos) / sizeof (datos[0]);

    int *clon = clonar_arreglo_enteros(datos, tamano);
    if (clon != NULL){
        printf("arreglo clonado en heap\n");
        liberar_bloque_enteros(&clon);
    }
    
    size_t cant_pares = 0;
    int *pares = filtrar_arreglo_pares(datos, tamano, &cant_pares);
    if (*pares != NULL){
        printf("pares encontrados (%zu): ", cant_pares);
        for (size_t i = 0; i < cant_pares; i++){
            printf("%d", pares[i]);
        }
        printf("\n");
        liberar_bloque_enteros(&pares);
    }
    return 0;
}
