#ifndef MATRIZ_DINAMICA_H
#define MATRIZ_DINAMICA_H

#include <stdbool.h>
#include <stddef.h>



 /**
  * @brief Reserva memoria para una matriz 2D simulada usando un unico bloque contiguo de datos
  * 
  * @param filas Cantidad de filas de la matriz
  * @param columnas Cantidad de columnas de la matriz
  * 
  * @return int ** Puntero al arreglo de filas o NUULL si hay error
  */
 int **matriz_crear(size_t filas, size_t columnas);

 /**
  * @brief Libera la memoria de una matriz contigua 
  * 
  * @param matriz Puntero a la matriz a liberar
  */
 void matriz_destruir(int **matriz);

 /**
  * @brief Lee un archivo cvs y carga sus datos en una nueva matriz. 
  * Asume que la primera linea tiene el formato: filas,columna y el resto contiene datos enteros
  * 
  * @param ruta Directorio y nombre del archivo csv
  * @param out_filas Puntero de salida donde se guardara la cantidad de filas
  * @param out_columnas puntero de salida donde se guardara la cantidad de columnas
  * 
  * @return int** Puntero a la matriz cargada o NULL ante error
  */
 int **matriz_cargar_desde_csv(const char *ruta, size_t *out_files, size_t *out_columnas);

#endif 
