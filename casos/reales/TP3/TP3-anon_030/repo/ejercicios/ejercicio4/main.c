/**
 * @file main.c
 * @brief Programa principal del Ejercicio 4.
 */

#include <stdio.h>
#include "busqueda.h"

int main(void)
{
    int arreglo[] = {10, 20, 30, 40, 30};
    size_t cantidad = 5;
    int valor;

    printf("Ejercicio 4: Busqueda con punteros\n");

    printf("Arreglo: ");

    const int *actual = arreglo;
    const int *fin = arreglo + cantidad;

    while (actual < fin)
    {
        printf("%d ", *actual);
        actual++;
    }

    printf("\n");

    printf("Ingrese el valor a buscar: ");
    scanf("%d", &valor);

    const int *encontrado = buscar_primero(arreglo, cantidad, valor);

    if (encontrado != NULL)
    {
        ptrdiff_t posicion = distancia_punteros(arreglo, encontrado);

        printf("Valor encontrado: %d\n", *encontrado);
        printf("Posicion: %td\n", posicion);
    }
    else
    {
        printf("El valor no se encuentra en el arreglo.\n");
    }

    return 0;
}
