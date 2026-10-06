/**
 * @file puntero_cadena.h
 * @brief Cadenas seguras reimplementadas con aritmética de punteros.
 *
 * Trabajo Práctico 3 - Programación 1
 * Universidad Nacional de Río Negro - Ingeniería en Computación
 *
 * Complementario al TP2 (libcadenas): reemplaza toda indexación por
 * desplazamiento directo de punteros (*p, p++), manteniendo los mismos
 * contratos de seguridad (capacidad acotada, terminador '\0' garantizado).
 */

#ifndef PUNTERO_CADENA_H
#define PUNTERO_CADENA_H

#include <stdbool.h>
#include <stddef.h>




/**
 * @brief Cuenta los caracteres de una cadena antes del terminador nulo,
 *        recorriendo la memoria exclusivamente con aritmética de punteros.
 *
 * @pre Si 'cadena' no es nula, apunta a una región válida de al menos
 *      'capacidad' bytes.
 * @post No se lee memoria más allá de 'capacidad' bytes desde 'cadena'.
 *
 * @param cadena cuyos caracteres se desean contar.
 * @param capacidad Cantidad máxima de bytes que se pueden inspeccionar.
 *
 * @return Cantidad de caracteres antes del '\0'.
 *         Retorna 'capacidad' si no se encuentra '\0' dentro del rango.
 *         Retorna 0 si 'cadena' es nula o 'capacidad' es 0.
 */
size_t longitud_con_punteros(const char *cadena, size_t capacidad);

/**
 * @brief Copia una cadena de origen en un búfer de destino de capacidad limitada,
 *        desplazando punteros de destino y origen sin usar el operador de indexación.
 *
 * @pre Si 'destino' no es nulo, apunta a un búfer válido de al menos
 *      'capacidad' bytes. Si 'origen' no es nulo, apunta a una cadena
 *      terminada en '\0'.
 * @post Si 'capacidad' > 0 y 'destino' no es nulo, 'destino' queda
 *       terminado en '\0' dentro del rango [0, capacidad - 1].
 *
 * @param destino Búfer donde se copiará la cadena de origen.
 * @param capacidad Cantidad máxima de bytes disponibles en 'destino'.
 * @param origen Cadena que se desea copiar.
 *
 * @return true si 'origen' se copió completo, incluyendo el terminador.
 *         false si hubo truncamiento, si 'destino' o 'origen' son nulos,
 *         o si 'capacidad' es 0.
 */
bool copiar_con_punteros(char *destino, size_t capacidad,
                          const char *origen);

/**
 * @brief Anexa una cadena de origen al final del texto existente en un
 *        búfer de destino, localizando el final mediante avance de punteros
 *        y copiando los caracteres nuevos sin usar el operador de indexación.
 *
 * @pre Si 'destino' no es nulo, contiene una cadena terminada en '\0'
 *      dentro de los primeros 'capacidad' bytes. Si 'origen' no es nulo,
 *      apunta a una cadena terminada en '\0'.
 * @post Si 'capacidad' > 0 y 'destino' no es nulo, 'destino' queda
 *       terminado en '\0'.
 *
 * @param destino Búfer con el texto existente, donde se anexará 'origen'.
 * @param capacidad Cantidad máxima de bytes disponibles en 'destino'.
 * @param origen Cadena que se desea anexar.
 *
 * @return true si todo 'origen' se concatenó sin truncamiento.
 *         false si hubo truncamiento, si 'destino' no contiene '\0'
 *         dentro de la capacidad, si 'destino' o 'origen' son nulos,
 *         o si 'capacidad' es 0.
 */
bool concatenar_con_punteros(char *destino, size_t capacidad,
                              const char *origen);

#endif 