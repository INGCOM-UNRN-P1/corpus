/**
 * @file matriz_dinamica.c
 * @brief Implementación para Ejercicio 4 (Matrices Dinámicas).
 */

#include "matriz_dinamica.h"
/**
 * @brief Descripción de la función matriz_crear.
 *
 * @param filas Descripción del parámetro filas.
 * @param columnas Descripción del parámetro columnas.
 * @return Descripción del valor de retorno.
 */
int **matriz_crear(size_t filas, size_t columnas)

{

    if (filas == 0 || columnas == 0)

    {
        return NULL;
    }

    int **filas_matriz = (int **)calloc(filas, sizeof(int *));

    if (filas_matriz == NULL)

    {
        free(filas_matriz);
        return NULL;
    }

    int *matriz = (int *)calloc((filas * columnas), sizeof(int));

    if (matriz == NULL)

    {
        free(matriz);
        return NULL;
    }

    for (size_t indice = 0; indice < filas; indice++)

    {

        

        *(filas_matriz + indice) = matriz + (indice * columnas);
    }

    return filas_matriz;
}

/**
 * @brief Descripción de la función matriz_destruir.
 *
 * @param matriz Descripción del parámetro matriz.
 */
void matriz_destruir(int **matriz)

{

    if (matriz == NULL)

    {

        return;
    }

    free(*matriz);

    free(matriz);
}

/**
 * @brief Descripción de la función matriz_cargar_desde_csv.
 *
 * @param ruta_archivo Descripción del parámetro ruta_archivo.
 * @param filas Descripción del parámetro filas.
 * @param columnas Descripción del parámetro columnas.
 * @return Descripción del valor de retorno.
 */
int **matriz_cargar_desde_csv(const char *ruta_archivo,

                              size_t *filas, size_t *columnas)

{

    size_t filas_archivo = 0;

    size_t columnas_archivo = 0;

    if (filas == NULL || columnas == NULL)

    {

        return NULL;
    }

    // abro el archivo

    FILE *archivo = fopen(ruta_archivo, "r");

    if (archivo == NULL)

    {

        return NULL;
    }

    // Leo las dimnesiones del archivo.

    fscanf(archivo, "%zu, %zu", &filas_archivo, &columnas_archivo);

    int **matriz = matriz_crear(filas_archivo, columnas_archivo);
    if (matriz == NULL)
    {
        fclose(archivo);
        return NULL;
    }

    

    for (size_t indice_filas = 0; indice_filas < filas_archivo; indice_filas++)

    {

        for (size_t indice_columnas = 0; indice_columnas < columnas_archivo;
             indice_columnas++)

        {

            fscanf(archivo, "%d,", *(matriz + indice_filas) + indice_columnas);
        }
    }

    *filas = filas_archivo;

    *columnas = columnas_archivo;

    // cierro el archivo

    fclose(archivo);

    return matriz;
}
