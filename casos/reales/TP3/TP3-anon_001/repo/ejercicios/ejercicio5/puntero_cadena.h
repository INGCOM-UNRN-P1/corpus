#ifndef PUNTERO_CADENA_H
#define PUNTERO_CADENA_H

#include <stdbool.h>
#include <stddef.h>



/**
 * @brief Copia una cadena de origen a un destino utilizando únicamente aritmética de punteros.
 *
 * @details Desplaza los punteros 'destino' y 'origen' copia a copia (*dst++ = *src++).
 *          Garantiza la colocación del terminador nulo '\0' dentro del rango [0, capacidad - 1].
 *
 * @param[out] destino Puntero al buffer de memoria donde se copiará la cadena.
 * @param[in] capacidad disponible en el buffer destino en bytes.
 * @param[in] origen Puntero constante a la cadena de caracteres origen.
 *
 * @pre Si 'destino' u 'origen' no son NULL, 'capacidad' debe ser mayor a 0.
 * @post La cadena en 'destino' siempre terminará en '\0' si 'capacidad' > 0.
 *
 * @return true si la cadena origen cupo completa sin truncarse.
 *         false si hubo truncamiento (origen más largo que la capacidad) o si los parámetros son inválidos.
 */
bool copiar_con_punteros(char *destino, size_t capacidad, const char *origen);

/**
 * @brief Concatena una cadena de origen al final de la cadena destino utilizando punteros.
 *
 * @details Avanza un puntero auxiliar hasta el terminador '\0' existente en 'destino'
 *          y a continuación copia los caracteres de 'origen' respetando la capacidad restante.
 *          Garantiza el terminador nulo al final.
 *
 * @param[in,out] destino Puntero al buffer que contiene la cadena inicial y recibirá el resultado.
 * @param[in] capacidad Tamaño total del buffer 'destino'.
 * @param[in] origen Puntero constante a la cadena a anexar.
 *
 * @pre 'destino' debe contener una cadena bien formada terminada en '\0'.
 * @post La cadena concatenada en 'destino' siempre terminará en '\0' si 'capacidad' > 0.
 *
 * @return true si la concatenación se completó sin truncamiento.
 *         false si la cadena resultante fue truncada o si los parámetros son inválidos.
 */
bool concatenar_con_punteros(char *destino, size_t capacidad, const char *origen);


#endif 
