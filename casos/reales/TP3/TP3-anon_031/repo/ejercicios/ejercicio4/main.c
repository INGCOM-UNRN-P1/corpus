/**
 * @file main.c
 * @brief Programa principal del Ejercicio 4.
 */

#include <stdio.h>
#include "busqueda.h"

int main(void)
{
    int datos[] = {10, 25, 30, 25, 50};
    size_t cantidad = 5;
    int valor_buscado = 25;

    const int *encontrado = buscar_primero(datos, cantidad, valor_buscado);

    printf("Ejercicio 4: Busqueda con punteros\n");

    if (encontrado != NULL)
    {
        ptrdiff_t posicion = distancia_punteros(datos, encontrado);

        printf("Valor encontrado: %d\n", *encontrado);
        printf("Posicion relativa: %td\n", posicion);
    }
    else
    {
        printf("El valor no fue encontrado.\n");
    }

    return 0;
}
