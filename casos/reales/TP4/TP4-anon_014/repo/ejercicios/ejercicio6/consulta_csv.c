/**
 * @file consulta_csv.c
 * @brief Implementación para Ejercicio 6 (Motor de Consulta y Exportación CSV).
 */

#include <stdlib.h>
#include <string.h>
#include "cadenas.h"
#include "consulta_csv.h"

#define TAM_LINEA 256

static bool agregar_linea(char ***lineas, size_t *cantidad,
                          const char *texto);

int *csv_cargar_matriz(const char *ruta, size_t *filas, size_t *columnas)
{
    if (ruta == NULL || filas == NULL || columnas == NULL)
    {
        return NULL;
    }
    FILE *archivo = fopen(ruta, "r");
    if (archivo == NULL)
    {
        return NULL;
    }

    unsigned long leidas_filas = 0;
    unsigned long leidas_columnas = 0;
    int *m = NULL;
    if (fscanf(archivo, "%lu,%lu", &leidas_filas, &leidas_columnas) == 2
        && leidas_filas > 0 && leidas_columnas > 0)
    {
        m = (int *)malloc(leidas_filas * leidas_columnas * sizeof(*m));
    }

    bool sin_error = m != NULL;
    size_t total = leidas_filas * leidas_columnas;
    for (size_t i = 0; i < total && sin_error == true; i++)
    {
        
        sin_error = fscanf(archivo, "%d,", &m[i]) == 1;
    }

    if (sin_error == false)
    {
        free(m);
        m = NULL;
    }
    else
    {
        *filas = leidas_filas;
        *columnas = leidas_columnas;
    }
    fclose(archivo);
    return m;
}

int *csv_filtrar_filas(const int *m, size_t filas, size_t columnas,
                       size_t columna, int umbral, size_t *filas_resultado)
{
    if (filas_resultado == NULL)
    {
        return NULL;
    }
    *filas_resultado = 0;
    if (m == NULL || columna >= columnas)
    {
        return NULL;
    }

    size_t cumplen = 0;
    for (size_t i = 0; i < filas; i++)
    {
        if (m[i * columnas + columna] > umbral)
        {
            cumplen++;
        }
    }
    if (cumplen == 0)
    {
        return NULL;
    }

    int *filtrada = (int *)malloc(cumplen * columnas * sizeof(*filtrada));
    if (filtrada == NULL)
    {
        return NULL;
    }
    size_t destino = 0;
    for (size_t i = 0; i < filas; i++)
    {
        if (m[i * columnas + columna] > umbral)
        {
            memcpy(filtrada + destino * columnas, m + i * columnas,
                   columnas * sizeof(*filtrada));
            destino++;
        }
    }
    *filas_resultado = cumplen;
    return filtrada;
}

float *csv_sumas_columnas(const int *m, size_t filas, size_t columnas)
{
    if (m == NULL || columnas == 0)
    {
        return NULL;
    }
    float *sumas = (float *)calloc(columnas, sizeof(*sumas));
    if (sumas == NULL)
    {
        return NULL;
    }
    for (size_t i = 0; i < filas; i++)
    {
        for (size_t j = 0; j < columnas; j++)
        {
            sumas[j] += (float)m[i * columnas + j];
        }
    }
    return sumas;
}

float *csv_promedios_columnas(const int *m, size_t filas, size_t columnas)
{
    if (filas == 0)
    {
        return NULL;
    }
    float *promedios = csv_sumas_columnas(m, filas, columnas);
    if (promedios == NULL)
    {
        return NULL;
    }
    for (size_t j = 0; j < columnas; j++)
    {
        promedios[j] /= (float)filas;
    }
    return promedios;
}

bool csv_exportar_matriz(const char *ruta, const int *m, size_t filas,
                         size_t columnas)
{
    if (ruta == NULL || m == NULL)
    {
        return false;
    }
    FILE *archivo = fopen(ruta, "w");
    if (archivo == NULL)
    {
        return false;
    }

    bool sin_error = fprintf(archivo, "%zu,%zu\n", filas, columnas) > 0;
    for (size_t i = 0; i < filas && sin_error == true; i++)
    {
        for (size_t j = 0; j < columnas && sin_error == true; j++)
        {
            const char *separador = ",";
            if (j == columnas - 1)
            {
                separador = "\n";
            }
            sin_error = fprintf(archivo, "%d%s", m[i * columnas + j],
                                separador) > 0;
        }
    }

    if (fclose(archivo) != 0)
    {
        sin_error = false;
    }
    return sin_error;
}

char **leer_lineas(FILE *entrada, size_t *cantidad)
{
    if (cantidad == NULL)
    {
        return NULL;
    }
    *cantidad = 0;
    if (entrada == NULL)
    {
        return NULL;
    }

    char **lineas = NULL;
    size_t leidas = 0;
    char buffer[TAM_LINEA] = {0};
    bool sin_error = true;
    while (sin_error == true && fgets(buffer, TAM_LINEA, entrada) != NULL)
    {
        buffer[strcspn(buffer, "\r\n")] = '\0';
        sin_error = agregar_linea(&lineas, &leidas, buffer);
    }

    if (sin_error == false)
    {
        liberar_lineas(&lineas, leidas);
        return NULL;
    }
    *cantidad = leidas;
    return lineas;
}

char **filtrar_lineas(char *const *lineas, size_t cantidad,
                      const char *subcadena, size_t *cantidad_filtradas)
{
    if (cantidad_filtradas == NULL)
    {
        return NULL;
    }
    *cantidad_filtradas = 0;
    if (lineas == NULL || subcadena == NULL)
    {
        return NULL;
    }

    char **filtradas = NULL;
    size_t copiadas = 0;
    bool sin_error = true;
    for (size_t i = 0; i < cantidad && sin_error == true; i++)
    {
        if (strstr(lineas[i], subcadena) != NULL)
        {
            sin_error = agregar_linea(&filtradas, &copiadas, lineas[i]);
        }
    }

    if (sin_error == false)
    {
        liberar_lineas(&filtradas, copiadas);
        return NULL;
    }
    *cantidad_filtradas = copiadas;
    return filtradas;
}

void liberar_lineas(char ***lineas, size_t cantidad)
{
    if (lineas == NULL || *lineas == NULL)
    {
        return;
    }
    for (size_t i = 0; i < cantidad; i++)
    {
        free((*lineas)[i]);
        (*lineas)[i] = NULL;
    }
    free(*lineas);
    *lineas = NULL;
}

/**
 * @brief Duplica 'texto' y lo agrega al final del arreglo de líneas.
 * @param lineas dirección del arreglo (puede apuntar a NULL si está vacío).
 * @param cantidad cantidad actual; se incrementa ante éxito.
 * @param texto línea a copiar.
 * @pre los tres punteros no son NULL.
 * @returns true ante éxito; false si falla la memoria (el arreglo queda
 *          intacto).
 */
static bool agregar_linea(char ***lineas, size_t *cantidad,
                          const char *texto)
{
    char *copia = cadena_duplicar_segura(texto, strlen(texto) + 1);
    if (copia == NULL)
    {
        return false;
    }
    
    char **nuevo = (char **)realloc(*lineas,
                                    (*cantidad + 1) * sizeof(*nuevo));
    if (nuevo == NULL)
    {
        free(copia);
        copia = NULL;
        return false;
    }
    nuevo[*cantidad] = copia;
    *cantidad = *cantidad + 1;
    *lineas = nuevo;
    return true;
}
