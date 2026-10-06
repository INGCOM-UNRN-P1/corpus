/**
 * @file main.c
 * @brief Programa principal del Ejercicio 2.
 */

#include <stdio.h>
#include "cadenas.h"
#include "texto_dinamico.h"

int main(void)
{
    printf("Ejercicio 2: Normalización Dinámica de Texto en Heap\n");

    const char *texto = "   Hola mundo   ";

    char *recortada = cadena_recortar_espacios(texto);

    if (recortada != NULL)
    {
        printf("Original:   \"%s\"\n", texto);
        printf("Recortada:  \"%s\"\n", recortada);

        cadena_liberar_segura(&recortada);
    }

    const char *palabra = "Hola ";
    char *repetida = cadena_repetir(palabra, 3);

    if (repetida != NULL)
    {
        printf("Repetida:   \"%s\"\n", repetida);

        cadena_liberar_segura(&repetida);
    }

    return 0;
}