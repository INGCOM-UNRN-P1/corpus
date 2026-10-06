#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "cadena_dinamica.h"

static void limpiar_salto_linea(char *cadena)
{
    bool encontrado = false;
    for (size_t i = 0; *(cadena + i) != '\0' && encontrado == false; i++)
    {
        if (*(cadena + i) == '\n')
        {
            *(cadena + i) = '\0';
            encontrado = true;
        }
    }
}

int main(void)
{
    printf("ejercicio 3: duplicacion y concatenacion dinamica de cadenas\n\n");

    char buffer1[256];
    char buffer2[256];

    printf("ingrese la primera cadena:\n> ");
    if (fgets(buffer1, sizeof(buffer1), stdin) == NULL)
    {
        printf("error leyendo la primera cadena.\n");
        return EXIT_FAILURE;
    }
    limpiar_salto_linea(buffer1);

    printf("ingrese la segunda cadena:\n> ");
    if (fgets(buffer2, sizeof(buffer2), stdin) == NULL)
    {
        printf("error leyendo la segunda cadena.\n");
        return EXIT_FAILURE;
    }
    limpiar_salto_linea(buffer2);

    char *clon = clonar_cadena(buffer1);
    if (clon != NULL)
    {
        printf("\nresultado de clonar la primera cadena:\n[%s]\n", clon);
        free(clon);
    }
    else
    {
        printf("\nerror al clonar la primera cadena.\n");
    }

    char *union_cadenas = unir_cadenas_dinamicas(buffer1, buffer2);
    if (union_cadenas != NULL)
    {
        printf("\nresultado de unir ambas cadenas:\n[%s]\n", union_cadenas);
        free(union_cadenas);
    }
    else
    {
        printf("\nerror al unir las cadenas.\n");
    }

    printf("\nmemoria liberada correctamente.\n");
    return EXIT_SUCCESS;
}