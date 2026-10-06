/**
 * @file registro_csv.c
 * @brief Implementación de tokenización dinámica de cadenas en heap (char** sin structs).
 */

#include <stdlib.h>
#include <string.h>
#include "cadenas.h"
#include "registro_csv.h"

static bool agregar_copia(char ***lista, size_t *cantidad, char *copia);

char **lista_cadenas_crear(void)
{
    return NULL;
}

bool lista_cadenas_agregar(char ***lista, size_t *cantidad,
                           const char *cadena)
{
    if (lista == NULL || cantidad == NULL || cadena == NULL)
    {
        return false;
    }
    char *copia = cadena_duplicar_segura(cadena, strlen(cadena) + 1);
    return agregar_copia(lista, cantidad, copia);
}

void lista_cadenas_destruir(char **lista, size_t cantidad)
{
    if (lista == NULL)
    {
        return;
    }
    for (size_t i = 0; i < cantidad; i++)
    {
        free(lista[i]);
        lista[i] = NULL;
    }
    free(lista);
}

char **dividir_linea_csv(const char *linea, char delimitador,
                         size_t *cantidad_tokens)
{
    if (cantidad_tokens == NULL)
    {
        return NULL;
    }
    *cantidad_tokens = 0;
    if (linea == NULL)
    {
        return NULL;
    }

    char **tokens = lista_cadenas_crear();
    size_t cantidad = 0;
    size_t longitud = strlen(linea);
    size_t inicio = 0;
    bool sin_error = true;
    for (size_t i = 0; i <= longitud && sin_error == true; i++)
    {
        if (linea[i] == delimitador || linea[i] == '\0')
        {
            char *campo = cadena_subcadena_dinamica(linea, longitud + 1,
                                                    inicio, i - inicio);
            sin_error = agregar_copia(&tokens, &cantidad, campo);
            inicio = i + 1;
        }
    }

    if (sin_error == false)
    {
        liberar_arreglo_cadenas(&tokens, cantidad);
        return NULL;
    }
    *cantidad_tokens = cantidad;
    return tokens;
}

void liberar_arreglo_cadenas(char ***puntero_arreglo, size_t cantidad)
{
    if (puntero_arreglo == NULL)
    {
        return;
    }
    lista_cadenas_destruir(*puntero_arreglo, cantidad);
    *puntero_arreglo = NULL;
}

/**
 * @brief Agrega al final de la lista una cadena ya reservada en heap.
 * @param lista dirección de la lista.
 * @param cantidad cantidad actual; se incrementa ante éxito.
 * @param copia cadena en heap; si es NULL la función falla.
 * @pre lista y cantidad no son NULL.
 * @returns true ante éxito; false si copia es NULL o falla realloc.
 * @post ante éxito la lista pasa a ser dueña de copia; ante fallo copia se
 *       libera y la lista queda intacta.
 */
static bool agregar_copia(char ***lista, size_t *cantidad, char *copia)
{
    if (copia == NULL)
    {
        return false;
    }
    
    char **nueva = (char **)realloc(*lista, (*cantidad + 1) * sizeof(*nueva));
    if (nueva == NULL)
    {
        free(copia);
        copia = NULL;
        return false;
    }
    nueva[*cantidad] = copia;
    *cantidad = *cantidad + 1;
    *lista = nueva;
    return true;
}
