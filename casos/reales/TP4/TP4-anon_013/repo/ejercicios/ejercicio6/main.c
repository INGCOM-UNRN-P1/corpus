/**
 * @file main.c
 * @brief Programa principal del Ejercicio 6.
 */

#include <stdio.h>
#include "consulta_csv.h"

#define RUTA_ORIGEN "matriz_origen.csv"
#define RUTA_DESTINO "matriz_filtrada.csv"


static void imprimir_matriz(int **matriz, size_t filas, size_t columnas)
{
    for (size_t i = 0; i < filas; i++)
    {
        for (size_t j = 0; j < columnas; j++)
        {
            printf("%d, ", matriz[i][j]);
        }
        printf("\n");
    }
}

static void imprimir_arreglo_float(const float *arreglo, size_t cantidad)
{
    for (size_t i = 0; i < cantidad; i++)
    {
        printf("%.2f, ", arreglo[i]);   // imprimo hasta 2 decimales
    }
    printf("\n");
}


static bool crear_dataset_ejemplo(const char *ruta)
{
    FILE *archivo = fopen(ruta, "w");
    if (archivo == NULL)
    {
        return false;
    }
 
    bool exito = fputs("1,25,70,170\n"
                       "2,32,82,180\n"
                       "3,41,65,160\n"
                       "4,19,58,165\n"
                       "5,36,90,185\n"
                       "6,28,76,175\n", archivo) >= 0;
 
    if (fclose(archivo) != 0)
    {
        exito = false;
    }
    return exito;
}

int main(void)
{
    printf("Ejercicio 6: Motor de Consultas y Pipeline CSV Dinámico\n");

    //______________________________________________________________________________________________________________
 
    printf("\n===== matriz_cargar_desde_csv =====\n");
 
    if (!crear_dataset_ejemplo(RUTA_ORIGEN))
    {
        printf("NO SE PUDO CREAR EL DATASET DE EJEMPLO\n");
        return 1;
    }
 
    size_t filas = 0;
    size_t columnas = 0;
 
    int **matriz = matriz_cargar_desde_csv(RUTA_ORIGEN, &filas, &columnas);
 
    if (matriz != NULL)
    {
        printf("MATRIZ CARGADA DESDE '%s' (%zu filas x %zu columnas):\n", RUTA_ORIGEN, filas, columnas);
        imprimir_matriz(matriz, filas, columnas);
    }
    else
    {
        printf("NO SE PUDO CARGAR LA MATRIZ DEDE '%s', algo malio sal\n", RUTA_ORIGEN);
    }

    //______________________________________________________________________________________________________________

    printf("\n===== filtrar_filas_matriz =====\n");
 
    printf("CONDICION: columna 1 > 30\n");

    size_t filas_filtradas = 0;
    int **matriz_filtrada = filtrar_filas_matriz(matriz, filas, columnas, 1, mayor_a_umbral, 30, &filas_filtradas);
 
    if (matriz_filtrada != NULL)
    {
        printf("MATRIZ FILTRADA EN EL HEAP (%zu filas x %zu columnas):\n", filas_filtradas, columnas);
        imprimir_matriz(matriz_filtrada, filas_filtradas, columnas);
        
    }
    else
    {
        printf("NO SE PUEDO FILTRAR LA MATRIZ, algo malio sal\n");
    }
 
    printf("\nCONDICION: columna 0 divisible por 2\n");

    size_t filas_pares = 0;
    int **matriz_filtrada2 = filtrar_filas_matriz(matriz, filas, columnas, 0, es_divisible_por, 2, &filas_pares);
 
    if (matriz_filtrada2 != NULL)
    {
        printf("MATRIZ FILTRADA EN EL HEAP (%zu filas x %zu columnas):\n", filas_pares, columnas);
        imprimir_matriz(matriz_filtrada2, filas_pares, columnas);
        matriz_destruir_v2(&matriz_filtrada2);
        printf("MATRIZ LIBERADA Y PUNTERO ANULADO CON matriz_destruir_v2()\n");
    }
    else
    {
        printf("NO SE PUEDO FILTRAR LA MATRIZ, algo malio sal\n");
    }

    //______________________________________________________________________________________________________________

    printf("\n===== matriz_sumar_columnas y matriz_promedio_columnas =====\n");
 
    printf("MATRIZ FILTRADA (columna 1 > 30):\n");
    imprimir_matriz(matriz_filtrada, filas_filtradas, columnas);
 
    float *sumas = matriz_sumar_columnas(matriz_filtrada, filas_filtradas, columnas);
 
    if (sumas != NULL)
    {
        printf("ARREGLO SUMA: ");
        imprimir_arreglo_float(sumas, columnas);
        liberar_bloque_float(&sumas);
        printf("ARREGLO LIBERADO CON liberar_bloque_float()\n");
    }
    else
    {
        printf("EL ARREGLO DE SUMAS ES NULO, algo malio sal\n");
    }
 
    float *promedios = matriz_promedio_columnas(matriz_filtrada, filas_filtradas, columnas);
 
    if (promedios != NULL)
    {
        printf("ARREGLO PROMEDIOS: ");
        imprimir_arreglo_float(promedios, columnas);
        liberar_bloque_float(&promedios);
        printf("ARREGLO LIBERADO CON liberar_bloque_float()\n");
    }
    else
    {
        printf("EL ARREGLO DE PROMEDIOS ES NULO, algo malio sal\n");
    }

    //______________________________________________________________________________________________________________

    printf("\n===== matriz_exportar_csv =====\n");
 
    if (matriz_exportar_csv(RUTA_DESTINO, matriz_filtrada, filas_filtradas, columnas))
    {
        printf("MATRIZ FILTRADA EXPORTADA A '%s'\n", RUTA_DESTINO);
    }
    else
    {
        printf("NO SE PUDO EXPORTAR LA MATRIZ A '%s'\n", RUTA_DESTINO);
    }
    
    

    printf("\n===== Liberacion Final =====\n");
 
    matriz_destruir_v2(&matriz_filtrada);
    matriz_destruir_v2(&matriz);
 
    if (matriz_filtrada == NULL && matriz == NULL)
    {
        printf("MATRICES LIBERADAS Y PUNTEROS ANULADOS CON matriz_destruir_v2()\n");
    }
    else
    {
        printf("ERROR AL DESTRUIR LAS MATRICES, algo malio sal\n");
    }

    return 0;
}
