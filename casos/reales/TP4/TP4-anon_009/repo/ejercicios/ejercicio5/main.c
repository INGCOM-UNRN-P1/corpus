/**
 * @file main.c
 * @brief Programa principal del Ejercicio 5.
 */

#include <stdio.h>
#include "registro_csv.h"

int main(void)
{
    printf("Ejercicio 5: Registros y Parseo CSV en Heap\n");
    const char *linea = "Juan,Perez,30,Ingeniero,Argentina";
    char delimitador = ',';
    size_t total_tokens = 0;
    char **tokens = dividir_linea_csv(linea, delimitador, &total_tokens);
    if (tokens != NULL)
    {
        printf("Linea original: \"%s\"\n", linea);
        printf("Tokens encontrados (%zu):\n", total_tokens);

        char **ptr = tokens;
        char **fin = tokens + total_tokens;
        size_t i = 1;
        while (ptr < fin)
        {
            printf("  [%zu]: %s\n", i++, *ptr);
            ptr++;
        }
        liberar_arreglo_cadenas(&tokens, total_tokens);
        if (tokens == NULL)
        {
            printf("\nArreglo liberado correctamente y puntero reseteado a NULL.\n");
        }
    }
    return 0;
}
