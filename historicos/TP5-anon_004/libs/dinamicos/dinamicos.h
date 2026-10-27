/**
 * @file dinamicos.h
 * @brief Gestion de arreglos dinamicos auto-redimensionables con structs en C11.
 *
 * Trabajo Practico 5 - Programacion 1
 * Universidad Nacional de Rio Negro - Ingenieria en Computacion
 */

#ifndef DINAMICOS_H
#define DINAMICOS_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @struct arreglo_dinamico
 * @brief Estructura que representa un arreglo dinamico de enteros en heap.
 */
typedef struct arreglo_dinamico {
    int *datos;         
    size_t cantidad;    
    size_t capacidad;   
} arreglo_dinamico_t;

/**
 * @brief Inicializa un arreglo dinamico reservando capacidad inicial.
 *
 * @param arreglo Puntero a la estructura arreglo_dinamico_t a inicializar.
 * @param capacidad_inicial Capacidad inicial solicitada (si es 0, asigna 4).
 * @return true si la inicializacion fue exitosa, false en caso de error.
 */
bool arreglo_dinamico_crear(arreglo_dinamico_t *arreglo, size_t capacidad_inicial);

/**
 * @brief Libera la memoria en heap del arreglo y restablece los campos a cero.
 *
 * @param arreglo Puntero a la estructura arreglo_dinamico_t a destruir.
 */
void arreglo_dinamico_destruir(arreglo_dinamico_t *arreglo);

/**
 * @brief Agrega un valor al final del arreglo, redimensionando si es necesario.
 *
 * @param arreglo Puntero a la estructura arreglo_dinamico_t.
 * @param valor Entero a insertar.
 * @return true si se inserto exitosamente, false en caso de fallo de memoria.
 */
bool arreglo_dinamico_agregar(arreglo_dinamico_t *arreglo, int valor);

/**
 * @brief Obtiene un puntero al elemento en la posicion indicada.
 *
 * @param arreglo Puntero constante a la estructura arreglo_dinamico_t.
 * @param indice Posicion del elemento a consultar.
 * @return Puntero al entero solicitado, o NULL si indice fuera de rango.
 */
int *arreglo_dinamico_obtener(const arreglo_dinamico_t *arreglo, size_t indice);

/**
 * @brief Filtra los numeros pares del arreglo origen hacia un nuevo destino.
 *
 * @param origen Puntero al arreglo fuente de lectura.
 * @param destino Puntero al arreglo destino que sera creado y poblado.
 * @return true si el filtrado fue exitoso, false ante error de asignacion o NULL.
 */
bool arreglo_dinamico_filtrar_pares(const arreglo_dinamico_t *origen,
                                    arreglo_dinamico_t *destino);

/**
 * @brief Busca la primera aparicion de un valor en el arreglo.
 *
 * @param arreglo Puntero constante al arreglo donde buscar.
 * @param valor Entero a buscar.
 * @return Indice de la primera aparicion (>= 0), o -1 si no se encuentra.
 */
int arreglo_dinamico_buscar(const arreglo_dinamico_t *arreglo, int valor);

/**
 * @brief Invierte el orden de los elementos del arreglo in-place.
 *
 * @param arreglo Puntero al arreglo a invertir.
 */
void arreglo_dinamico_invertir(arreglo_dinamico_t *arreglo);

/**
 * @brief Elimina todas las ocurrencias de un valor compactando in-place.
 *
 * @param arreglo Puntero al arreglo a compactar.
 * @param valor Entero a eliminar.
 * @return Cantidad de elementos eliminados del arreglo.
 */
size_t arreglo_dinamico_compactar(arreglo_dinamico_t *arreglo, int valor);

#endif 
