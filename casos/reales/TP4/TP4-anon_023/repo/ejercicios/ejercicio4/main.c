/**
 * @file main.c
 * @brief Programa principal del Ejercicio 4.
 */

#include <stdio.h>
#include <stdlib.h>
#include "matriz_dinamica.h"

static void imprimir_matriz(int **m, size_t filas, size_t columnas)
{
    for (size_t i = 0; i < filas; i++)
    {
        printf("  [ ");
        for (size_t j = 0; j < columnas; j++)
        {
            printf("%3d ", *(*(m + i) + j));
        }
        printf("]\n");
    }
}

int main(void)
{
    printf("=== Ejercicio 4: Matriz Dinamica 2D en Heap (Bloque Contiguo) ===\n\n");

    size_t filas = 3;
    size_t columnas = 4;
    printf("1. Creando matriz dinamica de %zux%zu...\n", filas, columnas);

    int **m = matriz_crear(filas, columnas);
    if (m != NULL)
    {
        int valor = 1;
        for (size_t i = 0; i < filas; i++)
        {
            for (size_t j = 0; j < columnas; j++)
            {
                *(*(m + i) + j) = valor++;
            }
        }

        printf("Contenido de la matriz:\n");
        imprimir_matriz(m, filas, columnas);

        printf("\nVerificacion de bloque contiguo:\n");
        printf("Direccion base datos (fila 0): %p\n", (void *)*(m + 0));
        printf("Direccion inicio fila 1     : %p\n", (void *)*(m + 1));
        printf("Offset esperado              : %zu bytes\n", columnas * sizeof(int));
    }

    printf("\n2. Creando y cargando archivo CSV de prueba ('datos.csv')...\n");
    const char *nombre_csv = "datos.csv";
    FILE *f = fopen(nombre_csv, "w");
    if (f != NULL)
    {
        fprintf(f, "10,20,30\n40,50,60\n");
        fclose(f);
    }

    size_t f_csv = 0, c_csv = 0;
    int **m_csv = matriz_cargar_desde_csv(nombre_csv, &f_csv, &c_csv);
    if (m_csv != NULL)
    {
        printf("Matriz cargada desde CSV (%zux%zu):\n", f_csv, c_csv);
        imprimir_matriz(m_csv, f_csv, c_csv);
    }

    printf("\n3. Destruyendo matrices dinamicas...\n");
    matriz_destruir(&m);
    matriz_destruir(&m_csv);

    printf("Puntero m tras destruir    : %p\n", (void *)m);
    printf("Puntero m_csv tras destruir: %p\n", (void *)m_csv);

    remove(nombre_csv);
    return 0;
}
