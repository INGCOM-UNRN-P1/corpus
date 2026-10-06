/**
 * @file main.c
 * @brief Programa principal del Ejercicio 3.
 */

#include <stdio.h>
#include "recorrido.h"

static void mostrar(const char *titulo, const int *arreglo, size_t cantidad)
{
    const int *fin = arreglo + cantidad;

    printf("%s: [", titulo);
    while (arreglo < fin)
    {
        printf("%d", *arreglo);
        arreglo++;
        if (arreglo < fin)
        {
            printf(", ");
        }
    }
    printf("]\n");
}

int main(void)
{
    printf("ejercicio 3 : recorrido e inversion con pinteros\n");

    int origen[] = {1, 2, 3, 4, 5};
    size_t cantidad = sizeof(origen) / sizeof(origen[0]);
    int destino[8] = {0};
    size_t capacidad = sizeof(destino) / sizeof(destino[0]);

    mostrar("origen", origen, cantidad);

    if (copiar_arreglo(destino, capacidad, origen, cantidad))
    {
        mostrar("copia en destino", destino, capacidad);
    }

    if (invertir_arreglo(destino, cantidad));
    {
        mostrar("destino invertido", destino, capacidad);
    }

    int pequeno[2] = {0};
    if (!copiar_arreglo(pequeno, 2, origen, cantidad))
    {
        printf("copia rechazada: destino sin capacidad suficiente\n");
    }
    
    return 0;
}
