#ifndef TEXTO_H
#define TEXTO_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Une dos cadenas de texto intercalando un separador en un búfer destino acotado.
 * 
 * Utiliza las funciones de copia y concatenación provistas por libcadenas para garantizar
 * un manejo seguro de memoria y evitar desbordamientos de búfer.
 * 
 * @param destino Búfer de caracteres donde se almacenará el resultado.
 * @param capacidad Tamaño total máximo disponible en el búfer destino.
 * @param primero Primera cadena de texto a copiar.
 * @param segundo Segunda cadena de texto a concatenar al final.
 * @param separador Cadena de texto intercalada entre la primera y la segunda.
 * @return true Si la unión de las cadenas y el separador se completó exitosamente.
 * @return false Si alguno de los punteros es NULL, la capacidad es 0, o si el espacio no es suficiente.
 * @pre El búfer destino debe ser un arreglo de caracteres válido.
 * @post Si no hay espacio suficiente, el contenido de destino dependerá del comportamiento de libcadenas.
 */
bool unir_con_separador(char destino[],
                        size_t capacidad,
                        const char primero[],
                        const char segundo[],
                        const char separador[]);

#endif
