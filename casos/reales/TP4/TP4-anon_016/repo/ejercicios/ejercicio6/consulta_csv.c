/**
 * @file consulta_csv.c
 * @brief Implementación para Ejercicio 6 (Motor de Consulta y Exportación CSV).
 */

#include "consulta_csv.h"




#include <stdio.h>
#include <stdlib.h>
 
#include "consulta_csv.h"
#include "../ejercicio4/matriz_dinamica.h"
 
int **matriz_filtrar_por_columna(int **matriz, size_t filas, size_t columnas,
                                 size_t columna_filtro, int umbral,
                                 size_t *filas_resultado)
{
    int **resultado = NULL;
 
    if (matriz != NULL && filas_resultado != NULL
        && columna_filtro < columnas)
    {
        *filas_resultado = 0;
 
        size_t cantidad = 0;
        for (size_t fila = 0; fila < filas; fila++)
        {
            if (matriz[fila][columna_filtro] > umbral)
            {
                cantidad++;
            }
        }
 
        if (cantidad > 0)
        {
            resultado = matriz_crear(cantidad, columnas);
 
            if (resultado != NULL)
            {
                size_t fila_destino = 0;
 
                for (size_t fila = 0; fila < filas; fila++)
                {
                    if (matriz[fila][columna_filtro] > umbral)
                    {
                        for (size_t columna_copiada = 0;
                             columna_copiada < columnas; columna_copiada++)
                        {
                            resultado[fila_destino][columna_copiada] =
                                matriz[fila][columna_copiada];
                        }
                        fila_destino++;
                    }
                }
                *filas_resultado = cantidad;
            }
        }
    }
 
    return resultado;
}
 
float *matriz_sumar_columnas(int **matriz, size_t filas, size_t columnas)
{
    float *resultado = NULL;
 
    if (matriz != NULL && filas > 0 && columnas > 0)
    {
        resultado = calloc(columnas, sizeof(*resultado));
 
        if (resultado != NULL)
        {
            for (size_t fila = 0; fila < filas; fila++)
            {
                for (size_t columna = 0; columna < columnas; columna++)
                {
                    resultado[columna] += (float)matriz[fila][columna];
                }
            }
        }
    }
 
    return resultado;
}
 
float *matriz_promediar_columnas(int **matriz, size_t filas, size_t columnas)
{
    float *resultado = matriz_sumar_columnas(matriz, filas, columnas);
 
    if (resultado != NULL)
    {
        for (size_t columna = 0; columna < columnas; columna++)
        {
            resultado[columna] /= (float)filas;
        }
    }
 
    return resultado;
}
 
void liberar_arreglo_floats(float **puntero_arreglo)
{
    if (puntero_arreglo != NULL && *puntero_arreglo != NULL)
    {
        free(*puntero_arreglo);
        *puntero_arreglo = NULL;
    }
}
 
bool matriz_exportar_csv(const char *ruta, int **matriz, size_t filas,
                         size_t columnas)
{
    bool exito = false;
 
    if (ruta != NULL && matriz != NULL && filas > 0 && columnas > 0)
    {
        FILE *archivo = fopen(ruta, "w");
 
        if (archivo != NULL)
        {
            fprintf(archivo, "%zu,%zu\n", filas, columnas);
 
            for (size_t fila = 0; fila < filas; fila++)
            {
                for (size_t columna = 0; columna < columnas; columna++)
                {
                    if (columna > 0)
                    {
                        fprintf(archivo, ",");
                    }
                    fprintf(archivo, "%d", matriz[fila][columna]);
                }
                fprintf(archivo, "\n");
            }
 
            int cierre = fclose(archivo);
            exito = (cierre == 0);
        }
    }
 
    return exito;
}