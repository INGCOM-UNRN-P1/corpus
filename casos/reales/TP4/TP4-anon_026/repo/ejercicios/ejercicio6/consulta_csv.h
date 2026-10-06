#ifndef CONSULTA_CSV_H
#define CONSULTA_CSV_H

#include <stdbool.h>
#include <stddef.h>





 
/**
 * @brief Carga una matriz de enteros de dimensiones variables desde un archivo CSV.
 *
 * El archivo contiene una fila de la matriz por línea, con valores enteros
 * separados por coma. Se toleran espacios o tabulaciones alrededor de los valores,
 * finales de línea "\n" o "\r\n", líneas en blanco (se ignoran) y la ausencia de
 * salto de línea final. Las dimensiones se determinan leyendo el archivo: la cantidad
 * de filas es la cantidad de líneas con datos y la de columnas es la cantidad de
 * valores de la primera fila.
 * @pre @p ruta apunta a una cadena válida; @p filas y @p columnas son punteros válidos.
 * @post Si retorna un puntero no NULL, apunta a un bloque contiguo en heap de
 *@p filas * *@p columnas enteros con los valores del archivo. Si retorna NULL, *@p filas y *@p columnas valen 0.
 * @param ruta Ruta del archivo CSV.
 * @param[out] filas Recibe la cantidad de filas leídas.
 * @param[out] columnas Recibe la cantidad de columnas leídas.
 * @return Bloque con la matriz cargada, o NULL si algún parámetro es NULL, el archivo no se puede abrir, está vacío, tiene filas con distinta cantidad de valores, contiene valores que no son enteros válidos (o fuera del rango de int) o falla la reserva de memoria.
 * @note El llamador es responsable de liberar el resultado con free().
 */
int *cargar_matriz_csv(const char *ruta, size_t *filas, size_t *columnas);
 
/**
 * @brief Filtra las filas cuyo valor en una columna es mayor que un umbral.
 * Genera una nueva matriz dinámica reducida en el heap con las filas de
 * @p matriz que cumplen matriz[fila][columna] > umbral, conservando su orden.
 * La matriz original no se modifica.
 * @pre @p matriz apunta a un bloque de @p filas * @p columnas enteros;
 *      @p columna < @p columnas; @p filas_resultado es un puntero válido.
 * @post Si retorna un puntero no NULL, apunta a un bloque contiguo en heap de
 *       *@p filas_resultado * @p columnas enteros (todas las filas que cumplen la
 *       condición). Si retorna NULL, *@p filas_resultado vale 0.
 *
 * @param matriz Matriz de entrada.
 * @param filas Cantidad de filas de @p matriz.
 * @param columnas Cantidad de columnas de @p matriz.
 * @param columna Índice (desde 0) de la columna sobre la que se evalúa la condición.
 * @param umbral Valor que debe superarse estrictamente.
 * @param[out] filas_resultado Recibe la cantidad de filas de la matriz filtrada.
 * @return Bloque con la matriz filtrada, o NULL si algún parámetro es inválido
 *         (puntero NULL, @p filas o @p columnas igual a 0, @p columna fuera de
 *         rango), si ninguna fila cumple la condición o si falla la reserva de memoria.
 *
 * @note El llamador es responsable de liberar el resultado con free().
 */
int *filtrar_filas_mayor_que(const int *matriz, size_t filas, size_t columnas, size_t columna, int umbral, size_t *filas_resultado);
 
/**
 * @brief Calcula la suma de cada columna en un arreglo dinámico de floats.
 *
 * @pre @p matriz apunta a un bloque de @p filas * @p columnas enteros.
 * @post Si retorna un puntero no NULL, apunta a un arreglo en heap de
 *       @p columnas floats donde el elemento j es la suma de la columna j.
 *       La matriz no se modifica.
 *
 * @param matriz Matriz de entrada.
 * @param filas Cantidad de filas de @p matriz.
 * @param columnas Cantidad de columnas de @p matriz.
 * @return Arreglo de sumas por columna, o NULL si @p matriz es NULL, @p filas o
 *         @p columnas es 0 o falla la reserva de memoria.
 *
 * @note Las sumas se acumulan en double y se convierten a float al final.
 * @note El llamador es responsable de liberar el resultado con free().
 */
float *calcular_sumas_columnas(const int *matriz, size_t filas, size_t columnas);
 
/**
 * @brief Calcula el promedio de cada columna en un arreglo dinámico de floats.
 *
 * @pre @p matriz apunta a un bloque de @p filas * @p columnas enteros.
 * @post Si retorna un puntero no NULL, apunta a un arreglo en heap de
 *       @p columnas floats donde el elemento j es el promedio (suma / filas) de la
 *       columna j. La matriz no se modifica.
 *
 * @param matriz Matriz de entrada.
 * @param filas Cantidad de filas de @p matriz.
 * @param columnas Cantidad de columnas de @p matriz.
 * @return Arreglo de promedios por columna, o NULL si @p matriz es NULL, @p filas o
 *         @p columnas es 0 o falla la reserva de memoria.
 *
 * @note El llamador es responsable de liberar el resultado con free().
 */
float *calcular_promedios_columnas(const int *matriz, size_t filas, size_t columnas);
 
/**
 * @brief Exporta una matriz de enteros a un archivo CSV.
 *
 * Escribe una fila por línea, con los valores separados por coma y cada línea
 * terminada en "\n". Si el archivo existe, se sobrescribe. El resultado puede
 * volver a leerse con cargar_matriz_csv().
 *
 * @pre @p matriz apunta a un bloque de @p filas * @p columnas enteros.
 * @post Si retorna true, el archivo @p ruta contiene la matriz completa.
 *
 * @param ruta Ruta del archivo CSV a crear.
 * @param matriz Matriz a exportar.
 * @param filas Cantidad de filas de @p matriz.
 * @param columnas Cantidad de columnas de @p matriz.
 * @return true si se escribió el archivo completo; false si @p ruta o @p matriz es
 *         NULL, @p filas o @p columnas es 0, no se pudo crear el archivo o falló la
 *         escritura.
 */
bool exportar_matriz_csv(const char *ruta, const int *matriz, size_t filas, size_t columnas);
 

#endif 
