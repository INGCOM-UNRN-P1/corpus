/**
 * @file main.c
 * @brief Programa principal del Ejercicio 3.
 */

#include "cadena_dinamica.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("=== Ejercicio 3: Cadenas Dinámicas en Heap ===\n\n");

    int codigo_salida = 0;
    char primera[256];
    char segunda[256];

    printf("Ingrese la primera cadena: ");

    if (scanf(" %255[^\n]", primera) != 1)
    {
        printf("Error: no se pudo ingresar la primera cadena.\n");
        codigo_salida = 1;
    }
    else
    {
        char *clon = clonar_cadena(primera);

        if (clon != NULL)
        {
            printf("\nCadena original: %s\n", primera);
            printf("Cadena clonada: %s\n", clon);
        }
        else
        {
            printf("No se pudo clonar la cadena.\n");
        }

        printf("\nIngrese la segunda cadena: ");

        if (scanf(" %255[^\n]", segunda) != 1)
        {
            printf("Error: no se pudo ingresar la segunda cadena.\n");
            codigo_salida = 1;
        }
        else
        {
            char *union_cadenas = unir_cadenas_dinamicas(primera, segunda);

            if (union_cadenas != NULL)
            {
                printf("Cadenas unidas: %s\n", union_cadenas);
                free(union_cadenas);
            }
            else
            {
                printf("No se pudieron unir las cadenas.\n");
            }
        }

        free(clon);
    }

    return codigo_salida;
}
