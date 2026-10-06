/**
 * @file main.c
 * @brief Programa principal del Ejercicio 2.
 */

#include <stdio.h>
#include <string.h>
#include "cadenas.h"
#include "texto_dinamico.h"

int main(void)
{
    char entrada[128];
    char *recortada = NULL;
    char *repetida = NULL;

    printf("Ejercicio 2: Normalización Dinámica de Texto en Heap\n");

    printf("Ingrese una frase: ");
    if (fgets(entrada, sizeof(entrada), stdin) == NULL)
    {
        return 1;
    }
    entrada[strcspn(entrada, "\r\n")] = '\0';

    recortada = cadena_recortar_espacios(entrada);
    if (recortada != NULL)
    {
        printf("Recortada: %s\n", recortada);
        cadena_liberar_segura(&recortada);
    }

    repetida = cadena_repetir(entrada, 2U);
    if (repetida != NULL)
    {
        printf("Repetida: %s\n", repetida);
        cadena_liberar_segura(&repetida);
    }

    return 0;
}