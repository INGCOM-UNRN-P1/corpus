/**
 * @file main.c
 * @brief Programa principal del Ejercicio 3.
 *
 * Uso: ./programa ["texto,separado,por,comas"]
 */

#include <stdio.h>
#include <stdlib.h>
#include "cadena_dinamica.h"

#define TEXTO_POR_DEFECTO "manzana,pera,,uva"

int main(int argc, char **argv)
{
    printf("Ejercicio 3: Cadenas Dinámicas en Heap\n");

    const char *texto = TEXTO_POR_DEFECTO;
    if (argc > 1)
    {
        texto = argv[1];
    }

    char *clon = clonar_cadena(texto);
    char *unida = unir_cadenas_dinamicas(texto, " (fin)");
    char *invertida = invertir_cadena_dinamico(texto);
    size_t cantidad = 0;
    char **tokens = partir_por_delimitador(texto, ',', &cantidad);

    int resultado = 0;
    if (clon == NULL || unida == NULL || invertida == NULL || tokens == NULL)
    {
        fprintf(stderr, "Error de memoria\n");
        resultado = 1;
    }
    else
    {
        printf("Clon:      %s\n", clon);
        printf("Unida:     %s\n", unida);
        printf("Invertida: %s\n", invertida);
        printf("Tokens (%zu):\n", cantidad);
        for (size_t i = 0; i < cantidad; i++)
        {
            printf("  [%zu] \"%s\"\n", i, tokens[i]);
        }
    }

    liberar_tokens(&tokens, cantidad);
    free(invertida);
    invertida = NULL;
    free(unida);
    unida = NULL;
    free(clon);
    clon = NULL;
    return resultado;
}
