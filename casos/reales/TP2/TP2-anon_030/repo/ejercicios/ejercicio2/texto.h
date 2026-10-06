#ifndef TEXTO_H
#define TEXTO_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Une dos cadenas colocando un separador entre ellas.
 *
 * La funcion copia la primera cadena en destino, luego agrega
 * el separador y finalmente agrega la segunda cadena.
 * Utiliza las funciones seguras de libcadenas.
 *
 * @param destino Buffer donde se guarda el texto resultante.
 * @param capacidad Capacidad total del buffer destino.
 * @param primero Primera cadena que se desea unir.
 * @param segundo Segunda cadena que se desea unir.
 * @param separador Cadena que se coloca entre primero y segundo.
 *
 * @pre destino debe tener espacio para capacidad bytes.
 * @pre primero, segundo y separador deben ser cadenas validas.
 *
 * @post Si capacidad es mayor que 0, destino queda terminado en '\0'.
 *
 * @return true si toda la union se realizo sin truncamiento.
 * @return false si hubo truncamiento o algun parametro es invalido.
 */
bool unir_con_separador(
    char destino[],
    size_t capacidad,
    const char primero[],
    const char segundo[],
    const char separador[]
);

#endif
