/**
 * @file matriz_dinamica.c
 * @brief Implementación para Ejercicio 4 (Matrices Dinámicas).
 */

#include "matriz_dinamica.h"
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>





int **matriz_crear (size_t filas, size_t columnas){
if (filas == 0 || columnas == 0){
    return NULL;

}
int **matriz = malloc(filas *sizeof (int *));
if(matriz == NULL){
    
    return NULL;
}

matriz[0] = malloc (filas*columnas*sizeof(int));
if (matriz [0] == NULL){
    free(matriz);
    return NULL;

}
for (size_t i = 1; i < filas; i++) {
        matriz[i] = matriz[0] + (i * columnas);
}
return matriz;
}

void matriz_destruir(int **matriz){
    free(matriz[0]);
    free(matriz);
    
    return;
}

int **matriz_cargar_desde_csv (const char *ruta_archivo, size_t filas, size_t columnas){
if (ruta_archivo == NULL || filas == NULL || columnas == NULL) {
        return NULL;
}

FILE *archivo_csv = fopen(ruta_archivo, "r");
if(!archivo_csv){
    perror("Error al intentar abrir el archivo");
    return EXIT_FAILURE;

}
int **matriz = matriz_crear(filas, columnas);

    if (matriz == NULL) {
        fclose(archivo_csv);
        return NULL;
    }

    for (size_t i = 0; i < filas; i++) {
        for (size_t a = 0; a < columnas; a++) {

            if (fscanf(archivo_csv, "%d", &matriz[i][a]) != 1) {
                matriz_destruir(matriz);
                fclose(archivo_csv);
                return NULL;
            }

            if (a < columnas - 1) {
                fgetc(archivo_csv);
            }
        }
    }

    fclose(archivo_csv);

    return matriz;
}