/**
 * @file main.c
 * @brief Programa principal del Ejercicio 4.
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "matriz_dinamica.h"




int main()
{
    int **matriz = NULL;
    size_t filas = 0;
    size_t columnas = 0;
    char buffer[256];
    
    printf("Ejercicio 4: Matriz Dinamica 2D en Heap\n");
 
    printf("|||CREAR MATRIZ MANUAL|||\n");
    printf("Ingrese cantidad de filas: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%zu", &filas);

    printf("Ingrese cantidad de columnas: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%zu", &columnas);
    matriz = matriz_crear(filas, columnas);
    
    if (matriz == NULL)
    {
        printf("\n[ERROR] No se pudo crear la matriz (error de asignacion o dimensiones invalidas).\n");
        filas = columnas = 0;
        return 1;
    } 

    printf("\n--- Ingreso de Valores ---\n");
    
    for (size_t i = 0; i < filas; i++)
    {
        for (size_t j = 0; j < columnas; j++)
        {
            printf("Matriz[%zu][%zu] = ", i, j);
            fgets(buffer, sizeof(buffer), stdin);
            sscanf(buffer, "%d", &matriz[i][j]);
        }
    }

    printf("\n[OK] Matriz de %zu x %zu creada con exito.\n", filas, columnas);

    if (matriz != NULL)
    {
        printf("\n[*] Liberando matriz previa en memoria...\n\n");
        matriz_destruir(&matriz);
    }


// ===============================================================
//              CARGA DE MATRIZ DESDE UN ARCHIVO CSV
// ===============================================================
    const char *nombre_archivo = "prueba.csv";
    
    // 1. Crear el archivo CSV de prueba
    FILE *f_crear = fopen(nombre_archivo, "w");
    if (f_crear != NULL)
    {
        fputs("10,20,30\n", f_crear);
        fputs("40,50,60\n", f_crear);
        fputs("70,80,90\n", f_crear);
        fclose(f_crear);
        printf("Archivo '%s' creado con exito.\n\n", nombre_archivo);
    }
    matriz = matriz_cargar_desde_csv(nombre_archivo, &filas, &columnas);

    if (matriz != NULL)
    {
        printf("\n[OK] Matriz cargada con exito desde '%s' (%zu filas x %zu columnas).\n", nombre_archivo, filas, columnas);
    }
                
    else
    {
        printf("\n[ERROR] No se pudo abrir o procesar el archivo '%s'.\n", nombre_archivo);
        filas = columnas = 0;
        return 1;
    }

    if (matriz != NULL)
    {
        matriz_destruir(&matriz);
        filas = columnas = 0;
        printf("\n[OK] Matriz destruida y memoria liberada correctamente.\n");
        return 0;
    }
    
    else
    {
        printf("\n[!] No hay ninguna matriz cargada para liberar.\n");
        return 0;
    }

    if (matriz != NULL)
    {
        matriz_destruir(&matriz);
        printf("[*] Memoria liberada al salir.\n");
    }

    return 0;
}

