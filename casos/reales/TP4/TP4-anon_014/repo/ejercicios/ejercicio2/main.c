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

    const char *texto = "   hola mundo   ";
    char *recortada = cadena_recortar_espacios(texto);
    char *mayusculas = normalizar_mayusculas_dinamico(recortada);
    char *repetida = cadena_repetir("ab", 3);

    if (recortada == NULL || mayusculas == NULL || repetida == NULL)
    {
        fprintf(stderr, "Error de memoria\n");
    }
    else
    {
        printf("Original:   [%s]\n", texto);
        printf("Recortada:  [%s]\n", recortada);
        printf("Mayusculas: [%s]\n", mayusculas);
        printf("Repetida:   [%s]\n", repetida);
    }

    cadena_liberar_segura(&repetida);
    cadena_liberar_segura(&mayusculas);
    cadena_liberar_segura(&recortada);
    return 0;
}
