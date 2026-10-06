
/**
 * @file main.c
 * @brief Programa principal del Ejercicio 2.
 */

#include <stdio.h>
#include "cadenas.h"
#include "texto_dinamico.h"

int main(void)
{
    const char texto[] = "   Hola UNRN   ";
    char *recortado = cadena_recortar_espacios(texto);
    char *repetido = NULL;

    if (recortado == NULL)
    {
        fprintf(stderr, "No se pudo recortar el texto.\n");
        return 1;
    }

    repetido = cadena_repetir(recortado, 3);

    if (repetido == NULL)
    {
        fprintf(stderr, "No se pudo reservar memoria para repetir el texto.\n");
        cadena_liberar_segura(&recortado);
        return 1;
    }

    printf("=== Ejercicio 2: Texto dinamico ===\n");
    printf("Original: [%s]\n", texto);
    printf("Recortado: [%s]\n", recortado);
    printf("Repetido tres veces: [%s]\n", repetido);

    cadena_liberar_segura(&recortado);
    cadena_liberar_segura(&repetido);

    return 0;
}
