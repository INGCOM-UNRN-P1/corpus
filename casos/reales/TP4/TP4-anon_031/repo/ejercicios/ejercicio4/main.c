/**
 * @file main.c
 * @brief Demostración del Ejercicio 4.
 */

#include <stdio.h>
#include "matriz_dinamica.h"

int main(void)
{
    int **matriz = matriz_crear(2U, 3U);
    int *matriz_plana = crear_matriz_plana(2U, 3U);
    size_t fila = 0U;
    size_t columna = 0U;

    printf("Ejercicio 4: Matriz Dinamica 2D en Heap\n");

    if (matriz != NULL)
    {
        for (fila = 0U; fila < 2U; fila++)
        {
            for (columna = 0U; columna < 3U; columna++)
            {
                matriz[fila][columna] = (int)((fila * 3U) + columna + 1U);
                printf("%d ", matriz[fila][columna]);
            }
            printf("\n");
        }
    }

    if (matriz_plana != NULL)
    {
        asignar_celda(matriz_plana, 3U, 1U, 2U, 42);
        printf("Celda plana (1,2): %d\n", obtener_celda(matriz_plana, 3U, 1U, 2U));
    }

    matriz_destruir(matriz);
    liberar_matriz_plana(matriz_plana);

    return 0;
}
