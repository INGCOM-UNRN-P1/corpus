/**
 * @file main.c
 * @brief Programa principal del Ejercicio 6.
 */

#include <stdio.h>
#include "ordenamiento.h"

int main(void)
{
    printf("Ejercicio 6: Ordenamiento por seleccion con punteros\n\n");

    int datos[] = {30, 10, 40, 20};
    size_t cantidad = sizeof(datos) / sizeof(datos[0]);

    printf("Antes:   %d %d %d %d\n", datos[0], datos[1], datos[2], datos[3]);

    ordenar_seleccion_punteros(datos, cantidad);

    printf("Despues: %d %d %d %d\n", datos[0], datos[1], datos[2], datos[3]);

    return 0;
}