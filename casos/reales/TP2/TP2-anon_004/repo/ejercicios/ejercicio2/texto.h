#ifndef TEXTO_H
#define TEXTO_H

#include <stdbool.h>
#include <stddef.h>



/**
 * @brief Une dos cadenas de texto intercalando un separador en un bufer destino seguro sin desbordar la capacidad.
 *
 * @pre destino apunta a un bufer de al menos capacidad bytes, y primero, segundo y separador son cadenas terminadas en '\0'.
 * @post Copia primero, concatena separador y luego segundo en destino garantizando '\0' si capacidad > 0; retorna false ante truncamiento o error.
 *
 * @param destino   Bufer de memoria donde se escribira el texto resultante de la union.
 * @param capacidad Capacidad fisica total del bufer destino en bytes incluyendo el byte nulo.
 * @param primero   Primera cadena de texto a volcar en el inicio de destino (solo lectura).
 * @param segundo   Segunda cadena de texto que se anexara tras el separador (solo lectura).
 * @param separador Cadena de texto intermedia que se intercalara entre ambas cadenas (solo lectura).
 *
 * @return bool true si se unieron todas las cadenas sin truncamiento; false si hubo truncamiento o parametros invalidos.
 */
bool unir_con_separador(char destino[],
                        size_t capacidad,
                        const char primero[],
                        const char segundo[],
                        const char separador[]);

#endif
