/**
 * @file consulta_csv.c
 * @brief Pipeline dinámico para matrices CSV y texto multilínea.
 */

#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "consulta_csv.h"

static bool linea_tiene_contenido(const char *linea)
{
    bool tiene_contenido = false;
    size_t indice = 0U;

    if (linea != NULL)
    {
        while ((linea[indice] != '\0') && !tiene_contenido)
        {
            if (!isspace((unsigned char)linea[indice]))
            {
                tiene_contenido = true;
            }
            indice++;
        }
    }

    return tiene_contenido;
}

static bool procesar_linea_numerica(const char *linea, int *destino,
                                    size_t columnas_esperadas,
                                    size_t *cantidad_valores)
{
    bool valida = false;
    bool finalizada = false;
    const char *cursor = NULL;
    char *fin_numero = NULL;
    long valor = 0L;
    size_t cantidad = 0U;

    if ((linea != NULL) && (cantidad_valores != NULL))
    {
        *cantidad_valores = 0U;
        cursor = linea;
        valida = linea_tiene_contenido(linea);
    }

    while (valida && !finalizada)
    {
        while ((*cursor != '\0') && (*cursor != '\n') && (*cursor != '\r') &&
               isspace((unsigned char)*cursor))
        {
            cursor++;
        }

        errno = 0;
        valor = strtol(cursor, &fin_numero, 10);
        if ((fin_numero == cursor) || (errno == ERANGE) ||
            (valor < INT_MIN) || (valor > INT_MAX))
        {
            valida = false;
        }
        else
        {
            if (destino != NULL)
            {
                if (cantidad < columnas_esperadas)
                {
                    destino[cantidad] = (int)valor;
                }
                else
                {
                    valida = false;
                }
            }

            if (valida)
            {
                cantidad++;
                cursor = fin_numero;
                while ((*cursor != '\0') && (*cursor != '\n') && (*cursor != '\r') &&
                       isspace((unsigned char)*cursor))
                {
                    cursor++;
                }

                if (*cursor == ',')
                {
                    cursor++;
                }
                else if ((*cursor == '\0') || (*cursor == '\n') || (*cursor == '\r'))
                {
                    finalizada = true;
                }
                else
                {
                    valida = false;
                }
            }
        }
    }

    if (valida && (columnas_esperadas > 0U) && (cantidad != columnas_esperadas))
    {
        valida = false;
    }

    if (valida)
    {
        *cantidad_valores = cantidad;
    }

    return valida;
}

static int **crear_matriz_consulta(size_t filas, size_t columnas)
{
    int **matriz = NULL;
    int *datos = NULL;
    size_t fila = 0U;
    bool valida = (filas > 0U) && (columnas > 0U) &&
                  (filas <= SIZE_MAX / columnas) &&
                  ((filas * columnas) <= SIZE_MAX / sizeof(int)) &&
                  (filas <= SIZE_MAX / sizeof(int *));

    if (valida)
    {
        matriz = malloc(filas * sizeof(int *));
        datos = calloc(filas * columnas, sizeof(int));
    }

    if ((matriz != NULL) && (datos != NULL))
    {
        for (fila = 0U; fila < filas; fila++)
        {
            matriz[fila] = datos + (fila * columnas);
        }
    }
    else
    {
        free(datos);
        free(matriz);
        matriz = NULL;
    }

    return matriz;
}

int **cargar_matriz_csv(const char *ruta, size_t *filas, size_t *columnas)
{
    FILE *archivo = NULL;
    int **matriz = NULL;
    char linea[4096] = {0};
    size_t cantidad_filas = 0U;
    size_t cantidad_columnas = 0U;
    size_t valores_linea = 0U;
    size_t fila_actual = 0U;
    bool valido = true;

    if (filas != NULL)
    {
        *filas = 0U;
    }
    if (columnas != NULL)
    {
        *columnas = 0U;
    }

    if ((ruta != NULL) && (filas != NULL) && (columnas != NULL))
    {
        archivo = fopen(ruta, "r");
    }

    while ((archivo != NULL) && valido && (fgets(linea, sizeof(linea), archivo) != NULL))
    {
        if (linea_tiene_contenido(linea))
        {
            valores_linea = 0U;
            if (!procesar_linea_numerica(linea, NULL, 0U, &valores_linea))
            {
                valido = false;
            }
            else if (cantidad_filas == 0U)
            {
                cantidad_columnas = valores_linea;
                cantidad_filas = 1U;
            }
            else if (valores_linea != cantidad_columnas)
            {
                valido = false;
            }
            else
            {
                cantidad_filas++;
            }
        }
    }

    if ((archivo != NULL) && valido &&
        (cantidad_filas > 0U) && (cantidad_columnas > 0U))
    {
        matriz = crear_matriz_consulta(cantidad_filas, cantidad_columnas);
    }

    if (matriz != NULL)
    {
        rewind(archivo);
        fila_actual = 0U;
        while (valido && (fila_actual < cantidad_filas) &&
               (fgets(linea, sizeof(linea), archivo) != NULL))
        {
            if (linea_tiene_contenido(linea))
            {
                valores_linea = 0U;
                if (procesar_linea_numerica(linea, matriz[fila_actual], cantidad_columnas,
                                            &valores_linea))
                {
                    fila_actual++;
                }
                else
                {
                    valido = false;
                }
            }
        }

        if (!valido || (fila_actual != cantidad_filas))
        {
            liberar_matriz_csv(&matriz);
        }
    }

    if (archivo != NULL)
    {
        fclose(archivo);
    }

    if (matriz != NULL)
    {
        *filas = cantidad_filas;
        *columnas = cantidad_columnas;
    }

    return matriz;
}

void liberar_matriz_csv(int ***puntero_matriz)
{
    if ((puntero_matriz != NULL) && (*puntero_matriz != NULL))
    {
        free((*puntero_matriz)[0]);
        free(*puntero_matriz);
        *puntero_matriz = NULL;
    }
}

int **filtrar_filas_por_umbral(const int *const *matriz, size_t filas,
                               size_t columnas, size_t columna_filtro,
                               int umbral, size_t *filas_resultantes)
{
    int **filtrada = NULL;
    size_t cantidad_seleccionada = 0U;
    size_t fila = 0U;
    size_t columna = 0U;
    size_t fila_destino = 0U;

    if (filas_resultantes != NULL)
    {
        *filas_resultantes = 0U;
    }

    if ((matriz != NULL) && (filas > 0U) && (columnas > 0U) &&
        (columna_filtro < columnas) && (filas_resultantes != NULL))
    {
        for (fila = 0U; fila < filas; fila++)
        {
            if (matriz[fila][columna_filtro] > umbral)
            {
                cantidad_seleccionada++;
            }
        }

        if (cantidad_seleccionada > 0U)
        {
            filtrada = crear_matriz_consulta(cantidad_seleccionada, columnas);
        }
    }

    if (filtrada != NULL)
    {
        fila_destino = 0U;
        for (fila = 0U; fila < filas; fila++)
        {
            if (matriz[fila][columna_filtro] > umbral)
            {
                for (columna = 0U; columna < columnas; columna++)
                {
                    filtrada[fila_destino][columna] = matriz[fila][columna];
                }
                fila_destino++;
            }
        }
        *filas_resultantes = cantidad_seleccionada;
    }

    return filtrada;
}

float *calcular_promedios_columnas(const int *const *matriz, size_t filas,
                                   size_t columnas)
{
    float *promedios = NULL;
    size_t fila = 0U;
    size_t columna = 0U;
    double suma = 0.0;

    if ((matriz != NULL) && (filas > 0U) && (columnas > 0U) &&
        (columnas <= SIZE_MAX / sizeof(float)))
    {
        promedios = malloc(columnas * sizeof(float));
    }

    if (promedios != NULL)
    {
        for (columna = 0U; columna < columnas; columna++)
        {
            suma = 0.0;
            for (fila = 0U; fila < filas; fila++)
            {
                suma += matriz[fila][columna];
            }
            promedios[columna] = (float)(suma / (double)filas);
        }
    }

    return promedios;
}

bool exportar_matriz_csv(const char *ruta, const int *const *matriz,
                         size_t filas, size_t columnas)
{
    FILE *archivo = NULL;
    bool correcto = false;
    size_t fila = 0U;
    size_t columna = 0U;
    int resultado = 0;

    if ((ruta != NULL) && (matriz != NULL) && (filas > 0U) && (columnas > 0U))
    {
        archivo = fopen(ruta, "w");
    }

    if (archivo != NULL)
    {
        correcto = true;
        for (fila = 0U; fila < filas; fila++)
        {
            for (columna = 0U; columna < columnas; columna++)
            {
                resultado = fprintf(archivo, "%d", matriz[fila][columna]);
                if (resultado < 0)
                {
                    correcto = false;
                }
                if (correcto && (columna + 1U < columnas))
                {
                    if (fputc(',', archivo) == EOF)
                    {
                        correcto = false;
                    }
                }
            }
            if (correcto && (fputc('\n', archivo) == EOF))
            {
                correcto = false;
            }
        }

        if (fclose(archivo) != 0)
        {
            correcto = false;
        }
    }

    return correcto;
}

static char *duplicar_linea(const char *linea)
{
    char *copia = NULL;
    size_t longitud = 0U;
    size_t indice = 0U;

    if (linea != NULL)
    {
        longitud = strlen(linea);
        copia = malloc((longitud + 1U) * sizeof(char));
    }

    if (copia != NULL)
    {
        for (indice = 0U; indice <= longitud; indice++)
        {
            copia[indice] = linea[indice];
        }
    }

    return copia;
}

static bool agregar_linea(char ***lineas, size_t *cantidad, const char *linea)
{
    bool agregada = false;
    char *copia = NULL;
    char **redimensionado = NULL;

    if ((lineas != NULL) && (cantidad != NULL) && (linea != NULL) &&
        (*cantidad < SIZE_MAX / sizeof(char *)))
    {
        copia = duplicar_linea(linea);
    }

    if (copia != NULL)
    {
        redimensionado = realloc(*lineas, (*cantidad + 1U) * sizeof(char *));
        if (redimensionado != NULL)
        {
            redimensionado[*cantidad] = copia;
            *lineas = redimensionado;
            *cantidad += 1U;
            agregada = true;
        }
        else
        {
            free(copia);
        }
    }

    return agregada;
}

void liberar_lineas_dinamicas(char ***lineas, size_t cantidad)
{
    size_t indice = 0U;

    if ((lineas != NULL) && (*lineas != NULL))
    {
        for (indice = 0U; indice < cantidad; indice++)
        {
            free((*lineas)[indice]);
            (*lineas)[indice] = NULL;
        }
        free(*lineas);
        *lineas = NULL;
    }
}

char **leer_lineas_dinamicas(FILE *entrada, size_t *cantidad_lineas)
{
    char **lineas = NULL;
    char buffer[512] = {0};
    size_t cantidad = 0U;
    bool correcto = true;

    if (cantidad_lineas != NULL)
    {
        *cantidad_lineas = 0U;
    }

    if ((entrada != NULL) && (cantidad_lineas != NULL))
    {
        while (correcto && (fgets(buffer, sizeof(buffer), entrada) != NULL))
        {
            if (!agregar_linea(&lineas, &cantidad, buffer))
            {
                correcto = false;
            }
        }
    }
    else
    {
        correcto = false;
    }

    if (!correcto)
    {
        liberar_lineas_dinamicas(&lineas, cantidad);
        cantidad = 0U;
    }

    if (lineas != NULL)
    {
        *cantidad_lineas = cantidad;
    }

    return lineas;
}

char **filtrar_lineas_por_subcadena(char *const *lineas, size_t cantidad,
                                    const char *subcadena, size_t *cantidad_filtrada)
{
    char **filtradas = NULL;
    size_t cantidad_resultado = 0U;
    size_t indice = 0U;
    bool correcto = true;

    if (cantidad_filtrada != NULL)
    {
        *cantidad_filtrada = 0U;
    }

    if ((lineas == NULL) || (subcadena == NULL) || (cantidad_filtrada == NULL))
    {
        correcto = false;
    }

    for (indice = 0U; correcto && (indice < cantidad); indice++)
    {
        if ((lineas[indice] != NULL) && (strstr(lineas[indice], subcadena) != NULL))
        {
            if (!agregar_linea(&filtradas, &cantidad_resultado, lineas[indice]))
            {
                correcto = false;
            }
        }
    }

    if (!correcto)
    {
        liberar_lineas_dinamicas(&filtradas, cantidad_resultado);
        cantidad_resultado = 0U;
    }

    if (filtradas != NULL)
    {
        *cantidad_filtrada = cantidad_resultado;
    }

    return filtradas;
}
