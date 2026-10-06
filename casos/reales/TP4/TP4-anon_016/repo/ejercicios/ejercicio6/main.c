/**
 * @file main.c
 * @brief Programa principal del Ejercicio 6.
 */
 
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
 
#include "consulta_csv.h"
#include "../ejercicio4/matriz_dinamica.h"
 
/**
 * @brief Muestra un titulo y una matriz con una fila por linea
 *
 * @param titulo Texto que va antes de la matriz
 * @param matriz Matriz a mostrar
 * @param filas Cantidad de filas de matriz
 * @param columnas Cantidad de columnas de matriz
 */
static void mostrar_matriz(const char *titulo, int **matriz, size_t filas,
                           size_t columnas)
{
    printf("%s (%zu x %zu):\n", titulo, filas, columnas);
    for (size_t fila = 0; fila < filas; fila++)
    {
        for (size_t columna = 0; columna < columnas; columna++)
        {
            printf("%6d", matriz[fila][columna]);
        }
        printf("\n");
    }
}
 
/**
 * @brief Muestra un titulo y los valores de un arreglo de floats
 *
 * @param titulo Texto que va antes de los valores
 * @param valores Arreglo a mostrar solo lectura
 * @param cantidad Cantidad de elementos del arreglo
 */
static void mostrar_floats(const char *titulo, const float *valores,
                           size_t cantidad)
{
    printf("%s:", titulo);
    for (size_t indice = 0; indice < cantidad; indice++)
    {
        printf(" %.2f", valores[indice]);
    }
    printf("\n");
}
 
int main(void)
{
    printf("Ejercicio 6: Motor de Consultas y Pipeline CSV Dinámico\n");
 
    char ruta_entrada[256];
    char ruta_salida[256];
    int columna_filtro = 0;
    int umbral = 0;
 
    printf("Archivo CSV de entrada: ");
    int leidos = scanf("%255s", ruta_entrada);
    printf("Archivo CSV de salida: ");
    leidos += scanf("%255s", ruta_salida);
    printf("Columna a filtrar (la primera es 0): ");
    leidos += scanf("%d", &columna_filtro);
    printf("Umbral (se conservan las filas con valor mayor): ");
    leidos += scanf("%d", &umbral);
 
    if (leidos == 4 && columna_filtro >= 0)
    {
        size_t filas = 0;
        size_t columnas = 0;
        int **matriz = matriz_cargar_desde_csv(ruta_entrada, &filas,
                                               &columnas);
 
        if (matriz == NULL)
        {
            printf("No se pudo cargar el archivo.\n");
        }
        else
        {
            mostrar_matriz("Matriz cargada", matriz, filas, columnas);
 
            size_t filas_filtradas = 0;
            int **filtrada = matriz_filtrar_por_columna(
                matriz, filas, columnas, (size_t)columna_filtro, umbral,
                &filas_filtradas);
 
            if (filtrada == NULL)
            {
                printf("Ninguna fila cumple la condicion (o la columna "
                       "no existe).\n");
            }
            else
            {
                mostrar_matriz("Matriz filtrada", filtrada, filas_filtradas,
                               columnas);
 
                float *sumas = matriz_sumar_columnas(filtrada,
                                                     filas_filtradas,
                                                     columnas);
                float *promedios = matriz_promediar_columnas(filtrada,
                                                             filas_filtradas,
                                                             columnas);
                if (sumas != NULL && promedios != NULL)
                {
                    mostrar_floats("Sumas por columna", sumas, columnas);
                    mostrar_floats("Promedios por columna", promedios,
                                   columnas);
                }
 
                bool exportada = matriz_exportar_csv(ruta_salida, filtrada,
                                                     filas_filtradas,
                                                     columnas);
                if (exportada)
                {
                    printf("Matriz filtrada guardada en %s\n", ruta_salida);
                }
                else
                {
                    printf("No se pudo escribir el archivo de salida.\n");
                }
 
                liberar_arreglo_floats(&sumas);
                liberar_arreglo_floats(&promedios);
                matriz_destruir(filtrada);
            }
 
            matriz_destruir(matriz);
        }
    }
    else
    {
        printf("Datos invalidos.\n");
    }
 
    return 0;
}
