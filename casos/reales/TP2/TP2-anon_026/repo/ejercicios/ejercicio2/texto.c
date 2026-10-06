/**
 * @file texto.c
 * @brief Implementación de procesamiento de texto con cadenas seguras.
 *
 * Trabajo Práctico 2 - Programación 1
 * Universidad Nacional de Río Negro - Ingeniería en Computación
 *
 * Esqueleto a ser completado por los estudiantes.
 */

#include "texto.h"
#include "cadenas.h"


bool unir_con_separador(char destino[],
                        size_t capacidad,
                        const char primero[],
                        const char segundo[],
                        const char separador[])
{
    bool copia_ok = cadena_copiar(destino, capacidad, primero);
    bool separador_ok = cadena_concatenar(destino, capacidad, separador);
    bool segundo_ok = cadena_concatenar(destino, capacidad, segundo);

    return copia_ok && separador_ok && segundo_ok;
}
