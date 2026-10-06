/**
 * @file main.c
 * @brief Programa principal del Ejercicio 5.
 */

#include "registro_csv.h"
#include <stdio.h>

int main(void)
{
    char linea[256];
    char delimitador = ',';
    size_t cant_tokens = 0;

    printf("=== TOKENIZADOR DE LÍNEA CSV ===\n");
    printf("Ingrese texto separado por comas: ");

    if (fgets(linea, sizeof(linea), stdin) == NULL)
    {
        return 1;
    }

    // Recorre la cadena y si encuentra '\n' lo reemplaza por '\0' sin romper el
    // bucle
    for (size_t i = 0; linea[i] != '\0'; i++)
    {
        if (linea[i] == '\n')
        {
            linea[i] = '\0';
        }
    }

    // 1. Dividir la línea
    char **tokens = dividir_linea_csv(linea, delimitador, &cant_tokens);
    if (tokens == NULL)
    {
        printf("Error al tokenizar o línea vacía.\n");
        return 1;
    }

    // 2. Mostrar los tokens extraídos
    printf("\nSe encontraron %zu campos:\n", cant_tokens);
    for (size_t i = 0; i < cant_tokens; i++)
    {
        printf("  Campo [%zu]: %s\n", i, tokens[i]);
    }

    // 3. Liberar la memoria
    liberar_arreglo_cadenas(&tokens, cant_tokens);
    printf("\nMemoria liberada correctamente.\n");

    return 0;
}
