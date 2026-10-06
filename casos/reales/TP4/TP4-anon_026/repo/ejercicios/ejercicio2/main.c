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
 
    char *limpio = cadena_recortar_espacios("   hola mundo   ");
    if (limpio == NULL) 
    {
        fprintf(stderr, "Error: no se pudo recortar la cadena\n");
        return 1;
    }
    printf("Recortado: \"%s\"\n", limpio);
 
    char *solo_espacios = cadena_recortar_espacios("     ");
    printf("Solo espacios: %s\n", solo_espacios == NULL ? "NULL" : "bloque");
 
    char *repetido = cadena_repetir(limpio, 3);
    if (repetido == NULL) 
    {
        fprintf(stderr, "Error: no se pudo repetir la cadena\n");
        cadena_liberar_segura(&limpio);
        return 1;
    }
    printf("Repetido 3 veces: \"%s\"\n", repetido);
 
    char *cero = cadena_repetir("abc", 0);
    printf("Repetido 0 veces: \"%s\"\n", cero == NULL ? "(NULL)" : cero);
 
    cadena_liberar_segura(&cero);
    cadena_liberar_segura(&repetido);
    cadena_liberar_segura(&solo_espacios);
    cadena_liberar_segura(&limpio);
    return 0;
}
