
#ifndef CONSULTA_CSV_H
#define CONSULTA_CSV_H

#include <stdbool.h>
#include <stddef.h>



/**
 * @brief Copia las filas cuyo valor en columna supera umbral.
 * 
 * @pre matriz tiene filas filas legibles de columnas enteros.
 * @post No modifica la entrada; filas_resultado queda en cero si no hay filas o falla.
 * 
 * @param matriz Matriz original.
 * @param filas Cantidad de filas originales.
 * @param columnas Ancho de la matriz.
 * @param columna Indice de columna, comenzando en cero.
 * @param umbral Valor que debe superarse estrictamente.
 * @param filas_resultado Salida escribible con cantidad seleccionada.
 * 
 * @return Nueva matriz a liberar con matriz_destruir, o NULL.
 */
int **filtrar_filas_csv(int *const *matriz, size_t filas, size_t columnas,
                        size_t columna, int umbral, size_t *filas_resultado);

/**
 * @brief Calcula las sumas por columna en un arreglo dinamico de floats.
 * 
 * @pre matriz contiene filas por columnas celdas legibles, dimensiones positivas.
 * @post No modifica matriz; el llamador libera el resultado con free.
 * 
 * @param matriz Matriz original.
 * @param filas Cantidad de filas.
 * @param columnas Cantidad de columnas.
 * 
 * @return Arreglo con columnas valores o NULL ante entrada invalida o fallo.
 */
float *sumar_columnas_csv(int *const *matriz, size_t filas, size_t columnas);

/**
 * @brief Calcula los promedios por columna en un arreglo dinamico de floats.
 * 
 * @pre matriz contiene filas por columnas celdas legibles, dimensiones positivas.
 * @post No modifica matriz; el llamador libera el resultado con free.
 * 
 * @param matriz Matriz original.
 * @param filas Cantidad de filas.
 * @param columnas Cantidad de columnas.
 * 
 * @return Arreglo con columnas promedios o NULL ante error.
 */
float *promediar_columnas_csv(int *const *matriz, size_t filas,
                              size_t columnas);

/**
 * @brief Exporta una matriz numerica como CSV sin encabezado.
 * 
 * @pre ruta indica un archivo de salida distinto de la entrada del usuario.
 * @post Reemplaza el archivo; un error de escritura puede dejarlo incompleto. Acepta matriz NULL cuando filas es cero y escribe un archivo vacio.
 * 
 * @param ruta Ruta del archivo a escribir.
 * @param matriz Datos a exportar.
 * @param filas Cantidad de filas.
 * @param columnas Cantidad positiva de columnas.
 * 
 * @return bool true si pudo escribir y cerrar todo; false ante error.
 */
bool exportar_matriz_csv(const char *ruta, int *const *matriz, size_t filas,
                         size_t columnas);

#endif 
