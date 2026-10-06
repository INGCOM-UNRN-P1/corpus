/**
 * @file registro_csv.c
 * @brief Implementación de tokenización dinámica de cadenas en heap (char** sin structs).
 */

#include "registro_csv.h"

char **dividir_linea_csv (const char *linea, char delimitador, size_t *cantidad_tokens, int *error)
{
    // Mejor manejar una variable de error local para no desreferenciar punteros que pueden ser NULL
    int error_local;
    if (error == NULL)
    {
        error = &error_local;   // asi nunca desreferencio NULL
    }
    *error = SIN_ERROR;

    if (linea == NULL || cantidad_tokens == NULL)
    {
        *error = ERROR_PUNTERO_NULO;
        return NULL;
    }
    else
    {
        size_t longitud_cadena = longitud_util_cadena(linea, MAX_LINEA);
        if (longitud_cadena == MAX_LINEA)
        {
            *error = ERROR_SIN_TERMINADOR;
            return NULL;
        }
        else if (longitud_cadena == 0)
        {
            *error = ERROR_CAPACIDAD;
            return NULL;
        }
        else
        {
            size_t cantidad_elementos = 0;
            const char *ptr_senalador = linea;

            char **bloque_punteros = NULL;

            while(ptr_senalador < linea + longitud_cadena)
            {
                if (*ptr_senalador != delimitador)
                {
                    // cantidad_elementos++;    lo puse despues del realloc y la duplicación para que no incremente si falla la memoria
                    const char *ptr_inicio_caracter = ptr_senalador;
                    while (ptr_senalador < linea + longitud_cadena && *ptr_senalador != delimitador)
                    {
                        ptr_senalador++;
                    }

                    char **ptr_temp = realloc(bloque_punteros, (cantidad_elementos + 1) * (sizeof(*bloque_punteros)));
                    if(ptr_temp == NULL)
                    {
                        *error = ERROR_MEMORIA;
                        liberar_arreglo_cadenas(&bloque_punteros, cantidad_elementos);    // libero la memoria que ya asigné
                        return NULL;
                    }
                    else
                    {
                        bloque_punteros = ptr_temp;
                        bloque_punteros[cantidad_elementos] = cadena_duplicar_segura(ptr_inicio_caracter, ptr_senalador - ptr_inicio_caracter);
                        if (bloque_punteros[cantidad_elementos] == NULL)
                        {
                            *error = ERROR_MEMORIA;
                            liberar_arreglo_cadenas(&bloque_punteros, cantidad_elementos);    // libero la memoria que ya asigné
                            return NULL;
                        }
                        cantidad_elementos++;
                    }
                }
                else
                {
                    ptr_senalador++;
                }
            }
            if (cantidad_elementos == 0)
            {
                *error = ERROR_SIN_CARACTER_VALIDO;
            }
            *cantidad_tokens = cantidad_elementos;
            return bloque_punteros;
        }
    }
}

void liberar_arreglo_cadenas (char ***puntero_arreglo, size_t cantidad)
{
    if (puntero_arreglo == NULL || *puntero_arreglo == NULL)
    {
        return;
    }

    for (size_t i = 0; i < cantidad; i++)
    {
        free((*puntero_arreglo)[i]);
    }
    free(*puntero_arreglo);
    *puntero_arreglo = NULL;
}