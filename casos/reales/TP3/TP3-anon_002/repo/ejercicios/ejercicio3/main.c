/**
 * @file main.c
 * @brief Programa principal del Ejercicio 3.
 */

#include <stdio.h>
#include "recorrido.h"

int main(void)
{
    printf("Ejercicio 3: Recorrido e inversión con punteros\n");

    int fuente[] = {10, 20, 30, 40, 50};
    int destino[] = {0, 0, 0, 0, 0};

    copiar_arreglo(fuente, destino, 5);

    printf("Arreglo copiado: ");
    printf("%d %d %d %d %d\n",*destino, *(destino + 1), *(destino + 2), *(destino + 3), *(destino + 4));

    invertir_arreglo(destino, 5);

    printf("Arreglo invertido: ");
    printf("%d %d %d %d %d\n", *destino, *(destino + 1), *(destino + 2), *(destino + 3), *(destino + 4));

    return 0;
}
