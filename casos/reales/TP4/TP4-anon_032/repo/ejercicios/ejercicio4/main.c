/**
 * @file main.c
 * @brief Programa principal del Ejercicio 4.
 */

#include <stdio.h>
#include "matriz_dinamica.h"

// Funcion improvisada para demostrar la libreria de matrices.
void print_mat(int *m, size_t f, size_t c)
{

}

int main(void)
{
    printf("Crear una matriz 3x3 y asignar elementos 1 - 9: \n");
    int *matriz = crear_matriz_plana(3, 3);
    int n = 1;
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            asignar_celda(matriz, 3, i, j, n);
            n++;
        }
    }
    for (size_t fila = 0; fila < 3; fila++)
    {
        for (size_t columna = 0; columna < 3; columna++)
        {
            printf("%d  ", matriz[fila * 3 + columna]);
        }
        printf("\n");
    }

    printf("\nAcceder al elemento (1, 1) (indexacion basada en cero) \n");
    int elemento = 0; 
    obtener_celda(matriz, 3, 1, 1, &elemento);
    printf("%d\n", elemento);

    liberar_matriz_plana(&matriz);
    return 0;
}
