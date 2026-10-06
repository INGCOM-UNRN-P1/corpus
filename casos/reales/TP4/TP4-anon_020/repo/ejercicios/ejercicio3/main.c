/**
 * @file main.c
 * @brief Programa principal del Ejercicio 3.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cadena_dinamica.h"

int main(void)
{
    char primera[128];
    char segunda[128];
    char *copiada = NULL;
    char *unida = NULL;

    printf("Ejercicio 3: Cadenas Dinámicas en Heap\n");

    printf("Ingrese la primera cadena: ");
    if (fgets(primera, sizeof(primera), stdin) == NULL)
    {
        return 1;
    }
    primera[strcspn(primera, "\r\n")] = '\0';

    printf("Ingrese la segunda cadena: ");
    if (fgets(segunda, sizeof(segunda), stdin) == NULL)
    {
        return 1;
    }
    segunda[strcspn(segunda, "\r\n")] = '\0';

    copiada = clonar_cadena(primera);
    if (copiada != NULL)
    {
        printf("Copia: %s\n", copiada);
        free(copiada);
        copiada = NULL;
    }

    unida = unir_cadenas_dinamicas(primera, segunda);
    if (unida != NULL)
    {
        printf("Union: %s\n", unida);
        free(unida);
        unida = NULL;
    }

    return 0;
}