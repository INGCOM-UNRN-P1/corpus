#ifndef MATRIZ_DINAMICA_H
#define MATRIZ_DINAMICA_H

#include <stddef.h>




/**
 * @brief Crea una matriz dinámica de enteros con almacenamiento contiguo.
 *
 * Reserva un bloque para 'filas * columnas' enteros y otro para los punteros
 * correspondientes a cada fila, permitiendo acceder a los elementos mediante
 * la notación matriz[i][j].
 *
 * @param filas Cantidad de filas.
 * @param columnas Cantidad de columnas.
 *
 * @post Si la creación es exitosa, todas las filas apuntan a posiciones del
 *       mismo bloque contiguo de datos.
 *       Si alguna reserva falla, se libera cualquier memoria reservada
 *       previamente.
 *
 * @return Puntero a la matriz creada, o NULL si alguna dimensión es cero o
 *         si falla una reserva de memoria.
 */
int **matriz_crear(size_t filas, size_t columnas);


/**
 * @brief Libera una matriz dinámica y toda la memoria asociada.
 *
 * @param matriz Matriz que se desea liberar.
 *
 * @post El bloque de datos y el arreglo de punteros quedan liberados.
 *       Si 'matriz' es NULL, no se realiza ninguna acción.
 *
 * @note El puntero del llamador no se modifica y queda inválido después de
 *       liberar la matriz.
 */
void matriz_destruir(int **matriz);


/**
 * @brief Carga una matriz de enteros desde un archivo CSV.
 *
 * Determina las dimensiones a partir del contenido del archivo, crea la matriz
 * dinámica y almacena en ella los valores leídos.
 *
 * @param ruta Ruta del archivo CSV.
 * @param filas Dirección donde se almacena la cantidad de filas leídas.
 * @param columnas Dirección donde se almacena la cantidad de columnas leídas.
 *
 * @pre 'ruta', 'filas' y 'columnas' deben apuntar a memoria válida.
 * @pre El archivo debe contener una matriz rectangular de enteros separados
 *      por comas, con una fila por línea.
 *
 * @post Si la carga es exitosa, '*filas' y '*columnas' contienen las
 *       dimensiones de la matriz retornada y el archivo queda cerrado.
 *       Ante un error, no queda memoria dinámica reservada por la función
 *       ni archivos abiertos.
 *
 * @return Puntero a la matriz cargada, o NULL si los argumentos son inválidos,
 *         el archivo no puede abrirse, está vacío, contiene datos que no pueden
 *         leerse como enteros o falla la creación de la matriz.
 */
int **matriz_cargar_desde_csv(const char *ruta,
                              size_t *filas,
                              size_t *columnas);

#endif 