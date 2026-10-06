/**
 * @file main.c
 * @brief Programa principal del Ejercicio 2.
 */

#include <stdio.h>
#include <stdlib.h>
#include "texto_dinamico.h"

int main(void)
{
    printf("=== Ejercicio 2: Normalizacion Dinamica de Texto en Heap ===\n\n");

    const char *original = "   Programacion 1 - UNRN 2026    ";
    printf("Cadena con espacios: \"%s\"\n", original);

    char *recortada = cadena_recortar_espacios(original);
    if (recortada != NULL)
    {
        printf("Cadena recortada   : \"%s\"\n\n", recortada);
    }

    const char *eco = "Eco! ";
    size_t veces = 3;
    printf("Repitiendo \"%s\" %zu veces...\n", eco, veces);

    char *repetida = cadena_repetir(eco, veces);
    if (repetida != NULL)
    {
        printf("Resultado repetido : \"%s\"\n\n", repetida);
    }

    
    free(recortada);
    recortada = NULL;

    free(repetida);
    repetida = NULL;

    printf("Memoria dinamica liberada correctamente.\n");
    return 0;
}