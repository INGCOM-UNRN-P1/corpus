/**
 * @file main.c
 * @brief Programa principal del Ejercicio 6.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "consulta_csv.h"
 
int main(void)
{
    int estado = 0;
 
    printf("Ejercicio 6: Motor de Consultas y Pipeline CSV Dinámico\n");
 
    char ruta[256];
    char salida[256];
    size_t columna = 0;
    int umbral = 0;
 
    printf("Archivo CSV de entrada: ");
    bool leido = (fgets(ruta, sizeof(ruta), stdin) != NULL);
    if (leido) {
        printf("Archivo CSV de salida: ");
        leido = (fgets(salida, sizeof(salida), stdin) != NULL);
    }
    if (leido) {
        printf("Columna a filtrar (desde 0): ");
        leido = (scanf("%zu", &columna) == 1);
    }
    if (leido) {
        printf("Se conservan las filas con valor mayor a: ");
        leido = (scanf("%d", &umbral) == 1);
    }
 
    if (!leido) {
        printf("Error de lectura\n");
        estado = 1;
    } 
    else {
        ruta[strcspn(ruta, "\n")] = '\0';
        salida[strcspn(salida, "\n")] = '\0';
 
        size_t filas = 0;
        size_t columnas = 0;
        int *matriz = cargar_matriz_csv(ruta, &filas, &columnas);
 
        if (matriz == NULL) {
            printf("Error: no se pudo cargar el archivo CSV\n");
            estado = 1;
        } 
        else if (columna >= columnas) {
            printf("Error: el archivo tiene %zu columnas y la columna %zu no existe\n",
                   columnas, columna);
            estado = 1;
        } 
        else {
            printf("Matriz cargada: %zu filas x %zu columnas\n", filas, columnas);
 
            size_t filas_filtradas = 0;
            int *filtrada = filtrar_filas_mayores(matriz, filas, columnas, columna, umbral, &filas_filtradas);
            if (filtrada == NULL) {
                printf("Ninguna fila tiene la columna %zu mayor a %d\n", columna, umbral);
            } 
            else {
                printf("Filas que cumplen la condición: %zu\n", filas_filtradas);
 
                float *sumas = sumar_columnas(filtrada, filas_filtradas, columnas);
                float *promedios = promediar_columnas(filtrada, filas_filtradas, columnas);
                if (sumas == NULL || promedios == NULL) {
                    printf("Error: no se pudieron calcular las estadísticas\n");
                    estado = 1;
                } 
                else {
                    for (size_t j = 0; j < columnas; ++j) {
                        printf("Columna %zu: suma %.2f, promedio %.2f\n", j, sumas[j], promedios[j]);
                    }
 
                    if (exportar_matriz_csv(filtrada, filas_filtradas, columnas, salida)) {
                        printf("Matriz filtrada exportada a %s\n", salida);
                    } 
                    else {
                        printf("Error: no se pudo exportar a %s\n", salida);
                        estado = 1;
                    }
                }
                free(promedios);
                free(sumas);
                free(filtrada);
            }
        }
 
        free(matriz);
    }
    return estado;
}