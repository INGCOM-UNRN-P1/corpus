#ifndef CONSULTA_CSV_H
#define CONSULTA_CSV_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Carga en heap una matriz de enteros desde un archivo CSV.
 *
 * Cada línea del archivo es una fila y los valores se separan con comas. Las líneas
 * vacías se ignoran. La cantidad de filas es la de líneas con datos y la de columnas
 * es la de valores de la primera línea.
 *
 * @param ruta Ruta del archivo CSV a leer.
 * @param filas Dirección donde se almacena la cantidad de filas leídas.
 * @param columnas Dirección donde se almacena la cantidad de columnas leídas.
 *
 * @pre 'ruta' debe ser una cadena terminada en '\0' y las líneas del archivo no deben
 *      superar los 1023 caracteres.
 * @post Si retorna un puntero no nulo, '*filas' y '*columnas' contienen las dimensiones
 *       y el bloque contiene los valores del archivo; el llamador es responsable de
 *       liberarlo con free. En caso contrario, '*filas' y '*columnas' quedan en 0.
 *
 * @return Puntero al bloque con la matriz, o NULL si algún parámetro es NULL, si no se
 *         puede abrir el archivo, si está vacío, si alguna fila tiene distinta cantidad
 *         de valores que la primera, si hay valores no numéricos o si falla la reserva
 *         de memoria.
 */
int *cargar_matriz_csv(const char *ruta, size_t *filas, size_t *columnas);
 
/**
 * @brief Crea una nueva matriz con las filas cuyo valor en una columna supera un umbral.
 *
 * @param matriz Matriz de origen.
 * @param filas Cantidad de filas de 'matriz'.
 * @param columnas Cantidad de columnas de 'matriz'.
 * @param columna Índice (base cero) de la columna sobre la que se evalúa la condición.
 * @param umbral Valor que debe ser superado estrictamente para conservar la fila.
 * @param filas_filtradas Dirección donde se almacena la cantidad de filas conservadas.
 *
 * @pre 'matriz' debe contener 'filas' * 'columnas' enteros y 'columna' debe ser menor
 *      que 'columnas'.
 * @post 'matriz' no se modifica. Si retorna un puntero no nulo, el nuevo bloque tiene
 *       '*filas_filtradas' filas y 'columnas' columnas, con las filas en su orden
 *       original, y el llamador es responsable de liberarlo con free. En caso
 *       contrario, '*filas_filtradas' queda en 0.
 *
 * @return Puntero a la matriz filtrada, o NULL si 'matriz' o 'filas_filtradas' son NULL,
 *         si 'columna' está fuera de rango, si ninguna fila cumple la condición o si
 *         falla la reserva de memoria.
 */
int *filtrar_filas_mayores(const int *matriz, size_t filas, size_t columnas, size_t columna, int umbral, size_t *filas_filtradas);
 
/**
 * @brief Calcula la suma de cada columna en un nuevo arreglo dinámico de floats.
 *
 * @param matriz Matriz sobre la que se calcula.
 * @param filas Cantidad de filas de 'matriz'.
 * @param columnas Cantidad de columnas de 'matriz'.
 *
 * @pre 'matriz' debe contener 'filas' * 'columnas' enteros.
 * @post 'matriz' no se modifica. El arreglo devuelto tiene 'columnas' elementos y el
 *       llamador es responsable de liberarlo con free.
 *
 * @return Puntero al arreglo con la suma de cada columna, o NULL si 'matriz' es NULL,
 *         'filas' o 'columnas' son 0 o falla la reserva de memoria.
 */
float *sumar_columnas(const int *matriz, size_t filas, size_t columnas);
 
/**
 * @brief Calcula el promedio de cada columna en un nuevo arreglo dinámico de floats.
 *
 * @param matriz Matriz sobre la que se calcula.
 * @param filas Cantidad de filas de 'matriz'.
 * @param columnas Cantidad de columnas de 'matriz'.
 *
 * @pre 'matriz' debe contener 'filas' * 'columnas' enteros.
 * @post 'matriz' no se modifica. El arreglo devuelto tiene 'columnas' elementos y el
 *       llamador es responsable de liberarlo con free.
 *
 * @return Puntero al arreglo con el promedio de cada columna, o NULL si 'matriz' es NULL,
 *         'filas' o 'columnas' son 0 o falla la reserva de memoria.
 */
float *promediar_columnas(const int *matriz, size_t filas, size_t columnas);
 
/**
 * @brief Exporta una matriz a un archivo CSV, una fila por línea y valores separados por comas.
 *
 * @param matriz Matriz a exportar.
 * @param filas Cantidad de filas de 'matriz'.
 * @param columnas Cantidad de columnas de 'matriz'.
 * @param ruta Ruta del archivo CSV a escribir.
 *
 * @pre 'matriz' debe contener 'filas' * 'columnas' enteros y 'ruta' debe estar terminada
 *      en '\0'.
 * @post 'matriz' no se modifica. Si retorna true, el archivo contiene la matriz completa;
 *       si ya existía, queda reemplazado.
 *
 * @return true si se escribió el archivo completo, o false si 'matriz' o 'ruta' son NULL,
 *         'filas' o 'columnas' son 0, o no se pudo abrir o escribir el archivo.
 */
bool exportar_matriz_csv(const int *matriz, size_t filas, size_t columnas, const char *ruta);

#endif 
