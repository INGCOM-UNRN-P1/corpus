/**
 * @file registro_csv.c
 * @brief Implementación de tokenización dinámica de cadenas en heap (char** sin structs).
 */

#include <stdbool.h>
#include <stdlib.h>
 
#include "registro_csv.h"
#include "cadenas.h"
 


 
void liberar_arreglo_cadenas(char ***puntero_arreglo, size_t cantidad)
{
    if (puntero_arreglo != NULL && *puntero_arreglo != NULL)
    {
        for (size_t indice = 0; indice < cantidad; indice++)
        {
            cadena_liberar_segura(&(*puntero_arreglo)[indice]);
        }
        free(*puntero_arreglo);
        *puntero_arreglo = NULL;
    }
}
 
char **dividir_linea_csv(const char *linea, char delimitador,
                         size_t *cantidad_tokens)
{
    char **resultado = NULL;
 
    if (linea != NULL && cantidad_tokens != NULL)
    {
        *cantidad_tokens = 0;
 
        size_t cantidad = 1;
        const char *recorrido = linea;
        while (*recorrido != '\0')
        {
            if (*recorrido == delimitador)
            {
                cantidad++;
            }
            recorrido++;
        }
 
        resultado = calloc(cantidad, sizeof(*resultado));
        if (resultado != NULL)
        {
            const char *inicio = linea;
            bool exito = true;
            size_t indice = 0;
 
            while (exito && indice < cantidad)
            {
                const char *fin = inicio;
                while (*fin != delimitador && *fin != '\0')
                {
                    fin++;
                }
 
                size_t longitud = (size_t)(fin - inicio);
                resultado[indice] = cadena_subcadena_dinamica(inicio, longitud,
                                                              0, longitud);
                exito = (resultado[indice] != NULL);
                inicio = fin + 1;
                indice++;
            }
 
            if (exito)
            {
                *cantidad_tokens = cantidad;
            }
            else
            {
                liberar_arreglo_cadenas(&resultado, cantidad);
            }
        }
    }
 
    return resultado;
}
 