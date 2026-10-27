/**
 * @file cadena_segura.h
 * @brief Gestion de cadenas dinamicas seguras en heap con capacidad auto-redimensionable.
 *
 * Trabajo Practico 5 - Programacion 1
 * Universidad Nacional de Rio Negro - Ingenieria en Computacion
 */

#ifndef CADENA_SEGURA_H
#define CADENA_SEGURA_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @struct cadena_segura
 * @brief Estructura que encapsula una cadena de caracteres terminada en '\0'
 *        con longitud explicita y capacidad fisica en heap.
 */
typedef struct cadena_segura {
    char *texto;       
    size_t longitud;   
    size_t capacidad;  
} cadena_segura_t;

/**
 * @brief Inicializa una cadena segura copiando el contenido de un literal o cadena C.
 *
 * @param cadena Puntero a la estructura cadena_segura_t a inicializar.
 * @param literal Puntero a la cadena de caracteres origen (o NULL para cadena vacia).
 * @return true si la reserva de memoria fue exitosa, false en caso contrario.
 */
bool cadena_segura_crear(cadena_segura_t *cadena, const char *literal);

/**
 * @brief Libera la memoria dinamica asociada y restablece los campos a cero.
 *
 * @param cadena Puntero a la estructura cadena_segura_t a destruir.
 */
void cadena_segura_destruir(cadena_segura_t *cadena);

/**
 * @brief Concatena una cadena C al final de la cadena segura, redimensionando si es necesario.
 *
 * @param cadena Puntero a la estructura cadena_segura_t destino.
 * @param sufijo Puntero a la cadena a anexar (si es NULL o vacia, no modifica la cadena).
 * @return true si la operacion fue exitosa, false en caso de fallo de asignacion de memoria.
 */
bool cadena_segura_concatenar(cadena_segura_t *cadena, const char *sufijo);

/**
 * @brief Extrae una subcadena a partir de una posicion de inicio y longitud maxima.
 *
 * @param origen Puntero a la cadena segura de origen.
 * @param inicio Indice base (0-indexado) donde comienza la subcadena.
 * @param longitud Cantidad maxima de caracteres a extraer.
 * @param destino Puntero a la estructura donde se inicializara la nueva subcadena.
 * @return true si se extrajo y creo exitosamente la subcadena, false en caso de error.
 */
bool cadena_segura_subcadena(const cadena_segura_t *origen, size_t inicio, size_t longitud, cadena_segura_t *destino);

/**
 * @brief Crea un clon profundo independiente de la cadena de origen.
 *
 * @param origen Puntero a la cadena segura a duplicar.
 * @param destino Puntero a la estructura donde se creara la copia independiente.
 * @return true si la clonacion fue exitosa, false en caso de error.
 */
bool cadena_segura_clonar(const cadena_segura_t *origen, cadena_segura_t *destino);

/**
 * @brief Busca la primera aparicion de una subcadena (aguja) dentro de la cadena segura.
 *
 * @param cadena Puntero a la cadena segura donde buscar.
 * @param aguja Subcadena a localizar en la cadena.
 * @return Indice base 0 de la primera coincidencia, o -1 si no se encuentra o parametros invalidos.
 */
int cadena_segura_buscar(const cadena_segura_t *cadena, const char *aguja);

#endif 
