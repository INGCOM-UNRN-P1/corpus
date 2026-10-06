#ifndef TEXTO_H
#define TEXTO_H

#include <stdbool.h>
#include <stddef.h>

/**
 * Une dos cadenas de texto colocando un separador entre ambas.
 *
 * Utiliza las funciones seguras de libcadenas para copiar y concatenar
 * sin exceder la capacidad del buffer destino.
 *
 * @param destino buffer donde se almacenara la cadena resultante.
 * @param capacidad cantidad total de bytes disponibles en destino.
 * @param primero primera cadena a copiar.
 * @param segundo segunda cadena a concatenar.
 * @param separador cadena que se coloca entre primero y segundo.
 * @return true si toda la operacion se completo sin truncamiento.
 *         Retorna false si algun parametro es invalido o si el buffer
 *         no tiene capacidad suficiente.
 */
bool unir_con_separador(char destino[],
                        size_t capacidad,
                        const char primero[],
                        const char segundo[],
                        const char separador[]);

#endif
