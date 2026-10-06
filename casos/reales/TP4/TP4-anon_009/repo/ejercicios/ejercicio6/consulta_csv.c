

#include "consulta_csv.h"

int *matriz_filtrar_por_columna(const int *matriz, size_t filas, size_t columnas,
                                size_t columna_criterio, int umbral,
                                size_t *out_filas)
{
    if (matriz == NULL || filas == 0 || columnas == 0 ||
        columna_criterio >= columnas || out_filas == NULL)
    {
        return NULL;
    }
    size_t coincidencia = 0;
    const int *ptr_fila = matriz;
    const int *fin_matriz = matriz + (filas * columnas);
    while (ptr_fila < fin_matriz)
    {
        if (*(ptr_fila + columna_criterio) > umbral)
        {
            coincidencia++;
        }
        ptr_fila += columnas;
    }
    if (coincidencia == 0)
    {
        *out_filas = 0;
        return NULL;
    }
    int *matriz_filtrada = (int *)malloc(coincidencia * columnas * sizeof(int));
    if (matriz_filtrada == NULL)
    {
        return NULL;
    }

    int *destino = matriz_filtrada;
    ptr_fila = matriz;
    while (ptr_fila < fin_matriz)
    {
        if (*(ptr_fila + columna_criterio) > umbral)
        {
            const int *src_cell = ptr_fila;
            const int *fin_cell = ptr_fila + columnas;

            while (src_cell < fin_cell)
            {
                *destino = *src_cell;
                destino++;
                src_cell++;
            }
        }
        ptr_fila += columnas;
    }
    *out_filas = coincidencia;
    return matriz_filtrada;
}

float *matriz_calcular_promedios_columna(const int *matriz, size_t filas, size_t columnas)
{
    if (matriz == NULL || filas == 0 || columnas == 0)
    {
        return NULL;
    }
    float *promedios = (float *)malloc(columnas * sizeof(float));
    if (promedios == NULL)
    {
        return NULL;
    }
    float *ptr_promedios = promedios;
    float *fin_promedios = promedios + columnas;
    while (ptr_promedios < fin_promedios)
    {
        *ptr_promedios = 0.0f;
        ptr_promedios++;
    }
    const int *ptr_fila = matriz;
    const int *fin_filas = matriz + (filas * columnas);
    while (ptr_fila < fin_filas)
    {
        const int *src_cell = ptr_fila;
        ptr_promedios = promedios;

        while (ptr_promedios < fin_promedios)
        {
            *ptr_promedios += (float)(*src_cell);
            ptr_promedios++;
            src_cell++;
        }
        ptr_fila += columnas;
    }
    ptr_promedios = promedios;
    while (ptr_promedios < fin_promedios)
    {
        *ptr_promedios /= (float)filas;
        ptr_promedios++;
    }
    return promedios;
}

int matriz_exportar_csv(const char *ruta_archivo, const int *matriz, size_t filas, size_t columnas)
{
    if (ruta_archivo == NULL || matriz == NULL || filas == 0 || columnas == 0)
    {
        return 0;
    }
    FILE *archivo = fopen(ruta_archivo, "w");
    if (archivo == NULL)
    {
        return 0;
    }
    fprintf(archivo, "%zu,%zu\n", filas, columnas);
    const int *ptr_casilla = matriz;
    const int *fin_matriz = matriz + (filas * columnas);
    size_t cuenta_columnas = 0;
    while (ptr_casilla < fin_matriz)
    {
        fprintf(archivo, "%d", *ptr_casilla);
        cuenta_columnas++;
        if (cuenta_columnas < columnas)
        {
            fputc(',', archivo);
        }
        else
        {
            fputc('\n', archivo);
            cuenta_columnas = 0;
        }
        ptr_casilla++;
    }
    fclose(archivo);
    return 1;
}