
/**
 * @file main.c
 * @brief Programa principal del Ejercicio 3.
 */

#include <stdio.h>
#include "cadena_dinamica.h"
#include <stdlib.h>

int main(void)
{
    char original[] = "Programacion 1";

    char *copia = NULL;
    char *unida = NULL;

    copia = clonar_cadena(original);
    unida = unir_cadenas_dinamicas(
        original,
        " - UNRN"
    );

    if (copia == NULL || unida == NULL)
    {
        fprintf(
            stderr,
            "No se pudo reservar memoria para las cadenas.\n"
        );

        free(copia);
        free(unida);

        return 1;
    }

    printf("=== Ejercicio 3: Cadenas en heap ===\n");

    printf("Original: %s\n", original);
    printf("Copia: %s\n", copia);
    printf("Union: %s\n", unida);

    copia[0] = 'p';

    printf("Copia modificada: %s\n", copia);
    printf("Original conservado: %s\n", original);

    free(copia);
    copia = NULL;

    free(unida);
    unida = NULL;

    return 0;
}
