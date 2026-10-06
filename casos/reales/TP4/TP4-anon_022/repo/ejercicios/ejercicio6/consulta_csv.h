#ifndef CONSULTA_CSV_H
#define CONSULTA_CSV_H

#include <stdbool.h>
#include <stddef.h>



/**
 * @brief Carga en memoria una matriz de enteros desde un archivo CSV.
 *
 * @param ruta Ruta del archivo CSV.
 * @param filas Dirección donde se almacena la cantidad de filas cargadas.
 * @param columnas Dirección donde se almacena la cantidad de columnas.
 *
 * @post Si la carga es exitosa, '*filas' y '*columnas' contienen las
 *       dimensiones de la matriz.
 *       Si falla, ambos valores quedan en 0.
 *
 * @return Puntero al bloque contiguo que contiene la matriz.
 *         Retorna NULL si los argumentos son inválidos, el archivo no puede
 *         abrirse, su contenido no representa una matriz válida o falla la
 *         asignación de memoria.
 */
int *cargar_csv(const char *ruta, size_t *filas, size_t *columnas);


/**
 * @brief Genera una nueva matriz con las filas que superan un umbral en una
 *        columna determinada.
 *
 * @param matriz Bloque contiguo que contiene la matriz.
 * @param filas Cantidad de filas.
 * @param columnas Cantidad de columnas.
 * @param columna_filtro Índice de la columna sobre la que se aplica el filtro.
 * @param umbral Valor que debe superarse para conservar una fila.
 * @param filas_resultado Dirección donde se almacena la cantidad de filas
 *                        obtenidas.
 *
 * @pre 'matriz' debe contener al menos 'filas * columnas' enteros.
 *
 * @post La matriz original no se modifica.
 *       Si no se obtiene ninguna fila, '*filas_resultado' queda en 0.
 *
 * @return Puntero al nuevo bloque con las filas que cumplen la condición.
 *         Retorna NULL si los argumentos son inválidos, ninguna fila cumple
 *         la condición o falla la asignación de memoria.
 */
int *filtrar_filas(const int *matriz, size_t filas, size_t columnas,
                   size_t columna_filtro, int umbral,
                   size_t *filas_resultado);


/**
 * @brief Calcula la suma de cada columna de una matriz.
 *
 * @param matriz Bloque contiguo que contiene la matriz.
 * @param filas Cantidad de filas.
 * @param columnas Cantidad de columnas.
 *
 * @pre 'matriz' debe contener al menos 'filas * columnas' enteros.
 *
 * @return Puntero a un arreglo dinámico de 'columnas' elementos con las
 *         sumas calculadas. Retorna NULL si los argumentos son inválidos
 *         o falla la asignación de memoria.
 */
float *calcular_sumas_columnas(const int *matriz, size_t filas,
                               size_t columnas);


/**
 * @brief Calcula el promedio de cada columna de una matriz.
 *
 * @param matriz Bloque contiguo que contiene la matriz.
 * @param filas Cantidad de filas.
 * @param columnas Cantidad de columnas.
 *
 * @pre 'matriz' debe contener al menos 'filas * columnas' enteros.
 *
 * @return Puntero a un arreglo dinámico de 'columnas' elementos con los
 *         promedios calculados. Retorna NULL si los argumentos son inválidos
 *         o falla la asignación de memoria.
 */
float *calcular_promedios_columnas(const int *matriz, size_t filas,
                                   size_t columnas);


/**
 * @brief Escribe una matriz de enteros en un archivo CSV.
 *
 * @param ruta Ruta del archivo de salida.
 * @param matriz Bloque contiguo que contiene la matriz.
 * @param filas Cantidad de filas.
 * @param columnas Cantidad de columnas.
 *
 * @pre 'matriz' debe contener al menos 'filas * columnas' enteros.
 *
 * @post Si la operación es exitosa, el archivo contiene una línea por fila
 *       y los valores de cada columna separados por comas.
 *
 * @return true si la matriz se exportó correctamente.
 *         false si los argumentos son inválidos o el archivo no pudo
 *         escribirse.
 */
bool exportar_csv(const char *ruta, const int *matriz, size_t filas,
                  size_t columnas);


/**
 * @brief Libera una matriz dinámica y anula su puntero.
 *
 * @param matriz Dirección del puntero a la matriz.
 *
 * @post Si 'matriz' no es NULL, '*matriz' queda establecido en NULL.
 */
void liberar_matriz(int **matriz);

#endif 