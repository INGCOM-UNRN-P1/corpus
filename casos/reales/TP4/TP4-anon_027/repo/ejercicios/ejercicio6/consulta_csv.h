#ifndef CONSULTA_CSV_H
#define CONSULTA_CSV_H

#include <stdbool.h>
#include <stddef.h>



 
 /** 
 *
 * @brief Reserva e inicializa una matriz dinámica de enteros en el Heap.
 * Reserva un arreglo de punteros a filas (`int**`) y asigna memoria 
 * inicializada en cero para cada fila usando `calloc`.
 *
 * @param[in] filas Número de filas a reservar. Debe ser mayor a 0.
 * @param[in] columnas Número de columnas a reservar. Debe ser mayor a 0.
 *
 * @return int** Puntero a la matriz reservada en Heap, o `NULL` si falla 
 * la asignación o si alguna dimensión es 0.
 */
int **matriz_crear(size_t filas, size_t columnas);




/**
 * @brief Libera la memoria ocupada por una matriz dinámica de enteros 
 * y anula el puntero.
 * Recorre y libera cada fila individualmente, posteriormente libera el 
 * contenedor de punteros principal y asigna `NULL` al puntero del cliente 
 * (`*puntero_matriz`).
 *
 * @param[in,out] puntero_matriz Puntero triple a la matriz de enteros (`int***`).
 * @param[in] filas Número de filas que componen la matriz.
 *
 * @note Es seguro llamar a esta función si `puntero_matriz` o `*puntero_matriz` 
 * son `NULL`.
 */
void matriz_liberar(int ***puntero_matriz, size_t filas);




/**
 * @brief Lee un archivo CSV numérico y carga su contenido en una matriz dinámica.
 * Analiza las dimensiones del archivo en una primera pasada para determinar el total
 * de filas y columnas, reserva la memoria correspondiente y parsea cada valor numérico.
 *
 * @param[in] ruta_archivo Ruta o nombre del archivo CSV a procesar.
 * @param[in] delimitador Carácter delimitador de campos (ej: ',').
 * @param[out] filas Puntero donde se almacenará el número total de filas leídas.
 * @param[out] columnas Puntero donde se almacenará el número total de columnas 
 * identificadas.
 *
 * @return int** Puntero a la matriz de enteros cargada, o `NULL` si el archivo 
 * no se pudo abrir,posee formato inválido o falla la reserva de memoria.
 */
int **matriz_cargar_desde_csv(const char *ruta_archivo, char delimitador, size_t *filas, size_t *columnas);




/**
 * @brief Crea una nueva matriz reducida filtrando las filas según una condición 
 * de umbral.
 *
 * Genera una matriz en Heap que conserva únicamente las filas cuyo valor 
 * en la columna `col_indice` sea estrictamente mayor a `umbral`.
 *
 * @param[in] matriz Puntero a la matriz dinámica origen.
 * @param[in] filas Cantidad de filas de la matriz origen.
 * @param[in] columnas Cantidad de columnas de la matriz origen.
 * @param[in] col_indice Índice base cero de la columna sobre la cual evaluar 
 * el filtro.
 * @param[in] umbral Valor entero de corte (`valor > umbral`).
 * @param[out] filas_filtradas Puntero donde se asignará la cantidad de filas 
 * de la nueva matriz.
 *
 * @return int** Puntero a la nueva matriz reducida, o `NULL` si ninguna 
 * fila cumple la condición, el índice es inválido o falla la asignación de 
 * memoria.
 */
int **matriz_filtrar_por_columna(int **matriz, size_t filas, size_t columnas, size_t col_indice, int umbral, size_t *filas_filtradas);




/**
 * @brief Calcula la media aritmética por columna en la matriz.
 *
 * Suma todos los elementos de cada columna y calcula su promedio de tipo 
 * flotante, retornando un arreglo dinámico con los resultados.
 *
 * @param[in] matriz Puntero a la matriz de enteros de origen.
 * @param[in] filas Cantidad de filas de la matriz.
 * @param[in] columnas Cantidad de columnas de la matriz.
 *
 * @return float* Arreglo dinámico de tamaño `columnas` con los promedios calculados,
 * o `NULL` si la matriz es `NULL`, sus dimensiones son 0 o falla `malloc`.
 */
float *matriz_calcular_promedios_columnas(int **matriz, size_t filas, size_t columnas);




/**
 * @brief Exporta el contenido de una matriz de enteros a un archivo CSV.
 *
 * Escribe la matriz en disco insertando el carácter `delimitador` entre elementos 
 * y finalizando cada registro con un salto de línea.
 *
 * @param[in] ruta_archivo Ruta o nombre del archivo CSV de salida.
 * @param[in] matriz Puntero a la matriz de enteros a guardar.
 * @param[in] filas Cantidad de filas a exportar.
 * @param[in] columnas Cantidad de columnas a exportar.
 * @param[in] delimitador Carácter separador de campos.
 *
 * @return int Retorna `0` en caso de éxito, o `-1` si no se pudo crear/abrir 
 * el archivo o los parámetros son inválidos.
 */
int matriz_exportar_csv(const char *ruta_archivo, int **matriz, size_t filas, size_t columnas, char delimitador);

#endif // CONSULTA_CSV_H