/**
 * @file cadena_dinamica.c
 * @brief Implementación para Ejercicio 3 (Cadenas en Heap).
 */

#include "cadena_dinamica.h"


char *invertir_cadena_dinamico(const char *cadena, size_t capacidad)
{
    if (cadena == NULL || capacidad == 0)
    {
        return NULL;
    }

    size_t largo = 0;
    while (largo < capacidad && cadena[largo] != '\0')
    {
        largo++;
    }

    char *bloque = malloc(largo);
    if (bloque == NULL)
    {
        return NULL;
    }

    for (size_t i = 0; i < largo; i++)
    {
        bloque[(largo - i) - 1] = cadena[i];
    }
    largo = '\0';

    return bloque;
}

char **partir_por_delimitador(const char *cadena, size_t capacidad, char caracter, size_t *cantidad)
{
    if (cadena == NULL || cantidad == NULL || capacidad == 0)
    {
        return NULL;
    }

    size_t largo = 0;
    while (largo < capacidad && cadena[largo] != '\0')
    {
        largo++;
    }

    *cantidad = 1;

    for (size_t i = 0; i < largo; i++)
    {
        if (cadena[i] == caracter)
        {
            (*cantidad)++;
        }
    }

    // Determina el indice donde comienza cada token para saber donde 
    // empezar y terminar de copiar con cadena_subcadena_segura
    int *indices_tokens = malloc(sizeof(int) * (*cantidad + 1));
    if (indices_tokens == NULL)
    {
        return NULL;
    }
    // Guarda el compenzo del primer token y el fin del ultimo a la fuerza antes
    // de calcular el resto de indices
    indices_tokens[0] = 0;
    indices_tokens[*cantidad] = largo + 1;
    size_t control_indices = 1;
    for (size_t i = 0; i < largo; i++)
    {
        if (cadena[i] == caracter)
        {
            indices_tokens[control_indices] = (i+1);
            control_indices++;
        }
    }

    char **tokens = malloc(sizeof(char*) * (*cantidad));
    if (tokens == NULL)
    {
        return NULL;
    }

    for (size_t i = 0; i < *cantidad; i++)
    {
        size_t inicio = (size_t)indices_tokens[i];
        size_t cant = (size_t)((indices_tokens[i + 1]) - inicio) - 1;
        tokens[i] = cadena_subcadena_dinamica(cadena, capacidad, inicio, cant);
    }

    liberar_bloque_enteros(&indices_tokens);
    return tokens;
}
