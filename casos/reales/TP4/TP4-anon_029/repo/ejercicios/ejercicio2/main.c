/**
 * @file main.c
 * @brief Programa principal del Ejercicio 2.
 */

#include "cadenas.h"
#include "texto_dinamico.h"
#include <stdio.h>

void prueba_ejercicio_2()
{
        printf("Ejercicio 2: Normalización Dinámica de Texto en Heap\n");

    printf("Cadena con espacios");
    char texto_espacios[] = "    hola    ";
    char *recortado = cadena_recortar_espacios(texto_espacios);
    if (recortado != NULL)
    {
        printf("Cadena limpia: %s\n", recortado);
        cadena_liberar_segura(&recortado);
    }
    else
    {
        printf("Error: Fallo en la asignacion de memoria");
    }

    printf("Repeticion de cadena");
    char *repetido = cadena_repetir("ABC", 3);
    if (repetido != NULL)
    {
        printf("Cadena repetida: %s\n", repetido);
        cadena_liberar_segura(&repetido);
    }
    else
    {
        printf("Error: Fallo en la asignacion de memoria");
    }
}
int main(void)
{
    prueba_ejercicio_2();
    return 0;
}
