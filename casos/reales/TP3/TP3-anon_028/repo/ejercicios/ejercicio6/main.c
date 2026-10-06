/**
 * @file main.c
 * @brief Programa principal del Ejercicio 6.
 */

#include <stdio.h>
#include "ordenamiento.h"

int main(void)
{
    printf("Ejercicio 6: Ordenamiento por selección con punteros\n");

    int datos[] = {64, 25, 12, 22, 11};
    size_t tam = sizeof(datos) / sizeof(datos[0]);

    printf("Arreglo original: ");
    for (size_t i = 0; i < tam; i++) {
        printf("%d ", *(datos + i));
    }
    printf("\n");

    if (ordenar_seleccion_punteros(datos, tam)) {
        printf("Arreglo ordenado: ");
        for (size_t i = 0; i < tam; i++) {
            printf("%d ", *(datos + i));
        }
        printf("\n");
    }

    return 0;
}