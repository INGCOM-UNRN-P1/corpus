/**
 * @file main.c
 * @brief Demostración del Ejercicio 2.
 */

#include <stdio.h>
#include "texto_dinamico.h"

int main(void)
{
    char *recortada = cadena_recortar_espacios("   Programacion I   ");
    char *repetida = cadena_repetir("C", 4U);

    printf("Ejercicio 2: Normalizacion Dinamica de Texto en Heap\n");

    if (recortada != NULL)
    {
        printf("Recortada: '%s'\n", recortada);
    }

    if (repetida != NULL)
    {
        printf("Repetida: '%s'\n", repetida);
    }

    cadena_liberar_segura(&recortada);
    cadena_liberar_segura(&repetida);

    return 0;
}
