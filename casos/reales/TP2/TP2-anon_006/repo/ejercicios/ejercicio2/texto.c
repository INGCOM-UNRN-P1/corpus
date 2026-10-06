/**
 * @file texto.c
 * @brief Implementación de funciones auxiliares para procesamiento de texto.
 *
 * Trabajo Práctico 2 - Programación 1
 * Universidad Nacional de Río Negro - Ingeniería en Computación
 */

#include <stdint.h>
#include "texto.h"
#include "cadenas.h"


bool unir_con_separador(char *destino, size_t tam_destino, 
                        const char *cadena1, const char *cadena2, 
                        const char *separador)
{
    if (destino == NULL || cadena1 == NULL || cadena2 == NULL || separador == NULL || tam_destino == 0) {
        return false;
    }

    size_t len1 = cadena_longitud(cadena1, SIZE_MAX);
    size_t len_sep = cadena_longitud(separador, SIZE_MAX);
    size_t len2 = cadena_longitud(cadena2, SIZE_MAX);

    
    if (len1 + len_sep + len2 + 1 > tam_destino) {
        return false;
    }

    
    cadena_copiar(destino, tam_destino, cadena1);

    
    cadena_concatenar(destino, tam_destino, separador);

    
    cadena_concatenar(destino, tam_destino, cadena2);

    return true;
}