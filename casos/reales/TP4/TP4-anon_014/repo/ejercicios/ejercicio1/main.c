/**
 * @file main.c
 * @brief Programa principal del Ejercicio 1.
 */

#include <stdio.h>
#include "vector.h"
#include "vector_enteros.h"

static void mostrar_bloque(const char *titulo, const int *bloque,
                           size_t cantidad);

int main(void)
{
    printf("Ejercicio 1: Vector Dinámico de Enteros\n");

    int datos[] = {-3, 4, 7, -8, 10, 0, 13};
    size_t cantidad = sizeof(datos) / sizeof(datos[0]);
    mostrar_bloque("Original", datos, cantidad);

    int *clon = clonar_arreglo_enteros(datos, cantidad);
    if (clon == NULL)
    {
        fprintf(stderr, "No se pudo clonar el arreglo\n");
        return 1;
    }
    mostrar_bloque("Clon", clon, cantidad);

    size_t cantidad_pares = 0;
    int *pares = filtrar_arreglo_pares(clon, cantidad, &cantidad_pares);
    mostrar_bloque("Pares", pares, cantidad_pares);

    size_t cantidad_positivos = 0;
    int *positivos = filtrar_bloque_positivos(clon, cantidad,
                                              &cantidad_positivos);
    mostrar_bloque("Positivos", positivos, cantidad_positivos);

    liberar_bloque_enteros(&positivos);
    liberar_bloque_enteros(&pares);
    liberar_bloque_enteros(&clon);
    return 0;
}

/**
 * @brief Muestra un bloque de enteros por salida estándar.
 * @param titulo texto que precede a los valores.
 * @param bloque bloque a mostrar (puede ser NULL si cantidad es 0).
 * @param cantidad cantidad de elementos.
 */
static void mostrar_bloque(const char *titulo, const int *bloque,
                           size_t cantidad)
{
    printf("%s (%zu):", titulo, cantidad);
    for (size_t i = 0; i < cantidad; i++)
    {
        printf(" %d", bloque[i]);
    }
    printf("\n");
}
