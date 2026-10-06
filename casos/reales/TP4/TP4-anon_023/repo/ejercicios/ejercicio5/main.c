/**
 * @file main.c
 * @brief Programa principal del Ejercicio 5.
 */

#include <stdio.h>
#include <stdlib.h>
#include "registro_csv.h"

int main(void)
{
    printf("=== Ejercicio 5: Registros y Parseo CSV en Heap ===\n\n");

    const char *registro = "44123890;Gonzalez;Martin;Ingenieria;8.75";
    char delimitador = ';';

    printf("Linea de entrada: \"%s\"\n", registro);
    printf("Delimitador: '%c'\n\n", delimitador);

    size_t total_tokens = 0;
    char **tokens = dividir_linea_csv(registro, delimitador, &total_tokens);

    if (tokens != NULL)
    {
        printf("Campos detectados (%zu):\n", total_tokens);
        for (size_t i = 0; i < total_tokens; i++)
        {
            printf("  [Campo %zu] -> \"%s\" (dir: %p)\n", i, *(tokens + i), (void *)*(tokens + i));
        }

        printf("\nLiberando arreglo dinamico de tokens...\n");
        liberar_arreglo_cadenas(&tokens, total_tokens);
        printf("Puntero tokens tras liberar: %p\n", (void *)tokens);
    }

    return 0;
}
