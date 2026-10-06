/**
 * @file main.c
 * @brief Programa principal del Ejercicio 3.
 */

#include <stdio.h>
#include "recorrido.h"

int main()
{
    int original [5] = {1, 2 ,3 ,4 ,5};
    int copia [5] = {0};
    int comienzo = 0;
    int final = 0;

    size_t cantidad = sizeof(original) / sizeof(original[0]);



    printf("Ejercicio 3: Recorrido e inversion con punteros\n");
    
    printf("copia de arreglo:\n");
    for (size_t i = 0; i < cantidad; i++)
    {
        copiar_arreglo(original, cantidad, copia);
        printf("%d ", copia[i]);
    }
    printf("\n");
    

    printf("inversion del arreglo:\n");
    invertir_arreglo(original, cantidad, &comienzo, &final);
    
    for (size_t j = 0; j < cantidad; j++)
    {
        printf("%d ", original[j]);
    }
    printf("\n");

    return 0;
}
