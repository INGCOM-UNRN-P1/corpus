/**
 * @file main.c
 * @brief Programa principal del Ejercicio 4.
 */

#include "matriz_dinamica.h"
#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    printf("=== Ejercicio 4: Matriz Dinámica 2D en Heap ===\n\n");

    int codigo_salida = 0;
    size_t filas = 0;
    size_t columnas = 0;

    printf("Ingrese la cantidad de filas: ");

    if (scanf("%zu", &filas) != 1 || filas == 0)
    {
        printf("Error: cantidad de filas no válida.\n");
        codigo_salida = 1;
    }
    else
    {
        printf("Ingrese la cantidad de columnas: ");

        if (scanf("%zu", &columnas) != 1 || columnas == 0)
        {
            printf("Error: cantidad de columnas no válida.\n");
            codigo_salida = 1;
        }
        else
        {
            int *matriz = crear_matriz_plana(filas, columnas);

            if (matriz == NULL)
            {
                printf("Error: no se pudo reservar memoria.\n");
                codigo_salida = 1;
            }
            else
            {
                size_t fila_actual = 0;
                size_t columna_actual = 0;
                bool entrada_valida = true;

                while (fila_actual < filas && entrada_valida)
                {
                    columna_actual = 0;

                    while (columna_actual < columnas && entrada_valida)
                    {
                        int valor = 0;

                        printf("Ingrese el valor [%zu][%zu]: ", fila_actual,
                               columna_actual);

                        if (scanf("%d", &valor) != 1)
                        {
                            printf("Error: valor ingresado no válido.\n");
                            entrada_valida = false;
                            codigo_salida = 1;
                        }
                        else
                        {
                            asignar_celda(matriz, columnas, fila_actual,
                                          columna_actual, valor);

                            columna_actual++;
                        }
                    }

                    fila_actual++;
                }

                if (entrada_valida)
                {
                    printf("\nMatriz ingresada:\n");

                    fila_actual = 0;

                    while (fila_actual < filas)
                    {
                        columna_actual = 0;

                        while (columna_actual < columnas)
                        {
                            int valor = obtener_celda(
                                matriz, columnas, fila_actual, columna_actual);

                            printf("%d ", valor);
                            columna_actual++;
                        }

                        printf("\n");
                        fila_actual++;
                    }
                }

                liberar_matriz_plana(matriz);
            }
        }
    }

    return codigo_salida;
}
