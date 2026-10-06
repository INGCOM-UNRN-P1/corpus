/**
 * @file main.c
 * @brief Programa principal del Ejercicio 3.
 */

#include <stdio.h>
#include "recorrido.h"

int main(void)
{
    printf("Ejercicio 3: Recorrido e inversión con punteros\n");

    int orig[5] = {1, 2, 3, 4, 5};
    int dest[5] = {0};

    printf("arreglo original: ");
    for (int i = 0; i < 5; i++){
        printf("%d", orig[i]);
        printf("\n");
    }

    if (copiar_arreglo(orig, dest, 5)){
        printf("arreglo copiado en destino: ");
        for (int i = 0; i < 5; i++){
            printf("%d", dest[i]);
            printf("\n");
        }
    }

    if (invertir_arreglo(dest, 5)){
        printf("arreglo destino invertido: ");
        for (int i = 0; i < 5; i++){
            printf("%d", dest[i]);
            printf("\n");
        }
    }
    return 0;
}
