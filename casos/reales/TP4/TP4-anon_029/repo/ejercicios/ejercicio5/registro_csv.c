/**
 * @file registro_csv.c
 * @brief Implementación de tokenización dinámica de
 *  cadenas en heap (char **sin structs).
 */

#include "registro_csv.h"

/**
 * @brief Descripción de la función dividir_linea_csv.
 *
 * @param linea Descripción del parámetro linea.
 * @param delimitador Descripción del parámetro delimitador.
 * @param cantidad_tokens Descripción del parámetro cantidad_tokens.
 * @return Descripción del valor de retorno.
 */
char **dividir_linea_csv(const char *linea, char delimitador,
                         size_t *cantidad_tokens)
{
    if (linea == NULL || cantidad_tokens == NULL)
    {
        if (cantidad_tokens != NULL)
        {
            *cantidad_tokens = 0;
        }
        return NULL;
    }

    // Contar cuantos tokens (delimitadores + 1) hay en la línea
    size_t tokens_totales = 1;
    for (size_t i = 0; linea[i] != '\0'; i++)
    {
        if (linea[i] == delimitador)
        {
            tokens_totales++;
        }
    }

    // Reservar memoria para el arreglo de punteros (char **)
    char **campo = (char **)malloc(tokens_totales * sizeof(char *));
    if (campo == NULL)
    {
        return NULL;
    }

    int indice = 0;
    int inicio_campo = 0;
    size_t indice_campo = 0;

    // Recorrer para extraer cada token
    while (linea[indice] != '\0')
    {
        if (linea[indice] == delimitador)
        {
            int largo_campo = indice - inicio_campo;
            campo[indice_campo] = cadena_duplicar_segura(&linea[inicio_campo],
                                                         largo_campo);
            indice_campo++;
            inicio_campo = indice + 1;
        }
        indice++;
    }

    // Guardar el ultimo campo despues del ultimo delimitador
    int largo_campo = indice - inicio_campo;
    campo[indice_campo] = cadena_duplicar_segura(&linea[inicio_campo],
                                                 largo_campo);
    indice_campo++;

    *cantidad_tokens = indice_campo;
    return campo;
}

/**
 * @brief Descripción de la función liberar_arreglo_cadenas.
 *
 * @param puntero_arreglo Descripción del parámetro puntero_arreglo.
 * @param cantidad Descripción del parámetro cantidad.
 */
void liberar_arreglo_cadenas(char ***puntero_arreglo, size_t cantidad)
{
    if (puntero_arreglo == NULL || *puntero_arreglo == NULL)
    {
        return;
    }

    for (size_t indice = 0; indice < cantidad; indice++)
    {
        if ((*puntero_arreglo)[indice] != NULL)
        {
            free((*puntero_arreglo)[indice]);
        }
    }
    free(*puntero_arreglo);
    *puntero_arreglo = NULL;
}
