/**
 * @file main.c
 * @brief Programa principal del Ejercicio 4.
 */

#include "matriz_dinamica.h"
#include <stdio.h>

void prueba_ejercicio_4()
{
    printf("Ejercicio 4: Matriz Dinámica 2D en Heap\n");
    size_t filas = 0;
    size_t columnas = 0;
    int **matriz = matriz_cargar_desde_csv("matriz.csv", &filas, &columnas);
    if (matriz != NULL)
    {
        for (size_t indice_filas = 0; indice_filas < filas; indice_filas++)
        {
            for (size_t indice_columnas = 0; indice_columnas < columnas;
                 indice_columnas++)
            {
                printf("%d,", *(*(matriz + indice_filas) + indice_columnas));
            }
            printf("\n");
        }
        matriz_destruir(matriz);
        matriz = NULL;
    }
    else
    {
        return -1;
    }
}
int main(void)
{
    prueba_ejercicio_4;
    return 0;
}
