/**
 * @file main.c
 * @brief Programa principal del Ejercicio 5.
 */

#include <stdio.h>
#include "registro_csv.h"

int main(void)
{
    printf("Ejercicio 5: Registros y Parseo CSV en Heap\n");

    const char *linea = "UNRN,2026,Bariloche";
    size_t cantidad_tokens = 0;

    char **tokens = dividir_linea_csv(linea, ',', &cantidad_tokens);

    if (tokens == NULL)
    {
        printf("No se pudo dividir la linea.\n");
        return 1;
    }

    printf("Linea original: %s\n", linea);
    printf("Cantidad de campos: %zu\n", cantidad_tokens);

    for (size_t i = 0; i < cantidad_tokens; i++)
    {
        printf("Campo %zu: %s\n", i + 1, tokens[i]);
    }

    liberar_arreglo_cadenas(&tokens, cantidad_tokens);

    return 0;
}