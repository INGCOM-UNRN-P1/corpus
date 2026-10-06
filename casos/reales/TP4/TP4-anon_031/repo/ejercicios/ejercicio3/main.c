/**
 * @file main.c
 * @brief Demostración del Ejercicio 3.
 */

#include <stdio.h>
#include <stdlib.h>
#include "cadena_dinamica.h"

int main(void)
{
    char *clon = clonar_cadena("heap");
    char *unida = unir_cadenas_dinamicas("memoria ", "dinamica");
    char *invertida = invertir_cadena_dinamico("punteros");
    char **partes = NULL;
    size_t cantidad_partes = 0U;
    size_t indice = 0U;

    partes = partir_por_delimitador("rojo,verde,azul", ',', &cantidad_partes);

    printf("Ejercicio 3: Cadenas Dinamicas en Heap\n");
    if (clon != NULL)
    {
        printf("Clon: %s\n", clon);
    }
    if (unida != NULL)
    {
        printf("Union: %s\n", unida);
    }
    if (invertida != NULL)
    {
        printf("Invertida: %s\n", invertida);
    }
    if (partes != NULL)
    {
        for (indice = 0U; indice < cantidad_partes; indice++)
        {
            printf("Parte %zu: %s\n", indice + 1U, partes[indice]);
        }
    }

    free(clon);
    free(unida);
    free(invertida);
    liberar_partes_cadena(&partes, cantidad_partes);

    return 0;
}
