/**
 * @file main.c
 * @brief Programa principal del Ejercicio 5.
 */

#include <stdio.h>
#include "registro_csv.h"

int main(void)
{
    printf("Ejercicio 5: Registros y Parseo CSV en Heap\n");
    

    const char *linea_ejemplo = "Juan,Perez,30,Ingeniero,Buenos Aires";
    size_t cantidad_tokens = 0;

    char **tokens = dividir_linea_csv(linea_ejemplo, ',', &cantidad_tokens);
    if (tokens == NULL) {
        printf("Error al tokenizar la línea CSV.\n");
        return 1;
    }

    printf("Línea original: %s\n", linea_ejemplo);
    printf("Se obtuvieron %zu tokens:\n", cantidad_tokens);

    for (size_t i = 0; i < cantidad_tokens; i++) {
        printf("  Campo [%zu]: %s\n", i, tokens[i]);
    }

    liberar_arreglo_cadenas(&tokens, cantidad_tokens);

    if (tokens == NULL) {
        printf("Arreglo liberado y puntero asignado a NULL correctamente.\n");
    }

    return 0;
}
