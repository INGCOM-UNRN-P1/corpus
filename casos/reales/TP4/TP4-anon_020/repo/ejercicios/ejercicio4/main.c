/**
 * @file main.c
 * @brief Programa principal del Ejercicio 4.
 */

#include <stdio.h>
#include "consola.h"
#include "matriz_dinamica.h"

int main(void)
{
    int *matriz = NULL;
    size_t filas = 0U;
    size_t columnas = 0U;
    size_t fila = 0U;
    size_t columna = 0U;

    printf("Ejercicio 4: Matriz Dinámica 2D en Heap\n");

    filas = (size_t)leer_entero_entre("Cantidad de filas", 1, 10);
    columnas = (size_t)leer_entero_entre("Cantidad de columnas", 1, 10);

    matriz = crear_matriz_plana(filas, columnas);
    if (matriz == NULL)
    {
        printf("No se pudo reservar la matriz.\n");
        return 1;
    }

    for (fila = 0U; fila < filas; ++fila)
    {
        for (columna = 0U; columna < columnas; ++columna)
        {
            int valor = leer_entero("Ingrese el valor de la celda");
            asignar_celda(matriz, columnas, fila, columna, valor);
        }
    }

    printf("Matriz resultante:\n");
    for (fila = 0U; fila < filas; ++fila)
    {
        for (columna = 0U; columna < columnas; ++columna)
        {
            printf("%d ", obtener_celda(matriz, columnas, fila, columna));
        }
        printf("\n");
    }

    liberar_matriz_plana(matriz);
    return 0;
}