/**
 * @file main.c
 * @brief Programa principal del Ejercicio 2.
 */

#include "texto_dinamico.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("=== Ejercicio 2: Normalización Dinámica de Texto en Heap ===\n\n");

    int codigo_salida = 0;
    char texto[256];
    size_t veces = 0;

    printf("Ingrese un texto: ");

    if (scanf(" %255[^\n]", texto) != 1)
    {
        printf("Error: no se pudo ingresar el texto.\n");
        codigo_salida = 1;
    }
    else
    {
        char *recortado = cadena_recortar_espacios(texto);

        if (recortado != NULL)
        {
            printf("\nTexto original: \"%s\"\n", texto);
            printf("Texto recortado: \"%s\"\n", recortado);
        }
        else
        {
            printf("El texto no contiene caracteres distintos de espacios.\n");
        }

        printf("\nIngrese la cantidad de repeticiones: ");

        if (scanf("%zu", &veces) != 1)
        {
            printf("Error: cantidad de repeticiones no válida.\n");
            codigo_salida = 1;
        }
        else
        {
            char *repetido = cadena_repetir(texto, veces);

            if (repetido != NULL)
            {
                printf("Texto repetido: \"%s\"\n", repetido);
                free(repetido);
            }
            else
            {
                printf("No se pudo generar el texto repetido.\n");
            }
        }

        free(recortado);
    }

    return codigo_salida;
}
