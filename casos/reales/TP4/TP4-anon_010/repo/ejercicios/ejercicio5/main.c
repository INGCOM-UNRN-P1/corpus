/**
 * @file main.c
 * @brief Programa principal del Ejercicio 5.
 */

#include <stdio.h>
#include "registro_csv.h"
 
int main(void)
{
    int estado = 0;
 
    printf("Ejercicio 5: Registros y Parseo CSV en Heap\n");
 
    const char *linea = "Ana,23,Bariloche,Ingenieria";
    size_t cantidad = 0;
 
    char **tokens = dividir_linea_csv(linea, ',', &cantidad);
    if (tokens == NULL) {
        printf("Error: no se pudo dividir la línea\n");
        estado = 1;
    } 
    else {
        printf("Línea: [%s]\n", linea);
        printf("Campos: %zu\n", cantidad);
        for (size_t i = 0; i < cantidad; ++i) {
            printf("  [%zu] %s\n", i, tokens[i]);
        }
 
        liberar_arreglo_cadenas(&tokens, cantidad);
    }
    return estado;
}
