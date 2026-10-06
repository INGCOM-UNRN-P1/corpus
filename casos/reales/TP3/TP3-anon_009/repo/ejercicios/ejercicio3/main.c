/**
 * @file main.c
 * @brief Programa principal del Ejercicio 3.
 */

#include <stdio.h>
#include "recorrido.h"

int main(void)
{
    printf("Ejercicio 3: Recorrido e inversión con punteros\n");
    
    int arreglo[] = {23, 52, 0, -3, 77, 5, 32};
    size_t cantidad = sizeof(arreglo)/sizeof(arreglo[0]);
    int copia[7] = {0};
    printf("---prueba de 'copiar_arreglo'--- \n");
    printf("arreglo original %d, copia(sin copiar): %d \n",*arreglo, *copia);
    copiar_arreglo(arreglo, cantidad, copia);
    printf("arreglo original: %d, copía: %d. \n", *arreglo, *copia);
    printf("---preuba de 'invertir_arreglo'---\n");
    printf("arreglo(sin invertir): %d. \n", *arreglo);
    invertir_arreglo(arreglo, cantidad);
    printf("arreglo invertido: %d \n", *arreglo);
    return 0;
}
