/**
 * @file texto_dinamico.c
 * @brief Implementación de funciones de texto dinámico en heap.
 */

#include "texto_dinamico.h"
#include <stdlib.h>

char *cadena_recortar_espacios(const char *origen)
{
    if (origen == NULL)
    {
        return NULL;
    }
    size_t cantidad_caracteres =
        strlen(origen); // Uso esta función porque las que programé necesitas de
                        // un parámetro 'capacidad' que esta función no recibe.
    size_t inicio_cadena = 0;
    while (origen[inicio_cadena] == ' ' && inicio_cadena < cantidad_caracteres)
    {
        inicio_cadena++;
    }

    if (inicio_cadena == cantidad_caracteres) // la cadena son todos espacios
    {
        return NULL;
    }

    size_t fin_cadena = cantidad_caracteres;
    while (origen[fin_cadena - 1] == ' ' && fin_cadena > inicio_cadena)
    {
        fin_cadena--;
    }
    size_t caracteres_utiles = fin_cadena - inicio_cadena;
    char *ptr_heap =
        cadena_duplicar_segura(origen + inicio_cadena, caracteres_utiles);
    return ptr_heap;
}

// En esta me ayudó la IA pq los intentos que hice fallaron
char *cadena_repetir(const char *origen, size_t veces)
{
    if (origen == NULL)
    {
        return NULL;
    }
    if (veces == 0)
    {
        return cadena_duplicar_segura("",
                                      1); // En esta me ayudó la IA pq no se me
                                          // ocurría como plantear este caso.
    }
    else
    {

        size_t longitud_cadena = strlen(
            origen); // Uso esta función porque las que programé necesitas de un
                     // parámetro 'capacidad' que esta función no recibe.
        size_t longitud_total = longitud_cadena * veces;

        char *ptr_repetir = malloc(longitud_total * sizeof(char) + 1);
        if (ptr_repetir == NULL)
        {
            return NULL;
        }

        for (size_t i = 0; i < veces; i++)
        {
            memcpy(ptr_repetir + (longitud_cadena * i), origen,
                   longitud_cadena * sizeof(char));
        }
        *(ptr_repetir + longitud_total) = '\0';

        return ptr_repetir;
    }
}
