/**
 * @file main.c
 * @brief Programa principal del Ejercicio 2.
 */

#include <stdio.h>
#include "cadenas.h"
#include "texto_dinamico.h"
 
int main(void)
{
    int estado = 0;
 
    printf("Ejercicio 2: Normalización Dinámica de Texto en Heap\n");
 
    char *limpio = cadena_recortar_espacios("   hola mundo   ");
    if (limpio == NULL) {
        printf("Error: no se pudo recortar la cadena\n");
        estado = 1;
    } else {
        printf("Recortada: [%s]\n", limpio);
 
        char *repetida = cadena_repetir(limpio, 3);
        if (repetida == NULL) {
            printf("Error: no se pudo repetir la cadena\n");
            estado = 1;
        } else {
            printf("Repetida 3 veces: [%s]\n", repetida);
        }
 
        char *solo_espacios = cadena_recortar_espacios("     ");
        if (solo_espacios == NULL) {
            printf("Solo espacios: se obtuvo NULL\n");
        }
 
        cadena_liberar_segura(&repetida);
        cadena_liberar_segura(&limpio);
    }
    return estado;
}