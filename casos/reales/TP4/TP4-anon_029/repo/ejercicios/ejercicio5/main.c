/**
 * @file main.c
 * @brief Programa principal del Ejercicio 5.
 */

#include "registro_csv.h"
#include <stdio.h>

void prueba_ejercicio_5()
{
    printf("Ejercicio 5: Registros y Parseo CSV en Heap\n");
    size_t cantidad_encontrada = 0;
    const char *lista = "manzana,cebolla,zanahoria,papa";
    char **tokens = dividir_linea_csv(lista, ',', &cantidad_encontrada);

    if (tokens != NULL)
    {
        for (size_t indice = 0; indice < cantidad_encontrada; indice++)
        {
            printf("Tokens %zu: %s\n", indice, tokens[indice]);
        }

        liberar_arreglo_cadenas(&tokens, cantidad_encontrada);
    }
}
int main(void)
{
    prueba_ejercicio_5();
    return 0;
}
