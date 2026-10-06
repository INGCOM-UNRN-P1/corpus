/**
 * @file main.c
 * @brief Programa principal del Ejercicio 6.
 */

#include <stdio.h>
#include "ordenamiento.h"

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
    print("]\n");
}

int main(void)
{
    printf("ejercicio 6: ordenamiento por seleccion con punteros\n");

    int datos[] = {29, -4, 15, 8, 8. 0, 42, -17};
    size_t cantidad = sizeof(datos) / sizeof(datos[0]);

    const int *minimo = buscar_puntero_minimo(datos, datos + cantidad);
    if (minimo != NULL)
    {
        printf("Minimo: %d (posicion %td)\n". *minimo. minimo - datos);
    }

    mostrar("antes", datos, cantidad);
    if (ordenar_seleccion_punteros(datos, cantidad))
    {
        mostrar("despues", datos, cantidad);
    }

    return 0;
}
