/**
 * @file consulta_csv.c
 * @brief Implementación para Ejercicio 6 (Motor de Consulta y Exportación CSV).
 */
#include "consulta_csv.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINEA 2048


int **matriz_crear(size_t filas, size_t columnas) 
{
    if (filas == 0 || columnas == 0)
    {
        return NULL;
    } 
  
    int **matriz = malloc(filas * sizeof(int *));
    if (matriz == NULL)
    {
        return NULL;
    } 

    for (size_t i = 0; i < filas; i++) 
    {
        matriz[i] = calloc(columnas, sizeof(int));
        
        if (matriz[i] == NULL) 
        {
            for (size_t j = 0; j < i; j++) 
            {
                free(matriz[j]);
            }
            free(matriz);
            return NULL;
        }
    }
    return matriz;
}



void matriz_liberar(int ***puntero_matriz, size_t filas) 
{
    if (puntero_matriz == NULL || *puntero_matriz == NULL)
    {
        return;
    } 

    for (size_t i = 0; i < filas; i++) 
    {
        free((*puntero_matriz)[i]);
    }

    free(*puntero_matriz);
    *puntero_matriz = NULL;
}



int **matriz_cargar_desde_csv(const char *ruta_archivo, char delimitador, size_t *filas, size_t *columnas) 
{
    if (ruta_archivo == NULL || filas == NULL || columnas == NULL) 
    {
        return NULL;
    }

    FILE *archivo = fopen(ruta_archivo, "r");
    if (archivo == NULL) 
    {   
        return NULL;
    }

    char buffer[MAX_LINEA];
    size_t num_filas = 0;
    size_t num_cols = 0;

    // Pasada 1: Contar filas y columnas
    while (fgets(buffer, sizeof(buffer), archivo) != NULL) 
    {
        if ((buffer[0] == '\n') || (buffer[0] == '\r') || (buffer[0] == '\0')) 
        {
            continue;
        }

        if (num_filas == 0) 
        {
            for (size_t i = 0; (buffer[i] != '\0') && (buffer[i] != '\n') && (buffer[i] != '\r'); i++) 
            {
                if (buffer[i] == delimitador)
                { 
                    num_cols++;
                }
            }
            num_cols++; // Total de columnas = delimitadores + 1
        }
        num_filas++;
    }

    if ((num_filas == 0) || (num_cols == 0)) 
    {
        fclose(archivo);
        return NULL;
    }

    int **matriz = matriz_crear(num_filas, num_cols);
    if (matriz == NULL) 
    {
        fclose(archivo);
        return NULL;
    }

    // Pasada 2: Leer valores e ingresar en la matriz
    rewind(archivo);
    
    size_t f = 0;
    
    char delim_str[2] = {delimitador, '\0'};

    while ((fgets(buffer, sizeof(buffer), archivo) != NULL) && (f < num_filas)) 
    {
        if ((buffer[0] == '\n') || (buffer[0] == '\r') || (buffer[0] == '\0')) 
        {
            continue;
        }

        buffer[strcspn(buffer, "\r\n")] = '\0';
        char *ptr = buffer;
        size_t c = 0;

        while ((ptr != NULL) && (c < num_cols)) 
        {
            char *siguiente = strchr(ptr, delimitador);
            if (siguiente != NULL) 
            {
                *siguiente = '\0';
                matriz[f][c] = atoi(ptr);
                ptr = siguiente + 1;
            } 
            else 
            {
                matriz[f][c] = atoi(ptr);
                ptr = NULL;
            }
            c++;
        }
        f++;
    }

    fclose(archivo);
    *filas = num_filas;
    *columnas = num_cols;
    return matriz;
}




int **matriz_filtrar_por_columna(int **matriz, size_t filas, size_t columnas, size_t col_indice, int umbral, size_t *filas_filtradas) 
{
    if (matriz == NULL || filas_filtradas == NULL || col_indice >= columnas) 
    {
        if (filas_filtradas != NULL)
        {
            *filas_filtradas = 0;
        }
         
        return NULL;
    }

    // Contar cuantas filas cumplen la condicion
    size_t coincidentes = 0;
    for (size_t i = 0; i < filas; i++) 
    {
        if (matriz[i][col_indice] > umbral) 
        {
            coincidentes++;
        }
    }

    *filas_filtradas = coincidentes;

    if (coincidentes == 0)
    {
        return NULL;
    } 

    int **filtrada = matriz_crear(coincidentes, columnas);
    if (filtrada == NULL) 
    {
        *filas_filtradas = 0;
        return NULL;
    }

    size_t idx = 0;
    for (size_t i = 0; i < filas; i++) 
    {
        if (matriz[i][col_indice] > umbral) 
        {
            for (size_t j = 0; j < columnas; j++) 
            {
                filtrada[idx][j] = matriz[i][j];
            }
            idx++;
        }
    }

    return filtrada;
    }



float *matriz_calcular_promedios_columnas(int **matriz, size_t filas, size_t columnas) 
{
    if (matriz == NULL || filas == 0 || columnas == 0)
    {
        return NULL;
    } 

    float *promedios = malloc(columnas * sizeof(float));
    if (promedios == NULL)
    { 
        return NULL;
    }

    for (size_t j = 0; j < columnas; j++) 
    {
        long suma = 0;
        for (size_t i = 0; i < filas; i++) 
        {
            suma += matriz[i][j];
        }
        promedios[j] = (float)suma / (float)filas;
    }

    return promedios;
}




int matriz_exportar_csv(const char *ruta_archivo, int **matriz, size_t filas, size_t columnas, char delimitador) 
{
    if (ruta_archivo == NULL || matriz == NULL || filas == 0 || columnas == 0)
    {  
        return -1;
    }

    FILE *archivo = fopen(ruta_archivo, "w");
    if (archivo == NULL)
    { 
        return -1;
    }
    
    for (size_t i = 0; i < filas; i++) 
    {
        for (size_t j = 0; j < columnas; j++) 
        {
            fprintf(archivo, "%d%s", matriz[i][j], (j + 1 < columnas) ? (char[]){delimitador, '\0'} : "");
        }
        fprintf(archivo, "\n");
    }

    fclose(archivo);
    return 0;
}