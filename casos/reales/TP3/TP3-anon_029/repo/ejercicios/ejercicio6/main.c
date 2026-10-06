/**
 * @file main.c
 * @brief Programa principal del Ejercicio 6.
 */

#include <stdio.h>
#include "ordenamiento.h"

int main(void)
{
    printf("Ejercicio 6: Ordenamiento por selección con punteros\n");
    int arreglo[] = {0, 5, 4, 3, 1, 2};
    size_t capacidad = 0;
    size_t indice = 0;
    const int *minimo = buscar_puntero_minimo(arreglo, arreglo + 6);
    printf("El elemento minimo del arreglo es: %d\n",*minimo);

    const int *resultado = ordenar_seleccion_punteros(arreglo, 6);
    if (resultado != NULL)
{
    printf("Arreglo ordenado: ");
    for (indice = 0; indice < capacidad; indice++)
    {
        printf("%d ", *(resultado + indice)); 
    }
    printf("\n");
}
else
{
    printf("Error al ordenar el arreglo.\n");
}
    return 0;
}
