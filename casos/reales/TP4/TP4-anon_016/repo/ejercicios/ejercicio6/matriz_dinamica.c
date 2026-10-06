/**
 * @file matriz_dinamica.c
 * @brief Implementación para Ejercicio 4 (Matrices Dinámicas).
 */

#include "matriz_dinamica.h"
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "vector.h"



int **matriz_crear(size_t filas, size_t columnas)
{
    int **resultado = NULL;

    if (filas > 0 && columnas > 0 && columnas <= SIZE_MAX / filas)
    {
        int *datos = crear_bloque_enteros(filas * columnas);

        if (datos != NULL)
        {
            resultado = calloc(filas, sizeof(*resultado));

            if (resultado == NULL)
            {
                liberar_bloque_enteros(&datos);
            }
            else
            {
                for (size_t fila = 0; fila < filas; fila++)
                {
                    resultado[fila] = datos + fila * columnas;
                }
            }
        }
    }

    return resultado;
}
void matriz_destruir(int **matriz)
{
    if (matriz != NULL)
    {
        liberar_bloque_enteros(&matriz[0]);
        free(matriz);
    }
}
 
int **matriz_cargar_desde_csv(const char *ruta, size_t *filas,
                              size_t *columnas)
{
    int **resultado = NULL;
 
    if (ruta != NULL && filas != NULL && columnas != NULL)
    {
        *filas = 0;
        *columnas = 0;
 
        FILE *archivo = fopen(ruta, "r");
 
        if (archivo != NULL)
        {
            int filas_leidas = 0;
            int columnas_leidas = 0;
            int campos = fscanf(archivo, "%d,%d", &filas_leidas,
                                &columnas_leidas);
 
            if (campos == 2 && filas_leidas > 0 && columnas_leidas > 0)
            {
                size_t cantidad_filas = (size_t)filas_leidas;
                size_t cantidad_columnas = (size_t)columnas_leidas;
                int **matriz = matriz_crear(cantidad_filas,
                                            cantidad_columnas);
 
                if (matriz != NULL)
                {
                    bool exito = true;
 
                    for (size_t fila = 0; exito && fila < cantidad_filas;
                         fila++)
                    {
                        for (size_t columna = 0;
                             exito && columna < cantidad_columnas; columna++)
                        {
                            int leidos = fscanf(archivo, "%d,",
                                                &matriz[fila][columna]);
                            exito = (leidos == 1);
                        }
                    }
 
                    if (exito)
                    {
                        resultado = matriz;
                        *filas = cantidad_filas;
                        *columnas = cantidad_columnas;
                    }
                    else
                    {
                        matriz_destruir(matriz);
                    }
                }
            }
 
            fclose(archivo);
        }
    }
 
    return resultado;
}
 