

#include "matriz_dinamica.h"



int **matriz_crear(size_t filas, size_t columnas)
{
    if(filas == 0 || columnas == 0)
    {
        return NULL;
    }
    int **matriz = (int **)malloc(filas * sizeof(int *));
    if(matriz == NULL)
    {
        return NULL;
    }
    int *datos = (int *)malloc(filas * columnas * sizeof(int));
    if(datos == NULL)
    {
        free(matriz);
        return NULL;
    }
    int *ptr_datos = datos;
    int **ptr_fila = matriz;
    int **fin_filas = matriz + filas;
    while(ptr_fila < fin_filas)
    {
        *ptr_fila = ptr_datos;
        ptr_datos += columnas;
        ptr_fila++;
    }
    return matriz;
}

void matriz_destruir(int **matriz)
{
    if(matriz == NULL)
    {
        return ;
    }
    if(*matriz != NULL)
    {
        free(*matriz);
    }
    free(matriz);
}

int **matriz_cargar_desde_csv(const char *ruta_archivo, size_t *out_filas, size_t *out_columnas)
{
    if(ruta_archivo == NULL || out_columnas == NULL || out_filas == NULL)
    {
        return NULL;
    }
    FILE *archivo = fopen(ruta_archivo, "r");
    if(archivo == NULL)
    {
        return NULL;
    }
    size_t filas = 0;
    size_t columnas = 0;
    if(fscanf(archivo, "%zu,%zu", &filas, &columnas) != 2 || filas == 0 || columnas == 0)
    {
        fclose(archivo);
        return NULL;
    }
    int **matriz = matriz_crear(filas, columnas);
    if (matriz == NULL)
    {
        fclose(archivo);
        return NULL;
    }
    int **ptr_fila = matriz;
    int **fin_filas = matriz + filas;
    while (ptr_fila < fin_filas)
    {
        int *ptr_col = *ptr_fila;
        int *fin_col = ptr_col + columnas;
        while (ptr_col < fin_col)
        {
            if (fscanf(archivo, "%d,", ptr_col) != 1)
            {
                matriz_destruir(matriz);
                fclose(archivo);
                return NULL;
            }
            ptr_col++;
        }
        ptr_fila++;
    }
    fclose(archivo);
    *out_filas = filas;
    *out_columnas = columnas;
    return matriz;
 }
