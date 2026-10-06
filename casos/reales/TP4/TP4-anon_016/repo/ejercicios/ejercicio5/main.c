/**
 * @file main.c
 * @brief Programa principal del Ejercicio 5.
 */

#include <stdio.h>
#include <stddef.h>
#include "registro_csv.h"
#include "cadenas.h"

int main(void)
{
    printf("Ejercicio 5: Registros y Parseo CSV en Heap\n");

    char delimitador = ',';
    char linea[256];
 
    printf("Delimitador (un caracter): ");
    int leidos = scanf(" %c", &delimitador);
 
    int caracter = getchar();
    while (caracter != '\n' && caracter != EOF)
    {
        caracter = getchar();
    }
 
    if (leidos == 1)
    {
        printf("Linea a dividir: ");
        char *lectura = fgets(linea, sizeof(linea), stdin);
 
        if (lectura != NULL)
        {
            size_t posicion = 0;
            while (linea[posicion] != '\0' && linea[posicion] != '\n')
            {
                posicion++;
            }
            linea[posicion] = '\0';
 
            
            size_t cantidad = 0;
            char **tokens = dividir_linea_csv(linea, delimitador, &cantidad);
 
            if (tokens != NULL)
            {
               
                printf("Campos obtenidos: %zu\n", cantidad);
                for (size_t indice = 0; indice < cantidad; indice++)
                {
                    printf("[%zu] \"%s\"\n", indice, tokens[indice]);
                }
 
                
                size_t no_vacios = 0;
                printf("Campos no vacios:\n");
                for (size_t indice = 0; indice < cantidad; indice++)
                {
                    if (tokens[indice][0] != '\0')
                    {
                        printf("[%zu] \"%s\"\n", indice, tokens[indice]);
                        no_vacios++;
                    }
                }
                printf("%zu de %zu campos no estan vacios\n", no_vacios,
                       cantidad);
 
                liberar_arreglo_cadenas(&tokens, cantidad);
            }
            else
            {
                printf("No se pudo dividir la linea.\n");
            }
        }
    }
 
    return 0;
}
 