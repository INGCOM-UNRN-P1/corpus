/**
 * @file main.c
 * @brief Programa principal del Ejercicio 3.
 */

#include <stdio.h>
#include <stdlib.h>
#include "cadena_dinamica.h"

int main(void)
{
    printf("=== Ejercicio 3: Cadenas Dinamicas en Heap ===\n\n");

    const char *original = "Ingenieria en Computacion";
    printf("1. Cadena fuente: \"%s\"\n", original);

    char *copia = clonar_cadena(original);
    if (copia != NULL)
    {
        printf("   Clon en heap: \"%s\" (direccion: %p)\n", copia, (void *)copia);
    }

    const char *saludo = "Universidad Nacional ";
    const char *sede = "de Rio Negro";
    printf("\n2. Concatenando \"%s\" y \"%s\"...\n", saludo, sede);

    char *concatenada = unir_cadenas_dinamicas(saludo, sede);
    if (concatenada != NULL)
    {
        printf("   Resultado concatenado: \"%s\"\n", concatenada);
    }

    printf("\n3. Liberando memoria asignada en el heap...\n");
    free(copia);
    copia = NULL;

    free(concatenada);
    concatenada = NULL;

    printf("Memoria liberada y punteros anulados con exito.\n");
    return 0;
}
