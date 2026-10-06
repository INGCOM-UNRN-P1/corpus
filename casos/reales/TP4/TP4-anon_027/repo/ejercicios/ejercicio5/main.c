/**
 * @file main.c
 * @brief Programa principal del Ejercicio 5.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "registro_csv.h"

int main()
{

    char buffer[1024];
    char delimitador_input[16];
    char delimitador;

    printf("Ejercicio 5: Registros y Parseo CSV en Heap\n");

    printf("Ingrese la linea a procesar: ");
        
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) 
    {
        return 1;
    }

    buffer[strcspn(buffer, "\r\n")] = '\0';

    printf("Ingrese el caracter delimitador [Enter para ',']: ");
    if (fgets(delimitador_input, sizeof(delimitador_input), stdin) == NULL) 
    {
        return 1;
    }

    if (delimitador_input[0] == '\n' || delimitador_input[0] == '\r' || delimitador_input[0] == '\0') 
    {
        delimitador = ',';
    } 
        
    else 
    {
        delimitador = delimitador_input[0];
    }

    size_t cantidad_tokens = 0;
    char **tokens = dividir_linea_csv(buffer, delimitador, &cantidad_tokens);

    if (tokens == NULL) 
    {
        printf("[Error] No se pudo procesar la linea (linea NULL o error de memoria).\n\n");
        return 1;
    }

    printf("\n--- Tokens Obtenidos (%zu campos, delimitador '%c') ---\n", cantidad_tokens, delimitador);
    for (size_t i = 0; i < cantidad_tokens; i++) 
    {
        printf("  [%zu]: \"%s\"\n", i, tokens[i]);
    }

    liberar_arreglo_cadenas(&tokens, cantidad_tokens);
    // Verificacion visual de anulación del punter
    if (tokens == NULL) 
    {
        printf("\n[OK] Memoria liberada correctamente (*tokens == NULL).\n");
    }

    printf("---------------------------------------------------\n\n");

    return 0;
}