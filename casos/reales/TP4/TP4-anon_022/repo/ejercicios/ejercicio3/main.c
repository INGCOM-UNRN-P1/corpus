/**
 * @file main.c
 * @brief Programa principal del Ejercicio 3.
 */

#include <stdio.h>
#include <stdlib.h>
#include "cadena_dinamica.h"
#include "cadenas.h"

int main(void)
{
    char primera[100];
    char segunda[100];

    printf("Ejercicio 3: Cadenas Dinámicas en Heap\n");

    printf("Ingrese la primera cadena: ");
    fgets(primera, sizeof(primera), stdin);

    size_t longitud_primera = cadena_longitud(primera, sizeof(primera));

    if (longitud_primera > 0 && primera[longitud_primera - 1] == '\n')
    {
        primera[longitud_primera - 1] = '\0';
    }

    printf("Ingrese la segunda cadena: ");
    fgets(segunda, sizeof(segunda), stdin);

    size_t longitud_segunda = cadena_longitud(segunda, sizeof(segunda));

    if (longitud_segunda > 0 && segunda[longitud_segunda - 1] == '\n')
    {
        segunda[longitud_segunda - 1] = '\0';
    }

    char *copia = clonar_cadena(primera);

    if (copia == NULL)
    {
        printf("No se pudo clonar la cadena.\n");
        return 1;
    }

    char *union_cadenas = unir_cadenas_dinamicas(primera, segunda);

    if (union_cadenas == NULL)
    {
        printf("No se pudieron unir las cadenas.\n");
        free(copia);
        return 1;
    }

    printf("\nCadena original: %s\n", primera);
    printf("Cadena clonada: %s\n", copia);
    printf("Cadenas unidas: %s\n", union_cadenas);

    free(copia);
    copia = NULL;

    free(union_cadenas);
    union_cadenas = NULL;

    return 0;
}