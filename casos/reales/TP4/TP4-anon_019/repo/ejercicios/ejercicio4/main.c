#include <stdio.h>
#include <stdlib.h>
#include "matriz_dinamica.h"

int main(void)
{
    printf("ejercicio 4: matriz dinamica 2d en heap\n\n");

    size_t filas = 3;
    size_t columnas = 4;
    
    int **matriz = matriz_crear(filas, columnas);
    
    if (matriz != NULL)
    {
        printf("matriz de %zux%zu creada exitosamente.\n", filas, columnas);
        
        int contador = 1;
        for (size_t i = 0; i < filas; i++)
        {
            for (size_t j = 0; j < columnas; j++)
            {
                *(*(matriz + i) + j) = contador;
                contador++;
            }
        }

        printf("contenido de la matriz:\n");
        for (size_t i = 0; i < filas; i++)
        {
            for (size_t j = 0; j < columnas; j++)
            {
                printf("%4d ", *(*(matriz + i) + j));
            }
            printf("\n");
        }

        matriz_destruir(&matriz);
        printf("\nmatriz destruida y memoria liberada sin leaks.\n");
    }

    return EXIT_SUCCESS;
}