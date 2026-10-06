/**
 * @file main.c
 * @brief Programa principal del Ejercicio 6.
 */

#include "consulta_csv.h"
#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    printf("=== Ejercicio 6: Filtro de Texto Multilinea ===\n\n");

    int codigo_salida = 0;
    char subcadena[256];
    char **lineas = NULL;
    size_t cantidad = 0;

    printf("Ingrese la subcadena que desea buscar: ");

    if (fgets(subcadena, sizeof(subcadena), stdin) == NULL)
    {
        printf("Error: no se pudo leer la subcadena.\n");
        codigo_salida = 1;
    }
    else
    {
        char *actual = subcadena;

        while (*actual != '\0')
        {
            if (*actual == '\n')
            {
                *actual = '\0';
            }

            actual++;
        }

        printf("\nIngrese las líneas de texto.\n");
        printf("Finalice la entrada con EOF.\n\n");

        bool entrada_valida = true;
        char buffer[256];

        while (entrada_valida && fgets(buffer, sizeof(buffer), stdin) != NULL)
        {
            if (!agregar_linea(&lineas, &cantidad, buffer))
            {
                printf("\nError: no se pudo almacenar una línea.\n");
                entrada_valida = false;
                codigo_salida = 1;
            }
        }

        if (entrada_valida)
        {
            printf("\nLíneas que contienen \"%s\":\n", subcadena);

            mostrar_lineas_filtradas(lineas, cantidad, subcadena);
        }
    }

    liberar_lineas(lineas, cantidad);

    return codigo_salida;
}
