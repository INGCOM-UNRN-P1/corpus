#ifndef CONSULTA_CSV_H
#define CONSULTA_CSV_H

#include <stdbool.h>
#include <stddef.h>



 /**
  * @brief Lee un csv y carga los datos en una natriz dinamica
  * 
  * @param ruta Ruta del arvhico a leer
  * @param out_filas Puntero donde se guarda la cantidad de filas leidas
  * @param out_columnas Puntero donde se guardara la cantidad de columnas leidas
  * 
  * @return int** Matriz dinamica cargada o NULL si hay error
  */
 int **matriz_cargar_csv(const char *ruta, size_t *out_filas, size_t *out_columnas);

 /**
  * @brief Filtra filas de una matriz genenrando una nueva matriz
  * 
  * @param original Matriz original
  * @param filas Filas de la matriz original
  * @param columnas Columnas de la matriz original
  * @param co_filtro Indice de la columna a evaluar
  * @param umbral Valor que debe superarse para conservar la fila
  * @param out_filas Puntero donde se guardara la cantidad de filas 
  * 
  * @return int** Nueva matriz filtrada o NULL si hay error
  */
 int **matriz_filtrar(int **original, size_t filas, size_t columnas, size_t col_filtro, int umbral, size_t *out_filas);

 /**
  * @brief Caltula el promedio matematico de cada columna en la matriz
  * 
  * @param matriz Matris original
  * @param filas Cantidad de filas
  * @param columnas Cantidad de columnas
  * 
  * @return float* Arreglo dinamico con los promedios o NULL si hay error
  */
 float *matriz_promedio_columnas(int **matriz, size_t filas, size_t columnas);

 /**
  * @brief Exporta una matriz a un archivo csv
  * 
  * @param matriz Matriz a esportar
  * @param filas Cantidad de filas
  * @param columnas Cantidad de columnas
  * @param ruta Ruta del archivo de destino
  * 
  * @return true Si se exporto con exito o false en caso contrario
  */
 bool matriz_exportar_csv(int **matriz, size_t filas, size_t columnas, const char *ruta);

 /**
  * @brief Libera la memoria de una matriz contigua
  * 
  * @param matriz Matriz a destruir
  */
 void matriz_liberar(int **matriz);

#endif 
