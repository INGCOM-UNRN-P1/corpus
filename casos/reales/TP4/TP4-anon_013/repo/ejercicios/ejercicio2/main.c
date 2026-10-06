/**
 * @file main.c
 * @brief Programa principal del Ejercicio 2.
 */

#include "cadenas.h"
#include "texto_dinamico.h"
#include <stdio.h>

int main(void)
{
    printf("Ejercicio 2: Normalización Dinámica de Texto en Heap\n");
    //______________________________________________________________________________________________________________

    printf("\n===== cadena_recortar_espacios =====\n");

    char cadena_origen[] = " asdfg ";

    printf("CADENA ORIGEN: [%s]\n", cadena_origen);

    char *ptr_heap = cadena_recortar_espacios(cadena_origen);

    if (ptr_heap != NULL)
    {
        printf("CADENA HEAP: [%s]\n", ptr_heap);
        cadena_liberar_segura(&ptr_heap);
        printf("PUNTERO AL HEAP LIBERADO CON cadena_liberar_segura()\n");
    }
    else
    {
        printf("EL PUNTERO AL HEAP ES NULL, algo malio sal\n");
    }

    //______________________________________________________________________________________________________________

    printf("\n===== cadena_repetir =====\n");

    char cadena_repetida[] = "abc";
    size_t veces = 3;

    printf("CADENA ORIGEN: [%s]\n", cadena_repetida);
    printf("VECES A REPETIT: %zu\n", veces);

    ptr_heap = cadena_repetir(cadena_repetida, veces);

    if (ptr_heap != NULL)
    {
        printf("CADENA HEAP: [%s]\n", ptr_heap);
        cadena_liberar_segura(&ptr_heap);
        printf("PUNTERO AL HEAP LIBERADO CON cadena_liberar_segura()\n");
    }
    else
    {
        printf("EL PUNTERO AL HEAP ES NULL, algo malio sal\n");
    }

    return 0;
}
