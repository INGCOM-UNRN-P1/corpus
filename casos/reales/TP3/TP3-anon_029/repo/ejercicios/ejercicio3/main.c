/**
 * @file main.c
 * @brief Programa principal del Ejercicio 3.
 */

#include <stdio.h>
#include "recorrido.h"

int main(void)
{
    printf("Ejercicio 3: Recorrido e inversión con punteros\n");
    int origen[] = {1, 2, 3, 4, 5};
    size_t capacidad = sizeof(origen) / sizeof(origen[0]);
    int destino[capacidad];
    
    copiar_arreglo(origen, destino, capacidad);
    printf("\nCopiar arreglo:\n");
    const int *puntero = destino;
    const int *fin = destino + capacidad;
    while (puntero < fin)
    {
        printf("%d ", *puntero);
        puntero++;
    }

    arreglo_invertir(destino, capacidad);
    puntero = destino; //reinicio el puntero
    printf("\nArreglo invertido:\n");
    while (puntero < fin)
    {
        printf("%d ", *puntero);
        puntero++;
    }
    printf("\n");
    return 0;
}
