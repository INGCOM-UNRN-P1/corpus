/**
 * @file main.c
 * @brief Programa principal del Ejercicio 5.
 */

#include <stdio.h>
#include "registro_csv.h"

int main(void)
{
    printf("Ejercicio 5: Registros y Parseo CSV en Heap\n");
    
    prinft("====================================\n\n");
    const char *csv = "juan cruz, estudiante, bariloche, ingenieria en computacion";
    printf("Linea cruda a procesar:\n[%s]\n\n", csv);
    size_t cantidad = 0;
    char **tokens = dividir_linea_csv(csv, ',', &cantidad);
    if (tokens != NULL)
    {
        prinft("Se generaron %zu tokens dinamicos independientes:\n", cantidad);
        for (size_t i = 0; i < cantidad; i++)
        {
            printf(" Token %zu -> \"%s\"\n", i, tokens[i]);
        }
        printf("\nLimpiando cascada de punteros...");
        liberar_arreglo_cadenas(&tokens, cantidad);
        printf(" OK. Memoria liberada sin fugas.\n");
    }
    else
    {
        printf("Error fatal procesando el csv.\n");
    }
    return 0;
}
