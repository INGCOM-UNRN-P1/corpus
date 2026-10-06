#ifndef MATRIZ_DINAMICA_H
#define MATRIZ_DINAMICA_H

#include <stdbool.h>
#include <stddef.h>



 /**
 * @brief Crea una matriz dinámica de enteros con datos en un bloque contiguo.
 *
 * Reserva un único bloque contiguo de filas * columnas enteros (inicializado en 0)
 * y un arreglo de @p filas punteros, donde el puntero i apunta al inicio de la
 * fila i dentro del bloque. Permite la notación matriz[i][j].
 *
 * @pre @p filas y @p columnas son mayores que 0 y su producto no desborda size_t.
 * @post Si retorna un puntero no NULL: matriz[0] apunta al inicio del bloque de
 *       datos, matriz[i] == matriz[0] + i * columnas y todos los elementos valen 0.
 *
 * @param filas Cantidad de filas de la matriz.
 * @param columnas Cantidad de columnas de la matriz.
 * @return Puntero al arreglo de punteros a fila, o NULL si @p filas o @p columnas
 *         es 0, el tamaño desborda size_t o falla la reserva de memoria.
 *
 * @note El llamador es responsable de liberar el resultado con matriz_destruir().
 */
int **matriz_crear(size_t filas, size_t columnas);
 
/**
 * @brief Libera una matriz creada con matriz_crear().
 *
 * Libera el bloque contiguo de datos (apuntado por matriz[0]) y luego el arreglo
 * de punteros a fila.
 *
 * @pre @p matriz es NULL o fue obtenida de matriz_crear() o matriz_cargar_desde_csv(),
 *      sin haberse modificado los punteros a fila ni liberado previamente.
 * @post Toda la memoria de la matriz queda liberada. @p matriz queda inválido:
 *       el llamador no debe volver a usarlo (conviene asignarle NULL).
 *
 * @param matriz Matriz a liberar. Si es NULL no se realiza ninguna acción.
 */
void matriz_destruir(int **matriz);
 
/**
 * @brief Crea y carga una matriz dinámica desde un archivo CSV de enteros.
 *
 * El archivo contiene una fila de la matriz por línea, con valores enteros
 * separados por coma. Se toleran espacios o tabulaciones alrededor de los valores,
 * finales de línea "\n" o "\r\n", líneas en blanco (se ignoran) y la ausencia de
 * salto de línea final. Las dimensiones se determinan leyendo el archivo: la cantidad
 * de filas es la cantidad de líneas con datos y la de columnas es la cantidad de
 * valores de la primera fila.
 *
 * @pre @p ruta apunta a una cadena válida; @p filas y @p columnas son punteros válidos.
 * @post Si retorna un puntero no NULL, apunta a una matriz creada con matriz_crear()
 *       con *@p filas filas y *@p columnas columnas cargada con los valores del
 *       archivo. Si retorna NULL, *@p filas y *@p columnas valen 0.
 *
 * @param ruta Ruta del archivo CSV.
 * @param[out] filas Recibe la cantidad de filas leídas.
 * @param[out] columnas Recibe la cantidad de columnas leídas.
 * @return Puntero a la matriz cargada, o NULL si algún parámetro es NULL, el archivo
 *         no se puede abrir, está vacío, tiene filas con distinta cantidad de valores,
 *         contiene valores que no son enteros válidos (o fuera del rango de int) o
 *         falla la reserva de memoria.
 *
 * @note El llamador es responsable de liberar el resultado con matriz_destruir().
 */
int **matriz_cargar_desde_csv(const char *ruta, size_t *filas, size_t *columnas);
 

#endif 
