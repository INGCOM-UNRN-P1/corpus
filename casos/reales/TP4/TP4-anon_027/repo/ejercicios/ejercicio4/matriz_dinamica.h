#ifndef MATRIZ_DINAMICA_H
#define MATRIZ_DINAMICA_H

#include <stdbool.h>
#include <stddef.h>


 /** 
 * @brief recibe size_t filas y size_t columnas. Reserva un bloque
 * contiguo en el heap para (filas * columnas * sizeof(int)) y un 
 * arreglo de punteros (filas * sizeof(int*)) que apuntan al inicio 
 * de cada fila.
 *
 * @param filas define las filas del bloque
 * @param columnas define las columnas del bloque
 * 
 * @pre toda asignación con `malloc`/`calloc`/`realloc` 
 * debe liberarse con `free`.
 * 
 * @return el puntero int** o NULL ante error.
 *
 * @post debe reservar en el heap un bloque contiguo 
 * y un arreglo de punteros que apuntan al inicio de cada 
 * fila con los parámetros dados. 
 *
 * @invariant -------------------------------------
*/
 int** matriz_crear(size_t filas, size_t columnas); 
 



 /** 
 * @brief Libera el bloque de datos y el arreglo
 *    de punteros a filas, previniendo memory leaks.
 *
 * @param matriz puntero de puntero que apunta al bloque de datos
 * y al arreglo de punteros a filas.
 * 
 * @pre la funcion debe prevenir los 'memory leaks'
 * 
 * @return -------------------------------------------------------
 *
 * @post debe retornar una nueva cadena concatenada en heap con su 
 * contenido de 'primera' y 'segunda' finalizado de '\0'
 *
 * @invariant ----------------------------------------------------
*/
void matriz_destruir(int ***matriz);





 /** 
 * @brief recibe la ruta de un archivo CSV con valores enteros
 * separados por coma, lee las dimensiones e inicializa y carga 
 * la matriz dinámica.
 *
 * @param ruta_archivo Ruta del archivo CSV a interactuar.
 * @param out_filas Puntero de salida donde se guardará la 
 * cantidad de filas leídas.
 * 
 * @param out_columnas Puntero de salida donde se guardará la 
 * cantidad de columnas leídas.
 * 
 * @pre El archivo debe existir, contener valores enteros 
 * separados por comas y poseer la misma cantidad de columnas 
 * en todas las filas.
 * 
 * 
 * @return int** Puntero a la matriz dinámica con los datos 
 * cargados, o NULL ante error.
 *
 * @post La matriz devuelta debe ser liberada posteriormente 
 * con matriz_destruir().
 *
 * @invariant ruta_archivo
*/
int** matriz_cargar_desde_csv(const char *ruta_archivo, size_t *out_filas, size_t *out_columnas);


 /**
 *implementar en matriz_dinamica.c,
 * programa en main.c y pruebas con p1_test en prueba.c.
 */
#endif 
