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
    bool exito = false;
    bool valido = ((destino != NULL) && (primero != NULL) && (segundo != NULL) 
                  && (separador != NULL) && (capacidad > 0));
    size_t requerido = 0;
    if (valido)
    {
        requerido = cadena_longitud(primero, capacidad) + cadena_longitud(separador, capacidad) + cadena_longitud(segundo, capacidad) + 1;
        if (capacidad >= requerido)
        {
            cadena_copiar(destino, capacidad, primero);
            cadena_concatenar(destino, capacidad, separador);
            cadena_concatenar(destino, capacidad, segundo);
            exito = true;
        }
    }
    return exito;
}
