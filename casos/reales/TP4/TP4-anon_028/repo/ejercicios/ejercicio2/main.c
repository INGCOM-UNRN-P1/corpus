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

    const char *texto = "hola mundo ";
    
    char *recortado = cadena_recortar_espacios(texto);
    if (recortado != NULL){
        printf("texto limpio %s\n", recortado);

        char *repetido = cadena_repetir(recortado, 3);
        if (repetido != NULL){
            printf("texto repetido %s\n", repetido);
            cadena_liberar_segura(&repetido);
        }
        cadena_liberar_segura(&recortado);
    }
    return 0;
}
