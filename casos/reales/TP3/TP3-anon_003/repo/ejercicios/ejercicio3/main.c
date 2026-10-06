/**
 * @file main.c
 * @brief Programa principal del Ejercicio 3.
 */

#include <stdio.h>
#include "recorrido.h"


int main(void)
{
    printf("Ejercicio 3: Recorrido e inversión con punteros\n");
    printf("Ejercicio 3: Test copia origen destino\n");

    int origen[] = {1, 2, 3, 4, 5};
    size_t cantidad = 5;
    int destino[5];    
    copiar_arreglo(origen, destino);
    for (int i=0 ; i <= cantidad ; i++){
        printf("%d \n", destino[i] );
    }
    printf(" \n");
    return 0;
}
