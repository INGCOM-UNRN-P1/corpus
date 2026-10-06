/**
 * @file main.c
 * @brief Programa principal del Ejercicio 1.
 */

#include <stdio.h>
#include "vector.h"
#include "vector_enteros.h"

static void imprimir_bloque(const char *titulo, const int *bloque, size_t cantidad)
{
    printf("%s (%zu elementos):", titulo, cantidad);
    for (size_t i = 0; i < cantidad; ++i) {
        printf(" %d", bloque[i]);
    }
    printf("\n");
}
 
int main(void)
{
    printf("Ejercicio 1: Vector Dinámico de Enteros\n");
 
    int datos[] = {1, 4, 7, 8, 10, 13};
    size_t cantidad = sizeof(datos) / sizeof(datos[0]);
    imprimir_bloque("Original", datos, cantidad);
 
    
    int *clon = clonar_arreglo_enteros(datos, cantidad);
    if (clon == NULL) {
        fprintf(stderr, "Error: no se pudo clonar el arreglo\n");
        return 1;
    }
    imprimir_bloque("Clon en heap", clon, cantidad);
 
    
    size_t cant_pares = 0;
    int *pares = filtrar_arreglo_pares(clon, cantidad, &cant_pares);
    if (pares == NULL) {
        printf("El clon no contiene numeros pares\n");
    } else {
        imprimir_bloque("Pares", pares, cant_pares);
    }
 
    
    int impares[] = {1, 3, 5};
    size_t cant_impares = 99;
    int *ninguno = filtrar_arreglo_pares(impares, 3, &cant_impares);
    printf("Filtrar {1, 3, 5}: %s (cantidad = %zu)\n",
           ninguno == NULL ? "NULL" : "bloque", cant_impares);
 
    
    liberar_bloque_enteros(&ninguno);
    liberar_bloque_enteros(&pares);
    liberar_bloque_enteros(&clon);
    return 0;
}