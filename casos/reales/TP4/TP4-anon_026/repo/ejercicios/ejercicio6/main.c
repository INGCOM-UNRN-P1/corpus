/**
 * @file main.c
 * @brief Programa principal del Ejercicio 6.
 */

#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "consulta_csv.h"
 
#define CAPACIDAD_LINEA 256
 
/**
 * @brief Muestra un mensaje y lee una línea de stdin sin el salto de línea final.
 *
 * Si la línea es más larga que el búfer, el resto se descarta.
 *
 * @param mensaje Texto a mostrar antes de leer.
 * @param buffer Búfer destino.
 * @param capacidad Tamaño total del búfer (incluyendo '\0').
 * @return true si se leyó una línea; false si se alcanzó el fin de la entrada.
 */
static bool leer_linea(const char *mensaje, char *buffer, size_t capacidad)
{
    printf("%s", mensaje);
    if (fgets(buffer, (int)capacidad, stdin) == NULL) 
    {
        return false;
    }
 
    size_t posicion = 0;
    while (buffer[posicion] != '\0' && buffer[posicion] != '\n' && buffer[posicion] != '\r') 
    {
        ++posicion;
    }
    if (buffer[posicion] == '\0') 
    {
        int caracter = getchar();
        while (caracter != '\n' && caracter != EOF) 
        {
            caracter = getchar();
        }
    }
    buffer[posicion] = '\0';
    return true;
}
 
/**
 * @brief Muestra un mensaje y lee un número entero de stdin.
 *
 * @param mensaje Texto a mostrar antes de leer.
 * @param valor Recibe el número leído.
 * @return true si se leyó un entero válido; false si no hay entrada o no es un entero.
 */
static bool leer_numero(const char *mensaje, long *valor)
{
    char linea[CAPACIDAD_LINEA];
    if (!leer_linea(mensaje, linea, sizeof(linea))) 
    {
        return false;
    }
 
    char *fin = NULL;
    errno = 0;
    long leido = strtol(linea, &fin, 10);
    if (fin == linea || *fin != '\0' || errno == ERANGE) 
    {
        return false;
    }
    *valor = leido;
    return true;
}
 
static void mostrar_matriz(const int *matriz, size_t filas, size_t columnas)
{
    for (size_t i = 0; i < filas; ++i) 
    {
        for (size_t j = 0; j < columnas; ++j) 
        {
            printf("%7d", matriz[i * columnas + j]);
        }
        printf("\n");
    }
}
 
/**
 * @brief Calcula y muestra la suma y el promedio de cada columna.
 *
 * @param matriz Matriz de entrada.
 * @param filas Cantidad de filas.
 * @param columnas Cantidad de columnas.
 */
static void mostrar_estadisticas(const int *matriz, size_t filas, size_t columnas)
{
    float *sumas = calcular_sumas_columnas(matriz, filas, columnas);
    float *promedios = calcular_promedios_columnas(matriz, filas, columnas);
    if (sumas == NULL || promedios == NULL) 
    {
        fprintf(stderr, "Error: no se pudieron calcular las estadisticas\n");
    } else 
        {
         for (size_t j = 0; j < columnas; ++j)
         {
            printf("  Columna %zu: suma = %.2f, promedio = %.2f\n", j, sumas[j], promedios[j]);
         }
    }
    free(sumas);
    free(promedios);
}
 
int main(void)
{
    printf("Ejercicio 6: Motor de Consultas y Pipeline CSV Dinámico\n");
 
    int estado = 1;
    int *matriz = NULL;
    int *filtrada = NULL;
    size_t filas = 0;
    size_t columnas = 0;
    size_t filas_filtradas = 0;
    long columna = 0;
    long umbral = 0;
    char ruta_entrada[CAPACIDAD_LINEA];
    char ruta_salida[CAPACIDAD_LINEA];
 
    if (!leer_linea("Ruta del archivo CSV de entrada: ", ruta_entrada, sizeof(ruta_entrada))) 
    {
        fprintf(stderr, "\nError: no se pudo leer la entrada\n");
        goto fin;
    }
    matriz = cargar_matriz_csv(ruta_entrada, &filas, &columnas);
    if (matriz == NULL) 
    {
        fprintf(stderr, "Error: no se pudo cargar '%s' (archivo inexistente o CSV invalido)\n",
                ruta_entrada);
        goto fin;
    }
    printf("\nMatriz cargada (%zu filas x %zu columnas):\n", filas, columnas);
    mostrar_matriz(matriz, filas, columnas);
    printf("Estadisticas por columna:\n");
    mostrar_estadisticas(matriz, filas, columnas);
 
    if (!leer_numero("\nColumna a evaluar (desde 0): ", &columna) || columna < 0 || (size_t)columna >= columnas) 
    {
        fprintf(stderr, "Error: columna invalida\n");
        goto fin;
    }
     if (!leer_numero("Conservar filas con valor mayor que: ", &umbral) || umbral < INT_MIN || umbral > INT_MAX) {
        fprintf(stderr, "Error: umbral invalido\n");
        goto fin;
    }
    filtrada = filtrar_filas_mayor_que(matriz, filas, columnas, (size_t)columna, (int)umbral, &filas_filtradas);
    if (filtrada == NULL) 
    {
        printf("Ninguna fila cumple la condicion (columna %ld > %ld).\n", columna, umbral);
        estado = 0;
        goto fin;
    }
    printf("\nMatriz filtrada (%zu filas x %zu columnas):\n", filas_filtradas, columnas);
    mostrar_matriz(filtrada, filas_filtradas, columnas);
 
    printf("Estadisticas por columna de la matriz filtrada:\n");
    mostrar_estadisticas(filtrada, filas_filtradas, columnas);
 
    if (!leer_linea("\nRuta del archivo CSV de salida: ", ruta_salida, sizeof(ruta_salida))) 
    {
        fprintf(stderr, "\nError: no se pudo leer la entrada\n");
        goto fin;
    }
    if (!exportar_matriz_csv(ruta_salida, filtrada, filas_filtradas, columnas)) 
    {
        fprintf(stderr, "Error: no se pudo escribir '%s'\n", ruta_salida);
        goto fin;
    }
    printf("Matriz filtrada exportada a '%s'\n", ruta_salida);
    estado = 0;
 
fin:
    free(filtrada);
    free(matriz);
    return estado;
}