/**
 * @file main.c
 * @brief Programa principal del Ejercicio 6.
 */

#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include "ordenamiento.h"

int main(void)
{
    printf("Ejercicio 6: Ordenamiento por selección con punteros\n");
    int datos[] = {64, 25, 12, 22, 11, -5, 0};
    size_t cantidad = 7;

    printf("Arreglo desordenado: ");
    
    for (size_t k = 0; k < cantidad; k++)
    { 
        printf("%d ", *(datos + k));
    }
    
    printf("\\n");
    
    if (ordenar_seleccion_punteros(datos, cantidad))
    { 
        printf("Arreglo ordenado: ");
        
        for (size_t k = 0; k < cantidad; k++)
        { 
            printf("%d ", *(datos + k));
        } 

        printf("\\n\\n");
    } 
    else
    { 
        printf("Error al ordenar el arreglo.\\n");
    }
    
    return 0;
}
